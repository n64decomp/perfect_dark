#define add_target(frpadnum, script, target01, flags) \
	0x00, frpadnum, script, target01, flags

#define set_num_targets(bronze, silver, gold) \
	0x01, bronze, silver, gold

#define set_goal_score(bronze, silver, gold) \
	0x02, bronze, silver, gold

#define set_time_limit(bronze, silver, gold) \
	0x03, bronze, silver, gold

#define set_ammo_limit(bronze, silver, gold) \
	0x04, bronze, silver, gold

#define set_extra_speed(bronze, silver, gold) \
	0x05, bronze * 10, silver * 10, gold * 10

#define set_goal_accuracy(bronze, silver, gold) \
	0x06, bronze, silver, gold

#define set_goal_targets(bronze, silver, gold) \
	0x07, bronze, silver, gold

#define set_help_script(script) \
	0x08, script

#define set_grenade_limit(bronze, silver, gold) \
	0x09, bronze, silver, gold

#define cmd_0a(value) \
	0x0a, value

#define set_score_multiplier(bronze, silver, gold) \
	0x0b, bronze, silver, gold

#define go_to_pad(frpadnum, unk2, seconds) \
	0x0c, frpadnum, unk2, seconds

#define restart() \
	0x0d

#define cmd_0e(seconds) \
	0x0e, seconds

#define rotate(angle, speed) \
	0x0f, angle, speed

#define hudmsg(frtextindex) \
	0x10, frtextindex

#define wait_until_shoot() \
	0x11

#define wait_seconds(seconds) \
	0x12, seconds

#define end() \
	0x13

#define if_bronze() \
	0xfb

#define if_silver() \
	0xfc

#define if_gold() \
	0xfd

#define start() \
	0xfe

