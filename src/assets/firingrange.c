#include <ultra64.h>
#include "constants.h"
#include "firingrange/frcommands.h"
#include "bss.h"
#include "types.h"

#if NTSC
u16 texts[] = {
	/*0*/ L_MISC_281, // "FIRING\n Press Z Button to fire gun.\n"
	/*1*/ L_MISC_282, // "AUTO RELOAD\n Release Z Button when out of ammo.\n"
	/*2*/ L_MISC_283, // "MANUAL RELOAD\n Press B Button to reload early if magazine not full.\n"
	/*3*/ L_MISC_284, // "Aiming: Hold down R Button to enter Aim mode.\n"
	/*4*/ L_MISC_285, // "Use Control Stick to move aiming sight.\n"
	/*5*/ L_MISC_286, // "AUTO FIRE\n Hold Z Button to repeatedly fire automatically.\n"
	/*6*/ L_MISC_287, // "ALTER AIM\n Press Up C Button or Down C Button to move sight up/down.\n"
	/*7*/ L_MISC_288, // "ZOOM\n Hold R Button to enter Zoom mode.\n"
	/*8*/ L_MISC_289, // "FAST FIRE\n Press Z Button quickly to fire faster.\n"
};
#else
u16 texts[] = {
	/*0*/ L_DISH_187,
	/*1*/ L_DISH_188,
	/*2*/ L_DISH_189,
	/*3*/ L_DISH_190,
	/*4*/ L_DISH_191,
	/*5*/ L_DISH_192,
	/*6*/ L_DISH_193,
	/*7*/ L_DISH_194,
	/*8*/ L_DISH_195,
};
#endif

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
	set_pad_index_offset(0),
	add_target(0, 0x12, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 8, FRTARGETFLAG_BRONZE),
	add_target(2, 0x14, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0f, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 8, FRTARGETFLAG_BRONZE),
	add_target(2, 0x11, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0c, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3b, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x3c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x3d, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x23, 8, FRTARGETFLAG_GOLD),
	add_target(0, 0x24, 8, FRTARGETFLAG_GOLD),
	add_target(0, 0x25, 8, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(0),
	set_goal_accuracy(0, 80, 0),
	add_target(1, 0x0c, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0c, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0c, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x26, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x27, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x28, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x1d, 8, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(0),
	set_goal_targets(255, 9, 3),
	add_target(1, 0x2f, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x30, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x31, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2e, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2c, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2b, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2a, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x29, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x32, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x33, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x34, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x35, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x36, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x37, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x38, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x39, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x3a, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x3b, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3c, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3d, 12, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_magsec4[] = {
	start(),
	set_max_active_targets(1, 7, 4),
	set_goal_score(135, 135, 80),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 18, 255),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(0),
	set_goal_targets(255, 255, 4),
	add_target(1, 0x2b, 9, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2a, 9, FRTARGETFLAG_BRONZE),
	add_target(1, 0x29, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x42, 255, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x32, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x33, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x34, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x35, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x36, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x37, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x3e, 3, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x41, 3, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x40, 3, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x3f, 3, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_mauler[] = {
	start(),
	set_max_active_targets(1, 8, 6),
	set_goal_score(200, 0, 0),
	set_time_limit(255, 255, 15),
	set_ammo_limit(255, 50, 35),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(0),
	set_goal_targets(255, 8, 6),
	add_target(1, 0x45, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x46, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x47, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x46, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x45, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x47, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x47, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x45, 20, FRTARGETFLAG_BRONZE),
	add_target(1, 0x46, 20, FRTARGETFLAG_BRONZE),
	add_target(0, 0x15, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x16, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x17, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x18, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x19, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x1a, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x1b, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x1c, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x35, 5, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x36, 5, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x37, 5, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x38, 5, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x39, 5, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x3a, 5, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_phoenix[] = {
	start(),
	set_max_active_targets(2, 3, 6),
	set_goal_score(90, 0, 0),
	set_time_limit(255, 255, 20),
	set_ammo_limit(255, 18, 3),
	set_extra_speed(2, 0.5, 2.5),
	set_pad_index_offset(9),
	set_goal_targets(255, 8, 6),
	add_target(0, 0x3e, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x40, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x41, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3f, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3e, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x40, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x41, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3f, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3b, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3c, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3d, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3b, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3c, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3d, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3b, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3c, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x3d, 12, FRTARGETFLAG_SILVER | FRTARGETFLAG_TMPINVINCIBLE),
	add_target(0, 0x22, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x21, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x20, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1f, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1d, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1e, 1, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_dy357magnum[] = {
	start(),
	set_max_active_targets(1, 9, 9),
	set_goal_score(90, 80, 50),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 3, 5),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(0),
	add_target(0, 0x38, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x39, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3a, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x39, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x38, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3a, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3a, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x39, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x38, 6, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0c, 1, FRTARGETFLAG_SILVER),
	add_target(1, 0x0d, 1, FRTARGETFLAG_SILVER),
	add_target(2, 0x0e, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 1, FRTARGETFLAG_SILVER),
	add_target(1, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(2, 0x11, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 1, FRTARGETFLAG_SILVER),
	add_target(1, 0x13, 1, FRTARGETFLAG_SILVER),
	add_target(2, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x32, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2a, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2b, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2c, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x36, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2e, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x38, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x30, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x3a, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_dy357lx[] = {
	start(),
	set_max_active_targets(1, 3, 1),
	set_goal_score(90, 200, 100),
	set_time_limit(255, 30, 50),
	set_ammo_limit(255, 255, 12),
	set_extra_speed(0, 1, 0.5),
	set_pad_index_offset(0),
	add_target(0, 0x15, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x16, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x17, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x18, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x19, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1a, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1b, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1c, 6, FRTARGETFLAG_BRONZE),
	add_target(0, 0x22, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x21, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x20, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x1f, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x1d, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x1e, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x22, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x3b, 12, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 4, 6),
	add_target(0, 0x3a, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x39, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x38, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x37, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x36, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x35, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x34, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x33, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x32, 32, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3e, 12, FRTARGETFLAG_SILVER),
	add_target(0, 0x40, 12, FRTARGETFLAG_SILVER),
	add_target(0, 0x41, 12, FRTARGETFLAG_SILVER),
	add_target(0, 0x3f, 12, FRTARGETFLAG_SILVER),
	add_target(0, 0x26, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x27, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x28, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x26, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x27, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x28, 12, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 5, 1),
	add_target(1, 0x12, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x14, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x11, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0f, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x45, 25, FRTARGETFLAG_SILVER),
	add_target(1, 0x46, 25, FRTARGETFLAG_SILVER),
	add_target(1, 0x47, 25, FRTARGETFLAG_SILVER),
	add_target(1, 0x45, 25, FRTARGETFLAG_SILVER),
	add_target(1, 0x46, 25, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 250, FRTARGETFLAG_GOLD),
	add_target(0, 0x42, 25, FRTARGETFLAG_GOLD),
	add_target(0, 0x43, 25, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 1, 2),
	add_target(1, 0x0f, 32, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 32, FRTARGETFLAG_BRONZE),
	add_target(1, 0x11, 32, FRTARGETFLAG_BRONZE),
	add_target(1, 0x12, 32, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 32, FRTARGETFLAG_BRONZE),
	add_target(1, 0x14, 32, FRTARGETFLAG_BRONZE),
	add_target(1, 0x4c, 255, FRTARGETFLAG_SILVER),
	add_target(1, 0x4d, 255, FRTARGETFLAG_SILVER),
	add_target(1, 0x4e, 255, FRTARGETFLAG_SILVER),
	add_target(0, 0x1f, 40, FRTARGETFLAG_SILVER),
	add_target(0, 0x32, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x2a, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x2b, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x2c, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x36, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x2e, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x38, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x30, 20, FRTARGETFLAG_GOLD),
	add_target(0, 0x3a, 20, FRTARGETFLAG_GOLD),
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

	set_pad_index_offset(9),
	set_goal_targets(255, 255, 9),
	add_target(1, 0x07, 255, FRTARGETFLAG_BRONZE),
	add_target(0, 0x14, 20, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0, 0x13, 20, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0, 0x12, 20, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0, 0x14, 4, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0, 0x13, 4, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0, 0x12, 4, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY | FRTARGETFLAG_ROTATEONCLOAK),
	add_target(0, 0x11, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x10, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x0f, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x0e, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x0d, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x0c, 10, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 3, 2),
	add_target(1, 0x0f, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 50, FRTARGETFLAG_BRONZE),
	add_target(2, 0x11, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x12, 50, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 50, FRTARGETFLAG_BRONZE),
	add_target(2, 0x14, 50, FRTARGETFLAG_BRONZE),
	add_target(0, 0x12, 30, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x13, 30, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x14, 30, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x49, 50, FRTARGETFLAG_GOLD),
	add_target(0, 0x4a, 50, FRTARGETFLAG_GOLD),
	add_target(0, 0x4b, 50, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 1, 255),
	set_goal_accuracy(0, 0, 90),
	add_target(0, 0x31, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x30, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x2f, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x2e, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x2d, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x2c, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x2b, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x2a, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x29, 30, FRTARGETFLAG_BRONZE),
	add_target(1, 0x45, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x42, 255, FRTARGETFLAG_GOLD),
	add_target(0, 0x43, 255, FRTARGETFLAG_GOLD),
	add_target(0, 0x2c, 30, FRTARGETFLAG_GOLD),
	add_target(0, 0x36, 30, FRTARGETFLAG_GOLD),
	add_target(0, 0x2e, 30, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 4, 3),
	add_target(1, 0x0c, 25, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0d, 25, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 25, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0c, 255, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 255, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0, 0x0e, 255, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 255, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0, 0x10, 255, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 255, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0, 0x12, 255, FRTARGETFLAG_SILVER),
	add_target(0, 0x13, 255, FRTARGETFLAG_SILVER | FRTARGETFLAG_ONEHITEXPLODE),
	add_target(0, 0x14, 255, FRTARGETFLAG_SILVER),
	add_target(0, 0x2b, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x33, 10, FRTARGETFLAG_GOLD),
	add_target(0, 0x29, 10, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 9, 255),
	set_goal_accuracy(0, 0, 100),
	add_target(1, 0x45, 30, FRTARGETFLAG_BRONZE),
	add_target(1, 0x46, 30, FRTARGETFLAG_BRONZE),
	add_target(1, 0x47, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x26, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x27, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x28, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x26, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x27, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x28, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x26, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x27, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x28, 10, FRTARGETFLAG_SILVER),
	add_target(0, 0x1d, 255, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	set_goal_targets(255, 9, 5),
	add_target(0, 0x22, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x21, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x20, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1f, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1d, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1e, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x22, 30, FRTARGETFLAG_BRONZE),
	add_target(0, 0x29, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x2a, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x2b, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x2c, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x2d, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x2e, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x2f, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x30, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x31, 20, FRTARGETFLAG_SILVER),
	add_target(0, 0x3e, 30, FRTARGETFLAG_GOLD),
	add_target(0, 0x3f, 30, FRTARGETFLAG_GOLD),
	add_target(0, 0x41, 30, FRTARGETFLAG_GOLD),
	add_target(0, 0x40, 30, FRTARGETFLAG_GOLD),
	add_target(0, 0x10, 10, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_shotgun[] = {
	start(),
	set_max_active_targets(1, 3, 1),
	set_goal_score(240, 0, 170),
	set_time_limit(255, 30, 20),
	set_ammo_limit(255, 255, 30),
	set_extra_speed(0, 0.5, 0.8),
	set_pad_index_offset(0),
	set_goal_targets(255, 9, 255),
	set_score_multiplier(0, 0, 5),
	add_target(0, 0x14, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x12, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x11, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0f, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x13, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x10, 9, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3b, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3c, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3d, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3b, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3c, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3d, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3b, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3c, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3d, 4, FRTARGETFLAG_SILVER),
	add_target(0, 0x3b, 250, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_sniperrifle[] = {
	start(),
	set_max_active_targets(3, 3, 3),
	set_goal_score(120, 120, 150),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 255, 15),
	set_extra_speed(0, 1, 6),
	set_pad_index_offset(18),
	set_goal_accuracy(0, 90, 0),
	add_target(1, 0x0c, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x29, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x2a, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x2b, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x2c, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x2f, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x2e, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x2d, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x30, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x31, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x45, 5, FRTARGETFLAG_GOLD),
	add_target(1, 0x46, 5, FRTARGETFLAG_GOLD),
	add_target(1, 0x47, 5, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_farsightxr20[] = {
	start(),
	set_max_active_targets(3, 9, 6),
	set_goal_score(0, 0, 40),
	set_time_limit(255, 15, 20),
	set_ammo_limit(255, 255, 3),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(18),
	set_goal_targets(3, 6, 6),
	add_target(1, 0x0c, 3, FRTARGETFLAG_BRONZE | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x10, 3, FRTARGETFLAG_BRONZE | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x14, 3, FRTARGETFLAG_BRONZE | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x29, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x2a, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x2b, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x2c, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x2d, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x2e, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x12, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(1, 0x13, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(1, 0x14, 1, FRTARGETFLAG_SILVER | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(1, 0x0c, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x12, 1, FRTARGETFLAG_GOLD),
	add_target(1, 0x0e, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	add_target(1, 0x14, 1, FRTARGETFLAG_GOLD),
	add_target(1, 0x10, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1f, 1, FRTARGETFLAG_GOLD | FRTARGETFLAG_FARSIGHTAUTOTARGETABLE),
	end(),
};

u8 weapon_crossbow[] = {
	start(),
	set_max_active_targets(3, 3, 1),
	set_score_multiplier(0, 0, 1),

#if VERSION < VERSION_NTSC_1_0
	set_goal_score(72, 90, 200),
#else
	set_goal_score(72, 90, 150),
#endif

	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 20, 255),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(0),
	add_target(1, 0x12, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x14, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0c, 250, FRTARGETFLAG_SILVER),
	add_target(1, 0x0d, 250, FRTARGETFLAG_SILVER),
	add_target(1, 0x0e, 250, FRTARGETFLAG_SILVER),
	add_target(0, 0x48, 255, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_tranquilizer[] = {
	start(),
	set_max_active_targets(8, 3, 1),
	set_goal_score(120, 250, 0),
	set_time_limit(255, 20, 15),
	set_ammo_limit(255, 255, 18),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(0),
	set_goal_targets(255, 255, 18),
	add_target(0, 0x15, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x16, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x17, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x18, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x19, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1a, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1b, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x1c, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x38, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x3a, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x39, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x35, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x36, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x37, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x38, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x39, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x3a, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x13, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x11, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0d, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0e, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x10, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0c, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0f, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x14, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x12, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x14, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x12, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x10, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0f, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0d, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0c, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x0e, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x11, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x13, 1, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(0),
	set_goal_targets(255, 18, 1),
	add_target(1, 0x2f, 100, FRTARGETFLAG_BRONZE),
	add_target(1, 0x30, 100, FRTARGETFLAG_BRONZE),
	add_target(1, 0x31, 100, FRTARGETFLAG_BRONZE),
	add_target(0, 0x13, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0e, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0e, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x13, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x49, 100, FRTARGETFLAG_GOLD),
	add_target(0, 0x4a, 100, FRTARGETFLAG_GOLD),
	add_target(0, 0x4b, 100, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_devastator[] = {
	start(),
	set_max_active_targets(3, 6, 1),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 50, 30),
	set_ammo_limit(255, 10, 6),
	set_extra_speed(0, 10, 3),
	set_pad_index_offset(18),
	set_goal_targets(6, 6, 6),
	add_target(0, 0x12, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x10, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x13, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x11, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x14, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0f, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0e, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x45, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x46, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x47, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x2c, 8, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2f, 8, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2d, 8, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x31, 8, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x2e, 8, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	add_target(0, 0x30, 8, FRTARGETFLAG_GOLD | FRTARGETFLAG_SPAWNFACINGAWAY),
	end(),
};

u8 weapon_rocketlauncher[] = {
	start(),
	set_max_active_targets(9, 8, 4),
	set_goal_score(0, 0, 40),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 18, 4),
	set_extra_speed(0, 4, 9),
	set_pad_index_offset(18),
	set_goal_targets(9, 8, 4),
	add_target(0, 0x0c, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0d, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0e, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0f, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x10, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x11, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x12, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x13, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x14, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x15, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x16, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x17, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x18, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x19, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x1a, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x1b, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x1c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x3e, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x3f, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x41, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x40, 3, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_slayer[] = {
	start(),
	set_max_active_targets(1, 4, 3),
	set_goal_score(0, 40, 60),
	set_time_limit(255, 255, 40),
	set_ammo_limit(255, 6, 8),
	set_extra_speed(0, 5, 3),
	set_pad_index_offset(18),
	set_goal_targets(6, 4, 6),
	add_target(1, 0x31, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x29, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2b, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2d, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x2f, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x15, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x17, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x1a, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x1c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x3b, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3c, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3d, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3b, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3c, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3d, 12, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_combatknife[] = {
	start(),
	set_max_active_targets(1, 3, 8),
	set_goal_score(72, 90, 80),
	set_time_limit(255, 255, 30),
	set_ammo_limit(255, 18, 255),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(0),
	set_goal_targets(255, 255, 8),
	add_target(1, 0x12, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x14, 250, FRTARGETFLAG_BRONZE),
	add_target(0, 0x38, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x3a, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x39, 6, FRTARGETFLAG_SILVER),
	add_target(0, 0x15, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x16, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x17, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x18, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x19, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1a, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1b, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1c, 1, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_laser[] = {
	start(),
	set_max_active_targets(3, 1, 3),
	set_goal_score(250, 180, 250),
	set_time_limit(255, 20, 20),
	set_ammo_limit(255, 255, 255),
	set_extra_speed(0, 0.1, 0.7),
	set_pad_index_offset(0),
	set_goal_targets(255, 255, 255),
	set_goal_accuracy(0, 80, 100),
	add_target(1, 0x12, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 250, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3b, 255, FRTARGETFLAG_SILVER),
	add_target(1, 0x45, 12, FRTARGETFLAG_GOLD),
	add_target(1, 0x46, 12, FRTARGETFLAG_GOLD),
	add_target(1, 0x47, 12, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_grenade[] = {
	start(),
	set_max_active_targets(1, 3, 1),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 30, 30),
	set_ammo_limit(255, 255, 6),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(9),
	set_goal_targets(3, 18, 4),
	add_target(1, 0x12, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x14, 250, FRTARGETFLAG_BRONZE),
	add_target(0, 0x13, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x13, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x3e, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x3f, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x41, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x40, 3, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_1e[] = {
	start(),
	set_max_active_targets(3, 9, 4),
	set_goal_score(72, 90, 80),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 18, 255),
	set_extra_speed(0, 1, 3),
	set_pad_index_offset(9),
	add_target(1, 0x12, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x10, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x0e, 250, FRTARGETFLAG_BRONZE),
	add_target(0, 0x13, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0e, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0c, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x14, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x12, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x10, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0c, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x0e, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x11, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x13, 1, FRTARGETFLAG_SILVER),
	add_target(0, 0x3e, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x3f, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x41, 3, FRTARGETFLAG_GOLD),
	add_target(0, 0x40, 3, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_timedmine[] = {
	start(),
	set_max_active_targets(3, 6, 6),
	set_goal_score(0, 0, 60),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 6, 1),
	set_extra_speed(0, 10, 3),
	set_pad_index_offset(9),
	set_goal_targets(3, 6, 6),
	add_target(1, 0x2f, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x30, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x31, 8, FRTARGETFLAG_BRONZE),
	add_target(0, 0x0c, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0d, 8, FRTARGETFLAG_SILVER),
	add_target(0, 0x0e, 8, FRTARGETFLAG_SILVER),
	add_target(1, 0x45, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x46, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x47, 5, FRTARGETFLAG_SILVER),
	add_target(0, 0x0f, 8, FRTARGETFLAG_GOLD),
	add_target(0, 0x10, 8, FRTARGETFLAG_GOLD),
	add_target(0, 0x11, 8, FRTARGETFLAG_GOLD),
	add_target(1, 0x45, 5, FRTARGETFLAG_GOLD),
	add_target(1, 0x46, 5, FRTARGETFLAG_GOLD),
	add_target(1, 0x47, 5, FRTARGETFLAG_GOLD),
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
	set_pad_index_offset(9),
	add_target(1, 0x12, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x14, 8, FRTARGETFLAG_BRONZE),
	add_target(1, 0x45, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x46, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x47, 5, FRTARGETFLAG_SILVER),
	add_target(1, 0x45, 5, FRTARGETFLAG_GOLD),
	add_target(1, 0x46, 5, FRTARGETFLAG_GOLD),
	add_target(1, 0x47, 5, FRTARGETFLAG_GOLD),
	add_target(0, 0x3b, 12, FRTARGETFLAG_GOLD),
	add_target(0, 0x3c, 12, FRTARGETFLAG_GOLD),
	end(),
};

u8 weapon_remotemine[] = {
	start(),
	set_max_active_targets(3, 4, 7),
	set_goal_score(0, 0, 0),
	set_time_limit(255, 255, 12),
	set_ammo_limit(255, 4, 2),
	set_extra_speed(0, 5, 3),
	set_pad_index_offset(0),
	set_goal_targets(3, 4, 7),
	add_target(1, 0x14, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x13, 250, FRTARGETFLAG_BRONZE),
	add_target(1, 0x12, 250, FRTARGETFLAG_BRONZE),
	add_target(0, 0x3e, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x3f, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x41, 3, FRTARGETFLAG_SILVER),
	add_target(0, 0x40, 3, FRTARGETFLAG_SILVER),
	add_target(1, 0x10, 250, FRTARGETFLAG_GOLD),
	add_target(0, 0x22, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x21, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x20, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1f, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1d, 1, FRTARGETFLAG_GOLD),
	add_target(0, 0x1e, 1, FRTARGETFLAG_GOLD),
	end(),
};

u8 target00[] = {
	start(),
	go_to_pad(4, 255, 255),
	end(),
};

u8 target01[] = {
	start(),
	go_to_pad(5, 255, 255),
	end(),
};

u8 target02[] = {
	start(),
	go_to_pad(6, 255, 255),
	end(),
};

u8 target03[] = {
	start(),
	go_to_pad(7, 255, 255),
	end(),
};

u8 target04[] = {
	start(),
	go_to_pad(8, 255, 255),
	end(),
};

u8 target05[] = {
	start(),
	go_to_pad(9, 255, 255),
	end(),
};

u8 target06[] = {
	start(),
	go_to_pad(10, 255, 255),
	end(),
};

u8 target07[] = {
	start(),
	go_to_pad(11, 255, 255),
	end(),
};

u8 target08[] = {
	start(),
	go_to_pad(12, 255, 255),
	end(),
};

u8 target09[] = {
	start(),
	go_to_pad(11, 255, 0),
	wait_seconds(2),
	rotate(FRROTATE_90L, 4),
	wait_seconds(2),
	rotate(FRROTATE_90R, 4),
	wait_seconds(2),
	rotate(FRROTATE_180R, 8),
	wait_seconds(2),
	rotate(FRROTATE_180L, 8),
	wait_seconds(255),
	end(),
};

u8 target0a[] = {
	start(),
	go_to_pad(2, 30, 255),
	go_to_pad(0, 30, 255),
	restart(),
	end(),
};

u8 target0b[] = {
	start(),
	go_to_pad(1, 30, 255),
	go_to_pad(3, 30, 255),
	restart(),
	end(),
};

u8 target0c[] = {
	start(),
	go_to_pad(4, 255, 255),
	restart(),
	end(),
};

u8 target0d[] = {
	start(),
	go_to_pad(5, 255, 255),
	restart(),
	end(),
};

u8 target0e[] = {
	start(),
	go_to_pad(6, 255, 255),
	restart(),
	end(),
};

u8 target0f[] = {
	start(),
	go_to_pad(7, 255, 255),
	restart(),
	end(),
};

u8 target10[] = {
	start(),
	go_to_pad(8, 255, 255),
	restart(),
	end(),
};

u8 target11[] = {
	start(),
	go_to_pad(9, 255, 255),
	restart(),
	end(),
};

u8 target12[] = {
	start(),
	go_to_pad(10, 255, 255),
	restart(),
	end(),
};

u8 target13[] = {
	start(),
	go_to_pad(11, 255, 255),
	restart(),
	end(),
};

u8 target14[] = {
	start(),
	go_to_pad(12, 255, 255),
	restart(),
	end(),
};

u8 target15[] = {
	start(),
	go_to_pad(4, 255, 0),
	go_to_pad(7, 200, 0),
	go_to_pad(10, 200, 2),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 2),
	go_to_pad(9, 200, 0),
	go_to_pad(6, 200, 2),
	go_to_pad(5, 200, 0),
	go_to_pad(4, 200, 2),
	restart(),
	end(),
};

u8 target16[] = {
	start(),
	go_to_pad(5, 255, 0),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 2),
	go_to_pad(10, 200, 0),
	go_to_pad(11, 200, 2),
	go_to_pad(12, 200, 0),
	go_to_pad(9, 200, 2),
	go_to_pad(6, 200, 0),
	go_to_pad(5, 200, 2),
	restart(),
	end(),
};

u8 target17[] = {
	start(),
	go_to_pad(6, 255, 0),
	go_to_pad(5, 200, 0),
	go_to_pad(4, 200, 2),
	go_to_pad(7, 200, 0),
	go_to_pad(10, 200, 2),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 2),
	go_to_pad(9, 200, 0),
	go_to_pad(6, 200, 2),
	restart(),
	end(),
};

u8 target18[] = {
	start(),
	go_to_pad(7, 255, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(11, 200, 2),
	go_to_pad(12, 200, 0),
	go_to_pad(9, 200, 2),
	go_to_pad(6, 200, 0),
	go_to_pad(5, 200, 2),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 2),
	restart(),
	end(),
};

u8 target19[] = {
	start(),
	go_to_pad(9, 255, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(5, 200, 2),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 2),
	go_to_pad(10, 200, 0),
	go_to_pad(11, 200, 2),
	go_to_pad(12, 200, 0),
	go_to_pad(9, 200, 2),
	restart(),
	end(),
};

u8 target1a[] = {
	start(),
	go_to_pad(10, 255, 0),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 2),
	go_to_pad(9, 200, 0),
	go_to_pad(6, 200, 2),
	go_to_pad(5, 200, 0),
	go_to_pad(4, 200, 2),
	go_to_pad(7, 200, 0),
	go_to_pad(10, 200, 2),
	restart(),
	end(),
};

u8 target1b[] = {
	start(),
	go_to_pad(11, 255, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(9, 200, 2),
	go_to_pad(6, 200, 0),
	go_to_pad(5, 200, 2),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 2),
	go_to_pad(10, 200, 0),
	go_to_pad(11, 200, 2),
	restart(),
	end(),
};

u8 target1c[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(9, 200, 0),
	go_to_pad(6, 200, 2),
	go_to_pad(5, 200, 0),
	go_to_pad(4, 200, 2),
	go_to_pad(7, 200, 0),
	go_to_pad(10, 200, 2),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 2),
	restart(),
	end(),
};

u8 target1d[] = {
	start(),
	go_to_pad(4, 255, 0),
	go_to_pad(6, 200, 2),
	go_to_pad(4, 200, 2),
	restart(),
	end(),
};

u8 target1e[] = {
	start(),
	go_to_pad(6, 255, 0),
	go_to_pad(4, 200, 2),
	go_to_pad(6, 200, 2),
	restart(),
	end(),
};

u8 target1f[] = {
	start(),
	go_to_pad(7, 255, 0),
	go_to_pad(9, 200, 2),
	go_to_pad(7, 200, 2),
	restart(),
	end(),
};

u8 target20[] = {
	start(),
	go_to_pad(9, 255, 0),
	go_to_pad(7, 200, 2),
	go_to_pad(9, 200, 2),
	restart(),
	end(),
};

u8 target21[] = {
	start(),
	go_to_pad(10, 255, 0),
	go_to_pad(12, 200, 2),
	go_to_pad(10, 200, 2),
	restart(),
	end(),
};

u8 target22[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(10, 200, 2),
	go_to_pad(12, 200, 2),
	restart(),
	end(),
};

u8 target23[] = {
	start(),
	go_to_pad(6, 255, 0),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 0),
	go_to_pad(8, 200, 0),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(6, 200, 0),
	restart(),
	end(),
};

u8 target24[] = {
	start(),
	go_to_pad(7, 255, 0),
	go_to_pad(8, 200, 0),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 0),
	restart(),
	end(),
};

u8 target25[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(4, 200, 0),
	go_to_pad(7, 200, 0),
	go_to_pad(8, 200, 0),
	go_to_pad(11, 200, 0),
	go_to_pad(12, 200, 0),
	restart(),
	end(),
};

u8 target26[] = {
	start(),
	go_to_pad(4, 255, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(4, 30, 0),
	restart(),
	end(),
};

u8 target27[] = {
	start(),
	go_to_pad(10, 255, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(4, 30, 0),
	go_to_pad(10, 200, 0),
	restart(),
	end(),
};

u8 target28[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(4, 30, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(12, 200, 0),
	restart(),
	end(),
};

u8 target29[] = {
	start(),
	go_to_pad(4, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target2a[] = {
	start(),
	go_to_pad(5, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target2b[] = {
	start(),
	go_to_pad(6, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target2c[] = {
	start(),
	go_to_pad(7, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target2d[] = {
	start(),
	go_to_pad(8, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target2e[] = {
	start(),
	go_to_pad(9, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target2f[] = {
	start(),
	go_to_pad(10, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target30[] = {
	start(),
	go_to_pad(11, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target31[] = {
	start(),
	go_to_pad(12, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target32[] = {
	start(),
	go_to_pad(4, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target33[] = {
	start(),
	go_to_pad(5, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target34[] = {
	start(),
	go_to_pad(6, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target35[] = {
	start(),
	go_to_pad(7, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target36[] = {
	start(),
	go_to_pad(8, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target37[] = {
	start(),
	go_to_pad(9, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target38[] = {
	start(),
	go_to_pad(10, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target39[] = {
	start(),
	go_to_pad(11, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target3a[] = {
	start(),
	go_to_pad(12, 255, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target3b[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(10, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	go_to_pad(12, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	restart(),
	end(),
};

u8 target3c[] = {
	start(),
	go_to_pad(9, 255, 0),
	go_to_pad(7, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	go_to_pad(9, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	restart(),
	end(),
};

u8 target3d[] = {
	start(),
	go_to_pad(6, 255, 0),
	go_to_pad(4, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	go_to_pad(6, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	restart(),
	end(),
};

u8 target3e[] = {
	start(),
	go_to_pad(4, 255, 0),
	rotate(FRROTATE_180R, 1),
	go_to_pad(6, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(4, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target3f[] = {
	start(),
	go_to_pad(6, 255, 0),
	rotate(FRROTATE_180R, 1),
	go_to_pad(12, 200, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(4, 200, 0),
	go_to_pad(6, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target40[] = {
	start(),
	go_to_pad(12, 255, 0),
	rotate(FRROTATE_180R, 1),
	go_to_pad(10, 200, 0),
	go_to_pad(4, 200, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(12, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target41[] = {
	start(),
	go_to_pad(10, 255, 0),
	rotate(FRROTATE_180R, 1),
	go_to_pad(4, 200, 0),
	go_to_pad(6, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(10, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(1),
	restart(),
	end(),
};

u8 target42[] = {
	start(),
	go_to_pad(10, 255, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(10, 200, 0),
	restart(),
	end(),
};

u8 target43[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(12, 100, 0),
	go_to_pad(10, 100, 0),
	go_to_pad(10, 100, 0),
	go_to_pad(12, 100, 0),
	restart(),
	end(),
};

u8 target44[] = {
	start(),
	go_to_pad(4, 255, 0),
	rotate(FRROTATE_180R, 0),
	go_to_pad(4, 100, 0),
	go_to_pad(6, 100, 0),
	go_to_pad(6, 100, 0),
	go_to_pad(4, 100, 0),
	rotate(FRROTATE_180R, 0),
	restart(),
	end(),
};

u8 target45[] = {
	start(),
	go_to_pad(4, 255, 0),
	go_to_pad(10, 200, 0),
	go_to_pad(4, 200, 0),
	restart(),
	end(),
};

u8 target46[] = {
	start(),
	go_to_pad(11, 255, 0),
	go_to_pad(5, 200, 0),
	go_to_pad(11, 200, 0),
	restart(),
	end(),
};

u8 target47[] = {
	start(),
	go_to_pad(6, 255, 0),
	go_to_pad(12, 200, 0),
	go_to_pad(6, 200, 0),
	restart(),
	end(),
};

u8 target48[] = {
	start(),
	go_to_pad(12, 255, 0),
	rotate(FRROTATE_180R, 1),
	go_to_pad(10, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	rotate(FRROTATE_180R, 1),
	go_to_pad(12, 200, 0),
	rotate(FRROTATE_180R, 1),
	wait_seconds(2),
	restart(),
	end(),
};

u8 target49[] = {
	start(),
	go_to_pad(4, 255, 0),
	go_to_pad(10, 100, 0),
	go_to_pad(12, 30, 0),
	go_to_pad(6, 100, 0),
	go_to_pad(4, 100, 0),
	restart(),
	end(),
};

u8 target4a[] = {
	start(),
	go_to_pad(10, 255, 0),
	go_to_pad(12, 30, 0),
	go_to_pad(6, 100, 0),
	go_to_pad(4, 100, 0),
	go_to_pad(10, 100, 0),
	restart(),
	end(),
};

u8 target4b[] = {
	start(),
	go_to_pad(12, 255, 0),
	go_to_pad(6, 100, 0),
	go_to_pad(4, 100, 0),
	go_to_pad(10, 100, 0),
	go_to_pad(12, 30, 0),
	restart(),
	end(),
};

u8 target4c[] = {
	start(),
	go_to_pad(10, 255, 0),
	rotate(FRROTATE_180R, 0),
	wait_seconds(255),
	rotate(FRROTATE_180R, 0),
	restart(),
	end(),
};

u8 target4d[] = {
	start(),
	go_to_pad(11, 255, 0),
	rotate(FRROTATE_180R, 0),
	wait_seconds(255),
	rotate(FRROTATE_180R, 0),
	restart(),
	end(),
};

u8 target4e[] = {
	start(),
	go_to_pad(12, 255, 0),
	rotate(FRROTATE_180R, 0),
	wait_seconds(255),
	rotate(FRROTATE_180R, 0),
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

