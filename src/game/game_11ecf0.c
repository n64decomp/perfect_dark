#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_11ecf0.h"
#include "gvars/gvars.h"
#include "types.h"

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
/*  f11edc8:	3c028007 */ 	lui	$v0,%hi(var80075d70)
/*  f11edcc:	03e00008 */ 	jr	$ra
/*  f11edd0:	8c425d70 */ 	lw	$v0,%lo(var80075d70)($v0)
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
/*  f11ee08:	3c028007 */ 	lui	$v0,%hi(var80075d74)
/*  f11ee0c:	03e00008 */ 	jr	$ra
/*  f11ee10:	8c425d74 */ 	lw	$v0,%lo(var80075d74)($v0)
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
