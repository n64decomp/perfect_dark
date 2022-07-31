#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_006900.h"
#include "game/objectives.h"
#include "game/tex.h"
#include "game/menugfx.h"
#include "game/menuitem.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/objectives.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

u8 g_MpSelectedPlayersForStats[4];

#if VERSION >= VERSION_NTSC_1_0
s32 g_ScissorX1 = 0;
s32 g_ScissorX2 = 0;
s32 g_ScissorY1 = 0;
s32 g_ScissorY2 = 0;
#endif

s32 var800711a0 = 0;
s32 var800711a4 = 0;
s32 g_LineHeight = LINEHEIGHT;

u8 g_KeyboardKeys[5][10] = {
	{ '0','1','2','3','4','5','6','7','8','9' },
	{ 'A','B','C','D','E','F','G','H','I','J' },
	{ 'K','L','M','N','O','P','Q','R','S','T' },
	{ 'U','V','W','X','Y','Z',' ','?','!','.' },
	{ '1','2','1','2','1','2','3','1','2','3' },
};

s32 func0f0e5ce0(s32 value)
{
	if (value < var800711a4) {
		var800711a0++;

		if (var800711a0 > 320) {
			var800711a0 = 0;
		}
	}

	var800711a4 = value;

	return var800711a0;
}

s32 menuitem0f0e5d2c(s32 arg0, struct menuitem *item)
{
	union handlerdata data;
	s32 s0;
	s32 s1;
	s32 a0;
	bool done;
	s32 numgroups;

	if (item->handler == NULL) {
		return 0;
	}

	data.list.value = 0;
	data.list.unk0c = 0;

	item->handler(MENUOP_GETOPTGROUPCOUNT, item, &data);

	if (data.list.value == 0) {
		s1 = arg0 / g_LineHeight;
	} else {
		numgroups = data.list.value;
		s0 = arg0;
		done = false;
		s1 = 0;
		data.list.values32 = 0;
		data.list.unk04 = 0;

		while (!done) {
			if (data.list.values32 < numgroups) {
				item->handler(MENUOP_GETGROUPSTARTINDEX, item, &data);
				a0 = data.list.groupstartindex;
			} else {
				a0 = 9999;
			}

			data.list.value++;

			if (s1 + s0 / g_LineHeight >= a0) {
				s0 = s0 - (a0 - s1) * g_LineHeight - LINEHEIGHT;
				s1 += a0 - s1;
			} else {
				s1 += s0 / g_LineHeight;
				done = true;
			}
		}
	}

	if (s1 < 0) {
		s1 = 0;
	}

	return s1;
}

s16 menuitem0f0e5ef8(s16 arg0, struct menuitem *item)
{
	union handlerdata data;
	bool done;
	s32 numlines;
	s32 numgroups;

	if (item->handler == NULL) {
		return 0;
	}

	if (arg0 < 0) {
		arg0 = 0;
	}

	data.list.value = 0;
	data.list.unk0c = 0;
	item->handler(MENUOP_GETOPTGROUPCOUNT, item, &data);

	if (data.list.value == 0) {
		return arg0 * g_LineHeight;
	}

	done = false;
	numlines = 0;

	numgroups = data.list.value;
	data.list.unk04 = 0;

	for (data.list.value = 0; !done && data.list.values32 < numgroups; data.list.value++) {
		item->handler(MENUOP_GETGROUPSTARTINDEX, item, &data);

		if (arg0 >= data.list.groupstartindex) {
			numlines++;
		} else {
			done = true;
		}
	}

	return arg0 * g_LineHeight + numlines * LINEHEIGHT;
}

Gfx *menuitemListRenderHeader(Gfx *gdl, s16 x1, s16 y1, s16 width, s16 arg4, s16 height, char *text, struct menudialog *dialog)
{
	s32 x;
	s32 y;
	u32 colour;

	colour = MIXCOLOUR(dialog, unk2c);

	if (dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x2c) & 0xffffff00) | (colour & 0xff);
	}

	gdl = text0f153780(gdl);
#if VERSION >= VERSION_NTSC_1_0
	gdl = menugfxDrawListGroupHeader(gdl, x1, y1, x1 + width, y1 + height, x1 + arg4, colour & 0xff);
#else
	gdl = menugfxDrawListGroupHeader(gdl, x1, y1, x1 + width, y1 + height, x1 + arg4);
#endif
	gdl = text0f153628(gdl);

	x = x1 + 3;
	y = y1 + 2;

	colour = MIXCOLOUR(dialog, unk30);

	if (dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x2c) & 0xffffff00) | (colour & 0xff);
	}

	textSetWaveColours(g_MenuColourPalettes3[dialog->type].unk30, g_MenuColourPalettes2[dialog->type].unk30);

	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, width, height, 0, 0);

	return gdl;
}

Gfx *menuitemListOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2)
{
	gDPFillRectangleScaled(gdl++, x, y, x + x2, y + y2);
	return gdl;
}

Gfx *menuitemListRender(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_list *itemdata = &context->data->list;
	union handlerdata sp15c;
	union handlerdata sp14c;
	union handlerdata sp13c;
	char *text2;
	s32 firstonscreenoptionindex;
	s32 x;
	s32 y;
	s32 sp128;
	s32 halfheight;
	bool done2 = false;
	s32 left = context->x + 2;
	s32 tmp;
	s32 s4;
	char *text;
	s32 height;
	s32 numoptions;
	s32 sp104;
	s32 numgroups;
	s32 nextgroupstartindex = 9999;
	s32 optionindex;
	struct font *font = g_FontHandelGothicSm;
	u32 selectedindex;
	s16 width;
	u8 donestickyheader = false;
	u8 done;
	struct fontchar *chars = g_CharsHandelGothicSm;
	u32 colour;
	union handlerdata spd4;
	char *title;

	if (context->item->flags & MENUITEMFLAG_00200000) {
		context->item->handler(MENUOP_GETOPTIONHEIGHT, context->item, &spd4);
		g_LineHeight = spd4.list.value;
	} else {
		g_LineHeight = LINEHEIGHT;
	}

	width = context->dialog->width;

	if (context->item->flags & MENUITEMFLAG_00800000) {
		width = context->width;
	}

#if VERSION >= VERSION_NTSC_1_0
	g_ScissorX1 = context->x * g_ScaleX;
	g_ScissorX2 = (context->x + width) * g_ScaleX;
	g_ScissorY1 = context->y;
	g_ScissorY2 = context->y + context->height;

	if (g_ScissorX1 < 0) {
		g_ScissorX1 = 0;
	}

	if (g_ScissorX2 < 0) {
		g_ScissorX2 = 0;
	}

	if (g_ScissorY1 < 0) {
		g_ScissorY1 = 0;
	}

	if (g_ScissorY2 < 0) {
		g_ScissorY2 = 0;
	}

	if (g_ScissorX1 > viGetBufWidth()) {
		g_ScissorX1 = viGetBufWidth();
	}

	if (g_ScissorX2 > viGetBufWidth()) {
		g_ScissorX2 = viGetBufWidth();
	}

	if (g_ScissorY1 > viGetBufHeight()) {
		g_ScissorY1 = viGetBufHeight();
	}

	if (g_ScissorY2 > viGetBufHeight()) {
		g_ScissorY2 = viGetBufHeight();
	}

	if (g_ScissorX1 > g_ScissorX2) {
		g_ScissorX2 = g_ScissorX1;
	}

	if (g_ScissorY1 > g_ScissorY2) {
		g_ScissorY2 = g_ScissorY1;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
			context->x * g_ScaleX, context->y,
			(context->x + width) * g_ScaleX, context->y + context->height);
#endif

	halfheight = context->height / 2;
	halfheight /= g_LineHeight;
	halfheight *= g_LineHeight;

	itemdata->unk06 = context->height;

	if (context->item->type == MENUITEMTYPE_DROPDOWN || context->item->type == MENUITEMTYPE_PLAYERSTATS) {
		gdl = menugfxDrawDropdownBackground(gdl, context->x, context->y, context->x + context->width, context->y + context->height);

		gdl = menugfxDrawShimmer(gdl, context->x, context->y, context->x + 1, context->y + context->height, 0x0000007f, true, 15, true);
		gdl = menugfxDrawShimmer(gdl, context->x + context->width, context->y, context->x + context->width + 1, context->y + context->height, 0x0000007f, false, 15, true);
		gdl = menugfxDrawShimmer(gdl, context->x, context->y, context->x + context->width, context->y + 1, 0x0000007f, false, 15, true);
		gdl = menugfxDrawShimmer(gdl, context->x, context->y + context->height, context->x + context->width, context->y + context->height + 1, 0x0000007f, false, 15, false);
	}

	if (context->item->handler == NULL) {
		return gdl;
	}

	sp15c.list.value = 0;
	context->item->handler(MENUOP_GETSELECTEDINDEX, context->item, &sp15c);
	selectedindex = sp15c.list.value;

	if (selectedindex >= 0x10000) {
		selectedindex = -1;
	}

	sp104 = context->y + 1;

	context->item->handler(MENUOP_GETOPTIONCOUNT, context->item, &sp15c);
	numoptions = sp15c.list.value;

	tmp = itemdata->unk00 - halfheight;
	firstonscreenoptionindex = menuitem0f0e5d2c(itemdata->unk00 - halfheight, context->item);
	y = context->y + tmp;

	gdl = text0f153628(gdl);

	optionindex = firstonscreenoptionindex;

	sp15c.list.unk04 = 0;

	s4 = menuitem0f0e5ef8(optionindex, context->item) + halfheight - itemdata->unk00;

	sp14c.list.value = 0;
	sp14c.list.unk0c = 0;
	context->item->handler(MENUOP_GETOPTGROUPCOUNT, context->item, &sp14c);
	numgroups = sp14c.list.values32 & 0xffffffff;

	if (numoptions > 0) {
		// If this list uses option groups, draw a sticky group header
		// if the player has scroll down far enough
		if (numgroups != 0) {
			s32 spc8;
			done = false;
			spc8 = 0;
			nextgroupstartindex = 0;
			sp14c.list.values32 = 0;
			sp14c.list.unk04 = 0;

			// Iterate all groups ascending until we find the first one that's
			// on-screen, then take the one before it
			while (!done && sp14c.list.values32 < numgroups) {
				context->item->handler(MENUOP_GETGROUPSTARTINDEX, context->item, &sp14c);
				tmp = sp14c.list.groupstartindex & 0xffffffff;

				if (tmp <= firstonscreenoptionindex) {
					spc8 = sp14c.list.values32;
					nextgroupstartindex = tmp;
					sp14c.list.values32++;
				} else {
					done = true;
				}
			}

			sp13c.list.values32 = spc8;
			sp13c.list.unk04 = 0;
			sp13c.list.unk0c = sp14c.list.unk0c;

			if (nextgroupstartindex < firstonscreenoptionindex || s4 < LINEHEIGHT) {
				text = (char *) context->item->handler(MENUOP_GETOPTGROUPTEXT, context->item, &sp13c);

				if (s4 + g_LineHeight > 0) {
					gdl = menuitemListRenderHeader(gdl, context->x, context->y, context->width, width, LINEHEIGHT, text, context->dialog);
					donestickyheader = true;
				}

				sp104 += LINEHEIGHT;

				sp13c.list.value++;

				if (sp14c.list.values32 < numgroups) {
					context->item->handler(MENUOP_GETGROUPSTARTINDEX, context->item, &sp14c);
					tmp = sp14c.list.groupstartindex & 0xffffffff;
					nextgroupstartindex = tmp;
					sp14c.list.values32++;
				} else {
					nextgroupstartindex = 9999;
				}
			}
		}

		if (firstonscreenoptionindex == nextgroupstartindex) {
			s4 -= LINEHEIGHT;
		}

		// Iterate the options to be drawn
		while (!done2) {
			colour = MIXCOLOUR(context->dialog, unfocused);

			if (context->dialog->dimmed) {
				colour = (colourBlend(colour, 0x00000000, 127) & 0xffffff00) | (colour & 0xff);
			}

			textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);

			if (optionindex == nextgroupstartindex) {
				// Draw a group header. Note that optionindex is not incremented
				// in this branch, but nextgroupstartindex is changed so next time the loop
				// iterates it will enter the else branch.
				if (context->item->flags & MENUITEMFLAG_00200000) {
					gdl = menuApplyScissor(gdl);
				}

				title = (char *) context->item->handler(MENUOP_GETOPTGROUPTEXT, context->item, &sp13c);
				sp13c.list.value++;

				height = context->height - s4;

				if (height > LINEHEIGHT) {
					height = LINEHEIGHT;
				}

				gdl = menuitemListRenderHeader(gdl, context->x, context->y + s4, context->width, width, height, title, context->dialog);

				if (sp14c.list.values32 < numgroups) {
					context->item->handler(MENUOP_GETGROUPSTARTINDEX, context->item, &sp14c);
					tmp = sp14c.list.groupstartindex & 0xffffffff;
					nextgroupstartindex = tmp;
					sp14c.list.value++;
				} else {
					nextgroupstartindex = 9999;
				}

				s4 += LINEHEIGHT;
			} else {
				if (optionindex < numoptions) {
					// Draw an option
					union handlerdata spb8;
					bool spb4 = false;

					if ((s32)selectedindex == optionindex) {
						colour |= 0xffffff00;
					}

					if (optionindex == itemdata->unk02 && context->focused) {
						u32 spb0;
						u32 weight = func0f006b08(40.0f) * 255.0f;

						spb0 = MIXCOLOUR(context->dialog, focused);
						colour = colourBlend(colour, colour & 0xff, 127);
						colour = colourBlend(colour, spb0, weight);

#if VERSION >= VERSION_NTSC_1_0
						// If not transitioning the dialog type
						if ((!(context->dialog->transitionfrac >= 0.0f) || context->dialog->type2 != 0)
								&& (!(context->dialog->transitionfrac < 0.0f) || context->dialog->type != 0)) {
							text0f156024(1);
							spb4 = true;
						}
#else
						text0f156024(1);
						spb4 = true;
#endif
					}

					if (context->item->flags & MENUITEMFLAG_00200000) {
						// The handler wants to override the default rendering
						struct menuitemrenderdata renderdata;
						s32 sp94left;
						s32 sp90top;
						s32 sp8cright;
						s32 sp88bottom;

						renderdata.x = context->x;
						renderdata.y = context->y + s4;
						renderdata.width = context->width;
						renderdata.colour = colour;
						renderdata.unk10 = optionindex == itemdata->unk02;

						sp94left = renderdata.x;
						sp90top = renderdata.y;
						sp8cright = renderdata.x + renderdata.width;
						sp88bottom = renderdata.y + g_LineHeight;

						if (sp90top < context->y) {
							sp90top = context->y;
						}

						if (sp88bottom > context->y + context->height - 1) {
							sp88bottom = context->y + context->height - 1;
						}

						if (donestickyheader && sp90top < context->y + LINEHEIGHT) {
							sp90top = context->y + LINEHEIGHT;
						}

						if (sp94left < 0) {
							sp94left = 0;
						}

						if (sp8cright < 0) {
							sp8cright = 0;
						}

						// This logic doesn't look right...
						if (sp94left / g_ScaleX > viGetWidth()) {
							sp94left = viGetWidth() / g_ScaleX;
						}

						if (sp8cright / g_ScaleX > viGetWidth()) {
							sp8cright = viGetWidth() / g_ScaleX;
						}

						gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
						g_ScissorX1 = sp94left * g_ScaleX;
						g_ScissorX2 = sp8cright * g_ScaleX;
						g_ScissorY1 = sp90top;
						g_ScissorY2 = sp88bottom;

						if (g_ScissorX1 < 0) {
							g_ScissorX1 = 0;
						}

						if (g_ScissorX2 < 0) {
							g_ScissorX2 = 0;
						}

						if (g_ScissorY1 < 0) {
							g_ScissorY1 = 0;
						}

						if (g_ScissorY2 < 0) {
							g_ScissorY2 = 0;
						}

						if (g_ScissorX1 > viGetBufWidth()) {
							g_ScissorX1 = viGetBufWidth();
						}

						if (g_ScissorX2 > viGetBufWidth()) {
							g_ScissorX2 = viGetBufWidth();
						}

						if (g_ScissorY1 > viGetBufHeight()) {
							g_ScissorY1 = viGetBufHeight();
						}

						if (g_ScissorY2 > viGetBufHeight()) {
							g_ScissorY2 = viGetBufHeight();
						}

						if (g_ScissorX2 < g_ScissorX1) {
							g_ScissorX2 = g_ScissorX1;
						}

						if (g_ScissorY2 < g_ScissorY1) {
							g_ScissorY2 = g_ScissorY1;
						}

						gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
						gDPSetScissor(gdl++, G_SC_NON_INTERLACE, sp94left * g_ScaleX, sp90top, sp8cright * g_ScaleX, sp88bottom);
#endif

						spb8.type19.gdl = gdl;
						spb8.type19.unk04 = optionindex;
						spb8.type19.renderdata2 = (void *)((u32)&renderdata & 0xffffffff);
						spb8.type19.unk0c = sp15c.list.unk04;

						gdl = (Gfx *) context->item->handler(MENUOP_RENDER, context->item, &spb8);

						sp15c.list.unk04 = spb8.type19.unk0c;
					} else {
						// Default/simple option (label and optional checkbox)
						sp15c.list.value = optionindex;
						text2 = (char *) context->item->handler(MENUOP_GETOPTIONTEXT, context->item, &sp15c);
						sp128 = 0;
						y = context->y + s4 + 1;

						if (context->item->type == MENUITEMTYPE_DROPDOWN || context->item->type == MENUITEMTYPE_PLAYERSTATS) {
							x = left;
						} else {
							x = left + 8;
						}

						if (y < sp104) {
							sp128 = y - sp104;
							y = sp104;
						}

						height = context->y + context->height - y;

						if (height < 0) {
							height = 0;
						}

						gdl = textRenderProjected(gdl, &x, &y, text2, chars, font, colour, context->width - left + context->x, height, sp128, 0);

						// Consider a checkbox
						spb8.list.value = optionindex;
						spb8.list.unk04 = 255;

						context->item->handler(MENUOP_GETLISTITEMCHECKBOX, context->item, &spb8);

						if (spb8.list.unk04 != 255) {
							gdl = menugfxDrawCheckbox(gdl, left, context->y + s4 + 1, 6, spb8.list.unk04, colour, 0xff00007f);
						}
					}

					if (spb4) {
						text0f156024(0);
					}
				}

				optionindex++;
				s4 += g_LineHeight;

				if (optionindex >= numoptions) {
					done2 = true;
				}
			}

			if (context->height < s4) {
				done2 = true;
			}
		}

		gdl = menuApplyScissor(gdl);
	} else {
		// The list has no options in it
		colour = MIXCOLOUR(context->dialog, unfocused);

		if (context->dialog->dimmed) {
			colour = (colourBlend(colour, 0x00000000, 0x0000007f) & 0xffffff00) | (colour & 0xff);
		}

		x = left + 8;
		y = context->y + context->height / 2;

		// "< Empty >"
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_OPTIONS_313), chars, font, colour, context->width - left + context->x, viGetHeight(), sp128, 0);
	}

	gdl = text0f153780(gdl);

	return gdl;
}

bool menuitemListTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	f32 f0;
	union handlerdata handlerdata;
	union handlerdata handlerdata2;
	s16 min;
	s16 max;
	s32 tmp;
	s32 i;
	u32 last;
	s16 prev2;
	s16 prev;

	if (item->handler == NULL) {
		return true;
	}

	if (item->flags & MENUITEMFLAG_00200000) {
		item->handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2);
		g_LineHeight = handlerdata2.list.value;
	} else {
		g_LineHeight = LINEHEIGHT;
	}

	if (item->type == MENUITEMTYPE_DROPDOWN || item->type == MENUITEMTYPE_PLAYERSTATS) {
		min = data->list.unk06 / 2;
		min = min / g_LineHeight;
		min *= g_LineHeight;

		data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);

		if (data->list.unk04 < min) {
			data->list.unk04 = min;
		}

		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);

		max = handlerdata.list2.unk02 * g_LineHeight - data->list.unk06 + min;

		if (data->list.unk04 > max) {
			data->list.unk04 = max;
		}
	}

	if (data->list.unk00 != data->list.unk04) {
		f0 = data->list.unk00;
		prev = data->list.unk00;

		for (i = 0; i < g_Vars.diffframe60; i++) {
			f0 = data->list.unk04 * (PAL ? 0.404f : 0.35f) + (PAL ? 0.59599995613098f : 0.65f) * f0;
		}

		data->list.unk00 = f0;

		if (data->list.unk00 != data->list.unk04 && prev == data->list.unk00) {
			if (data->list.unk00 < data->list.unk04) {
				data->list.unk00++;
			} else {
				data->list.unk00--;
			}
		}
	}

	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);

		if (handlerdata.list.value) {
			last = handlerdata.list.value - 1;

			if (data->list.unk02 > last) {
				data->list.unk02 = last;
				data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);
			}

			if (inputs->updown) {
				prev2 = data->list.unk02;
				data->list.unk02 += inputs->updown;

				if (data->list.unk02 < 0) {
					data->list.unk02 = handlerdata.list.value - 1;
				}

				if (data->list.unk02 >= (s16)handlerdata.list.value) {
					data->list.unk02 = 0;
				}

				data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);

				if (prev2 != data->list.unk02) {
					handlerdata.list.value = data->list.unk02;
					item->handler(MENUOP_LISTITEMFOCUS, item, &handlerdata);

					menuPlaySound(MENUSOUND_SUBFOCUS);
				}
			}

			if (inputs->select) {
				handlerdata.list.value = data->list.unk02;
				handlerdata.list.unk04 = 0;

				if (inputs->start) {
					handlerdata.list.unk04 = 1;
				}

				item->handler(MENUOP_SET, item, &handlerdata);

				menuPlaySound(MENUSOUND_SELECT);

				if (handlerdata.list.unk04 == 2) {
					inputs->start = false;
				}
			}

			inputs->updown = false;
		}
	}

	tmp = data->list.unk02;
	handlerdata.list.value = tmp;
	handlerdata.list.unk04 = 1;
	handlerdata.list.unk0c = tmp;
	handlerdata.list.groupstartindex = (tickflags & MENUTICKFLAG_ITEMISFOCUSED) ? 1 : 0;

	item->handler(MENUOP_25, item, &handlerdata);

	if (handlerdata.list.unk0c != handlerdata.list.value) {
		data->list.unk02 = handlerdata.list.value;
		data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);
	}

	return true;
}

void menuitemDropdownInit(struct menuitem *item, union menuitemdata *data)
{
	s32 (*handler)(s32 operation, struct menuitem *item, union handlerdata *data);
	union handlerdata handlerdata;
	union handlerdata handlerdata2;

	data->dropdown.unk00 = 0;
	data->dropdown.unk02 = 0;
	data->dropdown.unk08 = 0;
	data->dropdown.unk0a = 0;

	handlerdata.dropdown.value = 0;

	handler = item->handler;

	if (item->flags & MENUITEMFLAG_00200000) {
		handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2);
		g_LineHeight = handlerdata2.dropdown.value;
	} else {
		g_LineHeight = LINEHEIGHT;
	}

	item->handler(MENUOP_GETSELECTEDINDEX, item, &handlerdata);

	if (handlerdata.dropdown.value < 0xffff) {
		data->dropdown.unk02 = handlerdata.dropdown.value;
	} else {
		// The value won't fit in unk02.
		// Maybe MENUOP_25 is getting a scaled-down value?
		// But then how does it know the value is scaled?
		handlerdata.dropdown.value = 0;
		handlerdata.dropdown.unk04 = 0;

		item->handler(MENUOP_25, item, &handlerdata);
		data->dropdown.unk02 = handlerdata.dropdown.value;
	}

	data->dropdown.unk04 = menuitem0f0e5ef8(data->dropdown.unk02, item);

	item->handler(MENUOP_LISTITEMFOCUS, item, &handlerdata);
}

Gfx *menuitemDropdownRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;
	char *text;
	s32 x;
	s32 y;
	union handlerdata data;

	x = context->x;
	y = context->y;
	text = menuResolveParam2Text(context->item);

	colour = MIXCOLOUR(context->dialog, unfocused);

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
	}

	if (context->focused != 0) {
		if ((context->focused & 2) != 0) {
			u32 tmpcolour;
			u32 weight = func0f006b08(20) * 255.0f; \
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		} else {
			u32 tmpcolour;
			u32 weight = func0f006b08(40) * 255.0f; \
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		}

		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].focused, g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		colour = MIXCOLOUR(context->dialog, disabled);

		if (context->dialog->dimmed) {
			colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
		}

		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].disabled, g_MenuColourPalettes2[context->dialog->type].disabled);
	}

	gdl = text0f153628(gdl);

	x = context->x + 10;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);

	if (context->dialog->unk6e) {
		x = context->x + 80;
	} else {
		x = context->x + context->width - 60;
	}

	if (context->item->flags & MENUITEMFLAG_00000080) {
		x = context->x + 30;
	}

	y = context->y + 2;

	if (context->item->handler != NULL) {
		s32 textheight;
		s32 textwidth;

		data.list.value = 0;
		context->item->handler(MENUOP_GETSELECTEDINDEX, context->item, &data);

		data.list.unk04 = 0;
		text = (char *)context->item->handler(MENUOP_GETOPTIONTEXT, context->item, &data);

		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		x = context->x + context->width - textwidth - 10;
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);
	}

	gdl = text0f153780(gdl);

	return gdl;
}

bool menuitemDropdownTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	u32 stack;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && item->handler) {
		if (dialog->dimmed && item == dialog->focuseditem) {
			menuitemListTick(item, inputs, tickflags, data);

			if (mpIsPlayerLockedOut(g_MpPlayerNum)) {
				if ((item->flags & MENUITEMFLAG_00040000) || (dialog->definition->flags & MENUDIALOGFLAG_MPLOCKABLE)) {
					dialog->dimmed = false;
				}
			}
		}

		if (inputs->back && dialog->dimmed) {
			dialog->dimmed = false;
			inputs->back = false;
			menuPlaySound(MENUSOUND_TOGGLEOFF);
		}

		if (inputs->select) {
			if (dialog->dimmed) {
				dialog->dimmed = false;
			} else {
				union handlerdata handlerdata;

				dialog->dimmed = true;
				menuitemDropdownInit(item, data);

				handlerdata.dropdown.value = 0;
				item->handler(MENUOP_GETSELECTEDINDEX, item, &handlerdata);
				data->dropdown.unk0e = (u32)handlerdata.dropdown.value * g_LineHeight;
				menuPlaySound(MENUSOUND_TOGGLEOFF);
			}
		}
	}

	return true;
}

Gfx *menuitemDropdownOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data)
{
	s32 stack;
	s32 textwidth;
	s32 textheight;
	s32 numoptions;
	s32 i;
	char *text;
	struct menurendercontext context;

#if VERSION >= VERSION_NTSC_1_0
	if (dialog->unk6e) {
		context.x = x + 78;
	} else if (x2 < 0) {
		context.x = x + 2;
	} else {
		context.x = x + x2 - 62;
	}
#else
	if (dialog->unk6e) {
		context.x = x + 78;
	} else {
		context.x = x + x2 - 62;
	}
#endif

	if (item->flags & MENUITEMFLAG_00000080) {
		context.x = x + 30;
	}

	context.y = y + 1;
	context.width = 56;
	context.item = item;
	context.focused = true;
	context.dialog = dialog;
	context.data = data;

	if (dialog->dimmed && item->handler && dialog->focuseditem == item) {
		union handlerdata handlerdata;

		if (item->flags & MENUITEMFLAG_00200000) {
			union handlerdata handlerdata2;
			item->handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2); \
			g_LineHeight = handlerdata2.dropdown.value; \
		} else { \
			g_LineHeight = LINEHEIGHT;
		}

		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);
		numoptions = handlerdata.dropdown.value;

		context.width = 0;
		context.height = g_LineHeight * numoptions;

		for (i = 0; i != numoptions; i++) {
			handlerdata.dropdown.value = i;
			text = (char *)item->handler(MENUOP_GETOPTIONTEXT, item, &handlerdata);
			textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			textwidth += 6;

			if (textwidth > context.width) {
				context.width = textwidth;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (x2 > 0) {
			context.x = x + x2 - context.width - 7;
		}
#else
		context.x = x + x2 - context.width - 7;
#endif

		if (context.y + context.height > dialog->y + dialog->height + 2) {
			if (context.height > dialog->height) {
				i = dialog->height;
				i = i / (u32)g_LineHeight;
				i = i * g_LineHeight;
				context.height = i;
			}

			context.y = dialog->y + dialog->height - context.height + 2;
		}

		gdl = menuitemListRender(gdl, &context);
	}

	return gdl;
}

bool menuitemKeyboardIsStringEmptyOrSpaces(char *text)
{
	s32 i;

	if (text[0] == '\0') {
		return true;
	}

	i = 0;

	while (text[i] != '\0') {
		if (text[i] != ' ') {
			return false;
		}

		i++;
	}

	return true;
}

/**
 * Keyboard reference:
 * +---------------------------------------+
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
 * |---+---+---+---+---+---+---+---+---+---|
 * | a | b | c | d | e | f | g | h | i | j |
 * |---+---+---+---+---+---+---+---+---+---|
 * | k | l | m | n | o | p | q | r | s | t |
 * |---+---+---+---+---+---+---+---+---+---|
 * | u | v | w | x | y | z |   | ? | ! | . |
 * |-------+-----------+-----------+-------|
 * |  DEL  |    CAPS   |   CANCEL  |   OK  |
 * +-------+-----------+-----------+-------+
 */
Gfx *menuitemKeyboardRender(Gfx *gdl, struct menurendercontext *context)
{
	char label[8];
	s32 x;
	s32 y;
	struct menuitemdata_keyboard *data = &context->data->keyboard;
	u32 cursorcolour;
	u32 textcolour;
	u32 tmpcolour;
	s32 buttonwidth;
	s32 row;
	s32 col;
	s32 rowspan;
	u32 alpha;
	s32 textheight;
	s32 textwidth;

	label[1] = '\n';
	label[2] = '\0';

	textSetWaveColours(
			g_MenuColourPalettes3[context->dialog->type].unfocused,
			g_MenuColourPalettes2[context->dialog->type].unfocused);

	// Draw input field background
	gdl = textSetPrimColour(gdl, 0x0000ff7f);

	if (context->item->param3 == 0) {
		// Half width
		gDPFillRectangleScaled(gdl++,
				context->x + 4, context->y + 1,
				context->x + 63, context->y + 10);
	} else {
		// Full width
		gDPFillRectangleScaled(gdl++,
				context->x + 4, context->y + 1,
				context->x + 125, context->y + 10);
	}

	// Render text value
	gdl = text0f153838(gdl);

	x = context->x + 4;
	y = context->y + 2;

	gdl = text0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, data->string, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, context->width, context->height, 0, 0);
	gdl = text0f153780(gdl);

	// Render cursor
	alpha = func0f006b08(40) * 255;

	if (context->dialog->transitionfrac < 0) {
		cursorcolour = g_MenuColourPalettes[context->dialog->type].focused;
	} else {
		cursorcolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].focused,
				g_MenuColourPalettes[context->dialog->type].focused,
				context->dialog->colourweight);
	}

	cursorcolour = colourBlend(colourBlend(0x0000ffff, 0x000000ff, 127), cursorcolour, alpha);

	gdl = textSetPrimColour(gdl, cursorcolour);

	gDPFillRectangleScaled(gdl++, x + 1, context->y + 2, x + 3, context->y + 9);

	gdl = text0f153838(gdl);

	// Render horizontal grid lines
	for (row = 0; row < 6; row++) {
		gdl = menugfxDrawFilledRect(gdl, context->x + 4, context->y + row * 11 + 13,
				context->x + 124, context->y + row * 11 + 14, 0x00ffff7f, 0x00ffff7f);
	}

	// Render vertical grid lines
	for (col = 0; col < 11; col++) {
		rowspan = 5;

		if (col == 1 || col == 3 || col == 4 || col == 6 || col == 7 || col == 9) {
			rowspan = 4;
		}

		gdl = menugfxDrawFilledRect(gdl, context->x + col * 12 + 4, context->y + 13,
				context->x + col * 12 + 5, context->y + rowspan * 11 + 14, 0x00ffff7f, 0x00ffff7f);
	}

	gdl = text0f153628(gdl);

	x = context->x + 10;
	y = context->y + 2;

	for (col = 0; col < 10; col++) {
		for (row = 0; row < 5; row++) {
			if (context->dialog->transitionfrac < 0) {
				textcolour = g_MenuColourPalettes[context->dialog->type].unfocused;
			} else {
				textcolour = colourBlend(
						g_MenuColourPalettes[context->dialog->type2].unfocused,
						g_MenuColourPalettes[context->dialog->type].unfocused,
						context->dialog->colourweight);
			}

			if (context->dialog->dimmed) {
				textcolour = colourBlend(textcolour, 0x00000000, 127) & 0xffffff00 | textcolour & 0xff;
			}

			if (data->capseffective && col == 2 && row == 4) {
				// CAPS button - make it yellow
				textcolour = textcolour & 0xff | 0xffff0000;
			}

			// If this button is the focused one, set highlighted colour
			if (col == data->col && row == data->row) {
				alpha = func0f006b08(40) * 255;

				if (context->dialog->transitionfrac < 0) {
					tmpcolour = g_MenuColourPalettes[context->dialog->type].focused;
				} else {
					tmpcolour = colourBlend(
							g_MenuColourPalettes[context->dialog->type2].focused,
							g_MenuColourPalettes[context->dialog->type].focused,
							context->dialog->colourweight);
				}

				textcolour = colourBlend(colourBlend(textcolour, textcolour & 0xff, 127), tmpcolour, alpha);
			}

			x = context->x + col * 12 + 4;
			y = context->y + row * 11 + 15;

			if (row == 4) {
				u16 labels[] = {
					L_OPTIONS_314, // "DEL"
					L_OPTIONS_315, // "CAPS"
					L_OPTIONS_316, // "CANCEL"
					L_OPTIONS_317, // "OK"
				};

				s32 index = -1;

				if (col == 0) {
					index = 0;
				}

				if (col == 2) {
					index = 1;
				}

				if (col == 5) {
					index = 2;
				}

				if (col == 8) {
					index = 3;
				}

				if (index >= 0) {
					buttonwidth = 24;
					y++;

					if (index == 1 || index == 2) {
						buttonwidth = 36;
					}

					textMeasure(&textheight, &textwidth, langGet(labels[index]), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
					x = (buttonwidth - textwidth) / 2 + x;

					// Dim the OK button if string is empty
					if (index == 3 && menuitemKeyboardIsStringEmptyOrSpaces(data->string)) {
						if (context->dialog->transitionfrac < 0) {
							textcolour = g_MenuColourPalettes[context->dialog->type].disabled;
						} else {
							textcolour = colourBlend(
									g_MenuColourPalettes[context->dialog->type2].disabled,
									g_MenuColourPalettes[context->dialog->type].disabled,
									context->dialog->colourweight);
						}

						if (context->dialog->dimmed) {
							textcolour = colourBlend(textcolour, 0, 127) & 0xffffff00 | textcolour & 0xff;
						}

						textSetWaveColours(
								g_MenuColourPalettes3[context->dialog->type].disabled,
								g_MenuColourPalettes2[context->dialog->type].disabled);
					}

					gdl = textRenderProjected(gdl, &x, &y, langGet(labels[index]), g_CharsHandelGothicXs, g_FontHandelGothicXs, textcolour, context->width, context->height, 0, 0);

					if (index == 3 && menuitemKeyboardIsStringEmptyOrSpaces(data->string)) {
						textSetWaveColours(
								g_MenuColourPalettes3[context->dialog->type].unfocused,
								g_MenuColourPalettes2[context->dialog->type].unfocused);
					}
				}
			} else {
				// Alpha-numeric cell
				label[0] = g_KeyboardKeys[row][col];

				if (!data->capseffective && label[0] >= 'A' && label[0] <= 'Z') {
					// Make lowercase
					label[0] += 32;
				}

				textMeasure(&textheight, &textwidth, label, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
				x = (12 - textwidth) / 2 + x;
				gdl = textRenderProjected(gdl, &x, &y, label, g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
			}
		}
	}

	gdl = text0f153780(gdl);

	// Highlight border of focused button
	{
		s32 x1 = context->x + data->col * 12 + 4;
		s32 x2 = context->x + data->col * 12 + 16;
		s32 y1 = context->y + data->row * 11 + 13;
		s32 y2 = context->y + data->row * 11 + 24;

		if (data->row == 4) {
			if (data->col == 8) {
				x2 += 12;
			}

			if (data->col == 5) {
				x2 += 24;
			}

			if (data->col == 2) {
				x2 += 24;
			}

			if (data->col == 0) {
				x2 += 12;
			}
		}

		gdl = menugfxDrawLine(gdl, x1, y1, x2, y1 + 1, -1, -1); // top
		gdl = menugfxDrawLine(gdl, x2, y1, x2 + 1, y2 + 1, -1, -1); // right
		gdl = menugfxDrawLine(gdl, x1, y2, x2, y2 + 1, -1, -1); // bottom
		gdl = menugfxDrawLine(gdl, x1, y1, x1 + 1, y2 + 1, -1, -1); // left
	}

	return gdl;
}

/**
 * Keyboard reference:
 * +---------------------------------------+
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
 * |---+---+---+---+---+---+---+---+---+---|
 * | a | b | c | d | e | f | g | h | i | j |
 * |---+---+---+---+---+---+---+---+---+---|
 * | k | l | m | n | o | p | q | r | s | t |
 * |---+---+---+---+---+---+---+---+---+---|
 * | u | v | w | x | y | z |   | ? | ! | . |
 * |-------+-----------+-----------+-------|
 * |  DEL  |    CAPS   |   CANCEL  |   OK  |
 * +-------+-----------+-----------+-------+
 */
bool menuitemKeyboardTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	struct menuitemdata_keyboard *kb = &data->keyboard;
	union handlerdata handlerdata;
	s32 delete = false;

	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		s16 prevcol = kb->col;
		s16 prevrow = kb->row;

		// Handle left/right movement
		// In most cases the loop only runs once, but on row 4 the buttons span
		// across multiple columns so the loop will run again until the column
		// number is valid.
		if (inputs->leftright != 0) {
			do {
				kb->col += inputs->leftright;

				if (kb->col < 0) {
					kb->col = 9;
				}

				if (kb->col > 9) {
					kb->col = 0;
				}
			} while (kb->row == 4 && kb->col != 0 && kb->col != 2 && kb->col != 5 && kb->col != 8);
		}

		// Handle up/down movement
		if (inputs->updown) {
			kb->row += inputs->updown;

			if (kb->row < 0) {
				kb->row = 4;
			}

			if (kb->row > 4) {
				kb->row = 0;
			}

			// If moving onto row 4, bump column to a valid one
			if (kb->row == 4) {
				if (kb->col == 9) {
					kb->col = 8;
				}

				if (kb->col == 7 || kb->col == 6) {
					kb->col = 5;
				}

				if (kb->col == 3 || kb->col == 4) {
					kb->col = 2;
				}

				if (kb->col == 1) {
					kb->col = 0;
				}
			}
		}

		if (prevcol != kb->col || prevrow != kb->row) {
			menuPlaySound(MENUSOUND_KEYBOARDFOCUS);
		}

		if (inputs->back2) {
			delete = true;
		}

		if (inputs->start) {
			if (item->handler && !menuitemKeyboardIsStringEmptyOrSpaces(kb->string)) {
				menuPlaySound(MENUSOUND_SELECT);

				handlerdata.keyboard.string = kb->string;
				item->handler(MENUOP_SETTEXT, item, &handlerdata);

				menuPopDialog();

				item->handler(MENUOP_SET, item, &handlerdata);
			}

			inputs->start = false;
		}

		if (inputs->select) {
			if (kb->row == 4) {
				// DEL
				if (kb->col == 0) {
					delete = true;
				}

				// CAPS
				if (kb->col == 2) {
					kb->capslock = 1 - kb->capslock;
				}

				// OK
				if (kb->col == 8) {
					if (item->handler && !menuitemKeyboardIsStringEmptyOrSpaces(kb->string)) {
						handlerdata.keyboard.string = kb->string;
						item->handler(MENUOP_SETTEXT, item, &handlerdata);
					}
				}

				// OK or CANCEL
				if (kb->col == 8 || kb->col == 5) {
					s32 ok = (kb->col == 8);

					if (kb->col == 5 || !menuitemKeyboardIsStringEmptyOrSpaces(kb->string)) {
						menuPopDialog();

						if (ok) {
							item->handler(MENUOP_SET, item, &handlerdata);
							menuPlaySound(MENUSOUND_SELECT);
						} else {
							menuPlaySound(MENUSOUND_KEYBOARDCANCEL);
						}

						inputs->select = false;
					}
				}
			} else {
				// Pressed A on number or letter
				s32 appended = false;
				s32 i;
				s32 textwidth;
				s32 textheight;

				if (kb->string[9] == '\0') {
					// String is not full
					i = 0;

					while (!appended) {
						if (kb->string[i] == '\0') {
							u8 key = g_KeyboardKeys[kb->row][kb->col];
							appended = true;

							if (kb->capseffective == 0 && key >= 'A' && key <= 'Z') {
								// Make lowercase
								key += 32;
							}

							kb->string[i] = key;
						}

						i++;
					}

					textMeasure(&textheight, &textwidth, kb->string, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

					if (item->param3 == 0 && textwidth > 58) {
						delete = true;
					}

					if (!delete) {
						menuPlaySound(MENUSOUND_FOCUS);
					}
				}
			}
		}

		// Handle deleting
		if (delete && kb->string[0] != '\0') {
			s32 deleted = false;
			s32 i = 10;

			menuPlaySound(MENUSOUND_FOCUS);

			while (!deleted) {
				if (kb->string[i] != '\0') {
					kb->string[i] = '\0';
					deleted = true;
				}

				i--;
			}
		}
	}

	// Update caps
	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		u32 prev = kb->capseffective;
		kb->capseffective = kb->capslock;

		if (inputs->shoulder) {
			// Invert
			kb->capseffective = 1 - kb->capseffective;
		}

		if (kb->capseffective != prev) {
			if (kb->capseffective) {
				menuPlaySound(MENUSOUND_TOGGLEON);
			} else {
				menuPlaySound(MENUSOUND_TOGGLEOFF);
			}
		}
	}

	return true;
}

void menuitemKeyboardInit(struct menuitem *item, union menuitemdata *data)
{
	u32 stack;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(data->keyboard.string);) {
		data->keyboard.string[i++] = '\0';
	}

	if (item->handler) {
		union handlerdata handlerdata;
		handlerdata.keyboard.string = data->keyboard.string;
		item->handler(MENUOP_GETTEXT, item, &handlerdata);
	}

	data->keyboard.col = 0;
	data->keyboard.row = 4;
	data->keyboard.capseffective = 0;
	data->keyboard.capslock = 0;
}

Gfx *menuitemSeparatorRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;

	if (context->dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	colour = (colour & 0xffffff00) | 0x3f;

#if VERSION >= VERSION_JPN_FINAL
	return menugfxDrawFilledRect(gdl, context->x, context->y, context->x + context->width, context->y + 1, colour, colour);
#else
	return menugfxDrawFilledRect(gdl, context->x, context->y + 2, context->x + context->width, context->y + 3, colour, colour);
#endif
}

u32 var800711e8 = 0x00000000;

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
/*  f0ea654:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0ea658:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0ea65c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ea660:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0ea664:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0ea668:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0ea66c:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0ea670:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0ea674:	11c00002 */ 	beqz	$t6,.JF0f0ea680
/*  f0ea678:	00001025 */ 	move	$v0,$zero
/*  f0ea67c:	2402000e */ 	li	$v0,0xe
.JF0f0ea680:
/*  f0ea680:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0ea684:	3c058007 */ 	lui	$a1,0x8007
/*  f0ea688:	24a51728 */ 	addiu	$a1,$a1,0x1728
/*  f0ea68c:	2484ecd0 */ 	addiu	$a0,$a0,-4912
/*  f0ea690:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f0ea694:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0ea698:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0ea69c:	3c04800a */ 	lui	$a0,0x800a
/*  f0ea6a0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0ea6a4:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0ea6a8:	0fc5baa5 */ 	jal	langGet
/*  f0ea6ac:	9484e6ca */ 	lhu	$a0,-0x1936($a0)
/*  f0ea6b0:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0ea6b4:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0ea6b8:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0ea6bc:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0ea6c0:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea6c4:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ea6c8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea6cc:	00000000 */ 	nop
/*  f0ea6d0:	4502000b */ 	bc1fl	.JF0f0ea700
/*  f0ea6d4:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0ea6d8:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0ea6dc:	2410003c */ 	li	$s0,0x3c
/*  f0ea6e0:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0ea6e4:	01300019 */ 	multu	$t1,$s0
/*  f0ea6e8:	00005012 */ 	mflo	$t2
/*  f0ea6ec:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0ea6f0:	8d6b2cf8 */ 	lw	$t3,0x2cf8($t3)
/*  f0ea6f4:	10000012 */ 	b	.JF0f0ea740
/*  f0ea6f8:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0ea6fc:	906c003d */ 	lbu	$t4,0x3d($v1)
.JF0f0ea700:
/*  f0ea700:	2410003c */ 	li	$s0,0x3c
/*  f0ea704:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ea708:	01900019 */ 	multu	$t4,$s0
/*  f0ea70c:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0ea710:	25ce2ce0 */ 	addiu	$t6,$t6,0x2ce0
/*  f0ea714:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ea718:	00006812 */ 	mflo	$t5
/*  f0ea71c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0ea720:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0ea724:	03100019 */ 	multu	$t8,$s0
/*  f0ea728:	0000c812 */ 	mflo	$t9
/*  f0ea72c:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0ea730:	0fc01a60 */ 	jal	colourBlend
/*  f0ea734:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0ea738:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0ea73c:	8fa30134 */ 	lw	$v1,0x134($sp)
.JF0f0ea740:
/*  f0ea740:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0ea744:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0ea748:	00002825 */ 	move	$a1,$zero
/*  f0ea74c:	5140000b */ 	beqzl	$t2,.JF0f0ea77c
/*  f0ea750:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ea754:	0fc01a60 */ 	jal	colourBlend
/*  f0ea758:	2406002c */ 	li	$a2,0x2c
/*  f0ea75c:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0ea760:	2401ff00 */ 	li	$at,-256
/*  f0ea764:	00415824 */ 	and	$t3,$v0,$at
/*  f0ea768:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0ea76c:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0ea770:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0ea774:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0ea778:	9078003c */ 	lbu	$t8,0x3c($v1)
.JF0f0ea77c:
/*  f0ea77c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0ea780:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ea784:	03100019 */ 	multu	$t8,$s0
/*  f0ea788:	00001012 */ 	mflo	$v0
/*  f0ea78c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ea790:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ea794:	8ca52e60 */ 	lw	$a1,0x2e60($a1)
/*  f0ea798:	0fc54d69 */ 	jal	textSetWaveColours
/*  f0ea79c:	8c842fc8 */ 	lw	$a0,0x2fc8($a0)
/*  f0ea7a0:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0ea7a4:	0fc54b55 */ 	jal	text0f153628
/*  f0ea7a8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea7ac:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0ea7b0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ea7b4:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ea7b8:	24a5ecd8 */ 	addiu	$a1,$a1,-4904
/*  f0ea7bc:	02002025 */ 	move	$a0,$s0
/*  f0ea7c0:	0c004d95 */ 	jal	sprintf
/*  f0ea7c4:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0ea7c8:	3c198008 */ 	lui	$t9,0x8008
/*  f0ea7cc:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0ea7d0:	3c078008 */ 	lui	$a3,0x8008
/*  f0ea7d4:	8ce7014c */ 	lw	$a3,0x14c($a3)
/*  f0ea7d8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0ea7dc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0ea7e0:	02003025 */ 	move	$a2,$s0
/*  f0ea7e4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea7e8:	0fc55d49 */ 	jal	textMeasure
/*  f0ea7ec:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea7f0:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea7f4:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0ea7f8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ea7fc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0ea800:	8dad0148 */ 	lw	$t5,0x148($t5)
/*  f0ea804:	8d6b014c */ 	lw	$t3,0x14c($t3)
/*  f0ea808:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0ea80c:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0ea810:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0ea814:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0ea818:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0ea81c:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0ea820:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea824:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0ea828:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0ea82c:	02003825 */ 	move	$a3,$s0
/*  f0ea830:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea834:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea838:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ea83c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea840:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0ea844:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ea848:	0fc55886 */ 	jal	textRenderProjected
/*  f0ea84c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ea850:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea854:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0ea858:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ea85c:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0ea860:	1140001f */ 	beqz	$t2,.JF0f0ea8e0
/*  f0ea864:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0ea868:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0ea86c:	8d8c0140 */ 	lw	$t4,0x140($t4)
/*  f0ea870:	3c078008 */ 	lui	$a3,0x8008
/*  f0ea874:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f0ea878:	24040055 */ 	li	$a0,0x55
/*  f0ea87c:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0ea880:	02003025 */ 	move	$a2,$s0
/*  f0ea884:	0fc55dde */ 	jal	textWrap
/*  f0ea888:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea88c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ea890:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0ea894:	8dad0140 */ 	lw	$t5,0x140($t5)
/*  f0ea898:	8d6b0144 */ 	lw	$t3,0x144($t3)
/*  f0ea89c:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0ea8a0:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0ea8a4:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0ea8a8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea8ac:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0ea8b0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0ea8b4:	02003825 */ 	move	$a3,$s0
/*  f0ea8b8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea8bc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea8c0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ea8c4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea8c8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0ea8cc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ea8d0:	0fc55886 */ 	jal	textRenderProjected
/*  f0ea8d4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ea8d8:	1000001a */ 	b	.JF0f0ea944
/*  f0ea8dc:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0ea8e0:
/*  f0ea8e0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ea8e4:	24a5ece0 */ 	addiu	$a1,$a1,-4896
/*  f0ea8e8:	02002025 */ 	move	$a0,$s0
/*  f0ea8ec:	0c004d95 */ 	jal	sprintf
/*  f0ea8f0:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea8f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0ea8f8:	3c098008 */ 	lui	$t1,0x8008
/*  f0ea8fc:	8d290148 */ 	lw	$t1,0x148($t1)
/*  f0ea900:	8dce014c */ 	lw	$t6,0x14c($t6)
/*  f0ea904:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0ea908:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0ea90c:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0ea910:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea914:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0ea918:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0ea91c:	02003825 */ 	move	$a3,$s0
/*  f0ea920:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea924:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea928:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea92c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ea930:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0ea934:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0ea938:	0fc55886 */ 	jal	textRenderProjected
/*  f0ea93c:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0ea940:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0ea944:
/*  f0ea944:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0ea948:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea94c:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0ea950:	11a00126 */ 	beqz	$t5,.JF0f0eadec
/*  f0ea954:	25cc0016 */ 	addiu	$t4,$t6,0x16
/*  f0ea958:	0fc25901 */ 	jal	objectiveCheck
/*  f0ea95c:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0ea960:	10400007 */ 	beqz	$v0,.JF0f0ea980
/*  f0ea964:	24010001 */ 	li	$at,0x1
/*  f0ea968:	1041000c */ 	beq	$v0,$at,.JF0f0ea99c
/*  f0ea96c:	24010002 */ 	li	$at,0x2
/*  f0ea970:	10410011 */ 	beq	$v0,$at,.JF0f0ea9b8
/*  f0ea974:	00000000 */ 	nop
/*  f0ea978:	10000015 */ 	b	.JF0f0ea9d0
/*  f0ea97c:	00000000 */ 	nop
.JF0f0ea980:
/*  f0ea980:	0fc5baa5 */ 	jal	langGet
/*  f0ea984:	24045601 */ 	li	$a0,0x5601
/*  f0ea988:	3c0fffff */ 	lui	$t7,0xffff
/*  f0ea98c:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0ea990:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0ea994:	1000000e */ 	b	.JF0f0ea9d0
/*  f0ea998:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.JF0f0ea99c:
/*  f0ea99c:	0fc5baa5 */ 	jal	langGet
/*  f0ea9a0:	24045600 */ 	li	$a0,0x5600
/*  f0ea9a4:	3c1800ff */ 	lui	$t8,0xff
/*  f0ea9a8:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0ea9ac:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0ea9b0:	10000007 */ 	b	.JF0f0ea9d0
/*  f0ea9b4:	afb800c8 */ 	sw	$t8,0xc8($sp)
.JF0f0ea9b8:
/*  f0ea9b8:	0fc5baa5 */ 	jal	langGet
/*  f0ea9bc:	24045602 */ 	li	$a0,0x5602
/*  f0ea9c0:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0ea9c4:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0ea9c8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0ea9cc:	afb900c8 */ 	sw	$t9,0xc8($sp)
.JF0f0ea9d0:
/*  f0ea9d0:	3c098007 */ 	lui	$t1,0x8007
/*  f0ea9d4:	8d291998 */ 	lw	$t1,0x1998($t1)
/*  f0ea9d8:	3c0c800a */ 	lui	$t4,0x800a
/*  f0ea9dc:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0ea9e0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0ea9e4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ea9e8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ea9ec:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0ea9f0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0ea9f4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ea9f8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0ea9fc:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0eaa00:	8d8cebf8 */ 	lw	$t4,-0x1408($t4)
/*  f0eaa04:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0eaa08:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0eaa0c:	11cc0004 */ 	beq	$t6,$t4,.JF0f0eaa20
/*  f0eaa10:	3c078008 */ 	lui	$a3,0x8008
/*  f0eaa14:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0eaa18:	8d6b2cf8 */ 	lw	$t3,0x2cf8($t3)
/*  f0eaa1c:	afab00c8 */ 	sw	$t3,0xc8($sp)
.JF0f0eaa20:
/*  f0eaa20:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0eaa24:	8dad0140 */ 	lw	$t5,0x140($t5)
/*  f0eaa28:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0eaa2c:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f0eaa30:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eaa34:	0fc55d49 */ 	jal	textMeasure
/*  f0eaa38:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0eaa3c:	3c028007 */ 	lui	$v0,0x8007
/*  f0eaa40:	8c421728 */ 	lw	$v0,0x1728($v0)
/*  f0eaa44:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0eaa48:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0eaa4c:	10400002 */ 	beqz	$v0,.JF0f0eaa58
/*  f0eaa50:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0eaa54:	afa200c8 */ 	sw	$v0,0xc8($sp)
.JF0f0eaa58:
/*  f0eaa58:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0eaa5c:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0eaa60:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0eaa64:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0eaa68:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0eaa6c:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0eaa70:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0eaa74:	8d6b0140 */ 	lw	$t3,0x140($t3)
/*  f0eaa78:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0eaa7c:	8d8c0144 */ 	lw	$t4,0x144($t4)
/*  f0eaa80:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0eaa84:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0eaa88:	014e4021 */ 	addu	$t0,$t2,$t6
/*  f0eaa8c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0eaa90:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f0eaa94:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0eaa98:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0eaa9c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0eaaa0:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0eaaa4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eaaa8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eaaac:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0eaab0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0eaab4:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0eaab8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0eaabc:	0fc55886 */ 	jal	textRenderProjected
/*  f0eaac0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0eaac4:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0eaac8:	87a80146 */ 	lh	$t0,0x146($sp)
/*  f0eaacc:	00402025 */ 	move	$a0,$v0
/*  f0eaad0:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0eaad4:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0eaad8:	25080009 */ 	addiu	$t0,$t0,0x9
/*  f0eaadc:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0eaae0:	0fc54bb7 */ 	jal	text0f153780
/*  f0eaae4:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0eaae8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eaaec:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0eaaf0:	8fb8013c */ 	lw	$t8,0x13c($sp)
/*  f0eaaf4:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0eaaf8:	01856023 */ 	subu	$t4,$t4,$a1
/*  f0eaafc:	01851821 */ 	addu	$v1,$t4,$a1
/*  f0eab00:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0eab04:	24b90016 */ 	addiu	$t9,$a1,0x16
/*  f0eab08:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0eab0c:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f0eab10:	87a90146 */ 	lh	$t1,0x146($sp)
/*  f0eab14:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0eab18:	00402025 */ 	move	$a0,$v0
/*  f0eab1c:	252afffe */ 	addiu	$t2,$t1,-2
/*  f0eab20:	afaa00b0 */ 	sw	$t2,0xb0($sp)
/*  f0eab24:	252e0008 */ 	addiu	$t6,$t1,0x8
/*  f0eab28:	afae00ac */ 	sw	$t6,0xac($sp)
/*  f0eab2c:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0eab30:	04610003 */ 	bgez	$v1,.JF0f0eab40
/*  f0eab34:	00035883 */ 	sra	$t3,$v1,0x2
/*  f0eab38:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0eab3c:	00015883 */ 	sra	$t3,$at,0x2
.JF0f0eab40:
/*  f0eab40:	00cb6823 */ 	subu	$t5,$a2,$t3
/*  f0eab44:	25afffe8 */ 	addiu	$t7,$t5,-24
/*  f0eab48:	01f90019 */ 	multu	$t7,$t9
/*  f0eab4c:	24010005 */ 	li	$at,0x5
/*  f0eab50:	01601825 */ 	move	$v1,$t3
/*  f0eab54:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0eab58:	00005012 */ 	mflo	$t2
/*  f0eab5c:	00000000 */ 	nop
/*  f0eab60:	00000000 */ 	nop
/*  f0eab64:	0141001a */ 	div	$zero,$t2,$at
/*  f0eab68:	00004812 */ 	mflo	$t1
/*  f0eab6c:	01697021 */ 	addu	$t6,$t3,$t1
/*  f0eab70:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f0eab74:	25cc0013 */ 	addiu	$t4,$t6,0x13
/*  f0eab78:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f0eab7c:	010b6821 */ 	addu	$t5,$t0,$t3
/*  f0eab80:	25b80005 */ 	addiu	$t8,$t5,0x5
/*  f0eab84:	0fc38c93 */ 	jal	menugfx0f0e2498
/*  f0eab88:	afb800a8 */ 	sw	$t8,0xa8($sp)
/*  f0eab8c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0eab90:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0eab94:	2401ff00 */ 	li	$at,-256
/*  f0eab98:	0061c824 */ 	and	$t9,$v1,$at
/*  f0eab9c:	3730003f */ 	ori	$s0,$t9,0x3f
/*  f0eaba0:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*  f0eaba4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0eaba8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eabac:	03201825 */ 	move	$v1,$t9
/*  f0eabb0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0eabb4:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f0eabb8:	00402025 */ 	move	$a0,$v0
/*  f0eabbc:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eabc0:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eabc4:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0eabc8:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0eabcc:	8faa00ac */ 	lw	$t2,0xac($sp)
/*  f0eabd0:	00402025 */ 	move	$a0,$v0
/*  f0eabd4:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eabd8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0eabdc:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0eabe0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eabe4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eabe8:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eabec:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eabf0:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eabf4:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eabf8:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0eabfc:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0eac00:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0eac04:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0eac08:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eac0c:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0eac10:	00402025 */ 	move	$a0,$v0
/*  f0eac14:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eac18:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eac1c:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eac20:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0eac24:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eac28:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0eac2c:	00402025 */ 	move	$a0,$v0
/*  f0eac30:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0eac34:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0eac38:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eac3c:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0eac40:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eac44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eac48:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eac4c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eac50:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0eac54:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eac58:	00402025 */ 	move	$a0,$v0
/*  f0eac5c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0eac60:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0eac64:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0eac68:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eac6c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eac70:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eac74:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eac78:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eac7c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eac80:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0eac84:	00402025 */ 	move	$a0,$v0
/*  f0eac88:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0eac8c:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0eac90:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eac94:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eac98:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eac9c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaca0:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eaca4:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0eaca8:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0eacac:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eacb0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0eacb4:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0eacb8:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0eacbc:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0eacc0:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0eacc4:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0eacc8:	00402025 */ 	move	$a0,$v0
/*  f0eaccc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eacd0:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eacd4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eacd8:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0eacdc:	00402025 */ 	move	$a0,$v0
/*  f0eace0:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eace4:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0eace8:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0eacec:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0eacf0:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0eacf4:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eacf8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eacfc:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0ead00:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead04:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ead08:	00402025 */ 	move	$a0,$v0
/*  f0ead0c:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ead10:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ead14:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ead18:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ead1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead20:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0ead24:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ead28:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0ead2c:	00402025 */ 	move	$a0,$v0
/*  f0ead30:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ead34:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ead38:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ead3c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ead40:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead44:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0ead48:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ead4c:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ead50:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ead54:	2401ff00 */ 	li	$at,-256
/*  f0ead58:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f0ead5c:	0061c024 */ 	and	$t8,$v1,$at
/*  f0ead60:	3710003f */ 	ori	$s0,$t8,0x3f
/*  f0ead64:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ead68:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ead6c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ead70:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead74:	03001825 */ 	move	$v1,$t8
/*  f0ead78:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0ead7c:	00402025 */ 	move	$a0,$v0
/*  f0ead80:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ead84:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0ead88:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0ead8c:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ead90:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0ead94:	00402025 */ 	move	$a0,$v0
/*  f0ead98:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ead9c:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0eada0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0eada4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0eada8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eadac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eadb0:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eadb4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0eadb8:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f0eadbc:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f0eadc0:	00402025 */ 	move	$a0,$v0
/*  f0eadc4:	354900cf */ 	ori	$t1,$t2,0xcf
/*  f0eadc8:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0eadcc:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0eadd0:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0eadd4:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0eadd8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaddc:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eade0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eade4:	10000077 */ 	b	.JF0f0eafc4
/*  f0eade8:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0eadec:
/*  f0eadec:	87ab0146 */ 	lh	$t3,0x146($sp)
/*  f0eadf0:	3c198008 */ 	lui	$t9,0x8008
/*  f0eadf4:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0eadf8:	250f0001 */ 	addiu	$t7,$t0,0x1
/*  f0eadfc:	3c078008 */ 	lui	$a3,0x8008
/*  f0eae00:	256dfffe */ 	addiu	$t5,$t3,-2
/*  f0eae04:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f0eae08:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f0eae0c:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f0eae10:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0eae14:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0eae18:	8ce7014c */ 	lw	$a3,0x14c($a3)
/*  f0eae1c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0eae20:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0eae24:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0eae28:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eae2c:	0fc55d49 */ 	jal	textMeasure
/*  f0eae30:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eae34:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0eae38:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f0eae3c:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0eae40:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0eae44:	01cc6821 */ 	addu	$t5,$t6,$t4
/*  f0eae48:	25ab0019 */ 	addiu	$t3,$t5,0x19
/*  f0eae4c:	2549fffe */ 	addiu	$t1,$t2,-2
/*  f0eae50:	afa90074 */ 	sw	$t1,0x74($sp)
/*  f0eae54:	0fc54bb7 */ 	jal	text0f153780
/*  f0eae58:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f0eae5c:	0fc38c93 */ 	jal	menugfx0f0e2498
/*  f0eae60:	00402025 */ 	move	$a0,$v0
/*  f0eae64:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0eae68:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0eae6c:	2401ff00 */ 	li	$at,-256
/*  f0eae70:	00617824 */ 	and	$t7,$v1,$at
/*  f0eae74:	35f0003f */ 	ori	$s0,$t7,0x3f
/*  f0eae78:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0eae7c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eae80:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eae84:	01e01825 */ 	move	$v1,$t7
/*  f0eae88:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0eae8c:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f0eae90:	00402025 */ 	move	$a0,$v0
/*  f0eae94:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eae98:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eae9c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0eaea0:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0eaea4:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f0eaea8:	00402025 */ 	move	$a0,$v0
/*  f0eaeac:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eaeb0:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0eaeb4:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0eaeb8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaebc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaec0:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eaec4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eaec8:	87a90142 */ 	lh	$t1,0x142($sp)
/*  f0eaecc:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaed0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0eaed4:	00097080 */ 	sll	$t6,$t1,0x2
/*  f0eaed8:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f0eaedc:	01c93821 */ 	addu	$a3,$t6,$t1
/*  f0eaee0:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0eaee4:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0eaee8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eaeec:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0eaef0:	00402025 */ 	move	$a0,$v0
/*  f0eaef4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaef8:	01202825 */ 	move	$a1,$t1
/*  f0eaefc:	04e10003 */ 	bgez	$a3,.JF0f0eaf0c
/*  f0eaf00:	00076083 */ 	sra	$t4,$a3,0x2
/*  f0eaf04:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0eaf08:	00016083 */ 	sra	$t4,$at,0x2
.JF0f0eaf0c:
/*  f0eaf0c:	2587ffff */ 	addiu	$a3,$t4,-1
/*  f0eaf10:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0eaf14:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eaf18:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0eaf1c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eaf20:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0eaf24:	00402025 */ 	move	$a0,$v0
/*  f0eaf28:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0eaf2c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0eaf30:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaf34:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eaf38:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaf3c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaf40:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eaf44:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eaf48:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f0eaf4c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eaf50:	00402025 */ 	move	$a0,$v0
/*  f0eaf54:	25ab0003 */ 	addiu	$t3,$t5,0x3
/*  f0eaf58:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eaf5c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaf60:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaf64:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaf68:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eaf6c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eaf70:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eaf74:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0eaf78:	00402025 */ 	move	$a0,$v0
/*  f0eaf7c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0eaf80:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0eaf84:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaf88:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eaf8c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaf90:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaf94:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eaf98:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eaf9c:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0eafa0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0eafa4:	00402025 */ 	move	$a0,$v0
/*  f0eafa8:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f0eafac:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eafb0:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0eafb4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eafb8:	0fc38d3e */ 	jal	menugfxDrawTessellatedRect
/*  f0eafbc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eafc0:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0eafc4:
/*  f0eafc4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eafc8:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0eafcc:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0eafd0:	03e00008 */ 	jr	$ra
/*  f0eafd4:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
/*  f0e98ac:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e98b0:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e98b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e98b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e98bc:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e98c0:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e98c4:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e98c8:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e98cc:	11c00002 */ 	beqz	$t6,.L0f0e98d8
/*  f0e98d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e98d4:	2402000c */ 	addiu	$v0,$zero,0x10
.L0f0e98d8:
/*  f0e98d8:	3c047f1b */ 	lui	$a0,%hi(var7f1adfa0)
/*  f0e98dc:	3c058007 */ 	lui	$a1,%hi(var800711e8)
/*  f0e98e0:	24a511e8 */ 	addiu	$a1,$a1,%lo(var800711e8)
/*  f0e98e4:	2484dfa0 */ 	addiu	$a0,$a0,%lo(var7f1adfa0)
/*  f0e98e8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0e98ec:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e98f0:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e98f4:	3c04800a */ 	lui	$a0,%hi(g_Briefing+0x2)
/*  f0e98f8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e98fc:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e9900:	0fc5b9f1 */ 	jal	langGet
/*  f0e9904:	9484dfca */ 	lhu	$a0,%lo(g_Briefing+0x2)($a0)
/*  f0e9908:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e990c:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e9910:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e9914:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e9918:	44803000 */ 	mtc1	$zero,$f6
/*  f0e991c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e9920:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e9924:	00000000 */ 	nop
/*  f0e9928:	4502000b */ 	bc1fl	.L0f0e9958
/*  f0e992c:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e9930:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e9934:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e9938:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e993c:	01300019 */ 	multu	$t1,$s0
/*  f0e9940:	00005012 */ 	mflo	$t2
/*  f0e9944:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e9948:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e994c:	10000012 */ 	b	.L0f0e9998
/*  f0e9950:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e9954:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0e9958:
/*  f0e9958:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e995c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e9960:	01900019 */ 	multu	$t4,$s0
/*  f0e9964:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0e9968:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0e996c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e9970:	00006812 */ 	mflo	$t5
/*  f0e9974:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e9978:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e997c:	03100019 */ 	multu	$t8,$s0
/*  f0e9980:	0000c812 */ 	mflo	$t9
/*  f0e9984:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e9988:	0fc01a40 */ 	jal	colourBlend
/*  f0e998c:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e9990:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e9994:	8fa30134 */ 	lw	$v1,0x134($sp)
.L0f0e9998:
/*  f0e9998:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e999c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e99a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e99a4:	5140000b */ 	beqzl	$t2,.L0f0e99d4
/*  f0e99a8:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e99ac:	0fc01a40 */ 	jal	colourBlend
/*  f0e99b0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e99b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e99b8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e99bc:	00415824 */ 	and	$t3,$v0,$at
/*  f0e99c0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e99c4:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e99c8:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e99cc:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e99d0:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0e99d4:
/*  f0e99d4:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0e99d8:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0e99dc:	03100019 */ 	multu	$t8,$s0
/*  f0e99e0:	00001012 */ 	mflo	$v0
/*  f0e99e4:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e99e8:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e99ec:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0e99f0:	0fc54f8e */ 	jal	textSetWaveColours
/*  f0e99f4:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0e99f8:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e99fc:	0fc54d8a */ 	jal	text0f153628
/*  f0e9a00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a04:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e9a08:	3c057f1b */ 	lui	$a1,%hi(var7f1adfa8)
/*  f0e9a0c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9a10:	24a5dfa8 */ 	addiu	$a1,$a1,%lo(var7f1adfa8)
/*  f0e9a14:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9a18:	0c004dad */ 	jal	sprintf
/*  f0e9a1c:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e9a20:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm)
/*  f0e9a24:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm)($t9)
/*  f0e9a28:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9a2c:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0e9a30:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9a34:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9a38:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9a3c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9a40:	0fc55cbe */ 	jal	textMeasure
/*  f0e9a44:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e9a48:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9a4c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e9a50:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicSm)
/*  f0e9a54:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm)
/*  f0e9a58:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm)($t5)
/*  f0e9a5c:	8d6bfb10 */ 	lw	$t3,%lo(g_CharsHandelGothicSm)($t3)
/*  f0e9a60:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9a64:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9a68:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9a6c:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e9a70:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e9a74:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e9a78:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a7c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9a80:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9a84:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9a88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9a8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9a90:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9a94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9a98:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9a9c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9aa0:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9aa4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9aa8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9aac:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e9ab0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9ab4:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e9ab8:	1140001f */ 	beqz	$t2,.L0f0e9b38
/*  f0e9abc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9ac0:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicXs)
/*  f0e9ac4:	8d8cfb04 */ 	lw	$t4,%lo(g_FontHandelGothicXs)($t4)
/*  f0e9ac8:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9acc:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9ad0:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e9ad4:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e9ad8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9adc:	0fc55d48 */ 	jal	textWrap
/*  f0e9ae0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9ae4:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicXs)
/*  f0e9ae8:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9aec:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9af0:	8d6bfb08 */ 	lw	$t3,%lo(g_CharsHandelGothicXs)($t3)
/*  f0e9af4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9af8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9afc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9b00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b04:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b08:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b0c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b10:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b14:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b18:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9b1c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9b20:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9b24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9b28:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9b30:	1000001a */ 	b	.L0f0e9b9c
/*  f0e9b34:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b38:
/*  f0e9b38:	3c057f1b */ 	lui	$a1,%hi(var7f1adfb0)
/*  f0e9b3c:	24a5dfb0 */ 	addiu	$a1,$a1,%lo(var7f1adfb0)
/*  f0e9b40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9b44:	0c004dad */ 	jal	sprintf
/*  f0e9b48:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e9b4c:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicSm)
/*  f0e9b50:	3c098008 */ 	lui	$t1,%hi(g_FontHandelGothicSm)
/*  f0e9b54:	8d29fb0c */ 	lw	$t1,%lo(g_FontHandelGothicSm)($t1)
/*  f0e9b58:	8dcefb10 */ 	lw	$t6,%lo(g_CharsHandelGothicSm)($t6)
/*  f0e9b5c:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e9b60:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e9b64:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e9b68:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b6c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b70:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b74:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b78:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b7c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b80:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e9b84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9b88:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e9b8c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e9b90:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b94:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e9b98:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b9c:
/*  f0e9b9c:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e9ba0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9ba4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9ba8:	11a00141 */ 	beqz	$t5,.L0f0ea0b0
/*  f0e9bac:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9bb0:	0fc255a1 */ 	jal	objectiveCheck
/*  f0e9bb4:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e9bb8:	10400007 */ 	beqz	$v0,.L0f0e9bd8
/*  f0e9bbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e9bc0:	1041000c */ 	beq	$v0,$at,.L0f0e9bf4
/*  f0e9bc4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e9bc8:	10410011 */ 	beq	$v0,$at,.L0f0e9c10
/*  f0e9bcc:	00000000 */ 	nop
/*  f0e9bd0:	10000015 */ 	b	.L0f0e9c28
/*  f0e9bd4:	00000000 */ 	nop
.L0f0e9bd8:
/*  f0e9bd8:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bdc:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e9be0:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e9be4:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e9be8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9bec:	1000000e */ 	b	.L0f0e9c28
/*  f0e9bf0:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L0f0e9bf4:
/*  f0e9bf4:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bf8:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e9bfc:	3c1800ff */ 	lui	$t8,0xff
/*  f0e9c00:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e9c04:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c08:	10000007 */ 	b	.L0f0e9c28
/*  f0e9c0c:	afb800c8 */ 	sw	$t8,0xc8($sp)
.L0f0e9c10:
/*  f0e9c10:	0fc5b9f1 */ 	jal	langGet
/*  f0e9c14:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e9c18:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e9c1c:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e9c20:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c24:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L0f0e9c28:
/*  f0e9c28:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0e9c2c:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0e9c30:	3c0c800a */ 	lui	$t4,%hi(g_Menus+0x4f8)
/*  f0e9c34:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e9c38:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e9c3c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e9c44:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0e9c48:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e9c4c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c50:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e9c54:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e9c58:	8d8ce4f8 */ 	lw	$t4,%lo(g_Menus+0x4f8)($t4)
/*  f0e9c5c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9c60:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9c64:	11cc0004 */ 	beq	$t6,$t4,.L0f0e9c78
/*  f0e9c68:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9c6c:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e9c70:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e9c74:	afab00c8 */ 	sw	$t3,0xc8($sp)
.L0f0e9c78:
/*  f0e9c78:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9c7c:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9c80:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e9c84:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9c88:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9c8c:	0fc55cbe */ 	jal	textMeasure
/*  f0e9c90:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9c94:	3c028007 */ 	lui	$v0,%hi(var800711e8)
/*  f0e9c98:	8c4211e8 */ 	lw	$v0,%lo(var800711e8)($v0)
/*  f0e9c9c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9ca0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9ca4:	10400002 */ 	beqz	$v0,.L0f0e9cb0
/*  f0e9ca8:	3c0c8008 */ 	lui	$t4,%hi(g_CharsHandelGothicXs)
/*  f0e9cac:	afa200c8 */ 	sw	$v0,0xc8($sp)
.L0f0e9cb0:
/*  f0e9cb0:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e9cb4:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e9cb8:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9cbc:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e9cc0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e9cc4:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e9cc8:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0e9ccc:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0e9cd0:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9cd4:	8d8cfb08 */ 	lw	$t4,%lo(g_CharsHandelGothicXs)($t4)
/*  f0e9cd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e9cdc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9ce0:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e9ce4:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9ce8:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e9cec:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9cf0:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9cf4:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e9cf8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9cfc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d00:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d08:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e9d0c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e9d10:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d14:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9d18:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d1c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e9d20:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d24:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e9d28:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicXs)
/*  f0e9d2c:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f0e9d30:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e9d34:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f0e9d38:	8d4afb08 */ 	lw	$t2,%lo(g_CharsHandelGothicXs)($t2)
/*  f0e9d3c:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e9d40:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9d44:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e9d48:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9d4c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9d50:	01815824 */ 	and	$t3,$t4,$at
/*  f0e9d54:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9d58:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e9d5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d60:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9d64:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9d68:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d74:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9d78:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e9d7c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9d80:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e9d84:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d8c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d90:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e9d94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d98:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e9d9c:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e9da0:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e9da4:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e9da8:	0fc54de0 */ 	jal	text0f153780
/*  f0e9dac:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e9db0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9db4:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e9db8:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e9dbc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e9dc0:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e9dc4:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e9dc8:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e9dcc:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e9dd0:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e9dd4:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e9dd8:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e9ddc:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e9de0:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e9de4:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e9de8:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e9dec:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e9df0:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e9df4:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e9df8:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e9dfc:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e9e00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e04:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e9e08:	04610003 */ 	bgez	$v1,.L0f0e9e18
/*  f0e9e0c:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e9e10:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e9e14:	00015083 */ 	sra	$t2,$at,0x2
.L0f0e9e18:
/*  f0e9e18:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e9e1c:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e9e20:	01cd0019 */ 	multu	$t6,$t5
/*  f0e9e24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e9e28:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e9e2c:	00007812 */ 	mflo	$t7
/*  f0e9e30:	00000000 */ 	nop
/*  f0e9e34:	00000000 */ 	nop
/*  f0e9e38:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e9e3c:	0000c012 */ 	mflo	$t8
/*  f0e9e40:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e9e44:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e9e48:	0fc38926 */ 	jal	menugfx0f0e2498
/*  f0e9e4c:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e9e50:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e9e54:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9e58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e9e5c:	00616024 */ 	and	$t4,$v1,$at
/*  f0e9e60:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e9e64:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e9e68:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9e6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9e70:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e9e74:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e9e78:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e9e7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e80:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9e84:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9eb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9eb4:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9eb8:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9ebc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e9ec0:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e9ec4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e9ec8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e9ecc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9ed0:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e9ed4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ed8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9edc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9ee0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9ee4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e9ee8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9eec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e9ef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ef4:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e9ef8:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e9efc:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f00:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e9f04:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f0c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f10:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9f14:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9f18:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f1c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f20:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e9f24:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f28:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e9f2c:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f30:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f34:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f38:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f3c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9f40:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f44:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e9f48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f4c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e9f50:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e9f54:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9f5c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f64:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9f6c:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9f70:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9f74:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e9f78:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e9f7c:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e9f80:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e9f84:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f88:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e9f8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f90:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f94:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f9c:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9fa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fa4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9fa8:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e9fac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9fb0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e9fb4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9fb8:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9fbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fc0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea00c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ea010:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ea014:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ea018:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea01c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0ea020:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea024:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea028:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea02c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ea030:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea034:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea038:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea03c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0ea040:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea044:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ea048:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea04c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea050:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea054:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ea058:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea05c:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ea060:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0ea064:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ea068:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea06c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea070:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea074:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea078:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea07c:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0ea080:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0ea084:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea088:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0ea08c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea090:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0ea094:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea098:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea09c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea0a0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea0a4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea0a8:	10000074 */ 	b	.L0f0ea27c
/*  f0ea0ac:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea0b0:
/*  f0ea0b0:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0ea0b4:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0ea0b8:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0ea0bc:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm)
/*  f0ea0c0:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm)($t3)
/*  f0ea0c4:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0ea0c8:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0ea0cc:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0ea0d0:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0ea0d4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0ea0d8:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0ea0dc:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0ea0e0:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0ea0e4:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea0e8:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0ea0ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea0f0:	0fc55cbe */ 	jal	textMeasure
/*  f0ea0f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea0f8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea0fc:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0ea100:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea104:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ea108:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0ea10c:	0fc54de0 */ 	jal	text0f153780
/*  f0ea110:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0ea114:	0fc38926 */ 	jal	menugfx0f0e2498
/*  f0ea118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea11c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0ea120:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea124:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea128:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea12c:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea130:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0ea134:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea13c:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea140:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea144:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0ea148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea14c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0ea150:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea17c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea180:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0ea184:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea188:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0ea18c:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0ea190:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0ea194:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0ea198:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0ea19c:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0ea1a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea1a4:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0ea1a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1b0:	01602825 */ 	or	$a1,$t3,$zero
/*  f0ea1b4:	04e10003 */ 	bgez	$a3,.L0f0ea1c4
/*  f0ea1b8:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0ea1bc:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0ea1c0:	00016883 */ 	sra	$t5,$at,0x2
.L0f0ea1c4:
/*  f0ea1c4:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0ea1c8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ea1cc:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea1d0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0ea1d4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea1d8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0ea1dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1e0:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0ea1e4:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0ea1e8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea1ec:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0ea1f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea1f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1f8:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea224:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea228:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea22c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ea230:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea234:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0ea238:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ea23c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea240:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0ea244:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea248:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea24c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea274:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea278:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea27c:
/*  f0ea27c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ea280:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0ea284:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ea288:	03e00008 */ 	jr	$ra
/*  f0ea28c:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
/*  f0e98ac:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e98b0:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e98b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e98b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e98bc:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e98c0:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e98c4:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e98c8:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e98cc:	11c00002 */ 	beqz	$t6,.L0f0e98d8
/*  f0e98d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e98d4:	2402000c */ 	addiu	$v0,$zero,0xc
.L0f0e98d8:
/*  f0e98d8:	3c047f1b */ 	lui	$a0,%hi(var7f1adfa0)
/*  f0e98dc:	3c058007 */ 	lui	$a1,%hi(var800711e8)
/*  f0e98e0:	24a511e8 */ 	addiu	$a1,$a1,%lo(var800711e8)
/*  f0e98e4:	2484dfa0 */ 	addiu	$a0,$a0,%lo(var7f1adfa0)
/*  f0e98e8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0e98ec:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e98f0:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e98f4:	3c04800a */ 	lui	$a0,%hi(g_Briefing+0x2)
/*  f0e98f8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e98fc:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e9900:	0fc5b9f1 */ 	jal	langGet
/*  f0e9904:	9484dfca */ 	lhu	$a0,%lo(g_Briefing+0x2)($a0)
/*  f0e9908:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e990c:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e9910:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e9914:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e9918:	44803000 */ 	mtc1	$zero,$f6
/*  f0e991c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e9920:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e9924:	00000000 */ 	nop
/*  f0e9928:	4502000b */ 	bc1fl	.L0f0e9958
/*  f0e992c:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e9930:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e9934:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e9938:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e993c:	01300019 */ 	multu	$t1,$s0
/*  f0e9940:	00005012 */ 	mflo	$t2
/*  f0e9944:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e9948:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e994c:	10000012 */ 	b	.L0f0e9998
/*  f0e9950:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e9954:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0e9958:
/*  f0e9958:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e995c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e9960:	01900019 */ 	multu	$t4,$s0
/*  f0e9964:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0e9968:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0e996c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e9970:	00006812 */ 	mflo	$t5
/*  f0e9974:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e9978:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e997c:	03100019 */ 	multu	$t8,$s0
/*  f0e9980:	0000c812 */ 	mflo	$t9
/*  f0e9984:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e9988:	0fc01a40 */ 	jal	colourBlend
/*  f0e998c:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e9990:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e9994:	8fa30134 */ 	lw	$v1,0x134($sp)
.L0f0e9998:
/*  f0e9998:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e999c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e99a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e99a4:	5140000b */ 	beqzl	$t2,.L0f0e99d4
/*  f0e99a8:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e99ac:	0fc01a40 */ 	jal	colourBlend
/*  f0e99b0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e99b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e99b8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e99bc:	00415824 */ 	and	$t3,$v0,$at
/*  f0e99c0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e99c4:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e99c8:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e99cc:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e99d0:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0e99d4:
/*  f0e99d4:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0e99d8:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0e99dc:	03100019 */ 	multu	$t8,$s0
/*  f0e99e0:	00001012 */ 	mflo	$v0
/*  f0e99e4:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e99e8:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e99ec:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0e99f0:	0fc54f8e */ 	jal	textSetWaveColours
/*  f0e99f4:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0e99f8:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e99fc:	0fc54d8a */ 	jal	text0f153628
/*  f0e9a00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a04:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e9a08:	3c057f1b */ 	lui	$a1,%hi(var7f1adfa8)
/*  f0e9a0c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9a10:	24a5dfa8 */ 	addiu	$a1,$a1,%lo(var7f1adfa8)
/*  f0e9a14:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9a18:	0c004dad */ 	jal	sprintf
/*  f0e9a1c:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e9a20:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm)
/*  f0e9a24:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm)($t9)
/*  f0e9a28:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9a2c:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0e9a30:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9a34:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9a38:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9a3c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9a40:	0fc55cbe */ 	jal	textMeasure
/*  f0e9a44:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e9a48:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9a4c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e9a50:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicSm)
/*  f0e9a54:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm)
/*  f0e9a58:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm)($t5)
/*  f0e9a5c:	8d6bfb10 */ 	lw	$t3,%lo(g_CharsHandelGothicSm)($t3)
/*  f0e9a60:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9a64:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9a68:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9a6c:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e9a70:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e9a74:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e9a78:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a7c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9a80:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9a84:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9a88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9a8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9a90:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9a94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9a98:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9a9c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9aa0:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9aa4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9aa8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9aac:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e9ab0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9ab4:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e9ab8:	1140001f */ 	beqz	$t2,.L0f0e9b38
/*  f0e9abc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9ac0:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicXs)
/*  f0e9ac4:	8d8cfb04 */ 	lw	$t4,%lo(g_FontHandelGothicXs)($t4)
/*  f0e9ac8:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9acc:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9ad0:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e9ad4:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e9ad8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9adc:	0fc55d48 */ 	jal	textWrap
/*  f0e9ae0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9ae4:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicXs)
/*  f0e9ae8:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9aec:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9af0:	8d6bfb08 */ 	lw	$t3,%lo(g_CharsHandelGothicXs)($t3)
/*  f0e9af4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9af8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9afc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9b00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b04:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b08:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b0c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b10:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b14:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b18:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9b1c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9b20:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9b24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9b28:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9b30:	1000001a */ 	b	.L0f0e9b9c
/*  f0e9b34:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b38:
/*  f0e9b38:	3c057f1b */ 	lui	$a1,%hi(var7f1adfb0)
/*  f0e9b3c:	24a5dfb0 */ 	addiu	$a1,$a1,%lo(var7f1adfb0)
/*  f0e9b40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9b44:	0c004dad */ 	jal	sprintf
/*  f0e9b48:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e9b4c:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicSm)
/*  f0e9b50:	3c098008 */ 	lui	$t1,%hi(g_FontHandelGothicSm)
/*  f0e9b54:	8d29fb0c */ 	lw	$t1,%lo(g_FontHandelGothicSm)($t1)
/*  f0e9b58:	8dcefb10 */ 	lw	$t6,%lo(g_CharsHandelGothicSm)($t6)
/*  f0e9b5c:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e9b60:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e9b64:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e9b68:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b6c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b70:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b74:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b78:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b7c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b80:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e9b84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9b88:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e9b8c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e9b90:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b94:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e9b98:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b9c:
/*  f0e9b9c:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e9ba0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9ba4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9ba8:	11a00141 */ 	beqz	$t5,.L0f0ea0b0
/*  f0e9bac:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9bb0:	0fc255a1 */ 	jal	objectiveCheck
/*  f0e9bb4:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e9bb8:	10400007 */ 	beqz	$v0,.L0f0e9bd8
/*  f0e9bbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e9bc0:	1041000c */ 	beq	$v0,$at,.L0f0e9bf4
/*  f0e9bc4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e9bc8:	10410011 */ 	beq	$v0,$at,.L0f0e9c10
/*  f0e9bcc:	00000000 */ 	nop
/*  f0e9bd0:	10000015 */ 	b	.L0f0e9c28
/*  f0e9bd4:	00000000 */ 	nop
.L0f0e9bd8:
/*  f0e9bd8:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bdc:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e9be0:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e9be4:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e9be8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9bec:	1000000e */ 	b	.L0f0e9c28
/*  f0e9bf0:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L0f0e9bf4:
/*  f0e9bf4:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bf8:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e9bfc:	3c1800ff */ 	lui	$t8,0xff
/*  f0e9c00:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e9c04:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c08:	10000007 */ 	b	.L0f0e9c28
/*  f0e9c0c:	afb800c8 */ 	sw	$t8,0xc8($sp)
.L0f0e9c10:
/*  f0e9c10:	0fc5b9f1 */ 	jal	langGet
/*  f0e9c14:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e9c18:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e9c1c:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e9c20:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c24:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L0f0e9c28:
/*  f0e9c28:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0e9c2c:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0e9c30:	3c0c800a */ 	lui	$t4,%hi(g_Menus+0x4f8)
/*  f0e9c34:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e9c38:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e9c3c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e9c44:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0e9c48:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e9c4c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c50:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e9c54:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e9c58:	8d8ce4f8 */ 	lw	$t4,%lo(g_Menus+0x4f8)($t4)
/*  f0e9c5c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9c60:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9c64:	11cc0004 */ 	beq	$t6,$t4,.L0f0e9c78
/*  f0e9c68:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9c6c:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e9c70:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e9c74:	afab00c8 */ 	sw	$t3,0xc8($sp)
.L0f0e9c78:
/*  f0e9c78:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9c7c:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9c80:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e9c84:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9c88:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9c8c:	0fc55cbe */ 	jal	textMeasure
/*  f0e9c90:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9c94:	3c028007 */ 	lui	$v0,%hi(var800711e8)
/*  f0e9c98:	8c4211e8 */ 	lw	$v0,%lo(var800711e8)($v0)
/*  f0e9c9c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9ca0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9ca4:	10400002 */ 	beqz	$v0,.L0f0e9cb0
/*  f0e9ca8:	3c0c8008 */ 	lui	$t4,%hi(g_CharsHandelGothicXs)
/*  f0e9cac:	afa200c8 */ 	sw	$v0,0xc8($sp)
.L0f0e9cb0:
/*  f0e9cb0:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e9cb4:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e9cb8:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9cbc:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e9cc0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e9cc4:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e9cc8:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0e9ccc:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0e9cd0:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9cd4:	8d8cfb08 */ 	lw	$t4,%lo(g_CharsHandelGothicXs)($t4)
/*  f0e9cd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e9cdc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9ce0:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e9ce4:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9ce8:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e9cec:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9cf0:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9cf4:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e9cf8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9cfc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d00:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d08:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e9d0c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e9d10:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d14:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9d18:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d1c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e9d20:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d24:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e9d28:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicXs)
/*  f0e9d2c:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f0e9d30:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e9d34:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f0e9d38:	8d4afb08 */ 	lw	$t2,%lo(g_CharsHandelGothicXs)($t2)
/*  f0e9d3c:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e9d40:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9d44:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e9d48:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9d4c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9d50:	01815824 */ 	and	$t3,$t4,$at
/*  f0e9d54:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9d58:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e9d5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d60:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9d64:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9d68:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d74:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9d78:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e9d7c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9d80:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e9d84:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d8c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d90:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e9d94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d98:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e9d9c:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e9da0:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e9da4:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e9da8:	0fc54de0 */ 	jal	text0f153780
/*  f0e9dac:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e9db0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9db4:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e9db8:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e9dbc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e9dc0:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e9dc4:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e9dc8:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e9dcc:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e9dd0:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e9dd4:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e9dd8:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e9ddc:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e9de0:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e9de4:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e9de8:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e9dec:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e9df0:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e9df4:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e9df8:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e9dfc:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e9e00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e04:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e9e08:	04610003 */ 	bgez	$v1,.L0f0e9e18
/*  f0e9e0c:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e9e10:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e9e14:	00015083 */ 	sra	$t2,$at,0x2
.L0f0e9e18:
/*  f0e9e18:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e9e1c:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e9e20:	01cd0019 */ 	multu	$t6,$t5
/*  f0e9e24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e9e28:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e9e2c:	00007812 */ 	mflo	$t7
/*  f0e9e30:	00000000 */ 	nop
/*  f0e9e34:	00000000 */ 	nop
/*  f0e9e38:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e9e3c:	0000c012 */ 	mflo	$t8
/*  f0e9e40:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e9e44:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e9e48:	0fc38926 */ 	jal	menugfx0f0e2498
/*  f0e9e4c:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e9e50:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e9e54:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9e58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e9e5c:	00616024 */ 	and	$t4,$v1,$at
/*  f0e9e60:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e9e64:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e9e68:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9e6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9e70:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e9e74:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e9e78:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e9e7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e80:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9e84:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9eb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9eb4:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9eb8:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9ebc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e9ec0:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e9ec4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e9ec8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e9ecc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9ed0:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e9ed4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ed8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9edc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9ee0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9ee4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e9ee8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9eec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e9ef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ef4:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e9ef8:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e9efc:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f00:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e9f04:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f0c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f10:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9f14:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9f18:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f1c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f20:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e9f24:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f28:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e9f2c:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f30:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f34:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f38:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f3c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9f40:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f44:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e9f48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f4c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e9f50:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e9f54:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9f5c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f64:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9f6c:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9f70:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9f74:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e9f78:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e9f7c:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e9f80:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e9f84:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f88:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e9f8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f90:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f94:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9f98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f9c:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9fa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fa4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9fa8:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e9fac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9fb0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e9fb4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9fb8:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9fbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fc0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea00c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ea010:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ea014:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ea018:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea01c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0ea020:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea024:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea028:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea02c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ea030:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea034:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea038:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea03c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0ea040:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea044:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ea048:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea04c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea050:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea054:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ea058:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea05c:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ea060:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0ea064:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ea068:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea06c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea070:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea074:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea078:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea07c:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0ea080:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0ea084:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea088:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0ea08c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea090:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0ea094:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea098:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea09c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea0a0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea0a4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea0a8:	10000074 */ 	b	.L0f0ea27c
/*  f0ea0ac:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea0b0:
/*  f0ea0b0:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0ea0b4:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0ea0b8:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0ea0bc:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm)
/*  f0ea0c0:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm)($t3)
/*  f0ea0c4:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0ea0c8:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0ea0cc:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0ea0d0:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0ea0d4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0ea0d8:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0ea0dc:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0ea0e0:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0ea0e4:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea0e8:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0ea0ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea0f0:	0fc55cbe */ 	jal	textMeasure
/*  f0ea0f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea0f8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea0fc:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0ea100:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea104:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ea108:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0ea10c:	0fc54de0 */ 	jal	text0f153780
/*  f0ea110:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0ea114:	0fc38926 */ 	jal	menugfx0f0e2498
/*  f0ea118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea11c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0ea120:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea124:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea128:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea12c:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea130:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0ea134:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea13c:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea140:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea144:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0ea148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea14c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0ea150:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea17c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea180:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0ea184:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea188:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0ea18c:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0ea190:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0ea194:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0ea198:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0ea19c:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0ea1a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea1a4:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0ea1a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1b0:	01602825 */ 	or	$a1,$t3,$zero
/*  f0ea1b4:	04e10003 */ 	bgez	$a3,.L0f0ea1c4
/*  f0ea1b8:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0ea1bc:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0ea1c0:	00016883 */ 	sra	$t5,$at,0x2
.L0f0ea1c4:
/*  f0ea1c4:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0ea1c8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ea1cc:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea1d0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0ea1d4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea1d8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0ea1dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1e0:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0ea1e4:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0ea1e8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea1ec:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0ea1f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea1f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1f8:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea224:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea228:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea22c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ea230:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea234:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0ea238:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ea23c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea240:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0ea244:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea248:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea24c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea274:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea278:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea27c:
/*  f0ea27c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ea280:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0ea284:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ea288:	03e00008 */ 	jr	$ra
/*  f0ea28c:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#else
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
/*  f0e6a20:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e6a24:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e6a28:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e6a2c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e6a30:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e6a34:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e6a38:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e6a3c:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e6a40:	11c00002 */ 	beqz	$t6,.NB0f0e6a4c
/*  f0e6a44:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e6a48:	2402000c */ 	addiu	$v0,$zero,0xc
.NB0f0e6a4c:
/*  f0e6a4c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e6a50:	3c058007 */ 	lui	$a1,0x8007
/*  f0e6a54:	24a53898 */ 	addiu	$a1,$a1,0x3898
/*  f0e6a58:	248482d0 */ 	addiu	$a0,$a0,-32048
/*  f0e6a5c:	0c00381c */ 	jal	mainOverrideVariable
/*  f0e6a60:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e6a64:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e6a68:	3c04800a */ 	lui	$a0,0x800a
/*  f0e6a6c:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e6a70:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e6a74:	0fc5a4dd */ 	jal	langGet
/*  f0e6a78:	9484278a */ 	lhu	$a0,0x278a($a0)
/*  f0e6a7c:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e6a80:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e6a84:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e6a88:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e6a8c:	44803000 */ 	mtc1	$zero,$f6
/*  f0e6a90:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e6a94:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e6a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6a9c:	4502000b */ 	bc1fl	.NB0f0e6acc
/*  f0e6aa0:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e6aa4:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e6aa8:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e6aac:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0e6ab0:	01300019 */ 	multu	$t1,$s0
/*  f0e6ab4:	00005012 */ 	mflo	$t2
/*  f0e6ab8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e6abc:	8d6bc2f8 */ 	lw	$t3,-0x3d08($t3)
/*  f0e6ac0:	10000012 */ 	beqz	$zero,.NB0f0e6b0c
/*  f0e6ac4:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e6ac8:	906c003d */ 	lbu	$t4,0x3d($v1)
.NB0f0e6acc:
/*  f0e6acc:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e6ad0:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e6ad4:	01900019 */ 	multu	$t4,$s0
/*  f0e6ad8:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0e6adc:	25cec2e0 */ 	addiu	$t6,$t6,-15648
/*  f0e6ae0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e6ae4:	00006812 */ 	mflo	$t5
/*  f0e6ae8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e6aec:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e6af0:	03100019 */ 	multu	$t8,$s0
/*  f0e6af4:	0000c812 */ 	mflo	$t9
/*  f0e6af8:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e6afc:	0fc01990 */ 	jal	colourBlend
/*  f0e6b00:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e6b04:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e6b08:	8fa30134 */ 	lw	$v1,0x134($sp)
.NB0f0e6b0c:
/*  f0e6b0c:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e6b10:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e6b14:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e6b18:	5140000b */ 	beqzl	$t2,.NB0f0e6b48
/*  f0e6b1c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e6b20:	0fc01990 */ 	jal	colourBlend
/*  f0e6b24:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e6b28:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e6b2c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6b30:	00415824 */ 	and	$t3,$v0,$at
/*  f0e6b34:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e6b38:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e6b3c:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e6b40:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e6b44:	9078003c */ 	lbu	$t8,0x3c($v1)
.NB0f0e6b48:
/*  f0e6b48:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e6b4c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e6b50:	03100019 */ 	multu	$t8,$s0
/*  f0e6b54:	00001012 */ 	mflo	$v0
/*  f0e6b58:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e6b5c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e6b60:	8ca5c460 */ 	lw	$a1,-0x3ba0($a1)
/*  f0e6b64:	0fc53925 */ 	jal	textSetWaveColours
/*  f0e6b68:	8c84c5c8 */ 	lw	$a0,-0x3a38($a0)
/*  f0e6b6c:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e6b70:	0fc5374a */ 	jal	text0f153628
/*  f0e6b74:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6b78:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e6b7c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e6b80:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e6b84:	24a582d8 */ 	addiu	$a1,$a1,-32040
/*  f0e6b88:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6b8c:	0c004fc1 */ 	jal	sprintf
/*  f0e6b90:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e6b94:	3c198008 */ 	lui	$t9,0x8008
/*  f0e6b98:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f0e6b9c:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6ba0:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f0e6ba4:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e6ba8:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e6bac:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e6bb0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e6bb4:	0fc54655 */ 	jal	textMeasure
/*  f0e6bb8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e6bbc:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e6bc0:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e6bc4:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e6bc8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e6bcc:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f0e6bd0:	8d6b2370 */ 	lw	$t3,0x2370($t3)
/*  f0e6bd4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e6bd8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e6bdc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e6be0:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e6be4:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e6be8:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e6bec:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6bf0:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6bf4:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6bf8:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e6bfc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6c00:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6c04:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e6c08:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e6c0c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e6c10:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e6c14:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6c18:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e6c1c:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e6c20:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e6c24:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e6c28:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e6c2c:	1140001f */ 	beqz	$t2,.NB0f0e6cac
/*  f0e6c30:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e6c34:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e6c38:	8d8c2364 */ 	lw	$t4,0x2364($t4)
/*  f0e6c3c:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6c40:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0e6c44:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e6c48:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e6c4c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e6c50:	0fc546df */ 	jal	textWrap
/*  f0e6c54:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e6c58:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e6c5c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e6c60:	8dad2364 */ 	lw	$t5,0x2364($t5)
/*  f0e6c64:	8d6b2368 */ 	lw	$t3,0x2368($t3)
/*  f0e6c68:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e6c6c:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e6c70:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e6c74:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6c78:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6c7c:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6c80:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e6c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6c88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6c8c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e6c90:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e6c94:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e6c98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e6c9c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6ca0:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e6ca4:	1000001a */ 	beqz	$zero,.NB0f0e6d10
/*  f0e6ca8:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e6cac:
/*  f0e6cac:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e6cb0:	24a582e0 */ 	addiu	$a1,$a1,-32032
/*  f0e6cb4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6cb8:	0c004fc1 */ 	jal	sprintf
/*  f0e6cbc:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e6cc0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0e6cc4:	3c098008 */ 	lui	$t1,0x8008
/*  f0e6cc8:	8d29236c */ 	lw	$t1,0x236c($t1)
/*  f0e6ccc:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f0e6cd0:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e6cd4:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e6cd8:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e6cdc:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6ce0:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6ce4:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6ce8:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e6cec:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6cf0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6cf4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e6cf8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e6cfc:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e6d00:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e6d04:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6d08:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e6d0c:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e6d10:
/*  f0e6d10:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e6d14:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e6d18:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e6d1c:	11a00141 */ 	beqz	$t5,.NB0f0e7224
/*  f0e6d20:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6d24:	0fc24dd9 */ 	jal	objectiveCheck
/*  f0e6d28:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e6d2c:	10400007 */ 	beqz	$v0,.NB0f0e6d4c
/*  f0e6d30:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e6d34:	1041000c */ 	beq	$v0,$at,.NB0f0e6d68
/*  f0e6d38:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e6d3c:	10410011 */ 	beq	$v0,$at,.NB0f0e6d84
/*  f0e6d40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6d44:	10000015 */ 	beqz	$zero,.NB0f0e6d9c
/*  f0e6d48:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0e6d4c:
/*  f0e6d4c:	0fc5a4dd */ 	jal	langGet
/*  f0e6d50:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e6d54:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e6d58:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e6d5c:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e6d60:	1000000e */ 	beqz	$zero,.NB0f0e6d9c
/*  f0e6d64:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.NB0f0e6d68:
/*  f0e6d68:	0fc5a4dd */ 	jal	langGet
/*  f0e6d6c:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e6d70:	3c1800ff */ 	lui	$t8,0xff
/*  f0e6d74:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e6d78:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e6d7c:	10000007 */ 	beqz	$zero,.NB0f0e6d9c
/*  f0e6d80:	afb800c8 */ 	sw	$t8,0xc8($sp)
.NB0f0e6d84:
/*  f0e6d84:	0fc5a4dd */ 	jal	langGet
/*  f0e6d88:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e6d8c:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e6d90:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e6d94:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e6d98:	afb900c8 */ 	sw	$t9,0xc8($sp)
.NB0f0e6d9c:
/*  f0e6d9c:	3c098007 */ 	lui	$t1,0x8007
/*  f0e6da0:	8d293af0 */ 	lw	$t1,0x3af0($t1)
/*  f0e6da4:	3c0c800a */ 	lui	$t4,0x800a
/*  f0e6da8:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e6dac:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e6db0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e6db4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e6db8:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e6dbc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e6dc0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e6dc4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e6dc8:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e6dcc:	8d8c2c48 */ 	lw	$t4,0x2c48($t4)
/*  f0e6dd0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e6dd4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e6dd8:	11cc0004 */ 	beq	$t6,$t4,.NB0f0e6dec
/*  f0e6ddc:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6de0:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0e6de4:	8d6bc2f8 */ 	lw	$t3,-0x3d08($t3)
/*  f0e6de8:	afab00c8 */ 	sw	$t3,0xc8($sp)
.NB0f0e6dec:
/*  f0e6dec:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e6df0:	8dad2364 */ 	lw	$t5,0x2364($t5)
/*  f0e6df4:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e6df8:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0e6dfc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e6e00:	0fc54655 */ 	jal	textMeasure
/*  f0e6e04:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e6e08:	3c028007 */ 	lui	$v0,0x8007
/*  f0e6e0c:	8c423898 */ 	lw	$v0,0x3898($v0)
/*  f0e6e10:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6e14:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6e18:	10400002 */ 	beqz	$v0,.NB0f0e6e24
/*  f0e6e1c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e6e20:	afa200c8 */ 	sw	$v0,0xc8($sp)
.NB0f0e6e24:
/*  f0e6e24:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e6e28:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e6e2c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e6e30:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e6e34:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e6e38:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e6e3c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e6e40:	8d6b2364 */ 	lw	$t3,0x2364($t3)
/*  f0e6e44:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e6e48:	8d8c2368 */ 	lw	$t4,0x2368($t4)
/*  f0e6e4c:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e6e50:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e6e54:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e6e58:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e6e5c:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e6e60:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e6e64:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e6e68:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e6e6c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6e70:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e6e74:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6e78:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6e7c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e6e80:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e6e84:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e6e88:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e6e8c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6e90:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e6e94:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e6e98:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e6e9c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0e6ea0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0e6ea4:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e6ea8:	8dce2364 */ 	lw	$t6,0x2364($t6)
/*  f0e6eac:	8d4a2368 */ 	lw	$t2,0x2368($t2)
/*  f0e6eb0:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e6eb4:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e6eb8:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e6ebc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e6ec0:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e6ec4:	01815824 */ 	and	$t3,$t4,$at
/*  f0e6ec8:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e6ecc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e6ed0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6ed4:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6ed8:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6edc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e6ee0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6ee4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6ee8:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e6eec:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e6ef0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6ef4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e6ef8:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6efc:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e6f00:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e6f04:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e6f08:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6f0c:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e6f10:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e6f14:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e6f18:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e6f1c:	0fc537a0 */ 	jal	text0f153780
/*  f0e6f20:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e6f24:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e6f28:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e6f2c:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e6f30:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e6f34:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e6f38:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e6f3c:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e6f40:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e6f44:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e6f48:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e6f4c:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e6f50:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e6f54:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e6f58:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e6f5c:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e6f60:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e6f64:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e6f68:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e6f6c:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e6f70:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e6f74:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6f78:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e6f7c:	04610003 */ 	bgez	$v1,.NB0f0e6f8c
/*  f0e6f80:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e6f84:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e6f88:	00015083 */ 	sra	$t2,$at,0x2
.NB0f0e6f8c:
/*  f0e6f8c:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e6f90:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e6f94:	01cd0019 */ 	multu	$t6,$t5
/*  f0e6f98:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e6f9c:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e6fa0:	00007812 */ 	mflo	$t7
/*  f0e6fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6fac:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e6fb0:	0000c012 */ 	mflo	$t8
/*  f0e6fb4:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e6fb8:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e6fbc:	0fc37e4b */ 	jal	menugfx0f0e2498
/*  f0e6fc0:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e6fc4:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e6fc8:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e6fcc:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6fd0:	00616024 */ 	and	$t4,$v1,$at
/*  f0e6fd4:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e6fd8:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e6fdc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e6fe4:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e6fe8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e6fec:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e6ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6ff4:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e6ff8:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e6ffc:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e7000:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e7004:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e7008:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e700c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e7010:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e7014:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e7018:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e701c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7020:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7024:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e7028:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e702c:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e7030:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e7034:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e7038:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e703c:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e7040:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7044:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e7048:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e704c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e7050:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7054:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7058:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e705c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e7060:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e7064:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7068:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e706c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e7070:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e7074:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e7078:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e707c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7080:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7084:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7088:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e708c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e7090:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7094:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e7098:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e709c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e70a0:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e70a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e70a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e70ac:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e70b0:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e70b4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e70b8:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e70bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e70c0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e70c4:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e70c8:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e70cc:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e70d0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e70d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e70d8:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e70dc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e70e0:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e70e4:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e70e8:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e70ec:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e70f0:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e70f4:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e70f8:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e70fc:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e7100:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7104:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7108:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e710c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7110:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e7114:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7118:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e711c:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e7120:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e7124:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e7128:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e712c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e7130:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7134:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e713c:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e7140:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7144:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e7148:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e714c:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e7150:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7154:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7158:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e715c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e7160:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e7164:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7168:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e716c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e7170:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e7174:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7178:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e717c:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7180:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e7184:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0e7188:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0e718c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e7190:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0e7194:	00614824 */ 	and	$t1,$v1,$at
/*  f0e7198:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0e719c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e71a0:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e71a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e71a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e71ac:	01201825 */ 	or	$v1,$t1,$zero
/*  f0e71b0:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0e71b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e71b8:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e71bc:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e71c0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e71c4:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0e71c8:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0e71cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e71d0:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0e71d4:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0e71d8:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e71dc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0e71e0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e71e4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e71e8:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e71ec:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e71f0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0e71f4:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0e71f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e71fc:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0e7200:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e7204:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0e7208:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0e720c:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0e7210:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7214:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7218:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e721c:	10000074 */ 	beqz	$zero,.NB0f0e73f0
/*  f0e7220:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e7224:
/*  f0e7224:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0e7228:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0e722c:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0e7230:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e7234:	8d6b236c */ 	lw	$t3,0x236c($t3)
/*  f0e7238:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0e723c:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0e7240:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0e7244:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0e7248:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0e724c:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0e7250:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0e7254:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0e7258:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e725c:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f0e7260:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e7264:	0fc54655 */ 	jal	textMeasure
/*  f0e7268:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e726c:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e7270:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0e7274:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e7278:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0e727c:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0e7280:	0fc537a0 */ 	jal	text0f153780
/*  f0e7284:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0e7288:	0fc37e4b */ 	jal	menugfx0f0e2498
/*  f0e728c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7290:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e7294:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0e7298:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e729c:	00614824 */ 	and	$t1,$v1,$at
/*  f0e72a0:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0e72a4:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0e72a8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e72ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e72b0:	01201825 */ 	or	$v1,$t1,$zero
/*  f0e72b4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e72b8:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0e72bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e72c0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e72c4:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e72c8:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0e72cc:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0e72d0:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0e72d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e72d8:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e72dc:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e72e0:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0e72e4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e72e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e72ec:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e72f0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e72f4:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0e72f8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e72fc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e7300:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0e7304:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0e7308:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0e730c:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0e7310:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e7314:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7318:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0e731c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7320:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7324:	01602825 */ 	or	$a1,$t3,$zero
/*  f0e7328:	04e10003 */ 	bgez	$a3,.NB0f0e7338
/*  f0e732c:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0e7330:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0e7334:	00016883 */ 	sra	$t5,$at,0x2
.NB0f0e7338:
/*  f0e7338:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0e733c:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e7340:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7344:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e7348:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e734c:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0e7350:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7354:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e7358:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e735c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e7360:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e7364:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7368:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e736c:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7370:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7374:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e7378:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e737c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7380:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0e7384:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e7388:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e738c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7390:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7394:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7398:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e739c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e73a0:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0e73a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e73a8:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e73ac:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e73b0:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e73b4:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e73b8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e73bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e73c0:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e73c4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e73c8:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0e73cc:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e73d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e73d4:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e73d8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e73dc:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0e73e0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e73e4:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e73e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e73ec:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e73f0:
/*  f0e73f0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e73f4:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0e73f8:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0e73fc:	03e00008 */ 	jr	$ra
/*  f0e7400:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#endif

const char var7f1adfa0[] = "brcol";
const char var7f1adfa8[] = "%d: ";
const char var7f1adfb0[] = "%s";

// Mismatch: Stack usage is different. Target appears to use compiler-managed
// stack from 0x44 and below, which means the vars from 0x48 to 0x6c are real
// variables, and many are optimised out.
//Gfx *menuitemObjectivesRenderOne(Gfx *gdl, struct menudialog *dialog, s32 index, s32 position, s16 objx, s16 objy, s16 width, s16 height, bool withstatus, s32 arg9)
//{
//	u32 sp12c;
//	s32 x; // 128
//	s32 y; // 124
//	char *sp120;
//	char buffer[80]; // d0
//	char *spcc;
//	u32 spc8;
//	s32 textwidth; // c4
//	s32 textheight; // c0
//	s32 spbc;
//	s32 tmp;
//	s32 spb4;
//	s32 spb0;
//	s32 spac;
//	s32 spa8;
//	u32 stack3[2];
//	s32 sp9c;
//	s32 sp98;
//	u32 s0;
//	s32 stack[4];
//	s32 sp80;
//	s32 sp7c;
//	s32 sp78;
//	s32 sp74;
//	s32 stack2;
//	s32 sp6c;
//	s32 sp58;
//	s32 sp54;
//
//	spbc = 0;
//
//	if (arg9) {
//		spbc = PAL ? 16 : 12;
//	}
//
//	mainOverrideVariable("brcol", &var800711e8);
//	sp120 = langGet(g_Briefing.objectivenames[index]);
//	y = objy;
//	sp12c = MIXCOLOUR(dialog, unfocused);
//
//	if (dialog->dimmed) {
//		sp12c = (colourBlend(sp12c, 0, 0x2c) & 0xffffff00) | (sp12c & 0xff);
//	}
//
//	textSetWaveColours(g_MenuColourPalettes3[dialog->type].unfocused, g_MenuColourPalettes2[dialog->type].unfocused);
//	buffer[0] = '\0';
//
//	// Render objective number
//	gdl = text0f153628(gdl);
//	sprintf(buffer, "%d: ", position);
//	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
//	x = objx - textwidth + 25;
//	gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, sp12c, width, height, 0, 0);
//
//	x = objx + 25;
//
//	if (arg9) {
//		textWrap(85, sp120, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs);
//		gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, sp12c, width, height, 0, 0);
//	} else {
//		sprintf(buffer, "%s", sp120);
//		gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, sp12c, width, height, 0, 0);
//	}
//
//	if (withstatus) {
//		switch (objectiveCheck(index)) {
//		case OBJECTIVE_INCOMPLETE:
//			spcc = langGet(L_OPTIONS_001); // "Incomplete"
//			spc8 = 0xffff00ff;
//			break;
//		case OBJECTIVE_COMPLETE:
//			spcc = langGet(L_OPTIONS_000); // "Complete"
//			spc8 = 0x00ff00ff;
//			break;
//		case OBJECTIVE_FAILED:
//			spcc = langGet(L_OPTIONS_002); // "Failed"
//			spc8 = 0xff4040ff;
//			break;
//		}
//
//		if (dialog != g_Menus[g_MpPlayerNum].curdialog) {
//			spc8 = g_MenuColourPalettes[0].unfocused;
//		}
//
//		textMeasure(&textheight, &textwidth, spcc, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//		if (var800711e8 != 0) {
//			spc8 = var800711e8;
//		}
//
//		x = objx + width - textwidth - 10;
//		y = objy + spbc + 9;
//
//		gdl = textRenderProjected(gdl, &x, &y, spcc, g_CharsHandelGothicXs, g_FontHandelGothicXs, spc8, width, height, 0, 0);
//
//		x = objx + width - textwidth - 10;
//		y = objy + spbc + 9;
//
//		gdl = textRenderProjected(gdl, &x, &y, spcc, g_CharsHandelGothicXs, g_FontHandelGothicXs, spc8 & 0xffffff7f, width, height, 0, 0);
//
//		x = objx + width - textwidth - 13;
//		y = objy + 9;
//
//		gdl = text0f153780(gdl);
//
//		spb4 = objx + 22;
//		spb0 = objy - 2;
//		spac = objy + 8;
//		spa8 = y + spbc + 2;
//		tmp = (objx * 3 + objx + 66) / 4;
//		sp9c = x;
//		sp98 = tmp + 19 + (sp9c - tmp - 24) * (position - 1) / 5;
//
//		sp58 = (objx * 3 + objx + 66) / 4 - 1;
//		sp54 = (objx * 3 + objx + 66) / 4 + 14;
//
//		gdl = menugfx0f0e2498(gdl);
//
//		// Blue lines
//		gdl = menugfxDrawTessellatedRect(gdl, objx, spb0, spb4, spb0 + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, spb4, spb0, spb4 + 1, spac, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, objx, spac, sp58, spac + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 3, spac, spb4 + 1, spac + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58, spac, sp58 + 1, spa8 + 2, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, spac, sp58 + 3, spa8, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, spa8, sp54, spa8 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58, spa8 + 2, sp54, spa8 + 3, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp54, spa8, sp98, spa8 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp54, spa8 + 2, sp98, spa8 + 3, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//
//		// Coloured lines
//		gdl = menugfxDrawTessellatedRect(gdl, sp98, spa8, sp98 + 1, spa8 + 3, (spc8 & 0xffffff00) | 0x3f, (spc8 & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp98 + 1, spa8 + 1, sp9c - 4, spa8 + 2, (spc8 & 0xffffff00) | 0x3f, (spc8 & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp9c - 4, spa8 + 1, sp9c, spa8 + 2, (spc8 & 0xffffff00) | 0x3f, spc8 & 0xffffff00 | 0xcf);
//	} else {
//		// Render lines without status
//		sp80 = objx + 22;
//		sp7c = objy - 2;
//		sp78 = objy + 8;
//		sp74 = y + 1;
//
//		textMeasure(&textheight, &textwidth, sp120, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
//
//		sp6c = objx + textwidth + 25;
//		sp58 = (objx * 3 + objx + 66) / 4 - 1;
//
//		gdl = text0f153780(gdl);
//		gdl = menugfx0f0e2498(gdl);
//
//		gdl = menugfxDrawTessellatedRect(gdl, objx, sp7c, sp80, sp7c + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp80, sp7c, sp80 + 1, sp78, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, objx, sp78, sp58, sp78 + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 3, sp78, sp80 + 1, sp78 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58, sp78, sp58 + 1, sp74 + 2, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, sp78, sp58 + 3, sp74, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, sp74, sp6c, sp74 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//	}
//
//	return gdl;
//}

Gfx *menuitemObjectivesRender(Gfx *gdl, struct menurendercontext *context)
{
	s32 y = context->y + 5;
	s32 position = 1;
	s32 i;

	for (i = 0; i < 6; i++) {
		if (g_Briefing.objectivenames[i] && g_Briefing.objectivedifficulties[i] & (1 << lvGetDifficulty())) {
			gdl = menuitemObjectivesRenderOne(gdl,
					context->dialog,
					i, position, context->x, y, context->width, context->height,
					context->item->param != 1,
					context->item->param == 2);

			position++;

#if VERSION >= VERSION_JPN_FINAL
			if (context->item->param == 0) {
				y += 24;
			} else if (context->item->param == 2) {
				y += 36;
			} else {
				y += 16;
			}
#else
			if (context->item->param == 0) {
				y += 18;
			} else if (context->item->param == 2) {
				y += VERSION >= VERSION_PAL_FINAL ? 34 : 30;
			} else {
				y += 14;
			}
#endif
		}
	}

	return gdl;
}

Gfx *menuitemModelRender(Gfx *gdl, struct menurendercontext *context)
{
	if (context->item->flags & MENUITEMFLAG_00200000) {
		struct menuitemrenderdata renderdata;
		union handlerdata data;

		renderdata.x = context->x;
		renderdata.y = context->y;
		renderdata.width = context->width;

		if (context->dialog->transitionfrac < 0) {
			renderdata.colour = g_MenuColourPalettes[context->dialog->type].focused;
		} else {
			renderdata.colour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			renderdata.colour = (colourBlend(renderdata.colour, 0, 127) & 0xffffff00) | (renderdata.colour & 0xff);
		}

		renderdata.unk10 = true;

		data.type19.gdl = gdl;
		data.type19.unk04 = (s32)&renderdata;
		data.type19.renderdata2 = &renderdata;

		gdl = (Gfx *)context->item->handler(MENUOP_RENDER, context->item, &data);
	}

	return gdl;
}

Gfx *menuitemLabelRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour1;
	u32 colour2;
	char *text;
	s32 x;
	s32 y;
	struct menudfc *menudfc;
	u8 savedvalue = var8007fb9c;
	struct fontchar *font1 = g_CharsHandelGothicSm;
	struct font *font2 = g_FontHandelGothicSm;

	x = context->x + 10;
	y = context->y + 2;

	if (context->item->flags & MENUITEMFLAG_00000010) {
		x -= 6;
	}

	text = menuResolveParam2Text(context->item);

	if (!text) {
		return gdl;
	}

#if VERSION != VERSION_JPN_FINAL
	if (context->item->flags & MENUITEMFLAG_00000200) {
		font1 = g_CharsHandelGothicXs;
		font2 = g_FontHandelGothicXs;
		y -= 2;
	}
#endif

	if (context->item->flags & MENUITEMFLAG_00000020) {
		// Center
		s32 textheight;
		s32 textwidth;
		textMeasure(&textheight, &textwidth, text, font1, font2, 0);
		x = context->x + (context->width - textwidth) / 2;
	}

	if (context->item->flags & MENUITEMFLAG_00000100) {
		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].checkedunfocused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].checkedunfocused,
					g_MenuColourPalettes[context->dialog->type].checkedunfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].checkedunfocused,
				g_MenuColourPalettes2[context->dialog->type].checkedunfocused);
	} else {
		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].unfocused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].unfocused,
					g_MenuColourPalettes[context->dialog->type].unfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].unfocused,
				g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].disabled;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].disabled,
					g_MenuColourPalettes[context->dialog->type].disabled,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].disabled,
				g_MenuColourPalettes2[context->dialog->type].disabled);
	}

	menudfc = func0f0f1338(context->item);

	if (menudfc) {
		if (menudfc->unk04 < 0) {
			return gdl;
		}

		textBackupDiagonalBlendSettings();
		textSetDiagonalBlend(x, y, menudfc->unk04 * 300, 0);
		var8007fb9c = true;
	}

	colour2 = colour1;

	if (context->item->flags & MENUITEMFLAG_01000000) {
		union handlerdata data;
		data.label.colour2 = colour2;
		data.label.colour1 = colour1;

		if (context->item->handlervoid) {
			context->item->handlervoid(MENUOP_GETCOLOUR, context->item, &data);
		}

		if (context->item->handlervoid) {
		}

		colour2 = data.label.colour2;
		colour1 = data.label.colour1;
	}

	gdl = text0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, text,
			font1, font2, colour1, context->width, context->height, 0, 0);

	if ((context->item->flags & MENUITEMFLAG_00008000) == 0) {
		// Right side text
		text = menuResolveText(context->item->param3, context->item);

		// This is not how you check if a string is empty...
		if (text != NULL && text != "") {
			s32 textheight;
			s32 textwidth;

			y = context->y + 2;

#if VERSION != VERSION_JPN_FINAL
			if (context->item->flags & MENUITEMFLAG_00000200) {
				y -= 2;
			}
#endif

			textMeasure(&textheight, &textwidth, text, font1, font2, 0);
			x = context->x + context->width - textwidth - 10;

			if (context->item->flags & MENUITEMFLAG_00000010) {
				x += 6;
			}

			gdl = textRenderProjected(gdl, &x, &y, text,
					font1, font2, colour2, context->width, context->height, 0, 0);
		}
	}

	gdl = text0f153780(gdl);

	if (menudfc) {
		if (context->width + 200 < menudfc->unk04 * 300 && context->dialog->redrawtimer < 0) {
			func0f0f13ec(context->item);
		}

		var8007fb9c = savedvalue;

		textRestoreDiagonalBlendSettings();
	}

	if (context->item->flags & MENUITEMFLAG_00200000) {
		struct menuitemrenderdata renderdata;
		union handlerdata data;

		renderdata.x = context->x;
		renderdata.y = context->y;
		renderdata.width = context->width;
		renderdata.colour = colour1;
		renderdata.unk10 = false;

		data.type19.gdl = gdl;
		data.type19.unk04 = 0;
		data.type19.renderdata2 = &renderdata;

		gdl = (Gfx *) context->item->handler(MENUOP_RENDER, context->item, &data);
	}

	return gdl;
}

/**
 * Renders two yellow bars and an optional label. Suspected to be a resource
 * meter but with the calculations ifdeffed out, so the widths are static.
 */
Gfx *menuitemMeterRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 a = 9;
	char *text;
	s32 x;
	s32 y;
	u32 colour1;
	u32 colour2;
	u32 colour;
	s32 x1;
	s32 x2;
	s32 x3;

	if (context->dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 127) & 0xffffff00) | (colour & 0xff);
	}

	colour2 = 0xffff0000 | (colour & 0xff);
	colour1 = colourBlend(colour2, colour2 & 0xff, 127);

	x1 = context->x + 32;
	x2 = x1 + a;
	x3 = x2 + 6;

	gdl = textSetPrimColour(gdl, colour1);
	gDPFillRectangleScaled(gdl++, x1, context->y, x2, context->y + 5);
	gdl = text0f153838(gdl);

	gdl = textSetPrimColour(gdl, colour2);
	gDPFillRectangleScaled(gdl++, x2, context->y, x3, context->y + 5);
	gdl = text0f153838(gdl);

	text = menuResolveParam2Text(context->item);

	if (text) {
		gdl = text0f153628(gdl);
		x = context->x;
		y = context->y - 1;
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colour2 & 0xffffff7f, context->width, context->height, 0, 0);
		gdl = text0f153780(gdl);
	}

	return gdl;
}

Gfx *menuitemSelectableRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 leftcolour;
	u32 rightcolour;
	char *text;
	s32 x = context->x + 10;
	s32 y = context->y + 2;
	struct fontchar *font1 = g_CharsHandelGothicSm;
	struct font *font2 = g_FontHandelGothicSm;

	if (context->item->flags & MENUITEMFLAG_00000010) {
		x -= 6;
	}

	if (context->item->flags & MENUITEMFLAG_00400000) {
		font1 = g_CharsHandelGothicMd;
		font2 = g_FontHandelGothicMd;
	}

	text = menuResolveParam2Text(context->item);

	if (context->dialog->transitionfrac < 0) {
		leftcolour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		leftcolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		leftcolour = colourBlend(leftcolour, 0, 127) & 0xffffff00 | leftcolour & 0xff;
	}

	rightcolour = leftcolour;

	if (context->focused) {
		// Mismatch: The addiu and lui at eb030 and eb034 are swapped. The addiu
		// is adding the lower half of the address of g_MenuColourPalettes for
		// use in the else branch. The lui is loading a value into $at for the
		// float to u32 conversion for weight.
		u32 colour2;
		u32 weight = func0f006b08(40) * 255; \
		if (context->dialog->transitionfrac < 0) { \
			colour2 = g_MenuColourPalettes[context->dialog->type].focused; \
		} else { \
			colour2 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		leftcolour = colourBlend(colourBlend(leftcolour, leftcolour & 0x000000ff, 127), colour2, weight);

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].focused,
				g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].unfocused,
				g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		if (context->dialog->transitionfrac < 0) {
			leftcolour = g_MenuColourPalettes[context->dialog->type].disabled;
		} else {
			leftcolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].disabled,
					g_MenuColourPalettes[context->dialog->type].disabled,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			leftcolour = colourBlend(leftcolour, 0x00000000, 127) & 0xffffff00 | leftcolour & 0xff;
		}

		rightcolour = leftcolour;

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].disabled,
				g_MenuColourPalettes2[context->dialog->type].disabled);
	}

	if (context->item->flags & MENUITEMFLAG_00000020) {
		// Center text
		s32 textheight;
		s32 textwidth;
		textMeasure(&textheight, &textwidth, text, font1, font2, 0);
		x = context->x + (context->width - textwidth) / 2;
	}

	if (context->item->flags & MENUITEMFLAG_00400000) {
		x += 35;
		y += 6;
	}

	gdl = text0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
			leftcolour, context->width, context->height, 0, 0);

	if ((context->item->flags & (MENUITEMFLAG_00008000 | MENUITEMFLAG_00400000)) == 0) {
		// Right side text
		text = menuResolveText(context->item->param3, context->item);

		// This is not how you check if a string is empty...
		if (text != NULL && text != "") {
			s32 textheight;
			s32 textwidth;

			y = context->y + 2;
			textMeasure(&textheight, &textwidth, text, font1, font2, 0);
			x = context->x + context->width - textwidth - 10;

			gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
					rightcolour, context->width, context->height, 0, 0);
		}
	}

	return text0f153780(gdl);
}

bool menuitemSelectableTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags)
{
	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && inputs->select) {
		menuPlaySound(MENUSOUND_SELECT);

		if (item->flags & MENUITEMFLAG_00000008) {
			menuPopDialog();
		}

		if (item->flags & MENUITEMFLAG_00000004) {
			menuPushDialog((struct menudialogdef *)item->handler);
		} else if (item->handler) {
			union handlerdata data;
			item->handler(MENUOP_SET, item, &data);
		}
	}

	return true;
}

Gfx *menuitemSliderRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;
	char *label;
	char buffer[16];
	s32 x;
	s32 y;
	s32 extray;
	s32 textwidth;
	s32 textheight;
	union handlerdata data;
	s32 slidervalue;
	s32 markerx;

	extray = 0;

	if (context->item->handler != NULL) {
		context->item->handler(MENUOP_GETSLIDER, context->item, &data);
		slidervalue = data.slider.unk02;
	} else {
		slidervalue = 0;
	}

	if (context->dialog->unk6e != 0) {
		extray = 10;
	}

	if (context->item->flags & MENUITEMFLAG_00100000) {
		extray = 10;
	}

	x = context->x + 10;
	y = context->y + 2;

	if (context->item->flags & MENUITEMFLAG_00000010) {
		x -= 6;
	}

	label = menuResolveParam2Text(context->item);
	markerx = context->x + context->width + slidervalue * 75 / context->item->param3 - 82;

	colour = MIXCOLOUR(context->dialog, unfocused);

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
	}

	if (context->focused) {
		if (context->focused & 2) {
			u32 tmpcolour;
			u32 weight = func0f006b08(40) * 255.0f;

			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight) | 0xff;
		}

		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].focused, g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	gdl = menugfxRenderSlider(gdl, context->x + context->width - 82, context->y + extray + 5, context->x + context->width - 7, context->y + extray + 11, markerx, colour);

	colour = MIXCOLOUR(context->dialog, unfocused);

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
	}

	if (context->focused != 0) {
		if (context->focused & 2) {
			u32 tmpcolour;
			u32 weight = func0f006b08(20) * 255.0f;
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		} else {
			u32 tmpcolour;
			u32 weight = func0f006b08(40) * 255.0f;
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		}

		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].focused, g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	gdl = text0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, label, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);

	if ((context->item->flags & MENUITEMFLAG_00002000) == 0) {
		strcpy(buffer, "");
		sprintf(buffer, "%d\n", slidervalue);

		if (context->item->handler != NULL) {
			data.slider.value = slidervalue;
			data.slider.label = buffer;

			context->item->handler(MENUOP_GETSLIDERLABEL, context->item, &data);
		}

		textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		x = context->x + context->width - textwidth - 7;
		y = context->y + 2;

		colour = MIXCOLOUR(context->dialog, unfocused);

		if (context->dialog->dimmed) {
			colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
		}

		textSetWaveColours(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);

		colour = (colour & 0xffffff00) | ((colour & 0xff) >> 1);
		gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);
	}

	gdl = text0f153780(gdl);

	return gdl;
}

bool menuitemSliderTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	s32 index;
	union handlerdata handlerdata;
	s32 tmp;
	f32 f0;
	f32 f2;
	f32 f14;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED)) {
		if (tickflags & MENUTICKFLAG_DIALOGISDIMMED) {
			if (item->handler) {
				item->handler(MENUOP_GETSLIDER, item, &handlerdata);
				index = (s16)handlerdata.slider.value;
			} else {
				index = 0;
			}

			if ((item->flags & MENUITEMFLAG_00000800) == 0
					&& g_Menus[g_MpPlayerNum].xrepeatmode == MENUREPEATMODE_SLOW) {
				index = index + inputs->leftright;
			} else {
				f0 = data->slider.unk00 / 1000.0f;
				f0 = (f0 * 100.0f) / item->param3;
#if VERSION >= VERSION_PAL_BETA
				f0 = f0 + inputs->leftrightheld * g_Vars.diffframe60freal;
#else
				f0 = f0 + inputs->leftrightheld * g_Vars.diffframe60;
#endif
				f0 = (item->param3 * f0) / 100.0f;

				tmp = f0;
				f0 -= tmp;
				index += tmp;

				data->slider.unk00 = f0 * 1000.0f;
			}

			if (inputs->xaxis < 0) {
				f14 = inputs->xaxis;
				f2 = -f14;
			} else {
				f14 = inputs->xaxis;
				f2 = f14;
			}

			if ((item->flags & MENUITEMFLAG_00000800) == 0 && f2 < 40) {
				if (g_Menus[g_MpPlayerNum].xrepeatmode != MENUREPEATMODE_SLOW) {
					index = index + inputs->leftright;
				}
			} else {
				f0 = data->slider.unk00 / 1000.0f;
				f0 = (f0 * 100.0f) / item->param3;

				if (inputs->xaxis < 0) {
					f2 = -f14;
				} else {
					f2 = f14;
				}

				if (f2 > 20) {
					f2 = (f2 - 20) * 0.0625f;
#if VERSION >= VERSION_PAL_BETA
					f2 *= g_Vars.diffframe60freal;
#else
					f2 *= g_Vars.diffframe60f;
#endif

					if (inputs->xaxis < 0) {
						f0 -= f2;
					} else {
						f0 += f2;
					}
				}

				f0 = (item->param3 * f0) / 100.0f;
				tmp = f0;
				f0 -= tmp;
				index += tmp;
				data->slider.unk00 = f0 * 1000.0f;
			}

			if (index < 0) {
				index = 0;
			}

			if (index > item->param3) {
				index = item->param3;
			}

			inputs->leftright = 0;
			handlerdata.slider.value = index;

			if (item->handler) {
				item->handler(MENUOP_SET, item, &handlerdata);
			}

			if (inputs->select) {
				dialog->dimmed = false;
			}
		} else {
			if (inputs->select) {
				dialog->dimmed = true;
			}
		}
	}

	return true;
}

void menuitemSliderInit(union menuitemdata *data)
{
	data->slider.unk00 = 0;
}

Gfx *menuitemCarouselRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour = 0xff0000ff;

	if (context->focused) {
		u32 colour1;
		u32 weight = func0f006b08(40) * 255;

		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].focused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		colour = colourBlend(colourBlend(colour, 0x000000ff, 127), colour1, weight);
	}

	// Left arrow
	gdl = menugfxDrawCarouselChevron(gdl, context->x, context->y + context->height / 2, 8, 1, -1, colour);

	// Right arrow
	gdl = menugfxDrawCarouselChevron(gdl, context->x + context->width, context->y + context->height / 2, 8, 3, -1, colour);

	// This part of the function is unused because param2 is always zero.
	// Setting it to 0x7b causes a crash.
	// 0x7c and 0x7d don't do anything with the option value, so it's probable
	// that the original source has a commented function call in that block.
	if (context->item->param2 == 0x7b && context->item->handler) {
		union handlerdata data;
		s32 headorbodynum = 0;

		context->item->handler(MENUOP_GETSELECTEDINDEX, context->item, &data);
		headorbodynum += data.carousel.value;

		gdl = func0f14f07c(gdl, headorbodynum,
				context->x + context->width / 2 - 32, context->y,
				context->x + context->width / 2 + 32, context->y + 64);
	} else if ((context->item->param2 == 0x7c || context->item->param2 == 0x7d) && context->item->handler) {
		union handlerdata data;
		context->item->handler(MENUOP_GETSELECTEDINDEX, context->item, &data);
	}

	return gdl;
}

bool menuitemCarouselTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags)
{
	union handlerdata data;
	s32 index;
	s32 numoptions;
	bool done;
	u32 stack;

	if (((tickflags & MENUTICKFLAG_ITEMISFOCUSED) || (item->flags & MENUITEMFLAG_04000000)) && item->handler) {
		if (inputs->leftright != 0) {
			if (mpIsPlayerLockedOut(g_MpPlayerNum) == 0 || (item->flags & MENUITEMFLAG_00020000) == 0) {
				done = false;

				item->handler(MENUOP_GETOPTIONCOUNT, item, &data);

				numoptions = data.carousel.value;
				item->handler(MENUOP_GETSELECTEDINDEX, item, &data);

				index = data.carousel.value;

				while (!done) {
					index = index + inputs->leftright;

					if (index >= numoptions) {
						index = 0;
					}

					if (index < 0) {
						index = numoptions - 1;
					}

					// Some kind of option-is-locked check?
					data.carousel.value = index;

					if (!item->handler(MENUOP_21, item, &data)) {
						done = true;
					}
				}

				data.carousel.value = index;
#if VERSION >= VERSION_NTSC_1_0
				data.carousel.unk04 = inputs->shoulder;
#endif

				item->handler(MENUOP_SET, item, &data);
			}
		}

		if (item->handler) {
			item->handler(MENUOP_11, item, &data);
		}
	}

	return true;
}

Gfx *menuitemCheckboxRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 maincolour = 0x00000000;
	char *text;
	s32 x;
	s32 y;
	u8 data[3];
	bool checked = false;
	u32 fillcolour = 0xff002faf;
	struct font *font2 = g_FontHandelGothicSm;
	struct fontchar *font1 = g_CharsHandelGothicSm;

	if (context->item->flags & MENUITEMFLAG_00000200) {
		font2 = g_FontHandelGothicXs;
		font1 = g_CharsHandelGothicXs;
	}

	x = context->x;
	y = context->y;
	text = menuResolveParam2Text(context->item);
	data[0] = 0;

	if (context->item->handler
			&& context->item->handler(MENUOP_GET, context->item, (union handlerdata *)data) == true) {
		checked = true;

		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].checkedunfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].checkedunfocused,
					g_MenuColourPalettes[context->dialog->type].checkedunfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].checkedunfocused,
				g_MenuColourPalettes2[context->dialog->type].checkedunfocused);
	} else {
		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].unfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].unfocused,
					g_MenuColourPalettes[context->dialog->type].unfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].unfocused,
				g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	gdl = text0f153628(gdl);

	if (context->focused) {
		// Mismatch: The addiu and lui at ec8fc and ec900 are swapped. The addiu
		// is adding the lower half of the address of g_MenuColourPalettes for
		// use in the else branch. The lui is loading a value into $at for the
		// float to u32 conversion for weight.
		u32 focuscolour;
		u32 weight = func0f006b08(40) * 255; \
		if (context->dialog->transitionfrac < 0) { \
			focuscolour = g_MenuColourPalettes[context->dialog->type].focused;
		} else {
			focuscolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		maincolour = colourBlend(colourBlend(maincolour, maincolour & 0xff, 127), focuscolour, weight);

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].focused,
				g_MenuColourPalettes2[context->dialog->type].focused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].disabled;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].disabled,
					g_MenuColourPalettes[context->dialog->type].disabled,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		textSetWaveColours(
				g_MenuColourPalettes3[context->dialog->type].disabled,
				g_MenuColourPalettes2[context->dialog->type].disabled);

		fillcolour = 0x7f002faf;
	}

#if VERSION == VERSION_JPN_FINAL
	gdl = menugfxDrawCheckbox(gdl, context->x + context->width - 19, context->y + 2, 9, checked, maincolour, fillcolour);
#else
	gdl = menugfxDrawCheckbox(gdl, context->x + context->width - 16, context->y + 2, 6, checked, maincolour, fillcolour);
#endif

	x = context->x + 10;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
			maincolour, context->width, context->height, 0, 0);

	return text0f153780(gdl);
}

bool menuitemCheckboxTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags)
{
	union handlerdata data;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && inputs->select) {
		if (item->handler && item->handler(MENUOP_GET, item, &data) == 1) {
			data.checkbox.value = 0;
			menuPlaySound(MENUSOUND_TOGGLEOFF);
		} else {
			data.checkbox.value = 1;
			menuPlaySound(MENUSOUND_TOGGLEON);
		}

		if (item->handler) {
			item->handler(MENUOP_SET, item, &data);
		}
	}

	return true;
}

char *menuitemScrollableGetText(u32 type)
{
	switch (type) {
	case DESCRIPTION_MPCONFIG:
		return challengeGetConfigDescription(g_Menus[g_MpPlayerNum].training.mpconfig);
	case DESCRIPTION_MPCHALLENGE:
		if (!challengeIsLoaded()) {
			g_Menus[g_MpPlayerNum].unk840.unk010 = 0x4fac5ace;
			challengeLoadAndStoreCurrent(g_Menus[g_MpPlayerNum].unk840.unk004, g_Menus[g_MpPlayerNum].unk840.unk008);
		}
		return challengeGetCurrentDescription();
	case DESCRIPTION_CHRBIO:         return ciGetChrBioDescription();
	case DESCRIPTION_MISCBIO:        return ciGetMiscBioDescription();
	case DESCRIPTION_DEVICETRAINING: return dtGetDescription();
	case DESCRIPTION_FRWEAPON:       return frGetWeaponDescription();
	case DESCRIPTION_HANGARBIO:      return ciGetHangarBioDescription();
	case DESCRIPTION_HOLOTRAINING:   return htGetDescription();
	case DESCRIPTION_HOLOTIP1:       return htGetTip1();
	case DESCRIPTION_HOLOTIP2:       return htGetTip2();
	case DESCRIPTION_DEVICETIP1:     return dtGetTip1();
	case DESCRIPTION_DEVICETIP2:     return dtGetTip2();
	}

	return langGet(g_Briefing.briefingtextnum);
}

/**
 * Render a scrollable menu item, such as briefing paragraphs and challenge
 * descriptions.
 *
 * The text returned from menuitemScrollableGetText is first wrapped to fit the
 * width of the dialog. It is then separated into two strings:
 *
 * headings - which are started with the pipe character and ended with a
 * double line break
 * body text - which is anything else
 *
 * Headings are rendered in red, with a dropshadow and are outdented.
 */
Gfx *menuitemScrollableRender(Gfx *gdl, struct menurendercontext *context)
{
	char alltext[8000] = "";
	char headingtext[8000];
	char bodytext[8000];
	bool prevwaslinebreak;
	char *streams[2];
	char *inptr;
	s32 inheading;
	struct menuitemdata_scrollable *data = &context->data->scrollable;
	u32 colour;
	s32 x;
	s32 y;
	char *rawtext;
	s32 paddingright = 24;

	rawtext = menuitemScrollableGetText(context->item->param);

	if (menuIsScrollableUnscrollable(context->item)) {
		paddingright = 10;
	}

	if (rawtext) {
		textWrap(context->width - paddingright, rawtext, alltext, g_CharsHandelGothicSm, g_FontHandelGothicSm);
	}

	inptr = alltext;
	streams[1] = headingtext;
	streams[0] = bodytext;
	inheading = 0;
	prevwaslinebreak = false;

	while (*inptr != '\0') {
		if (*inptr == '|') {
			// Pipe character - don't append it to either string,
			// but switch the active string to the heading one
			inheading = 1;
		} else if (*inptr == '\n') {
			// Copy line breaks to both strings
			*streams[0] = *inptr;
			streams[0]++;
			*streams[1] = *inptr;
			streams[1]++;

			if (prevwaslinebreak) {
				// Got two line breaks in a row, so switch the active string
				// back to the body one
				inheading = 0;
			}

			prevwaslinebreak = true;
		} else {
			// Append to whichever string is the active one
			prevwaslinebreak = false;
			*streams[inheading] = *inptr;
			streams[inheading]++;
		}

		inptr++;
	}

	*streams[0] = '\0';
	*streams[1] = '\0';

	x = context->x + 2;
	y = context->y + 2;

	if (context->dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		colour = colourBlend(colour, 0, 0x7f) & 0xffffff00 | colour & 0xff;
	}

	textSetWaveColours(
			g_MenuColourPalettes3[context->dialog->type].unfocused,
			g_MenuColourPalettes2[context->dialog->type].unfocused);

	gdl = text0f153628(gdl);

	// Heading text shadow
	x = context->x + 3;
	y = context->y + 3;
	gdl = textRenderProjected(gdl, &x, &y, headingtext, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0x000000ff, context->width - 4, context->height - 4, -data->unk00, 0);

	// Heading text (red)
	x = context->x + 2;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, headingtext, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0xff4444ff, context->width - 4, context->height - 4, -data->unk00, 0);

	// Body text
	x = menuIsScrollableUnscrollable(context->item) ? context->x + 5 : context->x + 12;
	y = context->y + 2;

	gdl = textRenderProjected(gdl, &x, &y, bodytext, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			colour, context->width - 4, context->height - 1, -data->unk00, 0);

	return text0f153780(gdl);
}

bool menuitemScrollableTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	u32 stack;

#if VERSION >= VERSION_PAL_BETA
	if ((s16)dialog->height != data->scrollable.unk06 || data->scrollable.unk08 != g_LanguageId) {
#else
	if ((s16)dialog->height != data->scrollable.unk06) {
#endif
		char wrapped[8000] = "";
		char *rawtext;
		s32 width;
		s32 height;
		s32 rowindex;
		s32 colindex;
		s16 colwidth;
		s16 rowheight;

#if VERSION >= VERSION_PAL_BETA
		data->scrollable.unk08 = g_LanguageId;
#endif

		dialogFindItem(dialog, item, &rowindex, &colindex);

		colwidth = g_Menus[g_MpPlayerNum].cols[colindex].width;
		rowheight = g_Menus[g_MpPlayerNum].rows[rowindex].height;

		if (menuIsScrollableUnscrollable(item)) {
			width = colwidth - 10;
		} else {
			width = colwidth - 24;
		}

		rawtext = menuitemScrollableGetText(item->param);

		if (rawtext) {
			textWrap(width, rawtext, wrapped, g_CharsHandelGothicSm, g_FontHandelGothicSm);
		}

		textMeasure(&height, &width, wrapped, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		data->scrollable.unk04 = height - rowheight + 5;

		if (data->scrollable.unk04 < -10) {
			data->scrollable.unk04 = -10;
		}

		data->scrollable.unk06 = dialog->height;
	}

	if (menuIsScrollableUnscrollable(item)) {
		data->scrollable.unk00 = 0;
	} else if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		f32 floatval;
		s32 intval = 0;

		if (inputs->yaxis < 0) {
			floatval = -(f32)inputs->yaxis;
		} else {
			floatval = inputs->yaxis;
		}

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_BETA
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			if (inputs->yaxis < 0) {
				intval = floatval;
			} else {
				intval = -(s32)floatval;
			}
		}

#if VERSION >= VERSION_PAL_BETA
		intval = intval + (s32)(((f32)inputs->updownheld + (f32)inputs->updownheld) * g_Vars.diffframe60freal);
#else
		intval += inputs->updownheld * 2 * g_Vars.diffframe60;
#endif
		data->scrollable.unk00 += intval;

		if (data->scrollable.unk00 < -10) {
			data->scrollable.unk00 = -10;
		}

		if (data->scrollable.unk00 > data->scrollable.unk04) {
			data->scrollable.unk00 = data->scrollable.unk04;
		}
	}

	return true;
}

void menuitemScrollableInit(union menuitemdata *data)
{
	data->scrollable.unk06 = -1;
	data->scrollable.unk00 = -10;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel menuitemMarqueeRender
/*  f0ee244:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f0ee248:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ee24c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ee250:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ee254:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f0ee258:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ee25c:	00a08825 */ 	move	$s1,$a1
/*  f0ee260:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0ee264:	0fc3c87a */ 	jal	menuResolveParam2Text
/*  f0ee268:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ee26c:	3c188007 */ 	lui	$t8,0x8007
/*  f0ee270:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0ee274:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0ee278:	2718172c */ 	addiu	$t8,$t8,0x172c
/*  f0ee27c:	9b010002 */ 	lwr	$at,0x2($t8)
/*  f0ee280:	27af0064 */ 	addiu	$t7,$sp,0x64
/*  f0ee284:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0ee288:	b9e10002 */ 	swr	$at,0x2($t7)
/*  f0ee28c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ee290:	8d4a0154 */ 	lw	$t2,0x154($t2)
/*  f0ee294:	8d6b0150 */ 	lw	$t3,0x150($t3)
/*  f0ee298:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ee29c:	14400003 */ 	bnez	$v0,.JF0f0ee2ac
/*  f0ee2a0:	afab005c */ 	sw	$t3,0x5c($sp)
/*  f0ee2a4:	10000131 */ 	b	.JF0f0ee76c
/*  f0ee2a8:	8fa20088 */ 	lw	$v0,0x88($sp)
.JF0f0ee2ac:
/*  f0ee2ac:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0ee2b0:	44803000 */ 	mtc1	$zero,$f6
/*  f0ee2b4:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0ee2b8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ee2bc:	00000000 */ 	nop
/*  f0ee2c0:	4502000c */ 	bc1fl	.JF0f0ee2f4
/*  f0ee2c4:	9219003d */ 	lbu	$t9,0x3d($s0)
/*  f0ee2c8:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0ee2cc:	2403003c */ 	li	$v1,0x3c
/*  f0ee2d0:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ee2d4:	01830019 */ 	multu	$t4,$v1
/*  f0ee2d8:	24422ce0 */ 	addiu	$v0,$v0,0x2ce0
/*  f0ee2dc:	00006812 */ 	mflo	$t5
/*  f0ee2e0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ee2e4:	8dc80018 */ 	lw	$t0,0x18($t6)
/*  f0ee2e8:	10000012 */ 	b	.JF0f0ee334
/*  f0ee2ec:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0ee2f0:	9219003d */ 	lbu	$t9,0x3d($s0)
.JF0f0ee2f4:
/*  f0ee2f4:	2403003c */ 	li	$v1,0x3c
/*  f0ee2f8:	9209003c */ 	lbu	$t1,0x3c($s0)
/*  f0ee2fc:	03230019 */ 	multu	$t9,$v1
/*  f0ee300:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ee304:	24422ce0 */ 	addiu	$v0,$v0,0x2ce0
/*  f0ee308:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ee30c:	00007812 */ 	mflo	$t7
/*  f0ee310:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0ee314:	8f040018 */ 	lw	$a0,0x18($t8)
/*  f0ee318:	01230019 */ 	multu	$t1,$v1
/*  f0ee31c:	00005012 */ 	mflo	$t2
/*  f0ee320:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f0ee324:	0fc01a60 */ 	jal	colourBlend
/*  f0ee328:	8d650018 */ 	lw	$a1,0x18($t3)
/*  f0ee32c:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0ee330:	8e300010 */ 	lw	$s0,0x10($s1)
.JF0f0ee334:
/*  f0ee334:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0ee338:	5180000c */ 	beqzl	$t4,.JF0f0ee36c
/*  f0ee33c:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f0ee340:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0ee344:	00002825 */ 	move	$a1,$zero
/*  f0ee348:	0fc01a60 */ 	jal	colourBlend
/*  f0ee34c:	2406007f */ 	li	$a2,0x7f
/*  f0ee350:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0ee354:	2401ff00 */ 	li	$at,-256
/*  f0ee358:	00416824 */ 	and	$t5,$v0,$at
/*  f0ee35c:	31c800ff */ 	andi	$t0,$t6,0xff
/*  f0ee360:	01a8c825 */ 	or	$t9,$t5,$t0
/*  f0ee364:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0ee368:	8faa0084 */ 	lw	$t2,0x84($sp)
.JF0f0ee36c:
/*  f0ee36c:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ee370:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0ee374:	954b0000 */ 	lhu	$t3,0x0($t2)
/*  f0ee378:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f0ee37c:	01f84821 */ 	addu	$t1,$t7,$t8
/*  f0ee380:	012b6023 */ 	subu	$t4,$t1,$t3
/*  f0ee384:	afac007c */ 	sw	$t4,0x7c($sp)
/*  f0ee388:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0ee38c:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0ee390:	25cd0002 */ 	addiu	$t5,$t6,0x2
/*  f0ee394:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0ee398:	01198021 */ 	addu	$s0,$t0,$t9
/*  f0ee39c:	92020000 */ 	lbu	$v0,0x0($s0)
.JF0f0ee3a0:
/*  f0ee3a0:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ee3a4:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ee3a8:	14400003 */ 	bnez	$v0,.JF0f0ee3b8
/*  f0ee3ac:	304300ff */ 	andi	$v1,$v0,0xff
/*  f0ee3b0:	10000029 */ 	b	.JF0f0ee458
/*  f0ee3b4:	00001025 */ 	move	$v0,$zero
.JF0f0ee3b8:
/*  f0ee3b8:	28610080 */ 	slti	$at,$v1,0x80
/*  f0ee3bc:	10200003 */ 	beqz	$at,.JF0f0ee3cc
/*  f0ee3c0:	a3a20064 */ 	sb	$v0,0x64($sp)
/*  f0ee3c4:	1000000f */ 	b	.JF0f0ee404
/*  f0ee3c8:	a3a00065 */ 	sb	$zero,0x65($sp)
.JF0f0ee3cc:
/*  f0ee3cc:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f0ee3d0:	3062007f */ 	andi	$v0,$v1,0x7f
/*  f0ee3d4:	2401003e */ 	li	$at,0x3e
/*  f0ee3d8:	14410005 */ 	bne	$v0,$at,.JF0f0ee3f0
/*  f0ee3dc:	a3af0065 */ 	sb	$t7,0x65($sp)
/*  f0ee3e0:	93a30064 */ 	lbu	$v1,0x64($sp)
/*  f0ee3e4:	2478ffff */ 	addiu	$t8,$v1,-1
/*  f0ee3e8:	3302007f */ 	andi	$v0,$t8,0x7f
/*  f0ee3ec:	a3b80064 */ 	sb	$t8,0x64($sp)
.JF0f0ee3f0:
/*  f0ee3f0:	24010004 */ 	li	$at,0x4
/*  f0ee3f4:	14410003 */ 	bne	$v0,$at,.JF0f0ee404
/*  f0ee3f8:	93a30064 */ 	lbu	$v1,0x64($sp)
/*  f0ee3fc:	246affff */ 	addiu	$t2,$v1,-1
/*  f0ee400:	a3aa0064 */ 	sb	$t2,0x64($sp)
.JF0f0ee404:
/*  f0ee404:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0ee408:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ee40c:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f0ee410:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ee414:	0fc55d49 */ 	jal	textMeasure
/*  f0ee418:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ee41c:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0ee420:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f0ee424:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0ee428:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f0ee42c:	01c3082a */ 	slt	$at,$t6,$v1
/*  f0ee430:	50200004 */ 	beqzl	$at,.JF0f0ee444
/*  f0ee434:	93ad0065 */ 	lbu	$t5,0x65($sp)
/*  f0ee438:	10000007 */ 	b	.JF0f0ee458
/*  f0ee43c:	00001025 */ 	move	$v0,$zero
/*  f0ee440:	93ad0065 */ 	lbu	$t5,0x65($sp)
.JF0f0ee444:
/*  f0ee444:	24020001 */ 	li	$v0,0x1
/*  f0ee448:	afa3007c */ 	sw	$v1,0x7c($sp)
/*  f0ee44c:	11a00002 */ 	beqz	$t5,.JF0f0ee458
/*  f0ee450:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ee454:	26100001 */ 	addiu	$s0,$s0,0x1
.JF0f0ee458:
/*  f0ee458:	24010001 */ 	li	$at,0x1
/*  f0ee45c:	5041ffd0 */ 	beql	$v0,$at,.JF0f0ee3a0
/*  f0ee460:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ee464:	3c028008 */ 	lui	$v0,0x8008
/*  f0ee468:	8c4200f4 */ 	lw	$v0,0xf4($v0)
/*  f0ee46c:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ee470:	3c038007 */ 	lui	$v1,0x8007
/*  f0ee474:	246316d0 */ 	addiu	$v1,$v1,0x16d0
/*  f0ee478:	01020019 */ 	multu	$t0,$v0
/*  f0ee47c:	3c048007 */ 	lui	$a0,0x8007
/*  f0ee480:	248416d4 */ 	addiu	$a0,$a0,0x16d4
/*  f0ee484:	3c068007 */ 	lui	$a2,0x8007
/*  f0ee488:	24c616d8 */ 	addiu	$a2,$a2,0x16d8
/*  f0ee48c:	3c058007 */ 	lui	$a1,0x8007
/*  f0ee490:	24a516dc */ 	addiu	$a1,$a1,0x16dc
/*  f0ee494:	0000c812 */ 	mflo	$t9
/*  f0ee498:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0ee49c:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0ee4a0:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ee4a4:	01f85021 */ 	addu	$t2,$t7,$t8
/*  f0ee4a8:	01420019 */ 	multu	$t2,$v0
/*  f0ee4ac:	00004812 */ 	mflo	$t1
/*  f0ee4b0:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f0ee4b4:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0ee4b8:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f0ee4bc:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0ee4c0:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0ee4c4:	018e6821 */ 	addu	$t5,$t4,$t6
/*  f0ee4c8:	25a8ffff */ 	addiu	$t0,$t5,-1
/*  f0ee4cc:	07210002 */ 	bgez	$t9,.JF0f0ee4d8
/*  f0ee4d0:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f0ee4d4:	ac600000 */ 	sw	$zero,0x0($v1)
.JF0f0ee4d8:
/*  f0ee4d8:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0ee4dc:	05e30003 */ 	bgezl	$t7,.JF0f0ee4ec
/*  f0ee4e0:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0ee4e4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0ee4e8:	8cd80000 */ 	lw	$t8,0x0($a2)
.JF0f0ee4ec:
/*  f0ee4ec:	07030003 */ 	bgezl	$t8,.JF0f0ee4fc
/*  f0ee4f0:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f0ee4f4:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0ee4f8:	8caa0000 */ 	lw	$t2,0x0($a1)
.JF0f0ee4fc:
/*  f0ee4fc:	05410002 */ 	bgez	$t2,.JF0f0ee508
/*  f0ee500:	00000000 */ 	nop
/*  f0ee504:	aca00000 */ 	sw	$zero,0x0($a1)
.JF0f0ee508:
/*  f0ee508:	0c002eda */ 	jal	viGetBufWidth
/*  f0ee50c:	00000000 */ 	nop
/*  f0ee510:	3c098007 */ 	lui	$t1,0x8007
/*  f0ee514:	8d2916d0 */ 	lw	$t1,0x16d0($t1)
/*  f0ee518:	0049082a */ 	slt	$at,$v0,$t1
/*  f0ee51c:	10200005 */ 	beqz	$at,.JF0f0ee534
/*  f0ee520:	00000000 */ 	nop
/*  f0ee524:	0c002eda */ 	jal	viGetBufWidth
/*  f0ee528:	00000000 */ 	nop
/*  f0ee52c:	3c018007 */ 	lui	$at,0x8007
/*  f0ee530:	ac2216d0 */ 	sw	$v0,0x16d0($at)
.JF0f0ee534:
/*  f0ee534:	0c002eda */ 	jal	viGetBufWidth
/*  f0ee538:	00000000 */ 	nop
/*  f0ee53c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0ee540:	8d6b16d4 */ 	lw	$t3,0x16d4($t3)
/*  f0ee544:	004b082a */ 	slt	$at,$v0,$t3
/*  f0ee548:	10200005 */ 	beqz	$at,.JF0f0ee560
/*  f0ee54c:	00000000 */ 	nop
/*  f0ee550:	0c002eda */ 	jal	viGetBufWidth
/*  f0ee554:	00000000 */ 	nop
/*  f0ee558:	3c018007 */ 	lui	$at,0x8007
/*  f0ee55c:	ac2216d4 */ 	sw	$v0,0x16d4($at)
.JF0f0ee560:
/*  f0ee560:	0c002ede */ 	jal	viGetBufHeight
/*  f0ee564:	00000000 */ 	nop
/*  f0ee568:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0ee56c:	8d8c16d8 */ 	lw	$t4,0x16d8($t4)
/*  f0ee570:	004c082a */ 	slt	$at,$v0,$t4
/*  f0ee574:	10200005 */ 	beqz	$at,.JF0f0ee58c
/*  f0ee578:	00000000 */ 	nop
/*  f0ee57c:	0c002ede */ 	jal	viGetBufHeight
/*  f0ee580:	00000000 */ 	nop
/*  f0ee584:	3c018007 */ 	lui	$at,0x8007
/*  f0ee588:	ac2216d8 */ 	sw	$v0,0x16d8($at)
.JF0f0ee58c:
/*  f0ee58c:	0c002ede */ 	jal	viGetBufHeight
/*  f0ee590:	00000000 */ 	nop
/*  f0ee594:	3c068007 */ 	lui	$a2,0x8007
/*  f0ee598:	24c616dc */ 	addiu	$a2,$a2,0x16dc
/*  f0ee59c:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f0ee5a0:	0045082a */ 	slt	$at,$v0,$a1
/*  f0ee5a4:	10200009 */ 	beqz	$at,.JF0f0ee5cc
/*  f0ee5a8:	00000000 */ 	nop
/*  f0ee5ac:	0c002ede */ 	jal	viGetBufHeight
/*  f0ee5b0:	00000000 */ 	nop
/*  f0ee5b4:	3c018007 */ 	lui	$at,0x8007
/*  f0ee5b8:	ac2216dc */ 	sw	$v0,0x16dc($at)
/*  f0ee5bc:	3c058007 */ 	lui	$a1,0x8007
/*  f0ee5c0:	3c068007 */ 	lui	$a2,0x8007
/*  f0ee5c4:	24c616dc */ 	addiu	$a2,$a2,0x16dc
/*  f0ee5c8:	8ca516dc */ 	lw	$a1,0x16dc($a1)
.JF0f0ee5cc:
/*  f0ee5cc:	3c078007 */ 	lui	$a3,0x8007
/*  f0ee5d0:	3c038007 */ 	lui	$v1,0x8007
/*  f0ee5d4:	8c6316d0 */ 	lw	$v1,0x16d0($v1)
/*  f0ee5d8:	24e716d4 */ 	addiu	$a3,$a3,0x16d4
/*  f0ee5dc:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0ee5e0:	44834000 */ 	mtc1	$v1,$f8
/*  f0ee5e4:	3c048007 */ 	lui	$a0,0x8007
/*  f0ee5e8:	01c3082a */ 	slt	$at,$t6,$v1
/*  f0ee5ec:	10200002 */ 	beqz	$at,.JF0f0ee5f8
/*  f0ee5f0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ee5f4:	ace30000 */ 	sw	$v1,0x0($a3)
.JF0f0ee5f8:
/*  f0ee5f8:	8c8416d8 */ 	lw	$a0,0x16d8($a0)
/*  f0ee5fc:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0ee600:	50200003 */ 	beqzl	$at,.JF0f0ee610
/*  f0ee604:	44842000 */ 	mtc1	$a0,$f4
/*  f0ee608:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0ee60c:	44842000 */ 	mtc1	$a0,$f4
.JF0f0ee610:
/*  f0ee610:	3c014080 */ 	lui	$at,0x4080
/*  f0ee614:	44810000 */ 	mtc1	$at,$f0
/*  f0ee618:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ee61c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ee620:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ee624:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ee628:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0ee62c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ee630:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ee634:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ee638:	44089000 */ 	mfc1	$t0,$f18
/*  f0ee63c:	44095000 */ 	mfc1	$t1,$f10
/*  f0ee640:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0ee644:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f0ee648:	01e1c025 */ 	or	$t8,$t7,$at
/*  f0ee64c:	312b0fff */ 	andi	$t3,$t1,0xfff
/*  f0ee650:	030b6025 */ 	or	$t4,$t8,$t3
/*  f0ee654:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0ee658:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0ee65c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0ee660:	448e8000 */ 	mtc1	$t6,$f16
/*  f0ee664:	448a4000 */ 	mtc1	$t2,$f8
/*  f0ee668:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ee66c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ee670:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ee674:	00000000 */ 	nop
/*  f0ee678:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ee67c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ee680:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ee684:	44083000 */ 	mfc1	$t0,$f6
/*  f0ee688:	44189000 */ 	mfc1	$t8,$f18
/*  f0ee68c:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0ee690:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f0ee694:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f0ee698:	01eb6025 */ 	or	$t4,$t7,$t3
/*  f0ee69c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0ee6a0:	0fc54d24 */ 	jal	textBackupAndResetBlends
/*  f0ee6a4:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f0ee6a8:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0ee6ac:	8dcd0004 */ 	lw	$t5,0x4($t6)
/*  f0ee6b0:	31a80800 */ 	andi	$t0,$t5,0x800
/*  f0ee6b4:	51000009 */ 	beqzl	$t0,.JF0f0ee6dc
/*  f0ee6b8:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ee6bc:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ee6c0:	86390004 */ 	lh	$t9,0x4($s1)
/*  f0ee6c4:	2406001c */ 	li	$a2,0x1c
/*  f0ee6c8:	0fc54d15 */ 	jal	textSetHorizontalBlend
/*  f0ee6cc:	00992821 */ 	addu	$a1,$a0,$t9
/*  f0ee6d0:	10000005 */ 	b	.JF0f0ee6e8
/*  f0ee6d4:	00000000 */ 	nop
/*  f0ee6d8:	86240000 */ 	lh	$a0,0x0($s1)
.JF0f0ee6dc:
/*  f0ee6dc:	2406000e */ 	li	$a2,0xe
/*  f0ee6e0:	0fc54d15 */ 	jal	textSetHorizontalBlend
/*  f0ee6e4:	00802825 */ 	move	$a1,$a0
.JF0f0ee6e8:
/*  f0ee6e8:	0fc54b55 */ 	jal	text0f153628
/*  f0ee6ec:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0ee6f0:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ee6f4:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0ee6f8:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ee6fc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ee700:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ee704:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0ee708:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0ee70c:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f0ee710:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0ee714:	00402025 */ 	move	$a0,$v0
/*  f0ee718:	01eb6021 */ 	addu	$t4,$t7,$t3
/*  f0ee71c:	018e6823 */ 	subu	$t5,$t4,$t6
/*  f0ee720:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0ee724:	86280006 */ 	lh	$t0,0x6($s1)
/*  f0ee728:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee72c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee730:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0ee734:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0ee738:	02003825 */ 	move	$a3,$s0
/*  f0ee73c:	0fc55886 */ 	jal	textRenderProjected
/*  f0ee740:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0ee744:	0fc54bb7 */ 	jal	text0f153780
/*  f0ee748:	00402025 */ 	move	$a0,$v0
/*  f0ee74c:	0fc3d768 */ 	jal	menuApplyScissor
/*  f0ee750:	00402025 */ 	move	$a0,$v0
/*  f0ee754:	0fc54d2a */ 	jal	textRestoreBlends
/*  f0ee758:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0ee75c:	86390004 */ 	lh	$t9,0x4($s1)
/*  f0ee760:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f0ee764:	a5590004 */ 	sh	$t9,0x4($t2)
/*  f0ee768:	8fa20088 */ 	lw	$v0,0x88($sp)
.JF0f0ee76c:
/*  f0ee76c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ee770:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0ee774:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0ee778:	03e00008 */ 	jr	$ra
/*  f0ee77c:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuitemMarqueeRender
/*  f0ed528:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f0ed52c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ed530:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ed534:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ed538:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f0ed53c:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ed540:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ed544:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0ed548:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0ed54c:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ed550:	3c0f8007 */ 	lui	$t7,%hi(var800711ec)
/*  f0ed554:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm)
/*  f0ed558:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicSm)
/*  f0ed55c:	95ef11ec */ 	lhu	$t7,%lo(var800711ec)($t7)
/*  f0ed560:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm)($t8)
/*  f0ed564:	8f39fb10 */ 	lw	$t9,%lo(g_CharsHandelGothicSm)($t9)
/*  f0ed568:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0ed56c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0ed570:	a7af0064 */ 	sh	$t7,0x64($sp)
/*  f0ed574:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0ed578:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0ed57c:	8e280008 */ 	lw	$t0,0x8($s1)
/*  f0ed580:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0ed584:	3c0c8008 */ 	lui	$t4,%hi(g_CharsHandelGothicXs)
/*  f0ed588:	8d090004 */ 	lw	$t1,0x4($t0)
/*  f0ed58c:	312a0200 */ 	andi	$t2,$t1,0x200
/*  f0ed590:	11400005 */ 	beqz	$t2,.L0f0ed5a8
/*  f0ed594:	00000000 */ 	nop
/*  f0ed598:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0ed59c:	8d8cfb08 */ 	lw	$t4,%lo(g_CharsHandelGothicXs)($t4)
/*  f0ed5a0:	afab005c */ 	sw	$t3,0x5c($sp)
/*  f0ed5a4:	afac0058 */ 	sw	$t4,0x58($sp)
.L0f0ed5a8:
/*  f0ed5a8:	54400004 */ 	bnezl	$v0,.L0f0ed5bc
/*  f0ed5ac:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ed5b0:	1000011b */ 	b	.L0f0eda20
/*  f0ed5b4:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ed5b8:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ed5bc:
/*  f0ed5bc:	44803000 */ 	mtc1	$zero,$f6
/*  f0ed5c0:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ed5c4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ed5c8:	00000000 */ 	nop
/*  f0ed5cc:	4502000c */ 	bc1fl	.L0f0ed600
/*  f0ed5d0:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0ed5d4:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0ed5d8:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ed5dc:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ed5e0:	01a70019 */ 	multu	$t5,$a3
/*  f0ed5e4:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ed5e8:	00007012 */ 	mflo	$t6
/*  f0ed5ec:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0ed5f0:	8df80018 */ 	lw	$t8,0x18($t7)
/*  f0ed5f4:	10000012 */ 	b	.L0f0ed640
/*  f0ed5f8:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0ed5fc:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0ed600:
/*  f0ed600:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ed604:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0ed608:	03270019 */ 	multu	$t9,$a3
/*  f0ed60c:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ed610:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ed614:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ed618:	00004012 */ 	mflo	$t0
/*  f0ed61c:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ed620:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0ed624:	01470019 */ 	multu	$t2,$a3
/*  f0ed628:	00005812 */ 	mflo	$t3
/*  f0ed62c:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f0ed630:	0fc01a40 */ 	jal	colourBlend
/*  f0ed634:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ed638:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0ed63c:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ed640:
/*  f0ed640:	8c6d000c */ 	lw	$t5,0xc($v1)
/*  f0ed644:	51a0000c */ 	beqzl	$t5,.L0f0ed678
/*  f0ed648:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0ed64c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0ed650:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ed654:	0fc01a40 */ 	jal	colourBlend
/*  f0ed658:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ed65c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ed660:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ed664:	00417024 */ 	and	$t6,$v0,$at
/*  f0ed668:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0ed66c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0ed670:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0ed674:	8fab0084 */ 	lw	$t3,0x84($sp)
.L0f0ed678:
/*  f0ed678:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ed67c:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0ed680:	956c0000 */ 	lhu	$t4,0x0($t3)
/*  f0ed684:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0ed688:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0ed68c:	014c6823 */ 	subu	$t5,$t2,$t4
/*  f0ed690:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f0ed694:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0ed698:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0ed69c:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0ed6a0:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0ed6a4:	03198021 */ 	addu	$s0,$t8,$t9
/*  f0ed6a8:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0ed6ac:
/*  f0ed6ac:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ed6b0:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ed6b4:	14400003 */ 	bnez	$v0,.L0f0ed6c4
/*  f0ed6b8:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ed6bc:	10000013 */ 	b	.L0f0ed70c
/*  f0ed6c0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ed6c4:
/*  f0ed6c4:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0ed6c8:	a3a20064 */ 	sb	$v0,0x64($sp)
/*  f0ed6cc:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f0ed6d0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ed6d4:	0fc55cbe */ 	jal	textMeasure
/*  f0ed6d8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ed6dc:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f0ed6e0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f0ed6e4:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0ed6e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ed6ec:	012b1821 */ 	addu	$v1,$t1,$t3
/*  f0ed6f0:	0143082a */ 	slt	$at,$t2,$v1
/*  f0ed6f4:	50200004 */ 	beqzl	$at,.L0f0ed708
/*  f0ed6f8:	afa3007c */ 	sw	$v1,0x7c($sp)
/*  f0ed6fc:	10000003 */ 	b	.L0f0ed70c
/*  f0ed700:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ed704:	afa3007c */ 	sw	$v1,0x7c($sp)
.L0f0ed708:
/*  f0ed708:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ed70c:
/*  f0ed70c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ed710:	5041ffe6 */ 	beql	$v0,$at,.L0f0ed6ac
/*  f0ed714:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ed718:	3c028008 */ 	lui	$v0,%hi(g_ScaleX)
/*  f0ed71c:	8c42fac0 */ 	lw	$v0,%lo(g_ScaleX)($v0)
/*  f0ed720:	862c0000 */ 	lh	$t4,0x0($s1)
/*  f0ed724:	3c038007 */ 	lui	$v1,%hi(g_ScissorX1)
/*  f0ed728:	24631190 */ 	addiu	$v1,$v1,%lo(g_ScissorX1)
/*  f0ed72c:	01820019 */ 	multu	$t4,$v0
/*  f0ed730:	3c048007 */ 	lui	$a0,%hi(g_ScissorX2)
/*  f0ed734:	24841194 */ 	addiu	$a0,$a0,%lo(g_ScissorX2)
/*  f0ed738:	3c068007 */ 	lui	$a2,%hi(g_ScissorY1)
/*  f0ed73c:	24c61198 */ 	addiu	$a2,$a2,%lo(g_ScissorY1)
/*  f0ed740:	3c058007 */ 	lui	$a1,%hi(g_ScissorY2)
/*  f0ed744:	24a5119c */ 	addiu	$a1,$a1,%lo(g_ScissorY2)
/*  f0ed748:	00006812 */ 	mflo	$t5
/*  f0ed74c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0ed750:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ed754:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ed758:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0ed75c:	03020019 */ 	multu	$t8,$v0
/*  f0ed760:	0000c812 */ 	mflo	$t9
/*  f0ed764:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0ed768:	86280002 */ 	lh	$t0,0x2($s1)
/*  f0ed76c:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f0ed770:	862b0006 */ 	lh	$t3,0x6($s1)
/*  f0ed774:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ed778:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0ed77c:	254cffff */ 	addiu	$t4,$t2,-1
/*  f0ed780:	05a10002 */ 	bgez	$t5,.L0f0ed78c
/*  f0ed784:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f0ed788:	ac600000 */ 	sw	$zero,0x0($v1)
.L0f0ed78c:
/*  f0ed78c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0ed790:	05e30003 */ 	bgezl	$t7,.L0f0ed7a0
/*  f0ed794:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0ed798:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0ed79c:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f0ed7a0:
/*  f0ed7a0:	05c30003 */ 	bgezl	$t6,.L0f0ed7b0
/*  f0ed7a4:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0ed7a8:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0ed7ac:	8cb80000 */ 	lw	$t8,0x0($a1)
.L0f0ed7b0:
/*  f0ed7b0:	07010002 */ 	bgez	$t8,.L0f0ed7bc
/*  f0ed7b4:	00000000 */ 	nop
/*  f0ed7b8:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0ed7bc:
/*  f0ed7bc:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed7c0:	00000000 */ 	nop
/*  f0ed7c4:	3c198007 */ 	lui	$t9,%hi(g_ScissorX1)
/*  f0ed7c8:	8f391190 */ 	lw	$t9,%lo(g_ScissorX1)($t9)
/*  f0ed7cc:	0059082a */ 	slt	$at,$v0,$t9
/*  f0ed7d0:	10200005 */ 	beqz	$at,.L0f0ed7e8
/*  f0ed7d4:	00000000 */ 	nop
/*  f0ed7d8:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed7dc:	00000000 */ 	nop
/*  f0ed7e0:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0ed7e4:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0ed7e8:
/*  f0ed7e8:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed7ec:	00000000 */ 	nop
/*  f0ed7f0:	3c088007 */ 	lui	$t0,%hi(g_ScissorX2)
/*  f0ed7f4:	8d081194 */ 	lw	$t0,%lo(g_ScissorX2)($t0)
/*  f0ed7f8:	0048082a */ 	slt	$at,$v0,$t0
/*  f0ed7fc:	10200005 */ 	beqz	$at,.L0f0ed814
/*  f0ed800:	00000000 */ 	nop
/*  f0ed804:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed808:	00000000 */ 	nop
/*  f0ed80c:	3c018007 */ 	lui	$at,%hi(g_ScissorX2)
/*  f0ed810:	ac221194 */ 	sw	$v0,%lo(g_ScissorX2)($at)
.L0f0ed814:
/*  f0ed814:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed818:	00000000 */ 	nop
/*  f0ed81c:	3c098007 */ 	lui	$t1,%hi(g_ScissorY1)
/*  f0ed820:	8d291198 */ 	lw	$t1,%lo(g_ScissorY1)($t1)
/*  f0ed824:	0049082a */ 	slt	$at,$v0,$t1
/*  f0ed828:	10200005 */ 	beqz	$at,.L0f0ed840
/*  f0ed82c:	00000000 */ 	nop
/*  f0ed830:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed834:	00000000 */ 	nop
/*  f0ed838:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0ed83c:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0ed840:
/*  f0ed840:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed844:	00000000 */ 	nop
/*  f0ed848:	3c068007 */ 	lui	$a2,%hi(g_ScissorY2)
/*  f0ed84c:	24c6119c */ 	addiu	$a2,$a2,%lo(g_ScissorY2)
/*  f0ed850:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f0ed854:	0045082a */ 	slt	$at,$v0,$a1
/*  f0ed858:	10200009 */ 	beqz	$at,.L0f0ed880
/*  f0ed85c:	00000000 */ 	nop
/*  f0ed860:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed864:	00000000 */ 	nop
/*  f0ed868:	3c018007 */ 	lui	$at,%hi(g_ScissorY2)
/*  f0ed86c:	ac22119c */ 	sw	$v0,%lo(g_ScissorY2)($at)
/*  f0ed870:	3c058007 */ 	lui	$a1,%hi(g_ScissorY2)
/*  f0ed874:	3c068007 */ 	lui	$a2,%hi(g_ScissorY2)
/*  f0ed878:	24c6119c */ 	addiu	$a2,$a2,%lo(g_ScissorY2)
/*  f0ed87c:	8ca5119c */ 	lw	$a1,%lo(g_ScissorY2)($a1)
.L0f0ed880:
/*  f0ed880:	3c078007 */ 	lui	$a3,%hi(g_ScissorX2)
/*  f0ed884:	3c038007 */ 	lui	$v1,%hi(g_ScissorX1)
/*  f0ed888:	8c631190 */ 	lw	$v1,%lo(g_ScissorX1)($v1)
/*  f0ed88c:	24e71194 */ 	addiu	$a3,$a3,%lo(g_ScissorX2)
/*  f0ed890:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0ed894:	44834000 */ 	mtc1	$v1,$f8
/*  f0ed898:	3c048007 */ 	lui	$a0,%hi(g_ScissorY1)
/*  f0ed89c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0ed8a0:	10200002 */ 	beqz	$at,.L0f0ed8ac
/*  f0ed8a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ed8a8:	ace30000 */ 	sw	$v1,0x0($a3)
.L0f0ed8ac:
/*  f0ed8ac:	8c841198 */ 	lw	$a0,%lo(g_ScissorY1)($a0)
/*  f0ed8b0:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0ed8b4:	50200003 */ 	beqzl	$at,.L0f0ed8c4
/*  f0ed8b8:	44842000 */ 	mtc1	$a0,$f4
/*  f0ed8bc:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0ed8c0:	44842000 */ 	mtc1	$a0,$f4
.L0f0ed8c4:
/*  f0ed8c4:	3c014080 */ 	lui	$at,0x4080
/*  f0ed8c8:	44810000 */ 	mtc1	$at,$f0
/*  f0ed8cc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ed8d0:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ed8d4:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ed8d8:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ed8dc:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0ed8e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ed8e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ed8e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ed8ec:	440c9000 */ 	mfc1	$t4,$f18
/*  f0ed8f0:	44195000 */ 	mfc1	$t9,$f10
/*  f0ed8f4:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0ed8f8:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0ed8fc:	01e17025 */ 	or	$t6,$t7,$at
/*  f0ed900:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f0ed904:	01c84825 */ 	or	$t1,$t6,$t0
/*  f0ed908:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0ed90c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0ed910:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0ed914:	448b8000 */ 	mtc1	$t3,$f16
/*  f0ed918:	44984000 */ 	mtc1	$t8,$f8
/*  f0ed91c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ed920:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ed924:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ed928:	00000000 */ 	nop
/*  f0ed92c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ed930:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ed934:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ed938:	440c3000 */ 	mfc1	$t4,$f6
/*  f0ed93c:	440e9000 */ 	mfc1	$t6,$f18
/*  f0ed940:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0ed944:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0ed948:	31c80fff */ 	andi	$t0,$t6,0xfff
/*  f0ed94c:	01e84825 */ 	or	$t1,$t7,$t0
/*  f0ed950:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0ed954:	0fc54f49 */ 	jal	textBackupAndResetBlends
/*  f0ed958:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f0ed95c:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0ed960:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*  f0ed964:	314c0800 */ 	andi	$t4,$t2,0x800
/*  f0ed968:	51800009 */ 	beqzl	$t4,.L0f0ed990
/*  f0ed96c:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ed970:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ed974:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ed978:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ed97c:	0fc54f3a */ 	jal	textSetHorizontalBlend
/*  f0ed980:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f0ed984:	10000005 */ 	b	.L0f0ed99c
/*  f0ed988:	00000000 */ 	nop
/*  f0ed98c:	86240000 */ 	lh	$a0,0x0($s1)
.L0f0ed990:
/*  f0ed990:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ed994:	0fc54f3a */ 	jal	textSetHorizontalBlend
/*  f0ed998:	00802825 */ 	or	$a1,$a0,$zero
.L0f0ed99c:
/*  f0ed99c:	0fc54d8a */ 	jal	text0f153628
/*  f0ed9a0:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0ed9a4:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0ed9a8:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0ed9ac:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0ed9b0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ed9b4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ed9b8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ed9bc:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ed9c0:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f0ed9c4:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0ed9c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ed9cc:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f0ed9d0:	012b5023 */ 	subu	$t2,$t1,$t3
/*  f0ed9d4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0ed9d8:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0ed9dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ed9e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ed9e4:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0ed9e8:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0ed9ec:	02003825 */ 	or	$a3,$s0,$zero
/*  f0ed9f0:	0fc5580f */ 	jal	textRenderProjected
/*  f0ed9f4:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ed9f8:	0fc54de0 */ 	jal	text0f153780
/*  f0ed9fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eda00:	0fc3d43f */ 	jal	menuApplyScissor
/*  f0eda04:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eda08:	0fc54f4f */ 	jal	textRestoreBlends
/*  f0eda0c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0eda10:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0eda14:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f0eda18:	a70d0004 */ 	sh	$t5,0x4($t8)
/*  f0eda1c:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f0eda20:
/*  f0eda20:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eda24:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eda28:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eda2c:	03e00008 */ 	jr	$ra
/*  f0eda30:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#else
GLOBAL_ASM(
glabel menuitemMarqueeRender
/*  f0ea690:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0ea694:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0ea698:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f0ea69c:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f0ea6a0:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0ea6a4:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0ea6a8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0ea6ac:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0ea6b0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ea6b4:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ea6b8:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0ea6bc:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ea6c0:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ea6c4:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f0ea6c8:	0fc3b85b */ 	jal	menuResolveParam2Text
/*  f0ea6cc:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ea6d0:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0ea6d4:	25ef389c */ 	addiu	$t7,$t7,0x389c
/*  f0ea6d8:	95e10000 */ 	lhu	$at,0x0($t7)
/*  f0ea6dc:	27b50074 */ 	addiu	$s5,$sp,0x74
/*  f0ea6e0:	3c168008 */ 	lui	$s6,0x8008
/*  f0ea6e4:	a6a10000 */ 	sh	$at,0x0($s5)
/*  f0ea6e8:	8e290008 */ 	lw	$t1,0x8($s1)
/*  f0ea6ec:	3c178008 */ 	lui	$s7,0x8008
/*  f0ea6f0:	00409025 */ 	or	$s2,$v0,$zero
/*  f0ea6f4:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f0ea6f8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0ea6fc:	8ed6236c */ 	lw	$s6,0x236c($s6)
/*  f0ea700:	314b0200 */ 	andi	$t3,$t2,0x200
/*  f0ea704:	11600005 */ 	beqz	$t3,.NB0f0ea71c
/*  f0ea708:	8ef72370 */ 	lw	$s7,0x2370($s7)
/*  f0ea70c:	3c168008 */ 	lui	$s6,0x8008
/*  f0ea710:	3c178008 */ 	lui	$s7,0x8008
/*  f0ea714:	8ed62364 */ 	lw	$s6,0x2364($s6)
/*  f0ea718:	8ef72368 */ 	lw	$s7,0x2368($s7)
.NB0f0ea71c:
/*  f0ea71c:	54400004 */ 	bnezl	$v0,.NB0f0ea730
/*  f0ea720:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0ea724:	100000c3 */ 	beqz	$zero,.NB0f0eaa34
/*  f0ea728:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0ea72c:	8e300010 */ 	lw	$s0,0x10($s1)
.NB0f0ea730:
/*  f0ea730:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea734:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0ea738:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea73c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea740:	4502000c */ 	bc1fl	.NB0f0ea774
/*  f0ea744:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f0ea748:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0ea74c:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0ea750:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ea754:	01830019 */ 	multu	$t4,$v1
/*  f0ea758:	2442c2e0 */ 	addiu	$v0,$v0,-15648
/*  f0ea75c:	00006812 */ 	mflo	$t5
/*  f0ea760:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ea764:	8dd90018 */ 	lw	$t9,0x18($t6)
/*  f0ea768:	10000012 */ 	beqz	$zero,.NB0f0ea7b4
/*  f0ea76c:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f0ea770:	9218003d */ 	lbu	$t8,0x3d($s0)
.NB0f0ea774:
/*  f0ea774:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0ea778:	9209003c */ 	lbu	$t1,0x3c($s0)
/*  f0ea77c:	03030019 */ 	multu	$t8,$v1
/*  f0ea780:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ea784:	2442c2e0 */ 	addiu	$v0,$v0,-15648
/*  f0ea788:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ea78c:	00007812 */ 	mflo	$t7
/*  f0ea790:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f0ea794:	8d040018 */ 	lw	$a0,0x18($t0)
/*  f0ea798:	01230019 */ 	multu	$t1,$v1
/*  f0ea79c:	00005012 */ 	mflo	$t2
/*  f0ea7a0:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f0ea7a4:	0fc01990 */ 	jal	colourBlend
/*  f0ea7a8:	8d650018 */ 	lw	$a1,0x18($t3)
/*  f0ea7ac:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f0ea7b0:	8e300010 */ 	lw	$s0,0x10($s1)
.NB0f0ea7b4:
/*  f0ea7b4:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0ea7b8:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f0ea7bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ea7c0:	5180000a */ 	beqzl	$t4,.NB0f0ea7ec
/*  f0ea7c4:	8faa0094 */ 	lw	$t2,0x94($sp)
/*  f0ea7c8:	0fc01990 */ 	jal	colourBlend
/*  f0ea7cc:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ea7d0:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0ea7d4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea7d8:	00416824 */ 	and	$t5,$v0,$at
/*  f0ea7dc:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f0ea7e0:	01b9c025 */ 	or	$t8,$t5,$t9
/*  f0ea7e4:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f0ea7e8:	8faa0094 */ 	lw	$t2,0x94($sp)
.NB0f0ea7ec:
/*  f0ea7ec:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ea7f0:	86280004 */ 	lh	$t0,0x4($s1)
/*  f0ea7f4:	954b0000 */ 	lhu	$t3,0x0($t2)
/*  f0ea7f8:	02538021 */ 	addu	$s0,$s2,$s3
/*  f0ea7fc:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f0ea800:	012b6023 */ 	subu	$t4,$t1,$t3
/*  f0ea804:	afac008c */ 	sw	$t4,0x8c($sp)
/*  f0ea808:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0ea80c:	27b30078 */ 	addiu	$s3,$sp,0x78
/*  f0ea810:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0ea814:	25cd0002 */ 	addiu	$t5,$t6,0x2
/*  f0ea818:	afad0088 */ 	sw	$t5,0x88($sp)
/*  f0ea81c:	27b4007c */ 	addiu	$s4,$sp,0x7c
/*  f0ea820:	92020000 */ 	lbu	$v0,0x0($s0)
.NB0f0ea824:
/*  f0ea824:	02602025 */ 	or	$a0,$s3,$zero
/*  f0ea828:	02802825 */ 	or	$a1,$s4,$zero
/*  f0ea82c:	14400003 */ 	bnez	$v0,.NB0f0ea83c
/*  f0ea830:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0ea834:	10000012 */ 	beqz	$zero,.NB0f0ea880
/*  f0ea838:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0ea83c:
/*  f0ea83c:	a3a20074 */ 	sb	$v0,0x74($sp)
/*  f0ea840:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0ea844:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0ea848:	0fc54655 */ 	jal	textMeasure
/*  f0ea84c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea850:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0ea854:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0ea858:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ea85c:	02401025 */ 	or	$v0,$s2,$zero
/*  f0ea860:	03381821 */ 	addu	$v1,$t9,$t8
/*  f0ea864:	01e3082a */ 	slt	$at,$t7,$v1
/*  f0ea868:	50200004 */ 	beqzl	$at,.NB0f0ea87c
/*  f0ea86c:	afa3008c */ 	sw	$v1,0x8c($sp)
/*  f0ea870:	10000003 */ 	beqz	$zero,.NB0f0ea880
/*  f0ea874:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ea878:	afa3008c */ 	sw	$v1,0x8c($sp)
.NB0f0ea87c:
/*  f0ea87c:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f0ea880:
/*  f0ea880:	5052ffe8 */ 	beql	$v0,$s2,.NB0f0ea824
/*  f0ea884:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ea888:	3c038008 */ 	lui	$v1,0x8008
/*  f0ea88c:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0ea890:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0ea894:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ea898:	86380002 */ 	lh	$t8,0x2($s1)
/*  f0ea89c:	3c014080 */ 	lui	$at,0x4080
/*  f0ea8a0:	010a0019 */ 	multu	$t0,$t2
/*  f0ea8a4:	44982000 */ 	mtc1	$t8,$f4
/*  f0ea8a8:	44810000 */ 	mtc1	$at,$f0
/*  f0ea8ac:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0ea8b0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ea8b4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ea8b8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0ea8bc:	00004812 */ 	mflo	$t1
/*  f0ea8c0:	44894000 */ 	mtc1	$t1,$f8
/*  f0ea8c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea8c8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ea8cc:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ea8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea8d4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ea8d8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ea8dc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ea8e0:	440c9000 */ 	mfc1	$t4,$f18
/*  f0ea8e4:	44085000 */ 	mfc1	$t0,$f10
/*  f0ea8e8:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f0ea8ec:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f0ea8f0:	01a1c825 */ 	or	$t9,$t5,$at
/*  f0ea8f4:	310a0fff */ 	andi	$t2,$t0,0xfff
/*  f0ea8f8:	032a4825 */ 	or	$t1,$t9,$t2
/*  f0ea8fc:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0ea900:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ea904:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0ea908:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0ea90c:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ea910:	016c7021 */ 	addu	$t6,$t3,$t4
/*  f0ea914:	01cd0019 */ 	multu	$t6,$t5
/*  f0ea918:	862b0006 */ 	lh	$t3,0x6($s1)
/*  f0ea91c:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f0ea920:	258effff */ 	addiu	$t6,$t4,-1
/*  f0ea924:	448e4000 */ 	mtc1	$t6,$f8
/*  f0ea928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea92c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ea930:	0000c012 */ 	mflo	$t8
/*  f0ea934:	44988000 */ 	mtc1	$t8,$f16
/*  f0ea938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea93c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ea940:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ea944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea948:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ea94c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ea950:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ea954:	44083000 */ 	mfc1	$t0,$f6
/*  f0ea958:	44189000 */ 	mfc1	$t8,$f18
/*  f0ea95c:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0ea960:	00195300 */ 	sll	$t2,$t9,0xc
/*  f0ea964:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0ea968:	014f4025 */ 	or	$t0,$t2,$t7
/*  f0ea96c:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0ea970:	0fc538e0 */ 	jal	textBackupAndResetBlends
/*  f0ea974:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0ea978:	8e390008 */ 	lw	$t9,0x8($s1)
/*  f0ea97c:	8f290004 */ 	lw	$t1,0x4($t9)
/*  f0ea980:	312b0800 */ 	andi	$t3,$t1,0x800
/*  f0ea984:	51600009 */ 	beqzl	$t3,.NB0f0ea9ac
/*  f0ea988:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ea98c:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ea990:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ea994:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ea998:	0fc538d1 */ 	jal	textSetHorizontalBlend
/*  f0ea99c:	008c2821 */ 	addu	$a1,$a0,$t4
/*  f0ea9a0:	10000005 */ 	beqz	$zero,.NB0f0ea9b8
/*  f0ea9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea9a8:	86240000 */ 	lh	$a0,0x0($s1)
.NB0f0ea9ac:
/*  f0ea9ac:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ea9b0:	0fc538d1 */ 	jal	textSetHorizontalBlend
/*  f0ea9b4:	00802825 */ 	or	$a1,$a0,$zero
.NB0f0ea9b8:
/*  f0ea9b8:	0fc5374a */ 	jal	text0f153628
/*  f0ea9bc:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0ea9c0:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0ea9c4:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0ea9c8:	afb60014 */ 	sw	$s6,0x14($sp)
/*  f0ea9cc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea9d0:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0ea9d4:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ea9d8:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0ea9dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea9e0:	01b85021 */ 	addu	$t2,$t5,$t8
/*  f0ea9e4:	014f4023 */ 	subu	$t0,$t2,$t7
/*  f0ea9e8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ea9ec:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0ea9f0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea9f4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea9f8:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ea9fc:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0eaa00:	02003825 */ 	or	$a3,$s0,$zero
/*  f0eaa04:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eaa08:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0eaa0c:	0fc537a0 */ 	jal	text0f153780
/*  f0eaa10:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eaa14:	0fc3c728 */ 	jal	menuApplyScissor
/*  f0eaa18:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eaa1c:	0fc538e6 */ 	jal	textRestoreBlends
/*  f0eaa20:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0eaa24:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0eaa28:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f0eaa2c:	a5690004 */ 	sh	$t1,0x4($t3)
/*  f0eaa30:	8fa20098 */ 	lw	$v0,0x98($sp)
.NB0f0eaa34:
/*  f0eaa34:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0eaa38:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eaa3c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eaa40:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0eaa44:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0eaa48:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0eaa4c:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0eaa50:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f0eaa54:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f0eaa58:	03e00008 */ 	jr	$ra
/*  f0eaa5c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

u32 var800711ec = 0x20000000;

// Mismatch at 718
//Gfx *menuitemMarqueeRender(Gfx *gdl, struct menurendercontext *context)
//{
//	u16 *unk14 = context->unk14.u16; // 84
//	char *text = menuResolveParam2Text(context->item); // 80
//	s32 x; // 7c
//	s32 y; // 78
//	u32 colour; // 74
//	s32 i = 0; // 70
//	s32 textwidth; // 6c
//	s32 textheight; // 68
//	char string[] = {' ', '\0'}; // 64 - var800711ec
//	s32 hasmore;
//	struct font *font2 = g_FontHandelGothicSm; // 5c
//	struct fontchar *font1 = g_CharsHandelGothicSm; // 58
//
//	if (context->item->flags & MENUITEMFLAG_00000200) {
//		font2 = g_FontHandelGothicXs;
//		font1 = g_CharsHandelGothicXs;
//	}
//
//	if (!text) {
//		return gdl;
//	}
//
//	// 5b8
//	if (context->dialog->transitionfrac < 0) {
//		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
//	} else {
//		colour = colourBlend(
//				g_MenuColourPalettes[context->dialog->type2].unfocused,
//				g_MenuColourPalettes[context->dialog->type].unfocused,
//				context->dialog->colourweight);
//	}
//
//	// 644
//	if (context->dialog->dimmed) {
//		colour = colourBlend(colour, 0, 127) & 0xffffff00 | colour & 0xff;
//	}
//
//	// 674
//	x = context->x + context->width - *unk14;
//	y = context->y + 2;
//	hasmore = true;
//
//	while (hasmore == true) {
//		if (text[i] == '\0') {
//			hasmore = false;
//		} else {
//			string[0] = text[i];
//			textMeasure(&textheight, &textwidth, string, font1, font2, 0);
//
//			if (x + textwidth > context->x) {
//				hasmore = false;
//			} else {
//				x += textwidth;
//				hasmore = true;
//				i++;
//			}
//		}
//	}
//
//	// 718
//	// context->x is loaded into a0 but should be t4. Additionally, the loads of
//	// context->x and g_ScaleX are swapped.
//	g_ScissorX1 = context->x * g_ScaleX;
//	g_ScissorX2 = (context->x + context->width) * g_ScaleX;
//	g_ScissorY1 = context->y;
//	g_ScissorY2 = context->y + context->height - 1;
//
//	if (g_ScissorX1 < 0) {
//		g_ScissorX1 = 0;
//	}
//
//	if (g_ScissorX2 < 0) {
//		g_ScissorX2 = 0;
//	}
//
//	if (g_ScissorY1 < 0) {
//		g_ScissorY1 = 0;
//	}
//
//	if (g_ScissorY2 < 0) {
//		g_ScissorY2 = 0;
//	}
//
//	if (g_ScissorX1 > viGetBufWidth()) {
//		g_ScissorX1 = viGetBufWidth();
//	}
//
//	if (g_ScissorX2 > viGetBufWidth()) {
//		g_ScissorX2 = viGetBufWidth();
//	}
//
//	if (g_ScissorY1 > viGetBufHeight()) {
//		g_ScissorY1 = viGetBufHeight();
//	}
//
//	if (g_ScissorY2 > viGetBufHeight()) {
//		g_ScissorY2 = viGetBufHeight();
//	}
//
//	if (g_ScissorX2 < g_ScissorX1) {
//		g_ScissorX2 = g_ScissorX1;
//	}
//
//	if (g_ScissorY2 < g_ScissorY1) {
//		g_ScissorY2 = g_ScissorY1;
//	}
//
//	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
//
//	textBackupAndResetBlends();
//
//	if (context->item->flags & MENUITEMFLAG_00000800) {
//		textSetHorizontalBlend(context->x, context->x + context->width, 0xe);
//	} else {
//		textSetHorizontalBlend(context->x, context->x, 0xe);
//	}
//
//	gdl = text0f153628(gdl);
//	gdl = textRenderProjected(gdl, &x, &y, &text[i], font1, font2,
//			colour, context->width + context->x - x, context->height, 0, 0);
//	gdl = text0f153780(gdl);
//	gdl = menuApplyScissor(gdl);
//
//	textRestoreBlends();
//
//	unk14[2] = context->width;
//
//	return gdl;
//}

u32 var800711f0 = 0x00000002;

bool menuitemMarqueeTick(struct menuitem *item, union menuitemdata *data)
{
	s32 i;
	s32 textheight;
	s32 textwidth;
	struct fontchar *font1;
	struct font *font2;
	s32 increment;
	u16 sum = 0;
	char *text = menuResolveParam2Text(item);
	s32 limit;

#if VERSION == VERSION_JPN_FINAL
	font1 = g_CharsHandelGothicMd;
	font2 = g_FontHandelGothicMd;
#else
	font2 = g_FontHandelGothicSm;
	font1 = g_CharsHandelGothicSm;

	if (item->flags & MENUITEMFLAG_00000200) {
		font2 = g_FontHandelGothicXs;
		font1 = g_CharsHandelGothicXs;
	}
#endif

	if (!text) {
		return true;
	}

	i = 0;

	while (text[i] != '\0') {
		sum += text[i];
		i++;
	}

	if (data->marquee.sum != sum) {
		data->marquee.totalmoved = 0;
		data->marquee.sum = sum;
	}

	textMeasure(&textheight, &textwidth, text, font1, font2, 0);
	limit = data->marquee.unk04 + textwidth;
	increment = g_Vars.diffframe60 / 2;

	if (increment <= 0) {
		increment = 1;
	}

	data->marquee.totalmoved += increment;

	if (data->marquee.totalmoved > limit) {
		data->marquee.totalmoved = 0;
	}

	return true;
}

void menuitemMarqueeInit(union menuitemdata *data)
{
	data->marquee.totalmoved = 0;
	data->marquee.unk04 = 50;
	data->marquee.unk06 = 0;
}

Gfx *menuitem07Render(Gfx *gdl)
{
	return gdl;
}

Gfx *menuitemRankingRender(Gfx *gdl, struct menurendercontext *context)
{
	struct ranking rankings[MAX_MPCHRS];
	s32 numrows;
	u32 textcolour;
	s32 x;
	s32 y;
	u32 linecolour2; // ultimately unused
	s32 textwidth;
	s32 textheight;
	s32 team = false;
	u32 linecolour1;
	struct menuitemdata_ranking *data = &context->data->ranking;
	struct menudialog *dialog;
	s32 gap;
	s32 i;

	if (context->item->param2 == 1) {
		team = true;
		numrows = mpGetTeamRankings(rankings);
	} else {
		numrows = mpGetPlayerRankings(rankings);
	}

	gdl = text0f153628(gdl);

	// Gap from last item to bottom of dialog + header height
#if VERSION >= VERSION_JPN_FINAL
	gap = numrows * (LINEHEIGHT - 1) - context->height + 22;
#else
	gap = numrows * (LINEHEIGHT - 1) - context->height + 18;
#endif

	if (gap < 0) {
		gap = 0;
	}

	if (data->scrolloffset > gap) {
		data->scrolloffset = gap;
	}

	if (context->dialog->transitionfrac < 0) {
		textcolour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		textcolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		textcolour = colourBlend(textcolour, 0, 127) & 0xffffff00 | textcolour & 0xff;
	}

	if (!team) {
		// "Deaths"
		textMeasure(&textheight, &textwidth, langGet(L_MPMENU_277), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
		x = (context->x - textwidth) + 91;
		y = context->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_277), g_CharsHandelGothicXs, g_FontHandelGothicXs,
				textcolour, context->width, context->height, 0, 0);
	}

	// "Score"
	textMeasure(&textheight, &textwidth, langGet(L_MPMENU_278), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = (context->x - textwidth) + 120;
	y = context->y + 1;
	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_278), g_CharsHandelGothicXs, g_FontHandelGothicXs,
			textcolour, context->width, context->height, 0, 0);
	gdl = text0f153780(gdl);

	dialog = context->dialog;

	if (dialog->transitionfrac < 0) {
		linecolour1 = g_MenuColourPalettes[dialog->type].unk00;
	} else {
		linecolour1 = colourBlend(
				g_MenuColourPalettes[dialog->type2].unk00,
				g_MenuColourPalettes[dialog->type].unk00,
				dialog->colourweight);
	}

	if (dialog->dimmed) {
		linecolour1 = colourBlend(linecolour1, 0, 44) & 0xffffff00 | linecolour1 & 0xff;
	}

	if (dialog->transitionfrac < 0) {
		linecolour2 = g_MenuColourPalettes[dialog->type].unk08;
	} else {
		linecolour2 = colourBlend(
				g_MenuColourPalettes[dialog->type2].unk08,
				g_MenuColourPalettes[dialog->type].unk08,
				dialog->colourweight);
	}

	if (dialog->dimmed) {
		linecolour2 = colourBlend(linecolour2, 0, 44) & 0xffffff00 | linecolour2 & 0xff;
	}

	linecolour1 = text0f153e94(context->x, context->y + 2, -129) & 0xff | linecolour1 & 0xffffff00;
	linecolour2 = text0f153e94(context->x + context->width, context->y + 2, -129) & 0xff | linecolour2 & 0xffffff00;

	// Horizontal line between header and body
#if VERSION == VERSION_JPN_FINAL
	gdl = menugfxDrawFilledRect(gdl, context->x, context->y + 13, context->x + context->width, context->y + 14, linecolour1, linecolour1);
#else
	gdl = menugfxDrawFilledRect(gdl, context->x, context->y + 9, context->x + context->width, context->y + 10, linecolour1, linecolour1);
#endif

	gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
	g_ScissorX1 = context->x * g_ScaleX;
	g_ScissorX2 = (context->x + context->width) * g_ScaleX;
	g_ScissorY1 = context->y + (VERSION == VERSION_JPN_FINAL ? 14 : 10);
	g_ScissorY2 = context->y + context->height - 1;

	if (g_ScissorX1 < 0) {
		g_ScissorX1 = 0;
	}

	if (g_ScissorX2 < 0) {
		g_ScissorX2 = 0;
	}

	if (g_ScissorY1 < 0) {
		g_ScissorY1 = 0;
	}

	if (g_ScissorY2 < 0) {
		g_ScissorY2 = 0;
	}

	if (g_ScissorX1 > viGetBufWidth()) {
		g_ScissorX1 = viGetBufWidth();
	}

	if (g_ScissorX2 > viGetBufWidth()) {
		g_ScissorX2 = viGetBufWidth();
	}

	if (g_ScissorY1 > viGetBufHeight()) {
		g_ScissorY1 = viGetBufHeight();
	}

	if (g_ScissorY2 > viGetBufHeight()) {
		g_ScissorY2 = viGetBufHeight();
	}

	if (g_ScissorX2 < g_ScissorX1) {
		g_ScissorX2 = g_ScissorX1;
	}

	if (g_ScissorY2 < g_ScissorY1) {
		g_ScissorY2 = g_ScissorY1;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
			context->x * g_ScaleX,
			context->y + 10,
			(context->x + context->width) * g_ScaleX,
			context->y + context->height - 1);
#endif

	gdl = text0f153628(gdl);

	for (i = 0; i < numrows; i++) {
		struct ranking *ranking = &rankings[i];
		u32 weight = 0;
		char valuebuffer[8];

#if VERSION < VERSION_NTSC_1_0
		u32 stack;
#endif

		if (numrows >= 2) {
			weight = i / (f32)(numrows - 1) * 255;
		}

		textcolour = colourBlend(0x008888ff, 0x00ffffff, weight);
		x = context->x + 5;
#if VERSION >= VERSION_JPN_FINAL
		y = context->y + i * 13 - data->scrolloffset + 18;
#else
		y = context->y + i * 10 - data->scrolloffset + 14;
#endif

		if (team) {
			gdl = textRenderProjected(gdl, &x, &y, g_BossFile.teamnames[ranking->teamnum],
					g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
		} else {
			gdl = textRenderProjected(gdl, &x, &y, ranking->mpchr->name,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
		}

		if (!team) {
			// Deaths value (red)
			textcolour = colourBlend(0xcf0000ff, 0xff4040ff, weight);
			sprintf(valuebuffer, "%d\n", ranking->mpchr->numdeaths);
			textMeasure(&textheight, &textwidth, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			x = context->x - textwidth + 91;
#if VERSION >= VERSION_JPN_FINAL
			y = context->y + i * 13 - data->scrolloffset + 18;
#else
			y = context->y + i * 10 - data->scrolloffset + 14;
#endif
			gdl = textRenderProjected(gdl, &x, &y, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
					textcolour, context->width, context->height, 0, 0);
		}

		// Score value (green)
		textcolour = colourBlend(0x009f00ff, 0x00ff00ff, weight);
		sprintf(valuebuffer, "%d\n", ranking->score);
		textMeasure(&textheight, &textwidth, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = context->x - textwidth + 120;
#if VERSION >= VERSION_JPN_FINAL
		y = context->y + i * 13 - data->scrolloffset + 18;
#else
		y = context->y + i * 10 - data->scrolloffset + 14;
#endif
		gdl = textRenderProjected(gdl, &x, &y, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				textcolour, context->width, context->height, 0, 0);
	}

	return text0f153780(gdl);
}

bool menuitemRankingTick(struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	f32 floatval;
	s32 intval;

	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		intval = 0;
		floatval = inputs->yaxis < 0 ? -(f32)inputs->yaxis : inputs->yaxis;

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_BETA
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			intval = inputs->yaxis < 0 ? (s32)floatval : -(s32)floatval;
		}

#if VERSION >= VERSION_PAL_BETA
		intval = intval + (s32)(((f32)inputs->updownheld + (f32)inputs->updownheld) * g_Vars.diffframe60freal);
#else
		intval += inputs->updownheld * 2 * g_Vars.diffframe60;
#endif
		data->ranking.scrolloffset += intval;

		if (data->ranking.scrolloffset < 0) {
			data->ranking.scrolloffset = 0;
		}
	}

	return true;
}

void menuitemRankingInit(union menuitemdata *data)
{
	data->ranking.scrolloffset = 0;
}

Gfx *menuitemPlayerStatsRender(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_dropdown *data = &context->data->dropdown;
	s32 x;
	s32 y;
	u32 maincolour;
	s32 playernum = g_MpSelectedPlayersForStats[g_MpPlayerNum];
	struct mpchrconfig *mpchr;
	u32 selectioncolour;
	s32 textheight;
	s32 textwidth;
	s32 numchrs = mpGetNumChrs();
	char buffer[12];
	s32 i;
	u32 weight;
	s32 gap;
	s32 ypos = 0;

	mpchr = MPCHR(playernum);

	gdl = text0f153628(gdl);

	// Write selected player's name
	weight = func0f006b08(40) * 255;

	if (context->dialog->transitionfrac < 0) {
		selectioncolour = g_MenuColourPalettes[context->dialog->type].focused;
	} else {
		selectioncolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].focused,
				g_MenuColourPalettes[context->dialog->type].focused,
				context->dialog->colourweight);
	}

	selectioncolour = colourBlend(colourBlend(0xffffffff, 0x000000ff, 127), selectioncolour, weight);
	x = context->x + 2;
	y = context->y + 1;

	gdl = textRenderProjected(gdl, &x, &y, mpchr->name, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			selectioncolour, context->width, context->height, 0, 0);

	// "Suicides" heading
	if (context->dialog->transitionfrac < 0) {
		maincolour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		maincolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		maincolour = colourBlend(maincolour, 0x00000000, 127) & 0xffffff00 | maincolour & 0xff;
	}

	textMeasure(&textheight, &textwidth, langGet(L_MPMENU_281), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
#if VERSION >= VERSION_NTSC_1_0
	x = context->x - textwidth + 121;
#else
	x = context->x + 56;
#endif
	y = context->y + 1;

	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_281), g_CharsHandelGothicXs, g_FontHandelGothicXs,
			maincolour, context->width, context->height, 0, 0);

	// Num suicides
#if VERSION >= VERSION_NTSC_1_0
	x = context->x - textwidth + 119;
#endif
	sprintf(buffer, "%d\n", mpchr->killcounts[playernum]);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
#if VERSION >= VERSION_NTSC_1_0
	x -= textwidth;
#else
	x = context->x + 95;
#endif
	y = context->y + 1;

#if VERSION == VERSION_JPN_FINAL
	y++;
#endif

	gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0xffff00ff, context->width, context->height, 0, 0);

	// Move ypos past top row
#if VERSION >= VERSION_JPN_FINAL
	ypos += 14;
#else
	ypos += 12;
#endif

	if (mpGetNumChrs() >= 2) {
		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].unfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].unfocused,
					g_MenuColourPalettes[context->dialog->type].unfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		// "Deaths" heading
		textMeasure(&textheight, &textwidth, langGet(L_MPMENU_282), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
		x = context->x - textwidth + 120;
		y = context->y + ypos;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_282), g_CharsHandelGothicXs, g_FontHandelGothicXs,
				maincolour, context->width, context->height, 0, 0);

		// "Kills" heading
		textMeasure(&textheight, &textwidth, langGet(L_MPMENU_283), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION >= VERSION_JPN_FINAL
		x = context->x + 4;
#else
		x = context->x - textwidth + 25;
#endif

		y = context->y + ypos;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_283),  g_CharsHandelGothicXs, g_FontHandelGothicXs,
				maincolour, context->width, context->height, 0, 0);

		// Move ypos past heading row
#if VERSION >= VERSION_JPN_FINAL
		ypos += 12;
#else
		ypos += 7;
#endif

		// Prepare scissor for table
		gap = numchrs * (LINEHEIGHT - 1) - context->height + ypos;
#if VERSION >= VERSION_JPN_FINAL
		gap -= 13;
#else
		gap -= 10;
#endif

		if (gap < 0) {
			gap = 0;
		}

		if (data->scrolloffset > gap) {
			data->scrolloffset = gap;
		}

		gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
		g_ScissorX1 = context->x * g_ScaleX;
		g_ScissorX2 = (context->x + context->width) * g_ScaleX;
		g_ScissorY1 = context->y + ypos;
		g_ScissorY2 = context->y + context->height;

		if (g_ScissorX1 < 0) {
			g_ScissorX1 = 0;
		}

		if (g_ScissorX2 < 0) {
			g_ScissorX2 = 0;
		}

		if (g_ScissorY1 < 0) {
			g_ScissorY1 = 0;
		}

		if (g_ScissorY2 < 0) {
			g_ScissorY2 = 0;
		}

		if (g_ScissorX1 > viGetBufWidth()) {
			g_ScissorX1 = viGetBufWidth();
		}

		if (g_ScissorX2 > viGetBufWidth()) {
			g_ScissorX2 = viGetBufWidth();
		}

		if (g_ScissorY1 > viGetBufHeight()) {
			g_ScissorY1 = viGetBufHeight();
		}

		if (g_ScissorY2 > viGetBufHeight()) {
			g_ScissorY2 = viGetBufHeight();
		}

		if (g_ScissorX2 < g_ScissorX1) {
			g_ScissorX2 = g_ScissorX1;
		}

		if (g_ScissorY2 < g_ScissorY1) {
			g_ScissorY2 = g_ScissorY1;
		}

		gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
		gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
				context->x * g_ScaleX,
				context->y + ypos,
				(context->x + context->width) * g_ScaleX,
				context->y + context->height);
#endif

		ypos -= data->scrolloffset;

		for (i = 0; i < MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *loopmpchr = MPCHR(i);

				if (i != playernum) {
					// Name
					x = context->x + 29;
					y = context->y + ypos;
					gdl = textRenderProjected(gdl, &x, &y, loopmpchr->name, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							0x00ffffff, context->width, context->height, 0, 0);

					// Num deaths
					sprintf(buffer, "%d\n", loopmpchr->killcounts[playernum]);
					textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
					x = context->x - textwidth + 120;
					y = context->y + ypos;
					gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							0xff4040ff, context->width, context->height, 0, 0);

					// Num kills
					sprintf(buffer, "%d\n", mpchr->killcounts[i]);
					textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

#if VERSION == VERSION_JPN_FINAL
					x = context->x + 4;
#else
					x = context->x - textwidth + 25;
#endif

					y = context->y + ypos;
					gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							0x00ff00ff, context->width, context->height, 0, 0);

#if VERSION == VERSION_JPN_FINAL
					ypos += 13;
#else
					ypos += 10;
#endif
				}
			}
		}
	}

	return text0f153780(gdl);
}

bool menuitemPlayerStatsTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	f32 floatval;
	s32 intval;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && !dialog->dimmed) {
		intval = 0;
		floatval = inputs->yaxis < 0 ? -(f32)inputs->yaxis : inputs->yaxis;

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_BETA
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			intval = inputs->yaxis < 0 ? (s32)floatval : -(s32)floatval;
		}

#if VERSION >= VERSION_PAL_BETA
		intval = intval + (s32)(((f32)inputs->updownheld + (f32)inputs->updownheld) * g_Vars.diffframe60freal);
#else
		intval += inputs->updownheld * 2 * g_Vars.diffframe60;
#endif
		data->dropdown.scrolloffset += intval;

		if (data->dropdown.scrolloffset < 0) {
			data->dropdown.scrolloffset = 0;
		}
	}

	menuitemDropdownTick(item, dialog, inputs, tickflags, data);
}

Gfx *menuitemPlayerStatsOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data)
{
#if VERSION >= VERSION_NTSC_1_0
	return menuitemDropdownOverlay(gdl, x + 1, y, -1, y2, item, dialog, data);
#else
	return menuitemDropdownOverlay(gdl, x, y, 56, y2, item, dialog, data);
#endif
}

void menuitemPlayerStatsInit(struct menuitem *item, union menuitemdata *data)
{
	data->dropdown.scrolloffset = 0;
	g_MpSelectedPlayersForStats[g_MpPlayerNum] = g_MpPlayerNum;

	menuitemDropdownInit(item, data);
}

Gfx *menuitemControllerRenderLine(Gfx *gdl, s32 speed, s32 x1, s32 y1, s32 x2, s32 y2)
{
	speed = speed + (x1 % 4);

	gSPTextureRectangle(gdl++,
			x1 * 4 * g_ScaleX, y1 * 4,
			x2 * 4 * g_ScaleX, y2 * 4,
			G_TX_RENDERTILE,
			speed * 32,
			(y1 % 4) * 32,
			1024 / g_ScaleX, 1024);

	return gdl;
}

Gfx *menuitemControllerRenderTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha)
{
	gDPPipeSync(gdl++);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);

	texSelect(&gdl, &g_TexGeneralConfigs[texturenum], 2, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);

	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0);

	gDPSetColor(gdl++, G_SETENVCOLOR, 0xffffff00 | alpha);

	gSPTextureRectangle(gdl++,
			(x << 2) * g_ScaleX, y << 2,
			((x + 32) << 2) * g_ScaleX, (y + 32) << 2,
			0, 16, 1008, 1024 / g_ScaleX, 0xfc00);

	return gdl;
}

struct lineconfig {
	s32 x1;
	s32 y1;
	s32 x2;
	s32 y2;
};

#if VERSION >= VERSION_JPN_FINAL
struct lineconfig linecfgs[] = {
	/* 0*/ { 12, 4,   -1, 31  },
	/* 1*/ { 51, 4,   -1, 31  },
	/* 2*/ { 12, 4,   75, -1  },
	/* 3*/ { 55, 40,  64, -1  },
	/* 4*/ { 63, 40,  -1, 16  },
	/* 5*/ { 63, 16,  75, -1  },
	/* 6*/ { 51, 44,  55, -1  },
	/* 7*/ { 59, 44,  68, -1  },
	/* 8*/ { 67, 44,  -1, 28  },
	/* 9*/ { 67, 28,  75, -1  },
	/*10*/ { 55, 48,  72, -1  },
	/*11*/ { 71, 48,  -1, 40  },
	/*12*/ { 71, 40,  75, -1  },
	/*13*/ { 49, 52,  75, -1  },
	/*14*/ { 43, 49,  -1, 64  },
	/*15*/ { 43, 64,  75, -1  },
	/*16*/ { 30, 56,  37, -1  },
	/*17*/ { 37, 56,  -1, 76  },
	/*18*/ { 37, 76,  75, -1  },
	/*19*/ { 34, 73,  34, 88  },
	/*20*/ { 34, 88,  75, -1  },
	/*21*/ { 12, 51,  -1, 100 },
	/*22*/ { 12, 100, 75, -1  },
};

GLOBAL_ASM(
glabel menuitemControllerRenderLines
/*  f0f04a4:	3c018006 */ 	lui	$at,0x8006
/*  f0f04a8:	c4241510 */ 	lwc1	$f4,0x1510($at)
/*  f0f04ac:	3c014080 */ 	lui	$at,0x4080
/*  f0f04b0:	44814000 */ 	mtc1	$at,$f8
/*  f0f04b4:	46002187 */ 	neg.s	$f6,$f4
/*  f0f04b8:	3c014248 */ 	lui	$at,0x4248
/*  f0f04bc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f04c0:	44818000 */ 	mtc1	$at,$f16
/*  f0f04c4:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0f04c8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0f04cc:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f04d0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0f04d4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0f04d8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0f04dc:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f04e0:	8fb00068 */ 	lw	$s0,0x68($sp)
/*  f0f04e4:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0f04e8:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0f04ec:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0f04f0:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0f04f4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f04f8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0f04fc:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0f0500:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0f0504:	44152000 */ 	mfc1	$s5,$f4
/*  f0f0508:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0f050c:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0510:	3c0de700 */ 	lui	$t5,0xe700
/*  f0f0514:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f0518:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f051c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0f0520:	0010c042 */ 	srl	$t8,$s0,0x1
/*  f0f0524:	03008025 */ 	move	$s0,$t8
/*  f0f0528:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f052c:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f0f0530:	3c0db900 */ 	lui	$t5,0xb900
/*  f0f0534:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0f0538:	00a0b025 */ 	move	$s6,$a1
/*  f0f053c:	3c05800b */ 	lui	$a1,0x800b
/*  f0f0540:	00c09025 */ 	move	$s2,$a2
/*  f0f0544:	00e09825 */ 	move	$s3,$a3
/*  f0f0548:	06a10004 */ 	bgez	$s5,.JF0f0f055c
/*  f0f054c:	32af0003 */ 	andi	$t7,$s5,0x3
/*  f0f0550:	11e00002 */ 	beqz	$t7,.JF0f0f055c
/*  f0f0554:	00000000 */ 	nop
/*  f0f0558:	25effffc */ 	addiu	$t7,$t7,-4
.JF0f0f055c:
/*  f0f055c:	01e0a825 */ 	move	$s5,$t7
/*  f0f0560:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f0564:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0f0568:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f056c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0f0570:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f0574:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f0578:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f0f057c:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f0580:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0584:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f0588:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f058c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0f0590:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0f0594:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f0f0598:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f059c:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0f05a0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f05a4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0f05a8:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f05ac:	240e0c00 */ 	li	$t6,0xc00
/*  f0f05b0:	24180001 */ 	li	$t8,0x1
/*  f0f05b4:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f05b8:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f05bc:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f05c0:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f05c4:	8ca5bf98 */ 	lw	$a1,-0x4068($a1)
/*  f0f05c8:	240f0002 */ 	li	$t7,0x2
/*  f0f05cc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f05d0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f05d4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f05d8:	00003825 */ 	move	$a3,$zero
/*  f0f05dc:	24060002 */ 	li	$a2,0x2
/*  f0f05e0:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0f05e4:	0fc2d290 */ 	jal	texSelect
/*  f0f05e8:	24a50294 */ 	addiu	$a1,$a1,0x294
/*  f0f05ec:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f05f0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0f05f4:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f0f05f8:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f05fc:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0600:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f0604:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f0608:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0f060c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f0610:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0f0614:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f0618:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0f061c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f0620:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0f0624:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f0628:	3c0eff37 */ 	lui	$t6,0xff37
/*  f0f062c:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0f0630:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f0634:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0638:	35ad9a25 */ 	ori	$t5,$t5,0x9a25
/*  f0f063c:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0f0640:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f0644:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f0648:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0f064c:	2401ff00 */ 	li	$at,-256
/*  f0f0650:	02016025 */ 	or	$t4,$s0,$at
/*  f0f0654:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0f0658:	afb80050 */ 	sw	$t8,0x50($sp)
/*  f0f065c:	3c19fb00 */ 	lui	$t9,0xfb00
/*  f0f0660:	0272082a */ 	slt	$at,$s3,$s2
/*  f0f0664:	02408825 */ 	move	$s1,$s2
/*  f0f0668:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0f066c:	1420004e */ 	bnez	$at,.JF0f0f07a8
/*  f0f0670:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f0f0674:	00126900 */ 	sll	$t5,$s2,0x4
/*  f0f0678:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f067c:	25ce1734 */ 	addiu	$t6,$t6,0x1734
/*  f0f0680:	26770001 */ 	addiu	$s7,$s3,0x1
/*  f0f0684:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0f0688:	01ae8021 */ 	addu	$s0,$t5,$t6
/*  f0f068c:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0f0690:	241e000e */ 	li	$s8,0xe
/*  f0f0694:	2414ffff */ 	li	$s4,-1
.JF0f0f0698:
/*  f0f0698:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f069c:	02a02825 */ 	move	$a1,$s5
/*  f0f06a0:	568f0005 */ 	bnel	$s4,$t7,.JF0f0f06b8
/*  f0f06a4:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0f06a8:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f06ac:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0f06b0:	ae19000c */ 	sw	$t9,0xc($s0)
/*  f0f06b4:	8e080008 */ 	lw	$t0,0x8($s0)
.JF0f0f06b8:
/*  f0f06b8:	56880005 */ 	bnel	$s4,$t0,.JF0f0f06d0
/*  f0f06bc:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0f06c0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f0f06c4:	25880001 */ 	addiu	$t0,$t4,0x1
/*  f0f06c8:	ae080008 */ 	sw	$t0,0x8($s0)
/*  f0f06cc:	8e0a0000 */ 	lw	$t2,0x0($s0)
.JF0f0f06d0:
/*  f0f06d0:	150a0002 */ 	bne	$t0,$t2,.JF0f0f06dc
/*  f0f06d4:	254e0001 */ 	addiu	$t6,$t2,0x1
/*  f0f06d8:	ae0e0008 */ 	sw	$t6,0x8($s0)
.JF0f0f06dc:
/*  f0f06dc:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f06e0:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f06e4:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f0f06e8:	55e90004 */ 	bnel	$t7,$t1,.JF0f0f06fc
/*  f0f06ec:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0f06f0:	ae18000c */ 	sw	$t8,0xc($s0)
/*  f0f06f4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0f06f8:	8e080008 */ 	lw	$t0,0x8($s0)
.JF0f0f06fc:
/*  f0f06fc:	010a082a */ 	slt	$at,$t0,$t2
/*  f0f0700:	50200005 */ 	beqzl	$at,.JF0f0f0718
/*  f0f0704:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0f0708:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f0f070c:	ae0a0008 */ 	sw	$t2,0x8($s0)
/*  f0f0710:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f0714:	8e0b000c */ 	lw	$t3,0xc($s0)
.JF0f0f0718:
/*  f0f0718:	0169082a */ 	slt	$at,$t3,$t1
/*  f0f071c:	50200006 */ 	beqzl	$at,.JF0f0f0738
/*  f0f0720:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0f0724:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f0f0728:	01205825 */ 	move	$t3,$t1
/*  f0f072c:	ae09000c */ 	sw	$t1,0xc($s0)
/*  f0f0730:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f0734:	8e080008 */ 	lw	$t0,0x8($s0)
.JF0f0f0738:
/*  f0f0738:	123e0008 */ 	beq	$s1,$s8,.JF0f0f075c
/*  f0f073c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0f0740:	24010011 */ 	li	$at,0x11
/*  f0f0744:	12210005 */ 	beq	$s1,$at,.JF0f0f075c
/*  f0f0748:	24010013 */ 	li	$at,0x13
/*  f0f074c:	12210003 */ 	beq	$s1,$at,.JF0f0f075c
/*  f0f0750:	24010015 */ 	li	$at,0x15
/*  f0f0754:	56210003 */ 	bnel	$s1,$at,.JF0f0f0764
/*  f0f0758:	86c20000 */ 	lh	$v0,0x0($s6)
.JF0f0f075c:
/*  f0f075c:	00152823 */ 	negu	$a1,$s5
/*  f0f0760:	86c20000 */ 	lh	$v0,0x0($s6)
.JF0f0f0764:
/*  f0f0764:	86c30002 */ 	lh	$v1,0x2($s6)
/*  f0f0768:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0f076c:	01026821 */ 	addu	$t5,$t0,$v0
/*  f0f0770:	01637821 */ 	addu	$t7,$t3,$v1
/*  f0f0774:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f0f0778:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f0f077c:	0142c821 */ 	addu	$t9,$t2,$v0
/*  f0f0780:	01236021 */ 	addu	$t4,$t1,$v1
/*  f0f0784:	01933821 */ 	addu	$a3,$t4,$s3
/*  f0f0788:	03323021 */ 	addu	$a2,$t9,$s2
/*  f0f078c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f0790:	0fc3c038 */ 	jal	menuitemControllerRenderLine
/*  f0f0794:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f0798:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f079c:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f0f07a0:	16f1ffbd */ 	bne	$s7,$s1,.JF0f0f0698
/*  f0f07a4:	afa20050 */ 	sw	$v0,0x50($sp)
.JF0f0f07a8:
/*  f0f07a8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0f07ac:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0f07b0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0f07b4:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0f07b8:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0f07bc:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0f07c0:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0f07c4:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0f07c8:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0f07cc:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0f07d0:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0f07d4:	03e00008 */ 	jr	$ra
/*  f0f07d8:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#else
Gfx *menuitemControllerRenderLines(Gfx *gdl, struct menurendercontext *context, s32 firstindex, s32 lastindex, s32 padx, s32 pady, u32 alpha)
{
	s32 speed;
	s32 i;

	static struct lineconfig linecfgs[] = {
#if PAL
		/* 0*/ { 12, -1, -1, 10 },
		/* 1*/ { 51, -1, -1, 10 },
		/* 2*/ { 12, -1, 75, -1 },
		/* 3*/ { 55, 19, 64, -1 },
		/* 4*/ { 63, 19, -1, 7  },
		/* 5*/ { 63, 7,  75, -1 },
		/* 6*/ { 51, 23, 55, -1 },
		/* 7*/ { 59, 23, 68, -1 },
		/* 8*/ { 67, 23, -1, 15 },
		/* 9*/ { 67, 15, 75, -1 },
		/*10*/ { 55, 27, 72, -1 },
		/*11*/ { 71, 27, -1, 23 },
		/*12*/ { 71, 23, 75, -1 },
		/*13*/ { 49, 31, 75, -1 },
		/*14*/ { 43, 28, -1, 39 },
		/*15*/ { 43, 39, 75, -1 },
		/*16*/ { 30, 35, 37, -1 },
		/*17*/ { 37, 35, -1, 47 },
		/*18*/ { 37, 47, 75, -1 },
		/*19*/ { 34, 55, 75, -1 },
		/*20*/ { 12, 30, -1, 63 },
		/*21*/ { 12, 63, 75, -1 },
#else
		/* 0*/ { 12, 10, -1, 3  },
		/* 1*/ { 51, 10, -1, 3  },
		/* 2*/ { 12, 3,  75, -1 },
		/* 3*/ { 55, 19, 64, -1 },
		/* 4*/ { 63, 19, -1, 10 },
		/* 5*/ { 63, 10, 75, -1 },
		/* 6*/ { 51, 23, 55, -1 },
		/* 7*/ { 59, 23, 68, -1 },
		/* 8*/ { 67, 23, -1, 17 },
		/* 9*/ { 67, 17, 75, -1 },
		/*10*/ { 55, 27, 72, -1 },
		/*11*/ { 71, 27, -1, 24 },
		/*12*/ { 71, 24, 75, -1 },
		/*13*/ { 49, 31, 75, -1 },
		/*14*/ { 43, 28, -1, 38 },
		/*15*/ { 43, 38, 75, -1 },
		/*16*/ { 30, 35, 37, -1 },
		/*17*/ { 37, 35, -1, 45 },
		/*18*/ { 37, 45, 75, -1 },
		/*19*/ { 34, 52, 75, -1 },
		/*20*/ { 12, 30, -1, 59 },
		/*21*/ { 12, 59, 75, -1 },
#endif
	};

	speed = (s32)(-var80061630 * 4.0f * 50.0f) % 4;
	alpha = alpha >> 1;

	gDPPipeSync(gdl++);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);

	texSelect(&gdl, &g_TexGeneralConfigs[55], 2, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);
	gDPSetEnvColorViaWord(gdl++, 0xffffff00 | alpha);

	for (i = firstindex; i <= lastindex; i++) {
		s32 thisspeed = speed;
		s32 tmp;

		if (linecfgs[i].y2 == -1) {
			linecfgs[i].y2 = linecfgs[i].y1 + 1;
		}

		if (linecfgs[i].x2 == -1) {
			linecfgs[i].x2 = linecfgs[i].x1 + 1;
		}

		if (linecfgs[i].x2 == linecfgs[i].x1) {
			linecfgs[i].x2 = linecfgs[i].x1 + 1;
		}

		if (linecfgs[i].y2 == linecfgs[i].y1) {
			linecfgs[i].y2 = linecfgs[i].y1 + 1;
		}

		if (linecfgs[i].x2 < linecfgs[i].x1) {
			tmp = linecfgs[i].x1;
			linecfgs[i].x1 = linecfgs[i].x2;
			linecfgs[i].x2 = tmp;
		}

		if (linecfgs[i].y2 < linecfgs[i].y1) {
			tmp = linecfgs[i].y1;
			linecfgs[i].y1 = linecfgs[i].y2;
			linecfgs[i].y2 = tmp;
		}

		switch (i) {
		case 14:
		case 17:
		case 20:
			thisspeed = -thisspeed;
			break;
		}

		gdl = menuitemControllerRenderLine(gdl, thisspeed,
				linecfgs[i].x1 + context->x + padx, linecfgs[i].y1 + context->y + pady,
				linecfgs[i].x2 + context->x + padx, linecfgs[i].y2 + context->y + pady);
	}

	return gdl;
}
#endif

// These are the action names, like "AIM", and "LOOK UP"
u16 var80071354[][9] = {
	/*0*/  { L_MPWEAPONS_194, L_MPWEAPONS_196, L_MPWEAPONS_202, L_MPWEAPONS_197, L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_205, L_MPWEAPONS_210 },
	/*1*/  { L_MPWEAPONS_194, L_MPWEAPONS_200, L_MPWEAPONS_202, L_MPWEAPONS_201, L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_205, L_MPWEAPONS_210 },
	/*2*/  { L_MPWEAPONS_203, L_MPWEAPONS_196, L_MPWEAPONS_202, L_MPWEAPONS_197, L_MPWEAPONS_205, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_194, L_MPWEAPONS_210 },
	/*3*/  { L_MPWEAPONS_203, L_MPWEAPONS_200, L_MPWEAPONS_202, L_MPWEAPONS_201, L_MPWEAPONS_205, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_194, L_MPWEAPONS_210 },
	/*4*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_205, L_OPTIONS_003   },
	/*5*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_205, L_OPTIONS_003   },
	/*6*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*7*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*8*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_209, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*9*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_208, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*10*/ { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_209, L_MPWEAPONS_205, L_OPTIONS_003   },
	/*11*/ { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_208, L_MPWEAPONS_205, L_OPTIONS_003   },
};

u16 menuitemControllerGetButtonAction(s32 mode, s32 buttonnum)
{
	u32 textid = var80071354[mode][buttonnum];

	if (textid == L_MPWEAPONS_194 // "AIM"
			&& optionsGetAimControl(g_Menus[g_MpPlayerNum].main.mpindex) == AIMCONTROL_TOGGLE) {
		textid = L_MPWEAPONS_195; // "AIM TOGGLE"
	}

	if (textid == L_MPWEAPONS_196 // "LOOK UP"
			&& optionsGetForwardPitch(g_Menus[g_MpPlayerNum].main.mpindex) == false) {
		textid = L_MPWEAPONS_198; // "LOOK DOWN"
	}

	if (textid == L_MPWEAPONS_197 // "LOOK DOWN"
			&& optionsGetForwardPitch(g_Menus[g_MpPlayerNum].main.mpindex) == false) {
		textid = L_MPWEAPONS_199; // "LOOK UP"
	}

	return textid;
}

/**
 * Renders the button labels and actions for the control style dialog.
 *
 * When switching modes (control styles), a fade effect is used to fade in the
 * action names, but only if they differ from the previous mode.
 *
 * Note that the valuecolour argument is mostly unused - only the alpha channel
 * is used because the rest is bitwise or'ed to white.
 */
Gfx *menuitemControllerRenderText(Gfx *gdl, s32 curmode, struct menurendercontext *context, s32 padx, s32 pady, u32 valuecolour, u32 labelcolour, s8 prevmode)
{
	s32 rx;
	s32 ry;
	u16 textnum;
	u32 colour;

	u16 labels[] = {
		/*0*/ L_MPWEAPONS_185, // "L/R BUTTONS:"
		/*1*/ L_MPWEAPONS_186, // "UP C BUTTON:"
		/*2*/ L_MPWEAPONS_187, // "LEFT/RIGHT C BUTTONS:"
		/*3*/ L_MPWEAPONS_188, // "DOWN C BUTTON:"
		/*4*/ L_MPWEAPONS_189, // "A BUTTON:"
		/*5*/ L_MPWEAPONS_190, // "B BUTTON:"
		/*6*/ L_MPWEAPONS_191, // "CONTROL STICK:"
		/*7*/ L_MPWEAPONS_192, // "Z BUTTON:"
		/*8*/ L_MPWEAPONS_193, // "+ CONTROL PAD:"
	};

	s32 i;

	gdl = text0f153628(gdl);

	for (i = 0; i < ARRAYCOUNT(labels); i++) {
#if VERSION == VERSION_JPN_FINAL
		ry = i * 12 + context->y + pady + 1;
#elif VERSION >= VERSION_PAL_BETA
		ry = i * 8 + context->y + pady - 4;
#elif VERSION >= VERSION_NTSC_1_0
		ry = i * 7 + context->y + pady;
#endif

		// For the 2.x styles, only labels 4-7 are shown
		if (curmode < CONTROLMODE_21 || (i >= 4 && i <= 7)) {
			// Rendering a label such as "L/R BUTTONS:"
			rx = context->x + padx + 76;
#if VERSION < VERSION_NTSC_1_0
			ry = i * 7 + context->y + pady;
#endif
			gdl = textRenderProjected(gdl, &rx, &ry, langGet(labels[i]),
					g_CharsHandelGothicXs, g_FontHandelGothicXs, labelcolour, viGetWidth(), viGetHeight(), 0, 0);
		}

		textnum = menuitemControllerGetButtonAction(curmode, i);
		colour = valuecolour;

		// If there's a prevmode, get the text ID that was in this position for
		// prevmode. If it's the same text as curmode, don't fade the text.
		if (prevmode >= 0) {
			// I don't see how curmode can ever be > CONTROLMODE_24. Perhaps
			// during development the second player in the 2.x styles had to
			// choose their control style separately to player 1, in which case
			// there would have been 2.5, 2.6, 2.7 and 2.8 for player 2.
			if (curmode > CONTROLMODE_24) {
				if (textnum == menuitemControllerGetButtonAction(prevmode + 4, i)) {
					colour = labelcolour;
				}
			} else {
				if (textnum == menuitemControllerGetButtonAction(prevmode, i)) {
					colour = labelcolour;
				}
			}
		}

		if (curmode >= CONTROLMODE_21 && i == 2) {
			// Rendering a "CONTROLLER 1" or "CONTROLLER 2" heading
			rx = context->x + padx + 63;
			colour = labelcolour;
		} else {
			// Rendering a value such as "WALK/TURN"
			// Make it white but preserve alpha
			colour |= 0xffffff00;
		}

		gdl = textRenderProjected(gdl, &rx, &ry, langGet(textnum),
				g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, viGetWidth(), viGetHeight(), 0, 0);
	}

	return text0f153780(gdl);
}

Gfx *menuitemControllerRenderPad(Gfx *gdl, struct menurendercontext *context, s32 padx, s32 pady, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode)
{
	s32 rx = context->x + padx;
	s32 ry = context->y + pady + (VERSION == VERSION_JPN_FINAL ? 25 : 4);

	// The controller graphic is split into 4 textures
	gdl = menuitemControllerRenderTexture(gdl, rx, ry, 0x33, alpha);
	gdl = menuitemControllerRenderTexture(gdl, rx + 32, ry, 0x34, alpha);
	gdl = menuitemControllerRenderTexture(gdl, rx, ry + 32, 0x35, alpha);
	gdl = menuitemControllerRenderTexture(gdl, rx + 32, ry + 32, 0x36, alpha);

#if VERSION >= VERSION_JPN_FINAL
	if (curmode >= CONTROLMODE_21) {
		gdl = menuitemControllerRenderLines(gdl, context, 13, 20, padx, pady, alpha);
	} else {
		gdl = menuitemControllerRenderLines(gdl, context, 0, 22, padx, pady, alpha);
	}
#else
	if (curmode >= CONTROLMODE_21) {
		gdl = menuitemControllerRenderLines(gdl, context, 13, 19, padx, pady, alpha);
	} else {
		gdl = menuitemControllerRenderLines(gdl, context, 0, 21, padx, pady, alpha);
	}
#endif

	return menuitemControllerRenderText(gdl, curmode, context, padx, pady, colour1, colour2, prevmode);
}

Gfx *menuitemControllerRender(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_controller *data = &context->data->controller;
	u32 colour;
	u32 textcolour;
	s32 x;
	s32 y;
	char text[32];
	struct menudialog *dialog = context->dialog;
	u32 contalpha;
	u32 textalpha;

	textBackupAndResetBlends();

	// If changing modes within the same group (eg. within 1.x)
	if (data->curmode != (g_Menus[g_MpPlayerNum].main.controlmode & 0xff)) {
		data->prevmode = data->curmode;
		data->curmode = g_Menus[g_MpPlayerNum].main.controlmode;
		data->textfadetimer = 0;
	}

	// If changing control group (eg. 1.4 -> 2.1)
	if (data->controlgroup == 1) {
		if (g_Menus[g_MpPlayerNum].main.controlmode < CONTROLMODE_21) {
			data->controlgroup = 2;
			data->contfadetimer = 0;
			data->prevmode = -1;
		}
	} else {
		if (g_Menus[g_MpPlayerNum].main.controlmode >= CONTROLMODE_21) {
			data->controlgroup = 1;
			data->contfadetimer = 0;
			data->prevmode = -1;
		}
	}

	// If text is fading in (eg. recently changed 1.1 -> 1.2)
	if (data->textfadetimer < 255) {
		s32 value = data->textfadetimer + g_Vars.diffframe240 * 2;

		if (value > 255) {
			value = 255;
		}

		data->textfadetimer = value;
	}

	// If controller is fading in (eg. recently changed 1.4 -> 2.1)
	if (data->contfadetimer < 255) {
		s32 value = data->contfadetimer + g_Vars.diffframe240 * 2;

		if (value > 255) {
			value = 255;
		}

		data->contfadetimer = value;
	}

	textalpha = data->textfadetimer;
	contalpha = data->contfadetimer;
	gdl = text0f153628(gdl);

	if (dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[dialog->type2].unfocused,
				g_MenuColourPalettes[dialog->type].unfocused,
				dialog->colourweight);
	}

	if (dialog->dimmed) {
		colour = colourBlend(colour, 0, 44) & 0xffffff00 | colour & 0xff;
	}

	textSetWaveColours(
			g_MenuColourPalettes3[dialog->type].unfocused,
			g_MenuColourPalettes2[dialog->type].unfocused);

	if (g_Menus[g_MpPlayerNum].main.controlmode >= CONTROLMODE_21) {
		sprintf(text, langGet(L_MPWEAPONS_213), // "Control Style %s %s"
				langGet(g_ControlStyleOptions[g_Menus[g_MpPlayerNum].main.controlmode]),
				langGet(L_MPWEAPONS_215)); // "(Two-Handed)"
	} else {
		sprintf(text, langGet(L_MPWEAPONS_213), // "Control Style %s %s"
				langGet(g_ControlStyleOptions[g_Menus[g_MpPlayerNum].main.controlmode]),
				langGet(L_MPWEAPONS_214)); // "(One-Handed)"
	}

	x = context->x + 2;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, text,
			g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
	gdl = text0f153780(gdl);

	textcolour = colourBlend(colour, colour & 0xffffff00, textalpha);
	colour = colourBlend(colour, colour & 0xffffff00, contalpha);

	if (g_Menus[g_MpPlayerNum].main.controlmode >= CONTROLMODE_21) {
		gdl = menuitemControllerRenderPad(gdl, context, 0, VERSION == VERSION_JPN_FINAL ? -4 : 12,
				g_Menus[g_MpPlayerNum].main.controlmode,
				contalpha, textcolour, colour, data->prevmode);
		gdl = menuitemControllerRenderPad(gdl, context, 0, VERSION == VERSION_JPN_FINAL ? 74 : 80,
				g_Menus[g_MpPlayerNum].main.controlmode + 4,
				contalpha, textcolour, colour, data->prevmode);
	} else {
		gdl = menuitemControllerRenderPad(gdl, context, 0, PAL ? 19 : 15,
				g_Menus[g_MpPlayerNum].main.controlmode,
				contalpha, textcolour, colour, data->prevmode);

		x = context->x;
		y = context->y + 92;

#if VERSION == VERSION_JPN_FINAL
		y += 34;
#endif

		gdl = text0f153628(gdl);
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPWEAPONS_216), // "Hold weapon button for ..."
				g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
		gdl = text0f153780(gdl);
	}

	textRestoreBlends();

	return gdl;
}

void menuitemControllerInit(union menuitemdata *data)
{
	data->controller.textfadetimer = 0;
	data->controller.contfadetimer = 0;
	data->controller.curmode = 255;
	data->controller.controlgroup = 255;
	data->controller.prevmode = -1;
}

Gfx *menuitemRender(Gfx *gdl, struct menurendercontext *context)
{
	switch (context->item->type) {
	case MENUITEMTYPE_LIST:        return menuitemListRender(gdl, context);
	case MENUITEMTYPE_SELECTABLE:  return menuitemSelectableRender(gdl, context);
	case MENUITEMTYPE_SLIDER:      return menuitemSliderRender(gdl, context);
	case MENUITEMTYPE_CHECKBOX:    return menuitemCheckboxRender(gdl, context);
	case MENUITEMTYPE_SCROLLABLE:  return menuitemScrollableRender(gdl, context);
	case MENUITEMTYPE_MARQUEE:     return menuitemMarqueeRender(gdl, context);
	case MENUITEMTYPE_LABEL:       return menuitemLabelRender(gdl, context);
	case MENUITEMTYPE_METER:       return menuitemMeterRender(gdl, context);
	case MENUITEMTYPE_SEPARATOR:   return menuitemSeparatorRender(gdl, context);
	case MENUITEMTYPE_OBJECTIVES:  return menuitemObjectivesRender(gdl, context);
	case MENUITEMTYPE_07:          return menuitem07Render(gdl);
	case MENUITEMTYPE_DROPDOWN:    return menuitemDropdownRender(gdl, context);
	case MENUITEMTYPE_KEYBOARD:    return menuitemKeyboardRender(gdl, context);
	case MENUITEMTYPE_RANKING:     return menuitemRankingRender(gdl, context);
	case MENUITEMTYPE_PLAYERSTATS: return menuitemPlayerStatsRender(gdl, context);
	case MENUITEMTYPE_CAROUSEL:    return menuitemCarouselRender(gdl, context);
	case MENUITEMTYPE_MODEL:       return menuitemModelRender(gdl, context);
	case MENUITEMTYPE_CONTROLLER:  return menuitemControllerRender(gdl, context);
	}

	return gdl;
}

/**
 * Return true if default up/down/left/right/back behaviour should be used.
 */
bool menuitemTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:        return menuitemListTick(item, inputs, tickflags, data);
	case MENUITEMTYPE_SELECTABLE:  return menuitemSelectableTick(item, inputs, tickflags);
	case MENUITEMTYPE_SLIDER:      return menuitemSliderTick(item, dialog, inputs, tickflags, data);
	case MENUITEMTYPE_CHECKBOX:    return menuitemCheckboxTick(item, inputs, tickflags);
	case MENUITEMTYPE_SCROLLABLE:  return menuitemScrollableTick(item, dialog, inputs, tickflags, data);
	case MENUITEMTYPE_MARQUEE:     return menuitemMarqueeTick(item, data);
	case MENUITEMTYPE_RANKING:     return menuitemRankingTick(inputs, tickflags, data);
	case MENUITEMTYPE_DROPDOWN:    return menuitemDropdownTick(item, dialog, inputs, tickflags, data);
	case MENUITEMTYPE_KEYBOARD:    return menuitemKeyboardTick(item, inputs, tickflags, data);
	case MENUITEMTYPE_CAROUSEL:    return menuitemCarouselTick(item, inputs, tickflags);
	case MENUITEMTYPE_PLAYERSTATS: return menuitemPlayerStatsTick(item, dialog, inputs, tickflags, data);
	}

	return true;
}

void menuitemInit(struct menuitem *item, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:
	case MENUITEMTYPE_DROPDOWN:
		menuitemDropdownInit(item, data);
		break;
	case MENUITEMTYPE_SCROLLABLE:
		menuitemScrollableInit(data);
		break;
	case MENUITEMTYPE_MARQUEE:
		menuitemMarqueeInit(data);
		break;
	case MENUITEMTYPE_RANKING:
		menuitemRankingInit(data);
		break;
	case MENUITEMTYPE_SLIDER:
		menuitemSliderInit(data);
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		menuitemPlayerStatsInit(item, data);
		break;
	case MENUITEMTYPE_KEYBOARD:
		menuitemKeyboardInit(item, data);
		break;
	case MENUITEMTYPE_CONTROLLER:
		menuitemControllerInit(data);
		break;
	}
}

Gfx *menuitemOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:        return menuitemListOverlay(gdl, x, y, x2, y2);
	case MENUITEMTYPE_DROPDOWN:    return menuitemDropdownOverlay(gdl, x, y, x2, y2, item, dialog, data);
	case MENUITEMTYPE_PLAYERSTATS: return menuitemPlayerStatsOverlay(gdl, x, y, x2, y2, item, dialog, data);
	}

	return gdl;
}
