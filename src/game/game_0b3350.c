#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_096750.h"
#include "game/game_0b3350.h"
#include "game/game_127910.h"
#include "game/game_157db0.h"
#include "game/game_16e810.h"
#include "game/game_173a00.h"
#include "gvars/gvars.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0b3350
/*  f0b3350:	28810002 */ 	slti	$at,$a0,0x2
/*  f0b3354:	50200004 */ 	beqzl	$at,.L0f0b3368
/*  f0b3358:	28810003 */ 	slti	$at,$a0,0x3
/*  f0b335c:	03e00008 */ 	jr	$ra
/*  f0b3360:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b3364:	28810003 */ 	slti	$at,$a0,0x3
.L0f0b3368:
/*  f0b3368:	50200004 */ 	beqzl	$at,.L0f0b337c
/*  f0b336c:	28810005 */ 	slti	$at,$a0,0x5
/*  f0b3370:	03e00008 */ 	jr	$ra
/*  f0b3374:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0b3378:	28810005 */ 	slti	$at,$a0,0x5
.L0f0b337c:
/*  f0b337c:	50200004 */ 	beqzl	$at,.L0f0b3390
/*  f0b3380:	28810009 */ 	slti	$at,$a0,0x9
/*  f0b3384:	03e00008 */ 	jr	$ra
/*  f0b3388:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f0b338c:	28810009 */ 	slti	$at,$a0,0x9
.L0f0b3390:
/*  f0b3390:	50200004 */ 	beqzl	$at,.L0f0b33a4
/*  f0b3394:	28810011 */ 	slti	$at,$a0,0x11
/*  f0b3398:	03e00008 */ 	jr	$ra
/*  f0b339c:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f0b33a0:	28810011 */ 	slti	$at,$a0,0x11
.L0f0b33a4:
/*  f0b33a4:	50200004 */ 	beqzl	$at,.L0f0b33b8
/*  f0b33a8:	28810021 */ 	slti	$at,$a0,0x21
/*  f0b33ac:	03e00008 */ 	jr	$ra
/*  f0b33b0:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0b33b4:	28810021 */ 	slti	$at,$a0,0x21
.L0f0b33b8:
/*  f0b33b8:	50200004 */ 	beqzl	$at,.L0f0b33cc
/*  f0b33bc:	28810041 */ 	slti	$at,$a0,0x41
/*  f0b33c0:	03e00008 */ 	jr	$ra
/*  f0b33c4:	24020005 */ 	addiu	$v0,$zero,0x5
/*  f0b33c8:	28810041 */ 	slti	$at,$a0,0x41
.L0f0b33cc:
/*  f0b33cc:	50200004 */ 	beqzl	$at,.L0f0b33e0
/*  f0b33d0:	28810081 */ 	slti	$at,$a0,0x81
/*  f0b33d4:	03e00008 */ 	jr	$ra
/*  f0b33d8:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f0b33dc:	28810081 */ 	slti	$at,$a0,0x81
.L0f0b33e0:
/*  f0b33e0:	10200003 */ 	beqz	$at,.L0f0b33f0
/*  f0b33e4:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f0b33e8:	03e00008 */ 	jr	$ra
/*  f0b33ec:	24020007 */ 	addiu	$v0,$zero,0x7
.L0f0b33f0:
/*  f0b33f0:	03e00008 */ 	jr	$ra
/*  f0b33f4:	00000000 */ 	sll	$zero,$zero,0x0
);

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
/*  f0b3450:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b34c0:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b3530:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b35a0:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b3600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b3604:	13010023 */ 	beq	$t8,$at,.L0f0b3694
/*  f0b3608:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b360c:	1301003f */ 	beq	$t8,$at,.L0f0b370c
/*  f0b3610:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0b3614:	13010050 */ 	beq	$t8,$at,.L0f0b3758
/*  f0b3618:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b364c:	100000cc */ 	beqz	$zero,.L0f0b3980
/*  f0b3650:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3654:
/*  f0b3654:	3c0ab900 */ 	lui	$t2,0xb900
/*  f0b3658:	3c0b0055 */ 	lui	$t3,0x55
/*  f0b365c:	356b2078 */ 	ori	$t3,$t3,0x2078
/*  f0b3660:	354a031d */ 	ori	$t2,$t2,0x31d
/*  f0b3664:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0b3668:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0b366c:	100000c4 */ 	beqz	$zero,.L0f0b3980
/*  f0b3670:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3674:
/*  f0b3674:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0b3678:	3c0d0055 */ 	lui	$t5,0x55
/*  f0b367c:	35ad2048 */ 	ori	$t5,$t5,0x2048
/*  f0b3680:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0b3684:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0b3688:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f0b368c:	100000bc */ 	beqz	$zero,.L0f0b3980
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
/*  f0b36c4:	100000ae */ 	beqz	$zero,.L0f0b3980
/*  f0b36c8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b36cc:
/*  f0b36cc:	3c18b900 */ 	lui	$t8,0xb900
/*  f0b36d0:	3c190050 */ 	lui	$t9,0x50
/*  f0b36d4:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f0b36d8:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0b36dc:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0b36e0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0b36e4:	100000a6 */ 	beqz	$zero,.L0f0b3980
/*  f0b36e8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b36ec:
/*  f0b36ec:	3c09b900 */ 	lui	$t1,0xb900
/*  f0b36f0:	3c0a0050 */ 	lui	$t2,0x50
/*  f0b36f4:	354a41c8 */ 	ori	$t2,$t2,0x41c8
/*  f0b36f8:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0b36fc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0b3700:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f0b3704:	1000009e */ 	beqz	$zero,.L0f0b3980
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
/*  f0b3730:	10000093 */ 	beqz	$zero,.L0f0b3980
/*  f0b3734:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3738:
/*  f0b3738:	3c0db900 */ 	lui	$t5,0xb900
/*  f0b373c:	3c0e0055 */ 	lui	$t6,0x55
/*  f0b3740:	35ce3048 */ 	ori	$t6,$t6,0x3048
/*  f0b3744:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f0b3748:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0b374c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0b3750:	1000008b */ 	beqz	$zero,.L0f0b3980
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
/*  f0b377c:	10000080 */ 	beqz	$zero,.L0f0b3980
/*  f0b3780:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3784:
/*  f0b3784:	3c19b900 */ 	lui	$t9,0xb900
/*  f0b3788:	3c090050 */ 	lui	$t1,0x50
/*  f0b378c:	35294340 */ 	ori	$t1,$t1,0x4340
/*  f0b3790:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0b3794:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0b3798:	ac690004 */ 	sw	$t1,0x4($v1)
/*  f0b379c:	10000078 */ 	beqz	$zero,.L0f0b3980
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
/*  f0b37e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b37e4:	11a10023 */ 	beq	$t5,$at,.L0f0b3874
/*  f0b37e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b37ec:	11a1003f */ 	beq	$t5,$at,.L0f0b38ec
/*  f0b37f0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0b37f4:	11a10050 */ 	beq	$t5,$at,.L0f0b3938
/*  f0b37f8:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b382c:	10000054 */ 	beqz	$zero,.L0f0b3980
/*  f0b3830:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3834:
/*  f0b3834:	3c18b900 */ 	lui	$t8,0xb900
/*  f0b3838:	3c190c19 */ 	lui	$t9,0xc19
/*  f0b383c:	37392078 */ 	ori	$t9,$t9,0x2078
/*  f0b3840:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0b3844:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0b3848:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0b384c:	1000004c */ 	beqz	$zero,.L0f0b3980
/*  f0b3850:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3854:
/*  f0b3854:	3c09b900 */ 	lui	$t1,0xb900
/*  f0b3858:	3c0a0c19 */ 	lui	$t2,0xc19
/*  f0b385c:	354a2048 */ 	ori	$t2,$t2,0x2048
/*  f0b3860:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0b3864:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0b3868:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f0b386c:	10000044 */ 	beqz	$zero,.L0f0b3980
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
/*  f0b38a4:	10000036 */ 	beqz	$zero,.L0f0b3980
/*  f0b38a8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b38ac:
/*  f0b38ac:	3c0db900 */ 	lui	$t5,0xb900
/*  f0b38b0:	3c0e0c18 */ 	lui	$t6,0xc18
/*  f0b38b4:	35ce49d8 */ 	ori	$t6,$t6,0x49d8
/*  f0b38b8:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f0b38bc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0b38c0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0b38c4:	1000002e */ 	beqz	$zero,.L0f0b3980
/*  f0b38c8:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b38cc:
/*  f0b38cc:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0b38d0:	3c180c18 */ 	lui	$t8,0xc18
/*  f0b38d4:	371841c8 */ 	ori	$t8,$t8,0x41c8
/*  f0b38d8:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0b38dc:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0b38e0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0b38e4:	10000026 */ 	beqz	$zero,.L0f0b3980
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
/*  f0b3910:	1000001b */ 	beqz	$zero,.L0f0b3980
/*  f0b3914:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f0b3918:
/*  f0b3918:	3c0ab900 */ 	lui	$t2,0xb900
/*  f0b391c:	3c0b0c19 */ 	lui	$t3,0xc19
/*  f0b3920:	356b3048 */ 	ori	$t3,$t3,0x3048
/*  f0b3924:	354a031d */ 	ori	$t2,$t2,0x31d
/*  f0b3928:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0b392c:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0b3930:	10000013 */ 	beqz	$zero,.L0f0b3980
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
/*  f0b395c:	10000008 */ 	beqz	$zero,.L0f0b3980
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
/*  f0b39bc:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b3a3c:	10000008 */ 	beqz	$zero,.L0f0b3a60
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
/*  f0b3a80:	100003a7 */ 	beqz	$zero,.L0f0b4920
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
/*  f0b3b10:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b3ba0:	10000004 */ 	beqz	$zero,.L0f0b3bb4
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
/*  f0b3bec:	10000026 */ 	beqz	$zero,.L0f0b3c88
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
/*  f0b3c14:	1000001c */ 	beqz	$zero,.L0f0b3c88
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
/*  f0b3c3c:	10000012 */ 	beqz	$zero,.L0f0b3c88
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
/*  f0b3c64:	10000008 */ 	beqz	$zero,.L0f0b3c88
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
/*  f0b3cdc:	10000009 */ 	beqz	$zero,.L0f0b3d04
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
/*  f0b3d4c:	10000036 */ 	beqz	$zero,.L0f0b3e28
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
/*  f0b3d74:	1000002b */ 	beqz	$zero,.L0f0b3e24
/*  f0b3d78:	af2e0004 */ 	sw	$t6,0x4($t9)
.L0f0b3d7c:
/*  f0b3d7c:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0b3d80:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f0b3d84:	3c18ff33 */ 	lui	$t8,0xff33
/*  f0b3d88:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0b3d8c:	35ef1824 */ 	ori	$t7,$t7,0x1824
/*  f0b3d90:	afb90168 */ 	sw	$t9,0x168($sp)
/*  f0b3d94:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0b3d98:	10000022 */ 	beqz	$zero,.L0f0b3e24
/*  f0b3d9c:	adaf0000 */ 	sw	$t7,0x0($t5)
.L0f0b3da0:
/*  f0b3da0:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f0b3da4:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0b3da8:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0b3dac:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3db0:	240ff9fc */ 	addiu	$t7,$zero,-1540
/*  f0b3db4:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b3db8:	1000001a */ 	beqz	$zero,.L0f0b3e24
/*  f0b3dbc:	add90000 */ 	sw	$t9,0x0($t6)
.L0f0b3dc0:
/*  f0b3dc0:	34018000 */ 	dli	$at,0x8000
/*  f0b3dc4:	13010006 */ 	beq	$t8,$at,.L0f0b3de0
/*  f0b3dc8:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b3dcc:	3401c000 */ 	dli	$at,0xc000
/*  f0b3dd0:	1301000c */ 	beq	$t8,$at,.L0f0b3e04
/*  f0b3dd4:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0b3dd8:	10000013 */ 	beqz	$zero,.L0f0b3e28
/*  f0b3ddc:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b3de0:
/*  f0b3de0:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f0b3de4:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0b3de8:	3c0fff33 */ 	lui	$t7,0xff33
/*  f0b3dec:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0b3df0:	37391824 */ 	ori	$t9,$t9,0x1824
/*  f0b3df4:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b3df8:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b3dfc:	10000009 */ 	beqz	$zero,.L0f0b3e24
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
/*  f0b3eb0:	10000002 */ 	beqz	$zero,.L0f0b3ebc
/*  f0b3eb4:	01603825 */ 	or	$a3,$t3,$zero
.L0f0b3eb8:
/*  f0b3eb8:	240707ff */ 	addiu	$a3,$zero,0x7ff
.L0f0b3ebc:
/*  f0b3ebc:	30ef0fff */ 	andi	$t7,$a3,0xfff
/*  f0b3ec0:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0b3ec4:	3c010700 */ 	lui	$at,0x700
/*  f0b3ec8:	03017025 */ 	or	$t6,$t8,$at
/*  f0b3ecc:	1000001b */ 	beqz	$zero,.L0f0b3f3c
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
/*  f0b3f24:	10000001 */ 	beqz	$zero,.L0f0b3f2c
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
/*  f0b3f78:	10000002 */ 	beqz	$zero,.L0f0b3f84
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
/*  f0b4020:	1000000a */ 	beqz	$zero,.L0f0b404c
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
/*  f0b4130:	100001fb */ 	beqz	$zero,.L0f0b4920
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
/*  f0b4178:	10000004 */ 	beqz	$zero,.L0f0b418c
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
/*  f0b41a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b41ac:	0fc5cf94 */ 	jal	func0f173e50
/*  f0b41b0:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0b41b4:	1000002c */ 	beqz	$zero,.L0f0b4268
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
/*  f0b4200:	10000018 */ 	beqz	$zero,.L0f0b4264
/*  f0b4204:	afaf00b8 */ 	sw	$t7,0xb8($sp)
.L0f0b4208:
/*  f0b4208:	afae00bc */ 	sw	$t6,0xbc($sp)
/*  f0b420c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4210:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b4214:	0fc2cd36 */ 	jal	func0f0b34d8
/*  f0b4218:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0b421c:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f0b4220:	10000010 */ 	beqz	$zero,.L0f0b4264
/*  f0b4224:	afb900b8 */ 	sw	$t9,0xb8($sp)
.L0f0b4228:
/*  f0b4228:	afb800bc */ 	sw	$t8,0xbc($sp)
/*  f0b422c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0b4230:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b4234:	0fc2cd1a */ 	jal	func0f0b3468
/*  f0b4238:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0b423c:	244dffff */ 	addiu	$t5,$v0,-1
/*  f0b4240:	10000008 */ 	beqz	$zero,.L0f0b4264
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
/*  f0b42c8:	1000000e */ 	beqz	$zero,.L0f0b4304
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
/*  f0b434c:	10000037 */ 	beqz	$zero,.L0f0b442c
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
/*  f0b4374:	1000002c */ 	beqz	$zero,.L0f0b4428
/*  f0b4378:	adae0004 */ 	sw	$t6,0x4($t5)
.L0f0b437c:
/*  f0b437c:	270d0008 */ 	addiu	$t5,$t8,0x8
/*  f0b4380:	3c0ffc26 */ 	lui	$t7,0xfc26
/*  f0b4384:	3c191f10 */ 	lui	$t9,0x1f10
/*  f0b4388:	373993ff */ 	ori	$t9,$t9,0x93ff
/*  f0b438c:	35efa004 */ 	ori	$t7,$t7,0xa004
/*  f0b4390:	afad0168 */ 	sw	$t5,0x168($sp)
/*  f0b4394:	af190004 */ 	sw	$t9,0x4($t8)
/*  f0b4398:	10000023 */ 	beqz	$zero,.L0f0b4428
/*  f0b439c:	af0f0000 */ 	sw	$t7,0x0($t8)
.L0f0b43a0:
/*  f0b43a0:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b43a4:	3c0dfc26 */ 	lui	$t5,0xfc26
/*  f0b43a8:	3c0f1ffc */ 	lui	$t7,0x1ffc
/*  f0b43ac:	35ef93fc */ 	ori	$t7,$t7,0x93fc
/*  f0b43b0:	35ada004 */ 	ori	$t5,$t5,0xa004
/*  f0b43b4:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b43b8:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b43bc:	1000001a */ 	beqz	$zero,.L0f0b4428
/*  f0b43c0:	adcd0000 */ 	sw	$t5,0x0($t6)
.L0f0b43c4:
/*  f0b43c4:	34018000 */ 	dli	$at,0x8000
/*  f0b43c8:	13210006 */ 	beq	$t9,$at,.L0f0b43e4
/*  f0b43cc:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f0b43d0:	3401c000 */ 	dli	$at,0xc000
/*  f0b43d4:	1321000c */ 	beq	$t9,$at,.L0f0b4408
/*  f0b43d8:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0b43dc:	10000013 */ 	beqz	$zero,.L0f0b442c
/*  f0b43e0:	8fa20168 */ 	lw	$v0,0x168($sp)
.L0f0b43e4:
/*  f0b43e4:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0b43e8:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0b43ec:	3c0fff33 */ 	lui	$t7,0xff33
/*  f0b43f0:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0b43f4:	35ad1824 */ 	ori	$t5,$t5,0x1824
/*  f0b43f8:	afb80168 */ 	sw	$t8,0x168($sp)
/*  f0b43fc:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0b4400:	10000009 */ 	beqz	$zero,.L0f0b4428
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
/*  f0b44c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b44c4:	10000001 */ 	beqz	$zero,.L0f0b44cc
/*  f0b44c8:	01c03825 */ 	or	$a3,$t6,$zero
.L0f0b44cc:
/*  f0b44cc:	30f80fff */ 	andi	$t8,$a3,0xfff
/*  f0b44d0:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f0b44d4:	3c010700 */ 	lui	$at,0x700
/*  f0b44d8:	01e1c825 */ 	or	$t9,$t7,$at
/*  f0b44dc:	1000001f */ 	beqz	$zero,.L0f0b455c
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
/*  f0b4540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b4544:	10000001 */ 	beqz	$zero,.L0f0b454c
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
/*  f0b459c:	10000002 */ 	beqz	$zero,.L0f0b45a8
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
/*  f0b4644:	1000000a */ 	beqz	$zero,.L0f0b4670
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
/*  f0b4688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b468c:	12800010 */ 	beqz	$s4,.L0f0b46d0
/*  f0b4690:	2a610002 */ 	slti	$at,$s3,0x2
/*  f0b4694:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f0b4698:	02802025 */ 	or	$a0,$s4,$zero
/*  f0b469c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b46a0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0b46a4:	0701000a */ 	bgez	$t8,.L0f0b46d0
/*  f0b46a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b46ac:	0fc5cf04 */ 	jal	func0f173c10
/*  f0b46b0:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f0b46b4:	00409825 */ 	or	$s3,$v0,$zero
/*  f0b46b8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0b46bc:	0fc5cf2e */ 	jal	func0f173cb8
/*  f0b46c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b46c4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0b46c8:	10000008 */ 	beqz	$zero,.L0f0b46ec
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
/*  f0b4718:	10000029 */ 	beqz	$zero,.L0f0b47c0
/*  f0b471c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b4740:	1000001f */ 	beqz	$zero,.L0f0b47c0
/*  f0b4744:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b4768:	10000015 */ 	beqz	$zero,.L0f0b47c0
/*  f0b476c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b4790:	1000000b */ 	beqz	$zero,.L0f0b47c0
/*  f0b4794:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b47b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b47bc:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0b494c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b4950:	03e00008 */ 	jr	$ra
/*  f0b4954:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerSetScreenSize(f32 width, f32 height)
{
	struct player *player = g_Vars.currentplayer;

	player->c_screenwidth = width;
	player->c_screenheight = height;
	player->c_halfwidth = width * 0.5f;
	player->c_halfheight = height * 0.5f;
}

void currentPlayerSetScreenPosition(f32 left, f32 top)
{
	struct player *player = g_Vars.currentplayer;

	player->c_screenleft = left;
	player->c_screentop = top;
}

void currentPlayerSetPerspective(f32 near, f32 fovy, f32 aspect)
{
	struct player *player = g_Vars.currentplayer;

	player->c_perspnear = near;
	player->c_perspfovy = fovy;
	player->c_perspaspect = aspect;
}

f32 func0f0b49b8(f32 arg0)
{
	f32 result = func0f096750(g_Vars.currentplayer->c_scalelod60 * arg0 * g_Vars.currentplayer->c_halfheight, 1.0f);
	result *= 114.591552f;

	if (result < 0) {
		result = -result;
	}

	return result;
}

void currentPlayerSetCameraScale(void)
{
	struct player *player = g_Vars.currentplayer;
	f32 fVar4;
	f32 tmp;
	f32 fVar5;
	f32 fVar2;

	player->c_scaley = fsin(player->c_perspfovy * (M_CORRECT_PI / 360.0f)) / (fcos(player->c_perspfovy * (M_CORRECT_PI / 360.0f)) * player->c_halfheight);
	player->c_scalelod = player->c_scaley;
	player->c_scalex = (player->c_scaley * player->c_perspaspect * player->c_halfheight) / player->c_halfwidth;

	player->c_recipscalex = 1.0f / player->c_scalex;
	player->c_recipscaley = 1.0f / player->c_scaley;

	fVar4 = fsin(0.52359879016876f) / (fcos(0.52359879016876f) * 120.0f);
	player->c_scalelod60 = fVar4;
	player->c_lodscalez = player->c_scalelod / fVar4;
	tmp = player->c_lodscalez * 65536.0f;

	if (tmp > 4294967296.0f) {
		player->c_lodscalezu32 = 0xffffffff;
	} else {
		player->c_lodscalezu32 = tmp;
	}

	fVar2 = player->c_halfheight * player->c_scaley;
	fVar4 = 1.0f / sqrtf(fVar2 * fVar2 + 1.0f);
	player->c_cameratopnorm.x = 0;
	player->c_cameratopnorm.y = fVar4;
	player->c_cameratopnorm.z = fVar2 * fVar4;

	fVar5 = -player->c_halfwidth * player->c_scalex;
	fVar4 = 1.0f / sqrtf(fVar5 * fVar5 + 1.0f);
	player->c_cameraleftnorm.x = -fVar4;
	player->c_cameraleftnorm.y = 0;
	player->c_cameraleftnorm.z = -fVar5 * fVar4;
}

GLOBAL_ASM(
glabel func0f0b4c3c
/*  f0b4c3c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0b4c40:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0b4c44:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0b4c48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b4c4c:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0b4c50:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f0b4c54:	c4461710 */ 	lwc1	$f6,0x1710($v0)
/*  f0b4c58:	c44a1724 */ 	lwc1	$f10,0x1724($v0)
/*  f0b4c5c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0b4c60:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0b4c64:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f0b4c68:	c444172c */ 	lwc1	$f4,0x172c($v0)
/*  f0b4c6c:	44810000 */ 	mtc1	$at,$f0
/*  f0b4c70:	46085481 */ 	sub.s	$f18,$f10,$f8
/*  f0b4c74:	c44a170c */ 	lwc1	$f10,0x170c($v0)
/*  f0b4c78:	46049382 */ 	mul.s	$f14,$f18,$f4
/*  f0b4c7c:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0b4c80:	c4521720 */ 	lwc1	$f18,0x1720($v0)
/*  f0b4c84:	c4461728 */ 	lwc1	$f6,0x1728($v0)
/*  f0b4c88:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0b4c8c:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f0b4c90:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f0b4c94:	46062402 */ 	mul.s	$f16,$f4,$f6
/*  f0b4c98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b4c9c:	46108282 */ 	mul.s	$f10,$f16,$f16
/*  f0b4ca0:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0b4ca4:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0b4ca8:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0b4cac:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0b4cb0:	0c012974 */ 	jal	sqrtf
/*  f0b4cb4:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f0b4cb8:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f0b4cbc:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f0b4cc0:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*  f0b4cc4:	46003083 */ 	div.s	$f2,$f6,$f0
/*  f0b4cc8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0b4ccc:	44819000 */ 	mtc1	$at,$f18
/*  f0b4cd0:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0b4cd4:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f0b4cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b4cdc:	46027202 */ 	mul.s	$f8,$f14,$f2
/*  f0b4ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b4ce4:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0b4ce8:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f0b4cec:	e4a80004 */ 	swc1	$f8,0x4($a1)
/*  f0b4cf0:	e4a40008 */ 	swc1	$f4,0x8($a1)
/*  f0b4cf4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b4cf8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0b4cfc:	03e00008 */ 	jr	$ra
/*  f0b4d00:	00000000 */ 	sll	$zero,$zero,0x0
);

void func0f0b4d04(struct coord *in, struct coord *out)
{
	struct player *player = g_Vars.currentplayer;
	f32 value = 1.0f / in->z;

	out->y = in->y * value * player->c_recipscaley
		+ (player->c_screentop + player->c_halfheight);

	out->x = (player->c_screenleft + player->c_halfwidth)
		- in->x * value * player->c_recipscalex;
}

void func0f0b4d68(struct coord *in, struct coord *out)
{
	struct player *player = g_Vars.currentplayer;
	f32 value;

	if (in->z == 0.0f) {
		value = -100000000000000000000.0f;
	} else {
		value = 1.0f / in->z;
	}

	out->y = in->y * value * player->c_recipscaley
		+ (player->c_screentop + player->c_halfheight);

	out->x = (player->c_screenleft + player->c_halfwidth) -
		in->x * value * player->c_recipscalex;
}

void func0f0b4dec(struct coord *in, struct coord *out)
{
	struct player *player = g_Vars.currentplayer;
	f32 value = 1.0f / in->z;

	if (value < 0) {
		value = -value;
	}

	out->y = in->y * value * player->c_recipscaley +
		(player->c_screentop + player->c_halfheight);

	out->x = (player->c_screenleft + player->c_halfwidth)
		- in->x * value * player->c_recipscalex;
}

void func0f0b4e68(struct coord *in, f32 divisor, struct coord *out)
{
	out->y = in->y * (1.0f / divisor) * g_Vars.currentplayer->c_recipscaley;
	out->x = in->x * (1.0f / divisor) * g_Vars.currentplayer->c_recipscalex;
}

GLOBAL_ASM(
glabel func0f0b4eb8
.late_rodata
glabel var7f1ad154
.word 0x3c0efa35
.text
/*  f0b4eb8:	3c017f1b */ 	lui	$at,%hi(var7f1ad154)
/*  f0b4ebc:	44867000 */ 	mtc1	$a2,$f14
/*  f0b4ec0:	c424d154 */ 	lwc1	$f4,%lo(var7f1ad154)($at)
/*  f0b4ec4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0b4ec8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0b4ecc:	46047302 */ 	mul.s	$f12,$f14,$f4
/*  f0b4ed0:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0b4ed4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b4ed8:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0b4edc:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0b4ee0:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0b4ee4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0b4ee8:	0c0068f4 */ 	jal	fcos
/*  f0b4eec:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0b4ef0:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0b4ef4:	0c0068f7 */ 	jal	fsin
/*  f0b4ef8:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0b4efc:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f0b4f00:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0b4f04:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*  f0b4f08:	c4421724 */ 	lwc1	$f2,0x1724($v0)
/*  f0b4f0c:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0b4f10:	c4521720 */ 	lwc1	$f18,0x1720($v0)
/*  f0b4f14:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0b4f18:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f0b4f1c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f0b4f20:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0b4f24:	46104303 */ 	div.s	$f12,$f8,$f16
/*  f0b4f28:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f0b4f2c:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f0b4f30:	c4521710 */ 	lwc1	$f18,0x1710($v0)
/*  f0b4f34:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0b4f38:	46029180 */ 	add.s	$f6,$f18,$f2
/*  f0b4f3c:	460c4402 */ 	mul.s	$f16,$f8,$f12
/*  f0b4f40:	460a2383 */ 	div.s	$f14,$f4,$f10
/*  f0b4f44:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f0b4f48:	e4840004 */ 	swc1	$f4,0x4($a0)
/*  f0b4f4c:	c4700000 */ 	lwc1	$f16,0x0($v1)
/*  f0b4f50:	c4481720 */ 	lwc1	$f8,0x1720($v0)
/*  f0b4f54:	c44a170c */ 	lwc1	$f10,0x170c($v0)
/*  f0b4f58:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0b4f5c:	460e8182 */ 	mul.s	$f6,$f16,$f14
/*  f0b4f60:	46069101 */ 	sub.s	$f4,$f18,$f6
/*  f0b4f64:	e4840000 */ 	swc1	$f4,0x0($a0)
/*  f0b4f68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b4f6c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0b4f70:	03e00008 */ 	jr	$ra
/*  f0b4f74:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b4f78
/*  f0b4f78:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4f7c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4f80:	03e00008 */ 	jr	$ra
/*  f0b4f84:	adc41738 */ 	sw	$a0,0x1738($t6)
/*  f0b4f88:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4f8c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4f90:	03e00008 */ 	jr	$ra
/*  f0b4f94:	8dc21738 */ 	lw	$v0,0x1738($t6)
);

GLOBAL_ASM(
glabel func0f0b4f98
/*  f0b4f98:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4f9c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4fa0:	03e00008 */ 	jr	$ra
/*  f0b4fa4:	adc4173c */ 	sw	$a0,0x173c($t6)
);

GLOBAL_ASM(
glabel func0f0b4fa8
/*  f0b4fa8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4fac:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4fb0:	03e00008 */ 	jr	$ra
/*  f0b4fb4:	8dc2173c */ 	lw	$v0,0x173c($t6)
);

GLOBAL_ASM(
glabel func0f0b4fb8
/*  f0b4fb8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4fbc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4fc0:	03e00008 */ 	jr	$ra
/*  f0b4fc4:	adc4006c */ 	sw	$a0,0x6c($t6)
);

GLOBAL_ASM(
glabel func0f0b4fc8
/*  f0b4fc8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4fcc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4fd0:	03e00008 */ 	jr	$ra
/*  f0b4fd4:	8dc2006c */ 	lw	$v0,0x6c($t6)
);

GLOBAL_ASM(
glabel func0f0b4fd8
/*  f0b4fd8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4fdc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4fe0:	03e00008 */ 	jr	$ra
/*  f0b4fe4:	adc41750 */ 	sw	$a0,0x1750($t6)
);

GLOBAL_ASM(
glabel func0f0b4fe8
/*  f0b4fe8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4fec:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b4ff0:	03e00008 */ 	jr	$ra
/*  f0b4ff4:	8dc21750 */ 	lw	$v0,0x1750($t6)
);

GLOBAL_ASM(
glabel func0f0b4ff8
/*  f0b4ff8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b4ffc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5000:	03e00008 */ 	jr	$ra
/*  f0b5004:	adc41758 */ 	sw	$a0,0x1758($t6)
);

GLOBAL_ASM(
glabel func0f0b5008
/*  f0b5008:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b500c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5010:	03e00008 */ 	jr	$ra
/*  f0b5014:	8dc21758 */ 	lw	$v0,0x1758($t6)
);

GLOBAL_ASM(
glabel func0f0b5018
/*  f0b5018:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0b501c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0b5020:	3c0f8008 */ 	lui	$t7,%hi(var80084008)
/*  f0b5024:	3c19800b */ 	lui	$t9,%hi(var800aa59c)
/*  f0b5028:	8c4e1740 */ 	lw	$t6,0x1740($v0)
/*  f0b502c:	ac441740 */ 	sw	$a0,0x1740($v0)
/*  f0b5030:	8c580484 */ 	lw	$t8,0x484($v0)
/*  f0b5034:	ac4e1760 */ 	sw	$t6,0x1760($v0)
/*  f0b5038:	8def4008 */ 	lw	$t7,%lo(var80084008)($t7)
/*  f0b503c:	ac580488 */ 	sw	$t8,0x488($v0)
/*  f0b5040:	ac4f1744 */ 	sw	$t7,0x1744($v0)
/*  f0b5044:	8f39a59c */ 	lw	$t9,%lo(var800aa59c)($t9)
/*  f0b5048:	03e00008 */ 	jr	$ra
/*  f0b504c:	ac590484 */ 	sw	$t9,0x484($v0)
);

GLOBAL_ASM(
glabel func0f0b5050
/*  f0b5050:	3c02800b */ 	lui	$v0,%hi(var800aa5a0)
/*  f0b5054:	9042a5a0 */ 	lbu	$v0,%lo(var800aa5a0)($v0)
/*  f0b5058:	3c03800b */ 	lui	$v1,%hi(var800aa590)
/*  f0b505c:	2463a590 */ 	addiu	$v1,$v1,%lo(var800aa590)
/*  f0b5060:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0b5064:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0b5068:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0b506c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0b5070:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0b5074:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0b5078:	0098082b */ 	sltu	$at,$a0,$t8
/*  f0b507c:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0b5080:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b5084:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0b5088:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0b508c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0b5090:	1420005a */ 	bnez	$at,.L0f0b51fc
/*  f0b5094:	00009025 */ 	or	$s2,$zero,$zero
/*  f0b5098:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f0b509c:	00794021 */ 	addu	$t0,$v1,$t9
/*  f0b50a0:	8d090004 */ 	lw	$t1,0x4($t0)
/*  f0b50a4:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b50a8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b50ac:	0089082b */ 	sltu	$at,$a0,$t1
/*  f0b50b0:	10200052 */ 	beqz	$at,.L0f0b51fc
/*  f0b50b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b50b8:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*  f0b50bc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b50c0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b50c4:	11400003 */ 	beqz	$t2,.L0f0b50d4
/*  f0b50c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b50cc:	10000001 */ 	beqz	$zero,.L0f0b50d4
/*  f0b50d0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b50d4:
/*  f0b50d4:	8e0b0068 */ 	lw	$t3,0x68($s0)
/*  f0b50d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b50dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b50e0:	11600003 */ 	beqz	$t3,.L0f0b50f0
/*  f0b50e4:	3c138008 */ 	lui	$s3,%hi(var80084008)
/*  f0b50e8:	10000001 */ 	beqz	$zero,.L0f0b50f0
/*  f0b50ec:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b50f0:
/*  f0b50f0:	8e0c0064 */ 	lw	$t4,0x64($s0)
/*  f0b50f4:	26734008 */ 	addiu	$s3,$s3,%lo(var80084008)
/*  f0b50f8:	11800003 */ 	beqz	$t4,.L0f0b5108
/*  f0b50fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5100:	10000001 */ 	beqz	$zero,.L0f0b5108
/*  f0b5104:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b5108:
/*  f0b5108:	8e0d0070 */ 	lw	$t5,0x70($s0)
/*  f0b510c:	11a00003 */ 	beqz	$t5,.L0f0b511c
/*  f0b5110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5114:	10000001 */ 	beqz	$zero,.L0f0b511c
/*  f0b5118:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b511c:
/*  f0b511c:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0b5120:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0b5124:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f0b5128:	5b000096 */ 	blezl	$t8,.L0f0b5384
/*  f0b512c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b5130:
/*  f0b5130:	0fc4a39e */ 	jal	calculatePlayerIndex
/*  f0b5134:	02202025 */ 	or	$a0,$s1,$zero
/*  f0b5138:	8e190290 */ 	lw	$t9,0x290($s0)
/*  f0b513c:	00114080 */ 	sll	$t0,$s1,0x2
/*  f0b5140:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b5144:	0322082a */ 	slt	$at,$t9,$v0
/*  f0b5148:	1420000d */ 	bnez	$at,.L0f0b5180
/*  f0b514c:	02084821 */ 	addu	$t1,$s0,$t0
/*  f0b5150:	8d220064 */ 	lw	$v0,0x64($t1)
/*  f0b5154:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f0b5158:	8c4b1744 */ 	lw	$t3,0x1744($v0)
/*  f0b515c:	554b0009 */ 	bnel	$t2,$t3,.L0f0b5184
/*  f0b5160:	8e0c006c */ 	lw	$t4,0x6c($s0)
/*  f0b5164:	8c430484 */ 	lw	$v1,0x484($v0)
/*  f0b5168:	0283082b */ 	sltu	$at,$s4,$v1
/*  f0b516c:	14200004 */ 	bnez	$at,.L0f0b5180
/*  f0b5170:	0243082b */ 	sltu	$at,$s2,$v1
/*  f0b5174:	50200003 */ 	beqzl	$at,.L0f0b5184
/*  f0b5178:	8e0c006c */ 	lw	$t4,0x6c($s0)
/*  f0b517c:	8c521740 */ 	lw	$s2,0x1740($v0)
.L0f0b5180:
/*  f0b5180:	8e0c006c */ 	lw	$t4,0x6c($s0)
.L0f0b5184:
/*  f0b5184:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b5188:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b518c:	11800003 */ 	beqz	$t4,.L0f0b519c
/*  f0b5190:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b5194:	10000001 */ 	beqz	$zero,.L0f0b519c
/*  f0b5198:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b519c:
/*  f0b519c:	8e0d0068 */ 	lw	$t5,0x68($s0)
/*  f0b51a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b51a4:	11a00003 */ 	beqz	$t5,.L0f0b51b4
/*  f0b51a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b51ac:	10000001 */ 	beqz	$zero,.L0f0b51b4
/*  f0b51b0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b51b4:
/*  f0b51b4:	8e0e0064 */ 	lw	$t6,0x64($s0)
/*  f0b51b8:	11c00003 */ 	beqz	$t6,.L0f0b51c8
/*  f0b51bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b51c0:	10000001 */ 	beqz	$zero,.L0f0b51c8
/*  f0b51c4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b51c8:
/*  f0b51c8:	8e0f0070 */ 	lw	$t7,0x70($s0)
/*  f0b51cc:	11e00003 */ 	beqz	$t7,.L0f0b51dc
/*  f0b51d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b51d4:	10000001 */ 	beqz	$zero,.L0f0b51dc
/*  f0b51d8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b51dc:
/*  f0b51dc:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0b51e0:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0b51e4:	03264021 */ 	addu	$t0,$t9,$a2
/*  f0b51e8:	0228082a */ 	slt	$at,$s1,$t0
/*  f0b51ec:	1420ffd0 */ 	bnez	$at,.L0f0b5130
/*  f0b51f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b51f4:	10000063 */ 	beqz	$zero,.L0f0b5384
/*  f0b51f8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b51fc:
/*  f0b51fc:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b5200:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b5204:	8e09006c */ 	lw	$t1,0x6c($s0)
/*  f0b5208:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b520c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b5210:	11200003 */ 	beqz	$t1,.L0f0b5220
/*  f0b5214:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b5218:	10000001 */ 	beqz	$zero,.L0f0b5220
/*  f0b521c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b5220:
/*  f0b5220:	8e0a0068 */ 	lw	$t2,0x68($s0)
/*  f0b5224:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b5228:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b522c:	11400003 */ 	beqz	$t2,.L0f0b523c
/*  f0b5230:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f0b5234:	10000001 */ 	beqz	$zero,.L0f0b523c
/*  f0b5238:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b523c:
/*  f0b523c:	8e0b0064 */ 	lw	$t3,0x64($s0)
/*  f0b5240:	3c138008 */ 	lui	$s3,%hi(var80084008)
/*  f0b5244:	26734008 */ 	addiu	$s3,$s3,%lo(var80084008)
/*  f0b5248:	11600003 */ 	beqz	$t3,.L0f0b5258
/*  f0b524c:	02182821 */ 	addu	$a1,$s0,$t8
/*  f0b5250:	10000001 */ 	beqz	$zero,.L0f0b5258
/*  f0b5254:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b5258:
/*  f0b5258:	8e0c0070 */ 	lw	$t4,0x70($s0)
/*  f0b525c:	11800003 */ 	beqz	$t4,.L0f0b526c
/*  f0b5260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5264:	10000001 */ 	beqz	$zero,.L0f0b526c
/*  f0b5268:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b526c:
/*  f0b526c:	00436821 */ 	addu	$t5,$v0,$v1
/*  f0b5270:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f0b5274:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f0b5278:	19e00041 */ 	blez	$t7,.L0f0b5380
/*  f0b527c:	02202025 */ 	or	$a0,$s1,$zero
.L0f0b5280:
/*  f0b5280:	0fc4a39e */ 	jal	calculatePlayerIndex
/*  f0b5284:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0b5288:	8e190290 */ 	lw	$t9,0x290($s0)
/*  f0b528c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b5290:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b5294:	0322082a */ 	slt	$at,$t9,$v0
/*  f0b5298:	1420000f */ 	bnez	$at,.L0f0b52d8
/*  f0b529c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0b52a0:	8ca20064 */ 	lw	$v0,0x64($a1)
/*  f0b52a4:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f0b52a8:	8c491764 */ 	lw	$t1,0x1764($v0)
/*  f0b52ac:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0b52b0:	550a0017 */ 	bnel	$t0,$t2,.L0f0b5310
/*  f0b52b4:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b52b8:	8c430488 */ 	lw	$v1,0x488($v0)
/*  f0b52bc:	0283082b */ 	sltu	$at,$s4,$v1
/*  f0b52c0:	14200012 */ 	bnez	$at,.L0f0b530c
/*  f0b52c4:	0243082b */ 	sltu	$at,$s2,$v1
/*  f0b52c8:	50200011 */ 	beqzl	$at,.L0f0b5310
/*  f0b52cc:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b52d0:	1000000e */ 	beqz	$zero,.L0f0b530c
/*  f0b52d4:	8c521760 */ 	lw	$s2,0x1760($v0)
.L0f0b52d8:
/*  f0b52d8:	8ca20064 */ 	lw	$v0,0x64($a1)
/*  f0b52dc:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0b52e0:	8c4c1744 */ 	lw	$t4,0x1744($v0)
/*  f0b52e4:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0b52e8:	556d0009 */ 	bnel	$t3,$t5,.L0f0b5310
/*  f0b52ec:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b52f0:	8c430484 */ 	lw	$v1,0x484($v0)
/*  f0b52f4:	0283082b */ 	sltu	$at,$s4,$v1
/*  f0b52f8:	14200004 */ 	bnez	$at,.L0f0b530c
/*  f0b52fc:	0243082b */ 	sltu	$at,$s2,$v1
/*  f0b5300:	50200003 */ 	beqzl	$at,.L0f0b5310
/*  f0b5304:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b5308:	8c521740 */ 	lw	$s2,0x1740($v0)
.L0f0b530c:
/*  f0b530c:	8e0e006c */ 	lw	$t6,0x6c($s0)
.L0f0b5310:
/*  f0b5310:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b5314:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f0b5318:	11c00003 */ 	beqz	$t6,.L0f0b5328
/*  f0b531c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b5320:	10000001 */ 	beqz	$zero,.L0f0b5328
/*  f0b5324:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b5328:
/*  f0b5328:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*  f0b532c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5330:	11e00003 */ 	beqz	$t7,.L0f0b5340
/*  f0b5334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5338:	10000001 */ 	beqz	$zero,.L0f0b5340
/*  f0b533c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b5340:
/*  f0b5340:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f0b5344:	13000003 */ 	beqz	$t8,.L0f0b5354
/*  f0b5348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b534c:	10000001 */ 	beqz	$zero,.L0f0b5354
/*  f0b5350:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b5354:
/*  f0b5354:	8e190070 */ 	lw	$t9,0x70($s0)
/*  f0b5358:	13200003 */ 	beqz	$t9,.L0f0b5368
/*  f0b535c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5360:	10000001 */ 	beqz	$zero,.L0f0b5368
/*  f0b5364:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b5368:
/*  f0b5368:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0b536c:	01244021 */ 	addu	$t0,$t1,$a0
/*  f0b5370:	01065021 */ 	addu	$t2,$t0,$a2
/*  f0b5374:	022a082a */ 	slt	$at,$s1,$t2
/*  f0b5378:	5420ffc1 */ 	bnezl	$at,.L0f0b5280
/*  f0b537c:	02202025 */ 	or	$a0,$s1,$zero
.L0f0b5380:
/*  f0b5380:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b5384:
/*  f0b5384:	02401025 */ 	or	$v0,$s2,$zero
/*  f0b5388:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0b538c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0b5390:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0b5394:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0b5398:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0b539c:	03e00008 */ 	jr	$ra
/*  f0b53a0:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f0b53a4
/*  f0b53a4:	3c02800b */ 	lui	$v0,%hi(var800aa5a0)
/*  f0b53a8:	9042a5a0 */ 	lbu	$v0,%lo(var800aa5a0)($v0)
/*  f0b53ac:	3c03800b */ 	lui	$v1,%hi(var800aa590)
/*  f0b53b0:	2463a590 */ 	addiu	$v1,$v1,%lo(var800aa590)
/*  f0b53b4:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0b53b8:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0b53bc:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0b53c0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0b53c4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0b53c8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0b53cc:	0098082b */ 	sltu	$at,$a0,$t8
/*  f0b53d0:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0b53d4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b53d8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0b53dc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0b53e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0b53e4:	1420005a */ 	bnez	$at,.L0f0b5550
/*  f0b53e8:	00009025 */ 	or	$s2,$zero,$zero
/*  f0b53ec:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f0b53f0:	00794021 */ 	addu	$t0,$v1,$t9
/*  f0b53f4:	8d090004 */ 	lw	$t1,0x4($t0)
/*  f0b53f8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b53fc:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b5400:	0089082b */ 	sltu	$at,$a0,$t1
/*  f0b5404:	10200052 */ 	beqz	$at,.L0f0b5550
/*  f0b5408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b540c:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*  f0b5410:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b5414:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b5418:	11400003 */ 	beqz	$t2,.L0f0b5428
/*  f0b541c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b5420:	10000001 */ 	beqz	$zero,.L0f0b5428
/*  f0b5424:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b5428:
/*  f0b5428:	8e0b0068 */ 	lw	$t3,0x68($s0)
/*  f0b542c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b5430:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5434:	11600003 */ 	beqz	$t3,.L0f0b5444
/*  f0b5438:	3c138008 */ 	lui	$s3,%hi(var80084008)
/*  f0b543c:	10000001 */ 	beqz	$zero,.L0f0b5444
/*  f0b5440:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b5444:
/*  f0b5444:	8e0c0064 */ 	lw	$t4,0x64($s0)
/*  f0b5448:	26734008 */ 	addiu	$s3,$s3,%lo(var80084008)
/*  f0b544c:	11800003 */ 	beqz	$t4,.L0f0b545c
/*  f0b5450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5454:	10000001 */ 	beqz	$zero,.L0f0b545c
/*  f0b5458:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b545c:
/*  f0b545c:	8e0d0070 */ 	lw	$t5,0x70($s0)
/*  f0b5460:	11a00003 */ 	beqz	$t5,.L0f0b5470
/*  f0b5464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5468:	10000001 */ 	beqz	$zero,.L0f0b5470
/*  f0b546c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b5470:
/*  f0b5470:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0b5474:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0b5478:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f0b547c:	5b000096 */ 	blezl	$t8,.L0f0b56d8
/*  f0b5480:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b5484:
/*  f0b5484:	0fc4a39e */ 	jal	calculatePlayerIndex
/*  f0b5488:	02202025 */ 	or	$a0,$s1,$zero
/*  f0b548c:	8e190290 */ 	lw	$t9,0x290($s0)
/*  f0b5490:	00114080 */ 	sll	$t0,$s1,0x2
/*  f0b5494:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b5498:	0322082a */ 	slt	$at,$t9,$v0
/*  f0b549c:	1420000d */ 	bnez	$at,.L0f0b54d4
/*  f0b54a0:	02084821 */ 	addu	$t1,$s0,$t0
/*  f0b54a4:	8d220064 */ 	lw	$v0,0x64($t1)
/*  f0b54a8:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f0b54ac:	8c4b1744 */ 	lw	$t3,0x1744($v0)
/*  f0b54b0:	554b0009 */ 	bnel	$t2,$t3,.L0f0b54d8
/*  f0b54b4:	8e0c006c */ 	lw	$t4,0x6c($s0)
/*  f0b54b8:	8c430484 */ 	lw	$v1,0x484($v0)
/*  f0b54bc:	0283082b */ 	sltu	$at,$s4,$v1
/*  f0b54c0:	14200004 */ 	bnez	$at,.L0f0b54d4
/*  f0b54c4:	0243082b */ 	sltu	$at,$s2,$v1
/*  f0b54c8:	50200003 */ 	beqzl	$at,.L0f0b54d8
/*  f0b54cc:	8e0c006c */ 	lw	$t4,0x6c($s0)
/*  f0b54d0:	8c52174c */ 	lw	$s2,0x174c($v0)
.L0f0b54d4:
/*  f0b54d4:	8e0c006c */ 	lw	$t4,0x6c($s0)
.L0f0b54d8:
/*  f0b54d8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b54dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b54e0:	11800003 */ 	beqz	$t4,.L0f0b54f0
/*  f0b54e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b54e8:	10000001 */ 	beqz	$zero,.L0f0b54f0
/*  f0b54ec:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b54f0:
/*  f0b54f0:	8e0d0068 */ 	lw	$t5,0x68($s0)
/*  f0b54f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b54f8:	11a00003 */ 	beqz	$t5,.L0f0b5508
/*  f0b54fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5500:	10000001 */ 	beqz	$zero,.L0f0b5508
/*  f0b5504:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b5508:
/*  f0b5508:	8e0e0064 */ 	lw	$t6,0x64($s0)
/*  f0b550c:	11c00003 */ 	beqz	$t6,.L0f0b551c
/*  f0b5510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5514:	10000001 */ 	beqz	$zero,.L0f0b551c
/*  f0b5518:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b551c:
/*  f0b551c:	8e0f0070 */ 	lw	$t7,0x70($s0)
/*  f0b5520:	11e00003 */ 	beqz	$t7,.L0f0b5530
/*  f0b5524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5528:	10000001 */ 	beqz	$zero,.L0f0b5530
/*  f0b552c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b5530:
/*  f0b5530:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0b5534:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0b5538:	03264021 */ 	addu	$t0,$t9,$a2
/*  f0b553c:	0228082a */ 	slt	$at,$s1,$t0
/*  f0b5540:	1420ffd0 */ 	bnez	$at,.L0f0b5484
/*  f0b5544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5548:	10000063 */ 	beqz	$zero,.L0f0b56d8
/*  f0b554c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b5550:
/*  f0b5550:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b5554:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b5558:	8e09006c */ 	lw	$t1,0x6c($s0)
/*  f0b555c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b5560:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b5564:	11200003 */ 	beqz	$t1,.L0f0b5574
/*  f0b5568:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b556c:	10000001 */ 	beqz	$zero,.L0f0b5574
/*  f0b5570:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b5574:
/*  f0b5574:	8e0a0068 */ 	lw	$t2,0x68($s0)
/*  f0b5578:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b557c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5580:	11400003 */ 	beqz	$t2,.L0f0b5590
/*  f0b5584:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f0b5588:	10000001 */ 	beqz	$zero,.L0f0b5590
/*  f0b558c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b5590:
/*  f0b5590:	8e0b0064 */ 	lw	$t3,0x64($s0)
/*  f0b5594:	3c138008 */ 	lui	$s3,%hi(var80084008)
/*  f0b5598:	26734008 */ 	addiu	$s3,$s3,%lo(var80084008)
/*  f0b559c:	11600003 */ 	beqz	$t3,.L0f0b55ac
/*  f0b55a0:	02182821 */ 	addu	$a1,$s0,$t8
/*  f0b55a4:	10000001 */ 	beqz	$zero,.L0f0b55ac
/*  f0b55a8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b55ac:
/*  f0b55ac:	8e0c0070 */ 	lw	$t4,0x70($s0)
/*  f0b55b0:	11800003 */ 	beqz	$t4,.L0f0b55c0
/*  f0b55b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b55b8:	10000001 */ 	beqz	$zero,.L0f0b55c0
/*  f0b55bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b55c0:
/*  f0b55c0:	00436821 */ 	addu	$t5,$v0,$v1
/*  f0b55c4:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f0b55c8:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f0b55cc:	19e00041 */ 	blez	$t7,.L0f0b56d4
/*  f0b55d0:	02202025 */ 	or	$a0,$s1,$zero
.L0f0b55d4:
/*  f0b55d4:	0fc4a39e */ 	jal	calculatePlayerIndex
/*  f0b55d8:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0b55dc:	8e190290 */ 	lw	$t9,0x290($s0)
/*  f0b55e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b55e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b55e8:	0322082a */ 	slt	$at,$t9,$v0
/*  f0b55ec:	1420000f */ 	bnez	$at,.L0f0b562c
/*  f0b55f0:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0b55f4:	8ca20064 */ 	lw	$v0,0x64($a1)
/*  f0b55f8:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f0b55fc:	8c491764 */ 	lw	$t1,0x1764($v0)
/*  f0b5600:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0b5604:	550a0017 */ 	bnel	$t0,$t2,.L0f0b5664
/*  f0b5608:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b560c:	8c430488 */ 	lw	$v1,0x488($v0)
/*  f0b5610:	0283082b */ 	sltu	$at,$s4,$v1
/*  f0b5614:	14200012 */ 	bnez	$at,.L0f0b5660
/*  f0b5618:	0243082b */ 	sltu	$at,$s2,$v1
/*  f0b561c:	50200011 */ 	beqzl	$at,.L0f0b5664
/*  f0b5620:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b5624:	1000000e */ 	beqz	$zero,.L0f0b5660
/*  f0b5628:	8c521768 */ 	lw	$s2,0x1768($v0)
.L0f0b562c:
/*  f0b562c:	8ca20064 */ 	lw	$v0,0x64($a1)
/*  f0b5630:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0b5634:	8c4c1744 */ 	lw	$t4,0x1744($v0)
/*  f0b5638:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0b563c:	556d0009 */ 	bnel	$t3,$t5,.L0f0b5664
/*  f0b5640:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b5644:	8c430484 */ 	lw	$v1,0x484($v0)
/*  f0b5648:	0283082b */ 	sltu	$at,$s4,$v1
/*  f0b564c:	14200004 */ 	bnez	$at,.L0f0b5660
/*  f0b5650:	0243082b */ 	sltu	$at,$s2,$v1
/*  f0b5654:	50200003 */ 	beqzl	$at,.L0f0b5664
/*  f0b5658:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f0b565c:	8c52174c */ 	lw	$s2,0x174c($v0)
.L0f0b5660:
/*  f0b5660:	8e0e006c */ 	lw	$t6,0x6c($s0)
.L0f0b5664:
/*  f0b5664:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b5668:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f0b566c:	11c00003 */ 	beqz	$t6,.L0f0b567c
/*  f0b5670:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b5674:	10000001 */ 	beqz	$zero,.L0f0b567c
/*  f0b5678:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b567c:
/*  f0b567c:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*  f0b5680:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5684:	11e00003 */ 	beqz	$t7,.L0f0b5694
/*  f0b5688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b568c:	10000001 */ 	beqz	$zero,.L0f0b5694
/*  f0b5690:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b5694:
/*  f0b5694:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f0b5698:	13000003 */ 	beqz	$t8,.L0f0b56a8
/*  f0b569c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b56a0:	10000001 */ 	beqz	$zero,.L0f0b56a8
/*  f0b56a4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b56a8:
/*  f0b56a8:	8e190070 */ 	lw	$t9,0x70($s0)
/*  f0b56ac:	13200003 */ 	beqz	$t9,.L0f0b56bc
/*  f0b56b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b56b4:	10000001 */ 	beqz	$zero,.L0f0b56bc
/*  f0b56b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b56bc:
/*  f0b56bc:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0b56c0:	01244021 */ 	addu	$t0,$t1,$a0
/*  f0b56c4:	01065021 */ 	addu	$t2,$t0,$a2
/*  f0b56c8:	022a082a */ 	slt	$at,$s1,$t2
/*  f0b56cc:	5420ffc1 */ 	bnezl	$at,.L0f0b55d4
/*  f0b56d0:	02202025 */ 	or	$a0,$s1,$zero
.L0f0b56d4:
/*  f0b56d4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b56d8:
/*  f0b56d8:	02401025 */ 	or	$v0,$s2,$zero
/*  f0b56dc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0b56e0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0b56e4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0b56e8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0b56ec:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0b56f0:	03e00008 */ 	jr	$ra
/*  f0b56f4:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f0b56f8
/*  f0b56f8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b56fc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5700:	03e00008 */ 	jr	$ra
/*  f0b5704:	8dc21740 */ 	lw	$v0,0x1740($t6)
);

GLOBAL_ASM(
glabel func0f0b5708
/*  f0b5708:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b570c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5710:	03e00008 */ 	jr	$ra
/*  f0b5714:	adc41754 */ 	sw	$a0,0x1754($t6)
);

GLOBAL_ASM(
glabel func0f0b5718
/*  f0b5718:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b571c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5720:	03e00008 */ 	jr	$ra
/*  f0b5724:	8dc21754 */ 	lw	$v0,0x1754($t6)
/*  f0b5728:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b572c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5730:	03e00008 */ 	jr	$ra
/*  f0b5734:	8dc21760 */ 	lw	$v0,0x1760($t6)
/*  f0b5738:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b573c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5740:	03e00008 */ 	jr	$ra
/*  f0b5744:	adc41748 */ 	sw	$a0,0x1748($t6)
/*  f0b5748:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b574c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5750:	03e00008 */ 	jr	$ra
/*  f0b5754:	8dc21748 */ 	lw	$v0,0x1748($t6)
);

GLOBAL_ASM(
glabel func0f0b5758
/*  f0b5758:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0b575c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0b5760:	8c4e1744 */ 	lw	$t6,0x1744($v0)
/*  f0b5764:	8c4f174c */ 	lw	$t7,0x174c($v0)
/*  f0b5768:	ac44174c */ 	sw	$a0,0x174c($v0)
/*  f0b576c:	ac4e1764 */ 	sw	$t6,0x1764($v0)
/*  f0b5770:	03e00008 */ 	jr	$ra
/*  f0b5774:	ac4f1768 */ 	sw	$t7,0x1768($v0)
);

GLOBAL_ASM(
glabel func0f0b5778
/*  f0b5778:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b577c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5780:	03e00008 */ 	jr	$ra
/*  f0b5784:	8dc2174c */ 	lw	$v0,0x174c($t6)
/*  f0b5788:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b578c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5790:	03e00008 */ 	jr	$ra
/*  f0b5794:	8dc21768 */ 	lw	$v0,0x1768($t6)
);

GLOBAL_ASM(
glabel func0f0b5798
/*  f0b5798:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b579c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b57a0:	03e00008 */ 	jr	$ra
/*  f0b57a4:	adc4175c */ 	sw	$a0,0x175c($t6)
);

GLOBAL_ASM(
glabel func0f0b57a8
/*  f0b57a8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b57ac:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b57b0:	03e00008 */ 	jr	$ra
/*  f0b57b4:	8dc2175c */ 	lw	$v0,0x175c($t6)
);

GLOBAL_ASM(
glabel func0f0b57b8
/*  f0b57b8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b57bc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b57c0:	03e00008 */ 	jr	$ra
/*  f0b57c4:	c5c01774 */ 	lwc1	$f0,0x1774($t6)
/*  f0b57c8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b57cc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b57d0:	03e00008 */ 	jr	$ra
/*  f0b57d4:	8dc21778 */ 	lw	$v0,0x1778($t6)
);

GLOBAL_ASM(
glabel func0f0b57d8
/*  f0b57d8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b57dc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b57e0:	03e00008 */ 	jr	$ra
/*  f0b57e4:	c5c01704 */ 	lwc1	$f0,0x1704($t6)
);

GLOBAL_ASM(
glabel func0f0b57e8
/*  f0b57e8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b57ec:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b57f0:	03e00008 */ 	jr	$ra
/*  f0b57f4:	c5c01708 */ 	lwc1	$f0,0x1708($t6)
);

GLOBAL_ASM(
glabel func0f0b57f8
/*  f0b57f8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b57fc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5800:	03e00008 */ 	jr	$ra
/*  f0b5804:	c5c0170c */ 	lwc1	$f0,0x170c($t6)
);

GLOBAL_ASM(
glabel func0f0b5808
/*  f0b5808:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b580c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5810:	03e00008 */ 	jr	$ra
/*  f0b5814:	c5c01710 */ 	lwc1	$f0,0x1710($t6)
/*  f0b5818:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b581c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5820:	03e00008 */ 	jr	$ra
/*  f0b5824:	c5c01718 */ 	lwc1	$f0,0x1718($t6)
);

GLOBAL_ASM(
glabel func0f0b5828
/*  f0b5828:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b582c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5830:	03e00008 */ 	jr	$ra
/*  f0b5834:	c5c0171c */ 	lwc1	$f0,0x171c($t6)
);

GLOBAL_ASM(
glabel func0f0b5838
/*  f0b5838:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x284)
/*  f0b583c:	8c84a244 */ 	lw	$a0,%lo(g_Vars+0x284)($a0)
/*  f0b5840:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0b5844:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b5848:	c486172c */ 	lwc1	$f6,0x172c($a0)
/*  f0b584c:	c4841724 */ 	lwc1	$f4,0x1724($a0)
/*  f0b5850:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b5854:	44815000 */ 	mtc1	$at,$f10
/*  f0b5858:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f0b585c:	8c82174c */ 	lw	$v0,0x174c($a0)
/*  f0b5860:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0b5864:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0b5868:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0b586c:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f0b5870:	0c012974 */ 	jal	sqrtf
/*  f0b5874:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0b5878:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b587c:	44812000 */ 	mtc1	$at,$f4
/*  f0b5880:	c7a20024 */ 	lwc1	$f2,0x24($sp)
/*  f0b5884:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f0b5888:	46002483 */ 	div.s	$f18,$f4,$f0
/*  f0b588c:	3c03800a */ 	lui	$v1,%hi(var8009dd20)
/*  f0b5890:	2463dd20 */ 	addiu	$v1,$v1,%lo(var8009dd20)
/*  f0b5894:	3c01800a */ 	lui	$at,0x800a
/*  f0b5898:	3c05800a */ 	lui	$a1,%hi(var8009dd30)
/*  f0b589c:	24a5dd30 */ 	addiu	$a1,$a1,%lo(var8009dd30)
/*  f0b58a0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0b58a4:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f0b58a8:	46009307 */ 	neg.s	$f12,$f18
/*  f0b58ac:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f0b58b0:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f0b58b4:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0b58b8:	46006407 */ 	neg.s	$f16,$f12
/*  f0b58bc:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0b58c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b58c4:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f0b58c8:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0b58cc:	e4660000 */ 	swc1	$f6,0x0($v1)
/*  f0b58d0:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*  f0b58d4:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f0b58d8:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0b58dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b58e0:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0b58e4:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0b58e8:	e46a0004 */ 	swc1	$f10,0x4($v1)
/*  f0b58ec:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f0b58f0:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f0b58f4:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0b58f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b58fc:	46068282 */ 	mul.s	$f10,$f16,$f6
/*  f0b5900:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f0b5904:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0b5908:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f0b590c:	c4480030 */ 	lwc1	$f8,0x30($v0)
/*  f0b5910:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f0b5914:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0b5918:	c4460034 */ 	lwc1	$f6,0x34($v0)
/*  f0b591c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0b5920:	c4460038 */ 	lwc1	$f6,0x38($v0)
/*  f0b5924:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0b5928:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0b592c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0b5930:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0b5934:	e426dd2c */ 	swc1	$f6,-0x22d4($at)
/*  f0b5938:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f0b593c:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0b5940:	3c01800a */ 	lui	$at,0x800a
/*  f0b5944:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0b5948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b594c:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f0b5950:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0b5954:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f0b5958:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f0b595c:	c4460014 */ 	lwc1	$f6,0x14($v0)
/*  f0b5960:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0b5964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5968:	46066282 */ 	mul.s	$f10,$f12,$f6
/*  f0b596c:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*  f0b5970:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0b5974:	e4a40004 */ 	swc1	$f4,0x4($a1)
/*  f0b5978:	c4480018 */ 	lwc1	$f8,0x18($v0)
/*  f0b597c:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f0b5980:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0b5984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5988:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0b598c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f0b5990:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0b5994:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f0b5998:	c4460030 */ 	lwc1	$f6,0x30($v0)
/*  f0b599c:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f0b59a0:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0b59a4:	c4440034 */ 	lwc1	$f4,0x34($v0)
/*  f0b59a8:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0b59ac:	c4440038 */ 	lwc1	$f4,0x38($v0)
/*  f0b59b0:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0b59b4:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f0b59b8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0b59bc:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0b59c0:	e424dd3c */ 	swc1	$f4,-0x22c4($at)
/*  f0b59c4:	c48a1720 */ 	lwc1	$f10,0x1720($a0)
/*  f0b59c8:	c4881728 */ 	lwc1	$f8,0x1728($a0)
/*  f0b59cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b59d0:	46005187 */ 	neg.s	$f6,$f10
/*  f0b59d4:	44815000 */ 	mtc1	$at,$f10
/*  f0b59d8:	46083382 */ 	mul.s	$f14,$f6,$f8
/*  f0b59dc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0b59e0:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f0b59e4:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f0b59e8:	0c012974 */ 	jal	sqrtf
/*  f0b59ec:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f0b59f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b59f4:	44813000 */ 	mtc1	$at,$f6
/*  f0b59f8:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*  f0b59fc:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f0b5a00:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f0b5a04:	3c03800a */ 	lui	$v1,%hi(var8009dd40)
/*  f0b5a08:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0b5a0c:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f0b5a10:	2463dd40 */ 	addiu	$v1,$v1,%lo(var8009dd40)
/*  f0b5a14:	3c01800a */ 	lui	$at,0x800a
/*  f0b5a18:	3c04800a */ 	lui	$a0,%hi(var8009dd50)
/*  f0b5a1c:	2484dd50 */ 	addiu	$a0,$a0,%lo(var8009dd50)
/*  f0b5a20:	46127382 */ 	mul.s	$f14,$f14,$f18
/*  f0b5a24:	46009307 */ 	neg.s	$f12,$f18
/*  f0b5a28:	46086102 */ 	mul.s	$f4,$f12,$f8
/*  f0b5a2c:	46006407 */ 	neg.s	$f16,$f12
/*  f0b5a30:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*  f0b5a34:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0b5a38:	e4680000 */ 	swc1	$f8,0x0($v1)
/*  f0b5a3c:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f0b5a40:	c4460024 */ 	lwc1	$f6,0x24($v0)
/*  f0b5a44:	460a6102 */ 	mul.s	$f4,$f12,$f10
/*  f0b5a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5a4c:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0b5a50:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f0b5a54:	e46a0004 */ 	swc1	$f10,0x4($v1)
/*  f0b5a58:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0b5a5c:	c4480028 */ 	lwc1	$f8,0x28($v0)
/*  f0b5a60:	46066102 */ 	mul.s	$f4,$f12,$f6
/*  f0b5a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5a68:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0b5a6c:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f0b5a70:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0b5a74:	e4660008 */ 	swc1	$f6,0x8($v1)
/*  f0b5a78:	c4440030 */ 	lwc1	$f4,0x30($v0)
/*  f0b5a7c:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f0b5a80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b5a84:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f0b5a88:	c4480034 */ 	lwc1	$f8,0x34($v0)
/*  f0b5a8c:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0b5a90:	c4480038 */ 	lwc1	$f8,0x38($v0)
/*  f0b5a94:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0b5a98:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0b5a9c:	3c03800a */ 	lui	$v1,%hi(var8009dd60)
/*  f0b5aa0:	2463dd60 */ 	addiu	$v1,$v1,%lo(var8009dd60)
/*  f0b5aa4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0b5aa8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b5aac:	e428dd4c */ 	swc1	$f8,-0x22b4($at)
/*  f0b5ab0:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0b5ab4:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f0b5ab8:	3c01800a */ 	lui	$at,0x800a
/*  f0b5abc:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f0b5ac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5ac4:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0b5ac8:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f0b5acc:	e48a0000 */ 	swc1	$f10,0x0($a0)
/*  f0b5ad0:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0b5ad4:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f0b5ad8:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f0b5adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5ae0:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0b5ae4:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0b5ae8:	e4860004 */ 	swc1	$f6,0x4($a0)
/*  f0b5aec:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b5af0:	c44a0028 */ 	lwc1	$f10,0x28($v0)
/*  f0b5af4:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f0b5af8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5afc:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*  f0b5b00:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0b5b04:	e428dd58 */ 	swc1	$f8,-0x22a8($at)
/*  f0b5b08:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0b5b0c:	c4440030 */ 	lwc1	$f4,0x30($v0)
/*  f0b5b10:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f0b5b14:	3c01800a */ 	lui	$at,0x800a
/*  f0b5b18:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0b5b1c:	c44a0034 */ 	lwc1	$f10,0x34($v0)
/*  f0b5b20:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0b5b24:	c44a0038 */ 	lwc1	$f10,0x38($v0)
/*  f0b5b28:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0b5b2c:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f0b5b30:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f0b5b34:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0b5b38:	e42add5c */ 	swc1	$f10,-0x22a4($at)
/*  f0b5b3c:	c4460030 */ 	lwc1	$f6,0x30($v0)
/*  f0b5b40:	3c01800a */ 	lui	$at,0x800a
/*  f0b5b44:	46003107 */ 	neg.s	$f4,$f6
/*  f0b5b48:	e4640000 */ 	swc1	$f4,0x0($v1)
/*  f0b5b4c:	c4480034 */ 	lwc1	$f8,0x34($v0)
/*  f0b5b50:	46004287 */ 	neg.s	$f10,$f8
/*  f0b5b54:	e46a0004 */ 	swc1	$f10,0x4($v1)
/*  f0b5b58:	c4460038 */ 	lwc1	$f6,0x38($v0)
/*  f0b5b5c:	46003107 */ 	neg.s	$f4,$f6
/*  f0b5b60:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f0b5b64:	c44a0030 */ 	lwc1	$f10,0x30($v0)
/*  f0b5b68:	c4480020 */ 	lwc1	$f8,0x20($v0)
/*  f0b5b6c:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f0b5b70:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0b5b74:	c4480034 */ 	lwc1	$f8,0x34($v0)
/*  f0b5b78:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f0b5b7c:	c4480038 */ 	lwc1	$f8,0x38($v0)
/*  f0b5b80:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0b5b84:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f0b5b88:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0b5b8c:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0b5b90:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0b5b94:	03e00008 */ 	jr	$ra
/*  f0b5b98:	e428dd6c */ 	swc1	$f8,-0x2294($at)
);

GLOBAL_ASM(
glabel func0f0b5b9c
/*  f0b5b9c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b5ba0:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b5ba4:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f0b5ba8:	c48e0004 */ 	lwc1	$f14,0x4($a0)
/*  f0b5bac:	8dc2174c */ 	lw	$v0,0x174c($t6)
/*  f0b5bb0:	c4800008 */ 	lwc1	$f0,0x8($a0)
/*  f0b5bb4:	3c01800a */ 	lui	$at,0x800a
/*  f0b5bb8:	c4480020 */ 	lwc1	$f8,0x20($v0)
/*  f0b5bbc:	c4500024 */ 	lwc1	$f16,0x24($v0)
/*  f0b5bc0:	44856000 */ 	mtc1	$a1,$f12
/*  f0b5bc4:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0b5bc8:	c4480028 */ 	lwc1	$f8,0x28($v0)
/*  f0b5bcc:	c424dd6c */ 	lwc1	$f4,-0x2294($at)
/*  f0b5bd0:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f0b5bd4:	3c02800a */ 	lui	$v0,%hi(var8009dd40)
/*  f0b5bd8:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f0b5bdc:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f0b5be0:	2442dd40 */ 	addiu	$v0,$v0,%lo(var8009dd40)
/*  f0b5be4:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f0b5be8:	46048280 */ 	add.s	$f10,$f16,$f4
/*  f0b5bec:	460a303c */ 	c.lt.s	$f6,$f10
/*  f0b5bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5bf4:	45020004 */ 	bc1fl	.L0f0b5c08
/*  f0b5bf8:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f0b5bfc:	03e00008 */ 	jr	$ra
/*  f0b5c00:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5c04:	c4500000 */ 	lwc1	$f16,0x0($v0)
.L0f0b5c08:
/*  f0b5c08:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0b5c0c:	3c01800a */ 	lui	$at,0x800a
/*  f0b5c10:	46028102 */ 	mul.s	$f4,$f16,$f2
/*  f0b5c14:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f0b5c18:	c432dd4c */ 	lwc1	$f18,-0x22b4($at)
/*  f0b5c1c:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0b5c20:	3c02800a */ 	lui	$v0,%hi(var8009dd50)
/*  f0b5c24:	460c9200 */ 	add.s	$f8,$f18,$f12
/*  f0b5c28:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0b5c2c:	2442dd50 */ 	addiu	$v0,$v0,%lo(var8009dd50)
/*  f0b5c30:	460a2480 */ 	add.s	$f18,$f4,$f10
/*  f0b5c34:	46123100 */ 	add.s	$f4,$f6,$f18
/*  f0b5c38:	4604403c */ 	c.lt.s	$f8,$f4
/*  f0b5c3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5c40:	45020004 */ 	bc1fl	.L0f0b5c54
/*  f0b5c44:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f0b5c48:	03e00008 */ 	jr	$ra
/*  f0b5c4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5c50:	c4460000 */ 	lwc1	$f6,0x0($v0)
.L0f0b5c54:
/*  f0b5c54:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f0b5c58:	3c01800a */ 	lui	$at,0x800a
/*  f0b5c5c:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f0b5c60:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0b5c64:	c42add5c */ 	lwc1	$f10,-0x22a4($at)
/*  f0b5c68:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0b5c6c:	3c02800a */ 	lui	$v0,%hi(var8009dd20)
/*  f0b5c70:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f0b5c74:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0b5c78:	2442dd20 */ 	addiu	$v0,$v0,%lo(var8009dd20)
/*  f0b5c7c:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0b5c80:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0b5c84:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0b5c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5c8c:	45020004 */ 	bc1fl	.L0f0b5ca0
/*  f0b5c90:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0b5c94:	03e00008 */ 	jr	$ra
/*  f0b5c98:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5c9c:	c4480000 */ 	lwc1	$f8,0x0($v0)
.L0f0b5ca0:
/*  f0b5ca0:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f0b5ca4:	3c01800a */ 	lui	$at,0x800a
/*  f0b5ca8:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0b5cac:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b5cb0:	c424dd2c */ 	lwc1	$f4,-0x22d4($at)
/*  f0b5cb4:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f0b5cb8:	3c02800a */ 	lui	$v0,%hi(var8009dd30)
/*  f0b5cbc:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f0b5cc0:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f0b5cc4:	2442dd30 */ 	addiu	$v0,$v0,%lo(var8009dd30)
/*  f0b5cc8:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f0b5ccc:	46048280 */ 	add.s	$f10,$f16,$f4
/*  f0b5cd0:	460a303c */ 	c.lt.s	$f6,$f10
/*  f0b5cd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5cd8:	45020004 */ 	bc1fl	.L0f0b5cec
/*  f0b5cdc:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f0b5ce0:	03e00008 */ 	jr	$ra
/*  f0b5ce4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5ce8:	c4500000 */ 	lwc1	$f16,0x0($v0)
.L0f0b5cec:
/*  f0b5cec:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0b5cf0:	3c01800a */ 	lui	$at,0x800a
/*  f0b5cf4:	46028102 */ 	mul.s	$f4,$f16,$f2
/*  f0b5cf8:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f0b5cfc:	c432dd3c */ 	lwc1	$f18,-0x22c4($at)
/*  f0b5d00:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0b5d04:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0b5d08:	460c9200 */ 	add.s	$f8,$f18,$f12
/*  f0b5d0c:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0b5d10:	460a2480 */ 	add.s	$f18,$f4,$f10
/*  f0b5d14:	46123100 */ 	add.s	$f4,$f6,$f18
/*  f0b5d18:	4604403c */ 	c.lt.s	$f8,$f4
/*  f0b5d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5d20:	45000003 */ 	bc1f	.L0f0b5d30
/*  f0b5d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5d28:	03e00008 */ 	jr	$ra
/*  f0b5d2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b5d30:
/*  f0b5d30:	03e00008 */ 	jr	$ra
/*  f0b5d34:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b5d38
/*  f0b5d38:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0b5d3c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0b5d40:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0b5d44:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0b5d48:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b5d4c:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0b5d50:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0b5d54:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f0b5d58:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5d5c:	3c01800a */ 	lui	$at,0x800a
/*  f0b5d60:	4485b000 */ 	mtc1	$a1,$f22
/*  f0b5d64:	c424dd6c */ 	lwc1	$f4,-0x2294($at)
/*  f0b5d68:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0b5d6c:	c4480020 */ 	lwc1	$f8,0x20($v0)
/*  f0b5d70:	46162180 */ 	add.s	$f6,$f4,$f22
/*  f0b5d74:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f0b5d78:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0b5d7c:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f0b5d80:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0b5d84:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f0b5d88:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f0b5d8c:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f0b5d90:	c4520028 */ 	lwc1	$f18,0x28($v0)
/*  f0b5d94:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0b5d98:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0b5d9c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0b5da0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5da4:	45020004 */ 	bc1fl	.L0f0b5db8
/*  f0b5da8:	85cf0004 */ 	lh	$t7,0x4($t6)
/*  f0b5dac:	10000126 */ 	beqz	$zero,.L0f0b6248
/*  f0b5db0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b5db4:	85cf0004 */ 	lh	$t7,0x4($t6)
.L0f0b5db8:
/*  f0b5db8:	c604170c */ 	lwc1	$f4,0x170c($s0)
/*  f0b5dbc:	c6081720 */ 	lwc1	$f8,0x1720($s0)
/*  f0b5dc0:	448f9000 */ 	mtc1	$t7,$f18
/*  f0b5dc4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b5dc8:	4481a000 */ 	mtc1	$at,$f20
/*  f0b5dcc:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0b5dd0:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0b5dd4:	c60a1728 */ 	lwc1	$f10,0x1728($s0)
/*  f0b5dd8:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0b5ddc:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0b5de0:	460a9082 */ 	mul.s	$f2,$f18,$f10
/*  f0b5de4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5de8:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0b5dec:	e7a20038 */ 	swc1	$f2,0x38($sp)
/*  f0b5df0:	0c012974 */ 	jal	sqrtf
/*  f0b5df4:	46142300 */ 	add.s	$f12,$f4,$f20
/*  f0b5df8:	4600a303 */ 	div.s	$f12,$f20,$f0
/*  f0b5dfc:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0b5e00:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0b5e04:	c7a20038 */ 	lwc1	$f2,0x38($sp)
/*  f0b5e08:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0b5e0c:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5e10:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f0b5e14:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f0b5e18:	c4520020 */ 	lwc1	$f18,0x20($v0)
/*  f0b5e1c:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0b5e20:	46006387 */ 	neg.s	$f14,$f12
/*  f0b5e24:	46067202 */ 	mul.s	$f8,$f14,$f6
/*  f0b5e28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5e2c:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f0b5e30:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0b5e34:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f0b5e38:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5e3c:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0b5e40:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f0b5e44:	46067482 */ 	mul.s	$f18,$f14,$f6
/*  f0b5e48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5e4c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0b5e50:	460a9181 */ 	sub.s	$f6,$f18,$f10
/*  f0b5e54:	e7a60058 */ 	swc1	$f6,0x58($sp)
/*  f0b5e58:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5e5c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b5e60:	c44a0028 */ 	lwc1	$f10,0x28($v0)
/*  f0b5e64:	46087482 */ 	mul.s	$f18,$f14,$f8
/*  f0b5e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5e6c:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0b5e70:	46089281 */ 	sub.s	$f10,$f18,$f8
/*  f0b5e74:	e7aa005c */ 	swc1	$f10,0x5c($sp)
/*  f0b5e78:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5e7c:	c4520030 */ 	lwc1	$f18,0x30($v0)
/*  f0b5e80:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f0b5e84:	c4520034 */ 	lwc1	$f18,0x34($v0)
/*  f0b5e88:	46123482 */ 	mul.s	$f18,$f6,$f18
/*  f0b5e8c:	46124200 */ 	add.s	$f8,$f8,$f18
/*  f0b5e90:	c4520038 */ 	lwc1	$f18,0x38($v0)
/*  f0b5e94:	460a9482 */ 	mul.s	$f18,$f18,$f10
/*  f0b5e98:	46089400 */ 	add.s	$f16,$f18,$f8
/*  f0b5e9c:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f0b5ea0:	46082102 */ 	mul.s	$f4,$f4,$f8
/*  f0b5ea4:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f0b5ea8:	46168480 */ 	add.s	$f18,$f16,$f22
/*  f0b5eac:	46083182 */ 	mul.s	$f6,$f6,$f8
/*  f0b5eb0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b5eb4:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0b5eb8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0b5ebc:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0b5ec0:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0b5ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5ec8:	45000003 */ 	bc1f	.L0f0b5ed8
/*  f0b5ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5ed0:	100000dd */ 	beqz	$zero,.L0f0b6248
/*  f0b5ed4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b5ed8:
/*  f0b5ed8:	87190008 */ 	lh	$t9,0x8($t8)
/*  f0b5edc:	c608170c */ 	lwc1	$f8,0x170c($s0)
/*  f0b5ee0:	c6041720 */ 	lwc1	$f4,0x1720($s0)
/*  f0b5ee4:	44995000 */ 	mtc1	$t9,$f10
/*  f0b5ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5eec:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0b5ef0:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0b5ef4:	c6081728 */ 	lwc1	$f8,0x1728($s0)
/*  f0b5ef8:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0b5efc:	46049281 */ 	sub.s	$f10,$f18,$f4
/*  f0b5f00:	46005187 */ 	neg.s	$f6,$f10
/*  f0b5f04:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f0b5f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5f0c:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f0b5f10:	e7a20038 */ 	swc1	$f2,0x38($sp)
/*  f0b5f14:	0c012974 */ 	jal	sqrtf
/*  f0b5f18:	46149300 */ 	add.s	$f12,$f18,$f20
/*  f0b5f1c:	4600a303 */ 	div.s	$f12,$f20,$f0
/*  f0b5f20:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0b5f24:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0b5f28:	c7a20038 */ 	lwc1	$f2,0x38($sp)
/*  f0b5f2c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0b5f30:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5f34:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f0b5f38:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f0b5f3c:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f0b5f40:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0b5f44:	46006387 */ 	neg.s	$f14,$f12
/*  f0b5f48:	46007387 */ 	neg.s	$f14,$f14
/*  f0b5f4c:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f0b5f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5f54:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0b5f58:	46085481 */ 	sub.s	$f18,$f10,$f8
/*  f0b5f5c:	e7b20044 */ 	swc1	$f18,0x44($sp)
/*  f0b5f60:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5f64:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0b5f68:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*  f0b5f6c:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0b5f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5f74:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0b5f78:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0b5f7c:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f0b5f80:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5f84:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0b5f88:	c4480028 */ 	lwc1	$f8,0x28($v0)
/*  f0b5f8c:	460a7182 */ 	mul.s	$f6,$f14,$f10
/*  f0b5f90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5f94:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0b5f98:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0b5f9c:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f0b5fa0:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b5fa4:	c4460030 */ 	lwc1	$f6,0x30($v0)
/*  f0b5fa8:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f0b5fac:	c4460034 */ 	lwc1	$f6,0x34($v0)
/*  f0b5fb0:	46062182 */ 	mul.s	$f6,$f4,$f6
/*  f0b5fb4:	46065280 */ 	add.s	$f10,$f10,$f6
/*  f0b5fb8:	c4460038 */ 	lwc1	$f6,0x38($v0)
/*  f0b5fbc:	46083182 */ 	mul.s	$f6,$f6,$f8
/*  f0b5fc0:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0b5fc4:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0b5fc8:	460a9482 */ 	mul.s	$f18,$f18,$f10
/*  f0b5fcc:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f0b5fd0:	46168180 */ 	add.s	$f6,$f16,$f22
/*  f0b5fd4:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f0b5fd8:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0b5fdc:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f0b5fe0:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f0b5fe4:	460a2480 */ 	add.s	$f18,$f4,$f10
/*  f0b5fe8:	4612303c */ 	c.lt.s	$f6,$f18
/*  f0b5fec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5ff0:	45000003 */ 	bc1f	.L0f0b6000
/*  f0b5ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b5ff8:	10000093 */ 	beqz	$zero,.L0f0b6248
/*  f0b5ffc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b6000:
/*  f0b6000:	85090006 */ 	lh	$t1,0x6($t0)
/*  f0b6004:	c60a1710 */ 	lwc1	$f10,0x1710($s0)
/*  f0b6008:	c6121724 */ 	lwc1	$f18,0x1724($s0)
/*  f0b600c:	44894000 */ 	mtc1	$t1,$f8
/*  f0b6010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6014:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0b6018:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0b601c:	c604172c */ 	lwc1	$f4,0x172c($s0)
/*  f0b6020:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0b6024:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f0b6028:	46044082 */ 	mul.s	$f2,$f8,$f4
/*  f0b602c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6030:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0b6034:	e7a20034 */ 	swc1	$f2,0x34($sp)
/*  f0b6038:	0c012974 */ 	jal	sqrtf
/*  f0b603c:	46145300 */ 	add.s	$f12,$f10,$f20
/*  f0b6040:	4600a303 */ 	div.s	$f12,$f20,$f0
/*  f0b6044:	c7a20034 */ 	lwc1	$f2,0x34($sp)
/*  f0b6048:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0b604c:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0b6050:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0b6054:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f0b6058:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b605c:	c4520020 */ 	lwc1	$f18,0x20($v0)
/*  f0b6060:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0b6064:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0b6068:	46006387 */ 	neg.s	$f14,$f12
/*  f0b606c:	46007387 */ 	neg.s	$f14,$f14
/*  f0b6070:	46029182 */ 	mul.s	$f6,$f18,$f2
/*  f0b6074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6078:	46087102 */ 	mul.s	$f4,$f14,$f8
/*  f0b607c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0b6080:	e7aa0074 */ 	swc1	$f10,0x74($sp)
/*  f0b6084:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b6088:	c4520024 */ 	lwc1	$f18,0x24($v0)
/*  f0b608c:	c4460014 */ 	lwc1	$f6,0x14($v0)
/*  f0b6090:	46029202 */ 	mul.s	$f8,$f18,$f2
/*  f0b6094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6098:	46067102 */ 	mul.s	$f4,$f14,$f6
/*  f0b609c:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0b60a0:	e7b20078 */ 	swc1	$f18,0x78($sp)
/*  f0b60a4:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b60a8:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f0b60ac:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f0b60b0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0b60b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b60b8:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0b60bc:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0b60c0:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0b60c4:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b60c8:	c4480030 */ 	lwc1	$f8,0x30($v0)
/*  f0b60cc:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0b60d0:	c4480034 */ 	lwc1	$f8,0x34($v0)
/*  f0b60d4:	46089202 */ 	mul.s	$f8,$f18,$f8
/*  f0b60d8:	46083180 */ 	add.s	$f6,$f6,$f8
/*  f0b60dc:	c4480038 */ 	lwc1	$f8,0x38($v0)
/*  f0b60e0:	46044202 */ 	mul.s	$f8,$f8,$f4
/*  f0b60e4:	46064400 */ 	add.s	$f16,$f8,$f6
/*  f0b60e8:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f0b60ec:	46065282 */ 	mul.s	$f10,$f10,$f6
/*  f0b60f0:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f0b60f4:	46168200 */ 	add.s	$f8,$f16,$f22
/*  f0b60f8:	46069482 */ 	mul.s	$f18,$f18,$f6
/*  f0b60fc:	46125180 */ 	add.s	$f6,$f10,$f18
/*  f0b6100:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f0b6104:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f0b6108:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0b610c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0b6110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6114:	45000003 */ 	bc1f	.L0f0b6124
/*  f0b6118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b611c:	1000004a */ 	beqz	$zero,.L0f0b6248
/*  f0b6120:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b6124:
/*  f0b6124:	854b000a */ 	lh	$t3,0xa($t2)
/*  f0b6128:	c6061710 */ 	lwc1	$f6,0x1710($s0)
/*  f0b612c:	c60a1724 */ 	lwc1	$f10,0x1724($s0)
/*  f0b6130:	448b2000 */ 	mtc1	$t3,$f4
/*  f0b6134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6138:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0b613c:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f0b6140:	c606172c */ 	lwc1	$f6,0x172c($s0)
/*  f0b6144:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0b6148:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f0b614c:	46002487 */ 	neg.s	$f18,$f4
/*  f0b6150:	46069082 */ 	mul.s	$f2,$f18,$f6
/*  f0b6154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6158:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0b615c:	e7a20034 */ 	swc1	$f2,0x34($sp)
/*  f0b6160:	0c012974 */ 	jal	sqrtf
/*  f0b6164:	46145300 */ 	add.s	$f12,$f10,$f20
/*  f0b6168:	4600a303 */ 	div.s	$f12,$f20,$f0
/*  f0b616c:	c7a20034 */ 	lwc1	$f2,0x34($sp)
/*  f0b6170:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0b6174:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0b6178:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0b617c:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b6180:	c4480020 */ 	lwc1	$f8,0x20($v0)
/*  f0b6184:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f0b6188:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0b618c:	46006387 */ 	neg.s	$f14,$f12
/*  f0b6190:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0b6194:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6198:	46127182 */ 	mul.s	$f6,$f14,$f18
/*  f0b619c:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0b61a0:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*  f0b61a4:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b61a8:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f0b61ac:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f0b61b0:	46024482 */ 	mul.s	$f18,$f8,$f2
/*  f0b61b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b61b8:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0b61bc:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f0b61c0:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f0b61c4:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b61c8:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f0b61cc:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f0b61d0:	46022482 */ 	mul.s	$f18,$f4,$f2
/*  f0b61d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b61d8:	46067102 */ 	mul.s	$f4,$f14,$f6
/*  f0b61dc:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0b61e0:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*  f0b61e4:	8e02174c */ 	lw	$v0,0x174c($s0)
/*  f0b61e8:	c4520030 */ 	lwc1	$f18,0x30($v0)
/*  f0b61ec:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0b61f0:	c4520034 */ 	lwc1	$f18,0x34($v0)
/*  f0b61f4:	46124482 */ 	mul.s	$f18,$f8,$f18
/*  f0b61f8:	46122100 */ 	add.s	$f4,$f4,$f18
/*  f0b61fc:	c4520038 */ 	lwc1	$f18,0x38($v0)
/*  f0b6200:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0b6204:	46069482 */ 	mul.s	$f18,$f18,$f6
/*  f0b6208:	46049400 */ 	add.s	$f16,$f18,$f4
/*  f0b620c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0b6210:	46045282 */ 	mul.s	$f10,$f10,$f4
/*  f0b6214:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f0b6218:	46168480 */ 	add.s	$f18,$f16,$f22
/*  f0b621c:	46044202 */ 	mul.s	$f8,$f8,$f4
/*  f0b6220:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0b6224:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f0b6228:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0b622c:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0b6230:	460a903c */ 	c.lt.s	$f18,$f10
/*  f0b6234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6238:	45000003 */ 	bc1f	.L0f0b6248
/*  f0b623c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6240:	10000001 */ 	beqz	$zero,.L0f0b6248
/*  f0b6244:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b6248:
/*  f0b6248:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b624c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0b6250:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f0b6254:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0b6258:	03e00008 */ 	jr	$ra
/*  f0b625c:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f0b6260
/*  f0b6260:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0b6264:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b6268:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0b626c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0b6270:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0b6274:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0b6278:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0b627c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0b6280:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0b6284:	84860000 */ 	lh	$a2,0x0($a0)
/*  f0b6288:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0b628c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b6290:	10d20036 */ 	beq	$a2,$s2,.L0f0b636c
/*  f0b6294:	00808025 */ 	or	$s0,$a0,$zero
/*  f0b6298:	3c13800a */ 	lui	$s3,%hi(g_RoomPtrs)
/*  f0b629c:	26734928 */ 	addiu	$s3,$s3,%lo(g_RoomPtrs)
/*  f0b62a0:	2414008c */ 	addiu	$s4,$zero,0x8c
.L0f0b62a4:
/*  f0b62a4:	00d40019 */ 	multu	$a2,$s4
/*  f0b62a8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0b62ac:	00007812 */ 	mflo	$t7
/*  f0b62b0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b62b4:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f0b62b8:	33280004 */ 	andi	$t0,$t9,0x4
/*  f0b62bc:	51000028 */ 	beqzl	$t0,.L0f0b6360
/*  f0b62c0:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0b62c4:	0fc56050 */ 	jal	func0f158140
/*  f0b62c8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0b62cc:	2e230001 */ 	sltiu	$v1,$s1,0x1
/*  f0b62d0:	1060000a */ 	beqz	$v1,.L0f0b62fc
/*  f0b62d4:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0b62d8:	84490004 */ 	lh	$t1,0x4($v0)
/*  f0b62dc:	a7a90038 */ 	sh	$t1,0x38($sp)
/*  f0b62e0:	844a0006 */ 	lh	$t2,0x6($v0)
/*  f0b62e4:	a7aa003a */ 	sh	$t2,0x3a($sp)
/*  f0b62e8:	844b0008 */ 	lh	$t3,0x8($v0)
/*  f0b62ec:	a7ab003c */ 	sh	$t3,0x3c($sp)
/*  f0b62f0:	844c000a */ 	lh	$t4,0xa($v0)
/*  f0b62f4:	10000019 */ 	beqz	$zero,.L0f0b635c
/*  f0b62f8:	a7ac003e */ 	sh	$t4,0x3e($sp)
.L0f0b62fc:
/*  f0b62fc:	84430004 */ 	lh	$v1,0x4($v0)
/*  f0b6300:	87ad0038 */ 	lh	$t5,0x38($sp)
/*  f0b6304:	006d082a */ 	slt	$at,$v1,$t5
/*  f0b6308:	50200003 */ 	beqzl	$at,.L0f0b6318
/*  f0b630c:	84430006 */ 	lh	$v1,0x6($v0)
/*  f0b6310:	a7a30038 */ 	sh	$v1,0x38($sp)
/*  f0b6314:	84430006 */ 	lh	$v1,0x6($v0)
.L0f0b6318:
/*  f0b6318:	87ae003a */ 	lh	$t6,0x3a($sp)
/*  f0b631c:	006e082a */ 	slt	$at,$v1,$t6
/*  f0b6320:	50200003 */ 	beqzl	$at,.L0f0b6330
/*  f0b6324:	84430008 */ 	lh	$v1,0x8($v0)
/*  f0b6328:	a7a3003a */ 	sh	$v1,0x3a($sp)
/*  f0b632c:	84430008 */ 	lh	$v1,0x8($v0)
.L0f0b6330:
/*  f0b6330:	87af003c */ 	lh	$t7,0x3c($sp)
/*  f0b6334:	01e3082a */ 	slt	$at,$t7,$v1
/*  f0b6338:	50200003 */ 	beqzl	$at,.L0f0b6348
/*  f0b633c:	8443000a */ 	lh	$v1,0xa($v0)
/*  f0b6340:	a7a3003c */ 	sh	$v1,0x3c($sp)
/*  f0b6344:	8443000a */ 	lh	$v1,0xa($v0)
.L0f0b6348:
/*  f0b6348:	87b8003e */ 	lh	$t8,0x3e($sp)
/*  f0b634c:	0303082a */ 	slt	$at,$t8,$v1
/*  f0b6350:	50200003 */ 	beqzl	$at,.L0f0b6360
/*  f0b6354:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0b6358:	a7a3003e */ 	sh	$v1,0x3e($sp)
.L0f0b635c:
/*  f0b635c:	86060002 */ 	lh	$a2,0x2($s0)
.L0f0b6360:
/*  f0b6360:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0b6364:	14d2ffcf */ 	bne	$a2,$s2,.L0f0b62a4
/*  f0b6368:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b636c:
/*  f0b636c:	16200003 */ 	bnez	$s1,.L0f0b637c
/*  f0b6370:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0b6374:	10000004 */ 	beqz	$zero,.L0f0b6388
/*  f0b6378:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b637c:
/*  f0b637c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0b6380:	0fc2d74e */ 	jal	func0f0b5d38
/*  f0b6384:	27a60034 */ 	addiu	$a2,$sp,0x34
.L0f0b6388:
/*  f0b6388:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b638c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0b6390:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0b6394:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0b6398:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0b639c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0b63a0:	03e00008 */ 	jr	$ra
/*  f0b63a4:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0b63a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b63ac:	00000000 */ 	sll	$zero,$zero,0x0
);
