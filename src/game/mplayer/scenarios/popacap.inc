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
		menuhandlerMpOneHitKills,
	},
	{
		MENUITEMTYPE_DROPDOWN,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_223, // "Slow Motion"
		0,
		menuhandlerMpSlowMotion,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_224, // "Fast Movement"
		MPOPTION_FASTMOVEMENT,
		menuhandlerMpCheckboxOption,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_225, // "Display Team"
		MPOPTION_DISPLAYTEAM,
		menuhandlerMpDisplayTeam,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_226, // "No Radar"
		MPOPTION_NORADAR,
		menuhandlerMpCheckboxOption,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_227, // "No Auto-Aim"
		MPOPTION_NOAUTOAIM,
		menuhandlerMpCheckboxOption,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_OPTIONS_493, // "Kills Score"
		MPOPTION_KILLSSCORE,
		menuhandlerMpCheckboxOption,
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
		menuhandlerMpCheckboxOption,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_238, // "Show on Radar"
		MPOPTION_PAC_SHOWONRADAR,
		menuhandlerMpCheckboxOption,
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
	mpOptionsMenuDialog,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

void pacReset(void)
{
	s32 i;
	s32 j;
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	data->victimindex = -1;
	data->age240 = 0;


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


	for (j = 0; j < g_MpNumChrs; j++) {
	}

}

static void pacInit(void)
{
	pacReset();
}

static void pacInitProps(void)
{
	pacReset();
}

static bool pacHighlightProp(struct prop *prop, s32 *colour)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (g_MpSetup.options & MPOPTION_PAC_HIGHLIGHTTARGET
			&& (prop->type & (PROPTYPE_PLAYER | PROPTYPE_CHR))
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

void pacApplyNextVictim(void)
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
			sprintf(text, langGet(L_MPWEAPONS_013)); // "You are the victim!"
		} else if (scenarioChrsAreSameTeam(vplayernum, i)) {
			sprintf(text, langGet(L_MPWEAPONS_014), g_MpAllChrConfigPtrs[vplayernum]->name); // "Protect %s!"
		} else {
			sprintf(text, langGet(L_MPWEAPONS_015), g_MpAllChrConfigPtrs[vplayernum]->name); // "Get %s!"
		}

		scenarioCreateHudmsg(i, text);
	}
}

void pacHandleDeath(s32 aplayernum, s32 vplayernum)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (data->victimindex >= 0 && vplayernum == data->victims[data->victimindex]) {
		if (aplayernum != vplayernum) {
			if (aplayernum >= 0) {
				if (scenarioChrsAreSameTeam(aplayernum, vplayernum)) {
					scenarioCreateHudmsg(aplayernum, langGet(L_MPWEAPONS_008)); // "You're supposed to look"
					scenarioCreateHudmsg(aplayernum, langGet(L_MPWEAPONS_009)); // "after your friends!"
				} else {
					data->killcounts[aplayernum]++;
					scenarioCreateHudmsg(aplayernum, langGet(L_MPWEAPONS_010)); // "Well done!"
					scenarioCreateHudmsg(aplayernum, langGet(L_MPWEAPONS_011)); // "You popped a cap!"
					scenarioCreateHudmsg(aplayernum, langGet(L_MPWEAPONS_012)); // "Have 2 Points..."
				}
			}

			pacApplyNextVictim();
		} else {
			data->age240 = 0;
		}
	}
}

static void pacTick(void)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (data->victimindex == -1) {
		pacApplyNextVictim();
	}

	if (data->victimindex >= 0) {
		if (data->victims[data->victimindex] >= PLAYERCOUNT() ||
				g_Vars.players[data->victims[data->victimindex]]->isdead == false) {
			data->age240 += g_Vars.lvupdate240;

			if (data->age240 > (u32)TICKS(240 * 60)) {
				data->age240 = 0;
				data->survivalcounts[data->victims[data->victimindex]]++;
				scenarioCreateHudmsg(data->victims[data->victimindex], langGet(L_MPWEAPONS_007)); // "Have a point for living!"
			}
		}
	}
}

static Gfx *pacRenderHud(Gfx *gdl)
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

	if (g_Vars.currentplayernum == data->victims[data->victimindex] && !g_Vars.currentplayer->isdead) {
		time240 = TICKS(60 * 240) - data->age240;
		x = g_ViBackData->viewleft + g_ViBackData->viewx / 2;
		y = g_ViBackData->viewtop + 10;

		if (time240 < 0) {
			time240 = 0;
		}

		mins = time240 / TICKS(60 * 240);
		time240 -= TICKS(60 * 240) * mins;
		secs = (time240 + (TICKS(240) - 1)) / TICKS(240);
		sprintf(text, "%d:%02d", mins, secs);

		gdl = text0f153628(gdl);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x -= textwidth / 2;
		textwidth += x;
		textheight += y;

		gdl = text0f153990(gdl, x, y, textwidth, textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0xa0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		gdl = text0f153780(gdl);
	}

	return gdl;
}

static void pacCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchrconfig *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(mpchrnum);

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

static bool pacRadarChr(Gfx **gdl, struct prop *prop)
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
				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				*gdl = radarDrawDot(*gdl, vprop, &dist, colour, 0, 1);
			} else {
				*gdl = radarDrawDot(*gdl, vprop, &dist, 0x00ff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}
