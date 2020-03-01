#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_097970.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_111600.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/game_16e810.h"
#include "game/game_187770.h"
#include "game/game_19c990.h"
#include "game/game_1a3340.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_13130.h"
#include "lib/lib_1a500.h"
#include "types.h"

const char var7f1b97d0[] = "\n";
const char var7f1b97d4[] = "\n";
const char var7f1b97d8[] = "%dm %2ds\n";
const char var7f1b97e4[] = "%s%s%2.2fs\n";
const char var7f1b97f0[] = "";
const char var7f1b97f4[] = "";
const char var7f1b97f8[] = "%d\n";
const char var7f1b97fc[] = "%d\n";
const char var7f1b9800[] = "%d\n";
const char var7f1b9804[] = "%s%s%.1f%%\n";
const char var7f1b9810[] = "";
const char var7f1b9814[] = "";
const char var7f1b9818[] = "%s";
const char var7f1b981c[] = "%d\n";
const char var7f1b9820[] = "%s";
const char var7f1b9824[] = "%s";
const char var7f1b9828[] = "%d%%\n";
const char var7f1b9830[] = "%d\n";
const char var7f1b9834[] = "%s";
const char var7f1b9838[] = "%dm %ds\n";
const char var7f1b9844[] = "%ds\n";
const char var7f1b984c[] = "%s";
const char var7f1b9850[] = "/%d";
const char var7f1b9854[] = "%d%s\n";
const char var7f1b985c[] = "x1";
const char var7f1b9860[] = "x2";
const char var7f1b9864[] = "y1";
const char var7f1b9868[] = "y2";
const char var7f1b986c[] = "x3";
const char var7f1b9870[] = "x4";
const char var7f1b9874[] = "y3";
const char var7f1b9878[] = "y4";
const char var7f1b987c[] = "%d\n";
const char var7f1b9880[] = "%d\n";
const char var7f1b9884[] = "%d\n";
const char var7f1b9888[] = "%d\n";
const char var7f1b988c[] = "%d\n";
const char var7f1b9890[] = "%d\n";
const char var7f1b9894[] = "%d\n";
const char var7f1b9898[] = "%d\n";
const char var7f1b989c[] = "%d\n";
const char var7f1b98a0[] = "%s\n";
const char var7f1b98a4[] = "%s\n";
const char var7f1b98a8[] = "%s\n";
const char var7f1b98ac[] = "%s\n";
const char var7f1b98b0[] = "%dm %2ds\n";
const char var7f1b98bc[] = "%s%s%2.2fs\n";
const char var7f1b98c8[] = "";
const char var7f1b98cc[] = "";
const char var7f1b98d0[] = "%dm %2ds\n";
const char var7f1b98dc[] = "%s%s%2.2fs\n";
const char var7f1b98e8[] = "";
const char var7f1b98ec[] = "";
const char var7f1b98f0[] = "%s\n";

const u32 var7f1b98f4[] = {0x7f1a34e0};
const u32 var7f1b98f8[] = {0x7f1a34c8};
const u32 var7f1b98fc[] = {0x7f1a34f4};
const u32 var7f1b9900[] = {0x7f1a34d0};
const u32 var7f1b9904[] = {0x7f1a34d8};
const u32 var7f1b9908[] = {0x7f1a34fc};
const u32 var7f1b990c[] = {0x7f1a3584};
const u32 var7f1b9910[] = {0x7f1a3994};
const u32 var7f1b9914[] = {0x7f1a3994};
const u32 var7f1b9918[] = {0x7f1a3994};
const u32 var7f1b991c[] = {0x7f1a3994};
const u32 var7f1b9920[] = {0x7f1a3994};
const u32 var7f1b9924[] = {0x7f1a3994};
const u32 var7f1b9928[] = {0x7f1a3994};
const u32 var7f1b992c[] = {0x7f1a3994};
const u32 var7f1b9930[] = {0x7f1a3994};
const u32 var7f1b9934[] = {0x7f1a3994};
const u32 var7f1b9938[] = {0x7f1a3994};
const u32 var7f1b993c[] = {0x7f1a3598};
const u32 var7f1b9940[] = {0x7f1a34bc};
const u32 var7f1b9944[] = {0x4196cbe4};
const u32 var7f1b9948[] = {0x7f1a5e40};
const u32 var7f1b994c[] = {0x7f1a5ef4};
const u32 var7f1b9950[] = {0x7f1a5e4c};
const u32 var7f1b9954[] = {0x7f1a5f00};
const u32 var7f1b9958[] = {0x7f1a5f1c};
const u32 var7f1b995c[] = {0x7f1a5e9c};
const u32 var7f1b9960[] = {0x7f1a5ee0};
const u32 var7f1b9964[] = {0x3f333333};
const u32 var7f1b9968[] = {0x3f4ccccd};
const u32 var7f1b996c[] = {0x41033333};
const u32 var7f1b9970[] = {0xc0833333};
const u32 var7f1b9974[] = {0x3b80c73b};
const u32 var7f1b9978[] = {0x3c23d70a};
const u32 var7f1b997c[] = {0x7f1a6414};
const u32 var7f1b9980[] = {0x7f1a6478};
const u32 var7f1b9984[] = {0x7f1a6428};
const u32 var7f1b9988[] = {0x7f1a6480};
const u32 var7f1b998c[] = {0x7f1a6488};
const u32 var7f1b9990[] = {0x7f1a6448};
const u32 var7f1b9994[] = {0x7f1a6468};
const u32 var7f1b9998[] = {0x4196cbe4};
const u32 var7f1b999c[] = {0x7f1a6980};
const u32 var7f1b99a0[] = {0x7f1a69dc};
const u32 var7f1b99a4[] = {0x7f1a6994};
const u32 var7f1b99a8[] = {0x7f1a69e4};
const u32 var7f1b99ac[] = {0x7f1a69ec};
const u32 var7f1b99b0[] = {0x7f1a69ac};
const u32 var7f1b99b4[] = {0x7f1a69cc};
const u32 var7f1b99b8[] = {0x7f1a6dc0};
const u32 var7f1b99bc[] = {0x7f1a6e50};
const u32 var7f1b99c0[] = {0x7f1a6dd4};
const u32 var7f1b99c4[] = {0x7f1a6e5c};
const u32 var7f1b99c8[] = {0x7f1a6e78};
const u32 var7f1b99cc[] = {0x7f1a6df4};
const u32 var7f1b99d0[] = {0x7f1a6e3c};
const u32 var7f1b99d4[] = {0x3a83126f};
const u32 var7f1b99d8[] = {0x3c23d70a};
const u32 var7f1b99dc[] = {0x00000000};

GLOBAL_ASM(
glabel menuhandler001a3340
/*  f1a3340:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1a3344:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1a3348:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a334c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1a3350:	10810006 */ 	beq	$a0,$at,.L0f1a336c
/*  f1a3354:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f1a3358:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1a335c:	54810036 */ 	bnel	$a0,$at,.L0f1a3438
/*  f1a3360:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3364:	10000034 */ 	beqz	$zero,.L0f1a3438
/*  f1a3368:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a336c:
/*  f1a336c:	0fc6830c */ 	jal	func0f1a0c30
/*  f1a3370:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3374:	1440002d */ 	bnez	$v0,.L0f1a342c
/*  f1a3378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a337c:	0fc67494 */ 	jal	func0f19d250
/*  f1a3380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3384:	0fc6749a */ 	jal	func0f19d268
/*  f1a3388:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a338c:	3c048009 */ 	lui	$a0,0x8009
/*  f1a3390:	8c84889c */ 	lw	$a0,-0x7764($a0)
/*  f1a3394:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a3398:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f1a339c:	50810004 */ 	beql	$a0,$at,.L0f1a33b0
/*  f1a33a0:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f1a33a4:	0fc447a9 */ 	jal	currentPlayerRemoveWeapon
/*  f1a33a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a33ac:	8fae0018 */ 	lw	$t6,0x18($sp)
.L0f1a33b0:
/*  f1a33b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a33b4:	11c10003 */ 	beq	$t6,$at,.L0f1a33c4
/*  f1a33b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a33bc:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f1a33c0:	01c02025 */ 	or	$a0,$t6,$zero
.L0f1a33c4:
/*  f1a33c4:	0fc44bd8 */ 	jal	currentPlayerSetEquipCurItem
/*  f1a33c8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1a33cc:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f1a33d0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a33d4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f1a33d8:	10450004 */ 	beq	$v0,$a1,.L0f1a33ec
/*  f1a33dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a33e0:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f1a33e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a33e8:	8fa50018 */ 	lw	$a1,0x18($sp)
.L0f1a33ec:
/*  f1a33ec:	3c018009 */ 	lui	$at,0x8009
/*  f1a33f0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f1a33f4:	ac25889c */ 	sw	$a1,-0x7764($at)
/*  f1a33f8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f1a33fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3400:	24040008 */ 	addiu	$a0,$zero,0x8
.L0f1a3404:
/*  f1a3404:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f1a3408:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f1a340c:	a7000d74 */ 	sh	$zero,0xd74($t8)
/*  f1a3410:	8c790284 */ 	lw	$t9,0x284($v1)
/*  f1a3414:	03224021 */ 	addu	$t0,$t9,$v0
/*  f1a3418:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f1a341c:	1444fff9 */ 	bne	$v0,$a0,.L0f1a3404
/*  f1a3420:	a5001518 */ 	sh	$zero,0x1518($t0)
/*  f1a3424:	0fc67a70 */ 	jal	func0f19e9c0
/*  f1a3428:	00a02025 */ 	or	$a0,$a1,$zero
.L0f1a342c:
/*  f1a342c:	0fc3e048 */ 	jal	func0f0f8120
/*  f1a3430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3434:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3438:
/*  f1a3438:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a343c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1a3440:	03e00008 */ 	jr	$ra
/*  f1a3444:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler001a3448(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (func0f1a0c30()) {
			func0f19ecdc(1);
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler001a348c
/*  f1a348c:	248effff */ 	addiu	$t6,$a0,-1
/*  f1a3490:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1a3494:	2dc10014 */ 	sltiu	$at,$t6,0x14
/*  f1a3498:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1a349c:	1020013d */ 	beqz	$at,.L0f1a3994
/*  f1a34a0:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f1a34a4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a34a8:	3c017f1c */ 	lui	$at,%hi(var7f1b98f4)
/*  f1a34ac:	002e0821 */ 	addu	$at,$at,$t6
/*  f1a34b0:	8c2e98f4 */ 	lw	$t6,%lo(var7f1b98f4)($at)
/*  f1a34b4:	01c00008 */ 	jr	$t6
/*  f1a34b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a34bc:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f1a34c0:	10000134 */ 	beqz	$zero,.L0f1a3994
/*  f1a34c4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1a34c8:	10000132 */ 	beqz	$zero,.L0f1a3994
/*  f1a34cc:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f1a34d0:	10000131 */ 	beqz	$zero,.L0f1a3998
/*  f1a34d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a34d8:	1000012e */ 	beqz	$zero,.L0f1a3994
/*  f1a34dc:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f1a34e0:	0fc674b8 */ 	jal	func0f19d2e0
/*  f1a34e4:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f1a34e8:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f1a34ec:	10000129 */ 	beqz	$zero,.L0f1a3994
/*  f1a34f0:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a34f4:	10000128 */ 	beqz	$zero,.L0f1a3998
/*  f1a34f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a34fc:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a3500:	0fc6749a */ 	jal	func0f19d268
/*  f1a3504:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f1a3508:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a350c:	0fc67330 */ 	jal	func0f19ccc0
/*  f1a3510:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3514:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3518:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a351c:	0fc679ea */ 	jal	func0f19e7a8
/*  f1a3520:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f1a3524:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f1a3528:	0fc67497 */ 	jal	func0f19d25c
/*  f1a352c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a3530:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f1a3534:	1300000c */ 	beqz	$t8,.L0f1a3568
/*  f1a3538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a353c:	0fc67330 */ 	jal	func0f19ccc0
/*  f1a3540:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f1a3544:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3548:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a354c:	0fc67570 */ 	jal	func0f19d5c0
/*  f1a3550:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3554:	3c048009 */ 	lui	$a0,%hi(menudialog_frdifficulty)
/*  f1a3558:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a355c:	24848d38 */ 	addiu	$a0,$a0,%lo(menudialog_frdifficulty)
/*  f1a3560:	1000010d */ 	beqz	$zero,.L0f1a3998
/*  f1a3564:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3568:
/*  f1a3568:	0fc67570 */ 	jal	func0f19d5c0
/*  f1a356c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a3570:	3c048009 */ 	lui	$a0,%hi(menudialog_frtraininginfo2)
/*  f1a3574:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a3578:	24848f60 */ 	addiu	$a0,$a0,%lo(menudialog_frtraininginfo2)
/*  f1a357c:	10000106 */ 	beqz	$zero,.L0f1a3998
/*  f1a3580:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3584:	0fc67494 */ 	jal	func0f19d250
/*  f1a3588:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f1a358c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f1a3590:	10000100 */ 	beqz	$zero,.L0f1a3994
/*  f1a3594:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a3598:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f1a359c:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a35a0:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f1a35a4:	8cc40004 */ 	lw	$a0,0x4($a2)
/*  f1a35a8:	0fc6749a */ 	jal	func0f19d268
/*  f1a35ac:	afa80098 */ 	sw	$t0,0x98($sp)
/*  f1a35b0:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f1a35b4:	0fc67330 */ 	jal	func0f19ccc0
/*  f1a35b8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a35bc:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a35c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a35c4:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f1a35c8:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f1a35cc:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f1a35d0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1a35d4:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f1a35d8:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f1a35dc:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f1a35e0:	0fc54d8a */ 	jal	func0f153628
/*  f1a35e4:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f1a35e8:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f1a35ec:	0fc28857 */ 	jal	func0f0a215c
/*  f1a35f0:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f1a35f4:	0c002f02 */ 	jal	func0000bc08
/*  f1a35f8:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f1a35fc:	0c002f06 */ 	jal	func0000bc18
/*  f1a3600:	a7a2003e */ 	sh	$v0,0x3e($sp)
/*  f1a3604:	3c198008 */ 	lui	$t9,0x8008
/*  f1a3608:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1a360c:	8dcefb0c */ 	lw	$t6,-0x4f4($t6)
/*  f1a3610:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f1a3614:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f1a3618:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a361c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a3620:	8d0f000c */ 	lw	$t7,0xc($t0)
/*  f1a3624:	87b8003e */ 	lh	$t8,0x3e($sp)
/*  f1a3628:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a362c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a3630:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a3634:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f1a3638:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f1a363c:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f1a3640:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f1a3644:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a3648:	0fc5580f */ 	jal	func0f15603c
/*  f1a364c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1a3650:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f1a3654:	0fc54de0 */ 	jal	func0f153780
/*  f1a3658:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a365c:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f1a3660:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f1a3664:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a3668:	3c0ee700 */ 	lui	$t6,0xe700
/*  f1a366c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1a3670:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1a3674:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f1a3678:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1a367c:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f1a3680:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f1a3684:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f1a3688:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f1a368c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f1a3690:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f1a3694:	3c18b900 */ 	lui	$t8,0xb900
/*  f1a3698:	37180002 */ 	ori	$t8,$t8,0x2
/*  f1a369c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1a36a0:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a36a4:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1a36a8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1a36ac:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a36b0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a36b4:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f1a36b8:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f1a36bc:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f1a36c0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1a36c4:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f1a36c8:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a36cc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1a36d0:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f1a36d4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a36d8:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a36dc:	240f0c00 */ 	addiu	$t7,$zero,0xc00
/*  f1a36e0:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f1a36e4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f1a36e8:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a36ec:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1a36f0:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f1a36f4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a36f8:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a36fc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a3700:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f1a3704:	3c05800b */ 	lui	$a1,0x800b
/*  f1a3708:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
/*  f1a370c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1a3710:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f1a3714:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a3718:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a371c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a3720:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f1a3724:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1a3728:	00003825 */ 	or	$a3,$zero,$zero
/*  f1a372c:	afa80098 */ 	sw	$t0,0x98($sp)
/*  f1a3730:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1a3734:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f1a3738:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a373c:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f1a3740:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a3744:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f1a3748:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f1a374c:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f1a3750:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f1a3754:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1a3758:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a375c:	3c0ffffc */ 	lui	$t7,0xfffc
/*  f1a3760:	3c0efcff */ 	lui	$t6,0xfcff
/*  f1a3764:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a3768:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a376c:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f1a3770:	35eff279 */ 	ori	$t7,$t7,0xf279
/*  f1a3774:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f1a3778:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f1a377c:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a3780:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1a3784:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f1a3788:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a378c:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a3790:	3c1ffc12 */ 	lui	$ra,0xfc12
/*  f1a3794:	3c098008 */ 	lui	$t1,%hi(var8007fac0)
/*  f1a3798:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a379c:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f1a37a0:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f1a37a4:	2529fac0 */ 	addiu	$t1,$t1,%lo(var8007fac0)
/*  f1a37a8:	37ff9a25 */ 	ori	$ra,$ra,0x9a25
/*  f1a37ac:	00002825 */ 	or	$a1,$zero,$zero
/*  f1a37b0:	00003825 */ 	or	$a3,$zero,$zero
/*  f1a37b4:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f1a37b8:	240cff00 */ 	addiu	$t4,$zero,-256
/*  f1a37bc:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1a37c0:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f1a37c4:
/*  f1a37c4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f1a37c8:	00af082a */ 	slt	$at,$a1,$t7
/*  f1a37cc:	50200013 */ 	beqzl	$at,.L0f1a381c
/*  f1a37d0:	3c069999 */ 	lui	$a2,0x9999
/*  f1a37d4:	50a00008 */ 	beqzl	$a1,.L0f1a37f8
/*  f1a37d8:	3c068844 */ 	lui	$a2,0x8844
/*  f1a37dc:	50aa0009 */ 	beql	$a1,$t2,.L0f1a3804
/*  f1a37e0:	3c069999 */ 	lui	$a2,0x9999
/*  f1a37e4:	50ab000a */ 	beql	$a1,$t3,.L0f1a3810
/*  f1a37e8:	3c06bb99 */ 	lui	$a2,0xbb99
/*  f1a37ec:	1000000d */ 	beqz	$zero,.L0f1a3824
/*  f1a37f0:	8d19000c */ 	lw	$t9,0xc($t0)
/*  f1a37f4:	3c068844 */ 	lui	$a2,0x8844
.L0f1a37f8:
/*  f1a37f8:	10000009 */ 	beqz	$zero,.L0f1a3820
/*  f1a37fc:	34c600ff */ 	ori	$a2,$a2,0xff
/*  f1a3800:	3c069999 */ 	lui	$a2,0x9999
.L0f1a3804:
/*  f1a3804:	10000006 */ 	beqz	$zero,.L0f1a3820
/*  f1a3808:	34c69fff */ 	ori	$a2,$a2,0x9fff
/*  f1a380c:	3c06bb99 */ 	lui	$a2,0xbb99
.L0f1a3810:
/*  f1a3810:	10000003 */ 	beqz	$zero,.L0f1a3820
/*  f1a3814:	34c622ff */ 	ori	$a2,$a2,0x22ff
/*  f1a3818:	3c069999 */ 	lui	$a2,0x9999
.L0f1a381c:
/*  f1a381c:	34c69944 */ 	ori	$a2,$a2,0x9944
.L0f1a3820:
/*  f1a3820:	8d19000c */ 	lw	$t9,0xc($t0)
.L0f1a3824:
/*  f1a3824:	30d800ff */ 	andi	$t8,$a2,0xff
/*  f1a3828:	3c01e400 */ 	lui	$at,0xe400
/*  f1a382c:	332e00ff */ 	andi	$t6,$t9,0xff
/*  f1a3830:	030e0019 */ 	multu	$t8,$t6
/*  f1a3834:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f1a3838:	00ccc024 */ 	and	$t8,$a2,$t4
/*  f1a383c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1a3840:	00007812 */ 	mflo	$t7
/*  f1a3844:	000fca02 */ 	srl	$t9,$t7,0x8
/*  f1a3848:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1a384c:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a3850:	03193025 */ 	or	$a2,$t8,$t9
/*  f1a3854:	adc60004 */ 	sw	$a2,0x4($t6)
/*  f1a3858:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f1a385c:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a3860:	3c0eff37 */ 	lui	$t6,0xff37
/*  f1a3864:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f1a3868:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a386c:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a3870:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f1a3874:	af1f0000 */ 	sw	$ra,0x0($t8)
/*  f1a3878:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f1a387c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f1a3880:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f1a3884:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f1a3888:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1a388c:	03277021 */ 	addu	$t6,$t9,$a3
/*  f1a3890:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f1a3894:	25cf0088 */ 	addiu	$t7,$t6,0x88
/*  f1a3898:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1a389c:	03190019 */ 	multu	$t8,$t9
/*  f1a38a0:	00007012 */ 	mflo	$t6
/*  f1a38a4:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f1a38a8:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f1a38ac:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f1a38b0:	0301c825 */ 	or	$t9,$t8,$at
/*  f1a38b4:	25cf000b */ 	addiu	$t7,$t6,0xb
/*  f1a38b8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1a38bc:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f1a38c0:	032e7825 */ 	or	$t7,$t9,$t6
/*  f1a38c4:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1a38c8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1a38cc:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f1a38d0:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f1a38d4:	272e007d */ 	addiu	$t6,$t9,0x7d
/*  f1a38d8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1a38dc:	01f80019 */ 	multu	$t7,$t8
/*  f1a38e0:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f1a38e4:	24e7000d */ 	addiu	$a3,$a3,0xd
/*  f1a38e8:	0000c812 */ 	mflo	$t9
/*  f1a38ec:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f1a38f0:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f1a38f4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1a38f8:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f1a38fc:	01eec025 */ 	or	$t8,$t7,$t6
/*  f1a3900:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1a3904:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a3908:	24180160 */ 	addiu	$t8,$zero,0x160
/*  f1a390c:	3c0eb400 */ 	lui	$t6,0xb400
/*  f1a3910:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f1a3914:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a3918:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f1a391c:	af380004 */ 	sw	$t8,0x4($t9)
/*  f1a3920:	03201025 */ 	or	$v0,$t9,$zero
/*  f1a3924:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a3928:	3c0eb300 */ 	lui	$t6,0xb300
/*  f1a392c:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f1a3930:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a3934:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f1a3938:	03201825 */ 	or	$v1,$t9,$zero
/*  f1a393c:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f1a3940:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f1a3944:	0338001a */ 	div	$zero,$t9,$t8
/*  f1a3948:	17000002 */ 	bnez	$t8,.L0f1a3954
/*  f1a394c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3950:	0007000d */ 	break	0x7
.L0f1a3954:
/*  f1a3954:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a3958:	17010004 */ 	bne	$t8,$at,.L0f1a396c
/*  f1a395c:	3c018000 */ 	lui	$at,0x8000
/*  f1a3960:	17210002 */ 	bne	$t9,$at,.L0f1a396c
/*  f1a3964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3968:	0006000d */ 	break	0x6
.L0f1a396c:
/*  f1a396c:	00007812 */ 	mflo	$t7
/*  f1a3970:	31eeffff */ 	andi	$t6,$t7,0xffff
/*  f1a3974:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1a3978:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1a397c:	3738fc00 */ 	ori	$t8,$t9,0xfc00
/*  f1a3980:	14a1ff90 */ 	bne	$a1,$at,.L0f1a37c4
/*  f1a3984:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1a3988:	afa60094 */ 	sw	$a2,0x94($sp)
/*  f1a398c:	10000002 */ 	beqz	$zero,.L0f1a3998
/*  f1a3990:	8fa2009c */ 	lw	$v0,0x9c($sp)
.L0f1a3994:
/*  f1a3994:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3998:
/*  f1a3998:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1a399c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f1a39a0:	03e00008 */ 	jr	$ra
/*  f1a39a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog001a39a8
/*  f1a39a8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1a39ac:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a39b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a39b4:	10810008 */ 	beq	$a0,$at,.L0f1a39d8
/*  f1a39b8:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f1a39bc:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a39c0:	10810041 */ 	beq	$a0,$at,.L0f1a3ac8
/*  f1a39c4:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a39c8:	1081001e */ 	beq	$a0,$at,.L0f1a3a44
/*  f1a39cc:	3c188007 */ 	lui	$t8,0x8007
/*  f1a39d0:	10000044 */ 	beqz	$zero,.L0f1a3ae4
/*  f1a39d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a39d8:
/*  f1a39d8:	0fc67494 */ 	jal	func0f19d250
/*  f1a39dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a39e0:	0fc6749a */ 	jal	func0f19d268
/*  f1a39e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a39e8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1a39ec:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1a39f0:	3c01800a */ 	lui	$at,0x800a
/*  f1a39f4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f1a39f8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1a39fc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1a3a00:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1a3a04:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1a3a08:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1a3a0c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1a3a10:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1a3a14:	002f0821 */ 	addu	$at,$at,$t7
/*  f1a3a18:	ac22ee28 */ 	sw	$v0,-0x11d8($at)
/*  f1a3a1c:	0fc41652 */ 	jal	func0f105948
/*  f1a3a20:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3a24:	0fc6830c */ 	jal	func0f1a0c30
/*  f1a3a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3a2c:	5440002d */ 	bnezl	$v0,.L0f1a3ae4
/*  f1a3a30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3a34:	0fc67a40 */ 	jal	func0f19e900
/*  f1a3a38:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1a3a3c:	10000029 */ 	beqz	$zero,.L0f1a3ae4
/*  f1a3a40:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3a44:
/*  f1a3a44:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f1a3a48:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f1a3a4c:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f1a3a50:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f1a3a54:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1a3a58:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1a3a5c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1a3a60:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f1a3a64:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1a3a68:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f1a3a6c:	03281021 */ 	addu	$v0,$t9,$t0
/*  f1a3a70:	8c4304f8 */ 	lw	$v1,0x4f8($v0)
/*  f1a3a74:	5060001b */ 	beqzl	$v1,.L0f1a3ae4
/*  f1a3a78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3a7c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f1a3a80:	3c0b800a */ 	lui	$t3,0x800a
/*  f1a3a84:	54a90017 */ 	bnel	$a1,$t1,.L0f1a3ae4
/*  f1a3a88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3a8c:	8c4a0db4 */ 	lw	$t2,0xdb4($v0)
/*  f1a3a90:	8d6b9fc0 */ 	lw	$t3,-0x6040($t3)
/*  f1a3a94:	3c017f1c */ 	lui	$at,%hi(var7f1b9944)
/*  f1a3a98:	44801000 */ 	mtc1	$zero,$f2
/*  f1a3a9c:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f1a3aa0:	ac4c0db4 */ 	sw	$t4,0xdb4($v0)
/*  f1a3aa4:	c4249944 */ 	lwc1	$f4,%lo(var7f1b9944)($at)
/*  f1a3aa8:	3c018006 */ 	lui	$at,0x8006
/*  f1a3aac:	c4261630 */ 	lwc1	$f6,0x1630($at)
/*  f1a3ab0:	e4420d68 */ 	swc1	$f2,0xd68($v0)
/*  f1a3ab4:	e4420d90 */ 	swc1	$f2,0xd90($v0)
/*  f1a3ab8:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f1a3abc:	e4400d8c */ 	swc1	$f0,0xd8c($v0)
/*  f1a3ac0:	10000007 */ 	beqz	$zero,.L0f1a3ae0
/*  f1a3ac4:	e4400d64 */ 	swc1	$f0,0xd64($v0)
.L0f1a3ac8:
/*  f1a3ac8:	0fc6830c */ 	jal	func0f1a0c30
/*  f1a3acc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3ad0:	54400004 */ 	bnezl	$v0,.L0f1a3ae4
/*  f1a3ad4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3ad8:	0fc67b37 */ 	jal	func0f19ecdc
/*  f1a3adc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1a3ae0:
/*  f1a3ae0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3ae4:
/*  f1a3ae4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1a3ae8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3aec:	03e00008 */ 	jr	$ra
/*  f1a3af0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog001a3af4
/*  f1a3af4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3af8:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a3afc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3b00:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1a3b04:	14810007 */ 	bne	$a0,$at,.L0f1a3b24
/*  f1a3b08:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1a3b0c:	0fc6830c */ 	jal	func0f1a0c30
/*  f1a3b10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3b14:	54400004 */ 	bnezl	$v0,.L0f1a3b28
/*  f1a3b18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3b1c:	0fc67b37 */ 	jal	func0f19ecdc
/*  f1a3b20:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1a3b24:
/*  f1a3b24:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3b28:
/*  f1a3b28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a3b2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3b30:	03e00008 */ 	jr	$ra
/*  f1a3b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3b38:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a3b3c:	3c0e8009 */ 	lui	$t6,%hi(var80088c70)
/*  f1a3b40:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3b44:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1a3b48:	25ce8c70 */ 	addiu	$t6,$t6,%lo(var80088c70)
/*  f1a3b4c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a3b50:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f1a3b54:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1a3b58:	95c10004 */ 	lhu	$at,0x4($t6)
/*  f1a3b5c:	a4410004 */ 	sh	$at,0x4($v0)
/*  f1a3b60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a3b64:	10810009 */ 	beq	$a0,$at,.L0f1a3b8c
/*  f1a3b68:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1a3b6c:	10810013 */ 	beq	$a0,$at,.L0f1a3bbc
/*  f1a3b70:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1a3b74:	10810018 */ 	beq	$a0,$at,.L0f1a3bd8
/*  f1a3b78:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1a3b7c:	1081001d */ 	beq	$a0,$at,.L0f1a3bf4
/*  f1a3b80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3b84:	10000020 */ 	beqz	$zero,.L0f1a3c08
/*  f1a3b88:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3b8c:
/*  f1a3b8c:	0fc67494 */ 	jal	func0f19d250
/*  f1a3b90:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f1a3b94:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3b98:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3b9c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f1a3ba0:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f1a3ba4:	2c610004 */ 	sltiu	$at,$v1,0x4
/*  f1a3ba8:	14200016 */ 	bnez	$at,.L0f1a3c04
/*  f1a3bac:	acc30000 */ 	sw	$v1,0x0($a2)
/*  f1a3bb0:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f1a3bb4:	10000013 */ 	beqz	$zero,.L0f1a3c04
/*  f1a3bb8:	acc80000 */ 	sw	$t0,0x0($a2)
.L0f1a3bbc:
/*  f1a3bbc:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f1a3bc0:	00095040 */ 	sll	$t2,$t1,0x1
/*  f1a3bc4:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f1a3bc8:	0fc5b9f1 */ 	jal	langGet
/*  f1a3bcc:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f1a3bd0:	1000000e */ 	beqz	$zero,.L0f1a3c0c
/*  f1a3bd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3bd8:
/*  f1a3bd8:	0fc67570 */ 	jal	func0f19d5c0
/*  f1a3bdc:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a3be0:	3c048009 */ 	lui	$a0,%hi(menudialog_frtraininginfo2)
/*  f1a3be4:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a3be8:	24848f60 */ 	addiu	$a0,$a0,%lo(menudialog_frtraininginfo2)
/*  f1a3bec:	10000006 */ 	beqz	$zero,.L0f1a3c08
/*  f1a3bf0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3bf4:
/*  f1a3bf4:	0fc6757a */ 	jal	func0f19d5e8
/*  f1a3bf8:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f1a3bfc:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f1a3c00:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f1a3c04:
/*  f1a3c04:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3c08:
/*  f1a3c08:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3c0c:
/*  f1a3c0c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a3c10:	03e00008 */ 	jr	$ra
/*  f1a3c14:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerFrDifficulty
/*  f1a3c18:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3c1c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1a3c20:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3c24:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1a3c28:	10810015 */ 	beq	$a0,$at,.L0f1a3c80
/*  f1a3c2c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1a3c30:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1a3c34:	1081001a */ 	beq	$a0,$at,.L0f1a3ca0
/*  f1a3c38:	24010018 */ 	addiu	$at,$zero,0x18
/*  f1a3c3c:	54810028 */ 	bnel	$a0,$at,.L0f1a3ce0
/*  f1a3c40:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3c44:	0fc67494 */ 	jal	func0f19d250
/*  f1a3c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3c4c:	0fc6749a */ 	jal	func0f19d268
/*  f1a3c50:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3c54:	0fc67330 */ 	jal	func0f19ccc0
/*  f1a3c58:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3c5c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3c60:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3c64:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f1a3c68:	91cf0001 */ 	lbu	$t7,0x1($t6)
/*  f1a3c6c:	004f082a */ 	slt	$at,$v0,$t7
/*  f1a3c70:	5020001b */ 	beqzl	$at,.L0f1a3ce0
/*  f1a3c74:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3c78:	10000019 */ 	beqz	$zero,.L0f1a3ce0
/*  f1a3c7c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a3c80:
/*  f1a3c80:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f1a3c84:	0fc67570 */ 	jal	func0f19d5c0
/*  f1a3c88:	93040001 */ 	lbu	$a0,0x1($t8)
/*  f1a3c8c:	3c048009 */ 	lui	$a0,%hi(menudialog_frtraininginfo2)
/*  f1a3c90:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a3c94:	24848f60 */ 	addiu	$a0,$a0,%lo(menudialog_frtraininginfo2)
/*  f1a3c98:	10000011 */ 	beqz	$zero,.L0f1a3ce0
/*  f1a3c9c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3ca0:
/*  f1a3ca0:	0fc67494 */ 	jal	func0f19d250
/*  f1a3ca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3ca8:	0fc6749a */ 	jal	func0f19d268
/*  f1a3cac:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3cb0:	0fc67330 */ 	jal	func0f19ccc0
/*  f1a3cb4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3cb8:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3cbc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3cc0:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f1a3cc4:	93280001 */ 	lbu	$t0,0x1($t9)
/*  f1a3cc8:	0048082a */ 	slt	$at,$v0,$t0
/*  f1a3ccc:	54200004 */ 	bnezl	$at,.L0f1a3ce0
/*  f1a3cd0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3cd4:	10000002 */ 	beqz	$zero,.L0f1a3ce0
/*  f1a3cd8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a3cdc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3ce0:
/*  f1a3ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3ce4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a3ce8:	03e00008 */ 	jr	$ra
/*  f1a3cec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3cf0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3cf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3cf8:	0fc67494 */ 	jal	func0f19d250
/*  f1a3cfc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a3d00:	0fc6749a */ 	jal	func0f19d268
/*  f1a3d04:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3d08:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3d0c:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f1a3d10:	00002825 */ 	or	$a1,$zero,$zero
/*  f1a3d14:	10400005 */ 	beqz	$v0,.L0f1a3d2c
/*  f1a3d18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3d1c:	0fc5b9f1 */ 	jal	langGet
/*  f1a3d20:	94440004 */ 	lhu	$a0,0x4($v0)
/*  f1a3d24:	10000004 */ 	beqz	$zero,.L0f1a3d38
/*  f1a3d28:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3d2c:
/*  f1a3d2c:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f1a3d30:	244297d0 */ 	addiu	$v0,$v0,-26672
/*  f1a3d34:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3d38:
/*  f1a3d38:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a3d3c:	03e00008 */ 	jr	$ra
/*  f1a3d40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3d44:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3d48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3d4c:	0fc67494 */ 	jal	func0f19d250
/*  f1a3d50:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a3d54:	0fc6749a */ 	jal	func0f19d268
/*  f1a3d58:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3d5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3d60:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f1a3d64:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a3d68:	10400005 */ 	beqz	$v0,.L0f1a3d80
/*  f1a3d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3d70:	0fc5b9f1 */ 	jal	langGet
/*  f1a3d74:	94440004 */ 	lhu	$a0,0x4($v0)
/*  f1a3d78:	10000004 */ 	beqz	$zero,.L0f1a3d8c
/*  f1a3d7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3d80:
/*  f1a3d80:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f1a3d84:	244297d4 */ 	addiu	$v0,$v0,-26668
/*  f1a3d88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a3d8c:
/*  f1a3d8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a3d90:	03e00008 */ 	jr	$ra
/*  f1a3d94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a3d98
/*  f1a3d98:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a3d9c:	3c0f8009 */ 	lui	$t7,%hi(var80088c78)
/*  f1a3da0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3da4:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1a3da8:	25ef8c78 */ 	addiu	$t7,$t7,%lo(var80088c78)
/*  f1a3dac:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a3db0:	27ae001c */ 	addiu	$t6,$sp,0x1c
/*  f1a3db4:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a3db8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a3dbc:	95e10008 */ 	lhu	$at,0x8($t7)
/*  f1a3dc0:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a3dc4:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a3dc8:	a5c10008 */ 	sh	$at,0x8($t6)
/*  f1a3dcc:	9049045b */ 	lbu	$t1,0x45b($v0)
/*  f1a3dd0:	00095040 */ 	sll	$t2,$t1,0x1
/*  f1a3dd4:	03aa2021 */ 	addu	$a0,$sp,$t2
/*  f1a3dd8:	0fc5b9f1 */ 	jal	langGet
/*  f1a3ddc:	9484001c */ 	lhu	$a0,0x1c($a0)
/*  f1a3de0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3de4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a3de8:	03e00008 */ 	jr	$ra
/*  f1a3dec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a3df0
/*  f1a3df0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a3df4:	3c0f8009 */ 	lui	$t7,%hi(var80088c84)
/*  f1a3df8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3dfc:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1a3e00:	25ef8c84 */ 	addiu	$t7,$t7,%lo(var80088c84)
/*  f1a3e04:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a3e08:	27ae0020 */ 	addiu	$t6,$sp,0x20
/*  f1a3e0c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a3e10:	95e10004 */ 	lhu	$at,0x4($t7)
/*  f1a3e14:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a3e18:	a5c10004 */ 	sh	$at,0x4($t6)
/*  f1a3e1c:	90490448 */ 	lbu	$t1,0x448($v0)
/*  f1a3e20:	00095040 */ 	sll	$t2,$t1,0x1
/*  f1a3e24:	03aa2021 */ 	addu	$a0,$sp,$t2
/*  f1a3e28:	0fc5b9f1 */ 	jal	langGet
/*  f1a3e2c:	94840020 */ 	lhu	$a0,0x20($a0)
/*  f1a3e30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3e34:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a3e38:	03e00008 */ 	jr	$ra
/*  f1a3e3c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a3e40
/*  f1a3e40:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1a3e44:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1a3e48:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a3e4c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f1a3e50:	8c4e044c */ 	lw	$t6,0x44c($v0)
/*  f1a3e54:	904f0005 */ 	lbu	$t7,0x5($v0)
/*  f1a3e58:	3c014270 */ 	lui	$at,0x4270
/*  f1a3e5c:	448e2000 */ 	mtc1	$t6,$f4
/*  f1a3e60:	44810000 */ 	mtc1	$at,$f0
/*  f1a3e64:	448f4000 */ 	mtc1	$t7,$f8
/*  f1a3e68:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a3e6c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a3e70:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a3e74:	24a597e4 */ 	addiu	$a1,$a1,-26652
/*  f1a3e78:	3c048007 */ 	lui	$a0,0x8007
/*  f1a3e7c:	3c067f1c */ 	lui	$a2,0x7f1c
/*  f1a3e80:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f1a3e84:	05e10004 */ 	bgez	$t7,.L0f1a3e98
/*  f1a3e88:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f1a3e8c:	44815000 */ 	mtc1	$at,$f10
/*  f1a3e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3e94:	460a1080 */ 	add.s	$f2,$f2,$f10
.L0f1a3e98:
/*  f1a3e98:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1a3e9c:	3c077f1c */ 	lui	$a3,0x7f1c
/*  f1a3ea0:	24e797f4 */ 	addiu	$a3,$a3,-26636
/*  f1a3ea4:	24c697f0 */ 	addiu	$a2,$a2,-26640
/*  f1a3ea8:	45020003 */ 	bc1fl	.L0f1a3eb8
/*  f1a3eac:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a3eb0:	46001306 */ 	mov.s	$f12,$f2
/*  f1a3eb4:	460c003e */ 	c.le.s	$f0,$f12
.L0f1a3eb8:
/*  f1a3eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3ebc:	45020019 */ 	bc1fl	.L0f1a3f24
/*  f1a3ec0:	460064a1 */ 	cvt.d.s	$f18,$f12
/*  f1a3ec4:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a3ec8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a3ecc:	45000007 */ 	bc1f	.L0f1a3eec
/*  f1a3ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3ed4:	46006301 */ 	sub.s	$f12,$f12,$f0
.L0f1a3ed8:
/*  f1a3ed8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1a3edc:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a3ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3ee4:	4503fffc */ 	bc1tl	.L0f1a3ed8
/*  f1a3ee8:	46006301 */ 	sub.s	$f12,$f12,$f0
.L0f1a3eec:
/*  f1a3eec:	0fc25e5c */ 	jal	func0f097970
/*  f1a3ef0:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f1a3ef4:	4600040d */ 	trunc.w.s	$f16,$f0
/*  f1a3ef8:	3c048007 */ 	lui	$a0,0x8007
/*  f1a3efc:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a3f00:	24a597d8 */ 	addiu	$a1,$a1,-26664
/*  f1a3f04:	44078000 */ 	mfc1	$a3,$f16
/*  f1a3f08:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a3f0c:	0c004dad */ 	jal	sprintf
/*  f1a3f10:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f1a3f14:	3c028007 */ 	lui	$v0,0x8007
/*  f1a3f18:	10000007 */ 	beqz	$zero,.L0f1a3f38
/*  f1a3f1c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a3f20:	460064a1 */ 	cvt.d.s	$f18,$f12
.L0f1a3f24:
/*  f1a3f24:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a3f28:	0c004dad */ 	jal	sprintf
/*  f1a3f2c:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f1a3f30:	3c028007 */ 	lui	$v0,0x8007
/*  f1a3f34:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a3f38:
/*  f1a3f38:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1a3f3c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1a3f40:	03e00008 */ 	jr	$ra
/*  f1a3f44:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a3f48
/*  f1a3f48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3f4c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3f50:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a3f54:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a3f58:	3c048007 */ 	lui	$a0,0x8007
/*  f1a3f5c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a3f60:	24a597f8 */ 	addiu	$a1,$a1,-26632
/*  f1a3f64:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a3f68:	0c004dad */ 	jal	sprintf
/*  f1a3f6c:	8c460450 */ 	lw	$a2,0x450($v0)
/*  f1a3f70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3f74:	3c028007 */ 	lui	$v0,0x8007
/*  f1a3f78:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a3f7c:	03e00008 */ 	jr	$ra
/*  f1a3f80:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a3f84:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3f88:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3f8c:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a3f90:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a3f94:	3c048007 */ 	lui	$a0,0x8007
/*  f1a3f98:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a3f9c:	24a597fc */ 	addiu	$a1,$a1,-26628
/*  f1a3fa0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a3fa4:	0c004dad */ 	jal	sprintf
/*  f1a3fa8:	94460002 */ 	lhu	$a2,0x2($v0)
/*  f1a3fac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3fb0:	3c028007 */ 	lui	$v0,0x8007
/*  f1a3fb4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a3fb8:	03e00008 */ 	jr	$ra
/*  f1a3fbc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a3fc0
/*  f1a3fc0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3fc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3fc8:	0fc67494 */ 	jal	func0f19d250
/*  f1a3fcc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a3fd0:	0fc6749a */ 	jal	func0f19d268
/*  f1a3fd4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3fd8:	0fc28857 */ 	jal	func0f0a215c
/*  f1a3fdc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3fe0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a3fe4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a3fe8:	03e00008 */ 	jr	$ra
/*  f1a3fec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a3ff0
/*  f1a3ff0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a3ff4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a3ff8:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a3ffc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a4000:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4004:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4008:	24a59800 */ 	addiu	$a1,$a1,-26624
/*  f1a400c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a4010:	0c004dad */ 	jal	sprintf
/*  f1a4014:	90460455 */ 	lbu	$a2,0x455($v0)
/*  f1a4018:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a401c:	3c028007 */ 	lui	$v0,0x8007
/*  f1a4020:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a4024:	03e00008 */ 	jr	$ra
/*  f1a4028:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a402c
/*  f1a402c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1a4030:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1a4034:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a4038:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1a403c:	944e0462 */ 	lhu	$t6,0x462($v0)
/*  f1a4040:	944f045c */ 	lhu	$t7,0x45c($v0)
/*  f1a4044:	9459045e */ 	lhu	$t9,0x45e($v0)
/*  f1a4048:	94490460 */ 	lhu	$t1,0x460($v0)
/*  f1a404c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f1a4050:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1a4054:	01095021 */ 	addu	$t2,$t0,$t1
/*  f1a4058:	448a2000 */ 	mtc1	$t2,$f4
/*  f1a405c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f1a4060:	44816000 */ 	mtc1	$at,$f12
/*  f1a4064:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a4068:	94430458 */ 	lhu	$v1,0x458($v0)
/*  f1a406c:	44800000 */ 	mtc1	$zero,$f0
/*  f1a4070:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4074:	24a59804 */ 	addiu	$a1,$a1,-26620
/*  f1a4078:	3c048007 */ 	lui	$a0,0x8007
/*  f1a407c:	460c3082 */ 	mul.s	$f2,$f6,$f12
/*  f1a4080:	10600009 */ 	beqz	$v1,.L0f1a40a8
/*  f1a4084:	3c067f1c */ 	lui	$a2,0x7f1c
/*  f1a4088:	44834000 */ 	mtc1	$v1,$f8
/*  f1a408c:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a4090:	04610004 */ 	bgez	$v1,.L0f1a40a4
/*  f1a4094:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1a4098:	44818000 */ 	mtc1	$at,$f16
/*  f1a409c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a40a0:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f1a40a4:
/*  f1a40a4:	460a1003 */ 	div.s	$f0,$f2,$f10
.L0f1a40a8:
/*  f1a40a8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f1a40ac:	3c077f1c */ 	lui	$a3,0x7f1c
/*  f1a40b0:	24e79814 */ 	addiu	$a3,$a3,-26604
/*  f1a40b4:	24c69810 */ 	addiu	$a2,$a2,-26608
/*  f1a40b8:	45020003 */ 	bc1fl	.L0f1a40c8
/*  f1a40bc:	460004a1 */ 	cvt.d.s	$f18,$f0
/*  f1a40c0:	46006006 */ 	mov.s	$f0,$f12
/*  f1a40c4:	460004a1 */ 	cvt.d.s	$f18,$f0
.L0f1a40c8:
/*  f1a40c8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a40cc:	0c004dad */ 	jal	sprintf
/*  f1a40d0:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f1a40d4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1a40d8:	3c028007 */ 	lui	$v0,0x8007
/*  f1a40dc:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a40e0:	03e00008 */ 	jr	$ra
/*  f1a40e4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f1a40e8
/*  f1a40e8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a40ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a40f0:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a40f4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a40f8:	944e0002 */ 	lhu	$t6,0x2($v0)
/*  f1a40fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a4100:	19c0000c */ 	blez	$t6,.L0f1a4134
/*  f1a4104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4108:	0fc5b9f1 */ 	jal	langGet
/*  f1a410c:	240451db */ 	addiu	$a0,$zero,0x51db
/*  f1a4110:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4114:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4118:	24a59818 */ 	addiu	$a1,$a1,-26600
/*  f1a411c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a4120:	0c004dad */ 	jal	sprintf
/*  f1a4124:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a4128:	3c028007 */ 	lui	$v0,0x8007
/*  f1a412c:	10000001 */ 	beqz	$zero,.L0f1a4134
/*  f1a4130:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a4134:
/*  f1a4134:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a4138:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a413c:	03e00008 */ 	jr	$ra
/*  f1a4140:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a4144
/*  f1a4144:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a4148:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a414c:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a4150:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a4154:	944e0002 */ 	lhu	$t6,0x2($v0)
/*  f1a4158:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a415c:	24a5981c */ 	addiu	$a1,$a1,-26596
/*  f1a4160:	19c00007 */ 	blez	$t6,.L0f1a4180
/*  f1a4164:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4168:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f1a416c:	0c004dad */ 	jal	sprintf
/*  f1a4170:	94460002 */ 	lhu	$a2,0x2($v0)
/*  f1a4174:	3c028007 */ 	lui	$v0,0x8007
/*  f1a4178:	10000002 */ 	beqz	$zero,.L0f1a4184
/*  f1a417c:	8c421444 */ 	lw	$v0,0x1444($v0)
.L0f1a4180:
/*  f1a4180:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a4184:
/*  f1a4184:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a4188:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a418c:	03e00008 */ 	jr	$ra
/*  f1a4190:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a4194
/*  f1a4194:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a4198:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a419c:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a41a0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a41a4:	904e0008 */ 	lbu	$t6,0x8($v0)
/*  f1a41a8:	59c0000c */ 	blezl	$t6,.L0f1a41dc
/*  f1a41ac:	904f0004 */ 	lbu	$t7,0x4($v0)
/*  f1a41b0:	0fc5b9f1 */ 	jal	langGet
/*  f1a41b4:	240451d9 */ 	addiu	$a0,$zero,0x51d9
/*  f1a41b8:	3c048007 */ 	lui	$a0,0x8007
/*  f1a41bc:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a41c0:	24a59820 */ 	addiu	$a1,$a1,-26592
/*  f1a41c4:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a41c8:	0c004dad */ 	jal	sprintf
/*  f1a41cc:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a41d0:	10000011 */ 	beqz	$zero,.L0f1a4218
/*  f1a41d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a41d8:	904f0004 */ 	lbu	$t7,0x4($v0)
.L0f1a41dc:
/*  f1a41dc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a41e0:	11e1000b */ 	beq	$t7,$at,.L0f1a4210
/*  f1a41e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a41e8:	0fc5b9f1 */ 	jal	langGet
/*  f1a41ec:	240451da */ 	addiu	$a0,$zero,0x51da
/*  f1a41f0:	3c048007 */ 	lui	$a0,0x8007
/*  f1a41f4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a41f8:	24a59824 */ 	addiu	$a1,$a1,-26588
/*  f1a41fc:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a4200:	0c004dad */ 	jal	sprintf
/*  f1a4204:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a4208:	10000003 */ 	beqz	$zero,.L0f1a4218
/*  f1a420c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a4210:
/*  f1a4210:	10000003 */ 	beqz	$zero,.L0f1a4220
/*  f1a4214:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a4218:
/*  f1a4218:	3c028007 */ 	lui	$v0,0x8007
/*  f1a421c:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a4220:
/*  f1a4220:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a4224:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a4228:	03e00008 */ 	jr	$ra
/*  f1a422c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a4230
/*  f1a4230:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a4234:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a4238:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a423c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a4240:	904e0008 */ 	lbu	$t6,0x8($v0)
/*  f1a4244:	00401825 */ 	or	$v1,$v0,$zero
/*  f1a4248:	3c048007 */ 	lui	$a0,0x8007
/*  f1a424c:	19c00007 */ 	blez	$t6,.L0f1a426c
/*  f1a4250:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4254:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f1a4258:	24a59828 */ 	addiu	$a1,$a1,-26584
/*  f1a425c:	0c004dad */ 	jal	sprintf
/*  f1a4260:	90660008 */ 	lbu	$a2,0x8($v1)
/*  f1a4264:	1000000e */ 	beqz	$zero,.L0f1a42a0
/*  f1a4268:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a426c:
/*  f1a426c:	904f0004 */ 	lbu	$t7,0x4($v0)
/*  f1a4270:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a4274:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4278:	11e10007 */ 	beq	$t7,$at,.L0f1a4298
/*  f1a427c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4280:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f1a4284:	24a59830 */ 	addiu	$a1,$a1,-26576
/*  f1a4288:	0c004dad */ 	jal	sprintf
/*  f1a428c:	90660004 */ 	lbu	$a2,0x4($v1)
/*  f1a4290:	10000003 */ 	beqz	$zero,.L0f1a42a0
/*  f1a4294:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a4298:
/*  f1a4298:	10000003 */ 	beqz	$zero,.L0f1a42a8
/*  f1a429c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a42a0:
/*  f1a42a0:	3c028007 */ 	lui	$v0,0x8007
/*  f1a42a4:	8c421444 */ 	lw	$v0,0x1444($v0)
.L0f1a42a8:
/*  f1a42a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a42ac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a42b0:	03e00008 */ 	jr	$ra
/*  f1a42b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a42b8
/*  f1a42b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a42bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a42c0:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a42c4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a42c8:	904e0005 */ 	lbu	$t6,0x5($v0)
/*  f1a42cc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a42d0:	11c1000b */ 	beq	$t6,$at,.L0f1a4300
/*  f1a42d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a42d8:	0fc5b9f1 */ 	jal	langGet
/*  f1a42dc:	240451d8 */ 	addiu	$a0,$zero,0x51d8
/*  f1a42e0:	3c048007 */ 	lui	$a0,0x8007
/*  f1a42e4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a42e8:	24a59834 */ 	addiu	$a1,$a1,-26572
/*  f1a42ec:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a42f0:	0c004dad */ 	jal	sprintf
/*  f1a42f4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a42f8:	10000003 */ 	beqz	$zero,.L0f1a4308
/*  f1a42fc:	3c028007 */ 	lui	$v0,0x8007
.L0f1a4300:
/*  f1a4300:	10000002 */ 	beqz	$zero,.L0f1a430c
/*  f1a4304:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a4308:
/*  f1a4308:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a430c:
/*  f1a430c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a4310:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a4314:	03e00008 */ 	jr	$ra
/*  f1a4318:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a431c
/*  f1a431c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a4320:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a4324:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a4328:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a432c:	90430005 */ 	lbu	$v1,0x5($v0)
/*  f1a4330:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a4334:	10610018 */ 	beq	$v1,$at,.L0f1a4398
/*  f1a4338:	00603825 */ 	or	$a3,$v1,$zero
/*  f1a433c:	2861003c */ 	slti	$at,$v1,0x3c
/*  f1a4340:	14200005 */ 	bnez	$at,.L0f1a4358
/*  f1a4344:	00003025 */ 	or	$a2,$zero,$zero
.L0f1a4348:
/*  f1a4348:	24e7ffc4 */ 	addiu	$a3,$a3,-60
/*  f1a434c:	28e1003c */ 	slti	$at,$a3,0x3c
/*  f1a4350:	1020fffd */ 	beqz	$at,.L0f1a4348
/*  f1a4354:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1a4358:
/*  f1a4358:	18c00008 */ 	blez	$a2,.L0f1a437c
/*  f1a435c:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4360:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4364:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4368:	24a59838 */ 	addiu	$a1,$a1,-26568
/*  f1a436c:	0c004dad */ 	jal	sprintf
/*  f1a4370:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f1a4374:	1000000a */ 	beqz	$zero,.L0f1a43a0
/*  f1a4378:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a437c:
/*  f1a437c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4380:	24a59844 */ 	addiu	$a1,$a1,-26556
/*  f1a4384:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f1a4388:	0c004dad */ 	jal	sprintf
/*  f1a438c:	00e03025 */ 	or	$a2,$a3,$zero
/*  f1a4390:	10000003 */ 	beqz	$zero,.L0f1a43a0
/*  f1a4394:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a4398:
/*  f1a4398:	10000003 */ 	beqz	$zero,.L0f1a43a8
/*  f1a439c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a43a0:
/*  f1a43a0:	3c028007 */ 	lui	$v0,0x8007
/*  f1a43a4:	8c421444 */ 	lw	$v0,0x1444($v0)
.L0f1a43a8:
/*  f1a43a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a43ac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a43b0:	03e00008 */ 	jr	$ra
/*  f1a43b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a43b8
/*  f1a43b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a43bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a43c0:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a43c4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a43c8:	904e0006 */ 	lbu	$t6,0x6($v0)
/*  f1a43cc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a43d0:	11c1000b */ 	beq	$t6,$at,.L0f1a4400
/*  f1a43d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a43d8:	0fc5b9f1 */ 	jal	langGet
/*  f1a43dc:	240451d7 */ 	addiu	$a0,$zero,0x51d7
/*  f1a43e0:	3c048007 */ 	lui	$a0,0x8007
/*  f1a43e4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a43e8:	24a5984c */ 	addiu	$a1,$a1,-26548
/*  f1a43ec:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a43f0:	0c004dad */ 	jal	sprintf
/*  f1a43f4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a43f8:	10000003 */ 	beqz	$zero,.L0f1a4408
/*  f1a43fc:	3c028007 */ 	lui	$v0,0x8007
.L0f1a4400:
/*  f1a4400:	10000002 */ 	beqz	$zero,.L0f1a440c
/*  f1a4404:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a4408:
/*  f1a4408:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a440c:
/*  f1a440c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a4410:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a4414:	03e00008 */ 	jr	$ra
/*  f1a4418:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a441c
/*  f1a441c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a4420:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a4424:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a4428:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f1a442c:	904e0006 */ 	lbu	$t6,0x6($v0)
/*  f1a4430:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a4434:	11c1001b */ 	beq	$t6,$at,.L0f1a44a4
/*  f1a4438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a443c:	94440456 */ 	lhu	$a0,0x456($v0)
/*  f1a4440:	0fc6749a */ 	jal	func0f19d268
/*  f1a4444:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f1a4448:	24010012 */ 	addiu	$at,$zero,0x12
/*  f1a444c:	1441000b */ 	bne	$v0,$at,.L0f1a447c
/*  f1a4450:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f1a4454:	90660007 */ 	lbu	$a2,0x7($v1)
/*  f1a4458:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a445c:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f1a4460:	10c10006 */ 	beq	$a2,$at,.L0f1a447c
/*  f1a4464:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4468:	24a59850 */ 	addiu	$a1,$a1,-26544
/*  f1a446c:	0c004dad */ 	jal	sprintf
/*  f1a4470:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f1a4474:	10000002 */ 	beqz	$zero,.L0f1a4480
/*  f1a4478:	8fa30034 */ 	lw	$v1,0x34($sp)
.L0f1a447c:
/*  f1a447c:	a3a00024 */ 	sb	$zero,0x24($sp)
.L0f1a4480:
/*  f1a4480:	3c048007 */ 	lui	$a0,0x8007
/*  f1a4484:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4488:	24a59854 */ 	addiu	$a1,$a1,-26540
/*  f1a448c:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f1a4490:	90660006 */ 	lbu	$a2,0x6($v1)
/*  f1a4494:	0c004dad */ 	jal	sprintf
/*  f1a4498:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f1a449c:	10000003 */ 	beqz	$zero,.L0f1a44ac
/*  f1a44a0:	3c028007 */ 	lui	$v0,0x8007
.L0f1a44a4:
/*  f1a44a4:	10000002 */ 	beqz	$zero,.L0f1a44b0
/*  f1a44a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a44ac:
/*  f1a44ac:	8c421444 */ 	lw	$v0,0x1444($v0)
.L0f1a44b0:
/*  f1a44b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a44b4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a44b8:	03e00008 */ 	jr	$ra
/*  f1a44bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler001a44c0
/*  f1a44c0:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f1a44c4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1a44c8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1a44cc:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1a44d0:	1481061c */ 	bne	$a0,$at,.L0f1a5d44
/*  f1a44d4:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f1a44d8:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a44dc:	3c0f800b */ 	lui	$t7,0x800b
/*  f1a44e0:	8defb5a8 */ 	lw	$t7,-0x4a58($t7)
/*  f1a44e4:	afae015c */ 	sw	$t6,0x15c($sp)
/*  f1a44e8:	8cd00008 */ 	lw	$s0,0x8($a2)
/*  f1a44ec:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f1a44f0:	0fc675f3 */ 	jal	func0f19d7cc
/*  f1a44f4:	afb80144 */ 	sw	$t8,0x144($sp)
/*  f1a44f8:	afa20140 */ 	sw	$v0,0x140($sp)
/*  f1a44fc:	90430465 */ 	lbu	$v1,0x465($v0)
/*  f1a4500:	0003c942 */ 	srl	$t9,$v1,0x5
/*  f1a4504:	3b2c0002 */ 	xori	$t4,$t9,0x2
/*  f1a4508:	2d830001 */ 	sltiu	$v1,$t4,0x1
/*  f1a450c:	10600003 */ 	beqz	$v1,.L0f1a451c
/*  f1a4510:	3c06ff00 */ 	lui	$a2,0xff00
/*  f1a4514:	10000004 */ 	beqz	$zero,.L0f1a4528
/*  f1a4518:	34c60077 */ 	ori	$a2,$a2,0x77
.L0f1a451c:
/*  f1a451c:	3c0d00ff */ 	lui	$t5,0xff
/*  f1a4520:	35a60077 */ 	ori	$a2,$t5,0x77
/*  f1a4524:	afa600b8 */ 	sw	$a2,0xb8($sp)
.L0f1a4528:
/*  f1a4528:	50600004 */ 	beqzl	$v1,.L0f1a453c
/*  f1a452c:	3c0e00ff */ 	lui	$t6,0xff
/*  f1a4530:	10000004 */ 	beqz	$zero,.L0f1a4544
/*  f1a4534:	3c09ff00 */ 	lui	$t1,0xff00
/*  f1a4538:	3c0e00ff */ 	lui	$t6,0xff
.L0f1a453c:
/*  f1a453c:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f1a4540:	3c0900ff */ 	lui	$t1,0xff
.L0f1a4544:
/*  f1a4544:	10600003 */ 	beqz	$v1,.L0f1a4554
/*  f1a4548:	3c08ff00 */ 	lui	$t0,0xff00
/*  f1a454c:	10000004 */ 	beqz	$zero,.L0f1a4560
/*  f1a4550:	35080033 */ 	ori	$t0,$t0,0x33
.L0f1a4554:
/*  f1a4554:	3c0f00ff */ 	lui	$t7,0xff
/*  f1a4558:	35e80033 */ 	ori	$t0,$t7,0x33
/*  f1a455c:	afa800b0 */ 	sw	$t0,0xb0($sp)
.L0f1a4560:
/*  f1a4560:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f1a4564:	30cc00ff */ 	andi	$t4,$a2,0xff
/*  f1a4568:	2407ff00 */ 	addiu	$a3,$zero,-256
/*  f1a456c:	305800ff */ 	andi	$t8,$v0,0xff
/*  f1a4570:	01980019 */ 	multu	$t4,$t8
/*  f1a4574:	03001025 */ 	or	$v0,$t8,$zero
/*  f1a4578:	313800ff */ 	andi	$t8,$t1,0xff
/*  f1a457c:	00c7c824 */ 	and	$t9,$a2,$a3
/*  f1a4580:	01277824 */ 	and	$t7,$t1,$a3
/*  f1a4584:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a4588:	3c058009 */ 	lui	$a1,%hi(var80088c8c)
/*  f1a458c:	24a58c8c */ 	addiu	$a1,$a1,%lo(var80088c8c)
/*  f1a4590:	2484985c */ 	addiu	$a0,$a0,-26532
/*  f1a4594:	afa300bc */ 	sw	$v1,0xbc($sp)
/*  f1a4598:	00006812 */ 	mflo	$t5
/*  f1a459c:	000d7202 */ 	srl	$t6,$t5,0x8
/*  f1a45a0:	032e3025 */ 	or	$a2,$t9,$t6
/*  f1a45a4:	03020019 */ 	multu	$t8,$v0
/*  f1a45a8:	310e00ff */ 	andi	$t6,$t0,0xff
/*  f1a45ac:	0107c824 */ 	and	$t9,$t0,$a3
/*  f1a45b0:	afa600b8 */ 	sw	$a2,0xb8($sp)
/*  f1a45b4:	00006012 */ 	mflo	$t4
/*  f1a45b8:	000c6a02 */ 	srl	$t5,$t4,0x8
/*  f1a45bc:	01ed4825 */ 	or	$t1,$t7,$t5
/*  f1a45c0:	01c20019 */ 	multu	$t6,$v0
/*  f1a45c4:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f1a45c8:	0000c012 */ 	mflo	$t8
/*  f1a45cc:	00186202 */ 	srl	$t4,$t8,0x8
/*  f1a45d0:	032c4025 */ 	or	$t0,$t9,$t4
/*  f1a45d4:	0c0036cc */ 	jal	func0000db30
/*  f1a45d8:	afa800b0 */ 	sw	$t0,0xb0($sp)
/*  f1a45dc:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a45e0:	3c058009 */ 	lui	$a1,%hi(var80088c90)
/*  f1a45e4:	24a58c90 */ 	addiu	$a1,$a1,%lo(var80088c90)
/*  f1a45e8:	0c0036cc */ 	jal	func0000db30
/*  f1a45ec:	24849860 */ 	addiu	$a0,$a0,-26528
/*  f1a45f0:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a45f4:	3c058009 */ 	lui	$a1,%hi(var80088c94)
/*  f1a45f8:	24a58c94 */ 	addiu	$a1,$a1,%lo(var80088c94)
/*  f1a45fc:	0c0036cc */ 	jal	func0000db30
/*  f1a4600:	24849864 */ 	addiu	$a0,$a0,-26524
/*  f1a4604:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a4608:	3c058009 */ 	lui	$a1,%hi(var80088c98)
/*  f1a460c:	24a58c98 */ 	addiu	$a1,$a1,%lo(var80088c98)
/*  f1a4610:	0c0036cc */ 	jal	func0000db30
/*  f1a4614:	24849868 */ 	addiu	$a0,$a0,-26520
/*  f1a4618:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a461c:	3c058009 */ 	lui	$a1,%hi(var80088c9c)
/*  f1a4620:	24a58c9c */ 	addiu	$a1,$a1,%lo(var80088c9c)
/*  f1a4624:	0c0036cc */ 	jal	func0000db30
/*  f1a4628:	2484986c */ 	addiu	$a0,$a0,-26516
/*  f1a462c:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a4630:	3c058009 */ 	lui	$a1,%hi(var80088ca0)
/*  f1a4634:	24a58ca0 */ 	addiu	$a1,$a1,%lo(var80088ca0)
/*  f1a4638:	0c0036cc */ 	jal	func0000db30
/*  f1a463c:	24849870 */ 	addiu	$a0,$a0,-26512
/*  f1a4640:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a4644:	3c058009 */ 	lui	$a1,%hi(var80088ca4)
/*  f1a4648:	24a58ca4 */ 	addiu	$a1,$a1,%lo(var80088ca4)
/*  f1a464c:	0c0036cc */ 	jal	func0000db30
/*  f1a4650:	24849874 */ 	addiu	$a0,$a0,-26508
/*  f1a4654:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1a4658:	3c058009 */ 	lui	$a1,%hi(var80088ca8)
/*  f1a465c:	24a58ca8 */ 	addiu	$a1,$a1,%lo(var80088ca8)
/*  f1a4660:	0c0036cc */ 	jal	func0000db30
/*  f1a4664:	24849878 */ 	addiu	$a0,$a0,-26504
/*  f1a4668:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f1a466c:	3c0ee700 */ 	lui	$t6,0xe700
/*  f1a4670:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1a4674:	25ed0008 */ 	addiu	$t5,$t7,0x8
/*  f1a4678:	afad015c */ 	sw	$t5,0x15c($sp)
/*  f1a467c:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f1a4680:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f1a4684:	8fb8015c */ 	lw	$t8,0x15c($sp)
/*  f1a4688:	358c1301 */ 	ori	$t4,$t4,0x1301
/*  f1a468c:	3c0eb900 */ 	lui	$t6,0xb900
/*  f1a4690:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a4694:	afb9015c */ 	sw	$t9,0x15c($sp)
/*  f1a4698:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a469c:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1a46a0:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f1a46a4:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f1a46a8:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1a46ac:	25ed0008 */ 	addiu	$t5,$t7,0x8
/*  f1a46b0:	afad015c */ 	sw	$t5,0x15c($sp)
/*  f1a46b4:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f1a46b8:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f1a46bc:	8fb8015c */ 	lw	$t8,0x15c($sp)
/*  f1a46c0:	358c1001 */ 	ori	$t4,$t4,0x1001
/*  f1a46c4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1a46c8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a46cc:	afb9015c */ 	sw	$t9,0x15c($sp)
/*  f1a46d0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a46d4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1a46d8:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f1a46dc:	24180c00 */ 	addiu	$t8,$zero,0xc00
/*  f1a46e0:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f1a46e4:	25ed0008 */ 	addiu	$t5,$t7,0x8
/*  f1a46e8:	afad015c */ 	sw	$t5,0x15c($sp)
/*  f1a46ec:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f1a46f0:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f1a46f4:	8fb9015c */ 	lw	$t9,0x15c($sp)
/*  f1a46f8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a46fc:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1a4700:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f1a4704:	afac015c */ 	sw	$t4,0x15c($sp)
/*  f1a4708:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1a470c:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f1a4710:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a4714:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f1a4718:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a471c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a4720:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a4724:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f1a4728:	27a4015c */ 	addiu	$a0,$sp,0x15c
/*  f1a472c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1a4730:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1a4734:	00003825 */ 	or	$a3,$zero,$zero
/*  f1a4738:	8fb8015c */ 	lw	$t8,0x15c($sp)
/*  f1a473c:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f1a4740:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1a4744:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1a4748:	afb9015c */ 	sw	$t9,0x15c($sp)
/*  f1a474c:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f1a4750:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1a4754:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a4758:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f1a475c:	3c18fffc */ 	lui	$t8,0xfffc
/*  f1a4760:	3c0efcff */ 	lui	$t6,0xfcff
/*  f1a4764:	25ed0008 */ 	addiu	$t5,$t7,0x8
/*  f1a4768:	afad015c */ 	sw	$t5,0x15c($sp)
/*  f1a476c:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f1a4770:	3718f279 */ 	ori	$t8,$t8,0xf279
/*  f1a4774:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f1a4778:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f1a477c:	8fb9015c */ 	lw	$t9,0x15c($sp)
/*  f1a4780:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a4784:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1a4788:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f1a478c:	afac015c */ 	sw	$t4,0x15c($sp)
/*  f1a4790:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1a4794:	11400004 */ 	beqz	$t2,.L0f1a47a8
/*  f1a4798:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f1a479c:	3c07ff77 */ 	lui	$a3,0xff77
/*  f1a47a0:	10000003 */ 	beqz	$zero,.L0f1a47b0
/*  f1a47a4:	34e77799 */ 	ori	$a3,$a3,0x7799
.L0f1a47a8:
/*  f1a47a8:	3c0755ff */ 	lui	$a3,0x55ff
/*  f1a47ac:	34e75588 */ 	ori	$a3,$a3,0x5588
.L0f1a47b0:
/*  f1a47b0:	11400003 */ 	beqz	$t2,.L0f1a47c0
/*  f1a47b4:	3c03ff77 */ 	lui	$v1,0xff77
/*  f1a47b8:	10000003 */ 	beqz	$zero,.L0f1a47c8
/*  f1a47bc:	34637799 */ 	ori	$v1,$v1,0x7799
.L0f1a47c0:
/*  f1a47c0:	3c0355ff */ 	lui	$v1,0x55ff
/*  f1a47c4:	34635588 */ 	ori	$v1,$v1,0x5588
.L0f1a47c8:
/*  f1a47c8:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f1a47cc:	306d00ff */ 	andi	$t5,$v1,0xff
/*  f1a47d0:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a47d4:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f1a47d8:	01b80019 */ 	multu	$t5,$t8
/*  f1a47dc:	8fae015c */ 	lw	$t6,0x15c($sp)
/*  f1a47e0:	00e17824 */ 	and	$t7,$a3,$at
/*  f1a47e4:	3c18fb00 */ 	lui	$t8,0xfb00
/*  f1a47e8:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f1a47ec:	afad015c */ 	sw	$t5,0x15c($sp)
/*  f1a47f0:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1a47f4:	3c028008 */ 	lui	$v0,%hi(var8007fac0)
/*  f1a47f8:	2442fac0 */ 	addiu	$v0,$v0,%lo(var8007fac0)
/*  f1a47fc:	3c08e400 */ 	lui	$t0,0xe400
/*  f1a4800:	0000c812 */ 	mflo	$t9
/*  f1a4804:	00196202 */ 	srl	$t4,$t9,0x8
/*  f1a4808:	018f4825 */ 	or	$t1,$t4,$t7
/*  f1a480c:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f1a4810:	8fb9015c */ 	lw	$t9,0x15c($sp)
/*  f1a4814:	3c0eff37 */ 	lui	$t6,0xff37
/*  f1a4818:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f1a481c:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f1a4820:	afac015c */ 	sw	$t4,0x15c($sp)
/*  f1a4824:	35ef9a25 */ 	ori	$t7,$t7,0x9a25
/*  f1a4828:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f1a482c:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f1a4830:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f1a4834:	8fad015c */ 	lw	$t5,0x15c($sp)
/*  f1a4838:	03202825 */ 	or	$a1,$t9,$zero
/*  f1a483c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1a4840:	25b80008 */ 	addiu	$t8,$t5,0x8
/*  f1a4844:	afb8015c */ 	sw	$t8,0x15c($sp)
/*  f1a4848:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a484c:	01a03025 */ 	or	$a2,$t5,$zero
/*  f1a4850:	3c090010 */ 	lui	$t1,0x10
/*  f1a4854:	272c002a */ 	addiu	$t4,$t9,0x2a
/*  f1a4858:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f1a485c:	01ee0019 */ 	multu	$t7,$t6
/*  f1a4860:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f1a4864:	35290400 */ 	ori	$t1,$t1,0x400
/*  f1a4868:	3c07b400 */ 	lui	$a3,0xb400
/*  f1a486c:	25ee0025 */ 	addiu	$t6,$t7,0x25
/*  f1a4870:	3c0ab300 */ 	lui	$t2,0xb300
/*  f1a4874:	240bfc00 */ 	addiu	$t3,$zero,-1024
/*  f1a4878:	00006812 */ 	mflo	$t5
/*  f1a487c:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f1a4880:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f1a4884:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f1a4888:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f1a488c:	03286025 */ 	or	$t4,$t9,$t0
/*  f1a4890:	0198c825 */ 	or	$t9,$t4,$t8
/*  f1a4894:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f1a4898:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a489c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f1a48a0:	25ee000a */ 	addiu	$t6,$t7,0xa
/*  f1a48a4:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f1a48a8:	01ac0019 */ 	multu	$t5,$t4
/*  f1a48ac:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f1a48b0:	25cd0005 */ 	addiu	$t5,$t6,0x5
/*  f1a48b4:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f1a48b8:	0000c012 */ 	mflo	$t8
/*  f1a48bc:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f1a48c0:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f1a48c4:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f1a48c8:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f1a48cc:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f1a48d0:	8fae015c */ 	lw	$t6,0x15c($sp)
/*  f1a48d4:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f1a48d8:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f1a48dc:	afad015c */ 	sw	$t5,0x15c($sp)
/*  f1a48e0:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f1a48e4:	adc70000 */ 	sw	$a3,0x0($t6)
/*  f1a48e8:	8fac015c */ 	lw	$t4,0x15c($sp)
/*  f1a48ec:	01c01825 */ 	or	$v1,$t6,$zero
/*  f1a48f0:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f1a48f4:	afaf015c */ 	sw	$t7,0x15c($sp)
/*  f1a48f8:	ad8a0000 */ 	sw	$t2,0x0($t4)
/*  f1a48fc:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1a4900:	01802025 */ 	or	$a0,$t4,$zero
/*  f1a4904:	0338001a */ 	div	$zero,$t9,$t8
/*  f1a4908:	00006812 */ 	mflo	$t5
/*  f1a490c:	000d6400 */ 	sll	$t4,$t5,0x10
/*  f1a4910:	358ffc00 */ 	ori	$t7,$t4,0xfc00
/*  f1a4914:	17000002 */ 	bnez	$t8,.L0f1a4920
/*  f1a4918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a491c:	0007000d */ 	break	0x7
.L0f1a4920:
/*  f1a4920:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4924:	17010004 */ 	bne	$t8,$at,.L0f1a4938
/*  f1a4928:	3c018000 */ 	lui	$at,0x8000
/*  f1a492c:	17210002 */ 	bne	$t9,$at,.L0f1a4938
/*  f1a4930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4934:	0006000d */ 	break	0x6
.L0f1a4938:
/*  f1a4938:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1a493c:	8fb9015c */ 	lw	$t9,0x15c($sp)
/*  f1a4940:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f1a4944:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f1a4948:	afb8015c */ 	sw	$t8,0x15c($sp)
/*  f1a494c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1a4950:	03202825 */ 	or	$a1,$t9,$zero
/*  f1a4954:	25cd0049 */ 	addiu	$t5,$t6,0x49
/*  f1a4958:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f1a495c:	018f0019 */ 	multu	$t4,$t7
/*  f1a4960:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f1a4964:	258f0025 */ 	addiu	$t7,$t4,0x25
/*  f1a4968:	0000c812 */ 	mflo	$t9
/*  f1a496c:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f1a4970:	00187300 */ 	sll	$t6,$t8,0xc
/*  f1a4974:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1a4978:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f1a497c:	01c86825 */ 	or	$t5,$t6,$t0
/*  f1a4980:	01b87025 */ 	or	$t6,$t5,$t8
/*  f1a4984:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1a4988:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f1a498c:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f1a4990:	258f0029 */ 	addiu	$t7,$t4,0x29
/*  f1a4994:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1a4998:	032d0019 */ 	multu	$t9,$t5
/*  f1a499c:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f1a49a0:	25f90005 */ 	addiu	$t9,$t7,0x5
/*  f1a49a4:	00196880 */ 	sll	$t5,$t9,0x2
/*  f1a49a8:	0000c012 */ 	mflo	$t8
/*  f1a49ac:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f1a49b0:	000e6300 */ 	sll	$t4,$t6,0xc
/*  f1a49b4:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f1a49b8:	01987025 */ 	or	$t6,$t4,$t8
/*  f1a49bc:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1a49c0:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f1a49c4:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f1a49c8:	afb9015c */ 	sw	$t9,0x15c($sp)
/*  f1a49cc:	ade70000 */ 	sw	$a3,0x0($t7)
/*  f1a49d0:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f1a49d4:	8fad015c */ 	lw	$t5,0x15c($sp)
/*  f1a49d8:	01e03025 */ 	or	$a2,$t7,$zero
/*  f1a49dc:	25ac0008 */ 	addiu	$t4,$t5,0x8
/*  f1a49e0:	afac015c */ 	sw	$t4,0x15c($sp)
/*  f1a49e4:	adaa0000 */ 	sw	$t2,0x0($t5)
/*  f1a49e8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1a49ec:	01a01825 */ 	or	$v1,$t5,$zero
/*  f1a49f0:	0178001a */ 	div	$zero,$t3,$t8
/*  f1a49f4:	00007812 */ 	mflo	$t7
/*  f1a49f8:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f1a49fc:	372dfc00 */ 	ori	$t5,$t9,0xfc00
/*  f1a4a00:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f1a4a04:	8fac015c */ 	lw	$t4,0x15c($sp)
/*  f1a4a08:	17000002 */ 	bnez	$t8,.L0f1a4a14
/*  f1a4a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4a10:	0007000d */ 	break	0x7
.L0f1a4a14:
/*  f1a4a14:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4a18:	17010004 */ 	bne	$t8,$at,.L0f1a4a2c
/*  f1a4a1c:	3c018000 */ 	lui	$at,0x8000
/*  f1a4a20:	15610002 */ 	bne	$t3,$at,.L0f1a4a2c
/*  f1a4a24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4a28:	0006000d */ 	break	0x6
.L0f1a4a2c:
/*  f1a4a2c:	25980008 */ 	addiu	$t8,$t4,0x8
/*  f1a4a30:	afb8015c */ 	sw	$t8,0x15c($sp)
/*  f1a4a34:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1a4a38:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f1a4a3c:	01802025 */ 	or	$a0,$t4,$zero
/*  f1a4a40:	25cf002a */ 	addiu	$t7,$t6,0x2a
/*  f1a4a44:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1a4a48:	032d0019 */ 	multu	$t9,$t5
/*  f1a4a4c:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f1a4a50:	272d0044 */ 	addiu	$t5,$t9,0x44
/*  f1a4a54:	00006012 */ 	mflo	$t4
/*  f1a4a58:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f1a4a5c:	00187300 */ 	sll	$t6,$t8,0xc
/*  f1a4a60:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f1a4a64:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f1a4a68:	01c87825 */ 	or	$t7,$t6,$t0
/*  f1a4a6c:	01f87025 */ 	or	$t6,$t7,$t8
/*  f1a4a70:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1a4a74:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a4a78:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f1a4a7c:	272d000a */ 	addiu	$t5,$t9,0xa
/*  f1a4a80:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f1a4a84:	018f0019 */ 	multu	$t4,$t7
/*  f1a4a88:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f1a4a8c:	25ac0024 */ 	addiu	$t4,$t5,0x24
/*  f1a4a90:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f1a4a94:	0000c012 */ 	mflo	$t8
/*  f1a4a98:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f1a4a9c:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f1a4aa0:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f1a4aa4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1a4aa8:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f1a4aac:	8fad015c */ 	lw	$t5,0x15c($sp)
/*  f1a4ab0:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f1a4ab4:	25ac0008 */ 	addiu	$t4,$t5,0x8
/*  f1a4ab8:	afac015c */ 	sw	$t4,0x15c($sp)
/*  f1a4abc:	ada90004 */ 	sw	$t1,0x4($t5)
/*  f1a4ac0:	ada70000 */ 	sw	$a3,0x0($t5)
/*  f1a4ac4:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f1a4ac8:	01a02825 */ 	or	$a1,$t5,$zero
/*  f1a4acc:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f1a4ad0:	afb9015c */ 	sw	$t9,0x15c($sp)
/*  f1a4ad4:	adea0000 */ 	sw	$t2,0x0($t7)
/*  f1a4ad8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1a4adc:	01e03025 */ 	or	$a2,$t7,$zero
/*  f1a4ae0:	01d8001a */ 	div	$zero,$t6,$t8
/*  f1a4ae4:	00006012 */ 	mflo	$t4
/*  f1a4ae8:	000c7c00 */ 	sll	$t7,$t4,0x10
/*  f1a4aec:	35f90400 */ 	ori	$t9,$t7,0x400
/*  f1a4af0:	17000002 */ 	bnez	$t8,.L0f1a4afc
/*  f1a4af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4af8:	0007000d */ 	break	0x7
.L0f1a4afc:
/*  f1a4afc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4b00:	17010004 */ 	bne	$t8,$at,.L0f1a4b14
/*  f1a4b04:	3c018000 */ 	lui	$at,0x8000
/*  f1a4b08:	15c10002 */ 	bne	$t6,$at,.L0f1a4b14
/*  f1a4b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4b10:	0006000d */ 	break	0x6
.L0f1a4b14:
/*  f1a4b14:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f1a4b18:	8fae015c */ 	lw	$t6,0x15c($sp)
/*  f1a4b1c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f1a4b20:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f1a4b24:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f1a4b28:	afb8015c */ 	sw	$t8,0x15c($sp)
/*  f1a4b2c:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f1a4b30:	01c01825 */ 	or	$v1,$t6,$zero
/*  f1a4b34:	25ac0049 */ 	addiu	$t4,$t5,0x49
/*  f1a4b38:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f1a4b3c:	01f90019 */ 	multu	$t7,$t9
/*  f1a4b40:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f1a4b44:	25f90044 */ 	addiu	$t9,$t7,0x44
/*  f1a4b48:	00007012 */ 	mflo	$t6
/*  f1a4b4c:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f1a4b50:	00186b00 */ 	sll	$t5,$t8,0xc
/*  f1a4b54:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1a4b58:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f1a4b5c:	01a86025 */ 	or	$t4,$t5,$t0
/*  f1a4b60:	01986825 */ 	or	$t5,$t4,$t8
/*  f1a4b64:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f1a4b68:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a4b6c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f1a4b70:	25f90029 */ 	addiu	$t9,$t7,0x29
/*  f1a4b74:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1a4b78:	01cc0019 */ 	multu	$t6,$t4
/*  f1a4b7c:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f1a4b80:	272e0024 */ 	addiu	$t6,$t9,0x24
/*  f1a4b84:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f1a4b88:	0000c012 */ 	mflo	$t8
/*  f1a4b8c:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f1a4b90:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f1a4b94:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f1a4b98:	01f86825 */ 	or	$t5,$t7,$t8
/*  f1a4b9c:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f1a4ba0:	8fb9015c */ 	lw	$t9,0x15c($sp)
/*  f1a4ba4:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f1a4ba8:	afae015c */ 	sw	$t6,0x15c($sp)
/*  f1a4bac:	af290004 */ 	sw	$t1,0x4($t9)
/*  f1a4bb0:	af270000 */ 	sw	$a3,0x0($t9)
/*  f1a4bb4:	8fac015c */ 	lw	$t4,0x15c($sp)
/*  f1a4bb8:	03202025 */ 	or	$a0,$t9,$zero
/*  f1a4bbc:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f1a4bc0:	afaf015c */ 	sw	$t7,0x15c($sp)
/*  f1a4bc4:	ad8a0000 */ 	sw	$t2,0x0($t4)
/*  f1a4bc8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1a4bcc:	01802825 */ 	or	$a1,$t4,$zero
/*  f1a4bd0:	0178001a */ 	div	$zero,$t3,$t8
/*  f1a4bd4:	00006812 */ 	mflo	$t5
/*  f1a4bd8:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f1a4bdc:	17000002 */ 	bnez	$t8,.L0f1a4be8
/*  f1a4be0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4be4:	0007000d */ 	break	0x7
.L0f1a4be8:
/*  f1a4be8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4bec:	17010004 */ 	bne	$t8,$at,.L0f1a4c00
/*  f1a4bf0:	3c018000 */ 	lui	$at,0x8000
/*  f1a4bf4:	15610002 */ 	bne	$t3,$at,.L0f1a4c00
/*  f1a4bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a4bfc:	0006000d */ 	break	0x6
.L0f1a4c00:
/*  f1a4c00:	35cc0400 */ 	ori	$t4,$t6,0x400
/*  f1a4c04:	10c00004 */ 	beqz	$a2,.L0f1a4c18
/*  f1a4c08:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f1a4c0c:	3c07ff00 */ 	lui	$a3,0xff00
/*  f1a4c10:	10000003 */ 	beqz	$zero,.L0f1a4c20
/*  f1a4c14:	34e70055 */ 	ori	$a3,$a3,0x55
.L0f1a4c18:
/*  f1a4c18:	3c0700ff */ 	lui	$a3,0xff
/*  f1a4c1c:	34e70055 */ 	ori	$a3,$a3,0x55
.L0f1a4c20:
/*  f1a4c20:	10c00003 */ 	beqz	$a2,.L0f1a4c30
/*  f1a4c24:	3c03ff00 */ 	lui	$v1,0xff00
/*  f1a4c28:	10000003 */ 	beqz	$zero,.L0f1a4c38
/*  f1a4c2c:	34630055 */ 	ori	$v1,$v1,0x55
.L0f1a4c30:
/*  f1a4c30:	3c0300ff */ 	lui	$v1,0xff
/*  f1a4c34:	34630055 */ 	ori	$v1,$v1,0x55
.L0f1a4c38:
/*  f1a4c38:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f1a4c3c:	306f00ff */ 	andi	$t7,$v1,0xff
/*  f1a4c40:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a4c44:	330d00ff */ 	andi	$t5,$t8,0xff
/*  f1a4c48:	01ed0019 */ 	multu	$t7,$t5
/*  f1a4c4c:	00e16024 */ 	and	$t4,$a3,$at
/*  f1a4c50:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4c54:	0000c812 */ 	mflo	$t9
/*  f1a4c58:	00197202 */ 	srl	$t6,$t9,0x8
/*  f1a4c5c:	0fc54df7 */ 	jal	func0f1537dc
/*  f1a4c60:	01cc2825 */ 	or	$a1,$t6,$t4
/*  f1a4c64:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*  f1a4c68:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4c6c:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f1a4c70:	13000004 */ 	beqz	$t8,.L0f1a4c84
/*  f1a4c74:	3c07ff69 */ 	lui	$a3,0xff69
/*  f1a4c78:	34e769aa */ 	ori	$a3,$a3,0x69aa
/*  f1a4c7c:	10000003 */ 	beqz	$zero,.L0f1a4c8c
/*  f1a4c80:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f1a4c84:
/*  f1a4c84:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f1a4c88:	00403825 */ 	or	$a3,$v0,$zero
.L0f1a4c8c:
/*  f1a4c8c:	11e00004 */ 	beqz	$t7,.L0f1a4ca0
/*  f1a4c90:	305900ff */ 	andi	$t9,$v0,0xff
/*  f1a4c94:	3c03ff69 */ 	lui	$v1,0xff69
/*  f1a4c98:	10000002 */ 	beqz	$zero,.L0f1a4ca4
/*  f1a4c9c:	346369aa */ 	ori	$v1,$v1,0x69aa
.L0f1a4ca0:
/*  f1a4ca0:	00401825 */ 	or	$v1,$v0,$zero
.L0f1a4ca4:
/*  f1a4ca4:	306d00ff */ 	andi	$t5,$v1,0xff
/*  f1a4ca8:	01b90019 */ 	multu	$t5,$t9
/*  f1a4cac:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a4cb0:	00e1c024 */ 	and	$t8,$a3,$at
/*  f1a4cb4:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f1a4cb8:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4cbc:	24a5987c */ 	addiu	$a1,$a1,-26500
/*  f1a4cc0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a4cc4:	00007012 */ 	mflo	$t6
/*  f1a4cc8:	000e6202 */ 	srl	$t4,$t6,0x8
/*  f1a4ccc:	01987825 */ 	or	$t7,$t4,$t8
/*  f1a4cd0:	afaf00ac */ 	sw	$t7,0xac($sp)
/*  f1a4cd4:	0c004dad */ 	jal	sprintf
/*  f1a4cd8:	95a6045c */ 	lhu	$a2,0x45c($t5)
/*  f1a4cdc:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a4ce0:	27af0148 */ 	addiu	$t7,$sp,0x148
/*  f1a4ce4:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4ce8:	272e005d */ 	addiu	$t6,$t9,0x5d
/*  f1a4cec:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f1a4cf0:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f1a4cf4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a4cf8:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4cfc:	2598000e */ 	addiu	$t8,$t4,0xe
/*  f1a4d00:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f1a4d04:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4d08:	0fc54e16 */ 	jal	func0f153858
/*  f1a4d0c:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a4d10:	0c002f02 */ 	jal	func0000bc08
/*  f1a4d14:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4d18:	0c002f06 */ 	jal	func0000bc18
/*  f1a4d1c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4d20:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a4d24:	3c198008 */ 	lui	$t9,0x8008
/*  f1a4d28:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f1a4d2c:	8dadfb10 */ 	lw	$t5,-0x4f0($t5)
/*  f1a4d30:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f1a4d34:	87ac0044 */ 	lh	$t4,0x44($sp)
/*  f1a4d38:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4d3c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4d40:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4d44:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a4d48:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a4d4c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a4d50:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a4d54:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a4d58:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a4d5c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a4d60:	0fc5580f */ 	jal	func0f15603c
/*  f1a4d64:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1a4d68:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4d6c:	0fc5b9f1 */ 	jal	langGet
/*  f1a4d70:	240451cd */ 	addiu	$a0,$zero,0x51cd
/*  f1a4d74:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a4d78:	0c004dad */ 	jal	sprintf
/*  f1a4d7c:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a4d80:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a4d84:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f1a4d88:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4d8c:	270f007a */ 	addiu	$t7,$t8,0x7a
/*  f1a4d90:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f1a4d94:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f1a4d98:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a4d9c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4da0:	25b9000e */ 	addiu	$t9,$t5,0xe
/*  f1a4da4:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f1a4da8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4dac:	0fc54e16 */ 	jal	func0f153858
/*  f1a4db0:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a4db4:	0c002f02 */ 	jal	func0000bc08
/*  f1a4db8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4dbc:	0c002f06 */ 	jal	func0000bc18
/*  f1a4dc0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4dc4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a4dc8:	3c188008 */ 	lui	$t8,0x8008
/*  f1a4dcc:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f1a4dd0:	8d8cfb10 */ 	lw	$t4,-0x4f0($t4)
/*  f1a4dd4:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f1a4dd8:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f1a4ddc:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4de0:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4de4:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4de8:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a4dec:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a4df0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a4df4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a4df8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a4dfc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a4e00:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a4e04:	0fc5580f */ 	jal	func0f15603c
/*  f1a4e08:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a4e0c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f1a4e10:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4e14:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4e18:	9726045c */ 	lhu	$a2,0x45c($t9)
/*  f1a4e1c:	24a59880 */ 	addiu	$a1,$a1,-26496
/*  f1a4e20:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a4e24:	00067080 */ 	sll	$t6,$a2,0x2
/*  f1a4e28:	01c67021 */ 	addu	$t6,$t6,$a2
/*  f1a4e2c:	0c004dad */ 	jal	sprintf
/*  f1a4e30:	000e3040 */ 	sll	$a2,$t6,0x1
/*  f1a4e34:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a4e38:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f1a4e3c:	3c078008 */ 	lui	$a3,0x8008
/*  f1a4e40:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f1a4e44:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a4e48:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a4e4c:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a4e50:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a4e54:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a4e58:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a4e5c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a4e60:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f1a4e64:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4e68:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4e6c:	030f6823 */ 	subu	$t5,$t8,$t7
/*  f1a4e70:	25b900b6 */ 	addiu	$t9,$t5,0xb6
/*  f1a4e74:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f1a4e78:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f1a4e7c:	27b80148 */ 	addiu	$t8,$sp,0x148
/*  f1a4e80:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a4e84:	25cc000e */ 	addiu	$t4,$t6,0xe
/*  f1a4e88:	afac0150 */ 	sw	$t4,0x150($sp)
/*  f1a4e8c:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4e90:	0fc54e16 */ 	jal	func0f153858
/*  f1a4e94:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a4e98:	0c002f02 */ 	jal	func0000bc08
/*  f1a4e9c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4ea0:	0c002f06 */ 	jal	func0000bc18
/*  f1a4ea4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4ea8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a4eac:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a4eb0:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f1a4eb4:	8deffb10 */ 	lw	$t7,-0x4f0($t7)
/*  f1a4eb8:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1a4ebc:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f1a4ec0:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4ec4:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4ec8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4ecc:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a4ed0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a4ed4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a4ed8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a4edc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1a4ee0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a4ee4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1a4ee8:	0fc5580f */ 	jal	func0f15603c
/*  f1a4eec:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a4ef0:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1a4ef4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4ef8:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a4efc:	24a59884 */ 	addiu	$a1,$a1,-26492
/*  f1a4f00:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a4f04:	0c004dad */ 	jal	sprintf
/*  f1a4f08:	9586045e */ 	lhu	$a2,0x45e($t4)
/*  f1a4f0c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a4f10:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f1a4f14:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4f18:	270f005d */ 	addiu	$t7,$t8,0x5d
/*  f1a4f1c:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f1a4f20:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f1a4f24:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a4f28:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4f2c:	25b90019 */ 	addiu	$t9,$t5,0x19
/*  f1a4f30:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f1a4f34:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4f38:	0fc54e16 */ 	jal	func0f153858
/*  f1a4f3c:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a4f40:	0c002f02 */ 	jal	func0000bc08
/*  f1a4f44:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4f48:	0c002f06 */ 	jal	func0000bc18
/*  f1a4f4c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4f50:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a4f54:	3c188008 */ 	lui	$t8,0x8008
/*  f1a4f58:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f1a4f5c:	8d8cfb10 */ 	lw	$t4,-0x4f0($t4)
/*  f1a4f60:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f1a4f64:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f1a4f68:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4f6c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4f70:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4f74:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a4f78:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a4f7c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a4f80:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a4f84:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a4f88:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a4f8c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a4f90:	0fc5580f */ 	jal	func0f15603c
/*  f1a4f94:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a4f98:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4f9c:	0fc5b9f1 */ 	jal	langGet
/*  f1a4fa0:	240451ce */ 	addiu	$a0,$zero,0x51ce
/*  f1a4fa4:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a4fa8:	0c004dad */ 	jal	sprintf
/*  f1a4fac:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a4fb0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a4fb4:	27af0148 */ 	addiu	$t7,$sp,0x148
/*  f1a4fb8:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a4fbc:	272e007a */ 	addiu	$t6,$t9,0x7a
/*  f1a4fc0:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f1a4fc4:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f1a4fc8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a4fcc:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a4fd0:	25980019 */ 	addiu	$t8,$t4,0x19
/*  f1a4fd4:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f1a4fd8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a4fdc:	0fc54e16 */ 	jal	func0f153858
/*  f1a4fe0:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a4fe4:	0c002f02 */ 	jal	func0000bc08
/*  f1a4fe8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4fec:	0c002f06 */ 	jal	func0000bc18
/*  f1a4ff0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4ff4:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a4ff8:	3c198008 */ 	lui	$t9,0x8008
/*  f1a4ffc:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f1a5000:	8dadfb10 */ 	lw	$t5,-0x4f0($t5)
/*  f1a5004:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f1a5008:	87ac0044 */ 	lh	$t4,0x44($sp)
/*  f1a500c:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5010:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5014:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5018:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a501c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5020:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5024:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5028:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a502c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a5030:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a5034:	0fc5580f */ 	jal	func0f15603c
/*  f1a5038:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1a503c:	8fb80140 */ 	lw	$t8,0x140($sp)
/*  f1a5040:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5044:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a5048:	9706045e */ 	lhu	$a2,0x45e($t8)
/*  f1a504c:	24a59888 */ 	addiu	$a1,$a1,-26488
/*  f1a5050:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5054:	00067880 */ 	sll	$t7,$a2,0x2
/*  f1a5058:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f1a505c:	0c004dad */ 	jal	sprintf
/*  f1a5060:	01e03025 */ 	or	$a2,$t7,$zero
/*  f1a5064:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a5068:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f1a506c:	3c078008 */ 	lui	$a3,0x8008
/*  f1a5070:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f1a5074:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a5078:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a507c:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a5080:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a5084:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a5088:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a508c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a5090:	8fae014c */ 	lw	$t6,0x14c($sp)
/*  f1a5094:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5098:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a509c:	032e6023 */ 	subu	$t4,$t9,$t6
/*  f1a50a0:	259800b6 */ 	addiu	$t8,$t4,0xb6
/*  f1a50a4:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f1a50a8:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f1a50ac:	27b90148 */ 	addiu	$t9,$sp,0x148
/*  f1a50b0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a50b4:	25ed0019 */ 	addiu	$t5,$t7,0x19
/*  f1a50b8:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f1a50bc:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a50c0:	0fc54e16 */ 	jal	func0f153858
/*  f1a50c4:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a50c8:	0c002f02 */ 	jal	func0000bc08
/*  f1a50cc:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a50d0:	0c002f06 */ 	jal	func0000bc18
/*  f1a50d4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a50d8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1a50dc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a50e0:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f1a50e4:	8dcefb10 */ 	lw	$t6,-0x4f0($t6)
/*  f1a50e8:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f1a50ec:	87af0044 */ 	lh	$t7,0x44($sp)
/*  f1a50f0:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a50f4:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a50f8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a50fc:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5100:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5104:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5108:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a510c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a5110:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5114:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1a5118:	0fc5580f */ 	jal	func0f15603c
/*  f1a511c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1a5120:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f1a5124:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5128:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a512c:	24a5988c */ 	addiu	$a1,$a1,-26484
/*  f1a5130:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5134:	0c004dad */ 	jal	sprintf
/*  f1a5138:	95a60460 */ 	lhu	$a2,0x460($t5)
/*  f1a513c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a5140:	27af0148 */ 	addiu	$t7,$sp,0x148
/*  f1a5144:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5148:	272e005d */ 	addiu	$t6,$t9,0x5d
/*  f1a514c:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f1a5150:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f1a5154:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a5158:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a515c:	25980024 */ 	addiu	$t8,$t4,0x24
/*  f1a5160:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f1a5164:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5168:	0fc54e16 */ 	jal	func0f153858
/*  f1a516c:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5170:	0c002f02 */ 	jal	func0000bc08
/*  f1a5174:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5178:	0c002f06 */ 	jal	func0000bc18
/*  f1a517c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5180:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a5184:	3c198008 */ 	lui	$t9,0x8008
/*  f1a5188:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f1a518c:	8dadfb10 */ 	lw	$t5,-0x4f0($t5)
/*  f1a5190:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f1a5194:	87ac0044 */ 	lh	$t4,0x44($sp)
/*  f1a5198:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a519c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a51a0:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a51a4:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a51a8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a51ac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a51b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a51b4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a51b8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a51bc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a51c0:	0fc5580f */ 	jal	func0f15603c
/*  f1a51c4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1a51c8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a51cc:	0fc5b9f1 */ 	jal	langGet
/*  f1a51d0:	240451cf */ 	addiu	$a0,$zero,0x51cf
/*  f1a51d4:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a51d8:	0c004dad */ 	jal	sprintf
/*  f1a51dc:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a51e0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a51e4:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f1a51e8:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a51ec:	270f007a */ 	addiu	$t7,$t8,0x7a
/*  f1a51f0:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f1a51f4:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f1a51f8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a51fc:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5200:	25b90024 */ 	addiu	$t9,$t5,0x24
/*  f1a5204:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f1a5208:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a520c:	0fc54e16 */ 	jal	func0f153858
/*  f1a5210:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5214:	0c002f02 */ 	jal	func0000bc08
/*  f1a5218:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a521c:	0c002f06 */ 	jal	func0000bc18
/*  f1a5220:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5224:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a5228:	3c188008 */ 	lui	$t8,0x8008
/*  f1a522c:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f1a5230:	8d8cfb10 */ 	lw	$t4,-0x4f0($t4)
/*  f1a5234:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f1a5238:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f1a523c:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5240:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5244:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5248:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a524c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5250:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5254:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5258:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a525c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a5260:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a5264:	0fc5580f */ 	jal	func0f15603c
/*  f1a5268:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a526c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f1a5270:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5274:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a5278:	97260460 */ 	lhu	$a2,0x460($t9)
/*  f1a527c:	24a59890 */ 	addiu	$a1,$a1,-26480
/*  f1a5280:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5284:	00067040 */ 	sll	$t6,$a2,0x1
/*  f1a5288:	0c004dad */ 	jal	sprintf
/*  f1a528c:	01c03025 */ 	or	$a2,$t6,$zero
/*  f1a5290:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a5294:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f1a5298:	3c078008 */ 	lui	$a3,0x8008
/*  f1a529c:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f1a52a0:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a52a4:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a52a8:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a52ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a52b0:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a52b4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a52b8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a52bc:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f1a52c0:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a52c4:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a52c8:	030f6823 */ 	subu	$t5,$t8,$t7
/*  f1a52cc:	25b900b6 */ 	addiu	$t9,$t5,0xb6
/*  f1a52d0:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f1a52d4:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f1a52d8:	27b80148 */ 	addiu	$t8,$sp,0x148
/*  f1a52dc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a52e0:	25cc0024 */ 	addiu	$t4,$t6,0x24
/*  f1a52e4:	afac0150 */ 	sw	$t4,0x150($sp)
/*  f1a52e8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a52ec:	0fc54e16 */ 	jal	func0f153858
/*  f1a52f0:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a52f4:	0c002f02 */ 	jal	func0000bc08
/*  f1a52f8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a52fc:	0c002f06 */ 	jal	func0000bc18
/*  f1a5300:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5304:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a5308:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a530c:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f1a5310:	8deffb10 */ 	lw	$t7,-0x4f0($t7)
/*  f1a5314:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1a5318:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f1a531c:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5320:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5324:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5328:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a532c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5330:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5334:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5338:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1a533c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a5340:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1a5344:	0fc5580f */ 	jal	func0f15603c
/*  f1a5348:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a534c:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1a5350:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5354:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a5358:	24a59894 */ 	addiu	$a1,$a1,-26476
/*  f1a535c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5360:	0c004dad */ 	jal	sprintf
/*  f1a5364:	95860462 */ 	lhu	$a2,0x462($t4)
/*  f1a5368:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a536c:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f1a5370:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5374:	270f005d */ 	addiu	$t7,$t8,0x5d
/*  f1a5378:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f1a537c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f1a5380:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5384:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5388:	25b9002f */ 	addiu	$t9,$t5,0x2f
/*  f1a538c:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f1a5390:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5394:	0fc54e16 */ 	jal	func0f153858
/*  f1a5398:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a539c:	0c002f02 */ 	jal	func0000bc08
/*  f1a53a0:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a53a4:	0c002f06 */ 	jal	func0000bc18
/*  f1a53a8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a53ac:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a53b0:	3c188008 */ 	lui	$t8,0x8008
/*  f1a53b4:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f1a53b8:	8d8cfb10 */ 	lw	$t4,-0x4f0($t4)
/*  f1a53bc:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f1a53c0:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f1a53c4:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a53c8:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a53cc:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a53d0:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a53d4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a53d8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a53dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a53e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a53e4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a53e8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a53ec:	0fc5580f */ 	jal	func0f15603c
/*  f1a53f0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a53f4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a53f8:	0fc5b9f1 */ 	jal	langGet
/*  f1a53fc:	240451d0 */ 	addiu	$a0,$zero,0x51d0
/*  f1a5400:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f1a5404:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5408:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a540c:	0c004dad */ 	jal	sprintf
/*  f1a5410:	97260462 */ 	lhu	$a2,0x462($t9)
/*  f1a5414:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1a5418:	27ad0148 */ 	addiu	$t5,$sp,0x148
/*  f1a541c:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5420:	25cc007a */ 	addiu	$t4,$t6,0x7a
/*  f1a5424:	afac0154 */ 	sw	$t4,0x154($sp)
/*  f1a5428:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1a542c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a5430:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5434:	270f002f */ 	addiu	$t7,$t8,0x2f
/*  f1a5438:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f1a543c:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5440:	0fc54e16 */ 	jal	func0f153858
/*  f1a5444:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5448:	0c002f02 */ 	jal	func0000bc08
/*  f1a544c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5450:	0c002f06 */ 	jal	func0000bc18
/*  f1a5454:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5458:	3c198008 */ 	lui	$t9,0x8008
/*  f1a545c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1a5460:	8dcefb0c */ 	lw	$t6,-0x4f4($t6)
/*  f1a5464:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f1a5468:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f1a546c:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f1a5470:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5474:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5478:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a547c:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5480:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5484:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5488:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a548c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a5490:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a5494:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1a5498:	0fc5580f */ 	jal	func0f15603c
/*  f1a549c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1a54a0:	8faf0140 */ 	lw	$t7,0x140($sp)
/*  f1a54a4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a54a8:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a54ac:	24a59898 */ 	addiu	$a1,$a1,-26472
/*  f1a54b0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a54b4:	0c004dad */ 	jal	sprintf
/*  f1a54b8:	95e60462 */ 	lhu	$a2,0x462($t7)
/*  f1a54bc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a54c0:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f1a54c4:	3c078008 */ 	lui	$a3,0x8008
/*  f1a54c8:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f1a54cc:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a54d0:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a54d4:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a54d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a54dc:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a54e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a54e4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a54e8:	8fae014c */ 	lw	$t6,0x14c($sp)
/*  f1a54ec:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a54f0:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a54f4:	032e6023 */ 	subu	$t4,$t9,$t6
/*  f1a54f8:	259800b6 */ 	addiu	$t8,$t4,0xb6
/*  f1a54fc:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f1a5500:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f1a5504:	27b90148 */ 	addiu	$t9,$sp,0x148
/*  f1a5508:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a550c:	25ed002f */ 	addiu	$t5,$t7,0x2f
/*  f1a5510:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f1a5514:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5518:	0fc54e16 */ 	jal	func0f153858
/*  f1a551c:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5520:	0c002f02 */ 	jal	func0000bc08
/*  f1a5524:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5528:	0c002f06 */ 	jal	func0000bc18
/*  f1a552c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5530:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1a5534:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a5538:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f1a553c:	8dcefb10 */ 	lw	$t6,-0x4f0($t6)
/*  f1a5540:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f1a5544:	87af0044 */ 	lh	$t7,0x44($sp)
/*  f1a5548:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a554c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5550:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5554:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5558:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a555c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5560:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5564:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a5568:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a556c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1a5570:	0fc5580f */ 	jal	func0f15603c
/*  f1a5574:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1a5578:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a557c:	0fc5b9f1 */ 	jal	langGet
/*  f1a5580:	240451d1 */ 	addiu	$a0,$zero,0x51d1
/*  f1a5584:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5588:	0c004dad */ 	jal	sprintf
/*  f1a558c:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a5590:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f1a5594:	27b80148 */ 	addiu	$t8,$sp,0x148
/*  f1a5598:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a559c:	25b90085 */ 	addiu	$t9,$t5,0x85
/*  f1a55a0:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f1a55a4:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f1a55a8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a55ac:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a55b0:	25cc003f */ 	addiu	$t4,$t6,0x3f
/*  f1a55b4:	afac0150 */ 	sw	$t4,0x150($sp)
/*  f1a55b8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a55bc:	0fc54e16 */ 	jal	func0f153858
/*  f1a55c0:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a55c4:	0c002f02 */ 	jal	func0000bc08
/*  f1a55c8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a55cc:	0c002f06 */ 	jal	func0000bc18
/*  f1a55d0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a55d4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a55d8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a55dc:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f1a55e0:	8deffb10 */ 	lw	$t7,-0x4f0($t7)
/*  f1a55e4:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1a55e8:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f1a55ec:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a55f0:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a55f4:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a55f8:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a55fc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5600:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5604:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5608:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1a560c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a5610:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1a5614:	0fc5580f */ 	jal	func0f15603c
/*  f1a5618:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a561c:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1a5620:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5624:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a5628:	958f045c */ 	lhu	$t7,0x45c($t4)
/*  f1a562c:	95980462 */ 	lhu	$t8,0x462($t4)
/*  f1a5630:	9599045e */ 	lhu	$t9,0x45e($t4)
/*  f1a5634:	24a5989c */ 	addiu	$a1,$a1,-26468
/*  f1a5638:	030f6821 */ 	addu	$t5,$t8,$t7
/*  f1a563c:	95980460 */ 	lhu	$t8,0x460($t4)
/*  f1a5640:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f1a5644:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5648:	0c004dad */ 	jal	sprintf
/*  f1a564c:	01d83021 */ 	addu	$a2,$t6,$t8
/*  f1a5650:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a5654:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f1a5658:	3c078008 */ 	lui	$a3,0x8008
/*  f1a565c:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f1a5660:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a5664:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a5668:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a566c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a5670:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a5674:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a5678:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f1a567c:	8fb9014c */ 	lw	$t9,0x14c($sp)
/*  f1a5680:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5684:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5688:	01b96023 */ 	subu	$t4,$t5,$t9
/*  f1a568c:	258e00bc */ 	addiu	$t6,$t4,0xbc
/*  f1a5690:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f1a5694:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1a5698:	27ad0148 */ 	addiu	$t5,$sp,0x148
/*  f1a569c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a56a0:	270f003f */ 	addiu	$t7,$t8,0x3f
/*  f1a56a4:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f1a56a8:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a56ac:	0fc54e16 */ 	jal	func0f153858
/*  f1a56b0:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a56b4:	0c002f02 */ 	jal	func0000bc08
/*  f1a56b8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a56bc:	0c002f06 */ 	jal	func0000bc18
/*  f1a56c0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a56c4:	3c198008 */ 	lui	$t9,0x8008
/*  f1a56c8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a56cc:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f1a56d0:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f1a56d4:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f1a56d8:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f1a56dc:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a56e0:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a56e4:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a56e8:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a56ec:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a56f0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a56f4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a56f8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a56fc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a5700:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a5704:	0fc5580f */ 	jal	func0f15603c
/*  f1a5708:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1a570c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5710:	0fc5b9f1 */ 	jal	langGet
/*  f1a5714:	240451d2 */ 	addiu	$a0,$zero,0x51d2
/*  f1a5718:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a571c:	0c004dad */ 	jal	sprintf
/*  f1a5720:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a5724:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a5728:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f1a572c:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5730:	25ed0053 */ 	addiu	$t5,$t7,0x53
/*  f1a5734:	afad0154 */ 	sw	$t5,0x154($sp)
/*  f1a5738:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f1a573c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5740:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5744:	272c0001 */ 	addiu	$t4,$t9,0x1
/*  f1a5748:	afac0150 */ 	sw	$t4,0x150($sp)
/*  f1a574c:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5750:	0fc54e16 */ 	jal	func0f153858
/*  f1a5754:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5758:	0c002f02 */ 	jal	func0000bc08
/*  f1a575c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5760:	0c002f06 */ 	jal	func0000bc18
/*  f1a5764:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5768:	3c188008 */ 	lui	$t8,0x8008
/*  f1a576c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a5770:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f1a5774:	8f18fb10 */ 	lw	$t8,-0x4f0($t8)
/*  f1a5778:	8fad00ac */ 	lw	$t5,0xac($sp)
/*  f1a577c:	87b90044 */ 	lh	$t9,0x44($sp)
/*  f1a5780:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5784:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5788:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a578c:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5790:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5794:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5798:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a579c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1a57a0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a57a4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1a57a8:	0fc5580f */ 	jal	func0f15603c
/*  f1a57ac:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1a57b0:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a57b4:	0fc5b9f1 */ 	jal	langGet
/*  f1a57b8:	240451d3 */ 	addiu	$a0,$zero,0x51d3
/*  f1a57bc:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a57c0:	0c004dad */ 	jal	sprintf
/*  f1a57c4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a57c8:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f1a57cc:	27ad0148 */ 	addiu	$t5,$sp,0x148
/*  f1a57d0:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a57d4:	258e0026 */ 	addiu	$t6,$t4,0x26
/*  f1a57d8:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f1a57dc:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1a57e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a57e4:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a57e8:	270f0023 */ 	addiu	$t7,$t8,0x23
/*  f1a57ec:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f1a57f0:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a57f4:	0fc54e16 */ 	jal	func0f153858
/*  f1a57f8:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a57fc:	0c002f02 */ 	jal	func0000bc08
/*  f1a5800:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5804:	0c002f06 */ 	jal	func0000bc18
/*  f1a5808:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a580c:	3c198008 */ 	lui	$t9,0x8008
/*  f1a5810:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a5814:	8d8cfafc */ 	lw	$t4,-0x504($t4)
/*  f1a5818:	8f39fb00 */ 	lw	$t9,-0x500($t9)
/*  f1a581c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a5820:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a5824:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a5828:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f1a582c:	87ac0044 */ 	lh	$t4,0x44($sp)
/*  f1a5830:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5834:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f1a5838:	00187a00 */ 	sll	$t7,$t8,0x8
/*  f1a583c:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f1a5840:	000f6a02 */ 	srl	$t5,$t7,0x8
/*  f1a5844:	01a1c825 */ 	or	$t9,$t5,$at
/*  f1a5848:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1a584c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5850:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5854:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5858:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a585c:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5860:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5864:	0fc5580f */ 	jal	func0f15603c
/*  f1a5868:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1a586c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5870:	0fc5b9f1 */ 	jal	langGet
/*  f1a5874:	240451d4 */ 	addiu	$a0,$zero,0x51d4
/*  f1a5878:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a587c:	0c004dad */ 	jal	sprintf
/*  f1a5880:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a5884:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1a5888:	27b90148 */ 	addiu	$t9,$sp,0x148
/*  f1a588c:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5890:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f1a5894:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f1a5898:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f1a589c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a58a0:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a58a4:	25ed001a */ 	addiu	$t5,$t7,0x1a
/*  f1a58a8:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f1a58ac:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a58b0:	0fc54e16 */ 	jal	func0f153858
/*  f1a58b4:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a58b8:	0c002f02 */ 	jal	func0000bc08
/*  f1a58bc:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a58c0:	0c002f06 */ 	jal	func0000bc18
/*  f1a58c4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a58c8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1a58cc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1a58d0:	8dcefafc */ 	lw	$t6,-0x504($t6)
/*  f1a58d4:	8d8cfb00 */ 	lw	$t4,-0x500($t4)
/*  f1a58d8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a58dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a58e0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a58e4:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f1a58e8:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f1a58ec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a58f0:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f1a58f4:	000f6a00 */ 	sll	$t5,$t7,0x8
/*  f1a58f8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f1a58fc:	000dca02 */ 	srl	$t9,$t5,0x8
/*  f1a5900:	03216025 */ 	or	$t4,$t9,$at
/*  f1a5904:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1a5908:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a590c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5910:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5914:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5918:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a591c:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5920:	0fc5580f */ 	jal	func0f15603c
/*  f1a5924:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a5928:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a592c:	0fc5b9f1 */ 	jal	langGet
/*  f1a5930:	240451d5 */ 	addiu	$a0,$zero,0x51d5
/*  f1a5934:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5938:	0c004dad */ 	jal	sprintf
/*  f1a593c:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a5940:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a5944:	27ac0148 */ 	addiu	$t4,$sp,0x148
/*  f1a5948:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a594c:	270f0018 */ 	addiu	$t7,$t8,0x18
/*  f1a5950:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f1a5954:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f1a5958:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a595c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5960:	25b90010 */ 	addiu	$t9,$t5,0x10
/*  f1a5964:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f1a5968:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a596c:	0fc54e16 */ 	jal	func0f153858
/*  f1a5970:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5974:	0c002f02 */ 	jal	func0000bc08
/*  f1a5978:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a597c:	0c002f06 */ 	jal	func0000bc18
/*  f1a5980:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5984:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1a5988:	3c188008 */ 	lui	$t8,0x8008
/*  f1a598c:	8f18fafc */ 	lw	$t8,-0x504($t8)
/*  f1a5990:	8dcefb00 */ 	lw	$t6,-0x500($t6)
/*  f1a5994:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a5998:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a599c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a59a0:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f1a59a4:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f1a59a8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a59ac:	31ed00ff */ 	andi	$t5,$t7,0xff
/*  f1a59b0:	000dca00 */ 	sll	$t9,$t5,0x8
/*  f1a59b4:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f1a59b8:	00196202 */ 	srl	$t4,$t9,0x8
/*  f1a59bc:	01817025 */ 	or	$t6,$t4,$at
/*  f1a59c0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a59c4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a59c8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a59cc:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a59d0:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a59d4:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a59d8:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a59dc:	0fc5580f */ 	jal	func0f15603c
/*  f1a59e0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1a59e4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a59e8:	0fc5b9f1 */ 	jal	langGet
/*  f1a59ec:	240451d6 */ 	addiu	$a0,$zero,0x51d6
/*  f1a59f0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a59f4:	0c004dad */ 	jal	sprintf
/*  f1a59f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a59fc:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a5a00:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f1a5a04:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5a08:	25ed000e */ 	addiu	$t5,$t7,0xe
/*  f1a5a0c:	afad0154 */ 	sw	$t5,0x154($sp)
/*  f1a5a10:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f1a5a14:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5a18:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5a1c:	272c0004 */ 	addiu	$t4,$t9,0x4
/*  f1a5a20:	afac0150 */ 	sw	$t4,0x150($sp)
/*  f1a5a24:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5a28:	0fc54e16 */ 	jal	func0f153858
/*  f1a5a2c:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*  f1a5a30:	0c002f02 */ 	jal	func0000bc08
/*  f1a5a34:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5a38:	0c002f06 */ 	jal	func0000bc18
/*  f1a5a3c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5a40:	3c188008 */ 	lui	$t8,0x8008
/*  f1a5a44:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a5a48:	8deffafc */ 	lw	$t7,-0x504($t7)
/*  f1a5a4c:	8f18fb00 */ 	lw	$t8,-0x500($t8)
/*  f1a5a50:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a5a54:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1a5a58:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a5a5c:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f1a5a60:	87af0044 */ 	lh	$t7,0x44($sp)
/*  f1a5a64:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a5a68:	31b900ff */ 	andi	$t9,$t5,0xff
/*  f1a5a6c:	00196200 */ 	sll	$t4,$t9,0x8
/*  f1a5a70:	01996023 */ 	subu	$t4,$t4,$t9
/*  f1a5a74:	000c7202 */ 	srl	$t6,$t4,0x8
/*  f1a5a78:	01c1c025 */ 	or	$t8,$t6,$at
/*  f1a5a7c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1a5a80:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a5a84:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a5a88:	8fa4015c */ 	lw	$a0,0x15c($sp)
/*  f1a5a8c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f1a5a90:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f1a5a94:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1a5a98:	0fc5580f */ 	jal	func0f15603c
/*  f1a5a9c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1a5aa0:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5aa4:	0fc54e0e */ 	jal	func0f153838
/*  f1a5aa8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5aac:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5ab0:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5ab4:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5ab8:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*  f1a5abc:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f1a5ac0:	250d0025 */ 	addiu	$t5,$t0,0x25
/*  f1a5ac4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a5ac8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5acc:	25060024 */ 	addiu	$a2,$t0,0x24
/*  f1a5ad0:	2465002d */ 	addiu	$a1,$v1,0x2d
/*  f1a5ad4:	24670051 */ 	addiu	$a3,$v1,0x51
/*  f1a5ad8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a5adc:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f1a5ae0:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1a5ae4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5ae8:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5aec:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5af0:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f1a5af4:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f1a5af8:	250e002d */ 	addiu	$t6,$t0,0x2d
/*  f1a5afc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5b00:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5b04:	2506002c */ 	addiu	$a2,$t0,0x2c
/*  f1a5b08:	24650034 */ 	addiu	$a1,$v1,0x34
/*  f1a5b0c:	24670054 */ 	addiu	$a3,$v1,0x54
/*  f1a5b10:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a5b14:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5b18:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a5b1c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5b20:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5b24:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5b28:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*  f1a5b2c:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f1a5b30:	250d0033 */ 	addiu	$t5,$t0,0x33
/*  f1a5b34:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a5b38:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5b3c:	25060032 */ 	addiu	$a2,$t0,0x32
/*  f1a5b40:	2465003e */ 	addiu	$a1,$v1,0x3e
/*  f1a5b44:	24670057 */ 	addiu	$a3,$v1,0x57
/*  f1a5b48:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a5b4c:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5b50:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1a5b54:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5b58:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5b5c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5b60:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f1a5b64:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f1a5b68:	250e003d */ 	addiu	$t6,$t0,0x3d
/*  f1a5b6c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5b70:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5b74:	2506003c */ 	addiu	$a2,$t0,0x3c
/*  f1a5b78:	24650046 */ 	addiu	$a1,$v1,0x46
/*  f1a5b7c:	2467005a */ 	addiu	$a3,$v1,0x5a
/*  f1a5b80:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a5b84:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5b88:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1a5b8c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5b90:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5b94:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5b98:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f1a5b9c:	250d0025 */ 	addiu	$t5,$t0,0x25
/*  f1a5ba0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a5ba4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5ba8:	25060011 */ 	addiu	$a2,$t0,0x11
/*  f1a5bac:	24650051 */ 	addiu	$a1,$v1,0x51
/*  f1a5bb0:	24670052 */ 	addiu	$a3,$v1,0x52
/*  f1a5bb4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f1a5bb8:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5bbc:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1a5bc0:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5bc4:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5bc8:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5bcc:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f1a5bd0:	2519002d */ 	addiu	$t9,$t0,0x2d
/*  f1a5bd4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a5bd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5bdc:	2506001c */ 	addiu	$a2,$t0,0x1c
/*  f1a5be0:	24650054 */ 	addiu	$a1,$v1,0x54
/*  f1a5be4:	24670055 */ 	addiu	$a3,$v1,0x55
/*  f1a5be8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f1a5bec:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5bf0:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1a5bf4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5bf8:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5bfc:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5c00:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f1a5c04:	250c0033 */ 	addiu	$t4,$t0,0x33
/*  f1a5c08:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a5c0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5c10:	25060027 */ 	addiu	$a2,$t0,0x27
/*  f1a5c14:	24650057 */ 	addiu	$a1,$v1,0x57
/*  f1a5c18:	24670058 */ 	addiu	$a3,$v1,0x58
/*  f1a5c1c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f1a5c20:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5c24:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1a5c28:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5c2c:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5c30:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5c34:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f1a5c38:	250e003d */ 	addiu	$t6,$t0,0x3d
/*  f1a5c3c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a5c40:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5c44:	25060032 */ 	addiu	$a2,$t0,0x32
/*  f1a5c48:	2465005a */ 	addiu	$a1,$v1,0x5a
/*  f1a5c4c:	2467005b */ 	addiu	$a3,$v1,0x5b
/*  f1a5c50:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f1a5c54:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5c58:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1a5c5c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5c60:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5c64:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5c68:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f1a5c6c:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f1a5c70:	25180012 */ 	addiu	$t8,$t0,0x12
/*  f1a5c74:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a5c78:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5c7c:	25060011 */ 	addiu	$a2,$t0,0x11
/*  f1a5c80:	24650051 */ 	addiu	$a1,$v1,0x51
/*  f1a5c84:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f1a5c88:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1a5c8c:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5c90:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1a5c94:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5c98:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5c9c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5ca0:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f1a5ca4:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1a5ca8:	2519001d */ 	addiu	$t9,$t0,0x1d
/*  f1a5cac:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a5cb0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5cb4:	2506001c */ 	addiu	$a2,$t0,0x1c
/*  f1a5cb8:	24650054 */ 	addiu	$a1,$v1,0x54
/*  f1a5cbc:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f1a5cc0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a5cc4:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5cc8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a5ccc:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5cd0:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5cd4:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5cd8:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f1a5cdc:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f1a5ce0:	25180028 */ 	addiu	$t8,$t0,0x28
/*  f1a5ce4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a5ce8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5cec:	25060027 */ 	addiu	$a2,$t0,0x27
/*  f1a5cf0:	24650057 */ 	addiu	$a1,$v1,0x57
/*  f1a5cf4:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f1a5cf8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1a5cfc:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5d00:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1a5d04:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5d08:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1a5d0c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1a5d10:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f1a5d14:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1a5d18:	25190033 */ 	addiu	$t9,$t0,0x33
/*  f1a5d1c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a5d20:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5d24:	25060032 */ 	addiu	$a2,$t0,0x32
/*  f1a5d28:	2465005a */ 	addiu	$a1,$v1,0x5a
/*  f1a5d2c:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f1a5d30:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a5d34:	0fc38bba */ 	jal	func0f0e2ee8
/*  f1a5d38:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a5d3c:	10000003 */ 	beqz	$zero,.L0f1a5d4c
/*  f1a5d40:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a5d44:
/*  f1a5d44:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a5d48:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a5d4c:
/*  f1a5d4c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1a5d50:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*  f1a5d54:	03e00008 */ 	jr	$ra
/*  f1a5d58:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerFrFailedContinue(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.currentplayer->prop->rooms[0] == 0xa) {
			func0f0f3704(&g_frWeaponMenuDialog);
		} else {
			menuPopDialog();
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler001a5dc0
/*  f1a5dc0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1a5dc4:	3c0f8009 */ 	lui	$t7,%hi(var800891b0)
/*  f1a5dc8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a5dcc:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f1a5dd0:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f1a5dd4:	25ef91b0 */ 	addiu	$t7,$t7,%lo(var800891b0)
/*  f1a5dd8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a5ddc:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a5de0:	27ae0030 */ 	addiu	$t6,$sp,0x30
/*  f1a5de4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a5de8:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a5dec:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1a5df0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a5df4:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1a5df8:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1a5dfc:	0fc6846e */ 	jal	func0f1a11b8
/*  f1a5e00:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1a5e04:	0fc684e6 */ 	jal	func0f1a1398
/*  f1a5e08:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f1a5e0c:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f1a5e10:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f1a5e14:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f1a5e18:	252affff */ 	addiu	$t2,$t1,-1
/*  f1a5e1c:	2d410007 */ 	sltiu	$at,$t2,0x7
/*  f1a5e20:	10200044 */ 	beqz	$at,.L0f1a5f34
/*  f1a5e24:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f1a5e28:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1a5e2c:	3c017f1c */ 	lui	$at,%hi(var7f1b9948)
/*  f1a5e30:	002a0821 */ 	addu	$at,$at,$t2
/*  f1a5e34:	8c2a9948 */ 	lw	$t2,%lo(var7f1b9948)($at)
/*  f1a5e38:	01400008 */ 	jr	$t2
/*  f1a5e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a5e40:	00625821 */ 	addu	$t3,$v1,$v0
/*  f1a5e44:	1000003b */ 	beqz	$zero,.L0f1a5f34
/*  f1a5e48:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f1a5e4c:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1a5e50:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1a5e54:	10200009 */ 	beqz	$at,.L0f1a5e7c
/*  f1a5e58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a5e5c:	0fc68484 */ 	jal	func0f1a1210
/*  f1a5e60:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5e64:	0fc68429 */ 	jal	func0f1a10a4
/*  f1a5e68:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5e6c:	0fc5b9f1 */ 	jal	langGet
/*  f1a5e70:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a5e74:	10000031 */ 	beqz	$zero,.L0f1a5f3c
/*  f1a5e78:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a5e7c:
/*  f1a5e7c:	0fc684fc */ 	jal	func0f1a13f0
/*  f1a5e80:	00432023 */ 	subu	$a0,$v0,$v1
/*  f1a5e84:	0fc684a2 */ 	jal	func0f1a1288
/*  f1a5e88:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5e8c:	0fc5b9f1 */ 	jal	langGet
/*  f1a5e90:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a5e94:	10000029 */ 	beqz	$zero,.L0f1a5f3c
/*  f1a5e98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a5e9c:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f1a5ea0:	3c028009 */ 	lui	$v0,%hi(var800888a0)
/*  f1a5ea4:	244288a0 */ 	addiu	$v0,$v0,%lo(var800888a0)
/*  f1a5ea8:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1a5eac:	01a3082a */ 	slt	$at,$t5,$v1
/*  f1a5eb0:	10200006 */ 	beqz	$at,.L0f1a5ecc
/*  f1a5eb4:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f1a5eb8:	3c048009 */ 	lui	$a0,%hi(menudialog_characterprofile)
/*  f1a5ebc:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a5ec0:	24849338 */ 	addiu	$a0,$a0,%lo(menudialog_characterprofile)
/*  f1a5ec4:	1000001c */ 	beqz	$zero,.L0f1a5f38
/*  f1a5ec8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a5ecc:
/*  f1a5ecc:	3c048009 */ 	lui	$a0,%hi(menudialog_2f3c0)
/*  f1a5ed0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a5ed4:	248493a0 */ 	addiu	$a0,$a0,%lo(menudialog_2f3c0)
/*  f1a5ed8:	10000017 */ 	beqz	$zero,.L0f1a5f38
/*  f1a5edc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a5ee0:	3c028009 */ 	lui	$v0,%hi(var800888a0)
/*  f1a5ee4:	244288a0 */ 	addiu	$v0,$v0,%lo(var800888a0)
/*  f1a5ee8:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f1a5eec:	10000011 */ 	beqz	$zero,.L0f1a5f34
/*  f1a5ef0:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f1a5ef4:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f1a5ef8:	1000000e */ 	beqz	$zero,.L0f1a5f34
/*  f1a5efc:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f1a5f00:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a5f04:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1a5f08:	03af2021 */ 	addu	$a0,$sp,$t7
/*  f1a5f0c:	0fc5b9f1 */ 	jal	langGet
/*  f1a5f10:	94840034 */ 	lhu	$a0,0x34($a0)
/*  f1a5f14:	10000009 */ 	beqz	$zero,.L0f1a5f3c
/*  f1a5f18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a5f1c:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f1a5f20:	55000004 */ 	bnezl	$t0,.L0f1a5f34
/*  f1a5f24:	acc30008 */ 	sw	$v1,0x8($a2)
/*  f1a5f28:	10000002 */ 	beqz	$zero,.L0f1a5f34
/*  f1a5f2c:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f1a5f30:	acc30008 */ 	sw	$v1,0x8($a2)
.L0f1a5f34:
/*  f1a5f34:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a5f38:
/*  f1a5f38:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a5f3c:
/*  f1a5f3c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f1a5f40:	03e00008 */ 	jr	$ra
/*  f1a5f44:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog001a5f48
/*  f1a5f48:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1a5f4c:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f1a5f50:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1a5f54:	3c048009 */ 	lui	$a0,0x8009
/*  f1a5f58:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f1a5f5c:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f1a5f60:	0fc68484 */ 	jal	func0f1a1210
/*  f1a5f64:	908488a0 */ 	lbu	$a0,-0x7760($a0)
/*  f1a5f68:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f1a5f6c:	0fc62ef6 */ 	jal	mpGetBodyIndexByBodyId
/*  f1a5f70:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f1a5f74:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f1a5f78:	0fc62f27 */ 	jal	func0f18bc9c
/*  f1a5f7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a5f80:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f1a5f84:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a5f88:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f1a5f8c:	10610008 */ 	beq	$v1,$at,.L0f1a5fb0
/*  f1a5f90:	240a0078 */ 	addiu	$t2,$zero,0x78
/*  f1a5f94:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a5f98:	106100b7 */ 	beq	$v1,$at,.L0f1a6278
/*  f1a5f9c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a5fa0:	50610079 */ 	beql	$v1,$at,.L0f1a6188
/*  f1a5fa4:	2401006b */ 	addiu	$at,$zero,0x6b
/*  f1a5fa8:	100000b4 */ 	beqz	$zero,.L0f1a627c
/*  f1a5fac:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1a5fb0:
/*  f1a5fb0:	2401006b */ 	addiu	$at,$zero,0x6b
/*  f1a5fb4:	14a10013 */ 	bne	$a1,$at,.L0f1a6004
/*  f1a5fb8:	3c198007 */ 	lui	$t9,0x8007
/*  f1a5fbc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1a5fc0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1a5fc4:	3c017f1c */ 	lui	$at,%hi(var7f1b9964)
/*  f1a5fc8:	c42c9964 */ 	lwc1	$f12,%lo(var7f1b9964)($at)
/*  f1a5fcc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1a5fd0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1a5fd4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1a5fd8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1a5fdc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1a5fe0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1a5fe4:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f1a5fe8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1a5fec:	44812000 */ 	mtc1	$at,$f4
/*  f1a5ff0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1a5ff4:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f1a5ff8:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f1a5ffc:	10000011 */ 	beqz	$zero,.L0f1a6044
/*  f1a6000:	e4640d94 */ 	swc1	$f4,0xd94($v1)
.L0f1a6004:
/*  f1a6004:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f1a6008:	3c0141f0 */ 	lui	$at,0x41f0
/*  f1a600c:	44813000 */ 	mtc1	$at,$f6
/*  f1a6010:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f1a6014:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1a6018:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1a601c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1a6020:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1a6024:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f1a6028:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1a602c:	00084100 */ 	sll	$t0,$t0,0x4
/*  f1a6030:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f1a6034:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a6038:	01091821 */ 	addu	$v1,$t0,$t1
/*  f1a603c:	44816000 */ 	mtc1	$at,$f12
/*  f1a6040:	e4660d94 */ 	swc1	$f6,0xd94($v1)
.L0f1a6044:
/*  f1a6044:	3c01c302 */ 	lui	$at,0xc302
/*  f1a6048:	44817000 */ 	mtc1	$at,$f14
/*  f1a604c:	ac6a0db4 */ 	sw	$t2,0xdb4($v1)
/*  f1a6050:	ac600dc0 */ 	sw	$zero,0xdc0($v1)
/*  f1a6054:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f1a6058:	e7ac0030 */ 	swc1	$f12,0x30($sp)
/*  f1a605c:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f1a6060:	e7ae0038 */ 	swc1	$f14,0x38($sp)
/*  f1a6064:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a6068:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f1a606c:	c7ac0030 */ 	lwc1	$f12,0x30($sp)
/*  f1a6070:	14410004 */ 	bne	$v0,$at,.L0f1a6084
/*  f1a6074:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*  f1a6078:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f1a607c:	44817000 */ 	mtc1	$at,$f14
/*  f1a6080:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a6084:
/*  f1a6084:	3c01c170 */ 	lui	$at,0xc170
/*  f1a6088:	44810000 */ 	mtc1	$at,$f0
/*  f1a608c:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1a6090:	14a10005 */ 	bne	$a1,$at,.L0f1a60a8
/*  f1a6094:	46000086 */ 	mov.s	$f2,$f0
/*  f1a6098:	3c014140 */ 	lui	$at,0x4140
/*  f1a609c:	44814000 */ 	mtc1	$at,$f8
/*  f1a60a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a60a4:	46080081 */ 	sub.s	$f2,$f0,$f8
.L0f1a60a8:
/*  f1a60a8:	24010067 */ 	addiu	$at,$zero,0x67
/*  f1a60ac:	14a10003 */ 	bne	$a1,$at,.L0f1a60bc
/*  f1a60b0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1a60b4:	3c017f1c */ 	lui	$at,%hi(var7f1b9968)
/*  f1a60b8:	c42c9968 */ 	lwc1	$f12,%lo(var7f1b9968)($at)
.L0f1a60bc:
/*  f1a60bc:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f1a60c0:	44800000 */ 	mtc1	$zero,$f0
/*  f1a60c4:	3c0e800a */ 	lui	$t6,%hi(var8009e000)
/*  f1a60c8:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1a60cc:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a60d0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1a60d4:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1a60d8:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1a60dc:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a60e0:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1a60e4:	258d0840 */ 	addiu	$t5,$t4,0x840
/*  f1a60e8:	25cee000 */ 	addiu	$t6,$t6,%lo(var8009e000)
/*  f1a60ec:	44057000 */ 	mfc1	$a1,$f14
/*  f1a60f0:	44061000 */ 	mfc1	$a2,$f2
/*  f1a60f4:	240f0007 */ 	addiu	$t7,$zero,0x7
/*  f1a60f8:	44070000 */ 	mfc1	$a3,$f0
/*  f1a60fc:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f1a6100:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f1a6104:	e7ac001c */ 	swc1	$f12,0x1c($sp)
/*  f1a6108:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f1a610c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f1a6110:	0fc3cdcb */ 	jal	func0f0f372c
/*  f1a6114:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f1a6118:	3c188007 */ 	lui	$t8,0x8007
/*  f1a611c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f1a6120:	3c017f1c */ 	lui	$at,%hi(var7f1b996c)
/*  f1a6124:	c42a996c */ 	lwc1	$f10,%lo(var7f1b996c)($at)
/*  f1a6128:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f1a612c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1a6130:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1a6134:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1a6138:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f1a613c:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f1a6140:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1a6144:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f1a6148:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f1a614c:	03281821 */ 	addu	$v1,$t9,$t0
/*  f1a6150:	3c017f1c */ 	lui	$at,%hi(var7f1b9970)
/*  f1a6154:	e46a0d50 */ 	swc1	$f10,0xd50($v1)
/*  f1a6158:	c4309970 */ 	lwc1	$f16,%lo(var7f1b9970)($at)
/*  f1a615c:	3c017f1c */ 	lui	$at,%hi(var7f1b9974)
/*  f1a6160:	44800000 */ 	mtc1	$zero,$f0
/*  f1a6164:	e4700d54 */ 	swc1	$f16,0xd54($v1)
/*  f1a6168:	c4329974 */ 	lwc1	$f18,%lo(var7f1b9974)($at)
/*  f1a616c:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f1a6170:	ac690db8 */ 	sw	$t1,0xdb8($v1)
/*  f1a6174:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a6178:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a617c:	1000003e */ 	beqz	$zero,.L0f1a6278
/*  f1a6180:	e4720d5c */ 	swc1	$f18,0xd5c($v1)
/*  f1a6184:	2401006b */ 	addiu	$at,$zero,0x6b
.L0f1a6188:
/*  f1a6188:	14a10012 */ 	bne	$a1,$at,.L0f1a61d4
/*  f1a618c:	3c0a8007 */ 	lui	$t2,0x8007
/*  f1a6190:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f1a6194:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f1a6198:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f1a619c:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f1a61a0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1a61a4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1a61a8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f1a61ac:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f1a61b0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1a61b4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f1a61b8:	3c0d8009 */ 	lui	$t5,%hi(var80089268)
/*  f1a61bc:	25ad9268 */ 	addiu	$t5,$t5,%lo(var80089268)
/*  f1a61c0:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f1a61c4:	240e013e */ 	addiu	$t6,$zero,0x13e
/*  f1a61c8:	ac6d0df4 */ 	sw	$t5,0xdf4($v1)
/*  f1a61cc:	1000000f */ 	beqz	$zero,.L0f1a620c
/*  f1a61d0:	a46e089c */ 	sh	$t6,0x89c($v1)
.L0f1a61d4:
/*  f1a61d4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f1a61d8:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f1a61dc:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f1a61e0:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f1a61e4:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f1a61e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1a61ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1a61f0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1a61f4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f1a61f8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1a61fc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f1a6200:	03191821 */ 	addu	$v1,$t8,$t9
/*  f1a6204:	2408006a */ 	addiu	$t0,$zero,0x6a
/*  f1a6208:	a468089c */ 	sh	$t0,0x89c($v1)
.L0f1a620c:
/*  f1a620c:	24010067 */ 	addiu	$at,$zero,0x67
/*  f1a6210:	14a10004 */ 	bne	$a1,$at,.L0f1a6224
/*  f1a6214:	00025400 */ 	sll	$t2,$v0,0x10
/*  f1a6218:	3c098009 */ 	lui	$t1,%hi(var80089280)
/*  f1a621c:	25299280 */ 	addiu	$t1,$t1,%lo(var80089280)
/*  f1a6220:	ac690df4 */ 	sw	$t1,0xdf4($v1)
.L0f1a6224:
/*  f1a6224:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f1a6228:	8c640db8 */ 	lw	$a0,0xdb8($v1)
/*  f1a622c:	354bffff */ 	ori	$t3,$t2,0xffff
/*  f1a6230:	000c6e00 */ 	sll	$t5,$t4,0x18
/*  f1a6234:	016d7025 */ 	or	$t6,$t3,$t5
/*  f1a6238:	18800006 */ 	blez	$a0,.L0f1a6254
/*  f1a623c:	ac6e084c */ 	sw	$t6,0x84c($v1)
/*  f1a6240:	3c0f800a */ 	lui	$t7,0x800a
/*  f1a6244:	8def9fc0 */ 	lw	$t7,-0x6040($t7)
/*  f1a6248:	008fc023 */ 	subu	$t8,$a0,$t7
/*  f1a624c:	1000000a */ 	beqz	$zero,.L0f1a6278
/*  f1a6250:	ac780db8 */ 	sw	$t8,0xdb8($v1)
.L0f1a6254:
/*  f1a6254:	3c017f1c */ 	lui	$at,%hi(var7f1b9978)
/*  f1a6258:	c4249978 */ 	lwc1	$f4,%lo(var7f1b9978)($at)
/*  f1a625c:	3c01800a */ 	lui	$at,0x800a
/*  f1a6260:	c4269fc4 */ 	lwc1	$f6,-0x603c($at)
/*  f1a6264:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f1a6268:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1a626c:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f1a6270:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a6274:	e4600d64 */ 	swc1	$f0,0xd64($v1)
.L0f1a6278:
/*  f1a6278:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1a627c:
/*  f1a627c:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f1a6280:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a6284:	03e00008 */ 	jr	$ra
/*  f1a6288:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a628c
/*  f1a628c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6290:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6294:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6298:	3c048009 */ 	lui	$a0,0x8009
/*  f1a629c:	0fc68484 */ 	jal	func0f1a1210
/*  f1a62a0:	908488a0 */ 	lbu	$a0,-0x7760($a0)
/*  f1a62a4:	0fc68429 */ 	jal	func0f1a10a4
/*  f1a62a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a62ac:	0fc5b9f1 */ 	jal	langGet
/*  f1a62b0:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a62b4:	3c048007 */ 	lui	$a0,0x8007
/*  f1a62b8:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a62bc:	24a598a0 */ 	addiu	$a1,$a1,-26464
/*  f1a62c0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a62c4:	0c004dad */ 	jal	sprintf
/*  f1a62c8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a62cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a62d0:	3c028007 */ 	lui	$v0,0x8007
/*  f1a62d4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a62d8:	03e00008 */ 	jr	$ra
/*  f1a62dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a62e0
/*  f1a62e0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a62e4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a62e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a62ec:	3c048009 */ 	lui	$a0,0x8009
/*  f1a62f0:	0fc68484 */ 	jal	func0f1a1210
/*  f1a62f4:	908488a0 */ 	lbu	$a0,-0x7760($a0)
/*  f1a62f8:	0fc68429 */ 	jal	func0f1a10a4
/*  f1a62fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6300:	0fc5b9f1 */ 	jal	langGet
/*  f1a6304:	8c440008 */ 	lw	$a0,0x8($v0)
/*  f1a6308:	3c048007 */ 	lui	$a0,0x8007
/*  f1a630c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a6310:	24a598a4 */ 	addiu	$a1,$a1,-26460
/*  f1a6314:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a6318:	0c004dad */ 	jal	sprintf
/*  f1a631c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a6320:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6324:	3c028007 */ 	lui	$v0,0x8007
/*  f1a6328:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a632c:	03e00008 */ 	jr	$ra
/*  f1a6330:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a6334
/*  f1a6334:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6338:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a633c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6340:	3c048009 */ 	lui	$a0,0x8009
/*  f1a6344:	0fc68484 */ 	jal	func0f1a1210
/*  f1a6348:	908488a0 */ 	lbu	$a0,-0x7760($a0)
/*  f1a634c:	0fc68429 */ 	jal	func0f1a10a4
/*  f1a6350:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6354:	0fc5b9f1 */ 	jal	langGet
/*  f1a6358:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1a635c:	3c048007 */ 	lui	$a0,0x8007
/*  f1a6360:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a6364:	24a598a8 */ 	addiu	$a1,$a1,-26456
/*  f1a6368:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a636c:	0c004dad */ 	jal	sprintf
/*  f1a6370:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a6374:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6378:	3c028007 */ 	lui	$v0,0x8007
/*  f1a637c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a6380:	03e00008 */ 	jr	$ra
/*  f1a6384:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a6388
/*  f1a6388:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a638c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6390:	0fc6846e */ 	jal	func0f1a11b8
/*  f1a6394:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6398:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1a639c:	91ce88a0 */ 	lbu	$t6,-0x7760($t6)
/*  f1a63a0:	0fc684fc */ 	jal	func0f1a13f0
/*  f1a63a4:	01c22023 */ 	subu	$a0,$t6,$v0
/*  f1a63a8:	0fc684a2 */ 	jal	func0f1a1288
/*  f1a63ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a63b0:	0fc5b9f1 */ 	jal	langGet
/*  f1a63b4:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a63b8:	3c048007 */ 	lui	$a0,0x8007
/*  f1a63bc:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a63c0:	24a598ac */ 	addiu	$a1,$a1,-26452
/*  f1a63c4:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a63c8:	0c004dad */ 	jal	sprintf
/*  f1a63cc:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a63d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a63d4:	3c028007 */ 	lui	$v0,0x8007
/*  f1a63d8:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a63dc:	03e00008 */ 	jr	$ra
/*  f1a63e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel menuhandler001a63e4
/*  f1a63e4:	248effff */ 	addiu	$t6,$a0,-1
/*  f1a63e8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a63ec:	2dc10007 */ 	sltiu	$at,$t6,0x7
/*  f1a63f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a63f4:	10200025 */ 	beqz	$at,.L0f1a648c
/*  f1a63f8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1a63fc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a6400:	3c017f1c */ 	lui	$at,%hi(var7f1b997c)
/*  f1a6404:	002e0821 */ 	addu	$at,$at,$t6
/*  f1a6408:	8c2e997c */ 	lw	$t6,%lo(var7f1b997c)($at)
/*  f1a640c:	01c00008 */ 	jr	$t6
/*  f1a6410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6414:	0fc68744 */ 	jal	func0f1a1d10
/*  f1a6418:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1a641c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f1a6420:	1000001a */ 	beqz	$zero,.L0f1a648c
/*  f1a6424:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a6428:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a642c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a6430:	0fc68778 */ 	jal	func0f1a1de0
/*  f1a6434:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6438:	0fc28857 */ 	jal	func0f0a215c
/*  f1a643c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6440:	10000014 */ 	beqz	$zero,.L0f1a6494
/*  f1a6444:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6448:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1a644c:	3c018009 */ 	lui	$at,0x8009
/*  f1a6450:	3c048009 */ 	lui	$a0,%hi(menudialog_2f49c)
/*  f1a6454:	2484947c */ 	addiu	$a0,$a0,%lo(menudialog_2f49c)
/*  f1a6458:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a645c:	a02f8ad8 */ 	sb	$t7,-0x7528($at)
/*  f1a6460:	1000000b */ 	beqz	$zero,.L0f1a6490
/*  f1a6464:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a6468:	3c188009 */ 	lui	$t8,0x8009
/*  f1a646c:	93188ad8 */ 	lbu	$t8,-0x7528($t8)
/*  f1a6470:	10000006 */ 	beqz	$zero,.L0f1a648c
/*  f1a6474:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f1a6478:	10000004 */ 	beqz	$zero,.L0f1a648c
/*  f1a647c:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f1a6480:	10000003 */ 	beqz	$zero,.L0f1a6490
/*  f1a6484:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a6488:	acc00008 */ 	sw	$zero,0x8($a2)
.L0f1a648c:
/*  f1a648c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a6490:
/*  f1a6490:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6494:
/*  f1a6494:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a6498:	03e00008 */ 	jr	$ra
/*  f1a649c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a64a0
/*  f1a64a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a64a4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a64a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a64ac:	3c048009 */ 	lui	$a0,0x8009
/*  f1a64b0:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a64b4:	90848ad8 */ 	lbu	$a0,-0x7528($a0)
/*  f1a64b8:	0fc68778 */ 	jal	func0f1a1de0
/*  f1a64bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a64c0:	0fc28857 */ 	jal	func0f0a215c
/*  f1a64c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a64c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a64cc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a64d0:	03e00008 */ 	jr	$ra
/*  f1a64d4:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler001a64d8(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f1a1b54();
		func0f0f8120();
	}

	return 0;
}

s32 menuhandler001a6514(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f1a1bec();
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog001a6548
/*  f1a6548:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a654c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a6550:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6554:	10810008 */ 	beq	$a0,$at,.L0f1a6578
/*  f1a6558:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f1a655c:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a6560:	1081008e */ 	beq	$a0,$at,.L0f1a679c
/*  f1a6564:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a6568:	1081004c */ 	beq	$a0,$at,.L0f1a669c
/*  f1a656c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6570:	1000008b */ 	beqz	$zero,.L0f1a67a0
/*  f1a6574:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6578:
/*  f1a6578:	3c048009 */ 	lui	$a0,0x8009
/*  f1a657c:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a6580:	90848ad8 */ 	lbu	$a0,-0x7528($a0)
/*  f1a6584:	0fc68778 */ 	jal	func0f1a1de0
/*  f1a6588:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a658c:	3c0f8009 */ 	lui	$t7,%hi(var800893f8)
/*  f1a6590:	25ef93f8 */ 	addiu	$t7,$t7,%lo(var800893f8)
/*  f1a6594:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a6598:	27ae0028 */ 	addiu	$t6,$sp,0x28
/*  f1a659c:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f1a65a0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a65a4:	95e10008 */ 	lhu	$at,0x8($t7)
/*  f1a65a8:	add90004 */ 	sw	$t9,0x4($t6)
/*  f1a65ac:	a5c10008 */ 	sh	$at,0x8($t6)
/*  f1a65b0:	0fc686b0 */ 	jal	func0f1a1ac0
/*  f1a65b4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f1a65b8:	3c088007 */ 	lui	$t0,0x8007
/*  f1a65bc:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f1a65c0:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f1a65c4:	3c01800a */ 	lui	$at,0x800a
/*  f1a65c8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a65cc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a65d0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a65d4:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a65d8:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a65dc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a65e0:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a65e4:	00290821 */ 	addu	$at,$at,$t1
/*  f1a65e8:	0fc41652 */ 	jal	func0f105948
/*  f1a65ec:	ac24ee28 */ 	sw	$a0,-0x11d8($at)
/*  f1a65f0:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f1a65f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a65f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a65fc:	14410012 */ 	bne	$v0,$at,.L0f1a6648
/*  f1a6600:	3c0d8007 */ 	lui	$t5,0x8007
/*  f1a6604:	3c0a8007 */ 	lui	$t2,0x8007
/*  f1a6608:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f1a660c:	3c01428c */ 	lui	$at,0x428c
/*  f1a6610:	44810000 */ 	mtc1	$at,$f0
/*  f1a6614:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f1a6618:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1a661c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1a6620:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f1a6624:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f1a6628:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f1a662c:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1a6630:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f1a6634:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f1a6638:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f1a663c:	e4400d78 */ 	swc1	$f0,0xd78($v0)
/*  f1a6640:	10000010 */ 	beqz	$zero,.L0f1a6684
/*  f1a6644:	e4400d50 */ 	swc1	$f0,0xd50($v0)
.L0f1a6648:
/*  f1a6648:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f1a664c:	3c0142b4 */ 	lui	$at,0x42b4
/*  f1a6650:	44810000 */ 	mtc1	$at,$f0
/*  f1a6654:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f1a6658:	030dc023 */ 	subu	$t8,$t8,$t5
/*  f1a665c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1a6660:	030dc021 */ 	addu	$t8,$t8,$t5
/*  f1a6664:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f1a6668:	3c0e800a */ 	lui	$t6,%hi(var8009e000)
/*  f1a666c:	030dc023 */ 	subu	$t8,$t8,$t5
/*  f1a6670:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f1a6674:	25cee000 */ 	addiu	$t6,$t6,%lo(var8009e000)
/*  f1a6678:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f1a667c:	e4400d78 */ 	swc1	$f0,0xd78($v0)
/*  f1a6680:	e4400d50 */ 	swc1	$f0,0xd50($v0)
.L0f1a6684:
/*  f1a6684:	3c014020 */ 	lui	$at,0x4020
/*  f1a6688:	44813000 */ 	mtc1	$at,$f6
/*  f1a668c:	c4440d84 */ 	lwc1	$f4,0xd84($v0)
/*  f1a6690:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f1a6694:	10000041 */ 	beqz	$zero,.L0f1a679c
/*  f1a6698:	e4480d84 */ 	swc1	$f8,0xd84($v0)
.L0f1a669c:
/*  f1a669c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f1a66a0:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f1a66a4:	3c02800a */ 	lui	$v0,0x800a
/*  f1a66a8:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f1a66ac:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f1a66b0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1a66b4:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f1a66b8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f1a66bc:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f1a66c0:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f1a66c4:	00591021 */ 	addu	$v0,$v0,$t9
/*  f1a66c8:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f1a66cc:	50400034 */ 	beqzl	$v0,.L0f1a67a0
/*  f1a66d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a66d4:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f1a66d8:	3c048009 */ 	lui	$a0,0x8009
/*  f1a66dc:	54a80030 */ 	bnel	$a1,$t0,.L0f1a67a0
/*  f1a66e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a66e4:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a66e8:	90848ad8 */ 	lbu	$a0,-0x7528($a0)
/*  f1a66ec:	0fc68778 */ 	jal	func0f1a1de0
/*  f1a66f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a66f4:	24010041 */ 	addiu	$at,$zero,0x41
/*  f1a66f8:	14410013 */ 	bne	$v0,$at,.L0f1a6748
/*  f1a66fc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1a6700:	3c098007 */ 	lui	$t1,0x8007
/*  f1a6704:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f1a6708:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f1a670c:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f1a6710:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1a6714:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1a6718:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1a671c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1a6720:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1a6724:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1a6728:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f1a672c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f1a6730:	240c006a */ 	addiu	$t4,$zero,0x6a
/*  f1a6734:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f1a6738:	24180078 */ 	addiu	$t8,$zero,0x78
/*  f1a673c:	a44c089c */ 	sh	$t4,0x89c($v0)
/*  f1a6740:	ac4d0db8 */ 	sw	$t5,0xdb8($v0)
/*  f1a6744:	ac580db4 */ 	sw	$t8,0xdb4($v0)
.L0f1a6748:
/*  f1a6748:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1a674c:	3c017f1c */ 	lui	$at,%hi(var7f1b9998)
/*  f1a6750:	c42a9998 */ 	lwc1	$f10,%lo(var7f1b9998)($at)
/*  f1a6754:	3c018006 */ 	lui	$at,0x8006
/*  f1a6758:	c4301630 */ 	lwc1	$f16,0x1630($at)
/*  f1a675c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1a6760:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1a6764:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1a6768:	46105002 */ 	mul.s	$f0,$f10,$f16
/*  f1a676c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1a6770:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1a6774:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f1a6778:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1a677c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1a6780:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f1a6784:	44801000 */ 	mtc1	$zero,$f2
/*  f1a6788:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f1a678c:	e4400d8c */ 	swc1	$f0,0xd8c($v0)
/*  f1a6790:	e4400d64 */ 	swc1	$f0,0xd64($v0)
/*  f1a6794:	e4420d90 */ 	swc1	$f2,0xd90($v0)
/*  f1a6798:	e4420d68 */ 	swc1	$f2,0xd68($v0)
.L0f1a679c:
/*  f1a679c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a67a0:
/*  f1a67a0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a67a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a67a8:	03e00008 */ 	jr	$ra
/*  f1a67ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a67b0
/*  f1a67b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a67b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a67b8:	0fc68606 */ 	jal	ciGetTrainingData
/*  f1a67bc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a67c0:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1a67c4:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f1a67c8:	11e00005 */ 	beqz	$t7,.L0f1a67e0
/*  f1a67cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a67d0:	0fc5b9f1 */ 	jal	langGet
/*  f1a67d4:	240451ac */ 	addiu	$a0,$zero,0x51ac
/*  f1a67d8:	10000004 */ 	beqz	$zero,.L0f1a67ec
/*  f1a67dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a67e0:
/*  f1a67e0:	0fc5b9f1 */ 	jal	langGet
/*  f1a67e4:	240451ab */ 	addiu	$a0,$zero,0x51ab
/*  f1a67e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a67ec:
/*  f1a67ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a67f0:	03e00008 */ 	jr	$ra
/*  f1a67f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a67f8
/*  f1a67f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a67fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6800:	0fc68606 */ 	jal	ciGetTrainingData
/*  f1a6804:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6808:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1a680c:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f1a6810:	11e00005 */ 	beqz	$t7,.L0f1a6828
/*  f1a6814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6818:	0fc5b9f1 */ 	jal	langGet
/*  f1a681c:	240451ae */ 	addiu	$a0,$zero,0x51ae
/*  f1a6820:	10000004 */ 	beqz	$zero,.L0f1a6834
/*  f1a6824:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6828:
/*  f1a6828:	0fc5b9f1 */ 	jal	langGet
/*  f1a682c:	240451ad */ 	addiu	$a0,$zero,0x51ad
/*  f1a6830:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6834:
/*  f1a6834:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a6838:	03e00008 */ 	jr	$ra
/*  f1a683c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a6840
/*  f1a6840:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1a6844:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1a6848:	0fc68606 */ 	jal	ciGetTrainingData
/*  f1a684c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f1a6850:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f1a6854:	3c014270 */ 	lui	$at,0x4270
/*  f1a6858:	44810000 */ 	mtc1	$at,$f0
/*  f1a685c:	448e2000 */ 	mtc1	$t6,$f4
/*  f1a6860:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a6864:	3c067f1c */ 	lui	$a2,0x7f1c
/*  f1a6868:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a686c:	3c077f1c */ 	lui	$a3,0x7f1c
/*  f1a6870:	24e798cc */ 	addiu	$a3,$a3,-26420
/*  f1a6874:	24c698c8 */ 	addiu	$a2,$a2,-26424
/*  f1a6878:	24a598bc */ 	addiu	$a1,$a1,-26436
/*  f1a687c:	3c048007 */ 	lui	$a0,0x8007
/*  f1a6880:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f1a6884:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a6888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a688c:	45020019 */ 	bc1fl	.L0f1a68f4
/*  f1a6890:	460062a1 */ 	cvt.d.s	$f10,$f12
/*  f1a6894:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a6898:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a689c:	45000007 */ 	bc1f	.L0f1a68bc
/*  f1a68a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a68a4:	46006301 */ 	sub.s	$f12,$f12,$f0
.L0f1a68a8:
/*  f1a68a8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1a68ac:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a68b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a68b4:	4503fffc */ 	bc1tl	.L0f1a68a8
/*  f1a68b8:	46006301 */ 	sub.s	$f12,$f12,$f0
.L0f1a68bc:
/*  f1a68bc:	0fc25e5c */ 	jal	func0f097970
/*  f1a68c0:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f1a68c4:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f1a68c8:	3c048007 */ 	lui	$a0,0x8007
/*  f1a68cc:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a68d0:	24a598b0 */ 	addiu	$a1,$a1,-26448
/*  f1a68d4:	44074000 */ 	mfc1	$a3,$f8
/*  f1a68d8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a68dc:	0c004dad */ 	jal	sprintf
/*  f1a68e0:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f1a68e4:	3c028007 */ 	lui	$v0,0x8007
/*  f1a68e8:	10000007 */ 	beqz	$zero,.L0f1a6908
/*  f1a68ec:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a68f0:	460062a1 */ 	cvt.d.s	$f10,$f12
.L0f1a68f4:
/*  f1a68f4:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a68f8:	0c004dad */ 	jal	sprintf
/*  f1a68fc:	f7aa0010 */ 	sdc1	$f10,0x10($sp)
/*  f1a6900:	3c028007 */ 	lui	$v0,0x8007
/*  f1a6904:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a6908:
/*  f1a6908:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1a690c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1a6910:	03e00008 */ 	jr	$ra
/*  f1a6914:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogDeviceTrainingResults(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_101) {
		chrSetStageFlag(NULL, 0x08000000);
	}

	return false;
}

GLOBAL_ASM(
glabel menuhandler001a6950
/*  f1a6950:	248effff */ 	addiu	$t6,$a0,-1
/*  f1a6954:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6958:	2dc10007 */ 	sltiu	$at,$t6,0x7
/*  f1a695c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6960:	10200023 */ 	beqz	$at,.L0f1a69f0
/*  f1a6964:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1a6968:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a696c:	3c017f1c */ 	lui	$at,%hi(var7f1b999c)
/*  f1a6970:	002e0821 */ 	addu	$at,$at,$t6
/*  f1a6974:	8c2e999c */ 	lw	$t6,%lo(var7f1b999c)($at)
/*  f1a6978:	01c00008 */ 	jr	$t6
/*  f1a697c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6980:	0fc68921 */ 	jal	func0f1a2484
/*  f1a6984:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1a6988:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f1a698c:	10000018 */ 	beqz	$zero,.L0f1a69f0
/*  f1a6990:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a6994:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a6998:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a699c:	0fc68955 */ 	jal	func0f1a2554
/*  f1a69a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a69a4:	10000014 */ 	beqz	$zero,.L0f1a69f8
/*  f1a69a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a69ac:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1a69b0:	3c018009 */ 	lui	$at,0x8009
/*  f1a69b4:	3c048009 */ 	lui	$a0,%hi(menudialog_2f68c)
/*  f1a69b8:	2484966c */ 	addiu	$a0,$a0,%lo(menudialog_2f68c)
/*  f1a69bc:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a69c0:	a02f8bb4 */ 	sb	$t7,-0x744c($at)
/*  f1a69c4:	1000000b */ 	beqz	$zero,.L0f1a69f4
/*  f1a69c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a69cc:	3c188009 */ 	lui	$t8,0x8009
/*  f1a69d0:	93188bb4 */ 	lbu	$t8,-0x744c($t8)
/*  f1a69d4:	10000006 */ 	beqz	$zero,.L0f1a69f0
/*  f1a69d8:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f1a69dc:	10000004 */ 	beqz	$zero,.L0f1a69f0
/*  f1a69e0:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f1a69e4:	10000003 */ 	beqz	$zero,.L0f1a69f4
/*  f1a69e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a69ec:	acc00008 */ 	sw	$zero,0x8($a2)
.L0f1a69f0:
/*  f1a69f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a69f4:
/*  f1a69f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a69f8:
/*  f1a69f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a69fc:	03e00008 */ 	jr	$ra
/*  f1a6a00:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a6a04
/*  f1a6a04:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6a08:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6a0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6a10:	3c048009 */ 	lui	$a0,0x8009
/*  f1a6a14:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a6a18:	90848bb4 */ 	lbu	$a0,-0x744c($a0)
/*  f1a6a1c:	0fc68955 */ 	jal	func0f1a2554
/*  f1a6a20:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6a24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6a28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a6a2c:	03e00008 */ 	jr	$ra
/*  f1a6a30:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler001a6a34(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f1a2220();
		func0f0f8120();
	}

	return 0;
}

s32 menuhandler001a6a70(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f1a22d4();
	}

	return 0;
}

bool menudialog001a6aa4(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	switch (operation) {
	case MENUOP_100:
		func0f1a2198();
		break;
	case MENUOP_101:
		break;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f1a6aec
/*  f1a6aec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6af0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6af4:	0fc687f8 */ 	jal	func0f1a1fe0
/*  f1a6af8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6afc:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1a6b00:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f1a6b04:	11e00005 */ 	beqz	$t7,.L0f1a6b1c
/*  f1a6b08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6b0c:	0fc5b9f1 */ 	jal	langGet
/*  f1a6b10:	240451ac */ 	addiu	$a0,$zero,0x51ac
/*  f1a6b14:	10000004 */ 	beqz	$zero,.L0f1a6b28
/*  f1a6b18:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6b1c:
/*  f1a6b1c:	0fc5b9f1 */ 	jal	langGet
/*  f1a6b20:	240451ab */ 	addiu	$a0,$zero,0x51ab
/*  f1a6b24:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6b28:
/*  f1a6b28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a6b2c:	03e00008 */ 	jr	$ra
/*  f1a6b30:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a6b34
/*  f1a6b34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6b38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6b3c:	0fc687f8 */ 	jal	func0f1a1fe0
/*  f1a6b40:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6b44:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1a6b48:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f1a6b4c:	11e00005 */ 	beqz	$t7,.L0f1a6b64
/*  f1a6b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6b54:	0fc5b9f1 */ 	jal	langGet
/*  f1a6b58:	240451ae */ 	addiu	$a0,$zero,0x51ae
/*  f1a6b5c:	10000004 */ 	beqz	$zero,.L0f1a6b70
/*  f1a6b60:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6b64:
/*  f1a6b64:	0fc5b9f1 */ 	jal	langGet
/*  f1a6b68:	240451ad */ 	addiu	$a0,$zero,0x51ad
/*  f1a6b6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6b70:
/*  f1a6b70:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a6b74:	03e00008 */ 	jr	$ra
/*  f1a6b78:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a6b7c
/*  f1a6b7c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1a6b80:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1a6b84:	0fc687f8 */ 	jal	func0f1a1fe0
/*  f1a6b88:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f1a6b8c:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f1a6b90:	3c014270 */ 	lui	$at,0x4270
/*  f1a6b94:	44810000 */ 	mtc1	$at,$f0
/*  f1a6b98:	448e2000 */ 	mtc1	$t6,$f4
/*  f1a6b9c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a6ba0:	3c067f1c */ 	lui	$a2,0x7f1c
/*  f1a6ba4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a6ba8:	3c077f1c */ 	lui	$a3,0x7f1c
/*  f1a6bac:	24e798ec */ 	addiu	$a3,$a3,-26388
/*  f1a6bb0:	24c698e8 */ 	addiu	$a2,$a2,-26392
/*  f1a6bb4:	24a598dc */ 	addiu	$a1,$a1,-26404
/*  f1a6bb8:	3c048007 */ 	lui	$a0,0x8007
/*  f1a6bbc:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f1a6bc0:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a6bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6bc8:	45020019 */ 	bc1fl	.L0f1a6c30
/*  f1a6bcc:	460062a1 */ 	cvt.d.s	$f10,$f12
/*  f1a6bd0:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a6bd4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a6bd8:	45000007 */ 	bc1f	.L0f1a6bf8
/*  f1a6bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6be0:	46006301 */ 	sub.s	$f12,$f12,$f0
.L0f1a6be4:
/*  f1a6be4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1a6be8:	460c003e */ 	c.le.s	$f0,$f12
/*  f1a6bec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6bf0:	4503fffc */ 	bc1tl	.L0f1a6be4
/*  f1a6bf4:	46006301 */ 	sub.s	$f12,$f12,$f0
.L0f1a6bf8:
/*  f1a6bf8:	0fc25e5c */ 	jal	func0f097970
/*  f1a6bfc:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f1a6c00:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f1a6c04:	3c048007 */ 	lui	$a0,0x8007
/*  f1a6c08:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a6c0c:	24a598d0 */ 	addiu	$a1,$a1,-26416
/*  f1a6c10:	44074000 */ 	mfc1	$a3,$f8
/*  f1a6c14:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a6c18:	0c004dad */ 	jal	sprintf
/*  f1a6c1c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f1a6c20:	3c028007 */ 	lui	$v0,0x8007
/*  f1a6c24:	10000007 */ 	beqz	$zero,.L0f1a6c44
/*  f1a6c28:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a6c2c:	460062a1 */ 	cvt.d.s	$f10,$f12
.L0f1a6c30:
/*  f1a6c30:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a6c34:	0c004dad */ 	jal	sprintf
/*  f1a6c38:	f7aa0010 */ 	sdc1	$f10,0x10($sp)
/*  f1a6c3c:	3c028007 */ 	lui	$v0,0x8007
/*  f1a6c40:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f1a6c44:
/*  f1a6c44:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1a6c48:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1a6c4c:	03e00008 */ 	jr	$ra
/*  f1a6c50:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogFiringRangeResults(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_101) {
		chrSetStageFlag(NULL, 0x08000000);
	}

	return false;
}

GLOBAL_ASM(
glabel func0f1a6c8c
/*  f1a6c8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a6c90:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a6c94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6c98:	3c048009 */ 	lui	$a0,0x8009
/*  f1a6c9c:	0fc685db */ 	jal	func0f1a176c
/*  f1a6ca0:	90848964 */ 	lbu	$a0,-0x769c($a0)
/*  f1a6ca4:	0fc6852d */ 	jal	func0f1a14b4
/*  f1a6ca8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6cac:	0fc5b9f1 */ 	jal	langGet
/*  f1a6cb0:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a6cb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6cb8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a6cbc:	03e00008 */ 	jr	$ra
/*  f1a6cc0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a6cc4
/*  f1a6cc4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1a6cc8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1a6ccc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6cd0:	3c048009 */ 	lui	$a0,0x8009
/*  f1a6cd4:	90848964 */ 	lbu	$a0,-0x769c($a0)
/*  f1a6cd8:	0fc685db */ 	jal	func0f1a176c
/*  f1a6cdc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1a6ce0:	0fc6852d */ 	jal	func0f1a14b4
/*  f1a6ce4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6ce8:	0fc5b9f1 */ 	jal	langGet
/*  f1a6cec:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a6cf0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f1a6cf4:	2404007c */ 	addiu	$a0,$zero,0x7c
/*  f1a6cf8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f1a6cfc:	108e0007 */ 	beq	$a0,$t6,.L0f1a6d1c
/*  f1a6d00:	00403825 */ 	or	$a3,$v0,$zero
/*  f1a6d04:	00431021 */ 	addu	$v0,$v0,$v1
/*  f1a6d08:	904f0001 */ 	lbu	$t7,0x1($v0)
.L0f1a6d0c:
/*  f1a6d0c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1a6d10:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1a6d14:	548ffffd */ 	bnel	$a0,$t7,.L0f1a6d0c
/*  f1a6d18:	904f0001 */ 	lbu	$t7,0x1($v0)
.L0f1a6d1c:
/*  f1a6d1c:	3c048007 */ 	lui	$a0,0x8007
/*  f1a6d20:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1a6d24:	00673021 */ 	addu	$a2,$v1,$a3
/*  f1a6d28:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1a6d2c:	24a598f0 */ 	addiu	$a1,$a1,-26384
/*  f1a6d30:	0c004dad */ 	jal	sprintf
/*  f1a6d34:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1a6d38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6d3c:	3c028007 */ 	lui	$v0,0x8007
/*  f1a6d40:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1a6d44:	03e00008 */ 	jr	$ra
/*  f1a6d48:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel menuhandler001a6d4c
/*  f1a6d4c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a6d50:	3c0f8009 */ 	lui	$t7,%hi(var800897a4)
/*  f1a6d54:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a6d58:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f1a6d5c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f1a6d60:	25ef97a4 */ 	addiu	$t7,$t7,%lo(var800897a4)
/*  f1a6d64:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a6d68:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a6d6c:	27ae0028 */ 	addiu	$t6,$sp,0x28
/*  f1a6d70:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a6d74:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a6d78:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1a6d7c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a6d80:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1a6d84:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1a6d88:	0fc685a9 */ 	jal	func0f1a16a4
/*  f1a6d8c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f1a6d90:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f1a6d94:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f1a6d98:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f1a6d9c:	252affff */ 	addiu	$t2,$t1,-1
/*  f1a6da0:	2d410007 */ 	sltiu	$at,$t2,0x7
/*  f1a6da4:	1020003a */ 	beqz	$at,.L0f1a6e90
/*  f1a6da8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1a6dac:	3c017f1c */ 	lui	$at,%hi(var7f1b99b8)
/*  f1a6db0:	002a0821 */ 	addu	$at,$at,$t2
/*  f1a6db4:	8c2a99b8 */ 	lw	$t2,%lo(var7f1b99b8)($at)
/*  f1a6db8:	01400008 */ 	jr	$t2
/*  f1a6dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a6dc0:	0fc685c5 */ 	jal	func0f1a1714
/*  f1a6dc4:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f1a6dc8:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f1a6dcc:	10000030 */ 	beqz	$zero,.L0f1a6e90
/*  f1a6dd0:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a6dd4:	0fc685db */ 	jal	func0f1a176c
/*  f1a6dd8:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a6ddc:	0fc6852d */ 	jal	func0f1a14b4
/*  f1a6de0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a6de4:	0fc5b9f1 */ 	jal	langGet
/*  f1a6de8:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f1a6dec:	1000002a */ 	beqz	$zero,.L0f1a6e98
/*  f1a6df0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6df4:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f1a6df8:	3c028009 */ 	lui	$v0,%hi(var80088964)
/*  f1a6dfc:	24428964 */ 	addiu	$v0,$v0,%lo(var80088964)
/*  f1a6e00:	a04b0000 */ 	sb	$t3,0x0($v0)
/*  f1a6e04:	0fc685db */ 	jal	func0f1a176c
/*  f1a6e08:	316400ff */ 	andi	$a0,$t3,0xff
/*  f1a6e0c:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a6e10:	10200006 */ 	beqz	$at,.L0f1a6e2c
/*  f1a6e14:	3c048009 */ 	lui	$a0,%hi(menudialog_2f938)
/*  f1a6e18:	3c048009 */ 	lui	$a0,%hi(menudialog_2f950)
/*  f1a6e1c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a6e20:	24849930 */ 	addiu	$a0,$a0,%lo(menudialog_2f950)
/*  f1a6e24:	1000001b */ 	beqz	$zero,.L0f1a6e94
/*  f1a6e28:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a6e2c:
/*  f1a6e2c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a6e30:	24849918 */ 	addiu	$a0,$a0,%lo(menudialog_2f938)
/*  f1a6e34:	10000017 */ 	beqz	$zero,.L0f1a6e94
/*  f1a6e38:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a6e3c:	3c028009 */ 	lui	$v0,%hi(var80088964)
/*  f1a6e40:	24428964 */ 	addiu	$v0,$v0,%lo(var80088964)
/*  f1a6e44:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f1a6e48:	10000011 */ 	beqz	$zero,.L0f1a6e90
/*  f1a6e4c:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f1a6e50:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f1a6e54:	1000000e */ 	beqz	$zero,.L0f1a6e90
/*  f1a6e58:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f1a6e5c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f1a6e60:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f1a6e64:	03b82021 */ 	addu	$a0,$sp,$t8
/*  f1a6e68:	0fc5b9f1 */ 	jal	langGet
/*  f1a6e6c:	9484002c */ 	lhu	$a0,0x2c($a0)
/*  f1a6e70:	10000009 */ 	beqz	$zero,.L0f1a6e98
/*  f1a6e74:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a6e78:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a6e7c:	55c00004 */ 	bnezl	$t6,.L0f1a6e90
/*  f1a6e80:	acc20008 */ 	sw	$v0,0x8($a2)
/*  f1a6e84:	10000002 */ 	beqz	$zero,.L0f1a6e90
/*  f1a6e88:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f1a6e8c:	acc20008 */ 	sw	$v0,0x8($a2)
.L0f1a6e90:
/*  f1a6e90:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a6e94:
/*  f1a6e94:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a6e98:
/*  f1a6e98:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a6e9c:	03e00008 */ 	jr	$ra
/*  f1a6ea0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler001a6ea4
/*  f1a6ea4:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1a6ea8:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1a6eac:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1a6eb0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1a6eb4:	1481012b */ 	bne	$a0,$at,.L0f1a7364
/*  f1a6eb8:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f1a6ebc:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a6ec0:	3c048009 */ 	lui	$a0,0x8009
/*  f1a6ec4:	90848964 */ 	lbu	$a0,-0x769c($a0)
/*  f1a6ec8:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f1a6ecc:	0fc685db */ 	jal	func0f1a176c
/*  f1a6ed0:	8cd00008 */ 	lw	$s0,0x8($a2)
/*  f1a6ed4:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a6ed8:	102000ac */ 	beqz	$at,.L0f1a718c
/*  f1a6edc:	3c0f8009 */ 	lui	$t7,%hi(var800897b4)
/*  f1a6ee0:	25ef97b4 */ 	addiu	$t7,$t7,%lo(var800897b4)
/*  f1a6ee4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a6ee8:	27a7007c */ 	addiu	$a3,$sp,0x7c
/*  f1a6eec:	00e25021 */ 	addu	$t2,$a3,$v0
/*  f1a6ef0:	ace10000 */ 	sw	$at,0x0($a3)
/*  f1a6ef4:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f1a6ef8:	3c0de700 */ 	lui	$t5,0xe700
/*  f1a6efc:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f1a6f00:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f1a6f04:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a6f08:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1a6f0c:	ace10008 */ 	sw	$at,0x8($a3)
/*  f1a6f10:	95e1000c */ 	lhu	$at,0xc($t7)
/*  f1a6f14:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a6f18:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f1a6f1c:	a4e1000c */ 	sh	$at,0xc($a3)
/*  f1a6f20:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f1a6f24:	91490000 */ 	lbu	$t1,0x0($t2)
/*  f1a6f28:	00003825 */ 	or	$a3,$zero,$zero
/*  f1a6f2c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f1a6f30:	afac00a4 */ 	sw	$t4,0xa4($sp)
/*  f1a6f34:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f1a6f38:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f1a6f3c:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1a6f40:	3c0bb900 */ 	lui	$t3,0xb900
/*  f1a6f44:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f1a6f48:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f1a6f4c:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f1a6f50:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1a6f54:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f1a6f58:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1a6f5c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1a6f60:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f1a6f64:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f1a6f68:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f1a6f6c:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1a6f70:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f1a6f74:	8fac00a4 */ 	lw	$t4,0xa4($sp)
/*  f1a6f78:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1a6f7c:	37390903 */ 	ori	$t9,$t9,0x903
/*  f1a6f80:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f1a6f84:	afad00a4 */ 	sw	$t5,0xa4($sp)
/*  f1a6f88:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f1a6f8c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f1a6f90:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f1a6f94:	240a0c00 */ 	addiu	$t2,$zero,0xc00
/*  f1a6f98:	3c0c800b */ 	lui	$t4,0x800b
/*  f1a6f9c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f1a6fa0:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1a6fa4:	00095880 */ 	sll	$t3,$t1,0x2
/*  f1a6fa8:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f1a6fac:	af190000 */ 	sw	$t9,0x0($t8)
/*  f1a6fb0:	8d8cb5a8 */ 	lw	$t4,-0x4a58($t4)
/*  f1a6fb4:	01695823 */ 	subu	$t3,$t3,$t1
/*  f1a6fb8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1a6fbc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a6fc0:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f1a6fc4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a6fc8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a6fcc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a6fd0:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1a6fd4:	016c2821 */ 	addu	$a1,$t3,$t4
/*  f1a6fd8:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f1a6fdc:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1a6fe0:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f1a6fe4:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f1a6fe8:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1a6fec:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a6ff0:	af190000 */ 	sw	$t9,0x0($t8)
/*  f1a6ff4:	8faa00a4 */ 	lw	$t2,0xa4($sp)
/*  f1a6ff8:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f1a6ffc:	3c0dfffc */ 	lui	$t5,0xfffc
/*  f1a7000:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f1a7004:	afab00a4 */ 	sw	$t3,0xa4($sp)
/*  f1a7008:	35adf279 */ 	ori	$t5,$t5,0xf279
/*  f1a700c:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f1a7010:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f1a7014:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f1a7018:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1a701c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a7020:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1a7024:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f1a7028:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f1a702c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1a7030:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f1a7034:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1a7038:	3c0bfb00 */ 	lui	$t3,0xfb00
/*  f1a703c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1a7040:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f1a7044:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f1a7048:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f1a704c:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f1a7050:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a7054:	03202825 */ 	or	$a1,$t9,$zero
/*  f1a7058:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1a705c:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f1a7060:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f1a7064:	000ec202 */ 	srl	$t8,$t6,0x8
/*  f1a7068:	03017825 */ 	or	$t7,$t8,$at
/*  f1a706c:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f1a7070:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1a7074:	3c078008 */ 	lui	$a3,%hi(var8007fac0)
/*  f1a7078:	24e7fac0 */ 	addiu	$a3,$a3,%lo(var8007fac0)
/*  f1a707c:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f1a7080:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f1a7084:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f1a7088:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f1a708c:	03203025 */ 	or	$a2,$t9,$zero
/*  f1a7090:	256c003c */ 	addiu	$t4,$t3,0x3c
/*  f1a7094:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1a7098:	01ae0019 */ 	multu	$t5,$t6
/*  f1a709c:	8e0b0004 */ 	lw	$t3,0x4($s0)
/*  f1a70a0:	3c01e400 */ 	lui	$at,0xe400
/*  f1a70a4:	256c0027 */ 	addiu	$t4,$t3,0x27
/*  f1a70a8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1a70ac:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f1a70b0:	0000c012 */ 	mflo	$t8
/*  f1a70b4:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f1a70b8:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f1a70bc:	03215025 */ 	or	$t2,$t9,$at
/*  f1a70c0:	014ec025 */ 	or	$t8,$t2,$t6
/*  f1a70c4:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f1a70c8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a70cc:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f1a70d0:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1a70d4:	25f90006 */ 	addiu	$t9,$t7,0x6
/*  f1a70d8:	00195880 */ 	sll	$t3,$t9,0x2
/*  f1a70dc:	016c0019 */ 	multu	$t3,$t4
/*  f1a70e0:	270f0003 */ 	addiu	$t7,$t8,0x3
/*  f1a70e4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1a70e8:	332b0fff */ 	andi	$t3,$t9,0xfff
/*  f1a70ec:	240f0480 */ 	addiu	$t7,$zero,0x480
/*  f1a70f0:	3c18b400 */ 	lui	$t8,0xb400
/*  f1a70f4:	00006812 */ 	mflo	$t5
/*  f1a70f8:	31aa0fff */ 	andi	$t2,$t5,0xfff
/*  f1a70fc:	000a7300 */ 	sll	$t6,$t2,0xc
/*  f1a7100:	01cb6025 */ 	or	$t4,$t6,$t3
/*  f1a7104:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f1a7108:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f1a710c:	3c0bb300 */ 	lui	$t3,0xb300
/*  f1a7110:	25aa0008 */ 	addiu	$t2,$t5,0x8
/*  f1a7114:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f1a7118:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f1a711c:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f1a7120:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1a7124:	01a01025 */ 	or	$v0,$t5,$zero
/*  f1a7128:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f1a712c:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f1a7130:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f1a7134:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f1a7138:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f1a713c:	03201825 */ 	or	$v1,$t9,$zero
/*  f1a7140:	240effff */ 	addiu	$t6,$zero,-1
/*  f1a7144:	01ac001a */ 	div	$zero,$t5,$t4
/*  f1a7148:	00005012 */ 	mflo	$t2
/*  f1a714c:	3158ffff */ 	andi	$t8,$t2,0xffff
/*  f1a7150:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f1a7154:	35f9fc00 */ 	ori	$t9,$t7,0xfc00
/*  f1a7158:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1a715c:	15800002 */ 	bnez	$t4,.L0f1a7168
/*  f1a7160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a7164:	0007000d */ 	break	0x7
.L0f1a7168:
/*  f1a7168:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a716c:	15810004 */ 	bne	$t4,$at,.L0f1a7180
/*  f1a7170:	3c018000 */ 	lui	$at,0x8000
/*  f1a7174:	15a10002 */ 	bne	$t5,$at,.L0f1a7180
/*  f1a7178:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a717c:	0006000d */ 	break	0x6
.L0f1a7180:
/*  f1a7180:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f1a7184:	10000008 */ 	beqz	$zero,.L0f1a71a8
/*  f1a7188:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a718c:
/*  f1a718c:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f1a7190:	8d6d0008 */ 	lw	$t5,0x8($t3)
/*  f1a7194:	05a10003 */ 	bgez	$t5,.L0f1a71a4
/*  f1a7198:	000d6043 */ 	sra	$t4,$t5,0x1
/*  f1a719c:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f1a71a0:	00016043 */ 	sra	$t4,$at,0x1
.L0f1a71a4:
/*  f1a71a4:	afac0094 */ 	sw	$t4,0x94($sp)
.L0f1a71a8:
/*  f1a71a8:	0fc54d8a */ 	jal	func0f153628
/*  f1a71ac:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f1a71b0:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a71b4:	0fc69b23 */ 	jal	func0f1a6c8c
/*  f1a71b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a71bc:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1a71c0:	8d4afb14 */ 	lw	$t2,-0x4ec($t2)
/*  f1a71c4:	3c078008 */ 	lui	$a3,0x8008
/*  f1a71c8:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f1a71cc:	8ce7fb18 */ 	lw	$a3,-0x4e8($a3)
/*  f1a71d0:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f1a71d4:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f1a71d8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a71dc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a71e0:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a71e4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a71e8:	8fa20094 */ 	lw	$v0,0x94($sp)
/*  f1a71ec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a71f0:	54410006 */ 	bnel	$v0,$at,.L0f1a720c
/*  f1a71f4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a71f8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a71fc:	270f0040 */ 	addiu	$t7,$t8,0x40
/*  f1a7200:	10000007 */ 	beqz	$zero,.L0f1a7220
/*  f1a7204:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a7208:	8e190000 */ 	lw	$t9,0x0($s0)
.L0f1a720c:
/*  f1a720c:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f1a7210:	03227021 */ 	addu	$t6,$t9,$v0
/*  f1a7214:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f1a7218:	01cd6023 */ 	subu	$t4,$t6,$t5
/*  f1a721c:	afac009c */ 	sw	$t4,0x9c($sp)
.L0f1a7220:
/*  f1a7220:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f1a7224:	25580008 */ 	addiu	$t8,$t2,0x8
/*  f1a7228:	0c002f02 */ 	jal	func0000bc08
/*  f1a722c:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f1a7230:	0c002f06 */ 	jal	func0000bc18
/*  f1a7234:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a7238:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a723c:	3c198008 */ 	lui	$t9,0x8008
/*  f1a7240:	8f39fb14 */ 	lw	$t9,-0x4ec($t9)
/*  f1a7244:	8deffb18 */ 	lw	$t7,-0x4e8($t7)
/*  f1a7248:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f1a724c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a7250:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a7254:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f1a7258:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a725c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a7260:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a7264:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f1a7268:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f1a726c:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f1a7270:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f1a7274:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a7278:	0fc5580f */ 	jal	func0f15603c
/*  f1a727c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1a7280:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a7284:	0fc69b31 */ 	jal	func0f1a6cc4
/*  f1a7288:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a728c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a7290:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f1a7294:	3c078008 */ 	lui	$a3,0x8008
/*  f1a7298:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f1a729c:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f1a72a0:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f1a72a4:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f1a72a8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a72ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a72b0:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a72b4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a72b8:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1a72bc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a72c0:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f1a72c4:	15810005 */ 	bne	$t4,$at,.L0f1a72dc
/*  f1a72c8:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f1a72cc:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1a72d0:	25580040 */ 	addiu	$t8,$t2,0x40
/*  f1a72d4:	10000006 */ 	beqz	$zero,.L0f1a72f0
/*  f1a72d8:	afb8009c */ 	sw	$t8,0x9c($sp)
.L0f1a72dc:
/*  f1a72dc:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a72e0:	000e6843 */ 	sra	$t5,$t6,0x1
/*  f1a72e4:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f1a72e8:	016d6023 */ 	subu	$t4,$t3,$t5
/*  f1a72ec:	afac009c */ 	sw	$t4,0x9c($sp)
.L0f1a72f0:
/*  f1a72f0:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f1a72f4:	25580019 */ 	addiu	$t8,$t2,0x19
/*  f1a72f8:	0c002f02 */ 	jal	func0000bc08
/*  f1a72fc:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f1a7300:	0c002f06 */ 	jal	func0000bc18
/*  f1a7304:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a7308:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a730c:	3c198008 */ 	lui	$t9,0x8008
/*  f1a7310:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f1a7314:	8deffb10 */ 	lw	$t7,-0x4f0($t7)
/*  f1a7318:	87ab0044 */ 	lh	$t3,0x44($sp)
/*  f1a731c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a7320:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a7324:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f1a7328:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a732c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a7330:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a7334:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f1a7338:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f1a733c:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f1a7340:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f1a7344:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f1a7348:	0fc5580f */ 	jal	func0f15603c
/*  f1a734c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a7350:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a7354:	0fc54de0 */ 	jal	func0f153780
/*  f1a7358:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a735c:	10000003 */ 	beqz	$zero,.L0f1a736c
/*  f1a7360:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a7364:
/*  f1a7364:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a7368:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a736c:
/*  f1a736c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1a7370:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f1a7374:	03e00008 */ 	jr	$ra
/*  f1a7378:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog001a737c
/*  f1a737c:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a7380:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a7384:	00803025 */ 	or	$a2,$a0,$zero
/*  f1a7388:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a738c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a7390:	3c048009 */ 	lui	$a0,0x8009
/*  f1a7394:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a7398:	90848964 */ 	lbu	$a0,-0x769c($a0)
/*  f1a739c:	0fc685db */ 	jal	func0f1a176c
/*  f1a73a0:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1a73a4:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a73a8:	14200065 */ 	bnez	$at,.L0f1a7540
/*  f1a73ac:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f1a73b0:	3c0e8009 */ 	lui	$t6,%hi(hoverprops)
/*  f1a73b4:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f1a73b8:	25ce97cc */ 	addiu	$t6,$t6,%lo(hoverprops)
/*  f1a73bc:	25d8006c */ 	addiu	$t8,$t6,0x6c
/*  f1a73c0:	00e0c825 */ 	or	$t9,$a3,$zero
.L0f1a73c4:
/*  f1a73c4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a73c8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a73cc:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f1a73d0:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f1a73d4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a73d8:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f1a73dc:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a73e0:	15d8fff8 */ 	bne	$t6,$t8,.L0f1a73c4
/*  f1a73e4:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f1a73e8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1a73ec:	10c10008 */ 	beq	$a2,$at,.L0f1a7410
/*  f1a73f0:	3c088007 */ 	lui	$t0,0x8007
/*  f1a73f4:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a73f8:	10c10051 */ 	beq	$a2,$at,.L0f1a7540
/*  f1a73fc:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a7400:	10c10019 */ 	beq	$a2,$at,.L0f1a7468
/*  f1a7404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a7408:	1000004e */ 	beqz	$zero,.L0f1a7544
/*  f1a740c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7410:
/*  f1a7410:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f1a7414:	44800000 */ 	mtc1	$zero,$f0
/*  f1a7418:	3c0a800a */ 	lui	$t2,%hi(var8009e000)
/*  f1a741c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a7420:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7424:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a7428:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a742c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a7430:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7434:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a7438:	254ae000 */ 	addiu	$t2,$t2,%lo(var8009e000)
/*  f1a743c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a7440:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a7444:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a7448:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a744c:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a7450:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a7454:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a7458:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a745c:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7460:	10000037 */ 	beqz	$zero,.L0f1a7540
/*  f1a7464:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.L0f1a7468:
/*  f1a7468:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1a746c:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f1a7470:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f1a7474:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f1a7478:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1a747c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7480:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1a7484:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1a7488:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1a748c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1a7490:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1a7494:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f1a7498:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f1a749c:	50800029 */ 	beqzl	$a0,.L0f1a7544
/*  f1a74a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a74a4:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f1a74a8:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f1a74ac:	2445fff2 */ 	addiu	$a1,$v0,-14
/*  f1a74b0:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1a74b4:	15f80022 */ 	bne	$t7,$t8,.L0f1a7540
/*  f1a74b8:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f1a74bc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1a74c0:	00ee2021 */ 	addu	$a0,$a3,$t6
/*  f1a74c4:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f1a74c8:	94880008 */ 	lhu	$t0,0x8($a0)
/*  f1a74cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a74d0:	44992000 */ 	mtc1	$t9,$f4
/*  f1a74d4:	44883000 */ 	mtc1	$t0,$f6
/*  f1a74d8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1a74dc:	05010004 */ 	bgez	$t0,.L0f1a74f0
/*  f1a74e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a74e4:	44815000 */ 	mtc1	$at,$f10
/*  f1a74e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a74ec:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1a74f0:
/*  f1a74f0:	3c017f1c */ 	lui	$at,%hi(var7f1b99d4)
/*  f1a74f4:	c43099d4 */ 	lwc1	$f16,%lo(var7f1b99d4)($at)
/*  f1a74f8:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f1a74fc:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7500:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f1a7504:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a7508:	3c017f1c */ 	lui	$at,%hi(var7f1b99d8)
/*  f1a750c:	ac69084c */ 	sw	$t1,0x84c($v1)
/*  f1a7510:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f1a7514:	3c0a8009 */ 	lui	$t2,%hi(var800897c4)
/*  f1a7518:	254a97c4 */ 	addiu	$t2,$t2,%lo(var800897c4)
/*  f1a751c:	e46c0d84 */ 	swc1	$f12,0xd84($v1)
/*  f1a7520:	c43299d8 */ 	lwc1	$f18,%lo(var7f1b99d8)($at)
/*  f1a7524:	3c01800a */ 	lui	$at,0x800a
/*  f1a7528:	c4249fc4 */ 	lwc1	$f4,-0x603c($at)
/*  f1a752c:	ac6a0df4 */ 	sw	$t2,0xdf4($v1)
/*  f1a7530:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f1a7534:	46065080 */ 	add.s	$f2,$f10,$f6
/*  f1a7538:	e4620d8c */ 	swc1	$f2,0xd8c($v1)
/*  f1a753c:	e4620d64 */ 	swc1	$f2,0xd64($v1)
.L0f1a7540:
/*  f1a7540:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7544:
/*  f1a7544:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1a7548:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a754c:	03e00008 */ 	jr	$ra
/*  f1a7550:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a7554
/*  f1a7554:	3c028009 */ 	lui	$v0,%hi(g_frWeaponMenuDialog)
/*  f1a7558:	03e00008 */ 	jr	$ra
/*  f1a755c:	24428d78 */ 	addiu	$v0,$v0,%lo(g_frWeaponMenuDialog)
);

GLOBAL_ASM(
glabel func0f1a7560
/*  f1a7560:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f1a7564:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f1a7568:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a756c:	30a4ffff */ 	andi	$a0,$a1,0xffff
/*  f1a7570:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1a7574:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1a7578:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1a757c:	00e08825 */ 	or	$s1,$a3,$zero
/*  f1a7580:	00c09025 */ 	or	$s2,$a2,$zero
/*  f1a7584:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f1a7588:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f1a758c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f1a7590:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f1a7594:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f1a7598:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1a759c:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f1a75a0:	0fc59ca5 */ 	jal	func0f167294
/*  f1a75a4:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f1a75a8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1a75ac:	0fc59ca0 */ 	jal	func0f167280
/*  f1a75b0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f1a75b4:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f1a75b8:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f1a75bc:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a75c0:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f1a75c4:	0c008c67 */ 	jal	func0002319c
/*  f1a75c8:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f1a75cc:	8fb6006c */ 	lw	$s6,0x6c($sp)
/*  f1a75d0:	3c1700ff */ 	lui	$s7,0xff
/*  f1a75d4:	36f7ffff */ 	ori	$s7,$s7,0xffff
/*  f1a75d8:	12c00049 */ 	beqz	$s6,.L0f1a7700
/*  f1a75dc:	02c0a825 */ 	or	$s5,$s6,$zero
/*  f1a75e0:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f1a75e4:	02d77824 */ 	and	$t7,$s6,$s7
/*  f1a75e8:	026f2021 */ 	addu	$a0,$s3,$t7
/*  f1a75ec:	0093c823 */ 	subu	$t9,$a0,$s3
/*  f1a75f0:	03193023 */ 	subu	$a2,$t8,$t9
/*  f1a75f4:	02061823 */ 	subu	$v1,$s0,$a2
/*  f1a75f8:	02644023 */ 	subu	$t0,$s3,$a0
/*  f1a75fc:	00684821 */ 	addu	$t1,$v1,$t0
/*  f1a7600:	afa90084 */ 	sw	$t1,0x84($sp)
/*  f1a7604:	0fc5d7bd */ 	jal	func0f175ef4
/*  f1a7608:	00732821 */ 	addu	$a1,$v1,$s3
/*  f1a760c:	8fbe00a0 */ 	lw	$s8,0xa0($sp)
/*  f1a7610:	8e640018 */ 	lw	$a0,0x18($s3)
/*  f1a7614:	86650016 */ 	lh	$a1,0x16($s3)
/*  f1a7618:	02323823 */ 	subu	$a3,$s1,$s2
/*  f1a761c:	0fc5cd0d */ 	jal	func0f173434
/*  f1a7620:	03c03025 */ 	or	$a2,$s8,$zero
/*  f1a7624:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f1a7628:	5140002b */ 	beqzl	$t2,.L0f1a76d8
/*  f1a762c:	02b74824 */ 	and	$t1,$s5,$s7
/*  f1a7630:	8fb0006c */ 	lw	$s0,0x6c($sp)
.L0f1a7634:
/*  f1a7634:	8fb10074 */ 	lw	$s1,0x74($sp)
/*  f1a7638:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a763c:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f1a7640:	0c008c67 */ 	jal	func0002319c
/*  f1a7644:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f1a7648:	8fb6006c */ 	lw	$s6,0x6c($sp)
/*  f1a764c:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a7650:	02202825 */ 	or	$a1,$s1,$zero
/*  f1a7654:	12c00004 */ 	beqz	$s6,.L0f1a7668
/*  f1a7658:	02003025 */ 	or	$a2,$s0,$zero
/*  f1a765c:	02d0a023 */ 	subu	$s4,$s6,$s0
/*  f1a7660:	10000006 */ 	beqz	$zero,.L0f1a767c
/*  f1a7664:	02179024 */ 	and	$s2,$s0,$s7
.L0f1a7668:
/*  f1a7668:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f1a766c:	02179024 */ 	and	$s2,$s0,$s7
/*  f1a7670:	01736021 */ 	addu	$t4,$t3,$s3
/*  f1a7674:	01936823 */ 	subu	$t5,$t4,$s3
/*  f1a7678:	01b2a023 */ 	subu	$s4,$t5,$s2
.L0f1a767c:
/*  f1a767c:	0c008cc5 */ 	jal	func00023314
/*  f1a7680:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1a7684:	962e0000 */ 	lhu	$t6,0x0($s1)
/*  f1a7688:	24010018 */ 	addiu	$at,$zero,0x18
/*  f1a768c:	02727821 */ 	addu	$t7,$s3,$s2
/*  f1a7690:	15c10004 */ 	bne	$t6,$at,.L0f1a76a4
/*  f1a7694:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f1a7698:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f1a769c:	10000002 */ 	beqz	$zero,.L0f1a76a8
/*  f1a76a0:	8c43000c */ 	lw	$v1,0xc($v0)
.L0f1a76a4:
/*  f1a76a4:	00001825 */ 	or	$v1,$zero,$zero
.L0f1a76a8:
/*  f1a76a8:	02b7c824 */ 	and	$t9,$s5,$s7
/*  f1a76ac:	02793021 */ 	addu	$a2,$s3,$t9
/*  f1a76b0:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f1a76b4:	02802825 */ 	or	$a1,$s4,$zero
/*  f1a76b8:	03c03825 */ 	or	$a3,$s8,$zero
/*  f1a76bc:	0fc5d5b0 */ 	jal	func0f1756c0
/*  f1a76c0:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f1a76c4:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f1a76c8:	02a2a821 */ 	addu	$s5,$s5,$v0
/*  f1a76cc:	5500ffd9 */ 	bnezl	$t0,.L0f1a7634
/*  f1a76d0:	8fb0006c */ 	lw	$s0,0x6c($sp)
/*  f1a76d4:	02b74824 */ 	and	$t1,$s5,$s7
.L0f1a76d8:
/*  f1a76d8:	02695021 */ 	addu	$t2,$s3,$t1
/*  f1a76dc:	01533023 */ 	subu	$a2,$t2,$s3
/*  f1a76e0:	24c6000f */ 	addiu	$a2,$a2,0xf
/*  f1a76e4:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f1a76e8:	00c15824 */ 	and	$t3,$a2,$at
/*  f1a76ec:	01603025 */ 	or	$a2,$t3,$zero
/*  f1a76f0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f1a76f4:	02602825 */ 	or	$a1,$s3,$zero
/*  f1a76f8:	0fc59caa */ 	jal	func0f1672a8
/*  f1a76fc:	8fa700a4 */ 	lw	$a3,0xa4($sp)
.L0f1a7700:
/*  f1a7700:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1a7704:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1a7708:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1a770c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1a7710:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f1a7714:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f1a7718:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f1a771c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f1a7720:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f1a7724:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f1a7728:	03e00008 */ 	jr	$ra
/*  f1a772c:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f1a7730
/*  f1a7730:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f1a7734:	3c010001 */ 	lui	$at,0x1
/*  f1a7738:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1a773c:	0041082b */ 	sltu	$at,$v0,$at
/*  f1a7740:	10200012 */ 	beqz	$at,.L0f1a778c
/*  f1a7744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a7748:	8dce9990 */ 	lw	$t6,-0x6670($t6)
/*  f1a774c:	00021c00 */ 	sll	$v1,$v0,0x10
/*  f1a7750:	00037c03 */ 	sra	$t7,$v1,0x10
/*  f1a7754:	11c0000d */ 	beqz	$t6,.L0f1a778c
/*  f1a7758:	01e01825 */ 	or	$v1,$t7,$zero
/*  f1a775c:	3c188009 */ 	lui	$t8,0x8009
/*  f1a7760:	27059990 */ 	addiu	$a1,$t8,-26224
/*  f1a7764:	8ca60000 */ 	lw	$a2,0x0($a1)
/*  f1a7768:	84d90000 */ 	lh	$t9,0x0($a2)
.L0f1a776c:
/*  f1a776c:	54790004 */ 	bnel	$v1,$t9,.L0f1a7780
/*  f1a7770:	8ca60004 */ 	lw	$a2,0x4($a1)
/*  f1a7774:	03e00008 */ 	jr	$ra
/*  f1a7778:	ac860004 */ 	sw	$a2,0x4($a0)
/*  f1a777c:	8ca60004 */ 	lw	$a2,0x4($a1)
.L0f1a7780:
/*  f1a7780:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1a7784:	54c0fff9 */ 	bnezl	$a2,.L0f1a776c
/*  f1a7788:	84d90000 */ 	lh	$t9,0x0($a2)
.L0f1a778c:
/*  f1a778c:	03e00008 */ 	jr	$ra
/*  f1a7790:	00000000 */ 	sll	$zero,$zero,0x0
);

void *func0f1a7794(u16 fileid, u32 arg1, s32 arg2, s32 arg3)
{
	void *ptr;

	var8005d9a0 = 6;

	if (arg1) {
		ptr = func0f167200(fileid, 0x11, arg1, arg2);
	} else {
		ptr = func0f1670fc(fileid, 0x11);
	}

	func0f1a7730(ptr);
	func00022a24(ptr, 0x5000000, ptr);
	func0f1a7560(ptr, fileid, 0x5000000, ptr, arg3, arg1 < 1);

	return ptr;
}

void *fileLoad(u16 fileid)
{
	return func0f1a7794(fileid, 0, 0, 0);
}

void *func0f1a7878(u16 fileid, s32 arg1, s32 arg2)
{
	return func0f1a7794(fileid, arg1, arg2, 0);
}
