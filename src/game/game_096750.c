#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0969d0.h"
#include "gvars/gvars.h"
#include "lib/lib_4a360.h"
#include "types.h"

const u32 var7f1ab830[] = {0x40490fdb};
const u32 var7f1ab834[] = {0x3fc90fdb};
const u32 var7f1ab838[] = {0x4096cbe4};
const u32 var7f1ab83c[] = {0x40c90fdb};
const u32 var7f1ab840[] = {0x3fc90fdb};
const u32 var7f1ab844[] = {0x40490fdb};
const u32 var7f1ab848[] = {0x40c90fdb};
const u32 var7f1ab84c[] = {0x00000000};
const u32 var7f1ab850[] = {0x46fffe00};
const u32 var7f1ab854[] = {0x40490fdb};
const u32 var7f1ab858[] = {0x477fff00};
const u32 var7f1ab85c[] = {0x46fffe00};
const u32 var7f1ab860[] = {0x40490fdb};
const u32 var7f1ab864[] = {0x477fff00};
const u32 var7f1ab868[] = {0x00000000};
const u32 var7f1ab86c[] = {0x00000000};
const u32 var7f1ab870[] = {0x3c23d70a};
const u32 var7f1ab874[] = {0xbf7fff58};
const u32 var7f1ab878[] = {0x3f7fff58};
const u32 var7f1ab87c[] = {0xbf7fff58};
const u32 var7f1ab880[] = {0x3f7fff58};
const u32 var7f1ab884[] = {0x00000000};
const u32 var7f1ab888[] = {0x00000000};
const u32 var7f1ab88c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f096750
/*  f096750:	44808000 */ 	mtc1	$zero,$f16
/*  f096754:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f096758:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f09675c:	46106032 */ 	c.eq.s	$f12,$f16
/*  f096760:	46006506 */ 	mov.s	$f20,$f12
/*  f096764:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f096768:	4502000a */ 	bc1fl	.L0f096794
/*  f09676c:	46107032 */ 	c.eq.s	$f14,$f16
/*  f096770:	460e803e */ 	c.le.s	$f16,$f14
/*  f096774:	3c017f1b */ 	lui	$at,%hi(var7f1ab830)
/*  f096778:	45000003 */ 	bc1f	.L0f096788
/*  f09677c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096780:	1000003b */ 	beqz	$zero,.L0f096870
/*  f096784:	46008086 */ 	mov.s	$f2,$f16
.L0f096788:
/*  f096788:	10000039 */ 	beqz	$zero,.L0f096870
/*  f09678c:	c422b830 */ 	lwc1	$f2,%lo(var7f1ab830)($at)
/*  f096790:	46107032 */ 	c.eq.s	$f14,$f16
.L0f096794:
/*  f096794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096798:	4500000a */ 	bc1f	.L0f0967c4
/*  f09679c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0967a0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0967a4:	3c017f1b */ 	lui	$at,%hi(var7f1ab834)
/*  f0967a8:	45000004 */ 	bc1f	.L0f0967bc
/*  f0967ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0967b0:	3c017f1b */ 	lui	$at,%hi(var7f1ab838)
/*  f0967b4:	1000002e */ 	beqz	$zero,.L0f096870
/*  f0967b8:	c422b834 */ 	lwc1	$f2,%lo(var7f1ab834)($at)
.L0f0967bc:
/*  f0967bc:	1000002c */ 	beqz	$zero,.L0f096870
/*  f0967c0:	c422b838 */ 	lwc1	$f2,%lo(var7f1ab838)($at)
.L0f0967c4:
/*  f0967c4:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f0967c8:	e7ae0024 */ 	swc1	$f14,0x24($sp)
/*  f0967cc:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0967d0:	0c012974 */ 	jal	sqrtf
/*  f0967d4:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0967d8:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*  f0967dc:	46000086 */ 	mov.s	$f2,$f0
/*  f0967e0:	4614703c */ 	c.lt.s	$f14,$f20
/*  f0967e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0967e8:	4502000e */ 	bc1fl	.L0f096824
/*  f0967ec:	4602a303 */ 	div.s	$f12,$f20,$f2
/*  f0967f0:	0fc25a74 */ 	jal	func0f0969d0
/*  f0967f4:	46007303 */ 	div.s	$f12,$f14,$f0
/*  f0967f8:	44808000 */ 	mtc1	$zero,$f16
/*  f0967fc:	46000086 */ 	mov.s	$f2,$f0
/*  f096800:	3c017f1b */ 	lui	$at,%hi(var7f1ab83c)
/*  f096804:	4610a03c */ 	c.lt.s	$f20,$f16
/*  f096808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09680c:	45020019 */ 	bc1fl	.L0f096874
/*  f096810:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f096814:	c428b83c */ 	lwc1	$f8,%lo(var7f1ab83c)($at)
/*  f096818:	10000015 */ 	beqz	$zero,.L0f096870
/*  f09681c:	46004081 */ 	sub.s	$f2,$f8,$f0
/*  f096820:	4602a303 */ 	div.s	$f12,$f20,$f2
.L0f096824:
/*  f096824:	0fc25a74 */ 	jal	func0f0969d0
/*  f096828:	e7ae0024 */ 	swc1	$f14,0x24($sp)
/*  f09682c:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*  f096830:	44808000 */ 	mtc1	$zero,$f16
/*  f096834:	3c017f1b */ 	lui	$at,%hi(var7f1ab840)
/*  f096838:	c42ab840 */ 	lwc1	$f10,%lo(var7f1ab840)($at)
/*  f09683c:	4610703c */ 	c.lt.s	$f14,$f16
/*  f096840:	3c017f1b */ 	lui	$at,%hi(var7f1ab844)
/*  f096844:	46005301 */ 	sub.s	$f12,$f10,$f0
/*  f096848:	45000003 */ 	bc1f	.L0f096858
/*  f09684c:	46006086 */ 	mov.s	$f2,$f12
/*  f096850:	c432b844 */ 	lwc1	$f18,%lo(var7f1ab844)($at)
/*  f096854:	460c9081 */ 	sub.s	$f2,$f18,$f12
.L0f096858:
/*  f096858:	4610103c */ 	c.lt.s	$f2,$f16
/*  f09685c:	3c017f1b */ 	lui	$at,%hi(var7f1ab848)
/*  f096860:	45020004 */ 	bc1fl	.L0f096874
/*  f096864:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f096868:	c424b848 */ 	lwc1	$f4,%lo(var7f1ab848)($at)
/*  f09686c:	46041080 */ 	add.s	$f2,$f2,$f4
.L0f096870:
/*  f096870:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f096874:
/*  f096874:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f096878:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09687c:	03e00008 */ 	jr	$ra
/*  f096880:	46001006 */ 	mov.s	$f0,$f2
/*  f096884:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09688c:	00000000 */ 	sll	$zero,$zero,0x0
);
