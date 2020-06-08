#define _mkshort(a, b) ((a << 8) | (b & 0xff))
#define _mkword(a, b) ((a << 16) | (b & 0xffff))

#define _generic_object(id, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19) \
	_mkword(scale, id), \
	_mkword(model, pad), \
	props1, \
	props2, \
	u1, u2, u3, u4, \
	u5, u6, u7, u8, \
	u9, u10, u11, u12, \
	u13, u14, u15, u16, \
	u17, u18, u19

#define door(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51) \
	_generic_object(0x01, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39, \
	u40, u41, u42, u43, \
	u44, u45, u46, u47, \
	u48, u49, u50, u51,

#define door_scale(scale) \
	0x02, \
	scale,

#define stdobject(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19) \
	_generic_object(0x03, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19),

#define key(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, lockbits) \
	_generic_object(0x04, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	lockbits,

#define camera(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45) \
	_generic_object(0x06, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39, \
	u40, u41, u42, u43, \
	u44, u45,

#define ammocrate(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, ammotype) \
	_generic_object(0x07, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	ammotype,

#define weapon(scale, model, chr, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, weapon, u20, u21) \
	_generic_object(0x08, scale, model, chr, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	_mkword(_mkshort(weapon, 0), 0), \
	u20, u21,

#define chr(unk1, id, pad, body, head, function, target_pad, target_chr, hear_dist, view_dist, props1, bank1flags, team, group, chair, group2, associated) \
	0x09, \
	unk1, \
	_mkword(id, pad), \
	_mkword(_mkshort(body, head), function), \
	_mkword(target_pad, target_chr), \
	_mkword(hear_dist, view_dist), \
	props1, \
	bank1flags, \
	_mkword(_mkshort(team, group), chair), \
	group2, \
	associated,

#define singlemonitor(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49) \
	_generic_object(0x0a, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39, \
	u40, u41, u42, u43, \
	u44, u45, u46, u47, \
	u48, u49,

#define multimonitor(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51, u52, u53, u54, u55, u56, u57, u58, u59, u60, u61, u62, u63, u64, u65, u66, u67, u68, u69, u70, u71, u72, u73, u74, u75, u76, u77, u78, u79, u80, u81, u82, u83, u84, u85, u86, u87, u88, u89, u90, u91, u92, u93, u94, u95, u96, u97, u98, u99, u100, u101, u102, u103, u104, u105, u106, u107, u108, u109, u110, u111, u112, u113, u114, u115, u116, u117, u118, u119, u120, u121, u122, u123, u124, u125, u126, u127, u128, u129, u130, u131, u132, u133, u134, u135, u136) \
	_generic_object(0x0b, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39, \
	u40, u41, u42, u43, \
	u44, u45, u46, u47, \
	u48, u49, u50, u51, \
	u52, u53, u54, u55, \
	u56, u57, u58, u59, \
	u60, u61, u62, u63, \
	u64, u65, u66, u67, \
	u68, u69, u70, u71, \
	u72, u73, u74, u75, \
	u76, u77, u78, u79, \
	u80, u81, u82, u83, \
	u84, u85, u86, u87, \
	u88, u89, u90, u91, \
	u92, u93, u94, u95, \
	u96, u97, u98, u99, \
	u100, u101, u102, u103, \
	u104, u105, u106, u107, \
	u108, u109, u110, u111, \
	u112, u113, u114, u115, \
	u116, u117, u118, u119, \
	u120, u121, u122, u123, \
	u124, u125, u126, u127, \
	u128, u129, u130, u131, \
	u132, u133, u134, u135, \
	u136,

#define autogun(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39) \
	_generic_object(0x0d, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39,

#define link_collectibles(a, b) \
	0x0e, \
	_mkword(a, b),

#define debris(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19) \
	_generic_object(0x0f, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19),

#define link_objects(u1, u2, u3, u4) \
	0x13, \
	u1, u2, u3, u4,

#define ammocratemulti(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38) \
	_generic_object(0x14, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38,

#define shield(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22) \
	_generic_object(0x15, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22,

#define tag(id, value) \
	0x16, \
	_mkword(id, value), \
	0, \
	0,

#define beginobjective(value, text, diffbit) \
	0x17, \
	value, \
	text, \
	diffbit,

#define endobjective \
	0x18,

#define require_object_destroyed(object) \
	0x19, \
	object,

#define complete_flags(stageflag) \
	0x1a, \
	stageflag,

#define fail_flags(stageflag) \
	0x1b, \
	stageflag,

#define require_object_collected(object) \
	0x1c, \
	object,

#define require_object_thrown(object) \
	0x1d, \
	object,

#define require_object_holographed(object, u1, u2) \
	0x1e, \
	object, \
	u1, \
	u2,

#define require_room_entered(room) \
	0x20, \
	room,

#define require_object_thrown_on_target(throw_object, target_object, u1) \
	0x21, \
	throw_object, \
	target_object, \
	u1,

#define briefing(value, text1) \
	0x23, \
	value, \
	text1, \
	0,

#define rename_object(u1, id, text, text2, text3, text4, text5, u2, u3) \
	0x25, \
	u1, \
	id, \
	text, \
	text2, \
	text3, \
	text4, \
	text5, \
	u2, u3,

#define glass(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20) \
	_generic_object(0x2a, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20,

#define camera2(scale, u1, u2, u3, u4, u5, u6) \
	_mkword(scale, 0x2e), \
	u1, u2, u3, u4, \
	u5, u6,

#define tinted_glass(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22) \
	_generic_object(0x2f, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22,

#define lift(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, pad1, pad2, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32) \
	_generic_object(0x30, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	_mkword(pad1, pad2), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32,

#define link_scenery(unk1, unk2, unk3) \
	0x31, \
	unk1, unk2, unk3, \
	0,

#define link_paths(u1, u2, u3) \
	0x32, \
	u1, u2, u3,

#define hoverbike(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51, u52) \
	_generic_object(0x33, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39, \
	u40, u41, u42, u43, \
	u44, u45, u46, u47, \
	u48, u49, u50, u51, \
	u52,

#define endprops \
	0x34,

#define hover_prop(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35) \
	_generic_object(0x35, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35,

#define vent_fan(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25) \
	_generic_object(0x36, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25,

#define hovercar(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34) \
	_generic_object(0x37, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34,

#define pad_effect(effect, pad) \
	0x38, \
	effect, \
	pad,

#define chopper(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51, u52, u53, u54) \
	_generic_object(0x39, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23, \
	u24, u25, u26, u27, \
	u28, u29, u30, u31, \
	u32, u33, u34, u35, \
	u36, u37, u38, u39, \
	u40, u41, u42, u43, \
	u44, u45, u46, u47, \
	u48, u49, u50, u51, \
	u52, u53, u54,

#define remote_mine(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22) \
	_generic_object(0x3a, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22,

#define escalator(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23) \
	_generic_object(0x3b, scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	u20, u21, u22, u23,
