#include <ultra64.h>
#include "constants.h"
#include "game/activemenu.h"
#include "game/pdmode.h"
#include "game/bondgun.h"
#include "game/gset.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/options.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

void am_tick(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		set_current_player_num(i);
		g_AmIndex = g_Vars.currentplayernum;

		if (g_AmMenus[g_AmIndex].togglefunc) {
			if (bgun_consider_toggle_gun_function(60, false, true) > 0) {
				g_AmMenus[g_AmIndex].togglefunc = false;
			}
		} else {
			// empty
		}

		if (g_Vars.normmplayerisrunning == false
				&& inv_get_count() != g_AmMenus[g_AmIndex].numitems) {
			am_assign_weapon_slots();
		}

		if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
			s32 controlmode = options_get_control_mode(g_Vars.currentplayerstats->mpindex);
			s8 contpadnum = options_get_contpad_num1(g_Vars.currentplayerstats->mpindex);
			s32 numsamples = joy_get_num_samples();
			s32 j;

			for (j = 0; j < numsamples; j++) {
				s8 gotonextscreen = false;
				s8 cstickx = joy_get_stick_x_on_sample(j, contpadnum);
				s8 csticky = joy_get_stick_y_on_sample(j, contpadnum);
				s8 absstickx;
				s8 abssticky;
				u16 buttonsstate = joy_get_buttons_on_sample(j, contpadnum, 0xffff);
				u16 buttonspressed = joy_get_buttons_pressed_on_sample(j, contpadnum, 0xffff);
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

				g_AmMenus[g_AmIndex].allbots = false;

				if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
					buttonsstate = buttonsstate & A_BUTTON;
					cstickx = 0;
					csticky = 0;
					buttonspressed = 0;
				}

				// JPN fixes the bug that's documented in am_change_screen
				if (controlmode == CONTROLMODE_13 || controlmode == CONTROLMODE_14) {
					if ((buttonsstate & R_TRIG) || (buttonsstate & L_TRIG)) {
						stayopen = true;
					}

					if (buttonsstate & A_BUTTON) {
#if VERSION >= VERSION_JPN_FINAL
						if (g_Vars.currentplayer->numaibuddies > 0) {
							g_AmMenus[g_AmIndex].allbots = true;
						}
#else
						g_AmMenus[g_AmIndex].allbots = true;
#endif
					}
				} else {
					if (buttonsstate & A_BUTTON) {
						stayopen = true;
					}

					if ((buttonsstate & R_TRIG) || (buttonsstate & L_TRIG)) {
#if VERSION >= VERSION_JPN_FINAL
						if (g_Vars.currentplayer->numaibuddies > 0) {
							g_AmMenus[g_AmIndex].allbots = true;
						}
#else
						g_AmMenus[g_AmIndex].allbots = true;
#endif
					}
				}

				// If entering allbots mode, save current screen
				if (g_AmMenus[g_AmIndex].allbots
						&& g_AmMenus[g_AmIndex].screenindex >= 2
						&& g_AmMenus[g_AmIndex].origscreennum == 0) {
					g_AmMenus[g_AmIndex].origscreennum = g_AmMenus[g_AmIndex].screenindex;
					g_AmMenus[g_AmIndex].screenindex = 2;
					am_change_screen(0);
				}

				// If exiting allbots mode, return to original screen
				if (!g_AmMenus[g_AmIndex].allbots
						&& g_AmMenus[g_AmIndex].origscreennum) {
					g_AmMenus[g_AmIndex].screenindex = g_AmMenus[g_AmIndex].origscreennum;
					g_AmMenus[g_AmIndex].origscreennum = 0;
					am_change_screen(0);
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
					s8 contpadnum2 = options_get_contpad_num2(g_Vars.currentplayerstats->mpindex);
					s8 cstickx2 = joy_get_stick_x_on_sample(j, contpadnum2);
					s8 csticky2 = joy_get_stick_y_on_sample(j, contpadnum2);
					u16 buttonsstate2 = joy_get_buttons_on_sample(j, contpadnum2, 0xffff);
					u16 buttonspressed2 = joy_get_buttons_pressed_on_sample(j, contpadnum2, 0xffff);

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

#if VERSION >= VERSION_NTSC_1_0
				if (g_Vars.lvupdate240 == 0) {
					stayopen = false;
				}
#endif

				if (!stayopen &&
						(g_Vars.currentplayer->activemenumode != AMMODE_EDIT || g_Menus[g_MpPlayerNum].curdialog == NULL)) {
					am_close();
					break;
				}

				if (buttonspressed & Z_TRIG) {
					toggle = true;
				}

				if (toggle) {
					if (g_AmMenus[g_AmIndex].screenindex >= 2) {
						if (g_Vars.numaibuddies && g_MissionConfig.iscoop) {
							// Bot command screen, in coop with AI buddies
							if (g_AmMenus[g_AmIndex].slotnum == 4) {
								gotonextscreen = true;
							} else {
								am_apply(g_AmMenus[g_AmIndex].slotnum);
							}
						} else {
							// Bot command screen, in multiplayer
							if (g_AmBotCommands[g_AmMenus[g_AmIndex].slotnum] == AIBOTCMD_ATTACK) {
								am_open_pick_target();
							} else if (g_AmMenus[g_AmIndex].allbots == false) {
								gotonextscreen = true;
#if VERSION < VERSION_NTSC_1_0
								if (g_AmMenus[g_AmIndex].slotnum != 4) {
									am_apply(g_AmMenus[g_AmIndex].slotnum);
								}
#endif
							}

#if VERSION >= VERSION_NTSC_1_0
							if (g_AmMenus[g_AmIndex].slotnum != 4) {
								am_apply(g_AmMenus[g_AmIndex].slotnum);
							}
#endif
						}
					} else {
						// Weapon or function screen
						if (g_AmMenus[g_AmIndex].slotnum == 4) {
							gotonextscreen = true;
						} else {
							am_apply(g_AmMenus[g_AmIndex].slotnum);
						}
					}
				}

				if (gotonextscreen) {
					am_change_screen(gotonextscreen);

					// If weapon has no functions, skip past function screen
					if (g_AmMenus[g_AmIndex].screenindex == 1) {
						struct funcdef *pri = gset_get_funcdef_by_gset_funcnum(&g_Vars.currentplayer->hands[0].gset, FUNC_PRIMARY);
						struct funcdef *sec = gset_get_funcdef_by_gset_funcnum(&g_Vars.currentplayer->hands[0].gset, FUNC_SECONDARY);

						if (!pri && !sec) {
							am_change_screen(gotonextscreen);
						}
					}
				}

				slotnum = column * 1 + row * 3;

				if (g_Vars.currentplayer->activemenumode != AMMODE_EDIT) {
					if (slotnum == 4) {
						if (g_AmMenus[g_AmIndex].returntimer <= 0) {
							g_AmMenus[g_AmIndex].returntimer = 0;
							g_AmMenus[g_AmIndex].slotnum = slotnum;
						} else {
							g_AmMenus[g_AmIndex].returntimer--;
						}
					} else {
						bool gotoslot = true;
						char text[28];
						u32 flags;

						am_get_slot_details(slotnum, &flags, text);

						if (strcmp(text, "") == 0) {
							gotoslot = false;
						}

						// If focusing a corner slot with C buttons or J pad,
						// set a special timer for the release. The player is
						// unlikely to release both C buttons on the same frame,
						// so this gives a bit of grace and prevents accidental
						// movement to a neighbouring slot.
						if (g_AmMenus[g_AmIndex].slotnum != 4
								&& !stickpushed
								&&
								(g_AmMenus[g_AmIndex].slotnum == 0
								 || g_AmMenus[g_AmIndex].slotnum == 2
								 || g_AmMenus[g_AmIndex].slotnum == 6
								 || g_AmMenus[g_AmIndex].slotnum == 8)) {
							if (slotnum != g_AmMenus[g_AmIndex].fromslotnum) {
								g_AmMenus[g_AmIndex].cornertimer = 2;
								g_AmMenus[g_AmIndex].fromslotnum = slotnum;
								gotoslot = false;
							}

							if (g_AmMenus[g_AmIndex].cornertimer > 0 && gotoslot) {
								gotoslot = false;
								g_AmMenus[g_AmIndex].cornertimer--;
							}
						}

						if (gotoslot) {
							g_AmMenus[g_AmIndex].returntimer = 15;
							g_AmMenus[g_AmIndex].slotnum = slotnum;
						}
					}
				}
			}
		}

		if (g_Vars.currentplayer->activemenumode != AMMODE_EDIT) {
			s16 dist;
			s16 dstradius;

			if (g_AmMenus[g_AmIndex].dstx != -123) {
				s16 dist;

				// Update selection x/y values
				g_AmMenus[g_AmIndex].selx = (g_AmMenus[g_AmIndex].selx + g_AmMenus[g_AmIndex].dstx) / 2;
				g_AmMenus[g_AmIndex].sely = (g_AmMenus[g_AmIndex].sely + g_AmMenus[g_AmIndex].dsty) / 2;

				dist = g_AmMenus[g_AmIndex].selx - g_AmMenus[g_AmIndex].dstx;

				if (dist <= 1 && dist >= -1) {
					g_AmMenus[g_AmIndex].selx = g_AmMenus[g_AmIndex].dstx;
				}

				dist = g_AmMenus[g_AmIndex].sely - g_AmMenus[g_AmIndex].dsty;

				if (dist <= 1 && dist >= -1) {
					g_AmMenus[g_AmIndex].sely = g_AmMenus[g_AmIndex].dsty;
				}
			}

			// Update x radius (the expanding effect when a new screen is loaded)
			dstradius = g_AmMenus[g_AmIndex].slotwidth + 5;

			g_AmMenus[g_AmIndex].xradius = (g_AmMenus[g_AmIndex].xradius * 3 + dstradius) / 4;

			dist = g_AmMenus[g_AmIndex].xradius - dstradius;

			if (dist <= 1 && dist >= -1) {
				g_AmMenus[g_AmIndex].xradius = dstradius;
			}

			// Update alpha of slots so they fade in
			if (g_AmMenus[g_AmIndex].alphafrac < 1) {
				g_AmMenus[g_AmIndex].alphafrac += LVUPDATE60FREAL() / 30.0f;
			}

			if (g_AmMenus[g_AmIndex].alphafrac > 1) {
				g_AmMenus[g_AmIndex].alphafrac = 1;
			}

			// Make selection border pulsate
			g_AmMenus[g_AmIndex].selpulse += LVUPDATE60FREAL() / 5.0f;

			if (g_AmMenus[g_AmIndex].selpulse > 18.849555969238f) {
				g_AmMenus[g_AmIndex].selpulse -= 18.849555969238f;
			}
		}
	}

	set_current_player_num(prevplayernum);
}
