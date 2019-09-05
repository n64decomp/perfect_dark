# vi: ft=asm

.macro register_function label id
	.word \label
	.word \id
.endm

.macro endfunctions
	.word 0
	.word 0
.endm

// ---BEGIN-COMMANDS---

.macro goto_next label
	.short 0x0000
	.byte  \label
.endm

.macro goto_first label
	.short 0x0001
	.byte  \label
.endm

.macro label id
	.short 0x0002
	.byte  \id
.endm

.macro yield
	.short 0x0003
.endm

.macro endfunction
	.short 0x0004
	.align 2
.endm

.macro set_function chr function
	.short 0x0005
	.byte  \chr
	.short \function
.endm

.macro set_return_function chr function
	.short 0x0006
	.byte  \chr
	.short \function
.endm

.macro set_onshot_function function
	.short 0x0007
	.short \function
.endm

.macro return
	.short 0x0008
.endm

.macro stop_chr
	.short 0x0009
.endm

.macro kneel
	.short 0x000a
.endm

.macro animation animation unknown1 unknown2 unknown3 chr animspeed
	.short 0x000b
	.short \animation
	.short \unknown1
	.short \unknown2
	.short \unknown3
	.byte  \chr
	.byte  \animspeed
.endm

.macro if_chr_idle label
	.short 0x000c
	.byte  \label
.endm

.macro try_jump_sideways label
	.short 0x000f
	.byte  \label
.endm

.macro try_hop_sideways label
	.short 0x0010
	.byte  \label
.endm

.macro try_run_sideways label
	.short 0x0011
	.byte  \label
.endm

.macro try_walk_and_shoot label
	.short 0x0012
	.byte  \label
.endm

.macro try_roll_and_shoot label
	.short 0x0014
	.byte  \label
.endm

.macro try_aim_and_shoot_thing1 u1 u2 label
	.short 0x0015
	.short \u1
	.short \u2
	.byte  \label
.endm

.macro try_chr_kneel_and_shoot_thing u1 u2 label
	.short 0x0016
	.short \u1
	.short \u2
	.byte  \label
.endm

.macro try_aim_and_shoot_thing2 u1 u2 label
	.short 0x0017
	.short \u1
	.short \u2
	.byte  \label
.endm

// Suspected types:
// Type 0004 = no idea
// Type 0008 = pad
// Type 0010 = compass direction (0000, 4000, 8000, c000)
// Type 0200 = player
.macro try_face_entity entity_type entity_id label
	.short 0x0018
	.short \entity_type
	.short \entity_id
	.byte  \label
.endm

.macro damage_chr chr value
	.short 0x0019
	.byte  \chr
	.byte  0x08
	.byte  \value
	.byte  0x00
	.byte  0x00
	.byte  0x00
.endm

.macro chr_shoot_chr chr1 chr2 weapon
	.short 0x001a
	.byte  \chr1
	.byte  \chr2
	.byte  \weapon
.endm

// Only ever called with values 512, 0
.macro consider_throwing_grenade value_1 value_2 label
	.short 0x001b
	.short \value_1
	.short \value_2
	.byte  \label
.endm

.macro jog_to_pad pad
	.short 0x001d
	.short \pad
.endm

.macro go_to_target_pad speed
	.short 0x001e
	.byte  \speed
.endm

.macro walk_to_pad pad
	.short 0x001f
	.short \pad
.endm

.macro run_to_pad pad
	.short 0x0020
	.short \pad
.endm

.macro assign_path pathid
	.short 0x0021
	.byte  \pathid
.endm

.macro start_path
	.short 0x0022
.endm

.macro if_path_started label
	.short 0x0023
	.byte  \label
.endm

.macro surrender
	.short 0x0024
.endm

.macro drop_gun_and_fade_out
	.short 0x0025
.endm

.macro remove_chr chr
	.short 0x0026
	.byte  \chr
.endm

.macro activate_alarm
	.short 0x0028
.endm

.macro deactivate_alarm
	.short 0x0029
.endm

.macro try_run_to_target_chr_with_hand_up label
	.short 0x002b
	.byte  \label
.endm

.macro try_walk_to_target_chr label
	.short 0x002c
	.byte  \label
.endm

.macro try_run_to_target_chr label
	.short 0x002d
	.byte  \label
.endm

.macro chr_try_run_to_target_chr_with_hand_up chr label
	.short 0x002f
	.byte  \chr
	.byte  \label
.endm

.macro try_run_to_chr chr label
	.short 0x0031
	.byte  \chr
	.byte  \label
.endm

.macro if_chr_stopped label
	.short 0x0032
	.byte  \label
.endm

.macro if_chr_dying chr label
	.short 0x0033
	.byte  \chr
	.byte  \label
.endm

.macro if_chr_death_animation_finished chr label
	.short 0x0034
	.byte  \chr
	.byte  \label
.endm

.macro if_target_chr_in_sight label
	.short 0x0035
	.byte  \label
.endm

.macro call_rng
	.short 0x0036
.endm

.macro if_rand_lt value label
	.short 0x0037
	.byte  \value
	.byte  \label
.endm

.macro if_rand_gt value label
	.short 0x0038
	.byte  \value
	.byte  \label
.endm

.macro if_alarm_active2 label
	.short 0x0039
	.byte  \label
.endm

.macro if_alarm_active label
	.short 0x003a
	.byte  \label
.endm

.macro if_hears_gunfire label
	.short 0x003c
	.byte  \label
.endm

.macro if_shot_near_chr u1 label
	.short 0x003d
	.byte  \u1
	.byte  \label
.endm

.macro if_saw_death u1 label
	.short 0x003e
	.byte  \u1
	.byte  \label
.endm

.macro if_chr_sees_player label
	.short 0x003f
	.byte  \label
.endm

.macro if_within_units_of_sight value label
	.short 0x0041
	.word  \value
	.byte  \label
.endm

.macro if_shot_at_close_range label
	.short 0x0044
	.byte  \label
.endm

.macro if_detected_chr chr label
	.short 0x0045
	.byte  \chr
	.byte  \label
.endm

.macro if_never_been_onscreen label
	.short 0x0046
	.byte  \label
.endm

.macro if_bitcheck_in_position_struct label
	.short 0x0047
	.byte  \label
.endm

// Used by CIA guards in chicago
.macro cmd0049 u1 label
	.short 0x0049
	.short \u1
	.byte  \label
.endm

.macro if_chr_in_view label
	.short 0x004a
	.byte  \label
.endm

.macro if_near_miss label
	.short 0x004b
	.byte  \label
.endm

.macro if_dying label
	.short 0x004c
	.byte  \label
.endm

.macro if_angle_to_target_chr_lt value label
	.short 0x004d
	.byte  \value
	.byte  \label
.endm

// Either bool1 or bool2 are set - never none or both
// When bool1 is set, u1 is populated
// When bool2 is set, u1 is 0 (likely unused)
.macro if_player_looking_at_something_maybe u1 bool1 bool2 label
	.short 0x004e
	.byte  \u1
	.byte  \bool1
	.byte  \bool2
	.byte  \label
.endm

// If given value * some global / 256 is less than some value derived from the current chr
// Used by skedar before they do hand combat or pounce
.macro cmd004f value label
	.short 0x004f
	.byte  \value
	.byte  \label
.endm

// The value is multiplied by a variable at 0x7f1a9364
.macro if_distance_to_target_chr_lt value label
	.short 0x0050
	.byte  \value
	.byte  \label
.endm

.macro if_chr_distance_lt distance label
	.short 0x0052
	.short \distance / 10
	.byte  \label
.endm

.macro if_chr_distance_gt distance label
	.short 0x0053
	.short \distance / 10
	.byte  \label
.endm

.macro if_chr_distance_to_pad_lt chr distance pad label
	.short 0x0054
	.byte  \chr
	.short \distance / 10
	.short \pad
	.byte  \label
.endm

.macro if_chr_distance_to_pad_gt chr distance pad label
	.short 0x0055
	.byte  \chr
	.short \distance / 10
	.short \pad
	.byte  \label
.endm

.macro if_self_distance_to_chr_lt distance chr label
	.short 0x0056
	.short \distance / 10
	.byte  \chr
	.byte  \label
.endm

.macro if_chr_distance_to_target_chr_gt distance chr label
	.short 0x0057
	.short \distance / 10
	.byte  \chr
	.byte  \label
.endm

.macro if_distance_to_pad_gt2 distance pad label
	.short 0x0059
	.short \distance / 10
	.short \pad
	.byte  \label
.endm

// type 0 = if <chr> in <room>
// type 1 = if <chr> in same room as self
// type 2 = if <chr>'s camspy in <room>
.macro if_chr_in_room chr type room label
	.short 0x005b
	.byte  \chr
	.byte  \type
	.short \room
	.byte  \label
.endm

.macro if_chr_has_object chr object label
	.short 0x005d
	.byte  \chr
	.byte  \object
	.byte  \label
.endm

.macro if_weapon_thrown weapon label
	.short 0x005e
	.byte  \weapon
	.byte  \label
.endm

.macro if_weapon_thrown_on_object weapon object label
	.short 0x005f
	.byte  \weapon
	.byte  \object
	.byte  \label
.endm

.macro if_chr_weapon_equipped chr weapon label
	.short 0x0060
	.byte  \chr
	.byte  \weapon
	.byte  \label
.endm

// If behavior is zero, go to label if object exists.
// If behavior is nonzero, do something related to the current chr and ignore
// the object parameter.
// In practice this is always called with object = -1 and behavior = 1.
.macro if_gun_unclaimed object behavior label
	.short 0x0061
	.byte  \object
	.byte  \behavior
	.byte  \label
.endm

.macro if_object_in_good_condition object label
	.short 0x0062
	.byte  \object
	.byte  \label
.endm

.macro if_chr_activated_object chr object label
	.short 0x0063
	.byte  \chr
	.byte  \object
	.byte  \label
.endm

.macro destroy_object object
	.short 0x0066
	.byte  \object
.endm

.macro drop_concealed_items chr
	.short 0x0068
	.byte  \chr
.endm

.macro chr_drop_weapon chr
	.short 0x0069
	.byte  \chr
.endm

.macro give_object_to_chr object chr
	.short 0x006a
	.byte  \object
	.byte  \chr
.endm

.macro move_object_to_pad object pad
	.short 0x006b
	.byte  \object
	.short \pad
.endm

.macro open_door door
	.short 0x006c
	.byte  \door
.endm

.macro close_door door
	.short 0x006d
	.byte  \door
.endm

.macro if_door_state door doorstate label
	.short 0x006e
	.byte  \door
	.byte  \doorstate
	.byte  \label
.endm

.macro lock_door door bits
	.short 0x0070
	.byte  \door
	.byte  \bits
.endm

.macro unlock_door door bits
	.short 0x0071
	.byte  \door
	.byte  \bits
.endm

.macro if_door_locked door bits label
	.short 0x0072
	.byte  \door
	.byte  \bits
	.byte  \label
.endm

.macro if_objective_complete objective label
	.short 0x0073
	.byte  \objective
	.byte  \label
.endm

.macro if_objective_failed objective label
	.short 0x0074
	.byte  \objective
	.byte  \label
.endm

// This is only ever called in a sequence of 4, with u1 values 8, 2, 4, 8 in
// that order. Believed to be a pad within specific distance of target chr,
// where the higher the number the further the distance.
// If u1 were 0x10 or 0x20, some other logic would be used.
.macro try_set_target_pad_to_something u1 label
	.short 0x0075
	.byte \u1
	.byte \label
.endm

// Only ever called with values 1, 2, 4 and 8. The value is related to circles,
// perhaps specifying a certain side of the target chr.
// If u1 were 0x10 or 0x20, some other logic would be used (same as previous).
.macro try_set_target_pad_to_something2 u1 label
	.short 0x0076
	.byte  \u1
	.byte  \label
.endm

.macro if_difficulty_lt diff label
	.short 0x0077
	.byte  \diff
	.byte  \label
.endm

.macro if_difficulty_gt diff label
	.short 0x0078
	.byte  \diff
	.byte  \label
.endm

.macro if_stage_lt stage label
	.short 0x007b
	.byte  \stage
	.byte  \label
.endm

.macro if_stage_gt stage label
	.short 0x007c
	.byte  \stage
	.byte  \label
.endm

.macro if_num_times_shot_lt value label
	.short 0x007d
	.byte  \value
	.byte  \label
.endm

.macro if_num_times_shot_gt value label
	.short 0x007e
	.byte  \value
	.byte  \label
.endm

// Checks chr bank 3 0x00000100. If set, unsets it and follows label.
.macro if_just_injured chr label
	.short 0x0083
	.byte  \chr
	.byte  \label
.endm

.macro set_var_a value
	.short 0x0084
	.byte  \value
.endm

.macro add_var_a value
	.short 0x0085
	.byte  \value
.endm

.macro subtract_var_a value
	.short 0x0087
	.byte  \value
.endm

.macro if_var_a_lt value label
	.short 0x0088
	.byte  \value
	.byte  \label
.endm

.macro set_alertness value
	.short 0x008a
	.byte  \value
.endm

.macro increase_self_alertness value
	.short 0x008b
	.byte  \value
.endm

.macro increase_chr_alertness value chr
	.short 0x008c
	.byte  \value
	.byte  \chr
.endm

.macro if_alertness value operator label
	.short 0x008e
	.byte  \value
	.byte  \operator
	.byte  \label
.endm

.macro if_chr_alertness_lt value chr label
	.short 0x008f
	.byte  \value
	.byte  \chr
	.byte  \label
.endm

// Set their hear distance to value divided by 1000.
// Only ever called with distance = 10,000, so it gets set to 10.
.macro set_hear_distance value
	.short 0x0092
	.short \value
.endm

.macro set_view_distance value
	.short 0x0093
	.byte  \value
.endm

.macro set_grenade_probability_out_of_255 value
	.short 0x0094
	.byte  \value
.endm

.macro set_chr_id newid
	.short 0x0095
	.byte  \newid
.endm

.macro set_chr_health chr value
	.short 0x0096
	.byte  \chr
	.short \value
.endm

.macro set_armor value
	.short 0x0097
	.short \value
.endm

.macro set_reaction_speed value
	.short 0x0098
	.byte  \value
.endm

.macro set_recovery_speed value
	.short 0x0099
	.byte  \value
.endm

.macro set_accuracy value
	.short 0x009a
	.byte  \value
.endm

.macro set_self_flag_bankx flag bank
	.short 0x009b
	.word  \flag
	.byte  \bank
.endm

.macro unset_self_flag_bankx flag bank
	.short 0x009c
	.word  \flag
	.byte  \bank
.endm

.macro if_self_flag_bankx_eq props bool bank label
	.short 0x009d
	.word  \props
	.byte  \bool
	.byte  \bank
	.byte  \label
.endm

.macro set_chr_flag_bankx chr props bank
	.short 0x009e
	.byte  \chr
	.word  \props
	.byte  \bank
.endm

.macro unset_chr_flag_bankx chr flag bank
	.short 0x009f
	.byte  \chr
	.word  \flag
	.byte  \bank
.endm

.macro if_chr_flag_bankx chr flag bank label
	.short 0x00a0
	.byte  \chr
	.word  \flag
	.byte  \bank
	.byte  \label
.endm

.macro set_stage_flag stageflag
	.short 0x00a1
	.word  \stageflag
.endm

.macro unset_stage_flag stageflag
	.short 0x00a2
	.word  \stageflag
.endm

.macro if_stage_flag_eq stageflag bool label
	.short 0x00a3
	.word  \stageflag
	.byte  \bool
	.byte  \label
.endm

.macro set_self_flag_bank3 chrflag3
	.short 0x00a4
	.word  \chrflag3
.endm

.macro unset_self_flag_bank3 chrflag3
	.short 0x00a5
	.word  \chrflag3
.endm

.macro if_self_flag_bank3 chrflag3 label
	.short 0x00a6
	.word  \chrflag3
	.byte  \label
.endm

.macro set_chr_flag_bank3 chr chrflag3
	.short 0x00a7
	.byte  \chr
	.word  \chrflag3
.endm

.macro unset_chr_flag_bank3 chr chrflag3
	.short 0x00a8
	.byte  \chr
	.word  \chrflag3
.endm

.macro if_chr_flag_bank3 chr chrflag3 label
	.short 0x00a9
	.byte  \chr
	.word  \chrflag3
	.byte  \label
.endm

.macro set_object_flag_bank0 object objectflag0
	.short 0x00aa
	.byte  \object
	.word  \objectflag0
.endm

.macro unset_object_flag_bank0 object objectflag0
	.short 0x00ab
	.byte  \object
	.word  \objectflag0
.endm

.macro set_object_flag_bank1 object objectflag1
	.short 0x00ad
	.byte  \object
	.word  \objectflag1
.endm

.macro unset_object_flag_bank1 object objectflag1
	.short 0x00ae
	.byte  \object
	.word  \objectflag1
.endm

.macro if_object_flag_bank1 object objectflag1 label
	.short 0x00af
	.byte  \object
	.word  \objectflag1
	.byte  \label
.endm

.macro set_follow_chr chr
	.short 0x00b0
	.byte  \chr
.endm

.macro set_chr_target_chr chr target
	.short 0x00b1
	.byte  \chr
	.byte  \target
.endm

.macro set_target_pad pad
	.short 0x00b2
	.short \pad
.endm

.macro dprint str
	.short 0x00b5
	.ascii "\str"
	.byte 0
.endm

.macro restart_timer
	.short 0x00b6
.endm

.macro reset_timer
	.short 0x00b7
.endm

.macro pause_timer
	.short 0x00b8
.endm

.macro resume_timer
	.short 0x00b9
.endm

.macro if_timer_gt value label
	.short 0x00bd
	.byte  0x00
	.short \value
	.byte  \label
.endm

.macro if_timer_lt value label
	.short 0x00bc
	.byte  0x00
	.short \value
	.byte  \label
.endm

.macro show_countdown_timer
	.short 0x00be
.endm

.macro hide_countdown_timer
	.short 0x00bf
.endm

.macro set_countdown_timer seconds
	.short 0x00c0
	.short \seconds
.endm

.macro stop_countdown_timer
	.short 0x00c1
.endm

.macro start_countdown_timer
	.short 0x00c2
.endm

.macro if_countdown_timer_lt value label
	.short 0x00c4
	.short \value
	.byte  \label
.endm

.macro if_countdown_timer_gt value label
	.short 0x00c5
	.short \value
	.byte  \label
.endm

.macro try_spawn_chr body head pad function props label
	.short 0x00c6
	.byte  \body
	.byte  \head
	.short \pad
	.short \function
	.word  \props
	.byte  \label
.endm

.macro try_spawn_clone body head u1 function props label
	.short 0x00c7
	.byte  \body
	.byte  \head
	.byte  \u1
	.short \function
	.word  \props
	.byte  \label
.endm

.macro try_draw_weapon model weapon u1 label
	.short 0x00c8
	.short \model
	.byte  \weapon
	.word  \u1
	.byte  \label
.endm

.macro try_spawn_clone2 chr function u1 label
	.short 0x00ca
	.byte  \chr
	.short \function
	.word  \u1
	.byte  \label
.endm

.macro message chr text
	.short 0x00cb
	.byte  \chr
	.short \text
.endm

.macro display_text_top_middle chr text color
	.short 0x00cc
	.byte  \chr
	.short \text
	.byte  \color
.endm

.macro speak chr text sound channel color
	.short 0x00cd
	.byte  \chr
	.short \text
	.short \sound
	.byte  \channel
	.byte  \color
.endm

.macro play_sound id channel
	.short 0x00ce
	.short \id
	.byte  \channel
.endm

.macro control_sound_from_object channel object bool
	.short 0x00cf
	.byte  \channel
	.byte  \object
	.byte  0x00
	.byte  \bool
.endm

.macro play_sound_from_pad pad sound
	.short 0x00d0
	.byte  0x00
	.short \pad
	.short \sound
.endm

.macro mute_channel channel
	.short 0x00d3
	.byte  \channel
.endm

.macro begin_hovercar_path path
	.short 0x00d5
	.byte  \path
.endm

.macro set_vehicle_speed speed num_accel_frames
	.short 0x00d6
	.short \speed
	.short \num_accel_frames
.endm

.macro set_rotor_speed speed u1 u2
	.short 0x00d7
	.short \speed
	.byte  \u1
	.byte  \u2
.endm

.macro set_object_image object slot image
	.short 0x00da
	.byte  \object
	.byte  \slot
	.byte  \image
.endm

.macro end_level
	.short 0x00dc
.endm

.macro enter_firstperson
	.short 0x00dd
.endm

.macro enter_camera_and_move_to_pad pad
	.short 0x00de
	.short \pad
.endm

.macro revoke_control chr value
	.short 0x00e0
	.byte  \chr
	.byte  \value
.endm

.macro grant_control chr
	.short 0x00e1
	.byte  \chr
.endm

.macro chr_move_to_pad chr pad unknown label
	.short 0x00e2
	.byte  \chr
	.short \pad
	.byte  \unknown
	.byte  \label
.endm

.macro open_door2 door
	.short 0x00e8
	.byte  \door
.endm

// Reads 4 global values and counts how many are nonzero.
// If number of nonzeroes is less than given value, goto label.
// Only ever called with value = 2
.macro if_num_human_players_lt value label
	.short 0x00ea
	.byte  \value
	.byte  \label
.endm

.macro if_ammo_quantity_lt chr ammotype value label
	.short 0x00eb
	.byte  \chr
	.byte  \ammotype
	.byte  \value
	.byte  \label
.endm

.macro chr_draw_weapon chr weapon
	.short 0x00ec
	.byte  \chr
	.byte  \weapon
.endm

.macro chr_draw_weapon_in_cutscene chr weapon
	.short 0x00ed
	.byte  \chr
	.byte  \weapon
.endm

.macro if_object_in_room object room label
	.short 0x00ef
	.byte  \object
	.short \room
	.byte  \label
.endm

.macro set_invincible chr
	.short 0x00f3
	.byte  \chr
.endm

.macro if_all_objectives_complete label
	.short 0x00f7
	.byte  \label
.endm

.macro play_x_music channel seconds
	.short 0x00f9
	.byte  0x01
	.byte  \channel
	.byte  \seconds
.endm

.macro stop_music_channel channel
	.short 0x00fa
	.byte  \channel
.endm

.macro explosions_around_chr chr
	.short 0x00fb
	.byte  \chr
.endm

.macro if_kill_count_gt value label
	.short 0x00fc
	.byte  \value
	.byte  \label
.endm

.macro set_lights_state room u1 u2 u3 u4
	.short 0x0102
	.short \room
	.byte  \u1
	.byte  \u2
	.byte  \u3
	.byte  \u4
	.byte  0x00
	.byte  0x00
	.byte  0x00
.endm

.macro set_target_chr chr
	.short 0x0106
	.byte  \chr
	.short 0
.endm

.macro if_target_chrs_field_0x17e_is_different label
	.short 0x0107
	.byte  \label
.endm

// Used only in globals.s with CHR_SELF, CHR_P1P2, FALSE
.macro cmd0108_if_something chr1 chr2 bool label
	.short 0x0108
	.byte  \chr1
	.byte  \chr2
	.byte  \bool
	.byte  \label
.endm

.macro set_chr_alliance chr alliance
	.short 0x010b
	.byte  \chr
	.byte  \alliance
.endm

.macro set_shield value
	.short 0x010e
	.short \value
.endm

.macro if_chr_shield_lt chr value label
	.short 0x010f
	.byte  \chr
	.short \value
	.byte  \label
.endm

.macro camera_movement animation
	.short 0x0111
	.short \animation
.endm

.macro object_do_animation u1 object u2 u3
	.short 0x0112
	.short \u1
	.byte  \object
	.short \u2
	.byte  \u3
.endm

.macro if_camera_animating label
	.short 0x0113
	.byte  \label
.endm

.macro show_chr chr
	.short 0x0114
	.byte  \chr
.endm

.macro hide_chr chr
	.short 0x0115
	.byte  \chr
.endm

.macro show_object object
	.short 0x0116
	.byte  \object
.endm

.macro hide_object object
	.short 0x0117
	.byte  \object
.endm

.macro set_object_flag_bank2 object objectflag2
	.short 0x0118
	.byte  \object
	.word  \objectflag2
.endm

.macro unset_object_flag_bank2 object objectflag2
	.short 0x0119
	.byte  \object
	.word  \objectflag2
.endm

.macro if_object_flag_bank2 object objectflag2 label
	.short 0x011a
	.byte  \object
	.word  \objectflag2
	.byte  \label
.endm

.macro set_chr_flag_bank2 chr chrflag2
	.short 0x011b
	.byte  \chr
	.word  \chrflag2
.endm

.macro unset_chr_flag_bank2 chr chrflag2
	.short 0x011c
	.byte  \chr
	.word  \chrflag2
.endm

.macro if_chr_flag_bank2 chr chrflag2 label
	.short 0x011d
	.byte  \chr
	.word  \chrflag2
	.byte  \label
.endm

// This is definitely wrong
.macro if_chr_is_dead_maybe chr label
	.short 0x011f
	.byte  \chr
	.byte  \label
.endm

// Tries to find an chr in the group who meets certain criteria. For each
// chr, a score is calculated based on several fchrs, such as whether
// they've been shot. If any chr in the group has a score lower than the given
// value, the condition passes.
.macro if_retreat_risk_lt value label
	.short 0x0120
	.byte  \value
	.byte  \label
.endm

// If cover exists nearby
.macro cmd0121_if_something u1 label
	.short 0x0121
	.short \u1
	.byte  \label
.endm

.macro cmd0124_run_for_cover_maybe action
	.short 0x0124
	.byte  \action
.endm

// Related to command 012f
// globals.s only
.macro cmd0125_if_or_try_something label
	.short 0x0125
	.byte  \label
.endm

// Looks at the first element in some struct array,
// and checks if field 0x640 is nonzero.
// globals.s only
.macro cmd0126_if_something label
	.short 0x0126
	.byte  \label
.endm

// Tries to find an chr in the group who meets some criteria, the stores them
// in the current chr's struct at 0x17e.
// globals.s only
.macro cmd0127_try_find_chr_in_group label
	.short 0x0127
	.byte  \label
.endm

// Check if there's an enemy within the range and sight, then sets the
// target chr field to that enemy
.macro if_enemy_distance_lt_and_los distance label
	.short 0x0128
	.byte  \distance / 10
	.byte  \label
.endm

// If value is nonzero then it's an chr ID. If zero then use current chr.
// This means chr ID 0 cannot be used. In practice, this command is only
// called once and it has value 0.
.macro if_something_hypotenuse value label
	.short 0x012a
	.byte  \value
	.byte  \label
.endm

// Checks if the chr is within 50 units of something
.macro if_something_chicago_robot label
	.short 0x012b
	.byte  \label
.endm

// Does some math on chr fields 0x1a0 and 0x290, possibly involving square roots.
// If result is > 50, goto label
.macro if_distance_to_home_gt_50_maybe label
	.short 0x012c
	.byte  \label
.endm

// If chr field 0x292 > 0, call some function.
// Involves some global array at 0x800a2360
// globals.s only
.macro cmd012f
	.short 0x012f
.endm

.macro say_quip chr u1 index u2 u3 bank u4 channel
	.short 0x0130
	.byte  \chr
	.byte  \u1
	.byte  \index
	.byte  \u2
	.byte  \u3
	.byte  \bank
	.byte  \u4
	.byte  \channel
.endm

.macro set_group_alertness value
	.short 0x0131
	.byte  \value
.endm

// Sets chr's field_0x2a0 to value. If bool is false, also sets 0x2a1 to zero.
.macro set_action value bool
	.short 0x0132
	.byte  \value
	.byte  \bool
.endm

// Set next action (0x2a1)?
.macro cmd0133 action label
	.short 0x0133
	.byte  \action
	.byte  \label
.endm

.macro if_field_0x2a1_eq action label
	.short 0x0134
	.byte  0xfd
	.byte  \action
	.byte  \label
.endm

.macro if_field_0x2a1_nonzero label
	.short 0x0135
	.byte  \label
.endm

// u1 can theoretically be any value but in practice is only ever 2.
// u2 can be either 0, 1 or 2 and determines what the command does,
// but in practice is only ever 1 or 2.
.macro retreat u1 u2
	.short 0x0136
	.byte  \u1
	.byte  \u2
.endm

.macro if_any_chr_doing_action action label
	.short 0x0137
	.byte  \action
	.byte  \label
.endm

.macro if_sound_finished channel label
	.short 0x0138
	.byte  \channel
	.byte  \label
.endm

// value is either 25, 70 or 335.
// u1 is either 1 or 2.
// It seems related to the chr's position properties
// Used by G5 cloaked guards, Deep Sea cloaked purple guards and globals.s
// I think this is related to flanking, where the value arg is the angle
// relative to the player's direction. 335 is the same as 25 degress to the
// right (360 - 25).
.macro cmd0139 value u1 bool
	.short 0x0139
	.word  \value
	.byte  \u1
	.byte  \bool
.endm

.macro try_target_chr_in_same_group label
	.short 0x013a
	.short 0x0000
	.byte  \label
.endm

.macro set_group id
	.short 0x013b
	.byte  \id
.endm

// Value is only ever 3. The function checks bits 0x01 and 0x02 to decide what
// to do, so in all cases it does both paths.
// globals.s only
.macro cmd013d_if_grenade_thrown_nearby_maybe value label
	.short 0x013d
	.byte  \value
	.byte  \label
.endm

.macro run_from_grenade
	.short 0x013e
.endm

.macro if_hoverbot_path_finished u1 u2 label
	.short 0x0140
	.byte  \u1
	.byte  \u2
	.byte  \label
.endm

.macro shuffle_investigation_terminals dst1 dst2 src1 src2 src3 src4
	.short 0x0141
	.byte  \dst1
	.byte  \dst2
	.byte  \src1
	.byte  \src2
	.byte  \src3
	.byte  \src4
	.byte  0x00
.endm

.macro jog_to_object object
	.short 0x0142
	.byte  \object
	.byte  0x00
.endm

// Related to hovercopter and Infiltration interceptors
// Sets player struct's field_0x2e to 1/true.
.macro cmd0143
	.short 0x0143
.endm

.macro cmd0145_rebuild_groups
	.short 0x0145
.endm

.macro cmd0146_rebuild_groups
	.short 0x0146
.endm

.macro if_all_chrs_in_group_are_dead group label
	.short 0x0147
	.byte  \group
	.byte  \label
.endm

.macro if_num_chrs_in_group_gt value group label
	.short 0x0152
	.byte  \value
	.byte  \group
	.byte  \label
.endm

.macro set_tinted_glass_enabled bool
	.short 0x0157
	.byte  \bool
.endm

.macro play_music_track id
	.short 0x015b
	.byte  \id
.endm

.macro restart_music
	.short 0x015c
.endm

.macro if_chr_injured_target chr label
	.short 0x0165
	.byte  \chr
	.byte  \label
.endm

.macro hovercopter_fire_rocket side
	.short 0x0167
	.byte  \side
.endm

// If flag is set, unsets it and goes to label
.macro try_unset_chr_flag_bank3_02000000 chr label
	.short 0x0168
	.byte  \chr
	.byte  \label
.endm

.macro if_chr_idle_action_eq action label
	.short 0x0169
	.byte  \action
	.byte  \label
.endm

.macro if_chr_y chr value operator label
	.short 0x016a
	.byte  \chr
	.short \value
	.byte  \operator
	.byte  \label
.endm

.macro play_sound_from_object channel object sound u1
	.short 0x016b
	.byte  \channel
	.byte  \object
	.short 0x0001
	.short \sound
	.short \u1
.endm

.macro noop016c
	.short 0x016c
.endm

.macro add_motion_blur chr value bool
	.short 0x016d
	.byte  \chr
	.byte  \value
	.byte  \bool
.endm

.macro damage_chr2 chr value
	.short 0x016e
	.byte  \chr
	.short \value
.endm

// Likely related to being disarmed.
// Not sure what this does if the chr had no gun to begin with.
.macro if_has_gun chr label
	.short 0x016f
	.byte  \chr
	.byte  0x00
	.byte  \label
.endm

// If bool is false, run some function on the chr and their gun ground
// position, then follow the label.
// If bool is true, don't call the function, and only follow the label if field
// 0x4 in the gun ground position struct is less than 64.
.macro if_gun_landed bool label
	.short 0x0170
	.byte  \bool
	.byte  \label
.endm

.macro if_distance_to_target_position_lt distance label
	.short 0x0171
	.short \distance / 10
	.byte  \label
.endm

// Makes gun disappear from the ground and gives it to the chr
// (when a guard drops their gun and picks it up)
.macro chr_recover_gun chr label
	.short 0x0172
	.byte  \chr
	.byte  \label
.endm

.macro try_inherit_properties chr_src label
	.short 0x0173
	.byte  \chr_src
	.byte  \label
.endm

.macro if_controller_button_pressed label
	.short 0x0174
	.byte  \label
.endm

// Used in cutscenes before giving control to Jo
// Value is always 60
// Without this command, or with a 0 value, Jo faces a different direction
.macro cmd0175 u1
	.short 0x0175
	.byte  \u1
.endm

// Points to a non-command function...?
// globals.s only
.macro cmd0176_if_something label
	.short 0x0176
	.byte \label
.endm

.macro force_walk chr pad unknown1 unknown2
	.short 0x0177
	.byte  \chr
	.short \pad
	.short \unknown1
	.short \unknown2
.endm

.macro if_force_walk_finished chr label
	.short 0x0178
	.byte  \chr
	.byte  \label
.endm

.macro play_sound_from_entity channel entity_id u1 u2 entity_type
	.short 0x0179
	.byte  \channel
	.byte  \entity_id
	.short 0x0001
	.short \u1
	.short \u2
	.byte  \entity_type
.endm

// Suspected to be named incorrectly. Global functions suggests this checks if
// the chr can see the player.
.macro if_in_disarm_range label
	.short 0x017a
	.byte  \label
.endm

.macro if_chr_unloaded chr label
	.short 0x017b
	.byte  \chr
	.byte  \label
.endm

.macro assign_sound sound channel
	.short 0x017c
	.short \sound
	.byte  \channel
.endm

.macro set_music_track id
	.short 0x017d
	.byte  \id
.endm

.macro restart_default_music
	.short 0x017e
.endm

.macro set_sfx_track id
	.short 0x017f
	.byte  \id
.endm

.macro reset_ambience
	.short 0x0180
.endm

.macro if_chr_looking_at_object chr object label
	.short 0x0181
	.byte  \chr
	.byte  \object
	.byte  \label
.endm

.macro try_punch_or_kick label
	.short 0x0182
	.byte  0x00
	.byte  \label
.endm

// Related to chr fields 0x17e and 0x32e
// In practice, scripts will assign function unalerted guard if this passes
.macro if_chr_lost_track_of_target_maybe label
	.short 0x0183
	.byte  \label
.endm

// Involves a call to the RNG, and zeroing chr props 0x160 through 0x016c
//
// Called with values:
// 0x5a64 (23140)
// 0x283c (10300)
// 0x141e (5150)
//
// Used by:
// Attack Ship - Bridge skedar (with 0x283c)
// Ruins - Reaper and Slayer skedar (with 0x283c)
// globals.s - with values 0x5a64 and 0x141e
//
// Sometimes accompanied with dprint "FIRE FULL"
.macro cmd0184 u1
	.short 0x0184
	.short \u1
.endm

// The rom address for this command is not a valid function entry...?
.macro cmd0185_mponly
	.short 0x0185
.endm

// 0258 01 15
.macro if_chr_field_0x120 value operator label
	.short 0x0186
	.short \value
	.byte  \operator
	.byte  \label
.endm

.macro if_chr_sees_camspy_maybe label
	.short 0x0187
	.byte  \label
.endm

.macro if_lift_stationary lift label
	.short 0x0188
	.byte  \lift
	.byte  \label
.endm

.macro enable_rain value
	.short 0x018b
	.byte  \value
.endm

.macro remove_cass_necklace chr
	.short 0x018c
	.byte  \chr
	.byte  0x07
.endm

.macro activate_lift liftid object
	.short 0x018d
	.byte  \liftid
	.byte  \object
.endm

.macro miniskedar_try_pounce u1 u2 label
	.short 0x018e
	.byte  \u1
	.short \u2
	.byte  0x00
	.byte  \label
.endm

.macro if_object_distance_to_pad_lt object distance pad label
	.short 0x018f
	.byte  \object
	.short \distance / 10
	.short \pad
	.byte  \label
.endm

.macro set_eeprom_flag eeprom_flag
	.short 0x0190
	.byte  \eeprom_flag
.endm

.macro unset_eeprom_flag eeprom_flag
	.short 0x0191
	.byte  \eeprom_flag
.endm

.macro if_eeprom_flag_is_set eeprom_flag label
	.short 0x0192
	.byte  \eeprom_flag
	.byte  \label
.endm

.macro if_eeprom_flag_is_unset eeprom_flag label
	.short 0x0193
	.byte  \eeprom_flag
	.byte  \label
.endm

.macro if_object_health_lt object value label
	.short 0x019e
	.byte  \object
	.short \value
	.byte  \label
.endm

.macro set_object_health object value
	.short 0x019f
	.byte  \object
	.short \value
.endm

.macro set_chr_special_death_animation chr animation
	.short 0x01a0
	.byte  \chr
	.byte  \animation
.endm

// Copies a value from the chr's position struct into the chr struct itself
.macro set_chr_field_0x330
	.short 0x01a1
.endm

.macro play_chr_specific_quip bank channel
	.short 0x01a2
	.byte  \bank
	.byte  \channel
.endm

.macro do_special_animation value
	.short 0x01a3
	.byte  \value
.endm

.macro display_text position color text
	.short 0x01a4
	.byte  \position
	.byte  \color
	.short \text
.endm

.macro if_chr_field0x332_zero chr label
	.short 0x01a7
	.byte  \chr
	.byte  \label
.endm

.macro if_num_subdued value operator label
	.short 0x01ab
	.byte  \value
	.byte  1 - \operator
	.byte  \label
.endm

.macro release_grabbed_object chr
	.short 0x01ad
	.byte  \chr
.endm

.macro clear_inventory chr
	.short 0x01ae
	.byte  \chr
.endm

.macro grab_object chr object
	.short 0x01af
	.byte  \chr
	.byte  \object
.endm

.macro shuffle_ruins_pillars pdst1 pdst2 pdst3 psrc1 psrc2 psrc3 psrc4 psrc5 mdst1 mdst2 mdst3 msrc1 msrc2 msrc3 msrc4 msrc5
	.short 0x01b1
	.byte  \pdst1
	.byte  \pdst2
	.byte  \pdst3
	.byte  \psrc1
	.byte  \psrc2
	.byte  \psrc3
	.byte  \psrc4
	.byte  \psrc5
	.byte  \mdst1
	.byte  \mdst2
	.byte  \mdst3
	.byte  \msrc1
	.byte  \msrc2
	.byte  \msrc3
	.byte  \msrc4
	.byte  \msrc5
.endm

// This just does:
// addr8007db84 = addr7f1a9da4 * value
// In practice, value is 8, 11, 15, 20, 22 and 130,
// though some of these setup files are probably not used.
.macro cmd01b2_mponly value
	.short 0x01b2
	.byte  \value
.endm

.macro consider_coop_for_p1p2_chr chr
	.short 0x01b3
	.byte  \chr
.endm

.macro cmd01b4_if_something label
	.short 0x01b4
	.byte  \label
.endm

.macro enable_snow bool
	.short 0x01b6
	.byte  \bool
.endm

// bool_unknown determines whether to call some function on the chr afterwards
.macro set_chr_cloaked chr bool_enable bool_unknown
	.short 0x01b7
	.byte  \chr
	.byte  \bool_enable
	.byte  \bool_unknown
.endm

.macro set_autoturret_type object type
	.short 0x01b8
	.byte  \object
	.byte  \type
.endm

.macro shuffle_pelagic_switches
	.short 0x01b9
.endm

.macro cmd01ba u1 u2 label
	.short 0x01ba
	.short \u1
	.short \u2
	.byte  \label
.endm

.macro if_training_pc_holographed label
	.short 0x01bd
	.byte  \label
.endm

.macro if_chr_has_weapon_equipped chr weapon label
	.short 0x01be
	.byte  \chr
	.byte  \weapon
	.byte  \label
.endm

.macro teleport_to_pad pad chr
	.short 0x01bf
	.short \pad
	.byte  \chr
.endm

.macro if_teleport_full_white label chr
	.short 0x01c0
	.byte  \label
	.byte  \chr
.endm

.macro set_chr_field_0x356 value
	.short 0x01c2
	.short \value
.endm

// Sets a function in the chr's struct. Likely a callback of some sort, such as
// the onshot function.
.macro set_unknown_function function
	.short 0x01c3
	.short \function
.endm

// Calls some function on the chr. Possibly related to geometry, because it
// works with values such as 45 and 360.
.macro cmd01c5
	.short 0x01c5
.endm

// Sets a field in the chr struct
// If whichprop is 0, set field 0x35e
// If whichprop is 1, set field 0x35f
// If whichprop is 2, set both
.macro set_chr_field_0x35e_0x35f value whichprop
	.short 0x01c6
	.byte  \value
	.byte  \whichprop
.endm

.macro set_chr_field0x360 value
	.short 0x01c7
	.byte  \value
.endm

// Only used in test levels. Value can be 0-4.
// Looks up the index in a pointer array and calls the function at the pointer.
// If passed a value > 4, sets 800624b8 to -1.
// Related to cmd01c9
.macro cmd01c8 value
	.short 0x01c8
	.byte  \value
.endm

// Test levels only. Checks if value at 800624b8 is >= 0.
// If so, runs some function and goes to label.
// Related to cmd01c8.
.macro cmd01c9 label
	.short 0x01c9
	.byte  \label
.endm

.macro set_cutscene_weapon chr weapon weapon_fallback
	.short 0x01ca
	.byte  \chr
	.byte  \weapon
	.byte  \weapon_fallback
.endm

.macro fade_to_color rgba num_frames
	.short 0x01cb
	.word  \rgba
	.short \num_frames
.endm

.macro set_chr_hud_visible chr bool
	.short 0x01cd
	.byte  \chr
	.byte  \bool
.endm

// If enabled, Jo cannot use weapons or even the "unarmed" weapon
.macro passive_mode bool
	.short 0x01ce
	.byte  \bool
.endm

.macro set_chr_shooting_in_cutscene chr bool
	.short 0x01cf
	.byte  \chr
	.byte  \bool
.endm

.macro set_portal_flag portal flag
	.short 0x01d0
	.short \portal
	.byte  \flag
.endm

.macro set_object_part_visible object bool
	.short 0x01d1
	.byte  \object
	.byte  0xb7
	.byte  \bool
.endm

.macro emit_sparks chr
	.short 0x01d2
	.byte  \chr
.endm

.macro set_drcaroll_image chr left right
	.short 0x01d3
	.byte  \chr
	.byte  \left
	.byte  \right
.endm

.macro configure_room_portals room
	.short 0x01d4
	.short \room
	.short 0x0800
.endm

.macro show_nonessential_chrs bool
	.short 0x01d5
	.byte  \bool
.endm

.macro set_lighting room operation unknown
	.short 0x01d6
	.short \room
	.byte  \operation
	.byte  \unknown
.endm

.macro play_sound_from_object2 channel object sound u1 u2
	.short 0x01d9
	.byte  \channel
	.byte  \object
	.short \sound
	.short 0xffff
	.byte  \u1
	.byte  0x00
	.byte  \u2
.endm

// Only called in AF1 with param 0x35.
// Calls some functions and stores the value at 80840c8.
.macro cmd01da u1
	.short 0x01da
	.byte  \u1
.endm

.macro kill chr
	.short 0x01db
	.byte  \chr
.endm

.macro remove_weapon_from_inventory weapon
	.short 0x01dc
	.byte  \weapon
.endm

// Only used to trigger the Defection intro.
// Calls a bunch of functions outside of the main game binary object and then
// goes to label if 800840c4 is 0.
.macro cmd01dd_if_something u1 label
	.short 0x01dd
	.byte  \u1
	.byte  \label
.endm

.macro if_chr_distance_to_pad_lt2 chr pad distance label
	.short 0x01df
	.byte  \chr
	.short \pad
	.short \distance / 10
	.byte  \label
.endm

.macro if_coop_mode label
	.short 0x01de
	.byte  \label
.endm

// Something to do with the chr's position struct
.macro cmd01e0
	.short 0x01e0
.endm

// ---END-COMMANDS---

.macro beginloop id
	label \id
	yield
.endm

.macro endloop id
	goto_first \id
.endm

.macro reloop id
	goto_first \id
.endm

.macro remove_displayed_text
	display_text 0x02, 0, 0x0002
.endm

.macro if_stage_is_not stage label
	if_stage_lt \stage \label
	if_stage_gt \stage \label
.endm

