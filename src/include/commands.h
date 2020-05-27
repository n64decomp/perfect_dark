#include "util.h"

/**
 * Makes the script jump to the next label with the given ID, relative to the
 * current command. Note that the beginloop macro expands to a label command, so
 * this will match beginloops too.
 */
#define goto_next(label) \
	mkshort(0x0000), \
	label,

/**
 * Makes the script jump to the first label with the given ID, relative to the
 * start of the current ailist.  Note that the beginloop macro expands to a
 * label command, so this will match beginloops too.
 */
#define goto_first(label) \
	mkshort(0x0001), \
	label,

/**
 * Defines a label. Does not actually do anything, but can be jumped to from
 * other commands.
 *
 * Labels that are used to define the start of a loop should be unique within
 * the current ailist, otherwise they may be unreachable by the goto_first
 * command.
 */
#define label(id) \
	mkshort(0x0002), \
	id,

/**
 * Pauses the current script and yields execution back to the engine. At least
 * one frame will pass before the script is continued.
 *
 * To prevent infinite loops this must be called at least once per loop. This is
 * already done for you if you use the beginloop macro.
 *
 * Yielding should also be done when doing expensive operations like spawning
 * chrs. If you don't then it may create a lag spike.
 *
 * Lastly, sometimes you need to yield and let the engine recalculate things
 * before your script continues. For example, when moving a mine to a pad you
 * may need to yield before detonating it.
 */
#define yield \
	mkshort(0x0003),

/**
 * Marks the end of the ailist.
 *
 * Every ailist should end in this, and it must not be reachable by your ailist
 * logic. Typically your ailist should loop back to an earlier point in the list
 * or assign a different ailist before the end is reached.
 */
#define endlist \
	mkshort(0x0004),

/**
 * Assigns a new ailist to the given chr. If the given chr is the current chr,
 * execution is immediately passed to the start of the new list (ie. there is no
 * yield).
 */
#define set_ailist(chr, function) \
	mkshort(0x0005), \
	chr, \
	mkshort(function),

/**
 * Sets the chr's return ailist. The return ailist can be jumped to using the
 * return command.
 *
 * A common pattern is to set the return ailist to the current ailist, then use
 * set_ailist to assign a new one. The new ailist should use return to jump back
 * to the original ailist.
 */
#define set_returnlist(chr, function) \
	mkshort(0x0006), \
	chr, \
	mkshort(function),

/**
 * Sets the list that should be assigned when the chr is shot.
 *
 * You would typically set this to the same list as the current one so the chr
 * continues doing what they were doing previously (eg. running to a target).
 * The list will be restarted from the beginning. You may want to use
 * if_just_injured near the top of the list so you detect the injury, make them
 * say something and wait for their injury animation to finish before they
 * continue their regular logic.
 */
#define set_shotlist(function) \
	mkshort(0x0007), \
	mkshort(function),

/**
 * Assigns the chr's return list to their current one. Execution of the new list
 * is started from the top.
 */
#define return \
	mkshort(0x0008),

/**
 * Makes the chr stop doing whatever they were doing (eg. running).
 */
#define stop_chr \
	mkshort(0x0009),

/**
 * Makes the chr begin kneeling.
 */
#define kneel \
	mkshort(0x000a),

/**
 * Make a chr do an animation. See the ANIM constants in constants.h for known
 * animation IDs.
 *
 * startframe may be 0 or higher for that frame number, -1 for the first frame
 * (ie. same as 0) or -2 for the last frame.
 *
 * endframe may be 0 or higher for that frame number, or -1 for the last frame.
 */
#define chr_do_animation(animation, startframe, endframe, flags, transition, chr, animspeed) \
	mkshort(0x000b), \
	mkshort(animation), \
	mkshort(startframe), \
	mkshort(endframe), \
	flags, \
	transition, \
	chr, \
	animspeed,

/**
 * Checks if the chr is considered to be idle. It is not known exactly what idle
 * means, but it could be any of:
 * - standing doing nothing
 * - patrolling
 * - sitting/operating equipment
 * - idle animations such as yawning
 */
#define if_chr_idle(label) \
	mkshort(0x000c), \
	label,

/**
 * Makes the chr raise one hand briefly.
 * This isn't used, but was copied from GoldenEye and still works.
 */
#define be_surprised_one_hand \
	mkshort(0x000d),

/**
 * Makes the chr look over their shoulder.
 *
 * This command isn't used. The "surprised" part of the name is there because
 * this is internally implemented using the ACT_SURPRISED action.
 */
#define be_surprised_look_around \
	mkshort(0x000e),

/**
 * Attempt to jump sideways. If it worked then go to the given label.
 * The command may fail if the chr is blocked.
 */
#define try_sidestep(label) \
	mkshort(0x000f), \
	label,

/**
 * Attempt to hop sideways. If it worked then go to the given label.
 * The command may fail if the chr is blocked.
 */
#define try_jumpout(label) \
	mkshort(0x0010), \
	label,

/**
 * Attempt to run sideways. If it worked then go to the given label.
 * The command may fail if the chr is blocked.
 */
#define try_run_sideways(label) \
	mkshort(0x0011), \
	label,

/**
 * Attempt to walk and shoot. If it worked then go to the given label.
 * The command may fail if the chr is blocked, or maybe if the chr can't see
 * their target.
 */
#define try_attack_walk(label) \
	mkshort(0x0012), \
	label,

/**
 * Attempt to run and shoot. If it worked then go to the given label.
 * The command may fail if the chr is blocked, or maybe if the chr can't see
 * their target.
 */
#define try_attack_run(label) \
	mkshort(0x0013), \
	label,

/**
 * Attempt to roll and shoot. If it worked then go to the given label.
 * The command may fail if the chr is blocked, or maybe if the chr can't see
 * their target.
 */
#define try_attack_roll(label) \
	mkshort(0x0014), \
	label,

/**
 * Makes the chr attempt to do a standing attack.
 *
 * entity_type is expected to be an ENTITYTYPE constant. It can be bitwise ORed
 * with ENTITYTYPE_AIMONLY to make the chr only aim at the entity.
 */
#define try_attack_stand(entity_type, entity_id, label) \
	mkshort(0x0015), \
	mkshort(entity_type), \
	mkshort(entity_id), \
	label,

/**
 * Makes the chr attempt to do a kneeling attack.
 *
 * entity_type is expected to be an ENTITYTYPE constant. It can be bitwise ORed
 * with ENTITYTYPE_AIMONLY to make the chr only aim at the entity.
 */
#define try_attack_kneel(entity_type, entity_id, label) \
	mkshort(0x0016), \
	mkshort(entity_type), \
	mkshort(entity_id), \
	label,

/**
 * Modifies the target entity and the aim-only/shoot flag.
 *
 * This command can only be used after try_attack_stand, try_attack_kneel,
 * try_attack_lie or try_face_entity. A common pattern is to use one of those
 * commands with the ENTITYTYPE_AIMONLY flag to point the gun at the entity, and
 * if the label was followed then call try_modify_attack to remove the
 * ENTITYTYPE_AIMONLY flag, causing the chr to shoot.
 */
#define try_modify_attack(entity_type, entity_id, label) \
	mkshort(0x0017), \
	mkshort(entity_type), \
	mkshort(entity_id), \
	label,

/**
 * Makes the chr begin facing the given entity. They will continue to face it
 * until stop_chr is used or a significantly different action is given to them.
 *
 * entity_type is expected to be an ENTITYTYPE constant.
 */
#define try_face_entity(entity_type, entity_id, label) \
	mkshort(0x0018), \
	mkshort(entity_type), \
	mkshort(entity_id), \
	label,

/**
 * Damages the chr by the given amount.
 */
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

/**
 * Makes the chr consider throwing a grenade, using their grenade probability
 * property.
 *
 * The values are not known. It's only called with values 512 and 0.
 */
#define consider_throwing_grenade(value_1, value_2, label) \
	mkshort(0x001b), \
	mkshort(value_1), \
	mkshort(value_2), \
	label,

/**
 * Makes the chr spawn the given item and drop it immediately.
 */
#define drop_item(modelnum, weaponnum, label) \
	mkshort(0x001c), \
	mkshort(modelnum), \
	weaponnum, \
	label,

/**
 * Makes the chr jog to the given pad. This may fail if pathfinding fails.
 */
#define jog_to_pad(pad) \
	mkshort(0x001d), \
	mkshort(pad),

/**
 * Makes the chr go to their pad preset. This may fail if pathfinding fails.
 *
 * Speed should be SPEED_WALK, SPEED_JOG or SPEED_RUN.
 */
#define go_to_target_pad(speed) \
	mkshort(0x001e), \
	speed,

/**
 * Makes the chr walk to the given pad. This may fail if pathfinding fails.
 */
#define walk_to_pad(pad) \
	mkshort(0x001f), \
	mkshort(pad),

/**
 * Makes the chr run to the given pad. This may fail if pathfinding fails.
 */
#define run_to_pad(pad) \
	mkshort(0x0020), \
	mkshort(pad),

/**
 * Assigns the given path ID to the chr for patrolling. The chr will not start
 * patrolling until start_path is used.
 */
#define assign_path(pathid) \
	mkshort(0x0021), \
	pathid,

/**
 * Makes the chr start patrolling.
 */
#define start_path \
	mkshort(0x0022),

/**
 * Checks if the chr is patrolling.
 */
#define if_path_started(label) \
	mkshort(0x0023), \
	label,

/**
 * Makes the chr surrender.
 */
#define surrender \
	mkshort(0x0024),

/**
 * Makes the chr drop their gun and fade out. For an immersive gameplay
 * experience, don't do this when the chr is on screen.
 */
#define drop_gun_and_fade_out \
	mkshort(0x0025),

/**
 * Remove the chr completely.
 */
#define remove_chr(chr) \
	mkshort(0x0026), \
	chr,

#define cmd0027(pad, label) \
	mkshort(0x0027), \
	mkshort(pad), \
	label,

/**
 * Activates the alarm. This alone does nothing except make the alarm sound
 * start. To make guards spawn when the alarm is sounded, an AI list must wait
 * for the alarm then spawn them.
 *
 * The alarm does not have a timer. You may want to use an AI list to wait for
 * them alarm, then wait a certain amount of time before deactivating it.
 */
#define activate_alarm \
	mkshort(0x0028),

/**
 * Deactivates the alarm.
 */
#define deactivate_alarm \
	mkshort(0x0029),

#define cmd002a(label) \
	mkshort(0x002a), \
	label,

/**
 * Makes the chr attempt to jog to their target. The target can be a chr, object
 * or the player.
 */
#define try_jog_to_target(label) \
	mkshort(0x002b), \
	label,

/**
 * Makes the chr attempt to jog to their target. The target can be a chr, object
 * or the player.
 */
#define try_walk_to_target(label) \
	mkshort(0x002c), \
	label,

/**
 * Makes the chr attempt to jog to their target. The target can be a chr, object
 * or the player.
 */
#define try_run_to_target(label) \
	mkshort(0x002d), \
	label,

#define cmd002e(label) \
	mkshort(0x002e), \
	label,

/**
 * Makes the chr attempt to jog to the given chr.
 */
#define try_jog_to_chr(chr, label) \
	mkshort(0x002f), \
	chr, \
	label,

/**
 * Makes the chr attempt to walk to the given chr.
 */
#define try_walk_to_chr(chr, label) \
	mkshort(0x0030), \
	chr, \
	label,

/**
 * Makes the chr attempt to run to the given chr.
 */
#define try_run_to_chr(chr, label) \
	mkshort(0x0031), \
	chr, \
	label,

/**
 * Checks if the chr is doing anything, such as running or animating.
 */
#define if_chr_stopped(label) \
	mkshort(0x0032), \
	label,

/**
 * Checks if the chr is doing their death animation, has finished their death
 * animation or is invalid.
 */
#define if_chr_dead(chr, label) \
	mkshort(0x0033), \
	chr, \
	label,

/**
 * Checks if the chr has finished dying.
 */
#define if_chr_death_animation_finished(chr, label) \
	mkshort(0x0034), \
	chr, \
	label,

/**
 * Checks if the chr has line of sight to their target. The target can be a chr,
 * object or the player.
 */
#define if_target_in_sight(label) \
	mkshort(0x0035), \
	label,

/**
 * Calls the random number generator. The chr's rand property will be assigned a
 * value between 0 and 255 (inclusive).
 */
#define call_rng \
	mkshort(0x0036),

/**
 * Checks if the chr's rand property is less than the given value.
 */
#define if_rand_lt(value, label) \
	mkshort(0x0037), \
	value, \
	label,

/**
 * Checks if the chr's rand property is greater than the given value.
 */
#define if_rand_gt(value, label) \
	mkshort(0x0038), \
	value, \
	label,

/**
 * Checks if the alarm is currently sounding. Not sure how this differs from
 * if_alarm_active.
 */
#define if_alarm_active2(label) \
	mkshort(0x0039), \
	label,

/**
 * Checks if the alarm is currently sounding.
 */
#define if_alarm_active(label) \
	mkshort(0x003a), \
	label,

/**
 * Checks if the alarm is currently quiet.
 */
#define if_alarm_inactive(label) \
	mkshort(0x003b), \
	label,

/**
 * Checks if the chr has heard gunfire.
 */
#define if_hears_gunfire(label) \
	mkshort(0x003c), \
	label,

/**
 * Go to label if the chr has witnessed another chr being injured.
 *
 * The behaviour of the checktype argument is:
 *
 * |-----------|-------|-------------------------|
 * | Checktype | Teams | Reset "Saw injury" flag |
 * |-----------|-------|-------------------------|
 * | 0         | Any   | Yes                     |
 * | 1         | Same  | No                      |
 * | 2+        | Any   | Yes                     |
 * |-----------|-------|-------------------------|
 */
#define if_saw_injury(checktype, label) \
	mkshort(0x003d), \
	checktype, \
	label,

/**
 * Go to label if the chr has witnessed another chr dying.
 *
 * The behaviour of the checktype argument is:
 *
 * |-----------|-------|------------------------|
 * | Checktype | Teams | Reset "Saw death" flag |
 * |-----------|-------|------------------------|
 * | 0         | Any   | No                     |
 * | 1         | Same  | Yes                    |
 * | 2+        | Any   | Yes                    |
 * |-----------|-------|------------------------|
 */
#define if_saw_death(checktype, label) \
	mkshort(0x003e), \
	checktype, \
	label,

/**
 * Checks if the chr can see the player.
 */
#define if_chr_sees_player(label) \
	mkshort(0x003f), \
	label,

#define cmd0040(flags, label) \
	mkshort(0x0040), \
	mkword(flags), \
	label,

// Not sure about this.
#define if_within_units_of_sight(value, label) \
	mkshort(0x0041), \
	mkword(value), \
	label,

/**
 * Checks if the chr is in a loaded room.
 */
#define if_in_loaded_room(label) \
	mkshort(0x0042), \
	label,

/**
 * Checks if the chr saw their target within the last 10 seconds.
 */
#define if_saw_target_recently(label) \
	mkshort(0x0043), \
	label,

/**
 * Checks if the chr heard their target within the last 10 seconds.
 */
#define if_heard_target_recently(label) \
	mkshort(0x0044), \
	label,

/**
 * Checks if the chr has detected the given chr. Detecting can happen by seeing
 * the chr or hearing gunfire.
 */
#define if_detected_chr(chr, label) \
	mkshort(0x0045), \
	chr, \
	label,

/**
 * Checks if the chr has never been rendered. This is typically used to spawn
 * clones until the source chr has appeared on screen.
 */
#define if_never_been_onscreen(label) \
	mkshort(0x0046), \
	label,

#define if_bitcheck_in_prop_struct(label) \
	mkshort(0x0047), \
	label,

/**
 * Checks if the chr's room is onscreen.
 */
#define if_chr_in_onscreen_room(chr, label) \
	mkshort(0x0048), \
	chr, \
	label,

/**
 * Checks if a room is visible.
 *
 * If the room argument is 10,000 or more than it will subtract 10,000, treat
 * it as a pad number, and use the room that the pad is in.
 */
#define if_room_onscreen(room, label) \
	mkshort(0x0049), \
	mkshort(room), \
	label,

#define if_chr_in_view(label) \
	mkshort(0x004a), \
	label,

/**
 * Checks if the chr had a shot nearly hit them.
 */
#define if_near_miss(label) \
	mkshort(0x004b), \
	label,

/**
 * Checks if the chr has detected evidence that the player has been there.
 *
 * It looks for props in the same room:
 * - Guns on the guard
 * - Explosion scorch marks
 * - And other unknown things
 */
#define if_sees_suspicious_item(label) \
	mkshort(0x004c), \
	label,

/**
 * Checks if Jo is within a certain angle of the chr's direction.
 * Value is a percentage of the circle, where 256 is a full circle.
 * Only ever called with value = decimal 10, which is about 14 degrees.
 * With value 10, returns true if Jo is roughly within 12-11 o'clock.
 */
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

/**
 * Checks if Jo is outside of a certain angle of the chr's direction.
 * Value is a percentage of the circle, where 256 is a full circle.
 * Called with values = -10 and -11, which is about -14 degrees.
 * With value -10, returns true if Jo is roughly within 12-1 o'clock.
 */
#define if_jo_ccw_direction_gt(value, label) \
	mkshort(0x004f), \
	value, \
	label,

/**
 * Similar to 004d and 004f, but checks if Jo is within the angle of player's
 * 12 o'clock (ie. either side).
 */
#define if_jo_front_direction_lt(value, label) \
	mkshort(0x0050), \
	value, \
	label,

/**
 * Similar to 004d and 004f, but checks if Jo is not in front of the current chr
 * by the given angle.
 */
#define if_jo_front_direction_gt(value, label) \
	mkshort(0x0051), \
	value, \
	label,

/**
 * Checks if the distance from the current chr to their target is less than the
 * given value.
 */
#define if_distance_to_target_lt(distance, label) \
	mkshort(0x0052), \
	mkshort(distance / 10), \
	label,

/**
 * Checks if the distance from the current chr to their target is greater than
 * the given value.
 */
#define if_distance_to_target_gt(distance, label) \
	mkshort(0x0053), \
	mkshort(distance / 10), \
	label,

/**
 * Checks if the distance from the given chr to the given pad is less than the
 * given value.
 */
#define if_chr_distance_to_pad_lt(chr, distance, pad, label) \
	mkshort(0x0054), \
	chr, \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

/**
 * Checks if the distance from the given chr to the given pad is greater than
 * the given value.
 */
#define if_chr_distance_to_pad_gt(chr, distance, pad, label) \
	mkshort(0x0055), \
	chr, \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

/**
 * Checks if the distance from the current chr to the given chr is less than the
 * given value.
 */
#define if_distance_to_chr_lt(distance, chr, label) \
	mkshort(0x0056), \
	mkshort(distance / 10), \
	chr, \
	label,

/**
 * Checks if the distance from the current chr to the given chr is greater than
 * the given value.
 */
#define if_distance_to_chr_gt(distance, chr, label) \
	mkshort(0x0057), \
	mkshort(distance / 10), \
	chr, \
	label,

#define cmd0058(distance, label) \
	mkshort(0x0058), \
	mkshort(distance / 10), \
	label,

/**
 * Checks if the distance from the current chr's target to the given pad is less
 * than the given value. The target can be another chr or an object.
 */
#define if_distance_from_target_to_pad_lt(distance, pad, label) \
	mkshort(0x0059), \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

/**
 * Checks if the distance from the current chr's target to the given pad is
 * greater than the given value. The target can be another chr or an object.
 */
#define if_distance_from_target_to_pad_gt(distance, pad, label) \
	mkshort(0x005a), \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

/**
 * Checks if the chr or their camspy is in the given room.
 *
 * Type 0 = if <chr> is in <room>
 * Type 1 = if <chr> is in same room that the current chr is searching
 * Type 2 = if <chr>'s camspy is within 150 units of <pad>
 *
 * Type 2 is hard coded to only work in G5 Building.
 */
#define if_chr_in_room(chr, type, room_or_pad, label) \
	mkshort(0x005b), \
	chr, \
	type, \
	mkshort(room_or_pad), \
	label,

/**
 * Checks if the chr's target is in the given room. The target can be another
 * chr or object.
 */
#define if_target_in_room(room, label) \
	mkshort(0x005c), \
	mkshort(room), \
	label

/**
 * Checks if the given chr has the given object in their inventory.
 */
#define if_chr_has_object(chr, object, label) \
	mkshort(0x005d), \
	chr, \
	object, \
	label,

/**
 * Checks if the given weapon has been thrown.
 */
#define if_weapon_thrown(weapon, label) \
	mkshort(0x005e), \
	weapon, \
	label,

/**
 * Checks if the given weapon has been thrown and has landed on the given
 * object.
 */
#define if_weapon_thrown_on_object(weapon, object, label) \
	mkshort(0x005f), \
	weapon, \
	object, \
	label,

/**
 * Checks if the chr has the given weapon equipped.
 */
#define if_chr_weapon_equipped(chr, weapon, label) \
	mkshort(0x0060), \
	chr, \
	weapon, \
	label,

/**
 * If behavior is zero, go to label if object exists.
 * If behavior is nonzero, set flag on unclaimed gun.
 *
 * In practice this is always called with object = -1 and behavior = 1.
 */
#define if_gun_unclaimed(object, behavior, label) \
	mkshort(0x0061), \
	object, \
	behavior, \
	label,

/**
 * Checks if the object is in good working order (ie. not destroyed).
 */
#define if_object_in_good_condition(object, label) \
	mkshort(0x0062), \
	object, \
	label,

/**
 * Checks if the object has been activated by the given chr.
 *
 * When this command is used the activated flag is cleared, so subsequent uses
 * of this command will not pass unless the chr activates it again.
 */
#define if_chr_activated_object(chr, object, label) \
	mkshort(0x0063), \
	chr, \
	object, \
	label,

// Unused, and no idea what it does.
#define cmd0065(object) \
	mkshort(0x0065), \
	object,

/**
 * Destroys the given object.
 *
 * In practice this is only used on mines. It might work on other objects.
 */
#define destroy_object(object) \
	mkshort(0x0066), \
	object,

#define cmd0067(object) \
	mkshort(0x0067), \
	object,

/**
 * Makes the given chr drop their concealed items.
 */
#define drop_concealed_items(chr) \
	mkshort(0x0068), \
	chr,

/**
 * Makes the given chr drop their weapon.
 */
#define chr_drop_weapon(chr) \
	mkshort(0x0069), \
	chr,

/**
 * Makes the current chr give their object to the given chr.
 */
#define give_object_to_chr(object, chr) \
	mkshort(0x006a), \
	object, \
	chr,

/**
 * Moves the object to the given pad. The move is instant.
 */
#define move_object_to_pad(object, pad) \
	mkshort(0x006b), \
	object, \
	mkshort(pad),

/**
 * Opens the door.
 */
#define open_door(door) \
	mkshort(0x006c), \
	door,

/**
 * Closes the door.
 */
#define close_door(door) \
	mkshort(0x006d), \
	door,

/**
 * Checks the state of the current door.
 *
 * Doorstate is expected to be one of DOORSTATE_OPEN, DOORSTATE_CLOSED,
 * DOORSTATE_OPENING or DOORSTATE_CLOSING. You can bitwise or them
 * together to check multiple states at the same time.
 */
#define if_door_state(door, doorstate, label) \
	mkshort(0x006e), \
	door, \
	doorstate, \
	label,

/**
 * Checks if the given object is a door.
 *
 * Most likely a debug command, as you'd know what IDs your doors use.
 */
#define if_object_is_door(object, label) \
	mkshort(0x006f), \
	object, \
	label,

/**
 * Locks the door by applying the given bitmask to it.
 *
 * In most cases you can just use bit 1.
 *
 * The engine allows doors to be locked for multiple reasons, in which case
 * you'd lock the door with multiple bits, then unlock individual bits as the
 * player completes each requirement.
 */
#define lock_door(door, bits) \
	mkshort(0x0070), \
	door, \
	bits,

/**
 * Unsets bits from the door's bitmask. If all bits are unset (eg. if it uses
 * the same bitmask that was used to lock the door) then the door is unlocked.
 */
#define unlock_door(door, bits) \
	mkshort(0x0071), \
	door, \
	bits,

/**
 * Checks if the door is locked with the given bitmask.
 */
#define if_door_locked(door, bits, label) \
	mkshort(0x0072), \
	door, \
	bits, \
	label,

/**
 * Checks if the given objective index is complete.
 *
 * This is not the same as the objective number. Objective indexes start from 0,
 * and some objective indexes do not apply to easier difficulties.
 */
#define if_objective_complete(objective, label) \
	mkshort(0x0073), \
	objective, \
	label,

/**
 * Checks if the given objective index is failed.
 *
 * This is not the same as the objective number. Objective indexes start from 0,
 * and some objective indexes do not apply to easier difficulties.
 */
#define if_objective_failed(objective, label) \
	mkshort(0x0074), \
	objective, \
	label,

/**
 * This is only ever called in a sequence of 4, with u1 values 8, 2, 4, 8 in
 * that order. Believed to be a pad within specific distance of target chr,
 * where the higher the number the further the distance.
 * If u1 were 0x10 or 0x20, some other logic would be used.
 */
#define try_set_target_pad_to_something(u1, label) \
	mkshort(0x0075), \
	u1, \
	label,

/**
 * Only ever called with values 1, 2, 4 and 8. The value is related to circles,
 * perhaps specifying a certain side of the target chr.
 * If u1 were 0x10 or 0x20, some other logic would be used (same as previous).
 */
#define try_set_target_pad_to_something2(u1, label) \
	mkshort(0x0076), \
	u1, \
	label,

/**
 * Checks if the difficulty is less than the given value.
 *
 * Diff is expected to be one of DIFF_A, DIFF_SA, DIFF_PA or DIFF_PD.
 */
#define if_difficulty_lt(diff, label) \
	mkshort(0x0077), \
	diff, \
	label,

/**
 * Checks if the difficulty is greater than the given value.
 *
 * Diff is expected to be one of DIFF_A, DIFF_SA, DIFF_PA or DIFF_PD.
 */
#define if_difficulty_gt(diff, label) \
	mkshort(0x0078), \
	diff, \
	label,

/**
 * Checks if the N64 uptime is less than the given value.
 *
 * The units used are not known.
 */
#define if_uptime_lt(value, label) \
	mkshort(0x0079), \
	mkshort(value), \
	label,

/**
 * Checks if the N64 uptime is greater than the given value.
 *
 * The units used are not known.
 */
#define if_uptime_gt(value, label) \
	mkshort(0x007a), \
	mkshort(value), \
	label,

/**
 * Checks if the stage ID is less than the given value.
 *
 * Consider using the helper macro if_stage_is_not instead.
 */
#define if_stage_lt(stage, label) \
	mkshort(0x007b), \
	stage, \
	label,

/**
 * Checks if the stage ID is greater than the given value.
 *
 * Consider using the helper macro if_stage_is_not instead.
 */
#define if_stage_gt(stage, label) \
	mkshort(0x007c), \
	stage, \
	label,

/**
 * Checks if the chr has been shot less than the given number of times.
 */
#define if_num_times_shot_lt(value, label) \
	mkshort(0x007d), \
	value, \
	label,

/**
 * Checks if the chr has been shot more than the given number of times.
 */
#define if_num_times_shot_gt(value, label) \
	mkshort(0x007e), \
	value, \
	label,

/**
 * Checks if the chr has had less than the given number of near misses.
 */
#define if_num_close_arghs_lt(value, label) \
	mkshort(0x007f), \
	value, \
	label,

/**
 * Checks if the chr has had more than the given number of near misses.
 */
#define if_num_close_arghs_gt(value, label) \
	mkshort(0x0080), \
	value, \
	label,

/**
 * Checks if the chr's health is greater than the given value.
 */
#define if_chr_health_gt(chr, health, label) \
	mkshort(0x0081), \
	chr, \
	health, \
	label,

/**
 * Checks if the chr's health is less than the given value.
 */
#define if_chr_health_lt(chr, health, label) \
	mkshort(0x0082), \
	chr, \
	health, \
	label,

/**
 * Checks if the chr was just injured.
 *
 * Typically you use set_shotlist to specify an AI list that the chr will assign
 * when they are shot, and you set that list to the same one as their main task
 * (such as running somewhere). When the chr is shot, the shot list is assigned
 * which causes the list to be restarted from the top. You can then use the
 * if_just_injured command near the top of the list, make them say something
 * and wait for their injury animation to finish before continuing with their
 * main logic.
 *
 * Using this command clears the injury state, so further calls will not pass
 * unless the chr is injured again.
 */
#define if_just_injured(chr, label) \
	mkshort(0x0083), \
	chr, \
	label,

/**
 * Sets the current chr's morale to the given value.
 *
 * Morale is a general purpose property. Its usage depends on the AI list.
 * The value range is 0-255.
 */
#define set_morale(value) \
	mkshort(0x0084), \
	value,

/**
 * Adds the given value to the current chr's morale property.
 */
#define add_morale(value) \
	mkshort(0x0085), \
	value,

/**
 * Adds the given value to the given chr's morale property.
 */
#define chr_add_morale(chr, value) \
	mkshort(0x0086), \
	chr, \
	value,

/**
 * Subtracts the given value from the current chr's morale property.
 */
#define subtract_morale(value) \
	mkshort(0x0087), \
	value,

/**
 * Checks if the chr's morale property is less than the given value.
 */
#define if_morale_lt(value, label) \
	mkshort(0x0088), \
	value, \
	label,

/**
 * Checks if the chr's morale property is less than the chr's rand property.
 */
#define if_morale_lt_random(label) \
	mkshort(0x0089), \
	label,

/**
 * Sets the chr's alertness value. Alertness of 100 or more causes them to
 * respond.
 */
#define set_alertness(value) \
	mkshort(0x008a), \
	value,

/**
 * Adds the given value to the current chr's alertness.
 */
#define increase_self_alertness(value) \
	mkshort(0x008b), \
	value,

/**
 * Adds the given value to the given chr's alertness.
 */
#define increase_chr_alertness(value, chr) \
	mkshort(0x008c), \
	value, \
	chr,

/**
 * Subtracts the given value from current chr's alertness.
 */
#define subtract_alertness(value, chr) \
	mkshort(0x008d), \
	value, \
	chr,

/**
 * Checks if the current chr's alertness is less or more than the given value.
 *
 * Operator is expected to be OPERATOR_LESS_THAN or OPERATOR_GREATER_THAN.
 */
#define if_alertness(value, operator, label) \
	mkshort(0x008e), \
	value, \
	operator, \
	label,

/**
 * Checks if the given chr's alertness is less than the given value.
 */
#define if_chr_alertness_lt(value, chr, label) \
	mkshort(0x008f), \
	value, \
	chr, \
	label,

/**
 * Checks if the current chr's alertness is less than their rand property.
 */
#define if_alertness_lt_random(label) \
	mkshort(0x0090), \
	label,

#define noop0091 \
	mkshort(0x0091),

/**
 * Set the current chr's hear distance.
 *
 * This value might be multiplied or divided by 1000.
 */
#define set_hear_distance(value) \
	mkshort(0x0092), \
	mkshort(value),

/**
 * Set the current chr's view distance.
 */
#define set_view_distance(value) \
	mkshort(0x0093), \
	value,

/**
 * Set the current chr's grenade probability. Used by the
 * consider_throwing_grenade command.
 */
#define set_grenade_probability_out_of_255(value) \
	mkshort(0x0094), \
	value,

/**
 * Assigns a new ID to the chr.
 */
#define set_chr_id(newid) \
	mkshort(0x0095), \
	newid,

/**
 * Sets the limit of how much health a chr or chopper can take before they die.
 *
 * In most cases the value is assigned to the chr given by the chr argument,
 * however if the command is run by an object (eg. hovercar or chopper) it will
 * be assigned to the object itself.
 */
#define set_chr_maxdamage(chr, value) \
	mkshort(0x0096), \
	chr, \
	mkshort(value),

/**
 * Easy to understand, but technically incorrect explanation:
 *
 *     Adds health to the chr. If this causes the chr to exceed full health
 *     (ie. maxdamage) then the remainder is applied as armor.
 *
 * Relatively difficult to understand, but technically correct explanation:
 *
 *     Reduces the damage that the chr has taken by the given value. This value
 *     may become negative, which has the effect of having body armor.
 */
#define add_health_or_armor(value) \
	mkshort(0x0097), \
	mkshort(value),

/**
 * Set the chr's reaction speed. Range is 0-100.
 */
#define set_reaction_speed(value) \
	mkshort(0x0098), \
	value,

/**
 * Set the chr's injury recovery speed. Range is 0-100.
 */
#define set_recovery_speed(value) \
	mkshort(0x0099), \
	value,

/**
 * Set the chr's accuracy. Range is 0-100.
 */
#define set_accuracy(value) \
	mkshort(0x009a), \
	value,

/**
 * Sets a flag on the current chr's flags or flags2 property.
 *
 * Use BANK_0 and a CHRFLAG0 constant for chr->flags (chr struct offset 0x114).
 * Use BANK_1 and a CHRFLAG1 constant for chr->flags2 (chr struct offset 0x118).
 */
#define set_self_flag_bankx(flag, bank) \
	mkshort(0x009b), \
	mkword(flag), \
	bank,

/**
 * Sets a flag on the current chr's flags or flags2 property.
 *
 * See set_self_flag_bankx for more info.
 */
#define unset_self_flag_bankx(flag, bank) \
	mkshort(0x009c), \
	mkword(flag), \
	bank,

/**
 * Checks if the given flag is set on the current chr's flags or flags2
 * property.
 *
 * Set bool to TRUE if checking if set, or FALSE if checking if unset.
 *
 * See set_self_flag_bankx for more info.
 */
#define if_self_flag_bankx_eq(flag, bool, bank, label) \
	mkshort(0x009d), \
	mkword(flag), \
	bool, \
	bank, \
	label,

/**
 * Sets a flag on the given chr's flags or flags2 property.
 *
 * See set_self_flag_bankx for more info.
 */
#define set_chr_flag_bankx(chr, props, bank) \
	mkshort(0x009e), \
	chr, \
	mkword(props), \
	bank,

/**
 * Unsets a flag on the given chr's flags or flags2 property.
 *
 * See set_self_flag_bankx for more info.
 */
#define unset_chr_flag_bankx(chr, flag, bank) \
	mkshort(0x009f), \
	chr, \
	mkword(flag), \
	bank,

/**
 * Checks if the given flag is set on the given chr's flags or flags2 property.
 *
 * See set_self_flag_bankx for more info.
 */
#define if_chr_has_flag_bankx(chr, flag, bank, label) \
	mkshort(0x00a0), \
	chr, \
	mkword(flag), \
	bank, \
	label,

/**
 * Sets the given stage flag.
 *
 * Stage flags are defined in each stage's setup file and are named with a
 * STAGEFLAG prefix. They are used to track events that have happened. Stage
 * flags can also be mapped to objectives to make them complete or fail when the
 * stage flag is set.
 */
#define set_stage_flag(stageflag) \
	mkshort(0x00a1), \
	mkword(stageflag),

/**
 * Unsets the given stage flag.
 *
 * If the stage flag is mapped to an objective, the objective may become
 * incomplete.
 */
#define unset_stage_flag(stageflag) \
	mkshort(0x00a2), \
	mkword(stageflag),

/**
 * Checks if the given stage flag is set or not set.
 *
 * Set bool to TRUE if checking if set, or FALSE if checking if unset.
 */
#define if_stage_flag_eq(stageflag, bool, label) \
	mkshort(0x00a3), \
	mkword(stageflag), \
	bool, \
	label,

/**
 * Sets a flag on the current chr's chrflags property (chr struct offset 0x18).
 *
 * Expects a CHRCFLAG constant.
 */
#define set_self_chrflag(chrflag3) \
	mkshort(0x00a4), \
	mkword(chrflag3),

/**
 * Unsets a flag on the current chr's chrflags property.
 *
 * See set_self_chrflag for more info.
 */
#define unset_self_chrflag(chrflag3) \
	mkshort(0x00a5), \
	mkword(chrflag3),

/**
 * Checks if the current chr has the given chrflag.
 *
 * See set_self_chrflag for more info.
 */
#define if_self_has_chrflag(chrflag3, label) \
	mkshort(0x00a6), \
	mkword(chrflag3), \
	label,

/**
 * Sets a flag on the given chr's chrflags property.
 *
 * See set_self_chrflag for more info.
 */
#define set_chr_chrflag(chr, chrflag3) \
	mkshort(0x00a7), \
	chr, \
	mkword(chrflag3),

/**
 * Unsets a flag on the given chr's chrflags property.
 *
 * See set_self_chrflag for more info.
 */
#define unset_chr_chrflag(chr, chrflag3) \
	mkshort(0x00a8), \
	chr, \
	mkword(chrflag3),

/**
 * Checks if the given chr has the given chrflag.
 *
 * See set_self_chrflag for more info.
 */
#define if_chr_has_chrflag(chr, chrflag3, label) \
	mkshort(0x00a9), \
	chr, \
	mkword(chrflag3), \
	label,

/**
 * Sets a flag on the object's flags property (object struct offset 0x08).
 *
 * Expects an OBJECTFLAG constant.
 */
#define set_object_flag(object, objectflag) \
	mkshort(0x00aa), \
	object, \
	mkword(objectflag),

/**
 * Unsets a flag on the object's flags property.
 *
 * See set_object_flag for more info.
 */
#define unset_object_flag(object, objectflag) \
	mkshort(0x00ab), \
	object, \
	mkword(objectflag),

/**
 * Checks if the given object has the given flags property.
 *
 * See set_object_flag for more info.
 */
#define if_object_has_flag(object, objectflag, label) \
	mkshort(0x00ac), \
	object, \
	mkword(objectflag), \
	label,

/**
 * Sets a flag on the object's flags2 property (object struct offset 0x0c).
 *
 * Expects an OBJECTFLAG2 constant.
 */
#define set_object_flag2(object, objectflag2) \
	mkshort(0x00ad), \
	object, \
	mkword(objectflag2),

/**
 * Unsets a flag on the object's flags2 property.
 *
 * See set_object_flag2 for more info.
 */
#define unset_object_flag2(object, objectflag2) \
	mkshort(0x00ae), \
	object, \
	mkword(objectflag2),

/**
 * Checks if the given object has the given flags2 property.
 *
 * See set_object_flag2 for more info.
 */
#define if_object_flag2(object, objectflag2, label) \
	mkshort(0x00af), \
	object, \
	mkword(objectflag2), \
	label,

/**
 * Sets the current chr's chrpreset property.
 *
 * chrpreset is a general purpose property. It can be referenced via CHR_PRESET.
 */
#define set_chrpreset(chr) \
	mkshort(0x00b0), \
	chr,

/**
 * Sets the current chr's target property to the given chr.
 *
 * The target is a general purpose property. It can be referenced via
 * CHR_TARGET.
 */
#define set_chr_target_chr(chr, target) \
	mkshort(0x00b1), \
	chr, \
	target,

/**
 * Sets the current chr's padpreset property.
 *
 * padpreset can be referenced via PAD_PRESET.
 */
#define set_padpreset(pad) \
	mkshort(0x00b2), \
	mkshort(pad),

/**
 * Sets the given chr's padpreset property.
 *
 * padpreset can be referenced via PAD_PRESET.
 */
#define chr_set_target_pad(chr, pad) \
	mkshort(0x00b3), \
	chr, \
	mkshort(pad),

/**
 * Copies the padpreset from the source chr to the destination chr.
 */
#define chr_copy_target_pad(srcchr, dstchr) \
	mkshort(0x00b4), \
	srcchr, \
	dstchr,

/**
 * This command would have printed a message to the developer's console.
 *
 * It has no purpose in the retail game.
 */
#define dprint \
	mkshort(0x00b5),

/**
 * Resets the current chr's timer to zero and starts it.
 */
#define restart_timer \
	mkshort(0x00b6),

/**
 * Resets the current chr's timer to zero. The running state is unchanged.
 */
#define reset_timer \
	mkshort(0x00b7),

/**
 * Pauses the current chr's timer. The timer value is unchanged.
 */
#define pause_timer \
	mkshort(0x00b8),

/**
 * Resumes the current chr's timer. The timer continues from where it left off
 * previously.
 */
#define resume_timer \
	mkshort(0x00b9),

/**
 * Checks if the current chr's timer is stopped.
 */
#define if_timer_stopped(label) \
	mkshort(0x00ba), \
	label,

/**
 * Checks if the current chr's timer value is greater than the chr's rand value.
 *
 * You need to use call_rng before using this.
 */
#define if_timer_gt_random(label) \
	mkshort(0x00bb), \
	label,

/**
 * Checks if the current chr's timer value is greater than the given value.
 */
#define if_timer_gt(value, label) \
	mkshort(0x00bd), \
	0x00, \
	mkshort(value), \
	label,

/**
 * Checks if the current chr's timer value is less than the given value.
 */
#define if_timer_lt(value, label) \
	mkshort(0x00bc), \
	0x00, \
	mkshort(value), \
	label,

/**
 * Shows the countdown timer.
 */
#define show_countdown_timer \
	mkshort(0x00be),

/**
 * Hides the countdown timer.
 */
#define hide_countdown_timer \
	mkshort(0x00bf),

/**
 * Sets the countdown timer value.
 */
#define set_countdown_timer(seconds) \
	mkshort(0x00c0), \
	mkshort(seconds),

/**
 * Stops the countdown timer.
 */
#define stop_countdown_timer \
	mkshort(0x00c1),

/**
 * Starts the countdown timer.
 */
#define start_countdown_timer \
	mkshort(0x00c2),

/**
 * Checks if the countdown timer is stopped.
 */
#define if_countdown_timer_stopped(label) \
	mkshort(0x00c3), \
	label,

/**
 * Checks if the countdown timer value is less than the given value.
 */
#define if_countdown_timer_lt(value, label) \
	mkshort(0x00c4), \
	mkshort(value), \
	label,

/**
 * Checks if the countdown timer value is greater than the given value.
 */
#define if_countdown_timer_gt(value, label) \
	mkshort(0x00c5), \
	mkshort(value), \
	label,

/**
 * Attempts to spawn a chr at the given pad.
 */
#define try_spawn_chr_at_pad(body, head, pad, function, props, label) \
	mkshort(0x00c6), \
	body, \
	head, \
	mkshort(pad), \
	mkshort(function), \
	mkword(props), \
	label,

/**
 * Attempts to spawn a chr at the given chr.
 */
#define try_spawn_chr_at_chr(body, head, u1, function, props, label) \
	mkshort(0x00c7), \
	body, \
	head, \
	u1, \
	mkshort(function), \
	mkword(props), \
	label,

/**
 * Makes the chr equip the given weapon.
 *
 * Will cause crashes if the weapon's model file lacks positional information.
 */
#define try_equip_weapon(model, weapon, flags, label) \
	mkshort(0x00c8), \
	mkshort(model), \
	weapon, \
	mkword(flags), \
	label,

/**
 * Makes the chr equip the given hat.
 *
 * Perfect Dark has no hats, but you can assign a weapon ID if you want the chr
 * to wear a weapon like a hat.
 *
 * Will cause crashes if the weapon's model file lacks positional information.
 */
#define try_equip_hat(u1, flags, label) \
	mkshort(0x00c9), \
	mkshort(u1), \
	mkword(flags), \
	label,

#define try_spawn_clone2(chr, function, u1, label) \
	mkshort(0x00ca), \
	chr, \
	mkshort(function), \
	mkword(u1), \
	label,

/**
 * Show a HUD message to the player.
 *
 * The chr argument should be a player.
 */
#define show_hudmsg(chr, text) \
	mkshort(0x00cb), \
	chr, \
	mkshort(text),

/**
 * Show a HUD message in the top middle of the screen.
 *
 * The chr argument should be a player.
 * The color argument should be a COLOR constant.
 */
#define show_hudmsg_top_middle(chr, text, color) \
	mkshort(0x00cc), \
	chr, \
	mkshort(text), \
	color,

/**
 * Makes the given speech play and text appear at the top of the screen.
 *
 * The chr argument should be a player.
 * The channel argument should be a CHANNEL constant.
 * The color argument should be a COLOR constant.
 */
#define speak(chr, text, sound, channel, color) \
	mkshort(0x00cd), \
	chr, \
	mkshort(text), \
	mkshort(sound), \
	channel, \
	color,

/**
 * Plays the given sound effect.
 *
 * The channel argument should be a CHANNEL constant.
 */
#define play_sound(id, channel) \
	mkshort(0x00ce), \
	mkshort(id), \
	channel,

/**
 * Plays or stops a sound coming from the given object.
 *
 * The channel argument should be a CHANNEL constant.
 * The bool argument should be TRUE to play or FALSE to stop.
 */
#define control_sound_from_object(channel, object, bool) \
	mkshort(0x00cf), \
	channel, \
	object, \
	0x00, \
	bool,

/**
 * Plays a sound coming from the given pad.
 */
#define play_sound_from_pad(pad, sound) \
	mkshort(0x00d0), \
	0x00, \
	mkshort(pad), \
	mkshort(sound),

#define cmd00d1(channel, audio_id, u1) \
	mkshort(0x00d1), \
	channel, \
	mkshort(audio_id), \
	mkshort(u1),

#define cmd00d2(channel, audio_id, u1) \
	mkshort(0x00d2), \
	channel, \
	mkshort(audio_id), \
	mkshort(u1),

/**
 * Stops the given audio channel.
 *
 * The channel argument should be a CHANNEL constant.
 */
#define mute_channel(channel) \
	mkshort(0x00d3), \
	channel,

#define cmd00d4(u1, u2, label) \
	mkshort(0x00d4), \
	u1, \
	mkshort(u2), \
	label,

/**
 * Assigns a path to a hovercar and makes it start it.
 */
#define begin_hovercar_path(path) \
	mkshort(0x00d5), \
	path,

/**
 * Sets the hoverbot's speed.
 *
 * Speed is the maximum speed. 512 is an appropriate speed.
 *
 * The num_accel_frames is how many frames the vehicle takes to adjust to the
 * new speed, assuming 60 frames per second.
 */
#define set_vehicle_speed(speed, num_accel_frames) \
	mkshort(0x00d6), \
	mkshort(speed), \
	mkshort(num_accel_frames),

/**
 * Sets the speed of a component of the given vehicle, such as a rotor or wheel.
 *
 * Speed is the target speed. Time is the amount of time to reach that speed.
 * The units for this aren't known.
 */
#define set_rotor_speed(speed, time) \
	mkshort(0x00d7), \
	mkshort(speed), \
	mkshort(time),

#define noop00d8(u1) \
	mkshort(0x00d8), \
	u1,

#define noop00d9(u1) \
	mkshort(0x00d9), \
	u1,

/**
 * Sets the image for a monitor object.
 *
 * For single screen objects, slot should be 0.
 * For multi screen objects, slot can be 0-3.
 */
#define set_object_image(object, slot, image) \
	mkshort(0x00da), \
	object, \
	slot, \
	image,

#define noop00db(u1) \
	mkshort(0x00db), \
	u1,

/**
 * End the current level immediately.
 *
 * If all objectives are complete then the endscreen will be completed.
 */
#define end_level \
	mkshort(0x00dc),

#define enter_firstperson \
	mkshort(0x00dd),

#define enter_camera_and_move_to_pad(pad) \
	mkshort(0x00de), \
	mkshort(pad),

#define cmd00df(object, u1, u2) \
	mkshort(0x00df), \
	object, \
	mkshort(u1), \
	mkshort(u2),

/**
 * Remove control from the given chr.
 *
 * Used for the auto walk sequences in Extraction and Duel.
 */
#define revoke_control(chr, value) \
	mkshort(0x00e0), \
	chr, \
	value,

/**
 * Grant control back to the given chr.
 */
#define grant_control(chr) \
	mkshort(0x00e1), \
	chr,

/**
 * Attempt to move the chr to the given pad. The chr is moved immediately.
 * If successful, the label will be followed.
 *
 * If the pad is occupied then a reasonable attempt will be made to place the
 * chr near it. This attempt may fail if the pad is occupied by several chrs.
 *
 * If allowonscreen is FALSE, the chr will not be moved if the pad is on screen.
 *
 * If allowonscreen is TRUE, the chr will be moved even if the pad is on screen.
 * This may cause them to appear out of nowhere.
 *
 * If allowonscreen is 88 then the pad number will be interpreted as a chr
 * number and the chr will be moved to the other chr instead. This is used to
 * warp a co-op AI buddy to the player when using the stealth command.
 */
#define chr_move_to_pad(chr, pad, allowonscreen, label) \
	mkshort(0x00e2), \
	chr, \
	mkshort(pad), \
	allowonscreen, \
	label,

#define cmd00e3(chr) \
	mkshort(0x00e3), \
	chr,

#define cmd00e4(u1) \
	mkshort(0x00e4), \
	u1,

#define if_colour_fade_complete(chr, label) \
	mkshort(0x00e5), \
	chr, \
	label,

/**
 * Set the door's state to be fully open. There is no transition; the state is
 * applied instantly.
 */
#define set_door_open(door) \
	mkshort(0x00e8), \
	door,

#define cmd00e9(chr, u1) \
	mkshort(0x00e9), \
	chr, \
	u1,

/**
 * Checks if the number of players is less than the given value.
 */
#define if_num_human_players_lt(value, label) \
	mkshort(0x00ea), \
	value, \
	label,

/**
 * Checks if the chr's quantity of ammotype is less than the given value.
 *
 * Ammotype is expected to be an AMMOTYPE constant.
 */
#define if_ammo_quantity_lt(chr, ammotype, value, label) \
	mkshort(0x00eb), \
	chr, \
	ammotype, \
	value, \
	label,

/**
 * Makes the player equip the given weapon.
 */
#define chr_draw_weapon(chr, weapon) \
	mkshort(0x00ec), \
	chr, \
	weapon,

/**
 * Makes the player equip the given weapon (for cutscene use).
 */
#define chr_draw_weapon_in_cutscene(chr, weapon) \
	mkshort(0x00ed), \
	chr, \
	weapon,

#define cmd00ee(chr, x, z) \
	mkshort(0x00ee), \
	x, \
	z,

/**
 * Checks if the given object is in the given room.
 */
#define if_object_in_room(object, room, label) \
	mkshort(0x00ef), \
	object, \
	mkshort(room), \
	label,

#define cmd00f0(label) \
	mkshort(0x00f0), \
	label,

/**
 * Checks if the current chr is attacking.
 */
#define if_attacking(label) \
	mkshort(0x00f1), \
	label,

#define cmd00f2 \
	mkshort(0x00f2),

/**
 * Makes the given player invincible.
 */
#define set_invincible(chr) \
	mkshort(0x00f3), \
	chr,

#define cmd00f4(u1, u2, u3, u4, u5, u6) \
	mkshort(0x00f4), \
	mkshort(u1), \
	mkshort(u2), \
	mkshort(u3), \
	mkshort(u4), \
	mkshort(u5), \
	mkshort(u6),

#define cmd00f5 \
	mkshort(0x00f5),

#define cmd00f6(label) \
	mkshort(0x00f6), \
	label,

/**
 * Checks if all objectives are complete.
 */
#define if_all_objectives_complete(label) \
	mkshort(0x00f7), \
	label,

/**
 * Checks if the player is invincible.
 *
 * See set_invincible.
 */
#define if_player_is_invincible(chr, label) \
	mkshort(0x00f8), \
	chr, \
	label,

/**
 * Starts the X music theme. The music will play for the given number of seconds
 * before reverting to the standard level theme.
 */
#define play_x_music(channel, seconds) \
	mkshort(0x00f9), \
	0x01, \
	channel, \
	seconds,

/**
 * Stops the music in the given channel.
 */
#define stop_music_channel(channel) \
	mkshort(0x00fa), \
	channel,

/**
 * Surround the given player in infinite explosions.
 */
#define explosions_around_chr(chr) \
	mkshort(0x00fb), \
	chr,

/**
 * Checks if the player's kill count is greater than the given value.
 *
 * Only chrs flagged with CHRCFLAG_KILLCOUNTABLE are counted. This is typically
 * used to flag civilians, however is also used on enemies such as the hanger
 * Skedar in Attack Ship.
 */
#define if_kill_count_gt(value, label) \
	mkshort(0x00fc), \
	value, \
	label,

#define cmd00fd(chr, label) \
	mkshort(0x00fd), \
	chr, \
	label,

/**
 * Kill Bond/Joanna immediately.
 */
#define kill_bond \
	mkshort(0x00fe),

/**
 * Makes the chr raise their hands in a surrendering pose.
 *
 * This should not be used to make a chr surrender. Use the `surrender` command
 * instead.
 *
 * This command isn't used. The "surprised" part of the name is there because
 * this is internally implemented using the ACT_SURPRISED action.
 */
#define be_surprised_surrender \
	mkshort(0x00ff),

#define cmd0100_noop(u1) \
	mkshort(0x0100), \
	u1,

#define cmd0101_noop(u1) \
	mkshort(0x0101), \
	u1,

#define set_lights_state(room, operation, u1, u2, u3) \
	mkshort(0x0102), \
	mkshort(room), \
	operation, \
	u1, \
	u2, \
	u3, \
	0x00, \
	0x00, \
	0x00,

#define cmd0103(label) \
	mkshort(0x0103), \
	label,

/**
 * Removes a prop (chr or object) from the stage. The prop is the one referenced
 * by the current chr's proppreset property.
 */
#define remove_object_at_proppreset \
	mkshort(0x0104),

/**
 * Checks if the height (bounding box height, not Y value) of the current chr's
 * proppreset is less than the given value.
 *
 * If the prop is invalid, the computed height will be zero which causes the
 * check to pass.
 */
#define if_proppreset_height_lt(height, label) \
	mkshort(0x0105), \
	mkshort(height), \
	label,

/**
 * Set the current chr's target to the given chr.
 *
 * This command supports copying the target from another chr too, but this is
 * not currently supported by the decomp project.
 */
#define set_target_chr(chr) \
	mkshort(0x0106), \
	chr, \
	0x00, \
	0x00,

/**
 * Checks if the current chr's chrpreset's target is different to the current
 * chr's target.
 *
 * Could be used to set an ally as your chrpreset, then use this command to
 * prevent both chrs from attacking the same enemy.
 */
#define if_chrpresets_target_is_different(label) \
	mkshort(0x0107), \
	label,

/**
 * If anytarget is false, check if chr1's target is chr2.
 * If anytarget is true, check if chr1 has any target at all.
 */
#define if_chr_target_eq(chr1, chr2, anytarget, label) \
	mkshort(0x0108), \
	chr1, \
	chr2, \
	anytarget, \
	label,

#define cmd0109(u1, distance, label) \
	mkshort(0x0109), \
	u1, \
	mkshort(distance), \
	label, \

#define cmd010a(u1, distance, u2, label) \
	mkshort(0x010a), \
	u1, \
	mkshort(distance / 10), \
	mkshort(u2), \
	label,

/**
 * Set the team that the chr is on.
 *
 * The values are not well understood yet. Enemies are typically assigned to
 * team 0x02 and allies to team 0x10, but this varies.
 */
#define set_chr_team(chr, team) \
	mkshort(0x010b), \
	chr, \
	team,

/**
 * Compares the current chr's chrpreset's team with our own.
 *
 * checktype 1 = if friendly
 * checktype 2 = if enemies
 */
#define if_compare_chrpresets_team(checktype, label) \
	mkshort(0x010c), \
	checktype, \
	label,

#define noop010d \
	mkshort(0x010d),

/**
 * Set the shield amount for the current chr.
 */
#define set_shield(amount) \
	mkshort(0x010e), \
	mkshort(amount),

/**
 * Checks if the chr's shield amount is less than the given value.
 */
#define if_chr_shield_lt(chr, value, label) \
	mkshort(0x010f), \
	chr, \
	mkshort(value), \
	label,

/**
 * Checks if the chr's shield amount is greater than the given value.
 */
#define if_chr_shield_gt(chr, u1, label) \
	mkshort(0x0110), \
	chr, \
	mkshort(u1), \
	label,

/**
 * Begins a camera animation (ie. for cutscenes).
 */
#define camera_movement(animation) \
	mkshort(0x0111), \
	mkshort(animation),

/**
 * Makes the given object do the given animation. See the ANIM constants in
 * constants.h for known animation IDs.
 *
 * object may be the tag ID of an object, or 0xff to use the current chr's
 * myspecial object. The myspecial object is assigned during chr setup and is
 * commonly the chair that they're sitting in.
 *
 * startframe may be 0 or higher for that frame number, -1 for the first frame
 * (ie. same as 0), or -2 for the last frame.
 */
#define object_do_animation(animation, object, u2, startframe) \
	mkshort(0x0112), \
	mkshort(animation), \
	object, \
	u2, \
	mkshort(startframe),

/**
 * Checks if a cutscene is still running.
 */
#define if_camera_animating(label) \
	mkshort(0x0113), \
	label,

/**
 * Shows the given chr.
 */
#define show_chr(chr) \
	mkshort(0x0114), \
	chr,

/**
 * Hides the given chr.
 */
#define hide_chr(chr) \
	mkshort(0x0115), \
	chr,

/**
 * Shows the given object.
 */
#define show_object(object) \
	mkshort(0x0116), \
	object,

/**
 * Hides the given object.
 */
#define hide_object(object) \
	mkshort(0x0117), \
	object,

/**
 * Sets a flag on the object's flags3 property (object struct offset 0x10).
 *
 * Expects an OBJECTFLAG3 constant.
 */
#define set_object_flag3(object, objectflag3) \
	mkshort(0x0118), \
	object, \
	mkword(objectflag3),

/**
 * Unsets a flag on the object's flags3 property.
 *
 * See set_object_flag3 for more info.
 */
#define unset_object_flag3(object, objectflag3) \
	mkshort(0x0119), \
	object, \
	mkword(objectflag3),

/**
 * Checks if the given object has the given flags3 property.
 *
 * See set_object_flag3 for more info.
 */
#define if_object_flag3(object, objectflag3, label) \
	mkshort(0x011a), \
	object, \
	mkword(objectflag3), \
	label,

/**
 * Sets a flag on the given chr's hidden property (chr struct offset 0x14).
 *
 * Expects a CHRHFLAG constant.
 */
#define set_chr_hiddenflag(chr, chrflag2) \
	mkshort(0x011b), \
	chr, \
	mkword(chrflag2),

/**
 * Unsets a flag on the given chr's hidden property.
 *
 * See set_chr_hiddenflag for more info.
 */
#define unset_chr_hiddenflag(chr, chrflag2) \
	mkshort(0x011c), \
	chr, \
	mkword(chrflag2),

/**
 * Checks if the given chr has the given hidden flag.
 *
 * See set_chr_hiddenflag for more info.
 */
#define if_chr_has_hiddenflag(chr, chrflag2, label) \
	mkshort(0x011d), \
	chr, \
	mkword(chrflag2), \
	label,

/**
 * Checks if the given chr is human.
 *
 * Not sure how this handles Maians, or the female Extraction guards.
 */
#define if_chr_is_human(chr, label) \
	mkshort(0x011e), \
	chr, \
	label,

/**
 * Checks if the given chr is Skedar.
 */
#define if_chr_is_skedar(chr, label) \
	mkshort(0x011f), \
	chr, \
	label,

/**
 * Tries to find a chr in the smae team who meets certain criteria.
 *
 * For each chr, a risk is calculated based on several factors, such as whether
 * they've been shot. If any chr in the team has a risk lower than the given
 * value then the condition passes.
 */
#define if_retreat_risk_lt(value, label) \
	mkshort(0x0120), \
	value, \
	label,

// If cover exists nearby
#define cmd0121_if_something(u1, label) \
	mkshort(0x0121), \
	mkshort(u1), \
	label,

#define cmd0122(u1, flags, label) \
	mkshort(0x0122), \
	mkshort(u1), \
	mkword(flags), \
	label,

#define cmd0123(u1, flags, label) \
	mkshort(0x0123), \
	mkshort(u1), \
	mkword(flags), \
	label,

#define go_to_cover(speed) \
	mkshort(0x0124), \
	speed,

// Related to command 012f
// globals.c only
#define cmd0125_if_or_try_something(label) \
	mkshort(0x0125), \
	label,

/**
 * Checks if the player is using the CMP150 or AR34.
 */
#define if_player_using_cmp150_or_ar34(label) \
	mkshort(0x0126), \
	label,

/**
 * Tries to find a chr who meets some criteria and sets them as the current
 * chr's target. Only enemeies who are on the same floor will be considered.
 * A line of sight check is not used.
 */
#define set_target_to_enemy_on_same_floor(label) \
	mkshort(0x0127), \
	label,

/**
 * Checks if there's an enemy within the range and sight, then sets the
 * chr's target chr field to that enemy.
 */
#define if_enemy_distance_lt_and_los(distance, label) \
	mkshort(0x0128), \
	distance / 10, \
	label,

/**
 * Calculates a safety score based on several factors and compares it to the
 * given value.
 *
 * The safety score starts at 6.
 * Subtract 1 point if current chr has been shot.
 * Subtract 2 points if there are no other chrs nearby.
 * Subtract 1 point if there are 1 or 2 chrs nearby.
 *
 * So maximum safety is 6 and minimum safety is 3.
 */
#define if_calculated_safety_lt(score, label) \
	mkshort(0x0129), \
	score, \
	label,

/**
 * Checks if the distance change from the current chr to the chr's target has
 * not changed by more than 50 units since 1 second ago. In other words, if the
 * distance between the two is somewhat constant (eg. they are both not moving
 * much).
 *
 * It's used to decide whether to throw grenades or not.
 *
 * If chr is zero, compare the current chr and their target.
 * If chr is non-zero, compare the given chr and their target.
 */
#define if_target_moving_slowly(chr, label) \
	mkshort(0x012a), \
	chr, \
	label,

/**
 * Checks if the distance between the chr and their target has decreased by at
 * least 50 units in the last second.
 */
#define if_target_moving_closer(label) \
	mkshort(0x012b), \
	label,

/**
 * Checks if the distance between the chr and their target has increased by at
 * least 50 units in the last second.
 */
#define if_target_moving_away(label) \
	mkshort(0x012c), \
	label,

// If chr->cover > 0, call some function.
// Involves some global array at 0x800a2360
// globals.c only
#define cmd012f \
	mkshort(0x012f),

/**
 * Allows the current chr to say a semi-random statement from some predefined
 * lists.
 *
 * There are several banks (tables) of sound IDs. One for Skedar, one for
 * Maians, one for general guard speech and one for special character speech.
 * The guard speech bank is divided into four subbanks. Each subbank has similar
 * phrases to the other subbanks but each subbank uses a different style of
 * voice. The subbank used is determined by the chr's voicebox property. This
 * allows them to have the same sounding voice among all their phrases.
 *
 * Each bank (table) contains rows and columns. The row can be selected via an
 * argument to this command, but the column is determined randomly. All tables
 * have 3 columns.
 *
 * -----------------------------------------------------------------------------
 *
 * Arguments:
 *
 * The player argument is the player who the current chr is talking to. If the
 * player has died then it'll attempt to use the coop player. If all players
 * have died then it's likely their line will not be said.
 *
 * The quip argument determines which row in the bank is used. For guard speech
 * you should use a QUIP constant, otherwise use the row number.
 *
 * The probability argument determines the likelihood that the chr will say
 * the line. The higher the number (up to 255), the more likely they are to
 * talk. Note that under no conditions will the chr interrupt their existing
 * talk to start a new one.
 *
 * The soundgap argument is the amount of time in seconds it takes for the chr
 * to say their line, plus a suitable pause period at the end. The chr will not
 * start a new phrase if they are in the soundgap of a previous phrase.
 *
 * The conditions argument determines under what conditions the chr will talk:
 * 0   = only talk if no other chrs are nearby
 * 1   = only talk if there are other chrs nearby and none of them are talking
 * 255 = always talk, even if other chrs are nearby and talking
 *       (this applies after the probability check has passed)
 *
 * If special is true, the special bank will be used. For Skedar and Maians,
 * this argument is ignored and they use their own banks.
 *
 * The textrow argument determines whether text will be shown on the screen as
 * well as which row in the text bank will be used. Set to 0 to have no text.
 * The column that is used is determined by the chr's tude property, however you
 * can make it use the same column as the audio by bitwise ORing the bank
 * argument with 0x80.
 *
 * The colour argument determines the colour of the text on the screen. This is
 * expected to be a COLOUR constant.
 *
 * -----------------------------------------------------------------------------
 *
 * If called with zero values for all of quip, probability and onlyifothers,
 * the chr's current speech (if any) will be stopped.
 */
#define say_quip(player, quip, probability, soundgap, onlyifothers, special, textrow, colour) \
	mkshort(0x0130), \
	player, \
	quip, \
	probability, \
	soundgap, \
	onlyifothers, \
	special, \
	textrow, \
	colour,

/**
 * Increases the alertness value for other chrs in the current chr's squadron.
 *
 * By default, chrs will only be matched if they are within 1000 units of the
 * current chr. This limitation is bypassed if the current chr has
 * CHRFLAG0_SQUADALERTANYDIST.
 *
 * Chrs in squadron 255 will also be matched.
 *
 * The current chr's alertness will not be adjusted by this command.
 */
#define increase_squadron_alertness(value) \
	mkshort(0x0131), \
	value,

/**
 * Set the current chr's action. If bool is false, also sets orders to zero.
 *
 * Action is expected to be an ACT constant.
 */
#define set_action(action, bool) \
	mkshort(0x0132), \
	action, \
	bool,

/**
 * This command looks for other nearby and eligible chrs and assigns them orders
 * in order to assist the current chr in doing their action.
 *
 * For example, if the current chr is running for cover or is breaking cover,
 * this command will instruct the nearby chrs to shoot at the player to provide
 * them some cover. In another example, if the current chr is attempting to
 * flank the player on the left side then this command will instruct nearby chrs
 * to flank you on the right side. The command is also used to instruct other
 * chrs to withdraw if the current chr is throwing a grenade.
 *
 * The orders argument is completely ignored. The command acts based on the
 * current chr's myaction value. The chr's myaction value must be one of the
 * following, otherwise the command will have no effect:
 *
 * MA_COVERGOTO
 * MA_COVERBREAK
 * MA_COVERSEEN
 * MA_FLANKLEFT
 * MA_FLANKRIGHT
 * MA_DODGE
 * MA_GRENADE
 * MA_WAITSEEN
 * MA_WITHDRAW
 *
 * The command will never follow the label for MA_COVERGOTO or MA_WITHDRAW.
 * For all other actions it will follow if there is any eligible chr nearby.
 */
#define set_team_orders(orders, label) \
	mkshort(0x0133), \
	orders, \
	label,

/**
 * Checks if the current chr's orders equal the given value.
 */
#define if_orders_eq(action, label) \
	mkshort(0x0134), \
	0xfd, \
	action, \
	label,

/**
 * Checks if the current chr has orders at all.
 */
#define if_has_orders(label) \
	mkshort(0x0135), \
	label,

/**
 * If operation is 0, looks like the chr runs from their runfrompos property.
 * The distance they run is controlled by bit 0x10 in speed. If set then the run
 * distance will be 400 units. If unset it will be 10,000.
 *
 * If operation is 1, the chr tries to run 10,000 units away from their target.
 *
 * If operation is anything else, looks like it tries to find a cover point
 * within 2314 units then runs to it.
 */
#define retreat(speed, operation) \
	mkshort(0x0136), \
	speed, \
	operation,

#define if_chr_in_squadron_doing_action(action, label) \
	mkshort(0x0137), \
	action, \
	label,

/**
 * Checks if the sound if finished in the given channel.
 *
 * For chr speeches this should be accompanied by a timer check as well,
 * otherwise the speech can be skipped by pausing as it starts.
 */
#define if_sound_finished(channel, label) \
	mkshort(0x0138), \
	channel, \
	label,

// value is either 25, 70 or 335.
// u1 is either 1 or 2.
// It seems related to the chr's prop properties
// Used by G5 cloaked guards, Deep Sea cloaked purple guards and globals.c
// I think this is related to flanking, where the value arg is the angle
// relative to the player's direction. 335 is the same as 25 degress to the
// right (360 - 25).
#define cmd0139(value, u1, bool) \
	mkshort(0x0139), \
	mkword(value), \
	u1, \
	bool,

/**
 * Set the current chr's chrpreset to an unalerted teammate. The teammate must
 * be in the same squadron or have no squadron assigned.
 *
 * If distance is specified, limit search to chrs within that distance.
 */
#define try_set_chrpreset_to_unalerted_teammate(distance, label) \
	mkshort(0x013a), \
	distance, \
	0x00, \
	label,

/**
 * Set the current chr's squadron.
 */
#define set_squadron(id) \
	mkshort(0x013b), \
	id,

#define cmd013c(label) \
	mkshort(0x013c), \
	label,

/**
 * Checks if there is a live grenade or explosion nearby. If so, the position of
 * the object is stored in the chr's runfrompos property and the command passes.
 *
 * The flags argument is a bitfield which specifies what types of objects to
 * look for.
 *
 * Flag 0x1 = check for grenades
 * Flag 0x2 = check for explosions
 *
 * Set to 0x3 to check for both.
 *
 * Those are the only supported flags.
 */
#define if_dangerous_object_nearby(flags, label) \
	mkshort(0x013d), \
	flags, \
	label,

/**
 * Makes the chr run away from a live grenade.
 */
#define run_from_grenade \
	mkshort(0x013e),

/**
 * Checks if the current chopper's weapons are armed.
 */
#define if_chopper_weapons_armed(label) \
	mkshort(0x013f), \
	label,

/**
 * Checks if a hoverbot's next step is less than or greater than the given
 * value.
 *
 * Operator is expected to be OPERATOR_LESS_THAN or OPERATOR_GREATER_THAN.
 */
#define if_hoverbot_next_step(operator, step, label) \
	mkshort(0x0140), \
	operator, \
	step, \
	label,

/**
 * Shuffle a set of Investigation terminals.
 *
 * It works by editing the dst object tags to repoint them to the good and alarm
 * terminals.
 */
#define shuffle_investigation_terminals(goodtag, badtag, pc1, pc2, pc3, pc4) \
	mkshort(0x0141), \
	goodtag, \
	badtag, \
	pc1, \
	pc2, \
	pc3, \
	pc4, \
	0x00,

/**
 * Takes the given object, looks at the pad ID that the object is sitting on,
 * then uses a lookup table at g_InvestigationPadMap to decide which pad to set
 * as the current chr's pad preset.
 *
 * It's only used for Investigation scientists to run to a spot in front of the
 * terminal. Due to the fact that this lookup table is hard coded in a global
 * location, it's recommended to keep usage of this function to one stage only.
 */
#define set_pad_preset_to_investigation_terminal(object) \
	mkshort(0x0142), \
	object, \
	0x00,

/**
 * Sets the current chopper's weapons to armed.
 *
 * The state of the weapons can be checked with if_chopper_weapons_armed.
 */
#define chopper_arm_weapons \
	mkshort(0x0143),

/**
 * Sets the current chopper's weapons to unarmed.
 *
 * The state of the weapons can be checked with if_chopper_weapons_armed.
 */
#define chopper_unarm_weapons \
	mkshort(0x0144), \
	label,

/**
 * Rebuilds the list of teams containing chr IDs in each team.
 *
 * Should be used after reassigning chrs to teams.
 */
#define rebuild_teams \
	mkshort(0x0145),

/**
 * Rebuilds the list of squadrons containing chr IDs in each squadron.
 *
 * Should be used after reassigning chrs to squadrons.
 */
#define rebuild_squadrons \
	mkshort(0x0146),

/**
 * Checks if all chrs in the given squadron are dead.
 *
 * Note: Due to a bug, this command ends up only checking if the last chr in the
 * squadron is dead.
 */
#define if_all_chrs_in_squadron_are_dead(squadron, label) \
	mkshort(0x0147), \
	squadron, \
	label,

/**
 * Set the given chr to listening.
 *
 * The listening feature appears to be completely unused.
 */
#define chr_set_listening(chr, value) \
	mkshort(0x0148), \
	chr, \
	value,

/**
 * Checks if the given chr is listening.
 *
 * checktype 0 = if chr's listening value is listenvalue
 * checktype 1 = if chr's convtalk value is zero
 */
#define if_chr_listening(chr, listenvalue, checktype, label) \
	mkshort(0x0149), \
	chr, \
	listenvalue, \
	checktype, \
	label,

/**
 * Always goes to label. Other arguments are unused. Probably has a purpose in
 * debug.
 */
#define if_true(u1, u2, u3, label) \
	mkshort(0x014a), \
	u1, \
	u2, \
	u3, \
	label,

/**
 * Checks if the current chr is not listening (ie. not participating in a
 * conversation).
 */
#define if_not_listening(label) \
	mkshort(0x014b), \
	label,

/**
 * Checks if the number of chrs in the given squadron is greater than the given
 * value.
 */
#define if_num_chrs_in_squadron_gt(value, squadron, label) \
	mkshort(0x0152), \
	value, \
	squadron, \
	label,

/**
 * Toggles tinted glass opaqueness/transparency.
 */
#define set_tinted_glass_enabled(bool) \
	mkshort(0x0157), \
	bool,

/**
 * Plays the given music track.
 */
#define play_music_track(id) \
	mkshort(0x015b), \
	id,

/**
 * Restarts the default stage music from the beginning.
 */
#define restart_music \
	mkshort(0x015c),

/**
 * Checks if the chr injured their target. Use this after attacking.
 *
 * The command will unset the flag so it may be used again.
 */
#define if_chr_injured_target(chr, label) \
	mkshort(0x0165), \
	chr, \
	label,

/**
 * Checks if the current chr's action is the given action.
 */
#define if_action_eq(action, label) \
	mkshort(0x0166), \
	label,

/**
 * Makes the Extraction hovercopter fire a rocket from the given side.
 *
 * Side may be 0 or 1.
 */
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

/**
 * Checks if the chr's Y coordinate is greater than or less than the given
 * value.
 *
 * Operator is expected to be OPERATOR_LESS_THAN or OPERATOR_GREATER_THAN.
 */
#define if_chr_y(chr, value, operator, label) \
	mkshort(0x016a), \
	chr, \
	mkshort(value), \
	operator, \
	label,

/**
 * Play a sound from the given object.
 *
 * Typically used to make terminals hum.
 */
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

/**
 * Add motion blur to the player. Motion blur will wear off automatically.
 */
#define add_motion_blur(chr, value, bool) \
	mkshort(0x016d), \
	chr, \
	value, \
	bool,

#define damage_player(chr, u1, operation) \
	mkshort(0x016e), \
	chr, \
	u1, \
	operation,

// Likely related to being disarmed.
// Not sure what this does if the chr had no gun to begin with.
#define if_has_gun(chr, label) \
	mkshort(0x016f), \
	chr, \
	0x00, \
	label,

/**
 * If operation is 1, checks if the chr's dropped gun can be run to and follow
 * the label if so.
 *
 * If operation is 0, makes the chr run to the dropped gun. No check is done,
 * and the label is followed.
 *
 * Don't use this directly. Use convenience macros if_gun_landed and go_to_gun
 * instead.
 */
#define do_gun_command(operation, label) \
	mkshort(0x0170), \
	operation, \
	label,

/**
 * Checks if the chr's distance to their dropped gun is less than the given
 * value.
 */
#define if_distance_to_gun_lt(distance, label) \
	mkshort(0x0171), \
	mkshort(distance / 10), \
	label,

/**
 * Makes the chr's gun disappear from the ground and gives it to the chr
 * (when a guard drops their gun and picks it up).
 */
#define chr_recover_gun(chr, label) \
	mkshort(0x0172), \
	chr, \
	label,

/**
 * Attempts to copy properties from the given chr to the current chr.
 *
 * Typically used after spawning a guard.
 */
#define try_inherit_properties(chr_src, label) \
	mkshort(0x0173), \
	chr_src, \
	label,

/**
 * Checks if a controller button has been pressed during a cutscene.
 *
 * This should be checked inside every loop in cutscenes, otherwise that part of
 * the cutscene becomes unskippable.
 */
#define if_controller_button_pressed(label) \
	mkshort(0x0174), \
	label,

// Used in cutscenes before giving control to Jo
// Value is always 60
// Without this command, or with a 0 value, Jo faces a different direction
#define cmd0175(u1) \
	mkshort(0x0175), \
	u1,

/**
 *
 */
#define cmd0176_if_something(label) \
	mkshort(0x0176), \
	label,

/**
 * Forces the player to walk to the given pad (eg. Extraction and Duel).
 */
#define force_walk(chr, aimpad, walkspeed, turnspeed, lookup, dist) \
	mkshort(0x0177), \
	chr, \
	mkshort(aimpad), \
	walkspeed, \
	turnspeed, \
	lookup, \
	dist,

/**
 * Checks if the player's force walk has finished.
 */
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

/**
 * Checks if the chr is knocked out or invalid.
 */
#define if_chr_knockedout(chr, label) \
	mkshort(0x017b), \
	chr, \
	label,

/**
 * Assigns a sound to the given channel. Does not play the sound.
 */
#define assign_sound(sound, channel) \
	mkshort(0x017c), \
	mkshort(sound), \
	channel,

/**
 * Sets the music track for this stage.
 */
#define set_music_track(id) \
	mkshort(0x017d), \
	id,

/**
 * Restarts the default stage music.
 */
#define restart_default_music \
	mkshort(0x017e),

/**
 * Sets the sound effects track. This is typically background noise like wind,
 * waves and the Area 51 announcements.
 */
#define set_sfx_track(id) \
	mkshort(0x017f), \
	id,

/**
 * Resets the sound effects track.
 */
#define reset_ambience \
	mkshort(0x0180),

/**
 * Checks if the player is looking directly at the given object.
 */
#define if_chr_looking_at_object(chr, object, label) \
	mkshort(0x0181), \
	chr, \
	object, \
	label,

/**
 * Makes the current chr attack their target by punching or kicking.
 */
#define try_punch_or_kick(label) \
	mkshort(0x0182), \
	0x00, \
	label,

/**
 * Checks if the current chr's target is the player.
 */
#define if_target_is_player(label) \
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

#define mp_init_simulants \
	mkshort(0x0185),

#define if_chr_soundtimer(value, operator, label) \
	mkshort(0x0186), \
	mkshort(value), \
	operator, \
	label,

/**
 * Checks if the current chr can see the player's camspy. If they can, their
 * target is changed to the camspy and the label will be followed.
 *
 * This command respects the chr's p1p2 property, meaning in coop mode this must
 * be set to the player whose camspy should be checked.
 */
#define set_target_to_camspy_if_in_sight(label) \
	mkshort(0x0187), \
	label,

/**
 * Checks if the lift is currently stopped.
 */
#define if_lift_stationary(lift, label) \
	mkshort(0x0188), \
	lift, \
	label,

/**
 * Makes the lift go to the given stop number.
 *
 * Lifts only support up to 4 stops, so stopnum must be 0-3.
 */
#define lift_go_to_stop(lift, stopnum) \
	mkshort(0x0189), \
	lift, \
	stopnum,

/**
 * Checks if the lift is stopped at the given stop number.
 */
#define if_lift_at_stop(lift, stopnum, label) \
	mkshort(0x018a), \
	lift, \
	stopnum, \
	label,

/**
 * Enables rain.
 *
 * The given value is not known. It may be intensity or direction.
 */
#define enable_rain(value) \
	mkshort(0x018b), \
	value,

/**
 * Remove the necklace from the given chr.
 */
#define remove_cass_necklace(chr) \
	mkshort(0x018c), \
	chr, \
	0x07,

/**
 * Activate the given lift.
 *
 * Lifts need to be activated before they start working.
 */
#define activate_lift(liftid, object) \
	mkshort(0x018d), \
	liftid, \
	object,

/**
 * Makes a miniskedar attempt to pounce.
 *
 * Will not pass the check if the miniskedar doesn't have enough room.
 */
#define miniskedar_try_pounce(u1, u2, label) \
	mkshort(0x018e), \
	u1, \
	mkshort(u2), \
	0x00, \
	label,

/**
 * Checks if the distance between the given object and the given pad is less
 * than the given value.
 */
#define if_object_distance_to_pad_lt(object, distance, pad, label) \
	mkshort(0x018f), \
	object, \
	mkshort(distance / 10), \
	mkshort(pad), \
	label,

/**
 * Sets a savefile flag.
 *
 * Expected to be a SAVEFILEFLAG constant.
 */
#define set_savefile_flag(flag) \
	mkshort(0x0190), \
	flag,

/**
 * Unsets a savefile flag.
 */
#define unset_savefile_flag(flag) \
	mkshort(0x0191), \
	flag,

/**
 * Checks if the given savefile flag is set.
 */
#define if_savefile_flag_is_set(flag, label) \
	mkshort(0x0192), \
	flag, \
	label,

/**
 * Checks if the given savefile flag is unset.
 */
#define if_savefile_flag_is_unset(flag, label) \
	mkshort(0x0193), \
	flag, \
	label,

/**
 * Checks if the given object's health is less than the given value.
 */
#define if_object_health_lt(object, value, label) \
	mkshort(0x019e), \
	object, \
	mkshort(value), \
	label,

/**
 * Sets the given object's health.
 */
#define set_object_health(object, value) \
	mkshort(0x019f), \
	object, \
	mkshort(value),

/**
 * Assigns a special death animation to the given chr.
 *
 * This is used for the Villa snipers, the Chicago guard on the fire escape,
 * and all guards who sit in chairs.
 *
 * The value for specialdie should be one of the SPECIALDIE constants.
 */
#define set_chr_special_death_animation(chr, specialdie) \
	mkshort(0x01a0), \
	chr, \
	specialdie,

/**
 * Sets the current chr's roomtosearch field to the same room that the chr's
 * target is in.
 */
#define set_chr_roomtosearch \
	mkshort(0x01a1),

/**
 * Play a quip for the CI staff.
 *
 * The ciquip argument is expected to be one of the CIQUIP constants. This
 * determines what type of quip they say (greeting, main, annoyed or thankful).
 *
 * The voice used depends on the chr's morale property. Valid morales are 0-9,
 * but if using the main bank only 0-5 are valid.
 *
 * Each quip type + morale combination has up to three quips that may be said.
 * The quip used is random.
 */
#define play_cistaff_quip(ciquip, channel) \
	mkshort(0x01a2), \
	ciquip, \
	channel,

/**
 * If value is 0-2 or 4-14, do talking animation from g_PresetAnimations array.
 * If value is 3, choose a random talking anim out of 2.
 * If value is 254, do a gun jam animation.
 * If value is 255, choose a random talking anim out of 8.
 */
#define do_preset_animation(value) \
	mkshort(0x01a3), \
	value,

/**
 * Show or remove a HUD message.
 *
 * If operation is 0, show it in the top middle with infinite duration.
 * If operation is 1, show it in the bottom middle with a long duration.
 * If operation is 2, remove all HUD messages.
 *
 * For removing HUD messages, consider using remove_hudmsgs instead.
 */
#define show_hudmsg_middle(operation, color, text) \
	mkshort(0x01a4), \
	operation, \
	color, \
	mkshort(text),

#define cmd01a5(label) \
	mkshort(0x01a5), \
	label,

/**
 * Checks if the Y distance between the current chr and their target is less
 * than the given value.
 */
#define if_target_y_difference_lt(distance, label) \
	mkshort(0x01a6), \
	distance / 10, \
	label

#define if_chr_propsoundcount_zero(chr, label) \
	mkshort(0x01a7), \
	chr, \
	label,

#define cmd01aa(label) \
	mkshort(0x01aa), \
	label,

/**
 * Checks if the number of knocked out chrs is less than or greater than the
 * given value.
 *
 * Operator is expected to be OPERATOR_LESS_THAN or OPERATOR_GREATER_THAN.
 */
#define if_num_subdued(value, operator, label) \
	mkshort(0x01ab), \
	value, \
	1 - operator, \
	label,

/**
 * Makes the player let go of the currently held object (eg. hovercrate or bed).
 */
#define release_grabbed_object(chr) \
	mkshort(0x01ad), \
	chr,

/**
 * Removes all items from the player's inventory.
 */
#define clear_inventory(chr) \
	mkshort(0x01ae), \
	chr,

/**
 * Makes the player grab the given object (eg. hovercrate or bed).
 */
#define grab_object(chr, object) \
	mkshort(0x01af), \
	chr, \
	object,

/**
 * Shuffles the pillars in Skedar Ruins.
 *
 * The P arguments are pillars. M arguments are mines.
 *
 * The dst tags are remapped so they point at random pillars.
 */
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

/**
 * Toggle which player (Bond or Coop) is referenced by the chr's CHR_P1P2
 * identifier. This should be called inside a loop to give the illusion of
 * referencing both players.
 *
 * This is safe to use in solo mode; it will not set it to coop if they don't
 * exist.
 */
#define chr_toggle_p1p2(chr) \
	mkshort(0x01b3), \
	chr,

#define cmd01b4_if_something(label) \
	mkshort(0x01b4), \
	label,

/**
 * Sets the given chr's p1p2 value explicitly to the given p1p2_chr.
 */
#define chr_set_p1p2(chr, p1p2_chr) \
	mkshort(0x01b5), \
	chr, \
	p1p2_chr,

/**
 * Enables or disables the snow effect.
 */
#define enable_snow(bool) \
	mkshort(0x01b6), \
	bool,

/**
 * Cloak or uncloak the given chr.
 *
 * bool_unknown determines whether to call some function on the chr afterwards
 */
#define set_chr_cloaked(chr, bool_enable, bool_unknown) \
	mkshort(0x01b7), \
	chr, \
	bool_enable, \
	bool_unknown,

#define set_autoturret_type(object, type) \
	mkshort(0x01b8), \
	object, \
	type,

/**
 * Shuffle the generator switches in Pelagic II.
 *
 * Note no arguments are passed here. The switch numbers are hard coded.
 */
#define shuffle_pelagic_switches \
	mkshort(0x01b9),

/**
 * Makes the chr attempt to do a lying down attack.
 *
 * entity_type is expected to be an ENTITYTYPE constant. It can be bitwise ORed
 * with ENTITYTYPE_AIMONLY to make the chr only aim at the entity.
 */
#define try_attack_lie(entity_type, entity_id, label) \
	mkshort(0x01ba), \
	mkshort(entity_type), \
	mkshort(entity_id), \
	label,

#define noop01bb \
	mkshort(0x01bb), \
	mkshort(0),

#define cmd01bc(u1, label) \
	mkshort(0x01bc), \
	u1, \
	label,

/**
 * Checks if the CI training PC has been holographed.
 */
#define if_training_pc_holographed(label) \
	mkshort(0x01bd), \
	label,

/**
 * Checks if the given chr is using the given weapon.
 */
#define if_chr_has_weapon_equipped(chr, weapon, label) \
	mkshort(0x01be), \
	chr, \
	weapon, \
	label,

/**
 * Begins or ends the Deep Sea teleport effect.
 *
 * Call this with pad set, then go into a loop waiting for
 * if_teleport_full_white, then call this again with pad = 0.
 */
#define teleport_to_pad(pad, chr) \
	mkshort(0x01bf), \
	mkshort(pad), \
	chr,

/**
 * Checks if the teleport effect is full white.
 */
#define if_teleport_full_white(label, chr) \
	mkshort(0x01c0), \
	label, \
	chr,

/**
 * Sets the current chr's punchdodge ailist. Not sure if this used or not.
 */
#define set_aipunchdodgelist(ailistid) \
	mkshort(0x01c1), \
	mkshort(ailistid),

/**
 * Sets the current chr's shootingatme ailist.
 *
 * This is used to make the chr attempt a dodge when the player is aiming at
 * them. It is invoked somewhat randomly. See set_chr_dodge_rating.
 */
#define set_aishootingatmelist(ailistid) \
	mkshort(0x01c2), \
	mkshort(ailistid),

/**
 * Sets the current chr's darkroom ailist. This is assigned when the lights are
 * switched off.
 */
#define set_darkroomlist(function) \
	mkshort(0x01c3), \
	mkshort(function),

/**
 * Sets the current chr's playerdead ailist. This is probably assigned when the
 * player dies.
 */
#define set_aiplayerdeadlist(ailistid) \
	mkshort(0x01c4), \
	mkshort(ailistid),

// Calls some function on the chr. Possibly related to geometry, because it
// works with values such as 45 and 360.
#define cmd01c5 \
	mkshort(0x01c5),

/**
 * Sets the current chr's dodgerating and maxdodgerating properties.
 *
 * If whichprop is 0, set dodgerating
 * If whichprop is 1, set maxdodgerating
 * If whichprop is 2, set both
 *
 * When the player aims at the chr, there is a random chance that they will
 * attempt to dodge. Each time they decide not to dodge, the rating is doubled
 * until it hits the max. Once the chr has dodged once they will not dodge
 * again.
 */
#define set_chr_dodge_rating(value, whichprop) \
	mkshort(0x01c6), \
	value, \
	whichprop,

/**
 * This doesn't appear to be used.
 */
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

/**
 * Set a weapon to be used in a cutscene.
 *
 * If both weapon and fallback are given, this might set them to the left and
 * right weapons.
 *
 * If weapon is -1 (WEAPON_NONE) and fallback is given, fallback will be used.
 *
 * If both are -1 (WEAPON_NONE), the chr's current weapon will be used if it's
 * a pistol, otherwise the Falcon 2 will be used.
 */
#define set_cutscene_weapon(chr, weapon, weapon_fallback) \
	mkshort(0x01ca), \
	chr, \
	weapon, \
	weapon_fallback,

/**
 * Fade the scene to the given color over the given number of frames.
 *
 * The color is a hex colour code in RGBA format.
 * For num_frames, assume 60 frames per second.
 *
 * You can fade in the level by calling this twice in a row:
 * First with 0x000000ff (solid black) and num_frames = 0.
 * Second with 0x00000000 (transparent) and num_frames = 90.
 */
#define fade_to_color(rgba, num_frames) \
	mkshort(0x01cb), \
	mkword(rgba), \
	mkshort(num_frames),

/**
 * Checks if the screen fade is complete. Follows the label if complete.
 */
#define if_fade_complete(label) \
	mkshort(0x01cc), \
	label,

/**
 * Determines whether Jo's HUD eyepiece thing is visible when in the third
 * person perspective (ie. in cutscenes or when playing coop).
 */
#define set_chr_hudpiece_visible(chr, bool) \
	mkshort(0x01cd), \
	chr, \
	bool,

/**
 * Disallows the use of weapons and unarmed.
 *
 * Used in the Carrington Institute.
 */
#define passive_mode(bool) \
	mkshort(0x01ce), \
	bool,

/**
 * Makes a chr start or stop shooting in a cutscene.
 */
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

/**
 * Emits sparks from the given chr.
 *
 * Used for Dr Caroll.
 */
#define emit_sparks(chr) \
	mkshort(0x01d2), \
	chr,

/**
 * Sets the images for Dr Caroll.
 *
 * The chr argument must be Dr Caroll. The left and right arguments can be:
 *
 * 0-6 = set directly to that image ID
 * 7 = 25% chance of changing the image to a random one in range 0-5
 * 8 = 100% chance of changing the image to a random one in range 0-5
 *
 * See also DRCAROLLIMAGE constants.
 */
#define set_drcaroll_images(chr, left, right) \
	mkshort(0x01d3), \
	chr, \
	left, \
	right,

#define configure_room_portals(room) \
	mkshort(0x01d4), \
	mkshort(room), \
	0x08, \
	0x00,

/**
 * Shows or hides non-essential chrs.
 *
 * Used for cutscenes.
 */
#define show_nonessential_chrs(bool) \
	mkshort(0x01d5), \
	bool,

/**
 * Run a miscellaneous command.
 *
 * Operations 0 through 4 aren't known yet. They copy the given value to some
 * global variables. Value is expected to be 0 or 1.
 *
 * Operation 5 is unknown but operates on the given room ID.
 *
 * Operation 6 marks a room as internal or external. External rooms don't light
 * up when shots are fired. This operation expects the room ID to be supplied
 * and for value to be 0 (for internal) or 1 (for external).
 *
 * Operations 7 and 8 are unknown.
 *
 * Operation 9 is the same as operation 5, but applies to all rooms.
 *
 * Operation 0xa plays the AF1 nosedive noise. In this operation value is the
 * duration of the noise in seconds.
 *
 * Operation 0xb is unknown.
 *
 * Operation 0xc is related to the Rescue lights being overloaded, but specifics
 * are not known.
 *
 * Operation 0xd is believed to stop the AF1 nosedive noise.
 *
 * Operation 0xe and 0xf are related to the UFO exit on Escape. They probably
 * start and stop the UFO noise but this hasn't been tested.
 */
#define misc_command(room, operation, value) \
	mkshort(0x01d6), \
	mkshort(room), \
	operation, \
	value,

/**
 * Redundant command. See if_distance_to_target_lt.
 */
#define if_distance_to_target2_lt(distance, label) \
	mkshort(0x01d7), \
	mkshort(distance / 10), \
	label,

/**
 * Redundant command. See if_distance_to_target_gt.
 */
#define if_distance_to_target2_gt(distance, label) \
	mkshort(0x01d8), \
	mkshort(distance / 10), \
	label,

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

/**
 * Unsure exactly how this works. I think it replaces the main level theme with
 * the one specified.
 *
 * Track is expected to be a MUSIC constant.
 */
#define play_music_continuously(track) \
	mkshort(0x01da), \
	track,

/**
 * Kills the given chr.
 */
#define kill(chr) \
	mkshort(0x01db), \
	chr,

/**
 * Removes the given weapon from the current player's inventory.
 */
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

/**
 * Gets the distance from chr to pad, but only if they are on the same floor
 * (ie. Y difference is less than 150).
 */
#define if_chr_same_floor_distance_to_pad_lt(chr, pad, distance, label) \
	mkshort(0x01df), \
	chr, \
	mkshort(pad), \
	mkshort(distance / 10), \
	label,

/**
 * Checks if the game is being played in co-operative mode.
 *
 * This command does not check if the buddy is a human or bot. You can use
 * if_num_human_players_lt for that.
 */
#define if_coop_mode(label) \
	mkshort(0x01de), \
	label,

/**
 * Clears references to the current chr.
 *
 * Any chr who is targetting this one will have their target cleared.
 * Any chr who has their chrpreset set to this one will have their chrpreset
 * cleared.
 *
 * This appears to be a debug command. It is not used normally.
 */
#define remove_references_to_chr \
	mkshort(0x01e0),

// Convenience macros for readability
#define beginloop(id) label(id) yield

#define endloop(id) goto_first(id)

#define reloop(id) goto_first(id)

#define remove_hudmsgs show_hudmsg_middle(0x02, 0, 0x0002)

#define if_stage_is_not(stage, label) if_stage_lt(stage, label) if_stage_gt(stage, label)

#define go_to_gun(label) do_gun_command(0, label)
#define if_gun_landed(label) do_gun_command(1, label)
