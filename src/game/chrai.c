#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/chrai.h"
#include "game/chraicommands.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/ailist.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

bool (*g_CommandPointers[])(void) = {
	/*0x0000*/ ai_go_to_next,
	/*0x0001*/ ai_go_to_first,
	/*0x0002*/ ai_label,
	/*0x0003*/ ai_yield,
	/*0x0004*/ ai_end_list,
	/*0x0005*/ ai_set_list,
	/*0x0006*/ ai_set_return_list,
	/*0x0007*/ ai_set_shot_list,
	/*0x0008*/ ai_return,
	/*0x0009*/ ai_stop,
	/*0x000a*/ ai_kneel,
	/*0x000b*/ ai_chr_do_animation,
	/*0x000c*/ ai_if_idle,
	/*0x000d*/ ai_be_surprised_one_hand,
	/*0x000e*/ ai_be_surprised_look_around,
	/*0x000f*/ ai_try_sidestep,
	/*0x0010*/ ai_try_jump_out,
	/*0x0011*/ ai_try_run_sideways,
	/*0x0012*/ ai_try_attack_walk,
	/*0x0013*/ ai_try_attack_run,
	/*0x0014*/ ai_try_attack_roll,
	/*0x0015*/ ai_try_attack_stand,
	/*0x0016*/ ai_try_attack_kneel,
	/*0x0017*/ ai_try_modify_attack,
	/*0x0018*/ ai_face_entity,
	/*0x0019*/ ai0019,
	/*0x001a*/ ai_chr_damage_chr,
	/*0x001b*/ ai_consider_grenade_throw,
	/*0x001c*/ ai_drop_item,
	/*0x001d*/ ai_jog_to_pad,
	/*0x001e*/ ai_go_to_pad_preset,
	/*0x001f*/ ai_walk_to_pad,
	/*0x0020*/ ai_run_to_pad,
	/*0x0021*/ ai_set_path,
	/*0x0022*/ ai_start_patrol,
	/*0x0023*/ ai_if_patrolling,
	/*0x0024*/ ai_surrender,
	/*0x0025*/ ai_fade_out,
	/*0x0026*/ ai_remove_chr,
	/*0x0027*/ ai_try_start_alarm,
	/*0x0028*/ ai_activate_alarm,
	/*0x0029*/ ai_deactivate_alarm,
	/*0x002a*/ ai_try_run_from_target,
	/*0x002b*/ ai_try_jog_to_target_prop,
	/*0x002c*/ ai_try_walk_to_target_prop,
	/*0x002d*/ ai_try_run_to_target_prop,
	/*0x002e*/ ai_try_go_to_cover_prop,
	/*0x002f*/ ai_try_jog_to_chr,
	/*0x0030*/ ai_try_walk_to_chr,
	/*0x0031*/ ai_try_run_to_chr,
	/*0x0032*/ ai_if_stopped,
	/*0x0033*/ ai_if_chr_dead,
	/*0x0034*/ ai_if_chr_death_animation_finished,
	/*0x0035*/ ai_if_can_see_target,
	/*0x0036*/ ai_random,
	/*0x0037*/ ai_if_random_less_than,
	/*0x0038*/ ai_if_random_greater_than,
	/*0x0039*/ ai_if_can_hear_alarm,
	/*0x003a*/ ai_if_alarm_active,
	/*0x003b*/ ai_if_gas_active,
	/*0x003c*/ ai_if_hears_target,
	/*0x003d*/ ai_if_saw_injury,
	/*0x003e*/ ai_if_saw_death,
	/*0x003f*/ ai_if_los_to_target,
	/*0x0040*/ ai_if_target_nearly_in_sight,
	/*0x0041*/ ai_if_nearly_in_targets_sight,
	/*0x0042*/ ai_set_pad_preset_to_pad_on_route_to_target,
	/*0x0043*/ ai_if_saw_target_recently,
	/*0x0044*/ ai_if_heard_target_recently,
	/*0x0045*/ ai_if_los_to_chr,
	/*0x0046*/ ai_if_never_been_on_screen,
	/*0x0047*/ ai_if_on_screen,
	/*0x0048*/ ai_if_chr_in_on_screen_room,
	/*0x0049*/ ai_if_room_is_on_screen,
	/*0x004a*/ ai_if_target_aiming_at_me,
	/*0x004b*/ ai_if_near_miss,
	/*0x004c*/ ai_if_sees_suspicious_item,
	/*0x004d*/ ai_if_target_in_fov_left,
	/*0x004e*/ ai_if_check_fov_with_target,
	/*0x004f*/ ai_if_target_out_of_fov_left,
	/*0x0050*/ ai_if_target_in_fov,
	/*0x0051*/ ai_if_target_out_of_fov,
	/*0x0052*/ ai_if_distance_to_target_less_than,
	/*0x0053*/ ai_if_distance_to_target_greater_than,
	/*0x0054*/ ai_if_chr_distance_to_pad_less_than,
	/*0x0055*/ ai_if_chr_distance_to_pad_greater_than,
	/*0x0056*/ ai_if_distance_to_chr_less_than,
	/*0x0057*/ ai_if_distance_to_chr_greater_than,
	/*0x0058*/ ai0058,
	/*0x0059*/ ai_if_distance_from_target_to_pad_less_than,
	/*0x005a*/ ai_if_distance_from_target_to_pad_greater_than,
	/*0x005b*/ ai_if_chr_in_room,
	/*0x005c*/ ai_if_target_in_room,
	/*0x005d*/ ai_if_chr_has_object,
	/*0x005e*/ ai_if_weapon_thrown,
	/*0x005f*/ ai_if_weapon_thrown_on_object,
	/*0x0060*/ ai_if_chr_has_weapon_equipped,
	/*0x0061*/ ai_if_gun_unclaimed,
	/*0x0062*/ ai_if_object_healthy,
	/*0x0063*/ ai_if_chr_activated_object,
	/*0x0064*/ NULL,
	/*0x0065*/ ai_obj_interact,
	/*0x0066*/ ai_destroy_object,
	/*0x0067*/ ai0067,
	/*0x0068*/ ai_chr_drop_items,
	/*0x0069*/ ai_chr_drop_weapon,
	/*0x006a*/ ai_give_object_to_chr,
	/*0x006b*/ ai_object_move_to_pad,
	/*0x006c*/ ai_open_door,
	/*0x006d*/ ai_close_door,
	/*0x006e*/ ai_if_door_state,
	/*0x006f*/ ai_if_object_is_door,
	/*0x0070*/ ai_lock_door,
	/*0x0071*/ ai_unlock_door,
	/*0x0072*/ ai_if_door_locked,
	/*0x0073*/ ai_if_objective_complete,
	/*0x0074*/ ai_if_objective_failed,
	/*0x0075*/ ai0075,
	/*0x0076*/ ai_set_pad_preset_to_target_quadrant,
	/*0x0077*/ ai_if_difficulty_less_than,
	/*0x0078*/ ai_if_difficulty_greater_than,
	/*0x0079*/ ai_if_stage_timer_less_than,
	/*0x007a*/ ai_if_stage_timer_greater_than,
	/*0x007b*/ ai_if_stage_id_less_than,
	/*0x007c*/ ai_if_stage_id_greater_than,
	/*0x007d*/ ai_if_num_arghs_less_than,
	/*0x007e*/ ai_if_num_arghs_greater_than,
	/*0x007f*/ ai_if_num_close_arghs_less_than,
	/*0x0080*/ ai_if_num_close_arghs_greater_than,
	/*0x0081*/ ai_if_chr_health_greater_than,
	/*0x0082*/ ai_if_chr_health_less_than,
	/*0x0083*/ ai_if_injured,
	/*0x0084*/ ai_set_morale,
	/*0x0085*/ ai_add_morale,
	/*0x0086*/ ai_chr_add_morale,
	/*0x0087*/ ai_subtract_morale,
	/*0x0088*/ ai_if_morale_less_than,
	/*0x0089*/ ai_if_morale_less_than_random,
	/*0x008a*/ ai_set_alertness,
	/*0x008b*/ ai_add_alertness,
	/*0x008c*/ ai_chr_add_alertness,
	/*0x008d*/ ai_subtract_alertness,
	/*0x008e*/ ai_if_alertness,
	/*0x008f*/ ai_if_chr_alertness_less_than,
	/*0x0090*/ ai_if_alertness_less_than_random,
	/*0x0091*/ ai_noop_0091,
	/*0x0092*/ ai_set_hear_distance,
	/*0x0093*/ ai_set_view_distance,
	/*0x0094*/ ai_set_grenade_probability,
	/*0x0095*/ ai_set_chr_num,
	/*0x0096*/ ai_set_max_damage,
	/*0x0097*/ ai_add_health,
	/*0x0098*/ ai_set_reaction_speed,
	/*0x0099*/ ai_set_recovery_speed,
	/*0x009a*/ ai_set_accuracy,
	/*0x009b*/ ai_set_flag,
	/*0x009c*/ ai_unset_flag,
	/*0x009d*/ ai_if_has_flag,
	/*0x009e*/ ai_chr_set_flag,
	/*0x009f*/ ai_chr_unset_flag,
	/*0x00a0*/ ai_if_chr_has_flag,
	/*0x00a1*/ ai_set_stage_flag,
	/*0x00a2*/ ai_unset_stage_flag,
	/*0x00a3*/ ai_if_stage_flag_eq,
	/*0x00a4*/ ai_set_chrflag,
	/*0x00a5*/ ai_unset_chrflag,
	/*0x00a6*/ ai_if_has_chrflag,
	/*0x00a7*/ ai_chr_set_chrflag,
	/*0x00a8*/ ai_chr_unset_chrflag,
	/*0x00a9*/ ai_if_chr_has_chrflag,
	/*0x00aa*/ ai_set_obj_flag,
	/*0x00ab*/ ai_unset_obj_flag,
	/*0x00ac*/ ai_if_obj_has_flag,
	/*0x00ad*/ ai_set_obj_flag2,
	/*0x00ae*/ ai_unset_obj_flag2,
	/*0x00af*/ ai_if_obj_has_flag2,
	/*0x00b0*/ ai_set_chr_preset,
	/*0x00b1*/ ai_set_chr_target,
	/*0x00b2*/ ai_set_pad_preset,
	/*0x00b3*/ ai_chr_set_pad_preset,
	/*0x00b4*/ ai_chr_copy_pad_preset,
	/*0x00b5*/ ai_print,
	/*0x00b6*/ ai_restart_timer,
	/*0x00b7*/ ai_reset_timer,
	/*0x00b8*/ ai_pause_timer,
	/*0x00b9*/ ai_resume_timer,
	/*0x00ba*/ ai_if_timer_stopped,
	/*0x00bb*/ ai_if_timer_greater_than_random,
	/*0x00bc*/ ai_if_timer_less_than,
	/*0x00bd*/ ai_if_timer_greater_than,
	/*0x00be*/ ai_show_countdown_timer,
	/*0x00bf*/ ai_hide_countdown_timer,
	/*0x00c0*/ ai_set_countdown_timer_value,
	/*0x00c1*/ ai_stop_countdown_timer,
	/*0x00c2*/ ai_start_countdown_timer,
	/*0x00c3*/ ai_if_countdown_timer_stopped,
	/*0x00c4*/ ai_if_countdown_timer_less_than,
	/*0x00c5*/ ai_if_countdown_timer_greater_than,
	/*0x00c6*/ ai_spawn_chr_at_pad,
	/*0x00c7*/ ai_spawn_chr_at_chr,
	/*0x00c8*/ ai_try_equip_weapon,
	/*0x00c9*/ ai_try_equip_hat,
	/*0x00ca*/ ai_duplicate_chr,
	/*0x00cb*/ ai_show_hudmsg,
	/*0x00cc*/ ai_show_hudmsg_top_middle,
	/*0x00cd*/ ai_speak,
	/*0x00ce*/ ai_play_sound,
	/*0x00cf*/ ai_set_object_sound_playing,
	/*0x00d0*/ ai_play_repeating_sound_from_pad,
	/*0x00d1*/ ai_set_object_sound_volume,
	/*0x00d2*/ ai_set_object_sound_volume_by_distance,
	/*0x00d3*/ ai_audio_mute_channel,
	/*0x00d4*/ ai_if_object_sound_volume_less_than,
	/*0x00d5*/ ai_hovercar_begin_path,
	/*0x00d6*/ ai_set_vehicle_speed,
	/*0x00d7*/ ai_set_rotor_speed,
	/*0x00d8*/ ai_noop_00d8,
	/*0x00d9*/ ai_noop_00d9,
	/*0x00da*/ ai_set_obj_image,
	/*0x00db*/ ai_noop_00db,
	/*0x00dc*/ ai_end_level,
	/*0x00dd*/ ai00dd,
	/*0x00de*/ ai_move_camera_to_pad,
	/*0x00df*/ ai_move_camera_to_preset,
	/*0x00e0*/ ai_revoke_control,
	/*0x00e1*/ ai_grant_control,
	/*0x00e2*/ ai_chr_move_to_pad,
	/*0x00e3*/ ai00e3,
	/*0x00e4*/ ai00e4,
	/*0x00e5*/ ai_if_colour_fade_complete,
	/*0x00e6*/ NULL,
	/*0x00e7*/ NULL,
	/*0x00e8*/ ai_set_door_open,
	/*0x00e9*/ ai00e9,
	/*0x00ea*/ ai_if_num_players_less_than,
	/*0x00eb*/ ai_if_chr_ammo_quantity_less_than,
	/*0x00ec*/ ai_chr_draw_weapon,
	/*0x00ed*/ ai_chr_draw_weapon_in_cutscene,
	/*0x00ee*/ ai00ee,
	/*0x00ef*/ ai_if_obj_in_room,
	/*0x00f0*/ ai00f0,
	/*0x00f1*/ ai_if_attacking,
	/*0x00f2*/ ai_switch_to_alt_sky,
	/*0x00f3*/ ai_chr_set_invincible,
	/*0x00f4*/ ai_move_camera_to_pos,
	/*0x00f5*/ ai00f5,
	/*0x00f6*/ ai00f6,
	/*0x00f7*/ ai_if_all_objectives_complete,
	/*0x00f8*/ ai_if_player_is_invincible,
	/*0x00f9*/ ai_play_x_track,
	/*0x00fa*/ ai_stop_x_track,
	/*0x00fb*/ ai_chr_explosions,
	/*0x00fc*/ ai_if_kill_count_greater_than,
	/*0x00fd*/ ai00fd,
	/*0x00fe*/ ai_kill_bond,
	/*0x00ff*/ ai_be_surprised_surrender,
	/*0x0100*/ ai_noop_0100,
	/*0x0101*/ ai_noop_0101,
	/*0x0102*/ ai_set_lights,
	/*0x0103*/ ai_if_prop_preset_is_blocking_sight_to_target,
	/*0x0104*/ ai_remove_object_at_prop_preset,
	/*0x0105*/ ai_if_prop_preset_height_less_than,
	/*0x0106*/ ai_set_target,
	/*0x0107*/ ai_if_presets_target_is_not_my_target,
	/*0x0108*/ ai_if_chr_target,
	/*0x0109*/ ai_set_chr_preset_to_chr_near_self,
	/*0x010a*/ ai_set_chr_preset_to_chr_near_pad,
	/*0x010b*/ ai_chr_set_team,
	/*0x010c*/ ai_if_compare_chr_presets_team,
	/*0x010d*/ ai_noop_010d,
	/*0x010e*/ ai_set_shield,
	/*0x010f*/ ai_if_chr_shield_less_than,
	/*0x0110*/ ai_if_chr_shield_greater_than,
	/*0x0111*/ ai_set_camera_animation,
	/*0x0112*/ ai_object_do_animation,
	/*0x0113*/ ai_if_in_cutscene,
	/*0x0114*/ ai_enable_chr,
	/*0x0115*/ ai_disable_chr,
	/*0x0116*/ ai_enable_obj,
	/*0x0117*/ ai_disable_obj,
	/*0x0118*/ ai_set_obj_flag3,
	/*0x0119*/ ai_unset_obj_flag3,
	/*0x011a*/ ai_if_obj_has_flag3,
	/*0x011b*/ ai_chr_set_hidden_flag,
	/*0x011c*/ ai_chr_unset_hidden_flag,
	/*0x011d*/ ai_if_chr_has_hidden_flag,
	/*0x011e*/ ai_if_human,
	/*0x011f*/ ai_if_skedar,
	/*0x0120*/ ai_if_safety2_less_than,
	/*0x0121*/ ai_find_cover,
	/*0x0122*/ ai_find_cover_within_dist,
	/*0x0123*/ ai_find_cover_outside_dist,
	/*0x0124*/ ai_go_to_cover,
	/*0x0125*/ ai_check_cover_out_of_sight,
	/*0x0126*/ ai_if_player_using_cmp_or_ar34,
	/*0x0127*/ ai_detect_enemy_on_same_floor,
	/*0x0128*/ ai_detect_enemy,
	/*0x0129*/ ai_if_safety_less_than,
	/*0x012a*/ ai_if_target_moving_slowly,
	/*0x012b*/ ai_if_target_moving_closer,
	/*0x012c*/ ai_if_target_moving_away,
	/*0x012d*/ NULL,
	/*0x012e*/ NULL,
	/*0x012f*/ ai012f,
	/*0x0130*/ ai_say_quip,
	/*0x0131*/ ai_increase_squadron_alertness,
	/*0x0132*/ ai_set_action,
	/*0x0133*/ ai_set_team_orders,
	/*0x0134*/ ai_if_orders,
	/*0x0135*/ ai_if_has_orders,
	/*0x0136*/ ai_retreat,
	/*0x0137*/ ai_if_chr_in_squadron_doing_action,
	/*0x0138*/ ai_if_channel_free,
	/*0x0139*/ ai_flank,
	/*0x013a*/ ai_set_chr_preset_to_unalerted_teammate,
	/*0x013b*/ ai_set_squadron,
	/*0x013c*/ ai_face_cover,
	/*0x013d*/ ai_if_dangerous_object_nearby,
	/*0x013e*/ ai013e,
	/*0x013f*/ ai_if_heli_weapons_armed,
	/*0x0140*/ ai_if_hoverbot_next_step,
	/*0x0141*/ ai_shuffle_investigation_terminals,
	/*0x0142*/ ai_set_pad_preset_to_investigation_terminal,
	/*0x0143*/ ai_heli_arm_weapons,
	/*0x0144*/ ai_heli_unarm_weapons,
	/*0x0145*/ ai_rebuild_teams,
	/*0x0146*/ ai_rebuild_squadrons,
	/*0x0147*/ ai_if_squadron_is_dead,
	/*0x0148*/ ai_chr_set_listening,
	/*0x0149*/ ai_if_chr_listening,
	/*0x014a*/ ai_if_true,
	/*0x014b*/ ai_if_not_listening,
	/*0x014c*/ NULL,
	/*0x014d*/ NULL,
	/*0x014e*/ NULL,
	/*0x014f*/ NULL,
	/*0x0150*/ NULL,
	/*0x0151*/ NULL,
	/*0x0152*/ ai_if_num_chrs_in_squadron_greater_than,
	/*0x0153*/ NULL,
	/*0x0154*/ NULL,
	/*0x0155*/ NULL,
	/*0x0156*/ NULL,
	/*0x0157*/ ai_set_tinted_glass_enabled,
	/*0x0158*/ NULL,
	/*0x0159*/ NULL,
	/*0x015a*/ NULL,
	/*0x015b*/ ai_play_track_isolated,
	/*0x015c*/ ai_play_default_tracks,
	/*0x015d*/ NULL,
	/*0x015e*/ NULL,
	/*0x015f*/ NULL,
	/*0x0160*/ NULL,
	/*0x0161*/ NULL,
	/*0x0162*/ NULL,
	/*0x0163*/ NULL,
	/*0x0164*/ NULL,
	/*0x0165*/ ai_if_chr_injured,
	/*0x0166*/ ai_if_action,
	/*0x0167*/ ai_hovercopter_fire_rocket,
	/*0x0168*/ ai_if_shield_damaged,
	/*0x0169*/ ai_if_natural_anim,
	/*0x016a*/ ai_if_y,
	/*0x016b*/ ai_play_repeating_sound_from_object,
	/*0x016c*/ ai_noop_016c,
	/*0x016d*/ ai_chr_adjust_motion_blur,
	/*0x016e*/ ai_damage_chr_by_amount,
	/*0x016f*/ ai_if_chr_has_gun,
	/*0x0170*/ ai_do_gun_command,
	/*0x0171*/ ai_if_distance_to_gun_less_than,
	/*0x0172*/ ai_recover_gun,
	/*0x0173*/ ai_chr_copy_properties,
	/*0x0174*/ ai_if_cutscene_button_pressed,
	/*0x0175*/ ai0175,
	/*0x0176*/ ai_if_bot_respawning,
	/*0x0177*/ ai_player_auto_walk,
	/*0x0178*/ ai_if_player_auto_walk_finished,
	/*0x0179*/ ai_play_sound_from_entity,
	/*0x017a*/ ai_if_los_to_attack_target,
	/*0x017b*/ ai_if_chr_knocked_out,
	/*0x017c*/ ai_assign_sound,
	/*0x017d*/ ai_play_cutscene_track,
	/*0x017e*/ ai_stop_cutscene_track,
	/*0x017f*/ ai_play_temporary_track,
	/*0x0180*/ ai_stop_ambient_track,
	/*0x0181*/ ai_if_player_looking_at_object,
	/*0x0182*/ ai_punch_or_kick,
	/*0x0183*/ ai_if_target_is_player,
	/*0x0184*/ ai0184,
	/*0x0185*/ ai_mp_init_simulants,
	/*0x0186*/ ai_if_sound_timer,
	/*0x0187*/ ai_set_target_to_eyespy_if_in_sight,
	/*0x0188*/ ai_if_lift_stationary,
	/*0x0189*/ ai_lift_go_to_stop,
	/*0x018a*/ ai_if_lift_at_stop,
	/*0x018b*/ ai_configure_rain,
	/*0x018c*/ ai_chr_toggle_model_part,
	/*0x018d*/ ai_activate_lift,
	/*0x018e*/ ai_mini_skedar_try_pounce,
	/*0x018f*/ ai_if_object_distance_to_pad_less_than,
	/*0x0190*/ ai_set_savefile_flag,
	/*0x0191*/ ai_unset_savefile_flag,
	/*0x0192*/ ai_if_savefile_flag_is_set,
	/*0x0193*/ ai_if_savefile_flag_is_unset,
	/*0x0194*/ NULL,
	/*0x0195*/ NULL,
	/*0x0196*/ NULL,
	/*0x0197*/ NULL,
	/*0x0198*/ NULL,
	/*0x0199*/ NULL,
	/*0x019a*/ NULL,
	/*0x019b*/ NULL,
	/*0x019c*/ NULL,
	/*0x019d*/ NULL,
	/*0x019e*/ ai_if_obj_health_less_than,
	/*0x019f*/ ai_set_obj_health,
	/*0x01a0*/ ai_set_chr_special_death_animation,
	/*0x01a1*/ ai_set_room_to_search,
	/*0x01a2*/ ai_say_ci_staff_quip,
	/*0x01a3*/ ai_do_preset_animation,
	/*0x01a4*/ ai_show_hudmsg_middle,
	/*0x01a5*/ ai_if_using_lift,
	/*0x01a6*/ ai_if_target_y_difference_less_than,
	/*0x01a7*/ ai_if_chr_not_talking,
	/*0x01a8*/ NULL,
	/*0x01a9*/ NULL,
	/*0x01aa*/ ai01aa,
	/*0x01ab*/ ai_if_num_knocked_out_chrs,
	/*0x01ac*/ NULL,
	/*0x01ad*/ ai_release_object,
	/*0x01ae*/ ai_clear_inventory,
	/*0x01af*/ ai_chr_grab_object,
	/*0x01b0*/ NULL,
	/*0x01b1*/ ai_shuffle_ruins_pillars,
	/*0x01b2*/ ai_set_wind_speed,
	/*0x01b3*/ ai_toggle_p1p2,
#if VERSION >= VERSION_NTSC_1_0
	/*0x01b4*/ ai_if_nothing_in_my_space,
#else
	/*0x01b4*/ NULL,
#endif
	/*0x01b5*/ ai_chr_set_p1p2,
	/*0x01b6*/ ai_configure_snow,
	/*0x01b7*/ ai_chr_set_cloaked,
	/*0x01b8*/ ai_set_autogun_target_team,
	/*0x01b9*/ ai_shuffle_pelagic_switches,
	/*0x01ba*/ ai_try_attack_lie,
	/*0x01bb*/ ai_noop_01bb,
	/*0x01bc*/ ai_if_pouncebits_eq,
	/*0x01bd*/ ai_if_training_pc_holographed,
	/*0x01be*/ ai_if_player_using_device,
	/*0x01bf*/ ai_chr_begin_or_end_teleport,
	/*0x01c0*/ ai_if_chr_teleport_full_white,
	/*0x01c1*/ ai_set_punch_dodge_list,
	/*0x01c2*/ ai_set_shooting_at_me_list,
	/*0x01c3*/ ai_set_dark_room_list,
	/*0x01c4*/ ai_set_player_dead_list,
	/*0x01c5*/ ai_avoid,
	/*0x01c6*/ ai_set_dodge_rating,
	/*0x01c7*/ ai_set_unarmed_dodge_rating,
	/*0x01c8*/ ai_title_init_mode,
	/*0x01c9*/ ai_try_exit_title,
	/*0x01ca*/ ai_chr_set_cutscene_weapon,
	/*0x01cb*/ ai_fade_screen,
	/*0x01cc*/ ai_if_fade_complete,
	/*0x01cd*/ ai_set_chr_hudpiece_visible,
	/*0x01ce*/ ai_set_passive_mode,
	/*0x01cf*/ ai_chr_set_firing_in_cutscene,
	/*0x01d0*/ ai_set_portal_flag,
	/*0x01d1*/ ai_obj_set_model_part_visible,
	/*0x01d2*/ ai_chr_emit_sparks,
	/*0x01d3*/ ai_set_dr_caroll_images,
	/*0x01d4*/ ai_set_room_flag,
	/*0x01d5*/ ai_show_cutscene_chrs,
	/*0x01d6*/ ai_configure_environment,
	/*0x01d7*/ ai_if_distance_to_target2_less_than,
	/*0x01d8*/ ai_if_distance_to_target2_greater_than,
	/*0x01d9*/ ai_play_sound_from_prop,
	/*0x01da*/ ai_play_temporary_primary_track,
	/*0x01db*/ ai_chr_kill,
	/*0x01dc*/ ai_remove_weapon_from_inventory,
	/*0x01dd*/ ai_if_music_event_queue_is_empty,
	/*0x01de*/ ai_if_coop_mode,
#if VERSION >= VERSION_NTSC_1_0
	/*0x01df*/ ai_if_chr_same_floor_distance_to_pad_less_than,
	/*0x01e0*/ ai_remove_references_to_chr,
#endif
};

u16 g_CommandLengths[] = {
	/*0x0000*/ 3,  /*0x0001*/ 3,  /*0x0002*/ 3,  /*0x0003*/ 2,
	/*0x0004*/ 2,  /*0x0005*/ 5,  /*0x0006*/ 5,  /*0x0007*/ 4,
	/*0x0008*/ 2,  /*0x0009*/ 2,  /*0x000a*/ 2,  /*0x000b*/ 12,
	/*0x000c*/ 3,  /*0x000d*/ 2,  /*0x000e*/ 2,  /*0x000f*/ 3,
	/*0x0010*/ 3,  /*0x0011*/ 3,  /*0x0012*/ 3,  /*0x0013*/ 3,
	/*0x0014*/ 3,  /*0x0015*/ 7,  /*0x0016*/ 7,  /*0x0017*/ 7,
	/*0x0018*/ 7,  /*0x0019*/ 8,  /*0x001a*/ 5,  /*0x001b*/ 7,
	/*0x001c*/ 6,  /*0x001d*/ 4,  /*0x001e*/ 3,  /*0x001f*/ 4,
	/*0x0020*/ 4,  /*0x0021*/ 3,  /*0x0022*/ 2,  /*0x0023*/ 3,
	/*0x0024*/ 2,  /*0x0025*/ 2,  /*0x0026*/ 3,  /*0x0027*/ 5,
	/*0x0028*/ 2,  /*0x0029*/ 2,  /*0x002a*/ 3,  /*0x002b*/ 3,
	/*0x002c*/ 3,  /*0x002d*/ 3,  /*0x002e*/ 3,  /*0x002f*/ 4,
	/*0x0030*/ 4,  /*0x0031*/ 4,  /*0x0032*/ 3,  /*0x0033*/ 4,
	/*0x0034*/ 4,  /*0x0035*/ 3,  /*0x0036*/ 2,  /*0x0037*/ 4,
	/*0x0038*/ 4,  /*0x0039*/ 3,  /*0x003a*/ 3,  /*0x003b*/ 3,
	/*0x003c*/ 3,  /*0x003d*/ 4,  /*0x003e*/ 4,  /*0x003f*/ 3,
	/*0x0040*/ 7,  /*0x0041*/ 7,  /*0x0042*/ 3,  /*0x0043*/ 3,
	/*0x0044*/ 3,  /*0x0045*/ 4,  /*0x0046*/ 3,  /*0x0047*/ 3,
	/*0x0048*/ 4,  /*0x0049*/ 5,  /*0x004a*/ 3,  /*0x004b*/ 3,
	/*0x004c*/ 3,  /*0x004d*/ 4,  /*0x004e*/ 6,  /*0x004f*/ 4,
	/*0x0050*/ 4,  /*0x0051*/ 4,  /*0x0052*/ 5,  /*0x0053*/ 5,
	/*0x0054*/ 8,  /*0x0055*/ 8,  /*0x0056*/ 6,  /*0x0057*/ 6,
	/*0x0058*/ 5,  /*0x0059*/ 7,  /*0x005a*/ 7,  /*0x005b*/ 7,
	/*0x005c*/ 5,  /*0x005d*/ 5,  /*0x005e*/ 4,  /*0x005f*/ 5,
	/*0x0060*/ 5,  /*0x0061*/ 5,  /*0x0062*/ 4,  /*0x0063*/ 5,
	/*0x0064*/ 1,  /*0x0065*/ 3,  /*0x0066*/ 3,  /*0x0067*/ 3,
	/*0x0068*/ 3,  /*0x0069*/ 3,  /*0x006a*/ 4,  /*0x006b*/ 5,
	/*0x006c*/ 3,  /*0x006d*/ 3,  /*0x006e*/ 5,  /*0x006f*/ 4,
	/*0x0070*/ 4,  /*0x0071*/ 4,  /*0x0072*/ 5,  /*0x0073*/ 4,
	/*0x0074*/ 4,  /*0x0075*/ 4,  /*0x0076*/ 4,  /*0x0077*/ 4,
	/*0x0078*/ 4,  /*0x0079*/ 5,  /*0x007a*/ 5,  /*0x007b*/ 4,
	/*0x007c*/ 4,  /*0x007d*/ 4,  /*0x007e*/ 4,  /*0x007f*/ 4,
	/*0x0080*/ 4,  /*0x0081*/ 5,  /*0x0082*/ 5,  /*0x0083*/ 4,
	/*0x0084*/ 3,  /*0x0085*/ 3,  /*0x0086*/ 4,  /*0x0087*/ 3,
	/*0x0088*/ 4,  /*0x0089*/ 3,  /*0x008a*/ 3,  /*0x008b*/ 3,
	/*0x008c*/ 4,  /*0x008d*/ 3,  /*0x008e*/ 5,  /*0x008f*/ 5,
	/*0x0090*/ 3,  /*0x0091*/ 2,  /*0x0092*/ 4,  /*0x0093*/ 3,
	/*0x0094*/ 3,  /*0x0095*/ 3,  /*0x0096*/ 5,  /*0x0097*/ 4,
	/*0x0098*/ 3,  /*0x0099*/ 3,  /*0x009a*/ 3,  /*0x009b*/ 7,
	/*0x009c*/ 7,  /*0x009d*/ 9,  /*0x009e*/ 8,  /*0x009f*/ 8,
	/*0x00a0*/ 9,  /*0x00a1*/ 6,  /*0x00a2*/ 6,  /*0x00a3*/ 8,
	/*0x00a4*/ 6,  /*0x00a5*/ 6,  /*0x00a6*/ 7,  /*0x00a7*/ 7,
	/*0x00a8*/ 7,  /*0x00a9*/ 8,  /*0x00aa*/ 7,  /*0x00ab*/ 7,
	/*0x00ac*/ 8,  /*0x00ad*/ 7,  /*0x00ae*/ 7,  /*0x00af*/ 8,
	/*0x00b0*/ 3,  /*0x00b1*/ 4,  /*0x00b2*/ 4,  /*0x00b3*/ 5,
	/*0x00b4*/ 4,  /*0x00b5*/ 0,  /*0x00b6*/ 2,  /*0x00b7*/ 2,
	/*0x00b8*/ 2,  /*0x00b9*/ 2,  /*0x00ba*/ 3,  /*0x00bb*/ 3,
	/*0x00bc*/ 6,  /*0x00bd*/ 6,  /*0x00be*/ 2,  /*0x00bf*/ 2,
	/*0x00c0*/ 4,  /*0x00c1*/ 2,  /*0x00c2*/ 2,  /*0x00c3*/ 3,
	/*0x00c4*/ 5,  /*0x00c5*/ 5,  /*0x00c6*/ 13, /*0x00c7*/ 12,
	/*0x00c8*/ 10, /*0x00c9*/ 9,  /*0x00ca*/ 10, /*0x00cb*/ 5,
	/*0x00cc*/ 6,  /*0x00cd*/ 9,  /*0x00ce*/ 5,  /*0x00cf*/ 6,
	/*0x00d0*/ 7,  /*0x00d1*/ 7,  /*0x00d2*/ 7,  /*0x00d3*/ 3,
	/*0x00d4*/ 6,  /*0x00d5*/ 3,  /*0x00d6*/ 6,  /*0x00d7*/ 6,
	/*0x00d8*/ 3,  /*0x00d9*/ 3,  /*0x00da*/ 5,  /*0x00db*/ 3,
	/*0x00dc*/ 2,  /*0x00dd*/ 2,  /*0x00de*/ 4,  /*0x00df*/ 7,
	/*0x00e0*/ 4,  /*0x00e1*/ 3,  /*0x00e2*/ 7,  /*0x00e3*/ 3,
	/*0x00e4*/ 3,  /*0x00e5*/ 4,  /*0x00e6*/ 1,  /*0x00e7*/ 1,
	/*0x00e8*/ 3,  /*0x00e9*/ 4,  /*0x00ea*/ 4,  /*0x00eb*/ 6,
	/*0x00ec*/ 4,  /*0x00ed*/ 4,  /*0x00ee*/ 5,  /*0x00ef*/ 6,
	/*0x00f0*/ 3,  /*0x00f1*/ 3,  /*0x00f2*/ 2,  /*0x00f3*/ 3,
	/*0x00f4*/ 14, /*0x00f5*/ 2,  /*0x00f6*/ 3,  /*0x00f7*/ 3,
	/*0x00f8*/ 4,  /*0x00f9*/ 5,  /*0x00fa*/ 3,  /*0x00fb*/ 3,
	/*0x00fc*/ 4,  /*0x00fd*/ 4,  /*0x00fe*/ 2,  /*0x00ff*/ 2,
	/*0x0100*/ 3,  /*0x0101*/ 3,  /*0x0102*/ 11, /*0x0103*/ 3,
	/*0x0104*/ 2,  /*0x0105*/ 5,  /*0x0106*/ 5,  /*0x0107*/ 3,
	/*0x0108*/ 6,  /*0x0109*/ 6,  /*0x010a*/ 8,  /*0x010b*/ 4,
	/*0x010c*/ 4,  /*0x010d*/ 2,  /*0x010e*/ 4,  /*0x010f*/ 6,
	/*0x0110*/ 6,  /*0x0111*/ 4,  /*0x0112*/ 8,  /*0x0113*/ 3,
	/*0x0114*/ 3,  /*0x0115*/ 3,  /*0x0116*/ 3,  /*0x0117*/ 3,
	/*0x0118*/ 7,  /*0x0119*/ 7,  /*0x011a*/ 8,  /*0x011b*/ 7,
	/*0x011c*/ 7,  /*0x011d*/ 8,  /*0x011e*/ 4,  /*0x011f*/ 4,
	/*0x0120*/ 4,  /*0x0121*/ 5,  /*0x0122*/ 9,  /*0x0123*/ 9,
	/*0x0124*/ 3,  /*0x0125*/ 3,  /*0x0126*/ 3,  /*0x0127*/ 3,
	/*0x0128*/ 4,  /*0x0129*/ 4,  /*0x012a*/ 4,  /*0x012b*/ 3,
	/*0x012c*/ 3,  /*0x012d*/ 1,  /*0x012e*/ 1,  /*0x012f*/ 2,
	/*0x0130*/ 10, /*0x0131*/ 3,  /*0x0132*/ 4,  /*0x0133*/ 4,
	/*0x0134*/ 5,  /*0x0135*/ 3,  /*0x0136*/ 4,  /*0x0137*/ 4,
	/*0x0138*/ 4,  /*0x0139*/ 8,  /*0x013a*/ 5,  /*0x013b*/ 3,
	/*0x013c*/ 3,  /*0x013d*/ 4,  /*0x013e*/ 2,  /*0x013f*/ 3,
	/*0x0140*/ 5,  /*0x0141*/ 9,  /*0x0142*/ 4,  /*0x0143*/ 2,
	/*0x0144*/ 2,  /*0x0145*/ 2,  /*0x0146*/ 2,  /*0x0147*/ 4,
	/*0x0148*/ 4,  /*0x0149*/ 6,  /*0x014a*/ 6,  /*0x014b*/ 3,
	/*0x014c*/ 1,  /*0x014d*/ 1,  /*0x014e*/ 1,  /*0x014f*/ 1,
	/*0x0150*/ 1,  /*0x0151*/ 1,  /*0x0152*/ 5,  /*0x0153*/ 1,
	/*0x0154*/ 1,  /*0x0155*/ 1,  /*0x0156*/ 1,  /*0x0157*/ 3,
	/*0x0158*/ 1,  /*0x0159*/ 1,  /*0x015a*/ 1,  /*0x015b*/ 3,
	/*0x015c*/ 2,  /*0x015d*/ 1,  /*0x015e*/ 1,  /*0x015f*/ 1,
	/*0x0160*/ 1,  /*0x0161*/ 1,  /*0x0162*/ 1,  /*0x0163*/ 1,
	/*0x0164*/ 1,  /*0x0165*/ 4,  /*0x0166*/ 4,  /*0x0167*/ 3,
	/*0x0168*/ 4,  /*0x0169*/ 4,  /*0x016a*/ 7,  /*0x016b*/ 10,
	/*0x016c*/ 2,  /*0x016d*/ 5,  /*0x016e*/ 5,  /*0x016f*/ 5,
	/*0x0170*/ 4,  /*0x0171*/ 5,  /*0x0172*/ 4,  /*0x0173*/ 4,
	/*0x0174*/ 3,  /*0x0175*/ 3,  /*0x0176*/ 3,  /*0x0177*/ 9,
	/*0x0178*/ 4,  /*0x0179*/ 11, /*0x017a*/ 3,  /*0x017b*/ 4,
	/*0x017c*/ 5,  /*0x017d*/ 3,  /*0x017e*/ 2,  /*0x017f*/ 3,
	/*0x0180*/ 2,  /*0x0181*/ 5,  /*0x0182*/ 4,  /*0x0183*/ 3,
	/*0x0184*/ 4,  /*0x0185*/ 2,  /*0x0186*/ 6,  /*0x0187*/ 3,
	/*0x0188*/ 4,  /*0x0189*/ 4,  /*0x018a*/ 5,  /*0x018b*/ 3,
	/*0x018c*/ 4,  /*0x018d*/ 4,  /*0x018e*/ 7,  /*0x018f*/ 8,
	/*0x0190*/ 3,  /*0x0191*/ 3,  /*0x0192*/ 4,  /*0x0193*/ 4,
	/*0x0194*/ 1,  /*0x0195*/ 1,  /*0x0196*/ 1,  /*0x0197*/ 1,
	/*0x0198*/ 1,  /*0x0199*/ 1,  /*0x019a*/ 1,  /*0x019b*/ 1,
	/*0x019c*/ 1,  /*0x019d*/ 1,  /*0x019e*/ 6,  /*0x019f*/ 5,
	/*0x01a0*/ 4,  /*0x01a1*/ 2,  /*0x01a2*/ 4,  /*0x01a3*/ 3,
	/*0x01a4*/ 6,  /*0x01a5*/ 3,  /*0x01a6*/ 4,  /*0x01a7*/ 4,
	/*0x01a8*/ 1,  /*0x01a9*/ 1,  /*0x01aa*/ 3,  /*0x01ab*/ 5,
	/*0x01ac*/ 1,  /*0x01ad*/ 3,  /*0x01ae*/ 3,  /*0x01af*/ 4,
	/*0x01b0*/ 1,  /*0x01b1*/ 18, /*0x01b2*/ 3,  /*0x01b3*/ 3,
	/*0x01b4*/ VERSION >= VERSION_NTSC_1_0 ? 3 : 1, /*0x01b5*/ 4, /*0x01b6*/ 3, /*0x01b7*/ 5,
	/*0x01b8*/ 4,  /*0x01b9*/ 2,  /*0x01ba*/ 7,  /*0x01bb*/ 4,
	/*0x01bc*/ 4,  /*0x01bd*/ 3,  /*0x01be*/ 5,  /*0x01bf*/ 5,
	/*0x01c0*/ 4,  /*0x01c1*/ 4,  /*0x01c2*/ 4,  /*0x01c3*/ 4,
	/*0x01c4*/ 4,  /*0x01c5*/ 2,  /*0x01c6*/ 4,  /*0x01c7*/ 3,
	/*0x01c8*/ 3,  /*0x01c9*/ 3,  /*0x01ca*/ 5,  /*0x01cb*/ 8,
	/*0x01cc*/ 3,  /*0x01cd*/ 4,  /*0x01ce*/ 3,  /*0x01cf*/ 4,
	/*0x01d0*/ 5,  /*0x01d1*/ 5,  /*0x01d2*/ 3,  /*0x01d3*/ 5,
	/*0x01d4*/ 6,  /*0x01d5*/ 3,  /*0x01d6*/ 6,  /*0x01d7*/ 5,
	/*0x01d8*/ 5,  /*0x01d9*/ 11, /*0x01da*/ 3,  /*0x01db*/ 3,
	/*0x01dc*/ 3,  /*0x01dd*/ 4,  /*0x01de*/ 3,
#if VERSION >= VERSION_NTSC_1_0
	/*0x01df*/ 8,
	/*0x01e0*/ 2,
#endif
};

s32 chrai_get_list_id_by_list(u8 *ailist, bool *is_global)
{
	s32 i;

	if (g_StageSetup.ailists) {
		for (i = 0; g_StageSetup.ailists[i].list != NULL; i++) {
			if (g_StageSetup.ailists[i].list == ailist) {
				*is_global = false;
				return g_StageSetup.ailists[i].id;
			}
		}
	}

	for (i = 0; g_GlobalAilists[i].list != NULL; i++) {
		if (g_GlobalAilists[i].list == ailist) {
			*is_global = true;
			return g_GlobalAilists[i].id;
		}
	}

	return -1;
}

u32 chrai_go_to_label(u8 *ailist, u32 aioffset, u8 label)
{
	do {
		u8 *cmd = aioffset + ailist;
		u32 type = (cmd[0] << 8) + cmd[1];

		if (type == CMD_LABEL) {
			if (label == cmd[2]) {
				return aioffset;
			}
		} else if (type == CMD_END) {
			return 0;
		}

		aioffset += chrai_get_command_length(ailist, aioffset);
	} while (true);
}

void chrai_execute(void *entity, s32 proptype)
{
	g_Vars.chrdata = NULL;
	g_Vars.truck = NULL;
	g_Vars.heli = NULL;
	g_Vars.hovercar = NULL;
	g_Vars.ailist = NULL;
	g_Vars.aioffset = 0;

	if (proptype == PROPTYPE_CHR) {
		g_Vars.chrdata = entity;
	} else if (proptype == PROPTYPE_OBJ) {
		struct defaultobj *obj = entity;

		if (obj->type == OBJTYPE_TRUCK) {
			g_Vars.truck = entity;
		} else if (obj->type == OBJTYPE_HELI) {
			g_Vars.heli = entity;
		} else if (obj->type == OBJTYPE_HOVERCAR || obj->type == OBJTYPE_CHOPPER) {
			g_Vars.hovercar = entity;
		}
	}

	if (g_Vars.chrdata) {
		g_Vars.ailist = g_Vars.chrdata->ailist;
		g_Vars.aioffset = g_Vars.chrdata->aioffset;
	} else if (g_Vars.truck) {
		g_Vars.ailist = g_Vars.truck->ailist;
		g_Vars.aioffset = g_Vars.truck->aioffset;
	} else if (g_Vars.heli) {
		g_Vars.ailist = g_Vars.heli->ailist;
		g_Vars.aioffset = g_Vars.heli->aioffset;
	} else if (g_Vars.hovercar) {
		g_Vars.ailist = g_Vars.hovercar->ailist;
		g_Vars.aioffset = g_Vars.hovercar->aioffset;
	}

	if (g_Vars.ailist) {
		if (g_Vars.chrdata) {
			chr_add_target_to_bdlist(g_Vars.chrdata);
		}

		// Check if the ailist should be switched to a different one
		if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_TRIGGERSHOTLIST)) {
			u32 animnum = model_get_anim_num(g_Vars.chrdata->model);
			if (g_Vars.chrdata->aishotlist >= 0
					&& g_Vars.chrdata->cshield <= 0
					&& (0 <= g_Vars.chrdata->damage || g_Vars.chrdata->gunprop != NULL)
					&& animnum != ANIM_SNIPING_GETDOWN
					&& animnum != ANIM_SNIPING_GETUP
					&& animnum != ANIM_SNIPING_ONGROUND) {
				// Set shot list
				g_Vars.chrdata->chrflags &= ~CHRCFLAG_TRIGGERSHOTLIST;
				g_Vars.ailist = ailist_find_by_id(g_Vars.chrdata->aishotlist);
				g_Vars.aioffset = 0;
			}
		} else if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_CONSIDER_DODGE)) {
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_CONSIDER_DODGE;

			if (g_Vars.chrdata->aishootingatmelist >= 0
					&& ailist_find_by_id(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->dodgerating > random() % 100
					&& chr_has_flag(g_Vars.chrdata, CHRFLAG1_INDARKROOM, BANK_1) == 0
					&& chr_has_flag(g_Vars.chrdata, CHRFLAG0_AIVSAI, BANK_0) == 0
					&& ailist_find_by_id(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->actiontype != ACT_ATTACK
					&& g_Vars.chrdata->actiontype != ACT_ATTACKWALK
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH
					&& g_Vars.chrdata->actiontype != ACT_PREARGH
					&& g_Vars.chrdata->actiontype != ACT_ATTACKROLL) {
				// Set shooting at me list
				g_Vars.ailist = ailist_find_by_id(g_Vars.chrdata->aishootingatmelist);
				g_Vars.aioffset = 0;
				g_Vars.chrdata->dodgerating = 0;
			} else {
				// Increase dodge rating
				g_Vars.chrdata->dodgerating *= 2;

				if (g_Vars.chrdata->dodgerating > g_Vars.chrdata->maxdodgerating) {
					g_Vars.chrdata->dodgerating = g_Vars.chrdata->maxdodgerating;
				}
			}
		} else if (g_Vars.chrdata
				&& g_Vars.chrdata->darkroomthing
				&& chr_has_flag(g_Vars.chrdata, CHRFLAG1_INDARKROOM, BANK_1) == 0
				&& ailist_find_by_id(g_Vars.chrdata->aidarkroomlist) != g_Vars.chrdata->ailist
				&& g_Vars.stagenum != STAGE_CRASHSITE) {
			g_Vars.chrdata->darkroomthing = 0;

			if (g_Vars.chrdata->aidarkroomlist >= 0
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH) {
				// Set darkroom list
				chr_set_flags(g_Vars.chrdata, CHRFLAG1_INDARKROOM, BANK_1);
				chr_set_flags(g_Vars.chrdata, CHRFLAG1_SEARCHSAMEROOM, BANK_1);
				g_Vars.chrdata->alertness = 0;
				g_Vars.ailist = ailist_find_by_id(g_Vars.chrdata->aidarkroomlist);
				g_Vars.aioffset = 0;
			}
		} else {
			// empty
		}

		// Iterate and execute the ailist
		while (g_Vars.ailist) {
			u8 *cmd = g_Vars.aioffset + g_Vars.ailist;
			s32 type = (cmd[0] << 8) + cmd[1];

			if (type >= 0 && type < ARRAYCOUNT(g_CommandPointers)) {
				if (g_CommandPointers[type]()) {
					break;
				}
			} else {
				// This is attempting to handle situations where the command
				// type is invalid by passing over them and continuing
				// execution. This would very likely result in a crash though.
				g_Vars.aioffset += chrai_get_command_length(g_Vars.ailist, g_Vars.aioffset);
			}
		}
	}
}

u32 chrai_get_command_length(u8 *ailist, u32 aioffset)
{
	u8 *cmd = aioffset + ailist;
	s32 type = (cmd[0] << 8) + cmd[1];

	if (type == CMD_PRINT) {
		u32 prop = aioffset + 2;

		while (ailist[prop] != 0) {
			++prop;
		}

		return (prop - aioffset) + 1;
	}

	if (type >= 0 && type < ARRAYCOUNT(g_CommandLengths)) {
		return g_CommandLengths[type];
	}

	return 1;
}
