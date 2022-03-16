#include <ultra64.h>
#include "constants.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/chr/chr.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f000090
/*  f000100:	2402ffff */ 	li	$v0,-1
/*  f000104:	3c038006 */ 	lui	$v1,0x8006
/*  f000108:	3c018006 */ 	lui	$at,0x8006
/*  f00010c:	24632398 */ 	addiu	$v1,$v1,0x2398
/*  f000110:	ac222394 */ 	sw	$v0,0x2394($at)
/*  f000114:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f000118:	3c0e8009 */ 	lui	$t6,0x8009
/*  f00011c:	91ce1160 */ 	lbu	$t6,0x1160($t6)
/*  f000120:	24040001 */ 	li	$a0,0x1
/*  f000124:	24050080 */ 	li	$a1,0x80
/*  f000128:	148e0003 */ 	bne	$a0,$t6,.JF0f000138
/*  f00012c:	3c018006 */ 	lui	$at,0x8006
/*  f000130:	240f000a */ 	li	$t7,0xa
/*  f000134:	ac6f0000 */ 	sw	$t7,0x0($v1)
.JF0f000138:
/*  f000138:	ac2023a4 */ 	sw	$zero,0x23a4($at)
/*  f00013c:	3c018006 */ 	lui	$at,0x8006
/*  f000140:	ac2223c4 */ 	sw	$v0,0x23c4($at)
/*  f000144:	3c018006 */ 	lui	$at,0x8006
/*  f000148:	ac2023c0 */ 	sw	$zero,0x23c0($at)
/*  f00014c:	3c018006 */ 	lui	$at,0x8006
/*  f000150:	ac2423c8 */ 	sw	$a0,0x23c8($at)
/*  f000154:	3c018006 */ 	lui	$at,0x8006
/*  f000158:	ac2023cc */ 	sw	$zero,0x23cc($at)
/*  f00015c:	3c018006 */ 	lui	$at,0x8006
/*  f000160:	ac2023d0 */ 	sw	$zero,0x23d0($at)
/*  f000164:	3c03800a */ 	lui	$v1,0x800a
/*  f000168:	3c018006 */ 	lui	$at,0x8006
/*  f00016c:	2463e6e8 */ 	addiu	$v1,$v1,-6424
/*  f000170:	ac2423d4 */ 	sw	$a0,0x23d4($at)
/*  f000174:	a0600004 */ 	sb	$zero,0x4($v1)
/*  f000178:	a0650005 */ 	sb	$a1,0x5($v1)
/*  f00017c:	a0650006 */ 	sb	$a1,0x6($v1)
/*  f000180:	03e00008 */ 	jr	$ra
/*  f000184:	a0650007 */ 	sb	$a1,0x7($v1)
);
#else
void func0f000090(void)
{
	g_TitleMode = -1;
	g_TitleNextMode = TITLEMODE_LEGAL;
	g_TitleTimer = 0;
	g_TitleNextStage = -1;
	var800624e0 = 0;
	var800624e8 = 1;
	var800624ec = 0;
	var800624f0 = 0;
	var800624f4 = 1;
	g_MissionConfig.pdmodereaction = 0;
	g_MissionConfig.pdmodehealth = 128;
	g_MissionConfig.pdmodedamage = 128;
	g_MissionConfig.pdmodeaccuracy = 128;
}
#endif
