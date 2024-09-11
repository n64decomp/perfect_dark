/**
 * Hack that Mac (also known as Hacker Central)
 *
 * A data uplink and a terminal are spawned into a random location in the arena.
 * Players must pick up the data uplink then go to the terminal and download
 * data from it to score points. Each download takes 20 seconds and the player
 * cannot use weapons while uplinking.
 */

#define HTM_NUM_TERMINALS 1

struct menuitem g_HtmOptionsMenuItems[] = {
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
		L_MPMENU_231, // "Highlight Terminal"
		MPOPTION_HTM_HIGHLIGHTTERMINAL,
		menuhandler_mp_checkbox_option,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		MENUITEMFLAG_LOCKABLEMINOR,
		L_MPMENU_238, // "Show on Radar"
		MPOPTION_HTM_SHOWONRADAR,
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

struct menudialogdef g_HtmOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_217, // "Hacker Options"
	g_HtmOptionsMenuItems,
	mp_options_menu_dialog,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct weaponobj g_HtmUplinkObj;

void htm_init(void)
{
	g_ScenarioData.htm.uplink = NULL;
}

/**
 * Add one for the data uplink.
 */
s32 htm_num_props(void)
{
	return HTM_NUM_TERMINALS + 1;
}

void htm_add_pad(s16 padnum)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;

#if VERSION >= VERSION_NTSC_1_0
	if (data->numpads < ARRAYCOUNT(g_ScenarioData.htm.padnums))
#endif
	{
		osSyncPrintf("HackThatMacAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n", data->numpads, padnum);

		data->padnums[data->numpads] = padnum;
		data->numpads++;
	}
}

void htm_reset(void)
{
	s32 i;

	osSyncPrintf("HackThatMacReset -> Working\n");

	g_ScenarioData.htm.numpads = 0;
	g_ScenarioData.htm.numterminals = 0;
	g_ScenarioData.htm.unk138 = 0;
	g_ScenarioData.htm.dlplayernum = -1;
	g_ScenarioData.htm.playernuminrange = -1;
	g_ScenarioData.htm.dlterminalnum = -1;
	g_ScenarioData.htm.unk140 = 0;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.numpoints); i++) {
		g_ScenarioData.htm.numpoints[i] = 0;
		g_ScenarioData.htm.dltime240[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.padnums); i++) {
		g_ScenarioData.htm.padnums[i] = -1;
	}

	for (i = 0; i < HTM_NUM_TERMINALS; i++) {
		g_ScenarioData.htm.terminals[i].unk00 = 0;
		g_ScenarioData.htm.terminals[i].prop = NULL;
		g_ScenarioData.htm.terminals[i].padnum = -1;
		g_ScenarioData.htm.terminals[i].team = 255;
		g_ScenarioData.htm.terminals[i].unk0b = 255;
	}
}

void htb_create_uplink(void)
{
	struct weaponobj template = {
		512,                    // extrascale
		0,                      // hidden2
		OBJTYPE_WEAPON,         // type
		MODEL_CHRDATATHIEF,     // modelnum
		0,                      // pad
		OBJFLAG_FALL | OBJFLAG_INVINCIBLE | OBJFLAG_FORCENOBOUNCE,
		OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_IMMUNETOEXPLOSIONS,
		0,                      // flags3
		NULL,                   // prop
		NULL,                   // model
		1, 0, 0,                // realrot
		0, 1, 0,
		0, 0, 1,
		0,                      // hidden
		NULL,                   // geo
		NULL,                   // projectile
		0,                      // damage
		1000,                   // maxdamage
		0xff, 0xff, 0xff, 0x00, // shadecol
		0xff, 0xff, 0xff, 0x00, // nextcol
		0x0fff,                 // floorcol
		0,                      // tiles
		WEAPON_DATAUPLINK,      // weaponnum
		0,                      // upgradewant
		0,                      // miscbyte
		FUNC_PRIMARY,           // gunfunc
		0,                      // fadeouttimer60
		-1,                     // dualweaponnum
		-1,                     // timer240
		NULL,                   // dualweapon
	};

	struct prop *prop = g_Vars.activeprops;
	struct defaultobj *obj;
	s32 padnum;
	s32 count = 0;
	struct defaultobj *candidates[20];

	while (prop && count < 20) {
#if VERSION >= VERSION_NTSC_1_0
		if (prop->type == PROPTYPE_OBJ)
#endif
		{
			obj = prop->obj;

			if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
				candidates[count] = obj;
				count++;
			}
		}

		prop = prop->next;
	}

	if (count > 0) {
		count = random() % count;
		var800869ec = candidates[count];
		var800869ec->hidden |= OBJHFLAG_DELETING;
		var800869ec->hidden2 |= OBJH2FLAG_CANREGEN;
		padnum = var800869ec->pad;
	} else if (g_ScenarioData.htm.numpads > 0) {
		padnum = g_ScenarioData.htm.padnums[random() % g_ScenarioData.htm.numpads];
	} else {
		padnum = 0;
	}

	g_HtmUplinkObj = template;
	g_HtmUplinkObj.base.pad = padnum;

	setup_place_weapon(&g_HtmUplinkObj, 999);

	g_HtmUplinkObj.base.hidden2 &= ~OBJH2FLAG_CANREGEN;

	g_ScenarioData.htm.uplink = g_HtmUplinkObj.base.prop;

	if (g_ScenarioData.htm.uplink) {
		g_ScenarioData.htm.uplink->forcetick = true;
	}
}

void htm_init_props(void)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	struct prop *prop = g_Vars.activeprops;
	s32 i = 0;
	s32 rand;

	osSyncPrintf("HackThatMacInitProps -> Start : %d Bank Pads\n", data->numterminals);

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;

			if (obj->type == OBJTYPE_AMMOCRATE || obj->type == OBJTYPE_MULTIAMMOCRATE) {
				if (obj->modelnum == MODEL_MULTI_AMMO_CRATE) {
					osSyncPrintf("HackThatMacInitProps -> Adding prop %d (%x)\n", i, obj->pad);
					htm_add_pad(obj->pad);
				}
			}
		}

		prop = prop->next;
		i++;
	}

	osSyncPrintf("HackThatMacInitProps -> Mid : %d Bank Pads\n", data->numpads);
	osSyncPrintf("HackThatMacInitProps -> Generating %d random box pads from %d in the bank\n", htm_num_props(), data->numpads);

	data->numterminals = 0;

	// @bug: This should be < htm_num_props() - 1 to account for the data uplink,
	// or just < HTM_NUM_TERMINALS. If HTM_NUM_TERMINALS is set to 7 then it
	// will overflow the array.
	while (data->numterminals < htm_num_props()) {
		s32 padnum;

		do {
			rand = random() % data->numpads;
			padnum = data->padnums[rand];
		} while (padnum <= 0);

		data->terminals[data->numterminals].padnum = padnum;
		data->numterminals++;
		data->padnums[rand] = -1;
	}

	osSyncPrintf("HackThatMacInitProps -> %d/%d Random box pads generated - Listing\n", data->numterminals, htm_num_props());

	for (i = 0; i < data->numterminals; i++) {
		osSyncPrintf("Pad %d -> Pad Id = %d\n", i, data->terminals[i].padnum);
	}

	for (i = 0; i < HTM_NUM_TERMINALS; i++) {
		data->terminals[i].prop = scenario_create_obj(MODEL_GOODPC, data->terminals[i].padnum, 0.2f,
				OBJFLAG_FALL | OBJFLAG_INVINCIBLE | OBJFLAG_FORCENOBOUNCE,
				OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_IMMUNETOEXPLOSIONS,
				OBJFLAG3_HTMTERMINAL | OBJFLAG3_INTERACTABLE);
		osSyncPrintf("HackThatMacInitProps -> Building and adding custom prop %d - Pad=%d, Ptr=%08x\n",
				i, data->terminals[i].padnum, data->terminals[i].prop);
		htb_remove_ammo_crate_at_pad(data->terminals[i].padnum);
	}

	var800869ec = NULL;

	htb_create_uplink();

	osSyncPrintf("HackThatMacInitProps -> End\n");
}

void htm_tick(void)
{
	u8 stack[8];
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htm.uplink == NULL || g_ScenarioData.htm.uplink->type != PROPTYPE_WEAPON) {
			var800869ec = NULL;
		} else {
			var800869ec->prop->timetoregen = TICKS(1200);
		}
	}

	g_ScenarioData.htm.uplink = NULL;

	// Check if uplink is on the ground
	prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weaponnum == WEAPON_DATAUPLINK) {
				g_ScenarioData.htm.uplink = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			set_current_player_num(i);

			if (inv_has_data_uplink()) {
				g_ScenarioData.htm.uplink = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	set_current_player_num(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumChrs; i++) {
			if (g_MpAllChrPtrs[i]->aibot->hasuplink) {
				g_ScenarioData.htm.uplink = g_MpAllChrPtrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htm.uplink == NULL) {
		htb_create_uplink();
	}
}

void htm_tick_chr(struct chrdata *chr)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	bool hasuplink;
	s32 playernum;
	s32 i;
	s32 *time;

	if (chr) {
		hasuplink = chr->aibot->hasuplink;
		playernum = mp_player_get_index(chr);
	} else {
		hasuplink = inv_has_data_uplink() && bgun_get_weapon_num(HAND_RIGHT) == WEAPON_DATAUPLINK;
		playernum = g_Vars.currentplayernum;
	}

	time = &data->dltime240[playernum];

	for (i = 0; i < HTM_NUM_TERMINALS; i++) {
		if (data->terminals[i].prop) {
			struct prop *prop = data->terminals[i].prop;
			struct defaultobj *obj = prop->obj;
			s32 activatedbyplayernum = -1;

			if (chr) {
				if (hasuplink) {
					activatedbyplayernum = playernum;
				}
			} else {
				if (obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND) {
					activatedbyplayernum = (obj->hidden & 0xf0000000) >> 28;
				}
			}

			if (playernum == activatedbyplayernum) {
				obj->hidden &= ~OBJHFLAG_ACTIVATED_BY_BOND;
				obj->hidden &= ~0xf0000000;

				if (hasuplink) {
					if (data->dlterminalnum == -1) {
						data->dlterminalnum = i;
						data->dlplayernum = playernum;
						data->playernuminrange = playernum;
						*time = 0;

						if (chr == NULL) {
#if VERSION >= VERSION_JPN_FINAL
							hudmsg_create_with_flags(lang_get(L_MPWEAPONS_018), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP); // "Starting download."
#else
							hudmsg_create_with_flags(lang_get(L_MPWEAPONS_018), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE); // "Starting download."
#endif
							ps_create(NULL, data->terminals[data->dlterminalnum].prop, SFX_01BF, -1,
									-1, PSFLAG_REPEATING, PSFLAG2_MPPAUSABLE, PSTYPE_NONE, NULL, -1, NULL, -1, -1, -1, -1);
						}
					}
				} else {
					if (chr == NULL) {
#if VERSION >= VERSION_JPN_FINAL
						hudmsg_create_with_flags(lang_get(L_MPWEAPONS_019), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP); // "You need to use the Data Uplink."
#else
						hudmsg_create_with_flags(lang_get(L_MPWEAPONS_019), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE); // "You need to use the Data Uplink."
#endif
						snd00010718(NULL, 0, AL_VOL_FULL, AL_PAN_CENTER, SFX_01CC, 1, 1, -1, 1);
					}
				}
			}
		}
	}

	if (playernum == data->dlplayernum && data->dlterminalnum != -1) {
		struct coord *terminalpos = &data->terminals[data->dlterminalnum].prop->pos;
		f32 degrees;
		f32 reldegrees;
		f32 rangexz;
		f32 rangey;
		struct coord *chrpos;
		struct coord dist;
		bool holdinguplink;

		if (chr) {
			chrpos = &chr->prop->pos;
			degrees = RTOD2(BADDTOR(360) - chr_get_theta(chr));
			holdinguplink = chr->aibot->weaponnum == WEAPON_UNARMED;
		} else {
			chrpos = &g_Vars.currentplayer->prop->pos;
			degrees = g_Vars.currentplayer->vv_theta;
			holdinguplink = bgun_get_weapon_num(HAND_RIGHT) == WEAPON_DATAUPLINK;
		}

		dist.x = terminalpos->x - chrpos->x;
		dist.y = terminalpos->y - chrpos->y;
		dist.z = terminalpos->z - chrpos->z;

		rangexz = sqrtf(dist.x * dist.x + dist.z * dist.z);

		rangey = ABS(dist.y);

		reldegrees = degrees + RTOD2(atan2f(dist.x, dist.z));

		while (reldegrees < 180) {
			reldegrees += 360;
		}

		while (reldegrees > 180) {
			reldegrees -= 360;
		}

		if (reldegrees > 0) {
			// empty
		} else {
			reldegrees = -reldegrees;
		}

		osSyncPrintf("HTM : Player %d - Term Pos = (%d,%d,%d)", playernum, (s32)terminalpos->x, (s32)terminalpos->y, (s32)terminalpos->z);
		osSyncPrintf("HTM : Player %d - Play Pos = (%d,%d,%d)", playernum, (s32)chrpos->x, (s32)chrpos->y, (s32)chrpos->z);
		osSyncPrintf("HTM : Player %d - T/P  Rel = (%d,%d,%d)", playernum, (s32)dist.x, (s32)dist.y, (s32)dist.z);

		osSyncPrintf("HTM : Player %d - Range XZ = %d", playernum, rangexz);
		osSyncPrintf("HTM : Player %d - Range Y  = %d", playernum, rangey);
		osSyncPrintf("HTM : Player %d - Angle XZ = %d", playernum, reldegrees);

		if (rangexz > 250 || rangey > 200 || reldegrees > 45 || !holdinguplink) {
			if (rangexz < 250 && rangey < 200) {
				data->playernuminrange = playernum;
			} else {
				data->playernuminrange = -1;
			}

			if (chr == NULL) {
				// "Connection broken."
#if VERSION >= VERSION_JPN_FINAL
				hudmsg_create_with_flags(lang_get(L_MPWEAPONS_017), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP);
#else
				hudmsg_create_with_flags(lang_get(L_MPWEAPONS_017), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
#endif
				ps_stop_sound(data->terminals[data->dlterminalnum].prop, PSTYPE_GENERAL, 0xffff);
				snd00010718(NULL, 0, AL_VOL_FULL, AL_PAN_CENTER, SFX_01CC, 1, 1, -1, 1);
			}

			data->dlterminalnum = -1;
			data->dlplayernum = -1;
			*time = 0;
		} else {
			*time += g_Vars.lvupdate240;

			if (*time > 20 * TICKS(240)) {
				data->numpoints[playernum]++;
				data->playernuminrange = playernum;

				if (chr == NULL) {
					// "Download successful."
#if VERSION >= VERSION_JPN_FINAL
					hudmsg_create_with_flags(lang_get(L_MPWEAPONS_016), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_NOWRAP);
#else
					hudmsg_create_with_flags(lang_get(L_MPWEAPONS_016), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
#endif
					ps_stop_sound(data->terminals[data->dlterminalnum].prop, PSTYPE_GENERAL, 0xffff);
					snd00010718(NULL, 0, AL_VOL_FULL, AL_PAN_CENTER, SFX_01C1, 1, 1, -1, 1);
				}

				data->dlterminalnum = -1;
				data->dlplayernum = -1;
				*time = 0;
			}
		}

		osSyncPrintf("HTM : Player %d - Dwnld Plr=%d, Dwnld Prop=%d\n", playernum, data->playernuminrange, data->terminals[data->dlterminalnum].prop);
		osSyncPrintf("HTM : Player %d - Download Time = %d", playernum, *time);
	}
}

Gfx *htm_render_hud(Gfx *gdl)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	s32 dltime;
	s32 viewleft;
	s32 viewright;
	s32 viewtop;
	s32 a0;
	s32 a1;
	s32 barleft;
	s32 barright;
	s32 t1;
	s32 t6;
	s32 v1;
	s32 s1;

	dltime = data->dltime240[g_Vars.currentplayernum];

	if (data->dlterminalnum != -1 && g_Vars.currentplayernum == data->dlplayernum) {
		viewleft = vi_get_view_left();
		viewright = vi_get_view_left() + vi_get_view_width();
		viewtop = vi_get_view_top();
		t6 = (viewleft + viewright) / 2;
		a1 = vi_get_view_width() / 3;
		barleft = t6 - a1 / 2;
		barright = t6 + a1 / 2;
		s1 = barleft + (s32) (a1 * (dltime / TICKS(4800.0f)));

		gdl = text_begin(gdl);
		gdl = text_begin_boxmode(gdl, 0x60000060);

		gDPFillRectangle(gdl++, barleft, viewtop + 8, barright, viewtop + 16);

		gdl = text_end_boxmode(gdl);
		gdl = text_begin_boxmode(gdl, 0xc00000d0);

		v1 = barleft + 1;
		a0 = barleft;

		while (v1 < s1) {
			gDPFillRectangle(gdl++, a0, viewtop + 8, v1, viewtop + 16);
			v1 += 2;
			a0 += 2;
		}

		gdl = text_end_boxmode(gdl);
		gdl = text_end(gdl);
	}

	return gdl;
}

void htm_calculate_player_score(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(mpchrnum);

	if (index >= 0) {
		*score += g_ScenarioData.htm.numpoints[index] * 2;
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

	*deaths = mpchr->numdeaths;
}

Gfx *htm_radar_extra(Gfx *gdl)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	struct coord dist;
	s32 i;
	struct coord sp88;

	// Red/green/blue/alpha as float and integer
	f32 rf;
	f32 gf;
	f32 bf;
	f32 af;

	u32 ri;
	u32 gi;
	u32 bi;
	u32 ai;

	if (g_MpSetup.options & MPOPTION_HTM_SHOWONRADAR) {
		// Show the uplink
		if (data->uplink && data->uplink->type != PROPTYPE_PLAYER && data->uplink->type != PROPTYPE_CHR) {
			dist.x = data->uplink->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = data->uplink->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = data->uplink->pos.z - g_Vars.currentplayer->prop->pos.z;

			gdl = radar_draw_dot(gdl, data->uplink, &dist, 0x00ff0000, 0x00000000, true);
		}

		// Show the terminal
		for (i = 0; i < HTM_NUM_TERMINALS; i++) {
			if (data->terminals[i].prop) {
				sp88.x = data->terminals[i].prop->pos.x - g_Vars.currentplayer->prop->pos.x;
				sp88.y = data->terminals[i].prop->pos.y - g_Vars.currentplayer->prop->pos.y;
				sp88.z = data->terminals[i].prop->pos.z - g_Vars.currentplayer->prop->pos.z;

				if (data->terminals[i].team == 255) {
					rf = 0;
					gf = 255;
					bf = 0;
					af = 0;
				} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
					u32 colour = g_TeamColours[radar_get_team_index(data->terminals[i].team)];
					rf = (colour >> 24) & 0xff;
					gf = ((colour >> 16) & 0xff);
					bf = ((colour >> 8) & 0xff);
					af = colour & 0xff;
				} else {
					rf = 0;
					gf = 255;
					bf = 0;
					af = 0;
				}

				ri = rf;
				gi = gf;
				bi = bf;
				ai = af;

				if (ri > 255) {
					ri = 255;
				}

				if (gi > 255) {
					gi = 255;
				}

				if (bi > 255) {
					bi = 255;
				}

				if (ai > 255) {
					ai = 255;
				}

				gdl = radar_draw_dot(gdl, data->terminals[i].prop, &sp88,
						(ri << 24) | (gi << 16) | (bi << 8) | ai,
						0x00000000, true);
			}
		}
	}

	return gdl;
}

bool htm_radar_chr(Gfx **gdl, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_HTM_SHOWONRADAR) && g_ScenarioData.htm.uplink) {
		if (prop == g_ScenarioData.htm.uplink &&
				(prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR)) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radar_get_team_index(prop->chr->team)];
				*gdl = radar_draw_dot(*gdl, g_ScenarioData.htm.uplink, &dist, colour, 0, 1);
			} else {
				*gdl = radar_draw_dot(*gdl, g_ScenarioData.htm.uplink, &dist, 0x00ff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool htm_highlight_prop(struct prop *prop, s32 *colour)
{
	if (g_MpSetup.options & MPOPTION_HTM_HIGHLIGHTTERMINAL) {
		bool highlight = false;

		if (prop == g_ScenarioData.htm.uplink) {
			highlight = true;
		} else {
			s32 i;

			for (i = 0; i < HTM_NUM_TERMINALS; i++) {
				if (g_ScenarioData.htm.terminals[i].prop == prop) {
					highlight = true;
					break;
				}
			}
		}

		if (highlight) {
			colour[0] = 0;
			colour[1] = 0xff;
			colour[2] = 0;
			colour[3] = 0x40;

			return true;
		}
	}

	return false;
}
