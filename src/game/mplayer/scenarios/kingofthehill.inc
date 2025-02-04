/**
 * King of the Hill
 *
 * At the start of the match, a room is chosen as the "hill" and is highlighted
 * in green. When a player enters the hill it changes to their team colour.
 * If the player remains in the hill for the "mphilltime" (this is configurable)
 * then they score a point and a new room is chosen as the next hill.
 *
 * If a second team enters the hill then the timer is paused until the hill is
 * exclusive again. The enemy team must completely clear the hill of opposing
 * players before it is switched to their team.
 *
 * Points are awarded to each player in the hill at the time that it is won.
 */

MenuItemHandlerResult menuhandler_mp_hill_time(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_Vars.mphilltime;
		break;
	case MENUOP_SET:
		g_Vars.mphilltime = (u8)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, lang_get(L_MPWEAPONS_023), data->slider.value + 10); // "%ds/Point"
		break;
	}

	return 0;
}

struct menuitem g_KohOptionsMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_222, // "One-Hit Kills"
		MPOPTION_ONEHITKILLS,
		menuhandler_mp_one_hit_kills,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_223, // "Slow Motion"
		0,
		menuhandler_mp_slow_motion,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_224, // "Fast Movement"
		MPOPTION_FASTMOVEMENT,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_225, // "Display Team"
		MPOPTION_DISPLAYTEAM,
		menuhandler_mp_display_team,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_226, // "No Radar"
		MPOPTION_NORADAR,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_227, // "No Auto-Aim"
		MPOPTION_NOAUTOAIM,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_493, // "Kills Score"
		MPOPTION_KILLSSCORE,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_233, // "Hill on Radar"
		MPOPTION_KOH_HILLONRADAR,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_234, // "Mobile Hill"
		MPOPTION_KOH_MOBILEHILL,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_SLIDER,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_235, // "Time"
		0x0000006e,
		menuhandler_mp_hill_time,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_239, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_KohOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_219, // "Hill Options"
	g_KohOptionsMenuItems,
	mp_options_menu_dialog,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

void koh_read_save(struct savebuffer *buffer)
{
	g_Vars.mphilltime = savebuffer_read_bits(buffer, 8);
}

void koh_write_save(struct savebuffer *buffer)
{
	savebuffer_write_bits(buffer, g_Vars.mphilltime, 8);
}

void koh_init(void)
{
	s32 i;

	g_MpSetup.options |= MPOPTION_TEAMSENABLED;
	g_ScenarioData.koh.hillindex = -1;
	g_ScenarioData.koh.hillcount = 0;
	g_ScenarioData.koh.unk00 = 0;
	g_ScenarioData.koh.occupiedteam = -1;
	g_ScenarioData.koh.elapsed240 = 0;
	g_ScenarioData.koh.hillrooms[0] = -1;
	g_ScenarioData.koh.hillrooms[1] = -1;
	g_ScenarioData.koh.hillpos.x = 0;
	g_ScenarioData.koh.hillpos.y = 0;
	g_ScenarioData.koh.hillpos.z = 0;
	g_ScenarioData.koh.colourfracr = 0.25;
	g_ScenarioData.koh.colourfracg = 1;
	g_ScenarioData.koh.colourfracb = 0.25;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.koh.hillpads); i++) {
		g_ScenarioData.koh.hillpads[i] = -1;
	}
}

void koh_init_props(void)
{
	s16 pad_id = 0;
	struct pad pad;

	if (g_ScenarioData.koh.hillcount > 1) {
		g_ScenarioData.koh.hillindex = random() % g_ScenarioData.koh.hillcount;
		pad_id = g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillindex];
	} else {
		// @bug: If a stage setup file only has one hill, pad_id is not assigned
		// so it will always use the room that contains pad zero.
		g_ScenarioData.koh.hillindex = 0;
	}

	pad_unpack(pad_id, PADFIELD_POS | PADFIELD_ROOM, &pad);

	g_ScenarioData.koh.hillrooms[0] = pad.room;
	g_ScenarioData.koh.hillrooms[1] = -1;
	g_ScenarioData.koh.hillpos.x = pad.pos.x;
	g_ScenarioData.koh.hillpos.y = pad.pos.y;
	g_ScenarioData.koh.hillpos.z = pad.pos.z;
	g_ScenarioData.koh.hillpos.y = cd_find_floor_y_colour_type_at_pos(&g_ScenarioData.koh.hillpos, &g_ScenarioData.koh.hillrooms[0], 0, 0);
	g_ScenarioData.koh.movehill = false;

	room_set_light_op(g_ScenarioData.koh.hillrooms[0], LIGHTOP_HIGHLIGHT, 0, 0, 0);
}

/**
 * A match for this function has only been possible by making heavy reuse of
 * variables, but this impacts readability significantly.
 *
 * To make this code readable, constants have been used to map appropriate names
 * to the underlying variable.
 */
void koh_tick(void)
{
	s32 i;
	s32 hillteam;
	s32 s1;
	s32 s2;
	s32 numchrsinhill;
	s32 dualoccupancy;
	s32 s0;
	s32 previndex;
	f32 targetr;
	f32 targetg;
	f32 targetb;
	char text[64];
	s32 teamsinhill[MAX_TEAMS];
	struct pad pad;
	struct prop *chrsinhill[MAX_MPCHRS];
	struct prop *prop;
	struct chrdata *chr;
	s32 padnum;
	s32 teamindex;

#define hillteam       s0
#define inhill         s1
#define mostchrs       s1
#define playernum1     s1
#define prevplayernum1 s1
#define numteamsinhill s2
#define prevplayernum2 s2
#define playernum2     s2

	if (g_ScenarioData.koh.hillindex == -1) {
		return;
	}

	dualoccupancy = 0;

	if (g_ScenarioData.koh.movehill) {
		// The hill is moving, but first it needs to be returned to the natural
		// colour. This is done using a fade over several frames.
		g_ScenarioData.koh.occupiedteam = -1;
		g_ScenarioData.koh.elapsed240 = 0;

		targetr = 1;
		targetg = 1;
		targetb = 1;

		if (g_ScenarioData.koh.colourfracr >= .95f
				&& g_ScenarioData.koh.colourfracg >= .95f
				&& g_ScenarioData.koh.colourfracb >= .95f) {
			// The old hill is now "natural enough" to set it back to full
			// natural colour and actually choose a new hill.
			room_set_light_op(g_ScenarioData.koh.hillrooms[0], LIGHTOP_NONE, 0, 0, 0);

			// Choose the new hill. Note that hillcount refers to the number of
			// hill options, which is always >= 2.
			padnum = 0;

			if (g_ScenarioData.koh.hillcount >= 2) {
				previndex = g_ScenarioData.koh.hillindex;

				do {
					g_ScenarioData.koh.hillindex = random() % g_ScenarioData.koh.hillcount;
				} while (g_ScenarioData.koh.hillindex == previndex);

				padnum = g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillindex];
			} else {
				g_ScenarioData.koh.hillindex = 0;
			}

			pad_unpack(padnum, PADFIELD_POS | PADFIELD_ROOM, &pad);

			g_ScenarioData.koh.hillrooms[0] = pad.room;
			g_ScenarioData.koh.hillrooms[1] = -1;

			g_ScenarioData.koh.hillpos.x = pad.pos.x;
			g_ScenarioData.koh.hillpos.y = pad.pos.y;
			g_ScenarioData.koh.hillpos.z = pad.pos.z;

			g_ScenarioData.koh.hillpos.y = cd_find_floor_y_colour_type_at_pos(&g_ScenarioData.koh.hillpos, g_ScenarioData.koh.hillrooms, NULL, NULL);

			room_set_light_op(g_ScenarioData.koh.hillrooms[0], LIGHTOP_HIGHLIGHT, 0, 0, 0);

			g_ScenarioData.koh.occupiedteam = -1;
			g_ScenarioData.koh.elapsed240 = 0;
			g_ScenarioData.koh.movehill = false;
		}
	} else {
		// The hill is not moving on this frame
		// Build an array of chr props who are in the hill
		numchrsinhill = 0;
		prop = g_Vars.activeprops;

		while (prop) {
			if (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) {
				inhill = false;

				if (prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
					inhill = true;
				}

				if (inhill) {
					chr = prop->chr;

					if (!chr_is_dead(chr)) {
						chrsinhill[numchrsinhill] = prop;
						numchrsinhill++;
					}
				}
			}

			prop = prop->next;
		}

		// Use the chrshillhill array to build an array of all teams who have
		// chrs in the hill. During development, this array likely stored a
		// count of that team's chrs but was later changed to just be 0 or 1
		// to denote if they have any chrs in the hill.
		for (s0 = 0; s0 < ARRAYCOUNT(teamsinhill); s0++) {
			teamsinhill[s0] = 0;
		}

		for (s0 = 0, numteamsinhill = 0; s0 < numchrsinhill; s0++) {
			chr = chrsinhill[s0]->chr;
			teamindex = radar_get_team_index(chr->team);

			if (teamsinhill[teamindex] == 0) {
				numteamsinhill++;
				teamsinhill[teamindex] = 1;
			}
		}

		if (numteamsinhill == 0) {
			g_ScenarioData.koh.occupiedteam = -1;
			g_ScenarioData.koh.elapsed240 = 0;
		} else {
			if (numteamsinhill == 1) {
				// Set hillteam for later
				for (hillteam = 0; hillteam < MAX_TEAMS; hillteam++) {
					if (teamsinhill[hillteam]) {
						break;
					}
				}
			} else {
				// There are multiple teams in the hill.
				// This code attempts to filter the teamsinhill array to only
				// those which have the most chrs, but the teamsinhill array
				// only contains values 0 or 1 so it effectively does nothing.
				mostchrs = 0;

				for (s0 = 0; s0 < MAX_TEAMS; s0++) {
					if (teamsinhill[s0] > mostchrs) {
						mostchrs = teamsinhill[s0];
					}
				}

				for (s0 = 0; s0 < MAX_TEAMS; s0++) {
					if (teamsinhill[s0] != mostchrs) {
						teamsinhill[s0] = false;
					}
				}

				// Count the number of teams who are tied for the most chrs in
				// the hill. Or rather, because the teamsinhill array only
				// contains 0 or 1 values, this is just recounting the number of
				// teams who have presence in the hill.
				for (s0 = 0; s0 < MAX_TEAMS; s0++) {
					if (teamsinhill[s0]) {
						dualoccupancy++;
					}
				}

				dualoccupancy = dualoccupancy >= 2 ? true : false;

				// Set the hillteam to whoever was holding it previously
				// so the hill remains the same colour
				for (hillteam = 0; hillteam < MAX_TEAMS; hillteam++) {
					if (teamsinhill[hillteam] && hillteam == g_ScenarioData.koh.occupiedteam) {
						break;
					}
				}

				if (hillteam == 8) {
					// This happens if the controlling team leaves the hill
					// and there are two other teams still in the hill.
					// The hill goes green until one team holds it exclusively.
					g_ScenarioData.koh.occupiedteam = -1;
					hillteam = -1;
				}
			}

			// At this point we know there is a team in the hill on this frame.
			// So if these don't match then the hill is turning into a team
			// colour rather than going green.
			if (hillteam != g_ScenarioData.koh.occupiedteam) {
				snd_start(var80095200, SFX_MP_HILLENTERED, 0, -1, -1, -1, -1, -1);

				g_ScenarioData.koh.occupiedteam = hillteam;
				g_ScenarioData.koh.elapsed240 = 0;

				// "%has captured the Hill!"
#if VERSION >= VERSION_JPN_FINAL
				sprintf(text, lang_get(L_MPWEAPONS_022), scenario_remove_line_breaks(g_BossFile.teamnames[hillteam], 0));
#else
				sprintf(text, lang_get(L_MPWEAPONS_022), &g_BossFile.teamnames[hillteam]);
#endif

				prevplayernum2 = g_Vars.currentplayernum;

				for (playernum1 = 0; playernum1 < PLAYERCOUNT(); playernum1++) {
					set_current_player_num(playernum1);

					chr = g_Vars.currentplayer->prop->chr;

#if VERSION >= VERSION_JPN_FINAL
					if (radar_get_team_index(chr->team) == g_ScenarioData.koh.occupiedteam) {
						// "We have the Hill!"
						hudmsg_create_with_flags(lang_get(L_MPWEAPONS_021), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP);
					} else {
						hudmsg_create_with_flags(text, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP);
					}
#else
					if (radar_get_team_index(chr->team) == g_ScenarioData.koh.occupiedteam) {
						// "We have the Hill!"
						hudmsg_create_with_flags(lang_get(L_MPWEAPONS_021), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else {
						hudmsg_create_with_flags(text, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					}
#endif
				}

				set_current_player_num(prevplayernum2);
			} else {
				// A team is remaining in the hill.
				// Only tick the hill timer if they have exclusive occupancy.
				if (!dualoccupancy) {
					g_ScenarioData.koh.elapsed240 += g_Vars.lvupdate240;

					if (g_ScenarioData.koh.elapsed240 >= g_Vars.mphilltime * TICKS(240) + TICKS(2400)) {
						// Scored a point
						snd_start(var80095200, SFX_MP_SCOREPOINT, 0, -1, -1, -1, -1, -1);

						// @bug: There is no check for a chr being dead here.
						// If a player dies in the hill and waits on the
						// "press start" screen while their team mate scores the
						// hill, the dead player will always be awarded a point.
						for (playernum2 = 0; playernum2 < g_MpNumChrs; playernum2++) {
							if (radar_get_team_index(g_MpAllChrPtrs[playernum2]->team) == g_ScenarioData.koh.occupiedteam) {
								prop = g_MpAllChrPtrs[playernum2]->prop;

								if (prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
									g_MpAllChrConfigPtrs[playernum2]->numpoints++;
								}
							}
						}

						prevplayernum1 = g_Vars.currentplayernum;

						for (playernum2 = 0; playernum2 < g_MpNumChrs; playernum2++) {
							if (g_MpAllChrPtrs[playernum2]->aibot == NULL
									&& radar_get_team_index(g_MpAllChrPtrs[playernum2]->team) == g_ScenarioData.koh.occupiedteam) {
								set_current_player_num(playernum2);

								// "King of the Hill!"
#if VERSION >= VERSION_JPN_FINAL
								hudmsg_create_with_flags(lang_get(L_MPWEAPONS_020), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP);
#else
								hudmsg_create_with_flags(lang_get(L_MPWEAPONS_020), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
#endif
							}
						}

						set_current_player_num(prevplayernum1);

						g_ScenarioData.koh.occupiedteam = -1;
						g_ScenarioData.koh.elapsed240 = 0;

						if (g_MpSetup.options & MPOPTION_KOH_MOBILEHILL) {
							g_ScenarioData.koh.movehill = true;
						}
					}
				}
			}
		}

		// Calculate what colour the hill should tween towards
		if (g_ScenarioData.koh.occupiedteam == -1) {
			targetr = 0.25f;
			targetg = 1;
			targetb = 0.25f;
		} else {
			u32 colour = g_TeamColours[g_ScenarioData.koh.occupiedteam];
			targetr = ((s32)(colour >> 24 & 0xff) + 0xff) * (1.0f / 512.0f);
			targetg = ((s32)(colour >> 16 & 0xff) + 0xff) * (1.0f / 512.0f);
			targetb = ((s32)(colour >> 8 & 0xff) + 0xff) * (1.0f / 512.0f);
		}
	}

	// Tween the colour components towards the target colour.
	// @bug: This increments using g_Vars.diffframe60, which is updated while
	// the game is paused. Because of this, if you pause as soon as a hill is
	// scored then the colour fade and selection of the new hill will happen
	// while paused.
	if (g_ScenarioData.koh.colourfracr != targetr) {
		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			g_ScenarioData.koh.colourfracr = 0.0597f * targetr + 0.9403f * g_ScenarioData.koh.colourfracr;
#else
			g_ScenarioData.koh.colourfracr = 0.05f * targetr + 0.95f * g_ScenarioData.koh.colourfracr;
#endif
		}
	}

	if (g_ScenarioData.koh.colourfracg != targetg) {
		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			g_ScenarioData.koh.colourfracg = 0.0597f * targetg + 0.9403f * g_ScenarioData.koh.colourfracg;
#else
			g_ScenarioData.koh.colourfracg = 0.05f * targetg + 0.95f * g_ScenarioData.koh.colourfracg;
#endif
		}
	}

	if (g_ScenarioData.koh.colourfracb != targetb) {
		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			g_ScenarioData.koh.colourfracb = 0.0597f * targetb + 0.9403f * g_ScenarioData.koh.colourfracb;
#else
			g_ScenarioData.koh.colourfracb = 0.05f * targetb + 0.95f * g_ScenarioData.koh.colourfracb;
#endif
		}
	}
}

Gfx *koh_render_hud(Gfx *gdl)
{
	s32 time240;
	s32 mins;
	s32 secs;
	s32 textwidth;
	s32 textheight;
	s32 x;
	s32 y;
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	char text[64];

	if (radar_get_team_index(chr->team) == g_ScenarioData.koh.occupiedteam && !g_ScenarioData.koh.movehill) {
		x = vi_get_view_left() + vi_get_view_width() / 2;
		y = vi_get_view_top() + 10;

		time240 = g_Vars.mphilltime * TICKS(240) - g_ScenarioData.koh.elapsed240;
		time240 += VERSION >= VERSION_PAL_BETA ? TICKS(2640) - 1 : 2400;
		mins = time240 / TICKS(60 * 240);
		time240 -= TICKS(60 * 240) * mins;

#if VERSION >= VERSION_PAL_BETA
		secs = time240 / TICKS(240);
#else
		secs = (time240 + (TICKS(240) - 1)) / TICKS(240);
#endif

		if ((g_Vars.mphilltime * 60 + 600) / 3600) {
			sprintf(text, "%d:%02d", mins, secs);
		} else {
			sprintf(text, "%02d", secs);
		}

		gdl = text_begin(gdl);
		text_measure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x -= textwidth / 2;
		textwidth += x;
		textheight += y;

#if VERSION >= VERSION_NTSC_1_0
		gdl = text_draw_black_textbox(gdl, x, y, textwidth, textheight);
		gdl = text_render_v1(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0xa0, vi_get_width(), vi_get_height(), 0, 0);
#else
		gdl = text_draw_black_box(gdl, &x, &y, &textwidth, &textheight);
		gdl = text_render_v1(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0x88, vi_get_width(), vi_get_height(), 0, 0);
#endif
		gdl = text_end(gdl);
	}

	return gdl;
}

void koh_calculate_player_score(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *loopmpchr;
	s32 i;

	*score = 0;
	*score += mpchr->numpoints;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else {
				loopmpchr = MPCHR(i);

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			}
		}
	}

	*deaths = mpchr->numdeaths;
}

Gfx *koh_radar_extra(Gfx *gdl)
{
	if (g_MpSetup.options & MPOPTION_KOH_HILLONRADAR && !g_ScenarioData.koh.movehill) {
		struct coord dist;
		u32 colour;
		dist.x = g_ScenarioData.koh.hillpos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.koh.hillpos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.koh.hillpos.z - g_Vars.currentplayer->prop->pos.z;

		if (g_ScenarioData.koh.occupiedteam == -1) {
			colour = 0x00ff0000;
		} else {
			colour = g_TeamColours[g_ScenarioData.koh.occupiedteam];
		}

		gdl = radar_draw_dot(gdl, NULL, &dist, colour, 0, 1);
	}

	return gdl;
}

void koh_add_hill(s32 *cmd)
{
	if (g_ScenarioData.koh.hillcount < ARRAYCOUNT(g_ScenarioData.koh.hillpads)) {
		g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillcount] = cmd[1];
		g_ScenarioData.koh.hillcount++;
	}
}

bool koh_is_room_highlighted(RoomNum room)
{
	return room == g_ScenarioData.koh.hillrooms[0];
}

void koh_highlight_room(RoomNum roomnum, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (roomnum == g_ScenarioData.koh.hillrooms[0]) {
		f32 a = *arg1;
		f32 b = *arg2;
		f32 c = *arg3;

		a *= g_ScenarioData.koh.colourfracr;
		b *= g_ScenarioData.koh.colourfracg;
		c *= g_ScenarioData.koh.colourfracb;

		*arg1 = a;
		*arg2 = b;
		*arg3 = c;
	}
}
