#include "util.h"

// Only used within this file
// len 0x58
#define generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19) \
	mkshort(model), \
	mkshort(pad), \
	mkword(props1), \
	mkword(props2), \
	mkword(u1), mkword(u2), mkword(u3), mkword(u4), \
	mkword(u5), mkword(u6), mkword(u7), mkword(u8), \
	mkword(u9), mkword(u10), mkword(u11), mkword(u12), \
	mkword(u13), mkword(u14), mkword(u15), mkword(u16), \
	mkword(u17), mkword(u18), mkword(u19)

#define door(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51) \
	mkshort(scale), \
	mkshort(0x01), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39), \
	mkword(u40), mkword(u41), mkword(u42), mkword(u43), \
	mkword(u44), mkword(u45), mkword(u46), mkword(u47), \
	mkword(u48), mkword(u49), mkword(u50), mkword(u51),

#define door_scale(scale) \
	mkshort(0), \
	mkshort(0x02), \
	mkword(scale),

#define stdobject(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19) \
	mkshort(scale), \
	mkshort(0x03), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19),

#define key(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, lockbits) \
	mkshort(scale), \
	mkshort(0x04), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(lockbits),

#define camera(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45) \
	mkshort(scale), \
	mkshort(0x06), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39), \
	mkword(u40), mkword(u41), mkword(u42), mkword(u43), \
	mkword(u44), mkword(u45),

#define ammocrate(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, ammotype) \
	mkshort(scale), \
	mkshort(0x07), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(ammotype),

#define weapon(scale, model, chr, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, weapon, u20, u21) \
	mkshort(scale), \
	mkshort(0x08), \
	generic_object(model, chr, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	weapon, 0x00, 0x00, 0x00, \
	mkword(u20), mkword(u21),

#define chr(unk1, id, pad, body, head, function, target_pad, target_chr, hear_dist, view_dist, props1, bank1flags, team, group, chair, group2, associated) \
	mkshort(0), \
	mkshort(0x09), \
	mkword(unk1), \
	mkshort(id), \
	mkshort(pad), \
	body, \
	head, \
	mkshort(function), \
	mkshort(target_pad), \
	mkshort(target_chr), \
	mkshort(hear_dist), \
	mkshort(view_dist), \
	mkword(props1), \
	mkword(bank1flags), \
	team, \
	group, \
	mkshort(chair), \
	mkword(group2), \
	mkword(associated),

#define singlemonitor(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49) \
	mkshort(scale), \
	mkshort(0x0a), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39), \
	mkword(u40), mkword(u41), mkword(u42), mkword(u43), \
	mkword(u44), mkword(u45), mkword(u46), mkword(u47), \
	mkword(u48), mkword(u49),

#define multimonitor(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51, u52, u53, u54, u55, u56, u57, u58, u59, u60, u61, u62, u63, u64, u65, u66, u67, u68, u69, u70, u71, u72, u73, u74, u75, u76, u77, u78, u79, u80, u81, u82, u83, u84, u85, u86, u87, u88, u89, u90, u91, u92, u93, u94, u95, u96, u97, u98, u99, u100, u101, u102, u103, u104, u105, u106, u107, u108, u109, u110, u111, u112, u113, u114, u115, u116, u117, u118, u119, u120, u121, u122, u123, u124, u125, u126, u127, u128, u129, u130, u131, u132, u133, u134, u135, u136) \
	mkshort(scale), \
	mkshort(0x0b), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39), \
	mkword(u40), mkword(u41), mkword(u42), mkword(u43), \
	mkword(u44), mkword(u45), mkword(u46), mkword(u47), \
	mkword(u48), mkword(u49), mkword(u50), mkword(u51), \
	mkword(u52), mkword(u53), mkword(u54), mkword(u55), \
	mkword(u56), mkword(u57), mkword(u58), mkword(u59), \
	mkword(u60), mkword(u61), mkword(u62), mkword(u63), \
	mkword(u64), mkword(u65), mkword(u66), mkword(u67), \
	mkword(u68), mkword(u69), mkword(u70), mkword(u71), \
	mkword(u72), mkword(u73), mkword(u74), mkword(u75), \
	mkword(u76), mkword(u77), mkword(u78), mkword(u79), \
	mkword(u80), mkword(u81), mkword(u82), mkword(u83), \
	mkword(u84), mkword(u85), mkword(u86), mkword(u87), \
	mkword(u88), mkword(u89), mkword(u90), mkword(u91), \
	mkword(u92), mkword(u93), mkword(u94), mkword(u95), \
	mkword(u96), mkword(u97), mkword(u98), mkword(u99), \
	mkword(u100), mkword(u101), mkword(u102), mkword(u103), \
	mkword(u104), mkword(u105), mkword(u106), mkword(u107), \
	mkword(u108), mkword(u109), mkword(u110), mkword(u111), \
	mkword(u112), mkword(u113), mkword(u114), mkword(u115), \
	mkword(u116), mkword(u117), mkword(u118), mkword(u119), \
	mkword(u120), mkword(u121), mkword(u122), mkword(u123), \
	mkword(u124), mkword(u125), mkword(u126), mkword(u127), \
	mkword(u128), mkword(u129), mkword(u130), mkword(u131), \
	mkword(u132), mkword(u133), mkword(u134), mkword(u135), \
	mkword(u136),

#define autogun(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39) \
	mkshort(scale), \
	mkshort(0x0d), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39),

#define link_collectibles(a, b) \
	mkshort(0), \
	mkshort(0x0e), \
	mkshort(a), \
	mkshort(b),

#define debris(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19) \
	mkshort(scale), \
	mkshort(0x0f), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19),

#define link_objects(u1, u2, u3, u4) \
	mkshort(0), \
	mkshort(0x13), \
	mkword(u1), mkword(u2), mkword(u3), mkword(u4),

#define ammocratemulti(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38) \
	mkshort(scale), \
	mkshort(0x14), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38),

#define shield(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22) \
	mkshort(scale), \
	mkshort(0x15), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22),

#define tag(id, value) \
	mkshort(0), \
	mkshort(0x16), \
	mkshort(id), \
	mkshort(value), \
	mkword(0), \
	mkword(0),

#define beginobjective(value, text, diffbit) \
	mkshort(0), \
	mkshort(0x17), \
	mkword(value), \
	mkword(text), \
	mkword(diffbit),

#define endobjective \
	mkshort(0), \
	mkshort(0x18),

#define require_object_destroyed(object) \
	mkshort(0), \
	mkshort(0x19), \
	mkword(object),

#define complete_flags(stageflag) \
	mkshort(0), \
	mkshort(0x1a), \
	mkword(stageflag),

#define fail_flags(stageflag) \
	mkshort(0), \
	mkshort(0x1b), \
	mkword(stageflag),

#define require_object_collected(object) \
	mkshort(0), \
	mkshort(0x1c), \
	mkword(object),

#define require_object_thrown(object) \
	mkshort(0), \
	mkshort(0x1d), \
	mkword(object),

#define require_object_holographed(object, u1, u2) \
	mkshort(0), \
	mkshort(0x1e), \
	mkword(object), \
	mkword(u1), \
	mkword(u2),

#define require_room_entered(room) \
	mkshort(0), \
	mkshort(0x20), \
	mkword(room),

#define require_object_thrown_on_target(throw_object, target_object, u1) \
	mkshort(0), \
	mkshort(0x21), \
	mkword(throw_object), \
	mkword(target_object), \
	mkword(u1),

#define briefing(value, text1) \
	mkshort(0), \
	mkshort(0x23), \
	mkword(value), \
	mkword(text1), \
	mkword(0),

#define rename_object(u1, id, text, text2, text3, text4, text5, u2, u3) \
	mkshort(0), \
	mkshort(0x25), \
	mkword(u1), \
	mkword(id), \
	mkword(text), \
	mkword(text2), \
	mkword(text3), \
	mkword(text4), \
	mkword(text5), \
	mkword(u2), mkword(u3),

#define glass(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20) \
	mkshort(scale), \
	mkshort(0x2a), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20),

#define camera2(scale, u1, u2, u3, u4, u5, u6) \
	mkshort(scale), \
	mkshort(0x2e), \
	mkword(u1), mkword(u2), mkword(u3), mkword(u4), \
	mkword(u5), mkword(u6),

#define tinted_glass(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22) \
	mkshort(scale), \
	mkshort(0x2f), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22),

#define lift(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, pad1, pad2, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32) \
	mkshort(scale), \
	mkshort(0x30), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkshort(pad1), \
	mkshort(pad2), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32),

#define link_scenery(unk1, unk2, unk3) \
	mkshort(0), \
	mkshort(0x31), \
	mkword(unk1), mkword(unk2), mkword(unk3), \
	mkword(0),

#define link_paths(u1, u2, u3) \
	mkshort(0), \
	mkshort(0x32), \
	mkword(u1), mkword(u2), mkword(u3),

#define hoverbike(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51, u52) \
	mkshort(scale), \
	mkshort(0x33), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39), \
	mkword(u40), mkword(u41), mkword(u42), mkword(u43), \
	mkword(u44), mkword(u45), mkword(u46), mkword(u47), \
	mkword(u48), mkword(u49), mkword(u50), mkword(u51), \
	mkword(u52),

#define endprops \
	mkshort(0), \
	mkshort(0x34),

#define hover_prop(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35) \
	mkshort(scale), \
	mkshort(0x35), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35),

#define vent_fan(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25) \
	mkshort(scale), \
	mkshort(0x36), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25),

#define hovercar(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34) \
	mkshort(scale), \
	mkshort(0x37), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34),

#define pad_effect(effect, pad) \
	mkshort(0), \
	mkshort(0x38), \
	mkword(effect), \
	mkword(pad),

#define armed_vehicle(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35, u36, u37, u38, u39, u40, u41, u42, u43, u44, u45, u46, u47, u48, u49, u50, u51, u52, u53, u54) \
	mkshort(scale), \
	mkshort(0x39), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23), \
	mkword(u24), mkword(u25), mkword(u26), mkword(u27), \
	mkword(u28), mkword(u29), mkword(u30), mkword(u31), \
	mkword(u32), mkword(u33), mkword(u34), mkword(u35), \
	mkword(u36), mkword(u37), mkword(u38), mkword(u39), \
	mkword(u40), mkword(u41), mkword(u42), mkword(u43), \
	mkword(u44), mkword(u45), mkword(u46), mkword(u47), \
	mkword(u48), mkword(u49), mkword(u50), mkword(u51), \
	mkword(u52), mkword(u53), mkword(u54),

#define remote_mine(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22) \
	mkshort(scale), \
	mkshort(0x3a), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22),

#define escalator(scale, model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19, u20, u21, u22, u23) \
	mkshort(scale), \
	mkshort(0x3b), \
	generic_object(model, pad, props1, props2, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, u17, u18, u19), \
	mkword(u20), mkword(u21), mkword(u22), mkword(u23),
