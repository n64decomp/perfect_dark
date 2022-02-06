#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/bg.h"
#include "game/game_165670.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

struct twowords twowords_26a40[] = {
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc232dff, 0xfffffe38 },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26a58[] = {
	{ 0xb900031d, 0x0c192078 },
	{ 0xb900031d, 0xc8112078 },
	{ 0xb900031d, 0x0c182078 },
	{ 0xb900031d, 0xc8102078 },
	{ 0xb900031d, 0x0c192d58 },
	{ 0xb900031d, 0xc8112d58 },
	{ 0xb900031d, 0x0c184dd8 },
	{ 0xb900031d, 0xc8104dd8 },
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0xc81049d8 },
	{ 0xb900031d, 0x0c193078 },
	{ 0xb900031d, 0xc8113078 },
	{ 0xb900031d, 0x0c192048 },
	{ 0xb900031d, 0xc8112048 },
	{ 0xb900031d, 0x0c182048 },
	{ 0xb900031d, 0xc8102048 },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e404, 0x1f14ffff },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26b90[] = {
	{ 0xb900031d, 0x0c184dd8 },
	{ 0xb900031d, 0xc8104dd8 },
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0xc81049d8 },
	{ 0xb900031d, 0x0c193078 },
	{ 0xb900031d, 0xc8113078 },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e404, 0x1f14ffff },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26c78[] = {
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26d20[] = {
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1493ff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc121a24, 0xff37ffff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fd },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127e24, 0xfffffbfd },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfcffffff, 0xfffe7a38 },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfcffffff, 0xfffe7b3d },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26dc8[] = {
	{ 0xb900031d, 0x005049d8 },
	{ 0xb900031d, 0x00553078 },
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0x0c193078 },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26df0[] = {
	{ 0xb900031d, 0x00552078 },
	{ 0xb900031d, 0x00502078 },
	{ 0xb900031d, 0x0c192078 },
	{ 0xb900031d, 0x0c182078 },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26e18[] = {
	{ 0xb900031d, 0x0c1849d8 },
	{ 0xb900031d, 0x0c184b50 },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26e30[] = {
	{ 0xba001402, 0x00000000 },
	{ 0xba001402, 0x00100000 },
	{ 0xb900031d, 0x00502048 },
	{ 0xb900031d, 0x08d02048 },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc127fff, 0xfffff838 },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26e68[] = {
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfc637ec6, 0xfffff9fc },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0xfc637fff, 0xfffff838 },
	{ 0x00000000, 0x00000000 },
};

struct twowords twowords_26f50[] = {
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc137e26, 0xfffff9fc },
	{ 0xfc127e24, 0xfffff9fc },
	{ 0xfc131826, 0xff33ffff },
	{ 0xfc121824, 0xff33ffff },
	{ 0xfc637ec6, 0xfffff9fc },
	{ 0xfcffffff, 0xfffe793c },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26a006, 0x1ffc93fc },
	{ 0xfc26a004, 0x1ffc93fc },
	{ 0xfc26a006, 0x1f1093ff },
	{ 0xfc26a004, 0x1f1093ff },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc26e406, 0x1ffcfffc },
	{ 0xfc26e404, 0x1ffcfffc },
	{ 0xfc26e406, 0x1f10ffff },
	{ 0xfc26e404, 0x1f10ffff },
	{ 0xfc637fff, 0xfffff838 },
	{ 0xfcffffff, 0xfffe7838 },
	{ 0x00000000, 0x00000000 },
};

u32 var80081018 = (u32) &twowords_26a40;
u32 var8008101c = (u32) &twowords_26a58;
u32 var80081020 = (u32) &twowords_26dc8;
u32 var80081024 = (u32) &twowords_26df0;
u32 var80081028 = (u32) &twowords_26e18;
u32 var8008102c = (u32) &twowords_26b90;
u32 var80081030 = (u32) &twowords_26c78;
u32 var80081034 = (u32) &twowords_26d20;
u32 var80081038 = (u32) &twowords_26e30;
u32 var8008103c = (u32) &twowords_26e68;
u32 var80081040 = (u32) &twowords_26f50;

GLOBAL_ASM(
glabel func0f165670
/*  f165670:	10a00004 */ 	beqz	$a1,.L0f165684
/*  f165674:	00801025 */ 	or	$v0,$a0,$zero
/*  f165678:	0045082b */ 	sltu	$at,$v0,$a1
/*  f16567c:	14200006 */ 	bnez	$at,.L0f165698
/*  f165680:	00000000 */ 	nop
.L0f165684:
/*  f165684:	14a00026 */ 	bnez	$a1,.L0f165720
/*  f165688:	00000000 */ 	nop
/*  f16568c:	808e0000 */ 	lb	$t6,0x0($a0)
/*  f165690:	2407ffb8 */ 	addiu	$a3,$zero,-72
/*  f165694:	10ee0022 */ 	beq	$a3,$t6,.L0f165720
.L0f165698:
/*  f165698:	3c088008 */ 	lui	$t0,%hi(var80081018)
/*  f16569c:	25081018 */ 	addiu	$t0,$t0,%lo(var80081018)
/*  f1656a0:	00067880 */ 	sll	$t7,$a2,0x2
/*  f1656a4:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f1656a8:	8f030000 */ 	lw	$v1,0x0($t8)
/*  f1656ac:	2407ffb8 */ 	addiu	$a3,$zero,-72
/*  f1656b0:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f1656b4:	10800010 */ 	beqz	$a0,.L0f1656f8
/*  f1656b8:	00000000 */ 	nop
/*  f1656bc:	8c590000 */ 	lw	$t9,0x0($v0)
.L0f1656c0:
/*  f1656c0:	5724000a */ 	bnel	$t9,$a0,.L0f1656ec
/*  f1656c4:	8c640010 */ 	lw	$a0,0x10($v1)
/*  f1656c8:	8c490004 */ 	lw	$t1,0x4($v0)
/*  f1656cc:	8c6a0004 */ 	lw	$t2,0x4($v1)
/*  f1656d0:	552a0006 */ 	bnel	$t1,$t2,.L0f1656ec
/*  f1656d4:	8c640010 */ 	lw	$a0,0x10($v1)
/*  f1656d8:	8c610008 */ 	lw	$at,0x8($v1)
/*  f1656dc:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1656e0:	8c6c000c */ 	lw	$t4,0xc($v1)
/*  f1656e4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1656e8:	8c640010 */ 	lw	$a0,0x10($v1)
.L0f1656ec:
/*  f1656ec:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f1656f0:	5480fff3 */ 	bnezl	$a0,.L0f1656c0
/*  f1656f4:	8c590000 */ 	lw	$t9,0x0($v0)
.L0f1656f8:
/*  f1656f8:	10a00004 */ 	beqz	$a1,.L0f16570c
/*  f1656fc:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f165700:	0045082b */ 	sltu	$at,$v0,$a1
/*  f165704:	1420ffe4 */ 	bnez	$at,.L0f165698
/*  f165708:	00000000 */ 	nop
.L0f16570c:
/*  f16570c:	14a00004 */ 	bnez	$a1,.L0f165720
/*  f165710:	00000000 */ 	nop
/*  f165714:	804d0000 */ 	lb	$t5,0x0($v0)
/*  f165718:	14edffdf */ 	bne	$a3,$t5,.L0f165698
/*  f16571c:	00000000 */ 	nop
.L0f165720:
/*  f165720:	03e00008 */ 	jr	$ra
/*  f165724:	00000000 */ 	nop
);

void func0f165728(struct roomgfxdata18 *arg0, s32 arg1)
{
	if (arg0->unk00 == 1);

	while (true) {
		if (!arg0) {
			return;
		}

		switch (arg0->unk00) {
		case 0:
			func0f165670(arg0->gdl, 0, arg1);
			arg0 = arg0->next;
			break;
		case 1:
			func0f165728((struct roomgfxdata18 *)arg0->gdl, arg1);
			arg0 = arg0->next;
			break;
		default:
			return;
		}
	}
}
