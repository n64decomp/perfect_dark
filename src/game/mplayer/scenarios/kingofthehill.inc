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

s32 menuhandlerMpHillTime(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_Vars.mphilltime;
		break;
	case MENUOP_SET:
		g_Vars.mphilltime = (u8)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, langGet(L_MPWEAPONS_023), data->slider.value + 10); // "%ds/Point"
		break;
	}

	return 0;
}

struct menuitem g_KohOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_233,  MPOPTION_KOH_HILLONRADAR, menuhandlerMpCheckboxOption }, // "Hill on Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_234,  MPOPTION_KOH_MOBILEHILL,  menuhandlerMpCheckboxOption }, // "Mobile Hill"
	{ MENUITEMTYPE_SLIDER,     0, 0x00020000, L_MPMENU_235,  0x0000006e,               menuhandlerMpHillTime       }, // "Time"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,    0x00000000,               NULL                        },
};

struct menudialogdef g_KohOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_219, // "Hill Options"
	g_KohOptionsMenuItems,
	mpOptionsMenuDialog,
	MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

void kohReadSave(struct savebuffer *buffer)
{
	g_Vars.mphilltime = savebufferReadBits(buffer, 8);
}

void kohWriteSave(struct savebuffer *buffer)
{
	savebufferOr(buffer, g_Vars.mphilltime, 8);
}

void kohInit(void)
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

	for (i = 0; i < 9; i++) {
		g_ScenarioData.koh.hillpads[i] = -1;
	}
}

void kohInitProps(void)
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

	padUnpack(pad_id, PADFIELD_POS | PADFIELD_ROOM, &pad);
	g_ScenarioData.koh.hillrooms[0] = pad.room;
	g_ScenarioData.koh.hillrooms[1] = -1;
	g_ScenarioData.koh.hillpos.x = pad.pos.x;
	g_ScenarioData.koh.hillpos.y = pad.pos.y;
	g_ScenarioData.koh.hillpos.z = pad.pos.z;
	g_ScenarioData.koh.hillpos.y = cd0002a36c(&g_ScenarioData.koh.hillpos, &g_ScenarioData.koh.hillrooms[0], 0, 0);
	g_ScenarioData.koh.movehill = false;
	roomSetLighting(g_ScenarioData.koh.hillrooms[0], LIGHTOP_5, 0, 0, 0);
}

#if VERSION >= 99
GLOBAL_ASM(
glabel kohTick
/*  f18239c:	27bdfe78 */ 	addiu	$sp,$sp,-392
/*  f1823a0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f1823a4:	3c13800b */ 	lui	$s3,0x800b
/*  f1823a8:	2673cb40 */ 	addiu	$s3,$s3,-13504
/*  f1823ac:	866e000a */ 	lh	$t6,0xa($s3)
/*  f1823b0:	2401ffff */ 	li	$at,-1
/*  f1823b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1823b8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f1823bc:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1823c0:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1823c4:	11c10252 */ 	beq	$t6,$at,.JF0f182d10
/*  f1823c8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1823cc:	866f0008 */ 	lh	$t7,0x8($s3)
/*  f1823d0:	00003825 */ 	move	$a3,$zero
/*  f1823d4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1823d8:	11e00058 */ 	beqz	$t7,.JF0f18253c
/*  f1823dc:	00000000 */ 	nop
/*  f1823e0:	44811000 */ 	mtc1	$at,$f2
/*  f1823e4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1823e8:	c42c9888 */ 	lwc1	$f12,-0x6778($at)
/*  f1823ec:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f1823f0:	2418ffff */ 	li	$t8,-1
/*  f1823f4:	a6780004 */ 	sh	$t8,0x4($s3)
/*  f1823f8:	4600603e */ 	c.le.s	$f12,$f0
/*  f1823fc:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182400:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f182404:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182408:	45000047 */ 	bc1f	.JF0f182528
/*  f18240c:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f182410:	c6640034 */ 	lwc1	$f4,0x34($s3)
/*  f182414:	4604603e */ 	c.le.s	$f12,$f4
/*  f182418:	00000000 */ 	nop
/*  f18241c:	45000042 */ 	bc1f	.JF0f182528
/*  f182420:	00000000 */ 	nop
/*  f182424:	c6660038 */ 	lwc1	$f6,0x38($s3)
/*  f182428:	00002825 */ 	move	$a1,$zero
/*  f18242c:	00003025 */ 	move	$a2,$zero
/*  f182430:	4606603e */ 	c.le.s	$f12,$f6
/*  f182434:	00003825 */ 	move	$a3,$zero
/*  f182438:	4500003b */ 	bc1f	.JF0f182528
/*  f18243c:	00000000 */ 	nop
/*  f182440:	8664000e */ 	lh	$a0,0xe($s3)
/*  f182444:	0fc00b2e */ 	jal	0xf002cb8
/*  f182448:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18244c:	8679000c */ 	lh	$t9,0xc($s3)
/*  f182450:	00002025 */ 	move	$a0,$zero
/*  f182454:	2b210002 */ 	slti	$at,$t9,0x2
/*  f182458:	54200013 */ 	bnezl	$at,.JF0f1824a8
/*  f18245c:	a660000a */ 	sh	$zero,0xa($s3)
/*  f182460:	8670000a */ 	lh	$s0,0xa($s3)
.JF0f182464:
/*  f182464:	0c004b60 */ 	jal	0x12d80
/*  f182468:	00000000 */ 	nop
/*  f18246c:	8668000c */ 	lh	$t0,0xc($s3)
/*  f182470:	0048001b */ 	divu	$zero,$v0,$t0
/*  f182474:	00004810 */ 	mfhi	$t1
/*  f182478:	a669000a */ 	sh	$t1,0xa($s3)
/*  f18247c:	8663000a */ 	lh	$v1,0xa($s3)
/*  f182480:	15000002 */ 	bnez	$t0,.JF0f18248c
/*  f182484:	00000000 */ 	nop
/*  f182488:	0007000d */ 	break	0x7
.JF0f18248c:
/*  f18248c:	1203fff5 */ 	beq	$s0,$v1,.JF0f182464
/*  f182490:	00000000 */ 	nop
/*  f182494:	00035040 */ 	sll	$t2,$v1,0x1
/*  f182498:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f18249c:	10000002 */ 	b	.JF0f1824a8
/*  f1824a0:	85640012 */ 	lh	$a0,0x12($t3)
/*  f1824a4:	a660000a */ 	sh	$zero,0xa($s3)
.JF0f1824a8:
/*  f1824a8:	24050042 */ 	li	$a1,0x42
/*  f1824ac:	0fc45798 */ 	jal	0xf115e60
/*  f1824b0:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f1824b4:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f1824b8:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f1824bc:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f1824c0:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f1824c4:	240dffff */ 	li	$t5,-1
/*  f1824c8:	3c04800b */ 	lui	$a0,0x800b
/*  f1824cc:	3c05800b */ 	lui	$a1,0x800b
/*  f1824d0:	a66d0010 */ 	sh	$t5,0x10($s3)
/*  f1824d4:	24a5cb4e */ 	addiu	$a1,$a1,-13490
/*  f1824d8:	2484cb64 */ 	addiu	$a0,$a0,-13468
/*  f1824dc:	00003025 */ 	move	$a2,$zero
/*  f1824e0:	00003825 */ 	move	$a3,$zero
/*  f1824e4:	a66c000e */ 	sh	$t4,0xe($s3)
/*  f1824e8:	e6680024 */ 	swc1	$f8,0x24($s3)
/*  f1824ec:	e66a0028 */ 	swc1	$f10,0x28($s3)
/*  f1824f0:	0c00a79f */ 	jal	0x29e7c
/*  f1824f4:	e672002c */ 	swc1	$f18,0x2c($s3)
/*  f1824f8:	e6600028 */ 	swc1	$f0,0x28($s3)
/*  f1824fc:	8664000e */ 	lh	$a0,0xe($s3)
/*  f182500:	24050005 */ 	li	$a1,0x5
/*  f182504:	00003025 */ 	move	$a2,$zero
/*  f182508:	00003825 */ 	move	$a3,$zero
/*  f18250c:	0fc00b2e */ 	jal	0xf002cb8
/*  f182510:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f182514:	240effff */ 	li	$t6,-1
/*  f182518:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f18251c:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182520:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f182524:	c6600030 */ 	lwc1	$f0,0x30($s3)
.JF0f182528:
/*  f182528:	3c14800a */ 	lui	$s4,0x800a
/*  f18252c:	2694a630 */ 	addiu	$s4,$s4,-22992
/*  f182530:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f182534:	1000019b */ 	b	.JF0f182ba4
/*  f182538:	c6700038 */ 	lwc1	$f16,0x38($s3)
.JF0f18253c:
/*  f18253c:	3c14800a */ 	lui	$s4,0x800a
/*  f182540:	2694a630 */ 	addiu	$s4,$s4,-22992
/*  f182544:	8e83033c */ 	lw	$v1,0x33c($s4)
/*  f182548:	00003025 */ 	move	$a2,$zero
/*  f18254c:	24120003 */ 	li	$s2,0x3
/*  f182550:	1060001e */ 	beqz	$v1,.JF0f1825cc
/*  f182554:	24100006 */ 	li	$s0,0x6
/*  f182558:	90620000 */ 	lbu	$v0,0x0($v1)
.JF0f18255c:
/*  f18255c:	52020004 */ 	beql	$s0,$v0,.JF0f182570
/*  f182560:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f182564:	56420017 */ 	bnel	$s2,$v0,.JF0f1825c4
/*  f182568:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f18256c:	846f0028 */ 	lh	$t7,0x28($v1)
.JF0f182570:
/*  f182570:	8678000e */ 	lh	$t8,0xe($s3)
/*  f182574:	00008825 */ 	move	$s1,$zero
/*  f182578:	15f80002 */ 	bne	$t7,$t8,.JF0f182584
/*  f18257c:	00000000 */ 	nop
/*  f182580:	24110001 */ 	li	$s1,0x1
.JF0f182584:
/*  f182584:	5220000f */ 	beqzl	$s1,.JF0f1825c4
/*  f182588:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f18258c:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f182590:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f182594:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f182598:	0fc0eb32 */ 	jal	0xf03acc8
/*  f18259c:	afa30074 */ 	sw	$v1,0x74($sp)
/*  f1825a0:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f1825a4:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f1825a8:	14400005 */ 	bnez	$v0,.JF0f1825c0
/*  f1825ac:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f1825b0:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f1825b4:	03b94021 */ 	addu	$t0,$sp,$t9
/*  f1825b8:	ad030078 */ 	sw	$v1,0x78($t0)
/*  f1825bc:	24c60001 */ 	addiu	$a2,$a2,0x1
.JF0f1825c0:
/*  f1825c0:	8c630020 */ 	lw	$v1,0x20($v1)
.JF0f1825c4:
/*  f1825c4:	5460ffe5 */ 	bnezl	$v1,.JF0f18255c
/*  f1825c8:	90620000 */ 	lbu	$v0,0x0($v1)
.JF0f1825cc:
/*  f1825cc:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f1825d0:	27a3011c */ 	addiu	$v1,$sp,0x11c
.JF0f1825d4:
/*  f1825d4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1825d8:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1825dc:	1420fffd */ 	bnez	$at,.JF0f1825d4
/*  f1825e0:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f1825e4:	00008025 */ 	move	$s0,$zero
/*  f1825e8:	18c00017 */ 	blez	$a2,.JF0f182648
/*  f1825ec:	00009025 */ 	move	$s2,$zero
/*  f1825f0:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f1825f4:	27b100fc */ 	addiu	$s1,$sp,0xfc
.JF0f1825f8:
/*  f1825f8:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f1825fc:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f182600:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f182604:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f182608:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f18260c:	0fc63cb2 */ 	jal	0xf18f2c8
/*  f182610:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f182614:	00025080 */ 	sll	$t2,$v0,0x2
/*  f182618:	022a2021 */ 	addu	$a0,$s1,$t2
/*  f18261c:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f182620:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f182624:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f182628:	15600004 */ 	bnez	$t3,.JF0f18263c
/*  f18262c:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f182630:	240c0001 */ 	li	$t4,0x1
/*  f182634:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f182638:	ac8c0000 */ 	sw	$t4,0x0($a0)
.JF0f18263c:
/*  f18263c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182640:	1606ffed */ 	bne	$s0,$a2,.JF0f1825f8
/*  f182644:	24630004 */ 	addiu	$v1,$v1,0x4
.JF0f182648:
/*  f182648:	16400005 */ 	bnez	$s2,.JF0f182660
/*  f18264c:	24010001 */ 	li	$at,0x1
/*  f182650:	240dffff */ 	li	$t5,-1
/*  f182654:	a66d0004 */ 	sh	$t5,0x4($s3)
/*  f182658:	10000125 */ 	b	.JF0f182af0
/*  f18265c:	a6600006 */ 	sh	$zero,0x6($s3)
.JF0f182660:
/*  f182660:	1641000b */ 	bne	$s2,$at,.JF0f182690
/*  f182664:	00008025 */ 	move	$s0,$zero
/*  f182668:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f18266c:	24030008 */ 	li	$v1,0x8
.JF0f182670:
/*  f182670:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f182674:	55c0003d */ 	bnezl	$t6,.JF0f18276c
/*  f182678:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f18267c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182680:	1603fffb */ 	bne	$s0,$v1,.JF0f182670
/*  f182684:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182688:	10000038 */ 	b	.JF0f18276c
/*  f18268c:	866a0004 */ 	lh	$t2,0x4($s3)
.JF0f182690:
/*  f182690:	00008825 */ 	move	$s1,$zero
/*  f182694:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182698:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f18269c:	8c430000 */ 	lw	$v1,0x0($v0)
.JF0f1826a0:
/*  f1826a0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1826a4:	0223082a */ 	slt	$at,$s1,$v1
/*  f1826a8:	50200003 */ 	beqzl	$at,.JF0f1826b8
/*  f1826ac:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1826b0:	00608825 */ 	move	$s1,$v1
/*  f1826b4:	0044082b */ 	sltu	$at,$v0,$a0
.JF0f1826b8:
/*  f1826b8:	5420fff9 */ 	bnezl	$at,.JF0f1826a0
/*  f1826bc:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1826c0:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f1826c4:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f1826c8:	8c4f0000 */ 	lw	$t7,0x0($v0)
.JF0f1826cc:
/*  f1826cc:	522f0003 */ 	beql	$s1,$t7,.JF0f1826dc
/*  f1826d0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1826d4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f1826d8:	24420004 */ 	addiu	$v0,$v0,0x4
.JF0f1826dc:
/*  f1826dc:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1826e0:	5420fffa */ 	bnezl	$at,.JF0f1826cc
/*  f1826e4:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f1826e8:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f1826ec:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f1826f0:	8c580000 */ 	lw	$t8,0x0($v0)
.JF0f1826f4:
/*  f1826f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1826f8:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1826fc:	13000002 */ 	beqz	$t8,.JF0f182708
/*  f182700:	00000000 */ 	nop
/*  f182704:	24e70001 */ 	addiu	$a3,$a3,0x1
.JF0f182708:
/*  f182708:	5420fffa */ 	bnezl	$at,.JF0f1826f4
/*  f18270c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f182710:	28e10002 */ 	slti	$at,$a3,0x2
/*  f182714:	14200003 */ 	bnez	$at,.JF0f182724
/*  f182718:	00008025 */ 	move	$s0,$zero
/*  f18271c:	10000002 */ 	b	.JF0f182728
/*  f182720:	24070001 */ 	li	$a3,0x1
.JF0f182724:
/*  f182724:	00003825 */ 	move	$a3,$zero
.JF0f182728:
/*  f182728:	27a200fc */ 	addiu	$v0,$sp,0xfc
.JF0f18272c:
/*  f18272c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f182730:	53200005 */ 	beqzl	$t9,.JF0f182748
/*  f182734:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182738:	86680004 */ 	lh	$t0,0x4($s3)
/*  f18273c:	52080006 */ 	beql	$s0,$t0,.JF0f182758
/*  f182740:	24030008 */ 	li	$v1,0x8
/*  f182744:	26100001 */ 	addiu	$s0,$s0,0x1
.JF0f182748:
/*  f182748:	2a010008 */ 	slti	$at,$s0,0x8
/*  f18274c:	1420fff7 */ 	bnez	$at,.JF0f18272c
/*  f182750:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182754:	24030008 */ 	li	$v1,0x8
.JF0f182758:
/*  f182758:	16030003 */ 	bne	$s0,$v1,.JF0f182768
/*  f18275c:	2409ffff */ 	li	$t1,-1
/*  f182760:	a6690004 */ 	sh	$t1,0x4($s3)
/*  f182764:	2410ffff */ 	li	$s0,-1
.JF0f182768:
/*  f182768:	866a0004 */ 	lh	$t2,0x4($s3)
.JF0f18276c:
/*  f18276c:	3c048009 */ 	lui	$a0,0x8009
/*  f182770:	240505b9 */ 	li	$a1,0x5b9
/*  f182774:	120a0075 */ 	beq	$s0,$t2,.JF0f18294c
/*  f182778:	00003025 */ 	move	$a2,$zero
/*  f18277c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f182780:	44812000 */ 	mtc1	$at,$f4
/*  f182784:	240bffff */ 	li	$t3,-1
/*  f182788:	240cffff */ 	li	$t4,-1
/*  f18278c:	240dffff */ 	li	$t5,-1
/*  f182790:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f182794:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f182798:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f18279c:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f1827a0:	2407ffff */ 	li	$a3,-1
/*  f1827a4:	00008825 */ 	move	$s1,$zero
/*  f1827a8:	0c004230 */ 	jal	0x108c0
/*  f1827ac:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f1827b0:	a6700004 */ 	sh	$s0,0x4($s3)
/*  f1827b4:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f1827b8:	0fc5baa5 */ 	jal	0xf16ea94
/*  f1827bc:	24045417 */ 	li	$a0,0x5417
/*  f1827c0:	00107080 */ 	sll	$t6,$s0,0x2
/*  f1827c4:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f1827c8:	3c0f800b */ 	lui	$t7,0x800b
/*  f1827cc:	25efd5e0 */ 	addiu	$t7,$t7,-10784
/*  f1827d0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1827d4:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f1827d8:	00002825 */ 	move	$a1,$zero
/*  f1827dc:	0fc60110 */ 	jal	0xf180440
/*  f1827e0:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f1827e4:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f1827e8:	02002025 */ 	move	$a0,$s0
/*  f1827ec:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f1827f0:	0c004d95 */ 	jal	0x13654
/*  f1827f4:	00403025 */ 	move	$a2,$v0
/*  f1827f8:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f1827fc:	8e92028c */ 	lw	$s2,0x28c($s4)
/*  f182800:	00002025 */ 	move	$a0,$zero
/*  f182804:	13000003 */ 	beqz	$t8,.JF0f182814
/*  f182808:	00001825 */ 	move	$v1,$zero
/*  f18280c:	10000001 */ 	b	.JF0f182814
/*  f182810:	24040001 */ 	li	$a0,0x1
.JF0f182814:
/*  f182814:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182818:	00003825 */ 	move	$a3,$zero
/*  f18281c:	00001025 */ 	move	$v0,$zero
/*  f182820:	13200003 */ 	beqz	$t9,.JF0f182830
/*  f182824:	00000000 */ 	nop
/*  f182828:	10000001 */ 	b	.JF0f182830
/*  f18282c:	24030001 */ 	li	$v1,0x1
.JF0f182830:
/*  f182830:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182834:	11000003 */ 	beqz	$t0,.JF0f182844
/*  f182838:	00000000 */ 	nop
/*  f18283c:	10000001 */ 	b	.JF0f182844
/*  f182840:	24070001 */ 	li	$a3,0x1
.JF0f182844:
/*  f182844:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182848:	11200003 */ 	beqz	$t1,.JF0f182858
/*  f18284c:	00000000 */ 	nop
/*  f182850:	10000001 */ 	b	.JF0f182858
/*  f182854:	24020001 */ 	li	$v0,0x1
.JF0f182858:
/*  f182858:	00475021 */ 	addu	$t2,$v0,$a3
/*  f18285c:	01435821 */ 	addu	$t3,$t2,$v1
/*  f182860:	01646021 */ 	addu	$t4,$t3,$a0
/*  f182864:	19800035 */ 	blez	$t4,.JF0f18293c
/*  f182868:	00000000 */ 	nop
.JF0f18286c:
/*  f18286c:	0fc4a34d */ 	jal	0xf128d34
/*  f182870:	02202025 */ 	move	$a0,$s1
/*  f182874:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f182878:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f18287c:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f182880:	0fc63cb2 */ 	jal	0xf18f2c8
/*  f182884:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f182888:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f18288c:	02002025 */ 	move	$a0,$s0
/*  f182890:	24050009 */ 	li	$a1,0x9
/*  f182894:	144f0009 */ 	bne	$v0,$t7,.JF0f1828bc
/*  f182898:	00000000 */ 	nop
/*  f18289c:	0fc5baa5 */ 	jal	0xf16ea94
/*  f1828a0:	24045416 */ 	li	$a0,0x5416
/*  f1828a4:	00402025 */ 	move	$a0,$v0
/*  f1828a8:	24050009 */ 	li	$a1,0x9
/*  f1828ac:	0fc37c3e */ 	jal	0xf0df0f8
/*  f1828b0:	24060021 */ 	li	$a2,0x21
/*  f1828b4:	10000004 */ 	b	.JF0f1828c8
/*  f1828b8:	8e98006c */ 	lw	$t8,0x6c($s4)
.JF0f1828bc:
/*  f1828bc:	0fc37c3e */ 	jal	0xf0df0f8
/*  f1828c0:	24060021 */ 	li	$a2,0x21
/*  f1828c4:	8e98006c */ 	lw	$t8,0x6c($s4)
.JF0f1828c8:
/*  f1828c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1828cc:	00002025 */ 	move	$a0,$zero
/*  f1828d0:	13000003 */ 	beqz	$t8,.JF0f1828e0
/*  f1828d4:	00001825 */ 	move	$v1,$zero
/*  f1828d8:	10000001 */ 	b	.JF0f1828e0
/*  f1828dc:	24040001 */ 	li	$a0,0x1
.JF0f1828e0:
/*  f1828e0:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f1828e4:	00003825 */ 	move	$a3,$zero
/*  f1828e8:	00001025 */ 	move	$v0,$zero
/*  f1828ec:	13200003 */ 	beqz	$t9,.JF0f1828fc
/*  f1828f0:	00000000 */ 	nop
/*  f1828f4:	10000001 */ 	b	.JF0f1828fc
/*  f1828f8:	24030001 */ 	li	$v1,0x1
.JF0f1828fc:
/*  f1828fc:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182900:	11000003 */ 	beqz	$t0,.JF0f182910
/*  f182904:	00000000 */ 	nop
/*  f182908:	10000001 */ 	b	.JF0f182910
/*  f18290c:	24070001 */ 	li	$a3,0x1
.JF0f182910:
/*  f182910:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182914:	11200003 */ 	beqz	$t1,.JF0f182924
/*  f182918:	00000000 */ 	nop
/*  f18291c:	10000001 */ 	b	.JF0f182924
/*  f182920:	24020001 */ 	li	$v0,0x1
.JF0f182924:
/*  f182924:	00475021 */ 	addu	$t2,$v0,$a3
/*  f182928:	01435821 */ 	addu	$t3,$t2,$v1
/*  f18292c:	01646021 */ 	addu	$t4,$t3,$a0
/*  f182930:	022c082a */ 	slt	$at,$s1,$t4
/*  f182934:	1420ffcd */ 	bnez	$at,.JF0f18286c
/*  f182938:	00000000 */ 	nop
.JF0f18293c:
/*  f18293c:	0fc4a34d */ 	jal	0xf128d34
/*  f182940:	02402025 */ 	move	$a0,$s2
/*  f182944:	1000006b */ 	b	.JF0f182af4
/*  f182948:	86630004 */ 	lh	$v1,0x4($s3)
.JF0f18294c:
/*  f18294c:	54e00069 */ 	bnezl	$a3,.JF0f182af4
/*  f182950:	86630004 */ 	lh	$v1,0x4($s3)
/*  f182954:	866d0006 */ 	lh	$t5,0x6($s3)
/*  f182958:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f18295c:	8e990484 */ 	lw	$t9,0x484($s4)
/*  f182960:	3c048009 */ 	lui	$a0,0x8009
/*  f182964:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f182968:	a66f0006 */ 	sh	$t7,0x6($s3)
/*  f18296c:	00194100 */ 	sll	$t0,$t9,0x4
/*  f182970:	86780006 */ 	lh	$t8,0x6($s3)
/*  f182974:	01194023 */ 	subu	$t0,$t0,$t9
/*  f182978:	00084100 */ 	sll	$t0,$t0,0x4
/*  f18297c:	25090960 */ 	addiu	$t1,$t0,0x960
/*  f182980:	0309082a */ 	slt	$at,$t8,$t1
/*  f182984:	1420005a */ 	bnez	$at,.JF0f182af0
/*  f182988:	240505b8 */ 	li	$a1,0x5b8
/*  f18298c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f182990:	44813000 */ 	mtc1	$at,$f6
/*  f182994:	240affff */ 	li	$t2,-1
/*  f182998:	240bffff */ 	li	$t3,-1
/*  f18299c:	240cffff */ 	li	$t4,-1
/*  f1829a0:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1829a4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1829a8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1829ac:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f1829b0:	00003025 */ 	move	$a2,$zero
/*  f1829b4:	2407ffff */ 	li	$a3,-1
/*  f1829b8:	00009025 */ 	move	$s2,$zero
/*  f1829bc:	0c004230 */ 	jal	0x108c0
/*  f1829c0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f1829c4:	3c03800b */ 	lui	$v1,0x800b
/*  f1829c8:	8c63cf60 */ 	lw	$v1,-0x30a0($v1)
/*  f1829cc:	3c10800b */ 	lui	$s0,0x800b
/*  f1829d0:	2610cf00 */ 	addiu	$s0,$s0,-12544
/*  f1829d4:	1860001e */ 	blez	$v1,.JF0f182a50
/*  f1829d8:	00002825 */ 	move	$a1,$zero
/*  f1829dc:	3c11800b */ 	lui	$s1,0x800b
/*  f1829e0:	2631cf30 */ 	addiu	$s1,$s1,-12496
.JF0f1829e4:
/*  f1829e4:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f1829e8:	91a40125 */ 	lbu	$a0,0x125($t5)
/*  f1829ec:	0fc63cb2 */ 	jal	0xf18f2c8
/*  f1829f0:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f1829f4:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f1829f8:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f1829fc:	144e000c */ 	bne	$v0,$t6,.JF0f182a30
/*  f182a00:	00000000 */ 	nop
/*  f182a04:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f182a08:	8668000e */ 	lh	$t0,0xe($s3)
/*  f182a0c:	0225c021 */ 	addu	$t8,$s1,$a1
/*  f182a10:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f182a14:	84790028 */ 	lh	$t9,0x28($v1)
/*  f182a18:	17280005 */ 	bne	$t9,$t0,.JF0f182a30
/*  f182a1c:	00000000 */ 	nop
/*  f182a20:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f182a24:	8449003e */ 	lh	$t1,0x3e($v0)
/*  f182a28:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f182a2c:	a44a003e */ 	sh	$t2,0x3e($v0)
.JF0f182a30:
/*  f182a30:	3c03800b */ 	lui	$v1,0x800b
/*  f182a34:	8c63cf60 */ 	lw	$v1,-0x30a0($v1)
/*  f182a38:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f182a3c:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f182a40:	0243082a */ 	slt	$at,$s2,$v1
/*  f182a44:	1420ffe7 */ 	bnez	$at,.JF0f1829e4
/*  f182a48:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f182a4c:	00009025 */ 	move	$s2,$zero
.JF0f182a50:
/*  f182a50:	1860001b */ 	blez	$v1,.JF0f182ac0
/*  f182a54:	8e91028c */ 	lw	$s1,0x28c($s4)
/*  f182a58:	3c10800b */ 	lui	$s0,0x800b
/*  f182a5c:	2610cf00 */ 	addiu	$s0,$s0,-12544
/*  f182a60:	8e020000 */ 	lw	$v0,0x0($s0)
.JF0f182a64:
/*  f182a64:	8c4b02d4 */ 	lw	$t3,0x2d4($v0)
/*  f182a68:	1560000e */ 	bnez	$t3,.JF0f182aa4
/*  f182a6c:	00000000 */ 	nop
/*  f182a70:	0fc63cb2 */ 	jal	0xf18f2c8
/*  f182a74:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f182a78:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f182a7c:	144c0009 */ 	bne	$v0,$t4,.JF0f182aa4
/*  f182a80:	00000000 */ 	nop
/*  f182a84:	0fc4a34d */ 	jal	0xf128d34
/*  f182a88:	02402025 */ 	move	$a0,$s2
/*  f182a8c:	0fc5baa5 */ 	jal	0xf16ea94
/*  f182a90:	24045415 */ 	li	$a0,0x5415
/*  f182a94:	00402025 */ 	move	$a0,$v0
/*  f182a98:	24050009 */ 	li	$a1,0x9
/*  f182a9c:	0fc37c3e */ 	jal	0xf0df0f8
/*  f182aa0:	24060021 */ 	li	$a2,0x21
.JF0f182aa4:
/*  f182aa4:	3c0d800b */ 	lui	$t5,0x800b
/*  f182aa8:	8dadcf60 */ 	lw	$t5,-0x30a0($t5)
/*  f182aac:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f182ab0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f182ab4:	024d082a */ 	slt	$at,$s2,$t5
/*  f182ab8:	5420ffea */ 	bnezl	$at,.JF0f182a64
/*  f182abc:	8e020000 */ 	lw	$v0,0x0($s0)
.JF0f182ac0:
/*  f182ac0:	0fc4a34d */ 	jal	0xf128d34
/*  f182ac4:	02202025 */ 	move	$a0,$s1
/*  f182ac8:	240effff */ 	li	$t6,-1
/*  f182acc:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f182ad0:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182ad4:	3c0f800b */ 	lui	$t7,0x800b
/*  f182ad8:	8defd5c4 */ 	lw	$t7,-0x2a3c($t7)
/*  f182adc:	24080001 */ 	li	$t0,0x1
/*  f182ae0:	31f98000 */ 	andi	$t9,$t7,0x8000
/*  f182ae4:	53200003 */ 	beqzl	$t9,.JF0f182af4
/*  f182ae8:	86630004 */ 	lh	$v1,0x4($s3)
/*  f182aec:	a6680008 */ 	sh	$t0,0x8($s3)
.JF0f182af0:
/*  f182af0:	86630004 */ 	lh	$v1,0x4($s3)
.JF0f182af4:
/*  f182af4:	2401ffff */ 	li	$at,-1
/*  f182af8:	3c028009 */ 	lui	$v0,0x8009
/*  f182afc:	1461000c */ 	bne	$v1,$at,.JF0f182b30
/*  f182b00:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f182b04:	3c013f80 */ 	lui	$at,0x3f80
/*  f182b08:	44811000 */ 	mtc1	$at,$f2
/*  f182b0c:	3c013e80 */ 	lui	$at,0x3e80
/*  f182b10:	44817000 */ 	mtc1	$at,$f14
/*  f182b14:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182b18:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f182b1c:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182b20:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182b24:	e7ae0164 */ 	swc1	$f14,0x164($sp)
/*  f182b28:	1000001e */ 	b	.JF0f182ba4
/*  f182b2c:	e7ae015c */ 	swc1	$f14,0x15c($sp)
.JF0f182b30:
/*  f182b30:	00581021 */ 	addu	$v0,$v0,$t8
/*  f182b34:	8c428334 */ 	lw	$v0,-0x7ccc($v0)
/*  f182b38:	3c013b00 */ 	lui	$at,0x3b00
/*  f182b3c:	44811000 */ 	mtc1	$at,$f2
/*  f182b40:	00024e02 */ 	srl	$t1,$v0,0x18
/*  f182b44:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f182b48:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f182b4c:	448b4000 */ 	mtc1	$t3,$f8
/*  f182b50:	00026402 */ 	srl	$t4,$v0,0x10
/*  f182b54:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f182b58:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f182b5c:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f182b60:	448e2000 */ 	mtc1	$t6,$f4
/*  f182b64:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f182b68:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f182b6c:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f182b70:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f182b74:	44885000 */ 	mtc1	$t0,$f10
/*  f182b78:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182b7c:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f182b80:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182b84:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f182b88:	e7b20164 */ 	swc1	$f18,0x164($sp)
/*  f182b8c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f182b90:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f182b94:	00000000 */ 	nop
/*  f182b98:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f182b9c:	e7a80160 */ 	swc1	$f8,0x160($sp)
/*  f182ba0:	e7a4015c */ 	swc1	$f4,0x15c($sp)
.JF0f182ba4:
/*  f182ba4:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f182ba8:	46003032 */ 	c.eq.s	$f6,$f0
/*  f182bac:	00000000 */ 	nop
/*  f182bb0:	4503001c */ 	bc1tl	.JF0f182c24
/*  f182bb4:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f182bb8:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f182bbc:	00001025 */ 	move	$v0,$zero
/*  f182bc0:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182bc4:	58600017 */ 	blezl	$v1,.JF0f182c24
/*  f182bc8:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f182bcc:	c428988c */ 	lwc1	$f8,-0x6774($at)
/*  f182bd0:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182bd4:	c4209890 */ 	lwc1	$f0,-0x6770($at)
/*  f182bd8:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f182bdc:	00000000 */ 	nop
/*  f182be0:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f182be4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182be8:	0043082a */ 	slt	$at,$v0,$v1
/*  f182bec:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182bf0:	5020000a */ 	beqzl	$at,.JF0f182c1c
/*  f182bf4:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182bf8:	46121380 */ 	add.s	$f14,$f2,$f18
.JF0f182bfc:
/*  f182bfc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182c00:	0043082a */ 	slt	$at,$v0,$v1
/*  f182c04:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182c08:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f182c0c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182c10:	5420fffa */ 	bnezl	$at,.JF0f182bfc
/*  f182c14:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182c18:	46121380 */ 	add.s	$f14,$f2,$f18
.JF0f182c1c:
/*  f182c1c:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182c20:	c7a80160 */ 	lwc1	$f8,0x160($sp)
.JF0f182c24:
/*  f182c24:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182c28:	c4209894 */ 	lwc1	$f0,-0x676c($at)
/*  f182c2c:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f182c30:	00000000 */ 	nop
/*  f182c34:	4503001a */ 	bc1tl	.JF0f182ca0
/*  f182c38:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f182c3c:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f182c40:	00001025 */ 	move	$v0,$zero
/*  f182c44:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182c48:	58600015 */ 	blezl	$v1,.JF0f182ca0
/*  f182c4c:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f182c50:	c4269898 */ 	lwc1	$f6,-0x6768($at)
/*  f182c54:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f182c58:	00000000 */ 	nop
/*  f182c5c:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f182c60:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182c64:	0043082a */ 	slt	$at,$v0,$v1
/*  f182c68:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182c6c:	5020000a */ 	beqzl	$at,.JF0f182c98
/*  f182c70:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182c74:	46121380 */ 	add.s	$f14,$f2,$f18
.JF0f182c78:
/*  f182c78:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182c7c:	0043082a */ 	slt	$at,$v0,$v1
/*  f182c80:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f182c84:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f182c88:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182c8c:	5420fffa */ 	bnezl	$at,.JF0f182c78
/*  f182c90:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182c94:	46121380 */ 	add.s	$f14,$f2,$f18
.JF0f182c98:
/*  f182c98:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f182c9c:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
.JF0f182ca0:
/*  f182ca0:	46103032 */ 	c.eq.s	$f6,$f16
/*  f182ca4:	00000000 */ 	nop
/*  f182ca8:	4503001a */ 	bc1tl	.JF0f182d14
/*  f182cac:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f182cb0:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f182cb4:	00001025 */ 	move	$v0,$zero
/*  f182cb8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182cbc:	58600015 */ 	blezl	$v1,.JF0f182d14
/*  f182cc0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f182cc4:	c428989c */ 	lwc1	$f8,-0x6764($at)
/*  f182cc8:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f182ccc:	00000000 */ 	nop
/*  f182cd0:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182cd4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182cd8:	0043082a */ 	slt	$at,$v0,$v1
/*  f182cdc:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182ce0:	5020000a */ 	beqzl	$at,.JF0f182d0c
/*  f182ce4:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182ce8:	46121400 */ 	add.s	$f16,$f2,$f18
.JF0f182cec:
/*  f182cec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182cf0:	0043082a */ 	slt	$at,$v0,$v1
/*  f182cf4:	e6700038 */ 	swc1	$f16,0x38($s3)
/*  f182cf8:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182cfc:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182d00:	5420fffa */ 	bnezl	$at,.JF0f182cec
/*  f182d04:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182d08:	46121400 */ 	add.s	$f16,$f2,$f18
.JF0f182d0c:
/*  f182d0c:	e6700038 */ 	swc1	$f16,0x38($s3)
.JF0f182d10:
/*  f182d10:	8fbf003c */ 	lw	$ra,0x3c($sp)
.JF0f182d14:
/*  f182d14:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f182d18:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f182d1c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f182d20:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f182d24:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f182d28:	03e00008 */ 	jr	$ra
/*  f182d2c:	27bd0188 */ 	addiu	$sp,$sp,0x188
);
#else
/**
 * A match for this function has only been possible by making heavy reuse of
 * variables, but this impacts readability significantly.
 *
 * To make this code readable, constants have been used to map appropriate names
 * to the underlying variable.
 */
void kohTick(void)
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
	s32 teamsinhill[8];
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
			roomSetLighting(g_ScenarioData.koh.hillrooms[0], 0, 0, 0, 0);

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

			padUnpack(padnum, PADFIELD_POS | PADFIELD_ROOM, &pad);

			g_ScenarioData.koh.hillrooms[0] = pad.room;
			g_ScenarioData.koh.hillrooms[1] = -1;

			g_ScenarioData.koh.hillpos.x = pad.pos.x;
			g_ScenarioData.koh.hillpos.y = pad.pos.y;
			g_ScenarioData.koh.hillpos.z = pad.pos.z;

			g_ScenarioData.koh.hillpos.y = cd0002a36c(&g_ScenarioData.koh.hillpos, g_ScenarioData.koh.hillrooms, NULL, NULL);

			roomSetLighting(g_ScenarioData.koh.hillrooms[0], 5, 0, 0, 0);

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

					if (!chrIsDead(chr)) {
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
		for (s0 = 0; s0 < 8; s0++) {
			teamsinhill[s0] = 0;
		}

		for (s0 = 0, numteamsinhill = 0; s0 < numchrsinhill; s0++) {
			chr = chrsinhill[s0]->chr;
			teamindex = radarGetTeamIndex(chr->team);

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
				for (hillteam = 0; hillteam < 8; hillteam++) {
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

				for (s0 = 0; s0 < 8; s0++) {
					if (teamsinhill[s0] > mostchrs) {
						mostchrs = teamsinhill[s0];
					}
				}

				for (s0 = 0; s0 < 8; s0++) {
					if (teamsinhill[s0] != mostchrs) {
						teamsinhill[s0] = false;
					}
				}

				// Count the number of teams who are tied for the most chrs in
				// the hill. Or rather, because the teamsinhill array only
				// contains 0 or 1 values, this is just recounting the number of
				// teams who have presence in the hill.
				for (s0 = 0; s0 < 8; s0++) {
					if (teamsinhill[s0]) {
						dualoccupancy++;
					}
				}

				dualoccupancy = dualoccupancy >= 2 ? true : false;

				// Set the hillteam to whoever was holding it previously
				// so the hill remains the same colour
				for (hillteam = 0; hillteam < 8; hillteam++) {
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
				sndStart(var80095200, SFX_MP_HILLENTERED, 0, -1, -1, -1, -1, -1);

				g_ScenarioData.koh.occupiedteam = hillteam;
				g_ScenarioData.koh.elapsed240 = 0;

				// "%has captured the Hill!"
#if VERSION >= VERSION_JPN_FINAL
				sprintf(text, langGet(L_MPWEAPONS_022), func0f180440jf(g_BossFile.teamnames[hillteam], 0));
#else
				sprintf(text, langGet(L_MPWEAPONS_022), &g_BossFile.teamnames[hillteam]);
#endif

				prevplayernum2 = g_Vars.currentplayernum;

				for (playernum1 = 0; playernum1 < PLAYERCOUNT(); playernum1++) {
					setCurrentPlayerNum(playernum1);

					chr = g_Vars.currentplayer->prop->chr;

#if VERSION >= VERSION_JPN_FINAL
					if (radarGetTeamIndex(chr->team) == g_ScenarioData.koh.occupiedteam) {
						// "We have the Hill!"
						hudmsgCreateWithFlags(langGet(L_MPWEAPONS_021), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
					} else {
						hudmsgCreateWithFlags(text, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
					}
#else
					if (radarGetTeamIndex(chr->team) == g_ScenarioData.koh.occupiedteam) {
						// "We have the Hill!"
						hudmsgCreateWithFlags(langGet(L_MPWEAPONS_021), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else {
						hudmsgCreateWithFlags(text, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					}
#endif
				}

				setCurrentPlayerNum(prevplayernum2);
			} else {
				// A team is remaining in the hill.
				// Only tick the hill timer if they have exclusive occupancy.
				if (!dualoccupancy) {
					g_ScenarioData.koh.elapsed240 += g_Vars.lvupdate240;

					if (g_ScenarioData.koh.elapsed240 >= g_Vars.mphilltime * TICKS(240) + TICKS(2400)) {
						// Scored a point
						sndStart(var80095200, SFX_MP_SCOREPOINT, 0, -1, -1, -1, -1, -1);

						// @bug: There is no check for a chr being dead here.
						// If a player dies in the hill and waits on the
						// "press start" screen while their team mate scores the
						// hill, the dead player will always be awarded a point.
						for (playernum2 = 0; playernum2 < g_MpNumChrs; playernum2++) {
							if (radarGetTeamIndex(g_MpAllChrPtrs[playernum2]->team) == g_ScenarioData.koh.occupiedteam) {
								prop = g_MpAllChrPtrs[playernum2]->prop;

								if (prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
									g_MpAllChrConfigPtrs[playernum2]->numpoints++;
								}
							}
						}

						prevplayernum1 = g_Vars.currentplayernum;

						for (playernum2 = 0; playernum2 < g_MpNumChrs; playernum2++) {
							if (g_MpAllChrPtrs[playernum2]->aibot == NULL
									&& radarGetTeamIndex(g_MpAllChrPtrs[playernum2]->team) == g_ScenarioData.koh.occupiedteam) {
								setCurrentPlayerNum(playernum2);

								// "King of the Hill!"
								hudmsgCreateWithFlags(langGet(L_MPWEAPONS_020), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
							}
						}

						setCurrentPlayerNum(prevplayernum1);

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
#endif

Gfx *kohRenderHud(Gfx *gdl)
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

	if (radarGetTeamIndex(chr->team) == g_ScenarioData.koh.occupiedteam && !g_ScenarioData.koh.movehill) {
		x = viGetViewLeft() + viGetViewWidth() / 2;
		y = viGetViewTop() + 10;

		time240 = g_Vars.mphilltime * TICKS(240) - g_ScenarioData.koh.elapsed240;
		time240 += PAL ? 2199 : 2400;
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

		gdl = func0f153628(gdl);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x -= textwidth / 2;
		textwidth += x;
		textheight += y;

#if VERSION >= VERSION_NTSC_1_0
		gdl = func0f153990(gdl, x, y, textwidth, textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0xa0, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = func0f153858(gdl, &x, &y, &textwidth, &textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0x88, viGetWidth(), viGetHeight(), 0, 0);
#endif
		gdl = func0f153780(gdl);
	}

	return gdl;
}

void kohCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
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

Gfx *kohRadarExtra(Gfx *gdl)
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

		gdl = radarDrawDot(gdl, NULL, &dist, colour, 0, 1);
	}

	return gdl;
}

void kohAddHill(s32 *cmd)
{
	if (g_ScenarioData.koh.hillcount < ARRAYCOUNT(g_ScenarioData.koh.hillpads)) {
		g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillcount] = cmd[1];
		g_ScenarioData.koh.hillcount++;
	}
}

bool kohIsRoomHighlighted(s16 room)
{
	return room == g_ScenarioData.koh.hillrooms[0];
}

void kohHighlightRoom(s16 roomnum, s32 *arg1, s32 *arg2, s32 *arg3)
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
