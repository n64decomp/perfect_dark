#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_317f0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0c3620
/*  f0c3620:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0c3624:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0c3628:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f0c362c:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f0c3630:	8e8f0284 */ 	lw	$t7,0x284($s4)
/*  f0c3634:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c3638:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0c363c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0c3640:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0c3644:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0c3648:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0c364c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0c3650:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0c3654:	adee01b0 */ 	sw	$t6,0x1b0($t7)
/*  f0c3658:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f0c365c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0c3660:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c3664:	13000003 */ 	beqz	$t8,.L0f0c3674
/*  f0c3668:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c366c:	10000001 */ 	beqz	$zero,.L0f0c3674
/*  f0c3670:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c3674:
/*  f0c3674:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f0c3678:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c367c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c3680:	13200003 */ 	beqz	$t9,.L0f0c3690
/*  f0c3684:	00156880 */ 	sll	$t5,$s5,0x2
/*  f0c3688:	10000001 */ 	beqz	$zero,.L0f0c3690
/*  f0c368c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c3690:
/*  f0c3690:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f0c3694:	028d9021 */ 	addu	$s2,$s4,$t5
/*  f0c3698:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f0c369c:	11000003 */ 	beqz	$t0,.L0f0c36ac
/*  f0c36a0:	241307a4 */ 	addiu	$s3,$zero,0x7a4
/*  f0c36a4:	10000001 */ 	beqz	$zero,.L0f0c36ac
/*  f0c36a8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c36ac:
/*  f0c36ac:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f0c36b0:	11200003 */ 	beqz	$t1,.L0f0c36c0
/*  f0c36b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c36b8:	10000001 */ 	beqz	$zero,.L0f0c36c0
/*  f0c36bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c36c0:
/*  f0c36c0:	00435021 */ 	addu	$t2,$v0,$v1
/*  f0c36c4:	01445821 */ 	addu	$t3,$t2,$a0
/*  f0c36c8:	01656021 */ 	addu	$t4,$t3,$a1
/*  f0c36cc:	59800033 */ 	blezl	$t4,.L0f0c379c
/*  f0c36d0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0c36d4:	8e4e0064 */ 	lw	$t6,0x64($s2)
.L0f0c36d8:
/*  f0c36d8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c36dc:	add61c40 */ 	sw	$s6,0x1c40($t6)
.L0f0c36e0:
/*  f0c36e0:	8e4f0064 */ 	lw	$t7,0x64($s2)
/*  f0c36e4:	01f18021 */ 	addu	$s0,$t7,$s1
/*  f0c36e8:	8e040d84 */ 	lw	$a0,0xd84($s0)
/*  f0c36ec:	26100638 */ 	addiu	$s0,$s0,0x638
/*  f0c36f0:	50800009 */ 	beqzl	$a0,.L0f0c3718
/*  f0c36f4:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0c36f8:	0c00cdfc */ 	jal	func000337f0
/*  f0c36fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3700:	50400005 */ 	beqzl	$v0,.L0f0c3718
/*  f0c3704:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0c3708:	0c00cec9 */ 	jal	func00033b24
/*  f0c370c:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0c3710:	ae00074c */ 	sw	$zero,0x74c($s0)
/*  f0c3714:	263107a4 */ 	addiu	$s1,$s1,0x7a4
.L0f0c3718:
/*  f0c3718:	1633fff1 */ 	bne	$s1,$s3,.L0f0c36e0
/*  f0c371c:	a2000004 */ 	sb	$zero,0x4($s0)
/*  f0c3720:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f0c3724:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0c3728:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0c372c:	13000003 */ 	beqz	$t8,.L0f0c373c
/*  f0c3730:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c3734:	10000001 */ 	beqz	$zero,.L0f0c373c
/*  f0c3738:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c373c:
/*  f0c373c:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f0c3740:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c3744:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c3748:	13200003 */ 	beqz	$t9,.L0f0c3758
/*  f0c374c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c3750:	10000001 */ 	beqz	$zero,.L0f0c3758
/*  f0c3754:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c3758:
/*  f0c3758:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f0c375c:	11000003 */ 	beqz	$t0,.L0f0c376c
/*  f0c3760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3764:	10000001 */ 	beqz	$zero,.L0f0c376c
/*  f0c3768:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c376c:
/*  f0c376c:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f0c3770:	11200003 */ 	beqz	$t1,.L0f0c3780
/*  f0c3774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3778:	10000001 */ 	beqz	$zero,.L0f0c3780
/*  f0c377c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c3780:
/*  f0c3780:	00435021 */ 	addu	$t2,$v0,$v1
/*  f0c3784:	01445821 */ 	addu	$t3,$t2,$a0
/*  f0c3788:	01656021 */ 	addu	$t4,$t3,$a1
/*  f0c378c:	02ac082a */ 	slt	$at,$s5,$t4
/*  f0c3790:	5420ffd1 */ 	bnezl	$at,.L0f0c36d8
/*  f0c3794:	8e4e0064 */ 	lw	$t6,0x64($s2)
/*  f0c3798:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c379c:
/*  f0c379c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0c37a0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0c37a4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0c37a8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0c37ac:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0c37b0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0c37b4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0c37b8:	03e00008 */ 	jr	$ra
/*  f0c37bc:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f0c37c0
/*  f0c37c0:	03e00008 */ 	jr	$ra
/*  f0c37c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c37c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c37cc:	00000000 */ 	sll	$zero,$zero,0x0
);
