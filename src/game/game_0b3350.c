#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/game_0b3350.h"
#include "game/game_127910.h"
#include "game/room.h"
#include "game/texture.h"
#include "game/game_173a00.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

s32 func0f0b3350(s32 value)
{
	if (value < 2) {
		return 0;
	}

	if (value < 3) {
		return 1;
	}

	if (value < 5) {
		return 2;
	}

	if (value < 9) {
		return 3;
	}

	if (value < 17) {
		return 4;
	}

	if (value < 33) {
		return 5;
	}

	if (value < 65) {
		return 6;
	}

	if (value < 129) {
		return 7;
	}

	return 8;
}

GLOBAL_ASM(
glabel func0f0b33f8
/*  f0b33f8:	1cc00002 */ 	bgtz	$a2,.L0f0b3404
/*  f0b33fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b3400:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b3404:
/*  f0b3404:	18c00016 */ 	blez	$a2,.L0f0b3460
/*  f0b3408:	248e000f */ 	addiu	$t6,$a0,0xf
.L0f0b340c:
/*  f0b340c:	05c10003 */ 	bgez	$t6,.L0f0b341c
/*  f0b3410:	000e7903 */ 	sra	$t7,$t6,0x4
/*  f0b3414:	25c1000f */ 	addiu	$at,$t6,0xf
/*  f0b3418:	00017903 */ 	sra	$t7,$at,0x4
.L0f0b341c:
/*  f0b341c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0b3420:	03050019 */ 	multu	$t8,$a1
/*  f0b3424:	28810002 */ 	slti	$at,$a0,0x2
/*  f0b3428:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0b342c:	00044043 */ 	sra	$t0,$a0,0x1
/*  f0b3430:	00054843 */ 	sra	$t1,$a1,0x1
/*  f0b3434:	0000c812 */ 	mflo	$t9
/*  f0b3438:	00791821 */ 	addu	$v1,$v1,$t9
/*  f0b343c:	54200003 */ 	bnezl	$at,.L0f0b344c
/*  f0b3440:	28a10002 */ 	slti	$at,$a1,0x2
/*  f0b3444:	01002025 */ 	or	$a0,$t0,$zero
/*  f0b3448:	28a10002 */ 	slti	$at,$a1,0x2
.L0f0b344c:
/*  f0b344c:	14200002 */ 	bnez	$at,.L0f0b3458
/*  f0b3450:	00000000 */ 	nop
/*  f0b3454:	01202825 */ 	or	$a1,$t1,$zero
.L0f0b3458:
/*  f0b3458:	5cc0ffec */ 	bgtzl	$a2,.L0f0b340c
/*  f0b345c:	248e000f */ 	addiu	$t6,$a0,0xf
.L0f0b3460:
/*  f0b3460:	03e00008 */ 	jr	$ra
/*  f0b3464:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0b3468
/*  f0b3468:	1cc00002 */ 	bgtz	$a2,.L0f0b3474
/*  f0b346c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b3470:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b3474:
/*  f0b3474:	18c00016 */ 	blez	$a2,.L0f0b34d0
/*  f0b3478:	248e0007 */ 	addiu	$t6,$a0,0x7
.L0f0b347c:
/*  f0b347c:	05c10003 */ 	bgez	$t6,.L0f0b348c
/*  f0b3480:	000e78c3 */ 	sra	$t7,$t6,0x3
/*  f0b3484:	25c10007 */ 	addiu	$at,$t6,0x7
/*  f0b3488:	000178c3 */ 	sra	$t7,$at,0x3
.L0f0b348c:
/*  f0b348c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0b3490:	03050019 */ 	multu	$t8,$a1
/*  f0b3494:	28810002 */ 	slti	$at,$a0,0x2
/*  f0b3498:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0b349c:	00044043 */ 	sra	$t0,$a0,0x1
/*  f0b34a0:	00054843 */ 	sra	$t1,$a1,0x1
/*  f0b34a4:	0000c812 */ 	mflo	$t9
/*  f0b34a8:	00791821 */ 	addu	$v1,$v1,$t9
/*  f0b34ac:	54200003 */ 	bnezl	$at,.L0f0b34bc
/*  f0b34b0:	28a10002 */ 	slti	$at,$a1,0x2
/*  f0b34b4:	01002025 */ 	or	$a0,$t0,$zero
/*  f0b34b8:	28a10002 */ 	slti	$at,$a1,0x2
.L0f0b34bc:
/*  f0b34bc:	14200002 */ 	bnez	$at,.L0f0b34c8
/*  f0b34c0:	00000000 */ 	nop
/*  f0b34c4:	01202825 */ 	or	$a1,$t1,$zero
.L0f0b34c8:
/*  f0b34c8:	5cc0ffec */ 	bgtzl	$a2,.L0f0b347c
/*  f0b34cc:	248e0007 */ 	addiu	$t6,$a0,0x7
.L0f0b34d0:
/*  f0b34d0:	03e00008 */ 	jr	$ra
/*  f0b34d4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0b34d8
/*  f0b34d8:	1cc00002 */ 	bgtz	$a2,.L0f0b34e4
/*  f0b34dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b34e0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b34e4:
/*  f0b34e4:	18c00016 */ 	blez	$a2,.L0f0b3540
/*  f0b34e8:	248e0003 */ 	addiu	$t6,$a0,0x3
.L0f0b34ec:
/*  f0b34ec:	05c10003 */ 	bgez	$t6,.L0f0b34fc
/*  f0b34f0:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f0b34f4:	25c10003 */ 	addiu	$at,$t6,0x3
/*  f0b34f8:	00017883 */ 	sra	$t7,$at,0x2
.L0f0b34fc:
/*  f0b34fc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0b3500:	03050019 */ 	multu	$t8,$a1
/*  f0b3504:	28810002 */ 	slti	$at,$a0,0x2
/*  f0b3508:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0b350c:	00044043 */ 	sra	$t0,$a0,0x1
/*  f0b3510:	00054843 */ 	sra	$t1,$a1,0x1
/*  f0b3514:	0000c812 */ 	mflo	$t9
/*  f0b3518:	00791821 */ 	addu	$v1,$v1,$t9
/*  f0b351c:	54200003 */ 	bnezl	$at,.L0f0b352c
/*  f0b3520:	28a10002 */ 	slti	$at,$a1,0x2
/*  f0b3524:	01002025 */ 	or	$a0,$t0,$zero
/*  f0b3528:	28a10002 */ 	slti	$at,$a1,0x2
.L0f0b352c:
/*  f0b352c:	14200002 */ 	bnez	$at,.L0f0b3538
/*  f0b3530:	00000000 */ 	nop
/*  f0b3534:	01202825 */ 	or	$a1,$t1,$zero
.L0f0b3538:
/*  f0b3538:	5cc0ffec */ 	bgtzl	$a2,.L0f0b34ec
/*  f0b353c:	248e0003 */ 	addiu	$t6,$a0,0x3
.L0f0b3540:
/*  f0b3540:	03e00008 */ 	jr	$ra
/*  f0b3544:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0b3548
/*  f0b3548:	1cc00002 */ 	bgtz	$a2,.L0f0b3554
/*  f0b354c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b3550:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b3554:
/*  f0b3554:	18c00016 */ 	blez	$a2,.L0f0b35b0
/*  f0b3558:	248e0003 */ 	addiu	$t6,$a0,0x3
.L0f0b355c:
/*  f0b355c:	05c10003 */ 	bgez	$t6,.L0f0b356c
/*  f0b3560:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f0b3564:	25c10003 */ 	addiu	$at,$t6,0x3
/*  f0b3568:	00017883 */ 	sra	$t7,$at,0x2
.L0f0b356c:
/*  f0b356c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0b3570:	03050019 */ 	multu	$t8,$a1
/*  f0b3574:	28810002 */ 	slti	$at,$a0,0x2
/*  f0b3578:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0b357c:	00044043 */ 	sra	$t0,$a0,0x1
/*  f0b3580:	00054843 */ 	sra	$t1,$a1,0x1
/*  f0b3584:	0000c812 */ 	mflo	$t9
/*  f0b3588:	00791821 */ 	addu	$v1,$v1,$t9
/*  f0b358c:	54200003 */ 	bnezl	$at,.L0f0b359c
/*  f0b3590:	28a10002 */ 	slti	$at,$a1,0x2
/*  f0b3594:	01002025 */ 	or	$a0,$t0,$zero
/*  f0b3598:	28a10002 */ 	slti	$at,$a1,0x2
.L0f0b359c:
/*  f0b359c:	14200002 */ 	bnez	$at,.L0f0b35a8
/*  f0b35a0:	00000000 */ 	nop
/*  f0b35a4:	01202825 */ 	or	$a1,$t1,$zero
.L0f0b35a8:
/*  f0b35a8:	5cc0ffec */ 	bgtzl	$a2,.L0f0b355c
/*  f0b35ac:	248e0003 */ 	addiu	$t6,$a0,0x3
.L0f0b35b0:
/*  f0b35b0:	03e00008 */ 	jr	$ra
/*  f0b35b4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0b35b8
/*  f0b35b8:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f0b35bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b35c0:	14c80078 */ 	bne	$a2,$t0,.L0f0b37a4
/*  f0b35c4:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0b35c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b35cc:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b35d0:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0b35d4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0b35d8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0b35dc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0b35e0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0b35e4:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f0b35e8:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0b35ec:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f0b35f0:	8fb80004 */ 	lw	$t8,0x4($sp)
/*  f0b35f4:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b35f8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b35fc:	13080007 */ 	beq	$t8,$t0,.L0f0b361c
/*  f0b3600:	00000000 */ 	nop
/*  f0b3604:	13010023 */ 	beq	$t8,$at,.L0f0b3694
/*  f0b3608:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b360c:	1301003f */ 	beq	$t8,$at,.L0f0b370c
/*  f0b3610:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0b3614:	13010050 */ 	beq	$t8,$at,.L0f0b3758
/*  f0b3618:	00000000 */ 	nop
.L0f0b361c:
/*  f0b361c:	10e00015 */ 	beqz	$a3,.L0f0b3674
/*  f0b3620:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3624:	28e10002 */ 	slti	$at,$a3,0x2
/*  f0b3628:	1420000a */ 	bnez	$at,.L0f0b3654
/*  f0b362c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3630:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3634:	3c19b900 */ 	lui	$t9,0xb900
/*  f0b3638:	3c090055 */ 	lui	$t1,0x55
/*  f0b363c:	35292d58 */ 	ori	$t1,$t1,0x2d58
/*  f0b3640:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0b3644:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0b3648:	ac690004 */ 	sw	$t1,0x4($v1)
/*  f0b364c:	100000cc */ 	b	.L0f0b3980
/*  f0b3650:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3654:
/*  f0b3654:	3c0ab900 */ 	lui	$t2,0xb900
/*  f0b3658:	3c0b0055 */ 	lui	$t3,0x55
/*  f0b365c:	356b2078 */ 	ori	$t3,$t3,0x2078
/*  f0b3660:	354a031d */ 	ori	$t2,$t2,0x31d
/*  f0b3664:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0b3668:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0b366c:	100000c4 */ 	b	.L0f0b3980
/*  f0b3670:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3674:
/*  f0b3674:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0b3678:	3c0d0055 */ 	lui	$t5,0x55
/*  f0b367c:	35ad2048 */ 	ori	$t5,$t5,0x2048
/*  f0b3680:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0b3684:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0b3688:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f0b368c:	100000bc */ 	b	.L0f0b3980
/*  f0b3690:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3694:
/*  f0b3694:	10e00015 */ 	beqz	$a3,.L0f0b36ec
/*  f0b3698:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b369c:	28e10002 */ 	slti	$at,$a3,0x2
/*  f0b36a0:	1420000a */ 	bnez	$at,.L0f0b36cc
/*  f0b36a4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b36a8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b36ac:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0b36b0:	3c0f0050 */ 	lui	$t7,0x50
/*  f0b36b4:	35ef4dd8 */ 	ori	$t7,$t7,0x4dd8
/*  f0b36b8:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0b36bc:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0b36c0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0b36c4:	100000ae */ 	b	.L0f0b3980
/*  f0b36c8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b36cc:
/*  f0b36cc:	3c18b900 */ 	lui	$t8,0xb900
/*  f0b36d0:	3c190050 */ 	lui	$t9,0x50
/*  f0b36d4:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f0b36d8:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0b36dc:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0b36e0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0b36e4:	100000a6 */ 	b	.L0f0b3980
/*  f0b36e8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b36ec:
/*  f0b36ec:	3c09b900 */ 	lui	$t1,0xb900
/*  f0b36f0:	3c0a0050 */ 	lui	$t2,0x50
/*  f0b36f4:	354a41c8 */ 	ori	$t2,$t2,0x41c8
/*  f0b36f8:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0b36fc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0b3700:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f0b3704:	1000009e */ 	b	.L0f0b3980
/*  f0b3708:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b370c:
/*  f0b370c:	10e0000a */ 	beqz	$a3,.L0f0b3738
/*  f0b3710:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3714:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3718:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0b371c:	3c0c0055 */ 	lui	$t4,0x55
/*  f0b3720:	358c3078 */ 	ori	$t4,$t4,0x3078
/*  f0b3724:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f0b3728:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0b372c:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f0b3730:	10000093 */ 	b	.L0f0b3980
/*  f0b3734:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3738:
/*  f0b3738:	3c0db900 */ 	lui	$t5,0xb900
/*  f0b373c:	3c0e0055 */ 	lui	$t6,0x55
/*  f0b3740:	35ce3048 */ 	ori	$t6,$t6,0x3048
/*  f0b3744:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f0b3748:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0b374c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0b3750:	1000008b */ 	b	.L0f0b3980
/*  f0b3754:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3758:
/*  f0b3758:	10e0000a */ 	beqz	$a3,.L0f0b3784
/*  f0b375c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3760:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3764:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0b3768:	3c180050 */ 	lui	$t8,0x50
/*  f0b376c:	37184b50 */ 	ori	$t8,$t8,0x4b50
/*  f0b3770:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0b3774:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b3778:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0b377c:	10000080 */ 	b	.L0f0b3980
/*  f0b3780:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3784:
/*  f0b3784:	3c19b900 */ 	lui	$t9,0xb900
/*  f0b3788:	3c090050 */ 	lui	$t1,0x50
/*  f0b378c:	35294340 */ 	ori	$t1,$t1,0x4340
/*  f0b3790:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0b3794:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0b3798:	ac690004 */ 	sw	$t1,0x4($v1)
/*  f0b379c:	10000078 */ 	b	.L0f0b3980
/*  f0b37a0:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b37a4:
/*  f0b37a4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b37a8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b37ac:	3c0ae700 */ 	lui	$t2,0xe700
/*  f0b37b0:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0b37b4:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0b37b8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0b37bc:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0b37c0:	356b1402 */ 	ori	$t3,$t3,0x1402
/*  f0b37c4:	3c0c0010 */ 	lui	$t4,0x10
/*  f0b37c8:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f0b37cc:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f0b37d0:	8fad0004 */ 	lw	$t5,0x4($sp)
/*  f0b37d4:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b37d8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b37dc:	11a80007 */ 	beq	$t5,$t0,.L0f0b37fc
/*  f0b37e0:	00000000 */ 	nop
/*  f0b37e4:	11a10023 */ 	beq	$t5,$at,.L0f0b3874
/*  f0b37e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b37ec:	11a1003f */ 	beq	$t5,$at,.L0f0b38ec
/*  f0b37f0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0b37f4:	11a10050 */ 	beq	$t5,$at,.L0f0b3938
/*  f0b37f8:	00000000 */ 	nop
.L0f0b37fc:
/*  f0b37fc:	10e00015 */ 	beqz	$a3,.L0f0b3854
/*  f0b3800:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3804:	28e10002 */ 	slti	$at,$a3,0x2
/*  f0b3808:	1420000a */ 	bnez	$at,.L0f0b3834
/*  f0b380c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3810:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3814:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0b3818:	3c0f0c19 */ 	lui	$t7,0xc19
/*  f0b381c:	35ef2d58 */ 	ori	$t7,$t7,0x2d58
/*  f0b3820:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0b3824:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0b3828:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0b382c:	10000054 */ 	b	.L0f0b3980
/*  f0b3830:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3834:
/*  f0b3834:	3c18b900 */ 	lui	$t8,0xb900
/*  f0b3838:	3c190c19 */ 	lui	$t9,0xc19
/*  f0b383c:	37392078 */ 	ori	$t9,$t9,0x2078
/*  f0b3840:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0b3844:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0b3848:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0b384c:	1000004c */ 	b	.L0f0b3980
/*  f0b3850:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3854:
/*  f0b3854:	3c09b900 */ 	lui	$t1,0xb900
/*  f0b3858:	3c0a0c19 */ 	lui	$t2,0xc19
/*  f0b385c:	354a2048 */ 	ori	$t2,$t2,0x2048
/*  f0b3860:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0b3864:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0b3868:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f0b386c:	10000044 */ 	b	.L0f0b3980
/*  f0b3870:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3874:
/*  f0b3874:	10e00015 */ 	beqz	$a3,.L0f0b38cc
/*  f0b3878:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b387c:	28e10002 */ 	slti	$at,$a3,0x2
/*  f0b3880:	1420000a */ 	bnez	$at,.L0f0b38ac
/*  f0b3884:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3888:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b388c:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0b3890:	3c0c0c18 */ 	lui	$t4,0xc18
/*  f0b3894:	358c4dd8 */ 	ori	$t4,$t4,0x4dd8
/*  f0b3898:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f0b389c:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0b38a0:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f0b38a4:	10000036 */ 	b	.L0f0b3980
/*  f0b38a8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b38ac:
/*  f0b38ac:	3c0db900 */ 	lui	$t5,0xb900
/*  f0b38b0:	3c0e0c18 */ 	lui	$t6,0xc18
/*  f0b38b4:	35ce49d8 */ 	ori	$t6,$t6,0x49d8
/*  f0b38b8:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f0b38bc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0b38c0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0b38c4:	1000002e */ 	b	.L0f0b3980
/*  f0b38c8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b38cc:
/*  f0b38cc:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0b38d0:	3c180c18 */ 	lui	$t8,0xc18
/*  f0b38d4:	371841c8 */ 	ori	$t8,$t8,0x41c8
/*  f0b38d8:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0b38dc:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b38e0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0b38e4:	10000026 */ 	b	.L0f0b3980
/*  f0b38e8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b38ec:
/*  f0b38ec:	10e0000a */ 	beqz	$a3,.L0f0b3918
/*  f0b38f0:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b38f4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b38f8:	3c19b900 */ 	lui	$t9,0xb900
/*  f0b38fc:	3c090c19 */ 	lui	$t1,0xc19
/*  f0b3900:	35293078 */ 	ori	$t1,$t1,0x3078
/*  f0b3904:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0b3908:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0b390c:	ac690004 */ 	sw	$t1,0x4($v1)
/*  f0b3910:	1000001b */ 	b	.L0f0b3980
/*  f0b3914:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3918:
/*  f0b3918:	3c0ab900 */ 	lui	$t2,0xb900
/*  f0b391c:	3c0b0c19 */ 	lui	$t3,0xc19
/*  f0b3920:	356b3048 */ 	ori	$t3,$t3,0x3048
/*  f0b3924:	354a031d */ 	ori	$t2,$t2,0x31d
/*  f0b3928:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0b392c:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0b3930:	10000013 */ 	b	.L0f0b3980
/*  f0b3934:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3938:
/*  f0b3938:	10e0000a */ 	beqz	$a3,.L0f0b3964
/*  f0b393c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3940:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b3944:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0b3948:	3c0d0c18 */ 	lui	$t5,0xc18
/*  f0b394c:	35ad4b50 */ 	ori	$t5,$t5,0x4b50
/*  f0b3950:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0b3954:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0b3958:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f0b395c:	10000008 */ 	b	.L0f0b3980
/*  f0b3960:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3964:
/*  f0b3964:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0b3968:	3c0f0c18 */ 	lui	$t7,0xc18
/*  f0b396c:	35ef4340 */ 	ori	$t7,$t7,0x4340
/*  f0b3970:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0b3974:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0b3978:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0b397c:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3980:
/*  f0b3980:	03e00008 */ 	jr	$ra
/*  f0b3984:	ac820000 */ 	sw	$v0,0x0($a0)
);

GLOBAL_ASM(
glabel func0f0b3988
/*  f0b3988:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b398c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b3990:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0b3994:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b3998:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b399c:	2dc10daf */ 	sltiu	$at,$t6,0xdaf
/*  f0b39a0:	50200004 */ 	beqzl	$at,.L0f0b39b4
/*  f0b39a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b39a8:	0fc5cd0d */ 	jal	func0f173434
/*  f0b39ac:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b39b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b39b4:
/*  f0b39b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b39b8:	03e00008 */ 	jr	$ra
/*  f0b39bc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b39c0
/*  f0b39c0:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f0b39c4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b39c8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0b39cc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0b39d0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0b39d4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0b39d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0b39dc:	afa40170 */ 	sw	$a0,0x170($sp)
/*  f0b39e0:	afa50174 */ 	sw	$a1,0x174($sp)
/*  f0b39e4:	afa60178 */ 	sw	$a2,0x178($sp)
/*  f0b39e8:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0b39ec:	00e08825 */ 	or	$s1,$a3,$zero
/*  f0b39f0:	14a00025 */ 	bnez	$a1,.L0f0b3a88
/*  f0b39f4:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b39f8:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0b39fc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b3a00:	0fc2cd6e */ 	jal	func0f0b35b8
/*  f0b3a04:	27a40168 */ 	addiu	$a0,$sp,0x168
/*  f0b3a08:	2a210002 */ 	slti	$at,$s1,0x2
/*  f0b3a0c:	1420000d */ 	bnez	$at,.L0f0b3a44
/*  f0b3a10:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b3a14:	8fa20168 */ 	lw	$v0,0x168($sp)
/*  f0b3a18:	322e00ff */ 	andi	$t6,$s1,0xff
/*  f0b3a1c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f0b3a20:	3c01bb00 */ 	lui	$at,0xbb00
/*  f0b3a24:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0b3a28:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3a2c:	01e1c025 */ 	or	$t8,$t7,$at
/*  f0b3a30:	37190001 */ 	ori	$t9,$t8,0x1
/*  f0b3a34:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0b3a38:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0b3a3c:	10000008 */ 	b	.L0f0b3a60
/*  f0b3a40:	ac590000 */ 	sw	$t9,0x0($v0)
.L0f0b3a44:
/*  f0b3a44:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0b3a48:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b3a4c:	3c18bb00 */ 	lui	$t8,0xbb00
/*  f0b3a50:	37180001 */ 	ori	$t8,$t8,0x1
/*  f0b3a54:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0b3a58:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0b3a5c:	add80000 */ 	sw	$t8,0x0($t6)
.L0f0b3a60:
/*  f0b3a60:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b3a64:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f0b3a68:	3c18fffe */ 	lui	$t8,0xfffe
/*  f0b3a6c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0b3a70:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b3a74:	3718793c */ 	ori	$t8,$t8,0x793c
/*  f0b3a78:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0b3a7c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0b3a80:	100003a7 */ 	b	.L0f0b4920
/*  f0b3a84:	adb80004 */ 	sw	$t8,0x4($t5)
.L0f0b3a88:
/*  f0b3a88:	8fb90174 */ 	lw	$t9,0x174($sp)
/*  f0b3a8c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0b3a90:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b3a94:	8f2d0000 */ 	lw	$t5,0x0($t9)
/*  f0b3a98:	93330004 */ 	lbu	$s3,0x4($t9)
/*  f0b3a9c:	93320005 */ 	lbu	$s2,0x5($t9)
/*  f0b3aa0:	2da10daf */ 	sltiu	$at,$t5,0xdaf
/*  f0b3aa4:	10200004 */ 	beqz	$at,.L0f0b3ab8
/*  f0b3aa8:	03202025 */ 	or	$a0,$t9,$zero
/*  f0b3aac:	8fa60188 */ 	lw	$a2,0x188($sp)
/*  f0b3ab0:	0fc5cd0d */ 	jal	func0f173434
/*  f0b3ab4:	00003825 */ 	or	$a3,$zero,$zero
.L0f0b3ab8:
/*  f0b3ab8:	8fae0174 */ 	lw	$t6,0x174($sp)
/*  f0b3abc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b3ac0:	3c0d800b */ 	lui	$t5,%hi(var800ab560)
/*  f0b3ac4:	91cf000b */ 	lbu	$t7,0xb($t6)
/*  f0b3ac8:	55e10027 */ 	bnel	$t7,$at,.L0f0b3b68
/*  f0b3acc:	8fad0174 */ 	lw	$t5,0x174($sp)
/*  f0b3ad0:	8dc20000 */ 	lw	$v0,0x0($t6)
/*  f0b3ad4:	8dadb560 */ 	lw	$t5,%lo(var800ab560)($t5)
/*  f0b3ad8:	3c018000 */ 	lui	$at,0x8000
/*  f0b3adc:	0041c025 */ 	or	$t8,$v0,$at
/*  f0b3ae0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0b3ae4:	01cd8023 */ 	subu	$s0,$t6,$t5
/*  f0b3ae8:	0201001a */ 	div	$zero,$s0,$at
/*  f0b3aec:	0000c812 */ 	mflo	$t9
/*  f0b3af0:	9703fff8 */ 	lhu	$v1,-0x8($t8)
/*  f0b3af4:	0720000b */ 	bltz	$t9,.L0f0b3b24
/*  f0b3af8:	03208025 */ 	or	$s0,$t9,$zero
/*  f0b3afc:	3c0f800b */ 	lui	$t7,%hi(var800ab558)
/*  f0b3b00:	8defb558 */ 	lw	$t7,%lo(var800ab558)($t7)
/*  f0b3b04:	3c18800b */ 	lui	$t8,%hi(var800ab55c)
/*  f0b3b08:	032f082a */ 	slt	$at,$t9,$t7
/*  f0b3b0c:	10200005 */ 	beqz	$at,.L0f0b3b24
/*  f0b3b10:	00000000 */ 	nop
/*  f0b3b14:	8f18b55c */ 	lw	$t8,%lo(var800ab55c)($t8)
/*  f0b3b18:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0b3b1c:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f0b3b20:	8db40000 */ 	lw	$s4,0x0($t5)
.L0f0b3b24:
/*  f0b3b24:	1680000f */ 	bnez	$s4,.L0f0b3b64
/*  f0b3b28:	00602025 */ 	or	$a0,$v1,$zero
/*  f0b3b2c:	0fc5cba3 */ 	jal	func0f172e8c
/*  f0b3b30:	8fa50188 */ 	lw	$a1,0x188($sp)
/*  f0b3b34:	0600000b */ 	bltz	$s0,.L0f0b3b64
/*  f0b3b38:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0b3b3c:	3c19800b */ 	lui	$t9,%hi(var800ab558)
/*  f0b3b40:	8f39b558 */ 	lw	$t9,%lo(var800ab558)($t9)
/*  f0b3b44:	3c0f800b */ 	lui	$t7,%hi(var800ab55c)
/*  f0b3b48:	0219082a */ 	slt	$at,$s0,$t9
/*  f0b3b4c:	50200006 */ 	beqzl	$at,.L0f0b3b68
/*  f0b3b50:	8fad0174 */ 	lw	$t5,0x174($sp)
/*  f0b3b54:	8defb55c */ 	lw	$t7,%lo(var800ab55c)($t7)
/*  f0b3b58:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f0b3b5c:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f0b3b60:	adc20000 */ 	sw	$v0,0x0($t6)
.L0f0b3b64:
/*  f0b3b64:	8fad0174 */ 	lw	$t5,0x174($sp)
.L0f0b3b68:
/*  f0b3b68:	91a20006 */ 	lbu	$v0,0x6($t5)
/*  f0b3b6c:	14400172 */ 	bnez	$v0,.L0f0b4138
/*  f0b3b70:	28410007 */ 	slti	$at,$v0,0x7
/*  f0b3b74:	1280000c */ 	beqz	$s4,.L0f0b3ba8
/*  f0b3b78:	8faf0174 */ 	lw	$t7,0x174($sp)
/*  f0b3b7c:	8e820008 */ 	lw	$v0,0x8($s4)
/*  f0b3b80:	30580003 */ 	andi	$t8,$v0,0x3
/*  f0b3b84:	a3b80146 */ 	sb	$t8,0x146($sp)
/*  f0b3b88:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f0b3b8c:	000286c0 */ 	sll	$s0,$v0,0x1b
/*  f0b3b90:	0010cf42 */ 	srl	$t9,$s0,0x1d
/*  f0b3b94:	333000ff */ 	andi	$s0,$t9,0xff
/*  f0b3b98:	000e6f82 */ 	srl	$t5,$t6,0x1e
/*  f0b3b9c:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f0b3ba0:	10000004 */ 	b	.L0f0b3bb4
/*  f0b3ba4:	afb90140 */ 	sw	$t9,0x140($sp)
.L0f0b3ba8:
/*  f0b3ba8:	91f80008 */ 	lbu	$t8,0x8($t7)
/*  f0b3bac:	91f00007 */ 	lbu	$s0,0x7($t7)
/*  f0b3bb0:	a3b80146 */ 	sb	$t8,0x146($sp)
.L0f0b3bb4:
/*  f0b3bb4:	93a20146 */ 	lbu	$v0,0x146($sp)
/*  f0b3bb8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0b3bbc:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b3bc0:	1040002a */ 	beqz	$v0,.L0f0b3c6c
/*  f0b3bc4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b3bc8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b3bcc:	1041001d */ 	beq	$v0,$at,.L0f0b3c44
/*  f0b3bd0:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0b3bd4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b3bd8:	10410010 */ 	beq	$v0,$at,.L0f0b3c1c
/*  f0b3bdc:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0b3be0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b3be4:	10410003 */ 	beq	$v0,$at,.L0f0b3bf4
/*  f0b3be8:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0b3bec:	10000026 */ 	b	.L0f0b3c88
/*  f0b3bf0:	8fab0138 */ 	lw	$t3,0x138($sp)
.L0f0b3bf4:
/*  f0b3bf4:	afae013c */ 	sw	$t6,0x13c($sp)
/*  f0b3bf8:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b3bfc:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b3c00:	0fc2cd52 */ 	jal	func0f0b3548
/*  f0b3c04:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b3c08:	266d0003 */ 	addiu	$t5,$s3,0x3
/*  f0b3c0c:	000dc883 */ 	sra	$t9,$t5,0x2
/*  f0b3c10:	244bffff */ 	addiu	$t3,$v0,-1
/*  f0b3c14:	1000001c */ 	b	.L0f0b3c88
/*  f0b3c18:	afb90134 */ 	sw	$t9,0x134($sp)
.L0f0b3c1c:
/*  f0b3c1c:	afaf013c */ 	sw	$t7,0x13c($sp)
/*  f0b3c20:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b3c24:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b3c28:	0fc2cd36 */ 	jal	func0f0b34d8
/*  f0b3c2c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b3c30:	26780003 */ 	addiu	$t8,$s3,0x3
/*  f0b3c34:	00187083 */ 	sra	$t6,$t8,0x2
/*  f0b3c38:	244bffff */ 	addiu	$t3,$v0,-1
/*  f0b3c3c:	10000012 */ 	b	.L0f0b3c88
/*  f0b3c40:	afae0134 */ 	sw	$t6,0x134($sp)
.L0f0b3c44:
/*  f0b3c44:	afad013c */ 	sw	$t5,0x13c($sp)
/*  f0b3c48:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b3c4c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b3c50:	0fc2cd1a */ 	jal	func0f0b3468
/*  f0b3c54:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b3c58:	26790007 */ 	addiu	$t9,$s3,0x7
/*  f0b3c5c:	001978c3 */ 	sra	$t7,$t9,0x3
/*  f0b3c60:	244bffff */ 	addiu	$t3,$v0,-1
/*  f0b3c64:	10000008 */ 	b	.L0f0b3c88
/*  f0b3c68:	afaf0134 */ 	sw	$t7,0x134($sp)
.L0f0b3c6c:
/*  f0b3c6c:	afb8013c */ 	sw	$t8,0x13c($sp)
/*  f0b3c70:	0fc2ccfe */ 	jal	func0f0b33f8
/*  f0b3c74:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b3c78:	266e000f */ 	addiu	$t6,$s3,0xf
/*  f0b3c7c:	000e6903 */ 	sra	$t5,$t6,0x4
/*  f0b3c80:	244bffff */ 	addiu	$t3,$v0,-1
/*  f0b3c84:	afad0134 */ 	sw	$t5,0x134($sp)
.L0f0b3c88:
/*  f0b3c88:	8fb90184 */ 	lw	$t9,0x184($sp)
/*  f0b3c8c:	27a40168 */ 	addiu	$a0,$sp,0x168
/*  f0b3c90:	8fa50178 */ 	lw	$a1,0x178($sp)
/*  f0b3c94:	13200063 */ 	beqz	$t9,.L0f0b3e24
/*  f0b3c98:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b3c9c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0b3ca0:	0fc2cd6e */ 	jal	func0f0b35b8
/*  f0b3ca4:	afab0138 */ 	sw	$t3,0x138($sp)
/*  f0b3ca8:	2a210002 */ 	slti	$at,$s1,0x2
/*  f0b3cac:	1420000d */ 	bnez	$at,.L0f0b3ce4
/*  f0b3cb0:	8fab0138 */ 	lw	$t3,0x138($sp)
/*  f0b3cb4:	8fa20168 */ 	lw	$v0,0x168($sp)
/*  f0b3cb8:	322e00ff */ 	andi	$t6,$s1,0xff
/*  f0b3cbc:	000e6c00 */ 	sll	$t5,$t6,0x10
/*  f0b3cc0:	3c01bb00 */ 	lui	$at,0xbb00
/*  f0b3cc4:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f0b3cc8:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b3ccc:	01a1c825 */ 	or	$t9,$t5,$at
/*  f0b3cd0:	372f0001 */ 	ori	$t7,$t9,0x1
/*  f0b3cd4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0b3cd8:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0b3cdc:	10000009 */ 	b	.L0f0b3d04
/*  f0b3ce0:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L0f0b3ce4:
/*  f0b3ce4:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b3ce8:	3c19bb00 */ 	lui	$t9,0xbb00
/*  f0b3cec:	37390001 */ 	ori	$t9,$t9,0x1
/*  f0b3cf0:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f0b3cf4:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3cf8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0b3cfc:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b3d00:	add90000 */ 	sw	$t9,0x0($t6)
.L0f0b3d04:
/*  f0b3d04:	8fb80168 */ 	lw	$t8,0x168($sp)
/*  f0b3d08:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0b3d0c:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f0b3d10:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f0b3d14:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b3d18:	02003025 */ 	or	$a2,$s0,$zero
/*  f0b3d1c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0b3d20:	1200000c */ 	beqz	$s0,.L0f0b3d54
/*  f0b3d24:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0b3d28:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b3d2c:	10c10024 */ 	beq	$a2,$at,.L0f0b3dc0
/*  f0b3d30:	8fb80140 */ 	lw	$t8,0x140($sp)
/*  f0b3d34:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b3d38:	10c10010 */ 	beq	$a2,$at,.L0f0b3d7c
/*  f0b3d3c:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b3d40:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0b3d44:	10c10016 */ 	beq	$a2,$at,.L0f0b3da0
/*  f0b3d48:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b3d4c:	10000036 */ 	b	.L0f0b3e28
/*  f0b3d50:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b3d54:
/*  f0b3d54:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f0b3d58:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0b3d5c:	3c0eff33 */ 	lui	$t6,0xff33
/*  f0b3d60:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f0b3d64:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b3d68:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0b3d6c:	37181824 */ 	ori	$t8,$t8,0x1824
/*  f0b3d70:	af380000 */ 	sw	$t8,0x0($t9)
/*  f0b3d74:	1000002b */ 	b	.L0f0b3e24
/*  f0b3d78:	af2e0004 */ 	sw	$t6,0x4($t9)
.L0f0b3d7c:
/*  f0b3d7c:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0b3d80:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f0b3d84:	3c18ff33 */ 	lui	$t8,0xff33
/*  f0b3d88:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0b3d8c:	35ef1824 */ 	ori	$t7,$t7,0x1824
/*  f0b3d90:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b3d94:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0b3d98:	10000022 */ 	b	.L0f0b3e24
/*  f0b3d9c:	adaf0000 */ 	sw	$t7,0x0($t5)
.L0f0b3da0:
/*  f0b3da0:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f0b3da4:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0b3da8:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0b3dac:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3db0:	240ff9fc */ 	addiu	$t7,$zero,-1540
/*  f0b3db4:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b3db8:	1000001a */ 	b	.L0f0b3e24
/*  f0b3dbc:	add90000 */ 	sw	$t9,0x0($t6)
.L0f0b3dc0:
/*  f0b3dc0:	34018000 */ 	dli	$at,0x8000
/*  f0b3dc4:	13010006 */ 	beq	$t8,$at,.L0f0b3de0
/*  f0b3dc8:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b3dcc:	3401c000 */ 	dli	$at,0xc000
/*  f0b3dd0:	1301000c */ 	beq	$t8,$at,.L0f0b3e04
/*  f0b3dd4:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0b3dd8:	10000013 */ 	b	.L0f0b3e28
/*  f0b3ddc:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b3de0:
/*  f0b3de0:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f0b3de4:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0b3de8:	3c0fff33 */ 	lui	$t7,0xff33
/*  f0b3dec:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0b3df0:	37391824 */ 	ori	$t9,$t9,0x1824
/*  f0b3df4:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3df8:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b3dfc:	10000009 */ 	b	.L0f0b3e24
/*  f0b3e00:	add90000 */ 	sw	$t9,0x0($t6)
.L0f0b3e04:
/*  f0b3e04:	8fb80168 */ 	lw	$t8,0x168($sp)
/*  f0b3e08:	3c19ff33 */ 	lui	$t9,0xff33
/*  f0b3e0c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0b3e10:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f0b3e14:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b3e18:	35ad1824 */ 	ori	$t5,$t5,0x1824
/*  f0b3e1c:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0b3e20:	af190004 */ 	sw	$t9,0x4($t8)
.L0f0b3e24:
/*  f0b3e24:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b3e28:
/*  f0b3e28:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f0b3e2c:	32090007 */ 	andi	$t1,$s0,0x7
/*  f0b3e30:	00097540 */ 	sll	$t6,$t1,0x15
/*  f0b3e34:	3c01fd00 */ 	lui	$at,0xfd00
/*  f0b3e38:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f0b3e3c:	308d0003 */ 	andi	$t5,$a0,0x3
/*  f0b3e40:	000d24c0 */ 	sll	$a0,$t5,0x13
/*  f0b3e44:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b3e48:	01c17825 */ 	or	$t7,$t6,$at
/*  f0b3e4c:	01e4c025 */ 	or	$t8,$t7,$a0
/*  f0b3e50:	01c04825 */ 	or	$t1,$t6,$zero
/*  f0b3e54:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0b3e58:	8fae0174 */ 	lw	$t6,0x174($sp)
/*  f0b3e5c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b3e60:	02003025 */ 	or	$a2,$s0,$zero
/*  f0b3e64:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f0b3e68:	3c080500 */ 	lui	$t0,0x500
/*  f0b3e6c:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0b3e70:	8fb9013c */ 	lw	$t9,0x13c($sp)
/*  f0b3e74:	8faf0168 */ 	lw	$t7,0x168($sp)
/*  f0b3e78:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b3e7c:	17210015 */ 	bne	$t9,$at,.L0f0b3ed4
/*  f0b3e80:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0b3e84:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b3e88:	3c0ce600 */ 	lui	$t4,0xe600
/*  f0b3e8c:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f0b3e90:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0b3e94:	8fa30168 */ 	lw	$v1,0x168($sp)
/*  f0b3e98:	3c19f300 */ 	lui	$t9,0xf300
/*  f0b3e9c:	296107ff */ 	slti	$at,$t3,0x7ff
/*  f0b3ea0:	246d0008 */ 	addiu	$t5,$v1,0x8
/*  f0b3ea4:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3ea8:	10200003 */ 	beqz	$at,.L0f0b3eb8
/*  f0b3eac:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0b3eb0:	10000002 */ 	b	.L0f0b3ebc
/*  f0b3eb4:	01603825 */ 	or	$a3,$t3,$zero
.L0f0b3eb8:
/*  f0b3eb8:	240707ff */ 	addiu	$a3,$zero,0x7ff
.L0f0b3ebc:
/*  f0b3ebc:	30ef0fff */ 	andi	$t7,$a3,0xfff
/*  f0b3ec0:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0b3ec4:	3c010700 */ 	lui	$at,0x700
/*  f0b3ec8:	03017025 */ 	or	$t6,$t8,$at
/*  f0b3ecc:	1000001b */ 	b	.L0f0b3f3c
/*  f0b3ed0:	ac6e0004 */ 	sw	$t6,0x4($v1)
.L0f0b3ed4:
/*  f0b3ed4:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0b3ed8:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b3edc:	3c01f500 */ 	lui	$at,0xf500
/*  f0b3ee0:	00817825 */ 	or	$t7,$a0,$at
/*  f0b3ee4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0b3ee8:	ada80004 */ 	sw	$t0,0x4($t5)
/*  f0b3eec:	8fb80168 */ 	lw	$t8,0x168($sp)
/*  f0b3ef0:	3c0ce600 */ 	lui	$t4,0xe600
/*  f0b3ef4:	3c0ff300 */ 	lui	$t7,0xf300
/*  f0b3ef8:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f0b3efc:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b3f00:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0b3f04:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0b3f08:	8fa50168 */ 	lw	$a1,0x168($sp)
/*  f0b3f0c:	296107ff */ 	slti	$at,$t3,0x7ff
/*  f0b3f10:	240707ff */ 	addiu	$a3,$zero,0x7ff
/*  f0b3f14:	24b90008 */ 	addiu	$t9,$a1,0x8
/*  f0b3f18:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b3f1c:	10200003 */ 	beqz	$at,.L0f0b3f2c
/*  f0b3f20:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0b3f24:	10000001 */ 	b	.L0f0b3f2c
/*  f0b3f28:	01603825 */ 	or	$a3,$t3,$zero
.L0f0b3f2c:
/*  f0b3f2c:	30f80fff */ 	andi	$t8,$a3,0xfff
/*  f0b3f30:	00187300 */ 	sll	$t6,$t8,0xc
/*  f0b3f34:	01c86825 */ 	or	$t5,$t6,$t0
/*  f0b3f38:	acad0004 */ 	sw	$t5,0x4($a1)
.L0f0b3f3c:
/*  f0b3f3c:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f0b3f40:	3c0ae700 */ 	lui	$t2,0xe700
/*  f0b3f44:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b3f48:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f0b3f4c:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b3f50:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0b3f54:	14c10034 */ 	bne	$a2,$at,.L0f0b4028
/*  f0b3f58:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f0b3f5c:	9298000a */ 	lbu	$t8,0xa($s4)
/*  f0b3f60:	240e03ff */ 	addiu	$t6,$zero,0x3ff
/*  f0b3f64:	25670001 */ 	addiu	$a3,$t3,0x1
/*  f0b3f68:	01d81023 */ 	subu	$v0,$t6,$t8
/*  f0b3f6c:	0047082b */ 	sltu	$at,$v0,$a3
/*  f0b3f70:	10200003 */ 	beqz	$at,.L0f0b3f80
/*  f0b3f74:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b3f78:	10000002 */ 	b	.L0f0b3f84
/*  f0b3f7c:	00404025 */ 	or	$t0,$v0,$zero
.L0f0b3f80:
/*  f0b3f80:	00004025 */ 	or	$t0,$zero,$zero
.L0f0b3f84:
/*  f0b3f84:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0b3f88:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b3f8c:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0b3f90:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0b3f94:	8fa30168 */ 	lw	$v1,0x168($sp)
/*  f0b3f98:	00e83023 */ 	subu	$a2,$a3,$t0
/*  f0b3f9c:	30cd03ff */ 	andi	$t5,$a2,0x3ff
/*  f0b3fa0:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f0b3fa4:	310403ff */ 	andi	$a0,$t0,0x3ff
/*  f0b3fa8:	3c01f000 */ 	lui	$at,0xf000
/*  f0b3fac:	246e0008 */ 	addiu	$t6,$v1,0x8
/*  f0b3fb0:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b3fb4:	03217825 */ 	or	$t7,$t9,$at
/*  f0b3fb8:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f0b3fbc:	01f87025 */ 	or	$t6,$t7,$t8
/*  f0b3fc0:	03002025 */ 	or	$a0,$t8,$zero
/*  f0b3fc4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0b3fc8:	9298000a */ 	lbu	$t8,0xa($s4)
/*  f0b3fcc:	3c010600 */ 	lui	$at,0x600
/*  f0b3fd0:	03066821 */ 	addu	$t5,$t8,$a2
/*  f0b3fd4:	31b903ff */ 	andi	$t9,$t5,0x3ff
/*  f0b3fd8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0b3fdc:	01e17025 */ 	or	$t6,$t7,$at
/*  f0b3fe0:	01c4c025 */ 	or	$t8,$t6,$a0
/*  f0b3fe4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0b3fe8:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b3fec:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0b3ff0:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b3ff4:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0b3ff8:	adaa0000 */ 	sw	$t2,0x0($t5)
/*  f0b3ffc:	8faf0184 */ 	lw	$t7,0x184($sp)
/*  f0b4000:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b4004:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0b4008:	11e00010 */ 	beqz	$t7,.L0f0b404c
/*  f0b400c:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b4010:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b4014:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f0b4018:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f0b401c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f0b4020:	1000000a */ 	b	.L0f0b404c
/*  f0b4024:	add90004 */ 	sw	$t9,0x4($t6)
.L0f0b4028:
/*  f0b4028:	8faf0184 */ 	lw	$t7,0x184($sp)
/*  f0b402c:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b4030:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0b4034:	11e00005 */ 	beqz	$t7,.L0f0b404c
/*  f0b4038:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b403c:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b4040:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f0b4044:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f0b4048:	adc00004 */ 	sw	$zero,0x4($t6)
.L0f0b404c:
/*  f0b404c:	8fb90184 */ 	lw	$t9,0x184($sp)
/*  f0b4050:	8fb00168 */ 	lw	$s0,0x168($sp)
/*  f0b4054:	3c01f500 */ 	lui	$at,0xf500
/*  f0b4058:	13200231 */ 	beqz	$t9,.L0f0b4920
/*  f0b405c:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f0b4060:	93ad0146 */ 	lbu	$t5,0x146($sp)
/*  f0b4064:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b4068:	0121c025 */ 	or	$t8,$t1,$at
/*  f0b406c:	31b90003 */ 	andi	$t9,$t5,0x3
/*  f0b4070:	8fad0134 */ 	lw	$t5,0x134($sp)
/*  f0b4074:	00197cc0 */ 	sll	$t7,$t9,0x13
/*  f0b4078:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0b407c:	31b901ff */ 	andi	$t9,$t5,0x1ff
/*  f0b4080:	0019c240 */ 	sll	$t8,$t9,0x9
/*  f0b4084:	01d87825 */ 	or	$t7,$t6,$t8
/*  f0b4088:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f0b408c:	0fc2ccd4 */ 	jal	func0f0b3350
/*  f0b4090:	02402025 */ 	or	$a0,$s2,$zero
/*  f0b4094:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4098:	0fc2ccd4 */ 	jal	func0f0b3350
/*  f0b409c:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0b40a0:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f0b40a4:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f0b40a8:	304d000f */ 	andi	$t5,$v0,0xf
/*  f0b40ac:	90ce000a */ 	lbu	$t6,0xa($a2)
/*  f0b40b0:	000dc900 */ 	sll	$t9,$t5,0x4
/*  f0b40b4:	8fa50180 */ 	lw	$a1,0x180($sp)
/*  f0b40b8:	31d80003 */ 	andi	$t8,$t6,0x3
/*  f0b40bc:	00187c80 */ 	sll	$t7,$t8,0x12
/*  f0b40c0:	032f6825 */ 	or	$t5,$t9,$t7
/*  f0b40c4:	90cf0009 */ 	lbu	$t7,0x9($a2)
/*  f0b40c8:	30ee000f */ 	andi	$t6,$a3,0xf
/*  f0b40cc:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0b40d0:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f0b40d4:	31ee0003 */ 	andi	$t6,$t7,0x3
/*  f0b40d8:	000e6a00 */ 	sll	$t5,$t6,0x8
/*  f0b40dc:	032dc025 */ 	or	$t8,$t9,$t5
/*  f0b40e0:	ae180004 */ 	sw	$t8,0x4($s0)
/*  f0b40e4:	8fa40168 */ 	lw	$a0,0x168($sp)
/*  f0b40e8:	30a30fff */ 	andi	$v1,$a1,0xfff
/*  f0b40ec:	0003cb00 */ 	sll	$t9,$v1,0xc
/*  f0b40f0:	3c01f200 */ 	lui	$at,0xf200
/*  f0b40f4:	248e0008 */ 	addiu	$t6,$a0,0x8
/*  f0b40f8:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b40fc:	03216825 */ 	or	$t5,$t9,$at
/*  f0b4100:	266fffff */ 	addiu	$t7,$s3,-1
/*  f0b4104:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0b4108:	01a3c025 */ 	or	$t8,$t5,$v1
/*  f0b410c:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f0b4110:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0b4114:	264fffff */ 	addiu	$t7,$s2,-1
/*  f0b4118:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0b411c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0b4120:	000dc300 */ 	sll	$t8,$t5,0xc
/*  f0b4124:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f0b4128:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0b412c:	030d7825 */ 	or	$t7,$t8,$t5
/*  f0b4130:	100001fb */ 	b	.L0f0b4920
/*  f0b4134:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f0b4138:
/*  f0b4138:	afa000cc */ 	sw	$zero,0xcc($sp)
/*  f0b413c:	14200003 */ 	bnez	$at,.L0f0b414c
/*  f0b4140:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f0b4144:	24190006 */ 	addiu	$t9,$zero,0x6
/*  f0b4148:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L0f0b414c:
/*  f0b414c:	1280000c */ 	beqz	$s4,.L0f0b4180
/*  f0b4150:	8fad0174 */ 	lw	$t5,0x174($sp)
/*  f0b4154:	8e820008 */ 	lw	$v0,0x8($s4)
/*  f0b4158:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f0b415c:	a3af00c6 */ 	sb	$t7,0xc6($sp)
/*  f0b4160:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f0b4164:	000286c0 */ 	sll	$s0,$v0,0x1b
/*  f0b4168:	0010c742 */ 	srl	$t8,$s0,0x1d
/*  f0b416c:	331000ff */ 	andi	$s0,$t8,0xff
/*  f0b4170:	000ecf82 */ 	srl	$t9,$t6,0x1e
/*  f0b4174:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0b4178:	10000004 */ 	b	.L0f0b418c
/*  f0b417c:	afb800c0 */ 	sw	$t8,0xc0($sp)
.L0f0b4180:
/*  f0b4180:	91af0008 */ 	lbu	$t7,0x8($t5)
/*  f0b4184:	91b00007 */ 	lbu	$s0,0x7($t5)
/*  f0b4188:	a3af00c6 */ 	sb	$t7,0xc6($sp)
.L0f0b418c:
/*  f0b418c:	1280000b */ 	beqz	$s4,.L0f0b41bc
/*  f0b4190:	93a800c6 */ 	lbu	$t0,0xc6($sp)
/*  f0b4194:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f0b4198:	02802025 */ 	or	$a0,$s4,$zero
/*  f0b419c:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f0b41a0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0b41a4:	07010005 */ 	bgez	$t8,.L0f0b41bc
/*  f0b41a8:	00000000 */ 	nop
/*  f0b41ac:	0fc5cf94 */ 	jal	func0f173e50
/*  f0b41b0:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0b41b4:	1000002c */ 	b	.L0f0b4268
/*  f0b41b8:	8fb90184 */ 	lw	$t9,0x184($sp)
.L0f0b41bc:
/*  f0b41bc:	11000022 */ 	beqz	$t0,.L0f0b4248
/*  f0b41c0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0b41c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b41c8:	11010017 */ 	beq	$t0,$at,.L0f0b4228
/*  f0b41cc:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0b41d0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b41d4:	1101000c */ 	beq	$t0,$at,.L0f0b4208
/*  f0b41d8:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0b41dc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b41e0:	15010020 */ 	bne	$t0,$at,.L0f0b4264
/*  f0b41e4:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f0b41e8:	afad00bc */ 	sw	$t5,0xbc($sp)
/*  f0b41ec:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b41f0:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b41f4:	0fc2cd52 */ 	jal	func0f0b3548
/*  f0b41f8:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0b41fc:	244fffff */ 	addiu	$t7,$v0,-1
/*  f0b4200:	10000018 */ 	b	.L0f0b4264
/*  f0b4204:	afaf00b8 */ 	sw	$t7,0xb8($sp)
.L0f0b4208:
/*  f0b4208:	afae00bc */ 	sw	$t6,0xbc($sp)
/*  f0b420c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4210:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b4214:	0fc2cd36 */ 	jal	func0f0b34d8
/*  f0b4218:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0b421c:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f0b4220:	10000010 */ 	b	.L0f0b4264
/*  f0b4224:	afb900b8 */ 	sw	$t9,0xb8($sp)
.L0f0b4228:
/*  f0b4228:	afb800bc */ 	sw	$t8,0xbc($sp)
/*  f0b422c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4230:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b4234:	0fc2cd1a */ 	jal	func0f0b3468
/*  f0b4238:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0b423c:	244dffff */ 	addiu	$t5,$v0,-1
/*  f0b4240:	10000008 */ 	b	.L0f0b4264
/*  f0b4244:	afad00b8 */ 	sw	$t5,0xb8($sp)
.L0f0b4248:
/*  f0b4248:	afaf00bc */ 	sw	$t7,0xbc($sp)
/*  f0b424c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4250:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b4254:	0fc2ccfe */ 	jal	func0f0b33f8
/*  f0b4258:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0b425c:	244effff */ 	addiu	$t6,$v0,-1
/*  f0b4260:	afae00b8 */ 	sw	$t6,0xb8($sp)
.L0f0b4264:
/*  f0b4264:	8fb90184 */ 	lw	$t9,0x184($sp)
.L0f0b4268:
/*  f0b4268:	27a40168 */ 	addiu	$a0,$sp,0x168
/*  f0b426c:	8fa50178 */ 	lw	$a1,0x178($sp)
/*  f0b4270:	1320006d */ 	beqz	$t9,.L0f0b4428
/*  f0b4274:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0b4278:	0fc2cd6e */ 	jal	func0f0b35b8
/*  f0b427c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0b4280:	2a210002 */ 	slti	$at,$s1,0x2
/*  f0b4284:	14200012 */ 	bnez	$at,.L0f0b42d0
/*  f0b4288:	02002825 */ 	or	$a1,$s0,$zero
/*  f0b428c:	8fa20168 */ 	lw	$v0,0x168($sp)
/*  f0b4290:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f0b4294:	322f00ff */ 	andi	$t7,$s1,0xff
/*  f0b4298:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0b429c:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b42a0:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f0b42a4:	3c01bb00 */ 	lui	$at,0xbb00
/*  f0b42a8:	270dffff */ 	addiu	$t5,$t8,-1
/*  f0b42ac:	31af0007 */ 	andi	$t7,$t5,0x7
/*  f0b42b0:	01c1c825 */ 	or	$t9,$t6,$at
/*  f0b42b4:	000f72c0 */ 	sll	$t6,$t7,0xb
/*  f0b42b8:	032ec025 */ 	or	$t8,$t9,$t6
/*  f0b42bc:	370d0001 */ 	ori	$t5,$t8,0x1
/*  f0b42c0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0b42c4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0b42c8:	1000000e */ 	b	.L0f0b4304
/*  f0b42cc:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f0b42d0:
/*  f0b42d0:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f0b42d4:	8fa20168 */ 	lw	$v0,0x168($sp)
/*  f0b42d8:	3c01bb00 */ 	lui	$at,0xbb00
/*  f0b42dc:	270dffff */ 	addiu	$t5,$t8,-1
/*  f0b42e0:	31af0007 */ 	andi	$t7,$t5,0x7
/*  f0b42e4:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0b42e8:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b42ec:	000fcac0 */ 	sll	$t9,$t7,0xb
/*  f0b42f0:	03217025 */ 	or	$t6,$t9,$at
/*  f0b42f4:	35d80001 */ 	ori	$t8,$t6,0x1
/*  f0b42f8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0b42fc:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0b4300:	ac580000 */ 	sw	$t8,0x0($v0)
.L0f0b4304:
/*  f0b4304:	8faf0168 */ 	lw	$t7,0x168($sp)
/*  f0b4308:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0b430c:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f0b4310:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f0b4314:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b4318:	3c180001 */ 	lui	$t8,0x1
/*  f0b431c:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f0b4320:	1200000c */ 	beqz	$s0,.L0f0b4354
/*  f0b4324:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f0b4328:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b432c:	10a10025 */ 	beq	$a1,$at,.L0f0b43c4
/*  f0b4330:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0b4334:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b4338:	10a10010 */ 	beq	$a1,$at,.L0f0b437c
/*  f0b433c:	8fb80168 */ 	lw	$t8,0x168($sp)
/*  f0b4340:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0b4344:	10a10016 */ 	beq	$a1,$at,.L0f0b43a0
/*  f0b4348:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b434c:	10000037 */ 	b	.L0f0b442c
/*  f0b4350:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b4354:
/*  f0b4354:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b4358:	3c19fc26 */ 	lui	$t9,0xfc26
/*  f0b435c:	3c0e1f10 */ 	lui	$t6,0x1f10
/*  f0b4360:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f0b4364:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b4368:	35ce93ff */ 	ori	$t6,$t6,0x93ff
/*  f0b436c:	3739a004 */ 	ori	$t9,$t9,0xa004
/*  f0b4370:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f0b4374:	1000002c */ 	b	.L0f0b4428
/*  f0b4378:	adae0004 */ 	sw	$t6,0x4($t5)
.L0f0b437c:
/*  f0b437c:	270d0008 */ 	addiu	$t5,$t8,0x8
/*  f0b4380:	3c0ffc26 */ 	lui	$t7,0xfc26
/*  f0b4384:	3c191f10 */ 	lui	$t9,0x1f10
/*  f0b4388:	373993ff */ 	ori	$t9,$t9,0x93ff
/*  f0b438c:	35efa004 */ 	ori	$t7,$t7,0xa004
/*  f0b4390:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b4394:	af190004 */ 	sw	$t9,0x4($t8)
/*  f0b4398:	10000023 */ 	b	.L0f0b4428
/*  f0b439c:	af0f0000 */ 	sw	$t7,0x0($t8)
.L0f0b43a0:
/*  f0b43a0:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b43a4:	3c0dfc26 */ 	lui	$t5,0xfc26
/*  f0b43a8:	3c0f1ffc */ 	lui	$t7,0x1ffc
/*  f0b43ac:	35ef93fc */ 	ori	$t7,$t7,0x93fc
/*  f0b43b0:	35ada004 */ 	ori	$t5,$t5,0xa004
/*  f0b43b4:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b43b8:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b43bc:	1000001a */ 	b	.L0f0b4428
/*  f0b43c0:	adcd0000 */ 	sw	$t5,0x0($t6)
.L0f0b43c4:
/*  f0b43c4:	34018000 */ 	dli	$at,0x8000
/*  f0b43c8:	13210006 */ 	beq	$t9,$at,.L0f0b43e4
/*  f0b43cc:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b43d0:	3401c000 */ 	dli	$at,0xc000
/*  f0b43d4:	1321000c */ 	beq	$t9,$at,.L0f0b4408
/*  f0b43d8:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0b43dc:	10000013 */ 	b	.L0f0b442c
/*  f0b43e0:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b43e4:
/*  f0b43e4:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b43e8:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0b43ec:	3c0fff33 */ 	lui	$t7,0xff33
/*  f0b43f0:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0b43f4:	35ad1824 */ 	ori	$t5,$t5,0x1824
/*  f0b43f8:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b43fc:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b4400:	10000009 */ 	b	.L0f0b4428
/*  f0b4404:	adcd0000 */ 	sw	$t5,0x0($t6)
.L0f0b4408:
/*  f0b4408:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f0b440c:	3c0dff33 */ 	lui	$t5,0xff33
/*  f0b4410:	35adffff */ 	ori	$t5,$t5,0xffff
/*  f0b4414:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0b4418:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b441c:	37181824 */ 	ori	$t8,$t8,0x1824
/*  f0b4420:	af380000 */ 	sw	$t8,0x0($t9)
/*  f0b4424:	af2d0004 */ 	sw	$t5,0x4($t9)
.L0f0b4428:
/*  f0b4428:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b442c:
/*  f0b442c:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0b4430:	320e0007 */ 	andi	$t6,$s0,0x7
/*  f0b4434:	000ec540 */ 	sll	$t8,$t6,0x15
/*  f0b4438:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f0b443c:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b4440:	3c01fd00 */ 	lui	$at,0xfd00
/*  f0b4444:	31f90003 */ 	andi	$t9,$t7,0x3
/*  f0b4448:	001974c0 */ 	sll	$t6,$t9,0x13
/*  f0b444c:	03016825 */ 	or	$t5,$t8,$at
/*  f0b4450:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f0b4454:	01aec025 */ 	or	$t8,$t5,$t6
/*  f0b4458:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0b445c:	8faf0174 */ 	lw	$t7,0x174($sp)
/*  f0b4460:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b4464:	02002825 */ 	or	$a1,$s0,$zero
/*  f0b4468:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0b446c:	3c080500 */ 	lui	$t0,0x500
/*  f0b4470:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0b4474:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f0b4478:	8fa20168 */ 	lw	$v0,0x168($sp)
/*  f0b447c:	15a10019 */ 	bne	$t5,$at,.L0f0b44e4
/*  f0b4480:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0b4484:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b4488:	3c0ce600 */ 	lui	$t4,0xe600
/*  f0b448c:	3c0df300 */ 	lui	$t5,0xf300
/*  f0b4490:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b4494:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b4498:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0b449c:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f0b44a0:	8fa30168 */ 	lw	$v1,0x168($sp)
/*  f0b44a4:	240707ff */ 	addiu	$a3,$zero,0x7ff
/*  f0b44a8:	24790008 */ 	addiu	$t9,$v1,0x8
/*  f0b44ac:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b44b0:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0b44b4:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f0b44b8:	29c107ff */ 	slti	$at,$t6,0x7ff
/*  f0b44bc:	10200003 */ 	beqz	$at,.L0f0b44cc
/*  f0b44c0:	00000000 */ 	nop
/*  f0b44c4:	10000001 */ 	b	.L0f0b44cc
/*  f0b44c8:	01c03825 */ 	or	$a3,$t6,$zero
.L0f0b44cc:
/*  f0b44cc:	30f80fff */ 	andi	$t8,$a3,0xfff
/*  f0b44d0:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f0b44d4:	3c010700 */ 	lui	$at,0x700
/*  f0b44d8:	01e1c825 */ 	or	$t9,$t7,$at
/*  f0b44dc:	1000001f */ 	b	.L0f0b455c
/*  f0b44e0:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f0b44e4:
/*  f0b44e4:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*  f0b44e8:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b44ec:	3c01f500 */ 	lui	$at,0xf500
/*  f0b44f0:	330f0003 */ 	andi	$t7,$t8,0x3
/*  f0b44f4:	000fccc0 */ 	sll	$t9,$t7,0x13
/*  f0b44f8:	03216825 */ 	or	$t5,$t9,$at
/*  f0b44fc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0b4500:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0b4504:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b4508:	3c0ce600 */ 	lui	$t4,0xe600
/*  f0b450c:	3c0df300 */ 	lui	$t5,0xf300
/*  f0b4510:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b4514:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b4518:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0b451c:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f0b4520:	8fa40168 */ 	lw	$a0,0x168($sp)
/*  f0b4524:	240707ff */ 	addiu	$a3,$zero,0x7ff
/*  f0b4528:	24990008 */ 	addiu	$t9,$a0,0x8
/*  f0b452c:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b4530:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0b4534:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f0b4538:	29c107ff */ 	slti	$at,$t6,0x7ff
/*  f0b453c:	10200003 */ 	beqz	$at,.L0f0b454c
/*  f0b4540:	00000000 */ 	nop
/*  f0b4544:	10000001 */ 	b	.L0f0b454c
/*  f0b4548:	01c03825 */ 	or	$a3,$t6,$zero
.L0f0b454c:
/*  f0b454c:	30f80fff */ 	andi	$t8,$a3,0xfff
/*  f0b4550:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f0b4554:	01e8c825 */ 	or	$t9,$t7,$t0
/*  f0b4558:	ac990004 */ 	sw	$t9,0x4($a0)
.L0f0b455c:
/*  f0b455c:	8fad0168 */ 	lw	$t5,0x168($sp)
/*  f0b4560:	3c0ae700 */ 	lui	$t2,0xe700
/*  f0b4564:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b4568:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0b456c:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f0b4570:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0b4574:	14a10035 */ 	bne	$a1,$at,.L0f0b464c
/*  f0b4578:	adaa0000 */ 	sw	$t2,0x0($t5)
/*  f0b457c:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f0b4580:	9298000a */ 	lbu	$t8,0xa($s4)
/*  f0b4584:	240f03ff */ 	addiu	$t7,$zero,0x3ff
/*  f0b4588:	24660001 */ 	addiu	$a2,$v1,0x1
/*  f0b458c:	01f81023 */ 	subu	$v0,$t7,$t8
/*  f0b4590:	0046082b */ 	sltu	$at,$v0,$a2
/*  f0b4594:	10200003 */ 	beqz	$at,.L0f0b45a4
/*  f0b4598:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f0b459c:	10000002 */ 	b	.L0f0b45a8
/*  f0b45a0:	00403825 */ 	or	$a3,$v0,$zero
.L0f0b45a4:
/*  f0b45a4:	00003825 */ 	or	$a3,$zero,$zero
.L0f0b45a8:
/*  f0b45a8:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0b45ac:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b45b0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0b45b4:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f0b45b8:	8fa30168 */ 	lw	$v1,0x168($sp)
/*  f0b45bc:	00c73023 */ 	subu	$a2,$a2,$a3
/*  f0b45c0:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f0b45c4:	00196b80 */ 	sll	$t5,$t9,0xe
/*  f0b45c8:	30e403ff */ 	andi	$a0,$a3,0x3ff
/*  f0b45cc:	3c01f000 */ 	lui	$at,0xf000
/*  f0b45d0:	246f0008 */ 	addiu	$t7,$v1,0x8
/*  f0b45d4:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b45d8:	01a17025 */ 	or	$t6,$t5,$at
/*  f0b45dc:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f0b45e0:	01d87825 */ 	or	$t7,$t6,$t8
/*  f0b45e4:	03002025 */ 	or	$a0,$t8,$zero
/*  f0b45e8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b45ec:	9298000a */ 	lbu	$t8,0xa($s4)
/*  f0b45f0:	3c010600 */ 	lui	$at,0x600
/*  f0b45f4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0b45f8:	332d03ff */ 	andi	$t5,$t9,0x3ff
/*  f0b45fc:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0b4600:	01c17825 */ 	or	$t7,$t6,$at
/*  f0b4604:	01e4c025 */ 	or	$t8,$t7,$a0
/*  f0b4608:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0b460c:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f0b4610:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0b4614:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b4618:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0b461c:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f0b4620:	8fae0184 */ 	lw	$t6,0x184($sp)
/*  f0b4624:	8faf0168 */ 	lw	$t7,0x168($sp)
/*  f0b4628:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0b462c:	11c00010 */ 	beqz	$t6,.L0f0b4670
/*  f0b4630:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0b4634:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b4638:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f0b463c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0b4640:	8fad00c0 */ 	lw	$t5,0xc0($sp)
/*  f0b4644:	1000000a */ 	b	.L0f0b4670
/*  f0b4648:	aded0004 */ 	sw	$t5,0x4($t7)
.L0f0b464c:
/*  f0b464c:	8fae0184 */ 	lw	$t6,0x184($sp)
/*  f0b4650:	8faf0168 */ 	lw	$t7,0x168($sp)
/*  f0b4654:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0b4658:	11c00005 */ 	beqz	$t6,.L0f0b4670
/*  f0b465c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0b4660:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b4664:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f0b4668:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0b466c:	ade00004 */ 	sw	$zero,0x4($t7)
.L0f0b4670:
/*  f0b4670:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0b4674:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b4678:	93a800c6 */ 	lbu	$t0,0xc6($sp)
/*  f0b467c:	19a000a8 */ 	blez	$t5,.L0f0b4920
/*  f0b4680:	8fb0005c */ 	lw	$s0,0x5c($sp)
.L0f0b4684:
/*  f0b4684:	1a200019 */ 	blez	$s1,.L0f0b46ec
/*  f0b4688:	00000000 */ 	nop
/*  f0b468c:	12800010 */ 	beqz	$s4,.L0f0b46d0
/*  f0b4690:	2a610002 */ 	slti	$at,$s3,0x2
/*  f0b4694:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f0b4698:	02802025 */ 	or	$a0,$s4,$zero
/*  f0b469c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b46a0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0b46a4:	0701000a */ 	bgez	$t8,.L0f0b46d0
/*  f0b46a8:	00000000 */ 	nop
/*  f0b46ac:	0fc5cf04 */ 	jal	func0f173c10
/*  f0b46b0:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f0b46b4:	00409825 */ 	or	$s3,$v0,$zero
/*  f0b46b8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0b46bc:	0fc5cf2e */ 	jal	func0f173cb8
/*  f0b46c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b46c4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0b46c8:	10000008 */ 	b	.L0f0b46ec
/*  f0b46cc:	00409025 */ 	or	$s2,$v0,$zero
.L0f0b46d0:
/*  f0b46d0:	14200002 */ 	bnez	$at,.L0f0b46dc
/*  f0b46d4:	0013c843 */ 	sra	$t9,$s3,0x1
/*  f0b46d8:	03209825 */ 	or	$s3,$t9,$zero
.L0f0b46dc:
/*  f0b46dc:	2a410002 */ 	slti	$at,$s2,0x2
/*  f0b46e0:	14200002 */ 	bnez	$at,.L0f0b46ec
/*  f0b46e4:	00126843 */ 	sra	$t5,$s2,0x1
/*  f0b46e8:	01a09025 */ 	or	$s2,$t5,$zero
.L0f0b46ec:
/*  f0b46ec:	1100002a */ 	beqz	$t0,.L0f0b4798
/*  f0b46f0:	8fad0184 */ 	lw	$t5,0x184($sp)
/*  f0b46f4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b46f8:	1101001d */ 	beq	$t0,$at,.L0f0b4770
/*  f0b46fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b4700:	11010011 */ 	beq	$t0,$at,.L0f0b4748
/*  f0b4704:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b4708:	51010006 */ 	beql	$t0,$at,.L0f0b4724
/*  f0b470c:	26700003 */ 	addiu	$s0,$s3,0x3
/*  f0b4710:	02120019 */ 	multu	$s0,$s2
/*  f0b4714:	00003012 */ 	mflo	$a2
/*  f0b4718:	10000029 */ 	b	.L0f0b47c0
/*  f0b471c:	00000000 */ 	nop
/*  f0b4720:	26700003 */ 	addiu	$s0,$s3,0x3
.L0f0b4724:
/*  f0b4724:	06010003 */ 	bgez	$s0,.L0f0b4734
/*  f0b4728:	00107083 */ 	sra	$t6,$s0,0x2
/*  f0b472c:	26010003 */ 	addiu	$at,$s0,0x3
/*  f0b4730:	00017083 */ 	sra	$t6,$at,0x2
.L0f0b4734:
/*  f0b4734:	01d20019 */ 	multu	$t6,$s2
/*  f0b4738:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0b473c:	00003012 */ 	mflo	$a2
/*  f0b4740:	1000001f */ 	b	.L0f0b47c0
/*  f0b4744:	00000000 */ 	nop
.L0f0b4748:
/*  f0b4748:	26700003 */ 	addiu	$s0,$s3,0x3
/*  f0b474c:	06010003 */ 	bgez	$s0,.L0f0b475c
/*  f0b4750:	00107883 */ 	sra	$t7,$s0,0x2
/*  f0b4754:	26010003 */ 	addiu	$at,$s0,0x3
/*  f0b4758:	00017883 */ 	sra	$t7,$at,0x2
.L0f0b475c:
/*  f0b475c:	01f20019 */ 	multu	$t7,$s2
/*  f0b4760:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0b4764:	00003012 */ 	mflo	$a2
/*  f0b4768:	10000015 */ 	b	.L0f0b47c0
/*  f0b476c:	00000000 */ 	nop
.L0f0b4770:
/*  f0b4770:	26700007 */ 	addiu	$s0,$s3,0x7
/*  f0b4774:	06010003 */ 	bgez	$s0,.L0f0b4784
/*  f0b4778:	0010c0c3 */ 	sra	$t8,$s0,0x3
/*  f0b477c:	26010007 */ 	addiu	$at,$s0,0x7
/*  f0b4780:	0001c0c3 */ 	sra	$t8,$at,0x3
.L0f0b4784:
/*  f0b4784:	03120019 */ 	multu	$t8,$s2
/*  f0b4788:	03008025 */ 	or	$s0,$t8,$zero
/*  f0b478c:	00003012 */ 	mflo	$a2
/*  f0b4790:	1000000b */ 	b	.L0f0b47c0
/*  f0b4794:	00000000 */ 	nop
.L0f0b4798:
/*  f0b4798:	2670000f */ 	addiu	$s0,$s3,0xf
/*  f0b479c:	06010003 */ 	bgez	$s0,.L0f0b47ac
/*  f0b47a0:	0010c903 */ 	sra	$t9,$s0,0x4
/*  f0b47a4:	2601000f */ 	addiu	$at,$s0,0xf
/*  f0b47a8:	0001c903 */ 	sra	$t9,$at,0x4
.L0f0b47ac:
/*  f0b47ac:	03320019 */ 	multu	$t9,$s2
/*  f0b47b0:	03208025 */ 	or	$s0,$t9,$zero
/*  f0b47b4:	00003012 */ 	mflo	$a2
/*  f0b47b8:	00000000 */ 	nop
/*  f0b47bc:	00000000 */ 	nop
.L0f0b47c0:
/*  f0b47c0:	11a00050 */ 	beqz	$t5,.L0f0b4904
/*  f0b47c4:	8fa50180 */ 	lw	$a1,0x180($sp)
/*  f0b47c8:	8fa20168 */ 	lw	$v0,0x168($sp)
/*  f0b47cc:	93ad00c6 */ 	lbu	$t5,0xc6($sp)
/*  f0b47d0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f0b47d4:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0b47d8:	afaf0168 */ 	sw	$t7,0x168($sp)
/*  f0b47dc:	3c01f500 */ 	lui	$at,0xf500
/*  f0b47e0:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f0b47e4:	000e7cc0 */ 	sll	$t7,$t6,0x13
/*  f0b47e8:	0301c825 */ 	or	$t9,$t8,$at
/*  f0b47ec:	032fc025 */ 	or	$t8,$t9,$t7
/*  f0b47f0:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0b47f4:	320d01ff */ 	andi	$t5,$s0,0x1ff
/*  f0b47f8:	000d7240 */ 	sll	$t6,$t5,0x9
/*  f0b47fc:	030ec825 */ 	or	$t9,$t8,$t6
/*  f0b4800:	31ed01ff */ 	andi	$t5,$t7,0x1ff
/*  f0b4804:	032dc025 */ 	or	$t8,$t9,$t5
/*  f0b4808:	30a30fff */ 	andi	$v1,$a1,0xfff
/*  f0b480c:	00037300 */ 	sll	$t6,$v1,0xc
/*  f0b4810:	3c01f200 */ 	lui	$at,0xf200
/*  f0b4814:	01c17825 */ 	or	$t7,$t6,$at
/*  f0b4818:	266dffff */ 	addiu	$t5,$s3,-1
/*  f0b481c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0b4820:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f0b4824:	03057021 */ 	addu	$t6,$t8,$a1
/*  f0b4828:	01e3c825 */ 	or	$t9,$t7,$v1
/*  f0b482c:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0b4830:	264dffff */ 	addiu	$t5,$s2,-1
/*  f0b4834:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f0b4838:	afb90048 */ 	sw	$t9,0x48($sp)
/*  f0b483c:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0b4840:	03057021 */ 	addu	$t6,$t8,$a1
/*  f0b4844:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0b4848:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f0b484c:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f0b4850:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f0b4854:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0b4858:	02402025 */ 	or	$a0,$s2,$zero
/*  f0b485c:	0fc2ccd4 */ 	jal	func0f0b3350
/*  f0b4860:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0b4864:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4868:	0fc2ccd4 */ 	jal	func0f0b3350
/*  f0b486c:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0b4870:	32230007 */ 	andi	$v1,$s1,0x7
/*  f0b4874:	8faf0174 */ 	lw	$t7,0x174($sp)
/*  f0b4878:	0003ce00 */ 	sll	$t9,$v1,0x18
/*  f0b487c:	304d000f */ 	andi	$t5,$v0,0xf
/*  f0b4880:	000dc100 */ 	sll	$t8,$t5,0x4
/*  f0b4884:	03197025 */ 	or	$t6,$t8,$t9
/*  f0b4888:	03201825 */ 	or	$v1,$t9,$zero
/*  f0b488c:	91f9000a */ 	lbu	$t9,0xa($t7)
/*  f0b4890:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f0b4894:	3224000f */ 	andi	$a0,$s1,0xf
/*  f0b4898:	332d0003 */ 	andi	$t5,$t9,0x3
/*  f0b489c:	000dc480 */ 	sll	$t8,$t5,0x12
/*  f0b48a0:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0b48a4:	30ed000f */ 	andi	$t5,$a3,0xf
/*  f0b48a8:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0b48ac:	032ec025 */ 	or	$t8,$t9,$t6
/*  f0b48b0:	91ee0009 */ 	lbu	$t6,0x9($t7)
/*  f0b48b4:	00046a80 */ 	sll	$t5,$a0,0xa
/*  f0b48b8:	030dc825 */ 	or	$t9,$t8,$t5
/*  f0b48bc:	31d80003 */ 	andi	$t8,$t6,0x3
/*  f0b48c0:	00186a00 */ 	sll	$t5,$t8,0x8
/*  f0b48c4:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0b48c8:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0b48cc:	01e47025 */ 	or	$t6,$t7,$a0
/*  f0b48d0:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0b48d4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0b48d8:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0b48dc:	8fa50168 */ 	lw	$a1,0x168($sp)
/*  f0b48e0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f0b48e4:	24ad0008 */ 	addiu	$t5,$a1,0x8
/*  f0b48e8:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b48ec:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0b48f0:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0b48f4:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f0b48f8:	006ec025 */ 	or	$t8,$v1,$t6
/*  f0b48fc:	03196825 */ 	or	$t5,$t8,$t9
/*  f0b4900:	acad0004 */ 	sw	$t5,0x4($a1)
.L0f0b4904:
/*  f0b4904:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0b4908:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f0b490c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b4910:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f0b4914:	1638ff5b */ 	bne	$s1,$t8,.L0f0b4684
/*  f0b4918:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0b491c:	afb0005c */ 	sw	$s0,0x5c($sp)
.L0f0b4920:
/*  f0b4920:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f0b4924:	8fad0170 */ 	lw	$t5,0x170($sp)
/*  f0b4928:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f0b492c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b4930:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0b4934:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0b4938:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0b493c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0b4940:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0b4944:	03e00008 */ 	jr	$ra
/*  f0b4948:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
