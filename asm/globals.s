.include "asm/include/constants.inc"
.include "asm/include/commands.inc"

.data
.rept 0x0001be00
.byte 0x00
.endr

func0000_idle:
	dprint "dyeng"
	beginloop 0x0d
	endloop 0x0d

	endfunction

func0005_end_cinema:
	enter_firstperson
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func0001_unalerted_0001:
	set_function CHR_SELF, GFUNC_UNALERTED
	endfunction

// Never used
func0003_stop_unalerted:
	stop_chr
	set_function CHR_SELF, GFUNC_UNALERTED
	endfunction

func0002_unalerted_0002:
	set_function CHR_SELF, GFUNC_UNALERTED
	endfunction

func0004_unalerted_0004:
	set_function CHR_SELF, GFUNC_UNALERTED_0002
	endfunction

func0006_unalerted:
	.set LABEL_AIVSAIFAIL,   0x16
	.set LABEL_DISGUISE_UNCOVERED, 0x16
	.set LABEL_SCAN_START,   0x1a
	.set LABEL_SEE_DETECT,   0x1e
	.set LABEL_HEAR_DETECT,  0x1f
	.set LABEL_NEAR_MISS,    0x20
	.set LABEL_SEEFRIENDDIE, 0x21
	.set LABEL_HEARD_ALARM,  0x23
	.set LABEL_HEARSPAWN,    0xda

	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_return_function CHR_SELF, GFUNC_INIT_PSYCHOSIS
	set_function CHR_SELF, GFUNC_INIT_PSYCHOSIS

	label 0x16
	set_target_chr CHR_P1P2
	set_onshot_function GFUNC_UNALERTED
	if_chr_dying CHR_SELF, /*goto*/ 0x15
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x15
	if_chr_unloaded CHR_SELF, /*goto*/ 0x15
	if_just_injured CHR_SELF, /*goto*/ 0x16
	if_has_gun CHR_SELF, /*goto*/ 0x13
	dprint "NOGUN\n"
	goto_next 0x16

	label 0x13
	goto_next LABEL_SCAN_START

	// Dying
	label 0x15
	dprint "DIE INSCAN\n"
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	// Injured or has no gun
	label 0x16
	say_quip CHR_JOANNA, 0x0c, 0x78, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"
	dprint "NOGUN,\n"
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x06
	unset_self_flag_bankx CHRFLAG1_DOINGIDLEANIMATION, BANK_1
	if_chr_idle_action_eq IDLEACTION_SITTING_TYPING, /*goto*/ 0x05
	if_chr_idle_action_eq IDLEACTION_SITTING_DORMANT, /*goto*/ 0x05
	goto_next 0x06

	// Stand up from sitting
	label 0x05
	dprint "NOGUN2\n"
	dprint "ANIM OBJECT NOW\n"
	set_chr_health CHR_SELF, 40
	object_do_animation 0x025a, 0xff, 0x02ff, 0xff
	animation ANIM_STAND_UP_FROM_SITTING, 0, -1, 0x0210, CHR_SELF, 2
	unset_self_flag_bankx CHRFLAG1_DOINGIDLEANIMATION, BANK_1
	set_chr_special_death_animation CHR_SELF, NULL
	dprint "B4 WAT\n"
	goto_next 0x0c

	label 0x06
	dprint "BEEN SHOT\n"
	// if 01000000, set 04000000
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_01000000, /*goto*/ 0x14
	goto_next 0x13

	label 0x14
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_04000000

	// Stop chr, either immediately or by waiting for their animation to end.
	// I think the animation is their injured animation.
	label 0x13
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	if_chr_idle /*goto*/ 0x13
	goto_next 0x03

	label 0x13
	stop_chr
	goto_next 0x16

	beginloop 0x03
		if_chr_stopped /*goto*/ 0x16
	endloop 0x03

	// If warned already, go straight to scan
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_WARNED, TRUE, BANK_1, /*goto*/ LABEL_SCAN_START

	say_quip CHR_JOANNA, 0x0c, 0xff, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"
	dprint "NO WARNING\n"
	if_self_flag_bankx_eq CHRFLAG0_CANT_ALERT_GROUP, TRUE, BANK_0, /*goto*/ 0x13
	set_group_alertness 100
	label 0x13
	dprint "NO WARNING\n"
	set_function CHR_SELF, GFUNC_WAKEUP
	dprint "S1"

	// Armed
	label LABEL_SCAN_START
	dprint "SCAN START\n"
	set_action ACTION_SCAN, TRUE
	yield
	dprint "S2"
	consider_coop_for_p1p2_chr CHR_SELF
	set_target_chr CHR_P1P2
	label 0x13
	if_alertness 100, OPERATOR_LESS_THAN, /*goto*/ 0x16
	dprint "ALERT FAI\n"
	goto_next 0x78

	// Not alert
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_WARNED, TRUE, BANK_1, /*goto*/ 0x13
	if_saw_death 0x01, /*goto*/ LABEL_SEEFRIENDDIE
	if_shot_near_chr 0x01, /*goto*/ LABEL_NEAR_MISS

	// Warned
	label 0x13
	dprint "A1\n"
	if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x16
	if_target_chr_in_sight /*goto*/ LABEL_SEE_DETECT
	label 0x16
	dprint "B4 AIVSAI\n"
	if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ LABEL_AIVSAIFAIL
	dprint "AIVSAISET\n"
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x13
	dprint "AIVSAIFAIL\n"
	goto_next LABEL_AIVSAIFAIL

	label 0x13
	dprint "AIVSAIPASS\n"
	if_chr_lost_track_of_target_maybe /*goto*/ LABEL_AIVSAIFAIL
	goto_next 0x12

	// Check see and hear
	label LABEL_AIVSAIFAIL
	dprint "S4"
	if_near_miss /*goto*/ LABEL_SEE_DETECT
	if_num_times_shot_gt 0, /*goto*/ LABEL_SEE_DETECT
	dprint "B4NOHEAR\n"
	if_self_flag_bankx_eq CHRFLAG0_NOHEAR, FALSE, BANK_0, /*goto*/ 0x16
	if_chr_sees_player /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	dprint "CHEKHEAR\n"
	if_shot_at_close_range /*goto*/ LABEL_HEAR_DETECT
	label 0x13
	dprint "NOTHEARD\n"

	// Check alarm
	label 0x13
	dprint "N2\n"
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEAR_ALARMS, FALSE, BANK_0, /*goto*/ 0x16
	dprint "N3\n"
	if_alarm_active /*goto*/ LABEL_HEARD_ALARM
	label 0x16
	dprint "N1\n"
	if_alarm_active /*goto*/ 0x13
	goto_next 0x16

	// Can hear alarm
	label 0x13
	dprint "AL ONARD\n"
	if_stage_is_not STAGE_PELAGIC, /*goto*/ 0x16
	if_bitcheck_in_position_struct /*goto*/ LABEL_HEARD_ALARM

	// Check if can see camspy
	label 0x16
	if_chr_sees_camspy_maybe /*goto*/ 0x16
	dprint "ES NOVIS\n"
	goto_next 0x13

	// Can see camspy
	label 0x16
	dprint "SEEEYESPY\n"
	if_path_started /*goto*/ 0x15
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_OBSERVE_CAMSPY

	// Patroller seeing camspy
	label 0x15
	set_return_function CHR_SELF, GFUNC_DISGUISE_DETECTION
	set_function CHR_SELF, GFUNC_OBSERVE_CAMSPY

	// Can't see camspy
	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00080000, TRUE, BANK_1, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_DISSPEE, FALSE, BANK_1, /*goto*/ 0x15
	dprint "CHECK SOUFI\n" // checks outfit?
	if_chr_field0x332_zero CHR_SELF, /*goto*/ 0x28
	if_timer_gt 60, /*goto*/ 0x28
	goto_next 0x15

	// chr field 0x332 was zero
	label 0x28
	unset_self_flag_bankx CHRFLAG1_DISSPEE, BANK_1
	stop_chr

	// Disspee is false, or timer not at 1 second yet
	label 0x15
	if_chr_idle /*goto*/ 0x16
	call_rng
	if_rand_gt 1, /*goto*/ 0x16
	call_rng
	if_rand_gt 20, /*goto*/ 0x16
	if_path_started /*goto*/ 0x15
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_DO_BORED_ANIMATION

	label 0x15
	set_return_function CHR_SELF, GFUNC_DISGUISE_DETECTION
	set_function CHR_SELF, GFUNC_DO_BORED_ANIMATION

	// Consider looking around
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_CAN_LOOK_AROUND, FALSE, BANK_1, /*goto*/ 0x16
	call_rng
	if_rand_gt 10, /*goto*/ 0x16
	call_rng
	if_rand_gt 20, /*goto*/ 0x16
	if_path_started /*goto*/ 0x15
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_LOOK_AROUND

	label 0x15
	set_return_function CHR_SELF, GFUNC_DISGUISE_DETECTION
	set_function CHR_SELF, GFUNC_LOOK_AROUND

	label 0x16
	goto_first LABEL_SCAN_START

	// Idle animations
	label 0x13
	dprint "NAT ANIMS\n"
	if_chr_idle /*goto*/ 0x16
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_BUSY

	label 0x16
	dprint "IN ANIMS\n"
	goto_first LABEL_SCAN_START

	// Handle seeing player
	label LABEL_SEE_DETECT
	dprint "SEE DETECT\n"
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISE_UNCOVERED, /*goto*/ LABEL_DISGUISE_UNCOVERED
	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000, /*goto*/ 0x14
	goto_next 0x13

	label 0x14
	if_chr_weapon_equipped TARGET_CHR, WEAPON_NONE, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_UNARMED, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_COMBATBOOST, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_HORIZONSCANNER, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_SUITCASE, /*goto*/ 0x15
	if_chr_in_view /*goto*/ LABEL_DISGUISE_UNCOVERED
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_04000000, /*goto*/ LABEL_DISGUISE_UNCOVERED

	label 0x15
	dprint "NOT AIMING AT ME\n"

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x13
	goto_next LABEL_DISGUISE_UNCOVERED

	label 0x13
	if_chr_weapon_equipped TARGET_CHR, WEAPON_NONE, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_UNARMED, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_COMBATBOOST, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_HORIZONSCANNER, /*goto*/ 0x15
	if_chr_weapon_equipped TARGET_CHR, WEAPON_SUITCASE, /*goto*/ 0x15
	goto_next 0x14

	label 0x15
	if_chr_field_0x120 600, OPERATOR_GREATER_THAN, /*goto*/ 0x15
	goto_next 0xea

	label 0x14
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000, /*goto*/ 0xe8
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_01000000, /*goto*/ 0xe8

	label 0xea
	if_chr_weapon_equipped TARGET_CHR, WEAPON_NONE, /*goto*/ 0xe6
	if_chr_weapon_equipped TARGET_CHR, WEAPON_UNARMED, /*goto*/ 0xe6
	if_chr_weapon_equipped TARGET_CHR, WEAPON_COMBATBOOST, /*goto*/ 0xe6
	if_chr_weapon_equipped TARGET_CHR, WEAPON_HORIZONSCANNER, /*goto*/ 0xe6
	if_chr_weapon_equipped TARGET_CHR, WEAPON_SUITCASE, /*goto*/ 0xe6
	dprint "TALK DIST GUN\n"
	if_chr_distance_gt 900, /*goto*/ 0x15
	goto_next 0xe8

	label 0xe6
	if_chr_distance_gt 450, /*goto*/ 0x15
	label 0xe8
	if_chr_sees_player /*goto*/ 0xe9
	goto_next LABEL_DISGUISE_UNCOVERED

	label 0xe9
	label 0x13
	if_player_looking_at_something_maybe 0x0a, 0x01, 0x00, /*goto*/ 0x13
	goto_next 0x15

	label 0x13
	if_path_started /*goto*/ 0x14
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_CIVILIAN_SAY_COMMENT
	label 0x14
	set_return_function CHR_SELF, GFUNC_DISGUISE_DETECTION
	set_function CHR_SELF, GFUNC_CIVILIAN_SAY_COMMENT
	label 0x15
	goto_first LABEL_SCAN_START

	// Disguise broken
	label LABEL_DISGUISE_UNCOVERED
	dprint "DISBROKEN\n"
	if_near_miss /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_UNSURPRISABLE, TRUE, BANK_0, /*goto*/ 0x94
	label 0x16
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x14
	if_any_chr_doing_action ACTION_WARN_OTHERS, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_RUN_FOR_ALARM, TRUE, BANK_0, /*goto*/ 0x9f
	label 0x16
	say_quip CHR_JOANNA, 0x0b, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Hey, you!","Intruder alert","We've got a contact!"
	label 0x9f
	set_group_alertness 100
	goto_next 0x77

	label 0xdb // jumped to from below
	label 0x14
	say_quip CHR_JOANNA, 0x20, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Imposter!","It's a spy!"
	set_group_alertness 100
	goto_next 0x77

	// Unreachable?
	label 0x16
	yield
	yield
	dprint "S3"
	say_quip CHR_JOANNA, 0x0c, 0xff, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"
	set_group_alertness 100
	goto_next 0x77

	label 0x94
	label 0x16
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_PSYCHOSISED
	dprint "SURPRISED!\n"
	say_quip CHR_JOANNA, 0x12, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "What the?!","Who the?!"
	restart_timer
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x16
	if_chr_idle_action_eq IDLEACTION_SITTING_TYPING, /*goto*/ 0x13
	if_chr_idle_action_eq IDLEACTION_SITTING_DORMANT, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_chr_health CHR_SELF, 40
	goto_next 0x73

	label 0x16
	animation ANIM_SURPRISED_0202, 0, -1, 0x0010, CHR_SELF, 2

	beginloop 0x73
		dprint "S4"
		if_timer_gt 60, /*goto*/ 0x77
	endloop 0x73

	label 0x77
	set_alertness 255
	if_self_flag_bankx_eq CHRFLAG0_CANT_ALERT_GROUP, TRUE, BANK_0, /*goto*/ 0x13
	set_group_alertness 100
	label 0x13
	set_function CHR_SELF, GFUNC_WAKEUP

	//
	// HEAR DETECT
	//
	label LABEL_HEAR_DETECT
	yield
	dprint "S7"
	dprint "HEARDETECT\n"
	say_quip CHR_JOANNA, 0x09, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Did you hear that?","What's that noise?","I heard a noise..."
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEARSPAWN, TRUE, BANK_0, /*goto*/ LABEL_HEARSPAWN
	restart_timer
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, TRUE, BANK_1, /*goto*/ 0x80
	animation ANIM_YAWN, 0, 193, 0x1810, CHR_SELF, 2

	beginloop 0x80
		dprint "S8"
		if_timer_gt 60, /*goto*/ 0x81
	endloop 0x80

	label 0x81
	if_self_flag_bankx_eq CHRFLAG0_00000004, TRUE, BANK_0, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_01000000, TRUE, BANK_1, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	label 0x13
	set_group_alertness 100
	set_function CHR_SELF, GFUNC_WAKEUP

	//
	// HEAR SPAWN
	//
	label LABEL_HEARSPAWN
	dprint "HEARSPAWN\n"
	if_never_been_onscreen /*goto*/ 0x0e
	dprint "NEVER VISFAIL\n"
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	label 0x0e
	if_never_been_onscreen /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	// Never been on screen
	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_00100000, FALSE, BANK_0, /*goto*/ 0x13
	set_alertness 100
	label 0x13
	dprint "CHECK DUPE\n"
	if_chr_death_animation_finished CHR_CLONE, /*goto*/ 0x0e
	if_chr_unloaded CHR_CLONE, /*goto*/ 0x0e
	set_function CHR_SELF, GFUNC_UNALERTED_0001

	label 0x0e
	dprint "CREATE SPAWN\n"
	try_spawn_clone2 CHR_SELF, GFUNC_SEARCH_FOR_PLAYER, 0x00000000, /*goto*/ 0x13
	dprint "CREATE FAIL\n"
	if_self_flag_bankx_eq CHRFLAG0_00100000, TRUE, BANK_0, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	label 0x13
	set_function CHR_SELF, GFUNC_UNALERTED_0001

	//
	// NEAR MISS
	//
	label LABEL_NEAR_MISS
	increase_self_alertness 100
	say_quip CHR_JOANNA, 0x0c, 0xff, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"
	set_target_chr CHR_JOANNA
	if_within_units_of_sight 30, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	goto_next 0x94

	label 0x16
	if_chr_death_animation_finished CHR_VELVET, /*goto*/ 0x16
	set_target_chr CHR_VELVET
	if_within_units_of_sight 30, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	goto_next 0x94

	label 0x16
	goto_next 0x94

	//
	// SEE FRIEND DIE
	//
	label LABEL_SEEFRIENDDIE
	dprint "SEEFRIENDDIE\n"
	if_self_flag_bankx_eq CHRFLAG0_UNSURPRISABLE, FALSE, BANK_0, /*goto*/ 0x17
	label 0x94
	label 0x16
	dprint "SURPRISED!\n"
	say_quip CHR_JOANNA, 0x12, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "What the?!","Who the?!"
	restart_timer
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, TRUE, BANK_1, /*goto*/ 0x76
	animation ANIM_SURPRISED_0202, 0, -1, 0x0010, CHR_SELF, 2

	beginloop 0x76
		dprint "S6"
		if_timer_gt 60, /*goto*/ 0x17
	endloop 0x76

	label 0x17
	if_self_flag_bankx_eq CHRFLAG0_CAN_EXAMINE_BODY, FALSE, BANK_0, /*goto*/ 0x7d
	chr_try_run_to_target_chr_with_hand_up CHR_FRIEND, /*goto*/ 0x7e
	dprint "WALKFAIL\n"

	beginloop 0x7e
		dprint "S9"
		dprint "WALKING\n"
		if_shot_near_chr 0x00, /*goto*/ 0x16
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x13
		if_target_chr_in_sight /*goto*/ 0x16
		label 0x13
		if_self_distance_to_chr_lt 150, CHR_FRIEND, /*goto*/ 0x7f
		if_chr_stopped /*goto*/ 0x7f
	endloop 0x7e

	label 0x16
	goto_first LABEL_SEE_DETECT

	// At friend
	label 0x7f
	restart_timer
	kneel

	beginloop 0x7c
		dprint "T1"
		dprint "EXAM BODY\n"
		if_shot_near_chr 0x00, /*goto*/ 0x16
		set_hear_distance 10000
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_hears_gunfire /*goto*/ 0x16
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x13
		if_target_chr_in_sight /*goto*/ 0x17
		label 0x13
		if_self_flag_bankx_eq CHRFLAG0_CAN_EXAMINE_BODY, FALSE, BANK_0, /*goto*/ 0x13
		if_timer_lt 120, /*goto*/ 0x13
		say_quip CHR_JOANNA, 0x13, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Are you okay?","Got a man down!","He's bought it..."
		unset_self_flag_bankx CHRFLAG0_CAN_EXAMINE_BODY, BANK_0
		label 0x13
		if_timer_gt 600, /*goto*/ 0x7d
	endloop 0x7c

	// Heard gunfire
	label 0x16
	set_alertness 100
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	goto_first LABEL_SCAN_START

	// Saw player
	label 0x17
	set_alertness 100
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	goto_first LABEL_SCAN_START

	// Examination finished
	label 0x7d
	dprint "EXAM BODYDONE\n"
	set_target_chr CHR_JOANNA
	if_within_units_of_sight 30, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_alertness 100
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	goto_first 0xdb

	// Can't see Jonna
	label 0x16
	if_chr_death_animation_finished CHR_VELVET, /*goto*/ 0x16
	set_target_chr CHR_VELVET
	if_within_units_of_sight 30, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_alertness 100
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	goto_first 0xdb

	label 0x16
	set_target_chr CHR_P1P2
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_WAKEUP

	label 0x13
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	// Unreachable - nothing jumps here
	label 0x22
	increase_self_alertness 100
	dprint "SEE OBJECT\n"
	goto_next 0x16

	//
	// HEARD ALARM
	//
	label LABEL_HEARD_ALARM
	dprint "HEARD ALARM\n"
	if_self_flag_bankx_eq CHRFLAG1_00010000, FALSE, BANK_1, /*goto*/ 0x13
	set_self_flag_bankx CHRFLAG0_00100000, BANK_0
	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEARSPAWN, TRUE, BANK_0, /*goto*/ LABEL_HEARSPAWN
	restart_timer
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, TRUE, BANK_1, /*goto*/ 0x82
	animation ANIM_YAWN, 0, 193, 0x1810, CHR_SELF, 2

	beginloop 0x82
		dprint "T2"
		if_timer_gt 60, /*goto*/ 0x81
	endloop 0x82

	label 0x81
	set_group_alertness 100
	set_alertness 255
	set_function CHR_SELF, GFUNC_WAKEUP

	//
	// HEAR SPAWN 2
	//
	label LABEL_HEARSPAWN
	yield
	dprint "HEARSPAWN\n"
	if_never_been_onscreen /*goto*/ 0x0e
	dprint "NEVER VISFAIL\n"
	set_function CHR_SELF, GFUNC_WAKEUP

	label 0x0e
	if_never_been_onscreen /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_WAKEUP

	label 0x13
	dprint "CHECK DUPE\n"
	if_chr_death_animation_finished CHR_CLONE, /*goto*/ 0x0e
	if_chr_unloaded CHR_CLONE, /*goto*/ 0x0e
	if_self_flag_bankx_eq CHRFLAG0_00100000, FALSE, BANK_0, /*goto*/ 0x13
	goto_first LABEL_HEARSPAWN

	label 0x13
	goto_first LABEL_SCAN_START

	label 0x0e
	dprint "CREATE SPAWN\n"
	try_spawn_clone2 CHR_SELF, GFUNC_SEARCH_FOR_PLAYER, 0x00000000, /*goto*/ 0x13
	dprint "CREATE FAIL\n"
	if_self_flag_bankx_eq CHRFLAG0_00100000, FALSE, BANK_0, /*goto*/ 0x16
	goto_first LABEL_HEARSPAWN

	label 0x16
	goto_first LABEL_SCAN_START

	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_00100000, FALSE, BANK_0, /*goto*/ 0x13
	goto_first LABEL_HEARSPAWN

	label 0x13
	set_function CHR_SELF, GFUNC_UNALERTED_0001

	// Unreachable due to set_function above
	increase_self_alertness 255
	goto_next 0x16

	label 0x16
	goto_first LABEL_SCAN_START

	//
	// ALERT FAIL (alertness < 100)
	//
	label 0x78
	if_self_flag_bankx_eq CHRFLAG0_00100000, FALSE, BANK_0, /*goto*/ 0x13
	goto_first 0x0e // create spawn

	label 0x13
	dprint "WARNEDBYFRIEND\n"
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEARSPAWN, FALSE, BANK_0, /*goto*/ 0x13
	set_alertness 0
	goto_first LABEL_HEARSPAWN

	label 0x13
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x7b
	restart_timer
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, TRUE, BANK_1, /*goto*/ 0x7a
	animation ANIM_YAWN, 0, 193, 0x1810, CHR_SELF, 2

	beginloop 0x7a
		dprint "T3"
		if_timer_gt 60, /*goto*/ 0x7b
	endloop 0x7a

	label 0x7b
	dprint "WARNEDBEND\n"
	dprint "WARNEDBEND2\n"
	set_function CHR_SELF, GFUNC_WAKEUP

	// Unreachable - nothing jumps here
	label 0xe4
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_FLEE_FROM_GRENADE

	//
	// AIVSAI pass
	//
	label 0x12
	if_self_flag_bankx_eq CHRFLAG1_00100000, TRUE, BANK_1, /*goto*/ 0x13
	set_return_function CHR_SELF, GFUNC_UNALERTED

	label 0x13
	dprint "WARNEDBEND3\n"
	if_self_flag_bankx_eq CHRFLAG0_UNSURPRISABLE, FALSE, BANK_0, /*goto*/ 0x77
	say_quip CHR_JOANNA, 0x12, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "What the?!","Who the?!"
	restart_timer
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, TRUE, BANK_1, /*goto*/ 0x75
	animation ANIM_SURPRISED_0202, 0, -1, 0x0010, CHR_SELF, 2

	beginloop 0x75
		dprint "S6"
		if_timer_gt 60, /*goto*/ 0x77
	endloop 0x75

	label 0x77
	if_any_chr_doing_action ACTION_WARN_OTHERS, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_RUN_FOR_ALARM, TRUE, BANK_0, /*goto*/ 0x13
	label 0x16
	set_function CHR_SELF, GFUNC_INIT_COMBAT

	label 0x13
	set_function CHR_SELF, GFUNC_WAKEUP

	// Wait until chr finished animation, then become alert.
	// Used when standing up from sitting.
	label 0x0c
	dprint "GOT WAT\n"
	yield
	if_chr_stopped /*goto*/ 0x13
	goto_first 0x0c

	label 0x13
	set_function CHR_SELF, GFUNC_WAKEUP
	endfunction

unregistered_function1:
	dprint "IVEIJURED\n"
	set_function CHR_SELF, GFUNC_WAKEUP
	endfunction

func0008_wakeup:
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_PSYCHOSISED
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED, /*goto*/ 0x13
	goto_next 0x16

	// Psychosised
	label 0x13
	set_return_function CHR_SELF, GFUNC_INIT_PSYCHOSIS
	set_function CHR_SELF, GFUNC_INIT_PSYCHOSIS

	// Unset special death animation if no longer idle
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x13
	set_chr_special_death_animation CHR_SELF, NULL

	// If idle, unset it and stand up or whatever is needed
	label 0x13
	set_onshot_function GFUNC_ALERTED
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x06
	unset_self_flag_bankx CHRFLAG1_DOINGIDLEANIMATION, BANK_1
	if_chr_idle_action_eq IDLEACTION_SITTING_TYPING, /*goto*/ 0x05
	if_chr_idle_action_eq IDLEACTION_SITTING_DORMANT, /*goto*/ 0x05
	goto_next 0x06

	// About to stand up
	label 0x05
	dprint "ANIM OBJECT NOW\n"
	yield
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
	if_chr_dying CHR_SELF, /*goto*/ 0x13
	if_chr_unloaded CHR_SELF, /*goto*/ 0x13
	goto_next 0x15

	// Dead
	label 0x13
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	// Stand up
	label 0x15
	set_chr_health CHR_SELF, 40
	animation ANIM_STAND_UP_FROM_SITTING, 0, -1, 0x0210, CHR_SELF, 2
	object_do_animation 0x025a, 0xff, 0x02ff, 0xff
	goto_next 0x0c

	// Unreachable - nothing jumps here
	label 0x16
	object_do_animation 0x027b, 0xff, 0x02ff, 0xff

	// Wait for stand up animation to finish
	label 0x0c
	dprint "GOT WAT\n"
	yield
	if_chr_stopped /*goto*/ 0x13
	goto_first 0x0c

	label 0x13
	label 0x06
	set_function CHR_SELF, GFUNC_ALERTED
	endfunction

func0007_alerted:
	.set LABEL_DRAW_PISTOL,   0xe7
	.set LABEL_GETGUN_FAILED, 0xaf
	.set LABEL_CLOAKED,       0xeb
	.set LABEL_RUN_FOR_ALARM, 0x9f
	.set LABEL_RETREAT,       0x6b
	.set LABEL_FLANK_LEFT,    0x8f
	.set LABEL_FLANK_RIGHT,   0x90
	.set LABEL_TRACK,         0x34
	.set LABEL_SNIPE,         0xde
	.set LABEL_FLEE_GRENADE,  0xe4

	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_PSYCHOSISED
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_return_function CHR_SELF, GFUNC_INIT_PSYCHOSIS
	set_function CHR_SELF, GFUNC_INIT_PSYCHOSIS

	// If doing idle animation, turn off special death animation
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x13
	set_chr_special_death_animation CHR_SELF, NULL

	// If something, jump to combat
	label 0x13
	unset_self_flag_bankx CHRFLAG1_01000000, BANK_1
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	// is_chr_is_dead_maybe (named wrong) was false
	label 0x16
	set_onshot_function GFUNC_ALERTED
	set_chr_field_0x356 35
	set_unknown_function GFUNC_SEARCH_FOR_PLAYER

	dprint "START LOOP\n"
	if_chr_dying CHR_SELF, /*goto*/ 0x16
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x16
	if_chr_unloaded CHR_SELF, /*goto*/ 0x16
	dprint "NOT DEAD\n"
	goto_next 0x13

	// Dying
	label 0x16
	set_chr_field_0x35e_0x35f 2, 0x00
	set_onshot_function GFUNC_IDLE

	restart_timer

	beginloop 0x1c
		dprint "DIE LOOP\n"
		if_timer_gt 15, /*goto*/ 0x16
	endloop 0x1c

	label 0x16
	say_quip CHR_JOANNA, 0x19, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "You bitch!","Oh... my... god","She got me"
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	// Alive
	label 0x13
	dprint "START LOOP2\n"
	if_just_injured CHR_SELF, /*goto*/ 0x16
	if_has_gun CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Not injured and has gun
	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_CAN_DRAW_PISTOL, TRUE, BANK_1, /*goto*/ LABEL_DRAW_PISTOL
	goto_next 0x1b

	// Injured or no gun
	label 0x16
	restart_timer
	unset_self_flag_bankx CHRFLAG1_00000020, BANK_1
	unset_self_flag_bankx CHRFLAG1_CAN_DRAW_PISTOL, BANK_1
	dprint "CHECKINJURY\n"

	// Say an injury quip if we haven't already, then wait up to 3 seconds for
	// the chr to have finished their injury animation
	beginloop 0x1d
		if_self_flag_bankx_eq CHRFLAG0_SAID_INJURY_QUIP, TRUE, BANK_0, /*goto*/ 0x16
		if_num_times_shot_lt 1, /*goto*/ 0x16
		if_timer_lt 20, /*goto*/ 0x16
		say_quip CHR_JOANNA, 0x0d, 0x28, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Medic!","Help!","You shot me?!"
		say_quip CHR_JOANNA, 0x0e, 0x28, 0x03, 0x01, BANK_0, 0x00, 0x00 // "I'm hit, I'm hit!","I'm taking fire!","Taking damage!"
		set_self_flag_bankx CHRFLAG0_SAID_INJURY_QUIP, BANK_0
		label 0x16
		if_timer_gt 180, /*goto*/ 0x13
		if_chr_stopped /*goto*/ 0x13
	endloop 0x1d

	label 0x13
	stop_chr
	dprint "INJ OVER\n"
	if_self_flag_bankx_eq CHRFLAG1_CAN_DRAW_PISTOL, TRUE, BANK_1, /*goto*/ LABEL_DRAW_PISTOL
	dprint "B4 GUN\n"
	if_has_gun CHR_SELF, /*goto*/ 0x1b
	dprint "LOST MY GUN\n"
	label 0xac
	set_chr_field_0x35e_0x35f 2, 0x00
	say_quip CHR_JOANNA, 0x21, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "My gun!"
	stop_chr
	restart_timer
	yield

	// Wait for gun to land. If it disappears (eg. falls out of geometry), is
	// picked up by the player, or we've been waiting for 5 seconds then go to
	// GETFUN_FAILED.
	label 0xb0
	dprint "WAITING\n"
	yield
	yield
	yield
	if_gun_unclaimed -1, TRUE, /*goto*/ 0x13
	goto_next LABEL_GETGUN_FAILED

	label 0x13
	if_gun_landed TRUE, /*goto*/ 0xb1
	if_timer_gt 300, /*goto*/ LABEL_GETGUN_FAILED
	goto_first 0xb0

	// Note: When if_gun_landed param is FALSE, it's not actually an if
	// statement, but does some task.
	label 0xb1
	restart_timer
	if_gun_landed FALSE, /*goto*/ 0xad

	beginloop 0xad
		dprint "GO FOR GUN\n"
		if_timer_gt 300, /*goto*/ LABEL_GETGUN_FAILED
		if_gun_unclaimed -1, TRUE, /*goto*/ 0x13
		goto_next LABEL_GETGUN_FAILED
		label 0x13
		if_distance_to_target_position_lt 100, /*goto*/ 0x16
		if_chr_stopped /*goto*/ 0x16
	endloop 0xad

	label 0x16
	dprint "AT GUN\n"
	restart_timer
	animation ANIM_PICK_UP_GUN, 0, -1, 0x1010, CHR_SELF, 2

	beginloop 0xae
		if_timer_gt 60, /*goto*/ 0x16
	endloop 0xae

	label 0x16
	if_gun_unclaimed -1, TRUE, /*goto*/ 0x13
	goto_next LABEL_GETGUN_FAILED

	label 0x13
	chr_recover_gun CHR_SELF, /*goto*/ 0x16
	goto_next LABEL_GETGUN_FAILED

	label 0x16
	goto_next 0x1b

	//
	// GETGUN FAILED
	//
	label LABEL_GETGUN_FAILED
	stop_chr
	dprint "GETGUN FAILED\n"
	call_rng
	if_rand_lt 50, /*goto*/ 0xe6
	if_rand_lt 100, /*goto*/ LABEL_DRAW_PISTOL
	set_self_flag_bankx CHRFLAG0_CAN_RETREAT, BANK_0
	set_self_flag_bankx CHRFLAG0_CANT_ALERT_GROUP, BANK_0
	set_self_flag_bankx CHRFLAG0_00200000, BANK_0
	unset_self_flag_bankx CHRFLAG0_00002000, BANK_0
	unset_self_flag_bankx CHRFLAG0_00004000, BANK_0
	unset_self_flag_bankx CHRFLAG0_80000000, BANK_0
	set_self_flag_bankx CHRFLAG1_00000002, BANK_1
	goto_next 0x1b

	label 0xe6
	set_self_flag_bankx CHRFLAG1_00000001, BANK_1
	goto_next 0x1b

	//
	// DRAW PISTOL
	//
	label LABEL_DRAW_PISTOL
	call_rng
	if_rand_lt 82, /*goto*/ 0x13
	if_rand_lt 164, /*goto*/ 0x15
	animation ANIM_DRAW_PISTOL_0288, 0, -1, 0x1010, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	animation ANIM_DRAW_PISTOL_0289, 0, -1, 0x1010, CHR_SELF, 2
	goto_next 0x16

	label 0x15
	animation ANIM_DRAW_PISTOL_0245, 0, -1, 0x1010, CHR_SELF, 2

	label 0x16
	if_stage_is_not STAGE_AIRFORCEONE, /*goto*/ 0x13
	try_draw_weapon MODEL_CHRCYCLONE, WEAPON_CYCLONE, 0x00000000, /*goto*/ 0xe5
	label 0x13
	try_draw_weapon MODEL_CHRFALCON2, WEAPON_FALCON2, 0x00000000, /*goto*/ 0xe5

	beginloop 0xe5
		if_chr_stopped /*goto*/ 0x16
	endloop 0xe5

	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_CAN_DRAW_PISTOL, TRUE, BANK_1, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG0_80000000, BANK_0
	label 0x13
	unset_self_flag_bankx CHRFLAG1_CAN_DRAW_PISTOL, BANK_1
	label 0x16

	//
	// Lots of things go here
	//
	label 0x1b
	yield
	label 0x16
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_00002000, /*goto*/ 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_BUDDY_PLACED, /*goto*/ 0x01
	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ LABEL_TRACK
	dprint "CHECKINJURYEND\n"

	// Consider warning others in team
	dprint "B4 TEAM CHECK\n"
	if_alarm_active /*goto*/ 0x16
	if_any_chr_doing_action ACTION_WARN_OTHERS, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_RUN_FOR_ALARM, TRUE, BANK_0, /*goto*/ LABEL_RUN_FOR_ALARM

	// No need to warn
	label 0x16
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	goto_next 0x16

	// Unreachable - nothing jumps here
	label 0x13
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_alertness 0
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	// This flag appears to control whether the chr can declare that they're
	// attempting to surround the player. These quips are never said though, so
	// either the flag is never set for anyone or the field_0x201 values are
	// something different.
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x93
	if_field_0x2a1_eq ACTION_FLANK_LEFT, /*goto*/ 0x13
	if_field_0x2a1_eq ACTION_FLANK_RIGHT, /*goto*/ 0x15
	goto_next 0x93

	label 0x13
	say_quip CHR_JOANNA, 0x07, 0x28, 0x03, 0x01, BANK_0, 0x00, 0x00 // "Wipe the target!","Let's split up!","Surround her!"
	goto_next LABEL_FLANK_LEFT

	label 0x15
	say_quip CHR_JOANNA, 0x07, 0x28, 0x03, 0x01, BANK_0, 0x00, 0x00 // "Wipe the target!","Let's split up!","Surround her!"
	goto_next LABEL_FLANK_RIGHT

	// Attempt trap (hide and ambush when player gets near)
	label 0x93
	if_self_flag_bankx_eq CHRFLAG0_CANT_ALERT_GROUP, TRUE, BANK_0, /*goto*/ LABEL_RETREAT
	if_self_flag_bankx_eq CHRFLAG0_CAN_TRAP, TRUE, BANK_0, /*goto*/ 0x13
	dprint "TRAP NOT SET\n"
	if_self_flag_bankx_eq CHRFLAG0_00000004, FALSE, BANK_0, /*goto*/ 0x16
	label 0x13
	dprint "VIS\n"
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x98

	label 0x16
	dprint "TRAP FAILED\n"
	if_self_flag_bankx_eq CHRFLAG0_02000000, TRUE, BANK_0, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_01000000, FALSE, BANK_0, /*goto*/ 0x16
	label 0x13
	dprint "VIS\n"
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0xa1

	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_10000000, FALSE, BANK_0, /*goto*/ 0x16
	label 0x13
	dprint "IM GOING TO POP\n"
	goto_next 0xa4

	// Not popping
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_CAN_SNIPE, FALSE, BANK_1, /*goto*/ 0x16
	label 0x13
	dprint "IM GOING TO SNIPE\n"
	goto_next LABEL_SNIPE

	label 0x16
	dprint "AMBUSH FAILED\n"
	if_self_flag_bankx_eq CHRFLAG0_CAN_RETREAT, FALSE, BANK_0, /*goto*/ 0x16
	if_num_times_shot_lt 1, /*goto*/ 0x16
	if_retreat_risk_lt 3, /*goto*/ LABEL_RETREAT
	dprint "RISK FAILED\n"
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_00004000, TRUE, BANK_0, /*goto*/ 0x91
	if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0x92
	label 0x91
	if_retreat_risk_lt 5, /*goto*/ 0x52
	label 0x92
	goto_next 0x68

	//
	// TRAP/AMBUSH
	//
	label 0x98
	dprint "GOING TO TRAP PAD\n"
	go_to_target_pad SPEED_JOG

	beginloop 0x99
		label 0x16
		if_chr_stopped /*goto*/ 0x16
	endloop 0x99

	label 0x16
	dprint "AT TRAP PAD\n"
	label 0x9b
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x03

	beginloop 0x03
		if_in_disarm_range /*goto*/ 0x9a
		cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
		goto_next 0xef

		label 0xee
		consider_coop_for_p1p2_chr CHR_SELF
		cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
		set_target_chr CHR_P1P2
		if_in_disarm_range /*goto*/ 0x9a
		label 0xee
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		label 0xef
	endloop 0x03

	// Aiming only
	label 0x9a
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0x04

	beginloop 0x04
		if_chr_stopped /*goto*/ 0x16
	endloop 0x04

	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_TRAP, TRUE, BANK_0, /*goto*/ 0x16
	if_chr_distance_lt 800, /*goto*/ 0x9c
	label 0x16
	goto_first 0x9b

	label 0x9c
	unset_self_flag_bankx CHRFLAG0_00000004, BANK_0
	goto_first 0x1b

	label 0xa1
	kneel

	beginloop 0xa2
		dprint "WAIT FOR AMB\n"
		if_in_disarm_range /*goto*/ 0xa3
		dprint "AMB1\n"
		if_distance_to_pad_gt2 200, TARGET_PAD, /*goto*/ 0x13
		dprint "AMB2\n"
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_enemy_distance_lt_and_los 1200, /*goto*/ 0xee
	endloop 0xa2

	label 0xee
	if_chr_lost_track_of_target_maybe /*goto*/ 0x13
	set_return_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label 0x13
	dprint "AMBUSH PLAYER\n"
	set_accuracy 30
	set_self_flag_bankx CHRFLAG0_02000000, BANK_0
	say_quip CHR_JOANNA, 0x01, 0x50, 0x02, 0x01, BANK_0, 0x00, 0x00 // "Open fire!","Wipe her out!","Waste her!"
	goto_first 0x1b

	label 0xa3
	dprint "SEENTARG\n" // seen target
	unset_self_flag_bankx CHRFLAG0_01000000, BANK_0
	goto_first 0x1b

	//
	// POP
	//
	label 0xa4
	if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0xa8
	cmd0121_if_something 0xa0b5, /*goto*/ 0xa5
	dprint "POPPER FAILED\n"
	goto_next 0x52

	label 0xa5
	dprint "GO TO POPPER\n"
	set_action ACTION_GO_TO_COVER, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	label 0x16
	cmd0124_run_for_cover_maybe 2

	beginloop 0xa6
		if_chr_stopped /*goto*/ 0xa7
	endloop 0xa6

	label 0xa7
	dprint "UNDER POPPER\n"
	label 0xa8
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0xa9

	beginloop 0xa9
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_near_miss /*goto*/ 0x13
		if_shot_near_chr 0x00, /*goto*/ 0x13
		if_saw_death 0x00, /*goto*/ 0x13
		if_in_disarm_range /*goto*/ 0x13
	endloop 0xa9

	label 0x13
	call_rng
	if_rand_gt 150, /*goto*/ 0x13
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0xaa
	label 0x13
	kneel
	restart_timer

	beginloop 0xab
		set_target_chr CHR_P1P2
		if_chr_distance_gt 300, /*goto*/ 0x13
		unset_self_flag_bankx CHRFLAG0_10000000, BANK_0
		goto_first 0x1b

		label 0x13
		call_rng
		if_rand_gt 250, /*goto*/ 0x13
		if_timer_gt 240, /*goto*/ 0x16
	endloop 0xab

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0x13
	goto_first 0xa8

	label 0x13
	if_in_disarm_range /*goto*/ 0x13
	goto_first 0xa8

	label 0x13
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0x13
	goto_first 0xa8

	label 0x13

	beginloop 0xaa
		if_chr_stopped /*goto*/ 0x16
	endloop 0xaa

	label 0x16
	goto_first 0xa8

	//
	// SNIPE
	//
	label LABEL_SNIPE
	unset_self_flag_bankx CHRFLAG0_80000000, BANK_0
	yield
	if_chr_distance_lt 1000, /*goto*/ 0x16
	if_chr_distance_gt 2500, /*goto*/ 0x14

	// Distance between 1000 and 2500
	if_angle_to_target_chr_lt 10, /*goto*/ 0x13
	cmd004f 246, /*goto*/ 0x13
	restart_timer
	stop_chr
	try_face_entity 0x0200, 0x0000, /*goto*/ 0xec

	beginloop 0xec
		if_angle_to_target_chr_lt 10, /*goto*/ 0x13
		cmd004f 246, /*goto*/ 0x13
		if_timer_gt 60, /*goto*/ 0x13
	endloop 0xec

	label 0x13
	if_in_disarm_range /*goto*/ 0x13
	cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
	goto_next 0xef

	label 0xee
	consider_coop_for_p1p2_chr CHR_SELF
	cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
	set_target_chr CHR_P1P2
	if_in_disarm_range /*goto*/ 0x13
	label 0xee
	consider_coop_for_p1p2_chr CHR_SELF
	set_target_chr CHR_P1P2
	label 0xef
	goto_first LABEL_SNIPE

	// Distance > 2500
	label 0x14
	try_run_to_target_chr /*goto*/ 0xe1

	beginloop 0xe1
		if_chr_distance_lt 2500, /*goto*/ 0x15
	endloop 0xe1

	label 0x15
	goto_first LABEL_SNIPE

	label 0x13
	restart_timer
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	cmd01ba 0x0022, 0x0000, /*goto*/ 0xdf

	beginloop 0xdf
		if_chr_distance_lt 1000, /*goto*/ 0x16
		if_timer_gt 300, /*goto*/ 0x13
	endloop 0xdf

	label 0x13
	if_in_disarm_range /*goto*/ 0x13
	set_self_flag_bankx CHRFLAG0_80000000, BANK_0
	stop_chr
	goto_first 0x1b

	label 0x13
	restart_timer
	set_accuracy 100
	cmd01ba 0x0200, 0x0000, /*goto*/ 0xe0
	dprint "SNIPER NO SHOOT\n"

	beginloop 0xe0
		dprint "SNIPER  SHOOT\n"
		if_chr_stopped /*goto*/ 0x13
	endloop 0xe0

	label 0x13
	set_accuracy 10
	stop_chr
	goto_first LABEL_SNIPE

	// Distance < 1000
	label 0x16
	stop_chr
	unset_self_flag_bankx CHRFLAG1_CAN_SNIPE, BANK_1
	set_self_flag_bankx CHRFLAG0_80000000, BANK_0
	restart_timer

	beginloop 0xbd
		if_timer_gt 60, /*goto*/ 0x13
	endloop 0xbd

	label 0x13
	goto_first 0x1b

	//
	// POPPER/AMBUSH FAILED
	//
	label 0x52
	dprint "AMBUSH FAILED3\n"
	if_player_looking_at_something_maybe 0x3c, 0x01, 0x00, /*goto*/ 0x16
	goto_next 0x68

	label 0x16
	dprint "AMBUSH FAILED4\n"
	if_self_flag_bankx_eq CHRFLAG0_00000010, TRUE, BANK_0, /*goto*/ 0x16
	goto_next 0x5b

	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_00000080, TRUE, BANK_0, /*goto*/ 0x13
	call_rng
	if_rand_gt 100, /*goto*/ 0x13
	if_player_looking_at_something_maybe 0x1e, 0x01, 0x00, /*goto*/ 0x16
	label 0x13
	if_within_units_of_sight 30, /*goto*/ 0x5f
	label 0x16
	if_within_units_of_sight 30, /*goto*/ 0x16
	cmd0126_if_something /*goto*/ 0x69
	if_chr_distance_gt 2000, /*goto*/ 0x61
	goto_next 0x16

	label 0x69
	if_chr_distance_gt 4000, /*goto*/ 0x61
	label 0x16
	dprint "OKFORCOVER\n"
	if_in_disarm_range /*goto*/ 0x5b
	if_within_units_of_sight 30, /*goto*/ 0x5b
	if_chr_in_view /*goto*/ 0x5b
	goto_next 0x56

	label 0x5b
	dprint "COVER INVALID\n"
	if_self_flag_bankx_eq CHRFLAG1_00004000, TRUE, BANK_1, /*goto*/ 0x15
	if_self_flag_bankx_eq CHRFLAG0_00000040, TRUE, BANK_0, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_08000000, FALSE, BANK_0, /*goto*/ 0x5c
	cmd0121_if_something 0x10b5, /*goto*/ 0x53
	goto_next 0x14

	label 0x5c
	cmd0121_if_something 0x1035, /*goto*/ 0x53
	goto_next 0x14

	label 0x16
	cmd0121_if_something 0x0035, /*goto*/ 0x53
	goto_next 0x14

	label 0x15
	dprint "SOFT COVER\n"
	if_self_flag_bankx_eq CHRFLAG0_00000040, TRUE, BANK_0, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_08000000, FALSE, BANK_0, /*goto*/ 0x5c
	cmd0121_if_something 0x90b5, /*goto*/ 0x53
	goto_next 0x14

	label 0x5c
	cmd0121_if_something 0x9035, /*goto*/ 0x53
	goto_next 0x14

	label 0x16
	cmd0121_if_something 0x8035, /*goto*/ 0x53
	goto_next 0x14

	label 0x14
	goto_next 0x54

	label 0x53
	dprint "GO TO COVER\n"
	set_action ACTION_GO_TO_COVER, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_SYNC_SHOOT, /*goto*/ 0x16
	label 0x16
	say_quip CHR_JOANNA, 0x02, 0xff, 0x02, 0x01, BANK_0, 0x00, 0x00
	restart_timer
	cmd0124_run_for_cover_maybe ACTION_UNDER_COVER

	beginloop 0x55
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
		if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
		if_chr_distance_lt 120, /*goto*/ 0x16
		call_rng
		if_rand_lt 128, /*goto*/ 0x13
		if_chr_distance_gt 250, /*goto*/ 0x13
		label 0x16
		if_in_disarm_range /*goto*/ 0x16
		goto_next 0x13

		label 0x16
		set_return_function CHR_SELF, GFUNC_ALERTED
		set_function CHR_SELF, GFUNC_HAND_COMBAT

		label 0x13
		if_timer_gt 300, /*goto*/ 0x56
		if_chr_stopped /*goto*/ 0x56
	endloop 0x55

	label 0x56
	set_self_flag_bankx CHRFLAG0_00000010, BANK_0
	dprint "UNDER COVER\n"
	label 0x58
	set_follow_chr TARGET_CHR
	restart_timer
	set_action ACTION_UNDER_COVER, TRUE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x59

	beginloop 0x59
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_within_units_of_sight 30, /*goto*/ 0x5f
		if_timer_gt 240, /*goto*/ 0x61
		if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x93
		if_field_0x2a1_nonzero /*goto*/ 0x84
		label 0x93
		label 0x5a
	endloop 0x59

	label 0x61
	set_target_chr FOLLOW_CHR
	dprint "BREAK COVER\n"
	if_self_flag_bankx_eq CHRFLAG0_00008000, TRUE, BANK_0, /*goto*/ 0x66
	label 0x16
	goto_next 0x16

	label 0x66
	cmd0126_if_something /*goto*/ 0x69
	if_chr_distance_gt 2000, /*goto*/ 0x16
	goto_next 0x6a

	label 0x69
	if_chr_distance_gt 4000, /*goto*/ 0x16
	label 0x6a
	if_player_looking_at_something_maybe 0x11, 0x01, 0x00, /*goto*/ 0x63
	label 0x16
	label 0x64
	set_action ACTION_BREAKING_COVER, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_BREAKING_COVER, /*goto*/ 0x16
	label 0x16
	cmd012f
	restart_timer
	try_run_to_target_chr /*goto*/ 0x62

	beginloop 0x62
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_in_disarm_range /*goto*/ 0x5f
		cmd0126_if_something /*goto*/ 0x69
		if_chr_distance_gt 2000, /*goto*/ 0x65
		goto_next 0x16

		label 0x69
		if_chr_distance_gt 4000, /*goto*/ 0x65
		label 0x16
		if_timer_gt 120, /*goto*/ 0x63
		label 0x65
	endloop 0x62

	label 0x63
	if_self_flag_bankx_eq CHRFLAG0_00008000, FALSE, BANK_0, /*goto*/ 0x13
	if_player_looking_at_something_maybe 0x11, 0x01, 0x00, /*goto*/ 0x16
	goto_first 0x64

	label 0x13
	set_self_flag_bankx CHRFLAG1_01000000, BANK_1
	goto_next LABEL_TRACK

	label 0x16
	stop_chr
	yield
	cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
	dprint "BACK TO COVER\n"
	goto_first 0x52

	label 0x5f
	cmd012f
	dprint "SEECOVER\n"
	set_action ACTION_SEE_COVER, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_SEE_COVER, /*goto*/ 0x16
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x93
	if_field_0x2a1_nonzero /*goto*/ 0x84
	label 0x93
	if_in_disarm_range /*goto*/ 0x26
	goto_next 0x87

	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
	if_chr_distance_lt 120, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x13
	label 0x16
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00002000, FALSE, BANK_1, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG1_00002000, BANK_1
	goto_next 0x48

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	call_rng
	if_rand_lt 10, /*goto*/ 0x57
	if_rand_gt 64, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000010, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x5a64
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	goto_next 0x60

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000004, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x141e
	goto_next 0x60

	label 0x13
	label 0x16
	call_rng
	if_rand_gt 50, /*goto*/ 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x16
	label 0xbe
	try_roll_and_shoot /*goto*/ 0x60
	label 0x16
	try_walk_and_shoot /*goto*/ 0x60
	label 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x8c
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x16
	label 0x8c
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0x16
	label 0x16
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0x60

	beginloop 0x60
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x5e
	endloop 0x60

	label 0x57
	say_quip CHR_JOANNA, 0x27, 0xfe, 0x03, 0xff, BANK_0, 0x00, 0x00
	do_special_animation -2
	goto_next 0xe8

	label 0x5e
	call_rng
	if_rand_lt 20, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000020, FALSE, BANK_1, /*goto*/ 0x13
	label 0x16
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	restart_timer
	animation ANIM_RELOAD_0209, 0, -1, 0x1010, CHR_SELF, 2

	beginloop 0xe8
		if_self_flag_bankx_eq CHRFLAG1_00000020, FALSE, BANK_1, /*goto*/ 0x16
		if_timer_lt 120, /*goto*/ 0x16
		assign_sound 0x80f6, CHANNEL_7
		play_sound_from_entity CHANNEL_7, CHR_SELF, 0x0bb8, 0x1770, 0x01
		unset_self_flag_bankx CHRFLAG1_00000020, BANK_1
		label 0x16
		if_chr_stopped /*goto*/ 0x13
	endloop 0xe8

	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_01000000, FALSE, BANK_0, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG0_01000000, BANK_0
	set_accuracy 0
	label 0x13
	cmd0125_if_or_try_something /*goto*/ 0x16
	label 0x16
	goto_first 0x1b

	label 0x54
	dprint "NO COVERAVAILABLE\n"
	label 0x68
	if_in_disarm_range /*goto*/ 0x24
	goto_next 0x25

	label 0x25
	dprint "HECANT SEE ME\n"
	goto_next 0x2f

	label 0x24
	label 0x4e
	if_self_flag_bankx_eq CHRFLAG0_CAN_RETREAT, FALSE, BANK_0, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_CANT_ALERT_GROUP, TRUE, BANK_0, /*goto*/ LABEL_RETREAT
	if_num_times_shot_lt 1, /*goto*/ 0x16
	if_retreat_risk_lt 3, /*goto*/ LABEL_RETREAT
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_00004000, TRUE, BANK_0, /*goto*/ 0x91
	if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0x4d
	label 0x91
	if_retreat_risk_lt 5, /*goto*/ 0x32
	goto_next 0x4d

	label 0x4d
	if_self_flag_bankx_eq CHRFLAG1_00040000, TRUE, BANK_1, /*goto*/ 0x32
	call_rng
	if_player_looking_at_something_maybe 0x1e, 0x01, 0x00, /*goto*/ 0x16
	goto_next 0x32

	label 0x16
	if_rand_lt 128, /*goto*/ 0x32
	label 0x31
	dprint "FLANK\n"
	label 0x16
	label 0x13
	dprint "FLANK BEST\n"
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	cmd0139 25, 0x02, TRUE
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_FLANK_LEFT, /*goto*/ 0x16
	cmd0133 ACTION_FLANK_RIGHT, /*goto*/ 0x16
	label 0x16
	goto_next 0x33

	label LABEL_FLANK_LEFT
	dprint "FLANK LEFT\n"
	set_action ACTION_FLANK_LEFT, FALSE
	cmd0139 335, 0x02, FALSE
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_FLANK_LEFT, /*goto*/ 0x16
	label 0x16
	goto_next 0x33

	label LABEL_FLANK_RIGHT
	dprint "FLANK RIGHT\n"
	set_action ACTION_FLANK_RIGHT, FALSE
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_FLANK_RIGHT, /*goto*/ 0x16
	label 0x16
	cmd0139 25, 0x02, FALSE
	label 0x33
	set_self_flag_bankx CHRFLAG1_00040000, BANK_1
	restart_timer

	beginloop 0x30
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
		if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
		if_chr_distance_lt 120, /*goto*/ 0x16
		call_rng
		if_rand_lt 128, /*goto*/ 0x13
		if_chr_distance_gt 250, /*goto*/ 0x13
		label 0x16
		if_in_disarm_range /*goto*/ 0x16
		goto_next 0x13

		label 0x16
		set_return_function CHR_SELF, GFUNC_ALERTED
		set_function CHR_SELF, GFUNC_HAND_COMBAT

		label 0x13
		if_chr_stopped /*goto*/ 0x32
		if_timer_gt 180, /*goto*/ 0x32
	endloop 0x30

	// Unreachable - no label
	goto_next 0x2f
	if_self_flag_bankx_eq CHRFLAG1_00020000, TRUE, BANK_1, /*goto*/ 0x2f

	label 0x32
	if_player_looking_at_something_maybe 0x14, 0x01, 0x00, /*goto*/ 0x16
	goto_next 0x2f

	label 0x16
	call_rng
	if_rand_gt 100, /*goto*/ 0x2f
	if_chr_in_view /*goto*/ 0x18
	label 0x2f
	dprint "C 1\n"
	if_chr_distance_gt 1300, /*goto*/ LABEL_TRACK
	if_in_disarm_range /*goto*/ 0x26
	dprint "C 2\n"
	if_self_flag_bankx_eq CHRFLAG0_CAN_RETREAT, FALSE, BANK_0, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG0_CANT_ALERT_GROUP, TRUE, BANK_0, /*goto*/ LABEL_RETREAT
	if_num_times_shot_lt 1, /*goto*/ 0x16
	if_retreat_risk_lt 3, /*goto*/ LABEL_RETREAT
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_00004000, TRUE, BANK_0, /*goto*/ 0x91
	if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0x4d
	label 0x91
	if_retreat_risk_lt 5, /*goto*/ 0x51
	label 0x4d
	dprint "C 3\n"
	if_self_flag_bankx_eq CHRFLAG0_00008000, TRUE, BANK_0, /*goto*/ 0x48
	goto_next LABEL_TRACK

	label 0x51
	if_player_looking_at_something_maybe 0x15, 0x01, 0x00, /*goto*/ 0x16
	goto_next LABEL_TRACK

	//
	// GRENADE THROWING
	//
	label 0x16
	dprint "C 4\n"
	kneel
	yield
	cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
	label 0x48
	dprint "GRENADEP\n"
	set_grenade_probability_out_of_255 255
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_THROW_GRENADES, TRUE, BANK_0, /*goto*/ 0x16
	goto_next 0x4c

	label 0x16
	if_chr_distance_lt 500, /*goto*/ 0x4c
	dprint "GRENADE\n"
	restart_timer
	if_any_chr_doing_action ACTION_THROW_GRENADE, /*goto*/ 0x4c
	dprint "ACTION GRENADE\n"
	set_action ACTION_THROW_GRENADE, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	consider_throwing_grenade 0x0200, 0x0000, /*goto*/ 0x46
	goto_next 0x4c

	dprint "GRENADEFAIL\n"

	beginloop 0x46
		if_chr_stopped /*goto*/ 0x16
	endloop 0x46

	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x47
	cmd0133 ACTION_THROW_GRENADE, /*goto*/ 0x47

	beginloop 0x47
		say_quip CHR_JOANNA, 0x05, 0xff, 0x07, 0x00, BANK_0, 0x00, 0x00
		if_chr_stopped /*goto*/ 0x4a
	endloop 0x47

	label 0x4a
	if_timer_lt 60, /*goto*/ 0x49
	dprint "GRENADESTOP\n"
	set_action ACTION_GRENADE_STOP, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	restart_timer
	try_face_entity 0x0200, 0x0000, /*goto*/ 0x4b

	beginloop 0x4b
		if_within_units_of_sight 30, /*goto*/ 0x42
		if_chr_in_view /*goto*/ 0x42
		cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
		goto_next 0xef

		label 0xee
		consider_coop_for_p1p2_chr CHR_SELF
		cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
		set_target_chr CHR_P1P2
		if_within_units_of_sight 30, /*goto*/ 0x42
		if_chr_in_view /*goto*/ 0x42
		label 0xee
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		label 0xef
		if_timer_gt 240, /*goto*/ 0x49
	endloop 0x4b

	label 0x49
	label 0x4c
	restart_timer
	dprint "WAITING\n"
	set_action ACTION_WAIT, TRUE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x40

	beginloop 0x40
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_self_flag_bankx_eq CHRFLAG0_00004000, TRUE, BANK_0, /*goto*/ 0x91
		if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0x16
		label 0x91
		if_retreat_risk_lt 5, /*goto*/ 0x41
		label 0x16
		if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x93
		if_field_0x2a1_nonzero /*goto*/ 0x84
		label 0x93
		if_within_units_of_sight 30, /*goto*/ 0x42
		cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
		goto_next 0xef
		label 0xee
		consider_coop_for_p1p2_chr CHR_SELF
		cmd0108_if_something CHR_SELF, CHR_P1P2, FALSE, /*goto*/ 0xee
		set_target_chr CHR_P1P2
		if_within_units_of_sight 30, /*goto*/ 0x42
		label 0xee
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		label 0xef
		if_timer_gt 600, /*goto*/ 0x3d
		if_timer_gt 60, /*goto*/ 0x16
		label 0x16
		if_player_looking_at_something_maybe 0x15, 0x01, 0x00, /*goto*/ 0x16
		goto_next LABEL_TRACK
		label 0x16
		if_chr_distance_gt 2000, /*goto*/ 0x41
	endloop 0x40

	label 0x42
	dprint "SEEWAIT\n"
	set_action ACTION_SEEWAIT, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	dprint "SEEWAIT2\n"
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_SEEWAIT, /*goto*/ 0x16
	label 0x16
	dprint "SEEWAIT3\n"
	if_in_disarm_range /*goto*/ 0x8a
	restart_timer
	try_run_to_target_chr /*goto*/ 0x89

	beginloop 0x89
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_self_flag_bankx_eq CHRFLAG0_00004000, TRUE, BANK_0, /*goto*/ 0x91
		if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0x16
		label 0x91
		if_retreat_risk_lt 5, /*goto*/ 0x41
		label 0x16
		if_in_disarm_range /*goto*/ 0x8a
		if_timer_gt 60, /*goto*/ 0x29
	endloop 0x89

	label 0x8a
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
	if_chr_distance_lt 120, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x13
	label 0x16
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00002000, FALSE, BANK_1, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG1_00002000, BANK_1
	goto_first 0x48

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	call_rng
	if_rand_lt 10, /*goto*/ 0x57
	if_rand_gt 64, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000010, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x5a64
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	goto_next 0x43

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000004, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x141e
	goto_next 0x43

	label 0x13
	label 0x16
	call_rng
	if_rand_gt 50, /*goto*/ 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x16
	label 0xbe
	try_roll_and_shoot /*goto*/ 0x43
	label 0x16
	try_walk_and_shoot /*goto*/ 0x43
	label 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x8c
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0x16
	label 0x8c
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x16
	label 0x16
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0x43

	beginloop 0x43
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x29
	endloop 0x43

	label 0x57
	say_quip CHR_JOANNA, 0x27, 0xfe, 0x03, 0xff, BANK_0, 0x00, 0x00
	do_special_animation -2
	goto_next 0xe9

	label 0x29
	if_self_flag_bankx_eq CHRFLAG0_01000000, FALSE, BANK_0, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG0_01000000, BANK_0
	set_accuracy 0
	label 0x13
	if_chr_injured_target CHR_SELF, /*goto*/ 0x13
	say_quip CHR_JOANNA, 0x16, 0x19, 0x03, 0x00, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x17, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00
	goto_next 0x16

	label 0x13
	say_quip CHR_JOANNA, 0x15, 0x19, 0x02, 0x00, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x15, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00
	label 0x16
	call_rng
	if_rand_lt 20, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000020, FALSE, BANK_1, /*goto*/ 0x13
	label 0x16
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	restart_timer
	animation ANIM_RELOAD_0209, 0, -1, 0x1010, CHR_SELF, 2
	label 0xe9
	yield
	if_self_flag_bankx_eq CHRFLAG1_00000020, FALSE, BANK_1, /*goto*/ 0x16
	if_timer_lt 120, /*goto*/ 0x16
	assign_sound 0x80f6, CHANNEL_6
	play_sound_from_entity CHANNEL_6, CHR_SELF, 0x0bb8, 0x1770, 0x01
	unset_self_flag_bankx CHRFLAG1_00000020, BANK_1
	label 0x16
	if_chr_stopped /*goto*/ 0x13
	goto_first 0xe9

	label 0x13
	label 0x8b
	dprint "BACKOFF\n"
	if_player_looking_at_something_maybe 0x14, 0x01, 0x00, /*goto*/ 0x13
	goto_next 0x50

	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_CAN_BACKOFF, TRUE, BANK_0, /*goto*/ 0x16
	goto_next 0x50

	label 0x16
	set_action ACTION_BACKOFF, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	restart_timer
	retreat 0x02, 0x01
	cmd012f

	beginloop 0x4f
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_timer_gt 120, /*goto*/ 0x50
		if_chr_stopped /*goto*/ 0x50
	endloop 0x4f

	label 0x50
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
	if_chr_distance_lt 120, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x13
	label 0x16
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x13
	cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	goto_next 0x16

	label 0x13
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_alertness 0
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	if_self_flag_bankx_eq CHRFLAG0_04000000, TRUE, BANK_0, /*goto*/ 0x16
	call_rng
	if_rand_gt 196, /*goto*/ 0x16
	goto_next LABEL_TRACK

	label 0x16
	goto_first 0x1b

	label 0x3d
	dprint "WAITTIMEOUT\n"
	if_self_flag_bankx_eq CHRFLAG0_CAN_TRAP, FALSE, BANK_0, /*goto*/ 0x13
	goto_first 0x1b

	label 0x13
	set_action ACTION_16, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_16, /*goto*/ 0x16
	label 0x16
	goto_next 0x3f

	// Unreachable - no label
	dprint "WAITMOVE\n"
	try_run_sideways /*goto*/ 0x3e

	beginloop 0x3e
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x3f
	endloop 0x3e

	label 0x3f
	goto_first 0x1b

	label 0x41
	goto_first 0x1b

	label LABEL_TRACK
	set_follow_chr TARGET_CHR
	dprint "TRACK\n"
	set_action ACTION_FOLLOW, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	restart_timer
	label 0xf7
	try_run_to_target_chr /*goto*/ 0x35

	beginloop 0x35
		if_chr_flag_bank2 CHR_SELF, CHRFLAG2_00002000, /*goto*/ 0x13
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_BUDDY_PLACED, /*goto*/ 0x01
		label 0x13
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
		if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
		if_chr_distance_lt 120, /*goto*/ 0x16
		call_rng
		if_rand_lt 128, /*goto*/ 0x13
		if_chr_distance_gt 250, /*goto*/ 0x13
		label 0x16
		if_in_disarm_range /*goto*/ 0x16
		goto_next 0x13

		label 0x16
		set_return_function CHR_SELF, GFUNC_ALERTED
		set_function CHR_SELF, GFUNC_HAND_COMBAT

		label 0x13
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_chr_distance_gt 1300, /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG1_01000000, TRUE, BANK_1, /*goto*/ 0x16
		if_self_flag_bankx_eq CHRFLAG1_02000000, FALSE, BANK_1, /*goto*/ 0x16
		if_player_looking_at_something_maybe 0x15, 0x01, 0x00, /*goto*/ 0x3b
		goto_next 0x16

		label 0xc8
		unset_self_flag_bankx CHRFLAG1_02000000, BANK_1
		goto_first 0x31

		label 0x16
		if_in_disarm_range /*goto*/ 0x26
		label 0x13
		dprint "NOSEEPLAYER\n"
		if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ 0x13
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0x16
		goto_next 0x13

		label 0x16
		if_chr_lost_track_of_target_maybe /*goto*/ 0x13
		set_return_function CHR_SELF, GFUNC_UNALERTED
		set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

		label 0x13
		if_chr_distance_gt 1300, /*goto*/ 0x3c
		if_self_flag_bankx_eq CHRFLAG0_CAN_RETREAT, FALSE, BANK_0, /*goto*/ 0x16
		if_self_flag_bankx_eq CHRFLAG0_CANT_ALERT_GROUP, TRUE, BANK_0, /*goto*/ LABEL_RETREAT
		if_num_times_shot_lt 1, /*goto*/ 0x16
		if_retreat_risk_lt 3, /*goto*/ LABEL_RETREAT
		label 0x16
		if_self_flag_bankx_eq CHRFLAG0_00004000, TRUE, BANK_0, /*goto*/ 0x91
		if_self_flag_bankx_eq CHRFLAG0_00002000, TRUE, BANK_0, /*goto*/ 0x4d
		label 0x91
		if_retreat_risk_lt 5, /*goto*/ 0x39
		label 0x4d
		if_self_flag_bankx_eq CHRFLAG0_00008000, TRUE, BANK_0, /*goto*/ 0x3a
		goto_next 0x3c

		label 0x39
		if_self_flag_bankx_eq CHRFLAG1_01000000, TRUE, BANK_1, /*goto*/ 0x3c
		if_player_looking_at_something_maybe 0x15, 0x01, 0x00, /*goto*/ 0x3b
		if_chr_distance_lt 1300, /*goto*/ 0x3b
		goto_next 0x17

		label 0x3a
		if_self_flag_bankx_eq CHRFLAG1_01000000, TRUE, BANK_1, /*goto*/ 0x3c
		if_player_looking_at_something_maybe 0x15, 0x01, 0x00, /*goto*/ 0x3b
		goto_next 0x3c

		label 0x3c
		dprint "NOANG\n"
		label 0x17
		if_chr_stopped /*goto*/ 0x13
		if_timer_gt 600, /*goto*/ 0x36
	endloop 0x35

	label 0x13
	dprint "COMPLETED\n"
	set_target_chr FOLLOW_CHR
	goto_first 0xf7

	label 0x36
	set_target_chr FOLLOW_CHR
	dprint "END TRACK\n"
	set_alertness 0
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER
	goto_first 0x1b

	label 0x3b
	goto_first 0x1b

	label 0x37
	goto_first 0x1b

	//
	// SYNC SHOOT
	//
	label 0x87
	dprint "SYNC SHOOT\n"
	cmd012f
	set_action ACTION_SYNC_SHOOT, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	restart_timer
	try_run_to_target_chr /*goto*/ 0x85

	beginloop 0x85
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
		if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
		if_chr_distance_lt 120, /*goto*/ 0x16
		call_rng
		if_rand_lt 128, /*goto*/ 0x13
		if_chr_distance_gt 250, /*goto*/ 0x13
		label 0x16
		if_in_disarm_range /*goto*/ 0x16
		goto_next 0x13

		label 0x16
		set_return_function CHR_SELF, GFUNC_ALERTED
		set_function CHR_SELF, GFUNC_HAND_COMBAT

		label 0x13
		if_in_disarm_range /*goto*/ 0x26
		if_timer_gt 120, /*goto*/ 0x86
	endloop 0x85

	label 0x86
	goto_first 0x1b

	label 0x26
	dprint "ICANSE PLAYER\n"
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
	if_chr_distance_lt 120, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x13
	label 0x16
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x13
	dprint "target\n"
	restart_timer
	stop_chr
	set_action ACTION_SYNC_SHOOT, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_self_flag_bankx_eq CHRFLAG1_00002000, FALSE, BANK_1, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG1_00002000, BANK_1
	goto_first 0x48

	label 0x13
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ LABEL_CLOAKED
	call_rng
	if_rand_lt 10, /*goto*/ 0x57
	if_rand_gt 64, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000010, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x5a64
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	goto_next 0x44

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000004, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x141e
	goto_next 0x44

	label 0x13
	label 0x16
	call_rng
	if_rand_gt 50, /*goto*/ 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x16
	label 0xbe
	try_roll_and_shoot /*goto*/ 0x44
	label 0x16
	try_walk_and_shoot /*goto*/ 0x44
	label 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x8c
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x28
	label 0x8c
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0x28
	dprint "SHOOTFAILED\n"
	yield
	cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
	goto_first 0x8b

	label 0x28
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0x44
	goto_next 0x67

	label 0x44
	say_quip CHR_JOANNA, 0x00, 0x19, 0x02, 0x00, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x01, 0x19, 0x02, 0x01, BANK_0, 0x00, 0x00

	beginloop 0x45
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x2a
	endloop 0x45

	label 0x57
	say_quip CHR_JOANNA, 0x27, 0xfe, 0x03, 0xff, BANK_0, 0x00, 0x00
	do_special_animation -2
	goto_next 0xea
	label 0x2a
	if_self_flag_bankx_eq CHRFLAG0_01000000, FALSE, BANK_0, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG0_01000000, BANK_0
	set_accuracy 0
	label 0x13
	if_chr_injured_target CHR_SELF, /*goto*/ 0x13
	say_quip CHR_JOANNA, 0x16, 0x19, 0x03, 0x00, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x17, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00
	goto_next 0x16

	label 0x13
	say_quip CHR_JOANNA, 0x15, 0x19, 0x02, 0x00, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x15, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00
	label 0x16
	call_rng
	if_rand_lt 20, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000020, FALSE, BANK_1, /*goto*/ 0x13
	label 0x16
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	restart_timer
	animation ANIM_RELOAD_0209, 0, -1, 0x1010, CHR_SELF, 2
	label 0xea
	yield
	if_self_flag_bankx_eq CHRFLAG1_00000020, FALSE, BANK_1, /*goto*/ 0x16
	if_timer_lt 120, /*goto*/ 0x16
	assign_sound 0x80f6, CHANNEL_6
	play_sound_from_entity CHANNEL_6, CHR_SELF, 0x0bb8, 0x1770, 0x01
	unset_self_flag_bankx CHRFLAG1_00000020, BANK_1
	label 0x16
	if_chr_stopped /*goto*/ 0x13
	goto_first 0xea

	label 0x13
	dprint "LEFTSHOOT\n"
	goto_first 0x8b

	label 0x67
	dprint "SHOTNOWORK\n"
	label 0x2b
	goto_first 0x8b

	//
	// DODGE
	//
	label 0x18
	dprint "Dodge\n"
	set_action ACTION_DODGE, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	set_self_flag_bankx CHRFLAG1_00020000, BANK_1
	if_self_flag_bankx_eq CHRFLAG0_CAN_FLANK, FALSE, BANK_0, /*goto*/ 0x16
	cmd0133 ACTION_DODGE, /*goto*/ 0x16
	label 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x2d
	try_hop_sideways /*goto*/ 0x13
	goto_next 0x2e

	label 0x2d
	try_jump_sideways /*goto*/ 0x13
	goto_next 0x2e

	label 0x13
	set_self_flag_bankx CHRFLAG1_00020000, BANK_1

	beginloop 0x2c
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x2e
	endloop 0x2c

	label 0x2e
	dprint "DODGE DONE\n"
	call_rng
	if_rand_lt 128, /*goto*/ 0x16
	goto_first 0x87

	label 0x16
	goto_first 0x1b

	//
	// RETREAT
	//
	label LABEL_RETREAT
	set_chr_field_0x35e_0x35f 0, 0x00
	set_chr_field_0x35e_0x35f 1, 0x00
	dprint "ROUTED\n"
	set_action ACTION_RETREAT, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	say_quip CHR_JOANNA, 0x04, 0x19, 0x02, 0x01, BANK_0, 0x00, 0x00 // "Go to plan B","Get the hell out of here!","Retreat!"
	try_target_chr_in_same_group /*goto*/ 0x95
	if_self_flag_bankx_eq CHRFLAG1_00000002, TRUE, BANK_1, /*goto*/ 0x16
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_00200000, TRUE, BANK_0, /*goto*/ 0x16
	unset_self_flag_bankx CHRFLAG0_CAN_RETREAT, BANK_0
	unset_self_flag_bankx CHRFLAG0_CANT_ALERT_GROUP, BANK_0
	goto_first 0x1b

	//
	// RUNNING
	//
	label 0x16
	dprint "RUNNING\n"
	set_target_chr CHR_P1P2
	retreat 0x02, 0x01

	beginloop 0x6c
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_distance_gt 300, /*goto*/ 0x16
		if_chr_in_view /*goto*/ 0x70
		label 0x16
		if_chr_distance_gt 3000, /*goto*/ 0x6d
	endloop 0x6c

	label 0x6d
	stop_chr

	beginloop 0x6e
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_chr_distance_lt 3000, /*goto*/ 0x6f
	endloop 0x6e

	label 0x6f
	goto_first LABEL_RETREAT

	//
	// SURRENDER
	//
	label 0x70
	if_chr_dying CHR_SELF, /*goto*/ 0x88
	set_action ACTION_SURRENDER, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	say_quip CHR_JOANNA, 0x08, 0xfe, 0x0a, 0xff, BANK_0, 0x00, 0x00 // "Please! Don't shoot me!","I give up!","You win! I surrender"
	restart_timer
	surrender

	beginloop 0x71
		if_chr_dying CHR_SELF, /*goto*/ 0x88
		if_timer_gt 300, /*goto*/ 0x16
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_chr_in_view /*goto*/ 0x72
		if_bitcheck_in_position_struct /*goto*/ 0x13
	endloop 0x71

	// Out of view for 5 seconds - remove
	label 0x16
	drop_concealed_items CHR_SELF
	yield
	remove_chr CHR_SELF
	label 0x13
	restart_timer
	goto_first 0x71

	label 0x72
	say_quip CHR_JOANNA, 0x08, 0x23, 0x0a, 0x00, BANK_0, 0x00, 0x00
	restart_timer
	goto_first 0x71

	label 0x95
	unset_self_flag_bankx CHRFLAG0_CAN_RETREAT, BANK_0
	unset_self_flag_bankx CHRFLAG0_CANT_ALERT_GROUP, BANK_0
	try_run_to_chr FOLLOW_CHR, /*goto*/ 0x96

	beginloop 0x96
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_death_animation_finished FOLLOW_CHR, /*goto*/ 0x84
		if_chr_unloaded FOLLOW_CHR, /*goto*/ 0x84
		if_detected_chr FOLLOW_CHR, /*goto*/ 0x97
		if_chr_stopped /*goto*/ 0x97
	endloop 0x96

	label 0x97
	dprint "WARN FRIENDS\n"
	say_quip CHR_JOANNA, 0x10, 0xff, 0x02, 0xff, BANK_0, 0x00, 0x00
	set_group_alertness 100
	label 0x84
	goto_first 0x1b

	label 0x88
	set_function CHR_SELF, GFUNC_IDLE

	//
	// RUN FOR ALARM
	//
	label LABEL_RUN_FOR_ALARM
	set_action ACTION_WARN_OTHERS, FALSE
	unset_self_flag_bankx CHRFLAG1_00040000, BANK_1
	unset_self_flag_bankx CHRFLAG1_00020000, BANK_1
	say_quip CHR_JOANNA, 0x22, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Trigger the alarm"
	go_to_target_pad SPEED_JOG

	beginloop 0x9d
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x16
	endloop 0x9d

	label 0x16
	animation ANIM_PUSH_BUTTON, 0, 193, 0x1010, CHR_SELF, 2
	restart_timer

	beginloop 0xed
		if_timer_gt 70, /*goto*/ 0x16
	endloop 0xed

	label 0x16
	activate_alarm

	beginloop 0x9e
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ LABEL_FLEE_GRENADE
		if_chr_stopped /*goto*/ 0x16
	endloop 0x9e

	label 0x16
	goto_first 0x1b

	//
	// FLEE GRENADE
	//
	label LABEL_FLEE_GRENADE
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_FLEE_FROM_GRENADE

	//
	// CLOAKED
	//
	label LABEL_CLOAKED
	set_alertness 0
	set_return_function CHR_SELF, GFUNC_ALERTED
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	label 0x01
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_00002000
	stop_chr
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x16
	if_chr_dying CHR_SELF, /*goto*/ 0x16
	if_chr_unloaded CHR_SELF, /*goto*/ 0x16
	if_chr_sees_player /*goto*/ 0x13
	set_alertness 0
	set_self_flag_bankx CHRFLAG1_10000000, BANK_1
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER

	label 0x13
	set_function CHR_SELF, GFUNC_ALERTED

	label 0x0a
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func000a_do_idle_animation:
	set_chr_flag_bank3 CHR_SELF, CHRFLAG3_00000080
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_TRIGGER_BUDDY_WARP, /*goto*/ 0x13
	if_chr_idle_action_eq IDLEACTION_SITTING_TYPING, /*goto*/ 0x16
	if_chr_idle_action_eq IDLEACTION_SITTING_DORMANT, /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_chr_health CHR_SELF, 1
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_TRIGGER_BUDDY_WARP

	label 0x13
	set_onshot_function GFUNC_UNALERTED
	label 0x00
	if_chr_idle_action_eq IDLEACTION_STANDING, /*goto*/ 0x03
	if_chr_idle_action_eq IDLEACTION_SITTING_TYPING, /*goto*/ 0x04
	if_chr_idle_action_eq IDLEACTION_SITTING_DORMANT, /*goto*/ 0x05
	if_chr_idle_action_eq IDLEACTION_OPERATING, /*goto*/ 0x06
	if_chr_idle_action_eq IDLEACTION_OPERATING_PAD, /*goto*/ 0x07
	stop_chr
	return
	set_function CHR_SELF, GFUNC_IDLE

	label 0x03
	dprint "STANDING\n"
	animation ANIM_OPERATE_0204, 0, -1, 0x1010, CHR_SELF, 2
	goto_next 0x0c

	label 0x04
	dprint "SITTING TYPING\n"
	set_chr_special_death_animation CHR_SELF, 0x06
	animation ANIM_SITTING_TYPING, 0, -1, 0x1400, CHR_SELF, 2
	goto_next 0x0c

	label 0x05
	dprint "SITTING\n"
	set_chr_special_death_animation CHR_SELF, 0x06
	animation ANIM_SITTING_DORMANT, 0, -1, 0x1400, CHR_SELF, 2
	goto_next 0x0c

	label 0x07
	dprint "NAT 5\n"
	restart_timer
	try_face_entity ENTITYTYPE_PAD, TARGET_PAD, /*goto*/ 0xfa

	beginloop 0xfa
		if_timer_gt 60, /*goto*/ 0x06
	endloop 0xfa

	label 0x06
	dprint "OPERATING\n"
	call_rng
	if_rand_gt 85, /*goto*/ 0x28
	if_rand_gt 170, /*goto*/ 0x29
	animation ANIM_OPERATE_0221, 0, -1, 0x1000, CHR_SELF, 2
	goto_next 0x0c

	label 0x28
	animation ANIM_OPERATE_0222, 0, -1, 0x1000, CHR_SELF, 2
	goto_next 0x0c

	label 0x29
	animation ANIM_OPERATE_0223, 0, -1, 0x1000, CHR_SELF, 2
	goto_next 0x0c

	label 0x0c
	return

	// Nothing jumps to here or below
	beginloop 0x15
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_target_chr_in_sight /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ 0x16
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0x13
		goto_next 0x16

		label 0x13
		goto_next 0x12

		label 0x16
	endloop 0x15

	// Stand up
	label 0x13
	animation ANIM_STAND_UP_FROM_SITTING, 0, -1, 0x0210, CHR_SELF, 2
	object_do_animation 0x025a, 0xff, 0x02ff, 0xff

	beginloop 0x06
		if_chr_stopped /*goto*/ 0x13
	endloop 0x06

	label 0x13
	return

	label 0x12
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

/**
 * Attempts to set the target chr and engage in combat with them.
 *
 * - If current chr has been shot, say something, raise group alertness, then
 * engage combat with the target (if in range and line of sight).
 * - Otherwise, attempt to find the target using a one of two methods,
 * determined by a bitflag on the chr:
 *
 * 1) Find chr by group (details unknown)
 * 2) Distance and line of sight check on all chrs
 *
 * When one fails the other is attempted. Presumably both of these are quite
 * expensive, so the flag exists to determine which one is more likely to pass
 * on a per chr basis.
 *
 * If both fail, the function yields and continues checking.
 */
func000b_choose_target_chr:
	set_onshot_function GFUNC_CHOOSE_TARGET_CHR
	if_num_times_shot_lt 1, /*goto*/ 0xd3

	// Has been shot
	say_quip CHR_JOANNA, 0x0c, 0x78, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"

	beginloop 0x03
		if_chr_stopped /*goto*/ 0x16
	endloop 0x03

	label 0x16
	say_quip CHR_JOANNA, 0x0c, 0xff, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"
	dprint "NO WARNING\n"
	set_group_alertness 100
	dprint "NO WARNING\n"
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x13
	goto_next 0xd3

	label 0x13
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	// Hasn't been shot, or can't engage target chr
	label 0xd3
	set_action ACTION_SCAN, FALSE
	yield
	dprint "SCAN\n"

	if_self_flag_bankx_eq CHRFLAG0_NOHEAR, TRUE, BANK_0, /*goto*/ 0x13
	cmd0127_try_find_chr_in_group /*goto*/ 0x16
	goto_next 0x04

	// No hear - only see
	label 0x13
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x16

	// Scan failed
	label 0x04
	if_shot_near_chr 0x00, /*goto*/ 0x13
	if_alertness 99, OPERATOR_GREATER_THAN, /*goto*/ 0x13
	goto_first 0xd3

	// Found
	label 0x16
	dprint "FOUND\n"
	set_group_alertness 100
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	set_return_function CHR_SELF, GFUNC_CHOOSE_TARGET_CHR

	label 0x13
	dprint "FOUNDALERT\n"
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG0_NOHEAR, TRUE, BANK_0, /*goto*/ 0x16
	cmd0127_try_find_chr_in_group /*goto*/ 0x13
	label 0x16
	goto_first 0xd3

	label 0x13
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

func000d_init_combat:
	set_onshot_function GFUNC_COMBAT_WITH_TARGET_CHR

	// If not idle, turn off special death animation
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x13
	set_chr_special_death_animation CHR_SELF, NULL

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x16
	unset_self_flag_bankx CHRFLAG1_DOINGIDLEANIMATION, BANK_1
	if_chr_idle_action_eq IDLEACTION_SITTING_TYPING, /*goto*/ 0x05
	if_chr_idle_action_eq IDLEACTION_SITTING_DORMANT, /*goto*/ 0x05
	goto_next 0x16

	// Stand up
	label 0x05
	set_chr_health CHR_SELF, 40
	animation ANIM_STAND_UP_FROM_SITTING, 0, -1, 0x0210, CHR_SELF, 2
	object_do_animation 0x025a, 0xff, 0x02ff, 0xff

	beginloop 0x0c
		if_chr_stopped /*goto*/ 0x13
	endloop 0x0c

	label 0x13
	label 0x16
	set_onshot_function GFUNC_COMBAT_WITH_TARGET_CHR
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

func000c_combat_with_target_chr:
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x16
	dprint "SEE ENEMY\n"
	if_num_human_players_lt 2, /*goto*/ 0x16
	label 0x13
	if_chr_lost_track_of_target_maybe /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_WAR, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_DEEPSEA, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_DEFENSE, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_WAR, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_ESCAPE, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_ATTACKSHIP, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_CRASHSITE, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	// Solo mode, or co-op/counter-op on any other stage
	label 0x13
	if_chr_lost_track_of_target_maybe /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_function CHR_SELF, GFUNC_ALERTED

	// Co-op with friend or counter-op on any of the above stages
	// Or follow through if chr still has target
	label 0x16
	set_self_flag_bank3 CHRFLAG3_00000040
	dprint "DETECT\n"
	if_chr_dying CHR_SELF, /*goto*/ 0x16
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x16
	if_chr_unloaded CHR_SELF, /*goto*/ 0x16
	goto_next 0x13

	// Dying
	label 0x16
	set_onshot_function GFUNC_IDLE
	restart_timer

	beginloop 0x1c
		if_timer_gt 15, /*goto*/ 0x16
	endloop 0x1c

	label 0x16
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x16
	say_quip CHR_JOANNA, 0x19, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00
	goto_next 0x17

	label 0x16
	say_quip CHR_JOANNA, 0x02, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00

	label 0x17
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	// Alive
	label 0x13
	dprint "DETECT1\n"
	if_num_times_shot_lt 1, /*goto*/ 0xb2
	if_just_injured CHR_SELF, /*goto*/ 0x16
	if_has_gun CHR_SELF, /*goto*/ 0xb2
	set_self_flag_bankx CHRFLAG1_00000001, BANK_1
	goto_next 0xb2

	dprint "DETECT2\n"

	// Injured
	label 0x16
	restart_timer

	beginloop 0x1d
		if_self_flag_bankx_eq CHRFLAG0_SAID_INJURY_QUIP, TRUE, BANK_0, /*goto*/ 0x16
		if_num_times_shot_lt 1, /*goto*/ 0x16
		if_timer_lt 20, /*goto*/ 0x16
		say_quip CHR_JOANNA, 0x0d, 0x28, 0x03, 0xff, BANK_0, 0x00, 0x00
		say_quip CHR_JOANNA, 0x0e, 0x28, 0x03, 0x01, BANK_0, 0x00, 0x00
		set_self_flag_bankx CHRFLAG0_SAID_INJURY_QUIP, BANK_0
		label 0x16
		if_chr_stopped /*goto*/ 0x13
		if_timer_gt 180, /*goto*/ 0x13
	endloop 0x1d

	label 0x13
	dprint "DETECT3\n"
	label 0xb2
	yield
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_08000000, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG1_00000001, BANK_1
	goto_next 0x16

	label 0x13
	set_self_flag_bankx CHRFLAG1_00000001, BANK_1
	label 0x16
	dprint "TEAMD\n"
	if_alertness 100, OPERATOR_LESS_THAN, /*goto*/ 0xb3
	dprint "ALERT\n"
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0xb3
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x16
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_target_chrs_field_0x17e_is_different /*goto*/ 0xb3
	label 0x16
	dprint "NO TARGET\n"
	set_target_chr -1
	return

	label 0xb3
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x16
	label 0x13
	if_chr_lost_track_of_target_maybe /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_WAR, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_DEEPSEA, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_DEFENSE, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_WAR, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_ESCAPE, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_ATTACKSHIP, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	if_stage_is_not STAGE_CRASHSITE, /*goto*/ 0x13
	if_num_human_players_lt 2, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_function CHR_SELF, GFUNC_ALERTED

	label 0x16
	dprint "FOUND ENEMY\n"
	restart_timer
	if_chr_dying TARGET_CHR, /*goto*/ 0xba
	if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xba
	if_chr_unloaded TARGET_CHR, /*goto*/ 0xba
	if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
	goto_next 0x16

	// Target's field 0x17e is different
	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, FALSE, BANK_1, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x16
	if_in_disarm_range /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_self_flag_bankx CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT, BANK_1
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x16
	try_run_to_target_chr /*goto*/ 0xb4
	dprint "RUN FAIL\n"

	beginloop 0xb4
		dprint "FOUND 1\n"
		if_timer_gt 600, /*goto*/ 0xba
		if_self_flag_bankx_eq CHRFLAG1_00000001, FALSE, BANK_1, /*goto*/ 0x13
		if_timer_gt 20, /*goto*/ 0x09
		label 0x13
		if_chr_dying TARGET_CHR, /*goto*/ 0xba
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xba
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xba
		if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
		goto_next 0xba

		label 0x13
		dprint "FOUND 2\n"
		if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
		if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
		if_chr_distance_lt 120, /*goto*/ 0x16
		call_rng
		if_rand_lt 128, /*goto*/ 0x13
		if_chr_distance_gt 250, /*goto*/ 0x13
		label 0x16
		if_in_disarm_range /*goto*/ 0x16
		dprint "NOUNARM\n"
		goto_next 0x13

		label 0x16
		dprint "GOUNARM\n"
		set_self_flag_bankx CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT, BANK_1
		set_function CHR_SELF, GFUNC_HAND_COMBAT

		label 0x13
		label 0x13
		if_enemy_distance_lt_and_los 1200, /*goto*/ 0xb5
		if_in_disarm_range /*goto*/ 0xb6
	endloop 0xb4

	label 0x09
	goto_first 0xb3

	label 0xb7
	label 0xb9
	if_in_disarm_range /*goto*/ 0xb6
	if_chr_dying TARGET_CHR, /*goto*/ 0xba
	if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xba
	if_chr_unloaded TARGET_CHR, /*goto*/ 0xba
	if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
	goto_next 0xba

	label 0x13
	if_chr_in_view /*goto*/ 0xbb
	goto_first 0xb4

	label 0xb5
	restart_timer
	try_run_to_target_chr /*goto*/ 0xbc

	beginloop 0xbc
		if_chr_dying TARGET_CHR, /*goto*/ 0xc0
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc0
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xc0
		if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
		goto_next 0xc0

		label 0x13
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ 0x13
		if_in_disarm_range /*goto*/ 0xbf
		label 0x13
		if_timer_gt 120, /*goto*/ 0xc0
	endloop 0xbc

	label 0xbf
	goto_next 0xb6

	label 0xc0
	goto_first 0xb2

	label 0xb6
	set_grenade_probability_out_of_255 255
	set_self_flag_bank3 CHRFLAG3_00000040
	if_chr_dying TARGET_CHR, /*goto*/ 0xc1
	if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc1
	if_chr_unloaded TARGET_CHR, /*goto*/ 0xc1
	if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
	goto_next 0xc1

	label 0x13
	dprint "SHOOTING\n"
	goto_next 0xc2

	label 0x16
	if_chr_distance_lt 800, /*goto*/ 0xc2
	if_something_hypotenuse 0, /*goto*/ 0xc2
	dprint "GRENADE\n"
	restart_timer
	if_any_chr_doing_action ACTION_THROW_GRENADE, /*goto*/ 0xc2
	set_action ACTION_THROW_GRENADE, FALSE
	consider_throwing_grenade 0x0200, 0x0000, /*goto*/ 0x16
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
	if_chr_distance_lt 120, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x13
	label 0x16
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_self_flag_bankx CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT, BANK_1
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x13
	yield
	dprint "GRENADE END\n"
	label 0xc2
	if_self_flag_bankx_eq CHRFLAG1_00001000, TRUE, BANK_1, /*goto*/ 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x16
	if_chr_distance_lt 120, /*goto*/ 0x16
	call_rng
	if_rand_lt 128, /*goto*/ 0x13
	if_chr_distance_gt 250, /*goto*/ 0x13
	label 0x16
	if_in_disarm_range /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	set_self_flag_bankx CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT, BANK_1
	set_function CHR_SELF, GFUNC_HAND_COMBAT

	label 0x13
	label 0x13
	dprint "CHOSE SHTND\n" // choose... ?
	call_rng
	if_rand_gt 64, /*goto*/ 0x16
	if_self_flag_bankx_eq CHRFLAG1_00000010, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x5a64
	set_self_flag_bankx CHRFLAG1_00000020, BANK_1
	goto_next 0xc3

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_00000004, FALSE, BANK_1, /*goto*/ 0x13
	cmd0184 0x141e
	goto_next 0xc3

	label 0x13
	label 0x16
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x17
	goto_next 0x16

	label 0x17
	say_quip CHR_JOANNA, 0x01, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00
	label 0x16
	call_rng
	if_rand_gt 50, /*goto*/ 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x16
	label 0xbe
	try_roll_and_shoot /*goto*/ 0xc3
	label 0x16
	try_walk_and_shoot /*goto*/ 0xc3
	label 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x8c
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0x16
	label 0x8c
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0x16
	label 0x16
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0xc3

	label 0xc3
	say_quip CHR_JOANNA, 0x24, 0x19, 0x02, 0xff, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x25, 0x19, 0x02, 0x01, BANK_0, 0x00, 0x00

	beginloop 0xe2
		if_chr_dying TARGET_CHR, /*goto*/ 0xc1
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc1
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xc1
		if_target_chrs_field_0x17e_is_different /*goto*/ 0x16
		goto_next 0xc1

		label 0x16
		if_chr_stopped /*goto*/ 0xc1
	endloop 0xe2

	label 0x13
	restart_timer
	dprint "SHOOT FAIL\n"

	beginloop 0x03
		if_timer_gt 60, /*goto*/ 0x16
	endloop 0x03

	label 0x16
	goto_first 0xc3

	label 0xba
	dprint "FOUND 3\n"
	label 0xc1
	if_chr_injured_target CHR_SELF, /*goto*/ 0x13
	dprint "PUNCHMISSED\n"
	say_quip CHR_JOANNA, 0x16, 0x19, 0x03, 0xff, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x17, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00
	goto_next 0x16

	label 0x13
	dprint "PUNCHHIT\n"
	say_quip CHR_JOANNA, 0x15, 0x19, 0x02, 0xff, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x15, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00

	label 0x16
	dprint "BONND 3\n"
	if_self_flag_bankx_eq CHRFLAG1_00000800, FALSE, BANK_1, /*goto*/ 0x13
	if_chr_lost_track_of_target_maybe /*goto*/ 0x13
	damage_chr TARGET_CHR, 18
	unset_self_flag_bankx CHRFLAG1_00000800, BANK_1
	label 0x13
	if_chr_dying TARGET_CHR, /*goto*/ 0xc5
	if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc5
	if_chr_unloaded TARGET_CHR, /*goto*/ 0xc5
	if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
	goto_next 0xc5

	label 0x13
	if_self_flag_bankx_eq CHRFLAG1_40000000, TRUE, BANK_1, /*goto*/ 0xc5
	label 0xb8
	label 0xc6
	if_self_flag_bankx_eq CHRFLAG0_08000000, FALSE, BANK_0, /*goto*/ 0x13
	goto_first 0xb3

	label 0x13
	dprint "LOOK FOR COVER\n"
	if_self_flag_bankx_eq CHRFLAG1_00004000, TRUE, BANK_1, /*goto*/ 0x15
	cmd0121_if_something 0x1035, /*goto*/ 0x53
	cmd0121_if_something 0x1095, /*goto*/ 0x53
	goto_next 0x16

	label 0x15
	cmd0121_if_something 0x9035, /*goto*/ 0x53
	cmd0121_if_something 0x9095, /*goto*/ 0x53
	label 0x16
	goto_next 0x54

	label 0x53
	dprint "GO TO COVER\n"
	say_quip CHR_JOANNA, 0x02, 0xff, 0x02, 0x01, BANK_0, 0x00, 0x00
	cmd0124_run_for_cover_maybe ACTION_UNDER_COVER
	restart_timer

	beginloop 0xc7
		if_chr_dying TARGET_CHR, /*goto*/ 0xc5
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc5
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xc5
		if_enemy_distance_lt_and_los 400, /*goto*/ 0x13
		if_chr_stopped /*goto*/ 0x16
		if_timer_gt 360, /*goto*/ 0x16
	endloop 0xc7

	label 0x13
	goto_first 0xb5

	label 0x16
	dprint "GOT TO COVER\n"
	label 0xc8
	restart_timer
	try_chr_kneel_and_shoot_thing 0x0220, 0x0000, /*goto*/ 0xc9

	beginloop 0xc9
		if_chr_dying TARGET_CHR, /*goto*/ 0xc5
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc5
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xc5
		if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
		goto_next 0xc5

		label 0x13
		if_enemy_distance_lt_and_los 400, /*goto*/ 0x15
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_CLOAKED, /*goto*/ 0x13
		if_in_disarm_range /*goto*/ 0xca
		label 0x13
		if_timer_gt 200, /*goto*/ 0x16
	endloop 0xc9

	label 0x16
	dprint "TIMOUT\n"
	goto_first 0xb3

	label 0x15
	dprint "OPFIRE\n"
	goto_first 0xb5

	label 0xa3
	goto_first 0xc1

	label 0xca
	restart_timer
	dprint "TARSHO\n"
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x16
	goto_next 0x17

	label 0x16
	say_quip CHR_JOANNA, 0x01, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00
	label 0x17
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0xcb
	goto_next 0x16

	label 0xcb
	say_quip CHR_JOANNA, 0x24, 0x19, 0x02, 0xff, BANK_0, 0x00, 0x00
	say_quip CHR_JOANNA, 0x25, 0x19, 0x02, 0x01, BANK_0, 0x00, 0x00

	beginloop 0xcc
		if_chr_dying TARGET_CHR, /*goto*/ 0xc5
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xc5
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xc5
		if_target_chrs_field_0x17e_is_different /*goto*/ 0x13
		goto_next 0xc5

		label 0x13
		if_timer_gt 300, /*goto*/ 0x16
		if_chr_stopped /*goto*/ 0x16
	endloop 0xcc

	label 0x54
	dprint "NOCOVER\n"
	goto_first 0xb3

	restart_timer
	try_run_sideways /*goto*/ 0xcd

	beginloop 0xcd
		if_timer_gt 300, /*goto*/ 0xce
		if_chr_stopped /*goto*/ 0xce
	endloop 0xcd

	label 0xce
	goto_first 0xb3

	label 0xc5
	dprint "FOUND 4\n"
	if_self_flag_bankx_eq CHRFLAG1_00100000, FALSE, BANK_1, /*goto*/ 0x13
	dprint "FOUND 5\n"
	return

	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_NOHEAR, TRUE, BANK_0, /*goto*/ 0x13
	label 0x13
	goto_next 0xcf

	label 0x16
	dprint "KILLED TARGET\n"
	restart_timer
	call_rng
	if_self_flag_bankx_eq CHRFLAG1_00100000, FALSE, BANK_1, /*goto*/ 0x13
	return

	label 0x13
	goto_next 0xd0

	// Unreachable - no label
	if_rand_gt 128, /*goto*/ 0xd1
	try_run_to_target_chr_with_hand_up /*goto*/ 0xd0

	beginloop 0xd0
		if_timer_gt 120, /*goto*/ 0xd2
		if_chr_stopped /*goto*/ 0xd2
	endloop 0xd0

	label 0xd2
	goto_next 0xc4

	// Begin unreachable
	kneel

	beginloop 0xd4
		if_timer_gt 60, /*goto*/ 0xc4
	endloop 0xd4

	label 0xd1
	try_run_sideways /*goto*/ 0xd5

	beginloop 0xd5
		if_timer_gt 180, /*goto*/ 0xc4
		if_chr_stopped /*goto*/ 0xc4
	endloop 0xd5
	// End unreachable

	label 0xc4
	if_self_flag_bankx_eq CHRFLAG0_10000000, FALSE, BANK_0, /*goto*/ 0x13
	return

	label 0x13
	goto_first 0xb3

	label 0xcf
	if_self_flag_bankx_eq CHRFLAG0_10000000, FALSE, BANK_0, /*goto*/ 0x13
	if_chr_lost_track_of_target_maybe /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	return

	label 0x13
	try_walk_to_target_chr /*goto*/ 0xd6

	beginloop 0xd6
		if_enemy_distance_lt_and_los 1200, /*goto*/ 0x13
		if_chr_stopped /*goto*/ 0xd7
	endloop 0xd6

	label 0x13
	goto_first 0xb3

	label 0xd7
	say_quip CHR_JOANNA, 0x0f, 0x28, 0x00, 0x01, BANK_0, 0x00, 0x00
	try_face_entity 0x0200, 0x0000, /*goto*/ 0x16
	label 0x16
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0xd9
	animation ANIM_YAWN, 0, 193, 0x1810, CHR_SELF, 2

	beginloop 0xd8
		if_chr_stopped /*goto*/ 0xd9
	endloop 0xd8

	label 0xd9
	return
	endfunction

unregistered_function2:
	stop_chr
	label 0x19
	stop_chr
	yield
	goto_first 0x19

	endfunction

unregistered_function3:
	surrender
	beginloop 0x19
		if_chr_stopped /*goto*/ 0x16
	endloop 0x19

	label 0x16
	dprint "finyawn\n"
	return
	endfunction

/**
 * This is the initial function for Defense blondes and some chr in
 * Attack Ship.
 */
func0000_idle_0009:
	dprint "START LIST\n"
	set_action ACTION_SCAN, FALSE
	set_return_function CHR_SELF, GFUNC_IDLE_0009
	stop_chr

	beginloop 0x0c
	endloop 0x0c

	endfunction

/**
 * Not used.
 */
func000e_see_then_attack:
	set_onshot_function GFUNC_ALERTED

	beginloop 0x0c
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_chr_sees_player /*goto*/ 0x16
	endloop 0x0c

	label 0x16
	set_function CHR_SELF, GFUNC_ALERTED
	endfunction

/**
 * Waits for an objective to fail, then shows the objectives failed messages
 * periodically.
 */
func0016_show_objective_failed_msg:
	// Wait until an objective has failed
	beginloop 0x0c
		if_timer_gt 0, /*goto*/ 0x13
		if_objective_failed 0, /*goto*/ 0x16
		if_objective_failed 1, /*goto*/ 0x16
		if_objective_failed 2, /*goto*/ 0x16
		if_objective_failed 3, /*goto*/ 0x16
		if_objective_failed 4, /*goto*/ 0x16
	endloop 0x0c

	// Wait 30 seconds. It iterates to the top loop here, which instantly jumps
	// down to 0x13 because the timer is > 0. Seems a bit unnecessary...
	label 0x16
	restart_timer
	yield
	label 0x13
	if_timer_gt 1800, /*goto*/ 0x13
	goto_first 0x0c

	// Check objective is still failed
	label 0x13
	if_objective_failed 0, /*goto*/ 0x13
	if_objective_failed 1, /*goto*/ 0x13
	if_objective_failed 2, /*goto*/ 0x13
	if_objective_failed 3, /*goto*/ 0x13
	if_objective_failed 4, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_IDLE

	// Show message first time
	label 0x13
	message CHR_JOANNA, 0x5845 // "OBJECTIVES FAILED - abort mission."

	// Wait 60 seconds
	restart_timer

	beginloop 0x03
		if_timer_gt 3600, /*goto*/ 0x16
	endloop 0x03

	// Check objective is still failed
	label 0x16
	if_objective_failed 0, /*goto*/ 0x13
	if_objective_failed 1, /*goto*/ 0x13
	if_objective_failed 2, /*goto*/ 0x13
	if_objective_failed 3, /*goto*/ 0x13
	if_objective_failed 4, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_IDLE

	// Show message second time
	label 0x13
	message CHR_JOANNA, 0x5845 // "OBJECTIVES FAILED - abort mission."
	restart_timer

	// Wait 2 minutes
	beginloop 0x04
		if_timer_gt 7200, /*goto*/ 0x06
	endloop 0x04

	// Check objective is still failed
	label 0x06
	if_objective_failed 0, /*goto*/ 0x13
	if_objective_failed 1, /*goto*/ 0x13
	if_objective_failed 2, /*goto*/ 0x13
	if_objective_failed 3, /*goto*/ 0x13
	if_objective_failed 4, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_IDLE

	// Show message third time
	label 0x13
	message CHR_JOANNA, 0x5845 // "OBJECTIVES FAILED - abort mission."
	restart_timer

	// Wait 5 minutes
	beginloop 0x05
		if_timer_gt 18000, /*goto*/ 0x16
	endloop 0x05

	// Loop back to the last message, so it will display every 5 minutes
	label 0x16
	goto_first 0x06

	endfunction

func0017_rebuild_groups:
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func0018_do_bored_animation:
	call_rng
	if_rand_gt 50, /*goto*/ 0x13
	animation ANIM_YAWN, 0, 193, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 100, /*goto*/ 0x13
	animation ANIM_SCRATCH_HEAD, 0, 294, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 150, /*goto*/ 0x13
	animation ANIM_ROLL_HEAD, 0, 183, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 200, /*goto*/ 0x13
	animation ANIM_GRAB_CROTCH, 0, 123, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 250, /*goto*/ 0x13
	animation ANIM_GRAB_BUTT, 0, 56, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	label 0x16
	return
	endfunction

func001e_look_around:
	call_rng
	if_rand_gt 50, /*goto*/ 0x13
	animation ANIM_LOOK_AROUND_025B, 0, 193, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 100, /*goto*/ 0x13
	animation ANIM_LOOK_AROUND_025C, 0, 294, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 150, /*goto*/ 0x13
	animation ANIM_LOOK_AROUND_025D, 0, 183, 0x1810, CHR_SELF, 2
	goto_next 0x16

	// @bug: Shows grab crotch animation when wanting to look around instead.
	// Probably a copy/paste error from previous function.
	label 0x13
	if_rand_gt 200, /*goto*/ 0x13
	animation ANIM_GRAB_CROTCH, 0, 123, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	if_rand_gt 250, /*goto*/ 0x13
	animation ANIM_LOOK_AROUND_025E, 0, 56, 0x1810, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	label 0x16
	return
	endfunction

func0019_do_sitting_animation:
	call_rng
	if_rand_gt 128, /*goto*/ 0x13
	animation ANIM_SITTING_TYPING, 0, -1, 0x1010, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	animation ANIM_SITTING_DORMANT, 0, -1, 0x1010, CHR_SELF, 2
	goto_next 0x16

	label 0x13
	label 0x16
	return
	endfunction

/**
 * This function is only used by other global functions.
 *
 * It appears the purpose is to unset CHRFLAG1_DISSPEE in certain conditions.
 */
func001a_maybe_unset_disspee:
	restart_timer

	// If target has both DISGUISED and chrflag2_02000000
	// then they must not have a gun equipped.
	label 0x00
	yield
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x14
	goto_next 0x13

	label 0x14
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000, /*goto*/ 0xe8
	goto_next 0x13

	label 0xe8
	if_chr_weapon_equipped TARGET_CHR, WEAPON_NONE, /*goto*/ 0x13
	if_chr_weapon_equipped TARGET_CHR, WEAPON_UNARMED, /*goto*/ 0x13
	if_chr_weapon_equipped TARGET_CHR, WEAPON_COMBATBOOST, /*goto*/ 0x13
	if_chr_weapon_equipped TARGET_CHR, WEAPON_HORIZONSCANNER, /*goto*/ 0x13
	if_chr_weapon_equipped TARGET_CHR, WEAPON_SUITCASE, /*goto*/ 0x13
	set_function CHR_SELF, GFUNC_UNALERTED_0004

	// Not disguised, or
	// disguised but not 02000000, or
	// disguised and 02000000 and has no weapon equipped.
	// Wait 1 second, or for some field in the current chr to change.
	label 0x13
	if_timer_lt 60, /*goto*/ 0x15
	if_chr_field0x332_zero CHR_SELF, /*goto*/ 0x28
	goto_next 0x15

	// Field changed
	label 0x28
	unset_self_flag_bankx CHRFLAG1_DISSPEE, BANK_1
	stop_chr

	// Field changed (follow through from above) or 1 second elapsed
	label 0x15
	if_chr_idle /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	goto_first 0x00

	// Resume walking a path
	label 0x16
	start_path
	set_function CHR_SELF, GFUNC_UNALERTED_0004
	endfunction

func000f_hand_combat:
	.set LABEL_FACE_TARGET, 0x16
	.set LABEL_PUNCH,       0x16

	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
	if_chr_dying CHR_SELF, /*goto*/ 0x13
	if_chr_unloaded CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Dying
	label 0x13
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	label 0x16
	set_action ACTION_HAND_COMBAT, FALSE
	restart_timer

	// If current chr doesn't have this flag and isn't idle, stop them
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x0c
	if_chr_idle /*goto*/ 0x0c
	stop_chr

	// Begin loop
	label 0x0c
	yield
	if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xfa
	if_chr_dying TARGET_CHR, /*goto*/ 0xfa
	if_chr_unloaded TARGET_CHR, /*goto*/ 0xfa

	// This if-statement is effectively a no op
	dprint "L1\n"
	if_target_chrs_field_0x17e_is_different /*goto*/ 0x13

	dprint "L2\n"
	label 0x13
	dprint "LOOK FOR TARGET\n"
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x13
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x0f
	if_chr_distance_gt 120, /*goto*/ 0x13
	goto_next 0x10

	label 0x0f
	if_chr_distance_gt 150, /*goto*/ 0x13

	label 0x10
	if_in_disarm_range /*goto*/ 0x13
	if_timer_gt 120, /*goto*/ 0x0b
	goto_first 0x0c

	label 0x13
	if_chr_lost_track_of_target_maybe /*goto*/ 0x0a
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x13
	if_chr_distance_gt 400, /*goto*/ 0x0b
	label 0x13
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x0f
	if_chr_distance_lt 120, /*goto*/ LABEL_FACE_TARGET
	goto_next 0x10

	label 0x0f
	if_chr_distance_lt 150, /*goto*/ LABEL_FACE_TARGET
	label 0x10
	label 0xe3
	restart_timer
	dprint "RUN TO TARGET\n"
	try_run_to_target_chr /*goto*/ 0x03

	beginloop 0x03
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xfa
		if_chr_dying TARGET_CHR, /*goto*/ 0xfa
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xfa
		label 0x13
		if_timer_gt 90, /*goto*/ 0x0b
		if_chr_lost_track_of_target_maybe /*goto*/ 0x09
		if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x13
		if_chr_distance_gt 400, /*goto*/ 0x0b
		label 0x13
		if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x0f
		if_chr_distance_lt 120, /*goto*/ LABEL_FACE_TARGET
		goto_next 0x10

		label 0x0f
		if_chr_distance_lt 150, /*goto*/ LABEL_FACE_TARGET
		label 0x10
	endloop 0x03

	label 0x09
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x0f
	if_chr_distance_lt 120, /*goto*/ LABEL_FACE_TARGET
	goto_next 0x10

	label 0x0f
	if_chr_distance_lt 150, /*goto*/ LABEL_FACE_TARGET
	label 0x10
	if_self_flag_bankx_eq CHRFLAG1_00000001, TRUE, BANK_1, /*goto*/ 0x13
	if_chr_distance_gt 400, /*goto*/ 0x0b
	label 0x13
	goto_first 0x03

	label 0x0a
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x0f
	if_chr_distance_lt 120, /*goto*/ LABEL_FACE_TARGET
	goto_next 0x10

	label 0x0f
	if_chr_distance_lt 150, /*goto*/ LABEL_FACE_TARGET
	label 0x10
	if_chr_distance_gt 400, /*goto*/ 0x0b
	goto_first 0xe3

	label 0x13
	restart_timer
	goto_first 0x0c

	label LABEL_FACE_TARGET
	restart_timer
	dprint "FACE TARGET\n"
	if_angle_to_target_chr_lt 10, /*goto*/ LABEL_PUNCH
	cmd004f 246, /*goto*/ LABEL_PUNCH
	stop_chr
	try_face_entity 0x0200, 0x0001, /*goto*/ 0x04

	beginloop 0x04
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0xfa
		if_chr_dying TARGET_CHR, /*goto*/ 0xfa
		if_chr_unloaded TARGET_CHR, /*goto*/ 0xfa
		label 0x13
		if_chr_distance_gt 400, /*goto*/ 0x0b
		if_angle_to_target_chr_lt 15, /*goto*/ LABEL_PUNCH
		cmd004f 240, /*goto*/ LABEL_PUNCH
		if_timer_gt 60, /*goto*/ LABEL_PUNCH
	endloop 0x04

	label 0x13
	restart_timer
	goto_first 0x0c

	label LABEL_PUNCH
	dprint "PUNCH\n"
	try_punch_or_kick /*goto*/ 0x13

	// Unable to punch or kick for some reason - return to main loop
	restart_timer
	goto_first 0x0c

	label 0x13
	add_var_a 1
	if_chr_is_dead_maybe CHR_SELF, /*goto*/ 0x17
	goto_next 0x05

	label 0x17
	restart_timer
	say_quip CHR_JOANNA, 0x01, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Open fire!","Wipe her out!","Waste her!"

	beginloop 0x05
		if_timer_gt 180, /*goto*/ 0x16
		if_chr_stopped /*goto*/ 0x16
	endloop 0x05

	label 0x16
	if_chr_injured_target CHR_SELF, /*goto*/ 0x13
	dprint "PUNCHMISSED\n"
	say_quip CHR_JOANNA, 0x16, 0x19, 0x03, 0x00, BANK_0, 0x00, 0x00 // Say random quip: "Damn, missed!","How did I miss?"
	say_quip CHR_JOANNA, 0x17, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00 // "God sakes, someone hit her","She's a tricky one"
	goto_next 0x16

	label 0x13
	dprint "PUNCHHIT\n"
	say_quip CHR_JOANNA, 0x15, 0x19, 0x02, 0x00, BANK_0, 0x00, 0x00 // Say random quip: "Give it up!","Surrender, now!","Take that!"
	say_quip CHR_JOANNA, 0x15, 0x19, 0x03, 0x01, BANK_0, 0x00, 0x00 // "Give it up!","Surrender, now!","Take that!"

	label 0x16
	goto_next 0x0b

	label 0xfa
	dprint "TARGET IS DYING\n"

	// Finished attack
	label 0x0b
	dprint "FUN  HIT\n"
	label 0x15
	if_self_flag_bankx_eq CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT, TRUE, BANK_1, /*goto*/ 0x13
	dprint "RET HHIT\n"
	label 0x17
	return

	label 0x13
	dprint "DET ENIT\n"
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

/**
 * Used in Chicago, Air Base, and some other global functions.
 *
 * There is special logic for Chicago, where they don't care if you have a gun
 * and say different things.
 *
 * The chr will make one comment, then it returns to the previous function.
 */
func0010_civilian_say_comment:
	set_self_flag_bank3 CHRFLAG3_00040000
	set_onshot_function GFUNC_SURPRISED
	label 0x0c
	yield
	dprint "LOOK FOR TARGET\n"
	label 0x16
	restart_timer
	dprint "FACE TARGET\n"
	try_face_entity 0x0200, 0x0000, /*goto*/ 0x04

	// Wait until facing target, or a second has passed, or something else
	// happens such as hearing gunfire or seeing someone die.
	beginloop 0x04
		if_shot_near_chr 0x01, /*goto*/ 0x83
		if_saw_death 0x01, /*goto*/ 0x83
		if_angle_to_target_chr_lt 10, /*goto*/ 0x13
		cmd004f 246, /*goto*/ 0x13
		if_timer_gt 60, /*goto*/ 0x13
	endloop 0x04

	// Facing target
	label 0x13
	if_stage_is_not STAGE_CHICAGO, /*goto*/ 0x16
	goto_next 0x0e

	// Not Chicago
	label 0x16
	label 0x16
	set_self_flag_bankx CHRFLAG1_DISSPEE, BANK_1
	dprint "SET DISSPEE\n"
	if_chr_weapon_equipped TARGET_CHR, WEAPON_NONE, /*goto*/ 0x07
	if_chr_weapon_equipped TARGET_CHR, WEAPON_UNARMED, /*goto*/ 0x07
	if_chr_weapon_equipped TARGET_CHR, WEAPON_COMBATBOOST, /*goto*/ 0x07
	if_chr_weapon_equipped TARGET_CHR, WEAPON_HORIZONSCANNER, /*goto*/ 0x07
	if_chr_weapon_equipped TARGET_CHR, WEAPON_SUITCASE, /*goto*/ 0x07
	goto_next 0x05

	// Unarmed
	label 0x07
	restart_timer
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_01000000, /*goto*/ 0x13
	do_special_animation -1
	say_quip CHR_JOANNA, 0x1d, 0xff, 0x02, 0xff, BANK_0, 0x00, 0x00 // "How's things?","Hey there","Hi, how are you?"
	yield

	// Set a do-once flag, so chr is only stopped the first time
	dprint "RET\n"
	if_self_flag_bankx_eq CHRFLAG1_DISSPEE, TRUE, BANK_1, /*goto*/ 0x13
	stop_chr
	set_self_flag_bankx CHRFLAG1_DISSPEE, BANK_1

	label 0x13
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_01000000
	return

	// Armed
	label 0x05
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_01000000, /*goto*/ 0x06
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_01000000
	say_quip CHR_JOANNA, 0x1e, 0xff, 0x02, 0xff, BANK_0, 0x00, 0x00 // "Where did you get that?","Should you have that?","What are you doing with that weapon?"
	do_special_animation 6
	restart_timer

	beginloop 0x08
		if_shot_near_chr 0x01, /*goto*/ 0x83
		if_saw_death 0x01, /*goto*/ 0x83
		if_timer_gt 180, /*goto*/ 0x16
	endloop 0x08

	// Unreachable
	return

	// Has chrflag2_01000000
	label 0x06
	if_chr_in_view /*goto*/ 0x13
	return

	label 0x13
	set_chr_flag_bank2 TARGET_CHR, CHRFLAG2_02000000
	dprint "DONT POINT\n"
	say_quip CHR_JOANNA, 0x1f, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Don't point that at me","Watch where you're pointing that"
	do_special_animation -1
	restart_timer

	// Wait 3 seconds, or for see/hear gunfire
	beginloop 0x09
		if_shot_near_chr 0x01, /*goto*/ 0x83
		if_saw_death 0x01, /*goto*/ 0x83
		if_timer_gt 180, /*goto*/ 0x16
	endloop 0x09

	// Timer expired
	label 0x16
	return
	label 0x15

	// Special Chicago logic
	label 0x0e
	call_rng
	if_rand_gt 128, /*goto*/ 0x16
	dprint "B4TALK\n"
	if_stage_is_not STAGE_CHICAGO, /*goto*/ 0x15 // will never pass

	// 50% chance of this happening
	say_quip CHR_JOANNA, 0x16, 0xff, 0x00, 0xff, 0x81, 0x00, 0x00
	goto_next 0x13

	// 50% chance of this happening
	label 0x16
	say_quip CHR_JOANNA, 0x17, 0xff, 0x00, 0xff, 0x81, 0x00, 0x00
	label 0x13
	do_special_animation 3
	return

	// Not Chicago
	label 0x15
	say_quip CHR_JOANNA, 0x22, 0xff, 0x00, 0xff, 0x81, 0x00, 0x00
	goto_next 0x13

	label 0x16
	say_quip CHR_JOANNA, 0x23, 0xff, 0x00, 0xff, 0x81, 0x00, 0x00
	label 0x13
	do_special_animation 3
	return

	label 0x83
	set_alertness 100
	set_function CHR_SELF, GFUNC_UNALERTED
	endfunction

/**
 * This function is only used by civilians while they say comments...?
 */
func001c_surprised:
	set_onshot_function GFUNC_ALERTED
	set_group_alertness 100
	say_quip CHR_JOANNA, 0x0c, 0xff, 0x03, 0x00, BANK_0, 0x00, 0x00 // "Holy shh...","What the hell?!"
	restart_timer
	animation ANIM_SURPRISED_0202, 0, -1, 0x0010, CHR_SELF, 2

	// Wait 1 second
	beginloop 0x03
		dprint "S6"
		if_timer_gt 60, /*goto*/ 0x77
	endloop 0x03

	label 0x77
	set_function CHR_SELF, GFUNC_ALERTED
	set_return_function CHR_SELF, GFUNC_ALERTED
	endfunction

func0011_flee_from_grenade:
	set_action ACTION_FLEE_GRENADE, FALSE
	dprint "NEAR DANGER\n"
	run_from_grenade
	say_quip CHR_JOANNA, 0x03, 0xff, 0x00, 0xff, BANK_0, 0x00, 0x00 // "Look out, look out!","It's a grenade!","Clear the area!"
	restart_timer

	beginloop 0x0c
		dprint "DANGER LOOP\n"
		cmd013d_if_grenade_thrown_nearby_maybe ACTION_GRENADE_STOP, /*goto*/ 0x13
		goto_next 0x16

		label 0x13
		if_timer_gt 180, /*goto*/ 0x16
	endloop 0x0c

	label 0x16
	return
	endfunction

func001b_observe_camspy:
	stop_chr
	set_onshot_function GFUNC_ALERTED
	unset_self_flag_bankx CHRFLAG1_DOINGIDLEANIMATION, BANK_1
	set_chr_special_death_animation CHR_SELF, NULL
	set_follow_chr TARGET_CHR

	if_just_injured CHR_SELF, /*goto*/ 0x09
	dprint "EYE SPY\n"

	label 0x00
	set_target_chr FOLLOW_CHR
	if_chr_distance_lt 300, /*goto*/ 0x13
	try_run_to_target_chr_with_hand_up /*goto*/ 0x0c
	restart_timer

	beginloop 0x0c
		if_timer_gt 60, /*goto*/ 0x0b
		if_chr_distance_lt 300, /*goto*/ 0x13
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x16
		if_target_chr_in_sight /*goto*/ 0x0b
		label 0x16
		set_target_chr FOLLOW_CHR
	endloop 0x0c

	// At camspy
	label 0x13
	set_target_chr FOLLOW_CHR
	restart_timer
	try_face_entity 0x0200, 0x0000, /*goto*/ 0x03

	// Wait 5 seconds. During this time:
	// - If the camspy moves away, exit the loop and follow it
	// - If the player comes into sight, return from the function
	beginloop 0x03
		if_timer_gt 300, /*goto*/ 0x04
		if_chr_distance_gt 400, /*goto*/ 0x13
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x16
		if_target_chr_in_sight /*goto*/ 0x0b
		label 0x16
		set_target_chr FOLLOW_CHR
	endloop 0x03

	// Camspy moved away - follow it
	label 0x13
	goto_first 0x00

	// Timer expired
	label 0x04
	do_special_animation -1
	say_quip CHR_JOANNA, 0x1c, 0xff, 0x00, 0xff, BANK_0, 0x00, 0x00 // "What the hell?","Hello there","What's this?"

	// Wait another 5 seconds with same logic as previous timer
	beginloop 0x05
		if_chr_idle /*goto*/ 0x13
		if_timer_gt 300, /*goto*/ 0x06
		label 0x13
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x16
		if_target_chr_in_sight /*goto*/ 0x0b
		label 0x16
		set_target_chr FOLLOW_CHR
	endloop 0x05

	// Timer expired
	label 0x06
	if_self_flag_bankx_eq CHRFLAG1_LONG_CAMSPY_OBSERVATION, FALSE, BANK_1, /*goto*/ 0xe8
	unset_self_flag_bankx CHRFLAG1_LONG_CAMSPY_OBSERVATION, BANK_1
	goto_first 0x00

	// Player in sight while observing camspy
	label 0x0b
	return

	// Timer expired second time
	label 0xe8
	say_quip CHR_JOANNA, 0x28, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "It's a spy!"

	// Shoot camspy
	label 0x09
	set_self_flag_bank3 CHRFLAG3_00000040
	try_aim_and_shoot_thing1 0x0220, 0x0000, /*goto*/ 0x16
	label 0x16
	try_aim_and_shoot_thing2 0x0200, 0x0000, /*goto*/ 0xc3

	// Wait until shooting animation done
	beginloop 0xc3
		if_chr_stopped /*goto*/ 0x16
	endloop 0xc3

	label 0x16
	dprint "E1\n"
	if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0x13
	if_chr_dying TARGET_CHR, /*goto*/ 0x13
	if_chr_unloaded TARGET_CHR, /*goto*/ 0x13

	// Camspy still alive
	dprint "E2\n"
	if_chr_sees_player /*goto*/ 0x16
	dprint "E3\n"
	goto_next 0x13

	// Unreachable - no label
	dprint "E4\n"
	if_target_chrs_field_0x17e_is_different /*goto*/ 0x16
	dprint "E5\n"
	goto_next 0x13

	label 0x16
	dprint "E6\n"
	if_chr_lost_track_of_target_maybe /*goto*/ 0x13
	dprint "E7\n"
	goto_first 0x09

	label 0x13
	set_target_chr CHR_JOANNA
	dprint "E8\n"
	set_self_flag_bankx CHRFLAG1_10000000, BANK_1
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER
	endfunction

func001d_search_for_player:
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
	if_chr_dying CHR_SELF, /*goto*/ 0x13
	if_chr_unloaded CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Dying
	label 0x13
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	// Alive
	label 0x16
	if_self_flag_bankx_eq CHRFLAG1_DOINGIDLEANIMATION, FALSE, BANK_1, /*goto*/ 0x13
	set_chr_special_death_animation CHR_SELF, NULL
	label 0x13
	dprint "SEARCH ROOM\n"
	set_chr_field_0x35e_0x35f 2, 0x00
	label 0x00
	set_target_chr FOLLOW_CHR
	set_self_flag_bankx CHRFLAG1_01000000, BANK_1
	if_self_flag_bankx_eq CHRFLAG1_10000000, TRUE, BANK_1, /*goto*/ 0x16
	set_chr_field_0x330
	if_chr_distance_gt 1000, /*goto*/ 0x13
	try_run_to_target_chr_with_hand_up /*goto*/ 0x03
	label 0x13
	try_run_to_target_chr /*goto*/ 0x03

	beginloop 0x03
		dprint "SEARCHINIT\n"
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_target_chr_in_sight /*goto*/ 0x12
		if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ 0x13
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0xc3
		label 0x13
		if_chr_in_room CHR_SELF, 0x01, 0x0001, /*goto*/ 0x16
	endloop 0x03

	// Player is in the same room as self
	label 0x16
	restart_timer

	beginloop 0x0a
		dprint "POINT SRCH\n"
		if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000400, TRUE, BANK_1, /*goto*/ 0x15
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0xc3
		goto_next 0x13

		label 0x15
		if_enemy_distance_lt_and_los 100, /*goto*/ 0xc3
		label 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000400, FALSE, BANK_1, /*goto*/ 0x13
		if_chr_distance_lt 500, /*goto*/ 0x13
		goto_next 0x05

		label 0x13
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x15
		if_target_chr_in_sight /*goto*/ 0x12
		label 0x15
		if_timer_gt 30, /*goto*/ 0x05
	endloop 0x0a

	label 0x05
	restart_timer
	label 0x06
	if_chr_distance_lt 1000, /*goto*/ 0x13
	goto_first 0x00

	label 0x13
	stop_chr
	if_self_flag_bankx_eq CHRFLAG1_DONE_SEARCH_ANIM, TRUE, BANK_1, /*goto*/ 0x13
	call_rng
	if_rand_gt 128, /*goto*/ 0x13
	call_rng
	if_rand_lt 64, /*goto*/ 0x28
	if_rand_lt 128, /*goto*/ 0x29
	if_rand_lt 196, /*goto*/ 0x2a
	set_self_flag_bankx CHRFLAG1_DONE_SEARCH_ANIM, BANK_1
	animation ANIM_LOOK_AROUND_025B, 0, -1, 0x100a, CHR_SELF, 2
	goto_next 0x04

	label 0x28
	animation ANIM_LOOK_AROUND_025C, 0, -1, 0x100a, CHR_SELF, 2
	goto_next 0x04

	label 0x29
	animation ANIM_LOOK_AROUND_025D, 0, -1, 0x100a, CHR_SELF, 2
	goto_next 0x04

	label 0x2a
	animation ANIM_LOOK_AROUND_025E, 0, -1, 0x100a, CHR_SELF, 2
	goto_next 0x04

	label 0x13
	unset_self_flag_bankx CHRFLAG1_DONE_SEARCH_ANIM, BANK_1
	call_rng
	if_rand_lt 64, /*goto*/ 0x28
	if_rand_lt 128, /*goto*/ 0x29
	if_rand_lt 196, /*goto*/ 0x2a
	try_set_target_pad_to_something 0x08, /*goto*/ 0x13
	label 0x28
	try_set_target_pad_to_something 0x02, /*goto*/ 0x13
	label 0x29
	try_set_target_pad_to_something 0x04, /*goto*/ 0x13
	label 0x2a
	try_set_target_pad_to_something 0x08, /*goto*/ 0x13
	goto_next 0x04

	label 0x13
	go_to_target_pad SPEED_WALK

	beginloop 0x04
		dprint "WALK PAD\n"
		if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ 0x13
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0xc3
		label 0x13
		if_self_flag_bankx_eq CHRFLAG1_00000400, FALSE, BANK_1, /*goto*/ 0x13
		if_chr_distance_lt 500, /*goto*/ 0x13
		label 0x13
		consider_coop_for_p1p2_chr CHR_SELF
		set_target_chr CHR_P1P2
		dprint "1\n"
		if_timer_gt 600, /*goto*/ 0x0b
		dprint "1\n"
		if_chr_stopped /*goto*/ 0x16
		dprint "1\n"
		if_hears_gunfire /*goto*/ 0x12
		dprint "1\n"
		if_alertness 99, OPERATOR_GREATER_THAN, /*goto*/ 0x12
		dprint "1\n"
		if_near_miss /*goto*/ 0x12
		dprint "1\n"
		if_self_flag_bankx_eq CHRFLAG1_00000400, FALSE, BANK_1, /*goto*/ 0x13
		if_chr_distance_gt 500, /*goto*/ 0x15
		label 0x13
		dprint "CHEK VIS\n"
		if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x15
		if_target_chr_in_sight /*goto*/ 0x12
		label 0x15
		if_saw_death 0x00, /*goto*/ 0x28
	endloop 0x04

	label 0x16
	goto_first 0x06

	// Saw death?
	label 0x28
	dprint "EYE SPY\n"
	label 0x12
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_alertness 0
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_UNALERTED

	label 0x16
	set_alertness 100
	dprint "SEE PLAY\n"
	if_self_flag_bankx_eq CHRFLAG1_00000400, FALSE, BANK_1, /*goto*/ 0x13
	say_quip CHR_JOANNA, 0x1b, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00
	label 0x13
	set_function CHR_SELF, GFUNC_ALERTED
	label 0x0b
	say_quip CHR_JOANNA, 0x23, 0x32, 0x03, 0xff, BANK_0, 0x00, 0x00
	goto_first 0x05

	label 0xc3
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	set_alertness 0
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_function CHR_SELF, GFUNC_UNALERTED

	label 0x16
	set_return_function CHR_SELF, GFUNC_UNALERTED
	set_onshot_function GFUNC_COMBAT_WITH_TARGET_CHR
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

func001f_related_to_spawning:
	dprint "SEE PLAY\n"
	if_chr_dying CHR_SELF, /*goto*/ 0x13
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
	if_chr_unloaded CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Dying
	label 0x13
	set_onshot_function GFUNC_IDLE
	set_function CHR_SELF, GFUNC_IDLE

	// Alive
	label 0x16
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_target_chr CHR_P1P2
	set_onshot_function GFUNC_RELATED_TO_SPAWNING
	if_num_times_shot_lt 1, /*goto*/ 0x1a // pointless check
	label 0x1a
	set_action ACTION_SCAN, TRUE
	yield
	consider_coop_for_p1p2_chr CHR_SELF
	set_target_chr CHR_P1P2
	if_alertness 100, OPERATOR_LESS_THAN, /*goto*/ 0x16
	goto_next 0x78

	// Not alert
	label 0x16
	if_saw_death 0x01, /*goto*/ 0x1e
	if_shot_near_chr 0x01, /*goto*/ 0x1e
	if_player_looking_at_something_maybe 0x00, 0x00, 0x01, /*goto*/ 0x16
	if_target_chr_in_sight /*goto*/ 0x1e
	label 0x16
	if_self_flag_bankx_eq CHRFLAG0_AIVSAI, FALSE, BANK_0, /*goto*/ 0x16
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x13
	goto_next 0x16

	label 0x13
	goto_next 0x12

	label 0x16
	if_near_miss /*goto*/ 0x1e
	if_num_times_shot_gt 0, /*goto*/ 0x1e
	if_self_flag_bankx_eq CHRFLAG0_NOHEAR, FALSE, BANK_0, /*goto*/ 0x16
	if_chr_sees_player /*goto*/ 0x16
	goto_next 0x13

	label 0x16
	if_shot_at_close_range /*goto*/ 0x1f
	label 0x13
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEAR_ALARMS, FALSE, BANK_0, /*goto*/ 0x16
	if_alarm_active /*goto*/ 0x23
	label 0x16
	goto_first 0x1a

	label 0x1e
	dprint "SEE DETECT\n"
	say_quip CHR_JOANNA, 0x0b, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00
	label 0x9f
	set_group_alertness 100
	set_alertness 255
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label 0x1f
	yield
	say_quip CHR_JOANNA, 0x09, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEARSPAWN, TRUE, BANK_0, /*goto*/ 0xda
	set_group_alertness 100
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label 0xda
	if_never_been_onscreen /*goto*/ 0x0e
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label 0x0e
	if_chr_death_animation_finished CHR_CLONE, /*goto*/ 0x0e
	if_chr_unloaded CHR_CLONE, /*goto*/ 0x0e
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING

	label 0x0e
	try_spawn_clone2 CHR_SELF, GFUNC_SEARCH_FOR_PLAYER, 0x00000000, /*goto*/ 0x13
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label 0x13
	set_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING

	// Alert
	label 0x78
	if_self_flag_bankx_eq CHRFLAG0_CAN_HEARSPAWN, FALSE, BANK_0, /*goto*/ 0x13
	set_alertness 0
	goto_first 0xda

	label 0x13
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label 0x12
	if_self_flag_bankx_eq CHRFLAG1_00100000, TRUE, BANK_1, /*goto*/ 0x13
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING

	label 0x13
	dprint "WARNEDBEND3\n"
	set_return_function CHR_SELF, GFUNC_RELATED_TO_SPAWNING
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

/**
 * Not used?
 */
func0012_init_coop_100:
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_00000400
	set_self_flag_bank3 CHRFLAG3_00040000
	set_chr_alliance CHR_SELF, ALLIANCE_ALLY
	set_self_flag_bank3 CHRFLAG3_01000000
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED
	set_alertness 100
	set_follow_chr CHR_JOANNA
	yield
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	yield
	yield
	yield
	yield
	yield
	yield
	yield
	yield

	// Wait for intro to finish
	beginloop 0x03
		if_camera_animating /*goto*/ 0x13
		goto_next 0x16

		label 0x13
	endloop 0x03

	label 0x16
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_target_chr -1

	// Set stage flag 00000080 for Air Force One and Skedar Ruins
	if_stage_is_not STAGE_AIRFORCEONE, /*goto*/ 0x15
	set_stage_flag 0x00000080
	label 0x15

	if_stage_is_not STAGE_SKEDARRUINS, /*goto*/ 0x15
	set_stage_flag 0x00000080
	label 0x15

	// Uncloak
	set_chr_cloaked CHR_SELF, FALSE, TRUE

	// Wait 2 seconds
	restart_timer

	beginloop 0x04
		if_timer_gt 120, /*goto*/ 0x16
	endloop 0x04

	label 0x16
	set_target_chr -1

	// Set the flags again
	if_stage_is_not STAGE_AIRFORCEONE, /*goto*/ 0x15
	set_stage_flag 0x00000080

	label 0x15
	if_stage_is_not STAGE_SKEDARRUINS, /*goto*/ 0x15
	set_stage_flag 0x00000080

	label 0x15
	set_function CHR_SELF, GFUNC_COOP_BUDDY
	endfunction

/**
 * Similar to the previous function, but with minor differences.
 * Alertness is 200 for example.
 *
 * Not used?
 */
func0013_init_coop_200:
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_00000400
	set_chr_alliance CHR_SELF, ALLIANCE_ALLY
	set_self_flag_bank3 CHRFLAG3_00040000
	set_self_flag_bank3 CHRFLAG3_01000000
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED
	set_alertness 200
	yield
	yield
	yield
	yield
	yield
	yield
	yield
	yield
	yield
	set_self_flag_bank3 CHRFLAG3_00080000

	// Wait for intro to finish
	beginloop 0x03
		if_camera_animating /*goto*/ 0x13
		goto_next 0x16

		label 0x13
	endloop 0x03

	label 0x16
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_chr_cloaked CHR_SELF, FALSE, TRUE

	// Wait 2 seconds
	restart_timer

	beginloop 0x04
		if_timer_gt 120, /*goto*/ 0x16
	endloop 0x04

	label 0x16
	set_target_chr -1

	// Set stage flag 00000080 for Air Force One and Skedar Ruins
	if_stage_is_not STAGE_AIRFORCEONE, /*goto*/ 0x15
	set_stage_flag 0x00000080

	label 0x15
	if_stage_is_not STAGE_SKEDARRUINS, /*goto*/ 0x15
	set_stage_flag 0x00000080

	label 0x15
	set_function CHR_SELF, GFUNC_COOP_BUDDY
	endfunction

func0014_coop_buddy:
	.set LABEL_PLACE_BUDDY, 0x0a

	set_return_function CHR_SELF, GFUNC_COOP_BUDDY
	set_onshot_function GFUNC_COOP_BUDDY
	dprint "BACK TO BUDDY\n"
	unset_self_flag_bank3 CHRFLAG3_00040000
	set_self_flag_bankx CHRFLAG1_00100000, BANK_1
	set_var_a 0
	set_onshot_function GFUNC_COOP_BUDDY
	set_target_chr CHR_JOANNA
	if_chr_dying CHR_SELF, /*goto*/ 0x13
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
	if_chr_unloaded CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Dying
	label 0x13
	dprint "BUDDY DIE\n"
	set_function CHR_SELF, GFUNC_IDLE

	// Alive
	label 0x16
	if_just_injured CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Injured
	label 0x13
	say_quip CHR_JOANNA, 0x0e, 0xff, 0x14, 0xff, BANK_0, 0x00, 0x00 // "I'm hit, I'm hit!","I'm taking fire!","Taking damage!"
	dprint "BUDDY WOUND\n"

	beginloop 0xf2
		if_chr_flag_bank2 CHR_JOANNA, CHRFLAG2_TRIGGER_BUDDY_WARP, /*goto*/ 0x13
		unset_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED
		goto_next 0x15

		label 0x13
		if_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED, /*goto*/ 0x15
		goto_next LABEL_PLACE_BUDDY

		label 0x15
		if_chr_stopped /*goto*/ 0x16
	endloop 0xf2

	// Healthy
	label 0x16
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_08000000, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG1_00000001, BANK_1
	goto_next 0x16

	label 0x13
	set_self_flag_bankx CHRFLAG1_00000001, BANK_1
	label 0x16
	if_chr_flag_bank2 CHR_SELF, CHRFLAG2_00000400, /*goto*/ 0xdc
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x03
	label 0xdc
	set_target_chr CHR_JOANNA
	if_chr_distance_lt 200, /*goto*/ 0x16

	// Start outer loop
	label 0x00
	dprint "BUDDY GO TOWARDS\n"
	set_target_chr CHR_JOANNA
	restart_timer
	if_chr_distance_gt 300, /*goto*/ 0x16
	try_run_to_target_chr_with_hand_up /*goto*/ 0x0c
	label 0x16
	try_run_to_target_chr /*goto*/ 0x0c

	beginloop 0x0c
		if_chr_flag_bank2 CHR_JOANNA, CHRFLAG2_TRIGGER_BUDDY_WARP, /*goto*/ 0x13
		unset_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED
		goto_next 0x15

		label 0x13
		if_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED, /*goto*/ 0x15
		goto_next LABEL_PLACE_BUDDY

		label 0x15
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x06
		goto_next 0x07

		label 0x06
		set_chr_flag_bank2 CHR_SELF, CHRFLAG2_DISGUISED
		label 0x07
		set_target_chr CHR_JOANNA
		if_chr_sees_player /*goto*/ 0xdd
		if_chr_flag_bank2 CHR_SELF, CHRFLAG2_00000400, /*goto*/ 0xdc
		label 0xdd
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0x03
		label 0xdc
		set_target_chr CHR_JOANNA
		if_chr_distance_lt 200, /*goto*/ 0x16
		if_timer_gt 60, /*goto*/ 0x13
	endloop 0x0c

	label 0x13
	goto_first 0x00

	// Standing next to player
	label 0x16
	dprint "BUDDY STAND\n"
	stop_chr

	beginloop 0x04
		if_chr_flag_bank2 CHR_JOANNA, CHRFLAG2_TRIGGER_BUDDY_WARP, /*goto*/ 0x13
		unset_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED
		goto_next 0x15

		label 0x13
		if_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED, /*goto*/ 0x15
		goto_next LABEL_PLACE_BUDDY

		label 0x15
		label 0x13
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x06
		goto_next 0x07

		label 0x06
		set_chr_flag_bank2 CHR_SELF, CHRFLAG2_DISGUISED
		label 0x07
		if_chr_flag_bank2 CHR_SELF, CHRFLAG2_00000400, /*goto*/ 0xdc
		if_stage_is_not STAGE_G5BUILDING, /*goto*/ 0x15
		goto_next 0x13

		label 0x15
		if_stage_is_not STAGE_DEEPSEA, /*goto*/ 0x15
		goto_next 0x13

		// Not G5 Building or Deep Sea
		label 0x15
		cmd0127_try_find_chr_in_group /*goto*/ 0x0b

		// All stages
		label 0x13
		label 0xdc
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0x03
		set_target_chr CHR_JOANNA
		if_chr_distance_gt 300, /*goto*/ 0x16
	endloop 0x04

	label 0x16
	goto_first 0x00

	label 0x03
	dprint "DETECTED\n"
	call_rng
	if_rand_lt 85, /*goto*/ 0xfa
	if_rand_lt 170, /*goto*/ 0xf3
	say_quip CHR_JOANNA, 0x00, 0xff, 0x14, 0xff, BANK_0, 0x00, 0x00 // "I've got a clear shot","She's mine!"
	goto_next 0x13

	label 0xfa
	say_quip CHR_JOANNA, 0x0b, 0xff, 0x14, 0xff, BANK_0, 0x00, 0x00 // "Hey, you!","Intruder alert","We've got a contact!"
	goto_next 0x13

	label 0xf3
	say_quip CHR_JOANNA, 0x15, 0xff, 0x14, 0xff, BANK_0, 0x00, 0x00 // "Give it up!","Surrender, now!","Take that!"
	label 0x13

	// Found chr in group from non G5 or Deep Sea stage
	label 0x0b
	if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_08000000, /*goto*/ 0x13
	unset_self_flag_bankx CHRFLAG1_00000001, BANK_1
	goto_next 0x16

	label 0x13
	set_self_flag_bankx CHRFLAG1_00000001, BANK_1
	label 0x16
	set_return_function CHR_SELF, GFUNC_COOP_BUDDY
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR

	label LABEL_PLACE_BUDDY
	set_function CHR_SELF, GFUNC_PLACE_COOP_BUDDY
	endfunction

/**
 * Not used?
 */
func002b_do_something_and_wait:
	cmd01c5

	beginloop 0x03
		if_chr_stopped /*goto*/ 0x16
	endloop 0x03

	label 0x16
	return
	endfunction

/**
 * Not used.
 */
func0022_comment_on_player_dead:
	set_chr_field_0x356 0
	dprint "KILL\n"
	stop_chr

	// Wait until player in sight. Which won't happen if the current chr is
	// stopped and player is dying...
	beginloop 0x0c
		if_chr_sees_player /*goto*/ 0x16
	endloop 0x0c

	// Wait half a second
	label 0x16
	restart_timer

	beginloop 0x03
		if_timer_gt 30, /*goto*/ 0x13
	endloop 0x03

	// Roll the dice, and maybe wait another half second
	label 0x13
	call_rng
	if_rand_gt 25, /*goto*/ 0x16
	goto_first 0x03

	label 0x16
	dprint "KILLEDER\n"
	say_quip CHR_JOANNA, 0x26, 0xff, 0x02, 0x00, BANK_0, 0x00, 0x00 // "Grab a body bag","One for the morgue","Rest in peace"
	say_quip CHR_JOANNA, 0x15, 0x80, 0x03, 0x01, BANK_0, 0x00, 0x00 // "Give it up!","Surrender, now!","Take that!"

	beginloop 0x04
	endloop 0x04

	// Unreachable
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

/**
 * Do a sideways dodge, then assign GFUNC_ALERTED.
 *
 * Not used?
 */
func0023_dodge:
	if_chr_dying CHR_SELF, /*goto*/ 0x16
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x16
	if_chr_unloaded CHR_SELF, /*goto*/ 0x16
	goto_next 0x13

	// Dying
	label 0x16
	set_chr_field_0x356 0
	set_function CHR_SELF, GFUNC_IDLE

	label 0x13
	dprint "DODO\n"
	set_self_flag_bankx CHRFLAG1_00020000, BANK_1

	// 50% chance of hop vs jump
	call_rng
	if_rand_lt 128, /*goto*/ 0x2d
	try_hop_sideways /*goto*/ 0x13
	goto_next 0x2e

	label 0x2d
	try_jump_sideways /*goto*/ 0x13
	goto_next 0x2c

	// Unreachable
	label 0xbb
	cmd0139 25, 0x01, TRUE
	goto_next 0x2c

	// Was able to start dodge
	label 0x13

	beginloop 0x2c
		if_chr_stopped /*goto*/ 0x2e
	endloop 0x2c

	// Unable to hop sideways, or follow-through from above
	label 0x2e
	set_self_flag_bankx CHRFLAG1_00020000, BANK_1
	set_function CHR_SELF, GFUNC_ALERTED
	endfunction

/**
 * This appears to be a function used to test something related to the co-op
 * buddy and the intro cinema. The function expects the cutscene to finish and
 * then start again several times. After this has happened, the co-op buddy is
 * warped to the same pad every second.
 *
 * Not used.
 */
func0015_test_cutscene_buddy:
	stop_chr
	set_chr_cloaked CHR_SELF, TRUE, TRUE

	// Wait 1 second
	restart_timer

	beginloop 0x03
		if_timer_gt 60, /*goto*/ 0x16
	endloop 0x03

	// Hide chr
	label 0x16
	cmd01e0
	set_self_flag_bank3 CHRFLAG3_INVINCIBLE_TO_GUNFIRE
	set_self_flag_bank3 CHRFLAG3_HIDDEN | CHRFLAG3_00010000 | CHRFLAG3_00040000

	// Wait 3 seconds
	restart_timer

	beginloop 0x04
		if_timer_gt 180, /*goto*/ 0x16
	endloop 0x04

	// Wait for intro to finish and for 1 second to have passed
	// (in case intro was cut by player)
	.macro wait_intro loopid
		restart_timer
		beginloop \loopid
			if_camera_animating /*goto*/ 0x13
			if_timer_gt 60, /*goto*/ 0x16
			label 0x13
		endloop \loopid
		label 0x16
	.endm

	label 0x16

	wait_intro 0x05
	cmd01b4_if_something /*goto*/ 0x17

	wait_intro 0x06
	cmd01b4_if_something /*goto*/ 0x17

	wait_intro 0x07
	cmd01b4_if_something /*goto*/ 0x17

	wait_intro 0x08
	cmd01b4_if_something /*goto*/ 0x17

	wait_intro 0x09
	cmd01b4_if_something /*goto*/ 0x17

	wait_intro 0x0a
	cmd01b4_if_something /*goto*/ 0x17

	label 0x19
	wait_intro 0x0b

	// This will execute every second after the initial 7ish seconds and while
	// cutscene is not running. The chr is being moved back to the same pad
	// repeatedly, so this is surely some kind of debug function.
	set_chr_flag_bank2 CHR_SELF, 0x00100200
	chr_move_to_pad CHR_SELF, 0x00f8, 0x58, /*goto*/ 0x17
	goto_first 0x19

	label 0x17
	unset_self_flag_bank3 0x00050400
	unset_self_flag_bank3 CHRFLAG3_INVINCIBLE_TO_GUNFIRE
	unset_chr_flag_bank2 CHR_SELF, 0x00100200
	set_chr_cloaked CHR_SELF, FALSE, TRUE
	set_return_function CHR_SELF, GFUNC_COOP_BUDDY
	set_onshot_function GFUNC_COOP_BUDDY
	set_function CHR_SELF, GFUNC_COOP_BUDDY
	endfunction

/**
 * Not used.
 */
func002c_init_search_unused:
	set_self_flag_bankx CHRFLAG1_00000400, BANK_1
	set_self_flag_bankx CHRFLAG1_10000000, BANK_1
	set_function CHR_SELF, GFUNC_SEARCH_FOR_PLAYER
	endfunction

/**
 * Not used.
 */
func0024_follow_joanna:
	set_target_chr CHR_JOANNA

	label 0x03
	restart_timer
	try_run_to_target_chr /*goto*/ 0x04

	beginloop 0x04
		set_action ACTION_FOLLOW, FALSE
		if_chr_distance_lt 200, /*goto*/ 0x16
		if_timer_gt 120, /*goto*/ 0x13
		if_chr_stopped /*goto*/ 0x13
	endloop 0x04

	// Been running for 2 seconds, or stopped
	label 0x13
	goto_first 0x03

	// Within 200 units
	label 0x16
	stop_chr

	// Wait here until 300 units away, then follow again
	beginloop 0x05
		set_action ACTION_WAIT, FALSE
		if_chr_distance_gt 300, /*goto*/ 0x16
	endloop 0x05

	label 0x16
	goto_first 0x03

	endfunction

/**
 * Not used.
 */
func0025_pointless:
	// Wait until target chr is dead
	beginloop 0x0c
		if_chr_death_animation_finished TARGET_CHR, /*goto*/ 0x03
		if_chr_dying TARGET_CHR, /*goto*/ 0x03
	endloop 0x0c

	// Wait 10 seconds
	label 0x03
	restart_timer

	beginloop 0x04
		if_timer_gt 600, /*goto*/ 0x13
	endloop 0x04

	// Continue waiting 10 seconds indefinitely
	label 0x13
	goto_first 0x03

	endfunction

func0026_init_psychosis:
	set_onshot_function GFUNC_INIT_PSYCHOSIS
	set_chr_alliance CHR_SELF, 0x80
	set_self_flag_bankx CHRFLAG1_80000000, BANK_1
	set_self_flag_bank3 CHRFLAG3_00040000
	set_self_flag_bank3 CHRFLAG3_01000000
	set_self_flag_bankx CHRFLAG1_00100000, BANK_1
	set_self_flag_bankx CHRFLAG1_40000000, BANK_1
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_PSYCHOSISED
	set_alertness 100
	set_follow_chr CHR_JOANNA
	yield
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	yield
	yield
	yield
	yield
	yield
	yield
	yield
	yield
	animation ANIM_BIG_SNEEZE, -1, -1, 0x1014, CHR_SELF, 2

	// Wait for animation to finish
	beginloop 0x03
		if_chr_stopped /*goto*/ 0x16
	endloop 0x03

	// Become ally
	label 0x16
	set_chr_alliance CHR_SELF, ALLIANCE_ALLY
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups

	label 0x16
	set_target_chr -1
	set_function CHR_SELF, GFUNC_PSYCHOSISED
	endfunction

func0027_psychosised:
	set_var_a 0
	set_onshot_function GFUNC_PSYCHOSISED
	set_target_chr FOLLOW_CHR
	if_chr_dying CHR_SELF, /*goto*/ 0x13
	if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
	if_chr_unloaded CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Dying
	label 0x13
	set_function CHR_SELF, GFUNC_IDLE

	// Alive
	label 0x16
	if_just_injured CHR_SELF, /*goto*/ 0x13
	goto_next 0x16

	// Injured
	label 0x13
	say_quip CHR_JOANNA, 0x0e, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "I'm hit, I'm hit!","I'm taking fire!","Taking damage!"

	beginloop 0xf2
		if_chr_stopped /*goto*/ 0x16
	endloop 0xf2

	// Healthy
	label 0x16
	cmd0127_try_find_chr_in_group /*goto*/ 0x03
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0x03
	set_target_chr FOLLOW_CHR
	if_chr_distance_lt 200, /*goto*/ 0x16

	// Following Joanna
	label 0x00
	set_target_chr FOLLOW_CHR
	restart_timer
	if_chr_distance_gt 300, /*goto*/ 0x16
	try_run_to_target_chr_with_hand_up /*goto*/ 0x0c
	label 0x16
	if_chr_distance_lt 200, /*goto*/ 0x16
	try_run_to_target_chr /*goto*/ 0x0c

	beginloop 0x0c
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x06
		goto_next 0x07

		label 0x06
		set_chr_flag_bank2 CHR_SELF, CHRFLAG2_DISGUISED
		label 0x07
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0x03
		set_target_chr FOLLOW_CHR
		if_chr_distance_lt 200, /*goto*/ 0x16
		if_timer_gt 60, /*goto*/ 0x13
	endloop 0x0c

	label 0x13
	goto_first 0x00

	// At Joanna
	label 0x16
	stop_chr

	beginloop 0x04
		if_chr_flag_bank2 TARGET_CHR, CHRFLAG2_DISGUISED, /*goto*/ 0x06
		goto_next 0x07

		label 0x06
		set_chr_flag_bank2 CHR_SELF, CHRFLAG2_DISGUISED
		label 0x07
		cmd0127_try_find_chr_in_group /*goto*/ 0x03
		if_enemy_distance_lt_and_los 2540, /*goto*/ 0x03
		set_target_chr FOLLOW_CHR
		if_chr_distance_gt 300, /*goto*/ 0x16
	endloop 0x04

	label 0x16
	goto_first 0x00

	// Detected enemy
	label 0x03
	call_rng
	if_rand_lt 85, /*goto*/ 0xfa
	if_rand_lt 170, /*goto*/ 0xf3

	say_quip CHR_JOANNA, 0x00, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "I've got a clear shot","She's mine!"
	goto_next 0x13

	label 0xfa
	say_quip CHR_JOANNA, 0x0b, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Hey, you!","Intruder alert","We've got a contact!"
	goto_next 0x13

	label 0xf3
	say_quip CHR_JOANNA, 0x15, 0xff, 0x03, 0xff, BANK_0, 0x00, 0x00 // "Give it up!","Surrender, now!","Take that!"

	label 0x13
	set_return_function CHR_SELF, GFUNC_PSYCHOSISED
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

func002d_invincible_and_idle:
	set_self_flag_bank3 CHRFLAG3_INVINCIBLE_TO_GUNFIRE
	set_self_flag_bank3 CHRFLAG3_UNEXPLODABLE
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func0020_place_coop_buddy:
	set_self_flag_bank3 CHRFLAG3_INVINCIBLE_TO_GUNFIRE
	set_self_flag_bank3 CHRFLAG3_00040000
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_CLOAKED
	stop_chr
	set_target_chr CHR_JOANNA
	yield
	if_stage_is_not STAGE_DEEPSEA, /*goto*/ 0x15
	goto_next 0x16

	// Not Deep Sea
	label 0x15
	if_stage_is_not STAGE_AIRFORCEONE, /*goto*/ 0x15

	// Deep Sea or Air Force One
	label 0x16
	yield
	yield
	yield
	yield
	yield

	// Try to move chr to one of four pads until it works
	label 0x03
	yield
	try_set_target_pad_to_something2 0x01, /*goto*/ 0xfa
	goto_next 0xf3

	label 0xfa
	chr_move_to_pad CHR_SELF, TARGET_PAD, 0x01, /*goto*/ 0x13
	label 0xf3
	try_set_target_pad_to_something2 0x02, /*goto*/ 0xfa
	goto_next 0xf3

	label 0xfa
	chr_move_to_pad CHR_SELF, TARGET_PAD, 0x01, /*goto*/ 0x13
	label 0xf3
	try_set_target_pad_to_something2 0x04, /*goto*/ 0xfa
	goto_next 0xf3

	label 0xfa
	chr_move_to_pad CHR_SELF, TARGET_PAD, 0x01, /*goto*/ 0x13
	label 0xf3
	try_set_target_pad_to_something2 0x08, /*goto*/ 0xfa
	goto_next 0xf3

	label 0xfa
	chr_move_to_pad CHR_SELF, TARGET_PAD, 0x01, /*goto*/ 0x13
	label 0xf3
	goto_first 0x03

	// Move to pad worked
	label 0x13
	unset_self_flag_bank3 CHRFLAG3_HIDDEN
	unset_self_flag_bank3 CHRFLAG3_INVINCIBLE_TO_GUNFIRE
	stop_chr
	set_chr_cloaked CHR_SELF, FALSE, TRUE
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED
	set_return_function CHR_SELF, GFUNC_COOP_BUDDY
	set_function CHR_SELF, GFUNC_COOP_BUDDY

	// Not Deep Sea nor Air Force One
	label 0x15
	yield
	yield
	yield
	yield
	yield
	stop_chr
	if_stage_is_not STAGE_ATTACKSHIP, /*goto*/ 0x04

	// Attack Ship
	beginloop 0x05
		chr_move_to_pad CHR_SELF, 0x011f, 0x01, /*goto*/ 0x13
		chr_move_to_pad CHR_SELF, 0x0120, 0x01, /*goto*/ 0x13
		chr_move_to_pad CHR_SELF, 0x0121, 0x01, /*goto*/ 0x13
		chr_move_to_pad CHR_SELF, 0x0122, 0x01, /*goto*/ 0x13
	endloop 0x05

	// Not Air Force One, Deep Sea or Attack Ship
	beginloop 0x04
		chr_move_to_pad CHR_SELF, 0x0012, 0x01, /*goto*/ 0x13
		chr_move_to_pad CHR_SELF, 0x001a, 0x01, /*goto*/ 0x13
		chr_move_to_pad CHR_SELF, 0x0013, 0x01, /*goto*/ 0x13
		chr_move_to_pad CHR_SELF, 0x0019, 0x01, /*goto*/ 0x13
	endloop 0x04

	// Move to pad worked
	label 0x13
	stop_chr
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_00020000
	set_chr_flag_bank2 CHR_SELF, CHRFLAG2_BUDDY_PLACED

	// Wait until flag unset (timer is not checked)
	restart_timer

	beginloop 0xef
		if_chr_flag_bank2 CHR_JOANNA, CHRFLAG2_TRIGGER_BUDDY_WARP, /*goto*/ 0x13
		goto_next 0x16

		label 0x13
	endloop 0xef

	// Unhide
	label 0x16
	unset_self_flag_bank3 CHRFLAG3_HIDDEN
	unset_self_flag_bank3 CHRFLAG3_INVINCIBLE_TO_GUNFIRE
	stop_chr
	set_chr_cloaked CHR_SELF, FALSE, TRUE
	set_return_function CHR_SELF, GFUNC_COOP_BUDDY
	set_function CHR_SELF, GFUNC_COOP_BUDDY
	endfunction

func0021_stop_and_idle:
	set_onshot_function GFUNC_STOP_AND_IDLE
	stop_chr
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

/**
 * Maybe used by multiplayer bots?
 */
func0029_ai_bot_init:
	dprint "list: aibotinit"
	set_chr_health CHR_SELF, 80
	set_reaction_speed 100
	set_return_function CHR_SELF, GFUNC_AI_BOT_ALIVE

	beginloop 0x19
		if_chr_death_animation_finished CHR_SELF, /*goto*/ 0x13
		goto_next 0x16

		label 0x13
	endloop 0x19

	label 0x16
	set_function CHR_SELF, GFUNC_AI_BOT_ALIVE
	endfunction

func0028_ai_bot_dead:
	dprint "list: aidead"

	beginloop 0x0d
		cmd0176_if_something /*goto*/ 0x16
	endloop 0x0d

	label 0x16
	set_function CHR_SELF, GFUNC_AI_BOT_INIT
	endfunction

func002a_ai_bot_alive:
	beginloop 0xf8
		if_chr_dying CHR_SELF, /*goto*/ 0xf9
	endloop 0xf8

	label 0xf9
	set_function CHR_SELF, GFUNC_AI_BOT_DEAD
	endfunction

functions:
	register_function func0000_idle                      0x0000
	register_function func0001_unalerted_0001            0x0001
	register_function func0004_unalerted_0004            0x0004
	register_function func0003_stop_unalerted            0x0003
	register_function func0002_unalerted_0002            0x0002
	register_function func0005_end_cinema                0x0005
	register_function func0006_unalerted                 0x0006
	register_function func0007_alerted                   0x0007
	register_function func0008_wakeup                    0x0008
	register_function func000a_do_idle_animation         0x000a
	register_function func000b_choose_target_chr       0x000b
	register_function func000c_combat_with_target_chr  0x000c
	register_function func000d_init_combat               0x000d
	register_function func000e_see_then_attack           0x000e
	register_function func0016_show_objective_failed_msg 0x0016
	register_function func0017_rebuild_groups            0x0017
	register_function func0018_do_bored_animation        0x0018
	register_function func0019_do_sitting_animation      0x0019
	register_function func0000_idle_0009                 0x0009
	register_function func001a_maybe_unset_disspee       0x001a
	register_function func000f_hand_combat               0x000f
	register_function func0010_civilian_say_comment      0x0010
	register_function func0011_flee_from_grenade         0x0011
	register_function func001b_observe_camspy            0x001b
	register_function func0020_place_coop_buddy          0x0020
	register_function func0012_init_coop_100             0x0012
	register_function func0013_init_coop_200             0x0013
	register_function func0014_coop_buddy                0x0014
	register_function func001d_search_for_player         0x001d
	register_function func001e_look_around               0x001e
	register_function func001f_related_to_spawning       0x001f
	register_function func001c_surprised                 0x001c
	register_function func0022_comment_on_player_dead    0x0022
	register_function func0023_dodge                     0x0023
	register_function func002c_init_search_unused        0x002c
	register_function func0024_follow_joanna             0x0024
	register_function func0025_pointless                 0x0025
	register_function func0026_init_psychosis            0x0026
	register_function func0027_psychosised               0x0027
	register_function func002d_invincible_and_idle       0x002d
	register_function func0021_stop_and_idle             0x0021
	register_function func0015_test_cutscene_buddy       0x0015
	register_function func0028_ai_bot_dead               0x0028
	register_function func0029_ai_bot_init               0x0029
	register_function func002a_ai_bot_alive              0x002a
	register_function func002b_do_something_and_wait     0x002b
	endfunctions

.align 4
