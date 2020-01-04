#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_0b28d0.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/game_115ab0.h"
#include "game/game_152fa0.h"
#include "game/game_16cfa0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_1999b0.h"

const char var7f1b2f00[] = "%s-";
const char var7f1b2f04[] = "==:==";
const char var7f1b2f0c[] = "%d:%02d";
const char var7f1b2f14[] = "%d:%02d:%02d";
const char var7f1b2f24[] = "%s\n";
const char var7f1b2f28[] = "Setup: item = %x\n";

const u32 var7f1b2f3c[] = {0x000000a0};
const u32 var7f1b2f40[] = {0x00000031};
const u32 var7f1b2f44[] = {0x0000004e};
const u32 var7f1b2f48[] = {0x000004a0};

const char var7f1b2f4c[] = "location: controller pak 1\n";
const char var7f1b2f68[] = "%s";
const char var7f1b2f6c[] = "FileMan: Failure Handler\n";
const char var7f1b2f88[] = "Copy Memory Freed\n";
const char var7f1b2f9c[] = "FileMan: Success Handler\n";
const char var7f1b2fb8[] = "Copy Memory Freed\n";
const char var7f1b2fcc[] = ">> block read going write, target file is %x-%x\n";
const char var7f1b3000[] = "SaveElsewhere\n";
const char var7f1b3010[] = "DELETING: %x-%x\n";
const char var7f1b3024[] = "MyResult: %d\n";
const char var7f1b3034[] = "PakOperationSearch>> Search for pak: %x = %d\n";

const u32 var7f1b3064[] = {0x00000080};
const u32 var7f1b3068[] = {0x00000040};
const u32 var7f1b306c[] = {0x00000020};
const u32 var7f1b3070[] = {0x00000008};

const char var7f1b3074[] = "FileAttemptOperation - pak %d op %d\n";
const char var7f1b309c[] = ">> blockWrite: file:%x pak:%x\n";
const char var7f1b30bc[] = ">> blockRead: file:%x pak:%x\n";
const char var7f1b30dc[] = "SUCCESS**->%d\n";
const char var7f1b30ec[] = "SUCCESS**->%d\n";
const char var7f1b30fc[] = ">>>>>>>>>>>>> FileWrite: type %d <<<<<<<<<<<<<<<\n";
const char var7f1b3130[] = "!!!!!!!!!!!! Wanted: %d\n";
const char var7f1b314c[] = "&&&&&&&&&&&&&&&&&&&&&&&&&&&PASSED**************\n";
const char var7f1b3180[] = "guid: %x gives pakno: %d\n";
const char var7f1b319c[] = "Invalidating pak %d\n";
const char var7f1b31b4[] = "YOUR TARGET: %x-%x\n";
const char var7f1b31c8[] = "MyResult: %d\n";
const char var7f1b31d8[] = "COULD NOT DELETE\n";
const char var7f1b31ec[] = "Multiplayer %d was using that file...\n";

const u32 var7f1b3214[] = {0x47414d00};
const u32 var7f1b3218[] = {0x4d504700};
const u32 var7f1b321c[] = {0x4d505000};
const u32 var7f1b3220[] = {0x43414d00};
const u32 var7f1b3224[] = {0x00000080};
const u32 var7f1b3228[] = {0x00000040};
const u32 var7f1b322c[] = {0x00000020};
const u32 var7f1b3230[] = {0x00000008};

const char var7f1b3234[] = "DestPakNo: %d (guid F:%x-%x:P)\n";
const char var7f1b3254[] = "Copy Memory Alloced\n";
const char var7f1b326c[] = "COULDNT GET THE RAM!\n";
const char var7f1b3284[] = "Saving...\n";
const char var7f1b3290[] = "%s";
const char var7f1b3294[] = "GETFileNameForThePurposesOfTheFileRenamingChecker: Unknown type %d\n";
const char var7f1b32d8[] = "%s\n";
const char var7f1b32dc[] = "SetFileNameForThePurposesOfTheFileRenamingChecker: Unknown type %d\n";
const char var7f1b3320[] = "CheckFileName: Comparing range %d-%d\n";
const char var7f1b3348[] = "Compare '%s' to '%s' = %d\n";
const char var7f1b3364[] = "OI! DUPLICATE FILE NAME! NO!\n";
const char var7f1b3384[] = "()()()()()() Writing MPLAYER\n";
const char var7f1b33a4[] = "()()()()()() Writing MGAME\n";
const char var7f1b33c0[] = "Write Attempt Made...\n";
const char var7f1b33d8[] = "decided location: %d\n";
const char var7f1b33f0[] = "%s\n";
const char var7f1b33f4[] = "\n";
const char var7f1b33f8[] = "%d";
const char var7f1b33fc[] = "GOT OKed!, item->data = %d\n";
const char var7f1b3418[] = "GOT CANCELLED!\n";
const char var7f1b3428[] = "Picking Location, type %d wadtype %d wad %d\n";
const char var7f1b3458[] = "Torching file %d\n";
const char var7f1b346c[] = "Copying file %d\n";
const char var7f1b3480[] = "item: %x\n";
const char var7f1b348c[] = "Switched Wads Back\n";
const char var7f1b34a0[] = "MenuClosed\n";
const char var7f1b34ac[] = "Deleting files, wad %d\n";
const char var7f1b34c4[] = "%d:\n";
const char var7f1b34cc[] = "%s\n";
const char var7f1b34d0[] = "%s\n";
const char var7f1b34d4[] = "%d\n";
const char var7f1b34d8[] = "";
const char var7f1b34dc[] = "GOT OKed!\n";
const char var7f1b34e8[] = "Try to find last opened file...\n";
const char var7f1b350c[] = "%s %s";
const char var7f1b3514[] = "\n";
const char var7f1b3518[] = "%s %d:%02d:%02d";
const char var7f1b3528[] = "%s %02d:%02d";
const char var7f1b3538[] = ".%02d";
const char var7f1b3540[] = "%s %d\n";

const u32 var7f1b3548[] = {0x7f108544};
const u32 var7f1b354c[] = {0x7f108544};
const u32 var7f1b3550[] = {0x7f108544};
const u32 var7f1b3554[] = {0x7f10853c};
const u32 var7f1b3558[] = {0x7f10853c};
const u32 var7f1b355c[] = {0x7f108544};
const u32 var7f1b3560[] = {0x7f10853c};
const u32 var7f1b3564[] = {0x7f108544};
const u32 var7f1b3568[] = {0x7f108828};
const u32 var7f1b356c[] = {0x7f108848};
const u32 var7f1b3570[] = {0x7f108828};
const u32 var7f1b3574[] = {0x7f108888};
const u32 var7f1b3578[] = {0x7f108868};
const u32 var7f1b357c[] = {0x7f108868};
const u32 var7f1b3580[] = {0x7f108868};
const u32 var7f1b3584[] = {0x7f108838};
const u32 var7f1b3588[] = {0x7f108838};
const u32 var7f1b358c[] = {0x7f108838};
const u32 var7f1b3590[] = {0x7f108858};
const u32 var7f1b3594[] = {0x7f108838};
const u32 var7f1b3598[] = {0x7f108888};
const u32 var7f1b359c[] = {0x7f108878};
const u32 var7f1b35a0[] = {0x7f108878};
const u32 var7f1b35a4[] = {0x7f108878};
const u32 var7f1b35a8[] = {0x7f108944};
const u32 var7f1b35ac[] = {0x7f108964};
const u32 var7f1b35b0[] = {0x7f108954};
const u32 var7f1b35b4[] = {0x7f108974};
const u32 var7f1b35b8[] = {0x7f108944};
const u32 var7f1b35bc[] = {0x7f108954};
const u32 var7f1b35c0[] = {0x7f108964};
const u32 var7f1b35c4[] = {0x7f108944};
const u32 var7f1b35c8[] = {0x7f108944};
const u32 var7f1b35cc[] = {0x7f108944};
const u32 var7f1b35d0[] = {0x7f108964};
const u32 var7f1b35d4[] = {0x7f108954};
const u32 var7f1b35d8[] = {0x7f108974};
const u32 var7f1b35dc[] = {0x7f108944};
const u32 var7f1b35e0[] = {0x7f108954};
const u32 var7f1b35e4[] = {0x7f108964};
const u32 var7f1b35e8[] = {0x7f108a70};
const u32 var7f1b35ec[] = {0x7f108a70};
const u32 var7f1b35f0[] = {0x7f108a70};
const u32 var7f1b35f4[] = {0x7f108a70};
const u32 var7f1b35f8[] = {0x7f108a20};
const u32 var7f1b35fc[] = {0x7f108a20};
const u32 var7f1b3600[] = {0x7f108a20};
const u32 var7f1b3604[] = {0x7f108a70};
const u32 var7f1b3608[] = {0x7f108a70};
const u32 var7f1b360c[] = {0x7f108a70};
const u32 var7f1b3610[] = {0x7f108a70};
const u32 var7f1b3614[] = {0x7f108a70};
const u32 var7f1b3618[] = {0x7f108a70};
const u32 var7f1b361c[] = {0x7f108a20};
const u32 var7f1b3620[] = {0x7f108a20};
const u32 var7f1b3624[] = {0x7f108a20};
const u32 var7f1b3628[] = {0x7f108b70};
const u32 var7f1b362c[] = {0x7f108be0};
const u32 var7f1b3630[] = {0x7f108be0};
const u32 var7f1b3634[] = {0x7f108be0};
const u32 var7f1b3638[] = {0x7f108bcc};
const u32 var7f1b363c[] = {0x7f108bcc};
const u32 var7f1b3640[] = {0x7f108bcc};
const u32 var7f1b3644[] = {0x7f108be0};
const u32 var7f1b3648[] = {0x7f108be0};
const u32 var7f1b364c[] = {0x7f108be0};
const u32 var7f1b3650[] = {0x7f108be0};
const u32 var7f1b3654[] = {0x7f108be0};
const u32 var7f1b3658[] = {0x7f108be0};
const u32 var7f1b365c[] = {0x7f108b18};
const u32 var7f1b3660[] = {0x7f108b18};
const u32 var7f1b3664[] = {0x7f108b18};
const u32 var7f1b3668[] = {0x7f108c94};
const u32 var7f1b366c[] = {0x7f108c94};
const u32 var7f1b3670[] = {0x7f108c94};
const u32 var7f1b3674[] = {0x7f108c9c};
const u32 var7f1b3678[] = {0x7f108ca8};
const u32 var7f1b367c[] = {0x7f108cb0};
const u32 var7f1b3680[] = {0x7f108c94};
const u32 var7f1b3684[] = {0x7f108ca8};
const u32 var7f1b3688[] = {0x7f108c9c};
const u32 var7f1b368c[] = {0x7f1093c4};
const u32 var7f1b3690[] = {0x7f1093d4};
const u32 var7f1b3694[] = {0x7f1093f0};
const u32 var7f1b3698[] = {0x7f109420};
const u32 var7f1b369c[] = {0x7f109408};
const u32 var7f1b36a0[] = {0x7f109408};
const u32 var7f1b36a4[] = {0x7f109408};
const u32 var7f1b36a8[] = {0x7f1092b8};
const u32 var7f1b36ac[] = {0x7f1092b8};
const u32 var7f1b36b0[] = {0x7f1092b0};
const u32 var7f1b36b4[] = {0x7f1092d0};
const u32 var7f1b36b8[] = {0x7f1092ec};
const u32 var7f1b36bc[] = {0x7f109420};
const u32 var7f1b36c0[] = {0x7f10930c};
const u32 var7f1b36c4[] = {0x7f10930c};
const u32 var7f1b36c8[] = {0x7f10930c};
const u32 var7f1b36cc[] = {0x7f109acc};
const u32 var7f1b36d0[] = {0x7f109ae4};
const u32 var7f1b36d4[] = {0x7f109ae4};
const u32 var7f1b36d8[] = {0x7f109ae4};
const u32 var7f1b36dc[] = {0x7f109ae4};
const u32 var7f1b36e0[] = {0x7f109ba0};
const u32 var7f1b36e4[] = {0x7f109af8};
const u32 var7f1b36e8[] = {0x7f109b90};
const u32 var7f1b36ec[] = {0x7f109ba0};
const u32 var7f1b36f0[] = {0x7f109acc};
const u32 var7f1b36f4[] = {0x7f109acc};
const u32 var7f1b36f8[] = {0x7f109acc};
const u32 var7f1b36fc[] = {0x7f109af8};
const u32 var7f1b3700[] = {0x7f109b90};
const u32 var7f1b3704[] = {0x7f109ba0};
const u32 var7f1b3708[] = {0x7f109ae4};
const u32 var7f1b370c[] = {0x7f109ae4};
const u32 var7f1b3710[] = {0x7f109ae4};
const u32 var7f1b3714[] = {0x7f109c14};
const u32 var7f1b3718[] = {0x7f109c2c};
const u32 var7f1b371c[] = {0x7f109c2c};
const u32 var7f1b3720[] = {0x7f109c2c};
const u32 var7f1b3724[] = {0x7f109c2c};
const u32 var7f1b3728[] = {0x7f109c7c};
const u32 var7f1b372c[] = {0x7f109c40};
const u32 var7f1b3730[] = {0x7f109c6c};
const u32 var7f1b3734[] = {0x7f109c7c};
const u32 var7f1b3738[] = {0x7f109c14};
const u32 var7f1b373c[] = {0x7f109c14};
const u32 var7f1b3740[] = {0x7f109c14};
const u32 var7f1b3744[] = {0x7f109c40};
const u32 var7f1b3748[] = {0x7f109c6c};
const u32 var7f1b374c[] = {0x7f109c7c};
const u32 var7f1b3750[] = {0x7f109c2c};
const u32 var7f1b3754[] = {0x7f109c2c};
const u32 var7f1b3758[] = {0x7f109c2c};
const u32 var7f1b375c[] = {0x7f10ab8c};
const u32 var7f1b3760[] = {0x7f10ad40};
const u32 var7f1b3764[] = {0x7f10ad80};
const u32 var7f1b3768[] = {0x7f10ad4c};
const u32 var7f1b376c[] = {0x7f10ad64};
const u32 var7f1b3770[] = {0x7f10ad80};
const u32 var7f1b3774[] = {0x7f10ab7c};
const u32 var7f1b3778[] = {0x7f10ad80};
const u32 var7f1b377c[] = {0x7f10ad80};
const u32 var7f1b3780[] = {0x7f10ad80};
const u32 var7f1b3784[] = {0x7f10ad80};
const u32 var7f1b3788[] = {0x7f10ad80};
const u32 var7f1b378c[] = {0x7f10ad80};
const u32 var7f1b3790[] = {0x7f10ad80};
const u32 var7f1b3794[] = {0x7f10ad80};
const u32 var7f1b3798[] = {0x7f10ad80};
const u32 var7f1b379c[] = {0x7f10ad80};
const u32 var7f1b37a0[] = {0x7f10ad80};
const u32 var7f1b37a4[] = {0x7f10ab98};
const u32 var7f1b37a8[] = {0x7f10ad34};
const u32 var7f1b37ac[] = {0x7f10b2c8};
const u32 var7f1b37b0[] = {0x7f10b65c};
const u32 var7f1b37b4[] = {0x7f10b65c};
const u32 var7f1b37b8[] = {0x7f10b65c};
const u32 var7f1b37bc[] = {0x7f10b65c};
const u32 var7f1b37c0[] = {0x7f10b604};
const u32 var7f1b37c4[] = {0x7f10b2b8};
const u32 var7f1b37c8[] = {0x7f10b65c};
const u32 var7f1b37cc[] = {0x7f10b65c};
const u32 var7f1b37d0[] = {0x7f10b65c};
const u32 var7f1b37d4[] = {0x7f10b65c};
const u32 var7f1b37d8[] = {0x7f10b65c};
const u32 var7f1b37dc[] = {0x7f10b65c};
const u32 var7f1b37e0[] = {0x7f10b65c};
const u32 var7f1b37e4[] = {0x7f10b65c};
const u32 var7f1b37e8[] = {0x7f10b65c};
const u32 var7f1b37ec[] = {0x7f10b65c};
const u32 var7f1b37f0[] = {0x7f10b65c};
const u32 var7f1b37f4[] = {0x7f10b2d4};
const u32 var7f1b37f8[] = {0x7f10b5f8};
const u32 var7f1b37fc[] = {0x7f10bf70};
const u32 var7f1b3800[] = {0x7f10c768};
const u32 var7f1b3804[] = {0x7f10c7ec};
const u32 var7f1b3808[] = {0x7f10c778};
const u32 var7f1b380c[] = {0x7f10c7b0};
const u32 var7f1b3810[] = {0x7f10c6fc};
const u32 var7f1b3814[] = {0x7f10bdb4};
const u32 var7f1b3818[] = {0x7f10c7ec};
const u32 var7f1b381c[] = {0x7f10c7ec};
const u32 var7f1b3820[] = {0x7f10c7ec};
const u32 var7f1b3824[] = {0x7f10c7ec};
const u32 var7f1b3828[] = {0x7f10c7ec};
const u32 var7f1b382c[] = {0x7f10c7ec};
const u32 var7f1b3830[] = {0x7f10c7ec};
const u32 var7f1b3834[] = {0x7f10c7ec};
const u32 var7f1b3838[] = {0x7f10c7ec};
const u32 var7f1b383c[] = {0x7f10c7ec};
const u32 var7f1b3840[] = {0x7f10c7ec};
const u32 var7f1b3844[] = {0x7f10bf80};
const u32 var7f1b3848[] = {0x7f10c6f0};
const u32 var7f1b384c[] = {0x7f10c7ec};
const u32 var7f1b3850[] = {0x7f10c7ec};
const u32 var7f1b3854[] = {0x7f10c7ec};
const u32 var7f1b3858[] = {0x7f10c7ec};
const u32 var7f1b385c[] = {0x7f10bdc4};

GLOBAL_ASM(
glabel func0f107fb0
/*  f107fb0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f107fb4:	3c0e8007 */ 	lui	$t6,%hi(iomessages)
/*  f107fb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f107fbc:	25ce4380 */ 	addiu	$t6,$t6,%lo(iomessages)
/*  f107fc0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f107fc4:	27a2001c */ 	addiu	$v0,$sp,0x1c
/*  f107fc8:	00044040 */ 	sll	$t0,$a0,0x1
/*  f107fcc:	ac410000 */ 	sw	$at,0x0($v0)
/*  f107fd0:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f107fd4:	00484821 */ 	addu	$t1,$v0,$t0
/*  f107fd8:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f107fdc:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f107fe0:	ac410008 */ 	sw	$at,0x8($v0)
/*  f107fe4:	28810006 */ 	slti	$at,$a0,0x6
/*  f107fe8:	50200006 */ 	beqzl	$at,.L0f108004
/*  f107fec:	00001025 */ 	or	$v0,$zero,$zero
/*  f107ff0:	0fc5b9f1 */ 	jal	textGet
/*  f107ff4:	95240000 */ 	lhu	$a0,0x0($t1)
/*  f107ff8:	10000003 */ 	beqz	$zero,.L0f108008
/*  f107ffc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108000:	00001025 */ 	or	$v0,$zero,$zero
.L0f108004:
/*  f108004:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108008:
/*  f108008:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10800c:	03e00008 */ 	jr	$ra
/*  f108010:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler00108014(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MenuStack[g_MpPlayerNum].unk944_01 > 4) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f108078
/*  f108078:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10807c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108080:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108084:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f108088:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10808c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108090:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108094:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108098:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10809c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1080a0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1080a4:	3c04800a */ 	lui	$a0,0x800a
/*  f1080a8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f1080ac:	9084ee3c */ 	lbu	$a0,-0x11c4($a0)
/*  f1080b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1080b4:	3098007f */ 	andi	$t8,$a0,0x7f
/*  f1080b8:	0fc41fec */ 	jal	func0f107fb0
/*  f1080bc:	03002025 */ 	or	$a0,$t8,$zero
/*  f1080c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1080c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1080c8:	03e00008 */ 	jr	$ra
/*  f1080cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1080d0
/*  f1080d0:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f1080d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1080d8:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f1080dc:	10c00008 */ 	beqz	$a2,.L0f108100
/*  f1080e0:	00a03825 */ 	or	$a3,$a1,$zero
/*  f1080e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1080e8:	10c10005 */ 	beq	$a2,$at,.L0f108100
/*  f1080ec:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1080f0:	10c10009 */ 	beq	$a2,$at,.L0f108118
/*  f1080f4:	24e40006 */ 	addiu	$a0,$a3,0x6
/*  f1080f8:	1000004d */ 	beqz	$zero,.L0f108230
/*  f1080fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108100:
/*  f108100:	24e40006 */ 	addiu	$a0,$a3,0x6
/*  f108104:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f108108:	0fc35593 */ 	jal	func0f0d564c
/*  f10810c:	00003025 */ 	or	$a2,$zero,$zero
/*  f108110:	10000047 */ 	beqz	$zero,.L0f108230
/*  f108114:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108118:
/*  f108118:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f10811c:	0fc63669 */ 	jal	func0f18d9a4
/*  f108120:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f108124:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f00)
/*  f108128:	24a52f00 */ 	addiu	$a1,$a1,%lo(var7f1b2f00)
/*  f10812c:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f108130:	0c004dad */ 	jal	sprintf
/*  f108134:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f108138:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f10813c:	3c0107ff */ 	lui	$at,0x7ff
/*  f108140:	3421ffff */ 	ori	$at,$at,0xffff
/*  f108144:	00a1082b */ 	sltu	$at,$a1,$at
/*  f108148:	14200008 */ 	bnez	$at,.L0f10816c
/*  f10814c:	00404025 */ 	or	$t0,$v0,$zero
/*  f108150:	27ae0058 */ 	addiu	$t6,$sp,0x58
/*  f108154:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f04)
/*  f108158:	24a52f04 */ 	addiu	$a1,$a1,%lo(var7f1b2f04)
/*  f10815c:	0c004dad */ 	jal	sprintf
/*  f108160:	010e2021 */ 	addu	$a0,$t0,$t6
/*  f108164:	10000032 */ 	beqz	$zero,.L0f108230
/*  f108168:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10816c:
/*  f10816c:	2404003c */ 	addiu	$a0,$zero,0x3c
/*  f108170:	00a4001b */ 	divu	$zero,$a1,$a0
/*  f108174:	00004810 */ 	mfhi	$t1
/*  f108178:	00002812 */ 	mflo	$a1
/*  f10817c:	24070018 */ 	addiu	$a3,$zero,0x18
/*  f108180:	14800002 */ 	bnez	$a0,.L0f10818c
/*  f108184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108188:	0007000d */ 	break	0x7
.L0f10818c:
/*  f10818c:	00a4001b */ 	divu	$zero,$a1,$a0
/*  f108190:	00001012 */ 	mflo	$v0
/*  f108194:	00007810 */ 	mfhi	$t7
/*  f108198:	afaf0034 */ 	sw	$t7,0x34($sp)
/*  f10819c:	14800002 */ 	bnez	$a0,.L0f1081a8
/*  f1081a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1081a4:	0007000d */ 	break	0x7
.L0f1081a8:
/*  f1081a8:	0047001a */ 	div	$zero,$v0,$a3
/*  f1081ac:	00001812 */ 	mflo	$v1
/*  f1081b0:	0000c010 */ 	mfhi	$t8
/*  f1081b4:	00603025 */ 	or	$a2,$v1,$zero
/*  f1081b8:	14e00002 */ 	bnez	$a3,.L0f1081c4
/*  f1081bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1081c0:	0007000d */ 	break	0x7
.L0f1081c4:
/*  f1081c4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1081c8:	14e10004 */ 	bne	$a3,$at,.L0f1081dc
/*  f1081cc:	3c018000 */ 	lui	$at,0x8000
/*  f1081d0:	14410002 */ 	bne	$v0,$at,.L0f1081dc
/*  f1081d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1081d8:	0006000d */ 	break	0x6
.L0f1081dc:
/*  f1081dc:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f1081e0:	1460000b */ 	bnez	$v1,.L0f108210
/*  f1081e4:	afa50040 */ 	sw	$a1,0x40($sp)
/*  f1081e8:	27b90058 */ 	addiu	$t9,$sp,0x58
/*  f1081ec:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f0c)
/*  f1081f0:	24a52f0c */ 	addiu	$a1,$a1,%lo(var7f1b2f0c)
/*  f1081f4:	01192021 */ 	addu	$a0,$t0,$t9
/*  f1081f8:	03003025 */ 	or	$a2,$t8,$zero
/*  f1081fc:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f108200:	0c004dad */ 	jal	sprintf
/*  f108204:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f108208:	10000009 */ 	beqz	$zero,.L0f108230
/*  f10820c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108210:
/*  f108210:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f108214:	27aa0058 */ 	addiu	$t2,$sp,0x58
/*  f108218:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f14)
/*  f10821c:	24a52f14 */ 	addiu	$a1,$a1,%lo(var7f1b2f14)
/*  f108220:	010a2021 */ 	addu	$a0,$t0,$t2
/*  f108224:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f108228:	0c004dad */ 	jal	sprintf
/*  f10822c:	afab0010 */ 	sw	$t3,0x10($sp)
.L0f108230:
/*  f108230:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f24)
/*  f108234:	24a52f24 */ 	addiu	$a1,$a1,%lo(var7f1b2f24)
/*  f108238:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f10823c:	0c004dad */ 	jal	sprintf
/*  f108240:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f108244:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f108248:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*  f10824c:	03e00008 */ 	jr	$ra
/*  f108250:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler00108254(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MenuStack[g_MpPlayerNum].unk940 == 0) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f1082b0
/*  f1082b0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1082b4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1082b8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f1082bc:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f1082c0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1082c4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1082c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1082cc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1082d0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1082d4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1082d8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1082dc:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f1082e0:	8c450e38 */ 	lw	$a1,0xe38($v0)
/*  f1082e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1082e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1082ec:	10a00008 */ 	beqz	$a1,.L0f108310
/*  f1082f0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1082f4:	3c048007 */ 	lui	$a0,0x8007
/*  f1082f8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1082fc:	0fc42034 */ 	jal	func0f1080d0
/*  f108300:	90460e3d */ 	lbu	$a2,0xe3d($v0)
/*  f108304:	3c028007 */ 	lui	$v0,0x8007
/*  f108308:	10000002 */ 	beqz	$zero,.L0f108314
/*  f10830c:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f108310:
/*  f108310:	00001025 */ 	or	$v0,$zero,$zero
.L0f108314:
/*  f108314:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108318:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10831c:	03e00008 */ 	jr	$ra
/*  f108320:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f108324
/*  f108324:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108328:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10832c:	0fc479ac */ 	jal	func0f11e6b0
/*  f108330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108334:	0440000e */ 	bltz	$v0,.L0f108370
/*  f108338:	3c198007 */ 	lui	$t9,0x8007
/*  f10833c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108340:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108344:	3c01800a */ 	lui	$at,0x800a
/*  f108348:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10834c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108350:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108354:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108358:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10835c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108360:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108364:	002f0821 */ 	addu	$at,$at,$t7
/*  f108368:	1000000d */ 	beqz	$zero,.L0f1083a0
/*  f10836c:	a022ee3c */ 	sb	$v0,-0x11c4($at)
.L0f108370:
/*  f108370:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f108374:	3c01800a */ 	lui	$at,0x800a
/*  f108378:	24180005 */ 	addiu	$t8,$zero,0x5
/*  f10837c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f108380:	01194023 */ 	subu	$t0,$t0,$t9
/*  f108384:	00084080 */ 	sll	$t0,$t0,0x2
/*  f108388:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10838c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f108390:	01194023 */ 	subu	$t0,$t0,$t9
/*  f108394:	00084100 */ 	sll	$t0,$t0,0x4
/*  f108398:	00280821 */ 	addu	$at,$at,$t0
/*  f10839c:	a038ee3c */ 	sb	$t8,-0x11c4($at)
.L0f1083a0:
/*  f1083a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1083a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1083a8:	03e00008 */ 	jr	$ra
/*  f1083ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1083b0
/*  f1083b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1083b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1083b8:	0fc420c9 */ 	jal	func0f108324
/*  f1083bc:	94840004 */ 	lhu	$a0,0x4($a0)
/*  f1083c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1083c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1083c8:	03e00008 */ 	jr	$ra
/*  f1083cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1083d0
/*  f1083d0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1083d4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1083d8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f1083dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1083e0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1083e4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1083e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1083ec:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1083f0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1083f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1083f8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1083fc:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f108400:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108404:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f108408:	a0450e3d */ 	sb	$a1,0xe3d($v0)
/*  f10840c:	0fc420ec */ 	jal	func0f1083b0
/*  f108410:	ac440e38 */ 	sw	$a0,0xe38($v0)
/*  f108414:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108418:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10841c:	03e00008 */ 	jr	$ra
/*  f108420:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f108424
/*  f108424:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108428:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10842c:	3c18800a */ 	lui	$t8,0x800a
/*  f108430:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108434:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108438:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10843c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108440:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108444:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108448:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10844c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108450:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f108454:	9718ee34 */ 	lhu	$t8,-0x11cc($t8)
/*  f108458:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10845c:	3c048007 */ 	lui	$a0,0x8007
/*  f108460:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f108464:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108468:	00992021 */ 	addu	$a0,$a0,$t9
/*  f10846c:	0fc5b9f1 */ 	jal	textGet
/*  f108470:	9484438c */ 	lhu	$a0,0x438c($a0)
/*  f108474:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108478:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10847c:	03e00008 */ 	jr	$ra
/*  f108480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108484:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108488:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10848c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108490:	3c048007 */ 	lui	$a0,0x8007
/*  f108494:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f4c)
/*  f108498:	24a52f4c */ 	addiu	$a1,$a1,%lo(var7f1b2f4c)
/*  f10849c:	0c004dad */ 	jal	sprintf
/*  f1084a0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1084a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1084a8:	3c028007 */ 	lui	$v0,0x8007
/*  f1084ac:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1084b0:	03e00008 */ 	jr	$ra
/*  f1084b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel menuhandler001084b8
/*  f1084b8:	24010018 */ 	addiu	$at,$zero,0x18
/*  f1084bc:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f1084c0:	14810020 */ 	bne	$a0,$at,.L0f108544
/*  f1084c4:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f1084c8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1084cc:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1084d0:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f1084d4:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f1084d8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1084dc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1084e0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1084e4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1084e8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1084ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1084f0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1084f4:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f1084f8:	90590e3c */ 	lbu	$t9,0xe3c($v0)
/*  f1084fc:	3328007f */ 	andi	$t0,$t9,0x7f
/*  f108500:	29010005 */ 	slti	$at,$t0,0x5
/*  f108504:	54200004 */ 	bnezl	$at,.L0f108518
/*  f108508:	94490e34 */ 	lhu	$t1,0xe34($v0)
/*  f10850c:	03e00008 */ 	jr	$ra
/*  f108510:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f108514:	94490e34 */ 	lhu	$t1,0xe34($v0)
.L0f108518:
/*  f108518:	252affff */ 	addiu	$t2,$t1,-1
/*  f10851c:	2d410008 */ 	sltiu	$at,$t2,0x8
/*  f108520:	10200006 */ 	beqz	$at,.L0f10853c
/*  f108524:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f108528:	3c017f1b */ 	lui	$at,%hi(var7f1b3548)
/*  f10852c:	002a0821 */ 	addu	$at,$at,$t2
/*  f108530:	8c2a3548 */ 	lw	$t2,%lo(var7f1b3548)($at)
/*  f108534:	01400008 */ 	jr	$t2
/*  f108538:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10853c:
/*  f10853c:	03e00008 */ 	jr	$ra
/*  f108540:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f108544:
/*  f108544:	00001025 */ 	or	$v0,$zero,$zero
/*  f108548:	03e00008 */ 	jr	$ra
/*  f10854c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f108550
/*  f108550:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108554:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108558:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10855c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f108560:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108564:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108568:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10856c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108570:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108574:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108578:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10857c:	3c04800a */ 	lui	$a0,0x800a
/*  f108580:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f108584:	9084ee3c */ 	lbu	$a0,-0x11c4($a0)
/*  f108588:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10858c:	3098007f */ 	andi	$t8,$a0,0x7f
/*  f108590:	0fc41fec */ 	jal	func0f107fb0
/*  f108594:	03002025 */ 	or	$a0,$t8,$zero
/*  f108598:	3c078007 */ 	lui	$a3,%hi(var80071440)
/*  f10859c:	24e71440 */ 	addiu	$a3,$a3,%lo(var80071440)
/*  f1085a0:	3c057f1b */ 	lui	$a1,%hi(var7f1b2f68)
/*  f1085a4:	24a52f68 */ 	addiu	$a1,$a1,%lo(var7f1b2f68)
/*  f1085a8:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f1085ac:	0c004dad */ 	jal	sprintf
/*  f1085b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f1085b4:	3c198007 */ 	lui	$t9,0x8007
/*  f1085b8:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f1085bc:	3c09800a */ 	lui	$t1,0x800a
/*  f1085c0:	3c078007 */ 	lui	$a3,%hi(var80071440)
/*  f1085c4:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f1085c8:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1085cc:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1085d0:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1085d4:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1085d8:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1085dc:	00084100 */ 	sll	$t0,$t0,0x4
/*  f1085e0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1085e4:	9529ee34 */ 	lhu	$t1,-0x11cc($t1)
/*  f1085e8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1085ec:	24e71440 */ 	addiu	$a3,$a3,%lo(var80071440)
/*  f1085f0:	11210015 */ 	beq	$t1,$at,.L0f108648
/*  f1085f4:	240c003a */ 	addiu	$t4,$zero,0x3a
/*  f1085f8:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f1085fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f108600:	908a0000 */ 	lbu	$t2,0x0($a0)
/*  f108604:	00801025 */ 	or	$v0,$a0,$zero
/*  f108608:	51400007 */ 	beqzl	$t2,.L0f108628
/*  f10860c:	00836821 */ 	addu	$t5,$a0,$v1
/*  f108610:	904b0001 */ 	lbu	$t3,0x1($v0)
.L0f108614:
/*  f108614:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f108618:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10861c:	5560fffd */ 	bnezl	$t3,.L0f108614
/*  f108620:	904b0001 */ 	lbu	$t3,0x1($v0)
/*  f108624:	00836821 */ 	addu	$t5,$a0,$v1
.L0f108628:
/*  f108628:	a1acffff */ 	sb	$t4,-0x1($t5)
/*  f10862c:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f108630:	240e000a */ 	addiu	$t6,$zero,0xa
/*  f108634:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f108638:	a30e0000 */ 	sb	$t6,0x0($t8)
/*  f10863c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f108640:	03234021 */ 	addu	$t0,$t9,$v1
/*  f108644:	a1000001 */ 	sb	$zero,0x1($t0)
.L0f108648:
/*  f108648:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10864c:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f108650:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f108654:	03e00008 */ 	jr	$ra
/*  f108658:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10865c
/*  f10865c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108660:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108664:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108668:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10866c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108670:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108674:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108678:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10867c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108680:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108684:	00802825 */ 	or	$a1,$a0,$zero
/*  f108688:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10868c:	3c01800a */ 	lui	$at,0x800a
/*  f108690:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108694:	002f0821 */ 	addu	$at,$at,$t7
/*  f108698:	3c048007 */ 	lui	$a0,%hi(menudialog_1a410)
/*  f10869c:	a425ee34 */ 	sh	$a1,-0x11cc($at)
/*  f1086a0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1086a4:	248443f0 */ 	addiu	$a0,$a0,%lo(menudialog_1a410)
/*  f1086a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1086ac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1086b0:	03e00008 */ 	jr	$ra
/*  f1086b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1086b8
/*  f1086b8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1086bc:	3c0e8007 */ 	lui	$t6,%hi(savelocations2)
/*  f1086c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1086c4:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f1086c8:	25ce4408 */ 	addiu	$t6,$t6,%lo(savelocations2)
/*  f1086cc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1086d0:	27a8002c */ 	addiu	$t0,$sp,0x2c
/*  f1086d4:	00044880 */ 	sll	$t1,$a0,0x2
/*  f1086d8:	ad010000 */ 	sw	$at,0x0($t0)
/*  f1086dc:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1086e0:	3c038007 */ 	lui	$v1,0x8007
/*  f1086e4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f1086e8:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f1086ec:	95c10008 */ 	lhu	$at,0x8($t6)
/*  f1086f0:	00691821 */ 	addu	$v1,$v1,$t1
/*  f1086f4:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f1086f8:	a5010008 */ 	sh	$at,0x8($t0)
/*  f1086fc:	8c635bc0 */ 	lw	$v1,0x5bc0($v1)
/*  f108700:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f108704:	00003825 */ 	or	$a3,$zero,$zero
.L0f108708:
/*  f108708:	80640300 */ 	lb	$a0,0x300($v1)
/*  f10870c:	50a40010 */ 	beql	$a1,$a0,.L0f108750
/*  f108710:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f108714:	5440000d */ 	bnezl	$v0,.L0f10874c
/*  f108718:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f10871c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f108720:	24010004 */ 	addiu	$at,$zero,0x4
/*  f108724:	00075840 */ 	sll	$t3,$a3,0x1
/*  f108728:	15410005 */ 	bne	$t2,$at,.L0f108740
/*  f10872c:	010b6021 */ 	addu	$t4,$t0,$t3
/*  f108730:	0fc5b9f1 */ 	jal	textGet
/*  f108734:	95840000 */ 	lhu	$a0,0x0($t4)
/*  f108738:	10000009 */ 	beqz	$zero,.L0f108760
/*  f10873c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108740:
/*  f108740:	10000006 */ 	beqz	$zero,.L0f10875c
/*  f108744:	00801025 */ 	or	$v0,$a0,$zero
/*  f108748:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f10874c:
/*  f10874c:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f108750:
/*  f108750:	14e6ffed */ 	bne	$a3,$a2,.L0f108708
/*  f108754:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f108758:	00001025 */ 	or	$v0,$zero,$zero
.L0f10875c:
/*  f10875c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108760:
/*  f108760:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f108764:	03e00008 */ 	jr	$ra
/*  f108768:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10876c
/*  f10876c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f108770:	3c0f8007 */ 	lui	$t7,%hi(iomessages2)
/*  f108774:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108778:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f10877c:	25ef4414 */ 	addiu	$t7,$t7,%lo(iomessages2)
/*  f108780:	8de10000 */ 	lw	$at,0x0($t7)
/*  f108784:	27ae001c */ 	addiu	$t6,$sp,0x1c
/*  f108788:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f10878c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f108790:	8de10008 */ 	lw	$at,0x8($t7)
/*  f108794:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f108798:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f10879c:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1087a0:	95e10010 */ 	lhu	$at,0x10($t7)
/*  f1087a4:	3c098007 */ 	lui	$t1,0x8007
/*  f1087a8:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1087ac:	a5c10010 */ 	sh	$at,0x10($t6)
/*  f1087b0:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f1087b4:	3c02800a */ 	lui	$v0,0x800a
/*  f1087b8:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1087bc:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1087c0:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1087c4:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1087c8:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1087cc:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1087d0:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f1087d4:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f1087d8:	9042ee42 */ 	lbu	$v0,-0x11be($v0)
/*  f1087dc:	28410009 */ 	slti	$at,$v0,0x9
/*  f1087e0:	14200009 */ 	bnez	$at,.L0f108808
/*  f1087e4:	244bff9c */ 	addiu	$t3,$v0,-100
/*  f1087e8:	2d610007 */ 	sltiu	$at,$t3,0x7
/*  f1087ec:	10200026 */ 	beqz	$at,.L0f108888
/*  f1087f0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1087f4:	3c017f1b */ 	lui	$at,%hi(var7f1b3568)
/*  f1087f8:	002b0821 */ 	addu	$at,$at,$t3
/*  f1087fc:	8c2b3568 */ 	lw	$t3,%lo(var7f1b3568)($at)
/*  f108800:	01600008 */ 	jr	$t3
/*  f108804:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108808:
/*  f108808:	2c410009 */ 	sltiu	$at,$v0,0x9
/*  f10880c:	1020001e */ 	beqz	$at,.L0f108888
/*  f108810:	00026080 */ 	sll	$t4,$v0,0x2
/*  f108814:	3c017f1b */ 	lui	$at,%hi(var7f1b3584)
/*  f108818:	002c0821 */ 	addu	$at,$at,$t4
/*  f10881c:	8c2c3584 */ 	lw	$t4,%lo(var7f1b3584)($at)
/*  f108820:	01800008 */ 	jr	$t4
/*  f108824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108828:	0fc5b9f1 */ 	jal	textGet
/*  f10882c:	97a4001c */ 	lhu	$a0,0x1c($sp)
/*  f108830:	10000018 */ 	beqz	$zero,.L0f108894
/*  f108834:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108838:	0fc5b9f1 */ 	jal	textGet
/*  f10883c:	97a4001e */ 	lhu	$a0,0x1e($sp)
/*  f108840:	10000014 */ 	beqz	$zero,.L0f108894
/*  f108844:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108848:	0fc5b9f1 */ 	jal	textGet
/*  f10884c:	97a40020 */ 	lhu	$a0,0x20($sp)
/*  f108850:	10000010 */ 	beqz	$zero,.L0f108894
/*  f108854:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108858:	0fc5b9f1 */ 	jal	textGet
/*  f10885c:	97a40022 */ 	lhu	$a0,0x22($sp)
/*  f108860:	1000000c */ 	beqz	$zero,.L0f108894
/*  f108864:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108868:	0fc5b9f1 */ 	jal	textGet
/*  f10886c:	97a40028 */ 	lhu	$a0,0x28($sp)
/*  f108870:	10000008 */ 	beqz	$zero,.L0f108894
/*  f108874:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108878:	0fc5b9f1 */ 	jal	textGet
/*  f10887c:	97a4002a */ 	lhu	$a0,0x2a($sp)
/*  f108880:	10000004 */ 	beqz	$zero,.L0f108894
/*  f108884:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108888:
/*  f108888:	0fc5b9f1 */ 	jal	textGet
/*  f10888c:	97a4002c */ 	lhu	$a0,0x2c($sp)
/*  f108890:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108894:
/*  f108894:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f108898:	03e00008 */ 	jr	$ra
/*  f10889c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1088a0
/*  f1088a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1088a4:	3c0f8007 */ 	lui	$t7,%hi(filetypenames)
/*  f1088a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1088ac:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1088b0:	25ef4428 */ 	addiu	$t7,$t7,%lo(filetypenames)
/*  f1088b4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1088b8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1088bc:	27ae0020 */ 	addiu	$t6,$sp,0x20
/*  f1088c0:	3c098007 */ 	lui	$t1,0x8007
/*  f1088c4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1088c8:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1088cc:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f1088d0:	3c02800a */ 	lui	$v0,0x800a
/*  f1088d4:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1088d8:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1088dc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1088e0:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1088e4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1088e8:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1088ec:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f1088f0:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f1088f4:	9042ee42 */ 	lbu	$v0,-0x11be($v0)
/*  f1088f8:	28410009 */ 	slti	$at,$v0,0x9
/*  f1088fc:	14200009 */ 	bnez	$at,.L0f108924
/*  f108900:	244bff9c */ 	addiu	$t3,$v0,-100
/*  f108904:	2d610007 */ 	sltiu	$at,$t3,0x7
/*  f108908:	1020001a */ 	beqz	$at,.L0f108974
/*  f10890c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f108910:	3c017f1b */ 	lui	$at,%hi(var7f1b35a8)
/*  f108914:	002b0821 */ 	addu	$at,$at,$t3
/*  f108918:	8c2b35a8 */ 	lw	$t3,%lo(var7f1b35a8)($at)
/*  f10891c:	01600008 */ 	jr	$t3
/*  f108920:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108924:
/*  f108924:	2c410009 */ 	sltiu	$at,$v0,0x9
/*  f108928:	10200012 */ 	beqz	$at,.L0f108974
/*  f10892c:	00026080 */ 	sll	$t4,$v0,0x2
/*  f108930:	3c017f1b */ 	lui	$at,%hi(var7f1b35c4)
/*  f108934:	002c0821 */ 	addu	$at,$at,$t4
/*  f108938:	8c2c35c4 */ 	lw	$t4,%lo(var7f1b35c4)($at)
/*  f10893c:	01800008 */ 	jr	$t4
/*  f108940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108944:	0fc5b9f1 */ 	jal	textGet
/*  f108948:	97a40020 */ 	lhu	$a0,0x20($sp)
/*  f10894c:	1000000c */ 	beqz	$zero,.L0f108980
/*  f108950:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108954:	0fc5b9f1 */ 	jal	textGet
/*  f108958:	97a40022 */ 	lhu	$a0,0x22($sp)
/*  f10895c:	10000008 */ 	beqz	$zero,.L0f108980
/*  f108960:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108964:	0fc5b9f1 */ 	jal	textGet
/*  f108968:	97a40024 */ 	lhu	$a0,0x24($sp)
/*  f10896c:	10000004 */ 	beqz	$zero,.L0f108980
/*  f108970:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108974:
/*  f108974:	0fc5b9f1 */ 	jal	textGet
/*  f108978:	97a40020 */ 	lhu	$a0,0x20($sp)
/*  f10897c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108980:
/*  f108980:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f108984:	03e00008 */ 	jr	$ra
/*  f108988:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10898c
/*  f10898c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108990:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108994:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f108998:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f10899c:	00002825 */ 	or	$a1,$zero,$zero
/*  f1089a0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1089a4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1089a8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f1089ac:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f1089b0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1089b4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1089b8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1089bc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1089c0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1089c4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1089c8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1089cc:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f1089d0:	90620e42 */ 	lbu	$v0,0xe42($v1)
/*  f1089d4:	28410009 */ 	slti	$at,$v0,0x9
/*  f1089d8:	14200009 */ 	bnez	$at,.L0f108a00
/*  f1089dc:	2459ff9c */ 	addiu	$t9,$v0,-100
/*  f1089e0:	2f210007 */ 	sltiu	$at,$t9,0x7
/*  f1089e4:	10200022 */ 	beqz	$at,.L0f108a70
/*  f1089e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1089ec:	3c017f1b */ 	lui	$at,%hi(var7f1b35e8)
/*  f1089f0:	00390821 */ 	addu	$at,$at,$t9
/*  f1089f4:	8c3935e8 */ 	lw	$t9,%lo(var7f1b35e8)($at)
/*  f1089f8:	03200008 */ 	jr	$t9
/*  f1089fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108a00:
/*  f108a00:	2c410009 */ 	sltiu	$at,$v0,0x9
/*  f108a04:	1020001a */ 	beqz	$at,.L0f108a70
/*  f108a08:	00024080 */ 	sll	$t0,$v0,0x2
/*  f108a0c:	3c017f1b */ 	lui	$at,%hi(var7f1b3604)
/*  f108a10:	00280821 */ 	addu	$at,$at,$t0
/*  f108a14:	8c283604 */ 	lw	$t0,%lo(var7f1b3604)($at)
/*  f108a18:	01000008 */ 	jr	$t0
/*  f108a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108a20:	8c690e1c */ 	lw	$t1,0xe1c($v1)
/*  f108a24:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f108a28:	00095080 */ 	sll	$t2,$t1,0x2
/*  f108a2c:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f108a30:	0fc5db69 */ 	jal	func0f176da4
/*  f108a34:	8c842f38 */ 	lw	$a0,0x2f38($a0)
/*  f108a38:	3c0b8007 */ 	lui	$t3,0x8007
/*  f108a3c:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f108a40:	3c04800a */ 	lui	$a0,0x800a
/*  f108a44:	00402825 */ 	or	$a1,$v0,$zero
/*  f108a48:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f108a4c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f108a50:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f108a54:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f108a58:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f108a5c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f108a60:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f108a64:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f108a68:	0c004b2d */ 	jal	func00012cb4
/*  f108a6c:	8c84ee44 */ 	lw	$a0,-0x11bc($a0)
.L0f108a70:
/*  f108a70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108a74:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f108a78:	03e00008 */ 	jr	$ra
/*  f108a7c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f108a80
/*  f108a80:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108a84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108a88:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f108a8c:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f108a90:	00002825 */ 	or	$a1,$zero,$zero
/*  f108a94:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108a98:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108a9c:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f108aa0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f108aa4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108aa8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108aac:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108ab0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108ab4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108ab8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108abc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108ac0:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f108ac4:	90670e42 */ 	lbu	$a3,0xe42($v1)
/*  f108ac8:	28e10009 */ 	slti	$at,$a3,0x9
/*  f108acc:	1420000a */ 	bnez	$at,.L0f108af8
/*  f108ad0:	00e01025 */ 	or	$v0,$a3,$zero
/*  f108ad4:	2459ff9c */ 	addiu	$t9,$v0,-100
/*  f108ad8:	2f210007 */ 	sltiu	$at,$t9,0x7
/*  f108adc:	10200040 */ 	beqz	$at,.L0f108be0
/*  f108ae0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f108ae4:	3c017f1b */ 	lui	$at,%hi(var7f1b3628)
/*  f108ae8:	00390821 */ 	addu	$at,$at,$t9
/*  f108aec:	8c393628 */ 	lw	$t9,%lo(var7f1b3628)($at)
/*  f108af0:	03200008 */ 	jr	$t9
/*  f108af4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108af8:
/*  f108af8:	2c410009 */ 	sltiu	$at,$v0,0x9
/*  f108afc:	10200038 */ 	beqz	$at,.L0f108be0
/*  f108b00:	00024080 */ 	sll	$t0,$v0,0x2
/*  f108b04:	3c017f1b */ 	lui	$at,%hi(var7f1b3644)
/*  f108b08:	00280821 */ 	addu	$at,$at,$t0
/*  f108b0c:	8c283644 */ 	lw	$t0,%lo(var7f1b3644)($at)
/*  f108b10:	01000008 */ 	jr	$t0
/*  f108b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108b18:	8c690e1c */ 	lw	$t1,0xe1c($v1)
/*  f108b1c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f108b20:	00095080 */ 	sll	$t2,$t1,0x2
/*  f108b24:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f108b28:	0fc5db69 */ 	jal	func0f176da4
/*  f108b2c:	8c842f38 */ 	lw	$a0,0x2f38($a0)
/*  f108b30:	3c0b8007 */ 	lui	$t3,0x8007
/*  f108b34:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f108b38:	3c04800a */ 	lui	$a0,0x800a
/*  f108b3c:	00402825 */ 	or	$a1,$v0,$zero
/*  f108b40:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f108b44:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f108b48:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f108b4c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f108b50:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f108b54:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f108b58:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f108b5c:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f108b60:	0c004b2d */ 	jal	func00012cb4
/*  f108b64:	8c84ee44 */ 	lw	$a0,-0x11bc($a0)
/*  f108b68:	1000001e */ 	beqz	$zero,.L0f108be4
/*  f108b6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108b70:	8c6d0e48 */ 	lw	$t5,0xe48($v1)
/*  f108b74:	8c6e0e4c */ 	lw	$t6,0xe4c($v1)
/*  f108b78:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f108b7c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f108b80:	ac4d047c */ 	sw	$t5,0x47c($v0)
/*  f108b84:	0fc44270 */ 	jal	func0f1109c0
/*  f108b88:	a44e0480 */ 	sh	$t6,0x480($v0)
/*  f108b8c:	3c0f8009 */ 	lui	$t7,0x8009
/*  f108b90:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f108b94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f108b98:	3c048007 */ 	lui	$a0,%hi(menudialog_mainmenu)
/*  f108b9c:	15e10007 */ 	bne	$t7,$at,.L0f108bbc
/*  f108ba0:	24843a5c */ 	addiu	$a0,$a0,%lo(menudialog_mainmenu)
/*  f108ba4:	3c048007 */ 	lui	$a0,%hi(g_4MbMainMenu)
/*  f108ba8:	24845294 */ 	addiu	$a0,$a0,%lo(g_4MbMainMenu)
/*  f108bac:	0fc3e083 */ 	jal	func0f0f820c
/*  f108bb0:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f108bb4:	1000000b */ 	beqz	$zero,.L0f108be4
/*  f108bb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108bbc:
/*  f108bbc:	0fc3e083 */ 	jal	func0f0f820c
/*  f108bc0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f108bc4:	10000007 */ 	beqz	$zero,.L0f108be4
/*  f108bc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108bcc:	3c04800a */ 	lui	$a0,%hi(var800a21e8)
/*  f108bd0:	248421e8 */ 	addiu	$a0,$a0,%lo(var800a21e8)
/*  f108bd4:	24e5ff9e */ 	addiu	$a1,$a3,-98
/*  f108bd8:	0fc42539 */ 	jal	func0f1094e4
/*  f108bdc:	8c660e44 */ 	lw	$a2,0xe44($v1)
.L0f108be0:
/*  f108be0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108be4:
/*  f108be4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f108be8:	03e00008 */ 	jr	$ra
/*  f108bec:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerPakErrorTryAgain(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f109038(2);
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandlerSaveElsewhere
/*  f108c24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f108c28:	24010006 */ 	addiu	$at,$zero,0x6
/*  f108c2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108c30:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f108c34:	14810021 */ 	bne	$a0,$at,.L0f108cbc
/*  f108c38:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f108c3c:	0fc3ccef */ 	jal	func0f0f33bc
/*  f108c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c44:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108c48:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108c4c:	3c02800a */ 	lui	$v0,0x800a
/*  f108c50:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108c54:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108c58:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108c5c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108c60:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108c64:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108c68:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108c6c:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f108c70:	9042ee42 */ 	lbu	$v0,-0x11be($v0)
/*  f108c74:	2c410009 */ 	sltiu	$at,$v0,0x9
/*  f108c78:	1020000d */ 	beqz	$at,.L0f108cb0
/*  f108c7c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f108c80:	3c017f1b */ 	lui	$at,%hi(var7f1b3668)
/*  f108c84:	00380821 */ 	addu	$at,$at,$t8
/*  f108c88:	8c383668 */ 	lw	$t8,%lo(var7f1b3668)($at)
/*  f108c8c:	03000008 */ 	jr	$t8
/*  f108c90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108c94:	10000006 */ 	beqz	$zero,.L0f108cb0
/*  f108c98:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f108c9c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f108ca0:	10000003 */ 	beqz	$zero,.L0f108cb0
/*  f108ca4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f108ca8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f108cac:	afa8001c */ 	sw	$t0,0x1c($sp)
.L0f108cb0:
/*  f108cb0:	24440009 */ 	addiu	$a0,$v0,0x9
/*  f108cb4:	0fc42947 */ 	jal	func0f10a51c
/*  f108cb8:	8fa5001c */ 	lw	$a1,0x1c($sp)
.L0f108cbc:
/*  f108cbc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108cc0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f108cc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f108cc8:	03e00008 */ 	jr	$ra
/*  f108ccc:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerPakCancelSave2(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f0f33bc();
		func0f10898c();
		func0f0f361c();
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f108d14
/*  f108d14:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108d18:	24010006 */ 	addiu	$at,$zero,0x6
/*  f108d1c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108d20:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f108d24:	14810003 */ 	bne	$a0,$at,.L0f108d34
/*  f108d28:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f108d2c:	0fc4240e */ 	jal	func0f109038
/*  f108d30:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f108d34:
/*  f108d34:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108d38:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f108d3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f108d40:	03e00008 */ 	jr	$ra
/*  f108d44:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerAcknowledgePakFileLost(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f0f33bc();
		func0f10898c();
		func0f0f361c();
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f108d8c
/*  f108d8c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108d90:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108d94:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108d98:	3c04800a */ 	lui	$a0,0x800a
/*  f108d9c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108da0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108da4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108da8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108dac:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108db0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108db4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108db8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108dbc:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f108dc0:	0fc479ac */ 	jal	func0f11e6b0
/*  f108dc4:	8c84ee4c */ 	lw	$a0,-0x11b4($a0)
/*  f108dc8:	04400010 */ 	bltz	$v0,.L0f108e0c
/*  f108dcc:	00022600 */ 	sll	$a0,$v0,0x18
/*  f108dd0:	3c198007 */ 	lui	$t9,0x8007
/*  f108dd4:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f108dd8:	3c05800a */ 	lui	$a1,0x800a
/*  f108ddc:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f108de0:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f108de4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f108de8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f108dec:	01194021 */ 	addu	$t0,$t0,$t9
/*  f108df0:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f108df4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f108df8:	00084100 */ 	sll	$t0,$t0,0x4
/*  f108dfc:	00a82821 */ 	addu	$a1,$a1,$t0
/*  f108e00:	8ca5ee48 */ 	lw	$a1,-0x11b8($a1)
/*  f108e04:	0fc45a18 */ 	jal	func0f116860
/*  f108e08:	03002025 */ 	or	$a0,$t8,$zero
.L0f108e0c:
/*  f108e0c:	3c028007 */ 	lui	$v0,%hi(var80075bc0)
/*  f108e10:	3c058007 */ 	lui	$a1,%hi(var80075bd0)
/*  f108e14:	24a55bd0 */ 	addiu	$a1,$a1,%lo(var80075bd0)
/*  f108e18:	24425bc0 */ 	addiu	$v0,$v0,%lo(var80075bc0)
/*  f108e1c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f108e20:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f108e24:
/*  f108e24:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f108e28:	10600002 */ 	beqz	$v1,.L0f108e34
/*  f108e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108e30:	a064030c */ 	sb	$a0,0x30c($v1)
.L0f108e34:
/*  f108e34:	5445fffb */ 	bnel	$v0,$a1,.L0f108e24
/*  f108e38:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f108e3c:	3c048007 */ 	lui	$a0,%hi(menudialog_savelost)
/*  f108e40:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f108e44:	24844564 */ 	addiu	$a0,$a0,%lo(menudialog_savelost)
/*  f108e48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108e4c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f108e50:	03e00008 */ 	jr	$ra
/*  f108e54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog00108e58
/*  f108e58:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f108e5c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f108e60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f108e64:	14810014 */ 	bne	$a0,$at,.L0f108eb8
/*  f108e68:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f108e6c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f108e70:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f108e74:	3c02800a */ 	lui	$v0,0x800a
/*  f108e78:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f108e7c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108e80:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f108e84:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f108e88:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f108e8c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f108e90:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f108e94:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f108e98:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f108e9c:	50400007 */ 	beqzl	$v0,.L0f108ebc
/*  f108ea0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108ea4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f108ea8:	54b80004 */ 	bnel	$a1,$t8,.L0f108ebc
/*  f108eac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108eb0:	0fc4240e */ 	jal	func0f109038
/*  f108eb4:	00002025 */ 	or	$a0,$zero,$zero
.L0f108eb8:
/*  f108eb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f108ebc:
/*  f108ebc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f108ec0:	00001025 */ 	or	$v0,$zero,$zero
/*  f108ec4:	03e00008 */ 	jr	$ra
/*  f108ec8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler00108ecc(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f11c7a0();
		func0f109038(1);
	}

	return 0;
}

s32 menuhandler00108f08(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_MenuStack[g_MpPlayerNum].unk94a < 100 && g_MenuStack[g_MpPlayerNum].unk94a != 1) {
			func0f0f3704(&g_SaveElsewhereMenuDialog);
		} else {
			menuPopDialog();
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f108f90
/*  f108f90:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f108f94:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f108f98:	0fc42228 */ 	jal	func0f1088a0
/*  f108f9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108fa0:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f108fa4:	0c004dad */ 	jal	sprintf
/*  f108fa8:	00402825 */ 	or	$a1,$v0,$zero
/*  f108fac:	93ae0030 */ 	lbu	$t6,0x30($sp)
/*  f108fb0:	27a20030 */ 	addiu	$v0,$sp,0x30
/*  f108fb4:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f108fb8:	11c0000a */ 	beqz	$t6,.L0f108fe4
/*  f108fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f108fc0:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f108fc4:
/*  f108fc4:	54830004 */ 	bnel	$a0,$v1,.L0f108fd8
/*  f108fc8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f108fcc:	10000002 */ 	beqz	$zero,.L0f108fd8
/*  f108fd0:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f108fd4:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f108fd8:
/*  f108fd8:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f108fdc:	1460fff9 */ 	bnez	$v1,.L0f108fc4
/*  f108fe0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f108fe4:
/*  f108fe4:	0fc5b9f1 */ 	jal	textGet
/*  f108fe8:	2404576b */ 	addiu	$a0,$zero,0x576b
/*  f108fec:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f108ff0:	00402825 */ 	or	$a1,$v0,$zero
/*  f108ff4:	0c004dad */ 	jal	sprintf
/*  f108ff8:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f108ffc:	3c188008 */ 	lui	$t8,0x8008
/*  f109000:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f109004:	3c068007 */ 	lui	$a2,0x8007
/*  f109008:	3c078008 */ 	lui	$a3,0x8008
/*  f10900c:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f109010:	8cc61440 */ 	lw	$a2,0x1440($a2)
/*  f109014:	24040078 */ 	addiu	$a0,$zero,0x78
/*  f109018:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f10901c:	0fc55d48 */ 	jal	func0f157520
/*  f109020:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f109024:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f109028:	3c028007 */ 	lui	$v0,0x8007
/*  f10902c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f109030:	03e00008 */ 	jr	$ra
/*  f109034:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

GLOBAL_ASM(
glabel func0f109038
/*  f109038:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10903c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f109040:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f109044:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f109048:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10904c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109050:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f109054:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f109058:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10905c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109060:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f109064:	3c04800a */ 	lui	$a0,0x800a
/*  f109068:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10906c:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f109070:	0fc479ac */ 	jal	func0f11e6b0
/*  f109074:	8c84ee4c */ 	lw	$a0,-0x11b4($a0)
/*  f109078:	2401ffff */ 	addiu	$at,$zero,-1
/*  f10907c:	14410010 */ 	bne	$v0,$at,.L0f1090c0
/*  f109080:	00402025 */ 	or	$a0,$v0,$zero
/*  f109084:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f109088:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10908c:	57010004 */ 	bnel	$t8,$at,.L0f1090a0
/*  f109090:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f109094:	0fc42197 */ 	jal	func0f10865c
/*  f109098:	00002025 */ 	or	$a0,$zero,$zero
/*  f10909c:	8fb90020 */ 	lw	$t9,0x20($sp)
.L0f1090a0:
/*  f1090a0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1090a4:	3c048007 */ 	lui	$a0,%hi(menudialog_1a654)
/*  f1090a8:	5721004a */ 	bnel	$t9,$at,.L0f1091d4
/*  f1090ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1090b0:	0fc3cdc1 */ 	jal	func0f0f3704
/*  f1090b4:	24844634 */ 	addiu	$a0,$a0,%lo(menudialog_1a654)
/*  f1090b8:	10000046 */ 	beqz	$zero,.L0f1091d4
/*  f1090bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1090c0:
/*  f1090c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1090c4:	0fc42478 */ 	jal	func0f1091e0
/*  f1090c8:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f1090cc:	10400040 */ 	beqz	$v0,.L0f1091d0
/*  f1090d0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f1090d4:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f1090d8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1090dc:	3c098007 */ 	lui	$t1,0x8007
/*  f1090e0:	15010019 */ 	bne	$t0,$at,.L0f109148
/*  f1090e4:	3c0d8007 */ 	lui	$t5,0x8007
/*  f1090e8:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f1090ec:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f1090f0:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f1090f4:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1090f8:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1090fc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f109100:	01495021 */ 	addu	$t2,$t2,$t1
/*  f109104:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f109108:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10910c:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f109110:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f109114:	904c0e42 */ 	lbu	$t4,0xe42($v0)
/*  f109118:	a0440e3c */ 	sb	$a0,0xe3c($v0)
/*  f10911c:	29810064 */ 	slti	$at,$t4,0x64
/*  f109120:	10200005 */ 	beqz	$at,.L0f109138
/*  f109124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109128:	0fc42197 */ 	jal	func0f10865c
/*  f10912c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f109130:	10000028 */ 	beqz	$zero,.L0f1091d4
/*  f109134:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f109138:
/*  f109138:	0fc42197 */ 	jal	func0f10865c
/*  f10913c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f109140:	10000024 */ 	beqz	$zero,.L0f1091d4
/*  f109144:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f109148:
/*  f109148:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f10914c:	3c04800a */ 	lui	$a0,0x800a
/*  f109150:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f109154:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f109158:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10915c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f109160:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f109164:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f109168:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f10916c:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f109170:	0fc420c9 */ 	jal	func0f108324
/*  f109174:	8c84ee4c */ 	lw	$a0,-0x11b4($a0)
/*  f109178:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10917c:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f109180:	3c19800a */ 	lui	$t9,0x800a
/*  f109184:	3c048007 */ 	lui	$a0,%hi(menudialog_saveerror)
/*  f109188:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10918c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f109190:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f109194:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f109198:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10919c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1091a0:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f1091a4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1091a8:	9339ee42 */ 	lbu	$t9,-0x11be($t9)
/*  f1091ac:	2b210064 */ 	slti	$at,$t9,0x64
/*  f1091b0:	10200005 */ 	beqz	$at,.L0f1091c8
/*  f1091b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1091b8:	0fc3cdc1 */ 	jal	func0f0f3704
/*  f1091bc:	248444fc */ 	addiu	$a0,$a0,%lo(menudialog_saveerror)
/*  f1091c0:	10000004 */ 	beqz	$zero,.L0f1091d4
/*  f1091c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1091c8:
/*  f1091c8:	0fc42363 */ 	jal	func0f108d8c
/*  f1091cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1091d0:
/*  f1091d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1091d4:
/*  f1091d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1091d8:	03e00008 */ 	jr	$ra
/*  f1091dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1091e0
/*  f1091e0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1091e4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1091e8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f1091ec:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f1091f0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1091f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1091f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1091fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f109200:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f109204:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109208:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10920c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f109210:	94590e50 */ 	lhu	$t9,0xe50($v0)
/*  f109214:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f109218:	3c0b7f1b */ 	lui	$t3,%hi(var7f1b3064)
/*  f10921c:	33280001 */ 	andi	$t0,$t9,0x1
/*  f109220:	0008482b */ 	sltu	$t1,$zero,$t0
/*  f109224:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f109228:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f10922c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f109230:	afa90040 */ 	sw	$t1,0x40($sp)
/*  f109234:	256b3064 */ 	addiu	$t3,$t3,%lo(var7f1b3064)
/*  f109238:	8d610000 */ 	lw	$at,0x0($t3)
/*  f10923c:	8d6e0004 */ 	lw	$t6,0x4($t3)
/*  f109240:	27aa0030 */ 	addiu	$t2,$sp,0x30
/*  f109244:	ad410000 */ 	sw	$at,0x0($t2)
/*  f109248:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f10924c:	8d6e000c */ 	lw	$t6,0xc($t3)
/*  f109250:	8d610008 */ 	lw	$at,0x8($t3)
/*  f109254:	00003025 */ 	or	$a2,$zero,$zero
/*  f109258:	ad4e000c */ 	sw	$t6,0xc($t2)
/*  f10925c:	ad410008 */ 	sw	$at,0x8($t2)
/*  f109260:	90430e42 */ 	lbu	$v1,0xe42($v0)
/*  f109264:	28610009 */ 	slti	$at,$v1,0x9
/*  f109268:	14200009 */ 	bnez	$at,.L0f109290
/*  f10926c:	246fff9c */ 	addiu	$t7,$v1,-100
/*  f109270:	2de10007 */ 	sltiu	$at,$t7,0x7
/*  f109274:	1020006a */ 	beqz	$at,.L0f109420
/*  f109278:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10927c:	3c017f1b */ 	lui	$at,%hi(var7f1b368c)
/*  f109280:	002f0821 */ 	addu	$at,$at,$t7
/*  f109284:	8c2f368c */ 	lw	$t7,%lo(var7f1b368c)($at)
/*  f109288:	01e00008 */ 	jr	$t7
/*  f10928c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f109290:
/*  f109290:	2c610009 */ 	sltiu	$at,$v1,0x9
/*  f109294:	10200062 */ 	beqz	$at,.L0f109420
/*  f109298:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f10929c:	3c017f1b */ 	lui	$at,%hi(var7f1b36a8)
/*  f1092a0:	00380821 */ 	addu	$at,$at,$t8
/*  f1092a4:	8c3836a8 */ 	lw	$t8,%lo(var7f1b36a8)($at)
/*  f1092a8:	03000008 */ 	jr	$t8
/*  f1092ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1092b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1092b4:	afb90040 */ 	sw	$t9,0x40($sp)
/*  f1092b8:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f1092bc:	8c450e48 */ 	lw	$a1,0xe48($v0)
/*  f1092c0:	0fc43fab */ 	jal	func0f10feac
/*  f1092c4:	94460e4e */ 	lhu	$a2,0xe4e($v0)
/*  f1092c8:	10000055 */ 	beqz	$zero,.L0f109420
/*  f1092cc:	00403025 */ 	or	$a2,$v0,$zero
/*  f1092d0:	8c440e44 */ 	lw	$a0,0xe44($v0)
/*  f1092d4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1092d8:	8c460e48 */ 	lw	$a2,0xe48($v0)
/*  f1092dc:	0fc6367f */ 	jal	func0f18d9fc
/*  f1092e0:	94470e4e */ 	lhu	$a3,0xe4e($v0)
/*  f1092e4:	1000004e */ 	beqz	$zero,.L0f109420
/*  f1092e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1092ec:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f1092f0:	8c450e48 */ 	lw	$a1,0xe48($v0)
/*  f1092f4:	0fc63908 */ 	jal	func0f18e420
/*  f1092f8:	94460e4e */ 	lhu	$a2,0xe4e($v0)
/*  f1092fc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f109300:	00403025 */ 	or	$a2,$v0,$zero
/*  f109304:	10000046 */ 	beqz	$zero,.L0f109420
/*  f109308:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f10930c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f109310:	8c440e44 */ 	lw	$a0,0xe44($v0)
/*  f109314:	0fc355a4 */ 	jal	func0f0d5690
/*  f109318:	24450e53 */ 	addiu	$a1,$v0,0xe53
/*  f10931c:	3c098007 */ 	lui	$t1,0x8007
/*  f109320:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f109324:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f109328:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f10932c:	000968c0 */ 	sll	$t5,$t1,0x3
/*  f109330:	01a96823 */ 	subu	$t5,$t5,$t1
/*  f109334:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f109338:	01a96821 */ 	addu	$t5,$t5,$t1
/*  f10933c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f109340:	01a96823 */ 	subu	$t5,$t5,$t1
/*  f109344:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f109348:	01ac1021 */ 	addu	$v0,$t5,$t4
/*  f10934c:	904a0e42 */ 	lbu	$t2,0xe42($v0)
/*  f109350:	27ae002c */ 	addiu	$t6,$sp,0x2c
/*  f109354:	8c450e48 */ 	lw	$a1,0xe48($v0)
/*  f109358:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f10935c:	03ab3021 */ 	addu	$a2,$sp,$t3
/*  f109360:	8cc60018 */ 	lw	$a2,0x18($a2)
/*  f109364:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f109368:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f10936c:	8c470e44 */ 	lw	$a3,0xe44($v0)
/*  f109370:	0fc45a0a */ 	jal	func0f116828
/*  f109374:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f109378:	3c188007 */ 	lui	$t8,0x8007
/*  f10937c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f109380:	3c08800a */ 	lui	$t0,0x800a
/*  f109384:	3c018007 */ 	lui	$at,0x8007
/*  f109388:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10938c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f109390:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f109394:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f109398:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10939c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1093a0:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f1093a4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1093a8:	9108ee42 */ 	lbu	$t0,-0x11be($t0)
/*  f1093ac:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1093b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f1093b4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1093b8:	00290821 */ 	addu	$at,$at,$t1
/*  f1093bc:	10000018 */ 	beqz	$zero,.L0f109420
/*  f1093c0:	ac2f5bb8 */ 	sw	$t7,0x5bb8($at)
/*  f1093c4:	0fc43eb2 */ 	jal	func0f10fac8
/*  f1093c8:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f1093cc:	10000014 */ 	beqz	$zero,.L0f109420
/*  f1093d0:	00403025 */ 	or	$a2,$v0,$zero
/*  f1093d4:	8c440e44 */ 	lw	$a0,0xe44($v0)
/*  f1093d8:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1093dc:	8c460e48 */ 	lw	$a2,0xe48($v0)
/*  f1093e0:	0fc636b0 */ 	jal	func0f18dac0
/*  f1093e4:	94470e4e */ 	lhu	$a3,0xe4e($v0)
/*  f1093e8:	1000000d */ 	beqz	$zero,.L0f109420
/*  f1093ec:	00403025 */ 	or	$a2,$v0,$zero
/*  f1093f0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f1093f4:	8c450e48 */ 	lw	$a1,0xe48($v0)
/*  f1093f8:	0fc63932 */ 	jal	func0f18e4c8
/*  f1093fc:	94460e4e */ 	lhu	$a2,0xe4e($v0)
/*  f109400:	10000007 */ 	beqz	$zero,.L0f109420
/*  f109404:	00403025 */ 	or	$a2,$v0,$zero
/*  f109408:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f10940c:	8c450e48 */ 	lw	$a1,0xe48($v0)
/*  f109410:	8c460e44 */ 	lw	$a2,0xe44($v0)
/*  f109414:	0fc45a00 */ 	jal	func0f116800
/*  f109418:	00003825 */ 	or	$a3,$zero,$zero
/*  f10941c:	00403025 */ 	or	$a2,$v0,$zero
.L0f109420:
/*  f109420:	14c00006 */ 	bnez	$a2,.L0f10943c
/*  f109424:	8fad004c */ 	lw	$t5,0x4c($sp)
/*  f109428:	11a00004 */ 	beqz	$t5,.L0f10943c
/*  f10942c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109430:	0fc3ccef */ 	jal	func0f0f33bc
/*  f109434:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f109438:	8fa60044 */ 	lw	$a2,0x44($sp)
.L0f10943c:
/*  f10943c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f109440:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f109444:	3c0b800a */ 	lui	$t3,0x800a
/*  f109448:	000c50c0 */ 	sll	$t2,$t4,0x3
/*  f10944c:	014c5023 */ 	subu	$t2,$t2,$t4
/*  f109450:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f109454:	014c5021 */ 	addu	$t2,$t2,$t4
/*  f109458:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f10945c:	014c5023 */ 	subu	$t2,$t2,$t4
/*  f109460:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f109464:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f109468:	916bee42 */ 	lbu	$t3,-0x11be($t3)
/*  f10946c:	29610064 */ 	slti	$at,$t3,0x64
/*  f109470:	10200010 */ 	beqz	$at,.L0f1094b4
/*  f109474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109478:	54c00005 */ 	bnezl	$a2,.L0f109490
/*  f10947c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f109480:	0fc422a0 */ 	jal	func0f108a80
/*  f109484:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f109488:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f10948c:	8fae0040 */ 	lw	$t6,0x40($sp)
.L0f109490:
/*  f109490:	11c0000d */ 	beqz	$t6,.L0f1094c8
/*  f109494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109498:	14c0000b */ 	bnez	$a2,.L0f1094c8
/*  f10949c:	3c048007 */ 	lui	$a0,%hi(menudialog_filesaved)
/*  f1094a0:	2484446c */ 	addiu	$a0,$a0,%lo(menudialog_filesaved)
/*  f1094a4:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1094a8:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f1094ac:	10000006 */ 	beqz	$zero,.L0f1094c8
/*  f1094b0:	8fa60044 */ 	lw	$a2,0x44($sp)
.L0f1094b4:
/*  f1094b4:	14c00004 */ 	bnez	$a2,.L0f1094c8
/*  f1094b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1094bc:	0fc422a0 */ 	jal	func0f108a80
/*  f1094c0:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f1094c4:	8fa60044 */ 	lw	$a2,0x44($sp)
.L0f1094c8:
/*  f1094c8:	0fc3cd87 */ 	jal	func0f0f361c
/*  f1094cc:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f1094d0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1094d4:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f1094d8:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f1094dc:	03e00008 */ 	jr	$ra
/*  f1094e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1094e4
/*  f1094e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1094e8:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f1094ec:	10a30012 */ 	beq	$a1,$v1,.L0f109538
/*  f1094f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1094f4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1094f8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1094fc:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f109500:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f109504:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f109508:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10950c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f109510:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f109514:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f109518:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10951c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f109520:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f109524:	a0450e42 */ 	sb	$a1,0xe42($v0)
/*  f109528:	ac460e44 */ 	sw	$a2,0xe44($v0)
/*  f10952c:	a4400e50 */ 	sh	$zero,0xe50($v0)
/*  f109530:	3c01800a */ 	lui	$at,0x800a
/*  f109534:	ac2021f8 */ 	sw	$zero,0x21f8($at)
.L0f109538:
/*  f109538:	3c198007 */ 	lui	$t9,0x8007
/*  f10953c:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f109540:	8c8a0000 */ 	lw	$t2,0x0($a0)
/*  f109544:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f109548:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f10954c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f109550:	00084080 */ 	sll	$t0,$t0,0x2
/*  f109554:	01194021 */ 	addu	$t0,$t0,$t9
/*  f109558:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f10955c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f109560:	00084100 */ 	sll	$t0,$t0,0x4
/*  f109564:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f109568:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10956c:	ac4a0e48 */ 	sw	$t2,0xe48($v0)
/*  f109570:	948b0004 */ 	lhu	$t3,0x4($a0)
/*  f109574:	ac4b0e4c */ 	sw	$t3,0xe4c($v0)
/*  f109578:	0fc479ac */ 	jal	func0f11e6b0
/*  f10957c:	01602025 */ 	or	$a0,$t3,$zero
/*  f109580:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f109584:	14430015 */ 	bne	$v0,$v1,.L0f1095dc
/*  f109588:	00402025 */ 	or	$a0,$v0,$zero
/*  f10958c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f109590:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f109594:	3c0e800a */ 	lui	$t6,%hi(var8009e000)
/*  f109598:	25cee000 */ 	addiu	$t6,$t6,%lo(var8009e000)
/*  f10959c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f1095a0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f1095a4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f1095a8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f1095ac:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f1095b0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f1095b4:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f1095b8:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f1095bc:	944f0e50 */ 	lhu	$t7,0xe50($v0)
/*  f1095c0:	3c048007 */ 	lui	$a0,%hi(menudialog_1a654)
/*  f1095c4:	24844634 */ 	addiu	$a0,$a0,%lo(menudialog_1a654)
/*  f1095c8:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f1095cc:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1095d0:	a4580e50 */ 	sh	$t8,0xe50($v0)
/*  f1095d4:	1000002e */ 	beqz	$zero,.L0f109690
/*  f1095d8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1095dc:
/*  f1095dc:	0fc42478 */ 	jal	func0f1091e0
/*  f1095e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1095e4:	10400029 */ 	beqz	$v0,.L0f10968c
/*  f1095e8:	3c198007 */ 	lui	$t9,0x8007
/*  f1095ec:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f1095f0:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f1095f4:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f1095f8:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f1095fc:	01194023 */ 	subu	$t0,$t0,$t9
/*  f109600:	00084080 */ 	sll	$t0,$t0,0x2
/*  f109604:	01194021 */ 	addu	$t0,$t0,$t9
/*  f109608:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f10960c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f109610:	00084100 */ 	sll	$t0,$t0,0x4
/*  f109614:	01091021 */ 	addu	$v0,$t0,$t1
/*  f109618:	944a0e50 */ 	lhu	$t2,0xe50($v0)
/*  f10961c:	8c440e4c */ 	lw	$a0,0xe4c($v0)
/*  f109620:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f109624:	0fc420c9 */ 	jal	func0f108324
/*  f109628:	a44b0e50 */ 	sh	$t3,0xe50($v0)
/*  f10962c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f109630:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f109634:	3c0e800a */ 	lui	$t6,0x800a
/*  f109638:	3c048007 */ 	lui	$a0,%hi(menudialog_saveerror)
/*  f10963c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f109640:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f109644:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f109648:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f10964c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f109650:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f109654:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f109658:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f10965c:	91ceee42 */ 	lbu	$t6,-0x11be($t6)
/*  f109660:	29c10064 */ 	slti	$at,$t6,0x64
/*  f109664:	10200005 */ 	beqz	$at,.L0f10967c
/*  f109668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10966c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f109670:	248444fc */ 	addiu	$a0,$a0,%lo(menudialog_saveerror)
/*  f109674:	10000006 */ 	beqz	$zero,.L0f109690
/*  f109678:	00001025 */ 	or	$v0,$zero,$zero
.L0f10967c:
/*  f10967c:	0fc42363 */ 	jal	func0f108d8c
/*  f109680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109684:	10000002 */ 	beqz	$zero,.L0f109690
/*  f109688:	00001025 */ 	or	$v0,$zero,$zero
.L0f10968c:
/*  f10968c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109690:
/*  f109690:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109694:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f109698:	03e00008 */ 	jr	$ra
/*  f10969c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel pakDeleteFile
/*  f1096a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1096a4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1096a8:	3c13800a */ 	lui	$s3,%hi(var800a21f0)
/*  f1096ac:	267321f0 */ 	addiu	$s3,$s3,%lo(var800a21f0)
/*  f1096b0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1096b4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1096b8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1096bc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1096c0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1096c4:	0fc479ac */ 	jal	func0f11e6b0
/*  f1096c8:	96640004 */ 	lhu	$a0,0x4($s3)
/*  f1096cc:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f1096d0:	00117603 */ 	sra	$t6,$s1,0x18
/*  f1096d4:	0440000a */ 	bltz	$v0,.L0f109700
/*  f1096d8:	01c08825 */ 	or	$s1,$t6,$zero
/*  f1096dc:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f1096e0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1096e4:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1096e8:	0fc45a18 */ 	jal	func0f116860
/*  f1096ec:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1096f0:	10400004 */ 	beqz	$v0,.L0f109704
/*  f1096f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1096f8:	10000002 */ 	beqz	$zero,.L0f109704
/*  f1096fc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f109700:
/*  f109700:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f109704:
/*  f109704:	3c038007 */ 	lui	$v1,%hi(g_MpPlayerNum)
/*  f109708:	24631448 */ 	addiu	$v1,$v1,%lo(g_MpPlayerNum)
/*  f10970c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f109710:	24050e70 */ 	addiu	$a1,$zero,0xe70
/*  f109714:	3c02800a */ 	lui	$v0,%hi(var8009e000)
/*  f109718:	03250019 */ 	multu	$t9,$a1
/*  f10971c:	2442e000 */ 	addiu	$v0,$v0,%lo(var8009e000)
/*  f109720:	3c0c8007 */ 	lui	$t4,0x8007
/*  f109724:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f109728:	24120004 */ 	addiu	$s2,$zero,0x4
/*  f10972c:	00004012 */ 	mflo	$t0
/*  f109730:	00484821 */ 	addu	$t1,$v0,$t0
/*  f109734:	912a0e3f */ 	lbu	$t2,0xe3f($t1)
/*  f109738:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f10973c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f109740:	8d8c5bc0 */ 	lw	$t4,0x5bc0($t4)
/*  f109744:	1200000a */ 	beqz	$s0,.L0f109770
/*  f109748:	a198030c */ 	sb	$t8,0x30c($t4)
/*  f10974c:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f109750:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f109754:	01a50019 */ 	multu	$t5,$a1
/*  f109758:	00007012 */ 	mflo	$t6
/*  f10975c:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f109760:	0fc42197 */ 	jal	func0f10865c
/*  f109764:	a1f10e3c */ 	sb	$s1,0xe3c($t7)
/*  f109768:	10000013 */ 	beqz	$zero,.L0f1097b8
/*  f10976c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f109770:
/*  f109770:	3c11800b */ 	lui	$s1,%hi(g_MpChrs)
/*  f109774:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpChrs)
/*  f109778:	00008025 */ 	or	$s0,$zero,$zero
.L0f10977c:
/*  f10977c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f109780:	8e28004c */ 	lw	$t0,0x4c($s1)
/*  f109784:	57280009 */ 	bnel	$t9,$t0,.L0f1097ac
/*  f109788:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10978c:	96690004 */ 	lhu	$t1,0x4($s3)
/*  f109790:	962a0050 */ 	lhu	$t2,0x50($s1)
/*  f109794:	02002025 */ 	or	$a0,$s0,$zero
/*  f109798:	552a0004 */ 	bnel	$t1,$t2,.L0f1097ac
/*  f10979c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1097a0:	0fc62003 */ 	jal	func0f18800c
/*  f1097a4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1097a8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1097ac:
/*  f1097ac:	1612fff3 */ 	bne	$s0,$s2,.L0f10977c
/*  f1097b0:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f1097b4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1097b8:
/*  f1097b8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1097bc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1097c0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1097c4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1097c8:	03e00008 */ 	jr	$ra
/*  f1097cc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1097d0
/*  f1097d0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1097d4:	3c0f8007 */ 	lui	$t7,%hi(var8007464c)
/*  f1097d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1097dc:	25ef464c */ 	addiu	$t7,$t7,%lo(var8007464c)
/*  f1097e0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1097e4:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1097e8:	27ae0038 */ 	addiu	$t6,$sp,0x38
/*  f1097ec:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1097f0:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1097f4:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1097f8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1097fc:	3c0a7f1b */ 	lui	$t2,%hi(var7f1b3224)
/*  f109800:	254a3224 */ 	addiu	$t2,$t2,%lo(var7f1b3224)
/*  f109804:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f109808:	adc10008 */ 	sw	$at,0x8($t6)
/*  f10980c:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f109810:	8d410000 */ 	lw	$at,0x0($t2)
/*  f109814:	27a90028 */ 	addiu	$t1,$sp,0x28
/*  f109818:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f10981c:	ad210000 */ 	sw	$at,0x0($t1)
/*  f109820:	8d410008 */ 	lw	$at,0x8($t2)
/*  f109824:	8d4d000c */ 	lw	$t5,0xc($t2)
/*  f109828:	3c038007 */ 	lui	$v1,0x8007
/*  f10982c:	ad210008 */ 	sw	$at,0x8($t1)
/*  f109830:	ad2d000c */ 	sw	$t5,0xc($t1)
/*  f109834:	8c635bc0 */ 	lw	$v1,0x5bc0($v1)
/*  f109838:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f10983c:	10600041 */ 	beqz	$v1,.L0f109944
/*  f109840:	00791021 */ 	addu	$v0,$v1,$t9
/*  f109844:	8c5802d8 */ 	lw	$t8,0x2d8($v0)
/*  f109848:	3c05800a */ 	lui	$a1,%hi(var800a21e8)
/*  f10984c:	24a521e8 */ 	addiu	$a1,$a1,%lo(var800a21e8)
/*  f109850:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f109854:	944e02dc */ 	lhu	$t6,0x2dc($v0)
/*  f109858:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10985c:	3c0c800a */ 	lui	$t4,0x800a
/*  f109860:	a4ae0004 */ 	sh	$t6,0x4($a1)
/*  f109864:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f109868:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f10986c:	000f40c0 */ 	sll	$t0,$t7,0x3
/*  f109870:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f109874:	00084080 */ 	sll	$t0,$t0,0x2
/*  f109878:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f10987c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f109880:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f109884:	00084100 */ 	sll	$t0,$t0,0x4
/*  f109888:	01886021 */ 	addu	$t4,$t4,$t0
/*  f10988c:	8d8cee1c */ 	lw	$t4,-0x11e4($t4)
/*  f109890:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f109894:	008b2021 */ 	addu	$a0,$a0,$t3
/*  f109898:	0fc5db69 */ 	jal	func0f176da4
/*  f10989c:	8c842f38 */ 	lw	$a0,0x2f38($a0)
/*  f1098a0:	0c004aac */ 	jal	func00012ab0
/*  f1098a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1098a8:	10400013 */ 	beqz	$v0,.L0f1098f8
/*  f1098ac:	00403025 */ 	or	$a2,$v0,$zero
/*  f1098b0:	3c098007 */ 	lui	$t1,0x8007
/*  f1098b4:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f1098b8:	3c05800a */ 	lui	$a1,0x800a
/*  f1098bc:	3c04800a */ 	lui	$a0,%hi(var800a21e0)
/*  f1098c0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1098c4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1098c8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1098cc:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1098d0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1098d4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f1098d8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f1098dc:	00aa2821 */ 	addu	$a1,$a1,$t2
/*  f1098e0:	8ca5ee1c */ 	lw	$a1,-0x11e4($a1)
/*  f1098e4:	248421e0 */ 	addiu	$a0,$a0,%lo(var800a21e0)
/*  f1098e8:	0fc42539 */ 	jal	func0f1094e4
/*  f1098ec:	24a50067 */ 	addiu	$a1,$a1,0x67
/*  f1098f0:	10000003 */ 	beqz	$zero,.L0f109900
/*  f1098f4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1098f8:
/*  f1098f8:	0fc42197 */ 	jal	func0f10865c
/*  f1098fc:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f109900:
/*  f109900:	3c198007 */ 	lui	$t9,0x8007
/*  f109904:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f109908:	3c0e800a */ 	lui	$t6,0x800a
/*  f10990c:	3c018007 */ 	lui	$at,0x8007
/*  f109910:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f109914:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f109918:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10991c:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f109920:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f109924:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f109928:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10992c:	01d87021 */ 	addu	$t6,$t6,$t8
/*  f109930:	8dceee1c */ 	lw	$t6,-0x11e4($t6)
/*  f109934:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f109938:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10993c:	002f0821 */ 	addu	$at,$at,$t7
/*  f109940:	ac2d5bcc */ 	sw	$t5,0x5bcc($at)
.L0f109944:
/*  f109944:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109948:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f10994c:	03e00008 */ 	jr	$ra
/*  f109950:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f109954
/*  f109954:	3c038007 */ 	lui	$v1,0x8007
/*  f109958:	8c635bc0 */ 	lw	$v1,0x5bc0($v1)
/*  f10995c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f109960:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f109964:	1060000c */ 	beqz	$v1,.L0f109998
/*  f109968:	00803825 */ 	or	$a3,$a0,$zero
/*  f10996c:	000770c0 */ 	sll	$t6,$a3,0x3
/*  f109970:	006e1021 */ 	addu	$v0,$v1,$t6
/*  f109974:	8c4f02d8 */ 	lw	$t7,0x2d8($v0)
/*  f109978:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10997c:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f109980:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f109984:	945802dc */ 	lhu	$t8,0x2dc($v0)
/*  f109988:	00002825 */ 	or	$a1,$zero,$zero
/*  f10998c:	00003025 */ 	or	$a2,$zero,$zero
/*  f109990:	0fc42539 */ 	jal	func0f1094e4
/*  f109994:	a4980004 */ 	sh	$t8,0x4($a0)
.L0f109998:
/*  f109998:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10999c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1099a0:	03e00008 */ 	jr	$ra
/*  f1099a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1099a8
/*  f1099a8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1099ac:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1099b0:	3c18800a */ 	lui	$t8,0x800a
/*  f1099b4:	3c088007 */ 	lui	$t0,0x8007
/*  f1099b8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1099bc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1099c0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1099c4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1099c8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1099cc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1099d0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1099d4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1099d8:	9318ee3f */ 	lbu	$t8,-0x11c1($t8)
/*  f1099dc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1099e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1099e4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1099e8:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1099ec:	8d085bc0 */ 	lw	$t0,0x5bc0($t0)
/*  f1099f0:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f1099f4:	a3a00024 */ 	sb	$zero,0x24($sp)
/*  f1099f8:	9102030b */ 	lbu	$v0,0x30b($t0)
/*  f1099fc:	00a03825 */ 	or	$a3,$a1,$zero
/*  f109a00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f109a04:	10400007 */ 	beqz	$v0,.L0f109a24
/*  f109a08:	24e40006 */ 	addiu	$a0,$a3,0x6
/*  f109a0c:	10410005 */ 	beq	$v0,$at,.L0f109a24
/*  f109a10:	24010002 */ 	addiu	$at,$zero,0x2
/*  f109a14:	10410008 */ 	beq	$v0,$at,.L0f109a38
/*  f109a18:	24e40006 */ 	addiu	$a0,$a3,0x6
/*  f109a1c:	10000009 */ 	beqz	$zero,.L0f109a44
/*  f109a20:	00000000 */ 	sll	$zero,$zero,0x0
.L0f109a24:
/*  f109a24:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f109a28:	0fc35593 */ 	jal	func0f0d564c
/*  f109a2c:	00003025 */ 	or	$a2,$zero,$zero
/*  f109a30:	10000004 */ 	beqz	$zero,.L0f109a44
/*  f109a34:	00000000 */ 	sll	$zero,$zero,0x0
.L0f109a38:
/*  f109a38:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f109a3c:	0fc63669 */ 	jal	func0f18d9a4
/*  f109a40:	27a60020 */ 	addiu	$a2,$sp,0x20
.L0f109a44:
/*  f109a44:	3c057f1b */ 	lui	$a1,%hi(var7f1b3290)
/*  f109a48:	24a53290 */ 	addiu	$a1,$a1,%lo(var7f1b3290)
/*  f109a4c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f109a50:	0c004dad */ 	jal	sprintf
/*  f109a54:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f109a58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109a5c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f109a60:	03e00008 */ 	jr	$ra
/*  f109a64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f109a68
/*  f109a68:	3c078007 */ 	lui	$a3,0x8007
/*  f109a6c:	8ce71448 */ 	lw	$a3,0x1448($a3)
/*  f109a70:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f109a74:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f109a78:	000770c0 */ 	sll	$t6,$a3,0x3
/*  f109a7c:	01c77023 */ 	subu	$t6,$t6,$a3
/*  f109a80:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f109a84:	01c77021 */ 	addu	$t6,$t6,$a3
/*  f109a88:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f109a8c:	01c77023 */ 	subu	$t6,$t6,$a3
/*  f109a90:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f109a94:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f109a98:	90580e3e */ 	lbu	$t8,0xe3e($v0)
/*  f109a9c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f109aa0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f109aa4:	2f010012 */ 	sltiu	$at,$t8,0x12
/*  f109aa8:	00808025 */ 	or	$s0,$a0,$zero
/*  f109aac:	1020003c */ 	beqz	$at,.L0f109ba0
/*  f109ab0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f109ab4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f109ab8:	3c017f1b */ 	lui	$at,%hi(var7f1b36cc)
/*  f109abc:	00380821 */ 	addu	$at,$at,$t8
/*  f109ac0:	8c3836cc */ 	lw	$t8,%lo(var7f1b36cc)($at)
/*  f109ac4:	03000008 */ 	jr	$t8
/*  f109ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109acc:	3c05800a */ 	lui	$a1,0x800a
/*  f109ad0:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f109ad4:	0c004c4c */ 	jal	strcpy
/*  f109ad8:	02002025 */ 	or	$a0,$s0,$zero
/*  f109adc:	10000031 */ 	beqz	$zero,.L0f109ba4
/*  f109ae0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f109ae4:	02002025 */ 	or	$a0,$s0,$zero
/*  f109ae8:	0c004c4c */ 	jal	strcpy
/*  f109aec:	24450e53 */ 	addiu	$a1,$v0,0xe53
/*  f109af0:	1000002c */ 	beqz	$zero,.L0f109ba4
/*  f109af4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f109af8:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f109afc:	0327c821 */ 	addu	$t9,$t9,$a3
/*  f109b00:	3c08800b */ 	lui	$t0,%hi(g_MpChrs)
/*  f109b04:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpChrs)
/*  f109b08:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f109b0c:	03284821 */ 	addu	$t1,$t9,$t0
/*  f109b10:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f109b14:	00002025 */ 	or	$a0,$zero,$zero
/*  f109b18:	00003025 */ 	or	$a2,$zero,$zero
/*  f109b1c:	11400019 */ 	beqz	$t2,.L0f109b84
/*  f109b20:	00075880 */ 	sll	$t3,$a3,0x2
/*  f109b24:	01675821 */ 	addu	$t3,$t3,$a3
/*  f109b28:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f109b2c:	01681021 */ 	addu	$v0,$t3,$t0
/*  f109b30:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f109b34:	2407000a */ 	addiu	$a3,$zero,0xa
/*  f109b38:	00602825 */ 	or	$a1,$v1,$zero
.L0f109b3c:
/*  f109b3c:	10e5000c */ 	beq	$a3,$a1,.L0f109b70
/*  f109b40:	02066021 */ 	addu	$t4,$s0,$a2
/*  f109b44:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f109b48:	3c0d8007 */ 	lui	$t5,0x8007
/*  f109b4c:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f109b50:	3c18800b */ 	lui	$t8,%hi(g_MpChrs)
/*  f109b54:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpChrs)
/*  f109b58:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f109b5c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f109b60:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f109b64:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f109b68:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f109b6c:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f109b70:
/*  f109b70:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f109b74:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f109b78:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f109b7c:	1460ffef */ 	bnez	$v1,.L0f109b3c
/*  f109b80:	00602825 */ 	or	$a1,$v1,$zero
.L0f109b84:
/*  f109b84:	0206c821 */ 	addu	$t9,$s0,$a2
/*  f109b88:	10000005 */ 	beqz	$zero,.L0f109ba0
/*  f109b8c:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f109b90:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f109b94:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f109b98:	0c004c4c */ 	jal	strcpy
/*  f109b9c:	02002025 */ 	or	$a0,$s0,$zero
.L0f109ba0:
/*  f109ba0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f109ba4:
/*  f109ba4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f109ba8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f109bac:	03e00008 */ 	jr	$ra
/*  f109bb0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f109bb4
/*  f109bb4:	3c028007 */ 	lui	$v0,0x8007
/*  f109bb8:	8c421448 */ 	lw	$v0,0x1448($v0)
/*  f109bbc:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f109bc0:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f109bc4:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f109bc8:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f109bcc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f109bd0:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f109bd4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f109bd8:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f109bdc:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f109be0:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f109be4:	90780e3e */ 	lbu	$t8,0xe3e($v1)
/*  f109be8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f109bec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f109bf0:	2f010012 */ 	sltiu	$at,$t8,0x12
/*  f109bf4:	10200021 */ 	beqz	$at,.L0f109c7c
/*  f109bf8:	00803025 */ 	or	$a2,$a0,$zero
/*  f109bfc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f109c00:	3c017f1b */ 	lui	$at,%hi(var7f1b3714)
/*  f109c04:	00380821 */ 	addu	$at,$at,$t8
/*  f109c08:	8c383714 */ 	lw	$t8,%lo(var7f1b3714)($at)
/*  f109c0c:	03000008 */ 	jr	$t8
/*  f109c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109c14:	3c04800a */ 	lui	$a0,0x800a
/*  f109c18:	24842200 */ 	addiu	$a0,$a0,0x2200
/*  f109c1c:	0c004c4c */ 	jal	strcpy
/*  f109c20:	00c02825 */ 	or	$a1,$a2,$zero
/*  f109c24:	10000016 */ 	beqz	$zero,.L0f109c80
/*  f109c28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109c2c:	24640e53 */ 	addiu	$a0,$v1,0xe53
/*  f109c30:	0c004c4c */ 	jal	strcpy
/*  f109c34:	00c02825 */ 	or	$a1,$a2,$zero
/*  f109c38:	10000011 */ 	beqz	$zero,.L0f109c80
/*  f109c3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109c40:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f109c44:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f109c48:	3c08800b */ 	lui	$t0,%hi(g_MpChrs)
/*  f109c4c:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpChrs)
/*  f109c50:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f109c54:	3c057f1b */ 	lui	$a1,%hi(var7f1b32d8)
/*  f109c58:	24a532d8 */ 	addiu	$a1,$a1,%lo(var7f1b32d8)
/*  f109c5c:	0c004dad */ 	jal	sprintf
/*  f109c60:	03282021 */ 	addu	$a0,$t9,$t0
/*  f109c64:	10000006 */ 	beqz	$zero,.L0f109c80
/*  f109c68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109c6c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f109c70:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f109c74:	0c004c4c */ 	jal	strcpy
/*  f109c78:	00c02825 */ 	or	$a1,$a2,$zero
.L0f109c7c:
/*  f109c7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f109c80:
/*  f109c80:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f109c84:	03e00008 */ 	jr	$ra
/*  f109c88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f109c8c
/*  f109c8c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f109c90:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f109c94:	3c18800a */ 	lui	$t8,0x800a
/*  f109c98:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f109c9c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f109ca0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109ca4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f109ca8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f109cac:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f109cb0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109cb4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f109cb8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f109cbc:	9318ee3f */ 	lbu	$t8,-0x11c1($t8)
/*  f109cc0:	3c038007 */ 	lui	$v1,0x8007
/*  f109cc4:	3c058007 */ 	lui	$a1,0x8007
/*  f109cc8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f109ccc:	00791821 */ 	addu	$v1,$v1,$t9
/*  f109cd0:	8c635bc0 */ 	lw	$v1,0x5bc0($v1)
/*  f109cd4:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f109cd8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f109cdc:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f109ce0:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f109ce4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f109ce8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f109cec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f109cf0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f109cf4:	14600003 */ 	bnez	$v1,.L0f109d04
/*  f109cf8:	90a5465c */ 	lbu	$a1,0x465c($a1)
/*  f109cfc:	10000068 */ 	beqz	$zero,.L0f109ea0
/*  f109d00:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109d04:
/*  f109d04:	00654021 */ 	addu	$t0,$v1,$a1
/*  f109d08:	81120300 */ 	lb	$s2,0x300($t0)
/*  f109d0c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f109d10:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f109d14:	16440003 */ 	bne	$s2,$a0,.L0f109d24
/*  f109d18:	28a10004 */ 	slti	$at,$a1,0x4
/*  f109d1c:	10000060 */ 	beqz	$zero,.L0f109ea0
/*  f109d20:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109d24:
/*  f109d24:	10200009 */ 	beqz	$at,.L0f109d4c
/*  f109d28:	847502d0 */ 	lh	$s5,0x2d0($v1)
/*  f109d2c:	24620004 */ 	addiu	$v0,$v1,0x4
.L0f109d30:
/*  f109d30:	80430300 */ 	lb	$v1,0x300($v0)
/*  f109d34:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f109d38:	10830002 */ 	beq	$a0,$v1,.L0f109d44
/*  f109d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109d40:	0060a825 */ 	or	$s5,$v1,$zero
.L0f109d44:
/*  f109d44:	14b1fffa */ 	bne	$a1,$s1,.L0f109d30
/*  f109d48:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f109d4c:
/*  f109d4c:	27b40064 */ 	addiu	$s4,$sp,0x64
/*  f109d50:	a3a00064 */ 	sb	$zero,0x64($sp)
/*  f109d54:	0fc4269a */ 	jal	func0f109a68
/*  f109d58:	02802025 */ 	or	$a0,$s4,$zero
/*  f109d5c:	93a90064 */ 	lbu	$t1,0x64($sp)
/*  f109d60:	27a30064 */ 	addiu	$v1,$sp,0x64
/*  f109d64:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f109d68:	11200011 */ 	beqz	$t1,.L0f109db0
/*  f109d6c:	02408825 */ 	or	$s1,$s2,$zero
/*  f109d70:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109d74:	28410061 */ 	slti	$at,$v0,0x61
.L0f109d78:
/*  f109d78:	14200005 */ 	bnez	$at,.L0f109d90
/*  f109d7c:	2841007b */ 	slti	$at,$v0,0x7b
/*  f109d80:	10200003 */ 	beqz	$at,.L0f109d90
/*  f109d84:	244bffe0 */ 	addiu	$t3,$v0,-32
/*  f109d88:	a06b0000 */ 	sb	$t3,0x0($v1)
/*  f109d8c:	316200ff */ 	andi	$v0,$t3,0xff
.L0f109d90:
/*  f109d90:	56020004 */ 	bnel	$s0,$v0,.L0f109da4
/*  f109d94:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f109d98:	10000002 */ 	beqz	$zero,.L0f109da4
/*  f109d9c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f109da0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f109da4:
/*  f109da4:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109da8:	5440fff3 */ 	bnezl	$v0,.L0f109d78
/*  f109dac:	28410061 */ 	slti	$at,$v0,0x61
.L0f109db0:
/*  f109db0:	0255082a */ 	slt	$at,$s2,$s5
/*  f109db4:	10200039 */ 	beqz	$at,.L0f109e9c
/*  f109db8:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f109dbc:	00129080 */ 	sll	$s2,$s2,0x2
/*  f109dc0:	02519023 */ 	subu	$s2,$s2,$s1
/*  f109dc4:	001290c0 */ 	sll	$s2,$s2,0x3
/*  f109dc8:	27b30040 */ 	addiu	$s3,$sp,0x40
.L0f109dcc:
/*  f109dcc:	3c0c8007 */ 	lui	$t4,0x8007
/*  f109dd0:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f109dd4:	3c0e800a */ 	lui	$t6,0x800a
/*  f109dd8:	3c188007 */ 	lui	$t8,0x8007
/*  f109ddc:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f109de0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f109de4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f109de8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f109dec:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f109df0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f109df4:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f109df8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f109dfc:	91ceee3f */ 	lbu	$t6,-0x11c1($t6)
/*  f109e00:	02602025 */ 	or	$a0,$s3,$zero
/*  f109e04:	00001025 */ 	or	$v0,$zero,$zero
/*  f109e08:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f109e0c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f109e10:	8f185bc0 */ 	lw	$t8,0x5bc0($t8)
/*  f109e14:	0fc4266a */ 	jal	func0f1099a8
/*  f109e18:	03122821 */ 	addu	$a1,$t8,$s2
/*  f109e1c:	93b90040 */ 	lbu	$t9,0x40($sp)
/*  f109e20:	27a30040 */ 	addiu	$v1,$sp,0x40
/*  f109e24:	02802025 */ 	or	$a0,$s4,$zero
/*  f109e28:	13200011 */ 	beqz	$t9,.L0f109e70
/*  f109e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109e30:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109e34:	28410061 */ 	slti	$at,$v0,0x61
.L0f109e38:
/*  f109e38:	14200005 */ 	bnez	$at,.L0f109e50
/*  f109e3c:	2841007b */ 	slti	$at,$v0,0x7b
/*  f109e40:	10200003 */ 	beqz	$at,.L0f109e50
/*  f109e44:	2449ffe0 */ 	addiu	$t1,$v0,-32
/*  f109e48:	a0690000 */ 	sb	$t1,0x0($v1)
/*  f109e4c:	312200ff */ 	andi	$v0,$t1,0xff
.L0f109e50:
/*  f109e50:	56020004 */ 	bnel	$s0,$v0,.L0f109e64
/*  f109e54:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f109e58:	10000002 */ 	beqz	$zero,.L0f109e64
/*  f109e5c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f109e60:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f109e64:
/*  f109e64:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109e68:	5440fff3 */ 	bnezl	$v0,.L0f109e38
/*  f109e6c:	28410061 */ 	slti	$at,$v0,0x61
.L0f109e70:
/*  f109e70:	0c004c9d */ 	jal	func00013274
/*  f109e74:	02602825 */ 	or	$a1,$s3,$zero
/*  f109e78:	02802025 */ 	or	$a0,$s4,$zero
/*  f109e7c:	0c004c9d */ 	jal	func00013274
/*  f109e80:	02602825 */ 	or	$a1,$s3,$zero
/*  f109e84:	14400003 */ 	bnez	$v0,.L0f109e94
/*  f109e88:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f109e8c:	10000004 */ 	beqz	$zero,.L0f109ea0
/*  f109e90:	00001025 */ 	or	$v0,$zero,$zero
.L0f109e94:
/*  f109e94:	1635ffcd */ 	bne	$s1,$s5,.L0f109dcc
/*  f109e98:	26520018 */ 	addiu	$s2,$s2,0x18
.L0f109e9c:
/*  f109e9c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109ea0:
/*  f109ea0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f109ea4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f109ea8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f109eac:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f109eb0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f109eb4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f109eb8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f109ebc:	03e00008 */ 	jr	$ra
/*  f109ec0:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f109ec4
/*  f109ec4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f109ec8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f109ecc:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f109ed0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f109ed4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f109ed8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109edc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f109ee0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f109ee4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f109ee8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109eec:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f109ef0:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f109ef4:	90790e3f */ 	lbu	$t9,0xe3f($v1)
/*  f109ef8:	3c088007 */ 	lui	$t0,%hi(var80075bc0)
/*  f109efc:	25085bc0 */ 	addiu	$t0,$t0,%lo(var80075bc0)
/*  f109f00:	00194880 */ 	sll	$t1,$t9,0x2
/*  f109f04:	01095021 */ 	addu	$t2,$t0,$t1
/*  f109f08:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f109f0c:	90620e52 */ 	lbu	$v0,0xe52($v1)
/*  f109f10:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f109f14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f109f18:	01626021 */ 	addu	$t4,$t3,$v0
/*  f109f1c:	818d02d2 */ 	lb	$t5,0x2d2($t4)
/*  f109f20:	59a00060 */ 	blezl	$t5,.L0f10a0a4
/*  f109f24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109f28:	0fc42723 */ 	jal	func0f109c8c
/*  f109f2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f109f30:	14400005 */ 	bnez	$v0,.L0f109f48
/*  f109f34:	3c048007 */ 	lui	$a0,%hi(menudialog_duplicatefilename)
/*  f109f38:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f109f3c:	24844758 */ 	addiu	$a0,$a0,%lo(menudialog_duplicatefilename)
/*  f109f40:	10000058 */ 	beqz	$zero,.L0f10a0a4
/*  f109f44:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f109f48:
/*  f109f48:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f109f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f109f50:	3c078007 */ 	lui	$a3,0x8007
/*  f109f54:	8ce71448 */ 	lw	$a3,0x1448($a3)
/*  f109f58:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f109f5c:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f109f60:	000770c0 */ 	sll	$t6,$a3,0x3
/*  f109f64:	01c77023 */ 	subu	$t6,$t6,$a3
/*  f109f68:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f109f6c:	01c77021 */ 	addu	$t6,$t6,$a3
/*  f109f70:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f109f74:	01c77023 */ 	subu	$t6,$t6,$a3
/*  f109f78:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f109f7c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f109f80:	90620e3e */ 	lbu	$v0,0xe3e($v1)
/*  f109f84:	3c088007 */ 	lui	$t0,%hi(var80075bc0)
/*  f109f88:	25085bc0 */ 	addiu	$t0,$t0,%lo(var80075bc0)
/*  f109f8c:	14400005 */ 	bnez	$v0,.L0f109fa4
/*  f109f90:	24010005 */ 	addiu	$at,$zero,0x5
/*  f109f94:	0fc42655 */ 	jal	func0f109954
/*  f109f98:	90640e52 */ 	lbu	$a0,0xe52($v1)
/*  f109f9c:	10000041 */ 	beqz	$zero,.L0f10a0a4
/*  f109fa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f109fa4:
/*  f109fa4:	1041003e */ 	beq	$v0,$at,.L0f10a0a0
/*  f109fa8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f109fac:	54410013 */ 	bnel	$v0,$at,.L0f109ffc
/*  f109fb0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f109fb4:	90780e3f */ 	lbu	$t8,0xe3f($v1)
/*  f109fb8:	906b0e52 */ 	lbu	$t3,0xe52($v1)
/*  f109fbc:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f109fc0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f109fc4:	01194821 */ 	addu	$t1,$t0,$t9
/*  f109fc8:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f109fcc:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f109fd0:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f109fd4:	014c1021 */ 	addu	$v0,$t2,$t4
/*  f109fd8:	8c4d02d8 */ 	lw	$t5,0x2d8($v0)
/*  f109fdc:	00e03025 */ 	or	$a2,$a3,$zero
/*  f109fe0:	afad0038 */ 	sw	$t5,0x38($sp)
/*  f109fe4:	944e02dc */ 	lhu	$t6,0x2dc($v0)
/*  f109fe8:	0fc42539 */ 	jal	func0f1094e4
/*  f109fec:	a7ae003c */ 	sh	$t6,0x3c($sp)
/*  f109ff0:	1000002c */ 	beqz	$zero,.L0f10a0a4
/*  f109ff4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f109ff8:	24010007 */ 	addiu	$at,$zero,0x7
.L0f109ffc:
/*  f109ffc:	54410013 */ 	bnel	$v0,$at,.L0f10a04c
/*  f10a000:	28410009 */ 	slti	$at,$v0,0x9
/*  f10a004:	906f0e3f */ 	lbu	$t7,0xe3f($v1)
/*  f10a008:	906b0e52 */ 	lbu	$t3,0xe52($v1)
/*  f10a00c:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f10a010:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f10a014:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f10a018:	8f290000 */ 	lw	$t1,0x0($t9)
/*  f10a01c:	000b50c0 */ 	sll	$t2,$t3,0x3
/*  f10a020:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f10a024:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f10a028:	8c4c02d8 */ 	lw	$t4,0x2d8($v0)
/*  f10a02c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10a030:	afac0030 */ 	sw	$t4,0x30($sp)
/*  f10a034:	944d02dc */ 	lhu	$t5,0x2dc($v0)
/*  f10a038:	0fc42539 */ 	jal	func0f1094e4
/*  f10a03c:	a7ad0034 */ 	sh	$t5,0x34($sp)
/*  f10a040:	10000018 */ 	beqz	$zero,.L0f10a0a4
/*  f10a044:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10a048:	28410009 */ 	slti	$at,$v0,0x9
.L0f10a04c:
/*  f10a04c:	14200012 */ 	bnez	$at,.L0f10a098
/*  f10a050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a054:	906e0e3f */ 	lbu	$t6,0xe3f($v1)
/*  f10a058:	906b0e52 */ 	lbu	$t3,0xe52($v1)
/*  f10a05c:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f10a060:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10a064:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f10a068:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f10a06c:	000b48c0 */ 	sll	$t1,$t3,0x3
/*  f10a070:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f10a074:	03291021 */ 	addu	$v0,$t9,$t1
/*  f10a078:	8c4a02d8 */ 	lw	$t2,0x2d8($v0)
/*  f10a07c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10a080:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f10a084:	944c02dc */ 	lhu	$t4,0x2dc($v0)
/*  f10a088:	0fc42539 */ 	jal	func0f1094e4
/*  f10a08c:	a7ac002c */ 	sh	$t4,0x2c($sp)
/*  f10a090:	10000004 */ 	beqz	$zero,.L0f10a0a4
/*  f10a094:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a098:
/*  f10a098:	0fc425f4 */ 	jal	func0f1097d0
/*  f10a09c:	90640e52 */ 	lbu	$a0,0xe52($v1)
.L0f10a0a0:
/*  f10a0a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a0a4:
/*  f10a0a4:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f10a0a8:	03e00008 */ 	jr	$ra
/*  f10a0ac:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerRenameFile(u32 operation, struct menu_item *item, s32 *value)
{
	s32 val = *value;

	switch (operation) {
	case MENUOP_GETTEXT:
		func0f109a68(val);
		break;
	case MENUOP_SETTEXT:
		func0f109bb4(val);
		break;
	case MENUOP_SET:
		func0f109ec4();
		break;
	}

	return 0;
}

s32 menuhandlerPakRenameDuplicateSave(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&menudialog_changefilename);
	}

	return 0;
}

s32 menuhandlerPakCancelDuplicateSave(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10a19c
/*  f10a19c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10a1a0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10a1a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10a1a8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10a1ac:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10a1b0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a1b4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10a1b8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10a1bc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10a1c0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a1c4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10a1c8:	3c04800a */ 	lui	$a0,0x800a
/*  f10a1cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a1d0:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f10a1d4:	0fc41fec */ 	jal	func0f107fb0
/*  f10a1d8:	9084ee52 */ 	lbu	$a0,-0x11ae($a0)
/*  f10a1dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10a1e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10a1e4:	03e00008 */ 	jr	$ra
/*  f10a1e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10a1ec
/*  f10a1ec:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f10a1f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a1f4:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f10a1f8:	0fc4269a */ 	jal	func0f109a68
/*  f10a1fc:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f10a200:	3c048007 */ 	lui	$a0,0x8007
/*  f10a204:	3c057f1b */ 	lui	$a1,%hi(var7f1b33f0)
/*  f10a208:	24a533f0 */ 	addiu	$a1,$a1,%lo(var7f1b33f0)
/*  f10a20c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10a210:	0c004dad */ 	jal	sprintf
/*  f10a214:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f10a218:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10a21c:	3c028007 */ 	lui	$v0,0x8007
/*  f10a220:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10a224:	03e00008 */ 	jr	$ra
/*  f10a228:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f10a22c
/*  f10a22c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f10a230:	3c0e8007 */ 	lui	$t6,%hi(savelocations3)
/*  f10a234:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a238:	25ce4770 */ 	addiu	$t6,$t6,%lo(savelocations3)
/*  f10a23c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f10a240:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f10a244:	3c088007 */ 	lui	$t0,0x8007
/*  f10a248:	aca10000 */ 	sw	$at,0x0($a1)
/*  f10a24c:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f10a250:	3c0a800a */ 	lui	$t2,0x800a
/*  f10a254:	3c028007 */ 	lui	$v0,0x8007
/*  f10a258:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f10a25c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f10a260:	aca10008 */ 	sw	$at,0x8($a1)
/*  f10a264:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f10a268:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f10a26c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10a270:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10a274:	01284821 */ 	addu	$t1,$t1,$t0
/*  f10a278:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10a27c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10a280:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10a284:	01495021 */ 	addu	$t2,$t2,$t1
/*  f10a288:	914aee3f */ 	lbu	$t2,-0x11c1($t2)
/*  f10a28c:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f10a290:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f10a294:	8c425bc0 */ 	lw	$v0,0x5bc0($v0)
/*  f10a298:	54400004 */ 	bnezl	$v0,.L0f10a2ac
/*  f10a29c:	90830001 */ 	lbu	$v1,0x1($a0)
/*  f10a2a0:	1000000e */ 	beqz	$zero,.L0f10a2dc
/*  f10a2a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f10a2a8:	90830001 */ 	lbu	$v1,0x1($a0)
.L0f10a2ac:
/*  f10a2ac:	00436021 */ 	addu	$t4,$v0,$v1
/*  f10a2b0:	818d02d2 */ 	lb	$t5,0x2d2($t4)
/*  f10a2b4:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f10a2b8:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f10a2bc:	05a10005 */ 	bgez	$t5,.L0f10a2d4
/*  f10a2c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a2c4:	0fc5b9f1 */ 	jal	textGet
/*  f10a2c8:	97a4002e */ 	lhu	$a0,0x2e($sp)
/*  f10a2cc:	10000004 */ 	beqz	$zero,.L0f10a2e0
/*  f10a2d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a2d4:
/*  f10a2d4:	0fc5b9f1 */ 	jal	textGet
/*  f10a2d8:	95e40000 */ 	lhu	$a0,0x0($t7)
.L0f10a2dc:
/*  f10a2dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a2e0:
/*  f10a2e0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f10a2e4:	03e00008 */ 	jr	$ra
/*  f10a2e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10a2ec
/*  f10a2ec:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10a2f0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10a2f4:	3c18800a */ 	lui	$t8,0x800a
/*  f10a2f8:	3c028007 */ 	lui	$v0,0x8007
/*  f10a2fc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10a300:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a304:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10a308:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10a30c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10a310:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a314:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10a318:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10a31c:	9318ee3f */ 	lbu	$t8,-0x11c1($t8)
/*  f10a320:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10a324:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a328:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10a32c:	00591021 */ 	addu	$v0,$v0,$t9
/*  f10a330:	8c425bc0 */ 	lw	$v0,0x5bc0($v0)
/*  f10a334:	54400004 */ 	bnezl	$v0,.L0f10a348
/*  f10a338:	90880001 */ 	lbu	$t0,0x1($a0)
/*  f10a33c:	10000015 */ 	beqz	$zero,.L0f10a394
/*  f10a340:	00001025 */ 	or	$v0,$zero,$zero
/*  f10a344:	90880001 */ 	lbu	$t0,0x1($a0)
.L0f10a348:
/*  f10a348:	00484821 */ 	addu	$t1,$v0,$t0
/*  f10a34c:	812602d2 */ 	lb	$a2,0x2d2($t1)
/*  f10a350:	3c027f1b */ 	lui	$v0,%hi(var7f1b33f4)
/*  f10a354:	04c10003 */ 	bgez	$a2,.L0f10a364
/*  f10a358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a35c:	1000000d */ 	beqz	$zero,.L0f10a394
/*  f10a360:	244233f4 */ 	addiu	$v0,$v0,%lo(var7f1b33f4)
.L0f10a364:
/*  f10a364:	14c00005 */ 	bnez	$a2,.L0f10a37c
/*  f10a368:	3c048007 */ 	lui	$a0,0x8007
/*  f10a36c:	0fc5b9f1 */ 	jal	textGet
/*  f10a370:	24045774 */ 	addiu	$a0,$zero,0x5774
/*  f10a374:	10000008 */ 	beqz	$zero,.L0f10a398
/*  f10a378:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a37c:
/*  f10a37c:	3c057f1b */ 	lui	$a1,%hi(var7f1b33f8)
/*  f10a380:	24a533f8 */ 	addiu	$a1,$a1,%lo(var7f1b33f8)
/*  f10a384:	0c004dad */ 	jal	sprintf
/*  f10a388:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10a38c:	3c028007 */ 	lui	$v0,0x8007
/*  f10a390:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f10a394:
/*  f10a394:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a398:
/*  f10a398:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10a39c:	03e00008 */ 	jr	$ra
/*  f10a3a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerSaveLocation
/*  f10a3a4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10a3a8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10a3ac:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10a3b0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10a3b4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10a3b8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a3bc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10a3c0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10a3c4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10a3c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a3cc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10a3d0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10a3d4:	90590e3f */ 	lbu	$t9,0xe3f($v0)
/*  f10a3d8:	3c038007 */ 	lui	$v1,0x8007
/*  f10a3dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10a3e0:	00194080 */ 	sll	$t0,$t9,0x2
/*  f10a3e4:	00681821 */ 	addu	$v1,$v1,$t0
/*  f10a3e8:	8c635bc0 */ 	lw	$v1,0x5bc0($v1)
/*  f10a3ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a3f0:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f10a3f4:	14600003 */ 	bnez	$v1,.L0f10a404
/*  f10a3f8:	2401000c */ 	addiu	$at,$zero,0xc
/*  f10a3fc:	10000011 */ 	beqz	$zero,.L0f10a444
/*  f10a400:	00001025 */ 	or	$v0,$zero,$zero
.L0f10a404:
/*  f10a404:	54810009 */ 	bnel	$a0,$at,.L0f10a42c
/*  f10a408:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10a40c:	90a90001 */ 	lbu	$t1,0x1($a1)
/*  f10a410:	00695021 */ 	addu	$t2,$v1,$t1
/*  f10a414:	814b02d2 */ 	lb	$t3,0x2d2($t2)
/*  f10a418:	5d600004 */ 	bgtzl	$t3,.L0f10a42c
/*  f10a41c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10a420:	10000008 */ 	beqz	$zero,.L0f10a444
/*  f10a424:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10a428:	24010006 */ 	addiu	$at,$zero,0x6
.L0f10a42c:
/*  f10a42c:	54810005 */ 	bnel	$a0,$at,.L0f10a444
/*  f10a430:	00001025 */ 	or	$v0,$zero,$zero
/*  f10a434:	90ac0001 */ 	lbu	$t4,0x1($a1)
/*  f10a438:	0fc427b1 */ 	jal	func0f109ec4
/*  f10a43c:	a04c0e52 */ 	sb	$t4,0xe52($v0)
/*  f10a440:	00001025 */ 	or	$v0,$zero,$zero
.L0f10a444:
/*  f10a444:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10a448:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10a44c:	03e00008 */ 	jr	$ra
/*  f10a450:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerPakCancelSave(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerDeleteFiles(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f10b0c4(g_MenuStack[g_MpPlayerNum].unk947);
		g_MenuStack[g_MpPlayerNum].unk930 = 1;
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10a51c
/*  f10a51c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10a520:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10a524:	3c01800a */ 	lui	$at,0x800a
/*  f10a528:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10a52c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10a530:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a534:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10a538:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10a53c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10a540:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10a544:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10a548:	002f0821 */ 	addu	$at,$at,$t7
/*  f10a54c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a550:	a024ee3e */ 	sb	$a0,-0x11c2($at)
/*  f10a554:	0fc4433e */ 	jal	func0f110cf8
/*  f10a558:	30a400ff */ 	andi	$a0,$a1,0xff
/*  f10a55c:	3c188007 */ 	lui	$t8,0x8007
/*  f10a560:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10a564:	3c01800a */ 	lui	$at,0x800a
/*  f10a568:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10a56c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10a570:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10a574:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10a578:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10a57c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10a580:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10a584:	00390821 */ 	addu	$at,$at,$t9
/*  f10a588:	0fc4436a */ 	jal	func0f110da8
/*  f10a58c:	a022ee3f */ 	sb	$v0,-0x11c1($at)
/*  f10a590:	3c048007 */ 	lui	$a0,%hi(menudialog_selectlocation)
/*  f10a594:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10a598:	24844858 */ 	addiu	$a0,$a0,%lo(menudialog_selectlocation)
/*  f10a59c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10a5a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10a5a4:	03e00008 */ 	jr	$ra
/*  f10a5a8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerPakConfirmDelete(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		pakDeleteFile();
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10a5e8
/*  f10a5e8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10a5ec:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10a5f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a5f4:	3c048007 */ 	lui	$a0,%hi(menudialog_copyfile)
/*  f10a5f8:	0fc3f55c */ 	jal	func0f0fd570
/*  f10a5fc:	24844a34 */ 	addiu	$a0,$a0,%lo(menudialog_copyfile)
/*  f10a600:	10400005 */ 	beqz	$v0,.L0f10a618
/*  f10a604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a608:	0fc5b9f1 */ 	jal	textGet
/*  f10a60c:	240454f0 */ 	addiu	$a0,$zero,0x54f0
/*  f10a610:	10000004 */ 	beqz	$zero,.L0f10a624
/*  f10a614:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a618:
/*  f10a618:	0fc5b9f1 */ 	jal	textGet
/*  f10a61c:	240454a0 */ 	addiu	$a0,$zero,0x54a0
/*  f10a620:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10a624:
/*  f10a624:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10a628:	03e00008 */ 	jr	$ra
/*  f10a62c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10a630
/*  f10a630:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f10a634:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f10a638:	00a08025 */ 	or	$s0,$a1,$zero
/*  f10a63c:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f10a640:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f10a644:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f10a648:	3c048007 */ 	lui	$a0,0x8007
/*  f10a64c:	00c02825 */ 	or	$a1,$a2,$zero
/*  f10a650:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f10a654:	30e6ffff */ 	andi	$a2,$a3,0xffff
/*  f10a658:	0fc44518 */ 	jal	func0f111460
/*  f10a65c:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f10a660:	104000c1 */ 	beqz	$v0,.L0f10a968
/*  f10a664:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f10a668:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f10a66c:	3c198006 */ 	lui	$t9,%hi(var800613a0)
/*  f10a670:	3c070600 */ 	lui	$a3,0x600
/*  f10a674:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f10a678:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f10a67c:	273913a0 */ 	addiu	$t9,$t9,%lo(var800613a0)
/*  f10a680:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f10a684:	ade70000 */ 	sw	$a3,0x0($t7)
/*  f10a688:	8faa0038 */ 	lw	$t2,0x38($sp)
/*  f10a68c:	3c0c8006 */ 	lui	$t4,%hi(var80061360)
/*  f10a690:	258c1360 */ 	addiu	$t4,$t4,%lo(var80061360)
/*  f10a694:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f10a698:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f10a69c:	ad4c0004 */ 	sw	$t4,0x4($t2)
/*  f10a6a0:	ad470000 */ 	sw	$a3,0x0($t2)
/*  f10a6a4:	8fad0038 */ 	lw	$t5,0x38($sp)
/*  f10a6a8:	3c0fe700 */ 	lui	$t7,0xe700
/*  f10a6ac:	3c0aba00 */ 	lui	$t2,0xba00
/*  f10a6b0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f10a6b4:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f10a6b8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f10a6bc:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f10a6c0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f10a6c4:	354a1301 */ 	ori	$t2,$t2,0x1301
/*  f10a6c8:	3c0db900 */ 	lui	$t5,0xb900
/*  f10a6cc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f10a6d0:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f10a6d4:	af000004 */ 	sw	$zero,0x4($t8)
/*  f10a6d8:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f10a6dc:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f10a6e0:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f10a6e4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f10a6e8:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f10a6ec:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f10a6f0:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f10a6f4:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f10a6f8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f10a6fc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f10a700:	3c0bba00 */ 	lui	$t3,0xba00
/*  f10a704:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f10a708:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f10a70c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f10a710:	add80000 */ 	sw	$t8,0x0($t6)
/*  f10a714:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f10a718:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f10a71c:	240c0c00 */ 	addiu	$t4,$zero,0xc00
/*  f10a720:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f10a724:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f10a728:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f10a72c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f10a730:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f10a734:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f10a738:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f10a73c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f10a740:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f10a744:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f10a748:	00003825 */ 	or	$a3,$zero,$zero
/*  f10a74c:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f10a750:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f10a754:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10a758:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f10a75c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f10a760:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f10a764:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f10a768:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f10a76c:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f10a770:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f10a774:	8faa0038 */ 	lw	$t2,0x38($sp)
/*  f10a778:	3c0cba00 */ 	lui	$t4,0xba00
/*  f10a77c:	358c0c02 */ 	ori	$t4,$t4,0xc02
/*  f10a780:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f10a784:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f10a788:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f10a78c:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f10a790:	8fad0038 */ 	lw	$t5,0x38($sp)
/*  f10a794:	3c0ffb00 */ 	lui	$t7,0xfb00
/*  f10a798:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f10a79c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f10a7a0:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f10a7a4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f10a7a8:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f10a7ac:	3c0eff37 */ 	lui	$t6,0xff37
/*  f10a7b0:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f10a7b4:	331900ff */ 	andi	$t9,$t8,0xff
/*  f10a7b8:	03215025 */ 	or	$t2,$t9,$at
/*  f10a7bc:	adaa0004 */ 	sw	$t2,0x4($t5)
/*  f10a7c0:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f10a7c4:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f10a7c8:	35ad9a25 */ 	ori	$t5,$t5,0x9a25
/*  f10a7cc:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f10a7d0:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f10a7d4:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f10a7d8:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f10a7dc:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f10a7e0:	3c08e600 */ 	lui	$t0,0xe600
/*  f10a7e4:	3c09e800 */ 	lui	$t1,0xe800
/*  f10a7e8:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f10a7ec:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f10a7f0:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f10a7f4:	ade80000 */ 	sw	$t0,0x0($t7)
/*  f10a7f8:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f10a7fc:	3c078008 */ 	lui	$a3,%hi(var8007fac0)
/*  f10a800:	24e7fac0 */ 	addiu	$a3,$a3,%lo(var8007fac0)
/*  f10a804:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f10a808:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f10a80c:	af200004 */ 	sw	$zero,0x4($t9)
/*  f10a810:	af290000 */ 	sw	$t1,0x0($t9)
/*  f10a814:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f10a818:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f10a81c:	01e03025 */ 	or	$a2,$t7,$zero
/*  f10a820:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f10a824:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f10a828:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f10a82c:	03201025 */ 	or	$v0,$t9,$zero
/*  f10a830:	01601825 */ 	or	$v1,$t3,$zero
/*  f10a834:	25ae0014 */ 	addiu	$t6,$t5,0x14
/*  f10a838:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10a83c:	01f80019 */ 	multu	$t7,$t8
/*  f10a840:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f10a844:	3c01e400 */ 	lui	$at,0xe400
/*  f10a848:	25ae0012 */ 	addiu	$t6,$t5,0x12
/*  f10a84c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10a850:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f10a854:	0000c812 */ 	mflo	$t9
/*  f10a858:	332a0fff */ 	andi	$t2,$t9,0xfff
/*  f10a85c:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f10a860:	01616025 */ 	or	$t4,$t3,$at
/*  f10a864:	0198c825 */ 	or	$t9,$t4,$t8
/*  f10a868:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f10a86c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f10a870:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f10a874:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f10a878:	254b0004 */ 	addiu	$t3,$t2,0x4
/*  f10a87c:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f10a880:	01ae0019 */ 	multu	$t5,$t6
/*  f10a884:	272a0002 */ 	addiu	$t2,$t9,0x2
/*  f10a888:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f10a88c:	316d0fff */ 	andi	$t5,$t3,0xfff
/*  f10a890:	240a0200 */ 	addiu	$t2,$zero,0x200
/*  f10a894:	3c19b400 */ 	lui	$t9,0xb400
/*  f10a898:	00007812 */ 	mflo	$t7
/*  f10a89c:	31ec0fff */ 	andi	$t4,$t7,0xfff
/*  f10a8a0:	000cc300 */ 	sll	$t8,$t4,0xc
/*  f10a8a4:	030d7025 */ 	or	$t6,$t8,$t5
/*  f10a8a8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f10a8ac:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f10a8b0:	3c0db300 */ 	lui	$t5,0xb300
/*  f10a8b4:	25ec0008 */ 	addiu	$t4,$t7,0x8
/*  f10a8b8:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f10a8bc:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f10a8c0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f10a8c4:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f10a8c8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f10a8cc:	240f0400 */ 	addiu	$t7,$zero,0x400
/*  f10a8d0:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f10a8d4:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f10a8d8:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f10a8dc:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f10a8e0:	01602825 */ 	or	$a1,$t3,$zero
/*  f10a8e4:	01ee001a */ 	div	$zero,$t7,$t6
/*  f10a8e8:	0000c812 */ 	mflo	$t9
/*  f10a8ec:	00195400 */ 	sll	$t2,$t9,0x10
/*  f10a8f0:	354bfc00 */ 	ori	$t3,$t2,0xfc00
/*  f10a8f4:	acab0004 */ 	sw	$t3,0x4($a1)
/*  f10a8f8:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f10a8fc:	15c00002 */ 	bnez	$t6,.L0f10a908
/*  f10a900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a904:	0007000d */ 	break	0x7
.L0f10a908:
/*  f10a908:	2401ffff */ 	addiu	$at,$zero,-1
/*  f10a90c:	15c10004 */ 	bne	$t6,$at,.L0f10a920
/*  f10a910:	3c018000 */ 	lui	$at,0x8000
/*  f10a914:	15e10002 */ 	bne	$t7,$at,.L0f10a920
/*  f10a918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a91c:	0006000d */ 	break	0x6
.L0f10a920:
/*  f10a920:	270d0008 */ 	addiu	$t5,$t8,0x8
/*  f10a924:	afad0038 */ 	sw	$t5,0x38($sp)
/*  f10a928:	af000004 */ 	sw	$zero,0x4($t8)
/*  f10a92c:	af080000 */ 	sw	$t0,0x0($t8)
/*  f10a930:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f10a934:	3c0ae700 */ 	lui	$t2,0xe700
/*  f10a938:	03001025 */ 	or	$v0,$t8,$zero
/*  f10a93c:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f10a940:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f10a944:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f10a948:	ade90000 */ 	sw	$t1,0x0($t7)
/*  f10a94c:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f10a950:	01e01825 */ 	or	$v1,$t7,$zero
/*  f10a954:	25990008 */ 	addiu	$t9,$t4,0x8
/*  f10a958:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f10a95c:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f10a960:	ad8a0000 */ 	sw	$t2,0x0($t4)
/*  f10a964:	01802025 */ 	or	$a0,$t4,$zero
.L0f10a968:
/*  f10a968:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f10a96c:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f10a970:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f10a974:	03e00008 */ 	jr	$ra
/*  f10a978:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f10a97c
/*  f10a97c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10a980:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10a984:	00808025 */ 	or	$s0,$a0,$zero
/*  f10a988:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10a98c:	3c048007 */ 	lui	$a0,%hi(menudialog_copyfile)
/*  f10a990:	0fc3f55c */ 	jal	func0f0fd570
/*  f10a994:	24844a34 */ 	addiu	$a0,$a0,%lo(menudialog_copyfile)
/*  f10a998:	1040000d */ 	beqz	$v0,.L0f10a9d0
/*  f10a99c:	3c048007 */ 	lui	$a0,%hi(menudialog_fileselect2)
/*  f10a9a0:	3c02800a */ 	lui	$v0,%hi(var800a21e0)
/*  f10a9a4:	244221e0 */ 	addiu	$v0,$v0,%lo(var800a21e0)
/*  f10a9a8:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f10a9ac:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f10a9b0:	15cf0007 */ 	bne	$t6,$t7,.L0f10a9d0
/*  f10a9b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a9b8:	94580004 */ 	lhu	$t8,0x4($v0)
/*  f10a9bc:	96190004 */ 	lhu	$t9,0x4($s0)
/*  f10a9c0:	17190003 */ 	bne	$t8,$t9,.L0f10a9d0
/*  f10a9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10a9c8:	1000003e */ 	beqz	$zero,.L0f10aac4
/*  f10a9cc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10a9d0:
/*  f10a9d0:	0fc3f55c */ 	jal	func0f0fd570
/*  f10a9d4:	24844f34 */ 	addiu	$a0,$a0,%lo(menudialog_fileselect2)
/*  f10a9d8:	10400003 */ 	beqz	$v0,.L0f10a9e8
/*  f10a9dc:	3c09800a */ 	lui	$t1,0x800a
/*  f10a9e0:	10000038 */ 	beqz	$zero,.L0f10aac4
/*  f10a9e4:	00001025 */ 	or	$v0,$zero,$zero
.L0f10a9e8:
/*  f10a9e8:	8d2919c4 */ 	lw	$t1,0x19c4($t1)
/*  f10a9ec:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10a9f0:	3c02800a */ 	lui	$v0,%hi(var800a22c0)
/*  f10a9f4:	15210003 */ 	bne	$t1,$at,.L0f10aa04
/*  f10a9f8:	244222c0 */ 	addiu	$v0,$v0,%lo(var800a22c0)
/*  f10a9fc:	10000031 */ 	beqz	$zero,.L0f10aac4
/*  f10aa00:	00001025 */ 	or	$v0,$zero,$zero
.L0f10aa04:
/*  f10aa04:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f10aa08:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f10aa0c:	15480007 */ 	bne	$t2,$t0,.L0f10aa2c
/*  f10aa10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10aa14:	944b0004 */ 	lhu	$t3,0x4($v0)
/*  f10aa18:	960c0004 */ 	lhu	$t4,0x4($s0)
/*  f10aa1c:	156c0003 */ 	bne	$t3,$t4,.L0f10aa2c
/*  f10aa20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10aa24:	10000027 */ 	beqz	$zero,.L0f10aac4
/*  f10aa28:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10aa2c:
/*  f10aa2c:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f10aa30:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f10aa34:	8c4d0020 */ 	lw	$t5,0x20($v0)
/*  f10aa38:	3c04800b */ 	lui	$a0,0x800b
/*  f10aa3c:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f10aa40:	15a80007 */ 	bne	$t5,$t0,.L0f10aa60
/*  f10aa44:	240600a0 */ 	addiu	$a2,$zero,0xa0
/*  f10aa48:	944e0024 */ 	lhu	$t6,0x24($v0)
/*  f10aa4c:	960f0004 */ 	lhu	$t7,0x4($s0)
/*  f10aa50:	15cf0003 */ 	bne	$t6,$t7,.L0f10aa60
/*  f10aa54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10aa58:	1000001a */ 	beqz	$zero,.L0f10aac4
/*  f10aa5c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10aa60:
/*  f10aa60:	3c05800b */ 	lui	$a1,%hi(g_MpChrs)
/*  f10aa64:	24a5c7b8 */ 	addiu	$a1,$a1,%lo(g_MpChrs)
/*  f10aa68:	00001025 */ 	or	$v0,$zero,$zero
/*  f10aa6c:	9484cb9e */ 	lhu	$a0,-0x3462($a0)
/*  f10aa70:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f10aa74:
/*  f10aa74:	0058c804 */ 	sllv	$t9,$t8,$v0
/*  f10aa78:	00994824 */ 	and	$t1,$a0,$t9
/*  f10aa7c:	5120000e */ 	beqzl	$t1,.L0f10aab8
/*  f10aa80:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10aa84:	00460019 */ 	multu	$v0,$a2
/*  f10aa88:	00005012 */ 	mflo	$t2
/*  f10aa8c:	00aa1821 */ 	addu	$v1,$a1,$t2
/*  f10aa90:	8c6b004c */ 	lw	$t3,0x4c($v1)
/*  f10aa94:	550b0008 */ 	bnel	$t0,$t3,.L0f10aab8
/*  f10aa98:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10aa9c:	960c0004 */ 	lhu	$t4,0x4($s0)
/*  f10aaa0:	946d0050 */ 	lhu	$t5,0x50($v1)
/*  f10aaa4:	558d0004 */ 	bnel	$t4,$t5,.L0f10aab8
/*  f10aaa8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10aaac:	10000005 */ 	beqz	$zero,.L0f10aac4
/*  f10aab0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10aab4:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f10aab8:
/*  f10aab8:	5447ffee */ 	bnel	$v0,$a3,.L0f10aa74
/*  f10aabc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f10aac0:	00001025 */ 	or	$v0,$zero,$zero
.L0f10aac4:
/*  f10aac4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10aac8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10aacc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10aad0:	03e00008 */ 	jr	$ra
/*  f10aad4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10aad8
/*  f10aad8:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f10aadc:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f10aae0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f10aae4:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f10aae8:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f10aaec:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f10aaf0:	3c088007 */ 	lui	$t0,%hi(var80075bc0)
/*  f10aaf4:	25085bc0 */ 	addiu	$t0,$t0,%lo(var80075bc0)
/*  f10aaf8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10aafc:	00c08025 */ 	or	$s0,$a2,$zero
/*  f10ab00:	8d030000 */ 	lw	$v1,0x0($t0)
/*  f10ab04:	15c10010 */ 	bne	$t6,$at,.L0f10ab48
/*  f10ab08:	00008825 */ 	or	$s1,$zero,$zero
/*  f10ab0c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10ab10:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f10ab14:	3c02800a */ 	lui	$v0,0x800a
/*  f10ab18:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10ab1c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ab20:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10ab24:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10ab28:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10ab2c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ab30:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ab34:	00581021 */ 	addu	$v0,$v0,$t8
/*  f10ab38:	9051ee3f */ 	lbu	$s1,-0x11c1($v0)
/*  f10ab3c:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f10ab40:	01194821 */ 	addu	$t1,$t0,$t9
/*  f10ab44:	8d230000 */ 	lw	$v1,0x0($t1)
.L0f10ab48:
/*  f10ab48:	14600003 */ 	bnez	$v1,.L0f10ab58
/*  f10ab4c:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f10ab50:	1000008c */ 	beqz	$zero,.L0f10ad84
/*  f10ab54:	00001025 */ 	or	$v0,$zero,$zero
.L0f10ab58:
/*  f10ab58:	254bffff */ 	addiu	$t3,$t2,-1
/*  f10ab5c:	2d610014 */ 	sltiu	$at,$t3,0x14
/*  f10ab60:	10200087 */ 	beqz	$at,.L0f10ad80
/*  f10ab64:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10ab68:	3c017f1b */ 	lui	$at,%hi(var7f1b375c)
/*  f10ab6c:	002b0821 */ 	addu	$at,$at,$t3
/*  f10ab70:	8c2b375c */ 	lw	$t3,%lo(var7f1b375c)($at)
/*  f10ab74:	01600008 */ 	jr	$t3
/*  f10ab78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ab7c:	3c0c000f */ 	lui	$t4,0xf
/*  f10ab80:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f10ab84:	1000007e */ 	beqz	$zero,.L0f10ad80
/*  f10ab88:	ae0c0000 */ 	sw	$t4,0x0($s0)
/*  f10ab8c:	846d02d0 */ 	lh	$t5,0x2d0($v1)
/*  f10ab90:	1000007b */ 	beqz	$zero,.L0f10ad80
/*  f10ab94:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f10ab98:	3c198007 */ 	lui	$t9,0x8007
/*  f10ab9c:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f10aba0:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f10aba4:	3c0a800a */ 	lui	$t2,0x800a
/*  f10aba8:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f10abac:	01394823 */ 	subu	$t1,$t1,$t9
/*  f10abb0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10abb4:	01394821 */ 	addu	$t1,$t1,$t9
/*  f10abb8:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10abbc:	01394823 */ 	subu	$t1,$t1,$t9
/*  f10abc0:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10abc4:	01495021 */ 	addu	$t2,$t2,$t1
/*  f10abc8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10abcc:	8d4aee1c */ 	lw	$t2,-0x11e4($t2)
/*  f10abd0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10abd4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10abd8:	8e110000 */ 	lw	$s1,0x0($s0)
/*  f10abdc:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f10abe0:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f10abe4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f10abe8:	15410007 */ 	bne	$t2,$at,.L0f10ac08
/*  f10abec:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f10abf0:	02202025 */ 	or	$a0,$s1,$zero
/*  f10abf4:	8f060000 */ 	lw	$a2,0x0($t8)
/*  f10abf8:	0fc4298c */ 	jal	func0f10a630
/*  f10abfc:	97070004 */ 	lhu	$a3,0x4($t8)
/*  f10ac00:	10000061 */ 	beqz	$zero,.L0f10ad88
/*  f10ac04:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f10ac08:
/*  f10ac08:	8cb0000c */ 	lw	$s0,0xc($a1)
/*  f10ac0c:	10e00009 */ 	beqz	$a3,.L0f10ac34
/*  f10ac10:	afa50070 */ 	sw	$a1,0x70($sp)
/*  f10ac14:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f10ac18:	0fc42a5f */ 	jal	func0f10a97c
/*  f10ac1c:	afa50070 */ 	sw	$a1,0x70($sp)
/*  f10ac20:	10400004 */ 	beqz	$v0,.L0f10ac34
/*  f10ac24:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f10ac28:	3c01ff33 */ 	lui	$at,0xff33
/*  f10ac2c:	34213300 */ 	ori	$at,$at,0x3300
/*  f10ac30:	01818025 */ 	or	$s0,$t4,$at
.L0f10ac34:
/*  f10ac34:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f10ac38:	02202025 */ 	or	$a0,$s1,$zero
/*  f10ac3c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f10ac40:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*  f10ac44:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f10ac48:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f10ac4c:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f10ac50:	0fc54d8a */ 	jal	func0f153628
/*  f10ac54:	afb90080 */ 	sw	$t9,0x80($sp)
/*  f10ac58:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*  f10ac5c:	00408825 */ 	or	$s1,$v0,$zero
/*  f10ac60:	3c0a8007 */ 	lui	$t2,0x8007
/*  f10ac64:	1120002e */ 	beqz	$t1,.L0f10ad20
/*  f10ac68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ac6c:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f10ac70:	3c06800a */ 	lui	$a2,0x800a
/*  f10ac74:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f10ac78:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f10ac7c:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f10ac80:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10ac84:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f10ac88:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f10ac8c:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f10ac90:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f10ac94:	00cb3021 */ 	addu	$a2,$a2,$t3
/*  f10ac98:	8cc6ee1c */ 	lw	$a2,-0x11e4($a2)
/*  f10ac9c:	01202825 */ 	or	$a1,$t1,$zero
/*  f10aca0:	0fc42034 */ 	jal	func0f1080d0
/*  f10aca4:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f10aca8:	0c002f02 */ 	jal	func0000bc08
/*  f10acac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10acb0:	0c002f06 */ 	jal	func0000bc18
/*  f10acb4:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f10acb8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f10acbc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f10acc0:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f10acc4:	8d8cfb10 */ 	lw	$t4,-0x4f0($t4)
/*  f10acc8:	87ae0044 */ 	lh	$t6,0x44($sp)
/*  f10accc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10acd0:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f10acd4:	02202025 */ 	or	$a0,$s1,$zero
/*  f10acd8:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f10acdc:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f10ace0:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f10ace4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10ace8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10acec:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10acf0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f10acf4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f10acf8:	0fc5580f */ 	jal	func0f15603c
/*  f10acfc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ad00:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f10ad04:	00408825 */ 	or	$s1,$v0,$zero
/*  f10ad08:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f10ad0c:	2729000c */ 	addiu	$t1,$t9,0xc
/*  f10ad10:	afa90080 */ 	sw	$t1,0x80($sp)
/*  f10ad14:	8f0a0000 */ 	lw	$t2,0x0($t8)
/*  f10ad18:	254b0002 */ 	addiu	$t3,$t2,0x2
/*  f10ad1c:	afab0084 */ 	sw	$t3,0x84($sp)
.L0f10ad20:
/*  f10ad20:	0fc54de0 */ 	jal	func0f153780
/*  f10ad24:	02202025 */ 	or	$a0,$s1,$zero
/*  f10ad28:	00408825 */ 	or	$s1,$v0,$zero
/*  f10ad2c:	10000015 */ 	beqz	$zero,.L0f10ad84
/*  f10ad30:	02201025 */ 	or	$v0,$s1,$zero
/*  f10ad34:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f10ad38:	10000011 */ 	beqz	$zero,.L0f10ad80
/*  f10ad3c:	ae0c0000 */ 	sw	$t4,0x0($s0)
/*  f10ad40:	906d030a */ 	lbu	$t5,0x30a($v1)
/*  f10ad44:	1000000e */ 	beqz	$zero,.L0f10ad80
/*  f10ad48:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f10ad4c:	02202025 */ 	or	$a0,$s1,$zero
/*  f10ad50:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f10ad54:	0fc421ae */ 	jal	func0f1086b8
/*  f10ad58:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f10ad5c:	1000000a */ 	beqz	$zero,.L0f10ad88
/*  f10ad60:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f10ad64:	02202025 */ 	or	$a0,$s1,$zero
/*  f10ad68:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f10ad6c:	0fc421ae */ 	jal	func0f1086b8
/*  f10ad70:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f10ad74:	ae020008 */ 	sw	$v0,0x8($s0)
/*  f10ad78:	10000002 */ 	beqz	$zero,.L0f10ad84
/*  f10ad7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10ad80:
/*  f10ad80:	00001025 */ 	or	$v0,$zero,$zero
.L0f10ad84:
/*  f10ad84:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f10ad88:
/*  f10ad88:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f10ad8c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f10ad90:	03e00008 */ 	jr	$ra
/*  f10ad94:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel menucustomFileToDelete
/*  f10ad98:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f10ad9c:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f10ada0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f10ada4:	24090e70 */ 	addiu	$t1,$zero,0xe70
/*  f10ada8:	3c07800a */ 	lui	$a3,%hi(var8009e000)
/*  f10adac:	01c90019 */ 	multu	$t6,$t1
/*  f10adb0:	24e7e000 */ 	addiu	$a3,$a3,%lo(var8009e000)
/*  f10adb4:	3c038007 */ 	lui	$v1,%hi(var80075bc0)
/*  f10adb8:	24635bc0 */ 	addiu	$v1,$v1,%lo(var80075bc0)
/*  f10adbc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10adc0:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10adc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10adc8:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f10adcc:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f10add0:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f10add4:	00007812 */ 	mflo	$t7
/*  f10add8:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f10addc:	93190e3f */ 	lbu	$t9,0xe3f($t8)
/*  f10ade0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10ade4:	00195080 */ 	sll	$t2,$t9,0x2
/*  f10ade8:	006a5821 */ 	addu	$t3,$v1,$t2
/*  f10adec:	8d620000 */ 	lw	$v0,0x0($t3)
/*  f10adf0:	14400003 */ 	bnez	$v0,.L0f10ae00
/*  f10adf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10adf8:	10000040 */ 	beqz	$zero,.L0f10aefc
/*  f10adfc:	00001025 */ 	or	$v0,$zero,$zero
.L0f10ae00:
/*  f10ae00:	15810039 */ 	bne	$t4,$at,.L0f10aee8
/*  f10ae04:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f10ae08:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f10ae0c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10ae10:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ae14:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10ae18:	004f3021 */ 	addu	$a2,$v0,$t7
/*  f10ae1c:	10c00032 */ 	beqz	$a2,.L0f10aee8
/*  f10ae20:	00c02025 */ 	or	$a0,$a2,$zero
/*  f10ae24:	0fc42a5f */ 	jal	func0f10a97c
/*  f10ae28:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10ae2c:	3c038007 */ 	lui	$v1,%hi(var80075bc0)
/*  f10ae30:	3c07800a */ 	lui	$a3,%hi(var8009e000)
/*  f10ae34:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f10ae38:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f10ae3c:	24e7e000 */ 	addiu	$a3,$a3,%lo(var8009e000)
/*  f10ae40:	24635bc0 */ 	addiu	$v1,$v1,%lo(var80075bc0)
/*  f10ae44:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10ae48:	10400011 */ 	beqz	$v0,.L0f10ae90
/*  f10ae4c:	24090e70 */ 	addiu	$t1,$zero,0xe70
/*  f10ae50:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f10ae54:	00c02025 */ 	or	$a0,$a2,$zero
/*  f10ae58:	03090019 */ 	multu	$t8,$t1
/*  f10ae5c:	0000c812 */ 	mflo	$t9
/*  f10ae60:	00f95021 */ 	addu	$t2,$a3,$t9
/*  f10ae64:	914b0e3f */ 	lbu	$t3,0xe3f($t2)
/*  f10ae68:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f10ae6c:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f10ae70:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f10ae74:	0fc420f4 */ 	jal	func0f1083d0
/*  f10ae78:	91c5030b */ 	lbu	$a1,0x30b($t6)
/*  f10ae7c:	3c048007 */ 	lui	$a0,%hi(menudialog_1a984)
/*  f10ae80:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10ae84:	24844964 */ 	addiu	$a0,$a0,%lo(menudialog_1a984)
/*  f10ae88:	10000018 */ 	beqz	$zero,.L0f10aeec
/*  f10ae8c:	8fa40020 */ 	lw	$a0,0x20($sp)
.L0f10ae90:
/*  f10ae90:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f10ae94:	00c02025 */ 	or	$a0,$a2,$zero
/*  f10ae98:	01e90019 */ 	multu	$t7,$t1
/*  f10ae9c:	0000c012 */ 	mflo	$t8
/*  f10aea0:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f10aea4:	932a0e3f */ 	lbu	$t2,0xe3f($t9)
/*  f10aea8:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f10aeac:	006b6021 */ 	addu	$t4,$v1,$t3
/*  f10aeb0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f10aeb4:	91a5030b */ 	lbu	$a1,0x30b($t5)
/*  f10aeb8:	0fc420f4 */ 	jal	func0f1083d0
/*  f10aebc:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10aec0:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10aec4:	3c02800a */ 	lui	$v0,%hi(var800a21f0)
/*  f10aec8:	244221f0 */ 	addiu	$v0,$v0,%lo(var800a21f0)
/*  f10aecc:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f10aed0:	3c048007 */ 	lui	$a0,%hi(menudialog_confirmdelete)
/*  f10aed4:	248448e8 */ 	addiu	$a0,$a0,%lo(menudialog_confirmdelete)
/*  f10aed8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f10aedc:	94cf0004 */ 	lhu	$t7,0x4($a2)
/*  f10aee0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10aee4:	a44f0004 */ 	sh	$t7,0x4($v0)
.L0f10aee8:
/*  f10aee8:	8fa40020 */ 	lw	$a0,0x20($sp)
.L0f10aeec:
/*  f10aeec:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f10aef0:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f10aef4:	0fc42ab6 */ 	jal	func0f10aad8
/*  f10aef8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f10aefc:
/*  f10aefc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10af00:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10af04:	03e00008 */ 	jr	$ra
/*  f10af08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menucustomFileToCopy
/*  f10af0c:	3c028007 */ 	lui	$v0,0x8007
/*  f10af10:	8c425bc0 */ 	lw	$v0,0x5bc0($v0)
/*  f10af14:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10af18:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10af1c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10af20:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f10af24:	14400003 */ 	bnez	$v0,.L0f10af34
/*  f10af28:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f10af2c:	10000035 */ 	beqz	$zero,.L0f10b004
/*  f10af30:	00001025 */ 	or	$v0,$zero,$zero
.L0f10af34:
/*  f10af34:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f10af38:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10af3c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*  f10af40:	55c1002c */ 	bnel	$t6,$at,.L0f10aff4
/*  f10af44:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f10af48:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f10af4c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10af50:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10af54:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10af58:	00592821 */ 	addu	$a1,$v0,$t9
/*  f10af5c:	50a00025 */ 	beqzl	$a1,.L0f10aff4
/*  f10af60:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f10af64:	8ca80000 */ 	lw	$t0,0x0($a1)
/*  f10af68:	3c02800a */ 	lui	$v0,%hi(var800a21e0)
/*  f10af6c:	244221e0 */ 	addiu	$v0,$v0,%lo(var800a21e0)
/*  f10af70:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f10af74:	94a90004 */ 	lhu	$t1,0x4($a1)
/*  f10af78:	3c0a8007 */ 	lui	$t2,0x8007
/*  f10af7c:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f10af80:	a4490004 */ 	sh	$t1,0x4($v0)
/*  f10af84:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f10af88:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f10af8c:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f10af90:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f10af94:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10af98:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f10af9c:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f10afa0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f10afa4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f10afa8:	256c0e53 */ 	addiu	$t4,$t3,0xe53
/*  f10afac:	0fc4266a */ 	jal	func0f1099a8
/*  f10afb0:	018d2021 */ 	addu	$a0,$t4,$t5
/*  f10afb4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10afb8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10afbc:	3c02800a */ 	lui	$v0,0x800a
/*  f10afc0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10afc4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10afc8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10afcc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10afd0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10afd4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10afd8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10afdc:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10afe0:	8c42ee1c */ 	lw	$v0,-0x11e4($v0)
/*  f10afe4:	00402025 */ 	or	$a0,$v0,$zero
/*  f10afe8:	0fc42947 */ 	jal	func0f10a51c
/*  f10afec:	2445ffff */ 	addiu	$a1,$v0,-1
/*  f10aff0:	8fa40018 */ 	lw	$a0,0x18($sp)
.L0f10aff4:
/*  f10aff4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f10aff8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f10affc:	0fc42ab6 */ 	jal	func0f10aad8
/*  f10b000:	00003825 */ 	or	$a3,$zero,$zero
.L0f10b004:
/*  f10b004:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b008:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10b00c:	03e00008 */ 	jr	$ra
/*  f10b010:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010b014
/*  f10b014:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10b018:	24010065 */ 	addiu	$at,$zero,0x65
/*  f10b01c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b020:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f10b024:	14810022 */ 	bne	$a0,$at,.L0f10b0b0
/*  f10b028:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f10b02c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b030:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10b034:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10b038:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10b03c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10b040:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b044:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10b048:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10b04c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10b050:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b054:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10b058:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10b05c:	8c590e28 */ 	lw	$t9,0xe28($v0)
/*  f10b060:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10b064:	57210004 */ 	bnel	$t9,$at,.L0f10b078
/*  f10b068:	00002025 */ 	or	$a0,$zero,$zero
/*  f10b06c:	10000010 */ 	beqz	$zero,.L0f10b0b0
/*  f10b070:	ac400e28 */ 	sw	$zero,0xe28($v0)
/*  f10b074:	00002025 */ 	or	$a0,$zero,$zero
.L0f10b078:
/*  f10b078:	0fc44317 */ 	jal	func0f110c5c
/*  f10b07c:	00002825 */ 	or	$a1,$zero,$zero
/*  f10b080:	3c088007 */ 	lui	$t0,0x8007
/*  f10b084:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f10b088:	3c01800a */ 	lui	$at,0x800a
/*  f10b08c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f10b090:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10b094:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10b098:	01284821 */ 	addu	$t1,$t1,$t0
/*  f10b09c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10b0a0:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10b0a4:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10b0a8:	00290821 */ 	addu	$at,$at,$t1
/*  f10b0ac:	ac20ee1c */ 	sw	$zero,-0x11e4($at)
.L0f10b0b0:
/*  f10b0b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b0b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10b0b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f10b0bc:	03e00008 */ 	jr	$ra
/*  f10b0c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10b0c4
/*  f10b0c4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b0c8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10b0cc:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10b0d0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10b0d4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10b0d8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b0dc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10b0e0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10b0e4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10b0e8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b0ec:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10b0f0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10b0f4:	308800ff */ 	andi	$t0,$a0,0xff
/*  f10b0f8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f10b0fc:	00084880 */ 	sll	$t1,$t0,0x2
/*  f10b100:	3c038007 */ 	lui	$v1,0x8007
/*  f10b104:	a0440e3f */ 	sb	$a0,0xe3f($v0)
/*  f10b108:	ac400e28 */ 	sw	$zero,0xe28($v0)
/*  f10b10c:	ac590e1c */ 	sw	$t9,0xe1c($v0)
/*  f10b110:	00691821 */ 	addu	$v1,$v1,$t1
/*  f10b114:	8c635bc0 */ 	lw	$v1,0x5bc0($v1)
/*  f10b118:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10b11c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b120:	10600004 */ 	beqz	$v1,.L0f10b134
/*  f10b124:	3c048007 */ 	lui	$a0,%hi(menudialog_deletefile)
/*  f10b128:	906a030b */ 	lbu	$t2,0x30b($v1)
/*  f10b12c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f10b130:	ac4b0e1c */ 	sw	$t3,0xe1c($v0)
.L0f10b134:
/*  f10b134:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10b138:	248449cc */ 	addiu	$a0,$a0,%lo(menudialog_deletefile)
/*  f10b13c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b140:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10b144:	03e00008 */ 	jr	$ra
/*  f10b148:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0010b14c
/*  f10b14c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10b150:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10b154:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10b158:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f10b15c:	1481003e */ 	bne	$a0,$at,.L0f10b258
/*  f10b160:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f10b164:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b168:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10b16c:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10b170:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10b174:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10b178:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b17c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10b180:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10b184:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10b188:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b18c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10b190:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f10b194:	8c680e28 */ 	lw	$t0,0xe28($v1)
/*  f10b198:	8c6a0e20 */ 	lw	$t2,0xe20($v1)
/*  f10b19c:	3c198007 */ 	lui	$t9,0x8007
/*  f10b1a0:	8f394a4c */ 	lw	$t9,0x4a4c($t9)
/*  f10b1a4:	8c6d0e24 */ 	lw	$t5,0xe24($v1)
/*  f10b1a8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f10b1ac:	00084940 */ 	sll	$t1,$t0,0x5
/*  f10b1b0:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f10b1b4:	03291021 */ 	addu	$v0,$t9,$t1
/*  f10b1b8:	018d7025 */ 	or	$t6,$t4,$t5
/*  f10b1bc:	ac6e0e24 */ 	sw	$t6,0xe24($v1)
/*  f10b1c0:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10b1c4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f10b1c8:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10b1cc:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f10b1d0:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f10b1d4:	3c04800a */ 	lui	$a0,0x800a
/*  f10b1d8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10b1dc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10b1e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10b1e4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10b1e8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10b1ec:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10b1f0:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10b1f4:	00982021 */ 	addu	$a0,$a0,$t8
/*  f10b1f8:	94450008 */ 	lhu	$a1,0x8($v0)
/*  f10b1fc:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f10b200:	2448000a */ 	addiu	$t0,$v0,0xa
/*  f10b204:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f10b208:	8084ee23 */ 	lb	$a0,-0x11dd($a0)
/*  f10b20c:	0fc45a22 */ 	jal	func0f116888
/*  f10b210:	2447000e */ 	addiu	$a3,$v0,0xe
/*  f10b214:	3c198007 */ 	lui	$t9,0x8007
/*  f10b218:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f10b21c:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f10b220:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f10b224:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f10b228:	01394823 */ 	subu	$t1,$t1,$t9
/*  f10b22c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10b230:	01394821 */ 	addu	$t1,$t1,$t9
/*  f10b234:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10b238:	01394823 */ 	subu	$t1,$t1,$t9
/*  f10b23c:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10b240:	012b1821 */ 	addu	$v1,$t1,$t3
/*  f10b244:	8c6a0e20 */ 	lw	$t2,0xe20($v1)
/*  f10b248:	10400003 */ 	beqz	$v0,.L0f10b258
/*  f10b24c:	a06a0e3c */ 	sb	$t2,0xe3c($v1)
/*  f10b250:	0fc42197 */ 	jal	func0f10865c
/*  f10b254:	24040008 */ 	addiu	$a0,$zero,0x8
.L0f10b258:
/*  f10b258:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10b25c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10b260:	00001025 */ 	or	$v0,$zero,$zero
/*  f10b264:	03e00008 */ 	jr	$ra
/*  f10b268:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menucustomDeleteGameNote
/*  f10b26c:	3c038007 */ 	lui	$v1,0x8007
/*  f10b270:	8c634a4c */ 	lw	$v1,0x4a4c($v1)
/*  f10b274:	27bdfea8 */ 	addiu	$sp,$sp,-344
/*  f10b278:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f10b27c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f10b280:	afa5015c */ 	sw	$a1,0x15c($sp)
/*  f10b284:	14600003 */ 	bnez	$v1,.L0f10b294
/*  f10b288:	00c03825 */ 	or	$a3,$a2,$zero
/*  f10b28c:	100000f4 */ 	beqz	$zero,.L0f10b660
/*  f10b290:	00001025 */ 	or	$v0,$zero,$zero
.L0f10b294:
/*  f10b294:	248effff */ 	addiu	$t6,$a0,-1
/*  f10b298:	2dc10014 */ 	sltiu	$at,$t6,0x14
/*  f10b29c:	102000ef */ 	beqz	$at,.L0f10b65c
/*  f10b2a0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10b2a4:	3c017f1b */ 	lui	$at,%hi(var7f1b37ac)
/*  f10b2a8:	002e0821 */ 	addu	$at,$at,$t6
/*  f10b2ac:	8c2e37ac */ 	lw	$t6,%lo(var7f1b37ac)($at)
/*  f10b2b0:	01c00008 */ 	jr	$t6
/*  f10b2b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10b2b8:	3c0f000f */ 	lui	$t7,0xf
/*  f10b2bc:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f10b2c0:	100000e6 */ 	beqz	$zero,.L0f10b65c
/*  f10b2c4:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f10b2c8:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f10b2cc:	100000e3 */ 	beqz	$zero,.L0f10b65c
/*  f10b2d0:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f10b2d4:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f10b2d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b34c4)
/*  f10b2dc:	24a534c4 */ 	addiu	$a1,$a1,%lo(var7f1b34c4)
/*  f10b2e0:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f10b2e4:	8ce20004 */ 	lw	$v0,0x4($a3)
/*  f10b2e8:	8cf00008 */ 	lw	$s0,0x8($a3)
/*  f10b2ec:	afa70160 */ 	sw	$a3,0x160($sp)
/*  f10b2f0:	00024140 */ 	sll	$t0,$v0,0x5
/*  f10b2f4:	00684821 */ 	addu	$t1,$v1,$t0
/*  f10b2f8:	afa90144 */ 	sw	$t1,0x144($sp)
/*  f10b2fc:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f10b300:	0c004dad */ 	jal	sprintf
/*  f10b304:	24460001 */ 	addiu	$a2,$v0,0x1
/*  f10b308:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f10b30c:	254b0004 */ 	addiu	$t3,$t2,0x4
/*  f10b310:	afab0154 */ 	sw	$t3,0x154($sp)
/*  f10b314:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f10b318:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f10b31c:	0c002f02 */ 	jal	func0000bc08
/*  f10b320:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f10b324:	0c002f06 */ 	jal	func0000bc18
/*  f10b328:	a7a20050 */ 	sh	$v0,0x50($sp)
/*  f10b32c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f10b330:	3c0f8008 */ 	lui	$t7,0x8008
/*  f10b334:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f10b338:	8dcefb10 */ 	lw	$t6,-0x4f0($t6)
/*  f10b33c:	87b90050 */ 	lh	$t9,0x50($sp)
/*  f10b340:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f10b344:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f10b348:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f10b34c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f10b350:	afa80028 */ 	sw	$t0,0x28($sp)
/*  f10b354:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10b358:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10b35c:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f10b360:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f10b364:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f10b368:	27a700d4 */ 	addiu	$a3,$sp,0xd4
/*  f10b36c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f10b370:	0fc5580f */ 	jal	func0f15603c
/*  f10b374:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f10b378:	8faa0160 */ 	lw	$t2,0x160($sp)
/*  f10b37c:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f10b380:	3c098007 */ 	lui	$t1,0x8007
/*  f10b384:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f10b388:	8d294a4c */ 	lw	$t1,0x4a4c($t1)
/*  f10b38c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10b390:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f10b394:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f10b398:	8dae0200 */ 	lw	$t6,0x200($t5)
/*  f10b39c:	15c10020 */ 	bne	$t6,$at,.L0f10b420
/*  f10b3a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10b3a4:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f10b3a8:	27a5011c */ 	addiu	$a1,$sp,0x11c
/*  f10b3ac:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f10b3b0:	0fc47986 */ 	jal	func0f11e618
/*  f10b3b4:	2484000e */ 	addiu	$a0,$a0,0xe
/*  f10b3b8:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f10b3bc:	27a50110 */ 	addiu	$a1,$sp,0x110
/*  f10b3c0:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f10b3c4:	0fc47986 */ 	jal	func0f11e618
/*  f10b3c8:	2484000a */ 	addiu	$a0,$a0,0xa
/*  f10b3cc:	3c057f1b */ 	lui	$a1,%hi(var7f1b34cc)
/*  f10b3d0:	a3a00111 */ 	sb	$zero,0x111($sp)
/*  f10b3d4:	24a534cc */ 	addiu	$a1,$a1,%lo(var7f1b34cc)
/*  f10b3d8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f10b3dc:	0c004dad */ 	jal	sprintf
/*  f10b3e0:	27a6011c */ 	addiu	$a2,$sp,0x11c
/*  f10b3e4:	3c057f1b */ 	lui	$a1,%hi(var7f1b34d0)
/*  f10b3e8:	24a534d0 */ 	addiu	$a1,$a1,%lo(var7f1b34d0)
/*  f10b3ec:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f10b3f0:	0c004dad */ 	jal	sprintf
/*  f10b3f4:	27a60110 */ 	addiu	$a2,$sp,0x110
/*  f10b3f8:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f10b3fc:	3c057f1b */ 	lui	$a1,%hi(var7f1b34d4)
/*  f10b400:	24a534d4 */ 	addiu	$a1,$a1,%lo(var7f1b34d4)
/*  f10b404:	8de60000 */ 	lw	$a2,0x0($t7)
/*  f10b408:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f10b40c:	0006c202 */ 	srl	$t8,$a2,0x8
/*  f10b410:	0c004dad */ 	jal	sprintf
/*  f10b414:	03003025 */ 	or	$a2,$t8,$zero
/*  f10b418:	10000012 */ 	beqz	$zero,.L0f10b464
/*  f10b41c:	8e190000 */ 	lw	$t9,0x0($s0)
.L0f10b420:
/*  f10b420:	0fc5b9f1 */ 	jal	textGet
/*  f10b424:	24045788 */ 	addiu	$a0,$zero,0x5788
/*  f10b428:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f10b42c:	0c004dad */ 	jal	sprintf
/*  f10b430:	00402825 */ 	or	$a1,$v0,$zero
/*  f10b434:	0fc5b9f1 */ 	jal	textGet
/*  f10b438:	24045789 */ 	addiu	$a0,$zero,0x5789
/*  f10b43c:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f10b440:	0c004dad */ 	jal	sprintf
/*  f10b444:	00402825 */ 	or	$a1,$v0,$zero
/*  f10b448:	3c057f1b */ 	lui	$a1,%hi(var7f1b34d8)
/*  f10b44c:	24a534d8 */ 	addiu	$a1,$a1,%lo(var7f1b34d8)
/*  f10b450:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f10b454:	27a6011c */ 	addiu	$a2,$sp,0x11c
/*  f10b458:	0c004dad */ 	jal	sprintf
/*  f10b45c:	27a70110 */ 	addiu	$a3,$sp,0x110
/*  f10b460:	8e190000 */ 	lw	$t9,0x0($s0)
.L0f10b464:
/*  f10b464:	27280014 */ 	addiu	$t0,$t9,0x14
/*  f10b468:	afa80154 */ 	sw	$t0,0x154($sp)
/*  f10b46c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f10b470:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f10b474:	0c002f02 */ 	jal	func0000bc08
/*  f10b478:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f10b47c:	0c002f06 */ 	jal	func0000bc18
/*  f10b480:	a7a20050 */ 	sh	$v0,0x50($sp)
/*  f10b484:	3c098008 */ 	lui	$t1,0x8008
/*  f10b488:	3c0c8008 */ 	lui	$t4,0x8008
/*  f10b48c:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f10b490:	8d29fb10 */ 	lw	$t1,-0x4f0($t1)
/*  f10b494:	87ae0050 */ 	lh	$t6,0x50($sp)
/*  f10b498:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f10b49c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f10b4a0:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f10b4a4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10b4a8:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f10b4ac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10b4b0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10b4b4:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f10b4b8:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f10b4bc:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f10b4c0:	27a700d4 */ 	addiu	$a3,$sp,0xd4
/*  f10b4c4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10b4c8:	0fc5580f */ 	jal	func0f15603c
/*  f10b4cc:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f10b4d0:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f10b4d4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f10b4d8:	271900be */ 	addiu	$t9,$t8,0xbe
/*  f10b4dc:	afb90154 */ 	sw	$t9,0x154($sp)
/*  f10b4e0:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f10b4e4:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f10b4e8:	0c002f02 */ 	jal	func0000bc08
/*  f10b4ec:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f10b4f0:	0c002f06 */ 	jal	func0000bc18
/*  f10b4f4:	a7a20050 */ 	sh	$v0,0x50($sp)
/*  f10b4f8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f10b4fc:	3c098008 */ 	lui	$t1,0x8008
/*  f10b500:	8d29fb0c */ 	lw	$t1,-0x4f4($t1)
/*  f10b504:	8d6bfb10 */ 	lw	$t3,-0x4f0($t3)
/*  f10b508:	87ad0050 */ 	lh	$t5,0x50($sp)
/*  f10b50c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f10b510:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f10b514:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f10b518:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f10b51c:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f10b520:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10b524:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10b528:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f10b52c:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f10b530:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f10b534:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f10b538:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f10b53c:	0fc5580f */ 	jal	func0f15603c
/*  f10b540:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f10b544:	3c0f8008 */ 	lui	$t7,0x8008
/*  f10b548:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f10b54c:	3c078008 */ 	lui	$a3,0x8008
/*  f10b550:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f10b554:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f10b558:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f10b55c:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f10b560:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f10b564:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f10b568:	0fc55cbe */ 	jal	func0f1572f8
/*  f10b56c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f10b570:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f10b574:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f10b578:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f10b57c:	03194021 */ 	addu	$t0,$t8,$t9
/*  f10b580:	010a5823 */ 	subu	$t3,$t0,$t2
/*  f10b584:	2569fffa */ 	addiu	$t1,$t3,-6
/*  f10b588:	afa90154 */ 	sw	$t1,0x154($sp)
/*  f10b58c:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f10b590:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f10b594:	0c002f02 */ 	jal	func0000bc08
/*  f10b598:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f10b59c:	0c002f06 */ 	jal	func0000bc18
/*  f10b5a0:	a7a20050 */ 	sh	$v0,0x50($sp)
/*  f10b5a4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f10b5a8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f10b5ac:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f10b5b0:	8dcefb10 */ 	lw	$t6,-0x4f0($t6)
/*  f10b5b4:	87b90050 */ 	lh	$t9,0x50($sp)
/*  f10b5b8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f10b5bc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f10b5c0:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f10b5c4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f10b5c8:	afa80028 */ 	sw	$t0,0x28($sp)
/*  f10b5cc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10b5d0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10b5d4:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f10b5d8:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f10b5dc:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f10b5e0:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f10b5e4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f10b5e8:	0fc5580f */ 	jal	func0f15603c
/*  f10b5ec:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f10b5f0:	1000001c */ 	beqz	$zero,.L0f10b664
/*  f10b5f4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f10b5f8:	240a000b */ 	addiu	$t2,$zero,0xb
/*  f10b5fc:	10000017 */ 	beqz	$zero,.L0f10b65c
/*  f10b600:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f10b604:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f10b608:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10b60c:	3c0d8007 */ 	lui	$t5,0x8007
/*  f10b610:	00025880 */ 	sll	$t3,$v0,0x2
/*  f10b614:	006b4821 */ 	addu	$t1,$v1,$t3
/*  f10b618:	8d2c0200 */ 	lw	$t4,0x200($t1)
/*  f10b61c:	3c048007 */ 	lui	$a0,%hi(menudialog_deletegamenote)
/*  f10b620:	5581000f */ 	bnel	$t4,$at,.L0f10b660
/*  f10b624:	00001025 */ 	or	$v0,$zero,$zero
/*  f10b628:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f10b62c:	3c01800a */ 	lui	$at,0x800a
/*  f10b630:	24844aa0 */ 	addiu	$a0,$a0,%lo(menudialog_deletegamenote)
/*  f10b634:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f10b638:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10b63c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10b640:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f10b644:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10b648:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10b64c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f10b650:	002e0821 */ 	addu	$at,$at,$t6
/*  f10b654:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10b658:	ac22ee28 */ 	sw	$v0,-0x11d8($at)
.L0f10b65c:
/*  f10b65c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10b660:
/*  f10b660:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f10b664:
/*  f10b664:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f10b668:	27bd0158 */ 	addiu	$sp,$sp,0x158
/*  f10b66c:	03e00008 */ 	jr	$ra
/*  f10b670:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010b674
/*  f10b674:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10b678:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10b67c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b680:	14810031 */ 	bne	$a0,$at,.L0f10b748
/*  f10b684:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f10b688:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b68c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10b690:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10b694:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10b698:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10b69c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b6a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10b6a4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10b6a8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10b6ac:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b6b0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10b6b4:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10b6b8:	8c4304f8 */ 	lw	$v1,0x4f8($v0)
/*  f10b6bc:	50600023 */ 	beqzl	$v1,.L0f10b74c
/*  f10b6c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b6c4:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f10b6c8:	14b9001f */ 	bne	$a1,$t9,.L0f10b748
/*  f10b6cc:	3c058007 */ 	lui	$a1,%hi(var80074a4c)
/*  f10b6d0:	24a54a4c */ 	addiu	$a1,$a1,%lo(var80074a4c)
/*  f10b6d4:	0fc45a31 */ 	jal	func0f1168c4
/*  f10b6d8:	80440e23 */ 	lb	$a0,0xe23($v0)
/*  f10b6dc:	5040001b */ 	beqzl	$v0,.L0f10b74c
/*  f10b6e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b6e4:	0fc3ccef */ 	jal	func0f0f33bc
/*  f10b6e8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f10b6ec:	3c088007 */ 	lui	$t0,0x8007
/*  f10b6f0:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f10b6f4:	3c0a800a */ 	lui	$t2,%hi(var8009e000)
/*  f10b6f8:	3c018007 */ 	lui	$at,0x8007
/*  f10b6fc:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f10b700:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10b704:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10b708:	01284821 */ 	addu	$t1,$t1,$t0
/*  f10b70c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10b710:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10b714:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10b718:	254ae000 */ 	addiu	$t2,$t2,%lo(var8009e000)
/*  f10b71c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f10b720:	ac204a4c */ 	sw	$zero,0x4a4c($at)
/*  f10b724:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f10b728:	8c4b0e20 */ 	lw	$t3,0xe20($v0)
/*  f10b72c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10b730:	14610003 */ 	bne	$v1,$at,.L0f10b740
/*  f10b734:	a04b0e3c */ 	sb	$t3,0xe3c($v0)
/*  f10b738:	0fc42197 */ 	jal	func0f10865c
/*  f10b73c:	24040006 */ 	addiu	$a0,$zero,0x6
.L0f10b740:
/*  f10b740:	0fc3cd87 */ 	jal	func0f0f361c
/*  f10b744:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10b748:
/*  f10b748:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b74c:
/*  f10b74c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10b750:	00001025 */ 	or	$v0,$zero,$zero
/*  f10b754:	03e00008 */ 	jr	$ra
/*  f10b758:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10b75c
/*  f10b75c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b760:	8dce4a4c */ 	lw	$t6,0x4a4c($t6)
/*  f10b764:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10b768:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b76c:	15c00009 */ 	bnez	$t6,.L0f10b794
/*  f10b770:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10b774:	0fc5b9f1 */ 	jal	textGet
/*  f10b778:	2404578a */ 	addiu	$a0,$zero,0x578a
/*  f10b77c:	3c048007 */ 	lui	$a0,0x8007
/*  f10b780:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10b784:	0c004dad */ 	jal	sprintf
/*  f10b788:	00402825 */ 	or	$a1,$v0,$zero
/*  f10b78c:	1000000b */ 	beqz	$zero,.L0f10b7bc
/*  f10b790:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b794:
/*  f10b794:	0fc5b9f1 */ 	jal	textGet
/*  f10b798:	2404578b */ 	addiu	$a0,$zero,0x578b
/*  f10b79c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10b7a0:	8def4a4c */ 	lw	$t7,0x4a4c($t7)
/*  f10b7a4:	3c048007 */ 	lui	$a0,0x8007
/*  f10b7a8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10b7ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f10b7b0:	0c004dad */ 	jal	sprintf
/*  f10b7b4:	95e60242 */ 	lhu	$a2,0x242($t7)
/*  f10b7b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b7bc:
/*  f10b7bc:	3c028007 */ 	lui	$v0,0x8007
/*  f10b7c0:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10b7c4:	03e00008 */ 	jr	$ra
/*  f10b7c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10b7cc
/*  f10b7cc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b7d0:	8dce4a4c */ 	lw	$t6,0x4a4c($t6)
/*  f10b7d4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10b7d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b7dc:	15c00009 */ 	bnez	$t6,.L0f10b804
/*  f10b7e0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10b7e4:	0fc5b9f1 */ 	jal	textGet
/*  f10b7e8:	2404578c */ 	addiu	$a0,$zero,0x578c
/*  f10b7ec:	3c048007 */ 	lui	$a0,0x8007
/*  f10b7f0:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f10b7f4:	0c004dad */ 	jal	sprintf
/*  f10b7f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f10b7fc:	1000000b */ 	beqz	$zero,.L0f10b82c
/*  f10b800:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b804:
/*  f10b804:	0fc5b9f1 */ 	jal	textGet
/*  f10b808:	2404578d */ 	addiu	$a0,$zero,0x578d
/*  f10b80c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10b810:	8def4a4c */ 	lw	$t7,0x4a4c($t7)
/*  f10b814:	3c048007 */ 	lui	$a0,0x8007
/*  f10b818:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f10b81c:	00402825 */ 	or	$a1,$v0,$zero
/*  f10b820:	0c004dad */ 	jal	sprintf
/*  f10b824:	95e60240 */ 	lhu	$a2,0x240($t7)
/*  f10b828:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b82c:
/*  f10b82c:	3c028007 */ 	lui	$v0,0x8007
/*  f10b830:	8c421444 */ 	lw	$v0,0x1444($v0)
/*  f10b834:	03e00008 */ 	jr	$ra
/*  f10b838:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10b83c
/*  f10b83c:	3c058007 */ 	lui	$a1,0x8007
/*  f10b840:	8ca54a4c */ 	lw	$a1,0x4a4c($a1)
/*  f10b844:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10b848:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b84c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10b850:	00005025 */ 	or	$t2,$zero,$zero
/*  f10b854:	14a00005 */ 	bnez	$a1,.L0f10b86c
/*  f10b858:	00005825 */ 	or	$t3,$zero,$zero
/*  f10b85c:	0fc5b9f1 */ 	jal	textGet
/*  f10b860:	2404578e */ 	addiu	$a0,$zero,0x578e
/*  f10b864:	1000002c */ 	beqz	$zero,.L0f10b918
/*  f10b868:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b86c:
/*  f10b86c:	3c084e50 */ 	lui	$t0,0x4e50
/*  f10b870:	35084445 */ 	ori	$t0,$t0,0x4445
/*  f10b874:	00001825 */ 	or	$v1,$zero,$zero
/*  f10b878:	00a02025 */ 	or	$a0,$a1,$zero
/*  f10b87c:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f10b880:	24073459 */ 	addiu	$a3,$zero,0x3459
/*  f10b884:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f10b888:
/*  f10b888:	8c8e0200 */ 	lw	$t6,0x200($a0)
/*  f10b88c:	00037940 */ 	sll	$t7,$v1,0x5
/*  f10b890:	00af1021 */ 	addu	$v0,$a1,$t7
/*  f10b894:	54ce000a */ 	bnel	$a2,$t6,.L0f10b8c0
/*  f10b898:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f10b89c:	94580008 */ 	lhu	$t8,0x8($v0)
/*  f10b8a0:	54f80008 */ 	bnel	$a3,$t8,.L0f10b8c4
/*  f10b8a4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f10b8a8:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f10b8ac:	55190005 */ 	bnel	$t0,$t9,.L0f10b8c4
/*  f10b8b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f10b8b4:	10000002 */ 	beqz	$zero,.L0f10b8c0
/*  f10b8b8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f10b8bc:	240b0001 */ 	addiu	$t3,$zero,0x1
.L0f10b8c0:
/*  f10b8c0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f10b8c4:
/*  f10b8c4:	1469fff0 */ 	bne	$v1,$t1,.L0f10b888
/*  f10b8c8:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f10b8cc:	51400006 */ 	beqzl	$t2,.L0f10b8e8
/*  f10b8d0:	94ac0242 */ 	lhu	$t4,0x242($a1)
/*  f10b8d4:	0fc5b9f1 */ 	jal	textGet
/*  f10b8d8:	2404578e */ 	addiu	$a0,$zero,0x578e
/*  f10b8dc:	1000000e */ 	beqz	$zero,.L0f10b918
/*  f10b8e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b8e4:	94ac0242 */ 	lhu	$t4,0x242($a1)
.L0f10b8e8:
/*  f10b8e8:	2981001c */ 	slti	$at,$t4,0x1c
/*  f10b8ec:	14200003 */ 	bnez	$at,.L0f10b8fc
/*  f10b8f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10b8f4:	15600005 */ 	bnez	$t3,.L0f10b90c
/*  f10b8f8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10b8fc:
/*  f10b8fc:	0fc5b9f1 */ 	jal	textGet
/*  f10b900:	24045790 */ 	addiu	$a0,$zero,0x5790
/*  f10b904:	10000004 */ 	beqz	$zero,.L0f10b918
/*  f10b908:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b90c:
/*  f10b90c:	0fc5b9f1 */ 	jal	textGet
/*  f10b910:	2404578f */ 	addiu	$a0,$zero,0x578f
/*  f10b914:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10b918:
/*  f10b918:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10b91c:	03e00008 */ 	jr	$ra
/*  f10b920:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10b924
/*  f10b924:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b928:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10b92c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10b930:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10b934:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10b938:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b93c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10b940:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10b944:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10b948:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10b94c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10b950:	3c04800a */ 	lui	$a0,0x800a
/*  f10b954:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b958:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f10b95c:	0fc41fec */ 	jal	func0f107fb0
/*  f10b960:	8c84ee20 */ 	lw	$a0,-0x11e0($a0)
/*  f10b964:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b968:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10b96c:	03e00008 */ 	jr	$ra
/*  f10b970:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerPakSelection(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (pakIsConnected((s8)item->param) == 0) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_MenuStack[g_MpPlayerNum].paknum = item->param;
		menuPushDialog(&menudialog_gamenotes);
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog0010ba10
/*  f10ba10:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10ba14:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10ba18:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ba1c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f10ba20:	10810009 */ 	beq	$a0,$at,.L0f10ba48
/*  f10ba24:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f10ba28:	24010065 */ 	addiu	$at,$zero,0x65
/*  f10ba2c:	10810018 */ 	beq	$a0,$at,.L0f10ba90
/*  f10ba30:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10ba34:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10ba38:	10810012 */ 	beq	$a0,$at,.L0f10ba84
/*  f10ba3c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f10ba40:	10000039 */ 	beqz	$zero,.L0f10bb28
/*  f10ba44:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10ba48:
/*  f10ba48:	0c004e63 */ 	jal	func0001398c
/*  f10ba4c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10ba50:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10ba54:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10ba58:	3c01800a */ 	lui	$at,0x800a
/*  f10ba5c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10ba60:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ba64:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10ba68:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10ba6c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10ba70:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ba74:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10ba78:	002f0821 */ 	addu	$at,$at,$t7
/*  f10ba7c:	10000029 */ 	beqz	$zero,.L0f10bb24
/*  f10ba80:	ac20ee24 */ 	sw	$zero,-0x11dc($at)
.L0f10ba84:
/*  f10ba84:	3c018006 */ 	lui	$at,0x8006
/*  f10ba88:	10000026 */ 	beqz	$zero,.L0f10bb24
/*  f10ba8c:	a0382944 */ 	sb	$t8,0x2944($at)
.L0f10ba90:
/*  f10ba90:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10ba94:	8c5904b4 */ 	lw	$t9,0x4b4($v0)
/*  f10ba98:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f10ba9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f10baa0:	1321001e */ 	beq	$t9,$at,.L0f10bb1c
/*  f10baa4:	3c088007 */ 	lui	$t0,0x8007
/*  f10baa8:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f10baac:	3c04800a */ 	lui	$a0,0x800a
/*  f10bab0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f10bab4:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f10bab8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10babc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10bac0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f10bac4:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10bac8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10bacc:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10bad0:	00892021 */ 	addu	$a0,$a0,$t1
/*  f10bad4:	8c84ee24 */ 	lw	$a0,-0x11dc($a0)
/*  f10bad8:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f10badc:
/*  f10badc:	006a5804 */ 	sllv	$t3,$t2,$v1
/*  f10bae0:	008b6024 */ 	and	$t4,$a0,$t3
/*  f10bae4:	1180000a */ 	beqz	$t4,.L0f10bb10
/*  f10bae8:	24680008 */ 	addiu	$t0,$v1,0x8
/*  f10baec:	944d04e4 */ 	lhu	$t5,0x4e4($v0)
/*  f10baf0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f10baf4:	01095004 */ 	sllv	$t2,$t1,$t0
/*  f10baf8:	31affff0 */ 	andi	$t7,$t5,0xfff0
/*  f10bafc:	35f90008 */ 	ori	$t9,$t7,0x8
/*  f10bb00:	a44f04e4 */ 	sh	$t7,0x4e4($v0)
/*  f10bb04:	a45904e4 */ 	sh	$t9,0x4e4($v0)
/*  f10bb08:	032a5825 */ 	or	$t3,$t9,$t2
/*  f10bb0c:	a44b04e4 */ 	sh	$t3,0x4e4($v0)
.L0f10bb10:
/*  f10bb10:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f10bb14:	5465fff1 */ 	bnel	$v1,$a1,.L0f10badc
/*  f10bb18:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f10bb1c:
/*  f10bb1c:	0c004e72 */ 	jal	func000139c8
/*  f10bb20:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10bb24:
/*  f10bb24:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10bb28:
/*  f10bb28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10bb2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10bb30:	03e00008 */ 	jr	$ra
/*  f10bb34:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerOpenCopyFile
/*  f10bb38:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10bb3c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10bb40:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10bb44:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f10bb48:	14810023 */ 	bne	$a0,$at,.L0f10bbd8
/*  f10bb4c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f10bb50:	3c188007 */ 	lui	$t8,0x8007
/*  f10bb54:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10bb58:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f10bb5c:	3c01800a */ 	lui	$at,0x800a
/*  f10bb60:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10bb64:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10bb68:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10bb6c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10bb70:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10bb74:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10bb78:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10bb7c:	00390821 */ 	addu	$at,$at,$t9
/*  f10bb80:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10bb84:	ac2fee1c */ 	sw	$t7,-0x11e4($at)
/*  f10bb88:	90a50001 */ 	lbu	$a1,0x1($a1)
/*  f10bb8c:	0fc44317 */ 	jal	func0f110c5c
/*  f10bb90:	00002025 */ 	or	$a0,$zero,$zero
/*  f10bb94:	3c088007 */ 	lui	$t0,0x8007
/*  f10bb98:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f10bb9c:	3c0a800a */ 	lui	$t2,%hi(var8009e000)
/*  f10bba0:	254ae000 */ 	addiu	$t2,$t2,%lo(var8009e000)
/*  f10bba4:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f10bba8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10bbac:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10bbb0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f10bbb4:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f10bbb8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10bbbc:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10bbc0:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f10bbc4:	3c048007 */ 	lui	$a0,%hi(menudialog_copyfile)
/*  f10bbc8:	a0400e3f */ 	sb	$zero,0xe3f($v0)
/*  f10bbcc:	ac400e28 */ 	sw	$zero,0xe28($v0)
/*  f10bbd0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10bbd4:	24844a34 */ 	addiu	$a0,$a0,%lo(menudialog_copyfile)
.L0f10bbd8:
/*  f10bbd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10bbdc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10bbe0:	00001025 */ 	or	$v0,$zero,$zero
/*  f10bbe4:	03e00008 */ 	jr	$ra
/*  f10bbe8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerOpenDeleteFile(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MenuStack[g_MpPlayerNum].slotindex = item->param + 1;
		func0f110c5c(0, item->param);
		g_MenuStack[g_MpPlayerNum].unk946 = -1;
		func0f10b0c4(0);
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler0010bc98
/*  f10bc98:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10bc9c:	8dce5bc0 */ 	lw	$t6,0x5bc0($t6)
/*  f10bca0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10bca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10bca8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f10bcac:	15c00003 */ 	bnez	$t6,.L0f10bcbc
/*  f10bcb0:	8cc70000 */ 	lw	$a3,0x0($a2)
/*  f10bcb4:	10000026 */ 	beqz	$zero,.L0f10bd50
/*  f10bcb8:	00001025 */ 	or	$v0,$zero,$zero
.L0f10bcbc:
/*  f10bcbc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10bcc0:	10810013 */ 	beq	$a0,$at,.L0f10bd10
/*  f10bcc4:	00002825 */ 	or	$a1,$zero,$zero
/*  f10bcc8:	24010011 */ 	addiu	$at,$zero,0x11
/*  f10bccc:	10810006 */ 	beq	$a0,$at,.L0f10bce8
/*  f10bcd0:	3c05800a */ 	lui	$a1,0x800a
/*  f10bcd4:	24010012 */ 	addiu	$at,$zero,0x12
/*  f10bcd8:	10810008 */ 	beq	$a0,$at,.L0f10bcfc
/*  f10bcdc:	00e02825 */ 	or	$a1,$a3,$zero
/*  f10bce0:	1000001b */ 	beqz	$zero,.L0f10bd50
/*  f10bce4:	00001025 */ 	or	$v0,$zero,$zero
.L0f10bce8:
/*  f10bce8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f10bcec:	0c004c4c */ 	jal	strcpy
/*  f10bcf0:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10bcf4:	10000016 */ 	beqz	$zero,.L0f10bd50
/*  f10bcf8:	00001025 */ 	or	$v0,$zero,$zero
.L0f10bcfc:
/*  f10bcfc:	3c04800a */ 	lui	$a0,0x800a
/*  f10bd00:	0c004c4c */ 	jal	strcpy
/*  f10bd04:	24842200 */ 	addiu	$a0,$a0,0x2200
/*  f10bd08:	10000011 */ 	beqz	$zero,.L0f10bd50
/*  f10bd0c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10bd10:
/*  f10bd10:	0fc42947 */ 	jal	func0f10a51c
/*  f10bd14:	00002025 */ 	or	$a0,$zero,$zero
/*  f10bd18:	3c188007 */ 	lui	$t8,0x8007
/*  f10bd1c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10bd20:	3c01800a */ 	lui	$at,0x800a
/*  f10bd24:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10bd28:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10bd2c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10bd30:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10bd34:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10bd38:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10bd3c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10bd40:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10bd44:	00390821 */ 	addu	$at,$at,$t9
/*  f10bd48:	ac2fee2c */ 	sw	$t7,-0x11d4($at)
/*  f10bd4c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10bd50:
/*  f10bd50:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10bd54:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10bd58:	03e00008 */ 	jr	$ra
/*  f10bd5c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menucustomChooseAgent
/*  f10bd60:	3c088007 */ 	lui	$t0,0x8007
/*  f10bd64:	8d085bc0 */ 	lw	$t0,0x5bc0($t0)
/*  f10bd68:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f10bd6c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f10bd70:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f10bd74:	00802825 */ 	or	$a1,$a0,$zero
/*  f10bd78:	00c08025 */ 	or	$s0,$a2,$zero
/*  f10bd7c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f10bd80:	15000003 */ 	bnez	$t0,.L0f10bd90
/*  f10bd84:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f10bd88:	10000299 */ 	beqz	$zero,.L0f10c7f0
/*  f10bd8c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10bd90:
/*  f10bd90:	24aeffff */ 	addiu	$t6,$a1,-1
/*  f10bd94:	2dc10019 */ 	sltiu	$at,$t6,0x19
/*  f10bd98:	10200294 */ 	beqz	$at,.L0f10c7ec
/*  f10bd9c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10bda0:	3c017f1b */ 	lui	$at,%hi(var7f1b37fc)
/*  f10bda4:	002e0821 */ 	addu	$at,$at,$t6
/*  f10bda8:	8c2e37fc */ 	lw	$t6,%lo(var7f1b37fc)($at)
/*  f10bdac:	01c00008 */ 	jr	$t6
/*  f10bdb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10bdb4:	3c0f000f */ 	lui	$t7,0xf
/*  f10bdb8:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f10bdbc:	1000028b */ 	beqz	$zero,.L0f10c7ec
/*  f10bdc0:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f10bdc4:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f10bdc8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f10bdcc:	00003025 */ 	or	$a2,$zero,$zero
/*  f10bdd0:	1478003c */ 	bne	$v1,$t8,.L0f10bec4
/*  f10bdd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10bdd8:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f10bddc:	3c0b8007 */ 	lui	$t3,0x8007
/*  f10bde0:	54790034 */ 	bnel	$v1,$t9,.L0f10beb4
/*  f10bde4:	910f030e */ 	lbu	$t7,0x30e($t0)
/*  f10bde8:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f10bdec:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f10bdf0:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f10bdf4:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f10bdf8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f10bdfc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f10be00:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f10be04:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f10be08:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f10be0c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f10be10:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f10be14:	8c4e0e2c */ 	lw	$t6,0xe2c($v0)
/*  f10be18:	546e0026 */ 	bnel	$v1,$t6,.L0f10beb4
/*  f10be1c:	910f030e */ 	lbu	$t7,0x30e($t0)
/*  f10be20:	850502d0 */ 	lh	$a1,0x2d0($t0)
/*  f10be24:	3c07800a */ 	lui	$a3,%hi(var800a22c0)
/*  f10be28:	24e722c0 */ 	addiu	$a3,$a3,%lo(var800a22c0)
/*  f10be2c:	18a0001f */ 	blez	$a1,.L0f10beac
/*  f10be30:	00002025 */ 	or	$a0,$zero,$zero
/*  f10be34:	00001025 */ 	or	$v0,$zero,$zero
.L0f10be38:
/*  f10be38:	01021821 */ 	addu	$v1,$t0,$v0
/*  f10be3c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f10be40:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f10be44:	55f8000a */ 	bnel	$t7,$t8,.L0f10be70
/*  f10be48:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10be4c:	94f90004 */ 	lhu	$t9,0x4($a3)
/*  f10be50:	946b0004 */ 	lhu	$t3,0x4($v1)
/*  f10be54:	572b0006 */ 	bnel	$t9,$t3,.L0f10be70
/*  f10be58:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10be5c:	ae040000 */ 	sw	$a0,0x0($s0)
/*  f10be60:	3c088007 */ 	lui	$t0,0x8007
/*  f10be64:	8d085bc0 */ 	lw	$t0,0x5bc0($t0)
/*  f10be68:	850502d0 */ 	lh	$a1,0x2d0($t0)
/*  f10be6c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f10be70:
/*  f10be70:	0085082a */ 	slt	$at,$a0,$a1
/*  f10be74:	1420fff0 */ 	bnez	$at,.L0f10be38
/*  f10be78:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f10be7c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f10be80:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f10be84:	3c0e800a */ 	lui	$t6,%hi(var8009e000)
/*  f10be88:	25cee000 */ 	addiu	$t6,$t6,%lo(var8009e000)
/*  f10be8c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f10be90:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f10be94:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f10be98:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f10be9c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f10bea0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f10bea4:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f10bea8:	01ae1021 */ 	addu	$v0,$t5,$t6
.L0f10beac:
/*  f10beac:	ac400e2c */ 	sw	$zero,0xe2c($v0)
/*  f10beb0:	910f030e */ 	lbu	$t7,0x30e($t0)
.L0f10beb4:
/*  f10beb4:	11e00010 */ 	beqz	$t7,.L0f10bef8
/*  f10beb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10bebc:	1000000e */ 	beqz	$zero,.L0f10bef8
/*  f10bec0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f10bec4:
/*  f10bec4:	3c188007 */ 	lui	$t8,0x8007
/*  f10bec8:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10becc:	3c01800a */ 	lui	$at,0x800a
/*  f10bed0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10bed4:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10bed8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10bedc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10bee0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10bee4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10bee8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10beec:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10bef0:	00390821 */ 	addu	$at,$at,$t9
/*  f10bef4:	ac20ee2c */ 	sw	$zero,-0x11d4($at)
.L0f10bef8:
/*  f10bef8:	10c0023c */ 	beqz	$a2,.L0f10c7ec
/*  f10befc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f10bf00:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f10bf04:	8ccb047c */ 	lw	$t3,0x47c($a2)
/*  f10bf08:	51600239 */ 	beqzl	$t3,.L0f10c7f0
/*  f10bf0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10bf10:	850502d0 */ 	lh	$a1,0x2d0($t0)
/*  f10bf14:	00002025 */ 	or	$a0,$zero,$zero
/*  f10bf18:	00001025 */ 	or	$v0,$zero,$zero
/*  f10bf1c:	18a00233 */ 	blez	$a1,.L0f10c7ec
.L0f10bf20:
/*  f10bf20:	01021821 */ 	addu	$v1,$t0,$v0
/*  f10bf24:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f10bf28:	8ccc047c */ 	lw	$t4,0x47c($a2)
/*  f10bf2c:	558d000b */ 	bnel	$t4,$t5,.L0f10bf5c
/*  f10bf30:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10bf34:	94ce0480 */ 	lhu	$t6,0x480($a2)
/*  f10bf38:	946f0004 */ 	lhu	$t7,0x4($v1)
/*  f10bf3c:	55cf0007 */ 	bnel	$t6,$t7,.L0f10bf5c
/*  f10bf40:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10bf44:	ae040000 */ 	sw	$a0,0x0($s0)
/*  f10bf48:	acc0047c */ 	sw	$zero,0x47c($a2)
/*  f10bf4c:	3c088007 */ 	lui	$t0,0x8007
/*  f10bf50:	8d085bc0 */ 	lw	$t0,0x5bc0($t0)
/*  f10bf54:	850502d0 */ 	lh	$a1,0x2d0($t0)
/*  f10bf58:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f10bf5c:
/*  f10bf5c:	0085082a */ 	slt	$at,$a0,$a1
/*  f10bf60:	1420ffef */ 	bnez	$at,.L0f10bf20
/*  f10bf64:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f10bf68:	10000221 */ 	beqz	$zero,.L0f10c7f0
/*  f10bf6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10bf70:	851802d0 */ 	lh	$t8,0x2d0($t0)
/*  f10bf74:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f10bf78:	1000021c */ 	beqz	$zero,.L0f10c7ec
/*  f10bf7c:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f10bf80:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f10bf84:	2409000c */ 	addiu	$t1,$zero,0xc
/*  f10bf88:	00005025 */ 	or	$t2,$zero,$zero
/*  f10bf8c:	afab0130 */ 	sw	$t3,0x130($sp)
/*  f10bf90:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f10bf94:	afa00100 */ 	sw	$zero,0x100($sp)
/*  f10bf98:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f10bf9c:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f10bfa0:	afa0010c */ 	sw	$zero,0x10c($sp)
/*  f10bfa4:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f10bfa8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f10bfac:	850d02d0 */ 	lh	$t5,0x2d0($t0)
/*  f10bfb0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f10bfb4:	104d003c */ 	beq	$v0,$t5,.L0f10c0a8
/*  f10bfb8:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f10bfbc:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10bfc0:	010e5021 */ 	addu	$t2,$t0,$t6
/*  f10bfc4:	11400038 */ 	beqz	$t2,.L0f10c0a8
/*  f10bfc8:	25440006 */ 	addiu	$a0,$t2,0x6
/*  f10bfcc:	27af0110 */ 	addiu	$t7,$sp,0x110
/*  f10bfd0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f10bfd4:	27a50118 */ 	addiu	$a1,$sp,0x118
/*  f10bfd8:	27a60117 */ 	addiu	$a2,$sp,0x117
/*  f10bfdc:	27a70116 */ 	addiu	$a3,$sp,0x116
/*  f10bfe0:	0fc4417f */ 	jal	func0f1105fc
/*  f10bfe4:	afaa0124 */ 	sw	$t2,0x124($sp)
/*  f10bfe8:	8fa60110 */ 	lw	$a2,0x110($sp)
/*  f10bfec:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f10bff0:	93a50117 */ 	lbu	$a1,0x117($sp)
/*  f10bff4:	00c7001b */ 	divu	$zero,$a2,$a3
/*  f10bff8:	0000c010 */ 	mfhi	$t8
/*  f10bffc:	00003012 */ 	mflo	$a2
/*  f10c000:	28a10012 */ 	slti	$at,$a1,0x12
/*  f10c004:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f10c008:	14e00002 */ 	bnez	$a3,.L0f10c014
/*  f10c00c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c010:	0007000d */ 	break	0x7
.L0f10c014:
/*  f10c014:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f10c018:	54200005 */ 	bnezl	$at,.L0f10c030
/*  f10c01c:	93ab0116 */ 	lbu	$t3,0x116($sp)
/*  f10c020:	24190011 */ 	addiu	$t9,$zero,0x11
/*  f10c024:	a3b90117 */ 	sb	$t9,0x117($sp)
/*  f10c028:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f10c02c:	93ab0116 */ 	lbu	$t3,0x116($sp)
.L0f10c030:
/*  f10c030:	24a9000c */ 	addiu	$t1,$a1,0xc
/*  f10c034:	29610003 */ 	slti	$at,$t3,0x3
/*  f10c038:	54200004 */ 	bnezl	$at,.L0f10c04c
/*  f10c03c:	240105a0 */ 	addiu	$at,$zero,0x5a0
/*  f10c040:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f10c044:	a3ac0116 */ 	sb	$t4,0x116($sp)
/*  f10c048:	240105a0 */ 	addiu	$at,$zero,0x5a0
.L0f10c04c:
/*  f10c04c:	00c1001b */ 	divu	$zero,$a2,$at
/*  f10c050:	00001012 */ 	mflo	$v0
/*  f10c054:	00026880 */ 	sll	$t5,$v0,0x2
/*  f10c058:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f10c05c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f10c060:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f10c064:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f10c068:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f10c06c:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f10c070:	00cd1823 */ 	subu	$v1,$a2,$t5
/*  f10c074:	0067001b */ 	divu	$zero,$v1,$a3
/*  f10c078:	00002012 */ 	mflo	$a0
/*  f10c07c:	00047100 */ 	sll	$t6,$a0,0x4
/*  f10c080:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f10c084:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10c088:	006e7823 */ 	subu	$t7,$v1,$t6
/*  f10c08c:	afa2010c */ 	sw	$v0,0x10c($sp)
/*  f10c090:	14e00002 */ 	bnez	$a3,.L0f10c09c
/*  f10c094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c098:	0007000d */ 	break	0x7
.L0f10c09c:
/*  f10c09c:	afa40108 */ 	sw	$a0,0x108($sp)
/*  f10c0a0:	afaf0104 */ 	sw	$t7,0x104($sp)
/*  f10c0a4:	afa60110 */ 	sw	$a2,0x110($sp)
.L0f10c0a8:
/*  f10c0a8:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f10c0ac:	3c0be700 */ 	lui	$t3,0xe700
/*  f10c0b0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f10c0b4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f10c0b8:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f10c0bc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f10c0c0:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f10c0c4:	8fac0130 */ 	lw	$t4,0x130($sp)
/*  f10c0c8:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f10c0cc:	3c19b900 */ 	lui	$t9,0xb900
/*  f10c0d0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f10c0d4:	afad0130 */ 	sw	$t5,0x130($sp)
/*  f10c0d8:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f10c0dc:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f10c0e0:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f10c0e4:	37390002 */ 	ori	$t9,$t9,0x2
/*  f10c0e8:	3c0dba00 */ 	lui	$t5,0xba00
/*  f10c0ec:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f10c0f0:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f10c0f4:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f10c0f8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f10c0fc:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f10c100:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f10c104:	3c18ba00 */ 	lui	$t8,0xba00
/*  f10c108:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f10c10c:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f10c110:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f10c114:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f10c118:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f10c11c:	37180903 */ 	ori	$t8,$t8,0x903
/*  f10c120:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f10c124:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f10c128:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f10c12c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f10c130:	add80000 */ 	sw	$t8,0x0($t6)
/*  f10c134:	00095880 */ 	sll	$t3,$t1,0x2
/*  f10c138:	3c0c800b */ 	lui	$t4,0x800b
/*  f10c13c:	8d8cb5a8 */ 	lw	$t4,-0x4a58($t4)
/*  f10c140:	01695823 */ 	subu	$t3,$t3,$t1
/*  f10c144:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10c148:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f10c14c:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f10c150:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f10c154:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f10c158:	afaa0124 */ 	sw	$t2,0x124($sp)
/*  f10c15c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f10c160:	27a40130 */ 	addiu	$a0,$sp,0x130
/*  f10c164:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f10c168:	00003825 */ 	or	$a3,$zero,$zero
/*  f10c16c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f10c170:	016c2821 */ 	addu	$a1,$t3,$t4
/*  f10c174:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f10c178:	8fa7012c */ 	lw	$a3,0x12c($sp)
/*  f10c17c:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f10c180:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f10c184:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f10c188:	3c19ba00 */ 	lui	$t9,0xba00
/*  f10c18c:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f10c190:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f10c194:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f10c198:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f10c19c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f10c1a0:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f10c1a4:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f10c1a8:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f10c1ac:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f10c1b0:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f10c1b4:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f10c1b8:	3c18fb00 */ 	lui	$t8,0xfb00
/*  f10c1bc:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f10c1c0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f10c1c4:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f10c1c8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f10c1cc:	8cf9000c */ 	lw	$t9,0xc($a3)
/*  f10c1d0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f10c1d4:	3c18ff37 */ 	lui	$t8,0xff37
/*  f10c1d8:	332b00ff */ 	andi	$t3,$t9,0xff
/*  f10c1dc:	01616025 */ 	or	$t4,$t3,$at
/*  f10c1e0:	adcc0004 */ 	sw	$t4,0x4($t6)
/*  f10c1e4:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f10c1e8:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f10c1ec:	35ef9a25 */ 	ori	$t7,$t7,0x9a25
/*  f10c1f0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f10c1f4:	afae0130 */ 	sw	$t6,0x130($sp)
/*  f10c1f8:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f10c1fc:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f10c200:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f10c204:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f10c208:	3c088008 */ 	lui	$t0,%hi(var8007fac0)
/*  f10c20c:	2508fac0 */ 	addiu	$t0,$t0,%lo(var8007fac0)
/*  f10c210:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f10c214:	afab0130 */ 	sw	$t3,0x130($sp)
/*  f10c218:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f10c21c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f10c220:	01a02825 */ 	or	$a1,$t5,$zero
/*  f10c224:	258d003c */ 	addiu	$t5,$t4,0x3c
/*  f10c228:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f10c22c:	01cf0019 */ 	multu	$t6,$t7
/*  f10c230:	8ced0004 */ 	lw	$t5,0x4($a3)
/*  f10c234:	03203025 */ 	or	$a2,$t9,$zero
/*  f10c238:	3c01e400 */ 	lui	$at,0xe400
/*  f10c23c:	25ae0026 */ 	addiu	$t6,$t5,0x26
/*  f10c240:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10c244:	0000c012 */ 	mflo	$t8
/*  f10c248:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f10c24c:	00195b00 */ 	sll	$t3,$t9,0xc
/*  f10c250:	01616025 */ 	or	$t4,$t3,$at
/*  f10c254:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f10c258:	0198c825 */ 	or	$t9,$t4,$t8
/*  f10c25c:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f10c260:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f10c264:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f10c268:	256d0004 */ 	addiu	$t5,$t3,0x4
/*  f10c26c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f10c270:	01cf0019 */ 	multu	$t6,$t7
/*  f10c274:	8ceb0004 */ 	lw	$t3,0x4($a3)
/*  f10c278:	256d0002 */ 	addiu	$t5,$t3,0x2
/*  f10c27c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f10c280:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f10c284:	240e0480 */ 	addiu	$t6,$zero,0x480
/*  f10c288:	3c0db400 */ 	lui	$t5,0xb400
/*  f10c28c:	00006012 */ 	mflo	$t4
/*  f10c290:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f10c294:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f10c298:	032f6025 */ 	or	$t4,$t9,$t7
/*  f10c29c:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f10c2a0:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f10c2a4:	3c0cb300 */ 	lui	$t4,0xb300
/*  f10c2a8:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f10c2ac:	afab0130 */ 	sw	$t3,0x130($sp)
/*  f10c2b0:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f10c2b4:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f10c2b8:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f10c2bc:	03001025 */ 	or	$v0,$t8,$zero
/*  f10c2c0:	240b0400 */ 	addiu	$t3,$zero,0x400
/*  f10c2c4:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f10c2c8:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f10c2cc:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f10c2d0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f10c2d4:	03201825 */ 	or	$v1,$t9,$zero
/*  f10c2d8:	0178001a */ 	div	$zero,$t3,$t8
/*  f10c2dc:	00007012 */ 	mflo	$t6
/*  f10c2e0:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f10c2e4:	372ffc00 */ 	ori	$t7,$t9,0xfc00
/*  f10c2e8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f10c2ec:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f10c2f0:	17000002 */ 	bnez	$t8,.L0f10c2fc
/*  f10c2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c2f8:	0007000d */ 	break	0x7
.L0f10c2fc:
/*  f10c2fc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f10c300:	17010004 */ 	bne	$t8,$at,.L0f10c314
/*  f10c304:	3c018000 */ 	lui	$at,0x8000
/*  f10c308:	15610002 */ 	bne	$t3,$at,.L0f10c314
/*  f10c30c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c310:	0006000d */ 	break	0x6
.L0f10c314:
/*  f10c314:	258b003e */ 	addiu	$t3,$t4,0x3e
/*  f10c318:	afab0144 */ 	sw	$t3,0x144($sp)
/*  f10c31c:	8cf80004 */ 	lw	$t8,0x4($a3)
/*  f10c320:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c324:	afaa0124 */ 	sw	$t2,0x124($sp)
/*  f10c328:	270d0004 */ 	addiu	$t5,$t8,0x4
/*  f10c32c:	0fc54d8a */ 	jal	func0f153628
/*  f10c330:	afad0140 */ 	sw	$t5,0x140($sp)
/*  f10c334:	3c198007 */ 	lui	$t9,0x8007
/*  f10c338:	8f395bc0 */ 	lw	$t9,0x5bc0($t9)
/*  f10c33c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f10c340:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f10c344:	872f02d0 */ 	lh	$t7,0x2d0($t9)
/*  f10c348:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f10c34c:	15cf001d */ 	bne	$t6,$t7,.L0f10c3c4
/*  f10c350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c354:	0fc5b9f1 */ 	jal	textGet
/*  f10c358:	24045793 */ 	addiu	$a0,$zero,0x5793
/*  f10c35c:	0c002f02 */ 	jal	func0000bc08
/*  f10c360:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f10c364:	00028400 */ 	sll	$s0,$v0,0x10
/*  f10c368:	00106403 */ 	sra	$t4,$s0,0x10
/*  f10c36c:	0c002f06 */ 	jal	func0000bc18
/*  f10c370:	01808025 */ 	or	$s0,$t4,$zero
/*  f10c374:	3c0b8008 */ 	lui	$t3,0x8008
/*  f10c378:	3c188008 */ 	lui	$t8,0x8008
/*  f10c37c:	8f18fb14 */ 	lw	$t8,-0x4ec($t8)
/*  f10c380:	8d6bfb18 */ 	lw	$t3,-0x4e8($t3)
/*  f10c384:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f10c388:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f10c38c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f10c390:	8db9000c */ 	lw	$t9,0xc($t5)
/*  f10c394:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f10c398:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10c39c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10c3a0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10c3a4:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c3a8:	27a50144 */ 	addiu	$a1,$sp,0x144
/*  f10c3ac:	27a60140 */ 	addiu	$a2,$sp,0x140
/*  f10c3b0:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f10c3b4:	0fc5580f */ 	jal	func0f15603c
/*  f10c3b8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f10c3bc:	100000c8 */ 	beqz	$zero,.L0f10c6e0
/*  f10c3c0:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f10c3c4:
/*  f10c3c4:	114000c6 */ 	beqz	$t2,.L0f10c6e0
/*  f10c3c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c3cc:	0c002f02 */ 	jal	func0000bc08
/*  f10c3d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c3d4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f10c3d8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f10c3dc:	0c002f06 */ 	jal	func0000bc18
/*  f10c3e0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f10c3e4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f10c3e8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f10c3ec:	8d8cfb14 */ 	lw	$t4,-0x4ec($t4)
/*  f10c3f0:	8deffb18 */ 	lw	$t7,-0x4e8($t7)
/*  f10c3f4:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f10c3f8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f10c3fc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f10c400:	8d78000c */ 	lw	$t8,0xc($t3)
/*  f10c404:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10c408:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f10c40c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10c410:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10c414:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10c418:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c41c:	27a50144 */ 	addiu	$a1,$sp,0x144
/*  f10c420:	27a60140 */ 	addiu	$a2,$sp,0x140
/*  f10c424:	27a70118 */ 	addiu	$a3,$sp,0x118
/*  f10c428:	0fc5580f */ 	jal	func0f15603c
/*  f10c42c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f10c430:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f10c434:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f10c438:	93a50117 */ 	lbu	$a1,0x117($sp)
/*  f10c43c:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f10c440:	272e0012 */ 	addiu	$t6,$t9,0x12
/*  f10c444:	afae0140 */ 	sw	$t6,0x140($sp)
/*  f10c448:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f10c44c:	25ec003e */ 	addiu	$t4,$t7,0x3e
/*  f10c450:	18a00019 */ 	blez	$a1,.L0f10c4b8
/*  f10c454:	afac0144 */ 	sw	$t4,0x144($sp)
/*  f10c458:	00055880 */ 	sll	$t3,$a1,0x2
/*  f10c45c:	01655823 */ 	subu	$t3,$t3,$a1
/*  f10c460:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10c464:	3c048007 */ 	lui	$a0,0x8007
/*  f10c468:	008b2021 */ 	addu	$a0,$a0,$t3
/*  f10c46c:	0fc5b9f1 */ 	jal	textGet
/*  f10c470:	94841e66 */ 	lhu	$a0,0x1e66($a0)
/*  f10c474:	93b80117 */ 	lbu	$t8,0x117($sp)
/*  f10c478:	3c048007 */ 	lui	$a0,0x8007
/*  f10c47c:	00408025 */ 	or	$s0,$v0,$zero
/*  f10c480:	00186880 */ 	sll	$t5,$t8,0x2
/*  f10c484:	01b86823 */ 	subu	$t5,$t5,$t8
/*  f10c488:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f10c48c:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f10c490:	0fc5b9f1 */ 	jal	textGet
/*  f10c494:	94841e68 */ 	lhu	$a0,0x1e68($a0)
/*  f10c498:	3c057f1b */ 	lui	$a1,%hi(var7f1b350c)
/*  f10c49c:	24a5350c */ 	addiu	$a1,$a1,%lo(var7f1b350c)
/*  f10c4a0:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f10c4a4:	02003025 */ 	or	$a2,$s0,$zero
/*  f10c4a8:	0c004dad */ 	jal	sprintf
/*  f10c4ac:	00403825 */ 	or	$a3,$v0,$zero
/*  f10c4b0:	10000006 */ 	beqz	$zero,.L0f10c4cc
/*  f10c4b4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10c4b8:
/*  f10c4b8:	0fc5b9f1 */ 	jal	textGet
/*  f10c4bc:	24045794 */ 	addiu	$a0,$zero,0x5794
/*  f10c4c0:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f10c4c4:	0c004c4c */ 	jal	strcpy
/*  f10c4c8:	00402825 */ 	or	$a1,$v0,$zero
.L0f10c4cc:
/*  f10c4cc:	3c057f1b */ 	lui	$a1,%hi(var7f1b3514)
/*  f10c4d0:	24a53514 */ 	addiu	$a1,$a1,%lo(var7f1b3514)
/*  f10c4d4:	0c004c89 */ 	jal	func00013224
/*  f10c4d8:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f10c4dc:	0c002f02 */ 	jal	func0000bc08
/*  f10c4e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c4e4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f10c4e8:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f10c4ec:	0c002f06 */ 	jal	func0000bc18
/*  f10c4f0:	03208025 */ 	or	$s0,$t9,$zero
/*  f10c4f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f10c4f8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f10c4fc:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f10c500:	8dcefb10 */ 	lw	$t6,-0x4f0($t6)
/*  f10c504:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f10c508:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f10c50c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f10c510:	8d8b000c */ 	lw	$t3,0xc($t4)
/*  f10c514:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f10c518:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10c51c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10c520:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10c524:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c528:	27a50144 */ 	addiu	$a1,$sp,0x144
/*  f10c52c:	27a60140 */ 	addiu	$a2,$sp,0x140
/*  f10c530:	27a7009c */ 	addiu	$a3,$sp,0x9c
/*  f10c534:	0fc5580f */ 	jal	func0f15603c
/*  f10c538:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f10c53c:	8fb8012c */ 	lw	$t8,0x12c($sp)
/*  f10c540:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f10c544:	8fae0140 */ 	lw	$t6,0x140($sp)
/*  f10c548:	8f0d0000 */ 	lw	$t5,0x0($t8)
/*  f10c54c:	8fac010c */ 	lw	$t4,0x10c($sp)
/*  f10c550:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10c554:	25b9003e */ 	addiu	$t9,$t5,0x3e
/*  f10c558:	afb90144 */ 	sw	$t9,0x144($sp)
/*  f10c55c:	1980000f */ 	blez	$t4,.L0f10c59c
/*  f10c560:	afaf0140 */ 	sw	$t7,0x140($sp)
/*  f10c564:	0fc5b9f1 */ 	jal	textGet
/*  f10c568:	24045795 */ 	addiu	$a0,$zero,0x5795
/*  f10c56c:	8fab0108 */ 	lw	$t3,0x108($sp)
/*  f10c570:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f10c574:	3c057f1b */ 	lui	$a1,%hi(var7f1b3518)
/*  f10c578:	24a53518 */ 	addiu	$a1,$a1,%lo(var7f1b3518)
/*  f10c57c:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f10c580:	00403025 */ 	or	$a2,$v0,$zero
/*  f10c584:	8fa7010c */ 	lw	$a3,0x10c($sp)
/*  f10c588:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f10c58c:	0c004dad */ 	jal	sprintf
/*  f10c590:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f10c594:	1000000b */ 	beqz	$zero,.L0f10c5c4
/*  f10c598:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10c59c:
/*  f10c59c:	0fc5b9f1 */ 	jal	textGet
/*  f10c5a0:	24045795 */ 	addiu	$a0,$zero,0x5795
/*  f10c5a4:	8fad0104 */ 	lw	$t5,0x104($sp)
/*  f10c5a8:	3c057f1b */ 	lui	$a1,%hi(var7f1b3528)
/*  f10c5ac:	24a53528 */ 	addiu	$a1,$a1,%lo(var7f1b3528)
/*  f10c5b0:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f10c5b4:	00403025 */ 	or	$a2,$v0,$zero
/*  f10c5b8:	8fa70108 */ 	lw	$a3,0x108($sp)
/*  f10c5bc:	0c004dad */ 	jal	sprintf
/*  f10c5c0:	afad0010 */ 	sw	$t5,0x10($sp)
.L0f10c5c4:
/*  f10c5c4:	3c198008 */ 	lui	$t9,0x8008
/*  f10c5c8:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f10c5cc:	3c078008 */ 	lui	$a3,0x8008
/*  f10c5d0:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f10c5d4:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f10c5d8:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f10c5dc:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f10c5e0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f10c5e4:	0fc55cbe */ 	jal	func0f1572f8
/*  f10c5e8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f10c5ec:	0c002f02 */ 	jal	func0000bc08
/*  f10c5f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c5f4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f10c5f8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f10c5fc:	0c002f06 */ 	jal	func0000bc18
/*  f10c600:	01c08025 */ 	or	$s0,$t6,$zero
/*  f10c604:	3c0f8008 */ 	lui	$t7,0x8008
/*  f10c608:	3c0c8008 */ 	lui	$t4,0x8008
/*  f10c60c:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f10c610:	8deffb10 */ 	lw	$t7,-0x4f0($t7)
/*  f10c614:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f10c618:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f10c61c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f10c620:	8d78000c */ 	lw	$t8,0xc($t3)
/*  f10c624:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f10c628:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10c62c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10c630:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10c634:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c638:	27a50144 */ 	addiu	$a1,$sp,0x144
/*  f10c63c:	27a60140 */ 	addiu	$a2,$sp,0x140
/*  f10c640:	27a7009c */ 	addiu	$a3,$sp,0x9c
/*  f10c644:	0fc5580f */ 	jal	func0f15603c
/*  f10c648:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f10c64c:	8fad0140 */ 	lw	$t5,0x140($sp)
/*  f10c650:	8fae0144 */ 	lw	$t6,0x144($sp)
/*  f10c654:	3c057f1b */ 	lui	$a1,%hi(var7f1b3538)
/*  f10c658:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f10c65c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10c660:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f10c664:	afb90140 */ 	sw	$t9,0x140($sp)
/*  f10c668:	afaf0144 */ 	sw	$t7,0x144($sp)
/*  f10c66c:	24a53538 */ 	addiu	$a1,$a1,%lo(var7f1b3538)
/*  f10c670:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f10c674:	0c004dad */ 	jal	sprintf
/*  f10c678:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f10c67c:	0c002f02 */ 	jal	func0000bc08
/*  f10c680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c684:	00028400 */ 	sll	$s0,$v0,0x10
/*  f10c688:	00106403 */ 	sra	$t4,$s0,0x10
/*  f10c68c:	0c002f06 */ 	jal	func0000bc18
/*  f10c690:	01808025 */ 	or	$s0,$t4,$zero
/*  f10c694:	3c0b8008 */ 	lui	$t3,0x8008
/*  f10c698:	3c188008 */ 	lui	$t8,0x8008
/*  f10c69c:	8f18fb04 */ 	lw	$t8,-0x4fc($t8)
/*  f10c6a0:	8d6bfb08 */ 	lw	$t3,-0x4f8($t3)
/*  f10c6a4:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f10c6a8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f10c6ac:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f10c6b0:	8db9000c */ 	lw	$t9,0xc($t5)
/*  f10c6b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f10c6b8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10c6bc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10c6c0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10c6c4:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c6c8:	27a50144 */ 	addiu	$a1,$sp,0x144
/*  f10c6cc:	27a60140 */ 	addiu	$a2,$sp,0x140
/*  f10c6d0:	27a7009c */ 	addiu	$a3,$sp,0x9c
/*  f10c6d4:	0fc5580f */ 	jal	func0f15603c
/*  f10c6d8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f10c6dc:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f10c6e0:
/*  f10c6e0:	0fc54de0 */ 	jal	func0f153780
/*  f10c6e4:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f10c6e8:	10000042 */ 	beqz	$zero,.L0f10c7f4
/*  f10c6ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f10c6f0:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f10c6f4:	1000003d */ 	beqz	$zero,.L0f10c7ec
/*  f10c6f8:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f10c6fc:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f10c700:	850f02d0 */ 	lh	$t7,0x2d0($t0)
/*  f10c704:	3c04800a */ 	lui	$a0,0x800a
/*  f10c708:	00026080 */ 	sll	$t4,$v0,0x2
/*  f10c70c:	144f0008 */ 	bne	$v0,$t7,.L0f10c730
/*  f10c710:	01826023 */ 	subu	$t4,$t4,$v0
/*  f10c714:	0fc43da6 */ 	jal	func0f10f698
/*  f10c718:	24842200 */ 	addiu	$a0,$a0,0x2200
/*  f10c71c:	3c048007 */ 	lui	$a0,%hi(menudialog_enteragentname)
/*  f10c720:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10c724:	24844d80 */ 	addiu	$a0,$a0,%lo(menudialog_enteragentname)
/*  f10c728:	10000031 */ 	beqz	$zero,.L0f10c7f0
/*  f10c72c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10c730:
/*  f10c730:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f10c734:	010c1821 */ 	addu	$v1,$t0,$t4
/*  f10c738:	1060002c */ 	beqz	$v1,.L0f10c7ec
/*  f10c73c:	3c07800a */ 	lui	$a3,0x800a
/*  f10c740:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f10c744:	24e422c0 */ 	addiu	$a0,$a3,0x22c0
/*  f10c748:	24050064 */ 	addiu	$a1,$zero,0x64
/*  f10c74c:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f10c750:	94780004 */ 	lhu	$t8,0x4($v1)
/*  f10c754:	00003025 */ 	or	$a2,$zero,$zero
/*  f10c758:	0fc42539 */ 	jal	func0f1094e4
/*  f10c75c:	a4980004 */ 	sh	$t8,0x4($a0)
/*  f10c760:	10000023 */ 	beqz	$zero,.L0f10c7f0
/*  f10c764:	00001025 */ 	or	$v0,$zero,$zero
/*  f10c768:	910d030a */ 	lbu	$t5,0x30a($t0)
/*  f10c76c:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f10c770:	1000001e */ 	beqz	$zero,.L0f10c7ec
/*  f10c774:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f10c778:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f10c77c:	910e030a */ 	lbu	$t6,0x30a($t0)
/*  f10c780:	00002025 */ 	or	$a0,$zero,$zero
/*  f10c784:	004e082b */ 	sltu	$at,$v0,$t6
/*  f10c788:	14200005 */ 	bnez	$at,.L0f10c7a0
/*  f10c78c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c790:	0fc5b9f1 */ 	jal	textGet
/*  f10c794:	24045792 */ 	addiu	$a0,$zero,0x5792
/*  f10c798:	10000016 */ 	beqz	$zero,.L0f10c7f4
/*  f10c79c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f10c7a0:
/*  f10c7a0:	0fc421ae */ 	jal	func0f1086b8
/*  f10c7a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f10c7a8:	10000012 */ 	beqz	$zero,.L0f10c7f4
/*  f10c7ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f10c7b0:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f10c7b4:	910f030a */ 	lbu	$t7,0x30a($t0)
/*  f10c7b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f10c7bc:	004f082b */ 	sltu	$at,$v0,$t7
/*  f10c7c0:	14200005 */ 	bnez	$at,.L0f10c7d8
/*  f10c7c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c7c8:	850c02d0 */ 	lh	$t4,0x2d0($t0)
/*  f10c7cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f10c7d0:	10000007 */ 	beqz	$zero,.L0f10c7f0
/*  f10c7d4:	ae0c0008 */ 	sw	$t4,0x8($s0)
.L0f10c7d8:
/*  f10c7d8:	0fc421ae */ 	jal	func0f1086b8
/*  f10c7dc:	00403025 */ 	or	$a2,$v0,$zero
/*  f10c7e0:	ae020008 */ 	sw	$v0,0x8($s0)
/*  f10c7e4:	10000002 */ 	beqz	$zero,.L0f10c7f0
/*  f10c7e8:	00001025 */ 	or	$v0,$zero,$zero
.L0f10c7ec:
/*  f10c7ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f10c7f0:
/*  f10c7f0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f10c7f4:
/*  f10c7f4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f10c7f8:	27bd0148 */ 	addiu	$sp,$sp,0x148
/*  f10c7fc:	03e00008 */ 	jr	$ra
/*  f10c800:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010c804
/*  f10c804:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10c808:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10c80c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f10c810:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f10c814:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f10c818:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f10c81c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f10c820:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f10c824:	10810006 */ 	beq	$a0,$at,.L0f10c840
/*  f10c828:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f10c82c:	24010065 */ 	addiu	$at,$zero,0x65
/*  f10c830:	10810029 */ 	beq	$a0,$at,.L0f10c8d8
/*  f10c834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c838:	1000002a */ 	beqz	$zero,.L0f10c8e4
/*  f10c83c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f10c840:
/*  f10c840:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10c844:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10c848:	3c01800a */ 	lui	$at,0x800a
/*  f10c84c:	00002025 */ 	or	$a0,$zero,$zero
/*  f10c850:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10c854:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10c858:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10c85c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10c860:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10c864:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10c868:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10c86c:	002f0821 */ 	addu	$at,$at,$t7
/*  f10c870:	ac20ee1c */ 	sw	$zero,-0x11e4($at)
/*  f10c874:	0fc44317 */ 	jal	func0f110c5c
/*  f10c878:	00002825 */ 	or	$a1,$zero,$zero
/*  f10c87c:	0fc62084 */ 	jal	func0f188210
/*  f10c880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c884:	3c11800b */ 	lui	$s1,%hi(g_MpChrs)
/*  f10c888:	3c127f1b */ 	lui	$s2,%hi(var7f1b3540)
/*  f10c88c:	26523540 */ 	addiu	$s2,$s2,%lo(var7f1b3540)
/*  f10c890:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpChrs)
/*  f10c894:	00008025 */ 	or	$s0,$zero,$zero
/*  f10c898:	24130004 */ 	addiu	$s3,$zero,0x4
.L0f10c89c:
/*  f10c89c:	92380000 */ 	lbu	$t8,0x0($s1)
/*  f10c8a0:	57000009 */ 	bnezl	$t8,.L0f10c8c8
/*  f10c8a4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10c8a8:	0fc5b9f1 */ 	jal	textGet
/*  f10c8ac:	240459b5 */ 	addiu	$a0,$zero,0x59b5
/*  f10c8b0:	02202025 */ 	or	$a0,$s1,$zero
/*  f10c8b4:	02402825 */ 	or	$a1,$s2,$zero
/*  f10c8b8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10c8bc:	0c004dad */ 	jal	sprintf
/*  f10c8c0:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f10c8c4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f10c8c8:
/*  f10c8c8:	1613fff4 */ 	bne	$s0,$s3,.L0f10c89c
/*  f10c8cc:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f10c8d0:	10000004 */ 	beqz	$zero,.L0f10c8e4
/*  f10c8d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f10c8d8:
/*  f10c8d8:	0fc442fe */ 	jal	func0f110bf8
/*  f10c8dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c8e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f10c8e4:
/*  f10c8e4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f10c8e8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f10c8ec:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f10c8f0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f10c8f4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10c8f8:	03e00008 */ 	jr	$ra
/*  f10c8fc:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f10c900
/*  f10c900:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10c904:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10c908:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10c90c:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10c910:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10c914:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10c918:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10c91c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10c920:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10c924:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10c928:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10c92c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10c930:	9059083c */ 	lbu	$t9,0x83c($v0)
/*  f10c934:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10c938:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10c93c:	17200007 */ 	bnez	$t9,.L0f10c95c
/*  f10c940:	3c048007 */ 	lui	$a0,%hi(menudialog_fileselect)
/*  f10c944:	a040083b */ 	sb	$zero,0x83b($v0)
/*  f10c948:	24844dd4 */ 	addiu	$a0,$a0,%lo(menudialog_fileselect)
/*  f10c94c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10c950:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f10c954:	10000002 */ 	beqz	$zero,.L0f10c960
/*  f10c958:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10c95c:
/*  f10c95c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10c960:
/*  f10c960:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10c964:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10c968:	03e00008 */ 	jr	$ra
/*  f10c96c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10c970
/*  f10c970:	3c028007 */ 	lui	$v0,%hi(g_MpPlayerNum)
/*  f10c974:	24421448 */ 	addiu	$v0,$v0,%lo(g_MpPlayerNum)
/*  f10c978:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f10c97c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10c980:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10c984:	3c048007 */ 	lui	$a0,%hi(menudialog_controllerpakmenu)
/*  f10c988:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f10c98c:	24844c38 */ 	addiu	$a0,$a0,%lo(menudialog_controllerpakmenu)
/*  f10c990:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f10c994:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10c998:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10c99c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10c9a0:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f10c9a4:	3c018007 */ 	lui	$at,0x8007
/*  f10c9a8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10c9ac:	03e00008 */ 	jr	$ra
/*  f10c9b0:	ac2f1448 */ 	sw	$t7,0x1448($at)
/*  f10c9b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10c9bc:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler4MbDropOut(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();

		if (func0f18c87c() == 1) {
			func0f0f820c(&g_4MbMainMenu, 11);
		}
	}

	return 0;
}

s32 menuhandler0010ca1c(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == 0x5d) {
			func0f0f820c(&g_4MbMainMenu, 11);
		} else {
			func0f0f820c(&menudialog_196b0, 2);
		}
	}

	return 0;
}

s32 menuhandler4MbAdvancedSetup(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&g_4MbAdvancedSetupMenuDialog, 11);
	}

	return 0;
}

s32 menuhandler0010cabc(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f19b77c(g_MenuStack[g_MpPlayerNum].slotindex);
		func0f0f820c(&menudialog_mpquickgo2, 11);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10cb2c
/*  f10cb2c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10cb30:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10cb34:	3c028006 */ 	lui	$v0,%hi(var80062940)
/*  f10cb38:	3c018007 */ 	lui	$at,0x8007
/*  f10cb3c:	24422940 */ 	addiu	$v0,$v0,%lo(var80062940)
/*  f10cb40:	ac201448 */ 	sw	$zero,0x1448($at)
/*  f10cb44:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f10cb48:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10cb4c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10cb50:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f10cb54:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f10cb58:	11e0000e */ 	beqz	$t7,.L0f10cb94
/*  f10cb5c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f10cb60:	3c188008 */ 	lui	$t8,0x8008
/*  f10cb64:	8f187260 */ 	lw	$t8,0x7260($t8)
/*  f10cb68:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10cb6c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10cb70:	1700001d */ 	bnez	$t8,.L0f10cbe8
/*  f10cb74:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f10cb78:	3c048007 */ 	lui	$a0,%hi(g_4MbMainMenu)
/*  f10cb7c:	ac590490 */ 	sw	$t9,0x490($v0)
/*  f10cb80:	24845294 */ 	addiu	$a0,$a0,%lo(g_4MbMainMenu)
/*  f10cb84:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10cb88:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f10cb8c:	10000017 */ 	beqz	$zero,.L0f10cbec
/*  f10cb90:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f10cb94:
/*  f10cb94:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f10cb98:	a0480000 */ 	sb	$t0,0x0($v0)
/*  f10cb9c:	00008025 */ 	or	$s0,$zero,$zero
/*  f10cba0:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f10cba4:	02002025 */ 	or	$a0,$s0,$zero
.L0f10cba8:
/*  f10cba8:	0fc62003 */ 	jal	func0f18800c
/*  f10cbac:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10cbb0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10cbb4:	5611fffc */ 	bnel	$s0,$s1,.L0f10cba8
/*  f10cbb8:	02002025 */ 	or	$a0,$s0,$zero
/*  f10cbbc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10cbc0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10cbc4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f10cbc8:	ac400294 */ 	sw	$zero,0x294($v0)
/*  f10cbcc:	ac430298 */ 	sw	$v1,0x298($v0)
/*  f10cbd0:	0fc66bf7 */ 	jal	func0f19afdc
/*  f10cbd4:	ac43029c */ 	sw	$v1,0x29c($v0)
/*  f10cbd8:	3c048007 */ 	lui	$a0,%hi(menudialog_fileselect2)
/*  f10cbdc:	24844f34 */ 	addiu	$a0,$a0,%lo(menudialog_fileselect2)
/*  f10cbe0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10cbe4:	2405000a */ 	addiu	$a1,$zero,0xa
.L0f10cbe8:
/*  f10cbe8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f10cbec:
/*  f10cbec:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f10cbf0:	3c018007 */ 	lui	$at,0x8007
/*  f10cbf4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f10cbf8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f10cbfc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10cc00:	03e00008 */ 	jr	$ra
/*  f10cc04:	ac291448 */ 	sw	$t1,0x1448($at)
);

GLOBAL_ASM(
glabel menudialog0010cc08
/*  f10cc08:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10cc0c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10cc10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10cc14:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f10cc18:	14810007 */ 	bne	$a0,$at,.L0f10cc38
/*  f10cc1c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f10cc20:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10cc24:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10cc28:	a0400494 */ 	sb	$zero,0x494($v0)
/*  f10cc2c:	a0400495 */ 	sb	$zero,0x495($v0)
/*  f10cc30:	a0400496 */ 	sb	$zero,0x496($v0)
/*  f10cc34:	a0400497 */ 	sb	$zero,0x497($v0)
.L0f10cc38:
/*  f10cc38:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10cc3c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10cc40:	3c03800a */ 	lui	$v1,0x800a
/*  f10cc44:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10cc48:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10cc4c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10cc50:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10cc54:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10cc58:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10cc5c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10cc60:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10cc64:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f10cc68:	8c63e4f8 */ 	lw	$v1,-0x1b08($v1)
/*  f10cc6c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10cc70:	50600010 */ 	beqzl	$v1,.L0f10ccb4
/*  f10cc74:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10cc78:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f10cc7c:	3c188007 */ 	lui	$t8,%hi(g_4MbMainMenu)
/*  f10cc80:	27185294 */ 	addiu	$t8,$t8,%lo(g_4MbMainMenu)
/*  f10cc84:	1719000a */ 	bne	$t8,$t9,.L0f10ccb0
/*  f10cc88:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10cc8c:	14810008 */ 	bne	$a0,$at,.L0f10ccb0
/*  f10cc90:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f10cc94:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f10cc98:	ac480490 */ 	sw	$t0,0x490($v0)
/*  f10cc9c:	ac4904b0 */ 	sw	$t1,0x4b0($v0)
/*  f10cca0:	0fc6709a */ 	jal	func0f19c268
/*  f10cca4:	ac40049c */ 	sw	$zero,0x49c($v0)
/*  f10cca8:	0fc67088 */ 	jal	func0f19c220
/*  f10ccac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10ccb0:
/*  f10ccb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10ccb4:
/*  f10ccb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10ccb8:	00001025 */ 	or	$v0,$zero,$zero
/*  f10ccbc:	03e00008 */ 	jr	$ra
/*  f10ccc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ccc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ccc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cccc:	00000000 */ 	sll	$zero,$zero,0x0
);
