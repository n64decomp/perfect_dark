#define spawn(pad) \
	0x00, \
	pad, \
	0,

#define intro_weapon(weapon, u1) \
	0x01, \
	weapon, \
	u1, \
	0,

#define ammo(ammotype, value) \
	0x02, \
	ammotype, \
	value, \
	0,

#define outfit(outfit) \
	0x05, \
	outfit,

#define case(id, pad) \
	0x09, \
	id, \
	pad,

#define case_respawn(id, pad) \
	0x0a, \
	id, \
	pad,

#define hill(pad) \
	0x0b, \
	pad,

#define endintro \
	0x0c,
