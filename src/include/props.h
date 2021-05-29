#define _mkshort(a, b) (((a) << 8) | ((b) & 0xff))
#define _mkword(a, b) (((a) << 16) | ((b) & 0xffff))

#define _generic_object(type, scale, model, pad, flags, flags2, flags3, maxdamage) \
	_mkword(scale, type), _mkword(model, pad), flags, flags2, flags3, \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, maxdamage, 0, 0, 0x0fff0000

#define door(scale, model, pad, flags, flags2, flags3, maxdamage, maxfrac, perimfrac, accel, decel, maxspeed, doorflags, doortype, keyflags, autoclosetime, unk88, sibling, unkc4) \
	_generic_object(0x01, scale, model, pad, flags, flags2, flags3, maxdamage), \
	maxfrac, perimfrac, accel, decel, maxspeed, _mkword(doorflags, doortype), \
	keyflags, autoclosetime, 0, 0, 0, unk88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
	sibling, 0, unkc4, 0, 0xff000000, 0, 0, 0,

#define door_scale(scale) \
	0x02, scale,

#define stdobject(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x03, scale, model, pad, flags, flags2, flags3, maxdamage),

#define key(scale, model, pad, flags, flags2, flags3, lockbits) \
	_generic_object(0x04, scale, model, pad, flags, flags2, flags3, 1000), \
	lockbits,

#define camera(scale, model, pad, flags, flags2, flags3, maxdamage, targetpad, yaw, ymaxspeed, maxdist) \
	_generic_object(0x06, scale, model, pad, flags, flags2, flags3, maxdamage), \
	_mkword(targetpad, 0), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, yaw, 0, 0, ymaxspeed, 0, maxdist, 0,

#define ammocrate(scale, model, pad, flags, flags2, flags3, maxdamage, ammotype) \
	_generic_object(0x07, scale, model, pad, flags, flags2, flags3, maxdamage), \
	ammotype,

#define weapon(scale, model, chr, flags, flags2, flags3, weapon) \
	_generic_object(0x08, scale, model, chr, flags, flags2, flags3, 1000), \
	_mkword(_mkshort(weapon, 0), 0), 0x00ffffff, 0,

#define chr(spawnflags, chrnum, pad, body, head, function, padpreset, chrpreset, hear_scale, view_dist, flags, flags2, team, squadron, chair, convtalk, tude, naturalanim, yvisang, teamscandist) \
	0x09, \
	spawnflags, \
	_mkword(chrnum, pad), \
	_mkword(_mkshort(body, head), function), \
	_mkword(padpreset, chrpreset), \
	_mkword(hear_scale, view_dist), \
	flags, \
	flags2, \
	_mkword(_mkshort(team, squadron), chair), \
	convtalk, \
	_mkword(_mkshort(tude, naturalanim), _mkshort(yvisang, teamscandist)),

#define singlemonitor(scale, model, pad, flags, flags2, flags3, maxdamage, image) \
	_generic_object(0x0a, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
	_mkword(0xffff, _mkshort(0xff, image)),

#define multimonitor(scale, model, pad, flags, flags2, flags3, maxdamage, image1, image2, image3, image4) \
	_generic_object(0x0b, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
	_mkword(_mkshort(image1, image2), _mkshort(image3, image4)),

#define autogun(scale, model, pad, flags, flags2, flags3, maxdamage, targetpad, unk64, unk68, unk80, unk84) \
	_generic_object(0x0d, scale, model, pad, flags, flags2, flags3, maxdamage), \
	_mkword(targetpad, 0), 0, unk64, unk68, 0, 0, 0, 0, 0, unk80, unk84, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/**
 * Link two guns together, which allows them to be dual wielded once both have
 * been collected.
 */
#define link_guns(gun1offset, gun2offset) \
	0x0e, _mkword(gun1offset, gun2offset),

#define debris(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x0f, scale, model, pad, flags, flags2, flags3, maxdamage),

#define hat(scale, model, chr, flags, flags2, flags3, maxdamage) \
	_generic_object(0x11, scale, model, chr, flags, flags2, flags3, maxdamage),

#define lift_door(dooroffset, liftoffset, stopnum) \
	0x13, dooroffset, liftoffset, 0, stopnum,

#define ammocratemulti(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x14, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0xffff0000, 0xffff0000, 0xffff0000, 0xffff0000, \
	0xffff0000, 0xffff0000, 0xffff0000, 0xffff0000, \
	0xffff0000, 0xffff0000, 0xffff0000, 0xffff0000, \
	0xffff0000, 0xffff0000, 0xffff0000, 0xffff0000, \
	0xffff0000, 0xffff0000, 0xffff0000,

#define shield(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x15, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0x00010000, 0, 0,

#define tag(id, value) \
	0x16, _mkword(id, value), 0, 0,

#define beginobjective(value, text, diffbit) \
	0x17, value, text, diffbit,

#define endobjective \
	0x18,

#define require_object_destroyed(object) \
	0x19, object,

#define complete_flags(stageflag) \
	0x1a, stageflag,

#define fail_flags(stageflag) \
	0x1b, stageflag,

#define require_object_collected(object) \
	0x1c, object,

#define require_object_thrown(object) \
	0x1d, object,

#define require_object_holographed(object) \
	0x1e, object, 0, 0,

#define require_room_entered(room) \
	0x20, room,

#define require_object_thrown_on_target(throw_object, target_object) \
	0x21, throw_object, target_object, 0,

#define briefing(value, text) \
	0x23, value, text, 0,

#define gasbottle(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x24, scale, model, pad, flags, flags2, flags3, maxdamage),

#define rename_object(objoffset, weapon, text, text2, text3, text4, text5) \
	0x25, objoffset, weapon, text, text2, text3, text4, text5, 0, 0,

#define padlocked_door(dooroffset, lockoffset) \
	0x26, door, lock, 0,

#define glass(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x2a, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0,

#define safe(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x2b, scale, model, pad, flags, flags2, flags3, maxdamage),

#define safeitem(item, safe, door) \
	0x2c, item, safe, door,

#define camera2(scale, u1, u2, u3, u4, u5, u6) \
	_mkword(scale, 0x2e), u1, u2, u3, u4, u5, u6,

#define tinted_glass(scale, model, pad, flags, flags2, flags3, maxdamage, unk5c) \
	_generic_object(0x2f, scale, model, pad, flags, flags2, flags3, maxdamage), \
	unk5c, 0xffff, 0,

#define lift(scale, model, pad, flags, flags2, flags3, maxdamage, pad1, pad2, pad3, pad4, door1, door2, door3, door4, accel, maxspeed, unk84) \
	_generic_object(0x30, scale, model, pad, flags, flags2, flags3, maxdamage), \
	_mkword(pad1, pad2), _mkword(pad3, pad4), \
	door1, door2, door3, door4, \
	0, 0, accel, maxspeed, unk84, 0, 0, 0,

/**
 * Link some scenery objects together so they can be toggled as a group.
 *
 * The three arguments are all offsets to other objects.
 *
 * trigger - is the offset to the destructible object.
 * unexp - will be visible when trigger is healthy.
 * exp - will be visible when trigger is destroyed.
 *
 * Both unexp and exp are optional. Use 0 to disable.
 *
 * Note that the trigger itself can disappear when destroyed, so unexp works as
 * an additional object which should be hidden.
 */
#define conditional_scenery(trigger, unexp, exp) \
	0x31, trigger, unexp, exp, 0,

/**
 * Define two waypoints which start off unlinked and become linked once an
 * object is destroyed. It's used to activate a path through exploded walls in
 * Rescue and Escape.
 */
#define blocked_path(objoffset, waypoint1, waypoint2) \
	0x32, objoffset, _mkword(waypoint1, waypoint2), 0,

#define hoverbike(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x33, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0x01010000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

#define endprops \
	0x34,

#define hover_prop(scale, model, pad, flags, flags2, flags3, maxdamage, unk5c) \
	_generic_object(0x35, scale, model, pad, flags, flags2, flags3, maxdamage), \
	unk5c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

#define fan(scale, model, pad, flags, flags2, flags3, maxdamage, maxspeed, accel, on) \
	_generic_object(0x36, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0, 0, maxspeed, 0, accel, on,

#define hovercar(scale, model, pad, flags, flags2, flags3, maxdamage, unk5c) \
	_generic_object(0x37, scale, model, pad, flags, flags2, flags3, maxdamage), \
	unk5c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

#define pad_effect(effect, pad) \
	0x38, effect, pad,

#define chopper(scale, model, pad, flags, flags2, flags3, maxdamage, ailist) \
	_generic_object(0x39, scale, model, pad, flags, flags2, flags3, maxdamage), \
	ailist, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

#define mine(scale, model, pad, flags, flags2, flags3, maxdamage, weapon) \
	_generic_object(0x3a, scale, model, pad, flags, flags2, flags3, maxdamage), \
	_mkword(_mkshort(weapon, 0), 0), 1, 0,

#define escastep(scale, model, pad, flags, flags2, flags3, maxdamage) \
	_generic_object(0x3b, scale, model, pad, flags, flags2, flags3, maxdamage), \
	0, 0, 0, 0,
