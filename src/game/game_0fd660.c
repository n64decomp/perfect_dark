#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_0fd660.h"
#include "game/game_111600.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/mplayer.h"
#include "game/game_190260.h"
#include "game/game_197600.h"
#include "game/game_19c990.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_13130.h"
#include "lib/lib_16110.h"
#include "lib/lib_4b480.h"
#include "types.h"

const u32 var7f1b2b20[] = {0x00010603};
const u32 var7f1b2b24[] = {0x04070502};

void mpOpenPickTarget(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	if (!mpIsPaused()) {
		g_ActiveMenuThings[g_ActiveMenuIndex].unk33 = g_ActiveMenuThings[g_ActiveMenuIndex].allbots;
		g_Vars.currentplayer->activemenumode = 0;
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
		func0f0f8330(&menudialog_picktarget, 8);
		g_MpPlayerNum = prevplayernum;
	}
}

GLOBAL_ASM(
glabel menuhandler000fd6f0
.late_rodata
glabel var7f1b2c8c
.word menuhandler000fd6f0+0x34 # f0fd724
glabel var7f1b2c90
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2c94
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2c98
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2c9c
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2ca0
.word menuhandler000fd6f0+0x1a4 # f0fd894
glabel var7f1b2ca4
.word menuhandler000fd6f0+0x2e8 # f0fd9d8
glabel var7f1b2ca8
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cac
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cb0
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cb4
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cb8
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cbc
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cc0
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cc4
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cc8
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2ccc
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cd0
.word menuhandler000fd6f0+0x570 # f0fdc60
glabel var7f1b2cd4
.word menuhandler000fd6f0+0x2fc # f0fd9ec
glabel var7f1b2cd8
.word menuhandler000fd6f0+0x564 # f0fdc54
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
/*  f0fd720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd724:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuIndex)
/*  f0fd728:	8def21b8 */ 	lw	$t7,%lo(g_ActiveMenuIndex)($t7)
/*  f0fd72c:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuThings+0x33)
/*  f0fd730:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd734:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fd738:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fd73c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fd740:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fd744:	93392103 */ 	lbu	$t9,%lo(g_ActiveMenuThings+0x33)($t9)
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
/*  f0fd778:	10000001 */ 	beqz	$zero,.L0f0fd780
/*  f0fd77c:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fd780:
/*  f0fd780:	8d6d0068 */ 	lw	$t5,0x68($t3)
/*  f0fd784:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd788:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd78c:	11a00003 */ 	beqz	$t5,.L0f0fd79c
/*  f0fd790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd794:	10000001 */ 	beqz	$zero,.L0f0fd79c
/*  f0fd798:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd79c:
/*  f0fd79c:	8d7f0064 */ 	lw	$ra,0x64($t3)
/*  f0fd7a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd7a4:	13e00003 */ 	beqz	$ra,.L0f0fd7b4
/*  f0fd7a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd7ac:	10000001 */ 	beqz	$zero,.L0f0fd7b4
/*  f0fd7b0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fd7b4:
/*  f0fd7b4:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f0fd7b8:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f0fd7bc:	11400003 */ 	beqz	$t2,.L0f0fd7cc
/*  f0fd7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd7c4:	10000001 */ 	beqz	$zero,.L0f0fd7cc
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
/*  f0fd814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd818:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0fd81c:
/*  f0fd81c:	5420fff9 */ 	bnezl	$at,.L0f0fd804
/*  f0fd820:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f0fd824:
/*  f0fd824:	11400003 */ 	beqz	$t2,.L0f0fd834
/*  f0fd828:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0fd82c:	10000002 */ 	beqz	$zero,.L0f0fd838
/*  f0fd830:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fd834:
/*  f0fd834:	00004825 */ 	or	$t1,$zero,$zero
.L0f0fd838:
/*  f0fd838:	11800003 */ 	beqz	$t4,.L0f0fd848
/*  f0fd83c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd840:	10000001 */ 	beqz	$zero,.L0f0fd848
/*  f0fd844:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd848:
/*  f0fd848:	11a00003 */ 	beqz	$t5,.L0f0fd858
/*  f0fd84c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd850:	10000001 */ 	beqz	$zero,.L0f0fd858
/*  f0fd854:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fd858:
/*  f0fd858:	13e00003 */ 	beqz	$ra,.L0f0fd868
/*  f0fd85c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd860:	10000001 */ 	beqz	$zero,.L0f0fd868
/*  f0fd864:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd868:
/*  f0fd868:	00a37021 */ 	addu	$t6,$a1,$v1
/*  f0fd86c:	01c4c821 */ 	addu	$t9,$t6,$a0
/*  f0fd870:	03277821 */ 	addu	$t7,$t9,$a3
/*  f0fd874:	01e92821 */ 	addu	$a1,$t7,$t1
/*  f0fd878:	100000f9 */ 	beqz	$zero,.L0f0fdc60
/*  f0fd87c:	af050000 */ 	sw	$a1,0x0($t8)
.L0f0fd880:
/*  f0fd880:	8dcec530 */ 	lw	$t6,%lo(g_MpNumPlayers)($t6)
/*  f0fd884:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fd888:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f0fd88c:	100000f4 */ 	beqz	$zero,.L0f0fdc60
/*  f0fd890:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fd894:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f0fd898:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
/*  f0fd89c:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0fd8a0:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuThings)
/*  f0fd8a4:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0fd8a8:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0fd8ac:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd8b0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fd8b4:	25ef20d0 */ 	addiu	$t7,$t7,%lo(g_ActiveMenuThings)
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
/*  f0fd910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd914:	908f0125 */ 	lbu	$t7,0x125($a0)
/*  f0fd918:	90780125 */ 	lbu	$t8,0x125($v1)
/*  f0fd91c:	11f80008 */ 	beq	$t7,$t8,.L0f0fd940
/*  f0fd920:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fd924:
/*  f0fd924:	10000006 */ 	beqz	$zero,.L0f0fd940
/*  f0fd928:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0fd92c:
/*  f0fd92c:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f0fd930:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0fd934:	11c30002 */ 	beq	$t6,$v1,.L0f0fd940
/*  f0fd938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd93c:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0fd940:
/*  f0fd940:	0441ffef */ 	bgez	$v0,.L0f0fd900
/*  f0fd944:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0fd9b8:	10000003 */ 	beqz	$zero,.L0f0fd9c8
/*  f0fd9bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fd9c0:
/*  f0fd9c0:	0fc6490e */ 	jal	mpAibotApplyAttack
/*  f0fd9c4:	8c65001c */ 	lw	$a1,0x1c($v1)
.L0f0fd9c8:
/*  f0fd9c8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fd9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd9d0:	100000a4 */ 	beqz	$zero,.L0f0fdc64
/*  f0fd9d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd9d8:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0fd9dc:	3c0e000f */ 	lui	$t6,0xf
/*  f0fd9e0:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0fd9e4:	1000009e */ 	beqz	$zero,.L0f0fdc60
/*  f0fd9e8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0fd9ec:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fd9f0:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f0fd9f4:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
/*  f0fd9f8:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0fd9fc:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fda00:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0fda04:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f0fda08:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuThings)
/*  f0fda0c:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0fda10:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fda14:	271820d0 */ 	addiu	$t8,$t8,%lo(g_ActiveMenuThings)
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
/*  f0fda74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fda78:	90ce0125 */ 	lbu	$t6,0x125($a2)
/*  f0fda7c:	90590125 */ 	lbu	$t9,0x125($v0)
/*  f0fda80:	11d90007 */ 	beq	$t6,$t9,.L0f0fdaa0
/*  f0fda84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fda88:
/*  f0fda88:	10000005 */ 	beqz	$zero,.L0f0fdaa0
/*  f0fda8c:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f0fda90:
/*  f0fda90:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0fda94:	11380002 */ 	beq	$t1,$t8,.L0f0fdaa0
/*  f0fda98:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0fdb24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb28:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fdb2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0fdb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0fdb38:	51e00013 */ 	beqzl	$t7,.L0f0fdb88
/*  f0fdb3c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0fdb40:	44814000 */ 	mtc1	$at,$f8
/*  f0fdb44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fdb48:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fdb4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0fdb50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb54:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fdb58:	444ff800 */ 	cfc1	$t7,$31
/*  f0fdb5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0fdb64:	15e00005 */ 	bnez	$t7,.L0f0fdb7c
/*  f0fdb68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb6c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0fdb70:	3c018000 */ 	lui	$at,0x8000
/*  f0fdb74:	10000007 */ 	beqz	$zero,.L0f0fdb94
/*  f0fdb78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0fdb7c:
/*  f0fdb7c:	10000005 */ 	beqz	$zero,.L0f0fdb94
/*  f0fdb80:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0fdb84:	440f4000 */ 	mfc1	$t7,$f8
.L0f0fdb88:
/*  f0fdb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb8c:	05e0fffb */ 	bltz	$t7,.L0f0fdb7c
/*  f0fdb90:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fdb94:
/*  f0fdb94:	44d9f800 */ 	ctc1	$t9,$31
/*  f0fdb98:	0fc01a40 */ 	jal	func0f006900
/*  f0fdb9c:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0fdba0:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f0fdba4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fdba8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fdbac:	8d84000c */ 	lw	$a0,0xc($t4)
/*  f0fdbb0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0fdbb4:	00817025 */ 	or	$t6,$a0,$at
/*  f0fdbb8:	0fc01a40 */ 	jal	func0f006900
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
/*  f0fdbe8:	0c002f02 */ 	jal	func0000bc08
/*  f0fdbec:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0fdbf0:	0c002f06 */ 	jal	func0000bc18
/*  f0fdbf4:	a7a2005c */ 	sh	$v0,0x5c($sp)
/*  f0fdbf8:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0fdbfc:	3c198008 */ 	lui	$t9,%hi(var8007fb10)
/*  f0fdc00:	3c0f8008 */ 	lui	$t7,%hi(var8007fb0c)
/*  f0fdc04:	8f070000 */ 	lw	$a3,0x0($t8)
/*  f0fdc08:	87b8005c */ 	lh	$t8,0x5c($sp)
/*  f0fdc0c:	8deffb0c */ 	lw	$t7,%lo(var8007fb0c)($t7)
/*  f0fdc10:	8f39fb10 */ 	lw	$t9,%lo(var8007fb10)($t9)
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
/*  f0fdc3c:	0fc5580f */ 	jal	func0f15603c
/*  f0fdc40:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0fdc44:	0fc54de0 */ 	jal	func0f153780
/*  f0fdc48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fdc4c:	10000006 */ 	beqz	$zero,.L0f0fdc68
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
/*  f0fdc70:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogMpPickTarget(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	switch (operation) {
	case MENUOP_100:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_102:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_101:
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		break;
	}

	return false;
}

void activemenuSetAiBuddyTemperament(bool aggressive)
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

void activemenuSetAiBuddyStealth(void)
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

s32 activemenuGetFirstBuddyIndex(void)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr && chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DEAD
					&& chr->prop
					&& chr->animdata) {
				return i;
			}
		}
	}

	return -1;
}

void activemenuApply(s32 slot)
{
	s32 numinvitems;
	s32 invindex;
	bool pass;
	s32 lVar4;
	s32 uVar6;
	s32 weaponnum;
	s32 i;

	switch (g_ActiveMenuThings[g_ActiveMenuIndex].screenindex) {
	case 0: // Weapon
		if (slot > 4) {
			slot--;
		}

		invindex = g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot];
		numinvitems = currentPlayerGetNumInvItems();

		if (invindex < numinvitems) {
			weaponnum = currentPlayerGetWeaponNumByInvIndex(invindex);
			pass = true;

			if (weaponnum) {
				lVar4 = currentPlayerHasWeaponEquipped(weaponnum);

				if (lVar4 != -1) {
					pass = false;

					if (lVar4 == 0) {
						func0f0b1948(weaponnum, 1);
					} else {
						func0f0b1948(weaponnum, 0);
					}
				}
			}

			if (pass) {
				pass = true;

				if (var80088804 != 0) {
					uVar6 = func0f19d268(func0f19d250());

					if (uVar6 == g_Vars.currentplayer->unk0638) {
						pass = false;
					}
				}

				if (pass) {
					currentPlayerSetEquipCurItem(invindex);

					if (func0f111cf8(weaponnum, weaponnum)) {
						if (getCurrentPlayerWeaponId(0) != weaponnum) {
							currentPlayerEquipWeapon(0, weaponnum);
						}

						if (getCurrentPlayerWeaponId(1) != weaponnum) {
							currentPlayerEquipWeapon(1, weaponnum);
						}
					} else {
						if (getCurrentPlayerWeaponId(0) != weaponnum) {
							currentPlayerEquipWeapon(0, weaponnum);
						}

						if (getCurrentPlayerWeaponId(1) != 0) {
							currentPlayerEquipWeapon(1, 0);
						}
					}
				}
			}
		}
		break;
	case 1: // Function - 0c8
		if (g_Vars.currentplayer->unk1580 >= WEAPON_UNARMED
				&& g_Vars.currentplayer->unk1580 <= WEAPON_COMBATBOOST
				&& g_MpPlayers[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->unk1580 - 1) >> 3] & (1 << (g_Vars.currentplayer->unk1580 - 1 & 7))) {
			if (slot == 1) {
				g_ActiveMenuThings[g_ActiveMenuIndex].unk30 = 1;
			}
		} else {
			if (slot != 1) {
				g_ActiveMenuThings[g_ActiveMenuIndex].unk30 = 1;
			}
		}
		break;
	default: // 148
		if (g_MissionConfig.iscoop) {
			if (activemenuGetFirstBuddyIndex() > -1) {
				if (slot == 1) {
					activemenuSetAiBuddyTemperament(true); // aggressive
				} else if (slot == 7) {
					activemenuSetAiBuddyTemperament(false); // passive
				} else if (slot == 3) {
					activemenuSetAiBuddyStealth();
				}
			}
		} else if (g_Vars.normmplayerisrunning) {
			if (g_ActiveMenuThings[g_ActiveMenuIndex].allbots) {
				for (i = 0; i < g_Vars.currentplayer->numaibuddies; i++) {
					mpAibotApplyCommand(g_MpPlayerChrs[g_Vars.currentplayer->aibuddynums[i]], g_ActiveMenuMpBotCommands[slot]);
				}
			} else {
				mpAibotApplyCommand(g_MpPlayerChrs[g_Vars.currentplayer->aibuddynums[g_ActiveMenuThings[g_ActiveMenuIndex].screenindex - 2]], g_ActiveMenuMpBotCommands[slot]);
			}
		}
	}
}

void activemenuGetSlotDetails(s32 slot, u32 *flags, char *label)
{
	u32 weaponnum;
	s32 qty;
	s32 secs;
	s32 modulo;
	struct weaponfunc *prifunc;
	struct weaponfunc *secfunc;

	switch (g_ActiveMenuThings[g_ActiveMenuIndex].screenindex) {
	case 0: // Weapon screen
		if (slot == 4) {
			strcpy(label, langGet(L_MISC(170))); // "Weapon"
			return;
		}

		if (slot > 4) {
			slot--;
		}

		if (currentPlayerGetEquipCurItem() == g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot]) {
			*flags |= AMSLOTFLAG_CURRENT;
		}

		if (g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot] >= currentPlayerGetNumInvItems()) {
			strcpy(label, "");
		} else {
			if (currentPlayerGetWeaponNumByInvIndex(g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot]) == WEAPON_CLOAKINGDEVICE) {
				// Special case: "Cloak %d"
				qty = ammoGetQuantity(AMMOTYPE_CLOAK);
				secs = qty / 60;
				modulo = (qty - (secs * 60)) * 100 / 60;
				sprintf(label, langGet(0x57eb), secs + (modulo > 0 ? 1 : 0));
			} else {
				strcpy(label, currentPlayerGetInvShortNameByIndex(g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot]));
			}
		}

		weaponnum = currentPlayerGetWeaponNumByInvIndex(g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot]);

		if (currentPlayerHasWeaponEquipped(weaponnum) == true) {
			*flags |= AMSLOTFLAG_ACTIVE;
		}

		weaponnum = currentPlayerGetWeaponNumByInvIndex(g_ActiveMenuThings[g_ActiveMenuIndex].weaponnums[slot]);

		if (func0f0a1d14(weaponnum) == false) {
			*flags |= AMSLOTFLAG_HIDDEN;
		}
		break;
	case 1: // Function screen
		strcpy(label, "");

		if (slot == 4) {
			strcpy(label, langGet(L_MISC(171))); // "Function"
		} else if (slot == 1 || slot == 7) {
			prifunc = weaponGetFunction(&g_Vars.currentplayer->unk0638, 0);
			secfunc = weaponGetFunction(&g_Vars.currentplayer->unk0638, 1);

			if (slot == 1) {
				if (!secfunc
						|| g_Vars.currentplayer->unk1580 < WEAPON_UNARMED
						|| g_Vars.currentplayer->unk1580 > WEAPON_COMBATBOOST
						|| (g_MpPlayers[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->unk1580 - 1) >> 3] & (1 << (g_Vars.currentplayer->unk1580 - 1 & 7))) == 0) {
					*flags |= AMSLOTFLAG_CURRENT;
				}

				if (prifunc) {
					strcpy(label, langGet(prifunc->name));
				}
			} else {
				if (!prifunc || (
						g_Vars.currentplayer->unk1580 >= WEAPON_UNARMED
						&& g_Vars.currentplayer->unk1580 <= WEAPON_COMBATBOOST
						&& g_MpPlayers[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->unk1580 - 1) >> 3] & (1 << (g_Vars.currentplayer->unk1580 - 1 & 7)))) {
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
				strcpy(label, mpGetBotCommandName(g_ActiveMenuMpBotCommands[slot]));
			}
		}
		break;
	}
}

GLOBAL_ASM(
glabel func0f0fe848
/*  f0fe848:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fe84c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0fe850:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0fe854:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0fe858:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0fe85c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0fe860:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f0fe864:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f0fe868:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuThings)
/*  f0fe86c:	25e420d0 */ 	addiu	$a0,$t7,%lo(g_ActiveMenuThings)
/*  f0fe870:	3c12800b */ 	lui	$s2,%hi(g_MpSetup+0x6)
/*  f0fe874:	3c13800a */ 	lui	$s3,%hi(var800a21b0)
/*  f0fe878:	3c0c8008 */ 	lui	$t4,%hi(mpweaponstable)
/*  f0fe87c:	3c0a7f1b */ 	lui	$t2,%hi(var7f1b2b20)
/*  f0fe880:	a1c00250 */ 	sb	$zero,0x250($t6)
/*  f0fe884:	8d060318 */ 	lw	$a2,0x318($t0)
/*  f0fe888:	254a2b20 */ 	addiu	$t2,$t2,%lo(var7f1b2b20)
/*  f0fe88c:	258c7268 */ 	addiu	$t4,$t4,%lo(mpweaponstable)
/*  f0fe890:	267321b0 */ 	addiu	$s3,$s3,%lo(var800a21b0)
/*  f0fe894:	2652cb8e */ 	addiu	$s2,$s2,%lo(g_MpSetup+0x6)
/*  f0fe898:	00801825 */ 	or	$v1,$a0,$zero
/*  f0fe89c:	2410005b */ 	addiu	$s0,$zero,0x5b
/*  f0fe8a0:	2411005c */ 	addiu	$s1,$zero,0x5c
/*  f0fe8a4:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0fe8a8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0fe8ac:	240900ff */ 	addiu	$t1,$zero,0xff
.L0f0fe8b0:
/*  f0fe8b0:	a0600030 */ 	sb	$zero,0x30($v1)
/*  f0fe8b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fe8b8:	00802825 */ 	or	$a1,$a0,$zero
.L0f0fe8bc:
/*  f0fe8bc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fe8c0:	28410008 */ 	slti	$at,$v0,0x8
/*  f0fe8c4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0fe8c8:	1420fffc */ 	bnez	$at,.L0f0fe8bc
/*  f0fe8cc:	a0a90027 */ 	sb	$t1,0x27($a1)
/*  f0fe8d0:	10c00018 */ 	beqz	$a2,.L0f0fe934
/*  f0fe8d4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fe8d8:	91580000 */ 	lbu	$t8,0x0($t2)
/*  f0fe8dc:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f0fe8e0:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f0fe8e4:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f0fe8e8:	a32b0028 */ 	sb	$t3,0x28($t9)
/*  f0fe8ec:	90ee0018 */ 	lbu	$t6,0x18($a3)
.L0f0fe8f0:
/*  f0fe8f0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0fe8f4:	01cd0019 */ 	multu	$t6,$t5
/*  f0fe8f8:	00007812 */ 	mflo	$t7
/*  f0fe8fc:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f0fe900:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f0fe904:	10400009 */ 	beqz	$v0,.L0f0fe92c
/*  f0fe908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe90c:	10500007 */ 	beq	$v0,$s0,.L0f0fe92c
/*  f0fe910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe914:	10510005 */ 	beq	$v0,$s1,.L0f0fe92c
/*  f0fe918:	0145c821 */ 	addu	$t9,$t2,$a1
/*  f0fe91c:	932e0000 */ 	lbu	$t6,0x0($t9)
/*  f0fe920:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0fe924:	008e7821 */ 	addu	$t7,$a0,$t6
/*  f0fe928:	a1e20028 */ 	sb	$v0,0x28($t7)
.L0f0fe92c:
/*  f0fe92c:	54f2fff0 */ 	bnel	$a3,$s2,.L0f0fe8f0
/*  f0fe930:	90ee0018 */ 	lbu	$t6,0x18($a3)
.L0f0fe934:
/*  f0fe934:	24840038 */ 	addiu	$a0,$a0,0x38
/*  f0fe938:	1493ffdd */ 	bne	$a0,$s3,.L0f0fe8b0
/*  f0fe93c:	24630038 */ 	addiu	$v1,$v1,0x38
/*  f0fe940:	8d18006c */ 	lw	$t8,0x6c($t0)
/*  f0fe944:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fe948:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe94c:	13000003 */ 	beqz	$t8,.L0f0fe95c
/*  f0fe950:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fe954:	10000001 */ 	beqz	$zero,.L0f0fe95c
/*  f0fe958:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fe95c:
/*  f0fe95c:	8d190068 */ 	lw	$t9,0x68($t0)
/*  f0fe960:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fe964:	13200003 */ 	beqz	$t9,.L0f0fe974
/*  f0fe968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe96c:	10000001 */ 	beqz	$zero,.L0f0fe974
/*  f0fe970:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fe974:
/*  f0fe974:	8d0e0064 */ 	lw	$t6,0x64($t0)
/*  f0fe978:	11c00003 */ 	beqz	$t6,.L0f0fe988
/*  f0fe97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe980:	10000001 */ 	beqz	$zero,.L0f0fe988
/*  f0fe984:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fe988:
/*  f0fe988:	8d0f0070 */ 	lw	$t7,0x70($t0)
/*  f0fe98c:	11e00003 */ 	beqz	$t7,.L0f0fe99c
/*  f0fe990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe994:	10000001 */ 	beqz	$zero,.L0f0fe99c
/*  f0fe998:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fe99c:
/*  f0fe99c:	0045c021 */ 	addu	$t8,$v0,$a1
/*  f0fe9a0:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0fe9a4:	03237021 */ 	addu	$t6,$t9,$v1
/*  f0fe9a8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0fe9ac:	1420000a */ 	bnez	$at,.L0f0fe9d8
/*  f0fe9b0:	3c198008 */ 	lui	$t9,%hi(var8007fb10)
/*  f0fe9b4:	3c0f8008 */ 	lui	$t7,%hi(var8007fb08)
/*  f0fe9b8:	8deffb08 */ 	lw	$t7,%lo(var8007fb08)($t7)
/*  f0fe9bc:	3c01800a */ 	lui	$at,%hi(var800a21b0)
/*  f0fe9c0:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f0fe9c4:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f0fe9c8:	ac2f21b0 */ 	sw	$t7,%lo(var800a21b0)($at)
/*  f0fe9cc:	3c01800a */ 	lui	$at,%hi(var800a21b4)
/*  f0fe9d0:	10000008 */ 	beqz	$zero,.L0f0fe9f4
/*  f0fe9d4:	ac3821b4 */ 	sw	$t8,%lo(var800a21b4)($at)
.L0f0fe9d8:
/*  f0fe9d8:	8f39fb10 */ 	lw	$t9,%lo(var8007fb10)($t9)
/*  f0fe9dc:	3c0e8008 */ 	lui	$t6,%hi(var8007fb0c)
/*  f0fe9e0:	8dcefb0c */ 	lw	$t6,%lo(var8007fb0c)($t6)
/*  f0fe9e4:	3c01800a */ 	lui	$at,%hi(var800a21b0)
/*  f0fe9e8:	ac3921b0 */ 	sw	$t9,%lo(var800a21b0)($at)
/*  f0fe9ec:	3c01800a */ 	lui	$at,%hi(var800a21b4)
/*  f0fe9f0:	ac2e21b4 */ 	sw	$t6,%lo(var800a21b4)($at)
.L0f0fe9f4:
/*  f0fe9f4:	3c01800a */ 	lui	$at,%hi(g_ActiveMenuIndex)
/*  f0fe9f8:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0fe9fc:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0fea00:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f0fea04:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f0fea08:	ac2021b8 */ 	sw	$zero,%lo(g_ActiveMenuIndex)($at)
/*  f0fea0c:	03e00008 */ 	jr	$ra
/*  f0fea10:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

s16 func0f0fea14(void)
{
	u32 sp140;
	s32 value;
	s32 max = 0;
	s32 i;
	u32 flags;
	char label[32];

	for (i = 0; i != 9; i++) {
		activemenuGetSlotDetails(i, &flags, label);
		func0f1572f8(&sp140, &value, label, var800a21b0, var800a21b4, 0);

		if (value > max) {
			max = value;
		}
	}

	if (PLAYERCOUNT() > 1) {
		max += 3;
	} else {
		max += 4;
	}

	return max;
}

void activemenuChangeScreen(s32 step)
{
	s32 maxscreenindex;

	g_ActiveMenuThings[g_ActiveMenuIndex].screenindex += step;

	if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
		if (g_ActiveMenuThings[g_ActiveMenuIndex].allbots) {
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
		if (g_MissionConfig.iscoop && activemenuGetFirstBuddyIndex() >= 0) {
			// Weapon selection, second function and AI buddy commands
			maxscreenindex = 2;
		} else {
			// Weapon selection and second function
			maxscreenindex = 1;
		}
	}

	if (g_ActiveMenuThings[g_ActiveMenuIndex].screenindex > maxscreenindex) {
		g_ActiveMenuThings[g_ActiveMenuIndex].screenindex = 0;
	}

	if (g_ActiveMenuThings[g_ActiveMenuIndex].screenindex < 0) {
		g_ActiveMenuThings[g_ActiveMenuIndex].screenindex = maxscreenindex;
	}

	g_ActiveMenuThings[g_ActiveMenuIndex].unk02 = 10;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk0a = -123;
	g_ActiveMenuThings[g_ActiveMenuIndex].slotnum = 4;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk14 = 0;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk10 = 0;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk18 = 0;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk04 = func0f0fea14();
}

GLOBAL_ASM(
glabel func0f0fecd4
/*  f0fecd4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0fecd8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0fecdc:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0fece0:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0fece4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fece8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fecec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0fecf0:	0fc44a54 */ 	jal	currentPlayerGetNumInvItems
/*  f0fecf4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0fecf8:	3c04800a */ 	lui	$a0,%hi(g_ActiveMenuIndex)
/*  f0fecfc:	8c8421b8 */ 	lw	$a0,%lo(g_ActiveMenuIndex)($a0)
/*  f0fed00:	3c01800a */ 	lui	$at,%hi(g_ActiveMenuThings+0x31)
/*  f0fed04:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuThings)
/*  f0fed08:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f0fed0c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f0fed10:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f0fed14:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0fed18:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0fed1c:	002e0821 */ 	addu	$at,$at,$t6
/*  f0fed20:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fed24:	271820d0 */ 	addiu	$t8,$t8,%lo(g_ActiveMenuThings)
/*  f0fed28:	00409825 */ 	or	$s3,$v0,$zero
/*  f0fed2c:	a0222101 */ 	sb	$v0,%lo(g_ActiveMenuThings+0x31)($at)
/*  f0fed30:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0fed34:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f0fed38:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fed3c:
/*  f0fed3c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fed40:	2a210008 */ 	slti	$at,$s1,0x8
/*  f0fed44:	a0640020 */ 	sb	$a0,0x20($v1)
/*  f0fed48:	1420fffc */ 	bnez	$at,.L0f0fed3c
/*  f0fed4c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fed50:	18400029 */ 	blez	$v0,.L0f0fedf8
/*  f0fed54:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fed58:	2415004d */ 	addiu	$s5,$zero,0x4d
/*  f0fed5c:	2414005d */ 	addiu	$s4,$zero,0x5d
/*  f0fed60:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f0fed64:	24100008 */ 	addiu	$s0,$zero,0x8
.L0f0fed68:
/*  f0fed68:	0fc44b11 */ 	jal	currentPlayerGetWeaponNumByInvIndex
/*  f0fed6c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0fed70:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0fed74:	18800003 */ 	blez	$a0,.L0f0fed84
/*  f0fed78:	28810042 */ 	slti	$at,$a0,0x42
/*  f0fed7c:	14200006 */ 	bnez	$at,.L0f0fed98
/*  f0fed80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fed84:
/*  f0fed84:	12840004 */ 	beq	$s4,$a0,.L0f0fed98
/*  f0fed88:	24010044 */ 	addiu	$at,$zero,0x44
/*  f0fed8c:	10810002 */ 	beq	$a0,$at,.L0f0fed98
/*  f0fed90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fed94:	16a40014 */ 	bne	$s5,$a0,.L0f0fede8
.L0f0fed98:
/*  f0fed98:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuIndex)
/*  f0fed9c:	8f3921b8 */ 	lw	$t9,%lo(g_ActiveMenuIndex)($t9)
/*  f0feda0:	3c09800a */ 	lui	$t1,%hi(g_ActiveMenuThings)
/*  f0feda4:	252920d0 */ 	addiu	$t1,$t1,%lo(g_ActiveMenuThings)
/*  f0feda8:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f0fedac:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0fedb0:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0fedb4:	01091021 */ 	addu	$v0,$t0,$t1
/*  f0fedb8:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fedbc:
/*  f0fedbc:	904a0028 */ 	lbu	$t2,0x28($v0)
/*  f0fedc0:	548a0007 */ 	bnel	$a0,$t2,.L0f0fede0
/*  f0fedc4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fedc8:	904b0020 */ 	lbu	$t3,0x20($v0)
/*  f0fedcc:	564b0007 */ 	bnel	$s2,$t3,.L0f0fedec
/*  f0fedd0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fedd4:	10000004 */ 	beqz	$zero,.L0f0fede8
/*  f0fedd8:	a0510020 */ 	sb	$s1,0x20($v0)
/*  f0feddc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0fede0:
/*  f0fede0:	1470fff6 */ 	bne	$v1,$s0,.L0f0fedbc
/*  f0fede4:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0fede8:
/*  f0fede8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0fedec:
/*  f0fedec:	1633ffde */ 	bne	$s1,$s3,.L0f0fed68
/*  f0fedf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fedf4:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fedf8:
/*  f0fedf8:	24100008 */ 	addiu	$s0,$zero,0x8
/*  f0fedfc:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f0fee00:	2414005d */ 	addiu	$s4,$zero,0x5d
/*  f0fee04:	1a60004f */ 	blez	$s3,.L0f0fef44
/*  f0fee08:	2415004d */ 	addiu	$s5,$zero,0x4d
.L0f0fee0c:
/*  f0fee0c:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuIndex)
/*  f0fee10:	8d8c21b8 */ 	lw	$t4,%lo(g_ActiveMenuIndex)($t4)
/*  f0fee14:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuThings)
/*  f0fee18:	25ce20d0 */ 	addiu	$t6,$t6,%lo(g_ActiveMenuThings)
/*  f0fee1c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f0fee20:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0fee24:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0fee28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fee2c:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f0fee30:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fee34:
/*  f0fee34:	904f0020 */ 	lbu	$t7,0x20($v0)
/*  f0fee38:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fee3c:	162f0002 */ 	bne	$s1,$t7,.L0f0fee48
/*  f0fee40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fee44:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fee48:
/*  f0fee48:	1470fffa */ 	bne	$v1,$s0,.L0f0fee34
/*  f0fee4c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fee50:	5480003a */ 	bnezl	$a0,.L0f0fef3c
/*  f0fee54:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fee58:	0fc44b11 */ 	jal	currentPlayerGetWeaponNumByInvIndex
/*  f0fee5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0fee60:	304600ff */ 	andi	$a2,$v0,0xff
/*  f0fee64:	18c00004 */ 	blez	$a2,.L0f0fee78
/*  f0fee68:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0fee6c:	28810042 */ 	slti	$at,$a0,0x42
/*  f0fee70:	14200004 */ 	bnez	$at,.L0f0fee84
/*  f0fee74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fee78:
/*  f0fee78:	12840002 */ 	beq	$s4,$a0,.L0f0fee84
/*  f0fee7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fee80:	16a4002d */ 	bne	$s5,$a0,.L0f0fef38
.L0f0fee84:
/*  f0fee84:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuIndex)
/*  f0fee88:	8f1821b8 */ 	lw	$t8,%lo(g_ActiveMenuIndex)($t8)
/*  f0fee8c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuThings)
/*  f0fee90:	250820d0 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuThings)
/*  f0fee94:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0fee98:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fee9c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0feea0:	3c037f1b */ 	lui	$v1,%hi(var7f1b2b20)
/*  f0feea4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0feea8:	24632b20 */ 	addiu	$v1,$v1,%lo(var7f1b2b20)
/*  f0feeac:	03282021 */ 	addu	$a0,$t9,$t0
/*  f0feeb0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0feeb4:
/*  f0feeb4:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f0feeb8:	00895021 */ 	addu	$t2,$a0,$t1
/*  f0feebc:	914b0028 */ 	lbu	$t3,0x28($t2)
/*  f0feec0:	564b0004 */ 	bnel	$s2,$t3,.L0f0feed4
/*  f0feec4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0feec8:	10000005 */ 	beqz	$zero,.L0f0feee0
/*  f0feecc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0feed0:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0feed4:
/*  f0feed4:	28410008 */ 	slti	$at,$v0,0x8
/*  f0feed8:	1420fff6 */ 	bnez	$at,.L0f0feeb4
/*  f0feedc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0feee0:
/*  f0feee0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0feee4:	14a1000d */ 	bne	$a1,$at,.L0f0fef1c
/*  f0feee8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0feeec:	3c037f1b */ 	lui	$v1,%hi(var7f1b2b20)
/*  f0feef0:	24632b20 */ 	addiu	$v1,$v1,%lo(var7f1b2b20)
.L0f0feef4:
/*  f0feef4:	906c0000 */ 	lbu	$t4,0x0($v1)
/*  f0feef8:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f0feefc:	91ae0020 */ 	lbu	$t6,0x20($t5)
/*  f0fef00:	564e0004 */ 	bnel	$s2,$t6,.L0f0fef14
/*  f0fef04:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fef08:	10000004 */ 	beqz	$zero,.L0f0fef1c
/*  f0fef0c:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fef10:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0fef14:
/*  f0fef14:	1450fff7 */ 	bne	$v0,$s0,.L0f0feef4
/*  f0fef18:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0fef1c:
/*  f0fef1c:	04a00006 */ 	bltz	$a1,.L0f0fef38
/*  f0fef20:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b2b20)
/*  f0fef24:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f0fef28:	91ef2b20 */ 	lbu	$t7,%lo(var7f1b2b20)($t7)
/*  f0fef2c:	008f1021 */ 	addu	$v0,$a0,$t7
/*  f0fef30:	a0510020 */ 	sb	$s1,0x20($v0)
/*  f0fef34:	a0460028 */ 	sb	$a2,0x28($v0)
.L0f0fef38:
/*  f0fef38:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0fef3c:
/*  f0fef3c:	1633ffb3 */ 	bne	$s1,$s3,.L0f0fee0c
/*  f0fef40:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fef44:
/*  f0fef44:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0fef48:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0fef4c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0fef50:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0fef54:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0fef58:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0fef5c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0fef60:	03e00008 */ 	jr	$ra
/*  f0fef64:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

void activemenuOpen(void)
{
	if ((g_Vars.currentplayer->unk1580_s32 & 1) == 0) {
		g_ActiveMenuIndex = g_Vars.currentplayernum;
		g_Vars.currentplayer->activemenumode = 1;
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		g_ActiveMenuThings[g_ActiveMenuIndex].screenindex = 0;
		g_ActiveMenuThings[g_ActiveMenuIndex].unk1c = 0;
		func0f0fecd4();
		activemenuChangeScreen(0);
		g_ActiveMenuThings[g_ActiveMenuIndex].unk02 = g_ActiveMenuThings[g_ActiveMenuIndex].unk04 + 5;
		g_ActiveMenuThings[g_ActiveMenuIndex].unk18 = 0.3;
		g_ActiveMenuThings[g_ActiveMenuIndex].unk34 = 0;
		g_ActiveMenuThings[g_ActiveMenuIndex].unk33 = 0;
		g_ActiveMenuThings[g_ActiveMenuIndex].allbots = false;
	}
}

void activemenuClose(void)
{
	if (g_ActiveMenuThings[g_ActiveMenuIndex].slotnum != 4) {
		activemenuApply(g_ActiveMenuThings[g_ActiveMenuIndex].slotnum);
	}

	g_Vars.currentplayer->activemenumode = 0;
	g_Vars.currentplayer->unk1c40 = -1;
	g_PlayersWithControl[g_Vars.currentplayernum] = 1;
}

GLOBAL_ASM(
glabel func0f0ff0bc
/*  f0ff0bc:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f0ff0c0:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
/*  f0ff0c4:	3c02800a */ 	lui	$v0,%hi(g_ActiveMenuThings)
/*  f0ff0c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ff0cc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0ff0d0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ff0d4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0ff0d8:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f0ff0dc:	804220d0 */ 	lb	$v0,%lo(g_ActiveMenuThings)($v0)
/*  f0ff0e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ff0e4:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x6c)
/*  f0ff0e8:	2c580001 */ 	sltiu	$t8,$v0,0x1
/*  f0ff0ec:	13000020 */ 	beqz	$t8,.L0f0ff170
/*  f0ff0f0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ff0f4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ff0f8:	8c59006c */ 	lw	$t9,0x6c($v0)
/*  f0ff0fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ff100:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff104:	13200003 */ 	beqz	$t9,.L0f0ff114
/*  f0ff108:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff10c:	10000001 */ 	beqz	$zero,.L0f0ff114
/*  f0ff110:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0ff114:
/*  f0ff114:	8c4b0068 */ 	lw	$t3,0x68($v0)
/*  f0ff118:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff11c:	11600003 */ 	beqz	$t3,.L0f0ff12c
/*  f0ff120:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff124:	10000001 */ 	beqz	$zero,.L0f0ff12c
/*  f0ff128:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff12c:
/*  f0ff12c:	8c4c0064 */ 	lw	$t4,0x64($v0)
/*  f0ff130:	11800003 */ 	beqz	$t4,.L0f0ff140
/*  f0ff134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff138:	10000001 */ 	beqz	$zero,.L0f0ff140
/*  f0ff13c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff140:
/*  f0ff140:	8c4d0070 */ 	lw	$t5,0x70($v0)
/*  f0ff144:	11a00003 */ 	beqz	$t5,.L0f0ff154
/*  f0ff148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff14c:	10000001 */ 	beqz	$zero,.L0f0ff154
/*  f0ff150:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff154:
/*  f0ff154:	00657021 */ 	addu	$t6,$v1,$a1
/*  f0ff158:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0ff15c:	01e61021 */ 	addu	$v0,$t7,$a2
/*  f0ff160:	28580003 */ 	slti	$t8,$v0,0x3
/*  f0ff164:	3b020001 */ 	xori	$v0,$t8,0x1
/*  f0ff168:	5440003f */ 	bnezl	$v0,.L0f0ff268
/*  f0ff16c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff170:
/*  f0ff170:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f0ff174:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f0ff178:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x68)
/*  f0ff17c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x64)
/*  f0ff180:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x70)
/*  f0ff184:	38590001 */ 	xori	$t9,$v0,0x1
/*  f0ff188:	8d4aa030 */ 	lw	$t2,%lo(g_Vars+0x70)($t2)
/*  f0ff18c:	8d29a024 */ 	lw	$t1,%lo(g_Vars+0x64)($t1)
/*  f0ff190:	8d08a028 */ 	lw	$t0,%lo(g_Vars+0x68)($t0)
/*  f0ff194:	17200018 */ 	bnez	$t9,.L0f0ff1f8
/*  f0ff198:	8ce7a02c */ 	lw	$a3,%lo(g_Vars+0x6c)($a3)
/*  f0ff19c:	10e00003 */ 	beqz	$a3,.L0f0ff1ac
/*  f0ff1a0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ff1a4:	10000001 */ 	beqz	$zero,.L0f0ff1ac
/*  f0ff1a8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0ff1ac:
/*  f0ff1ac:	11000003 */ 	beqz	$t0,.L0f0ff1bc
/*  f0ff1b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff1b4:	10000001 */ 	beqz	$zero,.L0f0ff1bc
/*  f0ff1b8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff1bc:
/*  f0ff1bc:	11200003 */ 	beqz	$t1,.L0f0ff1cc
/*  f0ff1c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff1c4:	10000001 */ 	beqz	$zero,.L0f0ff1cc
/*  f0ff1c8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff1cc:
/*  f0ff1cc:	11400003 */ 	beqz	$t2,.L0f0ff1dc
/*  f0ff1d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff1d4:	10000001 */ 	beqz	$zero,.L0f0ff1dc
/*  f0ff1d8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff1dc:
/*  f0ff1dc:	00655821 */ 	addu	$t3,$v1,$a1
/*  f0ff1e0:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0ff1e4:	01861021 */ 	addu	$v0,$t4,$a2
/*  f0ff1e8:	384d0002 */ 	xori	$t5,$v0,0x2
/*  f0ff1ec:	2da20001 */ 	sltiu	$v0,$t5,0x1
/*  f0ff1f0:	5440001d */ 	bnezl	$v0,.L0f0ff268
/*  f0ff1f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff1f8:
/*  f0ff1f8:	10e00003 */ 	beqz	$a3,.L0f0ff208
/*  f0ff1fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ff200:	10000001 */ 	beqz	$zero,.L0f0ff208
/*  f0ff204:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0ff208:
/*  f0ff208:	11000003 */ 	beqz	$t0,.L0f0ff218
/*  f0ff20c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff210:	10000001 */ 	beqz	$zero,.L0f0ff218
/*  f0ff214:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff218:
/*  f0ff218:	11200003 */ 	beqz	$t1,.L0f0ff228
/*  f0ff21c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff220:	10000001 */ 	beqz	$zero,.L0f0ff228
/*  f0ff224:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff228:
/*  f0ff228:	11400003 */ 	beqz	$t2,.L0f0ff238
/*  f0ff22c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff230:	10000001 */ 	beqz	$zero,.L0f0ff238
/*  f0ff234:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff238:
/*  f0ff238:	00657021 */ 	addu	$t6,$v1,$a1
/*  f0ff23c:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0ff240:	01e61021 */ 	addu	$v0,$t7,$a2
/*  f0ff244:	38580002 */ 	xori	$t8,$v0,0x2
/*  f0ff248:	2f020001 */ 	sltiu	$v0,$t8,0x1
/*  f0ff24c:	50400006 */ 	beqzl	$v0,.L0f0ff268
/*  f0ff250:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ff254:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ff258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff25c:	38590001 */ 	xori	$t9,$v0,0x1
/*  f0ff260:	2f220001 */ 	sltiu	$v0,$t9,0x1
/*  f0ff264:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff268:
/*  f0ff268:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ff26c:	03e00008 */ 	jr	$ra
/*  f0ff270:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff274
/*  f0ff274:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ff278:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ff27c:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f0ff280:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0ff284:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ff288:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0ff28c:	11c00003 */ 	beqz	$t6,.L0f0ff29c
/*  f0ff290:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ff294:	10000002 */ 	beqz	$zero,.L0f0ff2a0
/*  f0ff298:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f0ff29c:
/*  f0ff29c:	00005025 */ 	or	$t2,$zero,$zero
.L0f0ff2a0:
/*  f0ff2a0:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f0ff2a4:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuIndex)
/*  f0ff2a8:	258c21b8 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuIndex)
/*  f0ff2ac:	51e00004 */ 	beqzl	$t7,.L0f0ff2c0
/*  f0ff2b0:	00004025 */ 	or	$t0,$zero,$zero
/*  f0ff2b4:	10000002 */ 	beqz	$zero,.L0f0ff2c0
/*  f0ff2b8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0ff2bc:	00004025 */ 	or	$t0,$zero,$zero
.L0f0ff2c0:
/*  f0ff2c0:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f0ff2c4:	53000004 */ 	beqzl	$t8,.L0f0ff2d8
/*  f0ff2c8:	00004825 */ 	or	$t1,$zero,$zero
/*  f0ff2cc:	10000002 */ 	beqz	$zero,.L0f0ff2d8
/*  f0ff2d0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0ff2d4:	00004825 */ 	or	$t1,$zero,$zero
.L0f0ff2d8:
/*  f0ff2d8:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f0ff2dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff2e0:	13200003 */ 	beqz	$t9,.L0f0ff2f0
/*  f0ff2e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff2e8:	10000001 */ 	beqz	$zero,.L0f0ff2f0
/*  f0ff2ec:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff2f0:
/*  f0ff2f0:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f0ff2f4:	240d0038 */ 	addiu	$t5,$zero,0x38
/*  f0ff2f8:	3c0b800a */ 	lui	$t3,%hi(g_ActiveMenuThings)
/*  f0ff2fc:	01cd0019 */ 	multu	$t6,$t5
/*  f0ff300:	256b20d0 */ 	addiu	$t3,$t3,%lo(g_ActiveMenuThings)
/*  f0ff304:	87a40042 */ 	lh	$a0,0x42($sp)
/*  f0ff308:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff30c:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f0ff310:	00007812 */ 	mflo	$t7
/*  f0ff314:	016fc021 */ 	addu	$t8,$t3,$t7
/*  f0ff318:	87190002 */ 	lh	$t9,0x2($t8)
/*  f0ff31c:	03240019 */ 	multu	$t9,$a0
/*  f0ff320:	00007012 */ 	mflo	$t6
/*  f0ff324:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f0ff328:	87a30046 */ 	lh	$v1,0x46($sp)
/*  f0ff32c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0ff330:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0ff334:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0ff338:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0ff33c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f0ff340:	25e3ffce */ 	addiu	$v1,$t7,-50
/*  f0ff344:	a4e30000 */ 	sh	$v1,0x0($a3)
/*  f0ff348:	87b80042 */ 	lh	$t8,0x42($sp)
/*  f0ff34c:	53010010 */ 	beql	$t8,$at,.L0f0ff390
/*  f0ff350:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0ff354:	5060000e */ 	beqzl	$v1,.L0f0ff390
/*  f0ff358:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0ff35c:	84d90000 */ 	lh	$t9,0x0($a2)
/*  f0ff360:	07210003 */ 	bgez	$t9,.L0f0ff370
/*  f0ff364:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0ff368:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0ff36c:	00017043 */ 	sra	$t6,$at,0x1
.L0f0ff370:
/*  f0ff370:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f0ff374:	84ef0000 */ 	lh	$t7,0x0($a3)
/*  f0ff378:	05e10003 */ 	bgez	$t7,.L0f0ff388
/*  f0ff37c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0ff380:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0ff384:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0ff388:
/*  f0ff388:	a4f80000 */ 	sh	$t8,0x0($a3)
/*  f0ff38c:	afa3001c */ 	sw	$v1,0x1c($sp)
.L0f0ff390:
/*  f0ff390:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff394:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0ff398:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff39c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff3a0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0ff3a4:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f0ff3a8:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f0ff3ac:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0ff3b0:	3c0b800a */ 	lui	$t3,%hi(g_ActiveMenuThings)
/*  f0ff3b4:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuIndex)
/*  f0ff3b8:	258c21b8 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuIndex)
/*  f0ff3bc:	256b20d0 */ 	addiu	$t3,$t3,%lo(g_ActiveMenuThings)
/*  f0ff3c0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0ff3c4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff3c8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0ff3cc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff3d0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff3d4:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0ff3d8:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f0ff3dc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f0ff3e0:	10400029 */ 	beqz	$v0,.L0f0ff488
/*  f0ff3e4:	240d0038 */ 	addiu	$t5,$zero,0x38
/*  f0ff3e8:	14600002 */ 	bnez	$v1,.L0f0ff3f4
/*  f0ff3ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ff3f0:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0ff3f4:
/*  f0ff3f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ff3f8:	54810012 */ 	bnel	$a0,$at,.L0f0ff444
/*  f0ff3fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff400:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0ff404:	032d0019 */ 	multu	$t9,$t5
/*  f0ff408:	00007012 */ 	mflo	$t6
/*  f0ff40c:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f0ff410:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f0ff414:	07010003 */ 	bgez	$t8,.L0f0ff424
/*  f0ff418:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0ff41c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0ff420:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ff424:
/*  f0ff424:	00197023 */ 	negu	$t6,$t9
/*  f0ff428:	01c27823 */ 	subu	$t7,$t6,$v0
/*  f0ff42c:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*  f0ff430:	00a97021 */ 	addu	$t6,$a1,$t1
/*  f0ff434:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f0ff438:	10000043 */ 	beqz	$zero,.L0f0ff548
/*  f0ff43c:	01ea2021 */ 	addu	$a0,$t7,$t2
/*  f0ff440:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0ff444:
/*  f0ff444:	5481000d */ 	bnel	$a0,$at,.L0f0ff47c
/*  f0ff448:	00a97021 */ 	addu	$t6,$a1,$t1
/*  f0ff44c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0ff450:	030d0019 */ 	multu	$t8,$t5
/*  f0ff454:	0000c812 */ 	mflo	$t9
/*  f0ff458:	01797021 */ 	addu	$t6,$t3,$t9
/*  f0ff45c:	85cf0004 */ 	lh	$t7,0x4($t6)
/*  f0ff460:	05e10003 */ 	bgez	$t7,.L0f0ff470
/*  f0ff464:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0ff468:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0ff46c:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0ff470:
/*  f0ff470:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0ff474:	a4d90000 */ 	sh	$t9,0x0($a2)
/*  f0ff478:	00a97021 */ 	addu	$t6,$a1,$t1
.L0f0ff47c:
/*  f0ff47c:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f0ff480:	10000031 */ 	beqz	$zero,.L0f0ff548
/*  f0ff484:	01ea2021 */ 	addu	$a0,$t7,$t2
.L0f0ff488:
/*  f0ff488:	00a9c021 */ 	addu	$t8,$a1,$t1
/*  f0ff48c:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f0ff490:	032a2021 */ 	addu	$a0,$t9,$t2
/*  f0ff494:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff498:	54200016 */ 	bnezl	$at,.L0f0ff4f4
/*  f0ff49c:	28810003 */ 	slti	$at,$a0,0x3
/*  f0ff4a0:	5460002a */ 	bnezl	$v1,.L0f0ff54c
/*  f0ff4a4:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff4a8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff4ac:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff4b0:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f0ff4b4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff4b8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff4bc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff4c0:	14400021 */ 	bnez	$v0,.L0f0ff548
/*  f0ff4c4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff4c8:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ff4cc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0ff4d0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0ff4d4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ff4d8:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f0ff4dc:	01e1001a */ 	div	$zero,$t7,$at
/*  f0ff4e0:	0000c012 */ 	mflo	$t8
/*  f0ff4e4:	a4d80000 */ 	sh	$t8,0x0($a2)
/*  f0ff4e8:	10000018 */ 	beqz	$zero,.L0f0ff54c
/*  f0ff4ec:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff4f0:	28810003 */ 	slti	$at,$a0,0x3
.L0f0ff4f4:
/*  f0ff4f4:	54200015 */ 	bnezl	$at,.L0f0ff54c
/*  f0ff4f8:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff4fc:	54600013 */ 	bnezl	$v1,.L0f0ff54c
/*  f0ff500:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff504:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff508:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff50c:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f0ff510:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff514:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff518:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff51c:	1440000a */ 	bnez	$v0,.L0f0ff548
/*  f0ff520:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff524:	84d90000 */ 	lh	$t9,0x0($a2)
/*  f0ff528:	2401000e */ 	addiu	$at,$zero,0xe
/*  f0ff52c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ff530:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0ff534:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0ff538:	01c1001a */ 	div	$zero,$t6,$at
/*  f0ff53c:	00007812 */ 	mflo	$t7
/*  f0ff540:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*  f0ff544:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ff548:
/*  f0ff548:	28810002 */ 	slti	$at,$a0,0x2
.L0f0ff54c:
/*  f0ff54c:	5420000b */ 	bnezl	$at,.L0f0ff57c
/*  f0ff550:	28810003 */ 	slti	$at,$a0,0x3
/*  f0ff554:	84f80000 */ 	lh	$t8,0x0($a3)
/*  f0ff558:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0ff55c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0ff560:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0ff564:	0321001a */ 	div	$zero,$t9,$at
/*  f0ff568:	00007012 */ 	mflo	$t6
/*  f0ff56c:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*  f0ff570:	1000000d */ 	beqz	$zero,.L0f0ff5a8
/*  f0ff574:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff578:	28810003 */ 	slti	$at,$a0,0x3
.L0f0ff57c:
/*  f0ff57c:	5420000a */ 	bnezl	$at,.L0f0ff5a8
/*  f0ff580:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff584:	84ef0000 */ 	lh	$t7,0x0($a3)
/*  f0ff588:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0ff58c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0ff590:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0ff594:	0301001a */ 	div	$zero,$t8,$at
/*  f0ff598:	0000c812 */ 	mflo	$t9
/*  f0ff59c:	a4f90000 */ 	sh	$t9,0x0($a3)
/*  f0ff5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff5a4:	afa40020 */ 	sw	$a0,0x20($sp)
.L0f0ff5a8:
/*  f0ff5a8:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff5ac:	0c002f22 */ 	jal	func0000bc88
/*  f0ff5b0:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff5b4:	0c002f40 */ 	jal	func0000bd00
/*  f0ff5b8:	a7a20024 */ 	sh	$v0,0x24($sp)
/*  f0ff5bc:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0ff5c0:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0ff5c4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff5c8:	87b90024 */ 	lh	$t9,0x24($sp)
/*  f0ff5cc:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ff5d0:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ff5d4:	00007812 */ 	mflo	$t7
/*  f0ff5d8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff5dc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0ff5e0:	00037040 */ 	sll	$t6,$v1,0x1
/*  f0ff5e4:	032e001a */ 	div	$zero,$t9,$t6
/*  f0ff5e8:	00007812 */ 	mflo	$t7
/*  f0ff5ec:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff5f0:	14600002 */ 	bnez	$v1,.L0f0ff5fc
/*  f0ff5f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff5f8:	0007000d */ 	break	0x7
.L0f0ff5fc:
/*  f0ff5fc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ff600:	14610004 */ 	bne	$v1,$at,.L0f0ff614
/*  f0ff604:	3c018000 */ 	lui	$at,0x8000
/*  f0ff608:	14410002 */ 	bne	$v0,$at,.L0f0ff614
/*  f0ff60c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff610:	0006000d */ 	break	0x6
.L0f0ff614:
/*  f0ff614:	15c00002 */ 	bnez	$t6,.L0f0ff620
/*  f0ff618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff61c:	0007000d */ 	break	0x7
.L0f0ff620:
/*  f0ff620:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ff624:	15c10004 */ 	bne	$t6,$at,.L0f0ff638
/*  f0ff628:	3c018000 */ 	lui	$at,0x8000
/*  f0ff62c:	17210002 */ 	bne	$t9,$at,.L0f0ff638
/*  f0ff630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff634:	0006000d */ 	break	0x6
.L0f0ff638:
/*  f0ff638:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f0ff63c:	0c002f26 */ 	jal	func0000bc98
/*  f0ff640:	a4d90000 */ 	sh	$t9,0x0($a2)
/*  f0ff644:	0c002f44 */ 	jal	func0000bd10
/*  f0ff648:	a7a20024 */ 	sh	$v0,0x24($sp)
/*  f0ff64c:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff650:	87af0024 */ 	lh	$t7,0x24($sp)
/*  f0ff654:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff658:	84ee0000 */ 	lh	$t6,0x0($a3)
/*  f0ff65c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff660:	01c2c021 */ 	addu	$t8,$t6,$v0
/*  f0ff664:	05e10003 */ 	bgez	$t7,.L0f0ff674
/*  f0ff668:	000fc843 */ 	sra	$t9,$t7,0x1
/*  f0ff66c:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0ff670:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ff674:
/*  f0ff674:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0ff678:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ff67c:	1481000b */ 	bne	$a0,$at,.L0f0ff6ac
/*  f0ff680:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*  f0ff684:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff688:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ff68c:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff690:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0ff694:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff698:	10620006 */ 	beq	$v1,$v0,.L0f0ff6b4
/*  f0ff69c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff6a0:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f0ff6a4:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f0ff6a8:	106f0002 */ 	beq	$v1,$t7,.L0f0ff6b4
.L0f0ff6ac:
/*  f0ff6ac:	28810003 */ 	slti	$at,$a0,0x3
/*  f0ff6b0:	1420000c */ 	bnez	$at,.L0f0ff6e4
.L0f0ff6b4:
/*  f0ff6b4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x28c)
/*  f0ff6b8:	8f18a24c */ 	lw	$t8,%lo(g_Vars+0x28c)($t8)
/*  f0ff6bc:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0ff6c0:	57200006 */ 	bnezl	$t9,.L0f0ff6dc
/*  f0ff6c4:	84d80000 */ 	lh	$t8,0x0($a2)
/*  f0ff6c8:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ff6cc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ff6d0:	10000004 */ 	beqz	$zero,.L0f0ff6e4
/*  f0ff6d4:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*  f0ff6d8:	84d80000 */ 	lh	$t8,0x0($a2)
.L0f0ff6dc:
/*  f0ff6dc:	2719fff8 */ 	addiu	$t9,$t8,-8
/*  f0ff6e0:	a4d90000 */ 	sh	$t9,0x0($a2)
.L0f0ff6e4:
/*  f0ff6e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ff6e8:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0ff6ec:	03e00008 */ 	jr	$ra
/*  f0ff6f0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff6f4
/*  f0ff6f4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0ff6f8:	3c0e800a */ 	lui	$t6,%hi(var800a21b4)
/*  f0ff6fc:	8dce21b4 */ 	lw	$t6,%lo(var800a21b4)($t6)
/*  f0ff700:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ff704:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0ff708:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0ff70c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0ff710:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0ff714:	3c07800a */ 	lui	$a3,%hi(var800a21b0)
/*  f0ff718:	8ce721b0 */ 	lw	$a3,%lo(var800a21b0)($a3)
/*  f0ff71c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ff720:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f0ff724:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0ff728:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ff72c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ff730:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ff734:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0ff738:	87af0056 */ 	lh	$t7,0x56($sp)
/*  f0ff73c:	87a9005a */ 	lh	$t1,0x5a($sp)
/*  f0ff740:	3c0b800a */ 	lui	$t3,%hi(var800a21b0)
/*  f0ff744:	3c0c800a */ 	lui	$t4,%hi(var800a21b4)
/*  f0ff748:	07010003 */ 	bgez	$t8,.L0f0ff758
/*  f0ff74c:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0ff750:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0ff754:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ff758:
/*  f0ff758:	8d8c21b4 */ 	lw	$t4,%lo(var800a21b4)($t4)
/*  f0ff75c:	8d6b21b0 */ 	lw	$t3,%lo(var800a21b0)($t3)
/*  f0ff760:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f0ff764:	241800f0 */ 	addiu	$t8,$zero,0xf0
/*  f0ff768:	240e0140 */ 	addiu	$t6,$zero,0x140
/*  f0ff76c:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f0ff770:	252afffc */ 	addiu	$t2,$t1,-4
/*  f0ff774:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f0ff778:	afaa0040 */ 	sw	$t2,0x40($sp)
/*  f0ff77c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ff780:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ff784:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ff788:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0ff78c:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0ff790:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff794:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ff798:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ff79c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0ff7a0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ff7a4:	0fc5580f */ 	jal	func0f15603c
/*  f0ff7a8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0ff7ac:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0ff7b0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0ff7b4:	03e00008 */ 	jr	$ra
/*  f0ff7b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff7bc
.late_rodata
glabel var7f1b2ce0
.word 0x3f8ccccd
.text
/*  f0ff7bc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff7c0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff7c4:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0ff7c8:	8d4e006c */ 	lw	$t6,0x6c($t2)
/*  f0ff7cc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0ff7d0:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0ff7d4:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0ff7d8:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f0ff7dc:	11c00003 */ 	beqz	$t6,.L0f0ff7ec
/*  f0ff7e0:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f0ff7e4:	10000002 */ 	beqz	$zero,.L0f0ff7f0
/*  f0ff7e8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff7ec:
/*  f0ff7ec:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ff7f0:
/*  f0ff7f0:	8d4f0068 */ 	lw	$t7,0x68($t2)
/*  f0ff7f4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff7f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff7fc:	11e00003 */ 	beqz	$t7,.L0f0ff80c
/*  f0ff800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff804:	10000001 */ 	beqz	$zero,.L0f0ff80c
/*  f0ff808:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff80c:
/*  f0ff80c:	8d580064 */ 	lw	$t8,0x64($t2)
/*  f0ff810:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff814:	13000003 */ 	beqz	$t8,.L0f0ff824
/*  f0ff818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff81c:	10000001 */ 	beqz	$zero,.L0f0ff824
/*  f0ff820:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff824:
/*  f0ff824:	8d590070 */ 	lw	$t9,0x70($t2)
/*  f0ff828:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ff82c:	13200003 */ 	beqz	$t9,.L0f0ff83c
/*  f0ff830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff834:	10000001 */ 	beqz	$zero,.L0f0ff83c
/*  f0ff838:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ff83c:
/*  f0ff83c:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0ff840:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0ff844:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0ff848:	15a10006 */ 	bne	$t5,$at,.L0f0ff864
/*  f0ff84c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff850:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0ff854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff858:	10400002 */ 	beqz	$v0,.L0f0ff864
/*  f0ff85c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0ff860:	afae0074 */ 	sw	$t6,0x74($sp)
.L0f0ff864:
/*  f0ff864:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff868:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff86c:	8d46006c */ 	lw	$a2,0x6c($t2)
/*  f0ff870:	8d470068 */ 	lw	$a3,0x68($t2)
/*  f0ff874:	8d480064 */ 	lw	$t0,0x64($t2)
/*  f0ff878:	10c00003 */ 	beqz	$a2,.L0f0ff888
/*  f0ff87c:	8d490070 */ 	lw	$t1,0x70($t2)
/*  f0ff880:	10000002 */ 	beqz	$zero,.L0f0ff88c
/*  f0ff884:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff888:
/*  f0ff888:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ff88c:
/*  f0ff88c:	10e00003 */ 	beqz	$a3,.L0f0ff89c
/*  f0ff890:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ff894:	10000002 */ 	beqz	$zero,.L0f0ff8a0
/*  f0ff898:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff89c:
/*  f0ff89c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ff8a0:
/*  f0ff8a0:	11000003 */ 	beqz	$t0,.L0f0ff8b0
/*  f0ff8a4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff8a8:	10000001 */ 	beqz	$zero,.L0f0ff8b0
/*  f0ff8ac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff8b0:
/*  f0ff8b0:	11200003 */ 	beqz	$t1,.L0f0ff8c0
/*  f0ff8b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ff8b8:	10000001 */ 	beqz	$zero,.L0f0ff8c0
/*  f0ff8bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ff8c0:
/*  f0ff8c0:	00437821 */ 	addu	$t7,$v0,$v1
/*  f0ff8c4:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0ff8c8:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0ff8cc:	17210013 */ 	bne	$t9,$at,.L0f0ff91c
/*  f0ff8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff8d4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ff8d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff8dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff8e0:	10410024 */ 	beq	$v0,$at,.L0f0ff974
/*  f0ff8e4:	3c0b8009 */ 	lui	$t3,%hi(g_Is4Mb)
/*  f0ff8e8:	916b0af0 */ 	lbu	$t3,%lo(g_Is4Mb)($t3)
/*  f0ff8ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff8f0:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x6c)
/*  f0ff8f4:	1161001f */ 	beq	$t3,$at,.L0f0ff974
/*  f0ff8f8:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x68)
/*  f0ff8fc:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x64)
/*  f0ff900:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x70)
/*  f0ff904:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff908:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff90c:	8d29a030 */ 	lw	$t1,%lo(g_Vars+0x70)($t1)
/*  f0ff910:	8d08a024 */ 	lw	$t0,%lo(g_Vars+0x64)($t0)
/*  f0ff914:	8cc6a02c */ 	lw	$a2,%lo(g_Vars+0x6c)($a2)
/*  f0ff918:	8ce7a028 */ 	lw	$a3,%lo(g_Vars+0x68)($a3)
.L0f0ff91c:
/*  f0ff91c:	10c00003 */ 	beqz	$a2,.L0f0ff92c
/*  f0ff920:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff924:	10000001 */ 	beqz	$zero,.L0f0ff92c
/*  f0ff928:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff92c:
/*  f0ff92c:	10e00003 */ 	beqz	$a3,.L0f0ff93c
/*  f0ff930:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff934:	10000001 */ 	beqz	$zero,.L0f0ff93c
/*  f0ff938:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff93c:
/*  f0ff93c:	11000003 */ 	beqz	$t0,.L0f0ff94c
/*  f0ff940:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff944:	10000001 */ 	beqz	$zero,.L0f0ff94c
/*  f0ff948:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff94c:
/*  f0ff94c:	11200003 */ 	beqz	$t1,.L0f0ff95c
/*  f0ff950:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ff954:	10000001 */ 	beqz	$zero,.L0f0ff95c
/*  f0ff958:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ff95c:
/*  f0ff95c:	00446021 */ 	addu	$t4,$v0,$a0
/*  f0ff960:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0ff964:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f0ff968:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0ff96c:	1420000c */ 	bnez	$at,.L0f0ff9a0
/*  f0ff970:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ff974:
/*  f0ff974:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff978:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff97c:	8d4f028c */ 	lw	$t7,0x28c($t2)
/*  f0ff980:	24190008 */ 	addiu	$t9,$zero,0x8
/*  f0ff984:	240bfff8 */ 	addiu	$t3,$zero,-8
/*  f0ff988:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0ff98c:	57000004 */ 	bnezl	$t8,.L0f0ff9a0
/*  f0ff990:	afab0078 */ 	sw	$t3,0x78($sp)
/*  f0ff994:	10000002 */ 	beqz	$zero,.L0f0ff9a0
/*  f0ff998:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0ff99c:	afab0078 */ 	sw	$t3,0x78($sp)
.L0f0ff9a0:
/*  f0ff9a0:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuIndex)
/*  f0ff9a4:	8d8c21b8 */ 	lw	$t4,%lo(g_ActiveMenuIndex)($t4)
/*  f0ff9a8:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuThings+0x32)
/*  f0ff9ac:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f0ff9b0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0ff9b4:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0ff9b8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0ff9bc:	91ce2102 */ 	lbu	$t6,%lo(g_ActiveMenuThings+0x32)($t6)
/*  f0ff9c0:	15c00142 */ 	bnez	$t6,.L0f0ffecc
/*  f0ff9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff9c8:	8d4f0284 */ 	lw	$t7,0x284($t2)
/*  f0ff9cc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0ff9d0:	3c0c800b */ 	lui	$t4,%hi(var800ac500)
/*  f0ff9d4:	3c0d800b */ 	lui	$t5,%hi(g_MpPlayerChrs)
/*  f0ff9d8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0ff9dc:	932b1be7 */ 	lbu	$t3,0x1be7($t9)
/*  f0ff9e0:	25adc4d0 */ 	addiu	$t5,$t5,%lo(g_MpPlayerChrs)
/*  f0ff9e4:	000b1080 */ 	sll	$v0,$t3,0x2
/*  f0ff9e8:	01826021 */ 	addu	$t4,$t4,$v0
/*  f0ff9ec:	8d8cc500 */ 	lw	$t4,%lo(var800ac500)($t4)
/*  f0ff9f0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ff9f4:	afae0048 */ 	sw	$t6,0x48($sp)
/*  f0ff9f8:	afab009c */ 	sw	$t3,0x9c($sp)
/*  f0ff9fc:	afac007c */ 	sw	$t4,0x7c($sp)
/*  f0ffa00:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f0ffa04:	8f0302d4 */ 	lw	$v1,0x2d4($t8)
/*  f0ffa08:	50600004 */ 	beqzl	$v1,.L0f0ffa1c
/*  f0ffa0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ffa10:	10000002 */ 	beqz	$zero,.L0f0ffa1c
/*  f0ffa14:	8c640020 */ 	lw	$a0,0x20($v1)
/*  f0ffa18:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ffa1c:
/*  f0ffa1c:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ffa20:	14200003 */ 	bnez	$at,.L0f0ffa30
/*  f0ffa24:	28810033 */ 	slti	$at,$a0,0x33
/*  f0ffa28:	14200005 */ 	bnez	$at,.L0f0ffa40
/*  f0ffa2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ffa30:
/*  f0ffa30:	0fc5b9f1 */ 	jal	langGet
/*  f0ffa34:	240458ad */ 	addiu	$a0,$zero,0x58ad
/*  f0ffa38:	10000004 */ 	beqz	$zero,.L0f0ffa4c
/*  f0ffa3c:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0ffa40:
/*  f0ffa40:	0fc28874 */ 	jal	func0f0a21d0
/*  f0ffa44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffa48:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0ffa4c:
/*  f0ffa4c:	3c19800a */ 	lui	$t9,%hi(var800a21b4)
/*  f0ffa50:	8f3921b4 */ 	lw	$t9,%lo(var800a21b4)($t9)
/*  f0ffa54:	3c07800a */ 	lui	$a3,%hi(var800a21b0)
/*  f0ffa58:	8ce721b0 */ 	lw	$a3,%lo(var800a21b0)($a3)
/*  f0ffa5c:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ffa60:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ffa64:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ffa68:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ffa6c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ffa70:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ffa74:	0c002f40 */ 	jal	func0000bd00
/*  f0ffa78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffa7c:	0c002f22 */ 	jal	func0000bc88
/*  f0ffa80:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f0ffa84:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0ffa88:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0ffa8c:	87ae004e */ 	lh	$t6,0x4e($sp)
/*  f0ffa90:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0ffa94:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ffa98:	00005812 */ 	mflo	$t3
/*  f0ffa9c:	448b2000 */ 	mtc1	$t3,$f4
/*  f0ffaa0:	44998000 */ 	mtc1	$t9,$f16
/*  f0ffaa4:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0ffaa8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ffaac:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ffab0:	44810000 */ 	mtc1	$at,$f0
/*  f0ffab4:	00007812 */ 	mflo	$t7
/*  f0ffab8:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0ffabc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ffac0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ffac4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0ffac8:	14600002 */ 	bnez	$v1,.L0f0ffad4
/*  f0ffacc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffad0:	0007000d */ 	break	0x7
.L0f0ffad4:
/*  f0ffad4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffad8:	14610004 */ 	bne	$v1,$at,.L0f0ffaec
/*  f0ffadc:	3c018000 */ 	lui	$at,0x8000
/*  f0ffae0:	14410002 */ 	bne	$v0,$at,.L0f0ffaec
/*  f0ffae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffae8:	0006000d */ 	break	0x6
.L0f0ffaec:
/*  f0ffaec:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ffaf0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ffaf4:	8cd9006c */ 	lw	$t9,0x6c($a2)
/*  f0ffaf8:	440d5000 */ 	mfc1	$t5,$f10
/*  f0ffafc:	14600002 */ 	bnez	$v1,.L0f0ffb08
/*  f0ffb00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffb04:	0007000d */ 	break	0x7
.L0f0ffb08:
/*  f0ffb08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffb0c:	14610004 */ 	bne	$v1,$at,.L0f0ffb20
/*  f0ffb10:	3c018000 */ 	lui	$at,0x8000
/*  f0ffb14:	15c10002 */ 	bne	$t6,$at,.L0f0ffb20
/*  f0ffb18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffb1c:	0006000d */ 	break	0x6
.L0f0ffb20:
/*  f0ffb20:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ffb24:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0ffb28:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0ffb2c:	440c3000 */ 	mfc1	$t4,$f6
/*  f0ffb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffb34:	030c7023 */ 	subu	$t6,$t8,$t4
/*  f0ffb38:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ffb3c:	13200003 */ 	beqz	$t9,.L0f0ffb4c
/*  f0ffb40:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f0ffb44:	10000002 */ 	beqz	$zero,.L0f0ffb50
/*  f0ffb48:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ffb4c:
/*  f0ffb4c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ffb50:
/*  f0ffb50:	8ccb0068 */ 	lw	$t3,0x68($a2)
/*  f0ffb54:	51600004 */ 	beqzl	$t3,.L0f0ffb68
/*  f0ffb58:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ffb5c:	10000002 */ 	beqz	$zero,.L0f0ffb68
/*  f0ffb60:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ffb64:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ffb68:
/*  f0ffb68:	8cd80064 */ 	lw	$t8,0x64($a2)
/*  f0ffb6c:	53000004 */ 	beqzl	$t8,.L0f0ffb80
/*  f0ffb70:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ffb74:	10000002 */ 	beqz	$zero,.L0f0ffb80
/*  f0ffb78:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0ffb7c:	00001825 */ 	or	$v1,$zero,$zero
.L0f0ffb80:
/*  f0ffb80:	8ccc0070 */ 	lw	$t4,0x70($a2)
/*  f0ffb84:	51800004 */ 	beqzl	$t4,.L0f0ffb98
/*  f0ffb88:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ffb8c:	10000002 */ 	beqz	$zero,.L0f0ffb98
/*  f0ffb90:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ffb94:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ffb98:
/*  f0ffb98:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0ffb9c:	01c46821 */ 	addu	$t5,$t6,$a0
/*  f0ffba0:	01a57821 */ 	addu	$t7,$t5,$a1
/*  f0ffba4:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0ffba8:	14200006 */ 	bnez	$at,.L0f0ffbc4
/*  f0ffbac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbb0:	0c002f44 */ 	jal	func0000bd10
/*  f0ffbb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbb8:	24590005 */ 	addiu	$t9,$v0,0x5
/*  f0ffbbc:	10000005 */ 	beqz	$zero,.L0f0ffbd4
/*  f0ffbc0:	afb90090 */ 	sw	$t9,0x90($sp)
.L0f0ffbc4:
/*  f0ffbc4:	0c002f44 */ 	jal	func0000bd10
/*  f0ffbc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbcc:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f0ffbd0:	afab0090 */ 	sw	$t3,0x90($sp)
.L0f0ffbd4:
/*  f0ffbd4:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ffbd8:	13000012 */ 	beqz	$t8,.L0f0ffc24
/*  f0ffbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbe0:	0c002f40 */ 	jal	func0000bd00
/*  f0ffbe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbe8:	3c0c8008 */ 	lui	$t4,%hi(var8007fac0)
/*  f0ffbec:	8d8cfac0 */ 	lw	$t4,%lo(var8007fac0)($t4)
/*  f0ffbf0:	004c001a */ 	div	$zero,$v0,$t4
/*  f0ffbf4:	00007012 */ 	mflo	$t6
/*  f0ffbf8:	25cd0020 */ 	addiu	$t5,$t6,0x20
/*  f0ffbfc:	afad0094 */ 	sw	$t5,0x94($sp)
/*  f0ffc00:	15800002 */ 	bnez	$t4,.L0f0ffc0c
/*  f0ffc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffc08:	0007000d */ 	break	0x7
.L0f0ffc0c:
/*  f0ffc0c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffc10:	15810004 */ 	bne	$t4,$at,.L0f0ffc24
/*  f0ffc14:	3c018000 */ 	lui	$at,0x8000
/*  f0ffc18:	14410002 */ 	bne	$v0,$at,.L0f0ffc24
/*  f0ffc1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffc20:	0006000d */ 	break	0x6
.L0f0ffc24:
/*  f0ffc24:	3c0f800a */ 	lui	$t7,%hi(var800a21b0)
/*  f0ffc28:	3c19800a */ 	lui	$t9,%hi(var800a21b4)
/*  f0ffc2c:	8f3921b4 */ 	lw	$t9,%lo(var800a21b4)($t9)
/*  f0ffc30:	8def21b0 */ 	lw	$t7,%lo(var800a21b0)($t7)
/*  f0ffc34:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0ffc38:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0ffc3c:	240c0140 */ 	addiu	$t4,$zero,0x140
/*  f0ffc40:	240e00f0 */ 	addiu	$t6,$zero,0xf0
/*  f0ffc44:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0ffc48:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ffc4c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ffc50:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0ffc54:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0ffc58:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ffc5c:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ffc60:	8fa7007c */ 	lw	$a3,0x7c($sp)
/*  f0ffc64:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ffc68:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0ffc6c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ffc70:	0fc55b92 */ 	jal	func0f156e48
/*  f0ffc74:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ffc78:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ffc7c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ffc80:	8d0d006c */ 	lw	$t5,0x6c($t0)
/*  f0ffc84:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0ffc88:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ffc8c:	11a00003 */ 	beqz	$t5,.L0f0ffc9c
/*  f0ffc90:	3c07800a */ 	lui	$a3,%hi(var800a21b0)
/*  f0ffc94:	10000001 */ 	beqz	$zero,.L0f0ffc9c
/*  f0ffc98:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ffc9c:
/*  f0ffc9c:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f0ffca0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ffca4:	11e00003 */ 	beqz	$t7,.L0f0ffcb4
/*  f0ffca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffcac:	10000001 */ 	beqz	$zero,.L0f0ffcb4
/*  f0ffcb0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ffcb4:
/*  f0ffcb4:	8d190064 */ 	lw	$t9,0x64($t0)
/*  f0ffcb8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ffcbc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ffcc0:	13200003 */ 	beqz	$t9,.L0f0ffcd0
/*  f0ffcc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffcc8:	10000001 */ 	beqz	$zero,.L0f0ffcd0
/*  f0ffccc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ffcd0:
/*  f0ffcd0:	8d0b0070 */ 	lw	$t3,0x70($t0)
/*  f0ffcd4:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0ffcd8:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f0ffcdc:	11600003 */ 	beqz	$t3,.L0f0ffcec
/*  f0ffce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffce4:	10000001 */ 	beqz	$zero,.L0f0ffcec
/*  f0ffce8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ffcec:
/*  f0ffcec:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f0ffcf0:	03056021 */ 	addu	$t4,$t8,$a1
/*  f0ffcf4:	01827021 */ 	addu	$t6,$t4,$v0
/*  f0ffcf8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0ffcfc:	14200003 */ 	bnez	$at,.L0f0ffd0c
/*  f0ffd00:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ffd04:	10000009 */ 	beqz	$zero,.L0f0ffd2c
/*  f0ffd08:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ffd0c:
/*  f0ffd0c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0ffd10:	3c017f1b */ 	lui	$at,%hi(var7f1b2ce0)
/*  f0ffd14:	c4302ce0 */ 	lwc1	$f16,%lo(var7f1b2ce0)($at)
/*  f0ffd18:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ffd1c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0ffd20:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0ffd24:	44022000 */ 	mfc1	$v0,$f4
/*  f0ffd28:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ffd2c:
/*  f0ffd2c:	3c18800a */ 	lui	$t8,%hi(var800a21b4)
/*  f0ffd30:	8f1821b4 */ 	lw	$t8,%lo(var800a21b4)($t8)
/*  f0ffd34:	03225821 */ 	addu	$t3,$t9,$v0
/*  f0ffd38:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f0ffd3c:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ffd40:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0ffd44:	8ce721b0 */ 	lw	$a3,%lo(var800a21b0)($a3)
/*  f0ffd48:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ffd4c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ffd50:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ffd54:	0c002f40 */ 	jal	func0000bd00
/*  f0ffd58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffd5c:	0c002f22 */ 	jal	func0000bc88
/*  f0ffd60:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f0ffd64:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0ffd68:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0ffd6c:	87af004e */ 	lh	$t7,0x4e($sp)
/*  f0ffd70:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0ffd74:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ffd78:	00006012 */ 	mflo	$t4
/*  f0ffd7c:	448c3000 */ 	mtc1	$t4,$f6
/*  f0ffd80:	44989000 */ 	mtc1	$t8,$f18
/*  f0ffd84:	01e3001a */ 	div	$zero,$t7,$v1
/*  f0ffd88:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0ffd8c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ffd90:	44810000 */ 	mtc1	$at,$f0
/*  f0ffd94:	14600002 */ 	bnez	$v1,.L0f0ffda0
/*  f0ffd98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffd9c:	0007000d */ 	break	0x7
.L0f0ffda0:
/*  f0ffda0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffda4:	14610004 */ 	bne	$v1,$at,.L0f0ffdb8
/*  f0ffda8:	3c018000 */ 	lui	$at,0x8000
/*  f0ffdac:	14410002 */ 	bne	$v0,$at,.L0f0ffdb8
/*  f0ffdb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffdb4:	0006000d */ 	break	0x6
.L0f0ffdb8:
/*  f0ffdb8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0ffdbc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ffdc0:	0000c812 */ 	mflo	$t9
/*  f0ffdc4:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ffdc8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0ffdcc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0ffdd0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ffdd4:	440d8000 */ 	mfc1	$t5,$f16
/*  f0ffdd8:	14600002 */ 	bnez	$v1,.L0f0ffde4
/*  f0ffddc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffde0:	0007000d */ 	break	0x7
.L0f0ffde4:
/*  f0ffde4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffde8:	14610004 */ 	bne	$v1,$at,.L0f0ffdfc
/*  f0ffdec:	3c018000 */ 	lui	$at,0x8000
/*  f0ffdf0:	15e10002 */ 	bne	$t7,$at,.L0f0ffdfc
/*  f0ffdf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffdf8:	0006000d */ 	break	0x6
.L0f0ffdfc:
/*  f0ffdfc:	440e4000 */ 	mfc1	$t6,$f8
/*  f0ffe00:	01b95821 */ 	addu	$t3,$t5,$t9
/*  f0ffe04:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0ffe08:	016e7823 */ 	subu	$t7,$t3,$t6
/*  f0ffe0c:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f0ffe10:	13000012 */ 	beqz	$t8,.L0f0ffe5c
/*  f0ffe14:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f0ffe18:	0c002f40 */ 	jal	func0000bd00
/*  f0ffe1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffe20:	3c0c8008 */ 	lui	$t4,%hi(var8007fac0)
/*  f0ffe24:	8d8cfac0 */ 	lw	$t4,%lo(var8007fac0)($t4)
/*  f0ffe28:	004c001a */ 	div	$zero,$v0,$t4
/*  f0ffe2c:	00005812 */ 	mflo	$t3
/*  f0ffe30:	256e0020 */ 	addiu	$t6,$t3,0x20
/*  f0ffe34:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f0ffe38:	15800002 */ 	bnez	$t4,.L0f0ffe44
/*  f0ffe3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffe40:	0007000d */ 	break	0x7
.L0f0ffe44:
/*  f0ffe44:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffe48:	15810004 */ 	bne	$t4,$at,.L0f0ffe5c
/*  f0ffe4c:	3c018000 */ 	lui	$at,0x8000
/*  f0ffe50:	14410002 */ 	bne	$v0,$at,.L0f0ffe5c
/*  f0ffe54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffe58:	0006000d */ 	break	0x6
.L0f0ffe5c:
/*  f0ffe5c:	3c0f800a */ 	lui	$t7,%hi(var800a21b0)
/*  f0ffe60:	3c0d800a */ 	lui	$t5,%hi(var800a21b4)
/*  f0ffe64:	8dad21b4 */ 	lw	$t5,%lo(var800a21b4)($t5)
/*  f0ffe68:	8def21b0 */ 	lw	$t7,%lo(var800a21b0)($t7)
/*  f0ffe6c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0ffe70:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0ffe74:	240c0140 */ 	addiu	$t4,$zero,0x140
/*  f0ffe78:	240b00f0 */ 	addiu	$t3,$zero,0xf0
/*  f0ffe7c:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f0ffe80:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ffe84:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ffe88:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ffe8c:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0ffe90:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ffe94:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ffe98:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ffe9c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ffea0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0ffea4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ffea8:	0fc55b92 */ 	jal	func0f156e48
/*  f0ffeac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ffeb0:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ffeb4:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0ffeb8:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x284)
/*  f0ffebc:	8dada244 */ 	lw	$t5,%lo(g_Vars+0x284)($t5)
/*  f0ffec0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f0ffec4:	10000093 */ 	beqz	$zero,.L0f100114
/*  f0ffec8:	adaf1c04 */ 	sw	$t7,0x1c04($t5)
.L0f0ffecc:
/*  f0ffecc:	0fc5b9f1 */ 	jal	langGet
/*  f0ffed0:	240458d7 */ 	addiu	$a0,$zero,0x58d7
/*  f0ffed4:	3c19800a */ 	lui	$t9,%hi(var800a21b4)
/*  f0ffed8:	8f3921b4 */ 	lw	$t9,%lo(var800a21b4)($t9)
/*  f0ffedc:	3c07800a */ 	lui	$a3,%hi(var800a21b0)
/*  f0ffee0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0ffee4:	8ce721b0 */ 	lw	$a3,%lo(var800a21b0)($a3)
/*  f0ffee8:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ffeec:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ffef0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0ffef4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ffef8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ffefc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0fff00:	0c002f40 */ 	jal	func0000bd00
/*  f0fff04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff08:	0c002f22 */ 	jal	func0000bc88
/*  f0fff0c:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f0fff10:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0fff14:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0fff18:	87ae004e */ 	lh	$t6,0x4e($sp)
/*  f0fff1c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0fff20:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fff24:	0000c012 */ 	mflo	$t8
/*  f0fff28:	44985000 */ 	mtc1	$t8,$f10
/*  f0fff2c:	14600002 */ 	bnez	$v1,.L0f0fff38
/*  f0fff30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff34:	0007000d */ 	break	0x7
.L0f0fff38:
/*  f0fff38:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fff3c:	14610004 */ 	bne	$v1,$at,.L0f0fff50
/*  f0fff40:	3c018000 */ 	lui	$at,0x8000
/*  f0fff44:	14410002 */ 	bne	$v0,$at,.L0f0fff50
/*  f0fff48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff4c:	0006000d */ 	break	0x6
.L0f0fff50:
/*  f0fff50:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0fff54:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0fff58:	3c013f00 */ 	lui	$at,0x3f00
/*  f0fff5c:	44819000 */ 	mtc1	$at,$f18
/*  f0fff60:	44994000 */ 	mtc1	$t9,$f8
/*  f0fff64:	00007812 */ 	mflo	$t7
/*  f0fff68:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x6c)
/*  f0fff6c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0fff70:	8f39a02c */ 	lw	$t9,%lo(g_Vars+0x6c)($t9)
/*  f0fff74:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x68)
/*  f0fff78:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fff7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fff80:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0fff84:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0fff88:	440b3000 */ 	mfc1	$t3,$f6
/*  f0fff8c:	14600002 */ 	bnez	$v1,.L0f0fff98
/*  f0fff90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff94:	0007000d */ 	break	0x7
.L0f0fff98:
/*  f0fff98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fff9c:	14610004 */ 	bne	$v1,$at,.L0f0fffb0
/*  f0fffa0:	3c018000 */ 	lui	$at,0x8000
/*  f0fffa4:	15c10002 */ 	bne	$t6,$at,.L0f0fffb0
/*  f0fffa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fffac:	0006000d */ 	break	0x6
.L0f0fffb0:
/*  f0fffb0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0fffb4:	44818000 */ 	mtc1	$at,$f16
/*  f0fffb8:	016f6821 */ 	addu	$t5,$t3,$t7
/*  f0fffbc:	8fab0078 */ 	lw	$t3,0x78($sp)
/*  f0fffc0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0fffc4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0fffc8:	440c2000 */ 	mfc1	$t4,$f4
/*  f0fffcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fffd0:	01ac7023 */ 	subu	$t6,$t5,$t4
/*  f0fffd4:	01cb7821 */ 	addu	$t7,$t6,$t3
/*  f0fffd8:	13200003 */ 	beqz	$t9,.L0f0fffe8
/*  f0fffdc:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f0fffe0:	10000001 */ 	beqz	$zero,.L0f0fffe8
/*  f0fffe4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fffe8:
/*  f0fffe8:	8f18a028 */ 	lw	$t8,%lo(g_Vars+0x68)($t8)
/*  f0fffec:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x64)
/*  f0ffff0:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x70)
/*  f0ffff4:	13000003 */ 	beqz	$t8,.L0f100004
/*  f0ffff8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ffffc:	10000001 */ 	beqz	$zero,.L0f100004
/*  f100000:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f100004:
/*  f100004:	8dada024 */ 	lw	$t5,%lo(g_Vars+0x64)($t5)
/*  f100008:	00001025 */ 	or	$v0,$zero,$zero
/*  f10000c:	11a00003 */ 	beqz	$t5,.L0f10001c
/*  f100010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100014:	10000001 */ 	beqz	$zero,.L0f10001c
/*  f100018:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10001c:
/*  f10001c:	8d8ca030 */ 	lw	$t4,%lo(g_Vars+0x70)($t4)
/*  f100020:	11800003 */ 	beqz	$t4,.L0f100030
/*  f100024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100028:	10000001 */ 	beqz	$zero,.L0f100030
/*  f10002c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f100030:
/*  f100030:	00437021 */ 	addu	$t6,$v0,$v1
/*  f100034:	01c45821 */ 	addu	$t3,$t6,$a0
/*  f100038:	01657821 */ 	addu	$t7,$t3,$a1
/*  f10003c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f100040:	14200006 */ 	bnez	$at,.L0f10005c
/*  f100044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100048:	0c002f44 */ 	jal	func0000bd10
/*  f10004c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100050:	24590005 */ 	addiu	$t9,$v0,0x5
/*  f100054:	10000005 */ 	beqz	$zero,.L0f10006c
/*  f100058:	afb90090 */ 	sw	$t9,0x90($sp)
.L0f10005c:
/*  f10005c:	0c002f44 */ 	jal	func0000bd10
/*  f100060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100064:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f100068:	afb80090 */ 	sw	$t8,0x90($sp)
.L0f10006c:
/*  f10006c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f100070:	11a00012 */ 	beqz	$t5,.L0f1000bc
/*  f100074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100078:	0c002f40 */ 	jal	func0000bd00
/*  f10007c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100080:	3c0c8008 */ 	lui	$t4,%hi(var8007fac0)
/*  f100084:	8d8cfac0 */ 	lw	$t4,%lo(var8007fac0)($t4)
/*  f100088:	004c001a */ 	div	$zero,$v0,$t4
/*  f10008c:	00007012 */ 	mflo	$t6
/*  f100090:	25cb0020 */ 	addiu	$t3,$t6,0x20
/*  f100094:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f100098:	15800002 */ 	bnez	$t4,.L0f1000a4
/*  f10009c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1000a0:	0007000d */ 	break	0x7
.L0f1000a4:
/*  f1000a4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1000a8:	15810004 */ 	bne	$t4,$at,.L0f1000bc
/*  f1000ac:	3c018000 */ 	lui	$at,0x8000
/*  f1000b0:	14410002 */ 	bne	$v0,$at,.L0f1000bc
/*  f1000b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1000b8:	0006000d */ 	break	0x6
.L0f1000bc:
/*  f1000bc:	3c0f800a */ 	lui	$t7,%hi(var800a21b0)
/*  f1000c0:	3c19800a */ 	lui	$t9,%hi(var800a21b4)
/*  f1000c4:	8f3921b4 */ 	lw	$t9,%lo(var800a21b4)($t9)
/*  f1000c8:	8def21b0 */ 	lw	$t7,%lo(var800a21b0)($t7)
/*  f1000cc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f1000d0:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f1000d4:	240c0140 */ 	addiu	$t4,$zero,0x140
/*  f1000d8:	240e00f0 */ 	addiu	$t6,$zero,0xf0
/*  f1000dc:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f1000e0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f1000e4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1000e8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1000ec:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f1000f0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1000f4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1000f8:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f1000fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f100100:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f100104:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f100108:	0fc55b92 */ 	jal	func0f156e48
/*  f10010c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f100110:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f100114:
/*  f100114:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f100118:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f10011c:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f100120:	03e00008 */ 	jr	$ra
/*  f100124:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f100128
/*  f100128:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f10012c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f100130:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f100134:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f100138:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f10013c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f100140:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f100144:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f100148:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f10014c:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f100150:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f100154:	11c00003 */ 	beqz	$t6,.L0f100164
/*  f100158:	240a0006 */ 	addiu	$t2,$zero,0x6
/*  f10015c:	10000002 */ 	beqz	$zero,.L0f100168
/*  f100160:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f100164:
/*  f100164:	00002825 */ 	or	$a1,$zero,$zero
.L0f100168:
/*  f100168:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f10016c:	00001825 */ 	or	$v1,$zero,$zero
/*  f100170:	00002025 */ 	or	$a0,$zero,$zero
/*  f100174:	11e00003 */ 	beqz	$t7,.L0f100184
/*  f100178:	00001025 */ 	or	$v0,$zero,$zero
/*  f10017c:	10000001 */ 	beqz	$zero,.L0f100184
/*  f100180:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f100184:
/*  f100184:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f100188:	13000003 */ 	beqz	$t8,.L0f100198
/*  f10018c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100190:	10000001 */ 	beqz	$zero,.L0f100198
/*  f100194:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f100198:
/*  f100198:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f10019c:	13200003 */ 	beqz	$t9,.L0f1001ac
/*  f1001a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1001a4:	10000001 */ 	beqz	$zero,.L0f1001ac
/*  f1001a8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1001ac:
/*  f1001ac:	00447021 */ 	addu	$t6,$v0,$a0
/*  f1001b0:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f1001b4:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1001b8:	2b010002 */ 	slti	$at,$t8,0x2
/*  f1001bc:	14200003 */ 	bnez	$at,.L0f1001cc
/*  f1001c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1001c4:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f1001c8:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0f1001cc:
/*  f1001cc:	12000008 */ 	beqz	$s0,.L0f1001f0
/*  f1001d0:	3c057f1b */ 	lui	$a1,%hi(var7f1b2c54)
/*  f1001d4:	24a52c54 */ 	addiu	$a1,$a1,%lo(var7f1b2c54)
/*  f1001d8:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f1001dc:	afaa0064 */ 	sw	$t2,0x64($sp)
/*  f1001e0:	0c004c9d */ 	jal	func00013274
/*  f1001e4:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f1001e8:	14400003 */ 	bnez	$v0,.L0f1001f8
/*  f1001ec:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c58)
.L0f1001f0:
/*  f1001f0:	10000232 */ 	beqz	$zero,.L0f100abc
/*  f1001f4:	8fa20070 */ 	lw	$v0,0x70($sp)
.L0f1001f8:
/*  f1001f8:	3c058007 */ 	lui	$a1,%hi(var800719ac)
/*  f1001fc:	24a519ac */ 	addiu	$a1,$a1,%lo(var800719ac)
/*  f100200:	0c0036cc */ 	jal	func0000db30
/*  f100204:	24842c58 */ 	addiu	$a0,$a0,%lo(var7f1b2c58)
/*  f100208:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c60)
/*  f10020c:	3c058007 */ 	lui	$a1,%hi(var800719b0)
/*  f100210:	24a519b0 */ 	addiu	$a1,$a1,%lo(var800719b0)
/*  f100214:	0c0036cc */ 	jal	func0000db30
/*  f100218:	24842c60 */ 	addiu	$a0,$a0,%lo(var7f1b2c60)
/*  f10021c:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c68)
/*  f100220:	3c058007 */ 	lui	$a1,%hi(var800719b4)
/*  f100224:	24a519b4 */ 	addiu	$a1,$a1,%lo(var800719b4)
/*  f100228:	0c0036cc */ 	jal	func0000db30
/*  f10022c:	24842c68 */ 	addiu	$a0,$a0,%lo(var7f1b2c68)
/*  f100230:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c70)
/*  f100234:	3c058007 */ 	lui	$a1,%hi(var800719b8)
/*  f100238:	24a519b8 */ 	addiu	$a1,$a1,%lo(var800719b8)
/*  f10023c:	0c0036cc */ 	jal	func0000db30
/*  f100240:	24842c70 */ 	addiu	$a0,$a0,%lo(var7f1b2c70)
/*  f100244:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c78)
/*  f100248:	3c058007 */ 	lui	$a1,%hi(var800719bc)
/*  f10024c:	24a519bc */ 	addiu	$a1,$a1,%lo(var800719bc)
/*  f100250:	0c0036cc */ 	jal	func0000db30
/*  f100254:	24842c78 */ 	addiu	$a0,$a0,%lo(var7f1b2c78)
/*  f100258:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c80)
/*  f10025c:	3c058007 */ 	lui	$a1,%hi(var800719c0)
/*  f100260:	24a519c0 */ 	addiu	$a1,$a1,%lo(var800719c0)
/*  f100264:	0c0036cc */ 	jal	func0000db30
/*  f100268:	24842c80 */ 	addiu	$a0,$a0,%lo(var7f1b2c80)
/*  f10026c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f100270:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f100274:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f100278:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f10027c:	3c028007 */ 	lui	$v0,%hi(var800719b0)
/*  f100280:	03290019 */ 	multu	$t9,$t1
/*  f100284:	8c4219b0 */ 	lw	$v0,%lo(var800719b0)($v0)
/*  f100288:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f10028c:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f100290:	305800ff */ 	andi	$t8,$v0,0xff
/*  f100294:	44983000 */ 	mtc1	$t8,$f6
/*  f100298:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f10029c:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f1002a0:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f1002a4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1002a8:	00007012 */ 	mflo	$t6
/*  f1002ac:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f1002b0:	07010005 */ 	bgez	$t8,.L0f1002c8
/*  f1002b4:	c5e40018 */ 	lwc1	$f4,0x18($t7)
/*  f1002b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1002bc:	44815000 */ 	mtc1	$at,$f10
/*  f1002c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1002c4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1002c8:
/*  f1002c8:	46082402 */ 	mul.s	$f16,$f4,$f8
/*  f1002cc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1002d0:	4459f800 */ 	cfc1	$t9,$31
/*  f1002d4:	44cef800 */ 	ctc1	$t6,$31
/*  f1002d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1002dc:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f1002e0:	444ef800 */ 	cfc1	$t6,$31
/*  f1002e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1002e8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1002ec:	11c00012 */ 	beqz	$t6,.L0f100338
/*  f1002f0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1002f4:	44819000 */ 	mtc1	$at,$f18
/*  f1002f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1002fc:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f100300:	44cef800 */ 	ctc1	$t6,$31
/*  f100304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100308:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f10030c:	444ef800 */ 	cfc1	$t6,$31
/*  f100310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100314:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f100318:	15c00005 */ 	bnez	$t6,.L0f100330
/*  f10031c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100320:	440e9000 */ 	mfc1	$t6,$f18
/*  f100324:	3c018000 */ 	lui	$at,0x8000
/*  f100328:	10000007 */ 	beqz	$zero,.L0f100348
/*  f10032c:	01c17025 */ 	or	$t6,$t6,$at
.L0f100330:
/*  f100330:	10000005 */ 	beqz	$zero,.L0f100348
/*  f100334:	240effff */ 	addiu	$t6,$zero,-1
.L0f100338:
/*  f100338:	440e9000 */ 	mfc1	$t6,$f18
/*  f10033c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100340:	05c0fffb */ 	bltz	$t6,.L0f100330
/*  f100344:	00000000 */ 	sll	$zero,$zero,0x0
.L0f100348:
/*  f100348:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f10034c:	00417824 */ 	and	$t7,$v0,$at
/*  f100350:	44d9f800 */ 	ctc1	$t9,$31
/*  f100354:	24010001 */ 	addiu	$at,$zero,0x1
/*  f100358:	14610003 */ 	bne	$v1,$at,.L0f100368
/*  f10035c:	01cf8025 */ 	or	$s0,$t6,$t7
/*  f100360:	321800ff */ 	andi	$t8,$s0,0xff
/*  f100364:	03008025 */ 	or	$s0,$t8,$zero
.L0f100368:
/*  f100368:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f10036c:	10620004 */ 	beq	$v1,$v0,.L0f100380
/*  f100370:	31780010 */ 	andi	$t8,$t3,0x10
/*  f100374:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f100378:	332e0002 */ 	andi	$t6,$t9,0x2
/*  f10037c:	11c00002 */ 	beqz	$t6,.L0f100388
.L0f100380:
/*  f100380:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f100384:	01e08025 */ 	or	$s0,$t7,$zero
.L0f100388:
/*  f100388:	13000003 */ 	beqz	$t8,.L0f100398
/*  f10038c:	03005825 */ 	or	$t3,$t8,$zero
/*  f100390:	321900ff */ 	andi	$t9,$s0,0xff
/*  f100394:	03208025 */ 	or	$s0,$t9,$zero
.L0f100398:
/*  f100398:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f10039c:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f1003a0:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f1003a4:	544f0003 */ 	bnel	$v0,$t7,.L0f1003b4
/*  f1003a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1003ac:	2410006f */ 	addiu	$s0,$zero,0x6f
/*  f1003b0:	02002825 */ 	or	$a1,$s0,$zero
.L0f1003b4:
/*  f1003b4:	0fc54df7 */ 	jal	func0f1537dc
/*  f1003b8:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f1003bc:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1003c0:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1003c4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1003c8:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1003cc:	87b0007e */ 	lh	$s0,0x7e($sp)
/*  f1003d0:	01c90019 */ 	multu	$t6,$t1
/*  f1003d4:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f1003d8:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1003dc:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1003e0:	02182821 */ 	addu	$a1,$s0,$t8
/*  f1003e4:	30a603ff */ 	andi	$a2,$a1,0x3ff
/*  f1003e8:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f1003ec:	03203025 */ 	or	$a2,$t9,$zero
/*  f1003f0:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f1003f4:	87bf007a */ 	lh	$ra,0x7a($sp)
/*  f1003f8:	00007812 */ 	mflo	$t7
/*  f1003fc:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f100400:	87190004 */ 	lh	$t9,0x4($t8)
/*  f100404:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f100408:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f10040c:	3c0cf600 */ 	lui	$t4,0xf600
/*  f100410:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f100414:	07210003 */ 	bgez	$t9,.L0f100424
/*  f100418:	00197043 */ 	sra	$t6,$t9,0x1
/*  f10041c:	27210001 */ 	addiu	$at,$t9,0x1
/*  f100420:	00017043 */ 	sra	$t6,$at,0x1
.L0f100424:
/*  f100424:	01df7821 */ 	addu	$t7,$t6,$ra
/*  f100428:	01f80019 */ 	multu	$t7,$t8
/*  f10042c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f100430:	0000c812 */ 	mflo	$t9
/*  f100434:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f100438:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f10043c:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f100440:	0306c825 */ 	or	$t9,$t8,$a2
/*  f100444:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f100448:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f10044c:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f100450:	03290019 */ 	multu	$t9,$t1
/*  f100454:	020e6823 */ 	subu	$t5,$s0,$t6
/*  f100458:	25aa0001 */ 	addiu	$t2,$t5,0x1
/*  f10045c:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f100460:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f100464:	00007012 */ 	mflo	$t6
/*  f100468:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f10046c:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f100470:	07010003 */ 	bgez	$t8,.L0f100480
/*  f100474:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f100478:	27010001 */ 	addiu	$at,$t8,0x1
/*  f10047c:	0001c843 */ 	sra	$t9,$at,0x1
.L0f100480:
/*  f100480:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f100484:	03f97023 */ 	subu	$t6,$ra,$t9
/*  f100488:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10048c:	01f80019 */ 	multu	$t7,$t8
/*  f100490:	0000c812 */ 	mflo	$t9
/*  f100494:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f100498:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f10049c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f1004a0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1004a4:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f1004a8:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f1004ac:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f1004b0:	0fc54e0e */ 	jal	func0f153838
/*  f1004b4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f1004b8:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f1004bc:	3c048007 */ 	lui	$a0,%hi(var800719ac)
/*  f1004c0:	8c8419ac */ 	lw	$a0,%lo(var800719ac)($a0)
/*  f1004c4:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1004c8:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1004cc:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1004d0:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1004d4:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f1004d8:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1004dc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f1004e0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f1004e4:	11600002 */ 	beqz	$t3,.L0f1004f0
/*  f1004e8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1004ec:	309000ff */ 	andi	$s0,$a0,0xff
.L0f1004f0:
/*  f1004f0:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f1004f4:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1004f8:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f1004fc:	53220006 */ 	beql	$t9,$v0,.L0f100518
/*  f100500:	2410ff8f */ 	addiu	$s0,$zero,-113
/*  f100504:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f100508:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f10050c:	51e00003 */ 	beqzl	$t7,.L0f10051c
/*  f100510:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f100514:	2410ff8f */ 	addiu	$s0,$zero,-113
.L0f100518:
/*  f100518:	8d180000 */ 	lw	$t8,0x0($t0)
.L0f10051c:
/*  f10051c:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f100520:	448f5000 */ 	mtc1	$t7,$f10
/*  f100524:	03090019 */ 	multu	$t8,$t1
/*  f100528:	3c014f80 */ 	lui	$at,0x4f80
/*  f10052c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f100530:	0000c812 */ 	mflo	$t9
/*  f100534:	00f97021 */ 	addu	$t6,$a3,$t9
/*  f100538:	05e10004 */ 	bgez	$t7,.L0f10054c
/*  f10053c:	c5c60018 */ 	lwc1	$f6,0x18($t6)
/*  f100540:	44814000 */ 	mtc1	$at,$f8
/*  f100544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100548:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f10054c:
/*  f10054c:	46043402 */ 	mul.s	$f16,$f6,$f4
/*  f100550:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100554:	3c014f00 */ 	lui	$at,0x4f00
/*  f100558:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f10055c:	4458f800 */ 	cfc1	$t8,$31
/*  f100560:	44d9f800 */ 	ctc1	$t9,$31
/*  f100564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100568:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f10056c:	4459f800 */ 	cfc1	$t9,$31
/*  f100570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100574:	33390078 */ 	andi	$t9,$t9,0x78
/*  f100578:	53200013 */ 	beqzl	$t9,.L0f1005c8
/*  f10057c:	44199000 */ 	mfc1	$t9,$f18
/*  f100580:	44819000 */ 	mtc1	$at,$f18
/*  f100584:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100588:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f10058c:	44d9f800 */ 	ctc1	$t9,$31
/*  f100590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100594:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f100598:	4459f800 */ 	cfc1	$t9,$31
/*  f10059c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1005a0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f1005a4:	17200005 */ 	bnez	$t9,.L0f1005bc
/*  f1005a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1005ac:	44199000 */ 	mfc1	$t9,$f18
/*  f1005b0:	3c018000 */ 	lui	$at,0x8000
/*  f1005b4:	10000007 */ 	beqz	$zero,.L0f1005d4
/*  f1005b8:	0321c825 */ 	or	$t9,$t9,$at
.L0f1005bc:
/*  f1005bc:	10000005 */ 	beqz	$zero,.L0f1005d4
/*  f1005c0:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1005c4:	44199000 */ 	mfc1	$t9,$f18
.L0f1005c8:
/*  f1005c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1005cc:	0720fffb */ 	bltz	$t9,.L0f1005bc
/*  f1005d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1005d4:
/*  f1005d4:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f1005d8:	44d8f800 */ 	ctc1	$t8,$31
/*  f1005dc:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1005e0:	91f80250 */ 	lbu	$t8,0x250($t7)
/*  f1005e4:	02017024 */ 	and	$t6,$s0,$at
/*  f1005e8:	032e8025 */ 	or	$s0,$t9,$t6
/*  f1005ec:	54580004 */ 	bnel	$v0,$t8,.L0f100600
/*  f1005f0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1005f4:	3c104f4f */ 	lui	$s0,0x4f4f
/*  f1005f8:	36104f7f */ 	ori	$s0,$s0,0x4f7f
/*  f1005fc:	02002825 */ 	or	$a1,$s0,$zero
.L0f100600:
/*  f100600:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f100604:	0fc54df7 */ 	jal	func0f1537dc
/*  f100608:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f10060c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f100610:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f100614:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f100618:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f10061c:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f100620:	03290019 */ 	multu	$t9,$t1
/*  f100624:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f100628:	87ab007a */ 	lh	$t3,0x7a($sp)
/*  f10062c:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f100630:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f100634:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f100638:	3c0cf600 */ 	lui	$t4,0xf600
/*  f10063c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f100640:	24450018 */ 	addiu	$a1,$v0,0x18
/*  f100644:	24440020 */ 	addiu	$a0,$v0,0x20
/*  f100648:	00007012 */ 	mflo	$t6
/*  f10064c:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f100650:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f100654:	07010003 */ 	bgez	$t8,.L0f100664
/*  f100658:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f10065c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f100660:	0001c843 */ 	sra	$t9,$at,0x1
.L0f100664:
/*  f100664:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f100668:	032b7021 */ 	addu	$t6,$t9,$t3
/*  f10066c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f100670:	01f80019 */ 	multu	$t7,$t8
/*  f100674:	0000c812 */ 	mflo	$t9
/*  f100678:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10067c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f100680:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f100684:	030ac825 */ 	or	$t9,$t8,$t2
/*  f100688:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f10068c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f100690:	01c90019 */ 	multu	$t6,$t1
/*  f100694:	00007812 */ 	mflo	$t7
/*  f100698:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f10069c:	87190004 */ 	lh	$t9,0x4($t8)
/*  f1006a0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f1006a4:	07210003 */ 	bgez	$t9,.L0f1006b4
/*  f1006a8:	00197043 */ 	sra	$t6,$t9,0x1
/*  f1006ac:	27210001 */ 	addiu	$at,$t9,0x1
/*  f1006b0:	00017043 */ 	sra	$t6,$at,0x1
.L0f1006b4:
/*  f1006b4:	016e7823 */ 	subu	$t7,$t3,$t6
/*  f1006b8:	01f80019 */ 	multu	$t7,$t8
/*  f1006bc:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*  f1006c0:	0000c812 */ 	mflo	$t9
/*  f1006c4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1006c8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1006cc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1006d0:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1006d4:	01eec025 */ 	or	$t8,$t7,$t6
/*  f1006d8:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1006dc:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f1006e0:	03290019 */ 	multu	$t9,$t1
/*  f1006e4:	00007812 */ 	mflo	$t7
/*  f1006e8:	00ef7021 */ 	addu	$t6,$a3,$t7
/*  f1006ec:	85d80004 */ 	lh	$t8,0x4($t6)
/*  f1006f0:	07010003 */ 	bgez	$t8,.L0f100700
/*  f1006f4:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f1006f8:	27010001 */ 	addiu	$at,$t8,0x1
/*  f1006fc:	0001c843 */ 	sra	$t9,$at,0x1
.L0f100700:
/*  f100700:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f100704:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f100708:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f10070c:	01d80019 */ 	multu	$t6,$t8
/*  f100710:	0000c812 */ 	mflo	$t9
/*  f100714:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f100718:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f10071c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f100720:	01ccc025 */ 	or	$t8,$t6,$t4
/*  f100724:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f100728:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f10072c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f100730:	03197825 */ 	or	$t7,$t8,$t9
/*  f100734:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f100738:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f10073c:	01c90019 */ 	multu	$t6,$t1
/*  f100740:	0000c012 */ 	mflo	$t8
/*  f100744:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f100748:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f10074c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f100750:	05e10003 */ 	bgez	$t7,.L0f100760
/*  f100754:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f100758:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f10075c:	00017043 */ 	sra	$t6,$at,0x1
.L0f100760:
/*  f100760:	016ec023 */ 	subu	$t8,$t3,$t6
/*  f100764:	03190019 */ 	multu	$t8,$t9
/*  f100768:	00007812 */ 	mflo	$t7
/*  f10076c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100770:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f100774:	0306c825 */ 	or	$t9,$t8,$a2
/*  f100778:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f10077c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f100780:	01e90019 */ 	multu	$t7,$t1
/*  f100784:	00007012 */ 	mflo	$t6
/*  f100788:	00eec021 */ 	addu	$t8,$a3,$t6
/*  f10078c:	87190004 */ 	lh	$t9,0x4($t8)
/*  f100790:	07210003 */ 	bgez	$t9,.L0f1007a0
/*  f100794:	00197843 */ 	sra	$t7,$t9,0x1
/*  f100798:	27210001 */ 	addiu	$at,$t9,0x1
/*  f10079c:	00017843 */ 	sra	$t7,$at,0x1
.L0f1007a0:
/*  f1007a0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f1007a4:	016f7023 */ 	subu	$t6,$t3,$t7
/*  f1007a8:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f1007ac:	03190019 */ 	multu	$t8,$t9
/*  f1007b0:	00007812 */ 	mflo	$t7
/*  f1007b4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1007b8:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f1007bc:	030cc825 */ 	or	$t9,$t8,$t4
/*  f1007c0:	03267825 */ 	or	$t7,$t9,$a2
/*  f1007c4:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f1007c8:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1007cc:	01c90019 */ 	multu	$t6,$t1
/*  f1007d0:	0000c012 */ 	mflo	$t8
/*  f1007d4:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1007d8:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f1007dc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f1007e0:	05e10003 */ 	bgez	$t7,.L0f1007f0
/*  f1007e4:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f1007e8:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f1007ec:	00017043 */ 	sra	$t6,$at,0x1
.L0f1007f0:
/*  f1007f0:	016ec023 */ 	subu	$t8,$t3,$t6
/*  f1007f4:	03190019 */ 	multu	$t8,$t9
/*  f1007f8:	00007812 */ 	mflo	$t7
/*  f1007fc:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100800:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f100804:	030ac825 */ 	or	$t9,$t8,$t2
/*  f100808:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f10080c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f100810:	01e90019 */ 	multu	$t7,$t1
/*  f100814:	00007012 */ 	mflo	$t6
/*  f100818:	00eec021 */ 	addu	$t8,$a3,$t6
/*  f10081c:	87190004 */ 	lh	$t9,0x4($t8)
/*  f100820:	07210003 */ 	bgez	$t9,.L0f100830
/*  f100824:	00197843 */ 	sra	$t7,$t9,0x1
/*  f100828:	27210001 */ 	addiu	$at,$t9,0x1
/*  f10082c:	00017843 */ 	sra	$t7,$at,0x1
.L0f100830:
/*  f100830:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f100834:	01eb7021 */ 	addu	$t6,$t7,$t3
/*  f100838:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f10083c:	03190019 */ 	multu	$t8,$t9
/*  f100840:	00007812 */ 	mflo	$t7
/*  f100844:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100848:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f10084c:	030cc825 */ 	or	$t9,$t8,$t4
/*  f100850:	03267825 */ 	or	$t7,$t9,$a2
/*  f100854:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f100858:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f10085c:	01c90019 */ 	multu	$t6,$t1
/*  f100860:	0000c012 */ 	mflo	$t8
/*  f100864:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f100868:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f10086c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f100870:	05e10003 */ 	bgez	$t7,.L0f100880
/*  f100874:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f100878:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f10087c:	00017043 */ 	sra	$t6,$at,0x1
.L0f100880:
/*  f100880:	01cbc021 */ 	addu	$t8,$t6,$t3
/*  f100884:	03190019 */ 	multu	$t8,$t9
/*  f100888:	00007812 */ 	mflo	$t7
/*  f10088c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100890:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f100894:	030ac825 */ 	or	$t9,$t8,$t2
/*  f100898:	0fc54e0e */ 	jal	func0f153838
/*  f10089c:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1008a0:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f1008a4:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1008a8:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1008ac:	3c108007 */ 	lui	$s0,%hi(var800719b4)
/*  f1008b0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1008b4:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1008b8:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1008bc:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1008c0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f1008c4:	11e10005 */ 	beq	$t7,$at,.L0f1008dc
/*  f1008c8:	8e1019b4 */ 	lw	$s0,%lo(var800719b4)($s0)
/*  f1008cc:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f1008d0:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f1008d4:	53000003 */ 	beqzl	$t8,.L0f1008e4
/*  f1008d8:	8fb90084 */ 	lw	$t9,0x84($sp)
.L0f1008dc:
/*  f1008dc:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f1008e0:	8fb90084 */ 	lw	$t9,0x84($sp)
.L0f1008e4:
/*  f1008e4:	3c014120 */ 	lui	$at,0x4120
/*  f1008e8:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f1008ec:	51e00034 */ 	beqzl	$t7,.L0f1009c0
/*  f1008f0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1008f4:	44816000 */ 	mtc1	$at,$f12
/*  f1008f8:	0fc01ad5 */ 	jal	func0f006b54
/*  f1008fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100900:	3c01437f */ 	lui	$at,0x437f
/*  f100904:	44815000 */ 	mtc1	$at,$f10
/*  f100908:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10090c:	3c04ffaf */ 	lui	$a0,0xffaf
/*  f100910:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f100914:	34848fff */ 	ori	$a0,$a0,0x8fff
/*  f100918:	3c014f00 */ 	lui	$at,0x4f00
/*  f10091c:	02002825 */ 	or	$a1,$s0,$zero
/*  f100920:	444ef800 */ 	cfc1	$t6,$31
/*  f100924:	44c6f800 */ 	ctc1	$a2,$31
/*  f100928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10092c:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f100930:	4446f800 */ 	cfc1	$a2,$31
/*  f100934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100938:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f10093c:	50c00013 */ 	beqzl	$a2,.L0f10098c
/*  f100940:	44063000 */ 	mfc1	$a2,$f6
/*  f100944:	44813000 */ 	mtc1	$at,$f6
/*  f100948:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10094c:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f100950:	44c6f800 */ 	ctc1	$a2,$31
/*  f100954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100958:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f10095c:	4446f800 */ 	cfc1	$a2,$31
/*  f100960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100964:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f100968:	14c00005 */ 	bnez	$a2,.L0f100980
/*  f10096c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100970:	44063000 */ 	mfc1	$a2,$f6
/*  f100974:	3c018000 */ 	lui	$at,0x8000
/*  f100978:	10000007 */ 	beqz	$zero,.L0f100998
/*  f10097c:	00c13025 */ 	or	$a2,$a2,$at
.L0f100980:
/*  f100980:	10000005 */ 	beqz	$zero,.L0f100998
/*  f100984:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f100988:	44063000 */ 	mfc1	$a2,$f6
.L0f10098c:
/*  f10098c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100990:	04c0fffb */ 	bltz	$a2,.L0f100980
/*  f100994:	00000000 */ 	sll	$zero,$zero,0x0
.L0f100998:
/*  f100998:	44cef800 */ 	ctc1	$t6,$31
/*  f10099c:	0fc01a40 */ 	jal	func0f006900
/*  f1009a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1009a4:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1009a8:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1009ac:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1009b0:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1009b4:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1009b8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1009bc:	8d180000 */ 	lw	$t8,0x0($t0)
.L0f1009c0:
/*  f1009c0:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f1009c4:	448e8000 */ 	mtc1	$t6,$f16
/*  f1009c8:	03090019 */ 	multu	$t8,$t1
/*  f1009cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1009d0:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f1009d4:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f1009d8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1009dc:	0000c812 */ 	mflo	$t9
/*  f1009e0:	00f97821 */ 	addu	$t7,$a3,$t9
/*  f1009e4:	05c10004 */ 	bgez	$t6,.L0f1009f8
/*  f1009e8:	c5e40018 */ 	lwc1	$f4,0x18($t7)
/*  f1009ec:	44815000 */ 	mtc1	$at,$f10
/*  f1009f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1009f4:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f1009f8:
/*  f1009f8:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f1009fc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100a00:	3c014f00 */ 	lui	$at,0x4f00
/*  f100a04:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f100a08:	87a7007a */ 	lh	$a3,0x7a($sp)
/*  f100a0c:	4458f800 */ 	cfc1	$t8,$31
/*  f100a10:	44d9f800 */ 	ctc1	$t9,$31
/*  f100a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a18:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f100a1c:	4459f800 */ 	cfc1	$t9,$31
/*  f100a20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a24:	33390078 */ 	andi	$t9,$t9,0x78
/*  f100a28:	53200013 */ 	beqzl	$t9,.L0f100a78
/*  f100a2c:	44193000 */ 	mfc1	$t9,$f6
/*  f100a30:	44813000 */ 	mtc1	$at,$f6
/*  f100a34:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100a38:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f100a3c:	44d9f800 */ 	ctc1	$t9,$31
/*  f100a40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a44:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f100a48:	4459f800 */ 	cfc1	$t9,$31
/*  f100a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a50:	33390078 */ 	andi	$t9,$t9,0x78
/*  f100a54:	17200005 */ 	bnez	$t9,.L0f100a6c
/*  f100a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a5c:	44193000 */ 	mfc1	$t9,$f6
/*  f100a60:	3c018000 */ 	lui	$at,0x8000
/*  f100a64:	10000007 */ 	beqz	$zero,.L0f100a84
/*  f100a68:	0321c825 */ 	or	$t9,$t9,$at
.L0f100a6c:
/*  f100a6c:	10000005 */ 	beqz	$zero,.L0f100a84
/*  f100a70:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f100a74:	44193000 */ 	mfc1	$t9,$f6
.L0f100a78:
/*  f100a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a7c:	0720fffb */ 	bltz	$t9,.L0f100a6c
/*  f100a80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f100a84:
/*  f100a84:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f100a88:	44d8f800 */ 	ctc1	$t8,$31
/*  f100a8c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f100a90:	91d80250 */ 	lbu	$t8,0x250($t6)
/*  f100a94:	02017824 */ 	and	$t7,$s0,$at
/*  f100a98:	24010002 */ 	addiu	$at,$zero,0x2
/*  f100a9c:	17010003 */ 	bne	$t8,$at,.L0f100aac
/*  f100aa0:	032f8025 */ 	or	$s0,$t9,$t7
/*  f100aa4:	3c104f4f */ 	lui	$s0,0x4f4f
/*  f100aa8:	36104f7f */ 	ori	$s0,$s0,0x4f7f
.L0f100aac:
/*  f100aac:	87b9007e */ 	lh	$t9,0x7e($sp)
/*  f100ab0:	02003025 */ 	or	$a2,$s0,$zero
/*  f100ab4:	0fc3fdbd */ 	jal	func0f0ff6f4
/*  f100ab8:	afb90010 */ 	sw	$t9,0x10($sp)
.L0f100abc:
/*  f100abc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f100ac0:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f100ac4:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f100ac8:	03e00008 */ 	jr	$ra
/*  f100acc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f100ad0
/*  f100ad0:	27bdfe28 */ 	addiu	$sp,$sp,-472
/*  f100ad4:	3c0e8007 */ 	lui	$t6,%hi(var800706c8)
/*  f100ad8:	8dce06c8 */ 	lw	$t6,%lo(var800706c8)($t6)
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
/*  f100b14:	3c018008 */ 	lui	$at,0x8008
/*  f100b18:	10000004 */ 	beqz	$zero,.L0f100b2c
/*  f100b1c:	ac2ffac0 */ 	sw	$t7,-0x540($at)
.L0f100b20:
/*  f100b20:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f100b24:	3c018008 */ 	lui	$at,0x8008
/*  f100b28:	ac38fac0 */ 	sw	$t8,-0x540($at)
.L0f100b2c:
/*  f100b2c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f100b30:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f100b34:	8d79028c */ 	lw	$t9,0x28c($t3)
/*  f100b38:	3c01800a */ 	lui	$at,%hi(g_ActiveMenuIndex)
/*  f100b3c:	ac3921b8 */ 	sw	$t9,%lo(g_ActiveMenuIndex)($at)
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
/*  f100b74:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuIndex)
/*  f100b78:	8f3921b8 */ 	lw	$t9,%lo(g_ActiveMenuIndex)($t9)
/*  f100b7c:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f100b80:	3c17800a */ 	lui	$s7,%hi(g_ActiveMenuThings)
/*  f100b84:	033e0019 */ 	multu	$t9,$s8
/*  f100b88:	26f720d0 */ 	addiu	$s7,$s7,%lo(g_ActiveMenuThings)
/*  f100b8c:	00007012 */ 	mflo	$t6
/*  f100b90:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f100b94:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f100b98:	28410002 */ 	slti	$at,$v0,0x2
/*  f100b9c:	14200005 */ 	bnez	$at,.L0f100bb4
/*  f100ba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100ba4:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f100ba8:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f100bac:	932e1be5 */ 	lbu	$t6,0x1be5($t9)
/*  f100bb0:	afae01c4 */ 	sw	$t6,0x1c4($sp)
.L0f100bb4:
/*  f100bb4:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuIndex)
/*  f100bb8:	8def21b8 */ 	lw	$t7,%lo(g_ActiveMenuIndex)($t7)
/*  f100bbc:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f100bc0:	3c17800a */ 	lui	$s7,%hi(g_ActiveMenuThings)
/*  f100bc4:	01fe0019 */ 	multu	$t7,$s8
/*  f100bc8:	26f720d0 */ 	addiu	$s7,$s7,%lo(g_ActiveMenuThings)
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
/*  f100c08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100c0c:	0007000d */ 	break	0x7
.L0f100c10:
/*  f100c10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f100c14:	14610004 */ 	bne	$v1,$at,.L0f100c28
/*  f100c18:	3c018000 */ 	lui	$at,0x8000
/*  f100c1c:	14410002 */ 	bne	$v0,$at,.L0f100c28
/*  f100c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100c24:	0006000d */ 	break	0x6
.L0f100c28:
/*  f100c28:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f100c2c:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f100c30:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100c34:	26070008 */ 	addiu	$a3,$s0,0x8
/*  f100c38:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f100c3c:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
/*  f100c40:	01de0019 */ 	multu	$t6,$s8
/*  f100c44:	00007812 */ 	mflo	$t7
/*  f100c48:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f100c4c:	86180006 */ 	lh	$t8,0x6($s0)
/*  f100c50:	86190008 */ 	lh	$t9,0x8($s0)
/*  f100c54:	a618000a */ 	sh	$t8,0xa($s0)
/*  f100c58:	1000000d */ 	beqz	$zero,.L0f100c90
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
/*  f100c88:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100c8c:	2607000c */ 	addiu	$a3,$s0,0xc
.L0f100c90:
/*  f100c90:	0fc351e7 */ 	jal	func0f0d479c
/*  f100c94:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f100c98:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f100c9c:	0fc59e73 */ 	jal	func0f1679cc
/*  f100ca0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f100ca4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f100ca8:	0fc59e59 */ 	jal	func0f167964
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
/*  f100dc0:	0fc3fc9d */ 	jal	func0f0ff274
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
/*  f100e04:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100e08:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f100e40:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100e44:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f100e7c:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100e80:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f10106c:	0fc3fc9d */ 	jal	func0f0ff274
/*  f101070:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f101074:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f101078:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
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
/*  f1010a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010a8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f1010ac:
/*  f1010ac:	81cfdfeb */ 	lb	$t7,%lo(g_MissionConfig+0x3)($t6)
/*  f1010b0:	05e10029 */ 	bgez	$t7,.L0f101158
/*  f1010b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010b8:	0fc3f7a3 */ 	jal	activemenuGetFirstBuddyIndex
/*  f1010bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010c0:	04400025 */ 	bltz	$v0,.L0f101158
/*  f1010c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010c8:	16000042 */ 	bnez	$s0,.L0f1011d4
/*  f1010cc:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuIndex)
/*  f1010d0:	8f1821b8 */ 	lw	$t8,%lo(g_ActiveMenuIndex)($t8)
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
/*  f101128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10112c:	10000029 */ 	beqz	$zero,.L0f1011d4
/*  f101130:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f101134:
/*  f101134:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101138:	14810026 */ 	bne	$a0,$at,.L0f1011d4
/*  f10113c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101140:	8c6f0014 */ 	lw	$t7,0x14($v1)
/*  f101144:	31f80400 */ 	andi	$t8,$t7,0x400
/*  f101148:	17000022 */ 	bnez	$t8,.L0f1011d4
/*  f10114c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101150:	10000020 */ 	beqz	$zero,.L0f1011d4
/*  f101154:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f101158:
/*  f101158:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x318)
/*  f10115c:	8f39a2d8 */ 	lw	$t9,%lo(g_Vars+0x318)($t9)
/*  f101160:	1320001c */ 	beqz	$t9,.L0f1011d4
/*  f101164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101168:	1600001a */ 	bnez	$s0,.L0f1011d4
/*  f10116c:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f101170:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
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
/*  f1011b4:	3c02800b */ 	lui	$v0,%hi(g_ActiveMenuMpBotCommands)
/*  f1011b8:	00591021 */ 	addu	$v0,$v0,$t9
/*  f1011bc:	8f1902d4 */ 	lw	$t9,0x2d4($t8)
/*  f1011c0:	9042cb78 */ 	lbu	$v0,%lo(g_ActiveMenuMpBotCommands)($v0)
/*  f1011c4:	93230079 */ 	lbu	$v1,0x79($t9)
/*  f1011c8:	14430002 */ 	bne	$v0,$v1,.L0f1011d4
/*  f1011cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1011d0:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f1011d4:
/*  f1011d4:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f1011d8:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f1011dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1011e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1011e4:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f1011e8:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f1011ec:	15e10003 */ 	bne	$t7,$at,.L0f1011fc
/*  f1011f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1011f4:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f1011f8:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.L0f1011fc:
/*  f1011fc:	0fc3f8a0 */ 	jal	activemenuGetSlotDetails
/*  f101200:	02a03025 */ 	or	$a2,$s5,$zero
/*  f101204:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f101208:	1662000f */ 	bne	$s3,$v0,.L0f101248
/*  f10120c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101210:	5622000e */ 	bnel	$s1,$v0,.L0f10124c
/*  f101214:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
/*  f101218:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f10121c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101220:	14400011 */ 	bnez	$v0,.L0f101268
/*  f101224:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101228:	87b80180 */ 	lh	$t8,0x180($sp)
/*  f10122c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f101230:	02803025 */ 	or	$a2,$s4,$zero
/*  f101234:	87a70182 */ 	lh	$a3,0x182($sp)
/*  f101238:	0fc3fdbd */ 	jal	func0f0ff6f4
/*  f10123c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f101240:	10000009 */ 	beqz	$zero,.L0f101268
/*  f101244:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101248:
/*  f101248:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
.L0f10124c:
/*  f10124c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f101250:	87a60182 */ 	lh	$a2,0x182($sp)
/*  f101254:	87a70180 */ 	lh	$a3,0x180($sp)
/*  f101258:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f10125c:	0fc4004a */ 	jal	func0f100128
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
/*  f1012a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012a8:	0fc3f7a3 */ 	jal	activemenuGetFirstBuddyIndex
/*  f1012ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012b0:	04410011 */ 	bgez	$v0,.L0f1012f8
.L0f1012b4:
/*  f1012b4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x318)
/*  f1012b8:	8f18a2d8 */ 	lw	$t8,%lo(g_Vars+0x318)($t8)
/*  f1012bc:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuIndex)
/*  f1012c0:	1300000d */ 	beqz	$t8,.L0f1012f8
/*  f1012c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012c8:	8f3921b8 */ 	lw	$t9,%lo(g_ActiveMenuIndex)($t9)
/*  f1012cc:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f1012d0:	033e0019 */ 	multu	$t9,$s8
/*  f1012d4:	00007012 */ 	mflo	$t6
/*  f1012d8:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f1012dc:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f1012e0:	28410002 */ 	slti	$at,$v0,0x2
/*  f1012e4:	14200004 */ 	bnez	$at,.L0f1012f8
/*  f1012e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012ec:	0fc3fdef */ 	jal	func0f0ff7bc
/*  f1012f0:	2445fffe */ 	addiu	$a1,$v0,-2
/*  f1012f4:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f1012f8:
/*  f1012f8:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuIndex)
/*  f1012fc:	8f1821b8 */ 	lw	$t8,%lo(g_ActiveMenuIndex)($t8)
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
/*  f101330:	00000000 */ 	sll	$zero,$zero,0x0
.L0f101334:
/*  f101334:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f101338:	24120006 */ 	addiu	$s2,$zero,0x6
/*  f10133c:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f101340:	51e00004 */ 	beqzl	$t7,.L0f101354
/*  f101344:	00003025 */ 	or	$a2,$zero,$zero
/*  f101348:	10000002 */ 	beqz	$zero,.L0f101354
/*  f10134c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101350:	00003025 */ 	or	$a2,$zero,$zero
.L0f101354:
/*  f101354:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f101358:	00002825 */ 	or	$a1,$zero,$zero
/*  f10135c:	13000003 */ 	beqz	$t8,.L0f10136c
/*  f101360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101364:	10000001 */ 	beqz	$zero,.L0f10136c
/*  f101368:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10136c:
/*  f10136c:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f101370:	00002025 */ 	or	$a0,$zero,$zero
/*  f101374:	13200003 */ 	beqz	$t9,.L0f101384
/*  f101378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10137c:	10000001 */ 	beqz	$zero,.L0f101384
/*  f101380:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101384:
/*  f101384:	8c4e0070 */ 	lw	$t6,0x70($v0)
/*  f101388:	00001825 */ 	or	$v1,$zero,$zero
/*  f10138c:	11c00003 */ 	beqz	$t6,.L0f10139c
/*  f101390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101394:	10000001 */ 	beqz	$zero,.L0f10139c
/*  f101398:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10139c:
/*  f10139c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f1013a0:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1013a4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f1013a8:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1013ac:	14200003 */ 	bnez	$at,.L0f1013bc
/*  f1013b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1013b4:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f1013b8:	24130003 */ 	addiu	$s3,$zero,0x3
.L0f1013bc:
/*  f1013bc:	0c0068f7 */ 	jal	fsin
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
/*  f1013f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1013f4:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f1013f8:	4442f800 */ 	cfc1	$v0,$31
/*  f1013fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101400:	30420078 */ 	andi	$v0,$v0,0x78
/*  f101404:	50400013 */ 	beqzl	$v0,.L0f101454
/*  f101408:	44028000 */ 	mfc1	$v0,$f16
/*  f10140c:	44818000 */ 	mtc1	$at,$f16
/*  f101410:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f101414:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f101418:	44c2f800 */ 	ctc1	$v0,$31
/*  f10141c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101420:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f101424:	4442f800 */ 	cfc1	$v0,$31
/*  f101428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10142c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f101430:	14400005 */ 	bnez	$v0,.L0f101448
/*  f101434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101438:	44028000 */ 	mfc1	$v0,$f16
/*  f10143c:	3c018000 */ 	lui	$at,0x8000
/*  f101440:	10000007 */ 	beqz	$zero,.L0f101460
/*  f101444:	00411025 */ 	or	$v0,$v0,$at
.L0f101448:
/*  f101448:	10000005 */ 	beqz	$zero,.L0f101460
/*  f10144c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f101450:	44028000 */ 	mfc1	$v0,$f16
.L0f101454:
/*  f101454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101458:	0440fffb */ 	bltz	$v0,.L0f101448
/*  f10145c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f101498:	0fc54df7 */ 	jal	func0f1537dc
/*  f10149c:	02802825 */ 	or	$a1,$s4,$zero
/*  f1014a0:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuIndex)
/*  f1014a4:	8f1821b8 */ 	lw	$t8,%lo(g_ActiveMenuIndex)($t8)
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
/*  f1014dc:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f1014e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1014e4:	10400005 */ 	beqz	$v0,.L0f1014fc
/*  f1014e8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x6c)
/*  f1014ec:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1014f0:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f1014f4:	10000034 */ 	beqz	$zero,.L0f1015c8
/*  f1014f8:	00009825 */ 	or	$s3,$zero,$zero
.L0f1014fc:
/*  f1014fc:	8f18a02c */ 	lw	$t8,%lo(g_Vars+0x6c)($t8)
/*  f101500:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x68)
/*  f101504:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x64)
/*  f101508:	13000003 */ 	beqz	$t8,.L0f101518
/*  f10150c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x70)
/*  f101510:	10000002 */ 	beqz	$zero,.L0f10151c
/*  f101514:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101518:
/*  f101518:	00003025 */ 	or	$a2,$zero,$zero
.L0f10151c:
/*  f10151c:	8f39a028 */ 	lw	$t9,%lo(g_Vars+0x68)($t9)
/*  f101520:	00002825 */ 	or	$a1,$zero,$zero
/*  f101524:	00002025 */ 	or	$a0,$zero,$zero
/*  f101528:	13200003 */ 	beqz	$t9,.L0f101538
/*  f10152c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101530:	10000001 */ 	beqz	$zero,.L0f101538
/*  f101534:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101538:
/*  f101538:	8dcea024 */ 	lw	$t6,%lo(g_Vars+0x64)($t6)
/*  f10153c:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f101540:	11c00003 */ 	beqz	$t6,.L0f101550
/*  f101544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101548:	10000001 */ 	beqz	$zero,.L0f101550
/*  f10154c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101550:
/*  f101550:	8defa030 */ 	lw	$t7,%lo(g_Vars+0x70)($t7)
/*  f101554:	11e00003 */ 	beqz	$t7,.L0f101564
/*  f101558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10155c:	10000001 */ 	beqz	$zero,.L0f101564
/*  f101560:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101564:
/*  f101564:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101568:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f10156c:	03267021 */ 	addu	$t6,$t9,$a2
/*  f101570:	29c10002 */ 	slti	$at,$t6,0x2
/*  f101574:	14200014 */ 	bnez	$at,.L0f1015c8
/*  f101578:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10157c:	27a50114 */ 	addiu	$a1,$sp,0x114
/*  f101580:	0fc3f8a0 */ 	jal	activemenuGetSlotDetails
/*  f101584:	02003025 */ 	or	$a2,$s0,$zero
/*  f101588:	3c0f800a */ 	lui	$t7,%hi(var800a21b4)
/*  f10158c:	8def21b4 */ 	lw	$t7,%lo(var800a21b4)($t7)
/*  f101590:	3c07800a */ 	lui	$a3,%hi(var800a21b0)
/*  f101594:	8ce721b0 */ 	lw	$a3,%lo(var800a21b0)($a3)
/*  f101598:	27a4013c */ 	addiu	$a0,$sp,0x13c
/*  f10159c:	27a50138 */ 	addiu	$a1,$sp,0x138
/*  f1015a0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1015a4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1015a8:	0fc55cbe */ 	jal	func0f1572f8
/*  f1015ac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1015b0:	8fb10138 */ 	lw	$s1,0x138($sp)
/*  f1015b4:	06210003 */ 	bgez	$s1,.L0f1015c4
/*  f1015b8:	0011c043 */ 	sra	$t8,$s1,0x1
/*  f1015bc:	26210001 */ 	addiu	$at,$s1,0x1
/*  f1015c0:	0001c043 */ 	sra	$t8,$at,0x1
.L0f1015c4:
/*  f1015c4:	27110002 */ 	addiu	$s1,$t8,0x2
.L0f1015c8:
/*  f1015c8:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuIndex)
/*  f1015cc:	8def21b8 */ 	lw	$t7,%lo(g_ActiveMenuIndex)($t7)
/*  f1015d0:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1015d4:	3c068008 */ 	lui	$a2,%hi(var8007fac0)
/*  f1015d8:	01fe0019 */ 	multu	$t7,$s8
/*  f1015dc:	24c6fac0 */ 	addiu	$a2,$a2,%lo(var8007fac0)
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
/*  f101630:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuIndex)
/*  f101634:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f101638:	8f3921b8 */ 	lw	$t9,%lo(g_ActiveMenuIndex)($t9)
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
/*  f101678:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuIndex)
/*  f10167c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f101680:	8f1821b8 */ 	lw	$t8,%lo(g_ActiveMenuIndex)($t8)
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
/*  f1016d8:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuIndex)
/*  f1016dc:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1016e0:	8def21b8 */ 	lw	$t7,%lo(g_ActiveMenuIndex)($t7)
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
/*  f101720:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f101724:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f101728:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
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
/*  f10177c:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuIndex)
/*  f101780:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f101784:	8f3921b8 */ 	lw	$t9,%lo(g_ActiveMenuIndex)($t9)
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
/*  f1017c8:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuIndex)
/*  f1017cc:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1017d0:	8def21b8 */ 	lw	$t7,%lo(g_ActiveMenuIndex)($t7)
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
/*  f101824:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuIndex)
/*  f101828:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f10182c:	8dce21b8 */ 	lw	$t6,%lo(g_ActiveMenuIndex)($t6)
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
/*  f1018f8:	10000002 */ 	beqz	$zero,.L0f101904
/*  f1018fc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101900:	00003025 */ 	or	$a2,$zero,$zero
.L0f101904:
/*  f101904:	8d680068 */ 	lw	$t0,0x68($t3)
/*  f101908:	51000004 */ 	beqzl	$t0,.L0f10191c
/*  f10190c:	00002825 */ 	or	$a1,$zero,$zero
/*  f101910:	10000002 */ 	beqz	$zero,.L0f10191c
/*  f101914:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101918:	00002825 */ 	or	$a1,$zero,$zero
.L0f10191c:
/*  f10191c:	8d690064 */ 	lw	$t1,0x64($t3)
/*  f101920:	51200004 */ 	beqzl	$t1,.L0f101934
/*  f101924:	00002025 */ 	or	$a0,$zero,$zero
/*  f101928:	10000002 */ 	beqz	$zero,.L0f101934
/*  f10192c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101930:	00002025 */ 	or	$a0,$zero,$zero
.L0f101934:
/*  f101934:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f101938:	51400004 */ 	beqzl	$t2,.L0f10194c
/*  f10193c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101940:	10000002 */ 	beqz	$zero,.L0f10194c
/*  f101944:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101948:	00001825 */ 	or	$v1,$zero,$zero
.L0f10194c:
/*  f10194c:	00647021 */ 	addu	$t6,$v1,$a0
/*  f101950:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f101954:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f101958:	2b010002 */ 	slti	$at,$t8,0x2
/*  f10195c:	54200004 */ 	bnezl	$at,.L0f101970
/*  f101960:	24170040 */ 	addiu	$s7,$zero,0x40
/*  f101964:	10000002 */ 	beqz	$zero,.L0f101970
/*  f101968:	24170030 */ 	addiu	$s7,$zero,0x30
/*  f10196c:	24170040 */ 	addiu	$s7,$zero,0x40
.L0f101970:
/*  f101970:	50e00004 */ 	beqzl	$a3,.L0f101984
/*  f101974:	00003025 */ 	or	$a2,$zero,$zero
/*  f101978:	10000002 */ 	beqz	$zero,.L0f101984
/*  f10197c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101980:	00003025 */ 	or	$a2,$zero,$zero
.L0f101984:
/*  f101984:	51000004 */ 	beqzl	$t0,.L0f101998
/*  f101988:	00002825 */ 	or	$a1,$zero,$zero
/*  f10198c:	10000002 */ 	beqz	$zero,.L0f101998
/*  f101990:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101994:	00002825 */ 	or	$a1,$zero,$zero
.L0f101998:
/*  f101998:	51200004 */ 	beqzl	$t1,.L0f1019ac
/*  f10199c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1019a0:	10000002 */ 	beqz	$zero,.L0f1019ac
/*  f1019a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1019a8:	00002025 */ 	or	$a0,$zero,$zero
.L0f1019ac:
/*  f1019ac:	51400004 */ 	beqzl	$t2,.L0f1019c0
/*  f1019b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1019b4:	10000002 */ 	beqz	$zero,.L0f1019c0
/*  f1019b8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1019bc:	00001825 */ 	or	$v1,$zero,$zero
.L0f1019c0:
/*  f1019c0:	00647821 */ 	addu	$t7,$v1,$a0
/*  f1019c4:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f1019c8:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f1019cc:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1019d0:	54200004 */ 	bnezl	$at,.L0f1019e4
/*  f1019d4:	2415000b */ 	addiu	$s5,$zero,0xb
/*  f1019d8:	10000002 */ 	beqz	$zero,.L0f1019e4
/*  f1019dc:	24150007 */ 	addiu	$s5,$zero,0x7
/*  f1019e0:	2415000b */ 	addiu	$s5,$zero,0xb
.L0f1019e4:
/*  f1019e4:	10e00003 */ 	beqz	$a3,.L0f1019f4
/*  f1019e8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1019ec:	10000002 */ 	beqz	$zero,.L0f1019f8
/*  f1019f0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1019f4:
/*  f1019f4:	00003025 */ 	or	$a2,$zero,$zero
.L0f1019f8:
/*  f1019f8:	11000003 */ 	beqz	$t0,.L0f101a08
/*  f1019fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f101a00:	10000002 */ 	beqz	$zero,.L0f101a0c
/*  f101a04:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101a08:
/*  f101a08:	00002825 */ 	or	$a1,$zero,$zero
.L0f101a0c:
/*  f101a0c:	51200004 */ 	beqzl	$t1,.L0f101a20
/*  f101a10:	00002025 */ 	or	$a0,$zero,$zero
/*  f101a14:	10000002 */ 	beqz	$zero,.L0f101a20
/*  f101a18:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101a1c:	00002025 */ 	or	$a0,$zero,$zero
.L0f101a20:
/*  f101a20:	51400004 */ 	beqzl	$t2,.L0f101a34
/*  f101a24:	00001825 */ 	or	$v1,$zero,$zero
/*  f101a28:	10000002 */ 	beqz	$zero,.L0f101a34
/*  f101a2c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101a30:	00001825 */ 	or	$v1,$zero,$zero
.L0f101a34:
/*  f101a34:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101a38:	03057821 */ 	addu	$t7,$t8,$a1
/*  f101a3c:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f101a40:	15c10011 */ 	bne	$t6,$at,.L0f101a88
/*  f101a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101a48:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f101a4c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f101a90:	10000001 */ 	beqz	$zero,.L0f101a98
/*  f101a94:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101a98:
/*  f101a98:	11000003 */ 	beqz	$t0,.L0f101aa8
/*  f101a9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f101aa0:	10000001 */ 	beqz	$zero,.L0f101aa8
/*  f101aa4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f101aa8:
/*  f101aa8:	11200003 */ 	beqz	$t1,.L0f101ab8
/*  f101aac:	00002025 */ 	or	$a0,$zero,$zero
/*  f101ab0:	10000001 */ 	beqz	$zero,.L0f101ab8
/*  f101ab4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101ab8:
/*  f101ab8:	11400003 */ 	beqz	$t2,.L0f101ac8
/*  f101abc:	00001825 */ 	or	$v1,$zero,$zero
/*  f101ac0:	10000001 */ 	beqz	$zero,.L0f101ac8
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
/*  f101b00:	10000002 */ 	beqz	$zero,.L0f101b0c
/*  f101b04:	24120008 */ 	addiu	$s2,$zero,0x8
.L0f101b08:
/*  f101b08:	2412fff8 */ 	addiu	$s2,$zero,-8
.L0f101b0c:
/*  f101b0c:	10e00003 */ 	beqz	$a3,.L0f101b1c
/*  f101b10:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101b14:	10000002 */ 	beqz	$zero,.L0f101b20
/*  f101b18:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101b1c:
/*  f101b1c:	00003025 */ 	or	$a2,$zero,$zero
.L0f101b20:
/*  f101b20:	51000004 */ 	beqzl	$t0,.L0f101b34
/*  f101b24:	00002825 */ 	or	$a1,$zero,$zero
/*  f101b28:	10000002 */ 	beqz	$zero,.L0f101b34
/*  f101b2c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101b30:	00002825 */ 	or	$a1,$zero,$zero
.L0f101b34:
/*  f101b34:	51200004 */ 	beqzl	$t1,.L0f101b48
/*  f101b38:	00002025 */ 	or	$a0,$zero,$zero
/*  f101b3c:	10000002 */ 	beqz	$zero,.L0f101b48
/*  f101b40:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101b44:	00002025 */ 	or	$a0,$zero,$zero
.L0f101b48:
/*  f101b48:	51400004 */ 	beqzl	$t2,.L0f101b5c
/*  f101b4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101b50:	10000002 */ 	beqz	$zero,.L0f101b5c
/*  f101b54:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101b58:	00001825 */ 	or	$v1,$zero,$zero
.L0f101b5c:
/*  f101b5c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f101b60:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f101b64:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f101b68:	17210019 */ 	bne	$t9,$at,.L0f101bd0
/*  f101b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b70:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f101b74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b78:	10400015 */ 	beqz	$v0,.L0f101bd0
/*  f101b7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b80:	0c002f40 */ 	jal	func0000bd00
/*  f101b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b88:	3c188008 */ 	lui	$t8,%hi(var8007fac0)
/*  f101b8c:	8f18fac0 */ 	lw	$t8,%lo(var8007fac0)($t8)
/*  f101b90:	44972000 */ 	mtc1	$s7,$f4
/*  f101b94:	0058001a */ 	div	$zero,$v0,$t8
/*  f101b98:	00008012 */ 	mflo	$s0
/*  f101b9c:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f101ba0:	17000002 */ 	bnez	$t8,.L0f101bac
/*  f101ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101ba8:	0007000d */ 	break	0x7
.L0f101bac:
/*  f101bac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101bb0:	17010004 */ 	bne	$t8,$at,.L0f101bc4
/*  f101bb4:	3c018000 */ 	lui	$at,0x8000
/*  f101bb8:	14410002 */ 	bne	$v0,$at,.L0f101bc4
/*  f101bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101bc0:	0006000d */ 	break	0x6
.L0f101bc4:
/*  f101bc4:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f101bc8:	10000031 */ 	beqz	$zero,.L0f101c90
/*  f101bcc:	3c013e80 */ 	lui	$at,0x3e80
.L0f101bd0:
/*  f101bd0:	0c002f22 */ 	jal	func0000bc88
/*  f101bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101bd8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f101bdc:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f101be0:	0c002f40 */ 	jal	func0000bd00
/*  f101be4:	01e08825 */ 	or	$s1,$t7,$zero
/*  f101be8:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f101bec:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
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
/*  f101c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c1c:	0007000d */ 	break	0x7
.L0f101c20:
/*  f101c20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101c24:	14610004 */ 	bne	$v1,$at,.L0f101c38
/*  f101c28:	3c018000 */ 	lui	$at,0x8000
/*  f101c2c:	14410002 */ 	bne	$v0,$at,.L0f101c38
/*  f101c30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c34:	0006000d */ 	break	0x6
.L0f101c38:
/*  f101c38:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f101c3c:	14600002 */ 	bnez	$v1,.L0f101c48
/*  f101c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c44:	0007000d */ 	break	0x7
.L0f101c48:
/*  f101c48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101c4c:	14610004 */ 	bne	$v1,$at,.L0f101c60
/*  f101c50:	3c018000 */ 	lui	$at,0x8000
/*  f101c54:	16210002 */ 	bne	$s1,$at,.L0f101c60
/*  f101c58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c5c:	0006000d */ 	break	0x6
.L0f101c60:
/*  f101c60:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f101c64:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f101c68:	46001102 */ 	mul.s	$f4,$f2,$f0
/*  f101c6c:	440f9000 */ 	mfc1	$t7,$f18
/*  f101c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c74:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f101c78:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f101c7c:	440e4000 */ 	mfc1	$t6,$f8
/*  f101c80:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f101cac:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f101d40:	0c002f26 */ 	jal	func0000bc98
/*  f101d44:	e7a20068 */ 	swc1	$f2,0x68($sp)
/*  f101d48:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f101d4c:	00147c03 */ 	sra	$t7,$s4,0x10
/*  f101d50:	0c002f44 */ 	jal	func0000bd10
/*  f101d54:	01e0a025 */ 	or	$s4,$t7,$zero
/*  f101d58:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f101d5c:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f101d60:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f101d64:	c7a20068 */ 	lwc1	$f2,0x68($sp)
/*  f101d68:	00001825 */ 	or	$v1,$zero,$zero
/*  f101d6c:	13000003 */ 	beqz	$t8,.L0f101d7c
/*  f101d70:	00003025 */ 	or	$a2,$zero,$zero
/*  f101d74:	10000001 */ 	beqz	$zero,.L0f101d7c
/*  f101d78:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101d7c:
/*  f101d7c:	8c990068 */ 	lw	$t9,0x68($a0)
/*  f101d80:	00002825 */ 	or	$a1,$zero,$zero
/*  f101d84:	13200003 */ 	beqz	$t9,.L0f101d94
/*  f101d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101d8c:	10000001 */ 	beqz	$zero,.L0f101d94
/*  f101d90:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101d94:
/*  f101d94:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*  f101d98:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f101d9c:	11c00003 */ 	beqz	$t6,.L0f101dac
/*  f101da0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101da4:	10000001 */ 	beqz	$zero,.L0f101dac
/*  f101da8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101dac:
/*  f101dac:	8c8f0070 */ 	lw	$t7,0x70($a0)
/*  f101db0:	00002025 */ 	or	$a0,$zero,$zero
/*  f101db4:	c7a80100 */ 	lwc1	$f8,0x100($sp)
/*  f101db8:	11e00003 */ 	beqz	$t7,.L0f101dc8
/*  f101dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101dc0:	10000001 */ 	beqz	$zero,.L0f101dc8
/*  f101dc4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101dc8:
/*  f101dc8:	0085c021 */ 	addu	$t8,$a0,$a1
/*  f101dcc:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f101dd0:	03237021 */ 	addu	$t6,$t9,$v1
/*  f101dd4:	29c10002 */ 	slti	$at,$t6,0x2
/*  f101dd8:	14200003 */ 	bnez	$at,.L0f101de8
/*  f101ddc:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f101de0:	10000002 */ 	beqz	$zero,.L0f101dec
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
/*  f101e28:	3c0b8008 */ 	lui	$t3,%hi(var8007fac0)
/*  f101e2c:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f101e30:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f101e34:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f101e38:	256bfac0 */ 	addiu	$t3,$t3,%lo(var8007fac0)
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
/*  f101e78:	3c078008 */ 	lui	$a3,%hi(var8007fac0)
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
/*  f101eac:	24e7fac0 */ 	addiu	$a3,$a3,%lo(var8007fac0)
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
/*  f101f68:	10000059 */ 	beqz	$zero,.L0f1020d0
/*  f101f6c:	acb90004 */ 	sw	$t9,0x4($a1)
.L0f101f70:
/*  f101f70:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f101f74:	3c1800c0 */ 	lui	$t8,0xc0
/*  f101f78:	37180060 */ 	ori	$t8,$t8,0x60
/*  f101f7c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f101f80:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f101f84:	add80004 */ 	sw	$t8,0x4($t6)
/*  f101f88:	3c188008 */ 	lui	$t8,%hi(var8007fac0)
/*  f101f8c:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f101f90:	8f18fac0 */ 	lw	$t8,%lo(var8007fac0)($t8)
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
/*  f101fd0:	3c0f8008 */ 	lui	$t7,%hi(var8007fac0)
/*  f101fd4:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f101fd8:	8deffac0 */ 	lw	$t7,%lo(var8007fac0)($t7)
/*  f101fdc:	00027080 */ 	sll	$t6,$v0,0x2
/*  f101fe0:	01c01025 */ 	or	$v0,$t6,$zero
/*  f101fe4:	020f0019 */ 	multu	$s0,$t7
/*  f101fe8:	0000c012 */ 	mflo	$t8
/*  f101fec:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f101ff0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f101ff4:	01c27825 */ 	or	$t7,$t6,$v0
/*  f101ff8:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f101ffc:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f102000:	3c188008 */ 	lui	$t8,%hi(var8007fac0)
/*  f102004:	8f18fac0 */ 	lw	$t8,%lo(var8007fac0)($t8)
/*  f102008:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f10200c:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f102010:	254f0008 */ 	addiu	$t7,$t2,0x8
/*  f102014:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f102018:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f10201c:	44199000 */ 	mfc1	$t9,$f18
/*  f102020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f102024:	03303021 */ 	addu	$a2,$t9,$s0
/*  f102028:	00d80019 */ 	multu	$a2,$t8
/*  f10202c:	00c04025 */ 	or	$t0,$a2,$zero
/*  f102030:	02173021 */ 	addu	$a2,$s0,$s7
/*  f102034:	0000c812 */ 	mflo	$t9
/*  f102038:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10203c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f102040:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f102044:	0303c825 */ 	or	$t9,$t8,$v1
/*  f102048:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f10204c:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f102050:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
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
/*  f102080:	3c0f8008 */ 	lui	$t7,%hi(var8007fac0)
/*  f102084:	8deffac0 */ 	lw	$t7,%lo(var8007fac0)($t7)
/*  f102088:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f10208c:	00cf0019 */ 	multu	$a2,$t7
/*  f102090:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f102094:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f102098:	0000c012 */ 	mflo	$t8
/*  f10209c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1020a0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1020a4:	01d67825 */ 	or	$t7,$t6,$s6
/*  f1020a8:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f1020ac:	3c198008 */ 	lui	$t9,%hi(var8007fac0)
/*  f1020b0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1020b4:	8f39fac0 */ 	lw	$t9,%lo(var8007fac0)($t9)
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
/*  f102104:	3c1f8008 */ 	lui	$ra,%hi(var8007fac0)
/*  f102108:	27fffac0 */ 	addiu	$ra,$ra,%lo(var8007fac0)
/*  f10210c:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f102110:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f102114:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f102118:	25250002 */ 	addiu	$a1,$t1,0x2
/*  f10211c:	30aa03ff */ 	andi	$t2,$a1,0x3ff
/*  f102120:	24990008 */ 	addiu	$t9,$a0,0x8
/*  f102124:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f102128:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f10212c:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f102130:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f102134:	44155000 */ 	mfc1	$s5,$f10
/*  f102138:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
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
/*  f1021f4:	3c018008 */ 	lui	$at,0x8008
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
/*  f102220:	ac2ffac0 */ 	sw	$t7,-0x540($at)
/*  f102224:	03e00008 */ 	jr	$ra
/*  f102228:	27bd01d8 */ 	addiu	$sp,$sp,0x1d8
/*  f10222c:	00000000 */ 	sll	$zero,$zero,0x0
);

const char var7f1b2b34[] = "Here is where the activemenu sets favourites\n";
const char var7f1b2b64[] = "slot %d = guntype %d\n";
const char var7f1b2b7c[] = "put it in %d\n";
const char var7f1b2b8c[] = "activemenu: setting up for multiplayer\n";
const char var7f1b2bb4[] = "activemenu: setting up for single player\n";
const char var7f1b2be0[] = "Put guntype %d in slot %d\n";
const char var7f1b2bfc[] = "ActiveMenu: Two or more equipped items of guntype %d\n";
const char var7f1b2c34[] = "FAV: Added gun %d to slot %d\n";
const char var7f1b2c54[] = "";
const char var7f1b2c58[] = "obcol";
const char var7f1b2c60[] = "ibcol";
const char var7f1b2c68[] = "defcol";
const char var7f1b2c70[] = "favcol";
const char var7f1b2c78[] = "pickcol";
const char var7f1b2c80[] = "pickcol2";
