#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_013540.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/pad.h"
#include "game/game_157db0.h"
#include "game/game_1668e0.h"
#include "game/game_187770.h"
#include "game/game_197600.h"
#include "library/library_12dc0.h"
#include "library/library_16110.h"

const u32 var7f1a8290[] = {0x3e99999a};
const u32 var7f1a8294[] = {0x3ecccccd};
const u32 var7f1a8298[] = {0x00000000};
const u32 var7f1a829c[] = {0x00000000};
const u32 var7f1a82a0[] = {0x7f014b38};
const u32 var7f1a82a4[] = {0x7f014b40};
const u32 var7f1a82a8[] = {0x7f014b4c};
const u32 var7f1a82ac[] = {0x7f014b58};
const u32 var7f1a82b0[] = {0x7f014b64};
const u32 var7f1a82b4[] = {0x7f014b70};
const u32 var7f1a82b8[] = {0x00000000};
const u32 var7f1a82bc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f013540
/*  f013540:	03e00008 */ 	jr	$ra
/*  f013544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01354c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013550
/*  f013550:	3c0e8009 */ 	lui	$t6,0x8009
/*  f013554:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f013558:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f01355c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f013560:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013564:	150e0005 */ 	bne	$t0,$t6,.L0f01357c
/*  f013568:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f01356c:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f013570:	25ad9fc0 */ 	addiu	$t5,$t5,%lo(g_Vars)
/*  f013574:	10000044 */ 	beqz	$zero,.L0f013688
/*  f013578:	00003025 */ 	or	$a2,$zero,$zero
.L0f01357c:
/*  f01357c:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f013580:	25ad9fc0 */ 	addiu	$t5,$t5,%lo(g_Vars)
/*  f013584:	8daf0298 */ 	lw	$t7,0x298($t5)
/*  f013588:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01358c:	05e30005 */ 	bgezl	$t7,.L0f0135a4
/*  f013590:	8db9006c */ 	lw	$t9,0x6c($t5)
/*  f013594:	8db8029c */ 	lw	$t8,0x29c($t5)
/*  f013598:	07020020 */ 	bltzl	$t8,.L0f01361c
/*  f01359c:	8db8006c */ 	lw	$t8,0x6c($t5)
/*  f0135a0:	8db9006c */ 	lw	$t9,0x6c($t5)
.L0f0135a4:
/*  f0135a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0135a8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0135ac:	13200003 */ 	beqz	$t9,.L0f0135bc
/*  f0135b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0135b4:	10000001 */ 	beqz	$zero,.L0f0135bc
/*  f0135b8:	01002825 */ 	or	$a1,$t0,$zero
.L0f0135bc:
/*  f0135bc:	8dae0068 */ 	lw	$t6,0x68($t5)
/*  f0135c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0135c4:	11c00003 */ 	beqz	$t6,.L0f0135d4
/*  f0135c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0135cc:	10000001 */ 	beqz	$zero,.L0f0135d4
/*  f0135d0:	01002025 */ 	or	$a0,$t0,$zero
.L0f0135d4:
/*  f0135d4:	8daf0064 */ 	lw	$t7,0x64($t5)
/*  f0135d8:	11e00003 */ 	beqz	$t7,.L0f0135e8
/*  f0135dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0135e0:	10000001 */ 	beqz	$zero,.L0f0135e8
/*  f0135e4:	01001825 */ 	or	$v1,$t0,$zero
.L0f0135e8:
/*  f0135e8:	8db80070 */ 	lw	$t8,0x70($t5)
/*  f0135ec:	13000003 */ 	beqz	$t8,.L0f0135fc
/*  f0135f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0135f4:	10000001 */ 	beqz	$zero,.L0f0135fc
/*  f0135f8:	01001025 */ 	or	$v0,$t0,$zero
.L0f0135fc:
/*  f0135fc:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f013600:	03247021 */ 	addu	$t6,$t9,$a0
/*  f013604:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f013608:	55e10004 */ 	bnel	$t7,$at,.L0f01361c
/*  f01360c:	8db8006c */ 	lw	$t8,0x6c($t5)
/*  f013610:	1000001d */ 	beqz	$zero,.L0f013688
/*  f013614:	01003025 */ 	or	$a2,$t0,$zero
/*  f013618:	8db8006c */ 	lw	$t8,0x6c($t5)
.L0f01361c:
/*  f01361c:	8da20068 */ 	lw	$v0,0x68($t5)
/*  f013620:	8da30064 */ 	lw	$v1,0x64($t5)
/*  f013624:	13000003 */ 	beqz	$t8,.L0f013634
/*  f013628:	8da70070 */ 	lw	$a3,0x70($t5)
/*  f01362c:	10000002 */ 	beqz	$zero,.L0f013638
/*  f013630:	01002825 */ 	or	$a1,$t0,$zero
.L0f013634:
/*  f013634:	00002825 */ 	or	$a1,$zero,$zero
.L0f013638:
/*  f013638:	10400003 */ 	beqz	$v0,.L0f013648
/*  f01363c:	00002025 */ 	or	$a0,$zero,$zero
/*  f013640:	10000001 */ 	beqz	$zero,.L0f013648
/*  f013644:	01002025 */ 	or	$a0,$t0,$zero
.L0f013648:
/*  f013648:	10600003 */ 	beqz	$v1,.L0f013658
/*  f01364c:	00001025 */ 	or	$v0,$zero,$zero
/*  f013650:	10000002 */ 	beqz	$zero,.L0f01365c
/*  f013654:	01001825 */ 	or	$v1,$t0,$zero
.L0f013658:
/*  f013658:	00001825 */ 	or	$v1,$zero,$zero
.L0f01365c:
/*  f01365c:	10e00003 */ 	beqz	$a3,.L0f01366c
/*  f013660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013664:	10000001 */ 	beqz	$zero,.L0f01366c
/*  f013668:	01001025 */ 	or	$v0,$t0,$zero
.L0f01366c:
/*  f01366c:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f013670:	03247021 */ 	addu	$t6,$t9,$a0
/*  f013674:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f013678:	29e10002 */ 	slti	$at,$t7,0x2
/*  f01367c:	14200002 */ 	bnez	$at,.L0f013688
/*  f013680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013684:	00003025 */ 	or	$a2,$zero,$zero
.L0f013688:
/*  f013688:	10c00008 */ 	beqz	$a2,.L0f0136ac
/*  f01368c:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f013690:	10c80022 */ 	beq	$a2,$t0,.L0f01371c
/*  f013694:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f013698:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01369c:	10c1003c */ 	beq	$a2,$at,.L0f013790
/*  f0136a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0136a4:	1000003a */ 	beqz	$zero,.L0f013790
/*  f0136a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0136ac:
/*  f0136ac:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f0136b0:	24180050 */ 	addiu	$t8,$zero,0x50
/*  f0136b4:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f0136b8:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0136bc:	3c01800a */ 	lui	$at,0x800a
/*  f0136c0:	ac39cc5c */ 	sw	$t9,-0x33a4($at)
/*  f0136c4:	3c01800a */ 	lui	$at,0x800a
/*  f0136c8:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f0136cc:	ac2ecc60 */ 	sw	$t6,-0x33a0($at)
/*  f0136d0:	3c01800a */ 	lui	$at,0x800a
/*  f0136d4:	ac28cc64 */ 	sw	$t0,-0x339c($at)
/*  f0136d8:	3c01800a */ 	lui	$at,0x800a
/*  f0136dc:	240f0019 */ 	addiu	$t7,$zero,0x19
/*  f0136e0:	ac2fcc68 */ 	sw	$t7,-0x3398($at)
/*  f0136e4:	3c01800a */ 	lui	$at,0x800a
/*  f0136e8:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0136ec:	ac38cc6c */ 	sw	$t8,-0x3394($at)
/*  f0136f0:	3c01800a */ 	lui	$at,0x800a
/*  f0136f4:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f0136f8:	ac39cc70 */ 	sw	$t9,-0x3390($at)
/*  f0136fc:	3c01800a */ 	lui	$at,0x800a
/*  f013700:	240e000f */ 	addiu	$t6,$zero,0xf
/*  f013704:	ac2ecc74 */ 	sw	$t6,-0x338c($at)
/*  f013708:	3c017f1b */ 	lui	$at,%hi(var7f1a8290)
/*  f01370c:	c4248290 */ 	lwc1	$f4,%lo(var7f1a8290)($at)
/*  f013710:	3c01800a */ 	lui	$at,0x800a
/*  f013714:	1000003b */ 	beqz	$zero,.L0f013804
/*  f013718:	e424cc78 */ 	swc1	$f4,-0x3388($at)
.L0f01371c:
/*  f01371c:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f013720:	240f00c8 */ 	addiu	$t7,$zero,0xc8
/*  f013724:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f013728:	24180019 */ 	addiu	$t8,$zero,0x19
/*  f01372c:	3c01800a */ 	lui	$at,0x800a
/*  f013730:	ac38cc5c */ 	sw	$t8,-0x33a4($at)
/*  f013734:	3c01800a */ 	lui	$at,0x800a
/*  f013738:	24190064 */ 	addiu	$t9,$zero,0x64
/*  f01373c:	ac39cc60 */ 	sw	$t9,-0x33a0($at)
/*  f013740:	3c01800a */ 	lui	$at,0x800a
/*  f013744:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f013748:	ac2ecc64 */ 	sw	$t6,-0x339c($at)
/*  f01374c:	3c01800a */ 	lui	$at,0x800a
/*  f013750:	240f0028 */ 	addiu	$t7,$zero,0x28
/*  f013754:	ac2fcc68 */ 	sw	$t7,-0x3398($at)
/*  f013758:	3c01800a */ 	lui	$at,0x800a
/*  f01375c:	24180050 */ 	addiu	$t8,$zero,0x50
/*  f013760:	ac38cc6c */ 	sw	$t8,-0x3394($at)
/*  f013764:	3c01800a */ 	lui	$at,0x800a
/*  f013768:	24190014 */ 	addiu	$t9,$zero,0x14
/*  f01376c:	ac39cc70 */ 	sw	$t9,-0x3390($at)
/*  f013770:	3c01800a */ 	lui	$at,0x800a
/*  f013774:	240e001e */ 	addiu	$t6,$zero,0x1e
/*  f013778:	ac2ecc74 */ 	sw	$t6,-0x338c($at)
/*  f01377c:	3c017f1b */ 	lui	$at,%hi(var7f1a8294)
/*  f013780:	c4268294 */ 	lwc1	$f6,%lo(var7f1a8294)($at)
/*  f013784:	3c01800a */ 	lui	$at,0x800a
/*  f013788:	1000001e */ 	beqz	$zero,.L0f013804
/*  f01378c:	e426cc78 */ 	swc1	$f6,-0x3388($at)
.L0f013790:
/*  f013790:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f013794:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f013798:	240f0168 */ 	addiu	$t7,$zero,0x168
/*  f01379c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0137a0:	24180032 */ 	addiu	$t8,$zero,0x32
/*  f0137a4:	3c01800a */ 	lui	$at,0x800a
/*  f0137a8:	ac38cc5c */ 	sw	$t8,-0x33a4($at)
/*  f0137ac:	3c01800a */ 	lui	$at,0x800a
/*  f0137b0:	24190078 */ 	addiu	$t9,$zero,0x78
/*  f0137b4:	ac39cc60 */ 	sw	$t9,-0x33a0($at)
/*  f0137b8:	3c01800a */ 	lui	$at,0x800a
/*  f0137bc:	240e000a */ 	addiu	$t6,$zero,0xa
/*  f0137c0:	ac2ecc64 */ 	sw	$t6,-0x339c($at)
/*  f0137c4:	3c01800a */ 	lui	$at,0x800a
/*  f0137c8:	240f003c */ 	addiu	$t7,$zero,0x3c
/*  f0137cc:	ac2fcc68 */ 	sw	$t7,-0x3398($at)
/*  f0137d0:	3c01800a */ 	lui	$at,0x800a
/*  f0137d4:	241800b4 */ 	addiu	$t8,$zero,0xb4
/*  f0137d8:	ac38cc6c */ 	sw	$t8,-0x3394($at)
/*  f0137dc:	3c01800a */ 	lui	$at,0x800a
/*  f0137e0:	24190019 */ 	addiu	$t9,$zero,0x19
/*  f0137e4:	ac39cc70 */ 	sw	$t9,-0x3390($at)
/*  f0137e8:	3c01800a */ 	lui	$at,0x800a
/*  f0137ec:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f0137f0:	ac2ecc74 */ 	sw	$t6,-0x338c($at)
/*  f0137f4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0137f8:	44814000 */ 	mtc1	$at,$f8
/*  f0137fc:	3c01800a */ 	lui	$at,0x800a
/*  f013800:	e428cc78 */ 	swc1	$f8,-0x3388($at)
.L0f013804:
/*  f013804:	3c0c800a */ 	lui	$t4,%hi(var8009cc40)
/*  f013808:	258ccc40 */ 	addiu	$t4,$t4,%lo(var8009cc40)
/*  f01380c:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f013810:	3c01800a */ 	lui	$at,0x800a
/*  f013814:	3c0a800a */ 	lui	$t2,%hi(var8009cc4c)
/*  f013818:	ac20cc48 */ 	sw	$zero,-0x33b8($at)
/*  f01381c:	254acc4c */ 	addiu	$t2,$t2,%lo(var8009cc4c)
/*  f013820:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f013824:	3c01800a */ 	lui	$at,0x800a
/*  f013828:	ac20cc50 */ 	sw	$zero,-0x33b0($at)
/*  f01382c:	3c01800a */ 	lui	$at,0x800a
/*  f013830:	ac20cc54 */ 	sw	$zero,-0x33ac($at)
/*  f013834:	3c01800a */ 	lui	$at,0x800a
/*  f013838:	ac20cc58 */ 	sw	$zero,-0x33a8($at)
/*  f01383c:	8daf04b4 */ 	lw	$t7,0x4b4($t5)
/*  f013840:	3c04800a */ 	lui	$a0,%hi(var800a41b0)
/*  f013844:	248441b0 */ 	addiu	$a0,$a0,%lo(var800a41b0)
/*  f013848:	29e1005a */ 	slti	$at,$t7,0x5a
/*  f01384c:	54200003 */ 	bnezl	$at,.L0f01385c
/*  f013850:	8d660000 */ 	lw	$a2,0x0($t3)
/*  f013854:	ad600000 */ 	sw	$zero,0x0($t3)
/*  f013858:	8d660000 */ 	lw	$a2,0x0($t3)
.L0f01385c:
/*  f01385c:	54c00004 */ 	bnezl	$a2,.L0f013870
/*  f013860:	8da302bc */ 	lw	$v1,0x2bc($t5)
/*  f013864:	1000005e */ 	beqz	$zero,.L0f0139e0
/*  f013868:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f01386c:	8da302bc */ 	lw	$v1,0x2bc($t5)
.L0f013870:
/*  f013870:	00061140 */ 	sll	$v0,$a2,0x5
/*  f013874:	00461023 */ 	subu	$v0,$v0,$a2
/*  f013878:	2407fff0 */ 	addiu	$a3,$zero,-16
/*  f01387c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f013880:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f013884:	2442000f */ 	addiu	$v0,$v0,0xf
/*  f013888:	2703000f */ 	addiu	$v1,$t8,0xf
/*  f01388c:	00471024 */ 	and	$v0,$v0,$a3
/*  f013890:	00671824 */ 	and	$v1,$v1,$a3
/*  f013894:	00432021 */ 	addu	$a0,$v0,$v1
/*  f013898:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f01389c:	0c0048f2 */ 	jal	func000123c8
/*  f0138a0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0138a4:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0138a8:	3c04800a */ 	lui	$a0,%hi(var800a41b0)
/*  f0138ac:	3c08800a */ 	lui	$t0,%hi(var800a41b4)
/*  f0138b0:	3c0c800a */ 	lui	$t4,%hi(var8009cc40)
/*  f0138b4:	258ccc40 */ 	addiu	$t4,$t4,%lo(var8009cc40)
/*  f0138b8:	250841b4 */ 	addiu	$t0,$t0,%lo(var800a41b4)
/*  f0138bc:	248441b0 */ 	addiu	$a0,$a0,%lo(var800a41b0)
/*  f0138c0:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0138c4:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f0138c8:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f0138cc:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0138d0:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f0138d4:	3c01800a */ 	lui	$at,0x800a
/*  f0138d8:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f0138dc:	ac2041b8 */ 	sw	$zero,0x41b8($at)
/*  f0138e0:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0138e4:	3c0a800a */ 	lui	$t2,%hi(var8009cc4c)
/*  f0138e8:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f0138ec:	25ad9fc0 */ 	addiu	$t5,$t5,%lo(g_Vars)
/*  f0138f0:	254acc4c */ 	addiu	$t2,$t2,%lo(var8009cc4c)
/*  f0138f4:	19c0002e */ 	blez	$t6,.L0f0139b0
/*  f0138f8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0138fc:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f013900:	00001825 */ 	or	$v1,$zero,$zero
/*  f013904:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f013908:
/*  f013908:	00e37821 */ 	addu	$t7,$a3,$v1
/*  f01390c:	a1e0006d */ 	sb	$zero,0x6d($t7)
/*  f013910:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f013914:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f013918:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f01391c:	a320006e */ 	sb	$zero,0x6e($t9)
/*  f013920:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f013924:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f013928:	8c450070 */ 	lw	$a1,0x70($v0)
/*  f01392c:	00057902 */ 	srl	$t7,$a1,0x4
/*  f013930:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f013934:	0305c826 */ 	xor	$t9,$t8,$a1
/*  f013938:	ac590070 */ 	sw	$t9,0x70($v0)
/*  f01393c:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f013940:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f013944:	904f006f */ 	lbu	$t7,0x6f($v0)
/*  f013948:	31f8ff7f */ 	andi	$t8,$t7,0xff7f
/*  f01394c:	a058006f */ 	sb	$t8,0x6f($v0)
/*  f013950:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f013954:	03237021 */ 	addu	$t6,$t9,$v1
/*  f013958:	a5c90068 */ 	sh	$t1,0x68($t6)
/*  f01395c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f013960:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f013964:	af00005c */ 	sw	$zero,0x5c($t8)
/*  f013968:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f01396c:	03237021 */ 	addu	$t6,$t9,$v1
/*  f013970:	adc00060 */ 	sw	$zero,0x60($t6)
/*  f013974:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f013978:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f01397c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f013980:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f013984:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f013988:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f01398c:	adf90074 */ 	sw	$t9,0x74($t7)
/*  f013990:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f013994:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f013998:	00ce082a */ 	slt	$at,$a2,$t6
/*  f01399c:	0067c021 */ 	addu	$t8,$v1,$a3
/*  f0139a0:	2463007c */ 	addiu	$v1,$v1,0x7c
/*  f0139a4:	1420ffd8 */ 	bnez	$at,.L0f013908
/*  f0139a8:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f0139ac:	00003025 */ 	or	$a2,$zero,$zero
.L0f0139b0:
/*  f0139b0:	8db902bc */ 	lw	$t9,0x2bc($t5)
/*  f0139b4:	1b20000a */ 	blez	$t9,.L0f0139e0
/*  f0139b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0139bc:	8d8f0000 */ 	lw	$t7,0x0($t4)
.L0f0139c0:
/*  f0139c0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0139c4:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f0139c8:	a7000000 */ 	sh	$zero,0x0($t8)
/*  f0139cc:	8dae02bc */ 	lw	$t6,0x2bc($t5)
/*  f0139d0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0139d4:	00ce082a */ 	slt	$at,$a2,$t6
/*  f0139d8:	5420fff9 */ 	bnezl	$at,.L0f0139c0
/*  f0139dc:	8d8f0000 */ 	lw	$t7,0x0($t4)
.L0f0139e0:
/*  f0139e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0139e4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0139e8:	03e00008 */ 	jr	$ra
/*  f0139ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0139f0
/*  f0139f0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0139f4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0139f8:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f0139fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013a00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013a04:	11c00003 */ 	beqz	$t6,.L0f013a14
/*  f013a08:	3c06800a */ 	lui	$a2,%hi(var800a45c0)
/*  f013a0c:	10000002 */ 	beqz	$zero,.L0f013a18
/*  f013a10:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f013a14:
/*  f013a14:	00003825 */ 	or	$a3,$zero,$zero
.L0f013a18:
/*  f013a18:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f013a1c:	24c645c0 */ 	addiu	$a2,$a2,%lo(var800a45c0)
/*  f013a20:	240b00c8 */ 	addiu	$t3,$zero,0xc8
/*  f013a24:	11e00003 */ 	beqz	$t7,.L0f013a34
/*  f013a28:	3c0d8009 */ 	lui	$t5,0x8009
/*  f013a2c:	10000002 */ 	beqz	$zero,.L0f013a38
/*  f013a30:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f013a34:
/*  f013a34:	00001825 */ 	or	$v1,$zero,$zero
.L0f013a38:
/*  f013a38:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f013a3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f013a40:	00001025 */ 	or	$v0,$zero,$zero
/*  f013a44:	13000003 */ 	beqz	$t8,.L0f013a54
/*  f013a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a4c:	10000001 */ 	beqz	$zero,.L0f013a54
/*  f013a50:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f013a54:
/*  f013a54:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f013a58:	13200003 */ 	beqz	$t9,.L0f013a68
/*  f013a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a60:	10000001 */ 	beqz	$zero,.L0f013a68
/*  f013a64:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f013a68:
/*  f013a68:	00444021 */ 	addu	$t0,$v0,$a0
/*  f013a6c:	01034821 */ 	addu	$t1,$t0,$v1
/*  f013a70:	01275021 */ 	addu	$t2,$t1,$a3
/*  f013a74:	016a001a */ 	div	$zero,$t3,$t2
/*  f013a78:	15400002 */ 	bnez	$t2,.L0f013a84
/*  f013a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a80:	0007000d */ 	break	0x7
.L0f013a84:
/*  f013a84:	2401ffff */ 	addiu	$at,$zero,-1
/*  f013a88:	15410004 */ 	bne	$t2,$at,.L0f013a9c
/*  f013a8c:	3c018000 */ 	lui	$at,0x8000
/*  f013a90:	15610002 */ 	bne	$t3,$at,.L0f013a9c
/*  f013a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a98:	0006000d */ 	break	0x6
.L0f013a9c:
/*  f013a9c:	00006012 */ 	mflo	$t4
/*  f013aa0:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f013aa4:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f013aa8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f013aac:	01807025 */ 	or	$t6,$t4,$zero
/*  f013ab0:	15a10006 */ 	bne	$t5,$at,.L0f013acc
/*  f013ab4:	3c04800a */ 	lui	$a0,%hi(var800a45c4)
/*  f013ab8:	05c10003 */ 	bgez	$t6,.L0f013ac8
/*  f013abc:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f013ac0:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f013ac4:	00017843 */ 	sra	$t7,$at,0x1
.L0f013ac8:
/*  f013ac8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f013acc:
/*  f013acc:	8cb804b4 */ 	lw	$t8,0x4b4($a1)
/*  f013ad0:	248445c4 */ 	addiu	$a0,$a0,%lo(var800a45c4)
/*  f013ad4:	2b01005a */ 	slti	$at,$t8,0x5a
/*  f013ad8:	54200003 */ 	bnezl	$at,.L0f013ae8
/*  f013adc:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f013ae0:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f013ae4:	8cc20000 */ 	lw	$v0,0x0($a2)
.L0f013ae8:
/*  f013ae8:	54400004 */ 	bnezl	$v0,.L0f013afc
/*  f013aec:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f013af0:	1000001e */ 	beqz	$zero,.L0f013b6c
/*  f013af4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f013af8:	000220c0 */ 	sll	$a0,$v0,0x3
.L0f013afc:
/*  f013afc:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013b00:	00042080 */ 	sll	$a0,$a0,0x2
/*  f013b04:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013b08:	00042080 */ 	sll	$a0,$a0,0x2
/*  f013b0c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013b10:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f013b14:	0081c824 */ 	and	$t9,$a0,$at
/*  f013b18:	03202025 */ 	or	$a0,$t9,$zero
/*  f013b1c:	0c0048f2 */ 	jal	func000123c8
/*  f013b20:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013b24:	3c06800a */ 	lui	$a2,%hi(var800a45c0)
/*  f013b28:	24c645c0 */ 	addiu	$a2,$a2,%lo(var800a45c0)
/*  f013b2c:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f013b30:	3c04800a */ 	lui	$a0,%hi(var800a45c4)
/*  f013b34:	248445c4 */ 	addiu	$a0,$a0,%lo(var800a45c4)
/*  f013b38:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f013b3c:	1900000b */ 	blez	$t0,.L0f013b6c
/*  f013b40:	00001825 */ 	or	$v1,$zero,$zero
/*  f013b44:	00001025 */ 	or	$v0,$zero,$zero
/*  f013b48:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f013b4c:
/*  f013b4c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f013b50:	01225821 */ 	addu	$t3,$t1,$v0
/*  f013b54:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f013b58:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f013b5c:	2442006c */ 	addiu	$v0,$v0,0x6c
/*  f013b60:	006a082a */ 	slt	$at,$v1,$t2
/*  f013b64:	5420fff9 */ 	bnezl	$at,.L0f013b4c
/*  f013b68:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f013b6c:
/*  f013b6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013b70:	3c018008 */ 	lui	$at,0x8008
/*  f013b74:	ac20fa80 */ 	sw	$zero,-0x580($at)
/*  f013b78:	03e00008 */ 	jr	$ra
/*  f013b7c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f013b80
/*  f013b80:	3c02800b */ 	lui	$v0,%hi(var800aabc8)
/*  f013b84:	3c01800b */ 	lui	$at,0x800b
/*  f013b88:	2442abc8 */ 	addiu	$v0,$v0,%lo(var800aabc8)
/*  f013b8c:	ac20b538 */ 	sw	$zero,-0x4ac8($at)
/*  f013b90:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f013b94:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f013b98:	03e00008 */ 	jr	$ra
/*  f013b9c:	ac40000c */ 	sw	$zero,0xc($v0)
);

GLOBAL_ASM(
glabel func0f013ba0
/*  f013ba0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f013ba4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f013ba8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f013bac:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f013bb0:	3c128008 */ 	lui	$s2,%hi(var8007e3d0)
/*  f013bb4:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f013bb8:	3c158008 */ 	lui	$s5,%hi(var8007e4a0)
/*  f013bbc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f013bc0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f013bc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f013bc8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f013bcc:	26b5e4a0 */ 	addiu	$s5,$s5,%lo(var8007e4a0)
/*  f013bd0:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f013bd4:	2652e3d0 */ 	addiu	$s2,$s2,%lo(var8007e3d0)
.L0f013bd8:
/*  f013bd8:	8e8e006c */ 	lw	$t6,0x6c($s4)
/*  f013bdc:	8e820068 */ 	lw	$v0,0x68($s4)
/*  f013be0:	8e840064 */ 	lw	$a0,0x64($s4)
/*  f013be4:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f013be8:	11c00003 */ 	beqz	$t6,.L0f013bf8
/*  f013bec:	00008025 */ 	or	$s0,$zero,$zero
/*  f013bf0:	10000002 */ 	beqz	$zero,.L0f013bfc
/*  f013bf4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f013bf8:
/*  f013bf8:	00002825 */ 	or	$a1,$zero,$zero
.L0f013bfc:
/*  f013bfc:	10400003 */ 	beqz	$v0,.L0f013c0c
/*  f013c00:	00001825 */ 	or	$v1,$zero,$zero
/*  f013c04:	10000001 */ 	beqz	$zero,.L0f013c0c
/*  f013c08:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f013c0c:
/*  f013c0c:	10800003 */ 	beqz	$a0,.L0f013c1c
/*  f013c10:	00001025 */ 	or	$v0,$zero,$zero
/*  f013c14:	10000002 */ 	beqz	$zero,.L0f013c20
/*  f013c18:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f013c1c:
/*  f013c1c:	00002025 */ 	or	$a0,$zero,$zero
.L0f013c20:
/*  f013c20:	10c00003 */ 	beqz	$a2,.L0f013c30
/*  f013c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013c28:	10000001 */ 	beqz	$zero,.L0f013c30
/*  f013c2c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f013c30:
/*  f013c30:	00447821 */ 	addu	$t7,$v0,$a0
/*  f013c34:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f013c38:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f013c3c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f013c40:	14200004 */ 	bnez	$at,.L0f013c54
/*  f013c44:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013c48:	8e530008 */ 	lw	$s3,0x8($s2)
/*  f013c4c:	1000000a */ 	beqz	$zero,.L0f013c78
/*  f013c50:	8e51000c */ 	lw	$s1,0xc($s2)
.L0f013c54:
/*  f013c54:	8e8804b4 */ 	lw	$t0,0x4b4($s4)
/*  f013c58:	2901005a */ 	slti	$at,$t0,0x5a
/*  f013c5c:	54200005 */ 	bnezl	$at,.L0f013c74
/*  f013c60:	8e530000 */ 	lw	$s3,0x0($s2)
/*  f013c64:	8e530010 */ 	lw	$s3,0x10($s2)
/*  f013c68:	10000003 */ 	beqz	$zero,.L0f013c78
/*  f013c6c:	8e510014 */ 	lw	$s1,0x14($s2)
/*  f013c70:	8e530000 */ 	lw	$s3,0x0($s2)
.L0f013c74:
/*  f013c74:	8e510004 */ 	lw	$s1,0x4($s2)
.L0f013c78:
/*  f013c78:	1a200004 */ 	blez	$s1,.L0f013c8c
/*  f013c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013c80:	0c0048f2 */ 	jal	func000123c8
/*  f013c84:	00112100 */ 	sll	$a0,$s1,0x4
/*  f013c88:	ae420024 */ 	sw	$v0,0x24($s2)
.L0f013c8c:
/*  f013c8c:	1a200007 */ 	blez	$s1,.L0f013cac
/*  f013c90:	00001025 */ 	or	$v0,$zero,$zero
.L0f013c94:
/*  f013c94:	8e490024 */ 	lw	$t1,0x24($s2)
/*  f013c98:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f013c9c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f013ca0:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f013ca4:	1611fffb */ 	bne	$s0,$s1,.L0f013c94
/*  f013ca8:	a540000e */ 	sh	$zero,0xe($t2)
.L0f013cac:
/*  f013cac:	26520034 */ 	addiu	$s2,$s2,0x34
/*  f013cb0:	ae51fffc */ 	sw	$s1,-0x4($s2)
/*  f013cb4:	ae53fff4 */ 	sw	$s3,-0xc($s2)
/*  f013cb8:	1655ffc7 */ 	bne	$s2,$s5,.L0f013bd8
/*  f013cbc:	ae53fff8 */ 	sw	$s3,-0x8($s2)
/*  f013cc0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f013cc4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f013cc8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f013ccc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f013cd0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f013cd4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f013cd8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f013cdc:	03e00008 */ 	jr	$ra
/*  f013ce0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f013ce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013cec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013cf0
/*  f013cf0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013cf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013cf8:	3c04800a */ 	lui	$a0,0x800a
/*  f013cfc:	0fc56c8f */ 	jal	func0f15b23c
/*  f013d00:	8c84a474 */ 	lw	$a0,-0x5b8c($a0)
/*  f013d04:	04410002 */ 	bgez	$v0,.L0f013d10
/*  f013d08:	00401825 */ 	or	$v1,$v0,$zero
/*  f013d0c:	00001825 */ 	or	$v1,$zero,$zero
.L0f013d10:
/*  f013d10:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f013d14:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f013d18:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f013d1c:	3c048008 */ 	lui	$a0,0x8008
/*  f013d20:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f013d24:	3c018006 */ 	lui	$at,0x8006
/*  f013d28:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f013d2c:	a02ed9a0 */ 	sb	$t6,-0x2660($at)
/*  f013d30:	9484fcca */ 	lhu	$a0,-0x336($a0)
/*  f013d34:	0fc59c3f */ 	jal	func0f1670fc
/*  f013d38:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f013d3c:	3c04800a */ 	lui	$a0,%hi(var8009a8a0)
/*  f013d40:	2484a8a0 */ 	addiu	$a0,$a0,%lo(var8009a8a0)
/*  f013d44:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f013d48:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f013d4c:	3c01800a */ 	lui	$at,0x800a
/*  f013d50:	24590004 */ 	addiu	$t9,$v0,0x4
/*  f013d54:	ac38a8a4 */ 	sw	$t8,-0x575c($at)
/*  f013d58:	3c01800a */ 	lui	$at,0x800a
/*  f013d5c:	0fc04f5d */ 	jal	func0f013d74
/*  f013d60:	ac39a8a8 */ 	sw	$t9,-0x5758($at)
/*  f013d64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013d68:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013d6c:	03e00008 */ 	jr	$ra
/*  f013d70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013d74
/*  f013d74:	3c03800a */ 	lui	$v1,0x800a
/*  f013d78:	8c63a8a8 */ 	lw	$v1,-0x5758($v1)
/*  f013d7c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f013d80:	3c0f800a */ 	lui	$t7,0x800a
/*  f013d84:	8defa8a4 */ 	lw	$t7,-0x575c($t7)
/*  f013d88:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f013d8c:	3c04800a */ 	lui	$a0,0x800a
/*  f013d90:	8c84a8a0 */ 	lw	$a0,-0x5760($a0)
/*  f013d94:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f013d98:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f013d9c:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f013da0:	01c41021 */ 	addu	$v0,$t6,$a0
/*  f013da4:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f013da8:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f013dac:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f013db0:	01c42821 */ 	addu	$a1,$t6,$a0
/*  f013db4:	0045082b */ 	sltu	$at,$v0,$a1
/*  f013db8:	10200044 */ 	beqz	$at,.L0f013ecc
/*  f013dbc:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f013dc0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f013dc4:	240a0006 */ 	addiu	$t2,$zero,0x6
/*  f013dc8:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f013dcc:
/*  f013dcc:	1460002c */ 	bnez	$v1,.L0f013e80
/*  f013dd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013dd4:	90430006 */ 	lbu	$v1,0x6($v0)
/*  f013dd8:	90440009 */ 	lbu	$a0,0x9($v0)
/*  f013ddc:	90460007 */ 	lbu	$a2,0x7($v0)
/*  f013de0:	00037840 */ 	sll	$t7,$v1,0x1
/*  f013de4:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f013de8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013dec:	272e000e */ 	addiu	$t6,$t9,0xe
/*  f013df0:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f013df4:	00047840 */ 	sll	$t7,$a0,0x1
/*  f013df8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013dfc:	a04e0006 */ 	sb	$t6,0x6($v0)
/*  f013e00:	9047000a */ 	lbu	$a3,0xa($v0)
/*  f013e04:	272e000e */ 	addiu	$t6,$t9,0xe
/*  f013e08:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f013e0c:	00067840 */ 	sll	$t7,$a2,0x1
/*  f013e10:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e14:	a04e0009 */ 	sb	$t6,0x9($v0)
/*  f013e18:	90480008 */ 	lbu	$t0,0x8($v0)
/*  f013e1c:	272e0010 */ 	addiu	$t6,$t9,0x10
/*  f013e20:	0007c080 */ 	sll	$t8,$a3,0x2
/*  f013e24:	00077840 */ 	sll	$t7,$a3,0x1
/*  f013e28:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e2c:	a04e0007 */ 	sb	$t6,0x7($v0)
/*  f013e30:	9049000b */ 	lbu	$t1,0xb($v0)
/*  f013e34:	272e0010 */ 	addiu	$t6,$t9,0x10
/*  f013e38:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f013e3c:	00087840 */ 	sll	$t7,$t0,0x1
/*  f013e40:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e44:	a04e000a */ 	sb	$t6,0xa($v0)
/*  f013e48:	272e0012 */ 	addiu	$t6,$t9,0x12
/*  f013e4c:	0009c080 */ 	sll	$t8,$t1,0x2
/*  f013e50:	00097840 */ 	sll	$t7,$t1,0x1
/*  f013e54:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e58:	904f0001 */ 	lbu	$t7,0x1($v0)
/*  f013e5c:	a04e0008 */ 	sb	$t6,0x8($v0)
/*  f013e60:	272e0012 */ 	addiu	$t6,$t9,0x12
/*  f013e64:	25f8ffc0 */ 	addiu	$t8,$t7,-64
/*  f013e68:	030a0019 */ 	multu	$t8,$t2
/*  f013e6c:	a04e000b */ 	sb	$t6,0xb($v0)
/*  f013e70:	0000c812 */ 	mflo	$t9
/*  f013e74:	00591021 */ 	addu	$v0,$v0,$t9
/*  f013e78:	10000011 */ 	beqz	$zero,.L0f013ec0
/*  f013e7c:	2442018e */ 	addiu	$v0,$v0,0x18e
.L0f013e80:
/*  f013e80:	15630008 */ 	bne	$t3,$v1,.L0f013ea4
/*  f013e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013e88:	904e0001 */ 	lbu	$t6,0x1($v0)
/*  f013e8c:	25cfffc0 */ 	addiu	$t7,$t6,-64
/*  f013e90:	01ec0019 */ 	multu	$t7,$t4
/*  f013e94:	0000c012 */ 	mflo	$t8
/*  f013e98:	00581021 */ 	addu	$v0,$v0,$t8
/*  f013e9c:	10000008 */ 	beqz	$zero,.L0f013ec0
/*  f013ea0:	24420310 */ 	addiu	$v0,$v0,0x310
.L0f013ea4:
/*  f013ea4:	15a30003 */ 	bne	$t5,$v1,.L0f013eb4
/*  f013ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013eac:	10000004 */ 	beqz	$zero,.L0f013ec0
/*  f013eb0:	2442004c */ 	addiu	$v0,$v0,0x4c
.L0f013eb4:
/*  f013eb4:	56030003 */ 	bnel	$s0,$v1,.L0f013ec4
/*  f013eb8:	0045082b */ 	sltu	$at,$v0,$a1
/*  f013ebc:	24420018 */ 	addiu	$v0,$v0,0x18
.L0f013ec0:
/*  f013ec0:	0045082b */ 	sltu	$at,$v0,$a1
.L0f013ec4:
/*  f013ec4:	5420ffc1 */ 	bnezl	$at,.L0f013dcc
/*  f013ec8:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f013ecc:
/*  f013ecc:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f013ed0:	03e00008 */ 	jr	$ra
/*  f013ed4:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f013ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013edc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013ee0
/*  f013ee0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f013ee4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f013ee8:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f013eec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013ef0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013ef4:	51c00004 */ 	beqzl	$t6,.L0f013f08
/*  f013ef8:	00004825 */ 	or	$t1,$zero,$zero
/*  f013efc:	10000002 */ 	beqz	$zero,.L0f013f08
/*  f013f00:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f013f04:	00004825 */ 	or	$t1,$zero,$zero
.L0f013f08:
/*  f013f08:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f013f0c:	51e00004 */ 	beqzl	$t7,.L0f013f20
/*  f013f10:	00003825 */ 	or	$a3,$zero,$zero
/*  f013f14:	10000002 */ 	beqz	$zero,.L0f013f20
/*  f013f18:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f013f1c:	00003825 */ 	or	$a3,$zero,$zero
.L0f013f20:
/*  f013f20:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f013f24:	53000004 */ 	beqzl	$t8,.L0f013f38
/*  f013f28:	00002825 */ 	or	$a1,$zero,$zero
/*  f013f2c:	10000002 */ 	beqz	$zero,.L0f013f38
/*  f013f30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f013f34:	00002825 */ 	or	$a1,$zero,$zero
.L0f013f38:
/*  f013f38:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f013f3c:	53200004 */ 	beqzl	$t9,.L0f013f50
/*  f013f40:	00001025 */ 	or	$v0,$zero,$zero
/*  f013f44:	10000002 */ 	beqz	$zero,.L0f013f50
/*  f013f48:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f013f4c:	00001025 */ 	or	$v0,$zero,$zero
.L0f013f50:
/*  f013f50:	00457021 */ 	addu	$t6,$v0,$a1
/*  f013f54:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f013f58:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f013f5c:	2b010002 */ 	slti	$at,$t8,0x2
/*  f013f60:	14200005 */ 	bnez	$at,.L0f013f78
/*  f013f64:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013f68:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013f6c:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f013f70:	10000005 */ 	beqz	$zero,.L0f013f88
/*  f013f74:	ad590000 */ 	sw	$t9,0x0($t2)
.L0f013f78:
/*  f013f78:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013f7c:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013f80:	240e0078 */ 	addiu	$t6,$zero,0x78
/*  f013f84:	ad4e0000 */ 	sw	$t6,0x0($t2)
.L0f013f88:
/*  f013f88:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f013f8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013f90:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013f94:	348f000f */ 	ori	$t7,$a0,0xf
/*  f013f98:	0c0048f2 */ 	jal	func000123c8
/*  f013f9c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f013fa0:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013fa4:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013fa8:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f013fac:	3c0d800a */ 	lui	$t5,%hi(var800a6660)
/*  f013fb0:	25ad6660 */ 	addiu	$t5,$t5,%lo(var800a6660)
/*  f013fb4:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f013fb8:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f013fbc:	348e000f */ 	ori	$t6,$a0,0xf
/*  f013fc0:	ada20000 */ 	sw	$v0,0x0($t5)
/*  f013fc4:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f013fc8:	0c0048f2 */ 	jal	func000123c8
/*  f013fcc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013fd0:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013fd4:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013fd8:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f013fdc:	3c1f800a */ 	lui	$ra,0x800a
/*  f013fe0:	27ff6664 */ 	addiu	$ra,$ra,0x6664
/*  f013fe4:	0004c040 */ 	sll	$t8,$a0,0x1
/*  f013fe8:	2704000f */ 	addiu	$a0,$t8,0xf
/*  f013fec:	afe20000 */ 	sw	$v0,0x0($ra)
/*  f013ff0:	3499000f */ 	ori	$t9,$a0,0xf
/*  f013ff4:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f013ff8:	0c0048f2 */ 	jal	func000123c8
/*  f013ffc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014000:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f014004:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f014008:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f01400c:	3c0b800a */ 	lui	$t3,%hi(var800a6668)
/*  f014010:	256b6668 */ 	addiu	$t3,$t3,%lo(var800a6668)
/*  f014014:	00047880 */ 	sll	$t7,$a0,0x2
/*  f014018:	25e4000f */ 	addiu	$a0,$t7,0xf
/*  f01401c:	3498000f */ 	ori	$t8,$a0,0xf
/*  f014020:	ad620000 */ 	sw	$v0,0x0($t3)
/*  f014024:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f014028:	0c0048f2 */ 	jal	func000123c8
/*  f01402c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014030:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f014034:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f014038:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f01403c:	3c0c800a */ 	lui	$t4,%hi(var800a666c)
/*  f014040:	258c666c */ 	addiu	$t4,$t4,%lo(var800a666c)
/*  f014044:	00047180 */ 	sll	$t6,$a0,0x6
/*  f014048:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f01404c:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014050:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f014054:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014058:	0c0048f2 */ 	jal	func000123c8
/*  f01405c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014060:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f014064:	3c01800a */ 	lui	$at,0x800a
/*  f014068:	ac226670 */ 	sw	$v0,0x6670($at)
/*  f01406c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f014070:	8d19006c */ 	lw	$t9,0x6c($t0)
/*  f014074:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f014078:	3c0b800a */ 	lui	$t3,%hi(var800a6668)
/*  f01407c:	3c0c800a */ 	lui	$t4,%hi(var800a666c)
/*  f014080:	3c0d800a */ 	lui	$t5,%hi(var800a6660)
/*  f014084:	3c1f800a */ 	lui	$ra,0x800a
/*  f014088:	27ff6664 */ 	addiu	$ra,$ra,0x6664
/*  f01408c:	25ad6660 */ 	addiu	$t5,$t5,%lo(var800a6660)
/*  f014090:	258c666c */ 	addiu	$t4,$t4,%lo(var800a666c)
/*  f014094:	256b6668 */ 	addiu	$t3,$t3,%lo(var800a6668)
/*  f014098:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f01409c:	13200003 */ 	beqz	$t9,.L0f0140ac
/*  f0140a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0140a4:	10000002 */ 	beqz	$zero,.L0f0140b0
/*  f0140a8:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0140ac:
/*  f0140ac:	00004825 */ 	or	$t1,$zero,$zero
.L0f0140b0:
/*  f0140b0:	8d0e0068 */ 	lw	$t6,0x68($t0)
/*  f0140b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0140b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0140bc:	11c00003 */ 	beqz	$t6,.L0f0140cc
/*  f0140c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0140c4:	10000001 */ 	beqz	$zero,.L0f0140cc
/*  f0140c8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0140cc:
/*  f0140cc:	8d0f0064 */ 	lw	$t7,0x64($t0)
/*  f0140d0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0140d4:	11e00003 */ 	beqz	$t7,.L0f0140e4
/*  f0140d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0140dc:	10000001 */ 	beqz	$zero,.L0f0140e4
/*  f0140e0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0140e4:
/*  f0140e4:	8d180070 */ 	lw	$t8,0x70($t0)
/*  f0140e8:	13000003 */ 	beqz	$t8,.L0f0140f8
/*  f0140ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0140f0:	10000001 */ 	beqz	$zero,.L0f0140f8
/*  f0140f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0140f8:
/*  f0140f8:	0045c821 */ 	addu	$t9,$v0,$a1
/*  f0140fc:	03277021 */ 	addu	$t6,$t9,$a3
/*  f014100:	01c97821 */ 	addu	$t7,$t6,$t1
/*  f014104:	19e00024 */ 	blez	$t7,.L0f014198
/*  f014108:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f01410c:	01181821 */ 	addu	$v1,$t0,$t8
/*  f014110:	8c790064 */ 	lw	$t9,0x64($v1)
.L0f014114:
/*  f014114:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f014118:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f01411c:	af261700 */ 	sw	$a2,0x1700($t9)
/*  f014120:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f014124:	00004825 */ 	or	$t1,$zero,$zero
/*  f014128:	00003825 */ 	or	$a3,$zero,$zero
/*  f01412c:	11c00003 */ 	beqz	$t6,.L0f01413c
/*  f014130:	00002825 */ 	or	$a1,$zero,$zero
/*  f014134:	10000001 */ 	beqz	$zero,.L0f01413c
/*  f014138:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f01413c:
/*  f01413c:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f014140:	00001025 */ 	or	$v0,$zero,$zero
/*  f014144:	11e00003 */ 	beqz	$t7,.L0f014154
/*  f014148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01414c:	10000001 */ 	beqz	$zero,.L0f014154
/*  f014150:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f014154:
/*  f014154:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f014158:	13000003 */ 	beqz	$t8,.L0f014168
/*  f01415c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014160:	10000001 */ 	beqz	$zero,.L0f014168
/*  f014164:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f014168:
/*  f014168:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f01416c:	13200003 */ 	beqz	$t9,.L0f01417c
/*  f014170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014174:	10000001 */ 	beqz	$zero,.L0f01417c
/*  f014178:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01417c:
/*  f01417c:	00457021 */ 	addu	$t6,$v0,$a1
/*  f014180:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f014184:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f014188:	0098082a */ 	slt	$at,$a0,$t8
/*  f01418c:	5420ffe1 */ 	bnezl	$at,.L0f014114
/*  f014190:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f014194:	00002025 */ 	or	$a0,$zero,$zero
.L0f014198:
/*  f014198:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f01419c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0141a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0141a4:	1b200018 */ 	blez	$t9,.L0f014208
/*  f0141a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0141ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0141b0:	44810000 */ 	mtc1	$at,$f0
/*  f0141b4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0141b8:	8fee0000 */ 	lw	$t6,0x0($ra)
.L0f0141bc:
/*  f0141bc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0141c0:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f0141c4:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f0141c8:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0141cc:	a3250000 */ 	sb	$a1,0x0($t9)
/*  f0141d0:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0141d4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0141d8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0141dc:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f0141e0:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0141e4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0141e8:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0141ec:	e7200000 */ 	swc1	$f0,0x0($t9)
/*  f0141f0:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f0141f4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0141f8:	008e082a */ 	slt	$at,$a0,$t6
/*  f0141fc:	5420ffef */ 	bnezl	$at,.L0f0141bc
/*  f014200:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f014204:	00002025 */ 	or	$a0,$zero,$zero
.L0f014208:
/*  f014208:	8d0f02bc */ 	lw	$t7,0x2bc($t0)
/*  f01420c:	3c03800a */ 	lui	$v1,%hi(g_RoomPtrs)
/*  f014210:	24634928 */ 	addiu	$v1,$v1,%lo(g_RoomPtrs)
/*  f014214:	19e0000a */ 	blez	$t7,.L0f014240
/*  f014218:	00001025 */ 	or	$v0,$zero,$zero
/*  f01421c:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f014220:
/*  f014220:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f014224:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f014228:	a7260010 */ 	sh	$a2,0x10($t9)
/*  f01422c:	8d0e02bc */ 	lw	$t6,0x2bc($t0)
/*  f014230:	2442008c */ 	addiu	$v0,$v0,0x8c
/*  f014234:	008e082a */ 	slt	$at,$a0,$t6
/*  f014238:	5420fff9 */ 	bnezl	$at,.L0f014220
/*  f01423c:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f014240:
/*  f014240:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f014244:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f014248:	03e00008 */ 	jr	$ra
/*  f01424c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f014250
/*  f014250:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f014254:	3c06800a */ 	lui	$a2,%hi(var800a236c)
/*  f014258:	24c6236c */ 	addiu	$a2,$a2,%lo(var800a236c)
/*  f01425c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f014260:	94c40000 */ 	lhu	$a0,0x0($a2)
/*  f014264:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f014268:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01426c:	00047040 */ 	sll	$t6,$a0,0x1
/*  f014270:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f014274:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014278:	0c0048f2 */ 	jal	func000123c8
/*  f01427c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014280:	3c05800a */ 	lui	$a1,%hi(g_CoverNums)
/*  f014284:	24a52370 */ 	addiu	$a1,$a1,%lo(g_CoverNums)
/*  f014288:	3c06800a */ 	lui	$a2,%hi(var800a236c)
/*  f01428c:	24c6236c */ 	addiu	$a2,$a2,%lo(var800a236c)
/*  f014290:	10400011 */ 	beqz	$v0,.L0f0142d8
/*  f014294:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f014298:	94c80000 */ 	lhu	$t0,0x0($a2)
/*  f01429c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0142a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0142a4:	1900000c */ 	blez	$t0,.L0f0142d8
/*  f0142a8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0142ac:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f0142b0:
/*  f0142b0:	94890000 */ 	lhu	$t1,0x0($a0)
/*  f0142b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0142b8:	01435821 */ 	addu	$t3,$t2,$v1
/*  f0142bc:	a5690000 */ 	sh	$t1,0x0($t3)
/*  f0142c0:	94cc0000 */ 	lhu	$t4,0x0($a2)
/*  f0142c4:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0142c8:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f0142cc:	004c082a */ 	slt	$at,$v0,$t4
/*  f0142d0:	5420fff7 */ 	bnezl	$at,.L0f0142b0
/*  f0142d4:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f0142d8:
/*  f0142d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0142dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0142e0:	03e00008 */ 	jr	$ra
/*  f0142e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0142e8
/*  f0142e8:	27bdf6f8 */ 	addiu	$sp,$sp,-2312
/*  f0142ec:	3c0e800a */ 	lui	$t6,0x800a
/*  f0142f0:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f0142f4:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0142f8:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0142fc:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f014300:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f014304:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f014308:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f01430c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f014310:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f014314:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f014318:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f01431c:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f014320:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f014324:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f014328:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f01432c:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f014330:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014334:	00022040 */ 	sll	$a0,$v0,0x1
/*  f014338:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f01433c:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014340:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014344:	0c0048f2 */ 	jal	func000123c8
/*  f014348:	afa20900 */ 	sw	$v0,0x900($sp)
/*  f01434c:	8fa40900 */ 	lw	$a0,0x900($sp)
/*  f014350:	3c13800a */ 	lui	$s3,%hi(g_CoverFlags)
/*  f014354:	26732360 */ 	addiu	$s3,$s3,%lo(g_CoverFlags)
/*  f014358:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f01435c:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f014360:	3488000f */ 	ori	$t0,$a0,0xf
/*  f014364:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f014368:	3904000f */ 	xori	$a0,$t0,0xf
/*  f01436c:	0c0048f2 */ 	jal	func000123c8
/*  f014370:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014374:	8fa40900 */ 	lw	$a0,0x900($sp)
/*  f014378:	3c15800a */ 	lui	$s5,%hi(g_CoverRooms)
/*  f01437c:	26b52364 */ 	addiu	$s5,$s5,%lo(g_CoverRooms)
/*  f014380:	00045100 */ 	sll	$t2,$a0,0x4
/*  f014384:	2544000f */ 	addiu	$a0,$t2,0xf
/*  f014388:	348b000f */ 	ori	$t3,$a0,0xf
/*  f01438c:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f014390:	3964000f */ 	xori	$a0,$t3,0xf
/*  f014394:	0c0048f2 */ 	jal	func000123c8
/*  f014398:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01439c:	3c03800a */ 	lui	$v1,%hi(var800a2368)
/*  f0143a0:	24632368 */ 	addiu	$v1,$v1,%lo(var800a2368)
/*  f0143a4:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f0143a8:	3c01800a */ 	lui	$at,0x800a
/*  f0143ac:	a420236c */ 	sh	$zero,0x236c($at)
/*  f0143b0:	3c01800a */ 	lui	$at,0x800a
/*  f0143b4:	ac202370 */ 	sw	$zero,0x2370($at)
/*  f0143b8:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0143bc:	51a000e6 */ 	beqzl	$t5,.L0f014758
/*  f0143c0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0143c4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0143c8:	51c000e3 */ 	beqzl	$t6,.L0f014758
/*  f0143cc:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0143d0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0143d4:	8fb80900 */ 	lw	$t8,0x900($sp)
/*  f0143d8:	51e000df */ 	beqzl	$t7,.L0f014758
/*  f0143dc:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0143e0:	1b0000da */ 	blez	$t8,.L0f01474c
/*  f0143e4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0143e8:	3c014416 */ 	lui	$at,0x4416
/*  f0143ec:	4481d000 */ 	mtc1	$at,$f26
/*  f0143f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0143f4:	4481c000 */ 	mtc1	$at,$f24
/*  f0143f8:	4481b000 */ 	mtc1	$at,$f22
/*  f0143fc:	4480a000 */ 	mtc1	$zero,$f20
/*  f014400:	00009025 */ 	or	$s2,$zero,$zero
/*  f014404:	27be0084 */ 	addiu	$s8,$sp,0x84
/*  f014408:	27b700b0 */ 	addiu	$s7,$sp,0xb0
/*  f01440c:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f014410:	8e790000 */ 	lw	$t9,0x0($s3)
.L0f014414:
/*  f014414:	00008025 */ 	or	$s0,$zero,$zero
/*  f014418:	02802025 */ 	or	$a0,$s4,$zero
/*  f01441c:	03324021 */ 	addu	$t0,$t9,$s2
/*  f014420:	a5000000 */ 	sh	$zero,0x0($t0)
/*  f014424:	0fc458b8 */ 	jal	coverLoad
/*  f014428:	27a508dc */ 	addiu	$a1,$sp,0x8dc
/*  f01442c:	104000c2 */ 	beqz	$v0,.L0f014738
/*  f014430:	8fa908e0 */ 	lw	$t1,0x8e0($sp)
/*  f014434:	c5240000 */ 	lwc1	$f4,0x0($t1)
/*  f014438:	27a408dc */ 	addiu	$a0,$sp,0x8dc
/*  f01443c:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f014440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014444:	4500000b */ 	bc1f	.L0f014474
/*  f014448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01444c:	c5260004 */ 	lwc1	$f6,0x4($t1)
/*  f014450:	4606a032 */ 	c.eq.s	$f20,$f6
/*  f014454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014458:	45000006 */ 	bc1f	.L0f014474
/*  f01445c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014460:	c5280008 */ 	lwc1	$f8,0x8($t1)
/*  f014464:	4608a032 */ 	c.eq.s	$f20,$f8
/*  f014468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01446c:	450300b3 */ 	bc1tl	.L0f01473c
/*  f014470:	8fae0900 */ 	lw	$t6,0x900($sp)
.L0f014474:
/*  f014474:	0fc4596c */ 	jal	coverHasSomeFlags
/*  f014478:	00148880 */ 	sll	$s1,$s4,0x2
/*  f01447c:	10400008 */ 	beqz	$v0,.L0f0144a0
/*  f014480:	3c02800a */ 	lui	$v0,0x800a
/*  f014484:	9442236c */ 	lhu	$v0,0x236c($v0)
/*  f014488:	3c01800a */ 	lui	$at,0x800a
/*  f01448c:	00025040 */ 	sll	$t2,$v0,0x1
/*  f014490:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f014494:	a57400dc */ 	sh	$s4,0xdc($t3)
/*  f014498:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f01449c:	a42c236c */ 	sh	$t4,0x236c($at)
.L0f0144a0:
/*  f0144a0:	8fad08dc */ 	lw	$t5,0x8dc($sp)
/*  f0144a4:	c5aa0000 */ 	lwc1	$f10,0x0($t5)
/*  f0144a8:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f0144ac:	e5b00000 */ 	swc1	$f16,0x0($t5)
/*  f0144b0:	8fae08dc */ 	lw	$t6,0x8dc($sp)
/*  f0144b4:	c5d20004 */ 	lwc1	$f18,0x4($t6)
/*  f0144b8:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0144bc:	e5c40004 */ 	swc1	$f4,0x4($t6)
/*  f0144c0:	8faf08dc */ 	lw	$t7,0x8dc($sp)
/*  f0144c4:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*  f0144c8:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f0144cc:	e5e80008 */ 	swc1	$f8,0x8($t7)
/*  f0144d0:	8fb808e0 */ 	lw	$t8,0x8e0($sp)
/*  f0144d4:	c70a0000 */ 	lwc1	$f10,0x0($t8)
/*  f0144d8:	460ac032 */ 	c.eq.s	$f24,$f10
/*  f0144dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0144e0:	45000011 */ 	bc1f	.L0f014528
/*  f0144e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0144e8:	c7100004 */ 	lwc1	$f16,0x4($t8)
/*  f0144ec:	4610c032 */ 	c.eq.s	$f24,$f16
/*  f0144f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0144f4:	4500000c */ 	bc1f	.L0f014528
/*  f0144f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0144fc:	c7120008 */ 	lwc1	$f18,0x8($t8)
/*  f014500:	4612c032 */ 	c.eq.s	$f24,$f18
/*  f014504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014508:	45000007 */ 	bc1f	.L0f014528
/*  f01450c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014510:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f014514:	03321021 */ 	addu	$v0,$t9,$s2
/*  f014518:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f01451c:	35090010 */ 	ori	$t1,$t0,0x10
/*  f014520:	1000000a */ 	beqz	$zero,.L0f01454c
/*  f014524:	a4490000 */ 	sh	$t1,0x0($v0)
.L0f014528:
/*  f014528:	0fc4596c */ 	jal	coverHasSomeFlags
/*  f01452c:	27a408dc */ 	addiu	$a0,$sp,0x8dc
/*  f014530:	14400006 */ 	bnez	$v0,.L0f01454c
/*  f014534:	8fa408e0 */ 	lw	$a0,0x8e0($sp)
/*  f014538:	44802000 */ 	mtc1	$zero,$f4
/*  f01453c:	24850004 */ 	addiu	$a1,$a0,0x4
/*  f014540:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f014544:	0c0011e4 */ 	jal	scaleTo1
/*  f014548:	e4840004 */ 	swc1	$f4,0x4($a0)
.L0f01454c:
/*  f01454c:	8fa408dc */ 	lw	$a0,0x8dc($sp)
/*  f014550:	02e02825 */ 	or	$a1,$s7,$zero
/*  f014554:	03c03025 */ 	or	$a2,$s8,$zero
/*  f014558:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f01455c:	0fc58865 */ 	jal	func0f162194
/*  f014560:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f014564:	87ab00b0 */ 	lh	$t3,0xb0($sp)
/*  f014568:	87ac0084 */ 	lh	$t4,0x84($sp)
/*  f01456c:	12cb0003 */ 	beq	$s6,$t3,.L0f01457c
/*  f014570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014574:	10000004 */ 	beqz	$zero,.L0f014588
/*  f014578:	02e08025 */ 	or	$s0,$s7,$zero
.L0f01457c:
/*  f01457c:	52cc0003 */ 	beql	$s6,$t4,.L0f01458c
/*  f014580:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f014584:	03c08025 */ 	or	$s0,$s8,$zero
.L0f014588:
/*  f014588:	8ead0000 */ 	lw	$t5,0x0($s5)
.L0f01458c:
/*  f01458c:	02002825 */ 	or	$a1,$s0,$zero
/*  f014590:	01b17021 */ 	addu	$t6,$t5,$s1
/*  f014594:	1200000f */ 	beqz	$s0,.L0f0145d4
/*  f014598:	add60000 */ 	sw	$s6,0x0($t6)
/*  f01459c:	0c00a900 */ 	jal	func0002a400
/*  f0145a0:	8fa408dc */ 	lw	$a0,0x8dc($sp)
/*  f0145a4:	58400008 */ 	blezl	$v0,.L0f0145c8
/*  f0145a8:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0145ac:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f0145b0:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f0145b4:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f0145b8:	03314021 */ 	addu	$t0,$t9,$s1
/*  f0145bc:	10000005 */ 	beqz	$zero,.L0f0145d4
/*  f0145c0:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f0145c4:	8eaa0000 */ 	lw	$t2,0x0($s5)
.L0f0145c8:
/*  f0145c8:	86090000 */ 	lh	$t1,0x0($s0)
/*  f0145cc:	01515821 */ 	addu	$t3,$t2,$s1
/*  f0145d0:	ad690000 */ 	sw	$t1,0x0($t3)
.L0f0145d4:
/*  f0145d4:	8eac0000 */ 	lw	$t4,0x0($s5)
/*  f0145d8:	01916821 */ 	addu	$t5,$t4,$s1
/*  f0145dc:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0145e0:	05c30008 */ 	bgezl	$t6,.L0f014604
/*  f0145e4:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f0145e8:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0145ec:	01f21021 */ 	addu	$v0,$t7,$s2
/*  f0145f0:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f0145f4:	37380004 */ 	ori	$t8,$t9,0x4
/*  f0145f8:	1000004f */ 	beqz	$zero,.L0f014738
/*  f0145fc:	a4580000 */ 	sh	$t8,0x0($v0)
/*  f014600:	8e680000 */ 	lw	$t0,0x0($s3)
.L0f014604:
/*  f014604:	8fac08e0 */ 	lw	$t4,0x8e0($sp)
/*  f014608:	01125021 */ 	addu	$t2,$t0,$s2
/*  f01460c:	95490000 */ 	lhu	$t1,0x0($t2)
/*  f014610:	312b0010 */ 	andi	$t3,$t1,0x10
/*  f014614:	55600049 */ 	bnezl	$t3,.L0f01473c
/*  f014618:	8fae0900 */ 	lw	$t6,0x900($sp)
/*  f01461c:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f014620:	8fad08dc */ 	lw	$t5,0x8dc($sp)
/*  f014624:	27a408ec */ 	addiu	$a0,$sp,0x8ec
/*  f014628:	461a3202 */ 	mul.s	$f8,$f6,$f26
/*  f01462c:	c5aa0000 */ 	lwc1	$f10,0x0($t5)
/*  f014630:	02e02825 */ 	or	$a1,$s7,$zero
/*  f014634:	03c03025 */ 	or	$a2,$s8,$zero
/*  f014638:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f01463c:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f014640:	e7b008ec */ 	swc1	$f16,0x8ec($sp)
/*  f014644:	c5b20004 */ 	lwc1	$f18,0x4($t5)
/*  f014648:	e7b208f0 */ 	swc1	$f18,0x8f0($sp)
/*  f01464c:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f014650:	c5a80008 */ 	lwc1	$f8,0x8($t5)
/*  f014654:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f014658:	461a2182 */ 	mul.s	$f6,$f4,$f26
/*  f01465c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f014660:	0fc58865 */ 	jal	func0f162194
/*  f014664:	e7aa08f4 */ 	swc1	$f10,0x8f4($sp)
/*  f014668:	87ae00b0 */ 	lh	$t6,0xb0($sp)
/*  f01466c:	87af0084 */ 	lh	$t7,0x84($sp)
/*  f014670:	27a408ec */ 	addiu	$a0,$sp,0x8ec
/*  f014674:	12ce0003 */ 	beq	$s6,$t6,.L0f014684
/*  f014678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01467c:	10000004 */ 	beqz	$zero,.L0f014690
/*  f014680:	02e08025 */ 	or	$s0,$s7,$zero
.L0f014684:
/*  f014684:	12cf0002 */ 	beq	$s6,$t7,.L0f014690
/*  f014688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01468c:	03c08025 */ 	or	$s0,$s8,$zero
.L0f014690:
/*  f014690:	52000025 */ 	beqzl	$s0,.L0f014728
/*  f014694:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f014698:	0c00a900 */ 	jal	func0002a400
/*  f01469c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0146a0:	58400012 */ 	blezl	$v0,.L0f0146ec
/*  f0146a4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0146a8:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0146ac:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f0146b0:	0019c403 */ 	sra	$t8,$t9,0x10
/*  f0146b4:	01115021 */ 	addu	$t2,$t0,$s1
/*  f0146b8:	8d490000 */ 	lw	$t1,0x0($t2)
/*  f0146bc:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f0146c0:	17090003 */ 	bne	$t8,$t1,.L0f0146d0
/*  f0146c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0146c8:	10000001 */ 	beqz	$zero,.L0f0146d0
/*  f0146cc:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f0146d0:
/*  f0146d0:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0146d4:	01721021 */ 	addu	$v0,$t3,$s2
/*  f0146d8:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f0146dc:	01836825 */ 	or	$t5,$t4,$v1
/*  f0146e0:	10000015 */ 	beqz	$zero,.L0f014738
/*  f0146e4:	a44d0000 */ 	sh	$t5,0x0($v0)
/*  f0146e8:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f0146ec:
/*  f0146ec:	86080000 */ 	lh	$t0,0x0($s0)
/*  f0146f0:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f0146f4:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f0146f8:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0146fc:	17280003 */ 	bne	$t9,$t0,.L0f01470c
/*  f014700:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014704:	10000001 */ 	beqz	$zero,.L0f01470c
/*  f014708:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f01470c:
/*  f01470c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f014710:	01521021 */ 	addu	$v0,$t2,$s2
/*  f014714:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f014718:	03034825 */ 	or	$t1,$t8,$v1
/*  f01471c:	10000006 */ 	beqz	$zero,.L0f014738
/*  f014720:	a4490000 */ 	sh	$t1,0x0($v0)
/*  f014724:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f014728:
/*  f014728:	01721021 */ 	addu	$v0,$t3,$s2
/*  f01472c:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f014730:	358d0008 */ 	ori	$t5,$t4,0x8
/*  f014734:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f014738:
/*  f014738:	8fae0900 */ 	lw	$t6,0x900($sp)
.L0f01473c:
/*  f01473c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f014740:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f014744:	568eff33 */ 	bnel	$s4,$t6,.L0f014414
/*  f014748:	8e790000 */ 	lw	$t9,0x0($s3)
.L0f01474c:
/*  f01474c:	0fc05094 */ 	jal	func0f014250
/*  f014750:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f014754:	8fbf0064 */ 	lw	$ra,0x64($sp)
.L0f014758:
/*  f014758:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f01475c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f014760:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f014764:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f014768:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f01476c:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f014770:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f014774:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f014778:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f01477c:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f014780:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f014784:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f014788:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f01478c:	03e00008 */ 	jr	$ra
/*  f014790:	27bd0908 */ 	addiu	$sp,$sp,0x908
/*  f014794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01479c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0147a0
/*  f0147a0:	3c01800a */ 	lui	$at,0x800a
/*  f0147a4:	ac2433a0 */ 	sw	$a0,0x33a0($at)
/*  f0147a8:	3c01800a */ 	lui	$at,0x800a
/*  f0147ac:	ac2033a4 */ 	sw	$zero,0x33a4($at)
/*  f0147b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0147b4:	44812000 */ 	mtc1	$at,$f4
/*  f0147b8:	3c018008 */ 	lui	$at,0x8008
/*  f0147bc:	03e00008 */ 	jr	$ra
/*  f0147c0:	e424db84 */ 	swc1	$f4,-0x247c($at)
/*  f0147c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0147c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0147cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0147d0
/*  f0147d0:	3c03800a */ 	lui	$v1,%hi(var8009da60)
/*  f0147d4:	3c04800a */ 	lui	$a0,%hi(var8009dbe0)
/*  f0147d8:	2484dbe0 */ 	addiu	$a0,$a0,%lo(var8009dbe0)
/*  f0147dc:	2463da60 */ 	addiu	$v1,$v1,%lo(var8009da60)
/*  f0147e0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0147e4:
/*  f0147e4:	24630030 */ 	addiu	$v1,$v1,0x30
/*  f0147e8:	1464fffe */ 	bne	$v1,$a0,.L0f0147e4
/*  f0147ec:	ac62ffd0 */ 	sw	$v0,-0x30($v1)
/*  f0147f0:	03e00008 */ 	jr	$ra
/*  f0147f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0147f8
/*  f0147f8:	3c03800a */ 	lui	$v1,%hi(var8009dbe0)
/*  f0147fc:	3c04800a */ 	lui	$a0,%hi(var8009dd00)
/*  f014800:	2484dd00 */ 	addiu	$a0,$a0,%lo(var8009dd00)
/*  f014804:	2463dbe0 */ 	addiu	$v1,$v1,%lo(var8009dbe0)
/*  f014808:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f01480c:
/*  f01480c:	24630048 */ 	addiu	$v1,$v1,0x48
/*  f014810:	1464fffe */ 	bne	$v1,$a0,.L0f01480c
/*  f014814:	ac62ffb8 */ 	sw	$v0,-0x48($v1)
/*  f014818:	03e00008 */ 	jr	$ra
/*  f01481c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f014820
/*  f014820:	3c03800b */ 	lui	$v1,%hi(var800acc80)
/*  f014824:	3c02800b */ 	lui	$v0,%hi(var800acca0)
/*  f014828:	2442cca0 */ 	addiu	$v0,$v0,%lo(var800acca0)
/*  f01482c:	2463cc80 */ 	addiu	$v1,$v1,%lo(var800acc80)
.L0f014830:
/*  f014830:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f014834:	1462fffe */ 	bne	$v1,$v0,.L0f014830
/*  f014838:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f01483c:	3c018008 */ 	lui	$at,0x8008
/*  f014840:	03e00008 */ 	jr	$ra
/*  f014844:	a0207d10 */ 	sb	$zero,0x7d10($at)
);

GLOBAL_ASM(
glabel func0f014848
/*  f014848:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f01484c:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f014850:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f014854:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014858:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f01485c:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f014860:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f014864:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014868:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f01486c:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f014870:	240effff */ 	addiu	$t6,$zero,-1
/*  f014874:	03191021 */ 	addu	$v0,$t8,$t9
/*  f014878:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f01487c:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f014880:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f014884:	a7ae0074 */ 	sh	$t6,0x74($sp)
/*  f014888:	9044000f */ 	lbu	$a0,0xf($v0)
/*  f01488c:	0fc62ecb */ 	jal	mpGetHeadId
/*  f014890:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f014894:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f014898:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f01489c:	0fc62ee4 */ 	jal	mpGetBodyId
/*  f0148a0:	91240010 */ 	lbu	$a0,0x10($t1)
/*  f0148a4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0148a8:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f0148ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0148b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0148b4:	15410004 */ 	bne	$t2,$at,.L0f0148c8
/*  f0148b8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0148bc:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0148c0:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0148c4:	2404005e */ 	addiu	$a0,$zero,0x5e
.L0f0148c8:
/*  f0148c8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0148cc:	0fc0b4db */ 	jal	func0f02d36c
/*  f0148d0:	afa4005c */ 	sw	$a0,0x5c($sp)
/*  f0148d4:	10400169 */ 	beqz	$v0,.L0f014e7c
/*  f0148d8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0148dc:	3c0d8006 */ 	lui	$t5,%hi(var80062400)
/*  f0148e0:	25ad2400 */ 	addiu	$t5,$t5,%lo(var80062400)
/*  f0148e4:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0148e8:	27ac004c */ 	addiu	$t4,$sp,0x4c
/*  f0148ec:	8daf0004 */ 	lw	$t7,0x4($t5)
/*  f0148f0:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0148f4:	8da10008 */ 	lw	$at,0x8($t5)
/*  f0148f8:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f0148fc:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f014900:	0c006134 */ 	jal	ailistFindById
/*  f014904:	ad810008 */ 	sw	$at,0x8($t4)
/*  f014908:	4480a000 */ 	mtc1	$zero,$f20
/*  f01490c:	02002025 */ 	or	$a0,$s0,$zero
/*  f014910:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f014914:	4407a000 */ 	mfc1	$a3,$f20
/*  f014918:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f01491c:	0fc08332 */ 	jal	func0f020cc8
/*  f014920:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f014924:	10400155 */ 	beqz	$v0,.L0f014e7c
/*  f014928:	00402025 */ 	or	$a0,$v0,$zero
/*  f01492c:	0fc1812f */ 	jal	func0f0604bc
/*  f014930:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f014934:	0fc180bc */ 	jal	propHide
/*  f014938:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f01493c:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f014940:	87a5007a */ 	lh	$a1,0x7a($sp)
/*  f014944:	8f100004 */ 	lw	$s0,0x4($t8)
/*  f014948:	0fc07937 */ 	jal	chrSetChrnum
/*  f01494c:	02002025 */ 	or	$a0,$s0,$zero
/*  f014950:	3c013f80 */ 	lui	$at,0x3f80
/*  f014954:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f014958:	44812000 */ 	mtc1	$at,$f4
/*  f01495c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f014960:	44813000 */ 	mtc1	$at,$f6
/*  f014964:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014968:	a6070128 */ 	sh	$a3,0x128($s0)
/*  f01496c:	a607012a */ 	sh	$a3,0x12a($s0)
/*  f014970:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f014974:	e60400f0 */ 	swc1	$f4,0xf0($s0)
/*  f014978:	e60600dc */ 	swc1	$f6,0xdc($s0)
/*  f01497c:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f014980:	a2090006 */ 	sb	$t1,0x6($s0)
/*  f014984:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f014988:	a60a0010 */ 	sh	$t2,0x10($s0)
/*  f01498c:	0fc0b378 */ 	jal	func0f02cde0
/*  f014990:	86040010 */ 	lh	$a0,0x10($s0)
/*  f014994:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f014998:	a20202fe */ 	sb	$v0,0x2fe($s0)
/*  f01499c:	ae0b0114 */ 	sw	$t3,0x114($s0)
/*  f0149a0:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f0149a4:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0149a8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0149ac:	3c088008 */ 	lui	$t0,%hi(var80087d10)
/*  f0149b0:	91cc0011 */ 	lbu	$t4,0x11($t6)
/*  f0149b4:	25087d10 */ 	addiu	$t0,$t0,%lo(var80087d10)
/*  f0149b8:	a20002a2 */ 	sb	$zero,0x2a2($s0)
/*  f0149bc:	018d7804 */ 	sllv	$t7,$t5,$t4
/*  f0149c0:	a20f0125 */ 	sb	$t7,0x125($s0)
/*  f0149c4:	91030000 */ 	lbu	$v1,0x0($t0)
/*  f0149c8:	240402e0 */ 	addiu	$a0,$zero,0x2e0
/*  f0149cc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0149d0:	28610008 */ 	slti	$at,$v1,0x8
/*  f0149d4:	10200129 */ 	beqz	$at,.L0f014e7c
/*  f0149d8:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0149dc:	3c01800b */ 	lui	$at,0x800b
/*  f0149e0:	00380821 */ 	addu	$at,$at,$t8
/*  f0149e4:	ac30cc80 */ 	sw	$s0,-0x3380($at)
/*  f0149e8:	24790001 */ 	addiu	$t9,$v1,0x1
/*  f0149ec:	0c0048f2 */ 	jal	func000123c8
/*  f0149f0:	a1190000 */ 	sb	$t9,0x0($t0)
/*  f0149f4:	3c088008 */ 	lui	$t0,%hi(var80087d10)
/*  f0149f8:	25087d10 */ 	addiu	$t0,$t0,%lo(var80087d10)
/*  f0149fc:	10400113 */ 	beqz	$v0,.L0f014e4c
/*  f014a00:	ae0202d4 */ 	sw	$v0,0x2d4($s0)
/*  f014a04:	a20002b0 */ 	sb	$zero,0x2b0($s0)
/*  f014a08:	0c004b70 */ 	jal	random
/*  f014a0c:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f014a10:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f014a14:	0043001b */ 	divu	$zero,$v0,$v1
/*  f014a18:	860a0010 */ 	lh	$t2,0x10($s0)
/*  f014a1c:	00004810 */ 	mfhi	$t1
/*  f014a20:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014a24:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f014a28:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f014a2c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f014a30:	3c0e8008 */ 	lui	$t6,0x8008
/*  f014a34:	a20902b1 */ 	sb	$t1,0x2b1($s0)
/*  f014a38:	01cb7021 */ 	addu	$t6,$t6,$t3
/*  f014a3c:	8dcecf04 */ 	lw	$t6,-0x30fc($t6)
/*  f014a40:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014a44:	14600002 */ 	bnez	$v1,.L0f014a50
/*  f014a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014a4c:	0007000d */ 	break	0x7
.L0f014a50:
/*  f014a50:	000e6fc2 */ 	srl	$t5,$t6,0x1f
/*  f014a54:	15a00002 */ 	bnez	$t5,.L0f014a60
/*  f014a58:	3c08800b */ 	lui	$t0,%hi(g_MpNumPlayers)
/*  f014a5c:	a20302b1 */ 	sb	$v1,0x2b1($s0)
.L0f014a60:
/*  f014a60:	240c0029 */ 	addiu	$t4,$zero,0x29
/*  f014a64:	a607017e */ 	sh	$a3,0x17e($s0)
/*  f014a68:	a20002e3 */ 	sb	$zero,0x2e3($s0)
/*  f014a6c:	ae0702e4 */ 	sw	$a3,0x2e4($s0)
/*  f014a70:	a20002fc */ 	sb	$zero,0x2fc($s0)
/*  f014a74:	a20002e2 */ 	sb	$zero,0x2e2($s0)
/*  f014a78:	ae0002a4 */ 	sw	$zero,0x2a4($s0)
/*  f014a7c:	a20c02a0 */ 	sb	$t4,0x2a0($s0)
/*  f014a80:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f014a84:	2508c530 */ 	addiu	$t0,$t0,%lo(g_MpNumPlayers)
/*  f014a88:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f014a8c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f014a90:	3c01800b */ 	lui	$at,0x800b
/*  f014a94:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f014a98:	00021880 */ 	sll	$v1,$v0,0x2
/*  f014a9c:	00230821 */ 	addu	$at,$at,$v1
/*  f014aa0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014aa4:	ac30c4d0 */ 	sw	$s0,-0x3b30($at)
/*  f014aa8:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f014aac:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f014ab0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014ab4:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f014ab8:	3c01800b */ 	lui	$at,0x800b
/*  f014abc:	00230821 */ 	addu	$at,$at,$v1
/*  f014ac0:	03194821 */ 	addu	$t1,$t8,$t9
/*  f014ac4:	ac29c500 */ 	sw	$t1,-0x3b00($at)
/*  f014ac8:	244a0001 */ 	addiu	$t2,$v0,0x1
/*  f014acc:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f014ad0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014ad4:	24040090 */ 	addiu	$a0,$zero,0x90
/*  f014ad8:	0c0048f2 */ 	jal	func000123c8
/*  f014adc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014ae0:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014ae4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014ae8:	00001825 */ 	or	$v1,$zero,$zero
/*  f014aec:	acc2001c */ 	sw	$v0,0x1c($a2)
.L0f014af0:
/*  f014af0:	8ccb001c */ 	lw	$t3,0x1c($a2)
/*  f014af4:	01637021 */ 	addu	$t6,$t3,$v1
/*  f014af8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f014afc:	28610084 */ 	slti	$at,$v1,0x84
/*  f014b00:	1420fffb */ 	bnez	$at,.L0f014af0
/*  f014b04:	adc00000 */ 	sw	$zero,0x0($t6)
/*  f014b08:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f014b0c:	accd0004 */ 	sw	$t5,0x4($a2)
/*  f014b10:	8fac003c */ 	lw	$t4,0x3c($sp)
/*  f014b14:	918f0048 */ 	lbu	$t7,0x48($t4)
/*  f014b18:	2de10006 */ 	sltiu	$at,$t7,0x6
/*  f014b1c:	1020000b */ 	beqz	$at,.L0f014b4c
/*  f014b20:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f014b24:	3c017f1b */ 	lui	$at,%hi(var7f1a82a0)
/*  f014b28:	002f0821 */ 	addu	$at,$at,$t7
/*  f014b2c:	8c2f82a0 */ 	lw	$t7,%lo(var7f1a82a0)($at)
/*  f014b30:	01e00008 */ 	jr	$t7
/*  f014b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014b38:	1000000e */ 	beqz	$zero,.L0f014b74
/*  f014b3c:	a0c00000 */ 	sb	$zero,0x0($a2)
/*  f014b40:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f014b44:	1000000b */ 	beqz	$zero,.L0f014b74
/*  f014b48:	a0d80000 */ 	sb	$t8,0x0($a2)
.L0f014b4c:
/*  f014b4c:	24190014 */ 	addiu	$t9,$zero,0x14
/*  f014b50:	10000008 */ 	beqz	$zero,.L0f014b74
/*  f014b54:	a0d90000 */ 	sb	$t9,0x0($a2)
/*  f014b58:	24090028 */ 	addiu	$t1,$zero,0x28
/*  f014b5c:	10000005 */ 	beqz	$zero,.L0f014b74
/*  f014b60:	a0c90000 */ 	sb	$t1,0x0($a2)
/*  f014b64:	240a003c */ 	addiu	$t2,$zero,0x3c
/*  f014b68:	10000002 */ 	beqz	$zero,.L0f014b74
/*  f014b6c:	a0ca0000 */ 	sb	$t2,0x0($a2)
/*  f014b70:	a0c00000 */ 	sb	$zero,0x0($a2)
.L0f014b74:
/*  f014b74:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f014b78:	240e012d */ 	addiu	$t6,$zero,0x12d
/*  f014b7c:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f014b80:	a4c00064 */ 	sh	$zero,0x64($a2)
/*  f014b84:	acc00010 */ 	sw	$zero,0x10($a2)
/*  f014b88:	a4c0002c */ 	sh	$zero,0x2c($a2)
/*  f014b8c:	a4c0002e */ 	sh	$zero,0x2e($a2)
/*  f014b90:	acc00034 */ 	sw	$zero,0x34($a2)
/*  f014b94:	e4d40040 */ 	swc1	$f20,0x40($a2)
/*  f014b98:	acc00024 */ 	sw	$zero,0x24($a2)
/*  f014b9c:	acc00028 */ 	sw	$zero,0x28($a2)
/*  f014ba0:	a0c00058 */ 	sb	$zero,0x58($a2)
/*  f014ba4:	a0c00059 */ 	sb	$zero,0x59($a2)
/*  f014ba8:	acc0005c */ 	sw	$zero,0x5c($a2)
/*  f014bac:	acc00060 */ 	sw	$zero,0x60($a2)
/*  f014bb0:	acce0030 */ 	sw	$t6,0x30($a2)
/*  f014bb4:	acc00038 */ 	sw	$zero,0x38($a2)
/*  f014bb8:	a4c7003e */ 	sh	$a3,0x3e($a2)
/*  f014bbc:	a4c0003c */ 	sh	$zero,0x3c($a2)
/*  f014bc0:	a4c70008 */ 	sh	$a3,0x8($a2)
/*  f014bc4:	a4c7000a */ 	sh	$a3,0xa($a2)
/*  f014bc8:	a4c7000c */ 	sh	$a3,0xc($a2)
/*  f014bcc:	acc00068 */ 	sw	$zero,0x68($a2)
/*  f014bd0:	e4d4006c */ 	swc1	$f20,0x6c($a2)
/*  f014bd4:	e4d40070 */ 	swc1	$f20,0x70($a2)
/*  f014bd8:	a0c70074 */ 	sb	$a3,0x74($a2)
/*  f014bdc:	a4c70076 */ 	sh	$a3,0x76($a2)
/*  f014be0:	acc70114 */ 	sw	$a3,0x114($a2)
/*  f014be4:	a0cd0079 */ 	sb	$t5,0x79($a2)
/*  f014be8:	e4d40098 */ 	swc1	$f20,0x98($a2)
/*  f014bec:	a4cb0002 */ 	sh	$t3,0x2($a2)
/*  f014bf0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f014bf4:	90cf004c */ 	lbu	$t7,0x4c($a2)
/*  f014bf8:	90cb004f */ 	lbu	$t3,0x4f($a2)
/*  f014bfc:	e4c8008c */ 	swc1	$f8,0x8c($a2)
/*  f014c00:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f014c04:	90cd009c */ 	lbu	$t5,0x9c($a2)
/*  f014c08:	31e9ffdf */ 	andi	$t1,$t7,0xffdf
/*  f014c0c:	e4ca0090 */ 	swc1	$f10,0x90($a2)
/*  f014c10:	c7b00054 */ 	lwc1	$f16,0x54($sp)
/*  f014c14:	316eff7f */ 	andi	$t6,$t3,0xff7f
/*  f014c18:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f014c1c:	35390040 */ 	ori	$t9,$t1,0x40
/*  f014c20:	a0ce004f */ 	sb	$t6,0x4f($a2)
/*  f014c24:	accc0020 */ 	sw	$t4,0x20($a2)
/*  f014c28:	a0c9004c */ 	sb	$t1,0x4c($a2)
/*  f014c2c:	332e00fd */ 	andi	$t6,$t9,0xfd
/*  f014c30:	a0d9004c */ 	sb	$t9,0x4c($a2)
/*  f014c34:	31cc00f7 */ 	andi	$t4,$t6,0xf7
/*  f014c38:	31afff7f */ 	andi	$t7,$t5,0xff7f
/*  f014c3c:	31ea00bf */ 	andi	$t2,$t7,0xbf
/*  f014c40:	a0ce004c */ 	sb	$t6,0x4c($a2)
/*  f014c44:	319800ef */ 	andi	$t8,$t4,0xef
/*  f014c48:	a0cf009c */ 	sb	$t7,0x9c($a2)
/*  f014c4c:	a0cc004c */ 	sb	$t4,0x4c($a2)
/*  f014c50:	330900fb */ 	andi	$t1,$t8,0xfb
/*  f014c54:	a0ca009c */ 	sb	$t2,0x9c($a2)
/*  f014c58:	314b00df */ 	andi	$t3,$t2,0xdf
/*  f014c5c:	a0d8004c */ 	sb	$t8,0x4c($a2)
/*  f014c60:	a0c9004c */ 	sb	$t1,0x4c($a2)
/*  f014c64:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f014c68:	a0c0004d */ 	sb	$zero,0x4d($a2)
/*  f014c6c:	a0c0004e */ 	sb	$zero,0x4e($a2)
/*  f014c70:	acc00044 */ 	sw	$zero,0x44($a2)
/*  f014c74:	acc000a0 */ 	sw	$zero,0xa0($a2)
/*  f014c78:	a0cb009c */ 	sb	$t3,0x9c($a2)
/*  f014c7c:	a0ca004c */ 	sb	$t2,0x4c($a2)
/*  f014c80:	a4c70048 */ 	sh	$a3,0x48($a2)
/*  f014c84:	a4c7004a */ 	sh	$a3,0x4a($a2)
/*  f014c88:	acc700bc */ 	sw	$a3,0xbc($a2)
/*  f014c8c:	acc000c8 */ 	sw	$zero,0xc8($a2)
/*  f014c90:	acc000c4 */ 	sw	$zero,0xc4($a2)
/*  f014c94:	acc000cc */ 	sw	$zero,0xcc($a2)
/*  f014c98:	acc000d0 */ 	sw	$zero,0xd0($a2)
/*  f014c9c:	acc000d8 */ 	sw	$zero,0xd8($a2)
/*  f014ca0:	acc000dc */ 	sw	$zero,0xdc($a2)
/*  f014ca4:	a4c000e2 */ 	sh	$zero,0xe2($a2)
/*  f014ca8:	a4c000e0 */ 	sh	$zero,0xe0($a2)
/*  f014cac:	e4d400e8 */ 	swc1	$f20,0xe8($a2)
/*  f014cb0:	e4d400e4 */ 	swc1	$f20,0xe4($a2)
/*  f014cb4:	e4d00094 */ 	swc1	$f16,0x94($a2)
/*  f014cb8:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f014cbc:	0c006b91 */ 	jal	func0001ae44
/*  f014cc0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014cc4:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014cc8:	e4c000a4 */ 	swc1	$f0,0xa4($a2)
/*  f014ccc:	e4d400a8 */ 	swc1	$f20,0xa8($a2)
/*  f014cd0:	e4d400ac */ 	swc1	$f20,0xac($a2)
/*  f014cd4:	0c006b91 */ 	jal	func0001ae44
/*  f014cd8:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f014cdc:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014ce0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014ce4:	3c014f80 */ 	lui	$at,0x4f80
/*  f014ce8:	e4c000b0 */ 	swc1	$f0,0xb0($a2)
/*  f014cec:	44810000 */ 	mtc1	$at,$f0
/*  f014cf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f014cf4:	e4d400b4 */ 	swc1	$f20,0xb4($a2)
/*  f014cf8:	e4d400b8 */ 	swc1	$f20,0xb8($a2)
/*  f014cfc:	e4d40108 */ 	swc1	$f20,0x108($a2)
/*  f014d00:	e4d4010c */ 	swc1	$f20,0x10c($a2)
/*  f014d04:	e4d40110 */ 	swc1	$f20,0x110($a2)
/*  f014d08:	acc00118 */ 	sw	$zero,0x118($a2)
/*  f014d0c:	acc0011c */ 	sw	$zero,0x11c($a2)
/*  f014d10:	acc70120 */ 	sw	$a3,0x120($a2)
/*  f014d14:	acc70124 */ 	sw	$a3,0x124($a2)
/*  f014d18:	acc00128 */ 	sw	$zero,0x128($a2)
/*  f014d1c:	acc0012c */ 	sw	$zero,0x12c($a2)
/*  f014d20:	00c01025 */ 	or	$v0,$a2,$zero
/*  f014d24:	00c02025 */ 	or	$a0,$a2,$zero
/*  f014d28:	00c01825 */ 	or	$v1,$a2,$zero
.L0f014d2c:
/*  f014d2c:	a0470130 */ 	sb	$a3,0x130($v0)
/*  f014d30:	e480013c */ 	swc1	$f0,0x13c($a0)
/*  f014d34:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f014d38:	a040016c */ 	sb	$zero,0x16c($v0)
/*  f014d3c:	28a1000c */ 	slti	$at,$a1,0xc
/*  f014d40:	ac870178 */ 	sw	$a3,0x178($a0)
/*  f014d44:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f014d48:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f014d4c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f014d50:	1420fff6 */ 	bnez	$at,.L0f014d2c
/*  f014d54:	a46701a6 */ 	sh	$a3,0x1a6($v1)
/*  f014d58:	e4d401c0 */ 	swc1	$f20,0x1c0($a2)
/*  f014d5c:	e4d401c4 */ 	swc1	$f20,0x1c4($a2)
/*  f014d60:	e4d401c8 */ 	swc1	$f20,0x1c8($a2)
/*  f014d64:	acc701cc */ 	sw	$a3,0x1cc($a2)
/*  f014d68:	acc001d0 */ 	sw	$zero,0x1d0($a2)
/*  f014d6c:	e4d401d4 */ 	swc1	$f20,0x1d4($a2)
/*  f014d70:	acc701e4 */ 	sw	$a3,0x1e4($a2)
/*  f014d74:	acc001e8 */ 	sw	$zero,0x1e8($a2)
/*  f014d78:	acc00208 */ 	sw	$zero,0x208($a2)
/*  f014d7c:	0c004b70 */ 	jal	random
/*  f014d80:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014d84:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014d88:	00002825 */ 	or	$a1,$zero,$zero
/*  f014d8c:	acc20210 */ 	sw	$v0,0x210($a2)
/*  f014d90:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f014d94:	acc0020c */ 	sw	$zero,0x20c($a2)
/*  f014d98:	00c02025 */ 	or	$a0,$a2,$zero
/*  f014d9c:	00c01825 */ 	or	$v1,$a2,$zero
.L0f014da0:
/*  f014da0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f014da4:	e4740214 */ 	swc1	$f20,0x214($v1)
/*  f014da8:	e4740218 */ 	swc1	$f20,0x218($v1)
/*  f014dac:	e4740244 */ 	swc1	$f20,0x244($v1)
/*  f014db0:	e4740248 */ 	swc1	$f20,0x248($v1)
/*  f014db4:	ac600274 */ 	sw	$zero,0x274($v1)
/*  f014db8:	ac600278 */ 	sw	$zero,0x278($v1)
/*  f014dbc:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f014dc0:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f014dc4:	14a2fff6 */ 	bne	$a1,$v0,.L0f014da0
/*  f014dc8:	ac8002a4 */ 	sw	$zero,0x2a4($a0)
/*  f014dcc:	90cb009c */ 	lbu	$t3,0x9c($a2)
/*  f014dd0:	acc002a4 */ 	sw	$zero,0x2a4($a2)
/*  f014dd4:	acc002c0 */ 	sw	$zero,0x2c0($a2)
/*  f014dd8:	316effef */ 	andi	$t6,$t3,0xffef
/*  f014ddc:	e4d402c4 */ 	swc1	$f20,0x2c4($a2)
/*  f014de0:	acc002c8 */ 	sw	$zero,0x2c8($a2)
/*  f014de4:	a0ce009c */ 	sb	$t6,0x9c($a2)
/*  f014de8:	acc002cc */ 	sw	$zero,0x2cc($a2)
/*  f014dec:	0c004b70 */ 	jal	random
/*  f014df0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014df4:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014df8:	0c004b70 */ 	jal	random
/*  f014dfc:	acc202d0 */ 	sw	$v0,0x2d0($a2)
/*  f014e00:	44829000 */ 	mtc1	$v0,$f18
/*  f014e04:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014e08:	04410005 */ 	bgez	$v0,.L0f014e20
/*  f014e0c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f014e10:	3c014f80 */ 	lui	$at,0x4f80
/*  f014e14:	44813000 */ 	mtc1	$at,$f6
/*  f014e18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014e1c:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f014e20:
/*  f014e20:	3c012f80 */ 	lui	$at,0x2f80
/*  f014e24:	44814000 */ 	mtc1	$at,$f8
/*  f014e28:	90cd009c */ 	lbu	$t5,0x9c($a2)
/*  f014e2c:	a0c00078 */ 	sb	$zero,0x78($a2)
/*  f014e30:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f014e34:	31acfffe */ 	andi	$t4,$t5,0xfffe
/*  f014e38:	a0cc009c */ 	sb	$t4,0x9c($a2)
/*  f014e3c:	acc00050 */ 	sw	$zero,0x50($a2)
/*  f014e40:	a0c0009d */ 	sb	$zero,0x9d($a2)
/*  f014e44:	1000000a */ 	beqz	$zero,.L0f014e70
/*  f014e48:	e4ca02d4 */ 	swc1	$f10,0x2d4($a2)
.L0f014e4c:
/*  f014e4c:	91020000 */ 	lbu	$v0,0x0($t0)
/*  f014e50:	3c01800b */ 	lui	$at,0x800b
/*  f014e54:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f014e58:	304f00ff */ 	andi	$t7,$v0,0xff
/*  f014e5c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f014e60:	00380821 */ 	addu	$at,$at,$t8
/*  f014e64:	a10f0000 */ 	sb	$t7,0x0($t0)
/*  f014e68:	10000004 */ 	beqz	$zero,.L0f014e7c
/*  f014e6c:	ac20cc80 */ 	sw	$zero,-0x3380($at)
.L0f014e70:
/*  f014e70:	02002025 */ 	or	$a0,$s0,$zero
/*  f014e74:	0fc053a4 */ 	jal	func0f014e90
/*  f014e78:	2405000a */ 	addiu	$a1,$zero,0xa
.L0f014e7c:
/*  f014e7c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f014e80:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f014e84:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f014e88:	03e00008 */ 	jr	$ra
/*  f014e8c:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f014e90
/*  f014e90:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f014e94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f014e98:	00803825 */ 	or	$a3,$a0,$zero
/*  f014e9c:	10800016 */ 	beqz	$a0,.L0f014ef8
/*  f014ea0:	00a03025 */ 	or	$a2,$a1,$zero
/*  f014ea4:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f014ea8:	50400014 */ 	beqzl	$v0,.L0f014efc
/*  f014eac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f014eb0:	18a00011 */ 	blez	$a1,.L0f014ef8
/*  f014eb4:	28a10100 */ 	slti	$at,$a1,0x100
/*  f014eb8:	14200002 */ 	bnez	$at,.L0f014ec4
/*  f014ebc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014ec0:	240600ff */ 	addiu	$a2,$zero,0xff
.L0f014ec4:
/*  f014ec4:	00062080 */ 	sll	$a0,$a2,0x2
/*  f014ec8:	00862021 */ 	addu	$a0,$a0,$a2
/*  f014ecc:	00042080 */ 	sll	$a0,$a0,0x2
/*  f014ed0:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f014ed4:	a0460018 */ 	sb	$a2,0x18($v0)
/*  f014ed8:	348e000f */ 	ori	$t6,$a0,0xf
/*  f014edc:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f014ee0:	0c0048f2 */ 	jal	func000123c8
/*  f014ee4:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f014ee8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f014eec:	8c9802d4 */ 	lw	$t8,0x2d4($a0)
/*  f014ef0:	0fc65f00 */ 	jal	func0f197c00
/*  f014ef4:	af020014 */ 	sw	$v0,0x14($t8)
.L0f014ef8:
/*  f014ef8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f014efc:
/*  f014efc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f014f00:	03e00008 */ 	jr	$ra
/*  f014f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014f0c:	00000000 */ 	sll	$zero,$zero,0x0
);
