#!/usr/bin/env python3

import commands
import os
import struct
import sys

"""
ai2asm - Convert a binary AI data file to assembly.

Usage:
    ai2asm <binfile>

Assembly is printed to stdout.
"""


class App():

    def run(self):
        self.commands = commands.get_commands()
        ailists = self.load_lists()

        self.print_header()
        self.next_temp_label_id = 0

        for offset in ailists:
            self.convert_list(ailists[offset])

        self.print_table(ailists)

    def load_lists(self):
        ailists = {}
        seen_ids = {}

        fd = open(sys.argv[1], 'rb')
        contents = fd.read()
        fd.close()

        if 'gailists' in sys.argv[1]:
            pos = int.from_bytes(contents[0:4], 'big')
            self.stage = 'global'
        else:
            pos = int.from_bytes(contents[0x18:0x1c], 'big')
            self.stage = os.path.basename(sys.argv[1]).replace('setup', '').replace('.bin', '')

        while True:
            listoffset = int.from_bytes(contents[pos:pos+4], 'big')
            listid = int.from_bytes(contents[pos+4:pos+8], 'big')
            pos += 8

            if listoffset == 0 and len(ailists) > 0:
                break

            if listid in seen_ids:
                print('Duplicate ID: %04x' % listid, file=sys.stderr)
                exit(1)

            seen_ids[listid] = True

            if listoffset not in ailists:
                listcmds = self.parse_ailist(contents[listoffset:])
                ailists[listoffset] = {'ids': [], 'cmds': listcmds}

            ailists[listoffset]['ids'].append(listid)

        return ailists

    def parse_ailist(self, data):
        listcmds = []
        pos = 0

        while True:
            type = int.from_bytes(data[pos:pos+2], 'big')
            length = self.commands[type]['len']
            listcmds.append({'id': type, 'params': data[pos+2:pos+length]})
            pos += length

            if type == 0x0004:
                break

        return listcmds

    def print_header(self):
        print('#include "macros.inc"')
        print('.text')
        print('')

    def print_table(self, ailists):
        entries = []

        for offset in ailists:
            for id in ailists[offset]['ids']:
                entries.append(id)

        entries.sort()

        print('')
        print('.data')

        if self.stage == 'global':
            print('glabel g_GlobalAilists')
        else:
            print('glabel g_StageAilists_%s' % self.stage)

        for id in entries:
            print('.word %s' % self.ailist_name(id))
            print('.word 0x%04x' % id)

        print('.word 0')
        print('.word 0')

    def print_missing(self):
        for cmdid in self.missing:
            definition = self.commands[cmdid]

    def convert_list(self, ailist):
        for id in ailist['ids']:
            print('glabel %s' % self.ailist_name(id))

        self.cur_list_id = ailist['ids'][0]
        self.labels = {}

        for cmd in ailist['cmds']:
            definition = self.commands[cmd['id']]
            callback = getattr(self, 'ai_' + definition['macro'])
            try:
                callback(cmd['params'])
            except NotImplementedError:
                print('Not implemented: %04x (%s)' % (cmd['id'], definition['macro']), file=sys.stderr)
        print('')

    def s8(self, value):
        if value >= 0x80:
            value -= 0x100
        return value

    def s16(self, params, offset):
        value = self.u16(params, offset)
        if value >= 0x8000:
            value -= 0x10000
        return value

    def u16(self, params, offset):
        return int.from_bytes(params[offset:offset+2], 'big')

    def u32(self, params, offset):
        return int.from_bytes(params[offset:offset+4], 'big')

    def temp_label(self):
        label = '.Ltemp%d' % self.next_temp_label_id
        self.next_temp_label_id += 1
        return label

    def emit(self, instruction, params=[]):
        print('\t% -10s%s' % (instruction, ', '.join(map(str, params))))

    def emit_beqz_label(self, label):
        self.emit('beqz', ['$v0', self.label_name(label)])

    def emit_bnez_label(self, label):
        self.emit('bnez', ['$v0', self.label_name(label)])

    def emit_raw(self, line):
        print(line)

    def emit_store_to_stack(self, stackoffset, value):
        if value == 0:
            self.emit('sw', ['$zero', '0x%x($sp)' % stackoffset])
        else:
            self.emit('li', ['$t0', value])
            self.emit('sw', ['$t0', '0x%x($sp)' % stackoffset])

    def get_shiftamount(self, flag):
        i = 0
        while i < 32:
            if flag & 1:
                if flag == 1:
                    return 31 - i
                else:
                    return -1
            flag >>= 1
            i += 1
        return -1

    def emit_has_flag(self, reg, flag, label):
        shiftamount = self.get_shiftamount(flag)
        if shiftamount >= 0:
            if shiftamount >= 1:
                self.emit('sll', [reg, reg, shiftamount])
            self.emit('bltz', [reg, self.label_name(label)])
        elif flag & 0xffff0000:
            self.emit('li', ['$t0', flag])
            self.emit('and', [reg, reg, '$t0'])
            self.emit('bnez', [reg, self.label_name(label)])
        else:
            self.emit('andi', [reg, reg, flag])
            self.emit('bnez', [reg, self.label_name(label)])

    def emit_not_has_flag(self, reg, flag, label):
        shiftamount = self.get_shiftamount(flag)
        if shiftamount >= 0:
            if shiftamount >= 1:
                self.emit('sll', [reg, reg, shiftamount])
            self.emit('bgez', [reg, self.label_name(label)])
        elif flag & 0xffff0000:
            self.emit('li', ['$t0', flag])
            self.emit('and', [reg, reg, '$t0'])
            self.emit('beqz', [reg, self.label_name(label)])
        else:
            self.emit('andi', [reg, reg, flag])
            self.emit('beqz', [reg, self.label_name(label)])

    def emit_set_flag(self, reg, flag):
        if flag & 0xffff0000:
            self.emit('li', ['$t0', flag])
            self.emit('or', ['$v0', '$v0', '$t0'])
        else:
            self.emit('ori', ['$v0', '$v0', flag])

    def emit_unset_flag(self, reg, flag):
        flag = (~flag) & 0xffffffff
        if flag & 0xffff0000:
            self.emit('li', ['$t0', flag])
            self.emit('and', [reg, reg, '$t0'])
        else:
            self.emit('andi', [reg, reg, flag])

    def chr_field_offset(self, fieldname):
        map = {
            'accuracyrating':     0x2,
            'speedrating':        0x3,
            'actiontype':         0x7,
            'numarghs':           0xb,
            'arghrating':         0xd,
            'grenadeprob':        0xf,
            'hidden':             0x14,
            'chrflags':           0x18,
            'hearingscale':       0xf0,
            'morale':             0x118,
            'alertness':          0x119,
            'flags':              0x11c,
            'flags2':             0x120,
            'timer60':            0x124,
            'soundtimer':         0x128,
            'team':               0x12d,
            'cshield':            0x188,
            'cover':              0x29a,
            'myaction':           0x2a8,
            'orders':             0x2a9,
            'squadron':           0x2aa,
            'naturalanim':        0x2eb,
            'race':               0x306,
            'gunprop':            0x308,
            'specialdie':         0x337,
            'dodgerating':        0x36c,
            'maxdodgerating':     0x36d,
            'unarmeddodgerating': 0x36e,
        }
        return map[fieldname];

    def chr_field(self, fieldname):
        return '0x%x($s0)' % self.chr_field_offset(fieldname)

    def ailist_name(self, ailistid):
        if ailistid < 0x100:
            return 'ailist_%04x' % ailistid
        return 'ailist_%s_%04x' % (self.stage, ailistid)

    def label_name(self, label_id, index=None):
        if index is None:
            if label_id in self.labels:
                index = self.labels[label_id] + 1
            else:
                index = 0
        return '.L%04x_%02x_%02x' % (self.cur_list_id, label_id, index)

    def ai_activate_alarm(self, params):
        self.emit('jal', ['alarmActivate'])

    def ai_activate_lift(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiActivateLift'])

    def ai_add_health_or_armor(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li.s', ['$a1', self.u16(params, 0) / 10])
        self.emit('jal', ['chrAddHealth'])

    def ai_add_morale(self, params):
        self.emit('addiu', ['$a0', '$s0', self.chr_field_offset('morale')])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['incrementByte'])

    def ai_add_motion_blur(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('jal', ['aiChrAddMotionBlur'])

    def ai_assign_path(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['chrSetPath'])

    def ai_assign_sound(self, params):
        self.emit('li', ['$a0', self.s16(params, 0)])
        self.emit('li', ['$a1', self.s8(params[2])])
        self.emit('jal', ['aiAssignSound'])

    def ai_begin_hovercar_path(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiHovercarBeginPath'])

    def ai_call_rng(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiCallRng'])

    def ai_camera_movement(self, params):
        # aiSetCameraAnimation returns true if we should yield
        # and re-run aiSetCameraAnimation again on the next invocation
        start = self.temp_label()
        end = self.temp_label()
        self.emit_raw('%s:' % start)
        self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['aiSetCameraAnimation'])
        self.emit('beqz', ['$v0', end])
        self.emit('jal', ['aiYield'])
        self.emit('b', [start])
        self.emit_raw('%s:' % end)

    def ai_check_cover_out_of_sight(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiCheckCoverOutOfSight'])
        self.emit_bnez_label(params[0])

    def ai_chopper_arm_weapons(self, params):
        self.emit('jal', ['aiHeliArmWeapons'])

    def ai_chr_damage_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('li', ['$a3', params[2]])
        self.emit('jal', ['aiChrDamageChr'])

    def ai_chr_do_animation(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[8]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a3', '0x%04x' % self.u16(params, 2)])
        self.emit_store_to_stack(0x10, '0x%04x' % self.u16(params, 4))
        self.emit_store_to_stack(0x14, '0x%02x' % params[6])
        self.emit_store_to_stack(0x18, params[7])
        self.emit_store_to_stack(0x1c, params[9])
        self.emit('jal', ['aiChrDoAnimation'])

    def ai_chr_draw_weapon(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiChrDrawWeapon'])

    def ai_chr_draw_weapon_in_cutscene(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiChrDrawWeaponInCutscene'])

    def ai_chr_drop_weapon(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiChrDropWeapon'])

    def ai_chr_move_to_pad(self, params):
        if params[3] == 88:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%02x' % params[2]])
            self.emit('jal', ['aiChrMoveToChr'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%04x' % self.u16(params, 1)])
            self.emit('li', ['$a3', params[3]])
            self.emit('jal', ['aiChrMoveToPad'])
        self.emit_bnez_label(params[4])

    def ai_chr_recover_gun(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiRecoverGun'])
        self.emit('b', [self.label_name(params[1])])

    def ai_chr_toggle_modelpart(self, params):
        if params[0] == 0xfd:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[1]])
            self.emit('jal', ['chrToggleModelPart'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%02x' % params[1]])
            self.emit('jal', ['aiChrToggleModelPart'])

    def ai_chr_toggle_p1p2(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiChrToggleP1P2'])

    def ai_clear_inventory(self, params):
        self.emit('jal', ['aiClearInventory'])

    def ai_close_door(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiCloseDoor'])

    def ai_cmd012f(self, params):
        self.emit('lh', ['$a0', self.chr_field('cover')])
        self.emit('jal', ['aiSetCoverUnused'])

    def ai_cmd0139(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', self.u32(params, 0)])
        self.emit('li', ['$a2', params[4]])
        self.emit('li', ['$a3', params[5]])
        self.emit('jal', ['ai0139'])

    def ai_cmd0175(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['playerReorientForCutsceneStop'])

    def ai_cmd0176_if_something(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['ai0176'])
        self.emit_bnez_label(params[0])

    def ai_cmd01b4_if_something(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['ai01b4'])
        self.emit_bnez_label(params[0])

    def ai_configure_environment(self, params):
        if params[2] == 0:
            pass
        elif params[2] == 1:
            pass
        elif params[2] == 2:
            pass
        elif params[2] == 3:
            pass
        elif params[2] == 4:
            pass
        elif params[2] == 5:
            self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
            self.emit('li', ['$a1', '0x4000'])
            self.emit('jal', ['aiSetRoomFlag' if params[3] else 'aiUnsetRoomFlag'])
        elif params[2] == 6:
            self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
            self.emit('li', ['$a1', '0x8000'])
            self.emit('jal', ['aiSetRoomFlag' if params[3] else 'aiUnsetRoomFlag'])
        elif params[2] == 7:
            raise NotImplementedError
        elif params[2] == 8:
            raise NotImplementedError
        elif params[2] == 9:
            self.emit('jal', ['aiSetAllRoomsAmbient' if params[3] else 'aiUnsetAllRoomsAmbient'])
        elif params[2] == 10:
            self.emit('li', ['$a0', params[3]])
            self.emit('jal', ['sndPlayNosedive'])
        elif params[2] == 11:
            self.emit('jal', ['musicTickEvents'])
        elif params[2] == 12:
            self.emit('li', ['$a0', '0x%04x' % params[0]])
            self.emit('li', ['$a1', params[1]])
            self.emit('jal', ['roomSetLightsFaulty'])
        elif params[2] == 13:
            self.emit('jal', ['sndStopNosedive'])
        elif params[2] == 14:
            self.emit('li', ['$a0', params[3]])
            self.emit('jal', ['sndPlayUfo'])
        elif params[2] == 15:
            self.emit('jal', ['sndStopUfo'])
        else:
            raise NotImplementedError

    def ai_consider_throwing_grenade(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiConsiderGrenadeThrow'])
        self.emit_bnez_label(params[4])

    def ai_control_sound_from_object(self, params):
        self.emit('li', ['$a0', self.s8(params[0])])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('li', ['$a2', params[3]])
        self.emit('jal', ['ai00cf'])

    def ai_damage_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', self.s8(params[1])])
        self.emit('li', ['$a3', '0x%08x' % (params[2] << 24)])
        self.emit('jal', ['aiDamageChr'])

    def ai_damage_chr_by_amount(self, params):
        if params[2] == 0:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li.s', ['$a2', self.s8(params[1]) / 32])
            self.emit('jal', ['aiDamageChrByAmount'])
        elif params[2] == 2:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li.s', ['$a2', self.s8(params[1]) / 32])
            self.emit('jal', ['aiDamageAndPoisonChrByAmount'])
        else:
            raise NotImplementedError

    def ai_deactivate_alarm(self, params):
        self.emit('jal', ['alarmDeactivate'])

    def ai_destroy_object(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiDestroyObject'])

    def ai_disable_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiDisableChr'])

    def ai_disable_object(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiDisableObj'])

    def ai_do_gun_command(self, params):
        if params[0] == 0:
            self.emit('move', ['$a0', '$s0'])
            self.emit('lw', ['$a1', self.chr_field('gunprop')])
            self.emit('li', ['$a2', '1'])
            self.emit('jal', ['chrGoToProp'])
            self.emit('b', [self.label_name(params[1])])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('jal', ['aiIfGunLanded'])
            self.emit_bnez_label(params[1])

    def ai_do_preset_animation(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['aiDoPresetAnimation'])

    def ai_drop_concealed_items(self, params):
        if params[0] == 0xfd:
            self.emit('move', ['$a0', '$s0'])
            self.emit('jal', ['chrDropConcealedItems'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiChrDropItems'])

    def ai_drop_gun_and_fade_out(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrFadeOut'])

    def ai_emit_sparks(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiChrEmitSparks'])

    def ai_enable_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiEnableChr'])

    def ai_enable_object(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiEnableObj'])

    def ai_enable_rain(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['weatherConfigureRain'])

    def ai_enable_snow(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['weatherConfigureSnow'])

    def ai_end_level(self, params):
        self.emit('jal', ['aiEndLevel'])

    def ai_endlist(self, params):
        pass

    def ai_enter_camera_and_move_to_pad(self, params):
        self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['playerPrepareWarpType1'])

    def ai_enter_firstperson(self, params):
        self.emit('jal', ['playerEndCutscene'])

    def ai_explosions_around_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiChrExplosions'])

    def ai_fade_to_color(self, params):
        self.emit('li', ['$a0', '0x%08x' % self.u32(params, 0)])
        self.emit('li', ['$a1', self.u16(params, 4)])
        self.emit('jal', ['lvConfigureFade'])

    def ai_find_cover(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % self.u16(params, 0)])
        self.emit('jal', ['aiFindCover'])
        self.emit_bnez_label(params[2])

    def ai_force_walk(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 1)])
        self.emit('li', ['$a3', params[3]])
        self.emit_store_to_stack(0x10, params[4])
        self.emit_store_to_stack(0x14, params[5])
        self.emit_store_to_stack(0x18, params[6])
        self.emit('jal', ['aiAutoWalk'])

    def ai_give_object_to_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiGiveObjectToChr'])

    def ai_go_to_cover(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['chrGoToCover'])

    def ai_go_to_target_pad(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['aiGoToPadPreset'])

    def ai_goto_first(self, params):
        self.emit('b', [self.label_name(params[0], 0)])

    def ai_goto_next(self, params):
        self.emit('b', [self.label_name(params[0])])

    def ai_grab_object(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiChrGrabObject'])

    def ai_grant_control(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiGrantControl'])

    def ai_hide_countdown_timer(self, params):
        self.emit('li', ['$a0', '1'])
        self.emit('li', ['$a1', '0'])
        self.emit('jal', ['countdownTimerSetVisible'])

    def ai_hovercopter_fire_rocket(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiHovercopterFireRocket'])

    def ai_if_alarm_active(self, params):
        self.emit('lui', ['$a0', '%hi(g_AlarmTimer)'])
        self.emit('lw', ['$v0', '%lo(g_AlarmTimer)($a0)'])
        self.emit('bgtz', ['$v0', self.label_name(params[0])])

    def ai_if_alertness(self, params):
        self.emit('lbu', ['$v0', self.chr_field('alertness')])
        self.emit('li', ['$v1', '0x%02x' % params[0]])
        if params[1] == 0:
            self.emit('blt', ['$v0', '$v1', self.label_name(params[2])])
        else:
            self.emit('bgt', ['$v0', '$v1', self.label_name(params[2])])

    def ai_if_all_chrs_in_squadron_are_dead(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiIfSquadronIsDead'])
        self.emit_bnez_label(params[1])

    def ai_if_all_objectives_complete(self, params):
        self.emit('jal', ['objectiveIsAllComplete'])
        self.emit_bnez_label(params[0])

    def ai_if_ammo_quantity_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('li', ['$a3', params[2]])
        self.emit('jal', ['aiIfChrAmmoQuantityLessThan'])
        self.emit_bnez_label(params[3])

    def ai_if_any_objective_failed(self, params):
        self.emit('lui', ['$a0', '%hi(g_AnyObjectiveFailed)'])
        self.emit('lw', ['$v0', '%lo(g_AnyObjectiveFailed)($a0)'])
        self.emit_bnez_label(params[0])

    def ai_if_calculated_safety2_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['aiIfSafety2LessThan'])
        self.emit_bnez_label(params[1])

    def ai_if_camera_animating(self, params):
        self.emit('lui', ['$v0', '%hi(g_Vars+0x4bc)'])
        self.emit('lw', ['$v0', '%lo(g_Vars+0x4bc)($v0)'])
        self.emit_bnez_label(params[0])

    def ai_if_can_hear_alarm(self, params):
        self.emit('lui', ['$a0', '%hi(g_AlarmTimer)'])
        self.emit('lw', ['$v0', '%lo(g_AlarmTimer)($a0)'])
        self.emit('bgtz', ['$v0', self.label_name(params[0])])

    def ai_if_can_see_attack_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfCanSeeAttackTarget'])
        self.emit_bnez_label(params[0])

    def ai_if_can_see_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfCanSeeTarget'])
        self.emit_bnez_label(params[0])

    def ai_if_chr_activated_object(self, params):
        if params[0] == 0xf3:
            self.emit('li', ['$a0', '0x%02x' % params[1]])
            self.emit('jal', ['aiIfAnyoneActivatedObject'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%02x' % params[1]])
            self.emit('jal', ['aiIfChrActivatedObject'])
        self.emit_bnez_label(params[2])

    def ai_if_chr_alertness_lt(self, params):
        raise NotImplementedError

    def ai_if_chr_dead(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrDead'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_deadish(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrDeadish'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_death_animation_finished(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrDeathAnimationFinished'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_distance_to_pad_gt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 3)])
        self.emit('li.s', ['$a3', self.u16(params, 1) * 10])
        self.emit('jal', ['aiIfChrDistanceToPadGreaterThan'])
        self.emit_bnez_label(params[5])

    def ai_if_chr_distance_to_pad_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 3)])
        self.emit('li.s', ['$a3', self.u16(params, 1) * 10])
        self.emit('jal', ['aiIfChrDistanceToPadLessThan'])
        self.emit_bnez_label(params[5])

    def ai_if_chr_has_chrflag(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiIfChrHasChrflag'])
        self.emit_bnez_label(params[5])

    def ai_if_chr_has_flag_bankx(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
        self.emit('li', ['$a3', params[5]])
        self.emit('jal', ['chrHasFlagById'])
        self.emit_bnez_label(params[6])

    def ai_if_chr_has_hiddenflag(self, params):
        if params[0] == 0xfd:
            flag = self.u32(params, 1)
            self.emit('lw', ['$v0', self.chr_field('hidden')])
            self.emit_has_flag('$v0', flag, params[5])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
            self.emit('jal', ['aiIfChrHasHiddenFlag'])
            self.emit_bnez_label(params[5])

    def ai_if_chr_has_object(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfChrHasObject'])
        self.emit_bnez_label(params[2])

    def ai_if_chr_idle(self, params):
        self.emit('lbu', ['$v0', self.chr_field('actiontype')])
        self.emit('li', ['$v1', 3])
        self.emit('beq', ['$v0', '$v1', self.label_name(params[0])])

    def ai_if_chr_idle_action_eq(self, params):
        self.emit('lbu', ['$v0', self.chr_field('naturalanim')])
        self.emit('li', ['$v1', params[0]])
        self.emit('beq', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_chr_in_room(self, params):
        if params[1] == 0:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
            self.emit('jal', ['aiIfChrInSameRoomAsPad'])
        elif params[1] == 1:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiIfChrInSearchRoom'])
        else:
            self.emit('li', ['$a0', '0x%04x' % self.u16(params, 2)])
            self.emit('jal', ['aiIfEyespyNearG5Pad'])
        self.emit_bnez_label(params[4])

    def ai_if_chr_in_squadron_doing_action(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrInSquadronDoingAction'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_in_view(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrCanSeeTargetWithExtraCheck'])
        self.emit_bnez_label(params[0])

    def ai_if_chr_injured_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrInjuredTarget'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_is_skedar(self, params):
        self.emit('lbu', ['$v0', self.chr_field('race')])
        self.emit('li', ['$v1', 1])
        self.emit('beq', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_chr_knockedout(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrKnockedOut'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_looking_at_object(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfPlayerLookingAtObject'])
        self.emit_bnez_label(params[2])

    def ai_if_chr_not_talking(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfChrNotTalking'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_same_floor_distance_to_pad_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 3)])
        self.emit('li.s', ['$a3', self.u16(params, 1) * 10])
        self.emit('jal', ['aiIfChrSameFloorDistanceToPadLessThan'])
        self.emit_bnez_label(params[5])

    def ai_if_chr_shield_damaged(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfShieldDamaged'])
        self.emit_bnez_label(params[1])

    def ai_if_chr_shield_lt(self, params):
        if params[0] == 0xfd:
            self.emit('lwc1', ['$f0', self.chr_field('cshield')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiGetChrShield'])
        self.emit('li.s', ['$f2', self.u16(params, 1) / 10])
        self.emit('c.lt.s', ['$f0', '$f2'])
        self.emit('bc1t', [self.label_name(params[3])])

    def ai_if_chr_soundtimer(self, params):
        self.emit('lw', ['$v0', self.chr_field('soundtimer')])
        self.emit('li', ['$v1', self.u16(params, 0)])
        if params[2] == 0:
            self.emit('bgt', ['$v0', '$v1', self.label_name(params[3])])
        else:
            self.emit('blt', ['$v0', '$v1', self.label_name(params[3])])

    def ai_if_chr_stopped(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrIsStopped'])
        self.emit_bnez_label(params[0])

    def ai_if_chr_target_eq(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfChrTarget'])
        self.emit_bnez_label(params[3])

    def ai_if_chr_weapon_equipped(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfChrHasWeaponEquipped'])
        self.emit_bnez_label(params[2])

    def ai_if_chr_y(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li.s', ['$a2', self.s16(params, 1)])
        self.emit('jal', ['aiIfChrYGreaterThan' if params[3] else 'aiIfChrYLessThan'])
        self.emit_bnez_label(params[4])

    def ai_if_chrpresets_target_is_different(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfPresetsTargetIsNotMyTarget'])
        self.emit_bnez_label(params[0])

    def ai_if_controller_button_pressed(self, params):
        self.emit('jal', ['aiIfCutsceneButtonPressed'])
        self.emit_bnez_label(params[0])

    def ai_if_coop_mode(self, params):
        self.emit('jal', ['aiIfCoopMode'])
        self.emit_bnez_label(params[0])

    def ai_if_countdown_timer_gt(self, params):
        self.emit('jal', ['aiIfCountdownTimerExpired'])
        self.emit_beqz_label(params[2])

    def ai_if_countdown_timer_lt(self, params):
        self.emit('jal', ['aiIfCountdownTimerExpired'])
        self.emit_bnez_label(params[2])

    def ai_if_dangerous_object_nearby(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrDetectDangerousObject'])
        self.emit_bnez_label(params[1])

    def ai_if_detected_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['ai0045'])
        self.emit_bnez_label(params[1])

    def ai_if_difficulty_gt(self, params):
        self.emit('lui', ['$a0', '%hi(g_Difficulty)'])
        self.emit('lw', ['$v0', '%lo(g_Difficulty)($a0)'])
        if params[0] == 0:
            self.emit('bnez', ['$v0', self.label_name(params[1])])
        else:
            self.emit('li', ['$v1', params[0]])
            self.emit('bgt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_difficulty_lt(self, params):
        self.emit('lui', ['$a0', '%hi(g_Difficulty)'])
        self.emit('lw', ['$v0', '%lo(g_Difficulty)($a0)'])
        if params[0] == 1:
            self.emit('beqz', ['$v0', self.label_name(params[1])])
        else:
            self.emit('li', ['$v1', params[0]])
            self.emit('blt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_distance_from_target_to_pad_gt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['chrGetDistanceFromTargetToPad'])
        self.emit('li.s', ['$f2', self.u16(params, 0) * 10])
        self.emit('c.le.s', ['$f0', '$f2'])
        self.emit('bc1f', [self.label_name(params[4])])

    def ai_if_distance_from_target_to_pad_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['chrGetDistanceFromTargetToPad'])
        self.emit('li.s', ['$f2', self.u16(params, 0) * 10])
        self.emit('c.lt.s', ['$f0', '$f2'])
        self.emit('bc1t', [self.label_name(params[4])])

    def ai_if_distance_to_chr_gt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[2]])
        self.emit('jal', ['chrGetDistanceToChr'])
        self.emit('li.s', ['$f2', self.u16(params, 0) * 10])
        self.emit('c.le.s', ['$f0', '$f2'])
        self.emit('bc1f', [self.label_name(params[3])])

    def ai_if_distance_to_chr_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[2]])
        self.emit('jal', ['chrGetDistanceToChr'])
        self.emit('li.s', ['$f2', self.u16(params, 0) * 10])
        self.emit('c.lt.s', ['$f0', '$f2'])
        self.emit('bc1t', [self.label_name(params[3])])

    def ai_if_distance_to_gun_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li.s', ['$a1', self.u16(params, 0) * 10])
        self.emit('jal', ['aiIfDistanceToGunLessThan'])
        self.emit_bnez_label(params[2])

    def ai_if_distance_to_target_gt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrGetDistanceToTarget'])
        self.emit('li.s', ['$f2', self.u16(params, 0) * 10])
        self.emit('c.le.s', ['$f0', '$f2'])
        self.emit('bc1f', [self.label_name(params[2])])

    def ai_if_distance_to_target_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrGetDistanceToTarget'])
        self.emit('li.s', ['$f2', self.u16(params, 0) * 10])
        self.emit('c.lt.s', ['$f0', '$f2'])
        self.emit('bc1t', [self.label_name(params[2])])

    def ai_if_door_locked(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfDoorLocked'])
        self.emit_bnez_label(params[2])

    def ai_if_door_state(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfDoorState'])
        self.emit_bnez_label(params[2])

    def ai_if_enemy_distance_lt_and_los(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li.s', ['$a1', params[0] * 10])
        self.emit('jal', ['aiDetectEnemy'])
        self.emit_bnez_label(params[1])

    def ai_if_force_walk_finished(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfAutoWalkFinished'])
        self.emit_bnez_label(params[1])

    def ai_if_fov_check_with_target(self, params):
        if params[2]:
            self.emit('move', ['$a0', '$s0'])
            self.emit('jal', ['aiIfCheckFovWithTarget2'])
        elif params[1]:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiIfCheckFovWithTarget1'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiIfCheckFovWithTarget0'])
        self.emit_bnez_label(params[3])

    def ai_if_gun_unclaimed(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfGunUnclaimed'])
        self.emit_bnez_label(params[2]) # not a wrong index

    def ai_if_has_gun(self, params):
        if params[0] == 0xfd:
            self.emit('lw', ['$v0', self.chr_field('gunprop')])
            self.emit_beqz_label(params[2]) # not a wrong index
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiIfChrHasGun'])
            self.emit_bnez_label(params[2]) # not a wrong index

    def ai_if_has_orders(self, params):
        self.emit('lbu', ['$v0', self.chr_field('orders')])
        self.emit_bnez_label(params[0])

    def ai_if_heard_target_recently(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrHeardTargetRecently'])
        self.emit_bnez_label(params[0])

    def ai_if_hears_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrIsHearingTarget'])
        self.emit_bnez_label(params[0])

    def ai_if_hoverbot_next_step(self, params):
        self.emit('jal', ['aiGetHoverbotNextStep'])
        self.emit('li', ['$v1', params[1]])
        if params[0] == 1:
            self.emit('bgt', ['$v0', '$v1', self.label_name(params[2])])
        else:
            self.emit('blt', ['$v0', '$v1', self.label_name(params[2])])

    def ai_if_just_injured(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIfInjured'])
        self.emit_bnez_label(params[1])

    def ai_if_kill_count_gt(self, params):
        self.emit('jal', ['aiGetKillCount'])
        if params[0] == 0:
            self.emit('bgtz', ['$v0', self.label_name(params[1])])
        else:
            self.emit('li', ['$v1', params[0]])
            self.emit('bgt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_lift_stationary(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiIfLiftStationary'])
        self.emit_bnez_label(params[1])

    def ai_if_morale_lt(self, params):
        self.emit('lbu', ['$v0', self.chr_field('morale')])
        self.emit('li', ['$v1', params[0]])
        self.emit('blt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_music_event_queue_empty(self, params):
        self.emit('lui', ['$a0', '%hi(g_MusicEventQueueLength)'])
        self.emit('lw', ['$v0', '%lo(g_MusicEventQueueLength)($a0)'])
        self.emit_beqz_label(params[1])

    def ai_if_near_miss(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrResetNearMiss'])
        self.emit_bnez_label(params[0])

    def ai_if_nearly_in_targets_sight(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', self.u32(params, 0)])
        self.emit('jal', ['chrIsNearlyInTargetsSight'])
        self.emit_bnez_label(params[4])

    def ai_if_never_been_onscreen(self, params):
        self.emit('lw', ['$v0', self.chr_field('chrflags')])
        self.emit('andi', ['$v0', '$v0', 8])
        self.emit_beqz_label(params[0])

    def ai_if_num_chrs_in_squadron_gt(self, params):
        self.emit('li', ['$a0', params[1]])
        self.emit('jal', ['aiGetNumChrsInSquadron'])
        self.emit('li', ['$v1', params[0]])
        self.emit('bgt', ['$v0', '$v1', self.label_name(params[2])])

    def ai_if_num_human_players_lt(self, params):
        self.emit('jal', ['aiGetNumPlayers'])
        self.emit('li', ['$v1', params[0]])
        self.emit('blt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_num_subdued(self, params):
        self.emit('jal', ['mpstatsGetTotalKnockoutCount'])
        if params[0] == 0 and params[1] == 0: # checking if > 0
            self.emit('bnez', ['$v0', self.label_name(params[2])])
        elif params[0] == 1 and params[1] == 1: # checking if < 1
            self.emit('beqz', ['$v0', self.label_name(params[2])])
        else:
            raise NotImplementedError

    def ai_if_num_times_shot_gt(self, params):
        self.emit('lb', ['$v0', self.chr_field('numarghs')])
        self.emit('bnez', ['$v0', self.label_name(params[1])])

    def ai_if_num_times_shot_lt(self, params):
        self.emit('lb', ['$v0', self.chr_field('numarghs')])
        self.emit('beqz', ['$v0', self.label_name(params[1])])

    def ai_if_object_distance_to_pad_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 3)])
        self.emit('li.s', ['$a3', self.u16(params, 1) * 10])
        self.emit('jal', ['aiIfObjectDistanceToPadLessThan'])
        self.emit_bnez_label(params[5])

    def ai_if_object_flag2(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiIfObjHasFlag2'])
        self.emit_bnez_label(params[5])

    def ai_if_object_flag3(self, params):
        raise NotImplementedError

    def ai_if_object_health_lt(self, params):
        # Actually "if object damage taken is less than"
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiGetObjDamage'])
        self.emit('li', ['$v1', self.u16(params, 1)])
        self.emit('blt', ['$v0', '$v1', self.label_name(params[3])])

    def ai_if_object_in_good_condition(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiIfObjectHealthy'])
        self.emit_bnez_label(params[1])

    def ai_if_object_in_room(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 1)])
        self.emit('jal', ['aiIfObjectInRoom'])
        self.emit_bnez_label(params[3])

    def ai_if_objective_complete(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiIfObjectiveComplete'])
        self.emit_bnez_label(params[1])

    def ai_if_objective_failed(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['aiIfObjectiveFailed'])
        self.emit_bnez_label(params[1])

    def ai_if_onscreen(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfOnScreen'])
        self.emit_bnez_label(params[0])

    def ai_if_orders_eq(self, params):
        self.emit('lbu', ['$v0', self.chr_field('orders')])
        self.emit('li', ['$v1', '0x%02x' % params[1]])
        self.emit('beq', ['$v0', '$v1', self.label_name(params[2])])

    def ai_if_patrolling(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfPatrolling'])
        self.emit_bnez_label(params[0])

    def ai_if_player_using_cmp150_or_ar34(self, params):
        self.emit('jal', ['aiIfPlayerUsingCmpOrAr34'])
        self.emit_bnez_label(params[0])

    def ai_if_player_using_device(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfPlayerUsingDevice'])
        self.emit_bnez_label(params[2])

    def ai_if_rand_gt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiGetRandom'])
        self.emit('li', ['$v1', params[0]])
        self.emit('bgt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_rand_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiGetRandom'])
        self.emit('li', ['$v1', params[0]])
        self.emit('blt', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_room_onscreen(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['aiIfRoomIsOnScreen'])
        self.emit_bnez_label(params[2])

    def ai_if_savefile_flag_is_set(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['gamefileHasFlag'])
        self.emit_bnez_label(params[1])

    def ai_if_savefile_flag_is_unset(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['gamefileHasFlag'])
        self.emit_beqz_label(params[1])

    def ai_if_saw_death(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['chrSawDeath'])
        self.emit_bnez_label(params[1])

    def ai_if_saw_injury(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['chrSawInjury'])
        self.emit_bnez_label(params[1])

    def ai_if_sees_suspicious_item(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfSeesSuspiciousItem'])
        self.emit_bnez_label(params[0])

    def ai_if_self_flag_bankx_eq(self, params):
        flag = self.u32(params, 0)
        fieldname = 'flags' if params[5] == 0 else 'flags2'
        self.emit('lw', ['$v0', self.chr_field(fieldname)])
        if params[4] == 0:
            self.emit_not_has_flag('$v0', flag, params[6])
        else:
            self.emit_has_flag('$v0', flag, params[6])

    def ai_if_self_has_chrflag(self, params):
        flag = self.u32(params, 0)
        self.emit('lw', ['$v0', self.chr_field('chrflags')])
        self.emit_has_flag('$v0', flag, params[4])

    def ai_if_sound_finished(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['audioIsChannelIdle'])
        self.emit_bnez_label(params[1])

    def ai_if_stage_flag_eq(self, params):
        flag = self.u32(params, 0)
        self.emit('lui', ['$a0', '%hi(g_StageFlags)'])
        self.emit('lw', ['$v0', '%lo(g_StageFlags)($a0)'])
        if params[4] == 0:
            self.emit_not_has_flag('$v0', flag, params[5])
        else:
            self.emit_has_flag('$v0', flag, params[5])

    def ai_if_stage_is_not(self, params):
        self.emit('lui', ['$v0', '%hi(g_StageNum)'])
        self.emit('lw', ['$v0', '%lo(g_StageNum)($v0)'])
        self.emit('li', ['$v1', params[0]])
        self.emit('bne', ['$v0', '$v1', self.label_name(params[1])])

    def ai_if_target_in_fov(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('move', ['$a2', '$zero'])
        self.emit('jal', ['chrIsTargetInFov'])
        self.emit_bnez_label(params[1])

    def ai_if_target_in_fov_left(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrGetAngleToTarget'])
        self.emit('li.s', ['$f2', params[0] * 3.141092641 * 2 * 0.00390625])
        self.emit('c.lt.s', ['$f0', '$f2'])
        self.emit('bc1t', [self.label_name(params[1])])

    def ai_if_target_in_sight(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrCheckTargetInSight'])
        self.emit_bnez_label(params[0])

    def ai_if_target_is_player(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfTargetIsPlayer'])
        self.emit_bnez_label(params[0])

    def ai_if_target_moving_away(self, params):
        # follow label if return value > 50
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrGetDistanceLostToTargetInLastSecond'])
        self.emit('li.s', ['$f2', 50])
        self.emit('c.lt.s', ['$f2', '$f0'])
        self.emit('bc1t', [self.label_name(params[0])])

    def ai_if_target_moving_closer(self, params):
        # follow label if return value < -50
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrGetDistanceLostToTargetInLastSecond'])
        self.emit('li.s', ['$f2', -50])
        self.emit('c.lt.s', ['$f0', '$f2'])
        self.emit('bc1t', [self.label_name(params[0])])

    def ai_if_target_moving_slowly(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiIfTargetMovingSlowly'])
        self.emit_bnez_label(params[1])

    def ai_if_target_out_of_fov_left(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrGetAngleToTarget'])
        self.emit('li.s', ['$f2', params[0] * 3.141092641 * 2 * 0.00390625])
        self.emit('c.le.s', ['$f0', '$f2'])
        self.emit('bc1f', [self.label_name(params[1])])

    def ai_if_teleport_full_white(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfChrTeleportFullWhite'])
        self.emit_bnez_label(params[0])

    def ai_if_timer_gt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiGetTimer'])
        self.emit('li', ['$v1', self.u16(params, 1)])
        self.emit('bgt', ['$v0', '$v1', self.label_name(params[3])])

    def ai_if_timer_lt(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiGetTimer'])
        self.emit('li', ['$v1', self.u16(params, 1)])
        self.emit('blt', ['$v0', '$v1', self.label_name(params[3])])

    def ai_if_training_pc_holographed(self, params):
        self.emit('jal', ['aiIfTrainingPcHolographed'])
        self.emit_bnez_label(params[0])

    def ai_if_weapon_thrown(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['weaponFindLanded'])
        self.emit_bnez_label(params[1])

    def ai_if_weapon_thrown_on_object(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiIfWeaponThrownOnObject'])
        self.emit_bnez_label(params[2])

    def ai_increase_chr_alertness(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('li', ['$a2', '0x%02x' % params[0]])
        self.emit('jal', ['aiChrAddAlertness'])

    def ai_increase_self_alertness(self, params):
        self.emit('addiu', ['$a0', '$s0', self.chr_field_offset('alertness')])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['incrementByte'])

    def ai_increase_squadron_alertness(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiIncreaseSquadronAlertness'])

    def ai_infloop(self, params):
        self.emit_raw('.infloop:')
        self.emit('b', ['.infloop'])

    def ai_jog_to_pad(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['aiJogToPad'])

    def ai_kill(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['aiChrKill'])

    def ai_kneel(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTryKneel'])

    def ai_label(self, params):
        label_id = params[0]
        if label_id not in self.labels:
            self.labels[label_id] = -1
        self.labels[label_id] += 1
        index = self.labels[label_id]
        self.emit_raw('%s:' % self.label_name(label_id, index))

    def ai_lock_door(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiLockDoor'])

    def ai_miniskedar_try_pounce(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiMiniSkedarTryPounce'])
        self.emit_bnez_label(params[4])

    def ai_move_object_to_pad(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 1)])
        self.emit('jal', ['aiObjectMoveToPad'])

    def ai_mp_init_simulants(self, params):
        self.emit('jal', ['botSpawnAll'])

    def ai_mute_channel(self, params):
        self.emit('li', ['$a0', self.s8(params[0])])
        self.emit('jal', ['audioMuteChannel'])

    def ai_object_do_animation(self, params):
        self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a1', '0x%02x' % params[2]])
        self.emit('li', ['$a2', self.s8(params[3])])
        self.emit('li', ['$a3', '0x%04x' % self.u16(params, 4)])
        self.emit('jal', ['aiObjectDoAnimation'])

    def ai_object_set_modelpart_visible(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('li', ['$a2', '0x%02x' % params[2]])
        self.emit('jal', ['aiObjSetModelPartVisible'])

    def ai_open_door(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiOpenDoor'])

    def ai_passive_mode(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['bgunSetPassiveMode'])

    def ai_pause_timer(self, params):
        self.emit('lw', ['$v0', self.chr_field('hidden')])
        self.emit_set_flag('$v0', 0x40)
        self.emit('sw', ['$v0', self.chr_field('hidden')])

    def ai_play_cistaff_quip(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', str(params[0])])
        self.emit('li', ['$a2', str(self.s8(params[1]))])
        self.emit('jal', ['aiSayCiStaffQuip'])

    def ai_play_cutscene_track(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['musicStartCutscene'])

    def ai_play_default_tracks(self, params):
        self.emit('jal', ['musicPlayDefaultTracks'])

    def ai_play_music_continuously(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['musicStartTemporaryPrimary'])

    def ai_play_sound(self, params):
        self.emit('li', ['$a0', self.s8(params[2])])
        self.emit('li', ['$a1', self.s16(params, 0)])
        self.emit('li', ['$a2', '0'])
        self.emit('li', ['$a3', '0'])
        self.emit_store_to_stack(0x10, 0)
        self.emit_store_to_stack(0x14, 0)
        self.emit('jal', ['audioPlayFromProp'])

    def ai_play_sound_from_entity(self, params):
        if params[8] == 0:
            self.emit('li', ['$a0', self.s8(params[0])])
            self.emit('li', ['$a1', params[1]])
            self.emit('li', ['$a2', '0x%04x' % self.u16(params, 4)])
            self.emit('li', ['$a3', '0x%04x' % self.u16(params, 6)])
            self.emit('jal', ['aiPlaySoundFromObj'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', params[1]])
            self.emit('li', ['$a2', self.s8(params[0])])
            self.emit('li', ['$a3', '0x%04x' % self.u16(params, 4)])
            self.emit_store_to_stack(0x10, '0x%04x' % self.u16(params, 6))
            self.emit('jal', ['aiPlaySoundFromChr'])

    def ai_play_sound_from_object(self, params):
        self.emit('li', ['$a0', self.s8(params[0])])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('li', ['$a3', '0x%04x' % self.u16(params, 4)])
        self.emit_store_to_stack(0x10, self.u16(params, 6))
        self.emit('jal', ['ai016b'])

    def ai_play_sound_from_object2(self, params):
        # We use params[8] twice because that's what the original game does
        self.emit('li', ['$a0', self.s8(params[0])])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('li', ['$a3', params[6]])
        self.emit_store_to_stack(0x10, (params[8] << 8) | params[8])
        self.emit('jal', ['aiPlaySoundFromProp'])

    def ai_play_sound_from_pad(self, params):
        self.emit('li', ['$a0', self.u16(params, 1)])
        self.emit('li', ['$a1', self.u16(params, 3)])
        self.emit('jal', ['ai00d0'])

    def ai_play_temporary_track(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['musicStartTemporaryAmbient'])

    def ai_play_track_isolated(self, params):
        if params[0] == 101: # MUSIC_CI_TRAINING
            self.emit('jal', ['musicGetVolume'])
            self.emit('sw', ['$v0', '0x10($sp)'])
            self.emit('li', ['$a0', params[0]])
            self.emit('jal', ['musicPlayTrackIsolated'])
            self.emit('lw', ['$a0', '0x10($sp)'])
            self.emit('jal', ['musicSetVolume'])
        else:
            self.emit('li', ['$a0', params[0]])
            self.emit('jal', ['musicPlayTrackIsolated'])

    def ai_play_x_track(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('li', ['$a1', params[1]])
        self.emit('li', ['$a2', params[2]])
        self.emit('jal', ['musicSetXReason'])

    def ai_rebuild_squadrons(self, params):
        self.emit('jal', ['rebuildSquadrons'])

    def ai_rebuild_teams(self, params):
        self.emit('jal', ['rebuildTeams'])

    def ai_release_grabbed_object(self, params):
        self.emit('move', ['$a0', '$zero'])
        self.emit('jal', ['bmoveSetModeForAllPlayers'])

    def ai_remove_chr(self, params):
        if params[0] == 0xfd:
            self.emit('lw', ['$v0', self.chr_field('hidden')])
            self.emit_set_flag('$v0', 0x20)
            self.emit('sw', ['$v0', self.chr_field('hidden')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('jal', ['aiRemoveChr'])

    def ai_remove_references_to_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiRemoveReferencesToChr'])

    def ai_remove_weapon_from_inventory(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['invRemoveItemByNum'])

    def ai_reset_timer(self, params):
        self.emit('sw', ['$zero', self.chr_field('timer60')])

    def ai_restart_timer(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiRestartTimer'])

    def ai_resume_timer(self, params):
        self.emit('lw', ['$v0', self.chr_field('hidden')])
        self.emit_set_flag('$v0', 0x40)
        self.emit('sw', ['$v0', self.chr_field('hidden')])

    def ai_retreat(self, params):
        self.emit('move', ['$a0', '$s0'])
        if params[1] == 1:
            self.emit('jal', ['aiRetreatFromTarget'])
        else:
            self.emit('jal', ['aiRetreatToCover'])

    def ai_return(self, params):
        # If aiReturn returns a pointer (common case) then follow it, otherwise terminate
        label = self.temp_label()
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiReturn'])
        self.emit('beqz', ['$v0', label])
        self.emit('jr', ['$v0'])
        self.emit_raw('%s:' % label)
        self.emit('jal', ['aiTerminate'])

    def ai_revoke_control(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('jal', ['aiRevokeControl'])

    def ai_run_from_grenade(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['ai013e'])

    def ai_run_to_pad(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['aiRunToPad'])

    def ai_say_quip(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('li', ['$a3', '0x%02x' % params[2]])
        self.emit_store_to_stack(0x10, '0x%02x' % params[3])
        self.emit_store_to_stack(0x14, params[4])
        self.emit_store_to_stack(0x18, params[5])
        self.emit_store_to_stack(0x1c, params[6])
        self.emit_store_to_stack(0x20, params[7])
        self.emit('jal', ['aiSayQuip'])

    def ai_set_accuracy(self, params):
        if params[0] == 0:
            self.emit('sb', ['$zero', self.chr_field('accuracyrating')])
        else:
            self.emit('li', ['$v0', self.s8(params[0])])
            self.emit('sb', ['$v0', self.chr_field('accuracyrating')])

    def ai_set_action(self, params):
        self.emit('li', ['$v0', params[0]])
        self.emit('sb', ['$v0', self.chr_field('myaction')])
        if params[1] == 0:
            self.emit('sb', ['$zero', self.chr_field('orders')])

    def ai_set_ailist(self, params):
        if params[0] == 0xfd:
            self.emit('move', ['$a0', '$s0'])
            self.emit('la', ['$a1', self.ailist_name(self.u16(params, 1))])
            self.emit('move', ['$ra', '$a1'])
            self.emit('j', ['aiSetMyList'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('la', ['$a2', self.ailist_name(self.u16(params, 1))])
            self.emit('jal', ['aiSetChrList'])

    def ai_set_aishootingatmelist(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('la', ['$a1', self.ailist_name(self.u16(params, 0))])
        self.emit('jal', ['aiSetShootingAtMeList'])

    def ai_set_alertness(self, params):
        self.emit('li', ['$v0', params[0]])
        self.emit('sb', ['$v0', self.chr_field('alertness')])

    def ai_set_autogun_target_team(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('li', ['$a1', params[1]])
        self.emit('jal', ['aiSetAutogunTargetTeam'])

    def ai_set_chr_chrflag(self, params):
        if params[0] == 0xfd:
            self.emit('lw', ['$v0', self.chr_field('chrflags')])
            self.emit_set_flag('$v0', self.u32(params, 1))
            self.emit('sw', ['$v0', self.chr_field('chrflags')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
            self.emit('jal', ['aiChrSetChrflag'])

    def ai_set_chr_cloaked(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('li', ['$a3', params[2]])
        self.emit('jal', ['aiChrSetCloaked'])

    def ai_set_chr_dodge_rating(self, params):
        if params[1] == 0:
            src_reg = '$zero'
        else:
            self.emit('li', ['$v0', params[1]])
            src_reg = '$v0'

        if params[1] == 0:
            self.emit('sb', [src_reg, self.chr_field('dodgerating')])
        elif params[1] == 1:
            self.emit('sb', [src_reg, self.chr_field('maxdodgerating')])
        else:
            self.emit('sb', [src_reg, self.chr_field('dodgerating')])
            self.emit('sb', [src_reg, self.chr_field('maxdodgerating')])

    def ai_set_chr_flag_bankx(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
        self.emit('li', ['$a3', params[5]])
        self.emit('jal', ['chrSetFlagsById'])

    def ai_set_chr_hiddenflag(self, params):
        if params[0] == 0xfd:
            self.emit('lw', ['$v0', self.chr_field('hidden')])
            self.emit_set_flag('$v0', self.u32(params, 1))
            self.emit('sw', ['$v0', self.chr_field('hidden')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
            self.emit('jal', ['aiChrSetHiddenFlag'])

    def ai_set_chr_hudpiece_visible(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('jal', ['aiSetChrHudpieceVisible'])

    def ai_set_chr_id(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['chrSetChrnum'])

    def ai_set_chr_maxdamage(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li.s', ['$a2', self.u16(params, 1) / 10])
        self.emit('jal', ['aiSetMaxDamage'])

    def ai_set_chr_roomtosearch(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiSetRoomToSearch'])

    def ai_set_chr_shooting_in_cutscene(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('jal', ['aiChrSetFiringInCutscene'])

    def ai_set_chr_special_death_animation(self, params):
        if params[0] == 0xfd:
            self.emit('li', ['$v0', '0x%02x' % params[1]])
            self.emit('sb', ['$v0', self.chr_field('specialdie')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%02x' % params[1]])
            self.emit('jal', ['aiSetChrSpecialDeathAnimation'])

    def ai_set_chr_target_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('jal', ['chrSetChrPresetByChrnum'])

    def ai_set_chr_team(self, params):
        if params[0] == 0xfd:
            self.emit('li', ['$v0', params[1]])
            self.emit('sb', ['$v0', self.chr_field('team')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%02x' % params[1]])
            self.emit('jal', ['aiChrSetTeam'])

    def ai_set_chrpreset(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['chrSetChrPreset'])

    def ai_set_countdown_timer(self, params):
        self.emit('li.s', ['$f2', self.u16(params, 0) * 60])
        self.emit('lui', ['$a0', '%hi(g_CountdownTimerValue60)'])
        self.emit('swc1', ['$f2', '%lo(g_CountdownTimerValue60)($a0)'])

    def ai_set_cutscene_weapon(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%02x' % params[1]])
        self.emit('li', ['$a3', '0x%02x' % params[2]])
        self.emit('jal', ['aiChrSetCutsceneWeapon'])

    def ai_set_darkroomlist(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('la', ['$a1', self.ailist_name(self.u16(params, 0))])
        self.emit('jal', ['aiSetDarkRoomList'])

    def ai_set_door_open(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['aiSetDoorOpen'])

    def ai_set_drcaroll_images(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('li', ['$a3', params[2]])
        self.emit('jal', ['aiSetDrCarollImages'])

    def ai_set_grenade_probability_out_of_255(self, params):
        self.emit('li', ['$v0', params[0]])
        self.emit('sb', ['$v0', self.chr_field('grenadeprob')])

    def ai_set_hear_distance(self, params):
        self.emit('li.s', ['$f0', self.u16(params, 0) / 1000])
        self.emit('swc1', ['$f0', self.chr_field('hearingscale')])

    def ai_set_invincible(self, params):
        self.emit('li', ['$v0', '1'])
        self.emit('lui', ['$a0', '%hi(g_PlayerInvincible)'])
        self.emit('sw', ['$v0', '%lo(g_PlayerInvincible)($a0)'])

    def ai_set_lights_state(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', params[2]])
        self.emit('li', ['$a3', params[3]])
        self.emit_store_to_stack(0x10, params[4])
        self.emit_store_to_stack(0x14, params[5])
        self.emit('jal', ['aiSetLights'])

    def ai_set_morale(self, params):
        if params[0] == 0:
            src_reg = '$zero'
        else:
            self.emit('li', ['$v0', params[0]])
            src_reg = '$v0'
        self.emit('sb', [src_reg, self.chr_field('morale')])

    def ai_set_object_flag(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiSetObjFlag'])

    def ai_set_object_flag2(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiSetObjFlag2'])

    def ai_set_object_flag3(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiSetObjFlag3'])

    def ai_set_object_health(self, params):
        # Actually "set object damage"
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', self.u16(params, 1)])
        self.emit('jal', ['aiSetObjDamage'])

    def ai_set_object_image(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('li', ['$a2', '0x%02x' % params[2]])
        self.emit('jal', ['aiSetObjImage'])

    def ai_set_pad_preset_to_investigation_terminal(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiSetPadPresetToInvestigationTerminal'])

    def ai_set_padpreset(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['aiSetPadPreset'])

    def ai_set_portal_flag(self, params):
        self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a1', '0x%02x' % params[2]])
        self.emit('jal', ['aiSetPortalFlag'])

    def ai_set_reaction_speed(self, params):
        if params[0] == 0:
            src_reg = '$zero'
        else:
            self.emit('li', ['$v0', self.s8(params[0])])
            src_reg = '$v0'
        self.emit('sb', [src_reg, self.chr_field('speedrating')])

    def ai_set_recovery_speed(self, params):
        if params[0] == 0:
            src_reg = '$zero'
        else:
            self.emit('li', ['$v0', self.s8(params[0])])
            src_reg = '$v0'
        self.emit('sb', [src_reg, self.chr_field('arghrating')])

    def ai_set_returnlist(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('la', ['$a2', self.ailist_name(self.u16(params, 1))])
        self.emit('jal', ['aiSetReturnList'])

    def ai_set_room_flag(self, params):
        self.emit('li', ['$a0', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['aiSetRoomFlag'])

    def ai_set_rotor_speed(self, params):
        raise NotImplementedError

    def ai_set_savefile_flag(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['gamefileSetFlag'])

    def ai_set_self_chrflag(self, params):
        self.emit('lw', ['$v0', self.chr_field('chrflags')])
        self.emit_set_flag('$v0', self.u32(params, 0))
        self.emit('sw', ['$v0', self.chr_field('chrflags')])

    def ai_set_self_flag_bankx(self, params):
        field = 'flags' if params[4] == 0 else 'flags2'
        self.emit('lw', ['$v0', self.chr_field(field)])
        self.emit_set_flag('$v0', self.u32(params, 0))
        self.emit('sw', ['$v0', self.chr_field(field)])

    def ai_set_shield(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li.s', ['$a1', self.u16(params, 0) / 10])
        self.emit('jal', ['aiSetShield'])

    def ai_set_shotlist(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('la', ['$a1', self.ailist_name(self.u16(params, 0))])
        self.emit('jal', ['aiSetShotList'])

    def ai_set_squadron(self, params):
        if params[0] == 0:
            src_reg = '$zero'
        else:
            self.emit('li', ['$v0', params[0]])
            src_reg = '$v0'
        self.emit('sb', [src_reg, self.chr_field('squadron')])

    def ai_set_stage_flag(self, params):
        self.emit('li', ['$a0', self.u32(params, 0)])
        self.emit('jal', ['aiSetStageFlag'])

    def ai_set_target_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiSetTargetChr'])

    def ai_set_target_to_camspy_if_in_sight(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiSetTargetToEyespyIfInSight'])
        self.emit_bnez_label(params[0])

    def ai_set_target_to_enemy_on_same_floor(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiDetectEnemyOnSameFloor'])
        self.emit_bnez_label(params[0])

    def ai_set_team_orders(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiSetTeamOrders'])

    def ai_set_tinted_glass_enabled(self, params):
        self.emit('li', ['$v0', params[0]])
        self.emit('lui', ['$a0', '%hi(g_TintedGlassEnabled)'])
        self.emit('sw', ['$v0', '%lo(g_TintedGlassEnabled)($a0)'])

    def ai_set_unarmeddodgerating(self, params):
        if params[0] == 0:
            src_reg = '$zero'
        else:
            self.emit('li', ['$v0', self.s8(params[0])])
            src_reg = '$v0'
        self.emit('sb', [src_reg, self.chr_field('unarmeddodgerating')])

    def ai_set_vehicle_speed(self, params):
        speedaim = self.u16(params, 0) * 100 / 15360
        speedtime = self.u16(params, 2)
        self.emit('li.s', ['$f12', speedaim])
        self.emit('li.s', ['$f14', speedtime])
        self.emit('jal', ['aiSetVehicleSpeed'])

    def ai_set_view_distance(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['aiSetViewDistance'])

    def ai_set_wind_speed(self, params):
        self.emit('li.s', ['$f2', self.s8(params[0]) / 10])
        self.emit('lui', ['$a0', '%hi(g_SkyWindSpeed)'])
        self.emit('swc1', ['$f2', '%lo(g_SkyWindSpeed)($a0)'])

    def ai_show_countdown_timer(self, params):
        self.emit('li', ['$a0', '1'])
        self.emit('li', ['$a1', '1'])
        self.emit('jal', ['countdownTimerSetVisible'])

    def ai_show_hudmsg(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 1)])
        self.emit('jal', ['aiShowHudmsg'])

    def ai_show_hudmsg_middle(self, params):
        if params[0] == 0:
            self.emit('li', ['$a0', '0x%04x' % self.u16(params, 2)])
            self.emit('jal', ['langGet'])
            self.emit('move', ['$a0', '$v0'])
            self.emit('li', ['$a1', '7'])
            self.emit('li', ['$a2', params[1]])
            self.emit('jal', ['hudmsgCreateWithColour'])
        elif params[0] == 1:
            self.emit('li', ['$a0', '0x%04x' % self.u16(params, 2)])
            self.emit('jal', ['langGet'])
            self.emit('move', ['$a0', '$v0'])
            self.emit('li', ['$a1', '8'])
            self.emit('li', ['$a2', params[1]])
            self.emit('jal', ['hudmsgCreateWithColour'])
        elif params[0] == 2:
            self.emit('jal', ['hudmsgRemoveAll'])

    def ai_show_hudmsg_top_middle(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 1)])
        self.emit('li', ['$a3', params[3]])
        self.emit('jal', ['aiShowHudmsgTopMiddle'])

    def ai_show_nonessential_chrs(self, params):
        self.emit('jal', ['aiShowCutsceneChrs' if params[0] else 'aiHideCutsceneChrs'])

    def ai_shuffle_investigation_terminals(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('li', ['$a1', params[1]])
        self.emit('li', ['$a2', params[2]])
        self.emit('li', ['$a3', params[3]])
        self.emit_store_to_stack(0x10, params[4])
        self.emit('jal', ['aiShuffleInvestigationTerminals'])

    def ai_shuffle_pelagic_switches(self, params):
        self.emit('jal', ['aiShufflePelagicSwitches'])

    def ai_shuffle_ruins_pillars(self, params):
        self.emit('jal', ['aiShuffleRuinsPillars'])

    def ai_speak(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', self.s16(params, 1)])
        self.emit('li', ['$a3', self.s16(params, 3)])
        self.emit_store_to_stack(0x10, params[5])
        self.emit_store_to_stack(0x14, params[6])
        self.emit('jal', ['aiSpeak'])

    def ai_start_countdown_timer(self, params):
        self.emit('li', ['$v1', '1'])
        self.emit('lui', ['$a0', '%hi(g_CountdownTimerRunning)'])
        self.emit('sw', ['$v1', '%lo(g_CountdownTimerRunning)($a0)'])

    def ai_start_patrol(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTryStartPatrol'])

    def ai_stop(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiStop'])

    def ai_stop_ambient_track(self, params):
        self.emit('jal', ['musicEndTemporaryAmbient'])

    def ai_stop_countdown_timer(self, params):
        self.emit('lui', ['$a0', '%hi(g_CountdownTimerRunning)'])
        self.emit('sw', ['$zero', '%lo(g_CountdownTimerRunning)($a0)'])

    def ai_stop_cutscene_track(self, params):
        self.emit('jal', ['musicEndCutscene'])

    def ai_stop_x_track(self, params):
        self.emit('li', ['$a0', params[0]])
        self.emit('jal', ['musicUnsetXReason'])

    def ai_subtract_morale(self, params):
        self.emit('addiu', ['$a0', '$s0', self.chr_field_offset('morale')])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['decrementByte'])

    def ai_surrender(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTrySurrender'])

    def ai_teleport_to_pad(self, params):
        pad = self.u16(params, 0)
        if pad:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', params[2]])
            self.emit('li', ['$a2', pad])
            self.emit('jal', ['aiChrBeginTeleport'])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', params[2]])
            self.emit('jal', ['aiChrEndTeleport'])

    def ai_terminate(self, params):
        self.emit('jal', ['aiTerminate'])

    def ai_try_attack_amount(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('li', ['$a2', params[1]])
        self.emit('jal', ['aiAttackAmount'])

    def ai_try_attack_kneel(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['chrTryAttackKneel'])
        self.emit_bnez_label(params[4])

    def ai_try_attack_lie(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['chrTryAttackLie'])
        self.emit_bnez_label(params[4])

    def ai_try_attack_roll(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTryAttackRoll'])
        self.emit_bnez_label(params[0])

    def ai_try_attack_stand(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['chrTryAttackStand'])
        self.emit_bnez_label(params[4])

    def ai_try_attack_walk(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTryAttackWalk'])
        self.emit_bnez_label(params[0])

    def ai_try_equip_weapon(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', '0x%02x' % params[2]])
        self.emit('li', ['$a3', '0x%08x' % self.u32(params, 3)])
        self.emit('jal', ['aiTryEquipWeapon'])
        self.emit_bnez_label(params[7])

    def ai_try_face_entity(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['chrFaceEntity'])
        self.emit_bnez_label(params[4])

    def ai_try_inherit_properties(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiChrCopyProperties'])
        self.emit_bnez_label(params[1])

    def ai_try_jog_to_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiTryJogToChr'])
        self.emit_bnez_label(params[1])

    def ai_try_jog_to_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiTryJogToTarget'])
        self.emit_bnez_label(params[0])

    def ai_try_jumpout(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTryJumpOut'])
        self.emit_bnez_label(params[0])

    def ai_try_modify_attack(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('li', ['$a2', '0x%04x' % self.u16(params, 2)])
        self.emit('jal', ['aiTryModifyAttack'])
        self.emit_bnez_label(params[4])

    def ai_try_punch_or_kick(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiTryMelee'])
        self.emit_bnez_label(params[1])

    def ai_try_run_sideways(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTryRunSideways'])
        self.emit_bnez_label(params[0])

    def ai_try_run_to_chr(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('jal', ['aiTryRunToChr'])
        self.emit_bnez_label(params[1])

    def ai_try_run_to_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiTryRunToTarget'])
        self.emit_bnez_label(params[0])

    def ai_try_set_chrpreset_to_unalerted_teammate(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiSetChrPresetToUnalertedTeammate'])
        self.emit_bnez_label(params[2])

    def ai_try_set_padpreset_to_target_quadrant(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['chrSetPadPresetToWaypointWithinTargetQuadrant'])
        self.emit_bnez_label(params[1])

    def ai_try_set_target_pad_to_something(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('jal', ['func0f04a4ec'])
        self.emit_bnez_label(params[1])

    def ai_try_sidestep(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['chrTrySidestep'])
        self.emit_bnez_label(params[0])

    def ai_try_spawn_chr_at_chr(self, params):
        raise NotImplementedError

    def ai_try_spawn_chr_at_pad(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', params[0]])
        self.emit('li', ['$a2', self.s8(params[1])])
        self.emit('li', ['$a3', '0x%04x' % self.u16(params, 2)])
        self.emit('la', ['$t0', self.ailist_name(self.u16(params, 4))])
        self.emit('sw', ['$t0', '0x10($sp)'])
        self.emit_store_to_stack(0x14, self.u32(params, 6))
        self.emit('jal', ['chrSpawnAtPad'])
        self.emit_bnez_label(params[10])

    def ai_try_spawn_clone2(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('la', ['$a2', self.ailist_name(self.u16(params, 1))])
        self.emit('li', ['$a3', '0x%08x' % self.u32(params, 3)])
        self.emit('jal', ['aiDuplicateChr'])
        self.emit_bnez_label(params[7])

    def ai_try_walk_to_target(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('jal', ['aiTryWalkToTarget'])
        self.emit_bnez_label(params[0])

    def ai_unlock_door(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%02x' % params[1]])
        self.emit('jal', ['aiUnlockDoor'])

    def ai_unset_chr_chrflag(self, params):
        if params[0] == 0xfd:
            self.emit('lw', ['$v0', self.chr_field('chrflags')])
            self.emit_unset_flag('$v0', self.u32(params, 1))
            self.emit('sw', ['$v0', self.chr_field('chrflags')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
            self.emit('jal', ['aiChrUnsetChrflag'])

    def ai_unset_chr_flag_bankx(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%02x' % params[0]])
        self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
        self.emit('li', ['$a3', params[5]])
        self.emit('jal', ['chrUnsetFlagsById'])

    def ai_unset_chr_hiddenflag(self, params):
        if params[0] == 0xfd:
            self.emit('lw', ['$v0', self.chr_field('hidden')])
            self.emit_unset_flag('$v0', self.u32(params, 1))
            self.emit('sw', ['$v0', self.chr_field('hidden')])
        else:
            self.emit('move', ['$a0', '$s0'])
            self.emit('li', ['$a1', '0x%02x' % params[0]])
            self.emit('li', ['$a2', '0x%08x' % self.u32(params, 1)])
            self.emit('jal', ['aiChrUnsetHiddenFlag'])

    def ai_unset_object_flag(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiUnsetObjFlag'])

    def ai_unset_object_flag2(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiUnsetObjFlag2'])

    def ai_unset_object_flag3(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('li', ['$a1', '0x%08x' % self.u32(params, 1)])
        self.emit('jal', ['aiUnsetObjFlag3'])

    def ai_unset_savefile_flag(self, params):
        self.emit('li', ['$a0', '0x%02x' % params[0]])
        self.emit('jal', ['gamefileUnsetFlag'])

    def ai_unset_self_chrflag(self, params):
        self.emit('lw', ['$v0', self.chr_field('chrflags')])
        self.emit_unset_flag('$v0', self.u32(params, 0))
        self.emit('sw', ['$v0', self.chr_field('chrflags')])

    def ai_unset_self_flag_bankx(self, params):
        field = 'flags' if params[4] == 0 else 'flags2'
        self.emit('lw', ['$v0', self.chr_field(field)])
        self.emit_unset_flag('$v0', self.u32(params, 0))
        self.emit('sw', ['$v0', self.chr_field(field)])

    def ai_unset_stage_flag(self, params):
        flag = self.u32(params, 0)
        self.emit('li', ['$a0', (~flag & 0xffffffff)])
        self.emit('jal', ['aiUnsetStageFlag'])

    def ai_walk_to_pad(self, params):
        self.emit('move', ['$a0', '$s0'])
        self.emit('li', ['$a1', '0x%04x' % self.u16(params, 0)])
        self.emit('jal', ['aiWalkToPad'])

    def ai_yield(self, params):
        self.emit('jal', ['aiYield'])

app = App()
app.run()
