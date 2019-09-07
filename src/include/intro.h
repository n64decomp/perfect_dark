#include "util.h"

#define spawn(pad) \
	mkword(0x00), \
	mkword(pad), \
	mkword(0),

#define intro_weapon(weapon, u1) \
	mkword(0x01), \
	mkword(weapon), \
	mkword(u1), \
	mkword(0),

#define ammo(ammotype, value) \
	mkword(0x02), \
	mkword(ammotype), \
	mkword(value), \
	mkword(0),

#define outfit(outfit) \
	mkword(0x05), \
	mkword(outfit),

#define case(id, pad) \
	mkword(0x09), \
	mkword(id), \
	mkword(pad),

#define case_respawn(id, pad) \
	mkword(0x0a), \
	mkword(id), \
	mkword(pad),

#define hill(room) \
	mkword(0x0b), \
	mkword(room),

#define endintro \
	mkword(0x0c),
