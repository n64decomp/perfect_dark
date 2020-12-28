#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096890.h"
#include "gvars/gvars.h"
#include "types.h"

s32 func0f096890(s32 arg0)
{
	u16 *array;
	s32 shiftamount;
	s32 mask;
	s32 index;
	s32 value;
	s32 nextvalue;

	if (arg0 >= 32736) {
		mask = 0x07;
		shiftamount = 3;
		array = var8006af8c;
		arg0 -= 32736;
	} else if (arg0 >= 30720) {
		mask = 0x1f;
		shiftamount = 5;
		array = var8006af0c;
		arg0 -= 30720;
	} else {
		mask = 0x1ff;
		shiftamount = 9;
		array = var8006ae90;
	}

	index = arg0 >> shiftamount;
	value = array[index];
	nextvalue = array[index + 1];

	return value - (((value - nextvalue) * (arg0 & mask)) >> shiftamount);
}

u16 func0f096910(s16 arg0)
{
	s32 value = arg0 >= 0 ? arg0 : -arg0;

	value = func0f096890(value);

	if (arg0 < 0) {
		value = 0xffff - value;
	}

	return value;
}

s16 func0f096964(s16 arg0)
{
	s32 value = arg0 >= 0 ? arg0 : -arg0;

	value = func0f096890(value);

	if (arg0 >= 0) {
		value = 0x7fff - value;
	} else {
		value -= 0x8000;
	}

	return value;
}
