#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/game_005fd0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/inventory/inventory.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/game_190260.h"
#include "game/game_197600.h"
#include "game/gfxmemory.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

struct menudialog g_AmPickTargetMenuDialog;

/**
 * This is a map of weapon numbers (as per the weapon set) to active menu slots.
 * For the purpose of this array, the AM slots are:
 *
 * 0-2 = top left to top right
 * 3,4 = left, right
 * 5-7 = bottom left to bottom right
 *
 * The values in the array are the slot numbers where that weapon will go.
 * For example, the value at index 2 is 6 which means weapon #2 from the
 * weapon set will go into slot 6 which is the bottom slot.
 */
const u8 g_AmMapping[] = {
	0, // unarmed
	1, // weapon #1
	6, // weapon #2
	3, // weapon #3
	4, // weapon #4
	7, // weapon #5
	5, // weapon #6
	2, // unused
};

void amOpenPickTarget(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	if (!mpIsPaused()) {
		g_AmMenus[g_AmIndex].prevallbots = g_AmMenus[g_AmIndex].allbots;
		g_Vars.currentplayer->activemenumode = AMMODE_CLOSED;
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
		menuPushRootDialog(&g_AmPickTargetMenuDialog, MENUROOT_PICKTARGET);
		g_MpPlayerNum = prevplayernum;
	}
}

u32 var80071940 = 0xff666600;
u32 var80071944 = 0xffff0000;
u32 var80071948 = 0x4444ff00;
u32 var8007194c = 0xff00ff00;
u32 var80071950 = 0x00ffff00;
u32 var80071954 = 0xff885500;
u32 var80071958 = 0x8800ff00;
u32 var8007195c = 0x88445500;

GLOBAL_ASM(
glabel amPickTargetMenuList
.late_rodata
glabel var7f1b2c8c
.word amPickTargetMenuList+0x34 # f0fd724
glabel var7f1b2c90
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2c94
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2c98
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2c9c
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2ca0
.word amPickTargetMenuList+0x1a4 # f0fd894
glabel var7f1b2ca4
.word amPickTargetMenuList+0x2e8 # f0fd9d8
glabel var7f1b2ca8
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cac
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cb0
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cb4
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cb8
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cbc
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cc0
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cc4
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cc8
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2ccc
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cd0
.word amPickTargetMenuList+0x570 # f0fdc60
glabel var7f1b2cd4
.word amPickTargetMenuList+0x2fc # f0fd9ec
glabel var7f1b2cd8
.word amPickTargetMenuList+0x564 # f0fdc54
.text
/*  f0fd6f0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0fd6f4:	248effff */ 	addiu	$t6,$a0,-1
/*  f0fd6f8:	2dc10014 */ 	sltiu	$at,$t6,0x14
/*  f0fd6fc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0fd700:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f0fd704:	10200156 */ 	beqz	$at,.L0f0fdc60
/*  f0fd708:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f0fd70c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0fd710:	3c017f1b */ 	lui	$at,%hi(var7f1b2c8c)
/*  f0fd714:	002e0821 */ 	addu	$at,$at,$t6
/*  f0fd718:	8c2e2c8c */ 	lw	$t6,%lo(var7f1b2c8c)($at)
/*  f0fd71c:	01c00008 */ 	jr	$t6
/*  f0fd720:	00000000 */ 	nop
/*  f0fd724:	3c0f800a */ 	lui	$t7,%hi(g_AmIndex)
/*  f0fd728:	8def21b8 */ 	lw	$t7,%lo(g_AmIndex)($t7)
/*  f0fd72c:	3c19800a */ 	lui	$t9,%hi(g_AmMenus+0x33)
/*  f0fd730:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd734:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fd738:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fd73c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fd740:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fd744:	93392103 */ 	lbu	$t9,%lo(g_AmMenus+0x33)($t9)
/*  f0fd748:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fd74c:	3c06800b */ 	lui	$a2,%hi(g_MpNumPlayers)
/*  f0fd750:	1320004b */ 	beqz	$t9,.L0f0fd880
/*  f0fd754:	3c0e800b */ 	lui	$t6,%hi(g_MpNumPlayers)
/*  f0fd758:	8d6e0284 */ 	lw	$t6,0x284($t3)
/*  f0fd75c:	8d6c006c */ 	lw	$t4,0x6c($t3)
/*  f0fd760:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd764:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0fd768:	00004825 */ 	or	$t1,$zero,$zero
/*  f0fd76c:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0fd770:	11800003 */ 	beqz	$t4,.L0f0fd780
/*  f0fd774:	afb800ac */ 	sw	$t8,0xac($sp)
/*  f0fd778:	10000001 */ 	b	.L0f0fd780
/*  f0fd77c:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fd780:
/*  f0fd780:	8d6d0068 */ 	lw	$t5,0x68($t3)
/*  f0fd784:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd788:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd78c:	11a00003 */ 	beqz	$t5,.L0f0fd79c
/*  f0fd790:	00000000 */ 	nop
/*  f0fd794:	10000001 */ 	b	.L0f0fd79c
/*  f0fd798:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd79c:
/*  f0fd79c:	8d7f0064 */ 	lw	$ra,0x64($t3)
/*  f0fd7a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd7a4:	13e00003 */ 	beqz	$ra,.L0f0fd7b4
/*  f0fd7a8:	00000000 */ 	nop
/*  f0fd7ac:	10000001 */ 	b	.L0f0fd7b4
/*  f0fd7b0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fd7b4:
/*  f0fd7b4:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f0fd7b8:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f0fd7bc:	11400003 */ 	beqz	$t2,.L0f0fd7cc
/*  f0fd7c0:	00000000 */ 	nop
/*  f0fd7c4:	10000001 */ 	b	.L0f0fd7cc
/*  f0fd7c8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd7cc:
/*  f0fd7cc:	8cc6c530 */ 	lw	$a2,%lo(g_MpNumPlayers)($a2)
/*  f0fd7d0:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0fd7d4:	03277021 */ 	addu	$t6,$t9,$a3
/*  f0fd7d8:	01c91021 */ 	addu	$v0,$t6,$t1
/*  f0fd7dc:	0046082a */ 	slt	$at,$v0,$a2
/*  f0fd7e0:	10200010 */ 	beqz	$at,.L0f0fd824
/*  f0fd7e4:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0fd7e8:	3c19800b */ 	lui	$t9,%hi(g_MpPlayerChrs)
/*  f0fd7ec:	2739c4d0 */ 	addiu	$t9,$t9,%lo(g_MpPlayerChrs)
/*  f0fd7f0:	00067080 */ 	sll	$t6,$a2,0x2
/*  f0fd7f4:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f0fd7f8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0fd7fc:	91e30125 */ 	lbu	$v1,0x125($t7)
/*  f0fd800:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f0fd804:
/*  f0fd804:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0fd808:	0044082b */ 	sltu	$at,$v0,$a0
/*  f0fd80c:	91f80125 */ 	lbu	$t8,0x125($t7)
/*  f0fd810:	10780002 */ 	beq	$v1,$t8,.L0f0fd81c
/*  f0fd814:	00000000 */ 	nop
/*  f0fd818:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0fd81c:
/*  f0fd81c:	5420fff9 */ 	bnezl	$at,.L0f0fd804
/*  f0fd820:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f0fd824:
/*  f0fd824:	11400003 */ 	beqz	$t2,.L0f0fd834
/*  f0fd828:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0fd82c:	10000002 */ 	b	.L0f0fd838
/*  f0fd830:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fd834:
/*  f0fd834:	00004825 */ 	or	$t1,$zero,$zero
.L0f0fd838:
/*  f0fd838:	11800003 */ 	beqz	$t4,.L0f0fd848
/*  f0fd83c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd840:	10000001 */ 	b	.L0f0fd848
/*  f0fd844:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd848:
/*  f0fd848:	11a00003 */ 	beqz	$t5,.L0f0fd858
/*  f0fd84c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd850:	10000001 */ 	b	.L0f0fd858
/*  f0fd854:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fd858:
/*  f0fd858:	13e00003 */ 	beqz	$ra,.L0f0fd868
/*  f0fd85c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd860:	10000001 */ 	b	.L0f0fd868
/*  f0fd864:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd868:
/*  f0fd868:	00a37021 */ 	addu	$t6,$a1,$v1
/*  f0fd86c:	01c4c821 */ 	addu	$t9,$t6,$a0
/*  f0fd870:	03277821 */ 	addu	$t7,$t9,$a3
/*  f0fd874:	01e92821 */ 	addu	$a1,$t7,$t1
/*  f0fd878:	100000f9 */ 	b	.L0f0fdc60
/*  f0fd87c:	af050000 */ 	sw	$a1,0x0($t8)
.L0f0fd880:
/*  f0fd880:	8dcec530 */ 	lw	$t6,%lo(g_MpNumPlayers)($t6)
/*  f0fd884:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fd888:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f0fd88c:	100000f4 */ 	b	.L0f0fdc60
/*  f0fd890:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fd894:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f0fd898:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f0fd89c:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0fd8a0:	3c0f800a */ 	lui	$t7,%hi(g_AmMenus)
/*  f0fd8a4:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0fd8a8:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0fd8ac:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd8b0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fd8b4:	25ef20d0 */ 	addiu	$t7,$t7,%lo(g_AmMenus)
/*  f0fd8b8:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fd8bc:	032f5021 */ 	addu	$t2,$t9,$t7
/*  f0fd8c0:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f0fd8c4:	81580000 */ 	lb	$t8,0x0($t2)
/*  f0fd8c8:	8d670284 */ 	lw	$a3,0x284($t3)
/*  f0fd8cc:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f0fd8d0:	2529c4d0 */ 	addiu	$t1,$t1,%lo(g_MpPlayerChrs)
/*  f0fd8d4:	00f87021 */ 	addu	$t6,$a3,$t8
/*  f0fd8d8:	91d91be5 */ 	lbu	$t9,0x1be5($t6)
/*  f0fd8dc:	3c06800b */ 	lui	$a2,%hi(var800ac4cc)
/*  f0fd8e0:	24c6c4cc */ 	addiu	$a2,$a2,%lo(var800ac4cc)
/*  f0fd8e4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0fd8e8:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f0fd8ec:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f0fd8f0:	91480033 */ 	lbu	$t0,0x33($t2)
/*  f0fd8f4:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0fd8f8:	8cf900bc */ 	lw	$t9,0xbc($a3)
/*  f0fd8fc:	8f240004 */ 	lw	$a0,0x4($t9)
.L0f0fd900:
/*  f0fd900:	1100000a */ 	beqz	$t0,.L0f0fd92c
/*  f0fd904:	24c60004 */ 	addiu	$a2,$a2,0x0004
/*  f0fd908:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f0fd90c:	10830005 */ 	beq	$a0,$v1,.L0f0fd924
/*  f0fd910:	00000000 */ 	nop
/*  f0fd914:	908f0125 */ 	lbu	$t7,0x125($a0)
/*  f0fd918:	90780125 */ 	lbu	$t8,0x125($v1)
/*  f0fd91c:	11f80008 */ 	beq	$t7,$t8,.L0f0fd940
/*  f0fd920:	00000000 */ 	nop
.L0f0fd924:
/*  f0fd924:	10000006 */ 	b	.L0f0fd940
/*  f0fd928:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0fd92c:
/*  f0fd92c:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f0fd930:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0fd934:	11c30002 */ 	beq	$t6,$v1,.L0f0fd940
/*  f0fd938:	00000000 */ 	nop
/*  f0fd93c:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0fd940:
/*  f0fd940:	0441ffef */ 	bgez	$v0,.L0f0fd900
/*  f0fd944:	00000000 */ 	nop
/*  f0fd948:	1100001d */ 	beqz	$t0,.L0f0fd9c0
/*  f0fd94c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0fd950:	a1400033 */ 	sb	$zero,0x33($t2)
/*  f0fd954:	90f91be6 */ 	lbu	$t9,0x1be6($a3)
/*  f0fd958:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd95c:	1b20001a */ 	blez	$t9,.L0f0fd9c8
/*  f0fd960:	00e27821 */ 	addu	$t7,$a3,$v0
.L0f0fd964:
/*  f0fd964:	91f81be7 */ 	lbu	$t8,0x1be7($t7)
/*  f0fd968:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f0fd96c:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f0fd970:	2529c4d0 */ 	addiu	$t1,$t1,%lo(g_MpPlayerChrs)
/*  f0fd974:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0fd978:	012ec821 */ 	addu	$t9,$t1,$t6
/*  f0fd97c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0fd980:	8de5001c */ 	lw	$a1,0x1c($t7)
/*  f0fd984:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0fd988:	0fc6490e */ 	jal	mpAibotApplyAttack
/*  f0fd98c:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0fd990:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd994:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fd998:	8d670284 */ 	lw	$a3,0x284($t3)
/*  f0fd99c:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0fd9a0:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0fd9a4:	90f81be6 */ 	lbu	$t8,0x1be6($a3)
/*  f0fd9a8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fd9ac:	0058082a */ 	slt	$at,$v0,$t8
/*  f0fd9b0:	5420ffec */ 	bnezl	$at,.L0f0fd964
/*  f0fd9b4:	00e27821 */ 	addu	$t7,$a3,$v0
/*  f0fd9b8:	10000003 */ 	b	.L0f0fd9c8
/*  f0fd9bc:	00000000 */ 	nop
.L0f0fd9c0:
/*  f0fd9c0:	0fc6490e */ 	jal	mpAibotApplyAttack
/*  f0fd9c4:	8c65001c */ 	lw	$a1,0x1c($v1)
.L0f0fd9c8:
/*  f0fd9c8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fd9cc:	00000000 */ 	nop
/*  f0fd9d0:	100000a4 */ 	b	.L0f0fdc64
/*  f0fd9d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd9d8:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0fd9dc:	3c0e000f */ 	lui	$t6,0xf
/*  f0fd9e0:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0fd9e4:	1000009e */ 	b	.L0f0fdc60
/*  f0fd9e8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0fd9ec:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fd9f0:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f0fd9f4:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f0fd9f8:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0fd9fc:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fda00:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0fda04:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f0fda08:	3c18800a */ 	lui	$t8,%hi(g_AmMenus)
/*  f0fda0c:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0fda10:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fda14:	271820d0 */ 	addiu	$t8,$t8,%lo(g_AmMenus)
/*  f0fda18:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fda1c:	03385021 */ 	addu	$t2,$t9,$t8
/*  f0fda20:	8dec0008 */ 	lw	$t4,0x8($t7)
/*  f0fda24:	8de30004 */ 	lw	$v1,0x4($t7)
/*  f0fda28:	814f0000 */ 	lb	$t7,0x0($t2)
/*  f0fda2c:	8d670284 */ 	lw	$a3,0x284($t3)
/*  f0fda30:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f0fda34:	3c04800b */ 	lui	$a0,%hi(var800ac4cc)
/*  f0fda38:	00ef7021 */ 	addu	$t6,$a3,$t7
/*  f0fda3c:	91d91be5 */ 	lbu	$t9,0x1be5($t6)
/*  f0fda40:	8cef00bc */ 	lw	$t7,0xbc($a3)
/*  f0fda44:	2484c4cc */ 	addiu	$a0,$a0,%lo(var800ac4cc)
/*  f0fda48:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0fda4c:	01384821 */ 	addu	$t1,$t1,$t8
/*  f0fda50:	8d29c4d0 */ 	lw	$t1,%lo(g_MpPlayerChrs)($t1)
/*  f0fda54:	91480033 */ 	lbu	$t0,0x33($t2)
/*  f0fda58:	2405fffc */ 	addiu	$a1,$zero,-4
/*  f0fda5c:	8de60004 */ 	lw	$a2,0x4($t7)
/*  f0fda60:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f0fda64:
/*  f0fda64:	1100000a */ 	beqz	$t0,.L0f0fda90
/*  f0fda68:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0fda6c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0fda70:	10c20005 */ 	beq	$a2,$v0,.L0f0fda88
/*  f0fda74:	00000000 */ 	nop
/*  f0fda78:	90ce0125 */ 	lbu	$t6,0x125($a2)
/*  f0fda7c:	90590125 */ 	lbu	$t9,0x125($v0)
/*  f0fda80:	11d90007 */ 	beq	$t6,$t9,.L0f0fdaa0
/*  f0fda84:	00000000 */ 	nop
.L0f0fda88:
/*  f0fda88:	10000005 */ 	b	.L0f0fdaa0
/*  f0fda8c:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f0fda90:
/*  f0fda90:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0fda94:	11380002 */ 	beq	$t1,$t8,.L0f0fdaa0
/*  f0fda98:	00000000 */ 	nop
/*  f0fda9c:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f0fdaa0:
/*  f0fdaa0:	0463fff0 */ 	bgezl	$v1,.L0f0fda64
/*  f0fdaa4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f0fdaa8:	3c0f800b */ 	lui	$t7,%hi(var800ac500)
/*  f0fdaac:	25efc500 */ 	addiu	$t7,$t7,%lo(var800ac500)
/*  f0fdab0:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f0fdab4:	afae0058 */ 	sw	$t6,0x58($sp)
/*  f0fdab8:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f0fdabc:	3c198007 */ 	lui	$t9,%hi(var80071940)
/*  f0fdac0:	3c014220 */ 	lui	$at,0x4220
/*  f0fdac4:	930f0011 */ 	lbu	$t7,0x11($t8)
/*  f0fdac8:	8d98000c */ 	lw	$t8,0xc($t4)
/*  f0fdacc:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0fdad0:	032ec821 */ 	addu	$t9,$t9,$t6
/*  f0fdad4:	8f391940 */ 	lw	$t9,%lo(var80071940)($t9)
/*  f0fdad8:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f0fdadc:	032f7025 */ 	or	$t6,$t9,$t7
/*  f0fdae0:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0fdae4:	91980010 */ 	lbu	$t8,0x10($t4)
/*  f0fdae8:	53000038 */ 	beqzl	$t8,.L0f0fdbcc
/*  f0fdaec:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0fdaf0:	44816000 */ 	mtc1	$at,$f12
/*  f0fdaf4:	0fc01ac2 */ 	jal	func0f006b08
/*  f0fdaf8:	afac0090 */ 	sw	$t4,0x90($sp)
/*  f0fdafc:	3c01437f */ 	lui	$at,0x437f
/*  f0fdb00:	44812000 */ 	mtc1	$at,$f4
/*  f0fdb04:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fdb08:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f0fdb0c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0fdb10:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fdb14:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0fdb18:	308500ff */ 	andi	$a1,$a0,0xff
/*  f0fdb1c:	4459f800 */ 	cfc1	$t9,$31
/*  f0fdb20:	44cff800 */ 	ctc1	$t7,$31
/*  f0fdb24:	00000000 */ 	nop
/*  f0fdb28:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fdb2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0fdb30:	00000000 */ 	nop
/*  f0fdb34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0fdb38:	51e00013 */ 	beqzl	$t7,.L0f0fdb88
/*  f0fdb3c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0fdb40:	44814000 */ 	mtc1	$at,$f8
/*  f0fdb44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fdb48:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fdb4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0fdb50:	00000000 */ 	nop
/*  f0fdb54:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fdb58:	444ff800 */ 	cfc1	$t7,$31
/*  f0fdb5c:	00000000 */ 	nop
/*  f0fdb60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0fdb64:	15e00005 */ 	bnez	$t7,.L0f0fdb7c
/*  f0fdb68:	00000000 */ 	nop
/*  f0fdb6c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0fdb70:	3c018000 */ 	lui	$at,0x8000
/*  f0fdb74:	10000007 */ 	b	.L0f0fdb94
/*  f0fdb78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0fdb7c:
/*  f0fdb7c:	10000005 */ 	b	.L0f0fdb94
/*  f0fdb80:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0fdb84:	440f4000 */ 	mfc1	$t7,$f8
.L0f0fdb88:
/*  f0fdb88:	00000000 */ 	nop
/*  f0fdb8c:	05e0fffb */ 	bltz	$t7,.L0f0fdb7c
/*  f0fdb90:	00000000 */ 	nop
.L0f0fdb94:
/*  f0fdb94:	44d9f800 */ 	ctc1	$t9,$31
/*  f0fdb98:	0fc01a40 */ 	jal	colourBlend
/*  f0fdb9c:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0fdba0:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f0fdba4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fdba8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fdbac:	8d84000c */ 	lw	$a0,0xc($t4)
/*  f0fdbb0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0fdbb4:	00817025 */ 	or	$t6,$a0,$at
/*  f0fdbb8:	0fc01a40 */ 	jal	colourBlend
/*  f0fdbbc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0fdbc0:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f0fdbc4:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f0fdbc8:	8d980000 */ 	lw	$t8,0x0($t4)
.L0f0fdbcc:
/*  f0fdbcc:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0fdbd0:	2719000a */ 	addiu	$t9,$t8,0xa
/*  f0fdbd4:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0fdbd8:	8d8f0004 */ 	lw	$t7,0x4($t4)
/*  f0fdbdc:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0fdbe0:	0fc54d8a */ 	jal	func0f153628
/*  f0fdbe4:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f0fdbe8:	0c002f02 */ 	jal	viGetWidth
/*  f0fdbec:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0fdbf0:	0c002f06 */ 	jal	viGetHeight
/*  f0fdbf4:	a7a2005c */ 	sh	$v0,0x5c($sp)
/*  f0fdbf8:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0fdbfc:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm1)
/*  f0fdc00:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm2)
/*  f0fdc04:	8f070000 */ 	lw	$a3,0x0($t8)
/*  f0fdc08:	87b8005c */ 	lh	$t8,0x5c($sp)
/*  f0fdc0c:	8deffb0c */ 	lw	$t7,%lo(g_FontHandelGothicSm2)($t7)
/*  f0fdc10:	8f39fb10 */ 	lw	$t9,%lo(g_FontHandelGothicSm1)($t9)
/*  f0fdc14:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0fdc18:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fdc1c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fdc20:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fdc24:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0fdc28:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0fdc2c:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0fdc30:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0fdc34:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0fdc38:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0fdc3c:	0fc5580f */ 	jal	textRenderProjected
/*  f0fdc40:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0fdc44:	0fc54de0 */ 	jal	func0f153780
/*  f0fdc48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fdc4c:	10000006 */ 	b	.L0f0fdc68
/*  f0fdc50:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0fdc54:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fdc58:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0fdc5c:	adf90000 */ 	sw	$t9,0x0($t7)
.L0f0fdc60:
/*  f0fdc60:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fdc64:
/*  f0fdc64:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0fdc68:
/*  f0fdc68:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0fdc6c:	03e00008 */ 	jr	$ra
/*  f0fdc70:	00000000 */ 	nop
);

s32 amPickTargetMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_TICK:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_CLOSE:
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		break;
	}

	return false;
}

struct menuitem g_AmPickTargetMenuItems[] = {
	{ MENUITEMTYPE_LIST, 0, 0x00200000, 0x0000005a, 0x00000000, amPickTargetMenuList },
	{ MENUITEMTYPE_END,  0, 0x00000000, 0x00000000, 0x00000000, NULL                 },
};

struct menudialog g_AmPickTargetMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(492), // "Pick Target"
	g_AmPickTargetMenuItems,
	amPickTargetMenuDialog,
	0x00000000,
	NULL,
};

void amSetAiBuddyTemperament(bool aggressive)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr) {
				if (aggressive) {
					chr->hidden &= ~CHRHFLAG_PASSIVE;
				} else {
					chr->hidden |= CHRHFLAG_PASSIVE;
				}
			}
		}
	}
}

void amSetAiBuddyStealth(void)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr && chr->prop
					&& !chrIsDead(chr)
					&& chr->ailist != ailistFindById(GAILIST_AIBUDDY_STEALTH)
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
				chrStopFiring(chr);
				chr->ailist = ailistFindById(GAILIST_AIBUDDY_STEALTH);
				chr->aioffset = 0;
			}
		}
	}
}

s32 amGetFirstBuddyIndex(void)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr && chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DEAD
					&& chr->prop
					&& chr->model) {
				return i;
			}
		}
	}

	return -1;
}

void amApply(s32 slot)
{
	s32 numinvitems;
	s32 invindex;
	bool pass;
	s32 state;
	s32 weaponnum;
	s32 i;

	switch (g_AmMenus[g_AmIndex].screenindex) {
	case 0: // Weapon
		if (slot > 4) {
			slot--;
		}

		invindex = g_AmMenus[g_AmIndex].invindexes[slot];
		numinvitems = invGetCount();

		if (invindex < numinvitems) {
			weaponnum = invGetWeaponNumByIndex(invindex);
			pass = true;

			if (weaponnum) {
				state = currentPlayerGetDeviceState(weaponnum);

				if (state != DEVICESTATE_UNEQUIPPED) {
					pass = false;

					if (state == DEVICESTATE_INACTIVE) {
						currentPlayerSetDeviceActive(weaponnum, true);
					} else {
						currentPlayerSetDeviceActive(weaponnum, false);
					}
				}
			}

			if (pass) {
				pass = true;

				if (g_FrIsValidWeapon) {
					s32 weaponnum = frGetWeaponBySlot(frGetSlot());

					if (g_Vars.currentplayer->hands[HAND_RIGHT].base.weaponnum == weaponnum) {
						pass = false;
					}
				}

				if (pass) {
					invSetCurrentIndex(invindex);

					if (invHasDoubleWeaponIncAllGuns(weaponnum, weaponnum)) {
						if (handGetWeaponNum(HAND_RIGHT) != weaponnum) {
							currentPlayerEquipWeaponWrapper(HAND_RIGHT, weaponnum);
						}

						if (handGetWeaponNum(HAND_LEFT) != weaponnum) {
							currentPlayerEquipWeaponWrapper(HAND_LEFT, weaponnum);
						}
					} else {
						if (handGetWeaponNum(HAND_RIGHT) != weaponnum) {
							currentPlayerEquipWeaponWrapper(HAND_RIGHT, weaponnum);
						}

						if (handGetWeaponNum(HAND_LEFT) != WEAPON_NONE) {
							currentPlayerEquipWeaponWrapper(HAND_LEFT, WEAPON_NONE);
						}
					}
				}
			}
		}
		break;
	case 1: // Function
		if (g_Vars.currentplayer->weaponnum >= WEAPON_UNARMED
				&& g_Vars.currentplayer->weaponnum <= WEAPON_COMBATBOOST
				&& g_MpPlayers[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->weaponnum - 1) >> 3] & (1 << (g_Vars.currentplayer->weaponnum - 1 & 7))) {
			if (slot == 1) {
				g_AmMenus[g_AmIndex].togglefunc = true;
			}
		} else {
			if (slot != 1) {
				g_AmMenus[g_AmIndex].togglefunc = true;
			}
		}
		break;
	default:
		if (g_MissionConfig.iscoop) {
			if (amGetFirstBuddyIndex() > -1) {
				if (slot == 1) {
					amSetAiBuddyTemperament(true); // aggressive
				} else if (slot == 7) {
					amSetAiBuddyTemperament(false); // passive
				} else if (slot == 3) {
					amSetAiBuddyStealth();
				}
			}
		} else if (g_Vars.normmplayerisrunning) {
			if (g_AmMenus[g_AmIndex].allbots) {
				for (i = 0; i < g_Vars.currentplayer->numaibuddies; i++) {
					mpAibotApplyCommand(g_MpPlayerChrs[g_Vars.currentplayer->aibuddynums[i]], g_AmBotCommands[slot]);
				}
			} else {
				mpAibotApplyCommand(g_MpPlayerChrs[g_Vars.currentplayer->aibuddynums[g_AmMenus[g_AmIndex].screenindex - 2]], g_AmBotCommands[slot]);
			}
		}
	}
}

void amGetSlotDetails(s32 slot, u32 *flags, char *label)
{
	u32 weaponnum;
	s32 qty;
	s32 secs;
	s32 modulo;
	struct weaponfunc *prifunc;
	struct weaponfunc *secfunc;

	switch (g_AmMenus[g_AmIndex].screenindex) {
	case 0: // Weapon screen
		if (slot == 4) {
			strcpy(label, langGet(L_MISC(170))); // "Weapon"
			return;
		}

		if (slot > 4) {
			slot--;
		}

		if (invGetCurrentIndex() == g_AmMenus[g_AmIndex].invindexes[slot]) {
			*flags |= AMSLOTFLAG_CURRENT;
		}

		if (g_AmMenus[g_AmIndex].invindexes[slot] >= invGetCount()) {
			strcpy(label, "");
		} else {
			if (invGetWeaponNumByIndex(g_AmMenus[g_AmIndex].invindexes[slot]) == WEAPON_CLOAKINGDEVICE) {
				// Special case: "Cloak %d"
				qty = ammoGetQuantity(AMMOTYPE_CLOAK);
				secs = qty / 60;
				modulo = (qty - (secs * 60)) * 100 / 60;
				sprintf(label, langGet(L_OPTIONS(491)), secs + (modulo > 0 ? 1 : 0)); // "cloak %d"
			} else {
				strcpy(label, invGetShortNameByIndex(g_AmMenus[g_AmIndex].invindexes[slot]));
			}
		}

		weaponnum = invGetWeaponNumByIndex(g_AmMenus[g_AmIndex].invindexes[slot]);

		if (currentPlayerGetDeviceState(weaponnum) == DEVICESTATE_ACTIVE) {
			*flags |= AMSLOTFLAG_ACTIVE;
		}

		weaponnum = invGetWeaponNumByIndex(g_AmMenus[g_AmIndex].invindexes[slot]);

		if (func0f0a1d14(weaponnum) == false) {
			*flags |= AMSLOTFLAG_NOAMMO;
		}
		break;
	case 1: // Function screen
		strcpy(label, "");

		if (slot == 4) {
			strcpy(label, langGet(L_MISC(171))); // "Function"
		} else if (slot == 1 || slot == 7) {
			prifunc = weaponGetFunction(&g_Vars.currentplayer->hands[HAND_RIGHT].base.weaponnum, FUNC_PRIMARY);
			secfunc = weaponGetFunction(&g_Vars.currentplayer->hands[HAND_RIGHT].base.weaponnum, FUNC_SECONDARY);

			if (slot == 1) {
				if (!secfunc
						|| g_Vars.currentplayer->weaponnum < WEAPON_UNARMED
						|| g_Vars.currentplayer->weaponnum > WEAPON_COMBATBOOST
						|| (g_MpPlayers[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->weaponnum - 1) >> 3] & (1 << (g_Vars.currentplayer->weaponnum - 1 & 7))) == 0) {
					*flags |= AMSLOTFLAG_CURRENT;
				}

				if (prifunc) {
					strcpy(label, langGet(prifunc->name));
				}
			} else {
				if (!prifunc || (
						g_Vars.currentplayer->weaponnum >= WEAPON_UNARMED
						&& g_Vars.currentplayer->weaponnum <= WEAPON_COMBATBOOST
						&& g_MpPlayers[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->weaponnum - 1) >> 3] & (1 << (g_Vars.currentplayer->weaponnum - 1 & 7)))) {
					*flags |= AMSLOTFLAG_CURRENT;
				}

				if (secfunc) {
					strcpy(label, langGet(secfunc->name));
				}
			}
		}
		break;
	default: // Orders screen
		strcpy(label, "");

		if (g_MissionConfig.iscoop) {
			if (slot == 4) {
				strcpy(label, langGet(L_MISC(474))); // "Perfect Buddies"
			} else if (slot == 1) {
				strcpy(label, langGet(L_MISC(472))); // "Aggressive"
			} else if (slot == 7) {
				strcpy(label, langGet(L_MISC(473))); // "Passive"
			} else if (slot == 3) {
				strcpy(label, langGet(L_MISC(475))); // "Stealth"
			}
		} else {
			if (slot == 4) {
				strcpy(label, langGet(L_MISC(172))); // "Orders"
			} else {
				strcpy(label, mpGetBotCommandName(g_AmBotCommands[slot]));
			}
		}
		break;
	}
}

void amInit(void)
{
	s32 i;
	s32 j;

	// @bug? Should this be set for each player?
	g_Vars.currentplayer->activemenumode = AMMODE_CLOSED;

	for (i = 0; i < ARRAYCOUNT(g_AmMenus); i++) {
		g_AmMenus[i].togglefunc = false;

		for (j = 0; j < ARRAYCOUNT(g_AmMenus[i].favourites); j++) {
			g_AmMenus[i].favourites[j] = 0xff;
		}

		if (g_Vars.normmplayerisrunning) {
			s32 index = 0;

			g_AmMenus[i].favourites[g_AmMapping[index]] = WEAPON_UNARMED;
			index++;

			for (j = 0; j < ARRAYCOUNT(g_MpSetup.weapons); j++) {
				s32 weaponnum = g_MpWeapons[g_MpSetup.weapons[j]].weaponnum;

				switch (weaponnum) {
				case WEAPON_NONE:
				case WEAPON_MPSHIELD:
				case WEAPON_DISABLED:
					break;
				default:
					g_AmMenus[i].favourites[g_AmMapping[index]] = weaponnum;
					index++;
					break;
				}
			}
		}
	}

	if (PLAYERCOUNT() >= 2) {
		g_AmFont1 = g_FontHandelGothicXs1;
		g_AmFont2 = g_FontHandelGothicXs2;
	} else {
		g_AmFont1 = g_FontHandelGothicSm1;
		g_AmFont2 = g_FontHandelGothicSm2;
	}

	g_AmIndex = 0;
}

s16 amCalculateSlotWidth(void)
{
	s32 textheight;
	s32 textwidth;
	s32 max = 0;
	s32 i;
	u32 flags;
	char text[32];

	for (i = 0; i != 9; i++) {
		amGetSlotDetails(i, &flags, text);
		textMeasure(&textheight, &textwidth, text, g_AmFont1, g_AmFont2, 0);

		if (textwidth > max) {
			max = textwidth;
		}
	}

	if (PLAYERCOUNT() > 1) {
		max += 3;
	} else {
		max += 4;
	}

	return max;
}

void amChangeScreen(s32 step)
{
	s32 maxscreenindex;

	g_AmMenus[g_AmIndex].screenindex += step;

	if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
		if (g_AmMenus[g_AmIndex].allbots) {
			// Weapon selection, second function, and bot command menu

			// @bug: This is missing a check to see if there are any bots on
			// your team. In most cases this isn't a problem because the player
			// opens the screen for a single bot then uses R to switch to all
			// bots. When they do this without buddy bots the else part below
			// runs first, limits the max screen index to 1 and all is good.
			// But if you hold R as you switch to the bot command menu then this
			// part runs first and sets the screen index to an invalid value,
			// causing a crash.
			maxscreenindex = 2;
		} else {
			// Weapon selection, second function and one for each AI buddy
			maxscreenindex = g_Vars.currentplayer->numaibuddies + 1;
		}
	} else {
		// Solo missions, or MP with no teams
		if (g_MissionConfig.iscoop && amGetFirstBuddyIndex() >= 0) {
			// Weapon selection, second function and AI buddy commands
			maxscreenindex = 2;
		} else {
			// Weapon selection and second function
			maxscreenindex = 1;
		}
	}

	if (g_AmMenus[g_AmIndex].screenindex > maxscreenindex) {
		g_AmMenus[g_AmIndex].screenindex = 0;
	}

	if (g_AmMenus[g_AmIndex].screenindex < 0) {
		g_AmMenus[g_AmIndex].screenindex = maxscreenindex;
	}

	g_AmMenus[g_AmIndex].xradius = 10;
	g_AmMenus[g_AmIndex].dstx = -123;
	g_AmMenus[g_AmIndex].slotnum = 4;
	g_AmMenus[g_AmIndex].returntimer = 0;
	g_AmMenus[g_AmIndex].cornertimer = 0;
	g_AmMenus[g_AmIndex].alphafrac = 0;
	g_AmMenus[g_AmIndex].slotwidth = amCalculateSlotWidth();
}

void amAssignWeaponSlots(void)
{
	s32 numitems = invGetCount();
	u8 weaponnum;
	s32 i;
	s32 j;

	g_AmMenus[g_AmIndex].numitems = numitems;

	// Reset inventory indexes
	for (i = 0; i < ARRAYCOUNT(g_AmMenus[g_AmIndex].invindexes);) {
		g_AmMenus[g_AmIndex].invindexes[i] = 0xff;
		i++;
	}

	// Assign favourites
	for (i = 0; i < numitems; i++) {
		weaponnum = invGetWeaponNumByIndex(i);

		if ((weaponnum >= WEAPON_UNARMED && weaponnum <= WEAPON_DISGUISE41)
				|| weaponnum == WEAPON_SUICIDEPILL
				|| weaponnum == WEAPON_BACKUPDISK
				|| weaponnum == WEAPON_SUITCASE) {
			for (j = 0; j < ARRAYCOUNT(g_AmMenus[g_AmIndex].favourites); j++) {
				if (g_AmMenus[g_AmIndex].favourites[j] == weaponnum) {
					if (g_AmMenus[g_AmIndex].invindexes[j] == 0xff) {
						g_AmMenus[g_AmIndex].invindexes[j] = i;
					} else {
						// empty
					}
					break;
				}
			}
		}
	}

	// If there are still unused slots, fill the remaining slots in inventory
	// order with unfavourited weapons.
	for (i = 0; i < numitems; i++) {
		bool isfavourited = false;

		for (j = 0; j < ARRAYCOUNT(g_AmMenus[g_AmIndex].invindexes); j++) {
			if (g_AmMenus[g_AmIndex].invindexes[j] == i) {
				isfavourited = true;
			}
		}

		if (!isfavourited) {
			weaponnum = invGetWeaponNumByIndex(i);

			if ((weaponnum >= WEAPON_UNARMED && weaponnum <= WEAPON_DISGUISE41)
					|| weaponnum == WEAPON_SUICIDEPILL
					|| weaponnum == WEAPON_SUITCASE) {
				s32 useindex = -1;
				s32 j;

				// Try to find any mapping which is not yet used.
				// While it could just iterate the invitems or weaponnums arrays
				// directly, doing it using the mapping makes it allocate these
				// somewhat randomly rather than in slot order.
				for (j = 0; j < ARRAYCOUNT(g_AmMapping); j++) {
					if (g_AmMenus[g_AmIndex].favourites[g_AmMapping[j]] == 0xff) {
						useindex = j;
						break;
					}
				}

				if (useindex == -1) {
					// This part is pointless. If this part of the code is
					// reached then all the mappings were in use, and therefore
					// all the slots are in use too. There's no way this can
					// find any new slots.
					for (j = 0; j < ARRAYCOUNT(g_AmMapping); j++) {
						if (g_AmMenus[g_AmIndex].invindexes[g_AmMapping[j]] == 0xff) {
							useindex = j;
							break;
						}
					}
				}

				if (useindex >= 0) {
					g_AmMenus[g_AmIndex].invindexes[g_AmMapping[useindex]] = i;
					g_AmMenus[g_AmIndex].favourites[g_AmMapping[useindex]] = weaponnum;
				}
			}
		}
	}
}

void amOpen(void)
{
	if (g_Vars.currentplayer->passivemode == false) {
		g_AmIndex = g_Vars.currentplayernum;
		g_Vars.currentplayer->activemenumode = AMMODE_VIEW;
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		g_AmMenus[g_AmIndex].screenindex = 0;
		g_AmMenus[g_AmIndex].selpulse = 0;
		amAssignWeaponSlots();
		amChangeScreen(0);
		g_AmMenus[g_AmIndex].xradius = g_AmMenus[g_AmIndex].slotwidth + 5;
		g_AmMenus[g_AmIndex].alphafrac = 0.3;
		g_AmMenus[g_AmIndex].origscreennum = 0;
		g_AmMenus[g_AmIndex].prevallbots = 0;
		g_AmMenus[g_AmIndex].allbots = false;
	}
}

void amClose(void)
{
	if (g_AmMenus[g_AmIndex].slotnum != 4) {
		amApply(g_AmMenus[g_AmIndex].slotnum);
	}

	g_Vars.currentplayer->activemenumode = AMMODE_CLOSED;
	g_Vars.currentplayer->joybutinhibit = 0xffffffff;
	g_PlayersWithControl[g_Vars.currentplayernum] = 1;
}

bool amIsCramped(void)
{
	return (g_AmMenus[g_AmIndex].screenindex == 0 && PLAYERCOUNT() >= 3)
		|| (IS4MB() && PLAYERCOUNT() == 2)
		|| (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL);
}

void amCalculateSlotPosition(s16 column, s16 row, s16 *x, s16 *y)
{
	s32 playercount = PLAYERCOUNT();

	*x = g_AmMenus[g_AmIndex].xradius * (column - 1);
	*y = row * 50 - 50;

	if (column != 1 && row != 1) {
		*x = *x / 2;
		*y = *y / 2;
	}

	if (amIsCramped()) {
		s32 offset = 1;

		if (row == 1) {
			offset = 3;
		}

		if (column == 0) {
			*x = -(g_AmMenus[g_AmIndex].slotwidth / 2) - offset;
		} else if (column == 2) {
			*x = g_AmMenus[g_AmIndex].slotwidth / 2 + offset;
		}
	} else {
		if (playercount >= 2) {
			if (row == 1 && !amIsCramped()) {
				*x = (*x * 6) / 7;
			}
		} else {
			if (playercount >= 3 && row == 1 && !amIsCramped()) {
				*x = (*x * 6) / 14;
			}
		}
	}

	if (playercount >= 2) {
		*y = (*y * 3) / 5;
	} else if (playercount >= 3) {
		*y = (*y * 3) / 5;
	}

	*x += viGetViewLeft() / g_ScaleX + viGetViewWidth() / (g_ScaleX * 2);
	*y += viGetViewTop() + viGetViewHeight() / 2;

	if ((playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
			|| playercount >= 3) {
		if ((g_Vars.currentplayernum & 1) == 0) {
			*x += 8;
		} else {
			*x -= 8;
		}
	}
}

Gfx *amRenderText(Gfx *gdl, char *text, u32 colour, s16 left, s16 top)
{
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;

	textMeasure(&textheight, &textwidth, text, g_AmFont1, g_AmFont2, 0);

	x = left - (textwidth / 2);
	y = top - 4;
	gdl = textRenderProjected(gdl, &x, &y, text, g_AmFont1, g_AmFont2, colour, 320, 240, 0, 0);

	return gdl;
}

Gfx *amRenderAibotInfo(Gfx *gdl, s32 buddynum)
{
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 weaponnum;
	char *weaponname;
	char *aibotname;
	s32 offset = 0;
	bool wide = false;

	if (PLAYERCOUNT() == 1 && optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
		wide = true;
	}

	if ((PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
			|| PLAYERCOUNT() >= 3) {
		if ((g_Vars.currentplayernum % 2) == 0) {
			offset = 8;
		} else {
			offset = -8;
		}
	}

	if (!g_AmMenus[g_AmIndex].allbots) {
		buddynum = g_Vars.currentplayer->aibuddynums[buddynum];
		aibotname = var800ac500[buddynum]->name;

		if (g_MpPlayerChrs[buddynum]->aibot) {
			weaponnum = g_MpPlayerChrs[buddynum]->aibot->weaponnum;
		} else {
			weaponnum = 0;
		}

		if (weaponnum < WEAPON_FALCON2 || weaponnum > WEAPON_HORIZONSCANNER) {
			weaponname = langGet(L_MISC(173)); // "No Weapon"
		} else {
			weaponname = weaponGetShortName(weaponnum);
		}

		textMeasure(&textheight, &textwidth, aibotname, g_AmFont1, g_AmFont2, 0);

		x = viGetViewLeft() / g_ScaleX
			+ (s32)(viGetViewWidth() / g_ScaleX * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (PLAYERCOUNT() >= 2) {
			y = viGetViewTop() + 5;
		} else {
			y = viGetViewTop() + 10;
		}

		if (wide) {
			x = viGetViewLeft() / g_ScaleX + 32;
		}

		gdl = textRender(gdl, &x, &y, aibotname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);

		y += (PLAYERCOUNT() >= 2) ? 0 : (s32)(textheight * 1.1f);
		textMeasure(&textheight, &textwidth, weaponname, g_AmFont1, g_AmFont2, 0);

		x = viGetViewLeft() / g_ScaleX
			+ (s32)(viGetViewWidth() / g_ScaleX * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (wide) {
			x = viGetViewLeft() / g_ScaleX + 32;
		}

		gdl = textRender(gdl, &x, &y, weaponname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);

		g_Vars.currentplayer->commandingaibot = g_MpPlayerChrs[buddynum];
	} else {
		char *title = langGet(L_MISC(215)); // "All Simulants"

		textMeasure(&textheight, &textwidth, title, g_AmFont1, g_AmFont2, 0);

		x = viGetViewLeft() / g_ScaleX
			+ (s32)(viGetViewWidth() / g_ScaleX * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (PLAYERCOUNT() >= 2) {
			y = viGetViewTop() + 5;
		} else {
			y = viGetViewTop() + 10;
		}

		if (wide) {
			x = viGetViewLeft() / g_ScaleX + 32;
		}

		gdl = textRender(gdl, &x, &y, title, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);
	}

	return gdl;
}

const char var7f1b2b34[] = "Here is where the activemenu sets favourites\n";
const char var7f1b2b64[] = "slot %d = guntype %d\n";
const char var7f1b2b7c[] = "put it in %d\n";
const char var7f1b2b8c[] = "activemenu: setting up for multiplayer\n";
const char var7f1b2bb4[] = "activemenu: setting up for single player\n";
const char var7f1b2be0[] = "Put guntype %d in slot %d\n";
const char var7f1b2bfc[] = "ActiveMenu: Two or more equipped items of guntype %d\n";
const char var7f1b2c34[] = "FAV: Added gun %d to slot %d\n";

u8 var800719a0[][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };

Gfx *amRenderSlot(Gfx *gdl, char *text, s16 x, s16 y, s32 mode, s32 flags)
{
	static u32 obcol = 0xff00004f; // outer border
	static u32 ibcol = 0x3f00008f; // inner background
	static u32 defcol = 0xff4f00ff; // text
	static u32 favcol = 0xffff7fff; // unused
	static u32 pickcol = 0xff4f00ff; // unused
	static u32 pickcol2 = 0xff4f00ff; // unused

	u32 colour;
	s32 paddingtop = 6;
	s32 paddingbottom = 6;

	if (PLAYERCOUNT() >= 2) {
		paddingtop = 5;
		paddingbottom = 3;
	}

	if (text == NULL || strcmp(text, "") == 0) {
		return gdl;
	}

	func0000db30("obcol", &obcol);
	func0000db30("ibcol", &ibcol);
	func0000db30("defcol", &defcol);
	func0000db30("favcol", &favcol);
	func0000db30("pickcol", &pickcol);
	func0000db30("pickcol2", &pickcol2);

	// Render background colour
	colour = (u32)(g_AmMenus[g_AmIndex].alphafrac * (ibcol & 0xff)) | (ibcol & 0xffffff00);

	if (mode == AMSLOTMODE_FOCUSED) {
		colour &= 0x000000ff;
	}

	if (mode == AMSLOTMODE_CURRENT || (flags & AMSLOTFLAG_CURRENT)) {
		colour &= 0x000000ff;
	}

	if (flags & AMSLOTFLAG_NOAMMO) {
		colour &= 0x000000ff;
	}

	if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		colour = 0x0000006f;
	}

	gdl = gfxSetPrimColour(gdl, colour);

	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y - paddingtop + 1,
			x + g_AmMenus[g_AmIndex].slotwidth / 2,
			y + paddingbottom);

	gdl = func0f153838(gdl);

	// Render borders
	colour = obcol;

	if (flags & AMSLOTFLAG_NOAMMO) {
		colour &= 0x000000ff;
	}

	if (mode == AMSLOTMODE_CURRENT || (flags & AMSLOTFLAG_CURRENT)) {
		colour = 0xffffff8f;
	}

	colour = (u32)(g_AmMenus[g_AmIndex].alphafrac * (colour & 0xff)) | (colour & 0xffffff00);

	if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		colour = 0x4f4f4f7f;
	}

	gdl = gfxSetPrimColour(gdl, colour);

	// Top border
	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2,
			y - paddingtop,
			x + g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y - paddingtop + 1);

	// Bottom border
	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2,
			y + paddingbottom,
			x + g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y + paddingbottom + 1);

	// Left border
	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2,
			y - paddingtop + 1,
			x - g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y + paddingbottom);

	// Right border
	gDPFillRectangleScaled(gdl++,
			x + g_AmMenus[g_AmIndex].slotwidth / 2,
			y - paddingtop + 1,
			x + g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y + paddingbottom);

	gdl = func0f153838(gdl);

	// Render text
	colour = defcol;

	if (mode == AMSLOTMODE_CURRENT || (flags & AMSLOTFLAG_CURRENT)) {
		colour = 0xffffffff;
	}

	if (flags & AMSLOTFLAG_ACTIVE) {
		colour = colourBlend(0xffaf8fff, colour, func0f006b54(10) * 255.0f);
	}

	colour = (u32)(g_AmMenus[g_AmIndex].alphafrac * (colour & 0xff)) | (colour & 0xffffff00);

	if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		colour = 0x4f4f4f7f;
	}

	gdl = amRenderText(gdl, text, colour, x, y);

	return gdl;
}

GLOBAL_ASM(
glabel amRender
/*  f100ad0:	27bdfe28 */ 	addiu	$sp,$sp,-472
/*  f100ad4:	3c0e8007 */ 	lui	$t6,%hi(g_ViMode)
/*  f100ad8:	8dce06c8 */ 	lw	$t6,%lo(g_ViMode)($t6)
/*  f100adc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f100ae0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f100ae4:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f100ae8:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f100aec:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f100af0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f100af4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f100af8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f100afc:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f100b00:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f100b04:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f100b08:	15c10005 */ 	bne	$t6,$at,.L0f100b20
/*  f100b0c:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f100b10:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f100b14:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f100b18:	10000004 */ 	b	.L0f100b2c
/*  f100b1c:	ac2ffac0 */ 	sw	$t7,%lo(g_ScaleX)($at)
.L0f100b20:
/*  f100b20:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f100b24:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f100b28:	ac38fac0 */ 	sw	$t8,%lo(g_ScaleX)($at)
.L0f100b2c:
/*  f100b2c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f100b30:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f100b34:	8d79028c */ 	lw	$t9,0x28c($t3)
/*  f100b38:	3c01800a */ 	lui	$at,%hi(g_AmIndex)
/*  f100b3c:	ac3921b8 */ 	sw	$t9,%lo(g_AmIndex)($at)
/*  f100b40:	8d6e0284 */ 	lw	$t6,0x284($t3)
/*  f100b44:	adc01c04 */ 	sw	$zero,0x1c04($t6)
/*  f100b48:	8d630284 */ 	lw	$v1,0x284($t3)
/*  f100b4c:	906f0250 */ 	lbu	$t7,0x250($v1)
/*  f100b50:	51e00353 */ 	beqzl	$t7,.L0f1018a0
/*  f100b54:	8c621c04 */ 	lw	$v0,0x1c04($v1)
/*  f100b58:	0fc54d8a */ 	jal	func0f153628
/*  f100b5c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f100b60:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f100b64:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f100b68:	8d180318 */ 	lw	$t8,0x318($t0)
/*  f100b6c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f100b70:	13000010 */ 	beqz	$t8,.L0f100bb4
/*  f100b74:	3c19800a */ 	lui	$t9,%hi(g_AmIndex)
/*  f100b78:	8f3921b8 */ 	lw	$t9,%lo(g_AmIndex)($t9)
/*  f100b7c:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f100b80:	3c17800a */ 	lui	$s7,%hi(g_AmMenus)
/*  f100b84:	033e0019 */ 	multu	$t9,$s8
/*  f100b88:	26f720d0 */ 	addiu	$s7,$s7,%lo(g_AmMenus)
/*  f100b8c:	00007012 */ 	mflo	$t6
/*  f100b90:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f100b94:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f100b98:	28410002 */ 	slti	$at,$v0,0x2
/*  f100b9c:	14200005 */ 	bnez	$at,.L0f100bb4
/*  f100ba0:	00000000 */ 	nop
/*  f100ba4:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f100ba8:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f100bac:	932e1be5 */ 	lbu	$t6,0x1be5($t9)
/*  f100bb0:	afae01c4 */ 	sw	$t6,0x1c4($sp)
.L0f100bb4:
/*  f100bb4:	3c0f800a */ 	lui	$t7,%hi(g_AmIndex)
/*  f100bb8:	8def21b8 */ 	lw	$t7,%lo(g_AmIndex)($t7)
/*  f100bbc:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f100bc0:	3c17800a */ 	lui	$s7,%hi(g_AmMenus)
/*  f100bc4:	01fe0019 */ 	multu	$t7,$s8
/*  f100bc8:	26f720d0 */ 	addiu	$s7,$s7,%lo(g_AmMenus)
/*  f100bcc:	2401ff85 */ 	addiu	$at,$zero,-123
/*  f100bd0:	0000c012 */ 	mflo	$t8
/*  f100bd4:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f100bd8:	8619000a */ 	lh	$t9,0xa($s0)
/*  f100bdc:	57210021 */ 	bnel	$t9,$at,.L0f100c64
/*  f100be0:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f100be4:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f100be8:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f100bec:	26060006 */ 	addiu	$a2,$s0,0x6
/*  f100bf0:	0043001a */ 	div	$zero,$v0,$v1
/*  f100bf4:	00002010 */ 	mfhi	$a0
/*  f100bf8:	00002812 */ 	mflo	$a1
/*  f100bfc:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f100c00:	00047400 */ 	sll	$t6,$a0,0x10
/*  f100c04:	14600002 */ 	bnez	$v1,.L0f100c10
/*  f100c08:	00000000 */ 	nop
/*  f100c0c:	0007000d */ 	break	0x7
.L0f100c10:
/*  f100c10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f100c14:	14610004 */ 	bne	$v1,$at,.L0f100c28
/*  f100c18:	3c018000 */ 	lui	$at,0x8000
/*  f100c1c:	14410002 */ 	bne	$v0,$at,.L0f100c28
/*  f100c20:	00000000 */ 	nop
/*  f100c24:	0006000d */ 	break	0x6
.L0f100c28:
/*  f100c28:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f100c2c:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f100c30:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f100c34:	26070008 */ 	addiu	$a3,$s0,0x8
/*  f100c38:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f100c3c:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f100c40:	01de0019 */ 	multu	$t6,$s8
/*  f100c44:	00007812 */ 	mflo	$t7
/*  f100c48:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f100c4c:	86180006 */ 	lh	$t8,0x6($s0)
/*  f100c50:	86190008 */ 	lh	$t9,0x8($s0)
/*  f100c54:	a618000a */ 	sh	$t8,0xa($s0)
/*  f100c58:	1000000d */ 	b	.L0f100c90
/*  f100c5c:	a619000c */ 	sh	$t9,0xc($s0)
/*  f100c60:	9202000e */ 	lbu	$v0,0xe($s0)
.L0f100c64:
/*  f100c64:	24010003 */ 	addiu	$at,$zero,0x3
/*  f100c68:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f100c6c:	0041001a */ 	div	$zero,$v0,$at
/*  f100c70:	00002010 */ 	mfhi	$a0
/*  f100c74:	00002812 */ 	mflo	$a1
/*  f100c78:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f100c7c:	00047400 */ 	sll	$t6,$a0,0x10
/*  f100c80:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f100c84:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f100c88:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f100c8c:	2607000c */ 	addiu	$a3,$s0,0xc
.L0f100c90:
/*  f100c90:	0fc351e7 */ 	jal	func0f0d479c
/*  f100c94:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f100c98:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f100c9c:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f100ca0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f100ca4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f100ca8:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f100cac:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f100cb0:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f100cb4:	3c18e700 */ 	lui	$t8,0xe700
/*  f100cb8:	00408025 */ 	or	$s0,$v0,$zero
/*  f100cbc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f100cc0:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f100cc4:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f100cc8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f100ccc:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f100cd0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f100cd4:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f100cd8:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f100cdc:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f100ce0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f100ce4:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f100ce8:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f100cec:	3c0eb900 */ 	lui	$t6,0xb900
/*  f100cf0:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f100cf4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f100cf8:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f100cfc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f100d00:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f100d04:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100d08:	3c19ba00 */ 	lui	$t9,0xba00
/*  f100d0c:	37390402 */ 	ori	$t9,$t9,0x402
/*  f100d10:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100d14:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100d18:	240e0020 */ 	addiu	$t6,$zero,0x20
/*  f100d1c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100d20:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100d24:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100d28:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f100d2c:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f100d30:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100d34:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100d38:	240ef9fc */ 	addiu	$t6,$zero,-1540
/*  f100d3c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100d40:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100d44:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100d48:	3c19b600 */ 	lui	$t9,0xb600
/*  f100d4c:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f100d50:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100d54:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100d58:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100d5c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100d60:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f100d64:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f100d68:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f100d6c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f100d70:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f100d74:	27a401d8 */ 	addiu	$a0,$sp,0x1d8
/*  f100d78:	00002825 */ 	or	$a1,$zero,$zero
/*  f100d7c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f100d80:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f100d84:	00003825 */ 	or	$a3,$zero,$zero
/*  f100d88:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f100d8c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f100d90:	3c180050 */ 	lui	$t8,0x50
/*  f100d94:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f100d98:	27b301ba */ 	addiu	$s3,$sp,0x1ba
/*  f100d9c:	27b401b8 */ 	addiu	$s4,$sp,0x1b8
/*  f100da0:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f100da4:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f100da8:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f100dac:	02803825 */ 	or	$a3,$s4,$zero
/*  f100db0:	02603025 */ 	or	$a2,$s3,$zero
/*  f100db4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f100db8:	00002825 */ 	or	$a1,$zero,$zero
/*  f100dbc:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f100dc0:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f100dc4:	af380004 */ 	sw	$t8,0x4($t9)
/*  f100dc8:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100dcc:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f100dd0:	2412fff6 */ 	addiu	$s2,$zero,-10
/*  f100dd4:	03310019 */ 	multu	$t9,$s1
/*  f100dd8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f100ddc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f100de0:	02603025 */ 	or	$a2,$s3,$zero
/*  f100de4:	02803825 */ 	or	$a3,$s4,$zero
/*  f100de8:	00007012 */ 	mflo	$t6
/*  f100dec:	a60e0000 */ 	sh	$t6,0x0($s0)
/*  f100df0:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100df4:	a6120004 */ 	sh	$s2,0x4($s0)
/*  f100df8:	01f10019 */ 	multu	$t7,$s1
/*  f100dfc:	0000c012 */ 	mflo	$t8
/*  f100e00:	a6180002 */ 	sh	$t8,0x2($s0)
/*  f100e04:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f100e08:	00000000 */ 	nop
/*  f100e0c:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100e10:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f100e14:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f100e18:	03310019 */ 	multu	$t9,$s1
/*  f100e1c:	02603025 */ 	or	$a2,$s3,$zero
/*  f100e20:	02803825 */ 	or	$a3,$s4,$zero
/*  f100e24:	00007012 */ 	mflo	$t6
/*  f100e28:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f100e2c:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100e30:	a6120010 */ 	sh	$s2,0x10($s0)
/*  f100e34:	01f10019 */ 	multu	$t7,$s1
/*  f100e38:	0000c012 */ 	mflo	$t8
/*  f100e3c:	a618000e */ 	sh	$t8,0xe($s0)
/*  f100e40:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f100e44:	00000000 */ 	nop
/*  f100e48:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100e4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f100e50:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f100e54:	03310019 */ 	multu	$t9,$s1
/*  f100e58:	02603025 */ 	or	$a2,$s3,$zero
/*  f100e5c:	02803825 */ 	or	$a3,$s4,$zero
/*  f100e60:	00007012 */ 	mflo	$t6
/*  f100e64:	a60e0018 */ 	sh	$t6,0x18($s0)
/*  f100e68:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100e6c:	a612001c */ 	sh	$s2,0x1c($s0)
/*  f100e70:	01f10019 */ 	multu	$t7,$s1
/*  f100e74:	0000c012 */ 	mflo	$t8
/*  f100e78:	a618001a */ 	sh	$t8,0x1a($s0)
/*  f100e7c:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f100e80:	00000000 */ 	nop
/*  f100e84:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100e88:	8602000c */ 	lh	$v0,0xc($s0)
/*  f100e8c:	8607001a */ 	lh	$a3,0x1a($s0)
/*  f100e90:	03310019 */ 	multu	$t9,$s1
/*  f100e94:	86030002 */ 	lh	$v1,0x2($s0)
/*  f100e98:	00e33023 */ 	subu	$a2,$a3,$v1
/*  f100e9c:	00007012 */ 	mflo	$t6
/*  f100ea0:	a60e0024 */ 	sh	$t6,0x24($s0)
/*  f100ea4:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100ea8:	86050024 */ 	lh	$a1,0x24($s0)
/*  f100eac:	a6120028 */ 	sh	$s2,0x28($s0)
/*  f100eb0:	01f10019 */ 	multu	$t7,$s1
/*  f100eb4:	00452023 */ 	subu	$a0,$v0,$a1
/*  f100eb8:	a6120034 */ 	sh	$s2,0x34($s0)
/*  f100ebc:	a6120040 */ 	sh	$s2,0x40($s0)
/*  f100ec0:	a612004c */ 	sh	$s2,0x4c($s0)
/*  f100ec4:	a6120058 */ 	sh	$s2,0x58($s0)
/*  f100ec8:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f100ecc:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f100ed0:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f100ed4:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f100ed8:	0000c012 */ 	mflo	$t8
/*  f100edc:	a6180026 */ 	sh	$t8,0x26($s0)
/*  f100ee0:	04810003 */ 	bgez	$a0,.L0f100ef0
/*  f100ee4:	0004c8c3 */ 	sra	$t9,$a0,0x3
/*  f100ee8:	24810007 */ 	addiu	$at,$a0,0x7
/*  f100eec:	0001c8c3 */ 	sra	$t9,$at,0x3
.L0f100ef0:
/*  f100ef0:	00197400 */ 	sll	$t6,$t9,0x10
/*  f100ef4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f100ef8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f100efc:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f100f00:	860e000e */ 	lh	$t6,0xe($s0)
/*  f100f04:	04c10003 */ 	bgez	$a2,.L0f100f14
/*  f100f08:	0006c0c3 */ 	sra	$t8,$a2,0x3
/*  f100f0c:	24c10007 */ 	addiu	$at,$a2,0x7
/*  f100f10:	0001c0c3 */ 	sra	$t8,$at,0x3
.L0f100f14:
/*  f100f14:	03003025 */ 	or	$a2,$t8,$zero
/*  f100f18:	0044c823 */ 	subu	$t9,$v0,$a0
/*  f100f1c:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f100f20:	860f0018 */ 	lh	$t7,0x18($s0)
/*  f100f24:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f100f28:	0066c021 */ 	addu	$t8,$v1,$a2
/*  f100f2c:	a60e003e */ 	sh	$t6,0x3e($s0)
/*  f100f30:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f100f34:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f100f38:	a619003c */ 	sh	$t9,0x3c($s0)
/*  f100f3c:	00e6c023 */ 	subu	$t8,$a3,$a2
/*  f100f40:	a618004a */ 	sh	$t8,0x4a($s0)
/*  f100f44:	00a4c821 */ 	addu	$t9,$a1,$a0
/*  f100f48:	a60f0048 */ 	sh	$t7,0x48($s0)
/*  f100f4c:	a6190054 */ 	sh	$t9,0x54($s0)
/*  f100f50:	a2020037 */ 	sb	$v0,0x37($s0)
/*  f100f54:	a2020043 */ 	sb	$v0,0x43($s0)
/*  f100f58:	a202004f */ 	sb	$v0,0x4f($s0)
/*  f100f5c:	a202005b */ 	sb	$v0,0x5b($s0)
/*  f100f60:	3c0f2222 */ 	lui	$t7,0x2222
/*  f100f64:	a60e0056 */ 	sh	$t6,0x56($s0)
/*  f100f68:	35ef2200 */ 	ori	$t7,$t7,0x2200
/*  f100f6c:	2418004f */ 	addiu	$t8,$zero,0x4f
/*  f100f70:	aeaf0000 */ 	sw	$t7,0x0($s5)
/*  f100f74:	aeb80004 */ 	sw	$t8,0x4($s5)
/*  f100f78:	8fb101d8 */ 	lw	$s1,0x1d8($sp)
/*  f100f7c:	3c0f0704 */ 	lui	$t7,0x704
/*  f100f80:	35ef0008 */ 	ori	$t7,$t7,0x8
/*  f100f84:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f100f88:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f100f8c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f100f90:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f100f94:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f100f98:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f100f9c:	8fb201d8 */ 	lw	$s2,0x1d8($sp)
/*  f100fa0:	3c0e0470 */ 	lui	$t6,0x470
/*  f100fa4:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f100fa8:	26590008 */ 	addiu	$t9,$s2,0x8
/*  f100fac:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f100fb0:	02002025 */ 	or	$a0,$s0,$zero
/*  f100fb4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f100fb8:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f100fbc:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f100fc0:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100fc4:	3c19b100 */ 	lui	$t9,0xb100
/*  f100fc8:	37390046 */ 	ori	$t9,$t9,0x46
/*  f100fcc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100fd0:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100fd4:	240e7654 */ 	addiu	$t6,$zero,0x7654
/*  f100fd8:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100fdc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100fe0:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100fe4:	3c19b100 */ 	lui	$t9,0xb100
/*  f100fe8:	3c0e4510 */ 	lui	$t6,0x4510
/*  f100fec:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100ff0:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100ff4:	35ce3740 */ 	ori	$t6,$t6,0x3740
/*  f100ff8:	37390507 */ 	ori	$t9,$t9,0x507
/*  f100ffc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101000:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101004:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f101008:	3c0e7326 */ 	lui	$t6,0x7326
/*  f10100c:	3c19b100 */ 	lui	$t9,0xb100
/*  f101010:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f101014:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101018:	37396316 */ 	ori	$t9,$t9,0x6316
/*  f10101c:	35ce5621 */ 	ori	$t6,$t6,0x5621
/*  f101020:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101024:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101028:	0fc35272 */ 	jal	func0f0d49c8
/*  f10102c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101030:	3c168007 */ 	lui	$s6,%hi(var800719a0)
/*  f101034:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f101038:	26d619a0 */ 	addiu	$s6,$s6,%lo(var800719a0)
/*  f10103c:	00009825 */ 	or	$s3,$zero,$zero
/*  f101040:	27b5015c */ 	addiu	$s5,$sp,0x15c
/*  f101044:	00008825 */ 	or	$s1,$zero,$zero
.L0f101048:
/*  f101048:	00132400 */ 	sll	$a0,$s3,0x10
.L0f10104c:
/*  f10104c:	00112c00 */ 	sll	$a1,$s1,0x10
/*  f101050:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f101054:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f101058:	00008025 */ 	or	$s0,$zero,$zero
/*  f10105c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f101060:	03002825 */ 	or	$a1,$t8,$zero
/*  f101064:	27a60182 */ 	addiu	$a2,$sp,0x182
/*  f101068:	27a70180 */ 	addiu	$a3,$sp,0x180
/*  f10106c:	0fc3fc9d */ 	jal	amCalculateSlotPosition
/*  f101070:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f101074:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f101078:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f10107c:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f101080:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f101084:	01de0019 */ 	multu	$t6,$s8
/*  f101088:	02799021 */ 	addu	$s2,$s3,$t9
/*  f10108c:	afa001d0 */ 	sw	$zero,0x1d0($sp)
/*  f101090:	3c0e800a */ 	lui	$t6,%hi(g_MissionConfig+0x3)
/*  f101094:	00007812 */ 	mflo	$t7
/*  f101098:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f10109c:	9319000e */ 	lbu	$t9,0xe($t8)
/*  f1010a0:	16590002 */ 	bne	$s2,$t9,.L0f1010ac
/*  f1010a4:	00000000 */ 	nop
/*  f1010a8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f1010ac:
/*  f1010ac:	81cfdfeb */ 	lb	$t7,%lo(g_MissionConfig+0x3)($t6)
/*  f1010b0:	05e10029 */ 	bgez	$t7,.L0f101158
/*  f1010b4:	00000000 */ 	nop
/*  f1010b8:	0fc3f7a3 */ 	jal	amGetFirstBuddyIndex
/*  f1010bc:	00000000 */ 	nop
/*  f1010c0:	04400025 */ 	bltz	$v0,.L0f101158
/*  f1010c4:	00000000 */ 	nop
/*  f1010c8:	16000042 */ 	bnez	$s0,.L0f1011d4
/*  f1010cc:	3c18800a */ 	lui	$t8,%hi(g_AmIndex)
/*  f1010d0:	8f1821b8 */ 	lw	$t8,%lo(g_AmIndex)($t8)
/*  f1010d4:	031e0019 */ 	multu	$t8,$s8
/*  f1010d8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1010dc:	0000c812 */ 	mflo	$t9
/*  f1010e0:	02f97021 */ 	addu	$t6,$s7,$t9
/*  f1010e4:	81cf0000 */ 	lb	$t7,0x0($t6)
/*  f1010e8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x4b8)
/*  f1010ec:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1010f0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f1010f4:	14200037 */ 	bnez	$at,.L0f1011d4
/*  f1010f8:	00117080 */ 	sll	$t6,$s1,0x2
/*  f1010fc:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f101100:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f101104:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f101108:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f10110c:	8f39a478 */ 	lw	$t9,%lo(g_Vars+0x4b8)($t9)
/*  f101110:	24010007 */ 	addiu	$at,$zero,0x7
/*  f101114:	14810007 */ 	bne	$a0,$at,.L0f101134
/*  f101118:	8f230004 */ 	lw	$v1,0x4($t9)
/*  f10111c:	8c790014 */ 	lw	$t9,0x14($v1)
/*  f101120:	332e0400 */ 	andi	$t6,$t9,0x400
/*  f101124:	11c0002b */ 	beqz	$t6,.L0f1011d4
/*  f101128:	00000000 */ 	nop
/*  f10112c:	10000029 */ 	b	.L0f1011d4
/*  f101130:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f101134:
/*  f101134:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101138:	14810026 */ 	bne	$a0,$at,.L0f1011d4
/*  f10113c:	00000000 */ 	nop
/*  f101140:	8c6f0014 */ 	lw	$t7,0x14($v1)
/*  f101144:	31f80400 */ 	andi	$t8,$t7,0x400
/*  f101148:	17000022 */ 	bnez	$t8,.L0f1011d4
/*  f10114c:	00000000 */ 	nop
/*  f101150:	10000020 */ 	b	.L0f1011d4
/*  f101154:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f101158:
/*  f101158:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x318)
/*  f10115c:	8f39a2d8 */ 	lw	$t9,%lo(g_Vars+0x318)($t9)
/*  f101160:	1320001c */ 	beqz	$t9,.L0f1011d4
/*  f101164:	00000000 */ 	nop
/*  f101168:	1600001a */ 	bnez	$s0,.L0f1011d4
/*  f10116c:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f101170:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f101174:	01de0019 */ 	multu	$t6,$s8
/*  f101178:	00117080 */ 	sll	$t6,$s1,0x2
/*  f10117c:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f101180:	00007812 */ 	mflo	$t7
/*  f101184:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f101188:	83190000 */ 	lb	$t9,0x0($t8)
/*  f10118c:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f101190:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f101194:	2b210002 */ 	slti	$at,$t9,0x2
/*  f101198:	1420000e */ 	bnez	$at,.L0f1011d4
/*  f10119c:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f1011a0:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f1011a4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayerChrs)
/*  f1011a8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1011ac:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1011b0:	8f18c4d0 */ 	lw	$t8,%lo(g_MpPlayerChrs)($t8)
/*  f1011b4:	3c02800b */ 	lui	$v0,%hi(g_AmBotCommands)
/*  f1011b8:	00591021 */ 	addu	$v0,$v0,$t9
/*  f1011bc:	8f1902d4 */ 	lw	$t9,0x2d4($t8)
/*  f1011c0:	9042cb78 */ 	lbu	$v0,%lo(g_AmBotCommands)($v0)
/*  f1011c4:	93230079 */ 	lbu	$v1,0x79($t9)
/*  f1011c8:	14430002 */ 	bne	$v0,$v1,.L0f1011d4
/*  f1011cc:	00000000 */ 	nop
/*  f1011d0:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f1011d4:
/*  f1011d4:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f1011d8:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f1011dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1011e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1011e4:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f1011e8:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f1011ec:	15e10003 */ 	bne	$t7,$at,.L0f1011fc
/*  f1011f0:	00000000 */ 	nop
/*  f1011f4:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f1011f8:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.L0f1011fc:
/*  f1011fc:	0fc3f8a0 */ 	jal	amGetSlotDetails
/*  f101200:	02a03025 */ 	or	$a2,$s5,$zero
/*  f101204:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f101208:	1662000f */ 	bne	$s3,$v0,.L0f101248
/*  f10120c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101210:	5622000e */ 	bnel	$s1,$v0,.L0f10124c
/*  f101214:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
/*  f101218:	0fc3fc2f */ 	jal	amIsCramped
/*  f10121c:	00000000 */ 	nop
/*  f101220:	14400011 */ 	bnez	$v0,.L0f101268
/*  f101224:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101228:	87b80180 */ 	lh	$t8,0x180($sp)
/*  f10122c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f101230:	02803025 */ 	or	$a2,$s4,$zero
/*  f101234:	87a70182 */ 	lh	$a3,0x182($sp)
/*  f101238:	0fc3fdbd */ 	jal	amRenderText
/*  f10123c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f101240:	10000009 */ 	b	.L0f101268
/*  f101244:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101248:
/*  f101248:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
.L0f10124c:
/*  f10124c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f101250:	87a60182 */ 	lh	$a2,0x182($sp)
/*  f101254:	87a70180 */ 	lh	$a3,0x180($sp)
/*  f101258:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f10125c:	0fc4004a */ 	jal	amRenderSlot
/*  f101260:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f101264:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101268:
/*  f101268:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f10126c:	00117400 */ 	sll	$t6,$s1,0x10
/*  f101270:	000e8c03 */ 	sra	$s1,$t6,0x10
/*  f101274:	2a210003 */ 	slti	$at,$s1,0x3
/*  f101278:	5420ff74 */ 	bnezl	$at,.L0f10104c
/*  f10127c:	00132400 */ 	sll	$a0,$s3,0x10
/*  f101280:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f101284:	0013c400 */ 	sll	$t8,$s3,0x10
/*  f101288:	00189c03 */ 	sra	$s3,$t8,0x10
/*  f10128c:	2a610003 */ 	slti	$at,$s3,0x3
/*  f101290:	5420ff6d */ 	bnezl	$at,.L0f101048
/*  f101294:	00008825 */ 	or	$s1,$zero,$zero
/*  f101298:	3c0e800a */ 	lui	$t6,%hi(g_MissionConfig+0x3)
/*  f10129c:	81cfdfeb */ 	lb	$t7,%lo(g_MissionConfig+0x3)($t6)
/*  f1012a0:	05e10004 */ 	bgez	$t7,.L0f1012b4
/*  f1012a4:	00000000 */ 	nop
/*  f1012a8:	0fc3f7a3 */ 	jal	amGetFirstBuddyIndex
/*  f1012ac:	00000000 */ 	nop
/*  f1012b0:	04410011 */ 	bgez	$v0,.L0f1012f8
.L0f1012b4:
/*  f1012b4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x318)
/*  f1012b8:	8f18a2d8 */ 	lw	$t8,%lo(g_Vars+0x318)($t8)
/*  f1012bc:	3c19800a */ 	lui	$t9,%hi(g_AmIndex)
/*  f1012c0:	1300000d */ 	beqz	$t8,.L0f1012f8
/*  f1012c4:	00000000 */ 	nop
/*  f1012c8:	8f3921b8 */ 	lw	$t9,%lo(g_AmIndex)($t9)
/*  f1012cc:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f1012d0:	033e0019 */ 	multu	$t9,$s8
/*  f1012d4:	00007012 */ 	mflo	$t6
/*  f1012d8:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f1012dc:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f1012e0:	28410002 */ 	slti	$at,$v0,0x2
/*  f1012e4:	14200004 */ 	bnez	$at,.L0f1012f8
/*  f1012e8:	00000000 */ 	nop
/*  f1012ec:	0fc3fdef */ 	jal	amRenderAibotInfo
/*  f1012f0:	2445fffe */ 	addiu	$a1,$v0,-2
/*  f1012f4:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f1012f8:
/*  f1012f8:	3c18800a */ 	lui	$t8,%hi(g_AmIndex)
/*  f1012fc:	8f1821b8 */ 	lw	$t8,%lo(g_AmIndex)($t8)
/*  f101300:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f101304:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f101308:	031e0019 */ 	multu	$t8,$s8
/*  f10130c:	0000c812 */ 	mflo	$t9
/*  f101310:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f101314:	820e0000 */ 	lb	$t6,0x0($s0)
/*  f101318:	29c10002 */ 	slti	$at,$t6,0x2
/*  f10131c:	14200005 */ 	bnez	$at,.L0f101334
/*  f101320:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101324:	16610003 */ 	bne	$s3,$at,.L0f101334
/*  f101328:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10132c:	12210154 */ 	beq	$s1,$at,.L0f101880
/*  f101330:	00000000 */ 	nop
.L0f101334:
/*  f101334:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f101338:	24120006 */ 	addiu	$s2,$zero,0x6
/*  f10133c:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f101340:	51e00004 */ 	beqzl	$t7,.L0f101354
/*  f101344:	00003025 */ 	or	$a2,$zero,$zero
/*  f101348:	10000002 */ 	b	.L0f101354
/*  f10134c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101350:	00003025 */ 	or	$a2,$zero,$zero
.L0f101354:
/*  f101354:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f101358:	00002825 */ 	or	$a1,$zero,$zero
/*  f10135c:	13000003 */ 	beqz	$t8,.L0f10136c
/*  f101360:	00000000 */ 	nop
/*  f101364:	10000001 */ 	b	.L0f10136c
/*  f101368:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10136c:
/*  f10136c:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f101370:	00002025 */ 	or	$a0,$zero,$zero
/*  f101374:	13200003 */ 	beqz	$t9,.L0f101384
/*  f101378:	00000000 */ 	nop
/*  f10137c:	10000001 */ 	b	.L0f101384
/*  f101380:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101384:
/*  f101384:	8c4e0070 */ 	lw	$t6,0x70($v0)
/*  f101388:	00001825 */ 	or	$v1,$zero,$zero
/*  f10138c:	11c00003 */ 	beqz	$t6,.L0f10139c
/*  f101390:	00000000 */ 	nop
/*  f101394:	10000001 */ 	b	.L0f10139c
/*  f101398:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10139c:
/*  f10139c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f1013a0:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1013a4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f1013a8:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1013ac:	14200003 */ 	bnez	$at,.L0f1013bc
/*  f1013b0:	00000000 */ 	nop
/*  f1013b4:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f1013b8:	24130003 */ 	addiu	$s3,$zero,0x3
.L0f1013bc:
/*  f1013bc:	0c0068f7 */ 	jal	sinf
/*  f1013c0:	c60c001c */ 	lwc1	$f12,0x1c($s0)
/*  f1013c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1013c8:	44812000 */ 	mtc1	$at,$f4
/*  f1013cc:	3c0142fe */ 	lui	$at,0x42fe
/*  f1013d0:	44814000 */ 	mtc1	$at,$f8
/*  f1013d4:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f1013d8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1013dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f1013e0:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f1013e4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f1013e8:	444ef800 */ 	cfc1	$t6,$31
/*  f1013ec:	44c2f800 */ 	ctc1	$v0,$31
/*  f1013f0:	00000000 */ 	nop
/*  f1013f4:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f1013f8:	4442f800 */ 	cfc1	$v0,$31
/*  f1013fc:	00000000 */ 	nop
/*  f101400:	30420078 */ 	andi	$v0,$v0,0x78
/*  f101404:	50400013 */ 	beqzl	$v0,.L0f101454
/*  f101408:	44028000 */ 	mfc1	$v0,$f16
/*  f10140c:	44818000 */ 	mtc1	$at,$f16
/*  f101410:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f101414:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f101418:	44c2f800 */ 	ctc1	$v0,$31
/*  f10141c:	00000000 */ 	nop
/*  f101420:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f101424:	4442f800 */ 	cfc1	$v0,$31
/*  f101428:	00000000 */ 	nop
/*  f10142c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f101430:	14400005 */ 	bnez	$v0,.L0f101448
/*  f101434:	00000000 */ 	nop
/*  f101438:	44028000 */ 	mfc1	$v0,$f16
/*  f10143c:	3c018000 */ 	lui	$at,0x8000
/*  f101440:	10000007 */ 	b	.L0f101460
/*  f101444:	00411025 */ 	or	$v0,$v0,$at
.L0f101448:
/*  f101448:	10000005 */ 	b	.L0f101460
/*  f10144c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f101450:	44028000 */ 	mfc1	$v0,$f16
.L0f101454:
/*  f101454:	00000000 */ 	nop
/*  f101458:	0440fffb */ 	bltz	$v0,.L0f101448
/*  f10145c:	00000000 */ 	nop
.L0f101460:
/*  f101460:	44cef800 */ 	ctc1	$t6,$31
/*  f101464:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f101468:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f10146c:	3c01ff00 */ 	lui	$at,0xff00
/*  f101470:	342100ff */ 	ori	$at,$at,0xff
/*  f101474:	00027a00 */ 	sll	$t7,$v0,0x8
/*  f101478:	01e1c025 */ 	or	$t8,$t7,$at
/*  f10147c:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f101480:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f101484:	24010002 */ 	addiu	$at,$zero,0x2
/*  f101488:	15e10003 */ 	bne	$t7,$at,.L0f101498
/*  f10148c:	0319a025 */ 	or	$s4,$t8,$t9
/*  f101490:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f101494:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.L0f101498:
/*  f101498:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f10149c:	02802825 */ 	or	$a1,$s4,$zero
/*  f1014a0:	3c18800a */ 	lui	$t8,%hi(g_AmIndex)
/*  f1014a4:	8f1821b8 */ 	lw	$t8,%lo(g_AmIndex)($t8)
/*  f1014a8:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f1014ac:	031e0019 */ 	multu	$t8,$s8
/*  f1014b0:	0000c812 */ 	mflo	$t9
/*  f1014b4:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f1014b8:	86110004 */ 	lh	$s1,0x4($s0)
/*  f1014bc:	920f000e */ 	lbu	$t7,0xe($s0)
/*  f1014c0:	06210003 */ 	bgez	$s1,.L0f1014d0
/*  f1014c4:	00117043 */ 	sra	$t6,$s1,0x1
/*  f1014c8:	26210001 */ 	addiu	$at,$s1,0x1
/*  f1014cc:	00017043 */ 	sra	$t6,$at,0x1
.L0f1014d0:
/*  f1014d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1014d4:	15e1003c */ 	bne	$t7,$at,.L0f1015c8
/*  f1014d8:	01c08825 */ 	or	$s1,$t6,$zero
/*  f1014dc:	0fc3fc2f */ 	jal	amIsCramped
/*  f1014e0:	00000000 */ 	nop
/*  f1014e4:	10400005 */ 	beqz	$v0,.L0f1014fc
/*  f1014e8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x6c)
/*  f1014ec:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1014f0:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f1014f4:	10000034 */ 	b	.L0f1015c8
/*  f1014f8:	00009825 */ 	or	$s3,$zero,$zero
.L0f1014fc:
/*  f1014fc:	8f18a02c */ 	lw	$t8,%lo(g_Vars+0x6c)($t8)
/*  f101500:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x68)
/*  f101504:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x64)
/*  f101508:	13000003 */ 	beqz	$t8,.L0f101518
/*  f10150c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x70)
/*  f101510:	10000002 */ 	b	.L0f10151c
/*  f101514:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101518:
/*  f101518:	00003025 */ 	or	$a2,$zero,$zero
.L0f10151c:
/*  f10151c:	8f39a028 */ 	lw	$t9,%lo(g_Vars+0x68)($t9)
/*  f101520:	00002825 */ 	or	$a1,$zero,$zero
/*  f101524:	00002025 */ 	or	$a0,$zero,$zero
/*  f101528:	13200003 */ 	beqz	$t9,.L0f101538
/*  f10152c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101530:	10000001 */ 	b	.L0f101538
/*  f101534:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101538:
/*  f101538:	8dcea024 */ 	lw	$t6,%lo(g_Vars+0x64)($t6)
/*  f10153c:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f101540:	11c00003 */ 	beqz	$t6,.L0f101550
/*  f101544:	00000000 */ 	nop
/*  f101548:	10000001 */ 	b	.L0f101550
/*  f10154c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101550:
/*  f101550:	8defa030 */ 	lw	$t7,%lo(g_Vars+0x70)($t7)
/*  f101554:	11e00003 */ 	beqz	$t7,.L0f101564
/*  f101558:	00000000 */ 	nop
/*  f10155c:	10000001 */ 	b	.L0f101564
/*  f101560:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101564:
/*  f101564:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101568:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f10156c:	03267021 */ 	addu	$t6,$t9,$a2
/*  f101570:	29c10002 */ 	slti	$at,$t6,0x2
/*  f101574:	14200014 */ 	bnez	$at,.L0f1015c8
/*  f101578:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10157c:	27a50114 */ 	addiu	$a1,$sp,0x114
/*  f101580:	0fc3f8a0 */ 	jal	amGetSlotDetails
/*  f101584:	02003025 */ 	or	$a2,$s0,$zero
/*  f101588:	3c0f800a */ 	lui	$t7,%hi(g_AmFont2)
/*  f10158c:	8def21b4 */ 	lw	$t7,%lo(g_AmFont2)($t7)
/*  f101590:	3c07800a */ 	lui	$a3,%hi(g_AmFont1)
/*  f101594:	8ce721b0 */ 	lw	$a3,%lo(g_AmFont1)($a3)
/*  f101598:	27a4013c */ 	addiu	$a0,$sp,0x13c
/*  f10159c:	27a50138 */ 	addiu	$a1,$sp,0x138
/*  f1015a0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1015a4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1015a8:	0fc55cbe */ 	jal	textMeasure
/*  f1015ac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1015b0:	8fb10138 */ 	lw	$s1,0x138($sp)
/*  f1015b4:	06210003 */ 	bgez	$s1,.L0f1015c4
/*  f1015b8:	0011c043 */ 	sra	$t8,$s1,0x1
/*  f1015bc:	26210001 */ 	addiu	$at,$s1,0x1
/*  f1015c0:	0001c043 */ 	sra	$t8,$at,0x1
.L0f1015c4:
/*  f1015c4:	27110002 */ 	addiu	$s1,$t8,0x2
.L0f1015c8:
/*  f1015c8:	3c0f800a */ 	lui	$t7,%hi(g_AmIndex)
/*  f1015cc:	8def21b8 */ 	lw	$t7,%lo(g_AmIndex)($t7)
/*  f1015d0:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1015d4:	3c068008 */ 	lui	$a2,%hi(g_ScaleX)
/*  f1015d8:	01fe0019 */ 	multu	$t7,$s8
/*  f1015dc:	24c6fac0 */ 	addiu	$a2,$a2,%lo(g_ScaleX)
/*  f1015e0:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f1015e4:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f1015e8:	3c16f600 */ 	lui	$s6,0xf600
/*  f1015ec:	0000c012 */ 	mflo	$t8
/*  f1015f0:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f1015f4:	86190006 */ 	lh	$t9,0x6($s0)
/*  f1015f8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1015fc:	03317021 */ 	addu	$t6,$t9,$s1
/*  f101600:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f101604:	01f80019 */ 	multu	$t7,$t8
/*  f101608:	86180008 */ 	lh	$t8,0x8($s0)
/*  f10160c:	0000c812 */ 	mflo	$t9
/*  f101610:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f101614:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f101618:	0312c823 */ 	subu	$t9,$t8,$s2
/*  f10161c:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f101620:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f101624:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f101628:	03367025 */ 	or	$t6,$t9,$s6
/*  f10162c:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f101630:	3c19800a */ 	lui	$t9,%hi(g_AmIndex)
/*  f101634:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f101638:	8f3921b8 */ 	lw	$t9,%lo(g_AmIndex)($t9)
/*  f10163c:	033e0019 */ 	multu	$t9,$s8
/*  f101640:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f101644:	00007012 */ 	mflo	$t6
/*  f101648:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f10164c:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f101650:	01f1c023 */ 	subu	$t8,$t7,$s1
/*  f101654:	03190019 */ 	multu	$t8,$t9
/*  f101658:	86190008 */ 	lh	$t9,0x8($s0)
/*  f10165c:	00007012 */ 	mflo	$t6
/*  f101660:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101664:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f101668:	03327023 */ 	subu	$t6,$t9,$s2
/*  f10166c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101670:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f101674:	03387025 */ 	or	$t6,$t9,$t8
/*  f101678:	3c18800a */ 	lui	$t8,%hi(g_AmIndex)
/*  f10167c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f101680:	8f1821b8 */ 	lw	$t8,%lo(g_AmIndex)($t8)
/*  f101684:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f101688:	031e0019 */ 	multu	$t8,$s8
/*  f10168c:	24790008 */ 	addiu	$t9,$v1,0x8
/*  f101690:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101694:	00007012 */ 	mflo	$t6
/*  f101698:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f10169c:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f1016a0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1016a4:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f1016a8:	27380001 */ 	addiu	$t8,$t9,0x1
/*  f1016ac:	030e0019 */ 	multu	$t8,$t6
/*  f1016b0:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f1016b4:	00007812 */ 	mflo	$t7
/*  f1016b8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1016bc:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f1016c0:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f1016c4:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f1016c8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1016cc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1016d0:	01f6c825 */ 	or	$t9,$t7,$s6
/*  f1016d4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1016d8:	3c0f800a */ 	lui	$t7,%hi(g_AmIndex)
/*  f1016dc:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1016e0:	8def21b8 */ 	lw	$t7,%lo(g_AmIndex)($t7)
/*  f1016e4:	01fe0019 */ 	multu	$t7,$s8
/*  f1016e8:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1016ec:	0000c812 */ 	mflo	$t9
/*  f1016f0:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f1016f4:	86180006 */ 	lh	$t8,0x6($s0)
/*  f1016f8:	03117023 */ 	subu	$t6,$t8,$s1
/*  f1016fc:	01cf0019 */ 	multu	$t6,$t7
/*  f101700:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f101704:	0000c812 */ 	mflo	$t9
/*  f101708:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f10170c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f101710:	01f3c821 */ 	addu	$t9,$t7,$s3
/*  f101714:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f101718:	00187880 */ 	sll	$t7,$t8,0x2
/*  f10171c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f101720:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f101724:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f101728:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f10172c:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101730:	01de0019 */ 	multu	$t6,$s8
/*  f101734:	24af0008 */ 	addiu	$t7,$a1,0x8
/*  f101738:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f10173c:	0000c812 */ 	mflo	$t9
/*  f101740:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f101744:	86180006 */ 	lh	$t8,0x6($s0)
/*  f101748:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f10174c:	03117823 */ 	subu	$t7,$t8,$s1
/*  f101750:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f101754:	01d90019 */ 	multu	$t6,$t9
/*  f101758:	86190008 */ 	lh	$t9,0x8($s0)
/*  f10175c:	0000c012 */ 	mflo	$t8
/*  f101760:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f101764:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f101768:	0333c021 */ 	addu	$t8,$t9,$s3
/*  f10176c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f101770:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f101774:	0336c025 */ 	or	$t8,$t9,$s6
/*  f101778:	030e7825 */ 	or	$t7,$t8,$t6
/*  f10177c:	3c19800a */ 	lui	$t9,%hi(g_AmIndex)
/*  f101780:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f101784:	8f3921b8 */ 	lw	$t9,%lo(g_AmIndex)($t9)
/*  f101788:	033e0019 */ 	multu	$t9,$s8
/*  f10178c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f101790:	0000c012 */ 	mflo	$t8
/*  f101794:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f101798:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f10179c:	01d17823 */ 	subu	$t7,$t6,$s1
/*  f1017a0:	01f90019 */ 	multu	$t7,$t9
/*  f1017a4:	86190008 */ 	lh	$t9,0x8($s0)
/*  f1017a8:	0000c012 */ 	mflo	$t8
/*  f1017ac:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1017b0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1017b4:	0332c023 */ 	subu	$t8,$t9,$s2
/*  f1017b8:	270e0001 */ 	addiu	$t6,$t8,0x1
/*  f1017bc:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1017c0:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1017c4:	030f7025 */ 	or	$t6,$t8,$t7
/*  f1017c8:	3c0f800a */ 	lui	$t7,%hi(g_AmIndex)
/*  f1017cc:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1017d0:	8def21b8 */ 	lw	$t7,%lo(g_AmIndex)($t7)
/*  f1017d4:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1017d8:	01fe0019 */ 	multu	$t7,$s8
/*  f1017dc:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f1017e0:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f1017e4:	00007012 */ 	mflo	$t6
/*  f1017e8:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f1017ec:	86190006 */ 	lh	$t9,0x6($s0)
/*  f1017f0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1017f4:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f1017f8:	270f0001 */ 	addiu	$t7,$t8,0x1
/*  f1017fc:	01ee0019 */ 	multu	$t7,$t6
/*  f101800:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f101804:	0000c812 */ 	mflo	$t9
/*  f101808:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f10180c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f101810:	01d3c821 */ 	addu	$t9,$t6,$s3
/*  f101814:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f101818:	00187080 */ 	sll	$t6,$t8,0x2
/*  f10181c:	01d6c825 */ 	or	$t9,$t6,$s6
/*  f101820:	032fc025 */ 	or	$t8,$t9,$t7
/*  f101824:	3c0e800a */ 	lui	$t6,%hi(g_AmIndex)
/*  f101828:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f10182c:	8dce21b8 */ 	lw	$t6,%lo(g_AmIndex)($t6)
/*  f101830:	01de0019 */ 	multu	$t6,$s8
/*  f101834:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f101838:	0000c812 */ 	mflo	$t9
/*  f10183c:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f101840:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f101844:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f101848:	030e0019 */ 	multu	$t8,$t6
/*  f10184c:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f101850:	0000c812 */ 	mflo	$t9
/*  f101854:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f101858:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f10185c:	01d2c823 */ 	subu	$t9,$t6,$s2
/*  f101860:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f101864:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f101868:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f10186c:	03387825 */ 	or	$t7,$t9,$t8
/*  f101870:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f101874:	0fc54e0e */ 	jal	func0f153838
/*  f101878:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f10187c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101880:
/*  f101880:	0fc54de0 */ 	jal	func0f153780
/*  f101884:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101888:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f10188c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f101890:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f101894:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f101898:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f10189c:	8c621c04 */ 	lw	$v0,0x1c04($v1)
.L0f1018a0:
/*  f1018a0:	3c16f600 */ 	lui	$s6,0xf600
/*  f1018a4:	50400252 */ 	beqzl	$v0,.L0f1021f0
/*  f1018a8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1018ac:	c4400104 */ 	lwc1	$f0,0x104($v0)
/*  f1018b0:	c4520100 */ 	lwc1	$f18,0x100($v0)
/*  f1018b4:	3c013e00 */ 	lui	$at,0x3e00
/*  f1018b8:	44815000 */ 	mtc1	$at,$f10
/*  f1018bc:	46120101 */ 	sub.s	$f4,$f0,$f18
/*  f1018c0:	3c013e80 */ 	lui	$at,0x3e80
/*  f1018c4:	44819000 */ 	mtc1	$at,$f18
/*  f1018c8:	0000f025 */ 	or	$s8,$zero,$zero
/*  f1018cc:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f1018d0:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f1018d4:	c4480180 */ 	lwc1	$f8,0x180($v0)
/*  f1018d8:	4612303c */ 	c.lt.s	$f6,$f18
/*  f1018dc:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f1018e0:	45000002 */ 	bc1f	.L0f1018ec
/*  f1018e4:	e7b000fc */ 	swc1	$f16,0xfc($sp)
/*  f1018e8:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f1018ec:
/*  f1018ec:	8d67006c */ 	lw	$a3,0x6c($t3)
/*  f1018f0:	50e00004 */ 	beqzl	$a3,.L0f101904
/*  f1018f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1018f8:	10000002 */ 	b	.L0f101904
/*  f1018fc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101900:	00003025 */ 	or	$a2,$zero,$zero
.L0f101904:
/*  f101904:	8d680068 */ 	lw	$t0,0x68($t3)
/*  f101908:	51000004 */ 	beqzl	$t0,.L0f10191c
/*  f10190c:	00002825 */ 	or	$a1,$zero,$zero
/*  f101910:	10000002 */ 	b	.L0f10191c
/*  f101914:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101918:	00002825 */ 	or	$a1,$zero,$zero
.L0f10191c:
/*  f10191c:	8d690064 */ 	lw	$t1,0x64($t3)
/*  f101920:	51200004 */ 	beqzl	$t1,.L0f101934
/*  f101924:	00002025 */ 	or	$a0,$zero,$zero
/*  f101928:	10000002 */ 	b	.L0f101934
/*  f10192c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101930:	00002025 */ 	or	$a0,$zero,$zero
.L0f101934:
/*  f101934:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f101938:	51400004 */ 	beqzl	$t2,.L0f10194c
/*  f10193c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101940:	10000002 */ 	b	.L0f10194c
/*  f101944:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101948:	00001825 */ 	or	$v1,$zero,$zero
.L0f10194c:
/*  f10194c:	00647021 */ 	addu	$t6,$v1,$a0
/*  f101950:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f101954:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f101958:	2b010002 */ 	slti	$at,$t8,0x2
/*  f10195c:	54200004 */ 	bnezl	$at,.L0f101970
/*  f101960:	24170040 */ 	addiu	$s7,$zero,0x40
/*  f101964:	10000002 */ 	b	.L0f101970
/*  f101968:	24170030 */ 	addiu	$s7,$zero,0x30
/*  f10196c:	24170040 */ 	addiu	$s7,$zero,0x40
.L0f101970:
/*  f101970:	50e00004 */ 	beqzl	$a3,.L0f101984
/*  f101974:	00003025 */ 	or	$a2,$zero,$zero
/*  f101978:	10000002 */ 	b	.L0f101984
/*  f10197c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101980:	00003025 */ 	or	$a2,$zero,$zero
.L0f101984:
/*  f101984:	51000004 */ 	beqzl	$t0,.L0f101998
/*  f101988:	00002825 */ 	or	$a1,$zero,$zero
/*  f10198c:	10000002 */ 	b	.L0f101998
/*  f101990:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101994:	00002825 */ 	or	$a1,$zero,$zero
.L0f101998:
/*  f101998:	51200004 */ 	beqzl	$t1,.L0f1019ac
/*  f10199c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1019a0:	10000002 */ 	b	.L0f1019ac
/*  f1019a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1019a8:	00002025 */ 	or	$a0,$zero,$zero
.L0f1019ac:
/*  f1019ac:	51400004 */ 	beqzl	$t2,.L0f1019c0
/*  f1019b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1019b4:	10000002 */ 	b	.L0f1019c0
/*  f1019b8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1019bc:	00001825 */ 	or	$v1,$zero,$zero
.L0f1019c0:
/*  f1019c0:	00647821 */ 	addu	$t7,$v1,$a0
/*  f1019c4:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f1019c8:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f1019cc:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1019d0:	54200004 */ 	bnezl	$at,.L0f1019e4
/*  f1019d4:	2415000b */ 	addiu	$s5,$zero,0xb
/*  f1019d8:	10000002 */ 	b	.L0f1019e4
/*  f1019dc:	24150007 */ 	addiu	$s5,$zero,0x7
/*  f1019e0:	2415000b */ 	addiu	$s5,$zero,0xb
.L0f1019e4:
/*  f1019e4:	10e00003 */ 	beqz	$a3,.L0f1019f4
/*  f1019e8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1019ec:	10000002 */ 	b	.L0f1019f8
/*  f1019f0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1019f4:
/*  f1019f4:	00003025 */ 	or	$a2,$zero,$zero
.L0f1019f8:
/*  f1019f8:	11000003 */ 	beqz	$t0,.L0f101a08
/*  f1019fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f101a00:	10000002 */ 	b	.L0f101a0c
/*  f101a04:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101a08:
/*  f101a08:	00002825 */ 	or	$a1,$zero,$zero
.L0f101a0c:
/*  f101a0c:	51200004 */ 	beqzl	$t1,.L0f101a20
/*  f101a10:	00002025 */ 	or	$a0,$zero,$zero
/*  f101a14:	10000002 */ 	b	.L0f101a20
/*  f101a18:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101a1c:	00002025 */ 	or	$a0,$zero,$zero
.L0f101a20:
/*  f101a20:	51400004 */ 	beqzl	$t2,.L0f101a34
/*  f101a24:	00001825 */ 	or	$v1,$zero,$zero
/*  f101a28:	10000002 */ 	b	.L0f101a34
/*  f101a2c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101a30:	00001825 */ 	or	$v1,$zero,$zero
.L0f101a34:
/*  f101a34:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101a38:	03057821 */ 	addu	$t7,$t8,$a1
/*  f101a3c:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f101a40:	15c10011 */ 	bne	$t6,$at,.L0f101a88
/*  f101a44:	00000000 */ 	nop
/*  f101a48:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f101a4c:	00000000 */ 	nop
/*  f101a50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101a54:	10410021 */ 	beq	$v0,$at,.L0f101adc
/*  f101a58:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f101a5c:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*  f101a60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101a64:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x6c)
/*  f101a68:	1321001c */ 	beq	$t9,$at,.L0f101adc
/*  f101a6c:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x68)
/*  f101a70:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x64)
/*  f101a74:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x70)
/*  f101a78:	8d4aa030 */ 	lw	$t2,%lo(g_Vars+0x70)($t2)
/*  f101a7c:	8d29a024 */ 	lw	$t1,%lo(g_Vars+0x64)($t1)
/*  f101a80:	8ce7a02c */ 	lw	$a3,%lo(g_Vars+0x6c)($a3)
/*  f101a84:	8d08a028 */ 	lw	$t0,%lo(g_Vars+0x68)($t0)
.L0f101a88:
/*  f101a88:	10e00003 */ 	beqz	$a3,.L0f101a98
/*  f101a8c:	00002825 */ 	or	$a1,$zero,$zero
/*  f101a90:	10000001 */ 	b	.L0f101a98
/*  f101a94:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101a98:
/*  f101a98:	11000003 */ 	beqz	$t0,.L0f101aa8
/*  f101a9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f101aa0:	10000001 */ 	b	.L0f101aa8
/*  f101aa4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f101aa8:
/*  f101aa8:	11200003 */ 	beqz	$t1,.L0f101ab8
/*  f101aac:	00002025 */ 	or	$a0,$zero,$zero
/*  f101ab0:	10000001 */ 	b	.L0f101ab8
/*  f101ab4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101ab8:
/*  f101ab8:	11400003 */ 	beqz	$t2,.L0f101ac8
/*  f101abc:	00001825 */ 	or	$v1,$zero,$zero
/*  f101ac0:	10000001 */ 	b	.L0f101ac8
/*  f101ac4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101ac8:
/*  f101ac8:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101acc:	03027821 */ 	addu	$t7,$t8,$v0
/*  f101ad0:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f101ad4:	29c10003 */ 	slti	$at,$t6,0x3
/*  f101ad8:	1420000c */ 	bnez	$at,.L0f101b0c
.L0f101adc:
/*  f101adc:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f101ae0:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f101ae4:	8d79028c */ 	lw	$t9,0x28c($t3)
/*  f101ae8:	8d67006c */ 	lw	$a3,0x6c($t3)
/*  f101aec:	8d680068 */ 	lw	$t0,0x68($t3)
/*  f101af0:	33380001 */ 	andi	$t8,$t9,0x1
/*  f101af4:	8d690064 */ 	lw	$t1,0x64($t3)
/*  f101af8:	17000003 */ 	bnez	$t8,.L0f101b08
/*  f101afc:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f101b00:	10000002 */ 	b	.L0f101b0c
/*  f101b04:	24120008 */ 	addiu	$s2,$zero,0x8
.L0f101b08:
/*  f101b08:	2412fff8 */ 	addiu	$s2,$zero,-8
.L0f101b0c:
/*  f101b0c:	10e00003 */ 	beqz	$a3,.L0f101b1c
/*  f101b10:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101b14:	10000002 */ 	b	.L0f101b20
/*  f101b18:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101b1c:
/*  f101b1c:	00003025 */ 	or	$a2,$zero,$zero
.L0f101b20:
/*  f101b20:	51000004 */ 	beqzl	$t0,.L0f101b34
/*  f101b24:	00002825 */ 	or	$a1,$zero,$zero
/*  f101b28:	10000002 */ 	b	.L0f101b34
/*  f101b2c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101b30:	00002825 */ 	or	$a1,$zero,$zero
.L0f101b34:
/*  f101b34:	51200004 */ 	beqzl	$t1,.L0f101b48
/*  f101b38:	00002025 */ 	or	$a0,$zero,$zero
/*  f101b3c:	10000002 */ 	b	.L0f101b48
/*  f101b40:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101b44:	00002025 */ 	or	$a0,$zero,$zero
.L0f101b48:
/*  f101b48:	51400004 */ 	beqzl	$t2,.L0f101b5c
/*  f101b4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101b50:	10000002 */ 	b	.L0f101b5c
/*  f101b54:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101b58:	00001825 */ 	or	$v1,$zero,$zero
.L0f101b5c:
/*  f101b5c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f101b60:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f101b64:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f101b68:	17210019 */ 	bne	$t9,$at,.L0f101bd0
/*  f101b6c:	00000000 */ 	nop
/*  f101b70:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f101b74:	00000000 */ 	nop
/*  f101b78:	10400015 */ 	beqz	$v0,.L0f101bd0
/*  f101b7c:	00000000 */ 	nop
/*  f101b80:	0c002f40 */ 	jal	viGetViewLeft
/*  f101b84:	00000000 */ 	nop
/*  f101b88:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f101b8c:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f101b90:	44972000 */ 	mtc1	$s7,$f4
/*  f101b94:	0058001a */ 	div	$zero,$v0,$t8
/*  f101b98:	00008012 */ 	mflo	$s0
/*  f101b9c:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f101ba0:	17000002 */ 	bnez	$t8,.L0f101bac
/*  f101ba4:	00000000 */ 	nop
/*  f101ba8:	0007000d */ 	break	0x7
.L0f101bac:
/*  f101bac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101bb0:	17010004 */ 	bne	$t8,$at,.L0f101bc4
/*  f101bb4:	3c018000 */ 	lui	$at,0x8000
/*  f101bb8:	14410002 */ 	bne	$v0,$at,.L0f101bc4
/*  f101bbc:	00000000 */ 	nop
/*  f101bc0:	0006000d */ 	break	0x6
.L0f101bc4:
/*  f101bc4:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f101bc8:	10000031 */ 	b	.L0f101c90
/*  f101bcc:	3c013e80 */ 	lui	$at,0x3e80
.L0f101bd0:
/*  f101bd0:	0c002f22 */ 	jal	viGetViewWidth
/*  f101bd4:	00000000 */ 	nop
/*  f101bd8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f101bdc:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f101be0:	0c002f40 */ 	jal	viGetViewLeft
/*  f101be4:	01e08825 */ 	or	$s1,$t7,$zero
/*  f101be8:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f101bec:	8c63fac0 */ 	lw	$v1,%lo(g_ScaleX)($v1)
/*  f101bf0:	44974000 */ 	mtc1	$s7,$f8
/*  f101bf4:	3c013f00 */ 	lui	$at,0x3f00
/*  f101bf8:	0043001a */ 	div	$zero,$v0,$v1
/*  f101bfc:	00007012 */ 	mflo	$t6
/*  f101c00:	44810000 */ 	mtc1	$at,$f0
/*  f101c04:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f101c08:	0223001a */ 	div	$zero,$s1,$v1
/*  f101c0c:	0000c812 */ 	mflo	$t9
/*  f101c10:	44995000 */ 	mtc1	$t9,$f10
/*  f101c14:	14600002 */ 	bnez	$v1,.L0f101c20
/*  f101c18:	00000000 */ 	nop
/*  f101c1c:	0007000d */ 	break	0x7
.L0f101c20:
/*  f101c20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101c24:	14610004 */ 	bne	$v1,$at,.L0f101c38
/*  f101c28:	3c018000 */ 	lui	$at,0x8000
/*  f101c2c:	14410002 */ 	bne	$v0,$at,.L0f101c38
/*  f101c30:	00000000 */ 	nop
/*  f101c34:	0006000d */ 	break	0x6
.L0f101c38:
/*  f101c38:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f101c3c:	14600002 */ 	bnez	$v1,.L0f101c48
/*  f101c40:	00000000 */ 	nop
/*  f101c44:	0007000d */ 	break	0x7
.L0f101c48:
/*  f101c48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101c4c:	14610004 */ 	bne	$v1,$at,.L0f101c60
/*  f101c50:	3c018000 */ 	lui	$at,0x8000
/*  f101c54:	16210002 */ 	bne	$s1,$at,.L0f101c60
/*  f101c58:	00000000 */ 	nop
/*  f101c5c:	0006000d */ 	break	0x6
.L0f101c60:
/*  f101c60:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f101c64:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f101c68:	46001102 */ 	mul.s	$f4,$f2,$f0
/*  f101c6c:	440f9000 */ 	mfc1	$t7,$f18
/*  f101c70:	00000000 */ 	nop
/*  f101c74:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f101c78:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f101c7c:	440e4000 */ 	mfc1	$t6,$f8
/*  f101c80:	00000000 */ 	nop
/*  f101c84:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f101c88:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f101c8c:	3c013e80 */ 	lui	$at,0x3e80
.L0f101c90:
/*  f101c90:	44815000 */ 	mtc1	$at,$f10
/*  f101c94:	44800000 */ 	mtc1	$zero,$f0
/*  f101c98:	c7b20100 */ 	lwc1	$f18,0x100($sp)
/*  f101c9c:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f101ca0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f101ca4:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f101ca8:	44123000 */ 	mfc1	$s2,$f6
/*  f101cac:	00000000 */ 	nop
/*  f101cb0:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f101cb4:	02128821 */ 	addu	$s1,$s0,$s2
/*  f101cb8:	45000002 */ 	bc1f	.L0f101cc4
/*  f101cbc:	26330002 */ 	addiu	$s3,$s1,0x2
/*  f101cc0:	e7a00100 */ 	swc1	$f0,0x100($sp)
.L0f101cc4:
/*  f101cc4:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f101cc8:	3c0fe700 */ 	lui	$t7,0xe700
/*  f101ccc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f101cd0:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f101cd4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f101cd8:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f101cdc:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f101ce0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f101ce4:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f101ce8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f101cec:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101cf0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f101cf4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f101cf8:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f101cfc:	3c0e0050 */ 	lui	$t6,0x50
/*  f101d00:	3c19b900 */ 	lui	$t9,0xb900
/*  f101d04:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f101d08:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101d0c:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f101d10:	35ce4240 */ 	ori	$t6,$t6,0x4240
/*  f101d14:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101d18:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101d1c:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f101d20:	3c19fcff */ 	lui	$t9,0xfcff
/*  f101d24:	3c0efffd */ 	lui	$t6,0xfffd
/*  f101d28:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f101d2c:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101d30:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f101d34:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f101d38:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101d3c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101d40:	0c002f26 */ 	jal	viGetViewHeight
/*  f101d44:	e7a20068 */ 	swc1	$f2,0x68($sp)
/*  f101d48:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f101d4c:	00147c03 */ 	sra	$t7,$s4,0x10
/*  f101d50:	0c002f44 */ 	jal	viGetViewTop
/*  f101d54:	01e0a025 */ 	or	$s4,$t7,$zero
/*  f101d58:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f101d5c:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f101d60:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f101d64:	c7a20068 */ 	lwc1	$f2,0x68($sp)
/*  f101d68:	00001825 */ 	or	$v1,$zero,$zero
/*  f101d6c:	13000003 */ 	beqz	$t8,.L0f101d7c
/*  f101d70:	00003025 */ 	or	$a2,$zero,$zero
/*  f101d74:	10000001 */ 	b	.L0f101d7c
/*  f101d78:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101d7c:
/*  f101d7c:	8c990068 */ 	lw	$t9,0x68($a0)
/*  f101d80:	00002825 */ 	or	$a1,$zero,$zero
/*  f101d84:	13200003 */ 	beqz	$t9,.L0f101d94
/*  f101d88:	00000000 */ 	nop
/*  f101d8c:	10000001 */ 	b	.L0f101d94
/*  f101d90:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101d94:
/*  f101d94:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*  f101d98:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f101d9c:	11c00003 */ 	beqz	$t6,.L0f101dac
/*  f101da0:	00000000 */ 	nop
/*  f101da4:	10000001 */ 	b	.L0f101dac
/*  f101da8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101dac:
/*  f101dac:	8c8f0070 */ 	lw	$t7,0x70($a0)
/*  f101db0:	00002025 */ 	or	$a0,$zero,$zero
/*  f101db4:	c7a80100 */ 	lwc1	$f8,0x100($sp)
/*  f101db8:	11e00003 */ 	beqz	$t7,.L0f101dc8
/*  f101dbc:	00000000 */ 	nop
/*  f101dc0:	10000001 */ 	b	.L0f101dc8
/*  f101dc4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101dc8:
/*  f101dc8:	0085c021 */ 	addu	$t8,$a0,$a1
/*  f101dcc:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f101dd0:	03237021 */ 	addu	$t6,$t9,$v1
/*  f101dd4:	29c10002 */ 	slti	$at,$t6,0x2
/*  f101dd8:	14200003 */ 	bnez	$at,.L0f101de8
/*  f101ddc:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f101de0:	10000002 */ 	b	.L0f101dec
/*  f101de4:	24030013 */ 	addiu	$v1,$zero,0x13
.L0f101de8:
/*  f101de8:	24030022 */ 	addiu	$v1,$zero,0x22
.L0f101dec:
/*  f101dec:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f101df0:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f101df4:	13c0005e */ 	beqz	$s8,.L0f101f70
/*  f101df8:	03233823 */ 	subu	$a3,$t9,$v1
/*  f101dfc:	44928000 */ 	mtc1	$s2,$f16
/*  f101e00:	3c013e80 */ 	lui	$at,0x3e80
/*  f101e04:	44812000 */ 	mtc1	$at,$f4
/*  f101e08:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f101e0c:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f101e10:	3c014080 */ 	lui	$at,0x4080
/*  f101e14:	3c0eff00 */ 	lui	$t6,0xff00
/*  f101e18:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f101e1c:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f101e20:	44812000 */ 	mtc1	$at,$f4
/*  f101e24:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101e28:	3c0b8008 */ 	lui	$t3,%hi(g_ScaleX)
/*  f101e2c:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f101e30:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f101e34:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f101e38:	256bfac0 */ 	addiu	$t3,$t3,%lo(g_ScaleX)
/*  f101e3c:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f101e40:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f101e44:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f101e48:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f101e4c:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101e50:	022e0019 */ 	multu	$s1,$t6
/*  f101e54:	00f54821 */ 	addu	$t1,$a3,$s5
/*  f101e58:	312303ff */ 	andi	$v1,$t1,0x3ff
/*  f101e5c:	24b80008 */ 	addiu	$t8,$a1,0x8
/*  f101e60:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101e64:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f101e68:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f101e6c:	03201825 */ 	or	$v1,$t9,$zero
/*  f101e70:	30e203ff */ 	andi	$v0,$a3,0x3ff
/*  f101e74:	440f8000 */ 	mfc1	$t7,$f16
/*  f101e78:	3c078008 */ 	lui	$a3,%hi(g_ScaleX)
/*  f101e7c:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f101e80:	022f3023 */ 	subu	$a2,$s1,$t7
/*  f101e84:	00007812 */ 	mflo	$t7
/*  f101e88:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f101e8c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f101e90:	03367025 */ 	or	$t6,$t9,$s6
/*  f101e94:	01c37825 */ 	or	$t7,$t6,$v1
/*  f101e98:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f101e9c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f101ea0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f101ea4:	03001025 */ 	or	$v0,$t8,$zero
/*  f101ea8:	00d90019 */ 	multu	$a2,$t9
/*  f101eac:	24e7fac0 */ 	addiu	$a3,$a3,%lo(g_ScaleX)
/*  f101eb0:	00007012 */ 	mflo	$t6
/*  f101eb4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101eb8:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f101ebc:	0302c825 */ 	or	$t9,$t8,$v0
/*  f101ec0:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f101ec4:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f101ec8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f101ecc:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f101ed0:	adcd0004 */ 	sw	$t5,0x4($t6)
/*  f101ed4:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f101ed8:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f101edc:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101ee0:	00ce0019 */ 	multu	$a2,$t6
/*  f101ee4:	24990008 */ 	addiu	$t9,$a0,0x8
/*  f101ee8:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101eec:	02173021 */ 	addu	$a2,$s0,$s7
/*  f101ef0:	00007812 */ 	mflo	$t7
/*  f101ef4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f101ef8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f101efc:	03367025 */ 	or	$t6,$t9,$s6
/*  f101f00:	01c37825 */ 	or	$t7,$t6,$v1
/*  f101f04:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f101f08:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f101f0c:	02180019 */ 	multu	$s0,$t8
/*  f101f10:	0000c812 */ 	mflo	$t9
/*  f101f14:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f101f18:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f101f1c:	01e2c025 */ 	or	$t8,$t7,$v0
/*  f101f20:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f101f24:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f101f28:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101f2c:	00cf0019 */ 	multu	$a2,$t7
/*  f101f30:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f101f34:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f101f38:	0000c012 */ 	mflo	$t8
/*  f101f3c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f101f40:	00197380 */ 	sll	$t6,$t9,0xe
/*  f101f44:	01d67825 */ 	or	$t7,$t6,$s6
/*  f101f48:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f101f4c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f101f50:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f101f54:	02790019 */ 	multu	$s3,$t9
/*  f101f58:	00007012 */ 	mflo	$t6
/*  f101f5c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101f60:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f101f64:	0302c825 */ 	or	$t9,$t8,$v0
/*  f101f68:	10000059 */ 	b	.L0f1020d0
/*  f101f6c:	acb90004 */ 	sw	$t9,0x4($a1)
.L0f101f70:
/*  f101f70:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f101f74:	3c1800c0 */ 	lui	$t8,0xc0
/*  f101f78:	37180060 */ 	ori	$t8,$t8,0x60
/*  f101f7c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f101f80:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f101f84:	add80004 */ 	sw	$t8,0x4($t6)
/*  f101f88:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f101f8c:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f101f90:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f101f94:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101f98:	00f54821 */ 	addu	$t1,$a3,$s5
/*  f101f9c:	02380019 */ 	multu	$s1,$t8
/*  f101fa0:	312303ff */ 	andi	$v1,$t1,0x3ff
/*  f101fa4:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f101fa8:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f101fac:	00037880 */ 	sll	$t7,$v1,0x2
/*  f101fb0:	01e01825 */ 	or	$v1,$t7,$zero
/*  f101fb4:	30e203ff */ 	andi	$v0,$a3,0x3ff
/*  f101fb8:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f101fbc:	0000c812 */ 	mflo	$t9
/*  f101fc0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f101fc4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f101fc8:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f101fcc:	0303c825 */ 	or	$t9,$t8,$v1
/*  f101fd0:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f101fd4:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f101fd8:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f101fdc:	00027080 */ 	sll	$t6,$v0,0x2
/*  f101fe0:	01c01025 */ 	or	$v0,$t6,$zero
/*  f101fe4:	020f0019 */ 	multu	$s0,$t7
/*  f101fe8:	0000c012 */ 	mflo	$t8
/*  f101fec:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f101ff0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f101ff4:	01c27825 */ 	or	$t7,$t6,$v0
/*  f101ff8:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f101ffc:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f102000:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f102004:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f102008:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f10200c:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f102010:	254f0008 */ 	addiu	$t7,$t2,0x8
/*  f102014:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f102018:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f10201c:	44199000 */ 	mfc1	$t9,$f18
/*  f102020:	00000000 */ 	nop
/*  f102024:	03303021 */ 	addu	$a2,$t9,$s0
/*  f102028:	00d80019 */ 	multu	$a2,$t8
/*  f10202c:	00c04025 */ 	or	$t0,$a2,$zero
/*  f102030:	02173021 */ 	addu	$a2,$s0,$s7
/*  f102034:	0000c812 */ 	mflo	$t9
/*  f102038:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10203c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f102040:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f102044:	0303c825 */ 	or	$t9,$t8,$v1
/*  f102048:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f10204c:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f102050:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f102054:	026e0019 */ 	multu	$s3,$t6
/*  f102058:	00007812 */ 	mflo	$t7
/*  f10205c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f102060:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f102064:	03227025 */ 	or	$t6,$t9,$v0
/*  f102068:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f10206c:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f102070:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f102074:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f102078:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f10207c:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f102080:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f102084:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f102088:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f10208c:	00cf0019 */ 	multu	$a2,$t7
/*  f102090:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f102094:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f102098:	0000c012 */ 	mflo	$t8
/*  f10209c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1020a0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1020a4:	01d67825 */ 	or	$t7,$t6,$s6
/*  f1020a8:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f1020ac:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f1020b0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1020b4:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f1020b8:	01190019 */ 	multu	$t0,$t9
/*  f1020bc:	00007012 */ 	mflo	$t6
/*  f1020c0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1020c4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1020c8:	0302c825 */ 	or	$t9,$t8,$v0
/*  f1020cc:	acb90004 */ 	sw	$t9,0x4($a1)
.L0f1020d0:
/*  f1020d0:	44952000 */ 	mtc1	$s5,$f4
/*  f1020d4:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f1020d8:	3c013f40 */ 	lui	$at,0x3f40
/*  f1020dc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f1020e0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f1020e4:	44818000 */ 	mtc1	$at,$f16
/*  f1020e8:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f1020ec:	3c1900c0 */ 	lui	$t9,0xc0
/*  f1020f0:	37390060 */ 	ori	$t9,$t9,0x60
/*  f1020f4:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f1020f8:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f1020fc:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f102100:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f102104:	3c1f8008 */ 	lui	$ra,%hi(g_ScaleX)
/*  f102108:	27fffac0 */ 	addiu	$ra,$ra,%lo(g_ScaleX)
/*  f10210c:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f102110:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f102114:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f102118:	25250002 */ 	addiu	$a1,$t1,0x2
/*  f10211c:	30aa03ff */ 	andi	$t2,$a1,0x3ff
/*  f102120:	24990008 */ 	addiu	$t9,$a0,0x8
/*  f102124:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f102128:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f10212c:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f102130:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f102134:	44155000 */ 	mfc1	$s5,$f10
/*  f102138:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f10213c:	440f4000 */ 	mfc1	$t7,$f8
/*  f102140:	00b53821 */ 	addu	$a3,$a1,$s5
/*  f102144:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f102148:	01f04021 */ 	addu	$t0,$t7,$s0
/*  f10214c:	01180019 */ 	multu	$t0,$t8
/*  f102150:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f102154:	0000c812 */ 	mflo	$t9
/*  f102158:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10215c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f102160:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f102164:	0307c825 */ 	or	$t9,$t8,$a3
/*  f102168:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f10216c:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f102170:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f102174:	01c05025 */ 	or	$t2,$t6,$zero
/*  f102178:	020f0019 */ 	multu	$s0,$t7
/*  f10217c:	0000c012 */ 	mflo	$t8
/*  f102180:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f102184:	00197380 */ 	sll	$t6,$t9,0xe
/*  f102188:	01ca7825 */ 	or	$t7,$t6,$t2
/*  f10218c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f102190:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f102194:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f102198:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f10219c:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f1021a0:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1021a4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f1021a8:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1021ac:	00d80019 */ 	multu	$a2,$t8
/*  f1021b0:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f1021b4:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f1021b8:	0000c812 */ 	mflo	$t9
/*  f1021bc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1021c0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1021c4:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f1021c8:	0307c825 */ 	or	$t9,$t8,$a3
/*  f1021cc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1021d0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f1021d4:	010e0019 */ 	multu	$t0,$t6
/*  f1021d8:	00007812 */ 	mflo	$t7
/*  f1021dc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1021e0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1021e4:	032a7025 */ 	or	$t6,$t9,$t2
/*  f1021e8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1021ec:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f1021f0:
/*  f1021f0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1021f4:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f1021f8:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1021fc:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f102200:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f102204:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f102208:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f10220c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f102210:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f102214:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f102218:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f10221c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f102220:	ac2ffac0 */ 	sw	$t7,%lo(g_ScaleX)($at)
/*  f102224:	03e00008 */ 	jr	$ra
/*  f102228:	27bd01d8 */ 	addiu	$sp,$sp,0x1d8
/*  f10222c:	00000000 */ 	nop
);

// Mismatch: Health bar rectangles near the end are just hopeless.
//Gfx *amRender(Gfx *gdl)
//{
//	u32 mode;
//	u32 flags; // 1d0
//	u32 *colours;
//	struct gfxvtx *vertices;
//	s32 mpchrnum; // 1c4
//	s16 column;
//	s16 row;
//	u32 colour;
//	s16 xb; // 1ba
//	s16 yb; // 1b8
//	s16 xa; // 182
//	s16 ya; // 180
//	char text1[32]; // 15c
//	s32 textheight; // 13c
//	s32 textwidth; // 138
//	char text2[32]; // 118
//	u32 flags2; // 114
//	struct chrdata *chr;
//	s16 tmp1;
//	s16 tmp2;
//	s32 buddynum;
//
//	if (g_ViMode == VIMODE_HIRES) {
//		g_ScaleX = 2;
//	} else {
//		g_ScaleX = 1;
//	}
//
//	g_AmIndex = g_Vars.currentplayernum;
//	g_Vars.currentplayer->commandingaibot = NULL;
//
//	if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
//		// Draw diamond
//		gdl = func0f153628(gdl);
//
//		if (g_Vars.normmplayerisrunning
//				&& g_AmMenus[g_AmIndex].screenindex >= 2) {
//			mpchrnum = g_Vars.currentplayer->aibuddynums[g_AmMenus[g_AmIndex].screenindex - 2];
//		}
//
//		if (g_AmMenus[g_AmIndex].dstx == -123) {
//			amCalculateSlotPosition(
//					g_AmMenus[g_AmIndex].slotnum % 3,
//					g_AmMenus[g_AmIndex].slotnum / 3,
//					&g_AmMenus[g_AmIndex].selx,
//					&g_AmMenus[g_AmIndex].sely);
//			g_AmMenus[g_AmIndex].dstx = g_AmMenus[g_AmIndex].selx;
//			g_AmMenus[g_AmIndex].dsty = g_AmMenus[g_AmIndex].sely;
//		} else {
//			amCalculateSlotPosition(
//					g_AmMenus[g_AmIndex].slotnum % 3,
//					g_AmMenus[g_AmIndex].slotnum / 3,
//					&g_AmMenus[g_AmIndex].dstx,
//					&g_AmMenus[g_AmIndex].dsty);
//		}
//
//		gdl = func0f0d479c(gdl);
//
//		colours = gfxAllocateColours(2);
//		vertices = gfxAllocateVertices(8);
//
//		gDPPipeSync(gdl++);
//		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//		gDPSetAlphaCompare(gdl++, G_AC_NONE);
//		gDPSetAlphaDither(gdl++, G_AD_NOISE);
//		gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
//		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//
//		func0f0b39c0(&gdl, NULL, 2, 0, 2, 1, 0);
//
//		gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//
//		// Top
//		amCalculateSlotPosition(1, 0, &xb, &yb);
//
//		vertices[0].x = xb * 10;
//		vertices[0].y = yb * 10;
//		vertices[0].z = -10;
//
//		// Right
//		amCalculateSlotPosition(2, 1, &xb, &yb);
//
//		vertices[1].x = xb * 10;
//		vertices[1].y = yb * 10;
//		vertices[1].z = -10;
//
//		// Bottom
//		amCalculateSlotPosition(1, 2, &xb, &yb);
//
//		vertices[2].x = xb * 10;
//		vertices[2].y = yb * 10;
//		vertices[2].z = -10;
//
//		// Left
//		amCalculateSlotPosition(0, 1, &xb, &yb);
//
//		vertices[3].x = xb * 10;
//		vertices[3].y = yb * 10;
//		vertices[3].z = -10;
//
//		vertices[4].z = -10;
//		vertices[5].z = -10;
//		vertices[6].z = -10;
//		vertices[7].z = -10;
//
//		tmp2 = (vertices[1].x - vertices[3].x) / 8;
//		tmp1 = (vertices[2].y - vertices[0].y) / 8;
//
//		vertices[4].x = vertices[0].x;
//		vertices[4].y = vertices[0].y + tmp1;
//		vertices[5].x = vertices[1].x - tmp2;
//		vertices[5].y = vertices[1].y;
//		vertices[6].x = vertices[2].x;
//		vertices[6].y = vertices[2].y - tmp1;
//		vertices[7].x = vertices[3].x + tmp2;
//		vertices[7].y = vertices[3].y;
//
//		vertices[0].s = 0;
//		vertices[1].s = 0;
//		vertices[2].s = 0;
//		vertices[3].s = 0;
//		vertices[4].s = 4;
//		vertices[5].s = 4;
//		vertices[6].s = 4;
//		vertices[7].s = 4;
//
//		colours[0] = 0x22222200;
//		colours[1] = 0x0000004f;
//
//		gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
//		gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);
//
//		gDPTri2(gdl++, 4, 5, 6, 6, 7, 4);
//		gDPTri4(gdl++, 0, 4, 7, 7, 3, 0, 0, 1, 5, 5, 4, 0);
//		gDPTri4(gdl++, 1, 2, 6, 6, 5, 1, 6, 2, 3, 3, 7, 6);
//
//		gdl = func0f0d49c8(gdl);
//
//		// Draw slots
//		for (column = 0; column < 3; column++) {
//			for (row = 0; row < 3; row++) {
//				// 06c
//				mode = AMSLOTMODE_DEFAULT;
//				amCalculateSlotPosition(column, row, &xa, &ya);
//				flags = 0;
//
//				// 0a0
//				if (column + row * 3 == g_AmMenus[g_AmIndex].slotnum) {
//					mode = AMSLOTMODE_FOCUSED;
//				}
//
//				// 0b0
//				if (g_MissionConfig.iscoop
//						&& (buddynum = amGetFirstBuddyIndex(), buddynum >= 0)) {
//					if (mode == AMSLOTMODE_DEFAULT && g_AmMenus[g_AmIndex].screenindex >= 2) {
//						struct chrdata *chr = g_Vars.aibuddies[buddynum]->chr;
//
//						if (var800719a0[row][column] == 7) {
//							if (chr->hidden & CHRHFLAG_PASSIVE) {
//								mode = AMSLOTMODE_CURRENT;
//							}
//						} else if (var800719a0[row][column] == 1) {
//							if ((chr->hidden & CHRHFLAG_PASSIVE) == 0) {
//								mode = AMSLOTMODE_CURRENT;
//							}
//						}
//					}
//				} else {
//					if (g_Vars.normmplayerisrunning
//							&& mode == AMSLOTMODE_DEFAULT
//							&& g_AmMenus[g_AmIndex].screenindex >= 2) {
//						s32 a = g_AmBotCommands[var800719a0[row][column]];
//						s32 b = g_MpPlayerChrs[mpchrnum]->aibot->command;
//
//						if (a == b) {
//							mode = AMSLOTMODE_CURRENT;
//						}
//					}
//				}
//
//				colour = 0xffffffff;
//
//				if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
//					colour = 0x4f4f4f7f;
//				}
//
//				amGetSlotDetails(column + row * 3, &flags, text1);
//
//				if (column == 1 && row == 1) {
//					if (!amIsCramped()) {
//						gdl = amRenderText(gdl, text1, colour, xa, ya);
//					}
//				} else {
//					gdl = amRenderSlot(gdl, text1, xa, ya, mode, flags);
//				}
//			}
//		}
//
//		// Render AI bot name and weapon
//		if (!(g_MissionConfig.iscoop && amGetFirstBuddyIndex() >= 0)
//				&& g_Vars.normmplayerisrunning
//				&& g_AmMenus[g_AmIndex].screenindex >= 2) {
//			gdl = amRenderAibotInfo(gdl, g_AmMenus[g_AmIndex].screenindex - 2);
//		}
//
//		// 131c
//		// Note: the column and row values will never be 1 here, so this
//		// condition always passes. Looks like they intended to skip drawing the
//		// selection box on the simulants screen if the middle box was selected.
//		if (g_AmMenus[g_AmIndex].screenindex < 2 || column != 1 || row != 1) {
//			// Render selection
//			s32 halfwidth;
//			s32 above = 6;
//			s32 below = 6;
//			u32 tmp;
//
//			if (PLAYERCOUNT() >= 2) {
//				above = 5;
//				below = 3;
//			}
//
//			tmp = (sinf(g_AmMenus[g_AmIndex].selpulse) + 1) * 127;
//			colour = 0xff0000ff | tmp << 8 | tmp << 16;
//
//			if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
//				colour = 0x4f4f4f7f;
//			}
//
//			gdl = gfxSetPrimColour(gdl, colour);
//
//			halfwidth = g_AmMenus[g_AmIndex].slotwidth / 2;
//
//			if (g_AmMenus[g_AmIndex].slotnum == 4) {
//				if (amIsCramped()) {
//					halfwidth = 1;
//					above = 2;
//					below = 0;
//				} else if (PLAYERCOUNT() >= 2) {
//					amGetSlotDetails(4, &flags2, text2);
//					textMeasure(&textheight, &textwidth, text2, g_AmFont1, g_AmFont2, 0);
//
//					halfwidth = textwidth / 2 + 2;
//				}
//			}
//
//			// Top
//			gDPFillRectangleScaled(gdl++,
//					g_AmMenus[g_AmIndex].selx - halfwidth,
//					g_AmMenus[g_AmIndex].sely - above,
//					g_AmMenus[g_AmIndex].selx + halfwidth + 1,
//					g_AmMenus[g_AmIndex].sely - above + 1);
//
//			// Bottom
//			gDPFillRectangleScaled(gdl++,
//					g_AmMenus[g_AmIndex].selx - halfwidth,
//					g_AmMenus[g_AmIndex].sely + below,
//					g_AmMenus[g_AmIndex].selx + halfwidth + 1,
//					g_AmMenus[g_AmIndex].sely + below + 1);
//
//			// Left
//			gDPFillRectangleScaled(gdl++,
//					g_AmMenus[g_AmIndex].selx - halfwidth,
//					g_AmMenus[g_AmIndex].sely - above + 1,
//					g_AmMenus[g_AmIndex].selx - halfwidth + 1,
//					g_AmMenus[g_AmIndex].sely + below);
//
//			// Right
//			gDPFillRectangleScaled(gdl++,
//					g_AmMenus[g_AmIndex].selx + halfwidth,
//					g_AmMenus[g_AmIndex].sely - above + 1,
//					g_AmMenus[g_AmIndex].selx + halfwidth + 1,
//					g_AmMenus[g_AmIndex].sely + below);
//
//			gdl = func0f153838(gdl);
//		}
//
//		gdl = func0f153780(gdl);
//	}
//
//	// 18a4
//	chr = g_Vars.currentplayer->commandingaibot;
//
//	if (chr) {
//		// Render health bar
//		f32 healthfrac = (chr->maxdamage - chr->damage) / chr->maxdamage;
//		f32 shieldfrac = chr->cshield * 0.125f;
//		bool redhealth = false;
//		s32 xoffset;
//		s32 width;
//		s32 healthheight;
//		s32 part1width;
//		s32 part1left;
//		s16 y;
//		s32 part2left;
//
//		// 18e0
//		if (healthfrac < 0.25f) {
//			redhealth = true; // s8
//		}
//
//		width = PLAYERCOUNT() >= 2 ? 48 : 64; // s7
//		healthheight = PLAYERCOUNT() >= 2 ? 7 : 11; // s5
//		xoffset = 0; // s2
//
//		if ((PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
//				|| PLAYERCOUNT() >= 3) {
//			xoffset = (g_Vars.currentplayernum & 1) == 0 ? 8 : -8;
//		}
//
//		// 1b0c
//		if (PLAYERCOUNT() == 1 && optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
//			part1left = viGetViewLeft() / g_ScaleX + 32; // s0
//		} else {
//			// 1bd0
//			part1left = (s32)((viGetViewWidth() / g_ScaleX) * 0.5f)
//				+ (s32)(viGetViewLeft() / g_ScaleX)
//				- (s32)(width * 0.5f)
//				+ xoffset;
//		}
//
//		// 1c90
//		part1width = (s32)(width * 0.25f) - 1; // s2
//		if (part1width);
//		part2left = part1left + part1width + 2; // s3
//
//		if (healthfrac < 0) {
//			healthfrac = 0;
//		}
//
//		gDPPipeSync(gdl++);
//		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//		gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
//
//		// 1d40
//		y = viGetViewTop() + viGetViewHeight() - (PLAYERCOUNT() >= 2 ? 19 : 34);
//
//		// 1df4
//		if (redhealth) {
//			gDPSetPrimColorViaWord(gdl++, 0, 0, 0xff000060);
//
//			// Part 1 red
//			gDPFillRectangleScaled(gdl++,
//					(part1left + part1width - 1) - (s32)(part1width * 0.25f - healthfrac * 4),
//					y,
//					part1left + part1width - 1,
//					y + healthheight);
//
//			gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000080);
//
//			// Part 1 black
//			gDPFillRectangleScaled(gdl++,
//					part1left,
//					y,
//					part1left + part1width - 1 - (s32)(part1width * 0.25f - healthfrac * 4),
//					y + healthheight);
//
//			// Part 2 black
//			gDPFillRectangleScaled(gdl++,
//					part2left,
//					y,
//					part1left + width,
//					y + healthheight);
//		} else {
//			// 1f70
//			gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00c00060);
//
//			// Part 1 green
//			gDPFillRectangleScaled(gdl++,
//					part1left,
//					y,
//					part1left + part1width - 1,
//					y + healthheight);
//
//			// Part 2 green
//			gDPFillRectangleScaled(gdl++,
//					part2left,
//					y,
//					part1left + (s32)(width * healthfrac),
//					y + healthheight);
//
//			gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000080);
//
//			// Part 2 black
//			gDPFillRectangleScaled(gdl++,
//					part1left + (s32)(width * healthfrac),
//					y,
//					part1left + width,
//					y + healthheight);
//		}
//
//		// Render shield bar
//		// 20d0
//		gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00c00060);
//
//		gDPFillRectangleScaled(gdl++,
//				part1left,
//				y + healthheight + 2,
//				part1left + (s32)(width * shieldfrac),
//				y + healthheight + 2 + (s32)(healthheight * 0.75f));
//
//		gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000080);
//
//		gDPFillRectangleScaled(gdl++,
//				part1left + (s32)(width * shieldfrac),
//				y + healthheight + 2,
//				part1left + width,
//				y + healthheight + 2 + (s32)(healthheight * 0.75f));
//	}
//
//	g_ScaleX = 1;
//
//	return gdl;
//}
