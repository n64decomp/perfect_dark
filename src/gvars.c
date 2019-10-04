#include "ultra64.h"
#include "src/include/gvars.h"

/**
 * This is a workaround for me not being to figure out why ld is ignoring the
 * memory address location in game.ld. It puts gvars immediately after setup,
 * which means it comes 0xf1a0 earlier than it should. So we pad it out here.
 */
u8 padding[0xf1a0];

struct g_vars g_Vars;
