#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_11ecf0.h"
#include "gvars/gvars.h"
#include "types.h"

const u32 var7f1b4fe0[] = {0x38d1b717};
const u32 var7f1b4fe4[] = {0x3c23d70a};
const u32 var7f1b4fe8[] = {0x48927c00};
const u32 var7f1b4fec[] = {0x38d1b717};
const u32 var7f1b4ff0[] = {0xbc23d70a};
const u32 var7f1b4ff4[] = {0x48927c00};
const u32 var7f1b4ff8[] = {0x3b808081};
const u32 var7f1b4ffc[] = {0x3b808081};
const u32 var7f1b5000[] = {0x3dcccccd};
const u32 var7f1b5004[] = {0x7f120024};
const u32 var7f1b5008[] = {0x7f1208a8};
const u32 var7f1b500c[] = {0x7f1209f8};
const u32 var7f1b5010[] = {0x7f120130};
const u32 var7f1b5014[] = {0x7f120b48};
const u32 var7f1b5018[] = {0x7f12045c};
const u32 var7f1b501c[] = {0x7f120de8};
const u32 var7f1b5020[] = {0x7f1207d8};
const u32 var7f1b5024[] = {0x7f120c98};
const u32 var7f1b5028[] = {0x7f120de8};
const u32 var7f1b502c[] = {0x7f120350};
const u32 var7f1b5030[] = {0x7f120708};
const u32 var7f1b5034[] = {0x7f12023c};
const u32 var7f1b5038[] = {0x7f120638};
const u32 var7f1b503c[] = {0x7f120568};
const u32 var7f1b5040[] = {0x7f120014};
const u32 var7f1b5044[] = {0x3d088889};
const u32 var7f1b5048[] = {0x3d088889};
const u32 var7f1b504c[] = {0x3d088889};
const u32 var7f1b5050[] = {0x3d088889};
const u32 var7f1b5054[] = {0x3d088889};
const u32 var7f1b5058[] = {0x3d088889};
const u32 var7f1b505c[] = {0x3d088889};
const u32 var7f1b5060[] = {0x3d088889};
const u32 var7f1b5064[] = {0x3d088889};
const u32 var7f1b5068[] = {0x3d088889};
const u32 var7f1b506c[] = {0x3d088889};
const u32 var7f1b5070[] = {0x3d088889};
const u32 var7f1b5074[] = {0x3d088889};
const u32 var7f1b5078[] = {0x3d088889};
const u32 var7f1b507c[] = {0x477fff00};
const u32 var7f1b5080[] = {0x449fe000};
const u32 var7f1b5084[] = {0x446fc000};
const u32 var7f1b5088[] = {0x7f12136c};
const u32 var7f1b508c[] = {0x7f121994};
const u32 var7f1b5090[] = {0x7f121a84};
const u32 var7f1b5094[] = {0x7f1215ec};
const u32 var7f1b5098[] = {0x7f121b74};
const u32 var7f1b509c[] = {0x7f121724};
const u32 var7f1b50a0[] = {0x7f122378};
const u32 var7f1b50a4[] = {0x7f1221f0};
const u32 var7f1b50a8[] = {0x7f121c64};
const u32 var7f1b50ac[] = {0x7f122378};
const u32 var7f1b50b0[] = {0x7f12185c};
const u32 var7f1b50b4[] = {0x7f122068};
const u32 var7f1b50b8[] = {0x7f1214b0};
const u32 var7f1b50bc[] = {0x7f121edc};
const u32 var7f1b50c0[] = {0x7f121d54};
const u32 var7f1b50c4[] = {0x7f121374};
const u32 var7f1b50c8[] = {0x477fff00};
const u32 var7f1b50cc[] = {0x46fffe00};
const u32 var7f1b50d0[] = {0x46fffe00};
const u32 var7f1b50d4[] = {0x43ff8000};
const u32 var7f1b50d8[] = {0xc57fa000};
const u32 var7f1b50dc[] = {0xc57fa000};
const u32 var7f1b50e0[] = {0xc4eac000};
const u32 var7f1b50e4[] = {0xc4eac000};
const u32 var7f1b50e8[] = {0xc4eac000};
const u32 var7f1b50ec[] = {0x46fffe00};
const u32 var7f1b50f0[] = {0xc4eac000};
const u32 var7f1b50f4[] = {0xc4eac000};
const u32 var7f1b50f8[] = {0xc4eac000};
const u32 var7f1b50fc[] = {0xc4eac000};
const u32 var7f1b5100[] = {0x44eaa000};
const u32 var7f1b5104[] = {0x46fffe00};
const u32 var7f1b5108[] = {0x3d888889};
const u32 var7f1b510c[] = {0x3c23d70a};
const u32 var7f1b5110[] = {0x3bb60b61};
const u32 var7f1b5114[] = {0x3d088889};
const u32 var7f1b5118[] = {0x3c4ccccd};
const u32 var7f1b511c[] = {0x3dcccccd};
const u32 var7f1b5120[] = {0x40c907a9};
const u32 var7f1b5124[] = {0x3ea8f5c3};
const u32 var7f1b5128[] = {0x3f28f5c3};
const u32 var7f1b512c[] = {0x3ea8f5c3};
const u32 var7f1b5130[] = {0x3fa66666};
const u32 var7f1b5134[] = {0x3fd9999a};
const u32 var7f1b5138[] = {0x40490fdb};
const u32 var7f1b513c[] = {0x3fa0d2ee};
const u32 var7f1b5140[] = {0x3eaaaaab};
const u32 var7f1b5144[] = {0x00000000};
const u32 var7f1b5148[] = {0x00000000};
const u32 var7f1b514c[] = {0x00000000};
const u32 var7f1b5150[] = {0xc3653838};
const u32 var7f1b5154[] = {0x4164924b};
const u32 var7f1b5158[] = {0x3f6e147b};
const u32 var7f1b515c[] = {0x3f666666};
const u32 var7f1b5160[] = {0xc0490fdb};
const u32 var7f1b5164[] = {0x3faaaaab};
const u32 var7f1b5168[] = {0x7f128b54};
const u32 var7f1b516c[] = {0x7f128b54};
const u32 var7f1b5170[] = {0x7f128b5c};
const u32 var7f1b5174[] = {0x7f128b8c};
const u32 var7f1b5178[] = {0x7f128b94};
const u32 var7f1b517c[] = {0x7f128b64};
const u32 var7f1b5180[] = {0x7f128b6c};
const u32 var7f1b5184[] = {0x7f128b84};
const u32 var7f1b5188[] = {0x7f128b74};
const u32 var7f1b518c[] = {0x7f128b7c};
const u32 var7f1b5190[] = {0x7f128b9c};
const u32 var7f1b5194[] = {0x7f128bc4};
const u32 var7f1b5198[] = {0x7f128bcc};
const u32 var7f1b519c[] = {0x7f128bd4};
const u32 var7f1b51a0[] = {0x7f128bdc};
const u32 var7f1b51a4[] = {0x7f128bac};
const u32 var7f1b51a8[] = {0x7f128bbc};
const u32 var7f1b51ac[] = {0x7f128ba4};
const u32 var7f1b51b0[] = {0x7f128bb4};
const u32 var7f1b51b4[] = {0x7f128be4};
const u32 var7f1b51b8[] = {0x7f128bec};
const u32 var7f1b51bc[] = {0x7f128c14};
const u32 var7f1b51c0[] = {0x7f128c0c};
const u32 var7f1b51c4[] = {0x7f128bfc};
const u32 var7f1b51c8[] = {0x7f128bf4};
const u32 var7f1b51cc[] = {0x7f128c04};
const u32 var7f1b51d0[] = {0x7f128c2c};
const u32 var7f1b51d4[] = {0x7f128c1c};
const u32 var7f1b51d8[] = {0x7f128c34};
const u32 var7f1b51dc[] = {0x7f128c24};
const u32 var7f1b51e0[] = {0x7f128c4c};
const u32 var7f1b51e4[] = {0x7f128c44};
const u32 var7f1b51e8[] = {0x7f128c64};
const u32 var7f1b51ec[] = {0x7f128c5c};
const u32 var7f1b51f0[] = {0x7f128c54};
const u32 var7f1b51f4[] = {0x7f128cbc};
const u32 var7f1b51f8[] = {0x7f128c7c};
const u32 var7f1b51fc[] = {0x7f128c84};
const u32 var7f1b5200[] = {0x7f128c8c};
const u32 var7f1b5204[] = {0x7f128c94};
const u32 var7f1b5208[] = {0x7f128c9c};
const u32 var7f1b520c[] = {0x7f128ca4};
const u32 var7f1b5210[] = {0x7f128cac};
const u32 var7f1b5214[] = {0x7f128cb4};
const u32 var7f1b5218[] = {0x7f128c3c};
const u32 var7f1b521c[] = {0x7f128cd4};
const u32 var7f1b5220[] = {0x7f128cd4};
const u32 var7f1b5224[] = {0x7f128cd4};
const u32 var7f1b5228[] = {0x7f128cd4};
const u32 var7f1b522c[] = {0x7f128c74};

const char var7f1b5230[] = "VTXSTORE : vtxfixrefs -> Start - p1=%x, p2=%x\n";
const char var7f1b5260[] = "vtxfixrefs : Part=%x -- Mapping ptr %x -> %x\n";
const char var7f1b5290[] = "VTXSTORE : vtxfixrefs -> End - Done=%d\n";
const char var7f1b52b8[] = "vtxstorecheck : memaFree -> %u bytes at Ptr=%x(%x)\n";
const char var7f1b52ec[] = "vtxstorecheck : At block 1 %d -> Ref1=%x, Ref2=%x\n";
const char var7f1b5320[] = "vtxstorecheck : At block 2 %d -> Ref1=%x, Ref2=%x\n";
const char var7f1b5354[] = "vtx buffer low, need to delete objects\n";
const char var7f1b537c[] = "getfreevertices : %d of type %d -> ref1=%x, ref2=%x\n";
const char var7f1b53b4[] = "vtxstore: 1st mema alloc of %u bytes\n";
const char var7f1b53dc[] = "getfreevertices : Return ptr = %x\n";
const char var7f1b5400[] = "vtxstore: Out of mema (returning NULL)\n";
const char var7f1b5428[] = "vtxstore: GROSS! CorspeCount > MAX_CORPSES corpses! Freeing corpse %x\n";
const char var7f1b5470[] = "vtxstore:  CorpseCount %d, Trying to free %d\n";
const char var7f1b54a0[] = "vtxstore: Freeing corpse %x\n";
const char var7f1b54c0[] = "vtxstore: Out of vertices type %d wanted %d free %d (returning NULL)\n";
const char var7f1b5508[] = "vtxstore: freevertices type %d, list %x\n";
const char var7f1b5534[] = "freevertices: address not found in array %x\n";
const char var7f1b5564[] = "";
const char var7f1b5568[] = "";
const char var7f1b556c[] = "";

GLOBAL_ASM(
glabel func0f11ecf0
/*  f11ecf0:	03e00008 */ 	jr	$ra
/*  f11ecf4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11ecf8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11ecfc:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f11ed00:	03e00008 */ 	jr	$ra
/*  f11ed04:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f11ed08:	03e00008 */ 	jr	$ra
/*  f11ed0c:	00801025 */ 	or	$v0,$a0,$zero
/*  f11ed10:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11ed14:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f11ed18:	03e00008 */ 	jr	$ra
/*  f11ed1c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f11ed20:	03e00008 */ 	jr	$ra
/*  f11ed24:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ed28:	03e00008 */ 	jr	$ra
/*  f11ed2c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11ed30:	03e00008 */ 	jr	$ra
/*  f11ed34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ed38:	03e00008 */ 	jr	$ra
/*  f11ed3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ed40:	03e00008 */ 	jr	$ra
/*  f11ed44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ed48:	03e00008 */ 	jr	$ra
/*  f11ed4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ed50:	03e00008 */ 	jr	$ra
/*  f11ed54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ed58:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11ed5c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f11ed60:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f11ed64:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f11ed68:	03e00008 */ 	jr	$ra
/*  f11ed6c:	00001025 */ 	or	$v0,$zero,$zero
);

bool func0f11ed70(void)
{
	return false;
}

bool func0f11ed78(void)
{
	return true;
}

GLOBAL_ASM(
glabel func0f11ed80
/*  f11ed80:	03e00008 */ 	jr	$ra
/*  f11ed84:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11ed88:	03e00008 */ 	jr	$ra
/*  f11ed8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ed90:	03e00008 */ 	jr	$ra
/*  f11ed94:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ed98:	03e00008 */ 	jr	$ra
/*  f11ed9c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11eda0:	03e00008 */ 	jr	$ra
/*  f11eda4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eda8:	03e00008 */ 	jr	$ra
/*  f11edac:	00001025 */ 	or	$v0,$zero,$zero
);

bool func0f11edb0(void)
{
	return false;
}

bool func0f11edb8(void)
{
	return false;
}

GLOBAL_ASM(
glabel func0f11edc0
/*  f11edc0:	03e00008 */ 	jr	$ra
/*  f11edc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11edc8:	3c028007 */ 	lui	$v0,0x8007
/*  f11edcc:	03e00008 */ 	jr	$ra
/*  f11edd0:	8c425d70 */ 	lw	$v0,0x5d70($v0)
/*  f11edd4:	3c018007 */ 	lui	$at,0x8007
/*  f11edd8:	03e00008 */ 	jr	$ra
/*  f11eddc:	ac245d70 */ 	sw	$a0,0x5d70($at)
/*  f11ede0:	03e00008 */ 	jr	$ra
/*  f11ede4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ede8:	03e00008 */ 	jr	$ra
/*  f11edec:	00001025 */ 	or	$v0,$zero,$zero
/*  f11edf0:	03e00008 */ 	jr	$ra
/*  f11edf4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11edf8:	03e00008 */ 	jr	$ra
/*  f11edfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ee00:	03e00008 */ 	jr	$ra
/*  f11ee04:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11ee08
/*  f11ee08:	3c028007 */ 	lui	$v0,0x8007
/*  f11ee0c:	03e00008 */ 	jr	$ra
/*  f11ee10:	8c425d74 */ 	lw	$v0,0x5d74($v0)
/*  f11ee14:	3c018007 */ 	lui	$at,0x8007
/*  f11ee18:	03e00008 */ 	jr	$ra
/*  f11ee1c:	ac245d74 */ 	sw	$a0,0x5d74($at)
);

bool func0f11ee20(void)
{
	return false;
}

GLOBAL_ASM(
glabel func0f11ee28
/*  f11ee28:	03e00008 */ 	jr	$ra
/*  f11ee2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee30:	03e00008 */ 	jr	$ra
/*  f11ee34:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee38:	03e00008 */ 	jr	$ra
/*  f11ee3c:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f11ee40
/*  f11ee40:	03e00008 */ 	jr	$ra
/*  f11ee44:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee48:	03e00008 */ 	jr	$ra
/*  f11ee4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee50:	03e00008 */ 	jr	$ra
/*  f11ee54:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee58:	03e00008 */ 	jr	$ra
/*  f11ee5c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee60:	03e00008 */ 	jr	$ra
/*  f11ee64:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee68:	03e00008 */ 	jr	$ra
/*  f11ee6c:	00001025 */ 	or	$v0,$zero,$zero
);

u32 debugGetSlowMotion(void)
{
	return SLOWMOTION_OFF;
}

GLOBAL_ASM(
glabel func0f11ee78
/*  f11ee78:	03e00008 */ 	jr	$ra
/*  f11ee7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee80:	03e00008 */ 	jr	$ra
/*  f11ee84:	00001025 */ 	or	$v0,$zero,$zero
);

bool func0f11ee88(void)
{
	return false;
}

GLOBAL_ASM(
glabel func0f11ee90
/*  f11ee90:	03e00008 */ 	jr	$ra
/*  f11ee94:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ee98:	03e00008 */ 	jr	$ra
/*  f11ee9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eea0:	03e00008 */ 	jr	$ra
/*  f11eea4:	00001025 */ 	or	$v0,$zero,$zero
);

bool func0f11eea8(void)
{
	return false;
}

GLOBAL_ASM(
glabel func0f11eeb0
/*  f11eeb0:	03e00008 */ 	jr	$ra
/*  f11eeb4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eeb8:	03e00008 */ 	jr	$ra
/*  f11eebc:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eec0:	03e00008 */ 	jr	$ra
/*  f11eec4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eec8:	03e00008 */ 	jr	$ra
/*  f11eecc:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eed0:	03e00008 */ 	jr	$ra
/*  f11eed4:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f11eed8
/*  f11eed8:	03e00008 */ 	jr	$ra
/*  f11eedc:	00001025 */ 	or	$v0,$zero,$zero
/*  f11eee0:	03e00008 */ 	jr	$ra
/*  f11eee4:	00001025 */ 	or	$v0,$zero,$zero
);

u32 dprint()
{
	return 0;
}

bool func0f11eef0(void)
{
	return false;
}

GLOBAL_ASM(
glabel func0f11eef8
/*  f11eef8:	03e00008 */ 	jr	$ra
/*  f11eefc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11ef00:	03e00008 */ 	jr	$ra
/*  f11ef04:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef08:	03e00008 */ 	jr	$ra
/*  f11ef0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef10:	03e00008 */ 	jr	$ra
/*  f11ef14:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef18:	03e00008 */ 	jr	$ra
/*  f11ef1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef20:	03e00008 */ 	jr	$ra
/*  f11ef24:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef28:	03e00008 */ 	jr	$ra
/*  f11ef2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef30:	03e00008 */ 	jr	$ra
/*  f11ef34:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef38:	03e00008 */ 	jr	$ra
/*  f11ef3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef40:	03e00008 */ 	jr	$ra
/*  f11ef44:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f11ef48
/*  f11ef48:	03e00008 */ 	jr	$ra
/*  f11ef4c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11ef50:	03e00008 */ 	jr	$ra
/*  f11ef54:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef58:	03e00008 */ 	jr	$ra
/*  f11ef5c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef60:	03e00008 */ 	jr	$ra
/*  f11ef64:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef68:	03e00008 */ 	jr	$ra
/*  f11ef6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef70:	03e00008 */ 	jr	$ra
/*  f11ef74:	00001025 */ 	or	$v0,$zero,$zero
);

bool func0f11ef78(void)
{
	return false;
}

GLOBAL_ASM(
glabel func0f11ef80
/*  f11ef80:	03e00008 */ 	jr	$ra
/*  f11ef84:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef88:	03e00008 */ 	jr	$ra
/*  f11ef8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef90:	03e00008 */ 	jr	$ra
/*  f11ef94:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ef98:	03e00008 */ 	jr	$ra
/*  f11ef9c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11efa0:	03e00008 */ 	jr	$ra
/*  f11efa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11efa8:	03e00008 */ 	jr	$ra
/*  f11efac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11efb0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11efb4:	03e00008 */ 	jr	$ra
/*  f11efb8:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f11efbc:	03e00008 */ 	jr	$ra
/*  f11efc0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11efc4:	03e00008 */ 	jr	$ra
/*  f11efc8:	00801025 */ 	or	$v0,$a0,$zero
/*  f11efcc:	03e00008 */ 	jr	$ra
/*  f11efd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11efd4:	03e00008 */ 	jr	$ra
/*  f11efd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11efdc:	03e00008 */ 	jr	$ra
/*  f11efe0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11efe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11efe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11efec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11eff0:	03e00008 */ 	jr	$ra
/*  f11eff4:	00801025 */ 	or	$v0,$a0,$zero
/*  f11eff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11effc:	00000000 */ 	sll	$zero,$zero,0x0
);
