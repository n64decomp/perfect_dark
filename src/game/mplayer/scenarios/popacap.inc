/**
 * Pop a Cap
 *
 * At the start of the match, a single player is randomly chosen as the victim.
 * Players must kill the victim in order to score, while the victim scores a
 * point for every 60 seconds they remain alive. Once killed, another player is
 * chosen as the victim.
 */

struct menuitem g_PacOptionsMenuItems[] = {
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
		L_MPMENU_230, // "Highlight Target"
		MPOPTION_PAC_HIGHLIGHTTARGET,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_238, // "Show on Radar"
		MPOPTION_PAC_SHOWONRADAR,
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
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPMENU_239, // "Back"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PacOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_218, // "Pop a Cap Options"
	g_PacOptionsMenuItems,
	mp_options_menu_dialog,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

void pac_reset(void)
{
	s32 i;
	s32 j;
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	data->victimindex = -1;
	data->age240 = 0;

	osSyncPrintf("PopACapReset -> num_mplayers=%d : Working\n", g_MpNumChrs);

	for (i = 0; i != MAX_MPCHRS; i++) {
		data->killcounts[i] = 0;
		data->survivalcounts[i] = 0;
	}

	i = 0;

	while (i < g_MpNumChrs) {
		bool isnew;
		s32 victimplayernum = random() % g_MpNumChrs;

		for (j = 0, isnew = true; j < i; j++) {
			if (data->victims[j] == victimplayernum) {
				isnew = false;
				break;
			}
		}

		if (isnew) {
			data->victims[i] = victimplayernum;
			i++;
		}
	}

	osSyncPrintf("PopACapReset -> Generated %d victims for this game : Listing\n", i);

	for (j = 0; j < g_MpNumChrs; j++) {
		osSyncPrintf("PopACapReset -> Victim %d is player %d\n", j, data->victims[j]);
	}

	osSyncPrintf("PopACapReset -> Done\n");
}

void pac_init(void)
{
	pac_reset();
}

void pac_init_props(void)
{
	pac_reset();
}

bool pac_highlight_prop(struct prop *prop, s32 *colour)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (g_MpSetup.options & MPOPTION_PAC_HIGHLIGHTTARGET
			&& (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR)
			&& data->victimindex != -1
			&& prop->chr == g_MpAllChrPtrs[data->victims[data->victimindex]]) {
		colour[0] = 0;
		colour[1] = 0xff;
		colour[2] = 0;
		colour[3] = 0x40;
		return true;
	}

	return false;
}

void pac_apply_next_victim(void)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;
	s32 vplayernum;
	char text[64];
	s32 i;

	data->victimindex++;

	if (data->victimindex == g_MpNumChrs) {
		data->victimindex = 0;
	}

	data->age240 = 0;

	vplayernum = data->victims[data->victimindex];

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (vplayernum == i) {
			sprintf(text, lang_get(L_MPWEAPONS_013)); // "You are the victim!"
		} else if (scenario_chrs_are_same_team(vplayernum, i)) {
#if VERSION >= VERSION_JPN_FINAL
			sprintf(text, lang_get(L_MPWEAPONS_014), scenario_remove_line_breaks(g_MpAllChrConfigPtrs[vplayernum]->name, 0)); // "Protect %s!"
#else
			sprintf(text, lang_get(L_MPWEAPONS_014), g_MpAllChrConfigPtrs[vplayernum]->name); // "Protect %s!"
#endif
		} else {
#if VERSION >= VERSION_JPN_FINAL
			sprintf(text, lang_get(L_MPWEAPONS_015), scenario_remove_line_breaks(g_MpAllChrConfigPtrs[vplayernum]->name, 0)); // "Get %s!"
#else
			sprintf(text, lang_get(L_MPWEAPONS_015), g_MpAllChrConfigPtrs[vplayernum]->name); // "Get %s!"
#endif
		}

		scenario_create_hudmsg(i, text);
	}
}

void pac_handle_death(s32 aplayernum, s32 vplayernum)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (data->victimindex >= 0 && vplayernum == data->victims[data->victimindex]) {
		if (aplayernum != vplayernum) {
			if (aplayernum >= 0) {
				if (scenario_chrs_are_same_team(aplayernum, vplayernum)) {
					scenario_create_hudmsg(aplayernum, lang_get(L_MPWEAPONS_008)); // "You're supposed to look"
					scenario_create_hudmsg(aplayernum, lang_get(L_MPWEAPONS_009)); // "after your friends!"
				} else {
					data->killcounts[aplayernum]++;
					scenario_create_hudmsg(aplayernum, lang_get(L_MPWEAPONS_010)); // "Well done!"
					scenario_create_hudmsg(aplayernum, lang_get(L_MPWEAPONS_011)); // "You popped a cap!"
					scenario_create_hudmsg(aplayernum, lang_get(L_MPWEAPONS_012)); // "Have 2 Points..."
				}
			}

			pac_apply_next_victim();
		} else {
#if VERSION >= VERSION_NTSC_1_0
			data->age240 = 0;
#endif
		}
	}
}

void pac_tick(void)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (data->victimindex == -1) {
		pac_apply_next_victim();
		osSyncPrintf("PopACapTick : Current Victim = %d (Player %d)\n",
				data->victimindex, data->victims[data->victimindex]);
	}

	if (data->victimindex >= 0) {
#if VERSION >= VERSION_NTSC_1_0
		if (data->victims[data->victimindex] >= PLAYERCOUNT() ||
				g_Vars.players[data->victims[data->victimindex]]->isdead == false)
#endif
		{
			data->age240 += g_Vars.lvupdate240;

			if (data->age240 > (u32)TICKS(240 * 60)) {
				data->age240 = 0;
				data->survivalcounts[data->victims[data->victimindex]]++;
				scenario_create_hudmsg(data->victims[data->victimindex], lang_get(L_MPWEAPONS_007)); // "Have a point for living!"
			}
		}
	}
}

Gfx *pac_render_hud(Gfx *gdl)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;
	s32 time240;
	s32 mins;
	s32 secs;
	s32 textwidth;
	s32 textheight;
	s32 x;
	s32 y;
	char text[64];

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayernum == data->victims[data->victimindex] && !g_Vars.currentplayer->isdead)
#else
	if (g_Vars.currentplayernum == data->victims[data->victimindex])
#endif
	{
		time240 = TICKS(60 * 240) - data->age240;
		x = vi_get_view_left() + vi_get_view_width() / 2;
		y = vi_get_view_top() + 10;

		if (time240 < 0) {
			time240 = 0;
		}

		mins = time240 / TICKS(60 * 240);
		time240 -= TICKS(60 * 240) * mins;
		secs = (time240 + (TICKS(240) - 1)) / TICKS(240);
		sprintf(text, "%d:%02d", mins, secs);

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

void pac_calculate_player_score(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchrconfig *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = mp_chrslot_to_chrindex(mpchrnum);

	if (index >= 0) {
		*score += g_ScenarioData.pac.killcounts[index] * 2;
		*score += g_ScenarioData.pac.survivalcounts[index];
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				loopmpchr = MPCHR(i);

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

Gfx *pac_radar_extra(Gfx *gdl)
{
	return gdl;
}

bool pac_radar_chr(Gfx **gdl, struct prop *prop)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;
	struct coord dist;

	if ((g_MpSetup.options & MPOPTION_PAC_SHOWONRADAR) && data->victimindex >= 0) {
		struct prop *vprop = g_MpAllChrPtrs[data->victims[data->victimindex]]->prop;

		if (vprop == prop) {
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radar_get_team_index(prop->chr->team)];
				*gdl = radar_draw_dot(*gdl, vprop, &dist, colour, 0, 1);
			} else {
				*gdl = radar_draw_dot(*gdl, vprop, &dist, 0x00ff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}
