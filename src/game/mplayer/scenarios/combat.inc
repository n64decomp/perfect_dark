/**
 * Combat
 *
 * This is a general combat scenario.
 *
 * There are no callback functions or special logic.
 */

struct menuitem g_MpCombatOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222, MPOPTION_ONEHITKILLS,       menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223, 0x00000000,                 menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224, MPOPTION_FASTMOVEMENT,      menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225, MPOPTION_DISPLAYTEAM,       menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226, MPOPTION_NORADAR,           menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227, MPOPTION_NOAUTOAIM,         menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_228, MPOPTION_NOPLAYERHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Player Highlight"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_229, MPOPTION_NOPICKUPHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Pickup Highlight"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239, 0x00000000,                 NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
};

struct menudialog g_MpCombatOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_215, // "Combat Options"
	g_MpCombatOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};
