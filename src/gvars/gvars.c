#include <ultra64.h>
#include "gvars/gvars.h"

/**
 * This is a workaround for me not being to figure out why ld is ignoring the
 * memory address location in game.ld. It puts gvars immediately after setup,
 * which means it comes 0xf1a0 earlier than it should. So we pad it out here.
 */
u8 padding[0xf1a0];

// 80099fc0
struct g_vars g_Vars;

// 8009d0c4
s32 g_NumTags;

// 8009d0c8
struct tag **g_TagPtrs;

// 8009d0d0
u8 padding2[0x5144];

// 800a2214
u32 g_EepromFlags;
