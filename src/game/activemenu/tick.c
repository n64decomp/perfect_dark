#include <ultra64.h>
#include "constants.h"
#include "game/activemenu/activemenu.h"
#include "game/game_01b0a0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/options.h"
#include "bss.h"
#include "lib/joy.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_NTSC_1_0
void amTick(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		g_AmIndex = g_Vars.currentplayernum;

		if (g_AmMenus[g_AmIndex].togglefunc) {
			if (currentPlayerConsiderToggleGunFunction(60, false, 1) > 0) {
				g_AmMenus[g_AmIndex].togglefunc = false;
			}
		} else {
			// empty
		}

		if (g_Vars.normmplayerisrunning == false
				&& invGetCount() != g_AmMenus[g_AmIndex].numitems) {
			amAssignWeaponSlots();
		}

		if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
			s32 controlmode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);
			s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
			s32 numsamples = joyGetNumSamples();
			s32 j;

			for (j = 0; j < numsamples; j++) {
				s8 gotonextscreen = false;
				s8 cstickx = joyGetStickXOnSample(j, contpadnum);
				s8 csticky = joyGetStickYOnSample(j, contpadnum);
				s8 absstickx;
				s8 abssticky;
				u16 buttonsstate = joyGetButtonsOnSample(j, contpadnum, 0xffff);
				u16 buttonspressed = joyGetButtonsPressedOnSample(j, contpadnum, 0xffff);
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

				if (controlmode == CONTROLMODE_13 || controlmode == CONTROLMODE_14) {
					if ((buttonsstate & R_TRIG) || (buttonsstate & L_TRIG)) {
						stayopen = true;
					}

					if (buttonsstate & A_BUTTON) {
						g_AmMenus[g_AmIndex].allbots = true;
					}
				} else {
					if (buttonsstate & A_BUTTON) {
						stayopen = true;
					}

					if ((buttonsstate & R_TRIG) || (buttonsstate & L_TRIG)) {
						g_AmMenus[g_AmIndex].allbots = true;
					}
				}

				// If entering allbots mode, save current screen
				if (g_AmMenus[g_AmIndex].allbots
						&& g_AmMenus[g_AmIndex].screenindex >= 2
						&& g_AmMenus[g_AmIndex].origscreennum == 0) {
					g_AmMenus[g_AmIndex].origscreennum = g_AmMenus[g_AmIndex].screenindex;
					g_AmMenus[g_AmIndex].screenindex = 2;
					amChangeScreen(0);
				}

				// If exiting allbots mode, return to original screen
				if (!g_AmMenus[g_AmIndex].allbots
						&& g_AmMenus[g_AmIndex].origscreennum) {
					g_AmMenus[g_AmIndex].screenindex = g_AmMenus[g_AmIndex].origscreennum;
					g_AmMenus[g_AmIndex].origscreennum = 0;
					amChangeScreen(0);
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
					s8 cstickx2 = joyGetStickXOnSample(j, contpadnum2);
					s8 csticky2 = joyGetStickYOnSample(j, contpadnum2);
					u16 buttonsstate2 = joyGetButtonsOnSample(j, contpadnum2, 0xffff);
					u16 buttonspressed2 = joyGetButtonsPressedOnSample(j, contpadnum2, 0xffff);

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
					amClose();
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
								amApply(g_AmMenus[g_AmIndex].slotnum);
							}
						} else {
							// Bot command screen, in multiplayer
							if (g_AmBotCommands[g_AmMenus[g_AmIndex].slotnum] == MPBOTCOMMAND_ATTACK) {
								amOpenPickTarget();
							} else if (g_AmMenus[g_AmIndex].allbots == false) {
								gotonextscreen = true;
							}

							if (g_AmMenus[g_AmIndex].slotnum != 4) {
								amApply(g_AmMenus[g_AmIndex].slotnum);
							}
						}
					} else {
						// Weapon or function screen
						if (g_AmMenus[g_AmIndex].slotnum == 4) {
							gotonextscreen = true;
						} else {
							amApply(g_AmMenus[g_AmIndex].slotnum);
						}
					}
				}

				if (gotonextscreen) {
					amChangeScreen(gotonextscreen);

					// If weapon has no functions, skip past function screen
					if (g_AmMenus[g_AmIndex].screenindex == 1) {
						struct weaponfunc *pri = weaponGetFunction(&g_Vars.currentplayer->hands[0].base, FUNC_PRIMARY);
						struct weaponfunc *sec = weaponGetFunction(&g_Vars.currentplayer->hands[0].base, FUNC_SECONDARY);

						if (!pri && !sec) {
							amChangeScreen(gotonextscreen);
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

						amGetSlotDetails(slotnum, &flags, text);

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
#if VERSION >= VERSION_PAL_FINAL
				g_AmMenus[g_AmIndex].alphafrac += g_Vars.lvupdate240freal / 30.0f;
#else
				g_AmMenus[g_AmIndex].alphafrac += g_Vars.lvupdate240f / 30.0f;
#endif
			}

			if (g_AmMenus[g_AmIndex].alphafrac > 1) {
				g_AmMenus[g_AmIndex].alphafrac = 1;
			}

			// Make selection border pulsate
#if VERSION >= VERSION_PAL_FINAL
			g_AmMenus[g_AmIndex].selpulse += g_Vars.lvupdate240freal / 5.0f;
#else
			g_AmMenus[g_AmIndex].selpulse += g_Vars.lvupdate240f / 5.0f;
#endif

			if (g_AmMenus[g_AmIndex].selpulse > 18.849555969238f) {
				g_AmMenus[g_AmIndex].selpulse -= 18.849555969238f;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);
}
#else
GLOBAL_ASM(
glabel amTick
.late_rodata
glabel var7f1a2240nb
.word 0
glabel var7f1a2244nb
.word 0x3e89374c
glabel var7f1a2248nb
.word 0x4196cbe4
glabel var7f1a224cnb
.word 0x4196cbe4
.text
/*  f01ae90:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f01ae94:	3c06800a */ 	lui	$a2,0x800a
/*  f01ae98:	24c6e6c0 */ 	addiu	$a2,$a2,-6464
/*  f01ae9c:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f01aea0:	8cce028c */ 	lw	$t6,0x28c($a2)
/*  f01aea4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f01aea8:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f01aeac:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f01aeb0:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f01aeb4:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f01aeb8:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f01aebc:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f01aec0:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f01aec4:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f01aec8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f01aecc:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f01aed0:	00003825 */ 	or	$a3,$zero,$zero
/*  f01aed4:	11e00003 */ 	beqz	$t7,.NB0f01aee4
/*  f01aed8:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f01aedc:	10000002 */ 	beqz	$zero,.NB0f01aee8
/*  f01aee0:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f01aee4:
/*  f01aee4:	00002825 */ 	or	$a1,$zero,$zero
.NB0f01aee8:
/*  f01aee8:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f01aeec:	00002025 */ 	or	$a0,$zero,$zero
/*  f01aef0:	00001825 */ 	or	$v1,$zero,$zero
/*  f01aef4:	13000003 */ 	beqz	$t8,.NB0f01af04
/*  f01aef8:	00001025 */ 	or	$v0,$zero,$zero
/*  f01aefc:	10000001 */ 	beqz	$zero,.NB0f01af04
/*  f01af00:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f01af04:
/*  f01af04:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f01af08:	3c017f1a */ 	lui	$at,0x7f1a
/*  f01af0c:	13200003 */ 	beqz	$t9,.NB0f01af1c
/*  f01af10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01af14:	10000001 */ 	beqz	$zero,.NB0f01af1c
/*  f01af18:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f01af1c:
/*  f01af1c:	8cc80070 */ 	lw	$t0,0x70($a2)
/*  f01af20:	11000003 */ 	beqz	$t0,.NB0f01af30
/*  f01af24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01af28:	10000001 */ 	beqz	$zero,.NB0f01af30
/*  f01af2c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f01af30:
/*  f01af30:	00434821 */ 	addu	$t1,$v0,$v1
/*  f01af34:	01245021 */ 	addu	$t2,$t1,$a0
/*  f01af38:	01455821 */ 	addu	$t3,$t2,$a1
/*  f01af3c:	19600306 */ 	blez	$t3,.NB0f01bb58
/*  f01af40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01af44:	afa700d8 */ 	sw	$a3,0xd8($sp)
/*  f01af48:	c4342244 */ 	lwc1	$f20,0x2244($at)
.NB0f01af4c:
/*  f01af4c:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f01af50:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f01af54:	3c07800a */ 	lui	$a3,0x800a
/*  f01af58:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f01af5c:	8cec028c */ 	lw	$t4,0x28c($a3)
/*  f01af60:	3c01800a */ 	lui	$at,0x800a
/*  f01af64:	3c0d800a */ 	lui	$t5,0x800a
/*  f01af68:	ac2c66a8 */ 	sw	$t4,0x66a8($at)
/*  f01af6c:	8dad66a8 */ 	lw	$t5,0x66a8($t5)
/*  f01af70:	3c0f800a */ 	lui	$t7,0x800a
/*  f01af74:	2404003c */ 	addiu	$a0,$zero,0x3c
/*  f01af78:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f01af7c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f01af80:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f01af84:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f01af88:	91ef65f0 */ 	lbu	$t7,0x65f0($t7)
/*  f01af8c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01af90:	51e0000f */ 	beqzl	$t7,.NB0f01afd0
/*  f01af94:	8ce80318 */ 	lw	$t0,0x318($a3)
/*  f01af98:	0fc299bf */ 	jal	currentPlayerConsiderToggleGunFunction
/*  f01af9c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f01afa0:	18400009 */ 	blez	$v0,.NB0f01afc8
/*  f01afa4:	3c07800a */ 	lui	$a3,0x800a
/*  f01afa8:	3c18800a */ 	lui	$t8,0x800a
/*  f01afac:	8f1866a8 */ 	lw	$t8,0x66a8($t8)
/*  f01afb0:	3c01800a */ 	lui	$at,0x800a
/*  f01afb4:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f01afb8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f01afbc:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f01afc0:	00390821 */ 	addu	$at,$at,$t9
/*  f01afc4:	a02065f0 */ 	sb	$zero,0x65f0($at)
.NB0f01afc8:
/*  f01afc8:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f01afcc:	8ce80318 */ 	lw	$t0,0x318($a3)
.NB0f01afd0:
/*  f01afd0:	1500000f */ 	bnez	$t0,.NB0f01b010
/*  f01afd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01afd8:	0fc4336c */ 	jal	invGetCount
/*  f01afdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01afe0:	3c09800a */ 	lui	$t1,0x800a
/*  f01afe4:	8d2966a8 */ 	lw	$t1,0x66a8($t1)
/*  f01afe8:	3c0b800a */ 	lui	$t3,0x800a
/*  f01afec:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f01aff0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f01aff4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f01aff8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f01affc:	916b65f1 */ 	lbu	$t3,0x65f1($t3)
/*  f01b000:	104b0003 */ 	beq	$v0,$t3,.NB0f01b010
/*  f01b004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b008:	0fc3ec1f */ 	jal	amAssignWeaponSlots
/*  f01b00c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b010:
/*  f01b010:	3c07800a */ 	lui	$a3,0x800a
/*  f01b014:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f01b018:	8cec0284 */ 	lw	$t4,0x284($a3)
/*  f01b01c:	918d0250 */ 	lbu	$t5,0x250($t4)
/*  f01b020:	11a00237 */ 	beqz	$t5,.NB0f01b900
/*  f01b024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b028:	8cee0288 */ 	lw	$t6,0x288($a3)
/*  f01b02c:	0000f025 */ 	or	$s8,$zero,$zero
/*  f01b030:	0fc53380 */ 	jal	optionsGetControlMode
/*  f01b034:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f01b038:	3c0f800a */ 	lui	$t7,0x800a
/*  f01b03c:	8defe948 */ 	lw	$t7,-0x16b8($t7)
/*  f01b040:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f01b044:	0fc5338e */ 	jal	optionsGetContpadNum1
/*  f01b048:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f01b04c:	0c0055bf */ 	jal	joyGetNumSamples
/*  f01b050:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f01b054:	1840022a */ 	blez	$v0,.NB0f01b900
/*  f01b058:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f01b05c:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.NB0f01b060:
/*  f01b060:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b064:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b068:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f01b06c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b070:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b074:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f01b078:	0c0055ca */ 	jal	joyGetStickXOnSample
/*  f01b07c:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f01b080:	0002b600 */ 	sll	$s6,$v0,0x18
/*  f01b084:	0016c603 */ 	sra	$t8,$s6,0x18
/*  f01b088:	0300b025 */ 	or	$s6,$t8,$zero
/*  f01b08c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b090:	0c0055f9 */ 	jal	joyGetStickYOnSample
/*  f01b094:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b098:	0002be00 */ 	sll	$s7,$v0,0x18
/*  f01b09c:	0017ce03 */ 	sra	$t9,$s7,0x18
/*  f01b0a0:	0320b825 */ 	or	$s7,$t9,$zero
/*  f01b0a4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b0a8:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b0ac:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f01b0b0:	3406ffff */ 	dli	$a2,0xffff
/*  f01b0b4:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f01b0b8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b0bc:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b0c0:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f01b0c4:	3406ffff */ 	dli	$a2,0xffff
/*  f01b0c8:	3c08800a */ 	lui	$t0,0x800a
/*  f01b0cc:	8d0866a8 */ 	lw	$t0,0x66a8($t0)
/*  f01b0d0:	3c0a800a */ 	lui	$t2,0x800a
/*  f01b0d4:	254a65c0 */ 	addiu	$t2,$t2,0x65c0
/*  f01b0d8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b0dc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b0e0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b0e4:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b0e8:	a2000032 */ 	sb	$zero,0x32($s0)
/*  f01b0ec:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b0f0:	8d6be944 */ 	lw	$t3,-0x16bc($t3)
/*  f01b0f4:	a7a200be */ 	sh	$v0,0xbe($sp)
/*  f01b0f8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b0fc:	916c0250 */ 	lbu	$t4,0x250($t3)
/*  f01b100:	02206825 */ 	or	$t5,$s1,$zero
/*  f01b104:	55810006 */ 	bnel	$t4,$at,.NB0f01b120
/*  f01b108:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f01b10c:	31b18000 */ 	andi	$s1,$t5,0x8000
/*  f01b110:	0000b025 */ 	or	$s6,$zero,$zero
/*  f01b114:	0000b825 */ 	or	$s7,$zero,$zero
/*  f01b118:	a7a000be */ 	sh	$zero,0xbe($sp)
/*  f01b11c:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.NB0f01b120:
/*  f01b120:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b124:	32380010 */ 	andi	$t8,$s1,0x10
/*  f01b128:	11e10003 */ 	beq	$t7,$at,.NB0f01b138
/*  f01b12c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01b130:	15e1000c */ 	bne	$t7,$at,.NB0f01b164
/*  f01b134:	322b8000 */ 	andi	$t3,$s1,0x8000
.NB0f01b138:
/*  f01b138:	17000003 */ 	bnez	$t8,.NB0f01b148
/*  f01b13c:	02209025 */ 	or	$s2,$s1,$zero
/*  f01b140:	32390020 */ 	andi	$t9,$s1,0x20
/*  f01b144:	13200002 */ 	beqz	$t9,.NB0f01b150
.NB0f01b148:
/*  f01b148:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01b14c:	afa800b0 */ 	sw	$t0,0xb0($sp)
.NB0f01b150:
/*  f01b150:	32498000 */ 	andi	$t1,$s2,0x8000
/*  f01b154:	1120000d */ 	beqz	$t1,.NB0f01b18c
/*  f01b158:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01b15c:	1000000b */ 	beqz	$zero,.NB0f01b18c
/*  f01b160:	a20a0032 */ 	sb	$t2,0x32($s0)
.NB0f01b164:
/*  f01b164:	11600003 */ 	beqz	$t3,.NB0f01b174
/*  f01b168:	02209025 */ 	or	$s2,$s1,$zero
/*  f01b16c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f01b170:	afac00b0 */ 	sw	$t4,0xb0($sp)
.NB0f01b174:
/*  f01b174:	324d0010 */ 	andi	$t5,$s2,0x10
/*  f01b178:	15a00002 */ 	bnez	$t5,.NB0f01b184
/*  f01b17c:	324e0020 */ 	andi	$t6,$s2,0x20
/*  f01b180:	11c00002 */ 	beqz	$t6,.NB0f01b18c
.NB0f01b184:
/*  f01b184:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b188:	a20f0032 */ 	sb	$t7,0x32($s0)
.NB0f01b18c:
/*  f01b18c:	92020032 */ 	lbu	$v0,0x32($s0)
/*  f01b190:	10400016 */ 	beqz	$v0,.NB0f01b1ec
/*  f01b194:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b198:	82030000 */ 	lb	$v1,0x0($s0)
/*  f01b19c:	28610002 */ 	slti	$at,$v1,0x2
/*  f01b1a0:	14200012 */ 	bnez	$at,.NB0f01b1ec
/*  f01b1a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b1a8:	82180034 */ 	lb	$t8,0x34($s0)
/*  f01b1ac:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f01b1b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b1b4:	1700000d */ 	bnez	$t8,.NB0f01b1ec
/*  f01b1b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b1bc:	a2030034 */ 	sb	$v1,0x34($s0)
/*  f01b1c0:	0fc3ebc8 */ 	jal	amChangeScreen
/*  f01b1c4:	a2190000 */ 	sb	$t9,0x0($s0)
/*  f01b1c8:	3c08800a */ 	lui	$t0,0x800a
/*  f01b1cc:	8d0866a8 */ 	lw	$t0,0x66a8($t0)
/*  f01b1d0:	3c0a800a */ 	lui	$t2,0x800a
/*  f01b1d4:	254a65c0 */ 	addiu	$t2,$t2,0x65c0
/*  f01b1d8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b1dc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b1e0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b1e4:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b1e8:	92020032 */ 	lbu	$v0,0x32($s0)
.NB0f01b1ec:
/*  f01b1ec:	54400009 */ 	bnezl	$v0,.NB0f01b214
/*  f01b1f0:	324b0008 */ 	andi	$t3,$s2,0x8
/*  f01b1f4:	82020034 */ 	lb	$v0,0x34($s0)
/*  f01b1f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b1fc:	50400005 */ 	beqzl	$v0,.NB0f01b214
/*  f01b200:	324b0008 */ 	andi	$t3,$s2,0x8
/*  f01b204:	a2020000 */ 	sb	$v0,0x0($s0)
/*  f01b208:	0fc3ebc8 */ 	jal	amChangeScreen
/*  f01b20c:	a2000034 */ 	sb	$zero,0x34($s0)
/*  f01b210:	324b0008 */ 	andi	$t3,$s2,0x8
.NB0f01b214:
/*  f01b214:	11600002 */ 	beqz	$t3,.NB0f01b220
/*  f01b218:	324c0004 */ 	andi	$t4,$s2,0x4
/*  f01b21c:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f01b220:
/*  f01b220:	11800002 */ 	beqz	$t4,.NB0f01b22c
/*  f01b224:	324d0002 */ 	andi	$t5,$s2,0x2
/*  f01b228:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b22c:
/*  f01b22c:	11a00002 */ 	beqz	$t5,.NB0f01b238
/*  f01b230:	324e0001 */ 	andi	$t6,$s2,0x1
/*  f01b234:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b238:
/*  f01b238:	11c00002 */ 	beqz	$t6,.NB0f01b244
/*  f01b23c:	324f0800 */ 	andi	$t7,$s2,0x800
/*  f01b240:	24150002 */ 	addiu	$s5,$zero,0x2
.NB0f01b244:
/*  f01b244:	11e00002 */ 	beqz	$t7,.NB0f01b250
/*  f01b248:	32580400 */ 	andi	$t8,$s2,0x400
/*  f01b24c:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f01b250:
/*  f01b250:	13000002 */ 	beqz	$t8,.NB0f01b25c
/*  f01b254:	32590200 */ 	andi	$t9,$s2,0x200
/*  f01b258:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b25c:
/*  f01b25c:	13200002 */ 	beqz	$t9,.NB0f01b268
/*  f01b260:	32480100 */ 	andi	$t0,$s2,0x100
/*  f01b264:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b268:
/*  f01b268:	11000002 */ 	beqz	$t0,.NB0f01b274
/*  f01b26c:	8fa900d4 */ 	lw	$t1,0xd4($sp)
/*  f01b270:	24150002 */ 	addiu	$s5,$zero,0x2
.NB0f01b274:
/*  f01b274:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01b278:	11210008 */ 	beq	$t1,$at,.NB0f01b29c
/*  f01b27c:	3c0a800a */ 	lui	$t2,0x800a
/*  f01b280:	24010007 */ 	addiu	$at,$zero,0x7
/*  f01b284:	11210005 */ 	beq	$t1,$at,.NB0f01b29c
/*  f01b288:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01b28c:	11210003 */ 	beq	$t1,$at,.NB0f01b29c
/*  f01b290:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b294:	15210089 */ 	bne	$t1,$at,.NB0f01b4bc
/*  f01b298:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b29c:
/*  f01b29c:	8d4ae948 */ 	lw	$t2,-0x16b8($t2)
/*  f01b2a0:	0fc53395 */ 	jal	optionsGetContpadNum2
/*  f01b2a4:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f01b2a8:	00028600 */ 	sll	$s0,$v0,0x18
/*  f01b2ac:	00022e00 */ 	sll	$a1,$v0,0x18
/*  f01b2b0:	00105e03 */ 	sra	$t3,$s0,0x18
/*  f01b2b4:	00056603 */ 	sra	$t4,$a1,0x18
/*  f01b2b8:	01608025 */ 	or	$s0,$t3,$zero
/*  f01b2bc:	01802825 */ 	or	$a1,$t4,$zero
/*  f01b2c0:	0c0055ca */ 	jal	joyGetStickXOnSample
/*  f01b2c4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b2c8:	00029600 */ 	sll	$s2,$v0,0x18
/*  f01b2cc:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b2d0:	00126e03 */ 	sra	$t5,$s2,0x18
/*  f01b2d4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f01b2d8:	01a09025 */ 	or	$s2,$t5,$zero
/*  f01b2dc:	01c02825 */ 	or	$a1,$t6,$zero
/*  f01b2e0:	0c0055f9 */ 	jal	joyGetStickYOnSample
/*  f01b2e4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b2e8:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f01b2ec:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b2f0:	00137e03 */ 	sra	$t7,$s3,0x18
/*  f01b2f4:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f01b2f8:	01e09825 */ 	or	$s3,$t7,$zero
/*  f01b2fc:	03002825 */ 	or	$a1,$t8,$zero
/*  f01b300:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b304:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f01b308:	3406ffff */ 	dli	$a2,0xffff
/*  f01b30c:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b310:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f01b314:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f01b318:	03202825 */ 	or	$a1,$t9,$zero
/*  f01b31c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b320:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f01b324:	3406ffff */ 	dli	$a2,0xffff
/*  f01b328:	3c08800a */ 	lui	$t0,0x800a
/*  f01b32c:	8d08e944 */ 	lw	$t0,-0x16bc($t0)
/*  f01b330:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b334:	3043ffff */ 	andi	$v1,$v0,0xffff
/*  f01b338:	91090250 */ 	lbu	$t1,0x250($t0)
/*  f01b33c:	02205025 */ 	or	$t2,$s1,$zero
/*  f01b340:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01b344:	15210005 */ 	bne	$t1,$at,.NB0f01b35c
/*  f01b348:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b34c:	31518000 */ 	andi	$s1,$t2,0x8000
/*  f01b350:	00009025 */ 	or	$s2,$zero,$zero
/*  f01b354:	00009825 */ 	or	$s3,$zero,$zero
/*  f01b358:	00001825 */ 	or	$v1,$zero,$zero
.NB0f01b35c:
/*  f01b35c:	322c8000 */ 	andi	$t4,$s1,0x8000
/*  f01b360:	11800002 */ 	beqz	$t4,.NB0f01b36c
/*  f01b364:	02201025 */ 	or	$v0,$s1,$zero
/*  f01b368:	afad00b0 */ 	sw	$t5,0xb0($sp)
.NB0f01b36c:
/*  f01b36c:	306e2000 */ 	andi	$t6,$v1,0x2000
/*  f01b370:	11c00002 */ 	beqz	$t6,.NB0f01b37c
/*  f01b374:	30580008 */ 	andi	$t8,$v0,0x8
/*  f01b378:	afaf00ac */ 	sw	$t7,0xac($sp)
.NB0f01b37c:
/*  f01b37c:	13000002 */ 	beqz	$t8,.NB0f01b388
/*  f01b380:	30590004 */ 	andi	$t9,$v0,0x4
/*  f01b384:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f01b388:
/*  f01b388:	13200002 */ 	beqz	$t9,.NB0f01b394
/*  f01b38c:	30480002 */ 	andi	$t0,$v0,0x2
/*  f01b390:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b394:
/*  f01b394:	11000002 */ 	beqz	$t0,.NB0f01b3a0
/*  f01b398:	30490001 */ 	andi	$t1,$v0,0x1
/*  f01b39c:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b3a0:
/*  f01b3a0:	11200002 */ 	beqz	$t1,.NB0f01b3ac
/*  f01b3a4:	304a0800 */ 	andi	$t2,$v0,0x800
/*  f01b3a8:	24150002 */ 	addiu	$s5,$zero,0x2
.NB0f01b3ac:
/*  f01b3ac:	11400002 */ 	beqz	$t2,.NB0f01b3b8
/*  f01b3b0:	304b0400 */ 	andi	$t3,$v0,0x400
/*  f01b3b4:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f01b3b8:
/*  f01b3b8:	11600002 */ 	beqz	$t3,.NB0f01b3c4
/*  f01b3bc:	304c0200 */ 	andi	$t4,$v0,0x200
/*  f01b3c0:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b3c4:
/*  f01b3c4:	11800002 */ 	beqz	$t4,.NB0f01b3d0
/*  f01b3c8:	304d0100 */ 	andi	$t5,$v0,0x100
/*  f01b3cc:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b3d0:
/*  f01b3d0:	11a00002 */ 	beqz	$t5,.NB0f01b3dc
/*  f01b3d4:	00121e00 */ 	sll	$v1,$s2,0x18
/*  f01b3d8:	24150002 */ 	addiu	$s5,$zero,0x2
.NB0f01b3dc:
/*  f01b3dc:	06410005 */ 	bgez	$s2,.NB0f01b3f4
/*  f01b3e0:	0003c603 */ 	sra	$t8,$v1,0x18
/*  f01b3e4:	00121823 */ 	negu	$v1,$s2
/*  f01b3e8:	00037600 */ 	sll	$t6,$v1,0x18
/*  f01b3ec:	10000002 */ 	beqz	$zero,.NB0f01b3f8
/*  f01b3f0:	000e1e03 */ 	sra	$v1,$t6,0x18
.NB0f01b3f4:
/*  f01b3f4:	03001825 */ 	or	$v1,$t8,$zero
.NB0f01b3f8:
/*  f01b3f8:	06610005 */ 	bgez	$s3,.NB0f01b410
/*  f01b3fc:	28610015 */ 	slti	$at,$v1,0x15
/*  f01b400:	00131023 */ 	negu	$v0,$s3
/*  f01b404:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f01b408:	10000004 */ 	beqz	$zero,.NB0f01b41c
/*  f01b40c:	00191603 */ 	sra	$v0,$t9,0x18
.NB0f01b410:
/*  f01b410:	00131600 */ 	sll	$v0,$s3,0x18
/*  f01b414:	00024e03 */ 	sra	$t1,$v0,0x18
/*  f01b418:	01201025 */ 	or	$v0,$t1,$zero
.NB0f01b41c:
/*  f01b41c:	10200004 */ 	beqz	$at,.NB0f01b430
/*  f01b420:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01b424:	28410015 */ 	slti	$at,$v0,0x15
/*  f01b428:	14200024 */ 	bnez	$at,.NB0f01b4bc
/*  f01b42c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b430:
/*  f01b430:	44822000 */ 	mtc1	$v0,$f4
/*  f01b434:	44833000 */ 	mtc1	$v1,$f6
/*  f01b438:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f01b43c:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f01b440:	46020203 */ 	div.s	$f8,$f0,$f2
/*  f01b444:	4614403c */ 	c.lt.s	$f8,$f20
/*  f01b448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b44c:	45020008 */ 	bc1fl	.NB0f01b470
/*  f01b450:	46001283 */ 	div.s	$f10,$f2,$f0
/*  f01b454:	06410003 */ 	bgez	$s2,.NB0f01b464
/*  f01b458:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b45c:	10000016 */ 	beqz	$zero,.NB0f01b4b8
/*  f01b460:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b464:
/*  f01b464:	10000014 */ 	beqz	$zero,.NB0f01b4b8
/*  f01b468:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b46c:	46001283 */ 	div.s	$f10,$f2,$f0
.NB0f01b470:
/*  f01b470:	4614503c */ 	c.lt.s	$f10,$f20
/*  f01b474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b478:	45000007 */ 	bc1f	.NB0f01b498
/*  f01b47c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b480:	06610003 */ 	bgez	$s3,.NB0f01b490
/*  f01b484:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b488:	1000000b */ 	beqz	$zero,.NB0f01b4b8
/*  f01b48c:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b490:
/*  f01b490:	10000009 */ 	beqz	$zero,.NB0f01b4b8
/*  f01b494:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f01b498:
/*  f01b498:	06410003 */ 	bgez	$s2,.NB0f01b4a8
/*  f01b49c:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b4a0:	10000001 */ 	beqz	$zero,.NB0f01b4a8
/*  f01b4a4:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b4a8:
/*  f01b4a8:	06610003 */ 	bgez	$s3,.NB0f01b4b8
/*  f01b4ac:	0000a025 */ 	or	$s4,$zero,$zero
/*  f01b4b0:	10000001 */ 	beqz	$zero,.NB0f01b4b8
/*  f01b4b4:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b4b8:
/*  f01b4b8:	afaa00b8 */ 	sw	$t2,0xb8($sp)
.NB0f01b4bc:
/*  f01b4bc:	3c04800a */ 	lui	$a0,0x800a
/*  f01b4c0:	06c10005 */ 	bgez	$s6,.NB0f01b4d8
/*  f01b4c4:	8c84e944 */ 	lw	$a0,-0x16bc($a0)
/*  f01b4c8:	00161823 */ 	negu	$v1,$s6
/*  f01b4cc:	00035e00 */ 	sll	$t3,$v1,0x18
/*  f01b4d0:	10000004 */ 	beqz	$zero,.NB0f01b4e4
/*  f01b4d4:	000b1e03 */ 	sra	$v1,$t3,0x18
.NB0f01b4d8:
/*  f01b4d8:	00161e00 */ 	sll	$v1,$s6,0x18
/*  f01b4dc:	00036e03 */ 	sra	$t5,$v1,0x18
/*  f01b4e0:	01a01825 */ 	or	$v1,$t5,$zero
.NB0f01b4e4:
/*  f01b4e4:	06e10005 */ 	bgez	$s7,.NB0f01b4fc
/*  f01b4e8:	28610015 */ 	slti	$at,$v1,0x15
/*  f01b4ec:	00171023 */ 	negu	$v0,$s7
/*  f01b4f0:	00027600 */ 	sll	$t6,$v0,0x18
/*  f01b4f4:	10000004 */ 	beqz	$zero,.NB0f01b508
/*  f01b4f8:	000e1603 */ 	sra	$v0,$t6,0x18
.NB0f01b4fc:
/*  f01b4fc:	00171600 */ 	sll	$v0,$s7,0x18
/*  f01b500:	0002c603 */ 	sra	$t8,$v0,0x18
/*  f01b504:	03001025 */ 	or	$v0,$t8,$zero
.NB0f01b508:
/*  f01b508:	10200004 */ 	beqz	$at,.NB0f01b51c
/*  f01b50c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f01b510:	28410015 */ 	slti	$at,$v0,0x15
/*  f01b514:	54200026 */ 	bnezl	$at,.NB0f01b5b0
/*  f01b518:	8c8800d8 */ 	lw	$t0,0xd8($a0)
.NB0f01b51c:
/*  f01b51c:	44828000 */ 	mtc1	$v0,$f16
/*  f01b520:	44839000 */ 	mtc1	$v1,$f18
/*  f01b524:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01b528:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f01b52c:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f01b530:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f01b534:	46020103 */ 	div.s	$f4,$f0,$f2
/*  f01b538:	4614203c */ 	c.lt.s	$f4,$f20
/*  f01b53c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b540:	45020008 */ 	bc1fl	.NB0f01b564
/*  f01b544:	46001183 */ 	div.s	$f6,$f2,$f0
/*  f01b548:	06c10003 */ 	bgez	$s6,.NB0f01b558
/*  f01b54c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b550:	10000016 */ 	beqz	$zero,.NB0f01b5ac
/*  f01b554:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b558:
/*  f01b558:	10000014 */ 	beqz	$zero,.NB0f01b5ac
/*  f01b55c:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b560:	46001183 */ 	div.s	$f6,$f2,$f0
.NB0f01b564:
/*  f01b564:	4614303c */ 	c.lt.s	$f6,$f20
/*  f01b568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b56c:	45000007 */ 	bc1f	.NB0f01b58c
/*  f01b570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b574:	06e10003 */ 	bgez	$s7,.NB0f01b584
/*  f01b578:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b57c:	1000000b */ 	beqz	$zero,.NB0f01b5ac
/*  f01b580:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b584:
/*  f01b584:	10000009 */ 	beqz	$zero,.NB0f01b5ac
/*  f01b588:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f01b58c:
/*  f01b58c:	06c10003 */ 	bgez	$s6,.NB0f01b59c
/*  f01b590:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b594:	10000001 */ 	beqz	$zero,.NB0f01b59c
/*  f01b598:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f01b59c:
/*  f01b59c:	06e10003 */ 	bgez	$s7,.NB0f01b5ac
/*  f01b5a0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f01b5a4:	10000001 */ 	beqz	$zero,.NB0f01b5ac
/*  f01b5a8:	24140002 */ 	addiu	$s4,$zero,0x2
.NB0f01b5ac:
/*  f01b5ac:	8c8800d8 */ 	lw	$t0,0xd8($a0)
.NB0f01b5b0:
/*  f01b5b0:	51000003 */ 	beqzl	$t0,.NB0f01b5c0
/*  f01b5b4:	8fa900b0 */ 	lw	$t1,0xb0($sp)
/*  f01b5b8:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f01b5bc:	8fa900b0 */ 	lw	$t1,0xb0($sp)
.NB0f01b5c0:
/*  f01b5c0:	97ae00be */ 	lhu	$t6,0xbe($sp)
/*  f01b5c4:	15200016 */ 	bnez	$t1,.NB0f01b620
/*  f01b5c8:	31cf2000 */ 	andi	$t7,$t6,0x2000
/*  f01b5cc:	908a0250 */ 	lbu	$t2,0x250($a0)
/*  f01b5d0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b5d4:	1541000e */ 	bne	$t2,$at,.NB0f01b610
/*  f01b5d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b5dc:	8d6b3af0 */ 	lw	$t3,0x3af0($t3)
/*  f01b5e0:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b5e4:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f01b5e8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f01b5ec:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f01b5f0:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f01b5f4:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f01b5f8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f01b5fc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f01b600:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f01b604:	8dad2c48 */ 	lw	$t5,0x2c48($t5)
/*  f01b608:	15a00005 */ 	bnez	$t5,.NB0f01b620
/*  f01b60c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b610:
/*  f01b610:	0fc3ecfa */ 	jal	amClose
/*  f01b614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b618:	100000b9 */ 	beqz	$zero,.NB0f01b900
/*  f01b61c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b620:
/*  f01b620:	11e00002 */ 	beqz	$t7,.NB0f01b62c
/*  f01b624:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f01b628:	afb800ac */ 	sw	$t8,0xac($sp)
.NB0f01b62c:
/*  f01b62c:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f01b630:	3c08800a */ 	lui	$t0,0x800a
/*  f01b634:	5320003f */ 	beqzl	$t9,.NB0f01b734
/*  f01b638:	83aa00c7 */ 	lb	$t2,0xc7($sp)
/*  f01b63c:	8d0866a8 */ 	lw	$t0,0x66a8($t0)
/*  f01b640:	3c0a800a */ 	lui	$t2,0x800a
/*  f01b644:	254a65c0 */ 	addiu	$t2,$t2,0x65c0
/*  f01b648:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b64c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b650:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b654:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b658:	820b0000 */ 	lb	$t3,0x0($s0)
/*  f01b65c:	3c0c800a */ 	lui	$t4,0x800a
/*  f01b660:	29610002 */ 	slti	$at,$t3,0x2
/*  f01b664:	5420002a */ 	bnezl	$at,.NB0f01b710
/*  f01b668:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b66c:	8d8ceb34 */ 	lw	$t4,-0x14cc($t4)
/*  f01b670:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b674:	51800010 */ 	beqzl	$t4,.NB0f01b6b8
/*  f01b678:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f01b67c:	81ae27ab */ 	lb	$t6,0x27ab($t5)
/*  f01b680:	05c3000d */ 	bgezl	$t6,.NB0f01b6b8
/*  f01b684:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f01b688:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b68c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b690:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b694:	14810003 */ 	bne	$a0,$at,.NB0f01b6a4
/*  f01b698:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b69c:	10000024 */ 	beqz	$zero,.NB0f01b730
/*  f01b6a0:	a3af00c7 */ 	sb	$t7,0xc7($sp)
.NB0f01b6a4:
/*  f01b6a4:	0fc3e8df */ 	jal	amApply
/*  f01b6a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b6ac:	10000021 */ 	beqz	$zero,.NB0f01b734
/*  f01b6b0:	83aa00c7 */ 	lb	$t2,0xc7($sp)
/*  f01b6b4:	9202000e */ 	lbu	$v0,0xe($s0)
.NB0f01b6b8:
/*  f01b6b8:	3c18800b */ 	lui	$t8,0x800b
/*  f01b6bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01b6c0:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f01b6c4:	93181428 */ 	lbu	$t8,0x1428($t8)
/*  f01b6c8:	57010006 */ 	bnel	$t8,$at,.NB0f01b6e4
/*  f01b6cc:	92190032 */ 	lbu	$t9,0x32($s0)
/*  f01b6d0:	0fc3e6f4 */ 	jal	amOpenPickTarget
/*  f01b6d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b6d8:	10000016 */ 	beqz	$zero,.NB0f01b734
/*  f01b6dc:	83aa00c7 */ 	lb	$t2,0xc7($sp)
/*  f01b6e0:	92190032 */ 	lbu	$t9,0x32($s0)
.NB0f01b6e4:
/*  f01b6e4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01b6e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f01b6ec:	17200010 */ 	bnez	$t9,.NB0f01b730
/*  f01b6f0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b6f4:	1041000e */ 	beq	$v0,$at,.NB0f01b730
/*  f01b6f8:	a3a800c7 */ 	sb	$t0,0xc7($sp)
/*  f01b6fc:	0fc3e8df */ 	jal	amApply
/*  f01b700:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b704:	1000000b */ 	beqz	$zero,.NB0f01b734
/*  f01b708:	83aa00c7 */ 	lb	$t2,0xc7($sp)
/*  f01b70c:	9204000e */ 	lbu	$a0,0xe($s0)
.NB0f01b710:
/*  f01b710:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b714:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f01b718:	14810003 */ 	bne	$a0,$at,.NB0f01b728
/*  f01b71c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b720:	10000003 */ 	beqz	$zero,.NB0f01b730
/*  f01b724:	a3a900c7 */ 	sb	$t1,0xc7($sp)
.NB0f01b728:
/*  f01b728:	0fc3e8df */ 	jal	amApply
/*  f01b72c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b730:
/*  f01b730:	83aa00c7 */ 	lb	$t2,0xc7($sp)
.NB0f01b734:
/*  f01b734:	1140001f */ 	beqz	$t2,.NB0f01b7b4
/*  f01b738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b73c:	0fc3ebc8 */ 	jal	amChangeScreen
/*  f01b740:	01402025 */ 	or	$a0,$t2,$zero
/*  f01b744:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b748:	8d6b66a8 */ 	lw	$t3,0x66a8($t3)
/*  f01b74c:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b750:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01b754:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f01b758:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f01b75c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f01b760:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f01b764:	81ad65c0 */ 	lb	$t5,0x65c0($t5)
/*  f01b768:	3c04800a */ 	lui	$a0,0x800a
/*  f01b76c:	15a10011 */ 	bne	$t5,$at,.NB0f01b7b4
/*  f01b770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b774:	8c84e944 */ 	lw	$a0,-0x16bc($a0)
/*  f01b778:	00002825 */ 	or	$a1,$zero,$zero
/*  f01b77c:	0fc2bb86 */ 	jal	weaponGetFunction
/*  f01b780:	24840638 */ 	addiu	$a0,$a0,0x638
/*  f01b784:	3c04800a */ 	lui	$a0,0x800a
/*  f01b788:	8c84e944 */ 	lw	$a0,-0x16bc($a0)
/*  f01b78c:	00408025 */ 	or	$s0,$v0,$zero
/*  f01b790:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f01b794:	0fc2bb86 */ 	jal	weaponGetFunction
/*  f01b798:	24840638 */ 	addiu	$a0,$a0,0x638
/*  f01b79c:	16000005 */ 	bnez	$s0,.NB0f01b7b4
/*  f01b7a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b7a4:	14400003 */ 	bnez	$v0,.NB0f01b7b4
/*  f01b7a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b7ac:	0fc3ebc8 */ 	jal	amChangeScreen
/*  f01b7b0:	83a400c7 */ 	lb	$a0,0xc7($sp)
.NB0f01b7b4:
/*  f01b7b4:	3c0e800a */ 	lui	$t6,0x800a
/*  f01b7b8:	8dcee944 */ 	lw	$t6,-0x16bc($t6)
/*  f01b7bc:	0014c080 */ 	sll	$t8,$s4,0x2
/*  f01b7c0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b7c4:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f01b7c8:	0314c023 */ 	subu	$t8,$t8,$s4
/*  f01b7cc:	02b89021 */ 	addu	$s2,$s5,$t8
/*  f01b7d0:	11e10046 */ 	beq	$t7,$at,.NB0f01b8ec
/*  f01b7d4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b7d8:	16410011 */ 	bne	$s2,$at,.NB0f01b820
/*  f01b7dc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f01b7e0:	3c19800a */ 	lui	$t9,0x800a
/*  f01b7e4:	8f3966a8 */ 	lw	$t9,0x66a8($t9)
/*  f01b7e8:	3c09800a */ 	lui	$t1,0x800a
/*  f01b7ec:	252965c0 */ 	addiu	$t1,$t1,0x65c0
/*  f01b7f0:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f01b7f4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f01b7f8:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f01b7fc:	01098021 */ 	addu	$s0,$t0,$t1
/*  f01b800:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f01b804:	1c400004 */ 	bgtz	$v0,.NB0f01b818
/*  f01b808:	244affff */ 	addiu	$t2,$v0,-1
/*  f01b80c:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f01b810:	10000036 */ 	beqz	$zero,.NB0f01b8ec
/*  f01b814:	a212000e */ 	sb	$s2,0xe($s0)
.NB0f01b818:
/*  f01b818:	10000034 */ 	beqz	$zero,.NB0f01b8ec
/*  f01b81c:	ae0a0014 */ 	sw	$t2,0x14($s0)
.NB0f01b820:
/*  f01b820:	02402025 */ 	or	$a0,$s2,$zero
/*  f01b824:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f01b828:	0fc3e9b3 */ 	jal	amGetSlotDetails
/*  f01b82c:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f01b830:	3c057f1a */ 	lui	$a1,0x7f1a
/*  f01b834:	24a52240 */ 	addiu	$a1,$a1,0x2240
/*  f01b838:	0c004eb1 */ 	jal	strcmp
/*  f01b83c:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f01b840:	14400002 */ 	bnez	$v0,.NB0f01b84c
/*  f01b844:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b848:	00008825 */ 	or	$s1,$zero,$zero
.NB0f01b84c:
/*  f01b84c:	8d6b66a8 */ 	lw	$t3,0x66a8($t3)
/*  f01b850:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b854:	25ad65c0 */ 	addiu	$t5,$t5,0x65c0
/*  f01b858:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f01b85c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f01b860:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f01b864:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f01b868:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b86c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b870:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f01b874:	10810019 */ 	beq	$a0,$at,.NB0f01b8dc
/*  f01b878:	2408000f */ 	addiu	$t0,$zero,0xf
/*  f01b87c:	15c00017 */ 	bnez	$t6,.NB0f01b8dc
/*  f01b880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b884:	10800007 */ 	beqz	$a0,.NB0f01b8a4
/*  f01b888:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b88c:	10810005 */ 	beq	$a0,$at,.NB0f01b8a4
/*  f01b890:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01b894:	10810003 */ 	beq	$a0,$at,.NB0f01b8a4
/*  f01b898:	24010008 */ 	addiu	$at,$zero,0x8
/*  f01b89c:	1481000f */ 	bne	$a0,$at,.NB0f01b8dc
/*  f01b8a0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f01b8a4:
/*  f01b8a4:	920f000f */ 	lbu	$t7,0xf($s0)
/*  f01b8a8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f01b8ac:	524f0005 */ 	beql	$s2,$t7,.NB0f01b8c4
/*  f01b8b0:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f01b8b4:	ae180010 */ 	sw	$t8,0x10($s0)
/*  f01b8b8:	a212000f */ 	sb	$s2,0xf($s0)
/*  f01b8bc:	00008825 */ 	or	$s1,$zero,$zero
/*  f01b8c0:	8e020010 */ 	lw	$v0,0x10($s0)
.NB0f01b8c4:
/*  f01b8c4:	18400005 */ 	blez	$v0,.NB0f01b8dc
/*  f01b8c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b8cc:	12200003 */ 	beqz	$s1,.NB0f01b8dc
/*  f01b8d0:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f01b8d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f01b8d8:	ae190010 */ 	sw	$t9,0x10($s0)
.NB0f01b8dc:
/*  f01b8dc:	52200004 */ 	beqzl	$s1,.NB0f01b8f0
/*  f01b8e0:	8fa900cc */ 	lw	$t1,0xcc($sp)
/*  f01b8e4:	ae080014 */ 	sw	$t0,0x14($s0)
/*  f01b8e8:	a212000e */ 	sb	$s2,0xe($s0)
.NB0f01b8ec:
/*  f01b8ec:	8fa900cc */ 	lw	$t1,0xcc($sp)
.NB0f01b8f0:
/*  f01b8f0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f01b8f4:	03c9082a */ 	slt	$at,$s8,$t1
/*  f01b8f8:	5420fdd9 */ 	bnezl	$at,.NB0f01b060
/*  f01b8fc:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.NB0f01b900:
/*  f01b900:	3c07800a */ 	lui	$a3,0x800a
/*  f01b904:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f01b908:	8cea0284 */ 	lw	$t2,0x284($a3)
/*  f01b90c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b910:	3c07800a */ 	lui	$a3,0x800a
/*  f01b914:	914b0250 */ 	lbu	$t3,0x250($t2)
/*  f01b918:	00002825 */ 	or	$a1,$zero,$zero
/*  f01b91c:	3c0c800a */ 	lui	$t4,0x800a
/*  f01b920:	1161006e */ 	beq	$t3,$at,.NB0f01badc
/*  f01b924:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f01b928:	8d8c66a8 */ 	lw	$t4,0x66a8($t4)
/*  f01b92c:	3c0e800a */ 	lui	$t6,0x800a
/*  f01b930:	25ce65c0 */ 	addiu	$t6,$t6,0x65c0
/*  f01b934:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f01b938:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01b93c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f01b940:	01ae8021 */ 	addu	$s0,$t5,$t6
/*  f01b944:	8603000a */ 	lh	$v1,0xa($s0)
/*  f01b948:	2401ff85 */ 	addiu	$at,$zero,-123
/*  f01b94c:	50610026 */ 	beql	$v1,$at,.NB0f01b9e8
/*  f01b950:	86020004 */ 	lh	$v0,0x4($s0)
/*  f01b954:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f01b958:	8604000c */ 	lh	$a0,0xc($s0)
/*  f01b95c:	86080008 */ 	lh	$t0,0x8($s0)
/*  f01b960:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f01b964:	07010003 */ 	bgez	$t8,.NB0f01b974
/*  f01b968:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f01b96c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f01b970:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f01b974:
/*  f01b974:	a6190006 */ 	sh	$t9,0x6($s0)
/*  f01b978:	860b0006 */ 	lh	$t3,0x6($s0)
/*  f01b97c:	00884821 */ 	addu	$t1,$a0,$t0
/*  f01b980:	05210003 */ 	bgez	$t1,.NB0f01b990
/*  f01b984:	00095043 */ 	sra	$t2,$t1,0x1
/*  f01b988:	25210001 */ 	addiu	$at,$t1,0x1
/*  f01b98c:	00015043 */ 	sra	$t2,$at,0x1
.NB0f01b990:
/*  f01b990:	01631023 */ 	subu	$v0,$t3,$v1
/*  f01b994:	00026400 */ 	sll	$t4,$v0,0x10
/*  f01b998:	000c6c03 */ 	sra	$t5,$t4,0x10
/*  f01b99c:	29a10002 */ 	slti	$at,$t5,0x2
/*  f01b9a0:	10200006 */ 	beqz	$at,.NB0f01b9bc
/*  f01b9a4:	a60a0008 */ 	sh	$t2,0x8($s0)
/*  f01b9a8:	29a1ffff */ 	slti	$at,$t5,-1
/*  f01b9ac:	54200004 */ 	bnezl	$at,.NB0f01b9c0
/*  f01b9b0:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f01b9b4:	a6030006 */ 	sh	$v1,0x6($s0)
/*  f01b9b8:	8604000c */ 	lh	$a0,0xc($s0)
.NB0f01b9bc:
/*  f01b9bc:	860e0008 */ 	lh	$t6,0x8($s0)
.NB0f01b9c0:
/*  f01b9c0:	01c41023 */ 	subu	$v0,$t6,$a0
/*  f01b9c4:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f01b9c8:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f01b9cc:	2b010002 */ 	slti	$at,$t8,0x2
/*  f01b9d0:	10200004 */ 	beqz	$at,.NB0f01b9e4
/*  f01b9d4:	2b01ffff */ 	slti	$at,$t8,-1
/*  f01b9d8:	54200003 */ 	bnezl	$at,.NB0f01b9e8
/*  f01b9dc:	86020004 */ 	lh	$v0,0x4($s0)
/*  f01b9e0:	a6040008 */ 	sh	$a0,0x8($s0)
.NB0f01b9e4:
/*  f01b9e4:	86020004 */ 	lh	$v0,0x4($s0)
.NB0f01b9e8:
/*  f01b9e8:	86090002 */ 	lh	$t1,0x2($s0)
/*  f01b9ec:	24420005 */ 	addiu	$v0,$v0,0x5
/*  f01b9f0:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f01b9f4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f01b9f8:	00194403 */ 	sra	$t0,$t9,0x10
/*  f01b9fc:	01495023 */ 	subu	$t2,$t2,$t1
/*  f01ba00:	01485821 */ 	addu	$t3,$t2,$t0
/*  f01ba04:	01001025 */ 	or	$v0,$t0,$zero
/*  f01ba08:	05610003 */ 	bgez	$t3,.NB0f01ba18
/*  f01ba0c:	000b6083 */ 	sra	$t4,$t3,0x2
/*  f01ba10:	25610003 */ 	addiu	$at,$t3,0x3
/*  f01ba14:	00016083 */ 	sra	$t4,$at,0x2
.NB0f01ba18:
/*  f01ba18:	a60c0002 */ 	sh	$t4,0x2($s0)
/*  f01ba1c:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f01ba20:	01a21823 */ 	subu	$v1,$t5,$v0
/*  f01ba24:	00037400 */ 	sll	$t6,$v1,0x10
/*  f01ba28:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f01ba2c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f01ba30:	10200004 */ 	beqz	$at,.NB0f01ba44
/*  f01ba34:	29e1ffff */ 	slti	$at,$t7,-1
/*  f01ba38:	54200003 */ 	bnezl	$at,.NB0f01ba48
/*  f01ba3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f01ba40:	a6020002 */ 	sh	$v0,0x2($s0)
.NB0f01ba44:
/*  f01ba44:	3c013f80 */ 	lui	$at,0x3f80
.NB0f01ba48:
/*  f01ba48:	44816000 */ 	mtc1	$at,$f12
/*  f01ba4c:	c6000018 */ 	lwc1	$f0,0x18($s0)
/*  f01ba50:	3c01800a */ 	lui	$at,0x800a
/*  f01ba54:	460c003c */ 	c.lt.s	$f0,$f12
/*  f01ba58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba5c:	45000009 */ 	bc1f	.NB0f01ba84
/*  f01ba60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba64:	c428e704 */ 	lwc1	$f8,-0x18fc($at)
/*  f01ba68:	3c0141f0 */ 	lui	$at,0x41f0
/*  f01ba6c:	44815000 */ 	mtc1	$at,$f10
/*  f01ba70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba74:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f01ba78:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f01ba7c:	e6120018 */ 	swc1	$f18,0x18($s0)
/*  f01ba80:	c6000018 */ 	lwc1	$f0,0x18($s0)
.NB0f01ba84:
/*  f01ba84:	3c01800a */ 	lui	$at,0x800a
/*  f01ba88:	4600603c */ 	c.lt.s	$f12,$f0
/*  f01ba8c:	c422e704 */ 	lwc1	$f2,-0x18fc($at)
/*  f01ba90:	3c0140a0 */ 	lui	$at,0x40a0
/*  f01ba94:	44813000 */ 	mtc1	$at,$f6
/*  f01ba98:	45000002 */ 	bc1f	.NB0f01baa4
/*  f01ba9c:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f01baa0:	e60c0018 */ 	swc1	$f12,0x18($s0)
.NB0f01baa4:
/*  f01baa4:	c604001c */ 	lwc1	$f4,0x1c($s0)
/*  f01baa8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f01baac:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f01bab0:	e60a001c */ 	swc1	$f10,0x1c($s0)
/*  f01bab4:	c4302248 */ 	lwc1	$f16,0x2248($at)
/*  f01bab8:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*  f01babc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f01bac0:	4600803c */ 	c.lt.s	$f16,$f0
/*  f01bac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bac8:	45020005 */ 	bc1fl	.NB0f01bae0
/*  f01bacc:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*  f01bad0:	c432224c */ 	lwc1	$f18,0x224c($at)
/*  f01bad4:	46120181 */ 	sub.s	$f6,$f0,$f18
/*  f01bad8:	e606001c */ 	swc1	$f6,0x1c($s0)
.NB0f01badc:
/*  f01badc:	8cf8006c */ 	lw	$t8,0x6c($a3)
.NB0f01bae0:
/*  f01bae0:	8fa600d8 */ 	lw	$a2,0xd8($sp)
/*  f01bae4:	3c08800a */ 	lui	$t0,0x800a
/*  f01bae8:	13000003 */ 	beqz	$t8,.NB0f01baf8
/*  f01baec:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f01baf0:	10000001 */ 	beqz	$zero,.NB0f01baf8
/*  f01baf4:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f01baf8:
/*  f01baf8:	8cf90068 */ 	lw	$t9,0x68($a3)
/*  f01bafc:	3c09800a */ 	lui	$t1,0x800a
/*  f01bb00:	00002025 */ 	or	$a0,$zero,$zero
/*  f01bb04:	13200003 */ 	beqz	$t9,.NB0f01bb14
/*  f01bb08:	00001825 */ 	or	$v1,$zero,$zero
/*  f01bb0c:	10000001 */ 	beqz	$zero,.NB0f01bb14
/*  f01bb10:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f01bb14:
/*  f01bb14:	8d08e724 */ 	lw	$t0,-0x18dc($t0)
/*  f01bb18:	00001025 */ 	or	$v0,$zero,$zero
/*  f01bb1c:	11000003 */ 	beqz	$t0,.NB0f01bb2c
/*  f01bb20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bb24:	10000001 */ 	beqz	$zero,.NB0f01bb2c
/*  f01bb28:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f01bb2c:
/*  f01bb2c:	8d29e730 */ 	lw	$t1,-0x18d0($t1)
/*  f01bb30:	11200003 */ 	beqz	$t1,.NB0f01bb40
/*  f01bb34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bb38:	10000001 */ 	beqz	$zero,.NB0f01bb40
/*  f01bb3c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f01bb40:
/*  f01bb40:	00435021 */ 	addu	$t2,$v0,$v1
/*  f01bb44:	01445821 */ 	addu	$t3,$t2,$a0
/*  f01bb48:	01656021 */ 	addu	$t4,$t3,$a1
/*  f01bb4c:	00cc082a */ 	slt	$at,$a2,$t4
/*  f01bb50:	1420fcfe */ 	bnez	$at,.NB0f01af4c
/*  f01bb54:	afa600d8 */ 	sw	$a2,0xd8($sp)
.NB0f01bb58:
/*  f01bb58:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f01bb5c:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f01bb60:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f01bb64:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f01bb68:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f01bb6c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f01bb70:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f01bb74:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f01bb78:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f01bb7c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f01bb80:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f01bb84:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f01bb88:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f01bb8c:	03e00008 */ 	jr	$ra
/*  f01bb90:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);
#endif
