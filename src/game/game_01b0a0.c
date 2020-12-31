#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_01b0a0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0fd660.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_13130.h"
#include "lib/lib_13900.h"
#include "types.h"

f32 pdmodeGetReaction(void)
{
	return 0;
}

f32 pdmodeGetHealth(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodehealthf;
	}

	return 1;
}

f32 pdmodeGetDamage(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodedamagef;
	}

	return 1;
}

f32 pdmodeGetAccuracy(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodeaccuracyf;
	}

	return 1;
}

void func0f01b148(u32 arg0)
{
	var800624e0 = arg0;
}

void titleSetNextStage(s32 stagenum)
{
	g_TitleNextStage = stagenum;
}

void activemenuTick(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		g_ActiveMenuIndex = g_Vars.currentplayernum;

		if (g_ActiveMenus[g_ActiveMenuIndex].togglefunc) {
			if (currentPlayerConsiderToggleGunFunction(60, false, 1) > 0) {
				g_ActiveMenus[g_ActiveMenuIndex].togglefunc = false;
			}
		} else {
			// empty
		}

		if (g_Vars.normmplayerisrunning == false
				&& currentPlayerGetNumInvItems() != g_ActiveMenus[g_ActiveMenuIndex].numitems) {
			activemenuAssignWeaponSlots();
		}

		if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
			s32 controlmode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);
			s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
			s32 numsamples = contGetNumSamples();
			s32 j;

			for (j = 0; j < numsamples; j++) {
				s8 gotonextscreen = false;
				s8 cstickx = contGetStickXOnSample(j, contpadnum);
				s8 csticky = contGetStickYOnSample(j, contpadnum);
				s8 absstickx;
				s8 abssticky;
				u16 buttonsstate = contGetButtonsOnSample(j, contpadnum, 0xffff);
				u16 buttonspressed = contGetButtonsPressedOnSample(j, contpadnum, 0xffff);
				bool stickpushed = false;
				s32 slotnum;
				bool stayopen;
				bool toggle;
				s32 row;
				s32 column;

				column = 1;
				row = 1;
				stayopen = false;
				toggle = false;

				g_ActiveMenus[g_ActiveMenuIndex].allbots = false;

				if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
					buttonsstate = buttonsstate & A_BUTTON;
					cstickx = 0;
					csticky = 0;
					buttonspressed = 0;
				}

				if (controlmode == CONTROLMODE_13 || controlmode == CONTROLMODE_14) {
					if ((buttonsstate & R_TRIG) || (buttonsstate & L_TRIG)) {
						stayopen = true;
					}

					if (buttonsstate & A_BUTTON) {
						g_ActiveMenus[g_ActiveMenuIndex].allbots = true;
					}
				} else {
					if (buttonsstate & A_BUTTON) {
						stayopen = true;
					}

					if ((buttonsstate & R_TRIG) || (buttonsstate & L_TRIG)) {
						g_ActiveMenus[g_ActiveMenuIndex].allbots = true;
					}
				}

				// If entering allbots mode, save current screen
				if (g_ActiveMenus[g_ActiveMenuIndex].allbots
						&& g_ActiveMenus[g_ActiveMenuIndex].screenindex >= 2
						&& g_ActiveMenus[g_ActiveMenuIndex].origscreennum == 0) {
					g_ActiveMenus[g_ActiveMenuIndex].origscreennum = g_ActiveMenus[g_ActiveMenuIndex].screenindex;
					g_ActiveMenus[g_ActiveMenuIndex].screenindex = 2;
					activemenuChangeScreen(0);
				}

				// If exiting allbots mode, return to original screen
				if (!g_ActiveMenus[g_ActiveMenuIndex].allbots
						&& g_ActiveMenus[g_ActiveMenuIndex].origscreennum) {
					g_ActiveMenus[g_ActiveMenuIndex].screenindex = g_ActiveMenus[g_ActiveMenuIndex].origscreennum;
					g_ActiveMenus[g_ActiveMenuIndex].origscreennum = 0;
					activemenuChangeScreen(0);
				}

				if (buttonsstate & U_CBUTTONS) {
					row = 0;
				}

				if (buttonsstate & D_CBUTTONS) {
					row = 2;
				}

				if (buttonsstate & L_CBUTTONS) {
					column = 0;
				}

				if (buttonsstate & R_CBUTTONS) {
					column = 2;
				}

				if (buttonsstate & U_JPAD) {
					row = 0;
				}

				if (buttonsstate & D_JPAD) {
					row = 2;
				}

				if (buttonsstate & L_JPAD) {
					column = 0;
				}

				if (buttonsstate & R_JPAD) {
					column = 2;
				}

				if (controlmode == CONTROLMODE_23
						|| controlmode == CONTROLMODE_24
						|| controlmode == CONTROLMODE_22
						|| controlmode == CONTROLMODE_21) {
					s8 contpadnum2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex);
					s8 cstickx2 = contGetStickXOnSample(j, contpadnum2);
					s8 csticky2 = contGetStickYOnSample(j, contpadnum2);
					u16 buttonsstate2 = contGetButtonsOnSample(j, contpadnum2, 0xffff);
					u16 buttonspressed2 = contGetButtonsPressedOnSample(j, contpadnum2, 0xffff);

					if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
						buttonsstate2 = buttonsstate2 & A_BUTTON;
						cstickx2 = 0;
						csticky2 = 0;
						buttonspressed2 = 0;
					}

					if (buttonsstate2 & A_BUTTON) {
						stayopen = true;
					}

					if (buttonspressed2 & Z_TRIG) {
						toggle = true;
					}

					if (buttonsstate2 & U_CBUTTONS) {
						row = 0;
					}

					if (buttonsstate2 & D_CBUTTONS) {
						row = 2;
					}

					if (buttonsstate2 & L_CBUTTONS) {
						column = 0;
					}

					if (buttonsstate2 & R_CBUTTONS) {
						column = 2;
					}

					if (buttonsstate2 & U_JPAD) {
						row = 0;
					}

					if (buttonsstate2 & D_JPAD) {
						row = 2;
					}

					if (buttonsstate2 & L_JPAD) {
						column = 0;
					}

					if (buttonsstate2 & R_JPAD) {
						column = 2;
					}

					absstickx = cstickx2 < 0 ? -cstickx2 : cstickx2;
					abssticky = csticky2 < 0 ? -csticky2 : csticky2;

					if (absstickx > 20 || abssticky > 20) {
						if ((f32)abssticky / (f32)absstickx < 0.268f) {
							row = 1;
							column = cstickx2 < 0 ? 0 : 2;
						} else if ((f32)absstickx / (f32)abssticky < 0.268f) {
							column = 1;
							row = csticky2 < 0 ? 2 : 0;
						} else {
							column = cstickx2 < 0 ? 0 : 2;
							row = csticky2 < 0 ? 2 : 0;
						}

						stickpushed = true;
					}
				}

				absstickx = cstickx < 0 ? -cstickx : cstickx;
				abssticky = csticky < 0 ? -csticky : csticky;

				if (absstickx > 20 || abssticky > 20) {
					stickpushed = true;

					if ((f32)abssticky / (f32)absstickx < 0.268f) {
						column = cstickx < 0 ? 0 : 2;
						row = 1;
					} else if ((f32)absstickx / (f32)abssticky < 0.268f) {
						column = 1;
						row = csticky < 0 ? 2 : 0;
					} else {
						column = cstickx < 0 ? 0 : 2;
						row = csticky < 0 ? 2 : 0;
					}
				}

				if (g_Vars.currentplayer->isdead) {
					stayopen = false;
				}

				if (g_Vars.lvupdate240 == 0) {
					stayopen = false;
				}

				if (!stayopen &&
						(g_Vars.currentplayer->activemenumode != AMMODE_EDIT || g_Menus[g_MpPlayerNum].curframe == NULL)) {
					activemenuClose();
					break;
				}

				if (buttonspressed & Z_TRIG) {
					toggle = true;
				}

				if (toggle) {
					if (g_ActiveMenus[g_ActiveMenuIndex].screenindex >= 2) {
						if (g_Vars.numaibuddies && g_MissionConfig.iscoop) {
							// Bot command screen, in coop with AI buddies
							if (g_ActiveMenus[g_ActiveMenuIndex].slotnum == 4) {
								gotonextscreen = true;
							} else {
								activemenuApply(g_ActiveMenus[g_ActiveMenuIndex].slotnum);
							}
						} else {
							// Bot command screen, in multiplayer
							if (g_ActiveMenuMpBotCommands[g_ActiveMenus[g_ActiveMenuIndex].slotnum] == MPBOTCOMMAND_ATTACK) {
								mpOpenPickTarget();
							} else if (g_ActiveMenus[g_ActiveMenuIndex].allbots == false) {
								gotonextscreen = true;
							}

							if (g_ActiveMenus[g_ActiveMenuIndex].slotnum != 4) {
								activemenuApply(g_ActiveMenus[g_ActiveMenuIndex].slotnum);
							}
						}
					} else {
						// Weapon or function screen
						if (g_ActiveMenus[g_ActiveMenuIndex].slotnum == 4) {
							gotonextscreen = true;
						} else {
							activemenuApply(g_ActiveMenus[g_ActiveMenuIndex].slotnum);
						}
					}
				}

				if (gotonextscreen) {
					activemenuChangeScreen(gotonextscreen);

					// If weapon has no functions, skip past function screen
					if (g_ActiveMenus[g_ActiveMenuIndex].screenindex == 1) {
						struct weaponfunc *pri = weaponGetFunction(&g_Vars.currentplayer->hands[0].weaponnum, FUNC_PRIMARY);
						struct weaponfunc *sec = weaponGetFunction(&g_Vars.currentplayer->hands[0].weaponnum, FUNC_SECONDARY);

						if (!pri && !sec) {
							activemenuChangeScreen(gotonextscreen);
						}
					}
				}

				slotnum = column * 1 + row * 3;

				if (g_Vars.currentplayer->activemenumode != AMMODE_EDIT) {
					if (slotnum == 4) {
						if (g_ActiveMenus[g_ActiveMenuIndex].returntimer <= 0) {
							g_ActiveMenus[g_ActiveMenuIndex].returntimer = 0;
							g_ActiveMenus[g_ActiveMenuIndex].slotnum = slotnum;
						} else {
							g_ActiveMenus[g_ActiveMenuIndex].returntimer--;
						}
					} else {
						bool gotoslot = true;
						char text[28];
						u32 flags;

						activemenuGetSlotDetails(slotnum, &flags, text);

						if (strcmp(text, "") == 0) {
							gotoslot = false;
						}

						// If focusing a corner slot with C buttons or J pad,
						// set a special timer for the release. The player is
						// unlikely to release both C buttons on the same frame,
						// so this gives a bit of grace and prevents accidental
						// movement to a neighbouring slot.
						if (g_ActiveMenus[g_ActiveMenuIndex].slotnum != 4
								&& !stickpushed
								&&
								(g_ActiveMenus[g_ActiveMenuIndex].slotnum == 0
								 || g_ActiveMenus[g_ActiveMenuIndex].slotnum == 2
								 || g_ActiveMenus[g_ActiveMenuIndex].slotnum == 6
								 || g_ActiveMenus[g_ActiveMenuIndex].slotnum == 8)) {
							if (slotnum != g_ActiveMenus[g_ActiveMenuIndex].fromslotnum) {
								g_ActiveMenus[g_ActiveMenuIndex].cornertimer = 2;
								g_ActiveMenus[g_ActiveMenuIndex].fromslotnum = slotnum;
								gotoslot = false;
							}

							if (g_ActiveMenus[g_ActiveMenuIndex].cornertimer > 0 && gotoslot) {
								gotoslot = false;
								g_ActiveMenus[g_ActiveMenuIndex].cornertimer--;
							}
						}

						if (gotoslot) {
							g_ActiveMenus[g_ActiveMenuIndex].returntimer = 15;
							g_ActiveMenus[g_ActiveMenuIndex].slotnum = slotnum;
						}
					}
				}
			}
		}

		if (g_Vars.currentplayer->activemenumode != AMMODE_EDIT) {
			s16 dist;
			s16 dstradius;

			if (g_ActiveMenus[g_ActiveMenuIndex].dstx != -123) {
				s16 dist;

				// Update selection x/y values
				g_ActiveMenus[g_ActiveMenuIndex].selx = (g_ActiveMenus[g_ActiveMenuIndex].selx + g_ActiveMenus[g_ActiveMenuIndex].dstx) / 2;
				g_ActiveMenus[g_ActiveMenuIndex].sely = (g_ActiveMenus[g_ActiveMenuIndex].sely + g_ActiveMenus[g_ActiveMenuIndex].dsty) / 2;

				dist = g_ActiveMenus[g_ActiveMenuIndex].selx - g_ActiveMenus[g_ActiveMenuIndex].dstx;

				if (dist <= 1 && dist >= -1) {
					g_ActiveMenus[g_ActiveMenuIndex].selx = g_ActiveMenus[g_ActiveMenuIndex].dstx;
				}

				dist = g_ActiveMenus[g_ActiveMenuIndex].sely - g_ActiveMenus[g_ActiveMenuIndex].dsty;

				if (dist <= 1 && dist >= -1) {
					g_ActiveMenus[g_ActiveMenuIndex].sely = g_ActiveMenus[g_ActiveMenuIndex].dsty;
				}
			}

			// Update x radius (the expanding effect when a new screen is loaded)
			dstradius = g_ActiveMenus[g_ActiveMenuIndex].slotwidth + 5;

			g_ActiveMenus[g_ActiveMenuIndex].xradius = (g_ActiveMenus[g_ActiveMenuIndex].xradius * 3 + dstradius) / 4;

			dist = g_ActiveMenus[g_ActiveMenuIndex].xradius - dstradius;

			if (dist <= 1 && dist >= -1) {
				g_ActiveMenus[g_ActiveMenuIndex].xradius = dstradius;
			}

			// Update alpha of slots so they fade in
			if (g_ActiveMenus[g_ActiveMenuIndex].alphafrac < 1) {
				g_ActiveMenus[g_ActiveMenuIndex].alphafrac += g_Vars.lvupdate240f / 30.0f;
			}

			if (g_ActiveMenus[g_ActiveMenuIndex].alphafrac > 1) {
				g_ActiveMenus[g_ActiveMenuIndex].alphafrac = 1;
			}

			// Make selection border pulsate
			g_ActiveMenus[g_ActiveMenuIndex].selpulse += g_Vars.lvupdate240f / 5.0f;

			if (g_ActiveMenus[g_ActiveMenuIndex].selpulse > 18.849555969238f) {
				g_ActiveMenus[g_ActiveMenuIndex].selpulse -= 18.849555969238f;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);
}
