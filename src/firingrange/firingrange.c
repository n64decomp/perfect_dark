#include <ultra64.h>
#include "constants.h"
#include "firingrange/frcommands.h"

u16 texts[] = {
	/*0*/ L_MISC(281), // "FIRING\n Press Z Button to fire gun.\n"
	/*1*/ L_MISC(282), // "AUTO RELOAD\n Release Z Button when out of ammo.\n"
	/*2*/ L_MISC(283), // "MANUAL RELOAD\n Press B Button to reload early if magazine not full.\n"
	/*3*/ L_MISC(284), // "Aiming: Hold down R Button to enter Aim mode.\n"
	/*4*/ L_MISC(285), // "Use Control Stick to move aiming sight.\n"
	/*5*/ L_MISC(286), // "AUTO FIRE\n Hold Z Button to repeatedly fire automatically.\n"
	/*6*/ L_MISC(287), // "ALTER AIM\n Press Up C Button or Down C Button to move sight up/down.\n"
	/*7*/ L_MISC(288), // "ZOOM\n Hold R Button to enter Zoom mode.\n"
	/*8*/ L_MISC(289), // "FAST FIRE\n Press Z Button quickly to fire faster.\n"
};

u8 weapon_dummy[] = {
	start(),
	end(),
};

u8 weapon_falcon2[] = {
	start(),
	set_max_active_targets(3, 1, 3),
	set_goal_score(120, 80, 170),
	set_time_limit(255, 15, 10),
	set_ammo_limit(255, 255, 24),
	set_extra_speed(0, 0.2, 0.4),
	set_help_script(0),
	cmd_0a(0x00),
	add_target(0x00, 0x12, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x02, 0x14, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x02, 0x11, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3b, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3d, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x23, 0x08, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x24, 0x08, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x25, 0x08, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_falcon2_scope[] = {
	start(),
	set_max_active_targets(1, 1, 3),
	set_goal_score(120, 120, 80),
	set_time_limit(255, 255, 10),
	set_ammo_limit(255, 255, 8),
	set_extra_speed(0, 2, 0.4),
	set_help_script(2),
	cmd_0a(0x00),
	set_goal_accuracy(0, 80, 0),
	add_target(0x01, 0x0c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x26, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x27, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x28, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1d, 0x08, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_falcon2_silencer[] = {
	start(),
	set_max_active_targets(1, 9, 3),
	set_goal_score(120, 30, 80),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 255, 255),
	set_extra_speed(0, 0.8, 0.4),
	set_help_script(1),
	cmd_0a(0x00),
	set_goal_targets(255, 9, 3),
	add_target(0x01, 0x2f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x30, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x31, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2b, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2a, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x29, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x32, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x33, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x34, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x35, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x36, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x37, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x38, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x39, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3a, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3d, 0x0c, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_magsec4[] = {
	start(),
	set_max_active_targets(1, 7, 4),
	set_goal_score(135, 135, 80),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 18, 255),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	set_goal_targets(255, 255, 4),
	add_target(0x01, 0x2b, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2a, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x29, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x42, 0xff, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x32, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x33, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x34, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x35, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x36, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x37, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3e, 0x03, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x41, 0x03, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x40, 0x03, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x3f, 0x03, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_mauler[] = {
	start(),
	set_max_active_targets(1, 8, 6),
	set_goal_score(200, 0, 0),
	set_time_limit(255, 255, 15),
	set_ammo_limit(255, 50, 35),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	set_goal_targets(255, 8, 6),
	add_target(0x01, 0x45, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x46, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x47, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x46, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x45, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x47, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x47, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x45, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x46, 0x14, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x15, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x16, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x17, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x18, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x19, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1a, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1b, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1c, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x35, 0x05, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x36, 0x05, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x37, 0x05, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x38, 0x05, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x39, 0x05, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x3a, 0x05, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_phoenix[] = {
	start(),
	set_max_active_targets(2, 3, 6),
	set_goal_score(90, 0, 0),
	set_time_limit(255, 255, 20),
	set_ammo_limit(255, 18, 3),
	set_extra_speed(2, 0.5, 2.5),
	cmd_0a(0x09),
	set_goal_targets(255, 8, 6),
	add_target(0x00, 0x3e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x40, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x41, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x40, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x41, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3d, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3d, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x3d, 0x0c, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0x00, 0x22, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x21, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x20, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1f, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1d, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1e, 0x01, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_dy357magnum[] = {
	start(),
	set_max_active_targets(1, 9, 9),
	set_goal_score(90, 80, 50),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 3, 5),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	add_target(0x00, 0x38, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x39, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3a, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x39, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x38, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3a, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3a, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x39, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x38, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0c, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x0d, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x02, 0x0e, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x02, 0x11, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x13, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x02, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x32, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2a, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2b, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2c, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x36, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2e, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x38, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x30, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x3a, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_dy357lx[] = {
	start(),
	set_max_active_targets(1, 3, 1),
	set_goal_score(90, 200, 100),
	set_time_limit(255, 30, 50),
	set_ammo_limit(255, 255, 12),
	set_extra_speed(0, 1, 0.5),
	cmd_0a(0x00),
	add_target(0x00, 0x15, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x16, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x17, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x18, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x19, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1a, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1b, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1c, 0x06, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x22, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x21, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x20, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1f, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1d, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1e, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x22, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_cmp150[] = {
	start(),
	set_max_active_targets(3, 4, 3),
	set_score_multiplier(1, 0, 2),
	set_goal_score(240, 0, 175),
	set_time_limit(255, 255, 20),
	set_ammo_limit(255, 80, 255),
	set_extra_speed(0, 12, 3),
	cmd_0a(0x09),
	set_goal_targets(255, 4, 6),
	add_target(0x00, 0x3a, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x39, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x38, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x37, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x36, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x35, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x34, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x33, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x32, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3e, 0x0c, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x40, 0x0c, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x41, 0x0c, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3f, 0x0c, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x26, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x27, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x28, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x26, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x27, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x28, 0x0c, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_cyclone[] = {
	start(),
	set_max_active_targets(3, 2, 3),
	set_score_multiplier(3, 0, 2),
	set_goal_score(250, 0, 200),
	set_time_limit(255, 20, 18),
	set_ammo_limit(255, 255, 255),
	set_extra_speed(0, 1, 1),
	cmd_0a(0x09),
	set_goal_targets(255, 5, 1),
	add_target(0x01, 0x12, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x14, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x11, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0f, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x45, 0x19, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x46, 0x19, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x47, 0x19, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x45, 0x19, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x46, 0x19, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0xfa, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x42, 0x19, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x43, 0x19, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_callistontg[] = {
	start(),
	set_max_active_targets(6, 4, 9),
	set_score_multiplier(2, 0, 1),
	set_goal_score(240, 0, 250),
	set_time_limit(255, 30, 20),
	set_ammo_limit(255, 255, 255),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x09),
	set_goal_targets(255, 1, 2),
	add_target(0x01, 0x0f, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x11, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x12, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x14, 0x20, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x4c, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x4d, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x4e, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1f, 0x28, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x32, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x2a, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x2b, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x2c, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x36, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x2e, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x38, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x30, 0x14, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3a, 0x14, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_rcp120[] = {
	start(),
	set_max_active_targets(1, 3, 9),
	set_score_multiplier(4, 2, 1),
	set_goal_score(250, 150, 0),
	set_time_limit(255, 20, 20),
	set_ammo_limit(255, 255, 180),
	set_extra_speed(0, 1, 3),

	// @bug: This causes the RC-P120 to show help messages.
	// It's likely a copy/paste error from the Falcon 2.
	set_help_script(0),

	cmd_0a(0x09),
	set_goal_targets(255, 255, 9),
	add_target(0x01, 0x07, 0xff, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x14, 0x14, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0x00, 0x13, 0x14, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0x00, 0x12, 0x14, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0x00, 0x14, 0x04, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0x00, 0x13, 0x04, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0x00, 0x12, 0x04, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0x00, 0x11, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x10, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0f, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0e, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0d, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0c, 0x0a, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_laptopgun[] = {
	start(),
	set_max_active_targets(3, 3, 3),
	set_score_multiplier(5, 0, 3),
	set_goal_score(150, 90, 250),
	set_time_limit(30, 20, 15),
	set_ammo_limit(255, 255, 250),
	set_extra_speed(0, 1, 5),
	cmd_0a(0x09),
	set_goal_targets(255, 3, 2),
	add_target(0x01, 0x0f, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x02, 0x11, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x12, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x02, 0x14, 0x32, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x12, 0x1e, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x13, 0x1e, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x14, 0x1e, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x49, 0x32, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x4a, 0x32, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x4b, 0x32, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_dragon[] = {
	start(),
	set_max_active_targets(3, 1, 5),
	set_score_multiplier(3, 0, 2),
	set_goal_score(150, 0, 250),
	set_time_limit(255, 10, 15),
	set_ammo_limit(255, 1, 255),
	set_extra_speed(0, 1, 0.6),
	cmd_0a(0x09),
	set_goal_targets(255, 1, 255),
	set_goal_accuracy(0, 0, 90),
	add_target(0x00, 0x31, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x30, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x2f, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x2e, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x2d, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x2c, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x2b, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x2a, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x29, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x42, 0xff, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x43, 0xff, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x2c, 0x1e, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x36, 0x1e, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x2e, 0x1e, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_k7avenger[] = {
	start(),
	set_max_active_targets(1, 5, 3),
	set_score_multiplier(3, 0, 0),
	set_goal_score(125, 0, 0),
	set_time_limit(255, 255, 15),
	set_ammo_limit(255, 4, 30),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x09),
	set_goal_targets(255, 4, 3),
	add_target(0x01, 0x0c, 0x19, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0d, 0x19, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0x19, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0c, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0xff, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0x00, 0x0e, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0xff, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0x00, 0x10, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0xff, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0x00, 0x12, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x13, 0xff, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0x00, 0x14, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2b, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x33, 0x0a, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x29, 0x0a, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_ar34[] = {
	start(),
	set_max_active_targets(3, 3, 1),
	set_score_multiplier(3, 0, 5),
	set_goal_score(150, 0, 100),
	set_time_limit(255, 255, 20),
	set_ammo_limit(255, 120, 255),
	set_extra_speed(0, 1, 0.5),
	cmd_0a(0x09),
	set_goal_targets(255, 9, 255),
	set_goal_accuracy(0, 0, 100),
	add_target(0x01, 0x45, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x46, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x47, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x26, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x27, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x28, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x26, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x27, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x28, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x26, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x27, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x28, 0x0a, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1d, 0xff, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_superdragon[] = {
	start(),
	set_max_active_targets(1, 9, 5),
	set_score_multiplier(3, 0, 1),
	set_goal_score(150, 0, 0),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 9, 60),
	set_grenade_limit(255, 9, 4),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x09),
	set_goal_targets(255, 9, 5),
	add_target(0x00, 0x22, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x21, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x20, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1f, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1d, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1e, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x22, 0x1e, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x29, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2a, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2b, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2c, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2d, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2e, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2f, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x30, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x31, 0x14, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3e, 0x1e, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3f, 0x1e, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x41, 0x1e, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x40, 0x1e, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x10, 0x0a, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_shotgun[] = {
	start(),
	set_max_active_targets(1, 3, 1),
	set_goal_score(240, 0, 170),
	set_time_limit(255, 30, 20),
	set_ammo_limit(255, 255, 30),
	set_extra_speed(0, 0.5, 0.8),
	cmd_0a(0x00),
	set_goal_targets(255, 9, 255),
	set_score_multiplier(0, 0, 5),
	add_target(0x00, 0x14, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x12, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x11, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0f, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x13, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x10, 0x09, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3b, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3c, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3d, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3b, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3c, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3d, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3b, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3c, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3d, 0x04, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3b, 0xfa, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_sniperrifle[] = {
	start(),
	set_max_active_targets(3, 3, 3),
	set_goal_score(120, 120, 150),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 255, 15),
	set_extra_speed(0, 1, 6),
	cmd_0a(0x12),
	set_goal_accuracy(0, 90, 0),
	add_target(0x01, 0x0c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x29, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x2a, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x2b, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x2c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x2f, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x2e, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x2d, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x30, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x31, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x46, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x47, 0x05, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_farsightxr20[] = {
	start(),
	set_max_active_targets(3, 9, 6),
	set_goal_score(0, 0, 40),
	set_time_limit(255, 15, 20),
	set_ammo_limit(255, 255, 3),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x12),
	set_goal_targets(3, 6, 6),
	add_target(0x01, 0x0c, 0x03, FRTARGETFLAG_BRONZE | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x10, 0x03, FRTARGETFLAG_BRONZE | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x14, 0x03, FRTARGETFLAG_BRONZE | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x29, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x2a, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x2b, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x2c, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x2d, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x2e, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x12, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x01, 0x13, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x01, 0x14, 0x01, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x01, 0x0c, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x12, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x0e, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(0x01, 0x14, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x10, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1f, 0x01, FRTARGETFLAG_GOLD | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	end(),
};

u8 weapon_crossbow[] = {
	start(),
	set_max_active_targets(3, 3, 1),
	set_score_multiplier(0, 0, 1),
	set_goal_score(72, 90, 150),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 20, 255),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	add_target(0x01, 0x12, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x14, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0c, 0xfa, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x0d, 0xfa, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x0e, 0xfa, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x48, 0xff, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_tranquilizer[] = {
	start(),
	set_max_active_targets(8, 3, 1),
	set_goal_score(120, 250, 0),
	set_time_limit(255, 20, 15),
	set_ammo_limit(255, 255, 18),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	set_goal_targets(255, 255, 18),
	add_target(0x00, 0x15, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x16, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x17, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x18, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x19, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1a, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1b, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x1c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x38, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3a, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x39, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x35, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x36, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x37, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x38, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x39, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3a, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x13, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x11, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0d, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0e, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0c, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0d, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0c, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x0e, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x11, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x13, 0x01, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_reaper[] = {
	start(),
	set_max_active_targets(3, 3, 3),
	set_score_multiplier(5, 0, 3),
	set_goal_score(200, 0, 250),
	set_time_limit(255, 30, 30),
	set_ammo_limit(255, 255, 255),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	set_goal_targets(255, 18, 1),
	add_target(0x01, 0x2f, 0x64, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x30, 0x64, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x31, 0x64, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x13, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0e, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0e, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x13, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x49, 0x64, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x4a, 0x64, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x4b, 0x64, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_devastator[] = {
	start(),
	set_max_active_targets(3, 6, 1),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 50, 30),
	set_ammo_limit(255, 10, 6),
	set_extra_speed(0, 10, 3),
	cmd_0a(0x12),
	set_goal_targets(6, 6, 6),
	add_target(0x00, 0x12, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x10, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x13, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x11, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x14, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0e, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x46, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x47, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x2c, 0x08, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2f, 0x08, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2d, 0x08, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x31, 0x08, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x2e, 0x08, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0x00, 0x30, 0x08, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_rocketlauncher[] = {
	start(),
	set_max_active_targets(9, 8, 4),
	set_goal_score(0, 0, 40),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 18, 4),
	set_extra_speed(0, 4, 9),
	cmd_0a(0x12),
	set_goal_targets(9, 8, 4),
	add_target(0x00, 0x0c, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0e, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x10, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x11, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x12, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x13, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x14, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x15, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x16, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x17, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x18, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x19, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1a, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1b, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3e, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3f, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x41, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x40, 0x03, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_slayer[] = {
	start(),
	set_max_active_targets(1, 4, 3),
	set_goal_score(0, 40, 60),
	set_time_limit(255, 255, 40),
	set_ammo_limit(255, 6, 8),
	set_extra_speed(0, 5, 3),
	cmd_0a(0x12),
	set_goal_targets(6, 4, 6),
	add_target(0x01, 0x31, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x29, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2b, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2d, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x2f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x15, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x17, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1a, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x1c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3d, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3d, 0x0c, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_combatknife[] = {
	start(),
	set_max_active_targets(1, 3, 8),
	set_goal_score(72, 90, 80),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 18, 255),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x00),
	set_goal_targets(255, 255, 8),
	add_target(0x01, 0x12, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x14, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x38, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3a, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x39, 0x06, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x15, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x16, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x17, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x18, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x19, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1a, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1b, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1c, 0x01, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_laser[] = {
	start(),
	set_max_active_targets(3, 1, 3),
	set_goal_score(250, 180, 250),
	set_time_limit(255, 20, 20),
	set_ammo_limit(255, 255, 255),
	set_extra_speed(0, 0.1, 0.7),
	cmd_0a(0x00),
	set_goal_targets(255, 255, 255),
	set_goal_accuracy(0, 80, 100),
	add_target(0x01, 0x12, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3b, 0xff, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x45, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x46, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x47, 0x0c, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_grenade[] = {
	start(),
	set_max_active_targets(1, 3, 1),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 30, 30),
	set_ammo_limit(255, 255, 6),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x09),
	set_goal_targets(3, 18, 4),
	add_target(0x01, 0x12, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x14, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x13, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x13, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3e, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3f, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x41, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x40, 0x03, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_1e[] = {
	start(),
	set_max_active_targets(3, 9, 4),
	set_goal_score(72, 90, 80),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 18, 255),
	set_extra_speed(0, 1, 3),
	cmd_0a(0x09),
	add_target(0x01, 0x12, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x10, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x0e, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x13, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0e, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0c, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x14, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x12, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x10, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0c, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0e, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x11, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x13, 0x01, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3e, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3f, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x41, 0x03, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x40, 0x03, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_timedmine[] = {
	start(),
	set_max_active_targets(3, 6, 6),
	set_goal_score(0, 0, 60),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 6, 1),
	set_extra_speed(0, 10, 3),
	cmd_0a(0x09),
	set_goal_targets(3, 6, 6),
	add_target(0x01, 0x2f, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x30, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x31, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x0c, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0d, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0e, 0x08, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x46, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x47, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x0f, 0x08, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x10, 0x08, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x11, 0x08, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x46, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x47, 0x05, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_proximitymine[] = {
	start(),
	set_max_active_targets(3, 3, 5),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 6, 4),
	set_extra_speed(0, 1, 3),
	set_goal_targets(3, 3, 5),
	cmd_0a(0x09),
	add_target(0x01, 0x12, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x14, 0x08, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x46, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x47, 0x05, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x45, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x46, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x01, 0x47, 0x05, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3b, 0x0c, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x3c, 0x0c, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_remotemine[] = {
	start(),
	set_max_active_targets(3, 4, 7),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 4, 2),
	set_extra_speed(0, 5, 3),
	cmd_0a(0x00),
	set_goal_targets(3, 4, 7),
	add_target(0x01, 0x14, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x13, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x01, 0x12, 0xfa, FRTARGETFLAG_BRONZE),
	add_target(0x00, 0x3e, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x3f, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x41, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x00, 0x40, 0x03, FRTARGETFLAG_SILVER),
	add_target(0x01, 0x10, 0xfa, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x22, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x21, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x20, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1f, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1d, 0x01, FRTARGETFLAG_GOLD),
	add_target(0x00, 0x1e, 0x01, FRTARGETFLAG_GOLD),
	end(),
};

u8 target00[] = {
	start(),
	go_to_pad(0x04, 0xff, 255),
	end(),
};

u8 target01[] = {
	start(),
	go_to_pad(0x05, 0xff, 255),
	end(),
};

u8 target02[] = {
	start(),
	go_to_pad(0x06, 0xff, 255),
	end(),
};

u8 target03[] = {
	start(),
	go_to_pad(0x07, 0xff, 255),
	end(),
};

u8 target04[] = {
	start(),
	go_to_pad(0x08, 0xff, 255),
	end(),
};

u8 target05[] = {
	start(),
	go_to_pad(0x09, 0xff, 255),
	end(),
};

u8 target06[] = {
	start(),
	go_to_pad(0x0a, 0xff, 255),
	end(),
};

u8 target07[] = {
	start(),
	go_to_pad(0x0b, 0xff, 255),
	end(),
};

u8 target08[] = {
	start(),
	go_to_pad(0x0c, 0xff, 255),
	end(),
};

u8 target09[] = {
	start(),
	go_to_pad(0x0b, 0xff, 0),
	cmd_0e(2),
	rotate(2, 4),
	cmd_0e(2),
	rotate(0, 4),
	cmd_0e(2),
	rotate(1, 8),
	cmd_0e(2),
	rotate(3, 8),
	cmd_0e(255),
	end(),
};

u8 target0a[] = {
	start(),
	go_to_pad(0x02, 0x1e, 255),
	go_to_pad(0x00, 0x1e, 255),
	restart(),
	end(),
};

u8 target0b[] = {
	start(),
	go_to_pad(0x01, 0x1e, 255),
	go_to_pad(0x03, 0x1e, 255),
	restart(),
	end(),
};

u8 target0c[] = {
	start(),
	go_to_pad(0x04, 0xff, 255),
	restart(),
	end(),
};

u8 target0d[] = {
	start(),
	go_to_pad(0x05, 0xff, 255),
	restart(),
	end(),
};

u8 target0e[] = {
	start(),
	go_to_pad(0x06, 0xff, 255),
	restart(),
	end(),
};

u8 target0f[] = {
	start(),
	go_to_pad(0x07, 0xff, 255),
	restart(),
	end(),
};

u8 target10[] = {
	start(),
	go_to_pad(0x08, 0xff, 255),
	restart(),
	end(),
};

u8 target11[] = {
	start(),
	go_to_pad(0x09, 0xff, 255),
	restart(),
	end(),
};

u8 target12[] = {
	start(),
	go_to_pad(0x0a, 0xff, 255),
	restart(),
	end(),
};

u8 target13[] = {
	start(),
	go_to_pad(0x0b, 0xff, 255),
	restart(),
	end(),
};

u8 target14[] = {
	start(),
	go_to_pad(0x0c, 0xff, 255),
	restart(),
	end(),
};

u8 target15[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	go_to_pad(0x07, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 2),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 2),
	go_to_pad(0x09, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 2),
	go_to_pad(0x05, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 2),
	restart(),
	end(),
};

u8 target16[] = {
	start(),
	go_to_pad(0x05, 0xff, 0),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 2),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 2),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x09, 0xc8, 2),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x05, 0xc8, 2),
	restart(),
	end(),
};

u8 target17[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	go_to_pad(0x05, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 2),
	go_to_pad(0x07, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 2),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 2),
	go_to_pad(0x09, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 2),
	restart(),
	end(),
};

u8 target18[] = {
	start(),
	go_to_pad(0x07, 0xff, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 2),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x09, 0xc8, 2),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x05, 0xc8, 2),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 2),
	restart(),
	end(),
};

u8 target19[] = {
	start(),
	go_to_pad(0x09, 0xff, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x05, 0xc8, 2),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 2),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 2),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x09, 0xc8, 2),
	restart(),
	end(),
};

u8 target1a[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 2),
	go_to_pad(0x09, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 2),
	go_to_pad(0x05, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 2),
	go_to_pad(0x07, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 2),
	restart(),
	end(),
};

u8 target1b[] = {
	start(),
	go_to_pad(0x0b, 0xff, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x09, 0xc8, 2),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x05, 0xc8, 2),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 2),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 2),
	restart(),
	end(),
};

u8 target1c[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x09, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 2),
	go_to_pad(0x05, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 2),
	go_to_pad(0x07, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 2),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 2),
	restart(),
	end(),
};

u8 target1d[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	go_to_pad(0x06, 0xc8, 2),
	go_to_pad(0x04, 0xc8, 2),
	restart(),
	end(),
};

u8 target1e[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	go_to_pad(0x04, 0xc8, 2),
	go_to_pad(0x06, 0xc8, 2),
	restart(),
	end(),
};

u8 target1f[] = {
	start(),
	go_to_pad(0x07, 0xff, 0),
	go_to_pad(0x09, 0xc8, 2),
	go_to_pad(0x07, 0xc8, 2),
	restart(),
	end(),
};

u8 target20[] = {
	start(),
	go_to_pad(0x09, 0xff, 0),
	go_to_pad(0x07, 0xc8, 2),
	go_to_pad(0x09, 0xc8, 2),
	restart(),
	end(),
};

u8 target21[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	go_to_pad(0x0c, 0xc8, 2),
	go_to_pad(0x0a, 0xc8, 2),
	restart(),
	end(),
};

u8 target22[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x0a, 0xc8, 2),
	go_to_pad(0x0c, 0xc8, 2),
	restart(),
	end(),
};

u8 target23[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 0),
	go_to_pad(0x08, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	restart(),
	end(),
};

u8 target24[] = {
	start(),
	go_to_pad(0x07, 0xff, 0),
	go_to_pad(0x08, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 0),
	restart(),
	end(),
};

u8 target25[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x07, 0xc8, 0),
	go_to_pad(0x08, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	restart(),
	end(),
};

u8 target26[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x04, 0x1e, 0),
	restart(),
	end(),
};

u8 target27[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x04, 0x1e, 0),
	go_to_pad(0x0a, 0xc8, 0),
	restart(),
	end(),
};

u8 target28[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x04, 0x1e, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	restart(),
	end(),
};

u8 target29[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target2a[] = {
	start(),
	go_to_pad(0x05, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target2b[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target2c[] = {
	start(),
	go_to_pad(0x07, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target2d[] = {
	start(),
	go_to_pad(0x08, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target2e[] = {
	start(),
	go_to_pad(0x09, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target2f[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target30[] = {
	start(),
	go_to_pad(0x0b, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target31[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target32[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target33[] = {
	start(),
	go_to_pad(0x05, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target34[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target35[] = {
	start(),
	go_to_pad(0x07, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target36[] = {
	start(),
	go_to_pad(0x08, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target37[] = {
	start(),
	go_to_pad(0x09, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target38[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target39[] = {
	start(),
	go_to_pad(0x0b, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target3a[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target3b[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x0a, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	go_to_pad(0x0c, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	restart(),
	end(),
};

u8 target3c[] = {
	start(),
	go_to_pad(0x09, 0xff, 0),
	go_to_pad(0x07, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	go_to_pad(0x09, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	restart(),
	end(),
};

u8 target3d[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	go_to_pad(0x04, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	go_to_pad(0x06, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	restart(),
	end(),
};

u8 target3e[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	rotate(1, 1),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target3f[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	rotate(1, 1),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target40[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	rotate(1, 1),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target41[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	rotate(1, 1),
	go_to_pad(0x04, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(1),
	restart(),
	end(),
};

u8 target42[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x0a, 0xc8, 0),
	restart(),
	end(),
};

u8 target43[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x0c, 0x64, 0),
	go_to_pad(0x0a, 0x64, 0),
	go_to_pad(0x0a, 0x64, 0),
	go_to_pad(0x0c, 0x64, 0),
	restart(),
	end(),
};

u8 target44[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	rotate(1, 0),
	go_to_pad(0x04, 0x64, 0),
	go_to_pad(0x06, 0x64, 0),
	go_to_pad(0x06, 0x64, 0),
	go_to_pad(0x04, 0x64, 0),
	rotate(1, 0),
	restart(),
	end(),
};

u8 target45[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	go_to_pad(0x0a, 0xc8, 0),
	go_to_pad(0x04, 0xc8, 0),
	restart(),
	end(),
};

u8 target46[] = {
	start(),
	go_to_pad(0x0b, 0xff, 0),
	go_to_pad(0x05, 0xc8, 0),
	go_to_pad(0x0b, 0xc8, 0),
	restart(),
	end(),
};

u8 target47[] = {
	start(),
	go_to_pad(0x06, 0xff, 0),
	go_to_pad(0x0c, 0xc8, 0),
	go_to_pad(0x06, 0xc8, 0),
	restart(),
	end(),
};

u8 target48[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	rotate(1, 1),
	go_to_pad(0x0a, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	rotate(1, 1),
	go_to_pad(0x0c, 0xc8, 0),
	rotate(1, 1),
	cmd_0e(2),
	restart(),
	end(),
};

u8 target49[] = {
	start(),
	go_to_pad(0x04, 0xff, 0),
	go_to_pad(0x0a, 0x64, 0),
	go_to_pad(0x0c, 0x1e, 0),
	go_to_pad(0x06, 0x64, 0),
	go_to_pad(0x04, 0x64, 0),
	restart(),
	end(),
};

u8 target4a[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	go_to_pad(0x0c, 0x1e, 0),
	go_to_pad(0x06, 0x64, 0),
	go_to_pad(0x04, 0x64, 0),
	go_to_pad(0x0a, 0x64, 0),
	restart(),
	end(),
};

u8 target4b[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	go_to_pad(0x06, 0x64, 0),
	go_to_pad(0x04, 0x64, 0),
	go_to_pad(0x0a, 0x64, 0),
	go_to_pad(0x0c, 0x1e, 0),
	restart(),
	end(),
};

u8 target4c[] = {
	start(),
	go_to_pad(0x0a, 0xff, 0),
	rotate(1, 0),
	cmd_0e(255),
	rotate(1, 0),
	restart(),
	end(),
};

u8 target4d[] = {
	start(),
	go_to_pad(0x0b, 0xff, 0),
	rotate(1, 0),
	cmd_0e(255),
	rotate(1, 0),
	restart(),
	end(),
};

u8 target4e[] = {
	start(),
	go_to_pad(0x0c, 0xff, 0),
	rotate(1, 0),
	cmd_0e(255),
	rotate(1, 0),
	restart(),
	end(),
};

u8 help00[] = {
	start(),
	if_bronze(),
		hudmsg(0),
		wait_until_shoot(),
		hudmsg(1),
	if_silver(),
		hudmsg(5),
	if_gold(),
		hudmsg(8),
	end(),
};

u8 help01[] = {
	start(),
	if_bronze(),
		hudmsg(6),
	if_silver(),
		hudmsg(2),
		wait_until_shoot(),
	if_gold(),
	end(),
};

u8 help02[] = {
	start(),
	if_bronze(),
		hudmsg(7),
	if_silver(),
		hudmsg(3),
		hudmsg(4),
	if_gold(),
	end(),
};

