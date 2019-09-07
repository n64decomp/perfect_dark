#include "ultra64.h"
#include "constants.h"
#include "commands.h"
#include "intro.h"
#include "props.h"

struct ailists {
	u8 *list;
	u32 id;
};

struct aipaths {
	s32 *pads;
	u8 id;
	u8 type;
};
