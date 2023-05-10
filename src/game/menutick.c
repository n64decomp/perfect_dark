#include <ultra64.h>
#include "constants.h"
#include "game/bossfile.h"
#include "game/game_006900.h"
#include "game/title.h"
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


static void menuCountDialogs(void)
{
	s32 i;
	g_MenuData.count = 0;

	for (i = 0; i < 4; i++) {
		if (g_Menus[i].curdialog) {
			g_MenuData.count++;
		}
	}
}

void menuTick(void)
{
	s32 i;
	s32 j;
	s32 k;
	s32 sp344;
	s32 sp340 = true;
	s32 anyopen = false;

	menuTickTimers();

	if (g_MenuData.count) {
		// empty
	}

	menuCountDialogs();

	for (i = 0; i < 4; i++) {
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

	if (anyopen && g_MenuData.unk66e > 0 && var8009dfc0) {
		s32 bVar12 = 50;
		s32 bVar11 = false;

		for (j = 0; j < 4; j++) {
			if (g_Menus[j].curdialog) {
				if (g_Menus[j].curdialog->state == MENUDIALOGSTATE_OPENING
						|| g_Menus[j].curdialog->state == MENUDIALOGSTATE_POPULATING
						|| g_Menus[j].curdialog->state == MENUDIALOGSTATE_PREOPEN) {
					bVar11 = true;
				}
			}
		}

		if (g_Vars.normmplayerisrunning) {
			bVar12 = 40;
		}

		if (g_MenuData.unk66f > bVar12 || !bVar11) {
			func0f0f3220(g_MenuData.unk66e - 1);
		} else {
			g_MenuData.unk66f++;
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

				if (g_Vars.currentplayer->gunctrl.gunmemowner) {
					g_Vars.currentplayer->gunctrl.unk1583_06 = true;
				}
			}

			if (g_MenuData.screenshottimer == 0 || g_MenuData.bg != 0) {
				f32 diffframe = g_Vars.diffframe60f;

				if (diffframe > 4) {
					diffframe = 4;
				}

				g_MenuData.unk010 += mult * diffframe;
			}

			if (g_MenuData.unk010 > 1) {
				if (g_MenuData.nextbg) {
					var8009dfc0 = true;
				}

				g_MenuData.unk010 = 0;
				g_MenuData.bg = g_MenuData.nextbg;
				g_MenuData.nextbg = 255;

				if (g_MenuData.root == MENUROOT_ENDSCREEN) {
					if (g_MenuData.bg == MENUBG_BLUR) {
						g_MenuData.nextbg = MENUBG_6;
					}

					if (g_MenuData.bg == MENUBG_6) {
						menugfxFreeParticles();
						g_MenuData.bg = MENUBG_BLUR;
						g_MenuData.nextbg = MENUBG_8;
					}

					if (g_MenuData.bg == MENUBG_8) {
						g_MenuData.nextbg = MENUBG_SUCCESS;
					}
				}

				if (g_MenuData.bg == 0) {
					func0f0fa6ac();
				}
			}

			if (g_MenuData.nextbg == MENUBG_FAILURE) {
				var8009dfc0 = true;
			}

			if (var8009dfc0 && g_Vars.currentplayer->gunmem2) {
				playerRemoveChrBody();

				if (g_Vars.currentplayer->gunmem2);
			}
		}
	} else {
		g_MenuData.unk010 = 0;
		var8009dfc0 = g_MenuData.bg == 0 ? false : true;
	}

	// Check if returning from a multiplayer match
	if (var80087260 > 0) {
		if (g_Vars.lvframenum >= 4) {
			if (g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU) {
				viBlack(false);
				g_MpNumJoined = 0;

				if (g_Vars.usingadvsetup) {
					g_Vars.mpsetupmenu = MPSETUPMENU_ADVSETUP;
				} else {
					g_Vars.mpsetupmenu = MPSETUPMENU_GENERAL;
				}

				for (i = 0; i < 4; i++) {
					g_Vars.waitingtojoin[i] = false;

					if (g_MpSetup.chrslots & (1 << i)) {
						g_MpPlayerNum = i;

						if (g_Vars.mpsetupmenu == MPSETUPMENU_ADVSETUP) {
							g_MpNumJoined++;
							func0f17fcb0(true);
						} else if (g_MpNumJoined == 0) {
							g_MpNumJoined++;

							menuPushRootDialog(&g_CombatSimulatorMenuDialog, MENUROOT_MPSETUP);
						} else {
							g_Vars.waitingtojoin[i] = true;
						}
					}
				}

				g_MpPlayerNum = 0;

				if (g_MpSetup.chrslots & 0xf) {
					sndStart(var80095200, SFX_EXPLOSION_8098, 0, -1, -1, -1, -1, -1);

					playerPause(MENUROOT_MPSETUP);
				}
			}

			var80087260 = 0;
		} else {
			viBlack(true);
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
			playerPause(MENUROOT_FILEMGR);
			g_FileState = FILESTATE_SELECTED;
		}
	}

	g_Vars.unk000498 = 0;

	if (g_MenuData.count > 0) {
		var8006294c = 1;

		if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
			if (g_MenuData.unk008 == -1) {
				g_MpSetup.chrslots &= 0xfff0;
			}

			g_MpNumJoined = 0;

			for (i = 0; i < 4; i++) {
				if (g_Menus[i].curdialog) {
					g_Menus[i].playernum = g_MpNumJoined++;

					if (g_MenuData.unk008 == -1) {
						g_MpSetup.chrslots |= (1 << i);
					}
				}
			}

			mpCalculateLockIfLastWinnerOrLoser();
			challengePerformSanityChecks();
		}

		for (i = 0; i < 4; i++) {
			g_MpPlayerNum = i;

			if (g_Menus[g_MpPlayerNum].curdialog) {
				if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpReadyMenuDialog) {
					g_Vars.unk000498 = 1;
				} else {
					sp340 = false;
				}
			}
		}

		for (i = 0; i < 4; i++) {
			g_MpPlayerNum = i;

			if (g_Menus[g_MpPlayerNum].curdialog) {
				// Player has a dialog open - tick it
				s32 prevplayernum = g_Vars.currentplayernum;

				if (g_Menus[g_MpPlayerNum].playernum < PLAYERCOUNT()) {
					setCurrentPlayerNum(g_Menus[g_MpPlayerNum].playernum);
				}

				menuProcessInput();
				setCurrentPlayerNum(prevplayernum);
			} else {
				if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
					// Check if player is joining the game
					bool canjoin;
					u16 buttons = joyGetButtonsPressedThisFrame(i, 0xffff);

					if (g_MenuData.root == MENUROOT_4MBMAINMENU) {
						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
							// Limit to 2 players? But in a roundabout kind of way
							canjoin = true;

							for (j = 0; j < 4; j++) {
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
							if (!g_Vars.waitingtojoin[i]) {
								sndStart(var80095200, SFX_EXPLOSION_809A, 0, -1, -1, -1, -1, -1);
							}

							g_Vars.waitingtojoin[i] = true;
						} else if (g_Vars.mpsetupmenu == MPSETUPMENU_QUICKGO) {
							// Joining from quick go - open Quick Go dialog
							g_MpNumJoined++;

							menuPushRootDialog(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
						} else {
							// Joining from advanced setup
							g_MpNumJoined++;
							func0f17fcb0(false);
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

								menuPushRootDialog(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
							} else if (g_Vars.mpsetupmenu == MPSETUPMENU_ADVSETUP) {
								// Player was waiting to join and we have just
								// reached the adv setup layer - open the dialog
								g_Vars.waitingtojoin[i] = false;
								g_MpNumJoined++;
								func0f17fcb0(false);
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
					u16 buttons2 = joyGetButtonsPressedThisFrame(g_PlayerConfigsArray[i].contpad1, 0xffff);

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
								setCurrentPlayerNum(playernum);
								endscreenPushCoop();
								setCurrentPlayerNum(prevplayernum);
							} else if (g_Vars.antiplayernum >= 0) {
								s32 prevplayernum = g_Vars.currentplayernum;
								setCurrentPlayerNum(playernum);
								endscreenPushAnti();
								setCurrentPlayerNum(prevplayernum);
							} else {
								mpPushEndscreenDialog(playernum, i);
							}
						}
					}
				}
			}
		}

		if (sp340 &&
				(g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)) {
			func0f0f820c(NULL, -5);
		}
	} else {
		var8006294c = 0;
	}

	if (var8006294c) {
		if (var80062948 == 0 &&
				(g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)) {
			var80062948 = 1;
			filelistCreate(0, FILETYPE_MPPLAYER);
			filelistCreate(1, FILETYPE_MPSETUP);
		}

		if (var80062944) {
			filelistsTick();
		}
	} else {
		if (var80062944 == 1) {
			menuStop();
		}
	}

	g_MpPlayerNum = 0;
	sp344 = false;

	for (i = 0; i < 4; i++) {
		if (g_Menus[i].curdialog) {
			sp344 = true;
		}
	}

	if ((g_MenuData.unk5d5_06 || g_MenuData.unk008 != -1) && sp344 == false) {
		if ((g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)
				&& g_MenuData.unk008 == -1) {
			if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
				g_MenuData.unk008 = MENUROOT_MAINMENU;
				g_MenuData.unk00c = &g_CiMenuViaPcMenuDialog;
			} else {
				g_MenuData.unk008 = MENUROOT_MPSETUP;
				g_MenuData.unk00c = &g_CombatSimulatorMenuDialog;
			}
		}

		if (g_MenuData.unk008 != -1) {
			if (g_MenuData.unk008 == -5) {
				// Match is beginning
				mpStartMatch();
				menuStop();

				if (g_Vars.modifiedfiles & MODFILE_MPSETUP) {
					bossfileSave();
					g_Vars.modifiedfiles &= ~MODFILE_MPSETUP;
				}
			} else if (g_MenuData.unk008 == -6) {
				// Match is ending
				s32 playernum = 0;

				if (g_Vars.normmplayerisrunning) {
					func0f0fd548(4);
				}

				for (i = 0; i < 4; i++) {
					if (g_MpSetup.chrslots & (1 << i)) {
						if (g_Vars.coopplayernum >= 0) {
							if (g_Vars.stagenum == STAGE_DEEPSEA) {
								g_MissionConfig.stageindex++;
								g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stagenum;
								g_TitleNextStage = g_MissionConfig.stagenum;
								lvSetDifficulty(g_MissionConfig.difficulty);
								titleSetNextMode(TITLEMODE_SKIP);
								mainChangeToStage(g_MissionConfig.stagenum);
							} else {
								s32 prevplayernum = g_Vars.currentplayernum;
								setCurrentPlayerNum(playernum);
								endscreenPushCoop();
								setCurrentPlayerNum(prevplayernum);
								sp344 = true;
							}
						} else if (g_Vars.antiplayernum >= 0) {
							s32 prevplayernum = g_Vars.currentplayernum;
							setCurrentPlayerNum(playernum);
							endscreenPushAnti();
							setCurrentPlayerNum(prevplayernum);
							sp344 = true;
						} else {
							mpPushEndscreenDialog(playernum, i);
							sp344 = true;

							if (g_PlayerConfigsArray[i].fileguid.fileid && g_PlayerConfigsArray[i].fileguid.deviceserial) {
								func0f0fd548(i);
							}
						}

						playernum++;
					}
				}
			} else if (g_MenuData.unk008 == -7) {
				menuStop();
				g_FileState = FILESTATE_CHANGINGAGENT;
				gamefileLoadDefaults(&g_GameFile);
				gamefileApplyOptions(&g_GameFile);
				mainChangeToStage(STAGE_CITRAINING);
				musicQueueStopAllEvent();
			} else {
				bool startmusic = false;
				menuPushRootDialog(g_MenuData.unk00c, g_MenuData.unk008);
				sp344 = true;

				if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
					startmusic = true;
					sndStart(var80095200, SFX_EXPLOSION_8098, 0, -1, -1, -1, -1, -1);
				}

				if (g_MenuData.root == MENUROOT_MAINMENU || g_MenuData.root == MENUROOT_TRAINING) {
					struct trainingdata *dtdata = dtGetData();

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
					musicStartMenu();
				}
			}

			g_MenuData.unk00c = NULL;
			g_MenuData.unk008 = -1;
		} else {
			switch (g_MenuData.root) {
			case MENUROOT_ENDSCREEN:
				if (g_Vars.restartlevel) {
					mainChangeToStage(g_StageNum);
				} else {
					mainChangeToStage(STAGE_TITLE);
				}
				break;
			case MENUROOT_MPPAUSE:
				break;
			case MENUROOT_MPENDSCREEN:
				if (g_Vars.normmplayerisrunning) {
					var80087260 = 3;
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
						&& ((!g_CheatsActiveBank0 && !g_CheatsActiveBank1) || isStageDifficultyUnlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty))) {
					endscreenPushSolo();
				} else if (g_Vars.restartlevel) {
					mainChangeToStage(g_StageNum);
				} else {
					mpSetPaused(MPPAUSEMODE_UNPAUSED);
					g_Vars.mplayerisrunning = false;
					g_Vars.normmplayerisrunning = false;
					g_Vars.lvmpbotlevel = 0;

					if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
						g_BossFile.locktype = MPLOCKTYPE_NONE;
					}

					g_TitleNextStage = STAGE_CITRAINING;
					g_NumPlayers = 1;
					titleSetNextMode(TITLEMODE_SKIP);
					mainChangeToStage(STAGE_CITRAINING);
				}
				break;
			case MENUROOT_COOPCONTINUE:
				if (g_Vars.coopplayernum >= 0) {
					mpSetPaused(MPPAUSEMODE_UNPAUSED);
					g_Vars.mplayerisrunning = false;
					g_Vars.normmplayerisrunning = false;
					g_Vars.lvmpbotlevel = 0;
					g_TitleNextStage = STAGE_CITRAINING;
					g_NumPlayers = 1;
					titleSetNextMode(TITLEMODE_SKIP);
					mainChangeToStage(STAGE_CITRAINING);
					g_MissionConfig.iscoop = false;
				}
				break;
			}
		}
	}

	menuCountDialogs();

	if (g_MenuData.count == 0) {
		if (g_MenuData.nextbg != 255) {
			if (g_MenuData.nextbg != 0) {
				g_MenuData.bg = g_MenuData.nextbg;
				g_MenuData.nextbg = 0;
				g_MenuData.unk010 = 1.0f - g_MenuData.unk010;
			}
		} else {
			if (g_MenuData.bg != 0) {
				g_MenuData.nextbg = 0;
			}
		}

		if (g_Vars.currentplayer->gunctrl.gunmemowner == GUNMEMOWNER_INVMENU && g_Vars.stagenum != STAGE_CITRAINING) {
			g_MenuData.unk5d5_01 = true;

			if (g_Menus[0].unk840.unk004) {
				g_Vars.currentplayer->gunctrl.gunmemowner = GUNMEMOWNER_FREE;
				g_Menus[0].unk840.unk004 = NULL;
			}
		}
	}

	g_Vars.paksconnected = 0;

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
					|| g_MenuData.unk5d5_05
					|| g_MenuData.unk5d4
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
					g_Vars.paksconnected = 0x1f;
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

	g_MenuData.unk5d5_06 = sp344 ? true : false;
}
