#define gunscript_end \
	0, \
	0,

#define gunscript_showpart(keyframe, part) \
	0x01000000 | keyframe, \
	part,

#define gunscript_hidepart(keyframe, part) \
	0x02000000 | keyframe, \
	part,

#define gunscript_waitforzreleased(keyframe) \
	0x03000000 | keyframe, \
	0,

#define gunscript_waittime(keyframe, time) \
	0x04000000 | keyframe, \
	time,

#define gunscript_playsound(keyframe, sound) \
	0x05000000 | keyframe, \
	sound,

#define gunscript_include(unk1, address) \
	0x06000000 | (unk1 << 16), \
	(u32)address,

#define gunscript_random(probability, address) \
	0x07000000 | probability, \
	(u32)address,

#define gunscript_repeatuntilfull(triggerkey, dontloop, gototrigger) \
	0x08000000 | triggerkey, \
	(dontloop << 16) | gototrigger,

#define gunscript_popoutsackofpills(unk1) \
	0x09000000 | unk1, \
	0,

#define gunscript_playanimation(animation, direction, speed) \
	0x0a000000 | animation, \
	(direction << 16) | speed,

#define gunscript_setsoundspeed(keyframe, speed) \
	0x0b000000 | keyframe, \
	speed,

