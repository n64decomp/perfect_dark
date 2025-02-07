#include <ultra64.h>
#include "constants.h"
#include "game/bossfile.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/pdmode.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/menugfx.h"
#include "game/menu.h"
#include "game/filelist.h"
#include "game/mainmenu.h"
#include "game/endscreen.h"
#include "game/playermgr.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "data.h"
#include "types.h"

u8 g_FileState = 0;
u8 var80062944 = 0;
u8 var80062948 = 0;
u8 var8006294c = 0;

const char var7f1a85b0[] = "lvup: %d\n";
const char var7f1a85bc[] = "file id %x-%x";
const char var7f1a85cc[] = " ticking: ";
const char var7f1a85d8[] = "1";
const char var7f1a85dc[] = "0";
const char var7f1a85e0[] = "Live: %d\n";
const char var7f1a85ec[] = "current:";
const char var7f1a85f8[] = " numactive %d ";

void menu_count_dialogs(void)
{
	s32 i;
	g_MenuData.count = 0;

	for (i = 0; i < ARRAYCOUNT(g_Menus); i++) {
		if (g_Menus[i].curdialog) {
			g_MenuData.count++;
		}
	}
}

void menu_tick(void)
{
	s32 i;
	s32 j;
	s32 k;
	s32 anyopen2;
	s32 allready = true;
	s32 anyopen = false;

#if PAL
	g_UiScaleX = 1;
#else
	g_UiScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	menu_tick_timers();

	if (g_MenuData.count) {
		// empty
	}

	menu_count_dialogs();

	for (i = 0; i < ARRAYCOUNT(g_Menus); i++) {
		if (i);

		if (g_Menus[i].openinhibit > 0) {
			g_Menus[i].openinhibit--;
		}

		if (g_Menus[i].curdialog) {
			anyopen = true;
		}
	}

	if (!anyopen && g_MenuData.bg != 0 && g_MenuData.nextbg == 255) {
		g_MenuData.nextbg = 0;
	}

	// If there are any pending file saves, wait up to 40 or 50 frames or until all
	// dialogs are settled, then save one.
	if (anyopen && g_MenuData.numpendingsaves > 0 && var8009dfc0) {
		s32 maxwait = 50;
		s32 busy = false;

		for (j = 0; j < ARRAYCOUNT(g_Menus); j++) {
			if (g_Menus[j].curdialog) {
				if (g_Menus[j].curdialog->state == MENUDIALOGSTATE_OPENING
						|| g_Menus[j].curdialog->state == MENUDIALOGSTATE_POPULATING
						|| g_Menus[j].curdialog->state == MENUDIALOGSTATE_PREOPEN) {
					busy = true;
				}
			}
		}

		if (g_Vars.normmplayerisrunning) {
			maxwait = 40;
		}

		if (g_MenuData.savetimer > maxwait || !busy) {
			menu_save_file(g_MenuData.numpendingsaves - 1);
		} else {
			g_MenuData.savetimer++;
		}
	}

	if (g_MenuData.nextbg != 255) {
		if (g_MenuData.nextbg == g_MenuData.bg) {
			g_MenuData.nextbg = 255;
		} else {
			f32 mult = 0.02f;

			if (g_MenuData.bg == 0) {
				mult = mult + mult;
			}

			if (g_MenuData.nextbg == 0) {
				mult = mult + mult;
			}

			if (g_MenuData.nextbg == MENUBG_8) {
				mult = mult / 5.0f;
			}

			if (g_MenuData.nextbg == MENUBG_SUCCESS) {
				mult = mult / 3.0f;
			}

			if (g_MenuData.nextbg == MENUBG_6) {
				mult = mult / 10.0f;
			}

			if (g_MenuData.nextbg == 0) {
				var8009dfc0 = false;

				if (g_Vars.currentplayer->gunctrl.gunmemowner != GUNMEMOWNER_BONDGUN) {
					g_Vars.currentplayer->gunctrl.loadall = true;
				}
			}

			if (g_MenuData.screenshottimer == 0 || g_MenuData.bg != 0) {
#if VERSION >= VERSION_PAL_BETA
				f32 diffframe = g_Vars.diffframe60freal;
#else
				f32 diffframe = g_Vars.diffframe60f;
#endif

				if (diffframe > 4) {
					diffframe = 4;
				}

				g_MenuData.bgopacityfrac += mult * diffframe;
			}

			if (g_MenuData.bgopacityfrac > 1) {
				if (g_MenuData.nextbg) {
					var8009dfc0 = true;
				}

				g_MenuData.bgopacityfrac = 0;
				g_MenuData.bg = g_MenuData.nextbg;
				g_MenuData.nextbg = 255;

				if (g_MenuData.root == MENUROOT_ENDSCREEN) {
					if (g_MenuData.bg == MENUBG_BLUR) {
						g_MenuData.nextbg = MENUBG_6;
					}

					if (g_MenuData.bg == MENUBG_6) {
						menugfx_free_particles();
						g_MenuData.bg = MENUBG_BLUR;
						g_MenuData.nextbg = MENUBG_8;
					}

					if (g_MenuData.bg == MENUBG_8) {
						g_MenuData.nextbg = MENUBG_SUCCESS;
					}
				}

				if (g_MenuData.bg == 0) {
					menu_consider_unpause();
				}
			}

			if (g_MenuData.nextbg == MENUBG_FAILURE) {
				var8009dfc0 = true;
			}

			if (var8009dfc0 && g_Vars.currentplayer->gunmem2) {
				player_remove_chr_body();

				if (g_Vars.currentplayer->gunmem2);
			}
		}
	} else {
		g_MenuData.bgopacityfrac = 0;
		var8009dfc0 = g_MenuData.bg == 0 ? false : true;
	}

	// Check if returning from a multiplayer match
	if (g_MpReturningFromMatch > 0) {
		if (g_Vars.lvframenum >= 4) {
			if (g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU) {
				vi_black(false);
				g_MpNumJoined = 0;

				if (g_Vars.usingadvsetup) {
					g_Vars.mpsetupmenu = MPSETUPMENU_ADVSETUP;
				} else {
					g_Vars.mpsetupmenu = MPSETUPMENU_GENERAL;
				}

				for (i = 0; i < MAX_PLAYERS; i++) {
					g_Vars.waitingtojoin[i] = false;

					if (g_MpSetup.chrslots & (1 << i)) {
						g_MpPlayerNum = i;

						if (g_Vars.mpsetupmenu == MPSETUPMENU_ADVSETUP) {
							g_MpNumJoined++;
							mp_open_advanced_setup(true);
						} else if (g_MpNumJoined == 0) {
							g_MpNumJoined++;

							if (IS4MB()) {
								menu_push_root_dialog(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
							} else {
								menu_push_root_dialog(&g_CombatSimulatorMenuDialog, MENUROOT_MPSETUP);
							}
						} else {
							g_Vars.waitingtojoin[i] = true;
						}
					}
				}

				g_MpPlayerNum = 0;

				if (g_MpSetup.chrslots & 0xf) {
					snd_start(var80095200, SFX_EXPLOSION_8098, 0, -1, -1, -1, -1, -1);

					player_pause(IS4MB() ? MENUROOT_4MBMAINMENU : MENUROOT_MPSETUP);
				}
			}

			g_MpReturningFromMatch = 0;
		} else {
			vi_black(true);
			g_PlayersWithControl[0] = false;
		}
	}

	// If a game file hasn't been selected (ie. just powered on),
	// force the file select menu open
	if (g_FileState == FILESTATE_UNSELECTED && g_Vars.stagenum == STAGE_CITRAINING) {
		g_PlayersWithControl[0] = false;

		if (g_Vars.lvframenum > 30 && g_Vars.tickmode != TICKMODE_CUTSCENE) {
			g_Menus[0].openinhibit = 0;
			g_Menus[1].openinhibit = 0;
			g_Menus[2].openinhibit = 0;
			g_Menus[3].openinhibit = 0;
			g_Vars.currentplayer->pausemode = PAUSEMODE_UNPAUSED;
			player_pause(MENUROOT_FILEMGR);
			g_FileState = FILESTATE_SELECTED;
		}
	}

	g_Vars.unk000498 = 0;

	if (g_MenuData.count > 0) {
		var8006294c = 1;

		if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
			if (g_MenuData.nextroot == -1) {
				g_MpSetup.chrslots &= 0xfff0;
			}

			g_MpNumJoined = 0;

			for (i = 0; i < ARRAYCOUNT(g_Menus); i++) {
				if (g_Menus[i].curdialog) {
					g_Menus[i].playernum = g_MpNumJoined++;

					if (g_MenuData.nextroot == -1) {
						g_MpSetup.chrslots |= (1 << i);
					}
				}
			}

			mp_calculate_lock_if_last_winner_or_loser();
			challenge_perform_sanity_checks();
		}

		for (i = 0; i < MAX_PLAYERS; i++) {
			g_MpPlayerNum = i;

			if (g_Menus[g_MpPlayerNum].curdialog) {
				if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpReadyMenuDialog) {
					g_Vars.unk000498 = 1;
				} else {
					allready = false;
				}
			}
		}

		for (i = 0; i < MAX_PLAYERS; i++) {
			g_MpPlayerNum = i;

			if (g_Menus[g_MpPlayerNum].curdialog) {
				// Player has a dialog open - tick it
				s32 prevplayernum = g_Vars.currentplayernum;

				if (g_Menus[g_MpPlayerNum].playernum < PLAYERCOUNT()) {
					set_current_player_num(g_Menus[g_MpPlayerNum].playernum);
				}

				menu_process_input();
				set_current_player_num(prevplayernum);
			} else {
				if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
					// Check if player is joining the game
					bool canjoin;
					u16 buttons = joy_get_buttons_pressed_this_frame(i, 0xffff);

					if (g_MenuData.root == MENUROOT_4MBMAINMENU) {
						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
							// Limit to 2 players? But in a roundabout kind of way
							canjoin = true;

							for (j = 0; j < MAX_PLAYERS; j++) {
								if (g_Vars.waitingtojoin[j]) {
									canjoin = false;
								}
							}
						} else {
							// Quick go or advanced setup - limit to 2 players
							canjoin = g_MpNumJoined < 2;
						}
					} else {
						// 8MB - no restrictions on joining
						canjoin = true;
					}

					if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
						g_PlayerConfigsArray[i].base.team = 0;
					}

					if (canjoin && (buttons & START_BUTTON)) {
						g_PlayerConfigsArray[i].handicap = 128;

						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
							// Joining from a general area such as the Combat
							// Simulator menu. We can't open dialogs for other
							// players here, so they are waiting to join.
#if VERSION >= VERSION_NTSC_1_0
							if (!g_Vars.waitingtojoin[i]) {
								snd_start(var80095200, SFX_EXPLOSION_809A, 0, -1, -1, -1, -1, -1);
							}
							g_Vars.waitingtojoin[i] = true;
#else
							g_Vars.waitingtojoin[i] = true;
							snd_start(var80095200, SFX_EXPLOSION_809A, 0, -1, -1, -1, -1, -1);
#endif

						} else if (g_Vars.mpsetupmenu == MPSETUPMENU_QUICKGO) {
							// Joining from quick go - open Quick Go dialog
							g_MpNumJoined++;

							if (IS4MB()) {
								menu_push_root_dialog(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
							} else {
								menu_push_root_dialog(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
							}
						} else {
							// Joining from advanced setup
							g_MpNumJoined++;
							mp_open_advanced_setup(false);
						}
					}

					if ((buttons & START_BUTTON) == 0) {
						if (buttons & B_BUTTON) {
							// No dialog open and pressing B -> no longer
							// waiting to join
							if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
								g_Vars.waitingtojoin[i] = false;
							}
						} else if (g_Vars.waitingtojoin[i]) {
							if (g_Vars.mpsetupmenu == MPSETUPMENU_QUICKGO) {
								// Player was waiting to join and we have just
								// reached the quick go layer - open the dialog
								g_Vars.waitingtojoin[i] = false;
								g_MpNumJoined++;

								if (IS4MB()) {
									menu_push_root_dialog(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
								} else {
									menu_push_root_dialog(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
								}
							} else if (g_Vars.mpsetupmenu == MPSETUPMENU_ADVSETUP) {
								// Player was waiting to join and we have just
								// reached the adv setup layer - open the dialog
								g_Vars.waitingtojoin[i] = false;
								g_MpNumJoined++;
								mp_open_advanced_setup(false);
							}
						}
					}
				} else {
					g_Vars.mpsetupmenu = 0;
					g_Vars.waitingtojoin[i] = false;
				}

				// Note that MPENDSCREEN also refers to coop and anti modes.
				// Handle re-opening the endscreen by pressing B.
				if (g_MenuData.root == MENUROOT_MPENDSCREEN) {
					u16 buttons2 = joy_get_buttons_pressed_this_frame(g_PlayerConfigsArray[i].contpad1, 0xffff);

					if (buttons2 & B_BUTTON) {
						s32 playernum = -1;
						s32 k;

						for (k = 0; k < PLAYERCOUNT(); k++) {
							if (g_Vars.playerstats[k].mpindex == i) {
								playernum = k;
							}
						}

						if (playernum >= 0) {
							if (g_Vars.coopplayernum >= 0) {
								s32 prevplayernum = g_Vars.currentplayernum;
								set_current_player_num(playernum);
								endscreen_push_coop();
								set_current_player_num(prevplayernum);
							} else if (g_Vars.antiplayernum >= 0) {
								s32 prevplayernum = g_Vars.currentplayernum;
								set_current_player_num(playernum);
								endscreen_push_anti();
								set_current_player_num(prevplayernum);
							} else {
								mp_push_endscreen_dialog(playernum, i);
							}
						}
					}
				}
			}
		}

		if (allready && (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)) {
			menu_save_and_push_root_dialog(NULL, MENUROOT_START_MP_MATCH);
		}
	} else {
		var8006294c = 0;
	}

	if (var8006294c) {
		if (var80062948 == 0 &&
				(g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)) {
			var80062948 = 1;
			filelist_create(0, FILETYPE_MPPLAYER);
			filelist_create(1, FILETYPE_MPSETUP);
		}

		if (var80062944) {
			filelists_tick();
		}
	} else {
		if (var80062944 == 1) {
			menu_stop();
		}
	}

	g_MpPlayerNum = 0;
	anyopen2 = false;

	for (i = 0; i < ARRAYCOUNT(g_Menus); i++) {
		if (g_Menus[i].curdialog) {
			anyopen2 = true;
		}
	}

	if ((g_MenuData.checkroots || g_MenuData.nextroot != -1) && anyopen2 == false) {
		if ((g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)
				&& g_MenuData.nextroot == -1) {
			if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
				g_MenuData.nextroot = MENUROOT_MAINMENU;
				g_MenuData.nextdialog = IS4MB() ? &g_CiMenuViaPauseMenuDialog : &g_CiMenuViaPcMenuDialog;
			} else if (IS4MB()) {
				g_MenuData.nextroot = MENUROOT_4MBMAINMENU;
				g_MenuData.nextdialog = &g_MainMenu4MbMenuDialog;
			} else {
				g_MenuData.nextroot = MENUROOT_MPSETUP;
				g_MenuData.nextdialog = &g_CombatSimulatorMenuDialog;
			}
		}

		if (g_MenuData.nextroot != -1) {
			if (g_MenuData.nextroot == MENUROOT_START_MP_MATCH) {
				// Match is beginning
				mp_start_match();
				menu_stop();

				if (g_Vars.modifiedfiles & MODFILE_MPSETUP) {
					bossfile_save();
					g_Vars.modifiedfiles &= ~MODFILE_MPSETUP;
				}
			} else if (g_MenuData.nextroot == MENUROOT_END_MP_MATCH) {
				// Match is ending
				s32 playernum = 0;

				if (g_Vars.normmplayerisrunning) {
					menu_queue_save(4);
				}

				for (i = 0; i < MAX_PLAYERS; i++) {
					if (g_MpSetup.chrslots & (1 << i)) {
						if (g_Vars.coopplayernum >= 0) {
							if (g_Vars.stagenum == STAGE_DEEPSEA) {
								g_MissionConfig.stageindex++;
								g_MissionConfig.stagenum = g_SoloStages[g_MissionConfig.stageindex].stagenum;
								title_set_next_stage(g_MissionConfig.stagenum);
								lv_set_difficulty(g_MissionConfig.difficulty);
								title_set_next_mode(TITLEMODE_SKIP);
								main_change_to_stage(g_MissionConfig.stagenum);
							} else {
								s32 prevplayernum = g_Vars.currentplayernum;
								set_current_player_num(playernum);
								endscreen_push_coop();
								set_current_player_num(prevplayernum);
								anyopen2 = true;
							}
						} else if (g_Vars.antiplayernum >= 0) {
							s32 prevplayernum = g_Vars.currentplayernum;
							set_current_player_num(playernum);
							endscreen_push_anti();
							set_current_player_num(prevplayernum);
							anyopen2 = true;
						} else {
							mp_push_endscreen_dialog(playernum, i);
							anyopen2 = true;

							if (g_PlayerConfigsArray[i].fileguid.fileid && g_PlayerConfigsArray[i].fileguid.deviceserial) {
								menu_queue_save(i);
							}
						}

						playernum++;
					}
				}
			} else if (g_MenuData.nextroot == MENUROOT_CHANGE_AGENT) {
				menu_stop();
				g_FileState = FILESTATE_CHANGINGAGENT;
				gamefile_load_defaults(&g_GameFile);
				gamefile_apply_options(&g_GameFile);
				main_change_to_stage(IS4MB() ? STAGE_4MBMENU : STAGE_CITRAINING);
				music_queue_stop_all_event();
			} else {
				bool startmusic = false;
				menu_push_root_dialog(g_MenuData.nextdialog, g_MenuData.nextroot);
				anyopen2 = true;

				if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
					startmusic = true;
					snd_start(var80095200, SFX_EXPLOSION_8098, 0, -1, -1, -1, -1, -1);
				}

				if (g_MenuData.root == MENUROOT_MAINMENU || g_MenuData.root == MENUROOT_TRAINING) {
					struct trainingdata *dtdata = dt_get_data();

					if ((g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU)
							&& ((g_Vars.currentplayer->prop->rooms[0] >= 0x16 && g_Vars.currentplayer->prop->rooms[0] <= 0x19)
								|| g_Vars.currentplayer->prop->rooms[0] == 0x0a
								|| g_Vars.currentplayer->prop->rooms[0] == 0x1e
								|| (dtdata && dtdata->intraining))) {
						startmusic = false;
					} else {
						startmusic = true;
					}
				}

				if (startmusic) {
					music_start_menu();
				}
			}

			g_MenuData.nextdialog = NULL;
			g_MenuData.nextroot = -1;
		} else {
			switch (g_MenuData.root) {
			case MENUROOT_ENDSCREEN:
				if (g_Vars.restartlevel) {
					main_change_to_stage(main_get_stage_num());
				} else {
					main_change_to_stage(STAGE_TITLE);
				}
				break;
			case MENUROOT_MPPAUSE:
				break;
			case MENUROOT_MPENDSCREEN:
				if (g_Vars.normmplayerisrunning) {
					g_MpReturningFromMatch = 3;
				} else if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
					struct mpplayerconfig tmp;

					tmp = g_PlayerConfigsArray[4];
					g_PlayerConfigsArray[4] = g_PlayerConfigsArray[0];
					g_PlayerConfigsArray[0] = tmp;

					tmp = g_PlayerConfigsArray[5];
					g_PlayerConfigsArray[5] = g_PlayerConfigsArray[1];
					g_PlayerConfigsArray[1] = tmp;
				}

				if (g_Vars.coopplayernum >= 0
						&& g_MissionConfig.stageindex <= SOLOSTAGEINDEX_SKEDARRUINS
						&& ((!g_CheatsActiveBank0 && !g_CheatsActiveBank1) || is_stage_difficulty_unlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty))) {
					endscreen_push_solo();
				} else if (g_Vars.restartlevel) {
					main_change_to_stage(main_get_stage_num());
				} else {
					mp_set_paused(MPPAUSEMODE_UNPAUSED);
					g_Vars.mplayerisrunning = false;
					g_Vars.normmplayerisrunning = false;
					g_Vars.lvmpbotlevel = 0;

					if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
						g_BossFile.locktype = MPLOCKTYPE_NONE;
					}

					if (IS8MB()) {
						title_set_next_stage(STAGE_CITRAINING);
						set_num_players(1);
						title_set_next_mode(TITLEMODE_SKIP);
						main_change_to_stage(STAGE_CITRAINING);
					} else {
						title_set_next_stage(STAGE_4MBMENU);
						set_num_players(1);
						title_set_next_mode(TITLEMODE_SKIP);
						main_change_to_stage(STAGE_4MBMENU);
					}
				}
				break;
			case MENUROOT_COOPCONTINUE:
				if (g_Vars.coopplayernum >= 0) {
					mp_set_paused(MPPAUSEMODE_UNPAUSED);
					g_Vars.mplayerisrunning = false;
					g_Vars.normmplayerisrunning = false;
					g_Vars.lvmpbotlevel = 0;
					title_set_next_stage(STAGE_CITRAINING);
					set_num_players(1);
					title_set_next_mode(TITLEMODE_SKIP);
					main_change_to_stage(STAGE_CITRAINING);
					g_MissionConfig.iscoop = false;
				}
				break;
			}
		}
	}

	menu_count_dialogs();

	if (g_MenuData.count == 0) {
		if (g_MenuData.nextbg != 255) {
			if (g_MenuData.nextbg != 0) {
				g_MenuData.bg = g_MenuData.nextbg;
				g_MenuData.nextbg = 0;
				g_MenuData.bgopacityfrac = 1.0f - g_MenuData.bgopacityfrac;
			}
		} else {
			if (g_MenuData.bg != 0) {
				g_MenuData.nextbg = 0;
			}
		}

		if (g_Vars.currentplayer->gunctrl.gunmemowner == GUNMEMOWNER_INVMENU && g_Vars.stagenum != STAGE_CITRAINING) {
			g_MenuData.ininventorymenu = true;

			if (g_Menus[0].menumodel.allocstart) {
				bgun_free_gun_mem();
				g_Menus[0].menumodel.allocstart = NULL;
			}
		}
	}

	g_Vars.paksneededformenu = 0;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		s32 mpindex = -1;

		if (g_Vars.mplayerisrunning) {
			mpindex = g_Vars.playerstats[i].mpindex;
		} else if (i == 0) {
			mpindex = 0;
		}

		if (mpindex >= 0 && g_Vars.players[i]) {
			if (g_MenuData.nextbg != 255U
					|| g_MenuData.bg
					|| g_MenuData.triggerhudpiece
					|| g_MenuData.hudpieceactive
					|| g_Menus[mpindex].curdialog
					|| g_MenuData.bannernum != -1) {
				g_Vars.players[i]->menuisactive = true;
			} else {
				g_Vars.players[i]->menuisactive = false;
			}

			switch (g_MenuData.root) {
			case MENUROOT_ENDSCREEN:
			case MENUROOT_MAINMENU:
			case MENUROOT_MPSETUP:
			case MENUROOT_MPENDSCREEN:
			case MENUROOT_FILEMGR:
			case MENUROOT_BOOTPAKMGR:
			case MENUROOT_4MBFILEMGR:
			case MENUROOT_4MBMAINMENU:
			case MENUROOT_TRAINING:
				if (g_Menus[mpindex].curdialog) {
					g_Vars.paksneededformenu = 0x1f;
				}
				break;
			}

			g_Vars.players[i]->devicesinhibit = 0;

			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
					&& PLAYERCOUNT() >= 2
					&& g_Menus[mpindex].curdialog) {
				g_Vars.players[i]->devicesinhibit = 0
					| DEVICE_NIGHTVISION
					| DEVICE_XRAYSCANNER
					| DEVICE_EYESPY
					| DEVICE_IRSCANNER;
			}
		}
	}

	g_UiScaleX = 1;
	g_MenuData.checkroots = anyopen2 ? true : false;
}
