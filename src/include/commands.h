#include "util.h"

#define goto_next(label) \
	mkshort(0x0000), \
	label,

#define goto_first(label) \
	mkshort(0x0001), \
	label,

#define label(id) \
	mkshort(0x0002), \
	id,

#define yield \
	mkshort(0x0003),

#define endfunction \
	mkshort(0x0004),

#define set_function(chr, function) \
	mkshort(0x0005), \
	chr, \
	mkshort(function),

#define set_return_function(chr, function) \
	mkshort(0x0006), \
	chr, \
	mkshort(function),

#define set_onshot_function(function) \
	mkshort(0x0007), \
	mkshort(function),

#define return \
	mkshort(0x0008),

#define stop_chr \
	mkshort(0x0009),

#define kneel \
	mkshort(0x000a),

#define animation(animation, startframe, endframe, flags, transition, chr, animspeed) \
	mkshort(0x000b), \
	mkshort(animation), \
	mkshort(startframe), \
	mkshort(endframe), \
	flags, \
	transition, \
	chr, \
	animspeed,

#define if_chr_idle(label) \
	mkshort(0x000c), \
	label,

#define try_jump_sideways(label) \
	mkshort(0x000f), \
	label,

#define try_hop_sideways(label) \
	mkshort(0x0010), \
	label,

#define try_run_sideways(label) \
	mkshort(0x0011), \
	label,

#define try_walk_and_shoot(label) \
	mkshort(0x0012), \
	label,

#define try_roll_and_shoot(label) \
	mkshort(0x0014), \
	label,

#define try_aim_and_shoot_thing1(u1, u2, label) \
	mkshort(0x0015), \
	mkshort(u1), \
	mkshort(u2), \
	label,

#define try_chr_kneel_and_shoot_thing(u1, u2, label) \
	mkshort(0x0016), \
	mkshort(u1), \
	mkshort(u2), \
	label,

#define try_aim_and_shoot_thing2(u1, u2, label) \
	mkshort(0x0017), \
	mkshort(u1), \
	mkshort(u2), \
	label,

// Suspected types:
// Type 0004 = no idea
// Type 0008 = pad
// Type 0010 = compass direction (0000, 4000, 8000, c000)
// Type 0200 = player
#define try_face_entity(entity_type, entity_id, label) \
	mkshort(0x0018), \
	mkshort(entity_type), \
	mkshort(entity_id), \
	label,

#define damage_chr(chr, value) \
	mkshort(0x0019), \
	chr, \
	0x08, \
	value, \
	0x00, \
	0x00, \
	0x00,

#define chr_shoot_chr(chr1, chr2, weapon) \
	mkshort(0x001a), \
	chr1, \
	chr2, \
	weapon,

// Only ever called with values 512, 0
#define consider_throwing_grenade(value_1, value_2, label) \
	mkshort(0x001b), \
	mkshort(value_1), \
	mkshort(value_2), \
	label,

#define jog_to_pad(pad) \
	mkshort(0x001d), \
	mkshort(pad),

#define go_to_target_pad(speed) \
	mkshort(0x001e), \
	speed,

#define walk_to_pad(pad) \
	mkshort(0x001f), \
	mkshort(pad),

#define run_to_pad(pad) \
	mkshort(0x0020), \
	mkshort(pad),

#define assign_path(pathid) \
	mkshort(0x0021), \
	pathid,

#define start_path \
	mkshort(0x0022),

#define if_path_started(label) \
	mkshort(0x0023), \
	label,

#define surrender \
	mkshort(0x0024),

#define drop_gun_and_fade_out \
	mkshort(0x0025),

#define remove_chr(chr) \
	mkshort(0x0026), \
	chr,

#define activate_alarm \
	mkshort(0x0028),

#define deactivate_alarm \
	mkshort(0x0029),

#define try_run_to_target_chr_with_hand_up(label) \
	mkshort(0x002b), \
	label,

#define try_walk_to_target_chr(label) \
	mkshort(0x002c), \
	label,

#define try_run_to_target_chr(label) \
	mkshort(0x002d), \
	label,

#define try_run_to_chr_with_hand_up(chr, label) \
	mkshort(0x002f), \
	chr, \
	label,

#define try_run_to_chr(chr, label) \
	mkshort(0x0031), \
	chr, \
	label,

#define if_chr_stopped(label) \
	mkshort(0x0032), \
	label,

#define if_chr_dying(chr, label) \
	mkshort(0x0033), \
	chr, \
	label,

#define if_chr_death_animation_finished(chr, label) \
	mkshort(0x0034), \
	chr, \
	label,

#define if_target_chr_in_sight(label) \
	mkshort(0x0035), \
	label,

#define call_rng \
	mkshort(0x0036),

#define if_rand_lt(value, label) \
	mkshort(0x0037), \
	value, \
	label,

#define if_rand_gt(value, label) \
	mkshort(0x0038), \
	value, \
	label,

#define if_alarm_active2(label) \
	mkshort(0x0039), \
	label,

#define if_alarm_active(label) \
	mkshort(0x003a), \
	label,

#define if_hears_gunfire(label) \
	mkshort(0x003c), \
	label,

#define if_shot_near_chr(u1, label) \
	mkshort(0x003d), \
	u1, \
	label,

#define if_saw_death(u1, label) \
	mkshort(0x003e), \
	u1, \
	label,

#define if_chr_sees_player(label) \
	mkshort(0x003f), \
	label,

#define if_within_units_of_sight(value, label) \
	mkshort(0x0041), \
	mkword(value), \
	label,

#define if_shot_at_close_range(label) \
	mkshort(0x0044), \
	label,

#define if_detected_chr(chr, label) \
	mkshort(0x0045), \
	chr, \
	label,

#define if_never_been_onscreen(label) \
	mkshort(0x0046), \
	label,

#define if_bitcheck_in_position_struct(label) \
	mkshort(0x0047), \
	label,

// Used by CIA guards in chicago
#define cmd0049(u1, label) \
	mkshort(0x0049), \
	mkshort(u1), \
	label,

#define if_chr_in_view(label) \
	mkshort(0x004a), \
	label,

#define if_near_miss(label) \
	mkshort(0x004b), \
	label,

#define if_dying(label) \
	mkshort(0x004c), \
	label,

// Checks if Jo is within a certain angle of the chr's direction.
// Value is a percentage of the circle, where 256 is a full circle.
// Only ever called with value = decimal 10, which is about 14 degrees.
// With value 10, returns true if Jo is roughly within 12-11 o'clock.
#define if_jo_ccw_direction_lt(value, label) \
	mkshort(0x004d), \
	value, \
	label,

// Either bool1 or bool2 are set - never none or both
// When bool1 is set, u1 is populated
// When bool2 is set, u1 is 0 (likely unused)
#define if_player_looking_at_something_maybe(u1, bool1, bool2, label) \
	mkshort(0x004e), \
	u1, \
	bool1, \
	bool2, \
	label,

// Checks if Jo is outside of a certain angle of the chr's direction.
// Value is a percentage of the circle, where 256 is a full circle.
// Called with values = -10 and -11, which is about -14 degrees.
// With value -10, returns true if Jo is roughly within 12-1 o'clock.
#define if_jo_ccw_direction_gt(value, label) \
	mkshort(0x004f), \
	value, \
	label,

// Similar to 004d and 004f, but checks if Jo is within the angle of player's
// 12 o'clock (ie. either side).
#define if_jo_front_direction_lt(value, label) \
	mkshort(0x0050), \
	value, \
	label,

// Similar to 004d and 004f, but checks if Jo is not in front of the current chr
// by the given angle.
#define if_jo_front_direction_gt(value, label) \
	mkshort(0x0051), \
	value, \
	label,

#define if_chr_distance_lt(distance, label) \
	mkshort(0x0052), \
	mkshort(distance / 10), \
	label,

#define if_chr_distance_gt(distance, label) \
	mkshort(0x0053), \
	mkshort(distance / 10), \
	label,

#define if_chr_distance_to_pad_lt(chr, distance, pad, label) \
	mkshort(0x0054), \
	chr, \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

#define if_chr_distance_to_pad_gt(chr, distance, pad, label) \
	mkshort(0x0055), \
	chr, \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

#define if_self_distance_to_chr_lt(distance, chr, label) \
	mkshort(0x0056), \
	mkshort(distance / 10), \
	chr, \
	label,

#define if_chr_distance_to_target_chr_gt(distance, chr, label) \
	mkshort(0x0057), \
	mkshort(distance / 10), \
	chr, \
	label,

#define if_distance_from_target_to_pad_lt(distance, pad, label) \
	mkshort(0x0059), \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

#define if_distance_from_target_to_pad_gt(distance, pad, label) \
	mkshort(0x005a), \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

// type 0 = if <chr> in <room>
// type 1 = if <chr> in same room as self
// type 2 = if <chr>'s camspy in <room>
#define if_chr_in_room(chr, type, room, label) \
	mkshort(0x005b), \
	chr, \
	type, \
	mkshort(room), \
	label,

#define if_target_in_room(room, label) \
	mkshort(0x005c), \
	mkshort(room), \
	label

#define if_chr_has_object(chr, object, label) \
	mkshort(0x005d), \
	chr, \
	object, \
	label,

#define if_weapon_thrown(weapon, label) \
	mkshort(0x005e), \
	weapon, \
	label,

#define if_weapon_thrown_on_object(weapon, object, label) \
	mkshort(0x005f), \
	weapon, \
	object, \
	label,

#define if_chr_weapon_equipped(chr, weapon, label) \
	mkshort(0x0060), \
	chr, \
	weapon, \
	label,

// If behavior is zero, go to label if object exists.
// If behavior is nonzero, set flag on unclaimed gun.
// In practice this is always called with object = -1 and behavior = 1.
#define if_gun_unclaimed(object, behavior, label) \
	mkshort(0x0061), \
	object, \
	behavior, \
	label,

#define if_object_in_good_condition(object, label) \
	mkshort(0x0062), \
	object, \
	label,

#define if_chr_activated_object(chr, object, label) \
	mkshort(0x0063), \
	chr, \
	object, \
	label,

// Unused, and no idea what it does.
#define cmd0065(object) \
	mkshort(0x0065), \
	object,

#define destroy_object(object) \
	mkshort(0x0066), \
	object,

#define drop_concealed_items(chr) \
	mkshort(0x0068), \
	chr,

#define chr_drop_weapon(chr) \
	mkshort(0x0069), \
	chr,

#define give_object_to_chr(object, chr) \
	mkshort(0x006a), \
	object, \
	chr,

#define move_object_to_pad(object, pad) \
	mkshort(0x006b), \
	object, \
	mkshort(pad),

#define open_door(door) \
	mkshort(0x006c), \
	door,

#define close_door(door) \
	mkshort(0x006d), \
	door,

#define if_door_state(door, doorstate, label) \
	mkshort(0x006e), \
	door, \
	doorstate, \
	label,

#define lock_door(door, bits) \
	mkshort(0x0070), \
	door, \
	bits,

#define unlock_door(door, bits) \
	mkshort(0x0071), \
	door, \
	bits,

#define if_door_locked(door, bits, label) \
	mkshort(0x0072), \
	door, \
	bits, \
	label,

#define if_objective_complete(objective, label) \
	mkshort(0x0073), \
	objective, \
	label,

#define if_objective_failed(objective, label) \
	mkshort(0x0074), \
	objective, \
	label,

// This is only ever called in a sequence of 4, with u1 values 8, 2, 4, 8 in
// that order. Believed to be a pad within specific distance of target chr,
// where the higher the number the further the distance.
// If u1 were 0x10 or 0x20, some other logic would be used.
#define try_set_target_pad_to_something(u1, label) \
	mkshort(0x0075), \
	u1, \
	label,

// Only ever called with values 1, 2, 4 and 8. The value is related to circles,
// perhaps specifying a certain side of the target chr.
// If u1 were 0x10 or 0x20, some other logic would be used (same as previous).
#define try_set_target_pad_to_something2(u1, label) \
	mkshort(0x0076), \
	u1, \
	label,

#define if_difficulty_lt(diff, label) \
	mkshort(0x0077), \
	diff, \
	label,

#define if_difficulty_gt(diff, label) \
	mkshort(0x0078), \
	diff, \
	label,

#define if_uptime_lt(value, label) \
	mkshort(0x0079), \
	mkshort(value), \
	label,

#define if_uptime_gt(value, label) \
	mkshort(0x007a), \
	mkshort(value), \
	label,

#define if_stage_lt(stage, label) \
	mkshort(0x007b), \
	stage, \
	label,

#define if_stage_gt(stage, label) \
	mkshort(0x007c), \
	stage, \
	label,

#define if_num_times_shot_lt(value, label) \
	mkshort(0x007d), \
	value, \
	label,

#define if_num_times_shot_gt(value, label) \
	mkshort(0x007e), \
	value, \
	label,

#define if_num_close_arghs_lt(value, label) \
	mkshort(0x007f), \
	value, \
	label,

#define if_num_close_arghs_gt(value, label) \
	mkshort(0x0080), \
	value, \
	label,

// Checks chr bank 3 0x00000100. If set, unsets it and follows label.
#define if_just_injured(chr, label) \
	mkshort(0x0083), \
	chr, \
	label,

#define set_morale(value) \
	mkshort(0x0084), \
	value,

#define add_morale(value) \
	mkshort(0x0085), \
	value,

#define chr_add_morale(chr, value) \
	mkshort(0x0085), \
	chr, \
	value,

#define subtract_morale(value) \
	mkshort(0x0087), \
	value,

#define if_morale_lt(value, label) \
	mkshort(0x0088), \
	value, \
	label,

#define if_morale_lt_random(label) \
	mkshort(0x0089), \
	label,

#define set_alertness(value) \
	mkshort(0x008a), \
	value,

#define increase_self_alertness(value) \
	mkshort(0x008b), \
	value,

#define increase_chr_alertness(value, chr) \
	mkshort(0x008c), \
	value, \
	chr,

#define subtract_alertness(value, chr) \
	mkshort(0x008d), \
	value, \
	chr,

#define if_alertness(value, operator, label) \
	mkshort(0x008e), \
	value, \
	operator, \
	label,

#define if_chr_alertness_lt(value, chr, label) \
	mkshort(0x008f), \
	value, \
	chr, \
	label,

#define if_alertness_lt_random(label) \
	mkshort(0x0090), \
	label,

#define cmd0091_noop \
	mkdir(0x0091),

// Set their hear distance to value divided by 1000.
// Only ever called with distance = 10,000, so it gets set to 10.
#define set_hear_distance(value) \
	mkshort(0x0092), \
	mkshort(value),

#define set_view_distance(value) \
	mkshort(0x0093), \
	value,

#define set_grenade_probability_out_of_255(value) \
	mkshort(0x0094), \
	value,

#define set_chr_id(newid) \
	mkshort(0x0095), \
	newid,

#define set_chr_health(chr, value) \
	mkshort(0x0096), \
	chr, \
	mkshort(value),

#define set_armor(value) \
	mkshort(0x0097), \
	mkshort(value),

#define set_reaction_speed(value) \
	mkshort(0x0098), \
	value,

#define set_recovery_speed(value) \
	mkshort(0x0099), \
	value,

#define set_accuracy(value) \
	mkshort(0x009a), \
	value,

#define set_self_flag_bankx(flag, bank) \
	mkshort(0x009b), \
	mkword(flag), \
	bank,

#define unset_self_flag_bankx(flag, bank) \
	mkshort(0x009c), \
	mkword(flag), \
	bank,

#define if_self_flag_bankx_eq(props, bool, bank, label) \
	mkshort(0x009d), \
	mkword(props), \
	bool, \
	bank, \
	label,

#define set_chr_flag_bankx(chr, props, bank) \
	mkshort(0x009e), \
	chr, \
	mkword(props), \
	bank,

#define unset_chr_flag_bankx(chr, flag, bank) \
	mkshort(0x009f), \
	chr, \
	mkword(flag), \
	bank,

#define if_chr_flag_bankx(chr, flag, bank, label) \
	mkshort(0x00a0), \
	chr, \
	mkword(flag), \
	bank, \
	label,

#define set_stage_flag(stageflag) \
	mkshort(0x00a1), \
	mkword(stageflag),

#define unset_stage_flag(stageflag) \
	mkshort(0x00a2), \
	mkword(stageflag),

#define if_stage_flag_eq(stageflag, bool, label) \
	mkshort(0x00a3), \
	mkword(stageflag), \
	bool, \
	label,

#define set_self_flag_bank3(chrflag3) \
	mkshort(0x00a4), \
	mkword(chrflag3),

#define unset_self_flag_bank3(chrflag3) \
	mkshort(0x00a5), \
	mkword(chrflag3),

#define if_self_flag_bank3(chrflag3, label) \
	mkshort(0x00a6), \
	mkword(chrflag3), \
	label,

#define set_chr_flag_bank3(chr, chrflag3) \
	mkshort(0x00a7), \
	chr, \
	mkword(chrflag3),

#define unset_chr_flag_bank3(chr, chrflag3) \
	mkshort(0x00a8), \
	chr, \
	mkword(chrflag3),

#define if_chr_flag_bank3(chr, chrflag3, label) \
	mkshort(0x00a9), \
	chr, \
	mkword(chrflag3), \
	label,

#define set_object_flag_bank0(object, objectflag0) \
	mkshort(0x00aa), \
	object, \
	mkword(objectflag0),

#define unset_object_flag_bank0(object, objectflag0) \
	mkshort(0x00ab), \
	object, \
	mkword(objectflag0),

#define set_object_flag_bank1(object, objectflag1) \
	mkshort(0x00ad), \
	object, \
	mkword(objectflag1),

#define unset_object_flag_bank1(object, objectflag1) \
	mkshort(0x00ae), \
	object, \
	mkword(objectflag1),

#define if_object_flag_bank1(object, objectflag1, label) \
	mkshort(0x00af), \
	object, \
	mkword(objectflag1), \
	label,

#define set_follow_chr(chr) \
	mkshort(0x00b0), \
	chr,

#define set_chr_target_chr(chr, target) \
	mkshort(0x00b1), \
	chr, \
	target,

#define set_target_pad(pad) \
	mkshort(0x00b2), \
	mkshort(pad),

#define chr_set_target_pad(pad) \
	mkshort(0x00b3), \
	chr, \
	mkshort(pad),

#define chr_copy_target_pad(srcchr, dstchr) \
	mkshort(0x00b4), \
	srcchr, \
	dstchr,

#define dprint \
	mkshort(0x00b5),

#define restart_timer \
	mkshort(0x00b6),

#define reset_timer \
	mkshort(0x00b7),

#define pause_timer \
	mkshort(0x00b8),

#define resume_timer \
	mkshort(0x00b9),

#define if_timer_stopped(label) \
	mkshort(0x00ba), \
	label,

/**
 * Compares the timer against the chr's random value.
 * (You need to use call_rng before using this)
 */
#define if_timer_gt_random(label) \
	mkshort(0x00bb), \
	label,

#define if_timer_gt(value, label) \
	mkshort(0x00bd), \
	0x00, \
	mkshort(value), \
	label,

#define if_timer_lt(value, label) \
	mkshort(0x00bc), \
	0x00, \
	mkshort(value), \
	label,

#define show_countdown_timer \
	mkshort(0x00be),

#define hide_countdown_timer \
	mkshort(0x00bf),

#define set_countdown_timer(seconds) \
	mkshort(0x00c0), \
	mkshort(seconds),

#define stop_countdown_timer \
	mkshort(0x00c1),

#define start_countdown_timer \
	mkshort(0x00c2),

#define if_countdown_timer_stopped(label) \
	mkshort(0x00c3), \
	label,

#define if_countdown_timer_lt(value, label) \
	mkshort(0x00c4), \
	mkshort(value), \
	label,

#define if_countdown_timer_gt(value, label) \
	mkshort(0x00c5), \
	mkshort(value), \
	label,

#define try_spawn_chr(body, head, pad, function, props, label) \
	mkshort(0x00c6), \
	body, \
	head, \
	mkshort(pad), \
	mkshort(function), \
	mkword(props), \
	label,

#define try_spawn_clone(body, head, u1, function, props, label) \
	mkshort(0x00c7), \
	body, \
	head, \
	u1, \
	mkshort(function), \
	mkword(props), \
	label,

#define try_draw_weapon(model, weapon, u1, label) \
	mkshort(0x00c8), \
	mkshort(model), \
	weapon, \
	mkword(u1), \
	label,

#define try_spawn_clone2(chr, function, u1, label) \
	mkshort(0x00ca), \
	chr, \
	mkshort(function), \
	mkword(u1), \
	label,

#define message(chr, text) \
	mkshort(0x00cb), \
	chr, \
	mkshort(text),

#define display_text_top_middle(chr, text, color) \
	mkshort(0x00cc), \
	chr, \
	mkshort(text), \
	color,

#define speak(chr, text, sound, channel, color) \
	mkshort(0x00cd), \
	chr, \
	mkshort(text), \
	mkshort(sound), \
	channel, \
	color,

#define play_sound(id, channel) \
	mkshort(0x00ce), \
	mkshort(id), \
	channel,

#define control_sound_from_object(channel, object, bool) \
	mkshort(0x00cf), \
	channel, \
	object, \
	0x00, \
	bool,

#define play_sound_from_pad(pad, sound) \
	mkshort(0x00d0), \
	0x00, \
	mkshort(pad), \
	mkshort(sound),

#define mute_channel(channel) \
	mkshort(0x00d3), \
	channel,

#define begin_hovercar_path(path) \
	mkshort(0x00d5), \
	path,

#define set_vehicle_speed(speed, num_accel_frames) \
	mkshort(0x00d6), \
	mkshort(speed), \
	mkshort(num_accel_frames),

#define set_rotor_speed(speed, u1, u2) \
	mkshort(0x00d7), \
	mkshort(speed), \
	u1, \
	u2,

#define set_object_image(object, slot, image) \
	mkshort(0x00da), \
	object, \
	slot, \
	image,

#define end_level \
	mkshort(0x00dc),

#define enter_firstperson \
	mkshort(0x00dd),

#define enter_camera_and_move_to_pad(pad) \
	mkshort(0x00de), \
	mkshort(pad),

#define revoke_control(chr, value) \
	mkshort(0x00e0), \
	chr, \
	value,

#define grant_control(chr) \
	mkshort(0x00e1), \
	chr,

#define chr_move_to_pad(chr, pad, unknown, label) \
	mkshort(0x00e2), \
	chr, \
	mkshort(pad), \
	unknown, \
	label,

#define open_door2(door) \
	mkshort(0x00e8), \
	door,

// Reads 4 global values and counts how many are nonzero.
// If number of nonzeroes is less than given value, goto label.
// Only ever called with value = 2
#define if_num_human_players_lt(value, label) \
	mkshort(0x00ea), \
	value, \
	label,

#define if_ammo_quantity_lt(chr, ammotype, value, label) \
	mkshort(0x00eb), \
	chr, \
	ammotype, \
	value, \
	label,

#define chr_draw_weapon(chr, weapon) \
	mkshort(0x00ec), \
	chr, \
	weapon,

#define chr_draw_weapon_in_cutscene(chr, weapon) \
	mkshort(0x00ed), \
	chr, \
	weapon,

#define if_object_in_room(object, room, label) \
	mkshort(0x00ef), \
	object, \
	mkshort(room), \
	label,

#define set_invincible(chr) \
	mkshort(0x00f3), \
	chr,

#define if_all_objectives_complete(label) \
	mkshort(0x00f7), \
	label,

#define if_player_is_invincible(chr, label) \
	mkshort(0x00f8), \
	chr, \
	label,

#define play_x_music(channel, seconds) \
	mkshort(0x00f9), \
	0x01, \
	channel, \
	seconds,

#define stop_music_channel(channel) \
	mkshort(0x00fa), \
	channel,

#define explosions_around_chr(chr) \
	mkshort(0x00fb), \
	chr,

#define if_kill_count_gt(value, label) \
	mkshort(0x00fc), \
	value, \
	label,

#define set_lights_state(room, u1, u2, u3, u4) \
	mkshort(0x0102), \
	mkshort(room), \
	u1, \
	u2, \
	u3, \
	u4, \
	0x00, \
	0x00, \
	0x00,

#define set_target_chr(chr) \
	mkshort(0x0106), \
	chr, \
	0x00, \
	0x00,

#define if_target_chrs_target_is_different(label) \
	mkshort(0x0107), \
	label,

// Used only in globals.s with CHR_SELF, CHR_P1P2, FALSE
#define cmd0108_if_something(chr1, chr2, bool, label) \
	mkshort(0x0108), \
	chr1, \
	chr2, \
	bool, \
	label,

#define set_chr_team(chr, team) \
	mkshort(0x010b), \
	chr, \
	team,

#define set_shield(value) \
	mkshort(0x010e), \
	mkshort(value),

#define if_chr_shield_lt(chr, value, label) \
	mkshort(0x010f), \
	chr, \
	mkshort(value), \
	label,

#define camera_movement(animation) \
	mkshort(0x0111), \
	mkshort(animation),

#define object_do_animation(u1, object, u2, u3) \
	mkshort(0x0112), \
	mkshort(u1), \
	object, \
	mkshort(u2), \
	u3,

#define if_camera_animating(label) \
	mkshort(0x0113), \
	label,

#define show_chr(chr) \
	mkshort(0x0114), \
	chr,

#define hide_chr(chr) \
	mkshort(0x0115), \
	chr,

#define show_object(object) \
	mkshort(0x0116), \
	object,

#define hide_object(object) \
	mkshort(0x0117), \
	object,

#define set_object_flag_bank2(object, objectflag2) \
	mkshort(0x0118), \
	object, \
	mkword(objectflag2),

#define unset_object_flag_bank2(object, objectflag2) \
	mkshort(0x0119), \
	object, \
	mkword(objectflag2),

#define if_object_flag_bank2(object, objectflag2, label) \
	mkshort(0x011a), \
	object, \
	mkword(objectflag2), \
	label,

#define set_chr_flag_bank2(chr, chrflag2) \
	mkshort(0x011b), \
	chr, \
	mkword(chrflag2),

#define unset_chr_flag_bank2(chr, chrflag2) \
	mkshort(0x011c), \
	chr, \
	mkword(chrflag2),

#define if_chr_flag_bank2(chr, chrflag2, label) \
	mkshort(0x011d), \
	chr, \
	mkword(chrflag2), \
	label,

#define if_chr_is_human(chr, label) \
	mkshort(0x011e), \
	chr, \
	label,

#define if_chr_is_skedar(chr, label) \
	mkshort(0x011f), \
	chr, \
	label,

// Tries to find an chr in the team who meets certain criteria. For each chr, a
// score is calculated based on several factors, such as whether they've been
// shot. If any chr in the team has a score lower than the given value, the
// condition passes.
#define if_retreat_risk_lt(value, label) \
	mkshort(0x0120), \
	value, \
	label,

// If cover exists nearby
#define cmd0121_if_something(u1, label) \
	mkshort(0x0121), \
	mkshort(u1), \
	label,

#define cmd0124_run_for_cover_maybe(action) \
	mkshort(0x0124), \
	action,

// Related to command 012f
// globals.s only
#define cmd0125_if_or_try_something(label) \
	mkshort(0x0125), \
	label,

#define if_player_using_cmp150_or_ar34(label) \
	mkshort(0x0126), \
	label,

// Tries to find a chr in the team who meets some criteria and sets them as the
// current chr's target. This is different to the target chr.
#define try_find_chr_in_team(label) \
	mkshort(0x0127), \
	label,

// Check if there's an enemy within the range and sight, then sets the
// target chr field to that enemy
#define if_enemy_distance_lt_and_los(distance, label) \
	mkshort(0x0128), \
	distance / 10, \
	label,

// If value is nonzero then it's an chr ID. If zero then use current chr.
// This means chr ID 0 cannot be used. In practice, this command is only
// called once and it has value 0.
#define if_something_hypotenuse(value, label) \
	mkshort(0x012a), \
	value, \
	label,

// Checks if the chr is within 50 units of something
#define if_something_chicago_robot(label) \
	mkshort(0x012b), \
	label,

// Does some math on chr's bdlist, possibly involving square roots.
// If result is > 50, goto label
#define if_distance_to_home_gt_50_maybe(label) \
	mkshort(0x012c), \
	label,

// If chr field 0x292 > 0, call some function.
// Involves some global array at 0x800a2360
// globals.s only
#define cmd012f \
	mkshort(0x012f),

/**
 * Make chr say something out of a random set of 3. Sets are defined in globals.
 * The bank argument applies to humans only. Skedar and maians have their own
 * hard coded banks.
 */
#define say_quip(chr, index, u1, u2, u3, bank, u4, channel) \
	mkshort(0x0130), \
	chr, \
	index, \
	u1, \
	u2, \
	u3, \
	bank, \
	u4, \
	channel,

#define set_squadron_alertness(value) \
	mkshort(0x0131), \
	value,

// Sets chr's action to value. If bool is false, also sets orders to zero.
#define set_action(value, bool) \
	mkshort(0x0132), \
	value, \
	bool,

#define set_orders(orders, label) \
	mkshort(0x0133), \
	orders, \
	label,

#define if_orders_eq(action, label) \
	mkshort(0x0134), \
	0xfd, \
	action, \
	label,

#define if_has_orders(label) \
	mkshort(0x0135), \
	label,

// u1 can theoretically be any value but in practice is only ever 2.
// u2 can be either 0, 1 or 2 and determines what the command does,
// but in practice is only ever 1 or 2.
#define retreat(u1, u2) \
	mkshort(0x0136), \
	u1, \
	u2,

#define if_any_chr_doing_action(action, label) \
	mkshort(0x0137), \
	action, \
	label,

#define if_sound_finished(channel, label) \
	mkshort(0x0138), \
	channel, \
	label,

// value is either 25, 70 or 335.
// u1 is either 1 or 2.
// It seems related to the chr's position properties
// Used by G5 cloaked guards, Deep Sea cloaked purple guards and globals.s
// I think this is related to flanking, where the value arg is the angle
// relative to the player's direction. 335 is the same as 25 degress to the
// right (360 - 25).
#define cmd0139(value, u1, bool) \
	mkshort(0x0139), \
	mkword(value), \
	u1, \
	bool,

#define try_set_target_chr_to_teammate(label) \
	mkshort(0x013a), \
	0x00, \
	0x00, \
	label,

#define set_squadron(id) \
	mkshort(0x013b), \
	id,

// Value is only ever 3. The function checks bits 0x01 and 0x02 to decide what
// to do, so in all cases it does both paths.
// globals.s only
#define cmd013d_if_grenade_thrown_nearby_maybe(value, label) \
	mkshort(0x013d), \
	value, \
	label,

#define run_from_grenade \
	mkshort(0x013e),

#define if_hoverbot_path_finished(u1, u2, label) \
	mkshort(0x0140), \
	u1, \
	u2, \
	label,

#define shuffle_investigation_terminals(dst1, dst2, src1, src2, src3, src4) \
	mkshort(0x0141), \
	dst1, \
	dst2, \
	src1, \
	src2, \
	src3, \
	src4, \
	0x00,

#define jog_to_object(object) \
	mkshort(0x0142), \
	object, \
	0x00,

// Related to hovercopter and Infiltration interceptors
// Sets player struct's field_0x2e to 1/true.
#define cmd0143 \
	mkshort(0x0143),

// Rebuild an array of teams containing chr IDs in that team
#define rebuild_teams \
	mkshort(0x0145),

// Rebuild an array of squadrons containing chr IDs in that squadron
#define rebuild_squadrons \
	mkshort(0x0146),

#define if_all_chrs_in_squadron_are_dead(squadron, label) \
	mkshort(0x0147), \
	squadron, \
	label,

#define if_num_chrs_in_squadron_gt(value, squadron, label) \
	mkshort(0x0152), \
	value, \
	squadron, \
	label,

#define set_tinted_glass_enabled(bool) \
	mkshort(0x0157), \
	bool,

#define play_music_track(id) \
	mkshort(0x015b), \
	id,

#define restart_music \
	mkshort(0x015c),

#define if_chr_injured_target(chr, label) \
	mkshort(0x0165), \
	chr, \
	label,

#define hovercopter_fire_rocket(side) \
	mkshort(0x0167), \
	side,

// If flag is set, unsets it and goes to label
#define try_unset_chr_flag_bank3_02000000(chr, label) \
	mkshort(0x0168), \
	chr, \
	label,

#define if_chr_idle_action_eq(action, label) \
	mkshort(0x0169), \
	action, \
	label,

#define if_chr_y(chr, value, operator, label) \
	mkshort(0x016a), \
	chr, \
	mkshort(value), \
	operator, \
	label,

#define play_sound_from_object(channel, object, sound, u1) \
	mkshort(0x016b), \
	channel, \
	object, \
	0x00, \
	0x01, \
	mkshort(sound), \
	mkshort(u1),

#define noop016c \
	mkshort(0x016c),

#define add_motion_blur(chr, value, bool) \
	mkshort(0x016d), \
	chr, \
	value, \
	bool,

#define damage_chr2(chr, value) \
	mkshort(0x016e), \
	chr, \
	mkshort(value),

// Likely related to being disarmed.
// Not sure what this does if the chr had no gun to begin with.
#define if_has_gun(chr, label) \
	mkshort(0x016f), \
	chr, \
	0x00, \
	label,

// If bool is false, run some function on the chr and their gun ground
// position, then follow the label.
// If bool is true, don't call the function, and only follow the label if field
// 0x4 in the gun ground position struct is less than 64.
#define if_gun_landed(bool, label) \
	mkshort(0x0170), \
	bool, \
	label,

#define if_distance_to_target_position_lt(distance, label) \
	mkshort(0x0171), \
	mkshort(distance / 10), \
	label,

// Makes gun disappear from the ground and gives it to the chr
// (when a guard drops their gun and picks it up)
#define chr_recover_gun(chr, label) \
	mkshort(0x0172), \
	chr, \
	label,

#define try_inherit_properties(chr_src, label) \
	mkshort(0x0173), \
	chr_src, \
	label,

#define if_controller_button_pressed(label) \
	mkshort(0x0174), \
	label,

// Used in cutscenes before giving control to Jo
// Value is always 60
// Without this command, or with a 0 value, Jo faces a different direction
#define cmd0175(u1) \
	mkshort(0x0175), \
	u1,

// Points to a non-command function...?
// globals.s only
#define cmd0176_if_something(label) \
	mkshort(0x0176), \
	label,

#define force_walk(chr, pad, unknown1, unknown2) \
	mkshort(0x0177), \
	chr, \
	mkshort(pad), \
	mkshort(unknown1), \
	mkshort(unknown2),

#define if_force_walk_finished(chr, label) \
	mkshort(0x0178), \
	chr, \
	label,

#define play_sound_from_entity(channel, entity_id, u1, u2, entity_type) \
	mkshort(0x0179), \
	channel, \
	entity_id, \
	0x00, \
	0x01, \
	mkshort(u1), \
	mkshort(u2), \
	entity_type,

// Suspected to be named incorrectly. Global functions suggests this checks if
// the chr can see the player.
#define if_in_disarm_range(label) \
	mkshort(0x017a), \
	label,

#define if_chr_unloaded(chr, label) \
	mkshort(0x017b), \
	chr, \
	label,

#define assign_sound(sound, channel) \
	mkshort(0x017c), \
	mkshort(sound), \
	channel,

#define set_music_track(id) \
	mkshort(0x017d), \
	id,

#define restart_default_music \
	mkshort(0x017e),

#define set_sfx_track(id) \
	mkshort(0x017f), \
	id,

#define reset_ambience \
	mkshort(0x0180),

#define if_chr_looking_at_object(chr, object, label) \
	mkshort(0x0181), \
	chr, \
	object, \
	label,

#define try_punch_or_kick(label) \
	mkshort(0x0182), \
	0x00, \
	label,

// In practice, scripts will assign function unalerted guard if this passes
#define if_chr_lost_track_of_target_maybe(label) \
	mkshort(0x0183), \
	label,

// Involves a call to the RNG, and zeroing chr fields aimendlshoulder,
// aimendrshoulder, aimendback and amendsideback.
//
// Called with values:
// 90, 100
// 40, 60
// 20, 30
//
// Used by:
// Attack Ship - Bridge skedar (with 40,60)
// Ruins - Reaper and Slayer skedar (with 40,60)
// globals.s - with values 90,100 and 20,30
//
// Sometimes accompanied with dprint "FIRE FULL"
#define cmd0184(u1, u2) \
	mkshort(0x0184), \
	u1, \
	u2,

// The rom address for this command is not a valid function entry...?
#define cmd0185_mponly \
	mkshort(0x0185),

#define if_chr_soundtimer(value, operator, label) \
	mkshort(0x0186), \
	mkshort(value), \
	operator, \
	label,

#define if_chr_sees_camspy_maybe(label) \
	mkshort(0x0187), \
	label,

#define if_lift_stationary(lift, label) \
	mkshort(0x0188), \
	lift, \
	label,

#define enable_rain(value) \
	mkshort(0x018b), \
	value,

#define remove_cass_necklace(chr) \
	mkshort(0x018c), \
	chr, \
	0x07,

#define activate_lift(liftid, object) \
	mkshort(0x018d), \
	liftid, \
	object,

#define miniskedar_try_pounce(u1, u2, label) \
	mkshort(0x018e), \
	u1, \
	mkshort(u2), \
	0x00, \
	label,

#define if_object_distance_to_pad_lt(object, distance, pad, label) \
	mkshort(0x018f), \
	object, \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

#define set_eeprom_flag(eeprom_flag) \
	mkshort(0x0190), \
	eeprom_flag,

#define unset_eeprom_flag(eeprom_flag) \
	mkshort(0x0191), \
	eeprom_flag,

#define if_eeprom_flag_is_set(eeprom_flag, label) \
	mkshort(0x0192), \
	eeprom_flag, \
	label,

#define if_eeprom_flag_is_unset(eeprom_flag, label) \
	mkshort(0x0193), \
	eeprom_flag, \
	label,

#define if_object_health_lt(object, value, label) \
	mkshort(0x019e), \
	object, \
	mkshort(value), \
	label,

#define set_object_health(object, value) \
	mkshort(0x019f), \
	object, \
	mkshort(value),

#define set_chr_special_death_animation(chr, anim) \
	mkshort(0x01a0), \
	chr, \
	anim,

// Sets the chr's roomtosearch field
// to the same room that the chr's target is in.
#define set_chr_roomtosearch \
	mkshort(0x01a1),

#define play_cistaff_quip(bank, channel) \
	mkshort(0x01a2), \
	bank, \
	channel,

/**
 * If value is -2, either do 0x299 or 0x29a based on something.
 * If value is -1, choose a random anim out of 8 from bank at 8006984c.
 * If value is 3, choose a random anim out of 2 from bank at 80069844.
 * Any other value is an index into bank at 80069840.
 */
#define do_special_animation(value) \
	mkshort(0x01a3), \
	value,

#define display_text(position, color, text) \
	mkshort(0x01a4), \
	position, \
	color, \
	mkshort(text),

#define if_target_y_difference_lt(distance, label) \
	mkshort(0x01a6), \
	distance / 10, \
	label

#define if_chr_propsoundcount_zero(chr, label) \
	mkshort(0x01a7), \
	chr, \
	label,

#define if_num_subdued(value, operator, label) \
	mkshort(0x01ab), \
	value, \
	1 - operator, \
	label,

#define release_grabbed_object(chr) \
	mkshort(0x01ad), \
	chr,

#define clear_inventory(chr) \
	mkshort(0x01ae), \
	chr,

#define grab_object(chr, object) \
	mkshort(0x01af), \
	chr, \
	object,

#define shuffle_ruins_pillars(pdst1, pdst2, pdst3, psrc1, psrc2, psrc3, psrc4, psrc5, mdst1, mdst2, mdst3, msrc1, msrc2, msrc3, msrc4, msrc5) \
	mkshort(0x01b1), \
	pdst1, \
	pdst2, \
	pdst3, \
	psrc1, \
	psrc2, \
	psrc3, \
	psrc4, \
	psrc5, \
	mdst1, \
	mdst2, \
	mdst3, \
	msrc1, \
	msrc2, \
	msrc3, \
	msrc4, \
	msrc5,

// This just does:
// addr8007db84 = addr7f1a9da4 * value
// In practice, value is 8, 11, 15, 20, 22 and 130,
// though some of these setup files are probably not used.
#define cmd01b2_mponly(value) \
	mkshort(0x01b2), \
	value,

#define consider_coop_for_p1p2_chr(chr) \
	mkshort(0x01b3), \
	chr,

#define cmd01b4_if_something(label) \
	mkshort(0x01b4), \
	label,

#define enable_snow(bool) \
	mkshort(0x01b6), \
	bool,

// bool_unknown determines whether to call some function on the chr afterwards
#define set_chr_cloaked(chr, bool_enable, bool_unknown) \
	mkshort(0x01b7), \
	chr, \
	bool_enable, \
	bool_unknown,

#define set_autoturret_type(object, type) \
	mkshort(0x01b8), \
	object, \
	type,

#define shuffle_pelagic_switches \
	mkshort(0x01b9),

// Likely some kind of shoot command, with u1 = entitytype and u2 = entityid
#define cmd01ba(u1, u2, label) \
	mkshort(0x01ba), \
	mkshort(u1), \
	mkshort(u2), \
	label,

#define if_training_pc_holographed(label) \
	mkshort(0x01bd), \
	label,

#define if_chr_has_weapon_equipped(chr, weapon, label) \
	mkshort(0x01be), \
	chr, \
	weapon, \
	label,

#define teleport_to_pad(pad, chr) \
	mkshort(0x01bf), \
	mkshort(pad), \
	chr,

#define if_teleport_full_white(label, chr) \
	mkshort(0x01c0), \
	label, \
	chr,

#define set_aipunchdodgelist(ailistid) \
	mkshort(0x01c1), \
	mkshort(ailistid),

#define set_aishootingatmelist(ailistid) \
	mkshort(0x01c2), \
	mkshort(ailistid),

#define set_darkroom_function(function) \
	mkshort(0x01c3), \
	mkshort(function),

#define set_aiplayerdeadlist(ailistid) \
	mkshort(0x01c4), \
	mkshort(ailistid),

// Calls some function on the chr. Possibly related to geometry, because it
// works with values such as 45 and 360.
#define cmd01c5 \
	mkshort(0x01c5),

// Sets a field in the chr struct
// If whichprop is 0, set dodgerating
// If whichprop is 1, set maxdodgerating
// If whichprop is 2, set both
#define set_chr_dodge_rating(value, whichprop) \
	mkshort(0x01c6), \
	value, \
	whichprop,

#define set_unarmeddodgerating(value) \
	mkshort(0x01c7), \
	value,

// Only used in test levels. Value can be 0-4.
// Looks up the index in a pointer array and calls the function at the pointer.
// If passed a value > 4, sets 800624b8 to -1.
// Related to cmd01c9
#define cmd01c8(value) \
	mkshort(0x01c8), \
	value,

// Test levels only. Checks if value at 800624b8 is >= 0.
// If so, runs some function and goes to label.
// Related to cmd01c8.
#define cmd01c9(label) \
	mkshort(0x01c9), \
	label,

#define set_cutscene_weapon(chr, weapon, weapon_fallback) \
	mkshort(0x01ca), \
	chr, \
	weapon, \
	weapon_fallback,

#define fade_to_color(rgba, num_frames) \
	mkshort(0x01cb), \
	mkword(rgba), \
	mkshort(num_frames),

#define set_chr_hud_visible(chr, bool) \
	mkshort(0x01cd), \
	chr, \
	bool,

// If enabled, Jo cannot use weapons or even the "unarmed" weapon
#define passive_mode(bool) \
	mkshort(0x01ce), \
	bool,

#define set_chr_shooting_in_cutscene(chr, bool) \
	mkshort(0x01cf), \
	chr, \
	bool,

#define set_portal_flag(portal, flag) \
	mkshort(0x01d0), \
	mkshort(portal), \
	flag,

#define set_object_part_visible(object, bool) \
	mkshort(0x01d1), \
	object, \
	0xb7, \
	bool,

#define emit_sparks(chr) \
	mkshort(0x01d2), \
	chr,

#define set_drcaroll_image(chr, left, right) \
	mkshort(0x01d3), \
	chr, \
	left, \
	right,

#define configure_room_portals(room) \
	mkshort(0x01d4), \
	mkshort(room), \
	0x08, \
	0x00,

#define show_nonessential_chrs(bool) \
	mkshort(0x01d5), \
	bool,

#define set_lighting(room, operation, unknown) \
	mkshort(0x01d6), \
	mkshort(room), \
	operation, \
	unknown,

#define play_sound_from_object2(channel, object, sound, u1, u2) \
	mkshort(0x01d9), \
	channel, \
	object, \
	mkshort(sound), \
	0xff, \
	0xff, \
	u1, \
	0x00, \
	u2,

// Only called in AF1 with param 0x35.
// Calls some functions and stores the value at 80840c8.
#define cmd01da(u1) \
	mkshort(0x01da), \
	u1,

#define kill(chr) \
	mkshort(0x01db), \
	chr,

#define remove_weapon_from_inventory(weapon) \
	mkshort(0x01dc), \
	weapon,

// Only used to trigger the Defection intro.
// Calls a bunch of functions outside of the main game binary object and then
// goes to label if 800840c4 is 0.
#define cmd01dd_if_something(u1, label) \
	mkshort(0x01dd), \
	u1, \
	label,

// Get distance from chr to pad, but only if they are on the same floor
// (ie. Y difference is less than 150).
#define if_chr_same_floor_distance_to_pad_lt(chr, pad, distance, label) \
	mkshort(0x01df), \
	chr, \
	mkshort(pad), \
	mkshort(distance / 10), \
	label,

#define if_coop_mode(label) \
	mkshort(0x01de), \
	label,

// Something to do with the chr's position struct
#define cmd01e0 \
	mkshort(0x01e0),

// Convenience macros for readability
#define beginloop(id) label(id) yield

#define endloop(id) goto_first(id)

#define reloop(id) goto_first(id)

#define remove_displayed_text display_text(0x02, 0, 0x0002)

#define if_stage_is_not(stage, label) if_stage_lt(stage, label) if_stage_gt(stage, label)

