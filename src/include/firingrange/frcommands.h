/**
 * Weapon scripts only: Adds a target to the current session.
 *
 * frpadnum - is the location where the target will appear.
 * script - is the target script index that the target will use.
 *     For example, 0x0c means it will use the script at "u8 target0c".
 * maxdamage - is how much health the target has.
 * flags - is a bitwise field. See below
 *
 * Flags:
 * FRTARGETFLAG_BRONZE                 - Target will appear on bronze difficulty
 * FRTARGETFLAG_SILVER                 - Target will appear on silver difficulty
 * FRTARGETFLAG_GOLD                   - Target will appear on gold difficulty
 * FRTARGETFLAG_ROTATEONCLOAK          - Rotate when the player uses cloak (RC-P120)
 * FRTARGETFLAG_SPAWNFACINGAWAY        - Spawn with its back to the player
 * FRTARGETFLAG_ONEHITEXPLODE          - For K7 Avenger's threat detector
 * FRTARGETFLAG_FARSIGHTAUTOTARGETABLE - Must be set for Farsight's second function to find it
 * FRTARGETFLAG_TMPINVINCIBLE          - Grant 5 seconds invincibility when the target spawns, for spawning into explosions
 */
#define add_target(frpadnum, script, maxdamage, flags) \
	0x00, frpadnum, script, maxdamage, flags

/**
 * Weapon scripts only: Sets the maximum number of targets that can be
 * active/visible at the same time. As each target is destroyed a new one will
 * become active until there are no more targets.
 */
#define set_max_active_targets(bronze, silver, gold) \
	0x01, bronze, silver, gold

/**
 * Weapon scripts only: Sets the goal score.
 *
 * Expects values in the range 0 to 250.
 *
 * Scores over 250 can be set by making use of the set_score_multiplier command.
 */
#define set_goal_score(bronze, silver, gold) \
	0x02, bronze, silver, gold

/**
 * Weapon scripts only: Sets the time limit in seconds, or 255 for no limit.
 */
#define set_time_limit(bronze, silver, gold) \
	0x03, bronze, silver, gold

/**
 * Weapon scripts only: Sets the ammo limit, or 255 for no limit.
 */
#define set_ammo_limit(bronze, silver, gold) \
	0x04, bronze, silver, gold

/**
 * Weapon scripts only: Increases the speed at which targets can travel.
 *
 * The "normal" speed is 1, so setting the extra speed to 1 makes it run twice
 * as fast. This value accepts single digit decimals such as 0.1. Acceptable
 * values are in the range 0.0 to 25.0.
 */
#define set_extra_speed(bronze, silver, gold) \
	0x05, bronze * 10, silver * 10, gold * 10

/**
 * Weapon scripts only: Sets the goal accuracy.
 *
 * Acceptable values are 0 to 100, where 0 disables the accuracy requirement.
 */
#define set_goal_accuracy(bronze, silver, gold) \
	0x06, bronze, silver, gold

/**
 * Weapon scripts only: Sets the goal number of targets to be destroyed.
 *
 * Acceptable values are 0 to 250, or 255 to disable the goal targets
 * requirement.
 */
#define set_goal_targets(bronze, silver, gold) \
	0x07, bronze, silver, gold

/**
 * Weapon scripts only: Sets the help script which will be used.
 *
 * Help scripts are used to display instructional help messages to the player.
 *
 * Acceptable values are 0 to 2, but this could be increased if more help
 * scripts are added.
 */
#define set_help_script(script) \
	0x08, script

/**
 * Weapon scripts only: Sets the SuperDragon grenade limit, or 255 for no limit.
 */
#define set_grenade_limit(bronze, silver, gold) \
	0x09, bronze, silver, gold

/**
 * Weapon scripts only: Set an offset which will be used when looking up
 * frpadnums for all targets in this session. This allows the same target script
 * to be shared across different sessions while having them visit different pads
 * based on the session.
 *
 * Care should be taken when using this, as an array overflow may occur if the
 * offset is too high.
 */
#define set_pad_index_offset(offset) \
	0x0a, offset

/**
 * Weapon scripts only: Sets a multiplier which is used to calculate the goal
 * score.
 *
 * Because the script data is made up of single bytes, it would normally be
 * impossible to set goal scores above 255. This command is a workaround to
 * allow higher goal scores.
 */
#define set_score_multiplier(bronze, silver, gold) \
	0x0b, bronze, silver, gold

/**
 * Target scripts only: Makes the target go to the specified pad.
 *
 * frpadnum:
 * If 0-30, is used as an index into the g_FrPads array, after applying an
 * offset if was specified using set_pad_index_offset.
 * If 31, returns a random pad in frpadnum range 4-12
 * If 32, returns a random pad in frpadnum range 13-21
 * If 33, returns a random pad in frpadnum range 22-30
 * If 34, returns a random pad in frpadnum range 4-30
 *
 * In practice the random values are not used, nor anything above 12.
 *
 * speed:
 * If set to 255, the target is immediately placed at the destination pad.
 *
 * seconds:
 * Disables script execution for the given amount of seconds. If the target
 * stops before this time then it'll effectively wait before continuing the
 * script.
 */
#define go_to_pad(frpadnum, speed, seconds) \
	0x0c, frpadnum, speed, seconds

/**
 * Target scripts only: Loops back to the start of the script and continues
 * execution.
 */
#define restart() \
	0x0d

/**
 * Target scripts only: Waits for the specified amount of seconds before
 * continuing the script.
 */
#define wait_seconds(seconds) \
	0x0e, seconds

/**
 * Target scripts only: Rotates the target in the given direction, relative to
 * its current direction.
 *
 * Expected values for direction are one of:
 * FRROTATE_90R
 * FRROTATE_180R
 * FRROTATE_90L
 * FRROTATE_180L
 *
 * The duration value is unitless. The higher it is the slower the rotation.
 */
#define rotate(direction, duration) \
	0x0f, direction, duration

/**
 * Help scripts only: Displays a HUD message to the player.
 *
 * The frtextindex is an index into the texts array at the top of the firing
 * range script file.
 */
#define hudmsg(frtextindex) \
	0x10, frtextindex

/**
 * Help scripts only: Waits until the player fires their gun before continuing
 * script execution.
 */
#define wait_until_shoot() \
	0x11

/**
 * Help scripts only: Waits the specified number of seconds before continuing
 * script execution.
 *
 * This command is unused.
 */
#define help_wait_seconds(seconds) \
	0x12, seconds

/**
 * All scripts: Marks the end of the script.
 */
#define end() \
	0x13

/**
 * Help scripts only: Applies the subsequent commands if the difficulty is bronze.
 */
#define if_bronze() \
	0xfb

/**
 * Help scripts only: Applies the subsequent commands if the difficulty is silver.
 */
#define if_silver() \
	0xfc

/**
 * Help scripts only: Applies the subsequent commands if the difficulty is gold.
 */
#define if_gold() \
	0xfd

/**
 * All scripts: Marks the start of the script.
 */
#define start() \
	0xfe

