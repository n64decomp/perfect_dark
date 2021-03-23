#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/ceil.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0e0770.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/inventory/inventory.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/texture.h"
#include "game/game_173a00.h"
#include "game/training/menus.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

struct menudialog g_BioProfileMenuDialog;
struct menudialog g_BioTextMenuDialog;
struct menudialog g_HangarLocationDetailsMenuDialog;
struct menudialog g_HangarVehicleDetailsMenuDialog;

s32 frDetailsOkMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 i;

	switch (operation) {
	case MENUOP_CHECKPREFOCUSED:
		return true;
	case MENUOP_SET:
		if (frIsInTraining() == false) {
			s32 weapon = frGetWeaponBySlot(frGetSlot());

			if (g_FrWeaponNum != WEAPON_UNARMED) {
				invRemoveItemByNum(g_FrWeaponNum);
			}

			if (weapon != WEAPON_UNARMED) {
				invGiveSingleWeapon(weapon);
			}

			invSetCurrentIndex(1);

			if (handGetWeaponNum(HAND_RIGHT) != weapon) {
				currentPlayerEquipWeaponWrapper(HAND_RIGHT, weapon);
			}

			g_FrWeaponNum = weapon;

			for (i = 0; i < 4; i++) {
				g_Vars.currentplayer->hands[0].unk0d74[i] = 0;
				g_Vars.currentplayer->hands[1].unk0d74[i] = 0;
			}

			frBeginSession(weapon);
		}

		func0f0f8120();
		break;
	}

	return 0;
}

s32 frAbortMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (frIsInTraining()) {
			frEndSession(true);
		}
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuhandler001a348c
.late_rodata
glabel var7f1b98f4
.word menuhandler001a348c+0x54 # f1a34e0
glabel var7f1b98f8
.word menuhandler001a348c+0x3c # f1a34c8
glabel var7f1b98fc
.word menuhandler001a348c+0x68 # f1a34f4
glabel var7f1b9900
.word menuhandler001a348c+0x44 # f1a34d0
glabel var7f1b9904
.word menuhandler001a348c+0x4c # f1a34d8
glabel var7f1b9908
.word menuhandler001a348c+0x70 # f1a34fc
glabel var7f1b990c
.word menuhandler001a348c+0xf8 # f1a3584
glabel var7f1b9910
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9914
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9918
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b991c
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9920
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9924
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9928
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b992c
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9930
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9934
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9938
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b993c
.word menuhandler001a348c+0x10c # f1a3598
glabel var7f1b9940
.word menuhandler001a348c+0x30 # f1a34bc
.text
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
/*  f1a34b8:	00000000 */ 	nop
/*  f1a34bc:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f1a34c0:	10000134 */ 	b	.L0f1a3994
/*  f1a34c4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1a34c8:	10000132 */ 	b	.L0f1a3994
/*  f1a34cc:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f1a34d0:	10000131 */ 	b	.L0f1a3998
/*  f1a34d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a34d8:	1000012e */ 	b	.L0f1a3994
/*  f1a34dc:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f1a34e0:	0fc674b8 */ 	jal	frGetNumWeaponsAvailable
/*  f1a34e4:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f1a34e8:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f1a34ec:	10000129 */ 	b	.L0f1a3994
/*  f1a34f0:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a34f4:	10000128 */ 	b	.L0f1a3998
/*  f1a34f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a34fc:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a3500:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f1a3504:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f1a3508:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a350c:	0fc67330 */ 	jal	frGetWeaponIndexByWeapon
/*  f1a3510:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3514:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3518:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a351c:	0fc679ea */ 	jal	frLoadData
/*  f1a3520:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f1a3524:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f1a3528:	0fc67497 */ 	jal	frSetSlot
/*  f1a352c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1a3530:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f1a3534:	1300000c */ 	beqz	$t8,.L0f1a3568
/*  f1a3538:	00000000 */ 	nop
/*  f1a353c:	0fc67330 */ 	jal	frGetWeaponIndexByWeapon
/*  f1a3540:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f1a3544:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1a3548:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a354c:	0fc67570 */ 	jal	frSetDifficulty
/*  f1a3550:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a3554:	3c048009 */ 	lui	$a0,%hi(g_FrDifficultyMenuDialog)
/*  f1a3558:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a355c:	24848d38 */ 	addiu	$a0,$a0,%lo(g_FrDifficultyMenuDialog)
/*  f1a3560:	1000010d */ 	b	.L0f1a3998
/*  f1a3564:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3568:
/*  f1a3568:	0fc67570 */ 	jal	frSetDifficulty
/*  f1a356c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a3570:	3c048009 */ 	lui	$a0,%hi(g_FrTrainingInfoPreGameMenuDialog)
/*  f1a3574:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1a3578:	24848f60 */ 	addiu	$a0,$a0,%lo(g_FrTrainingInfoPreGameMenuDialog)
/*  f1a357c:	10000106 */ 	b	.L0f1a3998
/*  f1a3580:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a3584:	0fc67494 */ 	jal	frGetSlot
/*  f1a3588:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f1a358c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f1a3590:	10000100 */ 	b	.L0f1a3994
/*  f1a3594:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f1a3598:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f1a359c:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f1a35a0:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f1a35a4:	8cc40004 */ 	lw	$a0,0x4($a2)
/*  f1a35a8:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f1a35ac:	afa80098 */ 	sw	$t0,0x98($sp)
/*  f1a35b0:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f1a35b4:	0fc67330 */ 	jal	frGetWeaponIndexByWeapon
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
/*  f1a35ec:	0fc28857 */ 	jal	weaponGetName
/*  f1a35f0:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f1a35f4:	0c002f02 */ 	jal	viGetWidth
/*  f1a35f8:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f1a35fc:	0c002f06 */ 	jal	viGetHeight
/*  f1a3600:	a7a2003e */ 	sh	$v0,0x3e($sp)
/*  f1a3604:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm1)
/*  f1a3608:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicSm2)
/*  f1a360c:	8dcefb0c */ 	lw	$t6,%lo(g_FontHandelGothicSm2)($t6)
/*  f1a3610:	8f39fb10 */ 	lw	$t9,%lo(g_FontHandelGothicSm1)($t9)
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
/*  f1a3648:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a3704:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f1a3708:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
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
/*  f1a3794:	3c098008 */ 	lui	$t1,%hi(g_ScaleX)
/*  f1a3798:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a379c:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f1a37a0:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f1a37a4:	2529fac0 */ 	addiu	$t1,$t1,%lo(g_ScaleX)
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
/*  f1a37ec:	1000000d */ 	b	.L0f1a3824
/*  f1a37f0:	8d19000c */ 	lw	$t9,0xc($t0)
/*  f1a37f4:	3c068844 */ 	lui	$a2,0x8844
.L0f1a37f8:
/*  f1a37f8:	10000009 */ 	b	.L0f1a3820
/*  f1a37fc:	34c600ff */ 	ori	$a2,$a2,0xff
/*  f1a3800:	3c069999 */ 	lui	$a2,0x9999
.L0f1a3804:
/*  f1a3804:	10000006 */ 	b	.L0f1a3820
/*  f1a3808:	34c69fff */ 	ori	$a2,$a2,0x9fff
/*  f1a380c:	3c06bb99 */ 	lui	$a2,0xbb99
.L0f1a3810:
/*  f1a3810:	10000003 */ 	b	.L0f1a3820
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
/*  f1a394c:	00000000 */ 	nop
/*  f1a3950:	0007000d */ 	break	0x7
.L0f1a3954:
/*  f1a3954:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a3958:	17010004 */ 	bne	$t8,$at,.L0f1a396c
/*  f1a395c:	3c018000 */ 	lui	$at,0x8000
/*  f1a3960:	17210002 */ 	bne	$t9,$at,.L0f1a396c
/*  f1a3964:	00000000 */ 	nop
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
/*  f1a398c:	10000002 */ 	b	.L0f1a3998
/*  f1a3990:	8fa2009c */ 	lw	$v0,0x9c($sp)
.L0f1a3994:
/*  f1a3994:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a3998:
/*  f1a3998:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1a399c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f1a39a0:	03e00008 */ 	jr	$ra
/*  f1a39a4:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel menuhandler001a348c
.late_rodata
glabel var7f1b98f4
.word menuhandler001a348c+0x54 # f1a34e0
glabel var7f1b98f8
.word menuhandler001a348c+0x3c # f1a34c8
glabel var7f1b98fc
.word menuhandler001a348c+0x68 # f1a34f4
glabel var7f1b9900
.word menuhandler001a348c+0x44 # f1a34d0
glabel var7f1b9904
.word menuhandler001a348c+0x4c # f1a34d8
glabel var7f1b9908
.word menuhandler001a348c+0x70 # f1a34fc
glabel var7f1b990c
.word menuhandler001a348c+0xf8 # f1a3584
glabel var7f1b9910
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9914
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9918
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b991c
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9920
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9924
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9928
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b992c
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9930
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9934
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b9938
.word menuhandler001a348c+0x508 # f1a3994
glabel var7f1b993c
.word menuhandler001a348c+0x10c # f1a3598
glabel var7f1b9940
.word menuhandler001a348c+0x30 # f1a34bc
.text
/*  f19d49c:	248effff */ 	addiu	$t6,$a0,-1
/*  f19d4a0:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f19d4a4:	2dc10014 */ 	sltiu	$at,$t6,0x14
/*  f19d4a8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f19d4ac:	10200151 */ 	beqz	$at,.NB0f19d9f4
/*  f19d4b0:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f19d4b4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19d4b8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f19d4bc:	002e0821 */ 	addu	$at,$at,$t6
/*  f19d4c0:	8c2e3f14 */ 	lw	$t6,0x3f14($at)
/*  f19d4c4:	01c00008 */ 	jr	$t6
/*  f19d4c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d4cc:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f19d4d0:	10000148 */ 	beqz	$zero,.NB0f19d9f4
/*  f19d4d4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f19d4d8:	10000146 */ 	beqz	$zero,.NB0f19d9f4
/*  f19d4dc:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f19d4e0:	10000145 */ 	beqz	$zero,.NB0f19d9f8
/*  f19d4e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f19d4e8:	10000142 */ 	beqz	$zero,.NB0f19d9f4
/*  f19d4ec:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f19d4f0:	0fc65ce0 */ 	jal	0xf197380
/*  f19d4f4:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f19d4f8:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f19d4fc:	1000013d */ 	beqz	$zero,.NB0f19d9f4
/*  f19d500:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f19d504:	1000013c */ 	beqz	$zero,.NB0f19d9f8
/*  f19d508:	00001025 */ 	or	$v0,$zero,$zero
/*  f19d50c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f19d510:	0fc65cc2 */ 	jal	0xf197308
/*  f19d514:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f19d518:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f19d51c:	0fc65b4c */ 	jal	0xf196d30
/*  f19d520:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d524:	0fc65a84 */ 	jal	0xf196a10
/*  f19d528:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d52c:	3c188007 */ 	lui	$t8,0x8007
/*  f19d530:	8f183af0 */ 	lw	$t8,0x3af0($t8)
/*  f19d534:	3c0e800a */ 	lui	$t6,0x800a
/*  f19d538:	25ce27c0 */ 	addiu	$t6,$t6,0x27c0
/*  f19d53c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f19d540:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f19d544:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f19d548:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f19d54c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f19d550:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f19d554:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f19d558:	032e1821 */ 	addu	$v1,$t9,$t6
/*  f19d55c:	846f0484 */ 	lh	$t7,0x484($v1)
/*  f19d560:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f19d564:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f19d568:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f19d56c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f19d570:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f19d574:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f19d578:	832e03f0 */ 	lb	$t6,0x3f0($t9)
/*  f19d57c:	29c10002 */ 	slti	$at,$t6,0x2
/*  f19d580:	14200007 */ 	bnez	$at,.NB0f19d5a0
/*  f19d584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d588:	0fc3bfcf */ 	jal	0xf0eff3c
/*  f19d58c:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f19d590:	3c048009 */ 	lui	$a0,0x8009
/*  f19d594:	0fc3beda */ 	jal	0xf0efb68
/*  f19d598:	2484b4e8 */ 	addiu	$a0,$a0,-19224
/*  f19d59c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
.NB0f19d5a0:
/*  f19d5a0:	0fc661eb */ 	jal	0xf1987ac
/*  f19d5a4:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f19d5a8:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f19d5ac:	0fc65cbf */ 	jal	0xf1972fc
/*  f19d5b0:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f19d5b4:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f19d5b8:	11e0000c */ 	beqz	$t7,.NB0f19d5ec
/*  f19d5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d5c0:	0fc65b4c */ 	jal	0xf196d30
/*  f19d5c4:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f19d5c8:	0fc65a84 */ 	jal	0xf196a10
/*  f19d5cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d5d0:	0fc65d88 */ 	jal	0xf197620
/*  f19d5d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d5d8:	3c048009 */ 	lui	$a0,0x8009
/*  f19d5dc:	0fc3beda */ 	jal	0xf0efb68
/*  f19d5e0:	2484b4a8 */ 	addiu	$a0,$a0,-19288
/*  f19d5e4:	10000104 */ 	beqz	$zero,.NB0f19d9f8
/*  f19d5e8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f19d5ec:
/*  f19d5ec:	0fc65d88 */ 	jal	0xf197620
/*  f19d5f0:	00002025 */ 	or	$a0,$zero,$zero
/*  f19d5f4:	3c048009 */ 	lui	$a0,0x8009
/*  f19d5f8:	0fc3beda */ 	jal	0xf0efb68
/*  f19d5fc:	2484b6d0 */ 	addiu	$a0,$a0,-18736
/*  f19d600:	100000fd */ 	beqz	$zero,.NB0f19d9f8
/*  f19d604:	00001025 */ 	or	$v0,$zero,$zero
/*  f19d608:	0fc65cbc */ 	jal	0xf1972f0
/*  f19d60c:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f19d610:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f19d614:	100000f7 */ 	beqz	$zero,.NB0f19d9f4
/*  f19d618:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f19d61c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f19d620:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d624:	8cca0008 */ 	lw	$t2,0x8($a2)
/*  f19d628:	8cc40004 */ 	lw	$a0,0x4($a2)
/*  f19d62c:	0fc65cc2 */ 	jal	0xf197308
/*  f19d630:	afaa0098 */ 	sw	$t2,0x98($sp)
/*  f19d634:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f19d638:	0fc65b4c */ 	jal	0xf196d30
/*  f19d63c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d640:	0fc65a84 */ 	jal	0xf196a10
/*  f19d644:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d648:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f19d64c:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f19d650:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f19d654:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f19d658:	272e000a */ 	addiu	$t6,$t9,0xa
/*  f19d65c:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f19d660:	8d4f0004 */ 	lw	$t7,0x4($t2)
/*  f19d664:	0fc5374a */ 	jal	0xf14dd28
/*  f19d668:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f19d66c:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f19d670:	0fc27fb6 */ 	jal	0xf09fed8
/*  f19d674:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f19d678:	0c002f77 */ 	jal	0xbddc
/*  f19d67c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f19d680:	0c002f7b */ 	jal	0xbdec
/*  f19d684:	a7a2003e */ 	sh	$v0,0x3e($sp)
/*  f19d688:	3c188008 */ 	lui	$t8,0x8008
/*  f19d68c:	3c198008 */ 	lui	$t9,0x8008
/*  f19d690:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19d694:	8f182370 */ 	lw	$t8,0x2370($t8)
/*  f19d698:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f19d69c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19d6a0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19d6a4:	8d4e000c */ 	lw	$t6,0xc($t2)
/*  f19d6a8:	87af003e */ 	lh	$t7,0x3e($sp)
/*  f19d6ac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19d6b0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19d6b4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19d6b8:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f19d6bc:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f19d6c0:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f19d6c4:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f19d6c8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f19d6cc:	0fc541a6 */ 	jal	0xf150698
/*  f19d6d0:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f19d6d4:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f19d6d8:	0fc537a0 */ 	jal	0xf14de80
/*  f19d6dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d6e0:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f19d6e4:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f19d6e8:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d6ec:	3c19e700 */ 	lui	$t9,0xe700
/*  f19d6f0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f19d6f4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f19d6f8:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f19d6fc:	3c18ba00 */ 	lui	$t8,0xba00
/*  f19d700:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f19d704:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f19d708:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f19d70c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f19d710:	add80000 */ 	sw	$t8,0x0($t6)
/*  f19d714:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f19d718:	3c0fb900 */ 	lui	$t7,0xb900
/*  f19d71c:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f19d720:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f19d724:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f19d728:	af200004 */ 	sw	$zero,0x4($t9)
/*  f19d72c:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f19d730:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f19d734:	3c0eba00 */ 	lui	$t6,0xba00
/*  f19d738:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f19d73c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19d740:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f19d744:	af000004 */ 	sw	$zero,0x4($t8)
/*  f19d748:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f19d74c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f19d750:	3c19ba00 */ 	lui	$t9,0xba00
/*  f19d754:	37390903 */ 	ori	$t9,$t9,0x903
/*  f19d758:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19d75c:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d760:	240e0c00 */ 	addiu	$t6,$zero,0xc00
/*  f19d764:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f19d768:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f19d76c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f19d770:	3c19ba00 */ 	lui	$t9,0xba00
/*  f19d774:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f19d778:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19d77c:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d780:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f19d784:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f19d788:	3c05800b */ 	lui	$a1,0x800b
/*  f19d78c:	8ca5fe58 */ 	lw	$a1,-0x1a8($a1)
/*  f19d790:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f19d794:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19d798:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19d79c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19d7a0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f19d7a4:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f19d7a8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19d7ac:	00003825 */ 	or	$a3,$zero,$zero
/*  f19d7b0:	afaa0098 */ 	sw	$t2,0x98($sp)
/*  f19d7b4:	0fc2c5c8 */ 	jal	0xf0b1720
/*  f19d7b8:	24a501a4 */ 	addiu	$a1,$a1,0x1a4
/*  f19d7bc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f19d7c0:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f19d7c4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f19d7c8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19d7cc:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f19d7d0:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f19d7d4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f19d7d8:	af000004 */ 	sw	$zero,0x4($t8)
/*  f19d7dc:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f19d7e0:	3c0efffc */ 	lui	$t6,0xfffc
/*  f19d7e4:	3c19fcff */ 	lui	$t9,0xfcff
/*  f19d7e8:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19d7ec:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d7f0:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f19d7f4:	35cef279 */ 	ori	$t6,$t6,0xf279
/*  f19d7f8:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f19d7fc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f19d800:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f19d804:	3c19ba00 */ 	lui	$t9,0xba00
/*  f19d808:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f19d80c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19d810:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d814:	3c1ffc12 */ 	lui	$ra,0xfc12
/*  f19d818:	3c098008 */ 	lui	$t1,0x8008
/*  f19d81c:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f19d820:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f19d824:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f19d828:	25292320 */ 	addiu	$t1,$t1,0x2320
/*  f19d82c:	37ff9a25 */ 	ori	$ra,$ra,0x9a25
/*  f19d830:	00002825 */ 	or	$a1,$zero,$zero
/*  f19d834:	00003825 */ 	or	$a3,$zero,$zero
/*  f19d838:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f19d83c:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f19d840:	240b0001 */ 	addiu	$t3,$zero,0x1
.NB0f19d844:
/*  f19d844:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f19d848:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f19d84c:	00ae082a */ 	slt	$at,$a1,$t6
/*  f19d850:	10200012 */ 	beqz	$at,.NB0f19d89c
/*  f19d854:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19d858:	50a00008 */ 	beqzl	$a1,.NB0f19d87c
/*  f19d85c:	3c088844 */ 	lui	$t0,0x8844
/*  f19d860:	50ab0009 */ 	beql	$a1,$t3,.NB0f19d888
/*  f19d864:	3c089999 */ 	lui	$t0,0x9999
/*  f19d868:	50ac000a */ 	beql	$a1,$t4,.NB0f19d894
/*  f19d86c:	3c08bb99 */ 	lui	$t0,0xbb99
/*  f19d870:	1000000d */ 	beqz	$zero,.NB0f19d8a8
/*  f19d874:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d878:	3c088844 */ 	lui	$t0,0x8844
.NB0f19d87c:
/*  f19d87c:	10000009 */ 	beqz	$zero,.NB0f19d8a4
/*  f19d880:	350800ff */ 	ori	$t0,$t0,0xff
/*  f19d884:	3c089999 */ 	lui	$t0,0x9999
.NB0f19d888:
/*  f19d888:	10000006 */ 	beqz	$zero,.NB0f19d8a4
/*  f19d88c:	35089fff */ 	ori	$t0,$t0,0x9fff
/*  f19d890:	3c08bb99 */ 	lui	$t0,0xbb99
.NB0f19d894:
/*  f19d894:	10000003 */ 	beqz	$zero,.NB0f19d8a4
/*  f19d898:	350822ff */ 	ori	$t0,$t0,0x22ff
.NB0f19d89c:
/*  f19d89c:	3c089999 */ 	lui	$t0,0x9999
/*  f19d8a0:	35089944 */ 	ori	$t0,$t0,0x9944
.NB0f19d8a4:
/*  f19d8a4:	afb8009c */ 	sw	$t8,0x9c($sp)
.NB0f19d8a8:
/*  f19d8a8:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f19d8ac:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f19d8b0:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f19d8b4:	3c0fff37 */ 	lui	$t7,0xff37
/*  f19d8b8:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f19d8bc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f19d8c0:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f19d8c4:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f19d8c8:	af3f0000 */ 	sw	$ra,0x0($t9)
/*  f19d8cc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f19d8d0:	03201825 */ 	or	$v1,$t9,$zero
/*  f19d8d4:	3c01e400 */ 	lui	$at,0xe400
/*  f19d8d8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19d8dc:	afb9009c */ 	sw	$t9,0x9c($sp)
/*  f19d8e0:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f19d8e4:	03002025 */ 	or	$a0,$t8,$zero
/*  f19d8e8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f19d8ec:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f19d8f0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f19d8f4:	25f80088 */ 	addiu	$t8,$t7,0x88
/*  f19d8f8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f19d8fc:	032e0019 */ 	multu	$t9,$t6
/*  f19d900:	00007812 */ 	mflo	$t7
/*  f19d904:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f19d908:	8d4f0004 */ 	lw	$t7,0x4($t2)
/*  f19d90c:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f19d910:	03217025 */ 	or	$t6,$t9,$at
/*  f19d914:	25f8000b */ 	addiu	$t8,$t7,0xb
/*  f19d918:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f19d91c:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f19d920:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f19d924:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f19d928:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f19d92c:	03277021 */ 	addu	$t6,$t9,$a3
/*  f19d930:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f19d934:	25cf007d */ 	addiu	$t7,$t6,0x7d
/*  f19d938:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f19d93c:	03190019 */ 	multu	$t8,$t9
/*  f19d940:	8d590004 */ 	lw	$t9,0x4($t2)
/*  f19d944:	24e7000d */ 	addiu	$a3,$a3,0xd
/*  f19d948:	00007012 */ 	mflo	$t6
/*  f19d94c:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f19d950:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f19d954:	00197080 */ 	sll	$t6,$t9,0x2
/*  f19d958:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f19d95c:	030fc825 */ 	or	$t9,$t8,$t7
/*  f19d960:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f19d964:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f19d968:	24190160 */ 	addiu	$t9,$zero,0x160
/*  f19d96c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f19d970:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f19d974:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d978:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f19d97c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f19d980:	01c03025 */ 	or	$a2,$t6,$zero
/*  f19d984:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f19d988:	3c0fb300 */ 	lui	$t7,0xb300
/*  f19d98c:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f19d990:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f19d994:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f19d998:	01c01025 */ 	or	$v0,$t6,$zero
/*  f19d99c:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f19d9a0:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f19d9a4:	01d9001a */ 	div	$zero,$t6,$t9
/*  f19d9a8:	17200002 */ 	bnez	$t9,.NB0f19d9b4
/*  f19d9ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d9b0:	0007000d */ 	break	0x7
.NB0f19d9b4:
/*  f19d9b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19d9b8:	17210004 */ 	bne	$t9,$at,.NB0f19d9cc
/*  f19d9bc:	3c018000 */ 	lui	$at,0x8000
/*  f19d9c0:	15c10002 */ 	bne	$t6,$at,.NB0f19d9cc
/*  f19d9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d9c8:	0006000d */ 	break	0x6
.NB0f19d9cc:
/*  f19d9cc:	0000c012 */ 	mflo	$t8
/*  f19d9d0:	330fffff */ 	andi	$t7,$t8,0xffff
/*  f19d9d4:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f19d9d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f19d9dc:	35d9fc00 */ 	ori	$t9,$t6,0xfc00
/*  f19d9e0:	14a1ff98 */ 	bne	$a1,$at,.NB0f19d844
/*  f19d9e4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f19d9e8:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f19d9ec:	10000002 */ 	beqz	$zero,.NB0f19d9f8
/*  f19d9f0:	8fa2009c */ 	lw	$v0,0x9c($sp)
.NB0f19d9f4:
/*  f19d9f4:	00001025 */ 	or	$v0,$zero,$zero
.NB0f19d9f8:
/*  f19d9f8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f19d9fc:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f19da00:	03e00008 */ 	jr	$ra
/*  f19da04:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

s32 frTrainingInfoMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	u32 stack;
	s32 weaponnum;

	switch (operation) {
	case MENUOP_OPEN:
		weaponnum = frGetWeaponBySlot(frGetSlot());
		g_Menus[g_MpPlayerNum].data.train.weaponnum = weaponnum;
		func0f105948(weaponnum);

		if (!frIsInTraining()) {
			frInitAmmo(weaponnum);
		}
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curframe && g_Menus[g_MpPlayerNum].curframe->dialog == dialog) {
			g_Menus[g_MpPlayerNum].unkdb4 -= g_Vars.diffframe60;
			g_Menus[g_MpPlayerNum].unkd8c = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unkd64 = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unkd68 = 0;
			g_Menus[g_MpPlayerNum].unkd90 = 0;
		}
		break;
	case MENUOP_CLOSE:
		if (!frIsInTraining()) {
			frEndSession(true);
		}
		break;
	}

	return 0;
}

s32 frTrainingStatsMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		if (frIsInTraining() == false) {
			frEndSession(true);
		}
	}

	return 0;
}

/**
 * This is an unused menu handler which implements the difficulty selection
 * using a dropdown.
 */
s32 frDifficultyDropdownMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 names[] = {
		L_MPMENU_439, // "Bronze"
		L_MPMENU_440, // "Silver"
		L_MPMENU_441, // "Gold"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = ciGetFiringRangeScore(frGetSlot()) + 1;

		if (data->dropdown.value > 3) {
			data->dropdown.value = 3;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(names[data->dropdown.value]);
	case MENUOP_SET:
		frSetDifficulty(data->dropdown.value);
		menuPushDialog(&g_FrTrainingInfoPreGameMenuDialog);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = frGetDifficulty();
		break;
	}

	return 0;
}

s32 frDifficultyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if (ciGetFiringRangeScore(frGetWeaponIndexByWeapon(frGetWeaponBySlot(frGetSlot()))) < item->param) {
			return true;
		}
		break;
	case MENUOP_SET:
		frSetDifficulty(item->param);
		menuPushDialog(&g_FrTrainingInfoPreGameMenuDialog);
		break;
	case MENUOP_CHECKPREFOCUSED:
		if (ciGetFiringRangeScore(frGetWeaponIndexByWeapon(frGetWeaponBySlot(frGetSlot()))) >= item->param) {
			return true;
		}
		break;
	}

	return 0;
}

char *frPrimaryFunctionMenuText(struct menuitem *item)
{
	struct weaponfunc *func = weaponGetFunctionById(frGetWeaponBySlot(frGetSlot()), FUNC_PRIMARY);

	if (func) {
		return langGet(func->name);
	}

	return "\n";
}

char *frSecondaryFunctionMenuText(struct menuitem *item)
{
	struct weaponfunc *func = weaponGetFunctionById(frGetWeaponBySlot(frGetSlot()), FUNC_SECONDARY);

	if (func) {
		return langGet(func->name);
	}

	return "\n";
}

char *frMenuTextFailReason(struct menuitem *item)
{
	u16 reasons[] = {
		L_MPMENU_456, // "Not Failed"
		L_MPMENU_457, // "Out of Ammo"
		L_MPMENU_458, // "Time Over"
		L_MPMENU_459, // "Score Unattainable"
		L_MPMENU_460, // "Too Inaccurate"
	};

	struct frdata *frdata = frGetData();

	return langGet(reasons[frdata->failreason]);
}

char *frMenuTextDifficultyName(struct menuitem *item)
{
	u16 names[] = {
		L_MPMENU_439, // "Bronze"
		L_MPMENU_440, // "Silver"
		L_MPMENU_441, // "Gold"
	};

	struct frdata *frdata = frGetData();

	return langGet(names[frdata->difficulty]);
}

char *frMenuTextTimeTakenValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	f32 secs = frdata->timetaken / (PAL ? 50.0f : 60.0f);

	if (secs > frdata->timelimit) {
		secs = frdata->timelimit;
	}

	if (secs >= 60.0f) {
		s32 mins = 0;

		while (secs >= 60.0f) {
			secs -= 60.0f;
			mins++;
		}

		sprintf(g_StringPointer, "%dm %2ds\n", mins, (s32)ceilf(secs));
		return g_StringPointer;
	} else {
		sprintf(g_StringPointer, "%s%s%2.2fs\n", "", "", secs);
	}

	return g_StringPointer;
}

char *frMenuTextScoreValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	sprintf(g_StringPointer, "%d\n", frdata->score);
	return g_StringPointer;
}

char *frMenuTextGoalScoreValueUnconditional(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	sprintf(g_StringPointer, "%d\n", frdata->goalscore);
	return g_StringPointer;
}

char *frMenuTextWeaponName(struct menuitem *item)
{
	return weaponGetName(frGetWeaponBySlot(frGetSlot()));
}

char *frMenuTextTargetsDestroyedValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	sprintf(g_StringPointer, "%d\n", frdata->targetsdestroyed);
	return g_StringPointer;
}

char *frMenuTextAccuracyValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	f32 totalhits = (frdata->numhitsring3 + frdata->numhitsbullseye + frdata->numhitsring1 + frdata->numhitsring2) * 100.0f;
	f32 accuracy = 0;

	if (frdata->numshots) {
		accuracy = totalhits / frdata->numshots;
	}

	if (accuracy > 100.0f) {
		accuracy = 100.0f;
	}

	sprintf(g_StringPointer, "%s%s%.1f%%\n", "", "", accuracy);
	return g_StringPointer;
}

char *frMenuTextGoalScoreLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalscore > 0) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_475)); // "Goal Score:"
		return g_StringPointer;
	}

	return NULL;
}

char *frMenuTextGoalScoreValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalscore > 0) {
		sprintf(g_StringPointer2, "%d\n", frdata->goalscore);
		return g_StringPointer2;
	}

	return NULL;
}

char *frMenuTextMinAccuracyOrTargetsLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalaccuracy > 0) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_473)); // "Min Accuracy:"
	} else if (frdata->goaltargets != 255) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_474)); // "Goal Targets:"
	} else {
		return NULL;
	}

	return g_StringPointer;
}

char *frMenuTextMinAccuracyOrTargetsValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->goalaccuracy > 0) {
		sprintf(g_StringPointer2, "%d%%\n", frdata->goalaccuracy);
	} else if (frdata->goaltargets != 255) {
		sprintf(g_StringPointer2, "%d\n", frdata->goaltargets);
	} else {
		return NULL;
	}

	return g_StringPointer2;
}

char *frMenuTextTimeLimitLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->timelimit != 255) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_472)); // "Time Limit:"
	} else {
		return NULL;
	}

	return g_StringPointer;
}

char *frMenuTextTimeLimitValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->timelimit != 255) {
		s32 secs = frdata->timelimit;
		s32 mins = 0;

		while (secs >= 60) {
			secs -= 60;
			mins++;
		}

		if (mins > 0) {
			sprintf(g_StringPointer2, "%dm %ds\n", mins, secs);
		} else {
			sprintf(g_StringPointer2, "%ds\n", secs);
		}
	} else {
		return NULL;
	}

	return g_StringPointer2;
}

char *frMenuTextAmmoLimitLabel(struct menuitem *item)
{
	struct frdata *frdata = frGetData();

	if (frdata->ammolimit != 255) {
		sprintf(g_StringPointer, "%s", langGet(L_MPMENU_471)); // "Ammo Limit:"
	} else {
		return NULL;
	}

	return g_StringPointer;
}

char *frMenuTextAmmoLimitValue(struct menuitem *item)
{
	struct frdata *frdata = frGetData();
	char suffix[16];
	s32 weaponnum;

	if (frdata->ammolimit != 255) {
		weaponnum = frGetWeaponBySlot(frdata->slot);

		if (weaponnum == WEAPON_SUPERDRAGON && frdata->sdgrenadelimit != 255) {
			sprintf(suffix, "/%d", frdata->sdgrenadelimit);
		} else {
			suffix[0] = '\0';
		}

		sprintf(g_StringPointer2, "%d%s\n", frdata->ammolimit, suffix);
	} else {
		return NULL;
	}

	return g_StringPointer2;
}

u32 var80088c8c = 0;
u32 var80088c90 = 0;
u32 var80088c94 = 0;
u32 var80088c98 = 0;
u32 var80088c9c = 0;
u32 var80088ca0 = 0;
u32 var80088ca4 = 0;
u32 var80088ca8 = 0;

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuhandler001a44c0
/*  f1a44c0:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f1a44c4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1a44c8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1a44cc:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1a44d0:	1481061c */ 	bne	$a0,$at,.L0f1a5d44
/*  f1a44d4:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f1a44d8:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a44dc:	3c0f800b */ 	lui	$t7,%hi(var800ab5a8)
/*  f1a44e0:	8defb5a8 */ 	lw	$t7,%lo(var800ab5a8)($t7)
/*  f1a44e4:	afae015c */ 	sw	$t6,0x15c($sp)
/*  f1a44e8:	8cd00008 */ 	lw	$s0,0x8($a2)
/*  f1a44ec:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f1a44f0:	0fc675f3 */ 	jal	frGetData
/*  f1a44f4:	afb80144 */ 	sw	$t8,0x144($sp)
/*  f1a44f8:	afa20140 */ 	sw	$v0,0x140($sp)
/*  f1a44fc:	90430465 */ 	lbu	$v1,0x465($v0)
/*  f1a4500:	0003c942 */ 	srl	$t9,$v1,0x5
/*  f1a4504:	3b2c0002 */ 	xori	$t4,$t9,0x2
/*  f1a4508:	2d830001 */ 	sltiu	$v1,$t4,0x1
/*  f1a450c:	10600003 */ 	beqz	$v1,.L0f1a451c
/*  f1a4510:	3c06ff00 */ 	lui	$a2,0xff00
/*  f1a4514:	10000004 */ 	b	.L0f1a4528
/*  f1a4518:	34c60077 */ 	ori	$a2,$a2,0x77
.L0f1a451c:
/*  f1a451c:	3c0d00ff */ 	lui	$t5,0xff
/*  f1a4520:	35a60077 */ 	ori	$a2,$t5,0x77
/*  f1a4524:	afa600b8 */ 	sw	$a2,0xb8($sp)
.L0f1a4528:
/*  f1a4528:	50600004 */ 	beqzl	$v1,.L0f1a453c
/*  f1a452c:	3c0e00ff */ 	lui	$t6,0xff
/*  f1a4530:	10000004 */ 	b	.L0f1a4544
/*  f1a4534:	3c09ff00 */ 	lui	$t1,0xff00
/*  f1a4538:	3c0e00ff */ 	lui	$t6,0xff
.L0f1a453c:
/*  f1a453c:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f1a4540:	3c0900ff */ 	lui	$t1,0xff
.L0f1a4544:
/*  f1a4544:	10600003 */ 	beqz	$v1,.L0f1a4554
/*  f1a4548:	3c08ff00 */ 	lui	$t0,0xff00
/*  f1a454c:	10000004 */ 	b	.L0f1a4560
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
/*  f1a4584:	3c047f1c */ 	lui	$a0,%hi(var7f1b985c)
/*  f1a4588:	3c058009 */ 	lui	$a1,%hi(var80088c8c)
/*  f1a458c:	24a58c8c */ 	addiu	$a1,$a1,%lo(var80088c8c)
/*  f1a4590:	2484985c */ 	addiu	$a0,$a0,%lo(var7f1b985c)
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
/*  f1a45dc:	3c047f1c */ 	lui	$a0,%hi(var7f1b9860)
/*  f1a45e0:	3c058009 */ 	lui	$a1,%hi(var80088c90)
/*  f1a45e4:	24a58c90 */ 	addiu	$a1,$a1,%lo(var80088c90)
/*  f1a45e8:	0c0036cc */ 	jal	func0000db30
/*  f1a45ec:	24849860 */ 	addiu	$a0,$a0,%lo(var7f1b9860)
/*  f1a45f0:	3c047f1c */ 	lui	$a0,%hi(var7f1b9864)
/*  f1a45f4:	3c058009 */ 	lui	$a1,%hi(var80088c94)
/*  f1a45f8:	24a58c94 */ 	addiu	$a1,$a1,%lo(var80088c94)
/*  f1a45fc:	0c0036cc */ 	jal	func0000db30
/*  f1a4600:	24849864 */ 	addiu	$a0,$a0,%lo(var7f1b9864)
/*  f1a4604:	3c047f1c */ 	lui	$a0,%hi(var7f1b9868)
/*  f1a4608:	3c058009 */ 	lui	$a1,%hi(var80088c98)
/*  f1a460c:	24a58c98 */ 	addiu	$a1,$a1,%lo(var80088c98)
/*  f1a4610:	0c0036cc */ 	jal	func0000db30
/*  f1a4614:	24849868 */ 	addiu	$a0,$a0,%lo(var7f1b9868)
/*  f1a4618:	3c047f1c */ 	lui	$a0,%hi(var7f1b986c)
/*  f1a461c:	3c058009 */ 	lui	$a1,%hi(var80088c9c)
/*  f1a4620:	24a58c9c */ 	addiu	$a1,$a1,%lo(var80088c9c)
/*  f1a4624:	0c0036cc */ 	jal	func0000db30
/*  f1a4628:	2484986c */ 	addiu	$a0,$a0,%lo(var7f1b986c)
/*  f1a462c:	3c047f1c */ 	lui	$a0,%hi(var7f1b9870)
/*  f1a4630:	3c058009 */ 	lui	$a1,%hi(var80088ca0)
/*  f1a4634:	24a58ca0 */ 	addiu	$a1,$a1,%lo(var80088ca0)
/*  f1a4638:	0c0036cc */ 	jal	func0000db30
/*  f1a463c:	24849870 */ 	addiu	$a0,$a0,%lo(var7f1b9870)
/*  f1a4640:	3c047f1c */ 	lui	$a0,%hi(var7f1b9874)
/*  f1a4644:	3c058009 */ 	lui	$a1,%hi(var80088ca4)
/*  f1a4648:	24a58ca4 */ 	addiu	$a1,$a1,%lo(var80088ca4)
/*  f1a464c:	0c0036cc */ 	jal	func0000db30
/*  f1a4650:	24849874 */ 	addiu	$a0,$a0,%lo(var7f1b9874)
/*  f1a4654:	3c047f1c */ 	lui	$a0,%hi(var7f1b9878)
/*  f1a4658:	3c058009 */ 	lui	$a1,%hi(var80088ca8)
/*  f1a465c:	24a58ca8 */ 	addiu	$a1,$a1,%lo(var80088ca8)
/*  f1a4660:	0c0036cc */ 	jal	func0000db30
/*  f1a4664:	24849878 */ 	addiu	$a0,$a0,%lo(var7f1b9878)
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
/*  f1a47a0:	10000003 */ 	b	.L0f1a47b0
/*  f1a47a4:	34e77799 */ 	ori	$a3,$a3,0x7799
.L0f1a47a8:
/*  f1a47a8:	3c0755ff */ 	lui	$a3,0x55ff
/*  f1a47ac:	34e75588 */ 	ori	$a3,$a3,0x5588
.L0f1a47b0:
/*  f1a47b0:	11400003 */ 	beqz	$t2,.L0f1a47c0
/*  f1a47b4:	3c03ff77 */ 	lui	$v1,0xff77
/*  f1a47b8:	10000003 */ 	b	.L0f1a47c8
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
/*  f1a47f4:	3c028008 */ 	lui	$v0,%hi(g_ScaleX)
/*  f1a47f8:	2442fac0 */ 	addiu	$v0,$v0,%lo(g_ScaleX)
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
/*  f1a4918:	00000000 */ 	nop
/*  f1a491c:	0007000d */ 	break	0x7
.L0f1a4920:
/*  f1a4920:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4924:	17010004 */ 	bne	$t8,$at,.L0f1a4938
/*  f1a4928:	3c018000 */ 	lui	$at,0x8000
/*  f1a492c:	17210002 */ 	bne	$t9,$at,.L0f1a4938
/*  f1a4930:	00000000 */ 	nop
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
/*  f1a4a0c:	00000000 */ 	nop
/*  f1a4a10:	0007000d */ 	break	0x7
.L0f1a4a14:
/*  f1a4a14:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4a18:	17010004 */ 	bne	$t8,$at,.L0f1a4a2c
/*  f1a4a1c:	3c018000 */ 	lui	$at,0x8000
/*  f1a4a20:	15610002 */ 	bne	$t3,$at,.L0f1a4a2c
/*  f1a4a24:	00000000 */ 	nop
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
/*  f1a4af4:	00000000 */ 	nop
/*  f1a4af8:	0007000d */ 	break	0x7
.L0f1a4afc:
/*  f1a4afc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4b00:	17010004 */ 	bne	$t8,$at,.L0f1a4b14
/*  f1a4b04:	3c018000 */ 	lui	$at,0x8000
/*  f1a4b08:	15c10002 */ 	bne	$t6,$at,.L0f1a4b14
/*  f1a4b0c:	00000000 */ 	nop
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
/*  f1a4be0:	00000000 */ 	nop
/*  f1a4be4:	0007000d */ 	break	0x7
.L0f1a4be8:
/*  f1a4be8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a4bec:	17010004 */ 	bne	$t8,$at,.L0f1a4c00
/*  f1a4bf0:	3c018000 */ 	lui	$at,0x8000
/*  f1a4bf4:	15610002 */ 	bne	$t3,$at,.L0f1a4c00
/*  f1a4bf8:	00000000 */ 	nop
/*  f1a4bfc:	0006000d */ 	break	0x6
.L0f1a4c00:
/*  f1a4c00:	35cc0400 */ 	ori	$t4,$t6,0x400
/*  f1a4c04:	10c00004 */ 	beqz	$a2,.L0f1a4c18
/*  f1a4c08:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f1a4c0c:	3c07ff00 */ 	lui	$a3,0xff00
/*  f1a4c10:	10000003 */ 	b	.L0f1a4c20
/*  f1a4c14:	34e70055 */ 	ori	$a3,$a3,0x55
.L0f1a4c18:
/*  f1a4c18:	3c0700ff */ 	lui	$a3,0xff
/*  f1a4c1c:	34e70055 */ 	ori	$a3,$a3,0x55
.L0f1a4c20:
/*  f1a4c20:	10c00003 */ 	beqz	$a2,.L0f1a4c30
/*  f1a4c24:	3c03ff00 */ 	lui	$v1,0xff00
/*  f1a4c28:	10000003 */ 	b	.L0f1a4c38
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
/*  f1a4c5c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f1a4c60:	01cc2825 */ 	or	$a1,$t6,$t4
/*  f1a4c64:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*  f1a4c68:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4c6c:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f1a4c70:	13000004 */ 	beqz	$t8,.L0f1a4c84
/*  f1a4c74:	3c07ff69 */ 	lui	$a3,0xff69
/*  f1a4c78:	34e769aa */ 	ori	$a3,$a3,0x69aa
/*  f1a4c7c:	10000003 */ 	b	.L0f1a4c8c
/*  f1a4c80:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f1a4c84:
/*  f1a4c84:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f1a4c88:	00403825 */ 	or	$a3,$v0,$zero
.L0f1a4c8c:
/*  f1a4c8c:	11e00004 */ 	beqz	$t7,.L0f1a4ca0
/*  f1a4c90:	305900ff */ 	andi	$t9,$v0,0xff
/*  f1a4c94:	3c03ff69 */ 	lui	$v1,0xff69
/*  f1a4c98:	10000002 */ 	b	.L0f1a4ca4
/*  f1a4c9c:	346369aa */ 	ori	$v1,$v1,0x69aa
.L0f1a4ca0:
/*  f1a4ca0:	00401825 */ 	or	$v1,$v0,$zero
.L0f1a4ca4:
/*  f1a4ca4:	306d00ff */ 	andi	$t5,$v1,0xff
/*  f1a4ca8:	01b90019 */ 	multu	$t5,$t9
/*  f1a4cac:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a4cb0:	00e1c024 */ 	and	$t8,$a3,$at
/*  f1a4cb4:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f1a4cb8:	3c057f1c */ 	lui	$a1,%hi(var7f1b987c)
/*  f1a4cbc:	24a5987c */ 	addiu	$a1,$a1,%lo(var7f1b987c)
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
/*  f1a4d10:	0c002f02 */ 	jal	viGetWidth
/*  f1a4d14:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4d18:	0c002f06 */ 	jal	viGetHeight
/*  f1a4d1c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4d20:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm1)
/*  f1a4d24:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm2)
/*  f1a4d28:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm2)($t9)
/*  f1a4d2c:	8dadfb10 */ 	lw	$t5,%lo(g_FontHandelGothicSm1)($t5)
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
/*  f1a4d60:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a4db4:	0c002f02 */ 	jal	viGetWidth
/*  f1a4db8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4dbc:	0c002f06 */ 	jal	viGetHeight
/*  f1a4dc0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4dc4:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm1)
/*  f1a4dc8:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm2)
/*  f1a4dcc:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm2)($t8)
/*  f1a4dd0:	8d8cfb10 */ 	lw	$t4,%lo(g_FontHandelGothicSm1)($t4)
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
/*  f1a4e04:	0fc5580f */ 	jal	textRenderProjected
/*  f1a4e08:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a4e0c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f1a4e10:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4e14:	3c057f1c */ 	lui	$a1,%hi(var7f1b9880)
/*  f1a4e18:	9726045c */ 	lhu	$a2,0x45c($t9)
/*  f1a4e1c:	24a59880 */ 	addiu	$a1,$a1,%lo(var7f1b9880)
/*  f1a4e20:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a4e24:	00067080 */ 	sll	$t6,$a2,0x2
/*  f1a4e28:	01c67021 */ 	addu	$t6,$t6,$a2
/*  f1a4e2c:	0c004dad */ 	jal	sprintf
/*  f1a4e30:	000e3040 */ 	sll	$a2,$t6,0x1
/*  f1a4e34:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f1a4e38:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f1a4e3c:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f1a4e40:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f1a4e44:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a4e48:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a4e4c:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a4e50:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a4e54:	0fc55cbe */ 	jal	textMeasure
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
/*  f1a4e98:	0c002f02 */ 	jal	viGetWidth
/*  f1a4e9c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4ea0:	0c002f06 */ 	jal	viGetHeight
/*  f1a4ea4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4ea8:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm1)
/*  f1a4eac:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm2)
/*  f1a4eb0:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm2)($t5)
/*  f1a4eb4:	8deffb10 */ 	lw	$t7,%lo(g_FontHandelGothicSm1)($t7)
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
/*  f1a4ee8:	0fc5580f */ 	jal	textRenderProjected
/*  f1a4eec:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a4ef0:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1a4ef4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4ef8:	3c057f1c */ 	lui	$a1,%hi(var7f1b9884)
/*  f1a4efc:	24a59884 */ 	addiu	$a1,$a1,%lo(var7f1b9884)
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
/*  f1a4f40:	0c002f02 */ 	jal	viGetWidth
/*  f1a4f44:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4f48:	0c002f06 */ 	jal	viGetHeight
/*  f1a4f4c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4f50:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm1)
/*  f1a4f54:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm2)
/*  f1a4f58:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm2)($t8)
/*  f1a4f5c:	8d8cfb10 */ 	lw	$t4,%lo(g_FontHandelGothicSm1)($t4)
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
/*  f1a4f90:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a4fe4:	0c002f02 */ 	jal	viGetWidth
/*  f1a4fe8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a4fec:	0c002f06 */ 	jal	viGetHeight
/*  f1a4ff0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a4ff4:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm1)
/*  f1a4ff8:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm2)
/*  f1a4ffc:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm2)($t9)
/*  f1a5000:	8dadfb10 */ 	lw	$t5,%lo(g_FontHandelGothicSm1)($t5)
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
/*  f1a5034:	0fc5580f */ 	jal	textRenderProjected
/*  f1a5038:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1a503c:	8fb80140 */ 	lw	$t8,0x140($sp)
/*  f1a5040:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5044:	3c057f1c */ 	lui	$a1,%hi(var7f1b9888)
/*  f1a5048:	9706045e */ 	lhu	$a2,0x45e($t8)
/*  f1a504c:	24a59888 */ 	addiu	$a1,$a1,%lo(var7f1b9888)
/*  f1a5050:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5054:	00067880 */ 	sll	$t7,$a2,0x2
/*  f1a5058:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f1a505c:	0c004dad */ 	jal	sprintf
/*  f1a5060:	01e03025 */ 	or	$a2,$t7,$zero
/*  f1a5064:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm2)
/*  f1a5068:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm2)($t5)
/*  f1a506c:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f1a5070:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f1a5074:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a5078:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a507c:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a5080:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a5084:	0fc55cbe */ 	jal	textMeasure
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
/*  f1a50c8:	0c002f02 */ 	jal	viGetWidth
/*  f1a50cc:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a50d0:	0c002f06 */ 	jal	viGetHeight
/*  f1a50d4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a50d8:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicSm1)
/*  f1a50dc:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f1a50e0:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f1a50e4:	8dcefb10 */ 	lw	$t6,%lo(g_FontHandelGothicSm1)($t6)
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
/*  f1a5118:	0fc5580f */ 	jal	textRenderProjected
/*  f1a511c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1a5120:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f1a5124:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5128:	3c057f1c */ 	lui	$a1,%hi(var7f1b988c)
/*  f1a512c:	24a5988c */ 	addiu	$a1,$a1,%lo(var7f1b988c)
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
/*  f1a5170:	0c002f02 */ 	jal	viGetWidth
/*  f1a5174:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5178:	0c002f06 */ 	jal	viGetHeight
/*  f1a517c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5180:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm1)
/*  f1a5184:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm2)
/*  f1a5188:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm2)($t9)
/*  f1a518c:	8dadfb10 */ 	lw	$t5,%lo(g_FontHandelGothicSm1)($t5)
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
/*  f1a51c0:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a5214:	0c002f02 */ 	jal	viGetWidth
/*  f1a5218:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a521c:	0c002f06 */ 	jal	viGetHeight
/*  f1a5220:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5224:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm1)
/*  f1a5228:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm2)
/*  f1a522c:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm2)($t8)
/*  f1a5230:	8d8cfb10 */ 	lw	$t4,%lo(g_FontHandelGothicSm1)($t4)
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
/*  f1a5264:	0fc5580f */ 	jal	textRenderProjected
/*  f1a5268:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a526c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f1a5270:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5274:	3c057f1c */ 	lui	$a1,%hi(var7f1b9890)
/*  f1a5278:	97260460 */ 	lhu	$a2,0x460($t9)
/*  f1a527c:	24a59890 */ 	addiu	$a1,$a1,%lo(var7f1b9890)
/*  f1a5280:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5284:	00067040 */ 	sll	$t6,$a2,0x1
/*  f1a5288:	0c004dad */ 	jal	sprintf
/*  f1a528c:	01c03025 */ 	or	$a2,$t6,$zero
/*  f1a5290:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f1a5294:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f1a5298:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f1a529c:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f1a52a0:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a52a4:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a52a8:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a52ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a52b0:	0fc55cbe */ 	jal	textMeasure
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
/*  f1a52f4:	0c002f02 */ 	jal	viGetWidth
/*  f1a52f8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a52fc:	0c002f06 */ 	jal	viGetHeight
/*  f1a5300:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5304:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm1)
/*  f1a5308:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm2)
/*  f1a530c:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm2)($t5)
/*  f1a5310:	8deffb10 */ 	lw	$t7,%lo(g_FontHandelGothicSm1)($t7)
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
/*  f1a5344:	0fc5580f */ 	jal	textRenderProjected
/*  f1a5348:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a534c:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1a5350:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5354:	3c057f1c */ 	lui	$a1,%hi(var7f1b9894)
/*  f1a5358:	24a59894 */ 	addiu	$a1,$a1,%lo(var7f1b9894)
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
/*  f1a539c:	0c002f02 */ 	jal	viGetWidth
/*  f1a53a0:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a53a4:	0c002f06 */ 	jal	viGetHeight
/*  f1a53a8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a53ac:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm1)
/*  f1a53b0:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm2)
/*  f1a53b4:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm2)($t8)
/*  f1a53b8:	8d8cfb10 */ 	lw	$t4,%lo(g_FontHandelGothicSm1)($t4)
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
/*  f1a53ec:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a5448:	0c002f02 */ 	jal	viGetWidth
/*  f1a544c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5450:	0c002f06 */ 	jal	viGetHeight
/*  f1a5454:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5458:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm1)
/*  f1a545c:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicSm2)
/*  f1a5460:	8dcefb0c */ 	lw	$t6,%lo(g_FontHandelGothicSm2)($t6)
/*  f1a5464:	8f39fb10 */ 	lw	$t9,%lo(g_FontHandelGothicSm1)($t9)
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
/*  f1a5498:	0fc5580f */ 	jal	textRenderProjected
/*  f1a549c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1a54a0:	8faf0140 */ 	lw	$t7,0x140($sp)
/*  f1a54a4:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a54a8:	3c057f1c */ 	lui	$a1,%hi(var7f1b9898)
/*  f1a54ac:	24a59898 */ 	addiu	$a1,$a1,%lo(var7f1b9898)
/*  f1a54b0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a54b4:	0c004dad */ 	jal	sprintf
/*  f1a54b8:	95e60462 */ 	lhu	$a2,0x462($t7)
/*  f1a54bc:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm2)
/*  f1a54c0:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm2)($t5)
/*  f1a54c4:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f1a54c8:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f1a54cc:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a54d0:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a54d4:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a54d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a54dc:	0fc55cbe */ 	jal	textMeasure
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
/*  f1a5520:	0c002f02 */ 	jal	viGetWidth
/*  f1a5524:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5528:	0c002f06 */ 	jal	viGetHeight
/*  f1a552c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5530:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicSm1)
/*  f1a5534:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f1a5538:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f1a553c:	8dcefb10 */ 	lw	$t6,%lo(g_FontHandelGothicSm1)($t6)
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
/*  f1a5570:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a55c4:	0c002f02 */ 	jal	viGetWidth
/*  f1a55c8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a55cc:	0c002f06 */ 	jal	viGetHeight
/*  f1a55d0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a55d4:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm1)
/*  f1a55d8:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm2)
/*  f1a55dc:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm2)($t5)
/*  f1a55e0:	8deffb10 */ 	lw	$t7,%lo(g_FontHandelGothicSm1)($t7)
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
/*  f1a5614:	0fc5580f */ 	jal	textRenderProjected
/*  f1a5618:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a561c:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f1a5620:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5624:	3c057f1c */ 	lui	$a1,%hi(var7f1b989c)
/*  f1a5628:	958f045c */ 	lhu	$t7,0x45c($t4)
/*  f1a562c:	95980462 */ 	lhu	$t8,0x462($t4)
/*  f1a5630:	9599045e */ 	lhu	$t9,0x45e($t4)
/*  f1a5634:	24a5989c */ 	addiu	$a1,$a1,%lo(var7f1b989c)
/*  f1a5638:	030f6821 */ 	addu	$t5,$t8,$t7
/*  f1a563c:	95980460 */ 	lhu	$t8,0x460($t4)
/*  f1a5640:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f1a5644:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1a5648:	0c004dad */ 	jal	sprintf
/*  f1a564c:	01d83021 */ 	addu	$a2,$t6,$t8
/*  f1a5650:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm2)
/*  f1a5654:	8deffb0c */ 	lw	$t7,%lo(g_FontHandelGothicSm2)($t7)
/*  f1a5658:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f1a565c:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f1a5660:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f1a5664:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f1a5668:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f1a566c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a5670:	0fc55cbe */ 	jal	textMeasure
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
/*  f1a56b4:	0c002f02 */ 	jal	viGetWidth
/*  f1a56b8:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a56bc:	0c002f06 */ 	jal	viGetHeight
/*  f1a56c0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a56c4:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm1)
/*  f1a56c8:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f1a56cc:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f1a56d0:	8f39fb10 */ 	lw	$t9,%lo(g_FontHandelGothicSm1)($t9)
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
/*  f1a5704:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a5758:	0c002f02 */ 	jal	viGetWidth
/*  f1a575c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5760:	0c002f06 */ 	jal	viGetHeight
/*  f1a5764:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5768:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm1)
/*  f1a576c:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm2)
/*  f1a5770:	8deffb0c */ 	lw	$t7,%lo(g_FontHandelGothicSm2)($t7)
/*  f1a5774:	8f18fb10 */ 	lw	$t8,%lo(g_FontHandelGothicSm1)($t8)
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
/*  f1a57a8:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a57fc:	0c002f02 */ 	jal	viGetWidth
/*  f1a5800:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5804:	0c002f06 */ 	jal	viGetHeight
/*  f1a5808:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a580c:	3c198008 */ 	lui	$t9,%hi(g_FontNumeric1)
/*  f1a5810:	3c0c8008 */ 	lui	$t4,%hi(g_FontNumeric2)
/*  f1a5814:	8d8cfafc */ 	lw	$t4,%lo(g_FontNumeric2)($t4)
/*  f1a5818:	8f39fb00 */ 	lw	$t9,%lo(g_FontNumeric1)($t9)
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
/*  f1a5864:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a58b8:	0c002f02 */ 	jal	viGetWidth
/*  f1a58bc:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a58c0:	0c002f06 */ 	jal	viGetHeight
/*  f1a58c4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a58c8:	3c0c8008 */ 	lui	$t4,%hi(g_FontNumeric1)
/*  f1a58cc:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f1a58d0:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f1a58d4:	8d8cfb00 */ 	lw	$t4,%lo(g_FontNumeric1)($t4)
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
/*  f1a5920:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a5974:	0c002f02 */ 	jal	viGetWidth
/*  f1a5978:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a597c:	0c002f06 */ 	jal	viGetHeight
/*  f1a5980:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5984:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric1)
/*  f1a5988:	3c188008 */ 	lui	$t8,%hi(g_FontNumeric2)
/*  f1a598c:	8f18fafc */ 	lw	$t8,%lo(g_FontNumeric2)($t8)
/*  f1a5990:	8dcefb00 */ 	lw	$t6,%lo(g_FontNumeric1)($t6)
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
/*  f1a59dc:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a5a30:	0c002f02 */ 	jal	viGetWidth
/*  f1a5a34:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f1a5a38:	0c002f06 */ 	jal	viGetHeight
/*  f1a5a3c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a5a40:	3c188008 */ 	lui	$t8,%hi(g_FontNumeric1)
/*  f1a5a44:	3c0f8008 */ 	lui	$t7,%hi(g_FontNumeric2)
/*  f1a5a48:	8deffafc */ 	lw	$t7,%lo(g_FontNumeric2)($t7)
/*  f1a5a4c:	8f18fb00 */ 	lw	$t8,%lo(g_FontNumeric1)($t8)
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
/*  f1a5a98:	0fc5580f */ 	jal	textRenderProjected
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
/*  f1a5adc:	0fc38bd7 */ 	jal	renderFilledRect
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
/*  f1a5d3c:	10000003 */ 	b	.L0f1a5d4c
/*  f1a5d40:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a5d44:
/*  f1a5d44:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a5d48:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a5d4c:
/*  f1a5d4c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1a5d50:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*  f1a5d54:	03e00008 */ 	jr	$ra
/*  f1a5d58:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel menuhandler001a44c0
/*  f19e518:	27bdfea8 */ 	addiu	$sp,$sp,-344
/*  f19e51c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19e520:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19e524:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f19e528:	14810626 */ 	bne	$a0,$at,.NB0f19fdc4
/*  f19e52c:	afa5015c */ 	sw	$a1,0x15c($sp)
/*  f19e530:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f19e534:	3c0f800b */ 	lui	$t7,0x800b
/*  f19e538:	8deffe58 */ 	lw	$t7,-0x1a8($t7)
/*  f19e53c:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f19e540:	8cd00008 */ 	lw	$s0,0x8($a2)
/*  f19e544:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f19e548:	0fc65e01 */ 	jal	0xf197804
/*  f19e54c:	afb8013c */ 	sw	$t8,0x13c($sp)
/*  f19e550:	afa20138 */ 	sw	$v0,0x138($sp)
/*  f19e554:	90430465 */ 	lbu	$v1,0x465($v0)
/*  f19e558:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e55c:	24843e7c */ 	addiu	$a0,$a0,0x3e7c
/*  f19e560:	0003c942 */ 	srl	$t9,$v1,0x5
/*  f19e564:	3b2d0002 */ 	xori	$t5,$t9,0x2
/*  f19e568:	2da30001 */ 	sltiu	$v1,$t5,0x1
/*  f19e56c:	10600005 */ 	beqz	$v1,.NB0f19e584
/*  f19e570:	3c058009 */ 	lui	$a1,0x8009
/*  f19e574:	3c0eff00 */ 	lui	$t6,0xff00
/*  f19e578:	35ce0077 */ 	ori	$t6,$t6,0x77
/*  f19e57c:	10000004 */ 	beqz	$zero,.NB0f19e590
/*  f19e580:	afae00b0 */ 	sw	$t6,0xb0($sp)
.NB0f19e584:
/*  f19e584:	3c0f00ff */ 	lui	$t7,0xff
/*  f19e588:	35ef0077 */ 	ori	$t7,$t7,0x77
/*  f19e58c:	afaf00b0 */ 	sw	$t7,0xb0($sp)
.NB0f19e590:
/*  f19e590:	10600004 */ 	beqz	$v1,.NB0f19e5a4
/*  f19e594:	24a5b3fc */ 	addiu	$a1,$a1,-19460
/*  f19e598:	3c18ff00 */ 	lui	$t8,0xff00
/*  f19e59c:	10000003 */ 	beqz	$zero,.NB0f19e5ac
/*  f19e5a0:	afb800ac */ 	sw	$t8,0xac($sp)
.NB0f19e5a4:
/*  f19e5a4:	3c1900ff */ 	lui	$t9,0xff
/*  f19e5a8:	afb900ac */ 	sw	$t9,0xac($sp)
.NB0f19e5ac:
/*  f19e5ac:	10600004 */ 	beqz	$v1,.NB0f19e5c0
/*  f19e5b0:	3c0dff00 */ 	lui	$t5,0xff00
/*  f19e5b4:	35ad0033 */ 	ori	$t5,$t5,0x33
/*  f19e5b8:	10000004 */ 	beqz	$zero,.NB0f19e5cc
/*  f19e5bc:	afad00a8 */ 	sw	$t5,0xa8($sp)
.NB0f19e5c0:
/*  f19e5c0:	3c0e00ff */ 	lui	$t6,0xff
/*  f19e5c4:	35ce0033 */ 	ori	$t6,$t6,0x33
/*  f19e5c8:	afae00a8 */ 	sw	$t6,0xa8($sp)
.NB0f19e5cc:
/*  f19e5cc:	0c00381c */ 	jal	0xe070
/*  f19e5d0:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f19e5d4:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e5d8:	3c058009 */ 	lui	$a1,0x8009
/*  f19e5dc:	24a5b400 */ 	addiu	$a1,$a1,-19456
/*  f19e5e0:	0c00381c */ 	jal	0xe070
/*  f19e5e4:	24843e80 */ 	addiu	$a0,$a0,0x3e80
/*  f19e5e8:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e5ec:	3c058009 */ 	lui	$a1,0x8009
/*  f19e5f0:	24a5b404 */ 	addiu	$a1,$a1,-19452
/*  f19e5f4:	0c00381c */ 	jal	0xe070
/*  f19e5f8:	24843e84 */ 	addiu	$a0,$a0,0x3e84
/*  f19e5fc:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e600:	3c058009 */ 	lui	$a1,0x8009
/*  f19e604:	24a5b408 */ 	addiu	$a1,$a1,-19448
/*  f19e608:	0c00381c */ 	jal	0xe070
/*  f19e60c:	24843e88 */ 	addiu	$a0,$a0,0x3e88
/*  f19e610:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e614:	3c058009 */ 	lui	$a1,0x8009
/*  f19e618:	24a5b40c */ 	addiu	$a1,$a1,-19444
/*  f19e61c:	0c00381c */ 	jal	0xe070
/*  f19e620:	24843e8c */ 	addiu	$a0,$a0,0x3e8c
/*  f19e624:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e628:	3c058009 */ 	lui	$a1,0x8009
/*  f19e62c:	24a5b410 */ 	addiu	$a1,$a1,-19440
/*  f19e630:	0c00381c */ 	jal	0xe070
/*  f19e634:	24843e90 */ 	addiu	$a0,$a0,0x3e90
/*  f19e638:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e63c:	3c058009 */ 	lui	$a1,0x8009
/*  f19e640:	24a5b414 */ 	addiu	$a1,$a1,-19436
/*  f19e644:	0c00381c */ 	jal	0xe070
/*  f19e648:	24843e94 */ 	addiu	$a0,$a0,0x3e94
/*  f19e64c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f19e650:	3c058009 */ 	lui	$a1,0x8009
/*  f19e654:	24a5b418 */ 	addiu	$a1,$a1,-19432
/*  f19e658:	0c00381c */ 	jal	0xe070
/*  f19e65c:	24843e98 */ 	addiu	$a0,$a0,0x3e98
/*  f19e660:	8faf0154 */ 	lw	$t7,0x154($sp)
/*  f19e664:	3c19e700 */ 	lui	$t9,0xe700
/*  f19e668:	27a40154 */ 	addiu	$a0,$sp,0x154
/*  f19e66c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19e670:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f19e674:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f19e678:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f19e67c:	8fad0154 */ 	lw	$t5,0x154($sp)
/*  f19e680:	3c0fba00 */ 	lui	$t7,0xba00
/*  f19e684:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f19e688:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f19e68c:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f19e690:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f19e694:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f19e698:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f19e69c:	3c0db900 */ 	lui	$t5,0xb900
/*  f19e6a0:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f19e6a4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19e6a8:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e6ac:	af000004 */ 	sw	$zero,0x4($t8)
/*  f19e6b0:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f19e6b4:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f19e6b8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f19e6bc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f19e6c0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f19e6c4:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f19e6c8:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f19e6cc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f19e6d0:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f19e6d4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f19e6d8:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f19e6dc:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f19e6e0:	afad0154 */ 	sw	$t5,0x154($sp)
/*  f19e6e4:	240f0c00 */ 	addiu	$t7,$zero,0xc00
/*  f19e6e8:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f19e6ec:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f19e6f0:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f19e6f4:	3c0dba00 */ 	lui	$t5,0xba00
/*  f19e6f8:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f19e6fc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19e700:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e704:	af000004 */ 	sw	$zero,0x4($t8)
/*  f19e708:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f19e70c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19e710:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f19e714:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19e718:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19e71c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f19e720:	8fa5013c */ 	lw	$a1,0x13c($sp)
/*  f19e724:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19e728:	0fc2c5c8 */ 	jal	0xf0b1720
/*  f19e72c:	00003825 */ 	or	$a3,$zero,$zero
/*  f19e730:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f19e734:	3c0dba00 */ 	lui	$t5,0xba00
/*  f19e738:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f19e73c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19e740:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e744:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f19e748:	af000004 */ 	sw	$zero,0x4($t8)
/*  f19e74c:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f19e750:	3c18fcff */ 	lui	$t8,0xfcff
/*  f19e754:	3c19fffc */ 	lui	$t9,0xfffc
/*  f19e758:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f19e75c:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f19e760:	3739f279 */ 	ori	$t9,$t9,0xf279
/*  f19e764:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f19e768:	add80000 */ 	sw	$t8,0x0($t6)
/*  f19e76c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f19e770:	8fad0154 */ 	lw	$t5,0x154($sp)
/*  f19e774:	3c0fba00 */ 	lui	$t7,0xba00
/*  f19e778:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f19e77c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f19e780:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f19e784:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f19e788:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f19e78c:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f19e790:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f19e794:	3c028008 */ 	lui	$v0,0x8008
/*  f19e798:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19e79c:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e7a0:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f19e7a4:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f19e7a8:	03002825 */ 	or	$a1,$t8,$zero
/*  f19e7ac:	11c00004 */ 	beqz	$t6,.NB0f19e7c0
/*  f19e7b0:	3c0fff77 */ 	lui	$t7,0xff77
/*  f19e7b4:	35ef7799 */ 	ori	$t7,$t7,0x7799
/*  f19e7b8:	10000004 */ 	beqz	$zero,.NB0f19e7cc
/*  f19e7bc:	af0f0004 */ 	sw	$t7,0x4($t8)
.NB0f19e7c0:
/*  f19e7c0:	3c1855ff */ 	lui	$t8,0x55ff
/*  f19e7c4:	37185588 */ 	ori	$t8,$t8,0x5588
/*  f19e7c8:	acb80004 */ 	sw	$t8,0x4($a1)
.NB0f19e7cc:
/*  f19e7cc:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f19e7d0:	3c0efc12 */ 	lui	$t6,0xfc12
/*  f19e7d4:	3c0fff37 */ 	lui	$t7,0xff37
/*  f19e7d8:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f19e7dc:	afad0154 */ 	sw	$t5,0x154($sp)
/*  f19e7e0:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f19e7e4:	35ce9a25 */ 	ori	$t6,$t6,0x9a25
/*  f19e7e8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f19e7ec:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f19e7f0:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f19e7f4:	03201825 */ 	or	$v1,$t9,$zero
/*  f19e7f8:	24422320 */ 	addiu	$v0,$v0,0x2320
/*  f19e7fc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f19e800:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e804:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f19e808:	03002025 */ 	or	$a0,$t8,$zero
/*  f19e80c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f19e810:	25ae002a */ 	addiu	$t6,$t5,0x2a
/*  f19e814:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f19e818:	01f80019 */ 	multu	$t7,$t8
/*  f19e81c:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f19e820:	3c08e400 */ 	lui	$t0,0xe400
/*  f19e824:	3c0a0010 */ 	lui	$t2,0x10
/*  f19e828:	354a0400 */ 	ori	$t2,$t2,0x400
/*  f19e82c:	3c09b400 */ 	lui	$t1,0xb400
/*  f19e830:	3c0bb300 */ 	lui	$t3,0xb300
/*  f19e834:	240cfc00 */ 	addiu	$t4,$zero,-1024
/*  f19e838:	0000c812 */ 	mflo	$t9
/*  f19e83c:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f19e840:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f19e844:	27190025 */ 	addiu	$t9,$t8,0x25
/*  f19e848:	00196880 */ 	sll	$t5,$t9,0x2
/*  f19e84c:	01c87825 */ 	or	$t7,$t6,$t0
/*  f19e850:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f19e854:	01eec025 */ 	or	$t8,$t7,$t6
/*  f19e858:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f19e85c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f19e860:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f19e864:	272d000a */ 	addiu	$t5,$t9,0xa
/*  f19e868:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f19e86c:	01ee0019 */ 	multu	$t7,$t6
/*  f19e870:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f19e874:	25ee0005 */ 	addiu	$t6,$t7,0x5
/*  f19e878:	0000c012 */ 	mflo	$t8
/*  f19e87c:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f19e880:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f19e884:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f19e888:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f19e88c:	01b97825 */ 	or	$t7,$t5,$t9
/*  f19e890:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f19e894:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f19e898:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f19e89c:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f19e8a0:	adca0004 */ 	sw	$t2,0x4($t6)
/*  f19e8a4:	adc90000 */ 	sw	$t1,0x0($t6)
/*  f19e8a8:	8fad0154 */ 	lw	$t5,0x154($sp)
/*  f19e8ac:	01c02825 */ 	or	$a1,$t6,$zero
/*  f19e8b0:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f19e8b4:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f19e8b8:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e8bc:	adab0000 */ 	sw	$t3,0x0($t5)
/*  f19e8c0:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f19e8c4:	01a03025 */ 	or	$a2,$t5,$zero
/*  f19e8c8:	01cf001a */ 	div	$zero,$t6,$t7
/*  f19e8cc:	00006812 */ 	mflo	$t5
/*  f19e8d0:	000dcc00 */ 	sll	$t9,$t5,0x10
/*  f19e8d4:	15e00002 */ 	bnez	$t7,.NB0f19e8e0
/*  f19e8d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e8dc:	0007000d */ 	break	0x7
.NB0f19e8e0:
/*  f19e8e0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19e8e4:	15e10004 */ 	bne	$t7,$at,.NB0f19e8f8
/*  f19e8e8:	3c018000 */ 	lui	$at,0x8000
/*  f19e8ec:	15c10002 */ 	bne	$t6,$at,.NB0f19e8f8
/*  f19e8f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e8f4:	0006000d */ 	break	0x6
.NB0f19e8f8:
/*  f19e8f8:	372efc00 */ 	ori	$t6,$t9,0xfc00
/*  f19e8fc:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f19e900:	8faf0154 */ 	lw	$t7,0x154($sp)
/*  f19e904:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f19e908:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f19e90c:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f19e910:	01e01825 */ 	or	$v1,$t7,$zero
/*  f19e914:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f19e918:	25b90049 */ 	addiu	$t9,$t5,0x49
/*  f19e91c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f19e920:	01cf0019 */ 	multu	$t6,$t7
/*  f19e924:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f19e928:	0000c012 */ 	mflo	$t8
/*  f19e92c:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f19e930:	000dcb00 */ 	sll	$t9,$t5,0xc
/*  f19e934:	25f80025 */ 	addiu	$t8,$t7,0x25
/*  f19e938:	00186880 */ 	sll	$t5,$t8,0x2
/*  f19e93c:	03287025 */ 	or	$t6,$t9,$t0
/*  f19e940:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f19e944:	01d97825 */ 	or	$t7,$t6,$t9
/*  f19e948:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f19e94c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19e950:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f19e954:	270d0029 */ 	addiu	$t5,$t8,0x29
/*  f19e958:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f19e95c:	01d90019 */ 	multu	$t6,$t9
/*  f19e960:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19e964:	25d90005 */ 	addiu	$t9,$t6,0x5
/*  f19e968:	00007812 */ 	mflo	$t7
/*  f19e96c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f19e970:	00186b00 */ 	sll	$t5,$t8,0xc
/*  f19e974:	00197880 */ 	sll	$t7,$t9,0x2
/*  f19e978:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f19e97c:	01b87025 */ 	or	$t6,$t5,$t8
/*  f19e980:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f19e984:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f19e988:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f19e98c:	afaf0154 */ 	sw	$t7,0x154($sp)
/*  f19e990:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f19e994:	af290000 */ 	sw	$t1,0x0($t9)
/*  f19e998:	8fad0154 */ 	lw	$t5,0x154($sp)
/*  f19e99c:	03202025 */ 	or	$a0,$t9,$zero
/*  f19e9a0:	25b80008 */ 	addiu	$t8,$t5,0x8
/*  f19e9a4:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f19e9a8:	adab0000 */ 	sw	$t3,0x0($t5)
/*  f19e9ac:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f19e9b0:	01a02825 */ 	or	$a1,$t5,$zero
/*  f19e9b4:	018e001a */ 	div	$zero,$t4,$t6
/*  f19e9b8:	00007812 */ 	mflo	$t7
/*  f19e9bc:	000f6c00 */ 	sll	$t5,$t7,0x10
/*  f19e9c0:	35b8fc00 */ 	ori	$t8,$t5,0xfc00
/*  f19e9c4:	15c00002 */ 	bnez	$t6,.NB0f19e9d0
/*  f19e9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e9cc:	0007000d */ 	break	0x7
.NB0f19e9d0:
/*  f19e9d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19e9d4:	15c10004 */ 	bne	$t6,$at,.NB0f19e9e8
/*  f19e9d8:	3c018000 */ 	lui	$at,0x8000
/*  f19e9dc:	15810002 */ 	bne	$t4,$at,.NB0f19e9e8
/*  f19e9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e9e4:	0006000d */ 	break	0x6
.NB0f19e9e8:
/*  f19e9e8:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f19e9ec:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f19e9f0:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f19e9f4:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19e9f8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f19e9fc:	01c03025 */ 	or	$a2,$t6,$zero
/*  f19ea00:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f19ea04:	25ed002a */ 	addiu	$t5,$t7,0x2a
/*  f19ea08:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f19ea0c:	030e0019 */ 	multu	$t8,$t6
/*  f19ea10:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19ea14:	0000c812 */ 	mflo	$t9
/*  f19ea18:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f19ea1c:	000f6b00 */ 	sll	$t5,$t7,0xc
/*  f19ea20:	25d90044 */ 	addiu	$t9,$t6,0x44
/*  f19ea24:	00197880 */ 	sll	$t7,$t9,0x2
/*  f19ea28:	01a8c025 */ 	or	$t8,$t5,$t0
/*  f19ea2c:	31ed0fff */ 	andi	$t5,$t7,0xfff
/*  f19ea30:	030d7025 */ 	or	$t6,$t8,$t5
/*  f19ea34:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f19ea38:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f19ea3c:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f19ea40:	272f000a */ 	addiu	$t7,$t9,0xa
/*  f19ea44:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f19ea48:	030d0019 */ 	multu	$t8,$t5
/*  f19ea4c:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f19ea50:	270d0024 */ 	addiu	$t5,$t8,0x24
/*  f19ea54:	00007012 */ 	mflo	$t6
/*  f19ea58:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f19ea5c:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f19ea60:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f19ea64:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f19ea68:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f19ea6c:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f19ea70:	8fad0154 */ 	lw	$t5,0x154($sp)
/*  f19ea74:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f19ea78:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f19ea7c:	adaa0004 */ 	sw	$t2,0x4($t5)
/*  f19ea80:	ada90000 */ 	sw	$t1,0x0($t5)
/*  f19ea84:	8faf0154 */ 	lw	$t7,0x154($sp)
/*  f19ea88:	01a01825 */ 	or	$v1,$t5,$zero
/*  f19ea8c:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f19ea90:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f19ea94:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f19ea98:	adeb0000 */ 	sw	$t3,0x0($t7)
/*  f19ea9c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f19eaa0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f19eaa4:	01b8001a */ 	div	$zero,$t5,$t8
/*  f19eaa8:	00007812 */ 	mflo	$t7
/*  f19eaac:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f19eab0:	17000002 */ 	bnez	$t8,.NB0f19eabc
/*  f19eab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19eab8:	0007000d */ 	break	0x7
.NB0f19eabc:
/*  f19eabc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19eac0:	17010004 */ 	bne	$t8,$at,.NB0f19ead4
/*  f19eac4:	3c018000 */ 	lui	$at,0x8000
/*  f19eac8:	15a10002 */ 	bne	$t5,$at,.NB0f19ead4
/*  f19eacc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ead0:	0006000d */ 	break	0x6
.NB0f19ead4:
/*  f19ead4:	372d0400 */ 	ori	$t5,$t9,0x400
/*  f19ead8:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f19eadc:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f19eae0:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f19eae4:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f19eae8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f19eaec:	03002825 */ 	or	$a1,$t8,$zero
/*  f19eaf0:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f19eaf4:	25f90049 */ 	addiu	$t9,$t7,0x49
/*  f19eaf8:	00196880 */ 	sll	$t5,$t9,0x2
/*  f19eafc:	01b80019 */ 	multu	$t5,$t8
/*  f19eb00:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f19eb04:	00007012 */ 	mflo	$t6
/*  f19eb08:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f19eb0c:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f19eb10:	270e0044 */ 	addiu	$t6,$t8,0x44
/*  f19eb14:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f19eb18:	03286825 */ 	or	$t5,$t9,$t0
/*  f19eb1c:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f19eb20:	01b9c025 */ 	or	$t8,$t5,$t9
/*  f19eb24:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f19eb28:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f19eb2c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f19eb30:	25cf0029 */ 	addiu	$t7,$t6,0x29
/*  f19eb34:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f19eb38:	01b90019 */ 	multu	$t5,$t9
/*  f19eb3c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f19eb40:	25b90024 */ 	addiu	$t9,$t5,0x24
/*  f19eb44:	0000c012 */ 	mflo	$t8
/*  f19eb48:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f19eb4c:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f19eb50:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f19eb54:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f19eb58:	01ee6825 */ 	or	$t5,$t7,$t6
/*  f19eb5c:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f19eb60:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f19eb64:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f19eb68:	afb80154 */ 	sw	$t8,0x154($sp)
/*  f19eb6c:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f19eb70:	af290000 */ 	sw	$t1,0x0($t9)
/*  f19eb74:	8faf0154 */ 	lw	$t7,0x154($sp)
/*  f19eb78:	03203825 */ 	or	$a3,$t9,$zero
/*  f19eb7c:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f19eb80:	afae0154 */ 	sw	$t6,0x154($sp)
/*  f19eb84:	adeb0000 */ 	sw	$t3,0x0($t7)
/*  f19eb88:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f19eb8c:	01e01825 */ 	or	$v1,$t7,$zero
/*  f19eb90:	018d001a */ 	div	$zero,$t4,$t5
/*  f19eb94:	0000c812 */ 	mflo	$t9
/*  f19eb98:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f19eb9c:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f19eba0:	35ee0400 */ 	ori	$t6,$t7,0x400
/*  f19eba4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f19eba8:	15a00002 */ 	bnez	$t5,.NB0f19ebb4
/*  f19ebac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ebb0:	0007000d */ 	break	0x7
.NB0f19ebb4:
/*  f19ebb4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19ebb8:	15a10004 */ 	bne	$t5,$at,.NB0f19ebcc
/*  f19ebbc:	3c018000 */ 	lui	$at,0x8000
/*  f19ebc0:	15810002 */ 	bne	$t4,$at,.NB0f19ebcc
/*  f19ebc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ebc8:	0006000d */ 	break	0x6
.NB0f19ebcc:
/*  f19ebcc:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f19ebd0:	11a00004 */ 	beqz	$t5,.NB0f19ebe4
/*  f19ebd4:	3c19ff00 */ 	lui	$t9,0xff00
/*  f19ebd8:	37390055 */ 	ori	$t9,$t9,0x55
/*  f19ebdc:	10000004 */ 	beqz	$zero,.NB0f19ebf0
/*  f19ebe0:	afb90048 */ 	sw	$t9,0x48($sp)
.NB0f19ebe4:
/*  f19ebe4:	3c0300ff */ 	lui	$v1,0xff
/*  f19ebe8:	34630055 */ 	ori	$v1,$v1,0x55
/*  f19ebec:	afa30048 */ 	sw	$v1,0x48($sp)
.NB0f19ebf0:
/*  f19ebf0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ebf4:	0fc537b7 */ 	jal	0xf14dedc
/*  f19ebf8:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f19ebfc:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f19ec00:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ec04:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19ec08:	24a53e9c */ 	addiu	$a1,$a1,0x3e9c
/*  f19ec0c:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19ec10:	0c004fc1 */ 	jal	0x13f04
/*  f19ec14:	9706045c */ 	lhu	$a2,0x45c($t8)
/*  f19ec18:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f19ec1c:	27b80140 */ 	addiu	$t8,$sp,0x140
/*  f19ec20:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ec24:	25ee005d */ 	addiu	$t6,$t7,0x5d
/*  f19ec28:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f19ec2c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f19ec30:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19ec34:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ec38:	25b9000e */ 	addiu	$t9,$t5,0xe
/*  f19ec3c:	afb90148 */ 	sw	$t9,0x148($sp)
/*  f19ec40:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ec44:	0fc537d6 */ 	jal	0xf14df58
/*  f19ec48:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19ec4c:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f19ec50:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ec54:	11e00003 */ 	beqz	$t7,.NB0f19ec64
/*  f19ec58:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19ec5c:	10000002 */ 	beqz	$zero,.NB0f19ec68
/*  f19ec60:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19ec64:
/*  f19ec64:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19ec68:
/*  f19ec68:	0c002f77 */ 	jal	0xbddc
/*  f19ec6c:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19ec70:	0c002f7b */ 	jal	0xbdec
/*  f19ec74:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19ec78:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19ec7c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19ec80:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f19ec84:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f19ec88:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19ec8c:	87b90044 */ 	lh	$t9,0x44($sp)
/*  f19ec90:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ec94:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ec98:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ec9c:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19eca0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19eca4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19eca8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19ecac:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f19ecb0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19ecb4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19ecb8:	0fc541a6 */ 	jal	0xf150698
/*  f19ecbc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f19ecc0:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ecc4:	0fc5a4dd */ 	jal	0xf169374
/*  f19ecc8:	240451cd */ 	addiu	$a0,$zero,0x51cd
/*  f19eccc:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19ecd0:	0c004fc1 */ 	jal	0x13f04
/*  f19ecd4:	00402825 */ 	or	$a1,$v0,$zero
/*  f19ecd8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19ecdc:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f19ece0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ece4:	270f007a */ 	addiu	$t7,$t8,0x7a
/*  f19ece8:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f19ecec:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19ecf0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19ecf4:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ecf8:	25cd000e */ 	addiu	$t5,$t6,0xe
/*  f19ecfc:	afad0148 */ 	sw	$t5,0x148($sp)
/*  f19ed00:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ed04:	0fc537d6 */ 	jal	0xf14df58
/*  f19ed08:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19ed0c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f19ed10:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ed14:	13000003 */ 	beqz	$t8,.NB0f19ed24
/*  f19ed18:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19ed1c:	10000002 */ 	beqz	$zero,.NB0f19ed28
/*  f19ed20:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19ed24:
/*  f19ed24:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19ed28:
/*  f19ed28:	0c002f77 */ 	jal	0xbddc
/*  f19ed2c:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19ed30:	0c002f7b */ 	jal	0xbdec
/*  f19ed34:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19ed38:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19ed3c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19ed40:	8dce236c */ 	lw	$t6,0x236c($t6)
/*  f19ed44:	8def2370 */ 	lw	$t7,0x2370($t7)
/*  f19ed48:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19ed4c:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f19ed50:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ed54:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ed58:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ed5c:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19ed60:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19ed64:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19ed68:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19ed6c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f19ed70:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19ed74:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19ed78:	0fc541a6 */ 	jal	0xf150698
/*  f19ed7c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19ed80:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f19ed84:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ed88:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19ed8c:	9726045c */ 	lhu	$a2,0x45c($t9)
/*  f19ed90:	24a53ea0 */ 	addiu	$a1,$a1,0x3ea0
/*  f19ed94:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19ed98:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f19ed9c:	0306c021 */ 	addu	$t8,$t8,$a2
/*  f19eda0:	0c004fc1 */ 	jal	0x13f04
/*  f19eda4:	00183040 */ 	sll	$a2,$t8,0x1
/*  f19eda8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19edac:	8def236c */ 	lw	$t7,0x236c($t7)
/*  f19edb0:	3c078008 */ 	lui	$a3,0x8008
/*  f19edb4:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f19edb8:	27a40144 */ 	addiu	$a0,$sp,0x144
/*  f19edbc:	27a50140 */ 	addiu	$a1,$sp,0x140
/*  f19edc0:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f19edc4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19edc8:	0fc54655 */ 	jal	0xf151954
/*  f19edcc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19edd0:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f19edd4:	8fad0144 */ 	lw	$t5,0x144($sp)
/*  f19edd8:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19eddc:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ede0:	01cdc823 */ 	subu	$t9,$t6,$t5
/*  f19ede4:	273800b6 */ 	addiu	$t8,$t9,0xb6
/*  f19ede8:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f19edec:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f19edf0:	27ad0140 */ 	addiu	$t5,$sp,0x140
/*  f19edf4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19edf8:	25ee000e */ 	addiu	$t6,$t7,0xe
/*  f19edfc:	afae0148 */ 	sw	$t6,0x148($sp)
/*  f19ee00:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ee04:	0fc537d6 */ 	jal	0xf14df58
/*  f19ee08:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19ee0c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f19ee10:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ee14:	13200003 */ 	beqz	$t9,.NB0f19ee24
/*  f19ee18:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19ee1c:	10000002 */ 	beqz	$zero,.NB0f19ee28
/*  f19ee20:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19ee24:
/*  f19ee24:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19ee28:
/*  f19ee28:	0c002f77 */ 	jal	0xbddc
/*  f19ee2c:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19ee30:	0c002f7b */ 	jal	0xbdec
/*  f19ee34:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19ee38:	3c188008 */ 	lui	$t8,0x8008
/*  f19ee3c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19ee40:	8def236c */ 	lw	$t7,0x236c($t7)
/*  f19ee44:	8f182370 */ 	lw	$t8,0x2370($t8)
/*  f19ee48:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19ee4c:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f19ee50:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ee54:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ee58:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ee5c:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19ee60:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19ee64:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19ee68:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19ee6c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19ee70:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19ee74:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19ee78:	0fc541a6 */ 	jal	0xf150698
/*  f19ee7c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f19ee80:	8fad0138 */ 	lw	$t5,0x138($sp)
/*  f19ee84:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ee88:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19ee8c:	24a53ea4 */ 	addiu	$a1,$a1,0x3ea4
/*  f19ee90:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19ee94:	0c004fc1 */ 	jal	0x13f04
/*  f19ee98:	95a6045e */ 	lhu	$a2,0x45e($t5)
/*  f19ee9c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f19eea0:	27ad0140 */ 	addiu	$t5,$sp,0x140
/*  f19eea4:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19eea8:	2738005d */ 	addiu	$t8,$t9,0x5d
/*  f19eeac:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f19eeb0:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f19eeb4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19eeb8:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19eebc:	25ee0019 */ 	addiu	$t6,$t7,0x19
/*  f19eec0:	afae0148 */ 	sw	$t6,0x148($sp)
/*  f19eec4:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19eec8:	0fc537d6 */ 	jal	0xf14df58
/*  f19eecc:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19eed0:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f19eed4:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19eed8:	13200003 */ 	beqz	$t9,.NB0f19eee8
/*  f19eedc:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19eee0:	10000002 */ 	beqz	$zero,.NB0f19eeec
/*  f19eee4:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19eee8:
/*  f19eee8:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19eeec:
/*  f19eeec:	0c002f77 */ 	jal	0xbddc
/*  f19eef0:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19eef4:	0c002f7b */ 	jal	0xbdec
/*  f19eef8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19eefc:	3c188008 */ 	lui	$t8,0x8008
/*  f19ef00:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19ef04:	8def236c */ 	lw	$t7,0x236c($t7)
/*  f19ef08:	8f182370 */ 	lw	$t8,0x2370($t8)
/*  f19ef0c:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19ef10:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f19ef14:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ef18:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ef1c:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ef20:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19ef24:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19ef28:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19ef2c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19ef30:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19ef34:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19ef38:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19ef3c:	0fc541a6 */ 	jal	0xf150698
/*  f19ef40:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f19ef44:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ef48:	0fc5a4dd */ 	jal	0xf169374
/*  f19ef4c:	240451ce */ 	addiu	$a0,$zero,0x51ce
/*  f19ef50:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19ef54:	0c004fc1 */ 	jal	0x13f04
/*  f19ef58:	00402825 */ 	or	$a1,$v0,$zero
/*  f19ef5c:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f19ef60:	27ae0140 */ 	addiu	$t6,$sp,0x140
/*  f19ef64:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19ef68:	25b9007a */ 	addiu	$t9,$t5,0x7a
/*  f19ef6c:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f19ef70:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f19ef74:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19ef78:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19ef7c:	270f0019 */ 	addiu	$t7,$t8,0x19
/*  f19ef80:	afaf0148 */ 	sw	$t7,0x148($sp)
/*  f19ef84:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19ef88:	0fc537d6 */ 	jal	0xf14df58
/*  f19ef8c:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19ef90:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f19ef94:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19ef98:	11a00003 */ 	beqz	$t5,.NB0f19efa8
/*  f19ef9c:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19efa0:	10000002 */ 	beqz	$zero,.NB0f19efac
/*  f19efa4:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19efa8:
/*  f19efa8:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19efac:
/*  f19efac:	0c002f77 */ 	jal	0xbddc
/*  f19efb0:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19efb4:	0c002f7b */ 	jal	0xbdec
/*  f19efb8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19efbc:	3c198008 */ 	lui	$t9,0x8008
/*  f19efc0:	3c188008 */ 	lui	$t8,0x8008
/*  f19efc4:	8f18236c */ 	lw	$t8,0x236c($t8)
/*  f19efc8:	8f392370 */ 	lw	$t9,0x2370($t9)
/*  f19efcc:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19efd0:	87af0044 */ 	lh	$t7,0x44($sp)
/*  f19efd4:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19efd8:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19efdc:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19efe0:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19efe4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19efe8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19efec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19eff0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19eff4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19eff8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19effc:	0fc541a6 */ 	jal	0xf150698
/*  f19f000:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f19f004:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f19f008:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f00c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19f010:	95c6045e */ 	lhu	$a2,0x45e($t6)
/*  f19f014:	24a53ea8 */ 	addiu	$a1,$a1,0x3ea8
/*  f19f018:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f01c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f19f020:	01a66821 */ 	addu	$t5,$t5,$a2
/*  f19f024:	0c004fc1 */ 	jal	0x13f04
/*  f19f028:	01a03025 */ 	or	$a2,$t5,$zero
/*  f19f02c:	3c198008 */ 	lui	$t9,0x8008
/*  f19f030:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19f034:	3c078008 */ 	lui	$a3,0x8008
/*  f19f038:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f19f03c:	27a40144 */ 	addiu	$a0,$sp,0x144
/*  f19f040:	27a50140 */ 	addiu	$a1,$sp,0x140
/*  f19f044:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f19f048:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19f04c:	0fc54655 */ 	jal	0xf151954
/*  f19f050:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f054:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19f058:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f19f05c:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f060:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f064:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f19f068:	25cd00b6 */ 	addiu	$t5,$t6,0xb6
/*  f19f06c:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f19f070:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f19f074:	27af0140 */ 	addiu	$t7,$sp,0x140
/*  f19f078:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f07c:	27380019 */ 	addiu	$t8,$t9,0x19
/*  f19f080:	afb80148 */ 	sw	$t8,0x148($sp)
/*  f19f084:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f088:	0fc537d6 */ 	jal	0xf14df58
/*  f19f08c:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f090:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f19f094:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f098:	11c00003 */ 	beqz	$t6,.NB0f19f0a8
/*  f19f09c:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f0a0:	10000002 */ 	beqz	$zero,.NB0f19f0ac
/*  f19f0a4:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f0a8:
/*  f19f0a8:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f0ac:
/*  f19f0ac:	0c002f77 */ 	jal	0xbddc
/*  f19f0b0:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f0b4:	0c002f7b */ 	jal	0xbdec
/*  f19f0b8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f0bc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19f0c0:	3c198008 */ 	lui	$t9,0x8008
/*  f19f0c4:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19f0c8:	8dad2370 */ 	lw	$t5,0x2370($t5)
/*  f19f0cc:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f0d0:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f19f0d4:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f0d8:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f0dc:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f0e0:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f0e4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f0e8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f0ec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f0f0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19f0f4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19f0f8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f0fc:	0fc541a6 */ 	jal	0xf150698
/*  f19f100:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19f104:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f19f108:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f10c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19f110:	24a53eac */ 	addiu	$a1,$a1,0x3eac
/*  f19f114:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f118:	0c004fc1 */ 	jal	0x13f04
/*  f19f11c:	95e60460 */ 	lhu	$a2,0x460($t7)
/*  f19f120:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f19f124:	27af0140 */ 	addiu	$t7,$sp,0x140
/*  f19f128:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f12c:	25cd005d */ 	addiu	$t5,$t6,0x5d
/*  f19f130:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f19f134:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f19f138:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f13c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f140:	27380024 */ 	addiu	$t8,$t9,0x24
/*  f19f144:	afb80148 */ 	sw	$t8,0x148($sp)
/*  f19f148:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f14c:	0fc537d6 */ 	jal	0xf14df58
/*  f19f150:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f154:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f19f158:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f15c:	11c00003 */ 	beqz	$t6,.NB0f19f16c
/*  f19f160:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f164:	10000002 */ 	beqz	$zero,.NB0f19f170
/*  f19f168:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f16c:
/*  f19f16c:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f170:
/*  f19f170:	0c002f77 */ 	jal	0xbddc
/*  f19f174:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f178:	0c002f7b */ 	jal	0xbdec
/*  f19f17c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f180:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19f184:	3c198008 */ 	lui	$t9,0x8008
/*  f19f188:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19f18c:	8dad2370 */ 	lw	$t5,0x2370($t5)
/*  f19f190:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f194:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f19f198:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f19c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f1a0:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f1a4:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f1a8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f1ac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f1b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f1b4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19f1b8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19f1bc:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f1c0:	0fc541a6 */ 	jal	0xf150698
/*  f19f1c4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19f1c8:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f1cc:	0fc5a4dd */ 	jal	0xf169374
/*  f19f1d0:	240451cf */ 	addiu	$a0,$zero,0x51cf
/*  f19f1d4:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f1d8:	0c004fc1 */ 	jal	0x13f04
/*  f19f1dc:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f1e0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f19f1e4:	27b80140 */ 	addiu	$t8,$sp,0x140
/*  f19f1e8:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f1ec:	25ee007a */ 	addiu	$t6,$t7,0x7a
/*  f19f1f0:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f19f1f4:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f19f1f8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19f1fc:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f200:	25b90024 */ 	addiu	$t9,$t5,0x24
/*  f19f204:	afb90148 */ 	sw	$t9,0x148($sp)
/*  f19f208:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f20c:	0fc537d6 */ 	jal	0xf14df58
/*  f19f210:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f214:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f19f218:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f21c:	11e00003 */ 	beqz	$t7,.NB0f19f22c
/*  f19f220:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f224:	10000002 */ 	beqz	$zero,.NB0f19f230
/*  f19f228:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f22c:
/*  f19f22c:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f230:
/*  f19f230:	0c002f77 */ 	jal	0xbddc
/*  f19f234:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f238:	0c002f7b */ 	jal	0xbdec
/*  f19f23c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f240:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19f244:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19f248:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f19f24c:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f19f250:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f254:	87b90044 */ 	lh	$t9,0x44($sp)
/*  f19f258:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f25c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f260:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f264:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f268:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f26c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f270:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f274:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f19f278:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19f27c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f280:	0fc541a6 */ 	jal	0xf150698
/*  f19f284:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f19f288:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f19f28c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f290:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19f294:	97060460 */ 	lhu	$a2,0x460($t8)
/*  f19f298:	24a53eb0 */ 	addiu	$a1,$a1,0x3eb0
/*  f19f29c:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f2a0:	00067840 */ 	sll	$t7,$a2,0x1
/*  f19f2a4:	0c004fc1 */ 	jal	0x13f04
/*  f19f2a8:	01e03025 */ 	or	$a2,$t7,$zero
/*  f19f2ac:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19f2b0:	8dce236c */ 	lw	$t6,0x236c($t6)
/*  f19f2b4:	3c078008 */ 	lui	$a3,0x8008
/*  f19f2b8:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f19f2bc:	27a40144 */ 	addiu	$a0,$sp,0x144
/*  f19f2c0:	27a50140 */ 	addiu	$a1,$sp,0x140
/*  f19f2c4:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f19f2c8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19f2cc:	0fc54655 */ 	jal	0xf151954
/*  f19f2d0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19f2d4:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f19f2d8:	8fb90144 */ 	lw	$t9,0x144($sp)
/*  f19f2dc:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f2e0:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f2e4:	01b9c023 */ 	subu	$t8,$t5,$t9
/*  f19f2e8:	270f00b6 */ 	addiu	$t7,$t8,0xb6
/*  f19f2ec:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f19f2f0:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19f2f4:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f19f2f8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f2fc:	25cd0024 */ 	addiu	$t5,$t6,0x24
/*  f19f300:	afad0148 */ 	sw	$t5,0x148($sp)
/*  f19f304:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f308:	0fc537d6 */ 	jal	0xf14df58
/*  f19f30c:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f310:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f19f314:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f318:	13000003 */ 	beqz	$t8,.NB0f19f328
/*  f19f31c:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f320:	10000002 */ 	beqz	$zero,.NB0f19f32c
/*  f19f324:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f328:
/*  f19f328:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f32c:
/*  f19f32c:	0c002f77 */ 	jal	0xbddc
/*  f19f330:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f334:	0c002f7b */ 	jal	0xbdec
/*  f19f338:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f33c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19f340:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19f344:	8dce236c */ 	lw	$t6,0x236c($t6)
/*  f19f348:	8def2370 */ 	lw	$t7,0x2370($t7)
/*  f19f34c:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f350:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f19f354:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f358:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f35c:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f360:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f364:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f368:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f36c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f370:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f19f374:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f378:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f37c:	0fc541a6 */ 	jal	0xf150698
/*  f19f380:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19f384:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f19f388:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f38c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19f390:	24a53eb4 */ 	addiu	$a1,$a1,0x3eb4
/*  f19f394:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f398:	0c004fc1 */ 	jal	0x13f04
/*  f19f39c:	97260462 */ 	lhu	$a2,0x462($t9)
/*  f19f3a0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19f3a4:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f19f3a8:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f3ac:	270f005d */ 	addiu	$t7,$t8,0x5d
/*  f19f3b0:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f19f3b4:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19f3b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f3bc:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f3c0:	25cd002f */ 	addiu	$t5,$t6,0x2f
/*  f19f3c4:	afad0148 */ 	sw	$t5,0x148($sp)
/*  f19f3c8:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f3cc:	0fc537d6 */ 	jal	0xf14df58
/*  f19f3d0:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f3d4:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f19f3d8:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f3dc:	13000003 */ 	beqz	$t8,.NB0f19f3ec
/*  f19f3e0:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f3e4:	10000002 */ 	beqz	$zero,.NB0f19f3f0
/*  f19f3e8:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f3ec:
/*  f19f3ec:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f3f0:
/*  f19f3f0:	0c002f77 */ 	jal	0xbddc
/*  f19f3f4:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f3f8:	0c002f7b */ 	jal	0xbdec
/*  f19f3fc:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f400:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19f404:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19f408:	8dce236c */ 	lw	$t6,0x236c($t6)
/*  f19f40c:	8def2370 */ 	lw	$t7,0x2370($t7)
/*  f19f410:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f414:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f19f418:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f41c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f420:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f424:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f428:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f42c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f430:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f434:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f19f438:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f43c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f440:	0fc541a6 */ 	jal	0xf150698
/*  f19f444:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19f448:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f44c:	0fc5a4dd */ 	jal	0xf169374
/*  f19f450:	240451d0 */ 	addiu	$a0,$zero,0x51d0
/*  f19f454:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f19f458:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f45c:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f460:	0c004fc1 */ 	jal	0x13f04
/*  f19f464:	97260462 */ 	lhu	$a2,0x462($t9)
/*  f19f468:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19f46c:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f19f470:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f474:	270f007a */ 	addiu	$t7,$t8,0x7a
/*  f19f478:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f19f47c:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19f480:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f484:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f488:	25cd002f */ 	addiu	$t5,$t6,0x2f
/*  f19f48c:	afad0148 */ 	sw	$t5,0x148($sp)
/*  f19f490:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f494:	0fc537d6 */ 	jal	0xf14df58
/*  f19f498:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f49c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f19f4a0:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f4a4:	13000003 */ 	beqz	$t8,.NB0f19f4b4
/*  f19f4a8:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f4ac:	10000002 */ 	beqz	$zero,.NB0f19f4b8
/*  f19f4b0:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f4b4:
/*  f19f4b4:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f4b8:
/*  f19f4b8:	0c002f77 */ 	jal	0xbddc
/*  f19f4bc:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f4c0:	0c002f7b */ 	jal	0xbdec
/*  f19f4c4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f4c8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19f4cc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19f4d0:	8dce236c */ 	lw	$t6,0x236c($t6)
/*  f19f4d4:	8def2370 */ 	lw	$t7,0x2370($t7)
/*  f19f4d8:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f4dc:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f19f4e0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f4e4:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f4e8:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f4ec:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f4f0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f4f4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f4f8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f4fc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f19f500:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f504:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f508:	0fc541a6 */ 	jal	0xf150698
/*  f19f50c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19f510:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f19f514:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f518:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19f51c:	24a53eb8 */ 	addiu	$a1,$a1,0x3eb8
/*  f19f520:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f524:	0c004fc1 */ 	jal	0x13f04
/*  f19f528:	97260462 */ 	lhu	$a2,0x462($t9)
/*  f19f52c:	3c188008 */ 	lui	$t8,0x8008
/*  f19f530:	8f18236c */ 	lw	$t8,0x236c($t8)
/*  f19f534:	3c078008 */ 	lui	$a3,0x8008
/*  f19f538:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f19f53c:	27a40144 */ 	addiu	$a0,$sp,0x144
/*  f19f540:	27a50140 */ 	addiu	$a1,$sp,0x140
/*  f19f544:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f19f548:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19f54c:	0fc54655 */ 	jal	0xf151954
/*  f19f550:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19f554:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f19f558:	8fae0144 */ 	lw	$t6,0x144($sp)
/*  f19f55c:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f560:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f564:	01ee6823 */ 	subu	$t5,$t7,$t6
/*  f19f568:	25b900b6 */ 	addiu	$t9,$t5,0xb6
/*  f19f56c:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f19f570:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f19f574:	27ae0140 */ 	addiu	$t6,$sp,0x140
/*  f19f578:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19f57c:	270f002f */ 	addiu	$t7,$t8,0x2f
/*  f19f580:	afaf0148 */ 	sw	$t7,0x148($sp)
/*  f19f584:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f588:	0fc537d6 */ 	jal	0xf14df58
/*  f19f58c:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f590:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f19f594:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f598:	11a00003 */ 	beqz	$t5,.NB0f19f5a8
/*  f19f59c:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f5a0:	10000002 */ 	beqz	$zero,.NB0f19f5ac
/*  f19f5a4:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f5a8:
/*  f19f5a8:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f5ac:
/*  f19f5ac:	0c002f77 */ 	jal	0xbddc
/*  f19f5b0:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f5b4:	0c002f7b */ 	jal	0xbdec
/*  f19f5b8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f5bc:	3c198008 */ 	lui	$t9,0x8008
/*  f19f5c0:	3c188008 */ 	lui	$t8,0x8008
/*  f19f5c4:	8f18236c */ 	lw	$t8,0x236c($t8)
/*  f19f5c8:	8f392370 */ 	lw	$t9,0x2370($t9)
/*  f19f5cc:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f5d0:	87af0044 */ 	lh	$t7,0x44($sp)
/*  f19f5d4:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f5d8:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f5dc:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f5e0:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f5e4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f5e8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f5ec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f5f0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19f5f4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f5f8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f5fc:	0fc541a6 */ 	jal	0xf150698
/*  f19f600:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f19f604:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f608:	0fc5a4dd */ 	jal	0xf169374
/*  f19f60c:	240451d1 */ 	addiu	$a0,$zero,0x51d1
/*  f19f610:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f614:	0c004fc1 */ 	jal	0x13f04
/*  f19f618:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f61c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f19f620:	27af0140 */ 	addiu	$t7,$sp,0x140
/*  f19f624:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f628:	25cd0085 */ 	addiu	$t5,$t6,0x85
/*  f19f62c:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f19f630:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f19f634:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f638:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f63c:	2738003f */ 	addiu	$t8,$t9,0x3f
/*  f19f640:	afb80148 */ 	sw	$t8,0x148($sp)
/*  f19f644:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f648:	0fc537d6 */ 	jal	0xf14df58
/*  f19f64c:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f650:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f19f654:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f658:	11c00003 */ 	beqz	$t6,.NB0f19f668
/*  f19f65c:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f660:	10000002 */ 	beqz	$zero,.NB0f19f66c
/*  f19f664:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f668:
/*  f19f668:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f66c:
/*  f19f66c:	0c002f77 */ 	jal	0xbddc
/*  f19f670:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f674:	0c002f7b */ 	jal	0xbdec
/*  f19f678:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f67c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19f680:	3c198008 */ 	lui	$t9,0x8008
/*  f19f684:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19f688:	8dad2370 */ 	lw	$t5,0x2370($t5)
/*  f19f68c:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f690:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f19f694:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f698:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f69c:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f6a0:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f6a4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f6a8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f6ac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f6b0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19f6b4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19f6b8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f6bc:	0fc541a6 */ 	jal	0xf150698
/*  f19f6c0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19f6c4:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f19f6c8:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f6cc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f19f6d0:	95ed045c */ 	lhu	$t5,0x45c($t7)
/*  f19f6d4:	95ee0462 */ 	lhu	$t6,0x462($t7)
/*  f19f6d8:	95f8045e */ 	lhu	$t8,0x45e($t7)
/*  f19f6dc:	24a53ebc */ 	addiu	$a1,$a1,0x3ebc
/*  f19f6e0:	01cdc821 */ 	addu	$t9,$t6,$t5
/*  f19f6e4:	95ed0460 */ 	lhu	$t5,0x460($t7)
/*  f19f6e8:	03387021 */ 	addu	$t6,$t9,$t8
/*  f19f6ec:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f6f0:	0c004fc1 */ 	jal	0x13f04
/*  f19f6f4:	01cd3021 */ 	addu	$a2,$t6,$t5
/*  f19f6f8:	3c198008 */ 	lui	$t9,0x8008
/*  f19f6fc:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19f700:	3c078008 */ 	lui	$a3,0x8008
/*  f19f704:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f19f708:	27a40144 */ 	addiu	$a0,$sp,0x144
/*  f19f70c:	27a50140 */ 	addiu	$a1,$sp,0x140
/*  f19f710:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f19f714:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19f718:	0fc54655 */ 	jal	0xf151954
/*  f19f71c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f720:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19f724:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f19f728:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f72c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f730:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f19f734:	25cd00bc */ 	addiu	$t5,$t6,0xbc
/*  f19f738:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f19f73c:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f19f740:	27af0140 */ 	addiu	$t7,$sp,0x140
/*  f19f744:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19f748:	2738003f */ 	addiu	$t8,$t9,0x3f
/*  f19f74c:	afb80148 */ 	sw	$t8,0x148($sp)
/*  f19f750:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f754:	0fc537d6 */ 	jal	0xf14df58
/*  f19f758:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f75c:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f19f760:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f764:	11c00003 */ 	beqz	$t6,.NB0f19f774
/*  f19f768:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f76c:	10000002 */ 	beqz	$zero,.NB0f19f778
/*  f19f770:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f774:
/*  f19f774:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f778:
/*  f19f778:	0c002f77 */ 	jal	0xbddc
/*  f19f77c:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f780:	0c002f7b */ 	jal	0xbdec
/*  f19f784:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f788:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19f78c:	3c198008 */ 	lui	$t9,0x8008
/*  f19f790:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f19f794:	8dad2370 */ 	lw	$t5,0x2370($t5)
/*  f19f798:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f79c:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f19f7a0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f7a4:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f7a8:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f7ac:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f7b0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f7b4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f7b8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f7bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19f7c0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19f7c4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f7c8:	0fc541a6 */ 	jal	0xf150698
/*  f19f7cc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19f7d0:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f7d4:	0fc5a4dd */ 	jal	0xf169374
/*  f19f7d8:	240451d2 */ 	addiu	$a0,$zero,0x51d2
/*  f19f7dc:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f7e0:	0c004fc1 */ 	jal	0x13f04
/*  f19f7e4:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f7e8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f19f7ec:	27b80140 */ 	addiu	$t8,$sp,0x140
/*  f19f7f0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f7f4:	25ee0053 */ 	addiu	$t6,$t7,0x53
/*  f19f7f8:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f19f7fc:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f19f800:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19f804:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f808:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f19f80c:	afb90148 */ 	sw	$t9,0x148($sp)
/*  f19f810:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f814:	0fc537d6 */ 	jal	0xf14df58
/*  f19f818:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f81c:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f19f820:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f824:	11e00003 */ 	beqz	$t7,.NB0f19f834
/*  f19f828:	3c03ff69 */ 	lui	$v1,0xff69
/*  f19f82c:	10000002 */ 	beqz	$zero,.NB0f19f838
/*  f19f830:	346369aa */ 	ori	$v1,$v1,0x69aa
.NB0f19f834:
/*  f19f834:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f19f838:
/*  f19f838:	0c002f77 */ 	jal	0xbddc
/*  f19f83c:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f19f840:	0c002f7b */ 	jal	0xbdec
/*  f19f844:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f848:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19f84c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19f850:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f19f854:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f19f858:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f19f85c:	87b90044 */ 	lh	$t9,0x44($sp)
/*  f19f860:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f864:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f868:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f86c:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f870:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f874:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f878:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f87c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f19f880:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19f884:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19f888:	0fc541a6 */ 	jal	0xf150698
/*  f19f88c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f19f890:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f894:	0fc5a4dd */ 	jal	0xf169374
/*  f19f898:	240451d3 */ 	addiu	$a0,$zero,0x51d3
/*  f19f89c:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f8a0:	0c004fc1 */ 	jal	0x13f04
/*  f19f8a4:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f8a8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19f8ac:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f19f8b0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f8b4:	270f0026 */ 	addiu	$t7,$t8,0x26
/*  f19f8b8:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f19f8bc:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f19f8c0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f8c4:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f8c8:	25cd0023 */ 	addiu	$t5,$t6,0x23
/*  f19f8cc:	afad0148 */ 	sw	$t5,0x148($sp)
/*  f19f8d0:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f8d4:	0fc537d6 */ 	jal	0xf14df58
/*  f19f8d8:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f8dc:	0c002f77 */ 	jal	0xbddc
/*  f19f8e0:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f8e4:	0c002f7b */ 	jal	0xbdec
/*  f19f8e8:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f8ec:	3c188008 */ 	lui	$t8,0x8008
/*  f19f8f0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f19f8f4:	8def235c */ 	lw	$t7,0x235c($t7)
/*  f19f8f8:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f19f8fc:	87ad0044 */ 	lh	$t5,0x44($sp)
/*  f19f900:	240effff */ 	addiu	$t6,$zero,-1
/*  f19f904:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f19f908:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f90c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f910:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f914:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f918:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f91c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f920:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f924:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19f928:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19f92c:	0fc541a6 */ 	jal	0xf150698
/*  f19f930:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19f934:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f938:	0fc5a4dd */ 	jal	0xf169374
/*  f19f93c:	240451d4 */ 	addiu	$a0,$zero,0x51d4
/*  f19f940:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f944:	0c004fc1 */ 	jal	0x13f04
/*  f19f948:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f94c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f19f950:	27ad0140 */ 	addiu	$t5,$sp,0x140
/*  f19f954:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f958:	27380020 */ 	addiu	$t8,$t9,0x20
/*  f19f95c:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f19f960:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f19f964:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19f968:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f96c:	25ee001a */ 	addiu	$t6,$t7,0x1a
/*  f19f970:	afae0148 */ 	sw	$t6,0x148($sp)
/*  f19f974:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f978:	0fc537d6 */ 	jal	0xf14df58
/*  f19f97c:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19f980:	0c002f77 */ 	jal	0xbddc
/*  f19f984:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f988:	0c002f7b */ 	jal	0xbdec
/*  f19f98c:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19f990:	3c198008 */ 	lui	$t9,0x8008
/*  f19f994:	3c188008 */ 	lui	$t8,0x8008
/*  f19f998:	8f18235c */ 	lw	$t8,0x235c($t8)
/*  f19f99c:	8f392360 */ 	lw	$t9,0x2360($t9)
/*  f19f9a0:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f19f9a4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f19f9a8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f19f9ac:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f9b0:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19f9b4:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19f9b8:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19f9bc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19f9c0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19f9c4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19f9c8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19f9cc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19f9d0:	0fc541a6 */ 	jal	0xf150698
/*  f19f9d4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f19f9d8:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19f9dc:	0fc5a4dd */ 	jal	0xf169374
/*  f19f9e0:	240451d5 */ 	addiu	$a0,$zero,0x51d5
/*  f19f9e4:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19f9e8:	0c004fc1 */ 	jal	0x13f04
/*  f19f9ec:	00402825 */ 	or	$a1,$v0,$zero
/*  f19f9f0:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f19f9f4:	27ae0140 */ 	addiu	$t6,$sp,0x140
/*  f19f9f8:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19f9fc:	25b90018 */ 	addiu	$t9,$t5,0x18
/*  f19fa00:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f19fa04:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f19fa08:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19fa0c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19fa10:	270f0010 */ 	addiu	$t7,$t8,0x10
/*  f19fa14:	afaf0148 */ 	sw	$t7,0x148($sp)
/*  f19fa18:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19fa1c:	0fc537d6 */ 	jal	0xf14df58
/*  f19fa20:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19fa24:	0c002f77 */ 	jal	0xbddc
/*  f19fa28:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fa2c:	0c002f7b */ 	jal	0xbdec
/*  f19fa30:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19fa34:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19fa38:	3c198008 */ 	lui	$t9,0x8008
/*  f19fa3c:	8f39235c */ 	lw	$t9,0x235c($t9)
/*  f19fa40:	8dad2360 */ 	lw	$t5,0x2360($t5)
/*  f19fa44:	87af0044 */ 	lh	$t7,0x44($sp)
/*  f19fa48:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f19fa4c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f19fa50:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19fa54:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19fa58:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19fa5c:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19fa60:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19fa64:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19fa68:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19fa6c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19fa70:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19fa74:	0fc541a6 */ 	jal	0xf150698
/*  f19fa78:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f19fa7c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fa80:	0fc5a4dd */ 	jal	0xf169374
/*  f19fa84:	240451d6 */ 	addiu	$a0,$zero,0x51d6
/*  f19fa88:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f19fa8c:	0c004fc1 */ 	jal	0x13f04
/*  f19fa90:	00402825 */ 	or	$a1,$v0,$zero
/*  f19fa94:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f19fa98:	27af0140 */ 	addiu	$t7,$sp,0x140
/*  f19fa9c:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19faa0:	25cd000e */ 	addiu	$t5,$t6,0xe
/*  f19faa4:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f19faa8:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f19faac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19fab0:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19fab4:	27380004 */ 	addiu	$t8,$t9,0x4
/*  f19fab8:	afb80148 */ 	sw	$t8,0x148($sp)
/*  f19fabc:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19fac0:	0fc537d6 */ 	jal	0xf14df58
/*  f19fac4:	27a70144 */ 	addiu	$a3,$sp,0x144
/*  f19fac8:	0c002f77 */ 	jal	0xbddc
/*  f19facc:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fad0:	0c002f7b */ 	jal	0xbdec
/*  f19fad4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f19fad8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f19fadc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f19fae0:	8dad235c */ 	lw	$t5,0x235c($t5)
/*  f19fae4:	8dce2360 */ 	lw	$t6,0x2360($t6)
/*  f19fae8:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f19faec:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f19faf0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f19faf4:	8fa40154 */ 	lw	$a0,0x154($sp)
/*  f19faf8:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f19fafc:	27a60148 */ 	addiu	$a2,$sp,0x148
/*  f19fb00:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f19fb04:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19fb08:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f19fb0c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19fb10:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f19fb14:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19fb18:	0fc541a6 */ 	jal	0xf150698
/*  f19fb1c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19fb20:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fb24:	0fc537ce */ 	jal	0xf14df38
/*  f19fb28:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fb2c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fb30:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fb34:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fb38:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f19fb3c:	8fad00b0 */ 	lw	$t5,0xb0($sp)
/*  f19fb40:	250f0025 */ 	addiu	$t7,$t0,0x25
/*  f19fb44:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19fb48:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fb4c:	25060024 */ 	addiu	$a2,$t0,0x24
/*  f19fb50:	2465002d */ 	addiu	$a1,$v1,0x2d
/*  f19fb54:	24670051 */ 	addiu	$a3,$v1,0x51
/*  f19fb58:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f19fb5c:	0fc380fc */ 	jal	0xf0e03f0
/*  f19fb60:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f19fb64:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fb68:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fb6c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fb70:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f19fb74:	8faf00b0 */ 	lw	$t7,0xb0($sp)
/*  f19fb78:	2519002d */ 	addiu	$t9,$t0,0x2d
/*  f19fb7c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19fb80:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fb84:	2506002c */ 	addiu	$a2,$t0,0x2c
/*  f19fb88:	24650034 */ 	addiu	$a1,$v1,0x34
/*  f19fb8c:	24670054 */ 	addiu	$a3,$v1,0x54
/*  f19fb90:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19fb94:	0fc380df */ 	jal	0xf0e037c
/*  f19fb98:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f19fb9c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fba0:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fba4:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fba8:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f19fbac:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*  f19fbb0:	250e0033 */ 	addiu	$t6,$t0,0x33
/*  f19fbb4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19fbb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fbbc:	25060032 */ 	addiu	$a2,$t0,0x32
/*  f19fbc0:	2465003e */ 	addiu	$a1,$v1,0x3e
/*  f19fbc4:	24670057 */ 	addiu	$a3,$v1,0x57
/*  f19fbc8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f19fbcc:	0fc380df */ 	jal	0xf0e037c
/*  f19fbd0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f19fbd4:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fbd8:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fbdc:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fbe0:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f19fbe4:	8fae00b0 */ 	lw	$t6,0xb0($sp)
/*  f19fbe8:	2518003d */ 	addiu	$t8,$t0,0x3d
/*  f19fbec:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19fbf0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fbf4:	2506003c */ 	addiu	$a2,$t0,0x3c
/*  f19fbf8:	24650046 */ 	addiu	$a1,$v1,0x46
/*  f19fbfc:	2467005a */ 	addiu	$a3,$v1,0x5a
/*  f19fc00:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19fc04:	0fc380df */ 	jal	0xf0e037c
/*  f19fc08:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f19fc0c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fc10:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fc14:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fc18:	8fa900b0 */ 	lw	$t1,0xb0($sp)
/*  f19fc1c:	250d0025 */ 	addiu	$t5,$t0,0x25
/*  f19fc20:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19fc24:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fc28:	25060011 */ 	addiu	$a2,$t0,0x11
/*  f19fc2c:	24650051 */ 	addiu	$a1,$v1,0x51
/*  f19fc30:	24670052 */ 	addiu	$a3,$v1,0x52
/*  f19fc34:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f19fc38:	0fc380df */ 	jal	0xf0e037c
/*  f19fc3c:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f19fc40:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fc44:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fc48:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fc4c:	8fa900b0 */ 	lw	$t1,0xb0($sp)
/*  f19fc50:	2519002d */ 	addiu	$t9,$t0,0x2d
/*  f19fc54:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19fc58:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fc5c:	2506001c */ 	addiu	$a2,$t0,0x1c
/*  f19fc60:	24650054 */ 	addiu	$a1,$v1,0x54
/*  f19fc64:	24670055 */ 	addiu	$a3,$v1,0x55
/*  f19fc68:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f19fc6c:	0fc380df */ 	jal	0xf0e037c
/*  f19fc70:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f19fc74:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fc78:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fc7c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fc80:	8fa900b0 */ 	lw	$t1,0xb0($sp)
/*  f19fc84:	25180033 */ 	addiu	$t8,$t0,0x33
/*  f19fc88:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19fc8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fc90:	25060027 */ 	addiu	$a2,$t0,0x27
/*  f19fc94:	24650057 */ 	addiu	$a1,$v1,0x57
/*  f19fc98:	24670058 */ 	addiu	$a3,$v1,0x58
/*  f19fc9c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f19fca0:	0fc380df */ 	jal	0xf0e037c
/*  f19fca4:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f19fca8:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fcac:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fcb0:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fcb4:	8fa900b0 */ 	lw	$t1,0xb0($sp)
/*  f19fcb8:	250f003d */ 	addiu	$t7,$t0,0x3d
/*  f19fcbc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19fcc0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fcc4:	25060032 */ 	addiu	$a2,$t0,0x32
/*  f19fcc8:	2465005a */ 	addiu	$a1,$v1,0x5a
/*  f19fccc:	2467005b */ 	addiu	$a3,$v1,0x5b
/*  f19fcd0:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f19fcd4:	0fc380df */ 	jal	0xf0e037c
/*  f19fcd8:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f19fcdc:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fce0:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fce4:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fce8:	8fad00b0 */ 	lw	$t5,0xb0($sp)
/*  f19fcec:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f19fcf0:	250e0012 */ 	addiu	$t6,$t0,0x12
/*  f19fcf4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19fcf8:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fcfc:	25060011 */ 	addiu	$a2,$t0,0x11
/*  f19fd00:	24650051 */ 	addiu	$a1,$v1,0x51
/*  f19fd04:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f19fd08:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f19fd0c:	0fc380df */ 	jal	0xf0e037c
/*  f19fd10:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f19fd14:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fd18:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fd1c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fd20:	8faf00b0 */ 	lw	$t7,0xb0($sp)
/*  f19fd24:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f19fd28:	2518001d */ 	addiu	$t8,$t0,0x1d
/*  f19fd2c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19fd30:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fd34:	2506001c */ 	addiu	$a2,$t0,0x1c
/*  f19fd38:	24650054 */ 	addiu	$a1,$v1,0x54
/*  f19fd3c:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f19fd40:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19fd44:	0fc380df */ 	jal	0xf0e037c
/*  f19fd48:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f19fd4c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fd50:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fd54:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fd58:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*  f19fd5c:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f19fd60:	250d0028 */ 	addiu	$t5,$t0,0x28
/*  f19fd64:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19fd68:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fd6c:	25060027 */ 	addiu	$a2,$t0,0x27
/*  f19fd70:	24650057 */ 	addiu	$a1,$v1,0x57
/*  f19fd74:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f19fd78:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f19fd7c:	0fc380df */ 	jal	0xf0e037c
/*  f19fd80:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f19fd84:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f19fd88:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f19fd8c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f19fd90:	8fae00b0 */ 	lw	$t6,0xb0($sp)
/*  f19fd94:	8fad00ac */ 	lw	$t5,0xac($sp)
/*  f19fd98:	250f0033 */ 	addiu	$t7,$t0,0x33
/*  f19fd9c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19fda0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fda4:	25060032 */ 	addiu	$a2,$t0,0x32
/*  f19fda8:	2465005a */ 	addiu	$a1,$v1,0x5a
/*  f19fdac:	24670060 */ 	addiu	$a3,$v1,0x60
/*  f19fdb0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f19fdb4:	0fc380df */ 	jal	0xf0e037c
/*  f19fdb8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f19fdbc:	10000003 */ 	beqz	$zero,.NB0f19fdcc
/*  f19fdc0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f19fdc4:
/*  f19fdc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f19fdc8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f19fdcc:
/*  f19fdcc:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f19fdd0:	27bd0158 */ 	addiu	$sp,$sp,0x158
/*  f19fdd4:	03e00008 */ 	jr	$ra
/*  f19fdd8:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
s32 menuhandlerFrFailedContinue(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.currentplayer->prop->rooms[0] == 0xa) {
			func0f0f3704(&g_FrWeaponListMenuDialog);
		} else {
			menuPopDialog();
		}
	}

	return 0;
}
#endif

struct menuitem g_FrDifficultyMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000012, L_MPMENU_444, L_MPMENU_445, NULL }, // "Select Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPMENU_439, L_OPTIONS_003, frDifficultyMenuHandler }, // "Bronze"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, L_MPMENU_440, L_OPTIONS_003, frDifficultyMenuHandler }, // "Silver"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000020, L_MPMENU_441, L_OPTIONS_003, frDifficultyMenuHandler }, // "Gold"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU_429, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FrDifficultyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_442, // "Difficulty"
	g_FrDifficultyMenuItems,
	NULL,
	0x00000200,
	NULL,
};

struct menuitem g_FrWeaponListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00200008, 0x000000aa, 0x00000000, menuhandler001a348c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FrWeaponListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_446, // "Weapon"
	g_FrWeaponListMenuItems,
	NULL,
	0x00000200,
	NULL,
};

struct menuitem g_FrTrainingInfoInGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_443,                             (u32)&frMenuTextDifficultyName,            NULL                   }, // "Difficulty"
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextGoalScoreLabel,            (u32)&frMenuTextGoalScoreValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextMinAccuracyOrTargetsLabel, (u32)&frMenuTextMinAccuracyOrTargetsValue, NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextTimeLimitLabel,            (u32)&frMenuTextTimeLimitValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextAmmoLimitLabel,            (u32)&frMenuTextAmmoLimitValue,            NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_FRWEAPON, 0x00004000, 0x0000010e,                                PAL ? 0x69 : 0x5f,                                NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_428,                             frDetailsOkMenuHandler }, // "", "Resume"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_430,                             frAbortMenuHandler    }, // "", "Abort"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
};

struct menudialog g_FrTrainingInfoInGameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_447, // "Training Info"
	g_FrTrainingInfoInGameMenuItems,
	frTrainingInfoMenuDialog,
	0x00000602,
	NULL,
};

struct menuitem g_FrTrainingInfoPreGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_443,                             (u32)&frMenuTextDifficultyName,            NULL                   }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextGoalScoreLabel,            (u32)&frMenuTextGoalScoreValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextMinAccuracyOrTargetsLabel, (u32)&frMenuTextMinAccuracyOrTargetsValue, NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextTimeLimitLabel,            (u32)&frMenuTextTimeLimitValue,            NULL                   },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, (u32)&frMenuTextAmmoLimitLabel,            (u32)&frMenuTextAmmoLimitValue,            NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_FRWEAPON, 0x00004000, 0x0000010e,                                PAL ? 0x69 : 0x5f,                                NULL                   },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_427,                             frDetailsOkMenuHandler }, // "", "Ok"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000028, L_OPTIONS_003,                              L_MPMENU_429,                             frAbortMenuHandler    }, // "", "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,                                0x00000000,                                NULL                   },
};

struct menudialog g_FrTrainingInfoPreGameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_447, // "Training Info"
	g_FrTrainingInfoPreGameMenuItems,
	frTrainingInfoMenuDialog,
	0x00000602,
	NULL,
};

struct menuitem g_FrCompletedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, L_MPMENU_449, 0x00000000, NULL }, // "Completed!"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_450, (u32)&frMenuTextScoreValue, NULL }, // "Score:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_451, (u32)&frMenuTextTargetsDestroyedValue, NULL }, // "Targets Destroyed:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_452, (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_453, (u32)&frMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_454, (u32)&frMenuTextWeaponName, NULL }, // "Weapon:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_455, (u32)&frMenuTextAccuracyValue, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x000000d2, 0x00000050, menuhandler001a44c0 },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_252, 0x00000000, menuhandlerFrFailedContinue }, // "Continue"
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FrCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_448, // "Training Stats"
	g_FrCompletedMenuItems,
	frTrainingStatsMenuDialog,
	0x00000004,
	NULL,
};

struct menuitem g_FrFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&frMenuTextFailReason, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_450, (u32)&frMenuTextScoreValue, NULL }, // "Score:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_451, (u32)&frMenuTextTargetsDestroyedValue, NULL }, // "Targets Destroyed:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_452, (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_453, (u32)&frMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_454, (u32)&frMenuTextWeaponName, NULL }, // "Weapon:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_455, (u32)&frMenuTextAccuracyValue, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x000000d2, 0x00000050, menuhandler001a44c0 },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_252, 0x00000000, menuhandlerFrFailedContinue }, // "Continue"
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FrFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_448, // "Training Stats"
	g_FrFailedMenuItems,
	frTrainingStatsMenuDialog,
	0x00000004,
	NULL,
};

s32 ciOfficeInformationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct optiongroup groups[2] = {
		{ 0, L_MPMENU_421 }, // "Character Profiles"
		{ 0, L_MPMENU_422 }, // "Other Information"
	};

	s32 numunlockedchrbios = ciGetNumUnlockedChrBios();
	s32 numunlockedmiscbios = ciGetNumUnlockedMiscBios();
	struct chrbio *chrbio;
	struct miscbio *miscbio;

	groups[1].offset = numunlockedchrbios;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = numunlockedchrbios + numunlockedmiscbios;
		break;
	case MENUOP_GETOPTIONTEXT:
		if (data->list.value < numunlockedchrbios) {
			chrbio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(data->list.value));
			return (s32) langGet(chrbio->name);
		} else {
			miscbio = ciGetMiscBio(ciGetMiscBioIndexBySlot(data->list.value - numunlockedchrbios));
			return (s32) langGet(miscbio->name);
		}
		break;
	case MENUOP_SET:
		g_ChrBioSlot = data->list.value;
		if (g_ChrBioSlot < numunlockedchrbios) {
			menuPushDialog(&g_BioProfileMenuDialog);
		} else {
			menuPushDialog(&g_BioTextMenuDialog);
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		data->list.value = g_ChrBioSlot;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32) langGet(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = data->list.value == 0 ? 0 : numunlockedchrbios;
		break;
	}

	return 0;
}

struct menuitem g_BioListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000c8, 0x00000000, ciOfficeInformationMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_BioListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_418, // "Information"
	g_BioListMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_NowSafeMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, L_MPMENU_437, 0x00000000, NULL }, // "It is now safe to turn off your computer"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_438, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_NowSafeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_436, // "Cheats"
	g_NowSafeMenuItems,
	NULL,
	0x00000200,
	NULL,
};

s32 ciCharacterProfileMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	u32 bodynum = ciGetChrBioBodynumBySlot(g_ChrBioSlot);
	u32 mpbodynum = mpGetMpbodynumByBodynum(bodynum);
	u32 mpheadnum = mpGetMpheadnumByMpbodynum(mpbodynum);
	f32 x;
	f32 y;
	f32 scale;

	switch (operation) {
	case MENUOP_OPEN:
		if (bodynum == BODY_DRCAROLL) {
			scale = 0.7f;
			g_Menus[g_MpPlayerNum].unkd94 = -1;
		} else {
			g_Menus[g_MpPlayerNum].unkd94 = 30;
			scale = 1.0f;
		}

		g_Menus[g_MpPlayerNum].unkdb4 = PALDOWN(120);
		g_Menus[g_MpPlayerNum].unkdc0 = 0;

#if VERSION >= VERSION_PAL_FINAL
		if (g_ViMode != VIMODE_HIRES) {
			x = -117;

			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				x = -87;
			}
		} else {
			x = -177;

			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				x = -127;
			}
		}
#else
		x = -130;

		if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
			x = -100;
		}
#endif

		y = -15;

		if (bodynum == BODY_MRBLONDE) {
			y -= 12;
		}

		if (bodynum == BODY_THEKING) {
			scale = 0.8f;
		}

		func0f0f372c(&g_Menus[g_MpPlayerNum].unk840, x, y, 0, 0, 0, 0, scale, 7);

		g_Menus[g_MpPlayerNum].unkd50 = 8.2f;
		g_Menus[g_MpPlayerNum].unkd54 = -4.1f;
		g_Menus[g_MpPlayerNum].unkd5c = 0.00393f;
		g_Menus[g_MpPlayerNum].unkd64 = 0;
		g_Menus[g_MpPlayerNum].unkd8c = 0;
		g_Menus[g_MpPlayerNum].unkdb8 = PALDOWN(60);
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (bodynum == BODY_DRCAROLL) {
			static struct modelpartvisibility vis[] = {
				{ MODELPART_DRCAROLL_01, false },
				{ MODELPART_DRCAROLL_02, false },
				{ MODELPART_DRCAROLL_03, false },
				{ MODELPART_DRCAROLL_04, false },
				{ MODELPART_DRCAROLL_05, false },
				{ MODELPART_DRCAROLL_07, false },
				{ MODELPART_DRCAROLL_08, false },
				{ MODELPART_DRCAROLL_09, false },
				{ MODELPART_DRCAROLL_0A, false },
				{ MODELPART_DRCAROLL_0B, false },
				{ 255 },
			};
			g_Menus[g_MpPlayerNum].partvisibility = vis;
			g_Menus[g_MpPlayerNum].unk89c = 318;

		} else {
			g_Menus[g_MpPlayerNum].unk89c = 106;
		}

		if (bodynum == BODY_THEKING) {
			static struct modelpartvisibility vis[] = {
				{ MODELPART_ELVIS_03, false },
				{ 255 },
			};
			g_Menus[g_MpPlayerNum].partvisibility = vis;
		}

		g_Menus[g_MpPlayerNum].unk84c = 0xffff;
		g_Menus[g_MpPlayerNum].unk84c |= (mpheadnum << 16);
		g_Menus[g_MpPlayerNum].unk84c |= (mpbodynum << 24);

		if (g_Menus[g_MpPlayerNum].unkdb8 > 0) {
			g_Menus[g_MpPlayerNum].unkdb8 -= g_Vars.diffframe60;
		} else {
#if VERSION >= VERSION_PAL_FINAL
			f32 tmp = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60freal;
#else
			f32 tmp = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60f;
#endif
			g_Menus[g_MpPlayerNum].unkd8c = tmp;
			g_Menus[g_MpPlayerNum].unkd64 = tmp;
		}

		break;
	}

	return 0;
}

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

char *ciMenuTextChrBioName(struct menuitem *item)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	sprintf(g_StringPointer, "%s\n", langGet(bio->name));

	return g_StringPointer;
}

char *ciMenuTextChrBioAge(struct menuitem *item)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	sprintf(g_StringPointer, "%s\n", langGet(bio->age));

	return g_StringPointer;
}

char *ciMenuTextChrBioRace(struct menuitem *item)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	sprintf(g_StringPointer, "%s\n", langGet(bio->race));

	return g_StringPointer;
}

char *ciMenuTextMiscBioName(struct menuitem *item)
{
	struct miscbio *bio = ciGetMiscBio(ciGetMiscBioIndexBySlot(g_ChrBioSlot - ciGetNumUnlockedChrBios()));

	sprintf(g_StringPointer, "%s\n", langGet(bio->name));

	return g_StringPointer;
}

s32 dtDeviceListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = dtGetNumAvailable();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) weaponGetName(dtGetWeaponByDeviceIndex(dtGetIndexBySlot(data->list.value)));
	case MENUOP_SET:
		g_DtSlot = data->list.value;
		menuPushDialog(&g_DtDetailsMenuDialog);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->list.value = g_DtSlot;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 0;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return 0;
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = 0;
		break;
	}

	return 0;
}

char *dtMenuTextName(struct menuitem *item)
{
	u32 weaponnum = dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot));

	return weaponGetName(weaponnum);
}

s32 menuhandlerDtOkOrResume(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		// @bug: dtBegin() should not be called if training is already in
		// progress. Doing this resets the training timer.
		dtBegin();
		func0f0f8120();
	}

	return 0;
}

s32 menuhandler001a6514(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		dtEnd();
	}

	return 0;
}

struct menuitem g_BioProfileMenuItems[] = {
	{ MENUITEMTYPE_MODEL,      0,                  0x00000002, 0x00000046,    0x00000096,              NULL },
	{ MENUITEMTYPE_LABEL,      0,                  0x00000003, L_MPMENU_432, (u32)&ciMenuTextChrBioName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,      0,                  0x00000002, L_MPMENU_433, (u32)&ciMenuTextChrBioAge,  NULL }, // "Age:"
	{ MENUITEMTYPE_LABEL,      0,                  0x00000002, L_MPMENU_434, (u32)&ciMenuTextChrBioRace, NULL }, // "Race:"
	{ MENUITEMTYPE_SEPARATOR,  0,                  0x00000002, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_CHRBIO, 0x00000000, 0x000000b4,    0x00000064,              NULL },
	{ MENUITEMTYPE_SEPARATOR,  0,                  0x00000002, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_LABEL,      0,                  0x00000022, L_MPMENU_435, 0x00000000,              NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                  0x00000000, 0x00000000,    0x00000000,              NULL },
};

struct menudialog g_BioProfileMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_431, // "Character Profile"
	g_BioProfileMenuItems,
	ciCharacterProfileMenuDialog,
	0x00000002,
	NULL,
};

struct menuitem g_BioTextMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MISCBIO, 0x00000000, 0x000000c8,    0x00000096, NULL },
	{ MENUITEMTYPE_SEPARATOR,  0,                   0x00000002, 0x00000000,    0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,      0,                   0x00000022, L_MPMENU_414, 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                   0x00000000, 0x00000000,    0x00000000, NULL },
};

struct menudialog g_BioTextMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&ciMenuTextMiscBioName,
	g_BioTextMenuItems,
	NULL,
	0x00000200,
	NULL,
};

struct menuitem g_DtListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, dtDeviceListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_DtListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_417, // "Device List"
	g_DtListMenuItems,
	NULL,
	0x00000000,
	NULL,
};

s32 dtTrainingDetailsMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		{
		s32 weaponnum = dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot));
		u16 unused[] = {64250, 38500, 25650, 25700, 12950};
		func0f1a1ac0();
		g_Menus[g_MpPlayerNum].data.train.weaponnum = weaponnum;
		func0f105948(weaponnum);

#if VERSION >= VERSION_PAL_FINAL
		if (g_ViMode == VIMODE_HIRES) {
			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				g_Menus[g_MpPlayerNum].unkd78 = 84;
				g_Menus[g_MpPlayerNum].unkd50 = 84;
			} else {
				g_Menus[g_MpPlayerNum].unkd78 = 104;
				g_Menus[g_MpPlayerNum].unkd50 = 104;
			}
		} else {
			if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
				g_Menus[g_MpPlayerNum].unkd78 = 64;
				g_Menus[g_MpPlayerNum].unkd50 = 64;
			} else {
				g_Menus[g_MpPlayerNum].unkd78 = 84;
				g_Menus[g_MpPlayerNum].unkd50 = 84;
			}
		}
#else
		if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
			g_Menus[g_MpPlayerNum].unkd78 = 70;
			g_Menus[g_MpPlayerNum].unkd50 = 70;
		} else {
			g_Menus[g_MpPlayerNum].unkd78 = 90;
			g_Menus[g_MpPlayerNum].unkd50 = 90;
		}
#endif

		g_Menus[g_MpPlayerNum].unkd84 /= 2.5f;
		}
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curframe && g_Menus[g_MpPlayerNum].curframe->dialog == dialog) {
			s32 weaponnum = dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot));

			if (weaponnum == WEAPON_DISGUISE41) {
				g_Menus[g_MpPlayerNum].unk89c = 0x6a;
				g_Menus[g_MpPlayerNum].unkdb8 = PALDOWN(60);
				g_Menus[g_MpPlayerNum].unkdb4 = PALDOWN(120);
			}

			g_Menus[g_MpPlayerNum].unkd8c = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unkd64 = 18.849555969238f * var80061630;
			g_Menus[g_MpPlayerNum].unkd90 = 0;
			g_Menus[g_MpPlayerNum].unkd68 = 0;
		}
		break;
	}

	return 0;
}

char *dtMenuTextOkOrResume(struct menuitem *item)
{
	struct trainingdata *data = dtGetData();

	if (data->intraining) {
		return langGet(L_MPMENU_428); // "Resume"
	}

	return langGet(L_MPMENU_427); // "Ok"
}

char *dtMenuTextCancelOrAbort(struct menuitem *item)
{
	struct trainingdata *data = dtGetData();

	if (data->intraining) {
		return langGet(L_MPMENU_430); // "Abort"
	}

	return langGet(L_MPMENU_429); // "Cancel"
}

char *dtMenuTextTimeTakenValue(struct menuitem *item)
{
	struct trainingdata *data = dtGetData();
	f32 secs = data->timetaken / (PAL ? 50.0f : 60.0f);

	if (secs >= 60.0f) {
		s32 mins = 0;

		while (secs >= 60.0f) {
			secs -= 60.0f;
			mins++;
		}

		sprintf(g_StringPointer, "%dm %2ds\n", mins, (s32)ceilf(secs));
		return g_StringPointer;
	} else {
		sprintf(g_StringPointer, "%s%s%2.2fs\n", "", "", secs);
	}

	return g_StringPointer;
}

s32 menudialogDeviceTrainingResults(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		chrSetStageFlag(NULL, 0x08000000);
	}

	return false;
}

s32 htHoloListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = htGetNumUnlocked();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) htGetName(htGetIndexBySlot(data->list.value));
	case MENUOP_SET:
		var80088bb4 = data->list.value;
		menuPushDialog(&g_HtDetailsMenuDialog);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->list.value = var80088bb4;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 0;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return 0;
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = 0;
		break;
	}

	return 0;
}

char *htMenuTextName(struct menuitem *item)
{
	return htGetName(htGetIndexBySlot(var80088bb4));
}

s32 menuhandler001a6a34(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		htBegin();
		func0f0f8120();
	}

	return 0;
}

s32 menuhandler001a6a70(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		htEnd();
	}

	return 0;
}

s32 menudialog001a6aa4(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		func0f1a2198();
		break;
	case MENUOP_CLOSE:
		break;
	}

	return false;
}

char *htMenuTextOkOrResume(struct menuitem *item)
{
	struct trainingdata *data = getHoloTrainingData();

	if (data->intraining) {
		return langGet(L_MPMENU_428); // "Resume"
	}

	return langGet(L_MPMENU_427); // "Ok"
}

char *htMenuTextCancelOrAbort(struct menuitem *item)
{
	struct trainingdata *data = getHoloTrainingData();

	if (data->intraining) {
		return langGet(L_MPMENU_430); // "Abort"
	}

	return langGet(L_MPMENU_429); // "Cancel"
}

char *htMenuTextTimeTakenValue(struct menuitem *item)
{
	struct trainingdata *data = getHoloTrainingData();
	f32 secs = data->timetaken / (PAL ? 50.0f : 60.0f);

	if (secs >= 60.0f) {
		s32 mins = 0;

		while (secs >= 60.0f) {
			secs -= 60.0f;
			mins++;
		}

		sprintf(g_StringPointer, "%dm %2ds\n", mins, (s32)ceilf(secs));
		return g_StringPointer;
	} else {
		sprintf(g_StringPointer, "%s%s%2.2fs\n", "", "", secs);
	}

	return g_StringPointer;
}

s32 menudialogFiringRangeResults(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		chrSetStageFlag(NULL, 0x08000000);
	}

	return false;
}

char *bioMenuTextName(struct menuitem *item)
{
	struct hangarbio *bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(g_HangarBioSlot));

	return langGet(bio->name);
}

/**
 * The subheading is stored in the same string as the name, separated by a pipe.
 * eg. "Lucerne Tower\0|Global headquarters\n"
 */
char *ciMenuTextHangarBioSubheading(struct menuitem *item)
{
	s32 index = 0;
	struct hangarbio *bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(g_HangarBioSlot));
	char *name = langGet(bio->name);

	while (name[index] != '|') {
		index++;
	}

	sprintf(g_StringPointer, "%s\n", &name[index + 1]);

	return g_StringPointer;
}

struct menuitem g_DtDetailsMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_DEVICETRAINING, 0x00000000, 0x000000aa,                    PAL ? 0xd6 : 0xbe, NULL                    },
	{ MENUITEMTYPE_MODEL,      0,                          0x00000003, 0x0000008c,                    PAL ? 0xb4 : 0x9c, NULL                    },
	{ MENUITEMTYPE_SEPARATOR,  0,                          0x00000002, 0x00000000,                    0x00000000, NULL                    },
	{ MENUITEMTYPE_SELECTABLE, 0,                          0x00000008, (u32)&dtMenuTextOkOrResume,    0x00000000, menuhandlerDtOkOrResume },
	{ MENUITEMTYPE_SELECTABLE, 0,                          0x00000008, (u32)&dtMenuTextCancelOrAbort, 0x00000000, menuhandler001a6514     },
	{ MENUITEMTYPE_END,        0,                          0x00000000, 0x00000000,                    0x00000000, NULL                    },
};

struct menudialog g_DtDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&dtMenuTextName,
	g_DtDetailsMenuItems,
	dtTrainingDetailsMenuDialog,
	0x00000206,
	NULL,
};

struct menuitem g_DtFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                      0x00000032, L_MPMENU_426, 0x00000000,                     NULL }, // "Failed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                      0x00000002, L_MPMENU_424, (u32)&dtMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_DEVICETIP1, 0x00000000, 0x00000082,    PAL ? 110 : 100,                     NULL },
	{ MENUITEMTYPE_END,        0,                      0x00000000, 0x00000000,    0x00000000,                     NULL },
};

struct menudialog g_DtFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_423, // "Training Stats"
	g_DtFailedMenuItems,
	menudialogDeviceTrainingResults,
	0x00000200,
	&g_DtListMenuDialog,
};

struct menuitem g_DtCompletedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                      0x00000032, L_MPMENU_425, 0x00000000,                     NULL }, // "Completed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                      0x00000002, L_MPMENU_424, (u32)&dtMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                      0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_DEVICETIP2, 0x00000000, 0x00000082,    PAL ? 110 : 100,                     NULL },
	{ MENUITEMTYPE_END,        0,                      0x00000000, 0x00000000,    0x00000000,                     NULL },
};

struct menudialog g_DtCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_423, // "Training Stats"
	g_DtCompletedMenuItems,
	menudialogDeviceTrainingResults,
	0x00000200,
	&g_DtListMenuDialog,
};

struct menuitem g_HtListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, htHoloListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_HtListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_416, // "Holotraining"
	g_HtListMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_HtDetailsMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTRAINING, 0x00000000, 0x000000aa,                    0x000000be, NULL                },
	{ MENUITEMTYPE_MODEL,      0,                        0x00000003, 0x0000008c,                    0x0000009c, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                        0x00000002, 0x00000000,                    0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                        0x00000008, (u32)&htMenuTextOkOrResume,    0x00000000, menuhandler001a6a34 },
	{ MENUITEMTYPE_SELECTABLE, 0,                        0x00000008, (u32)&htMenuTextCancelOrAbort, 0x00000000, menuhandler001a6a70 },
	{ MENUITEMTYPE_END,        0,                        0x00000000, 0x00000000,                    0x00000000, NULL                },
};

struct menudialog g_HtDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&htMenuTextName,
	g_HtDetailsMenuItems,
	menudialog001a6aa4,
	0x00000206,
	NULL,
};

struct menuitem g_HtFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000032, L_MPMENU_426, 0x00000000,                     NULL }, // "Failed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_424, (u32)&htMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP1, 0x00000000, 0x00000082,    PAL ? 110 : 100,                     NULL },
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,    0x00000000,                     NULL },
};

struct menudialog g_HtFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_423, // "Training Stats"
	g_HtFailedMenuItems,
	menudialogFiringRangeResults,
	0x00000200,
	&g_HtListMenuDialog,
};

struct menuitem g_HtCompletedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,                    0x00000032, L_MPMENU_425, 0x00000000,                     NULL }, // "Completed!"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_LABEL,      0,                    0x00000002, L_MPMENU_424, (u32)&htMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000002, 0x00000000,    0x00000000,                     NULL },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HOLOTIP2, 0x00000000, 0x00000082,    PAL ? 110 : 100,                     NULL },
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,    0x00000000,                     NULL },
};

struct menudialog g_HtCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_423, // "Training Stats"
	g_HtCompletedMenuItems,
	menudialogFiringRangeResults,
	0x00000200,
	&g_HtListMenuDialog,
};

s32 ciHangarInformationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct optiongroup groups[2] = {
		{ 0, L_MPMENU_419 }, // "Locations"
		{ 0, L_MPMENU_420 }, // "Vehicles"
	};

	s32 bioindex;
	struct hangarbio *bio;

	groups[1].offset = ciGetNumUnlockedLocationBios();

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = ciGetNumUnlockedHangarBios();
		break;
	case MENUOP_GETOPTIONTEXT:
		bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(data->list.value));
		return (s32) langGet(bio->name);
	case MENUOP_SET:
		g_HangarBioSlot = data->list.value;
		bioindex = ciGetHangarBioIndexBySlot(g_HangarBioSlot);

		if (bioindex <= HANGARBIO_SKEDARRUINS) {
			menuPushDialog(&g_HangarLocationDetailsMenuDialog);
		} else {
			menuPushDialog(&g_HangarVehicleDetailsMenuDialog);
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		data->list.value = g_HangarBioSlot;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32) langGet(groups[data->list.value].name);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = data->list.value == 0 ? 0 : groups[1].offset;
		break;
	}

	return 0;
}

u32 var800897b4 = 0x1b0d0e10;
u32 var800897b8 = 0x11121316;
u32 var800897bc = 0x1718191a;
u32 var800897c0 = 0x1c1d0000;

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuhandler001a6ea4
/*  f1a6ea4:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1a6ea8:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1a6eac:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1a6eb0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1a6eb4:	1481012b */ 	bne	$a0,$at,.L0f1a7364
/*  f1a6eb8:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f1a6ebc:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a6ec0:	3c048009 */ 	lui	$a0,%hi(g_HangarBioSlot)
/*  f1a6ec4:	90848964 */ 	lbu	$a0,%lo(g_HangarBioSlot)($a0)
/*  f1a6ec8:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f1a6ecc:	0fc685db */ 	jal	ciGetHangarBioIndexBySlot
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
/*  f1a6f98:	3c0c800b */ 	lui	$t4,%hi(var800ab5a8)
/*  f1a6f9c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f1a6fa0:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1a6fa4:	00095880 */ 	sll	$t3,$t1,0x2
/*  f1a6fa8:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f1a6fac:	af190000 */ 	sw	$t9,0x0($t8)
/*  f1a6fb0:	8d8cb5a8 */ 	lw	$t4,%lo(var800ab5a8)($t4)
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
/*  f1a7074:	3c078008 */ 	lui	$a3,%hi(g_ScaleX)
/*  f1a7078:	24e7fac0 */ 	addiu	$a3,$a3,%lo(g_ScaleX)
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
/*  f1a7160:	00000000 */ 	nop
/*  f1a7164:	0007000d */ 	break	0x7
.L0f1a7168:
/*  f1a7168:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a716c:	15810004 */ 	bne	$t4,$at,.L0f1a7180
/*  f1a7170:	3c018000 */ 	lui	$at,0x8000
/*  f1a7174:	15a10002 */ 	bne	$t5,$at,.L0f1a7180
/*  f1a7178:	00000000 */ 	nop
/*  f1a717c:	0006000d */ 	break	0x6
.L0f1a7180:
/*  f1a7180:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f1a7184:	10000008 */ 	b	.L0f1a71a8
/*  f1a7188:	00000000 */ 	nop
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
/*  f1a71b4:	0fc69b23 */ 	jal	bioMenuTextName
/*  f1a71b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a71bc:	3c0a8008 */ 	lui	$t2,%hi(g_FontHandelGothicMd2)
/*  f1a71c0:	8d4afb14 */ 	lw	$t2,%lo(g_FontHandelGothicMd2)($t2)
/*  f1a71c4:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicMd1)
/*  f1a71c8:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f1a71cc:	8ce7fb18 */ 	lw	$a3,%lo(g_FontHandelGothicMd1)($a3)
/*  f1a71d0:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f1a71d4:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f1a71d8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a71dc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a71e0:	0fc55cbe */ 	jal	textMeasure
/*  f1a71e4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a71e8:	8fa20094 */ 	lw	$v0,0x94($sp)
/*  f1a71ec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a71f0:	54410006 */ 	bnel	$v0,$at,.L0f1a720c
/*  f1a71f4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a71f8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a71fc:	270f0040 */ 	addiu	$t7,$t8,0x40
/*  f1a7200:	10000007 */ 	b	.L0f1a7220
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
/*  f1a7228:	0c002f02 */ 	jal	viGetWidth
/*  f1a722c:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f1a7230:	0c002f06 */ 	jal	viGetHeight
/*  f1a7234:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a7238:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicMd1)
/*  f1a723c:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicMd2)
/*  f1a7240:	8f39fb14 */ 	lw	$t9,%lo(g_FontHandelGothicMd2)($t9)
/*  f1a7244:	8deffb18 */ 	lw	$t7,%lo(g_FontHandelGothicMd1)($t7)
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
/*  f1a7278:	0fc5580f */ 	jal	textRenderProjected
/*  f1a727c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1a7280:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a7284:	0fc69b31 */ 	jal	ciMenuTextHangarBioSubheading
/*  f1a7288:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a728c:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm2)
/*  f1a7290:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm2)($t5)
/*  f1a7294:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f1a7298:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f1a729c:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f1a72a0:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f1a72a4:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f1a72a8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a72ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a72b0:	0fc55cbe */ 	jal	textMeasure
/*  f1a72b4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a72b8:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1a72bc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a72c0:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f1a72c4:	15810005 */ 	bne	$t4,$at,.L0f1a72dc
/*  f1a72c8:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f1a72cc:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1a72d0:	25580040 */ 	addiu	$t8,$t2,0x40
/*  f1a72d4:	10000006 */ 	b	.L0f1a72f0
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
/*  f1a72f8:	0c002f02 */ 	jal	viGetWidth
/*  f1a72fc:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f1a7300:	0c002f06 */ 	jal	viGetHeight
/*  f1a7304:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f1a7308:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm1)
/*  f1a730c:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm2)
/*  f1a7310:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm2)($t9)
/*  f1a7314:	8deffb10 */ 	lw	$t7,%lo(g_FontHandelGothicSm1)($t7)
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
/*  f1a7348:	0fc5580f */ 	jal	textRenderProjected
/*  f1a734c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a7350:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f1a7354:	0fc54de0 */ 	jal	func0f153780
/*  f1a7358:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a735c:	10000003 */ 	b	.L0f1a736c
/*  f1a7360:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a7364:
/*  f1a7364:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a7368:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1a736c:
/*  f1a736c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1a7370:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f1a7374:	03e00008 */ 	jr	$ra
/*  f1a7378:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel menuhandler001a6ea4
/*  f1a0ec0:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a0ec4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1a0ec8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1a0ecc:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1a0ed0:	1481011d */ 	bne	$a0,$at,.NB0f1a1348
/*  f1a0ed4:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a0ed8:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a0edc:	3c048009 */ 	lui	$a0,0x8009
/*  f1a0ee0:	9084b0d4 */ 	lbu	$a0,-0x4f2c($a0)
/*  f1a0ee4:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f1a0ee8:	0fc66ddf */ 	jal	0xf19b77c
/*  f1a0eec:	8cd00008 */ 	lw	$s0,0x8($a2)
/*  f1a0ef0:	2841000e */ 	slti	$at,$v0,0xe
/*  f1a0ef4:	1020009e */ 	beqz	$at,.NB0f1a1170
/*  f1a0ef8:	3c0f8009 */ 	lui	$t7,0x8009
/*  f1a0efc:	25efbf24 */ 	addiu	$t7,$t7,-16604
/*  f1a0f00:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a0f04:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f1a0f08:	00e25021 */ 	addu	$t2,$a3,$v0
/*  f1a0f0c:	ace10000 */ 	sw	$at,0x0($a3)
/*  f1a0f10:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f1a0f14:	3c0de700 */ 	lui	$t5,0xe700
/*  f1a0f18:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f1a0f1c:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f1a0f20:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a0f24:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1a0f28:	ace10008 */ 	sw	$at,0x8($a3)
/*  f1a0f2c:	95e1000c */ 	lhu	$at,0xc($t7)
/*  f1a0f30:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a0f34:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f1a0f38:	a4e1000c */ 	sh	$at,0xc($a3)
/*  f1a0f3c:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f1a0f40:	91490000 */ 	lbu	$t1,0x0($t2)
/*  f1a0f44:	00003825 */ 	or	$a3,$zero,$zero
/*  f1a0f48:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f1a0f4c:	afac009c */ 	sw	$t4,0x9c($sp)
/*  f1a0f50:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f1a0f54:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f1a0f58:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f1a0f5c:	3c0bb900 */ 	lui	$t3,0xb900
/*  f1a0f60:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f1a0f64:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f1a0f68:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f1a0f6c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1a0f70:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f1a0f74:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a0f78:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1a0f7c:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f1a0f80:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f1a0f84:	afaa009c */ 	sw	$t2,0x9c($sp)
/*  f1a0f88:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1a0f8c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f1a0f90:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f1a0f94:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1a0f98:	37390903 */ 	ori	$t9,$t9,0x903
/*  f1a0f9c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f1a0fa0:	afad009c */ 	sw	$t5,0x9c($sp)
/*  f1a0fa4:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f1a0fa8:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f1a0fac:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a0fb0:	240a0c00 */ 	addiu	$t2,$zero,0xc00
/*  f1a0fb4:	3c0c800b */ 	lui	$t4,0x800b
/*  f1a0fb8:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f1a0fbc:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a0fc0:	00095880 */ 	sll	$t3,$t1,0x2
/*  f1a0fc4:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f1a0fc8:	af190000 */ 	sw	$t9,0x0($t8)
/*  f1a0fcc:	8d8cfe58 */ 	lw	$t4,-0x1a8($t4)
/*  f1a0fd0:	01695823 */ 	subu	$t3,$t3,$t1
/*  f1a0fd4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1a0fd8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a0fdc:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f1a0fe0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a0fe4:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a0fe8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a0fec:	0fc2c5c8 */ 	jal	0xf0b1720
/*  f1a0ff0:	016c2821 */ 	addu	$a1,$t3,$t4
/*  f1a0ff4:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f1a0ff8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1a0ffc:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f1a1000:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f1a1004:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1a1008:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1a100c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f1a1010:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f1a1014:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f1a1018:	3c0dfffc */ 	lui	$t5,0xfffc
/*  f1a101c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f1a1020:	afab009c */ 	sw	$t3,0x9c($sp)
/*  f1a1024:	35adf279 */ 	ori	$t5,$t5,0xf279
/*  f1a1028:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f1a102c:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f1a1030:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f1a1034:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f1a1038:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1a103c:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1a1040:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f1a1044:	afb8009c */ 	sw	$t8,0x9c($sp)
/*  f1a1048:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1a104c:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f1a1050:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a1054:	3c068008 */ 	lui	$a2,0x8008
/*  f1a1058:	24c62320 */ 	addiu	$a2,$a2,0x2320
/*  f1a105c:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f1a1060:	afaa009c */ 	sw	$t2,0x9c($sp)
/*  f1a1064:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f1a1068:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1a106c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1a1070:	256c003c */ 	addiu	$t4,$t3,0x3c
/*  f1a1074:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1a1078:	01ae0019 */ 	multu	$t5,$t6
/*  f1a107c:	8e0b0004 */ 	lw	$t3,0x4($s0)
/*  f1a1080:	03202825 */ 	or	$a1,$t9,$zero
/*  f1a1084:	3c01e400 */ 	lui	$at,0xe400
/*  f1a1088:	256c0027 */ 	addiu	$t4,$t3,0x27
/*  f1a108c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1a1090:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f1a1094:	0000c012 */ 	mflo	$t8
/*  f1a1098:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f1a109c:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f1a10a0:	03215025 */ 	or	$t2,$t9,$at
/*  f1a10a4:	014ec025 */ 	or	$t8,$t2,$t6
/*  f1a10a8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1a10ac:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a10b0:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f1a10b4:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1a10b8:	25f90006 */ 	addiu	$t9,$t7,0x6
/*  f1a10bc:	00195880 */ 	sll	$t3,$t9,0x2
/*  f1a10c0:	016c0019 */ 	multu	$t3,$t4
/*  f1a10c4:	270f0003 */ 	addiu	$t7,$t8,0x3
/*  f1a10c8:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1a10cc:	332b0fff */ 	andi	$t3,$t9,0xfff
/*  f1a10d0:	240f0480 */ 	addiu	$t7,$zero,0x480
/*  f1a10d4:	3c18b400 */ 	lui	$t8,0xb400
/*  f1a10d8:	00006812 */ 	mflo	$t5
/*  f1a10dc:	31aa0fff */ 	andi	$t2,$t5,0xfff
/*  f1a10e0:	000a7300 */ 	sll	$t6,$t2,0xc
/*  f1a10e4:	01cb6025 */ 	or	$t4,$t6,$t3
/*  f1a10e8:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f1a10ec:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f1a10f0:	3c0bb300 */ 	lui	$t3,0xb300
/*  f1a10f4:	25aa0008 */ 	addiu	$t2,$t5,0x8
/*  f1a10f8:	afaa009c */ 	sw	$t2,0x9c($sp)
/*  f1a10fc:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f1a1100:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f1a1104:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f1a1108:	01a01025 */ 	or	$v0,$t5,$zero
/*  f1a110c:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f1a1110:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f1a1114:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f1a1118:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f1a111c:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f1a1120:	03201825 */ 	or	$v1,$t9,$zero
/*  f1a1124:	240effff */ 	addiu	$t6,$zero,-1
/*  f1a1128:	01ac001a */ 	div	$zero,$t5,$t4
/*  f1a112c:	00005012 */ 	mflo	$t2
/*  f1a1130:	3158ffff */ 	andi	$t8,$t2,0xffff
/*  f1a1134:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f1a1138:	35f9fc00 */ 	ori	$t9,$t7,0xfc00
/*  f1a113c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1a1140:	15800002 */ 	bnez	$t4,.NB0f1a114c
/*  f1a1144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1148:	0007000d */ 	break	0x7
.NB0f1a114c:
/*  f1a114c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a1150:	15810004 */ 	bne	$t4,$at,.NB0f1a1164
/*  f1a1154:	3c018000 */ 	lui	$at,0x8000
/*  f1a1158:	15a10002 */ 	bne	$t5,$at,.NB0f1a1164
/*  f1a115c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1160:	0006000d */ 	break	0x6
.NB0f1a1164:
/*  f1a1164:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f1a1168:	10000008 */ 	beqz	$zero,.NB0f1a118c
/*  f1a116c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1a1170:
/*  f1a1170:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f1a1174:	8d6d0008 */ 	lw	$t5,0x8($t3)
/*  f1a1178:	05a10003 */ 	bgez	$t5,.NB0f1a1188
/*  f1a117c:	000d6043 */ 	sra	$t4,$t5,0x1
/*  f1a1180:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f1a1184:	00016043 */ 	sra	$t4,$at,0x1
.NB0f1a1188:
/*  f1a1188:	afac008c */ 	sw	$t4,0x8c($sp)
.NB0f1a118c:
/*  f1a118c:	0fc5374a */ 	jal	0xf14dd28
/*  f1a1190:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f1a1194:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f1a1198:	0fc6832a */ 	jal	0xf1a0ca8
/*  f1a119c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a11a0:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1a11a4:	8d4a2374 */ 	lw	$t2,0x2374($t2)
/*  f1a11a8:	3c078008 */ 	lui	$a3,0x8008
/*  f1a11ac:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f1a11b0:	8ce72378 */ 	lw	$a3,0x2378($a3)
/*  f1a11b4:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f1a11b8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1a11bc:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a11c0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a11c4:	0fc54655 */ 	jal	0xf151954
/*  f1a11c8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a11cc:	8fa2008c */ 	lw	$v0,0x8c($sp)
/*  f1a11d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a11d4:	54410006 */ 	bnel	$v0,$at,.NB0f1a11f0
/*  f1a11d8:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1a11dc:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1a11e0:	270f0040 */ 	addiu	$t7,$t8,0x40
/*  f1a11e4:	10000007 */ 	beqz	$zero,.NB0f1a1204
/*  f1a11e8:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f1a11ec:	8e190000 */ 	lw	$t9,0x0($s0)
.NB0f1a11f0:
/*  f1a11f0:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f1a11f4:	03227021 */ 	addu	$t6,$t9,$v0
/*  f1a11f8:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f1a11fc:	01cd6023 */ 	subu	$t4,$t6,$t5
/*  f1a1200:	afac0094 */ 	sw	$t4,0x94($sp)
.NB0f1a1204:
/*  f1a1204:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f1a1208:	25580008 */ 	addiu	$t8,$t2,0x8
/*  f1a120c:	0c002f77 */ 	jal	0xbddc
/*  f1a1210:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f1a1214:	0c002f7b */ 	jal	0xbdec
/*  f1a1218:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f1a121c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a1220:	3c198008 */ 	lui	$t9,0x8008
/*  f1a1224:	8f392374 */ 	lw	$t9,0x2374($t9)
/*  f1a1228:	8def2378 */ 	lw	$t7,0x2378($t7)
/*  f1a122c:	87ae0040 */ 	lh	$t6,0x40($sp)
/*  f1a1230:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a1234:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a1238:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f1a123c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a1240:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a1244:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a1248:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f1a124c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1a1250:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1a1254:	8fa70088 */ 	lw	$a3,0x88($sp)
/*  f1a1258:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a125c:	0fc541a6 */ 	jal	0xf150698
/*  f1a1260:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1a1264:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f1a1268:	0fc68338 */ 	jal	0xf1a0ce0
/*  f1a126c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1270:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1a1274:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f1a1278:	3c078008 */ 	lui	$a3,0x8008
/*  f1a127c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f1a1280:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f1a1284:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f1a1288:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1a128c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a1290:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a1294:	0fc54655 */ 	jal	0xf151954
/*  f1a1298:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a129c:	8fac008c */ 	lw	$t4,0x8c($sp)
/*  f1a12a0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1a12a4:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f1a12a8:	15810005 */ 	bne	$t4,$at,.NB0f1a12c0
/*  f1a12ac:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f1a12b0:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1a12b4:	25580040 */ 	addiu	$t8,$t2,0x40
/*  f1a12b8:	10000006 */ 	beqz	$zero,.NB0f1a12d4
/*  f1a12bc:	afb80094 */ 	sw	$t8,0x94($sp)
.NB0f1a12c0:
/*  f1a12c0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1a12c4:	000e6843 */ 	sra	$t5,$t6,0x1
/*  f1a12c8:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f1a12cc:	016d6023 */ 	subu	$t4,$t3,$t5
/*  f1a12d0:	afac0094 */ 	sw	$t4,0x94($sp)
.NB0f1a12d4:
/*  f1a12d4:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f1a12d8:	25580019 */ 	addiu	$t8,$t2,0x19
/*  f1a12dc:	0c002f77 */ 	jal	0xbddc
/*  f1a12e0:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f1a12e4:	0c002f7b */ 	jal	0xbdec
/*  f1a12e8:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f1a12ec:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1a12f0:	3c198008 */ 	lui	$t9,0x8008
/*  f1a12f4:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f1a12f8:	8def2370 */ 	lw	$t7,0x2370($t7)
/*  f1a12fc:	87ab0040 */ 	lh	$t3,0x40($sp)
/*  f1a1300:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a1304:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a1308:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f1a130c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a1310:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1a1314:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1a1318:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f1a131c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1a1320:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1a1324:	8fa70088 */ 	lw	$a3,0x88($sp)
/*  f1a1328:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f1a132c:	0fc541a6 */ 	jal	0xf150698
/*  f1a1330:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1a1334:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f1a1338:	0fc537a0 */ 	jal	0xf14de80
/*  f1a133c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a1340:	10000003 */ 	beqz	$zero,.NB0f1a1350
/*  f1a1344:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f1a1348:
/*  f1a1348:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a134c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f1a1350:
/*  f1a1350:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1a1354:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1a1358:	03e00008 */ 	jr	$ra
/*  f1a135c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel ciHangarHolographMenuDialog
.late_rodata
glabel var7f1b99d4
.word 0x3a83126f
glabel var7f1b99d8
.word 0x3c23d70a
.text
/*  f1a737c:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a7380:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a7384:	00803025 */ 	or	$a2,$a0,$zero
/*  f1a7388:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a738c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a7390:	3c048009 */ 	lui	$a0,%hi(g_HangarBioSlot)
/*  f1a7394:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a7398:	90848964 */ 	lbu	$a0,%lo(g_HangarBioSlot)($a0)
/*  f1a739c:	0fc685db */ 	jal	ciGetHangarBioIndexBySlot
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
/*  f1a73f0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f1a73f4:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a73f8:	10c10051 */ 	beq	$a2,$at,.L0f1a7540
/*  f1a73fc:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a7400:	10c10019 */ 	beq	$a2,$at,.L0f1a7468
/*  f1a7404:	00000000 */ 	nop
/*  f1a7408:	1000004e */ 	b	.L0f1a7544
/*  f1a740c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7410:
/*  f1a7410:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f1a7414:	44800000 */ 	mtc1	$zero,$f0
/*  f1a7418:	3c0a800a */ 	lui	$t2,%hi(g_Menus)
/*  f1a741c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a7420:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7424:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a7428:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a742c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a7430:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7434:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a7438:	254ae000 */ 	addiu	$t2,$t2,%lo(g_Menus)
/*  f1a743c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a7440:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a7444:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a7448:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a744c:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a7450:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a7454:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a7458:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a745c:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7460:	10000037 */ 	b	.L0f1a7540
/*  f1a7464:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.L0f1a7468:
/*  f1a7468:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f1a746c:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f1a7470:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f1a7474:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
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
/*  f1a74e8:	00000000 */ 	nop
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
/*  f1a7524:	3c01800a */ 	lui	$at,%hi(g_Vars+0x10)
/*  f1a7528:	c4249fc4 */ 	lwc1	$f4,%lo(g_Vars+0x10)($at)
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
/*  f1a7550:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel ciHangarHolographMenuDialog
.late_rodata
glabel var7f1b99d4
.word 0x3a83126f
glabel var7f1b99d8
.word 0x3c23d70a
.text
/*  f1a737c:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1a7380:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f1a7384:	00803025 */ 	or	$a2,$a0,$zero
/*  f1a7388:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f1a738c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a7390:	3c048009 */ 	lui	$a0,%hi(g_HangarBioSlot)
/*  f1a7394:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1a7398:	90848964 */ 	lbu	$a0,%lo(g_HangarBioSlot)($a0)
/*  f1a739c:	0fc685db */ 	jal	ciGetHangarBioIndexBySlot
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
/*  f1a73f0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f1a73f4:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1a73f8:	10c10051 */ 	beq	$a2,$at,.L0f1a7540
/*  f1a73fc:	24010066 */ 	addiu	$at,$zero,0x66
/*  f1a7400:	10c10019 */ 	beq	$a2,$at,.L0f1a7468
/*  f1a7404:	00000000 */ 	nop
/*  f1a7408:	1000004e */ 	b	.L0f1a7544
/*  f1a740c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a7410:
/*  f1a7410:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f1a7414:	44800000 */ 	mtc1	$zero,$f0
/*  f1a7418:	3c0a800a */ 	lui	$t2,%hi(g_Menus)
/*  f1a741c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1a7420:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7424:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1a7428:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1a742c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f1a7430:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1a7434:	00094900 */ 	sll	$t1,$t1,0x4
/*  f1a7438:	254ae000 */ 	addiu	$t2,$t2,%lo(g_Menus)
/*  f1a743c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f1a7440:	e4600d88 */ 	swc1	$f0,0xd88($v1)
/*  f1a7444:	e4600d60 */ 	swc1	$f0,0xd60($v1)
/*  f1a7448:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f1a744c:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f1a7450:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f1a7454:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f1a7458:	e4600d7c */ 	swc1	$f0,0xd7c($v1)
/*  f1a745c:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f1a7460:	10000037 */ 	b	.L0f1a7540
/*  f1a7464:	e4600d5c */ 	swc1	$f0,0xd5c($v1)
.L0f1a7468:
/*  f1a7468:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f1a746c:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f1a7470:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f1a7474:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
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
/*  f1a74e8:	00000000 */ 	nop
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
/*  f1a7524:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4)
/*  f1a7528:	c4249fc4 */ 	lwc1	$f4,%lo(g_Vars+0x4)($at)
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
/*  f1a7550:	00000000 */ 	nop
);
#endif

s8 var800897c4[] = {-73, 0, 5, 0};
u32 var800897c8 = 0x0400ff00;

struct hoverprop hoverprops[] = {
	// File ID, Y offset, size
	{ FILE_PDROPSHIP,       7,   8    },
	{ FILE_PHOVERCRATE1,    -5,  600  },
	{ FILE_PHOVBIKE,        -10, 50   },
	{ FILE_PHOOVERBOT,      -20, 1000 },
	{ FILE_PDD_HOVERCOPTER, 35,  30   },
	{ FILE_CCHICROB,        0,   70   },
	{ FILE_PA51INTERCEPTOR, -30, 500  },
	{ FILE_PELVIS_SAUCER,   0,   15   },
	{ FILE_PSK_SHUTTLE,     0,   10   },
};

// Can't match the 4bc part
//s32 ciHangarHolographMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
//{
//	s32 index = ciGetHangarBioIndexBySlot(g_HangarBioSlot);
//
//	if (index >= 14) {
//		struct hoverprop props[9] = hoverprops;
//		static s8 tmp[] = {0xb7, 0, 5, 0};
//
//		switch (operation) {
//		case MENUOP_OPEN:
//			g_Menus[g_MpPlayerNum].unkd88 = 0;
//			g_Menus[g_MpPlayerNum].unkd60 = 0;
//			g_Menus[g_MpPlayerNum].unkd8c = 0;
//			g_Menus[g_MpPlayerNum].unkd64 = 0;
//			g_Menus[g_MpPlayerNum].unkd78 = 0;
//			g_Menus[g_MpPlayerNum].unkd50 = 0;
//			g_Menus[g_MpPlayerNum].unkd7c = 0;
//			g_Menus[g_MpPlayerNum].unkd54 = 0;
//			g_Menus[g_MpPlayerNum].unkd5c = 0;
//			break;
//		case MENUOP_CLOSE:
//			break;
//		case MENUOP_TICK:
//			if (g_Menus[g_MpPlayerNum].curframe && g_Menus[g_MpPlayerNum].curframe->dialog == dialog) {
//				// 4bc
//				index -= 14;
//				g_Menus[g_MpPlayerNum].unkd54 = props[index].y_offset;
//				g_Menus[g_MpPlayerNum].unkd84 = props[index].size * 0.001f;
//				g_Menus[g_MpPlayerNum].unkd7c = props[index].y_offset;
//				g_Menus[g_MpPlayerNum].unk84c = props[index].fileid;
//				g_Menus[g_MpPlayerNum].unkd8c = g_Menus[g_MpPlayerNum].unkd64 + 0.01f * g_Vars.diffframe60f;
//				g_Menus[g_MpPlayerNum].unkd64 += 0.01f * g_Vars.diffframe60f;
//				g_Menus[g_MpPlayerNum].partvisibility = tmp;
//			}
//			break;
//		}
//	}
//
//	return 0;
//}

struct menudialog *ciGetFrWeaponListMenuDialog(void)
{
	return &g_FrWeaponListMenuDialog;
}

struct menuitem g_HangarDetailsMenuItems[] = {
	{ MENUITEMTYPE_MODEL,      0,                     0x00200002, 0x00000104,    0x0000002c, menuhandler001a6ea4 },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000002, 0x00000000,    0x00000000, NULL                },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HANGARBIO, 0x00000000, 0x00000104,    0x0000005a, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000002, 0x00000000,    0x00000000, NULL                },
	{ MENUITEMTYPE_LABEL,      0,                     0x00000022, L_MPMENU_414, 0x00000000, NULL                }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                     0x00000000, 0x00000000,    0x00000000, NULL                },
};

struct menuitem g_HangarVehicleHolographMenuItems[] = {
	{ MENUITEMTYPE_MODEL,       0, 0x00000002, 0x00000104, 0x0000006e, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU_414, 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_HangarVehicleHolographMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_471, // "Holograph"
	g_HangarVehicleHolographMenuItems,
	ciHangarHolographMenuDialog,
	0x00000202,
	NULL,
};

struct menudialog g_HangarVehicleDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&bioMenuTextName,
	g_HangarDetailsMenuItems,
	NULL,
	0x00000202,
	&g_HangarVehicleHolographMenuDialog,
};

struct menudialog g_HangarLocationDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&bioMenuTextName,
	g_HangarDetailsMenuItems,
	NULL,
	0x00000202,
	NULL,
};

struct menuitem g_HangarListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, ciHangarInformationMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_HangarListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_415, // "Hangar Information"
	g_HangarListMenuItems,
	NULL,
	0x00000000,
	NULL,
};
