# User configurable

ROMID ?= ntsc-final
PIRACYCHECKS ?= 1

QEMU_IRIX ?= tools/irix/qemu-irix
IRIX_ROOT ?= tools/irix/root

IDOCC ?= $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
IDOAS ?= $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/as

################################################################################

QEMUCC = $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
QEMUAS = $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/as

export ROMID

NTSC=0
PAL=0
JPN=0

ifeq ($(ROMID),ntsc-beta)
	NTSC=1
	VERSION=0
	PIRACYCHECKS=0
endif
ifeq ($(ROMID),ntsc-1.0)
	NTSC=1
	VERSION=1
endif
ifeq ($(ROMID),ntsc-final)
	NTSC=1
	VERSION=2
endif
ifeq ($(ROMID),pal-beta)
	PAL=1
	VERSION=3
endif
ifeq ($(ROMID),pal-final)
	PAL=1
	VERSION=4
endif
ifeq ($(ROMID),jpn-final)
	JPN=1
	VERSION=5
endif

A_DIR := src/assets/$(ROMID)
B_DIR := build/$(ROMID)
E_DIR := extracted/$(ROMID)

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
	# Debian, Ubuntu and Arch AUR
    TOOLCHAIN := mips-linux-gnu
else ifeq ($(shell type mips64-elf-ld >/dev/null 2>/dev/null; echo $$?), 0)
	# Arch AUR
    TOOLCHAIN := mips64-elf
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
    TOOLCHAIN := mips64-linux-gnu
else
    TOOLCHAIN := mips-elf
endif

MIPSISET := -mips2 -32
OPT_LVL := -O2
LOOPUNROLL := -Wo,-loopunroll,0

$(B_DIR)/lib/ultra/gu/frustum.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/gu/mtxutil.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/gu/ortho.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/conteepread.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/conteepwrite.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/contpfs.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/contramread.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/contramwrite.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/gbpakgetstatus.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/motor.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/pfschecker.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/pfsfreeblocks.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/pfsgetstatus.o: LOOPUNROLL :=

$(B_DIR)/lib/ultra/libc/ll.o: MIPSISET := -mips3 -o32
$(B_DIR)/lib/ultra/libc/llcvt.o: MIPSISET := -mips3 -32

# Note: Files that use -O3 must be compiled without the ASM processor, otherwise
# it introduces a race condition when using make -j because they create a
# temporary include-stdin.u file during compilation.
# For these files, see their explicit targets towards the end of this file.
$(B_DIR)/lib/lib_2fba0.o: OPT_LVL := -g
$(B_DIR)/lib/lib_30ce0.o: OPT_LVL := -g
$(B_DIR)/lib/lib_37b00.o: OPT_LVL := -g
$(B_DIR)/lib/lib_3a100.o: OPT_LVL := -g
$(B_DIR)/lib/lib_3d280.o: OPT_LVL := -g
$(B_DIR)/lib/lib_3e730.o: OPT_LVL := -g
$(B_DIR)/lib/lib_3e8c0.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/bnkf.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/cseq.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/csplayer.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/event.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/heap.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/syndelete.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/audio/synsetpriority.o: OPT_LVL := -g
$(B_DIR)/lib/ultra/gu/align.o: OPT_LVL := -O3
$(B_DIR)/lib/ultra/gu/frustum.o: OPT_LVL := -O3
$(B_DIR)/lib/ultra/gu/ortho.o: OPT_LVL := -O3
$(B_DIR)/lib/ultra/gu/scale.o: OPT_LVL := -O3
$(B_DIR)/lib/ultra/io/ai.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/aisetnextbuf.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/conteeplongread.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/contquery.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/controller.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/dpctr.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/pigetcmdq.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/pidma.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/si.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/sp.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/spsetpc.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/sptaskyielded.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/vi.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/viblack.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/vigetcurrframebuf.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/vigetnextframebuf.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/visetevent.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/visetmode.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/visetxscale.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/visetyscale.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/io/viswapbuf.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/libc/ll.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/libc/llcvt.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/atomic.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/createmesgqueue.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/destroythread.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/gettime.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/jammesg.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/recvmesg.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/resetglobalintmask.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/sendmesg.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/seteventmesg.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/setglobalintmask.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/setthreadpri.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/settimer.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/startthread.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/stopthread.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/stoptimer.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/thread.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/timerintr.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/virtualtophysical.o: OPT_LVL := -O1
$(B_DIR)/lib/ultra/os/yieldthread.o: OPT_LVL := -O1

ifeq ($(ROMID), ntsc-beta)
$(B_DIR)/lib/ultra/io/pfsisplug.o: OPT_LVL := -O1
endif

CFLAGS = -DVERSION=$(VERSION) \
	-DNTSC=$(NTSC) \
	-DPAL=$(PAL) \
	-DJPN=$(JPN) \
	-DPIRACYCHECKS=$(PIRACYCHECKS) \
	$(LOOPUNROLL) \
	-Wab,-r4300_mul \
	-non_shared \
	-Olimit 1000 \
	-G 0 \
	-Xcpluscomm \
	-woff 581,649,819,820,821,838,852 \
	-w2 \
	-I src/include \
	-I src/generated/$(ROMID) \
	$(OPT_LVL) \
	$(MIPSISET)

C_FILES := $(shell find src/lib src/game src/inflate -name '*.c')
S_FILES := $(shell find src/lib src/game -name '*.s')

# Create names such as $(B_DIR)/assets/files/PfooZ.
# These names (with .o added) will be dependenices for ld.
#
# There are two types of assets: Those which are generated for all versions from
# a single location in src, and those which are copied into each ROM version
# folder at src/assets/$(ROMID) folder. Currently the former is just setup and
# tile files.
ASSET_FILES := \
	$(patsubst $(A_DIR)/files/audio/%.mp3,        $(B_DIR)/assets/files/A%M,               $(shell find $(A_DIR)/files/audio -name '*.mp3')) \
	$(patsubst $(A_DIR)/files/chrs/%.bin,         $(B_DIR)/assets/files/C%Z,               $(shell find $(A_DIR)/files/chrs -name '*.bin')) \
	$(patsubst $(A_DIR)/files/guns/%.bin,         $(B_DIR)/assets/files/G%Z,               $(shell find $(A_DIR)/files/guns -name '*.bin')) \
	$(patsubst $(A_DIR)/files/props/%.bin,        $(B_DIR)/assets/files/P%Z,               $(shell find $(A_DIR)/files/props -name '*.bin')) \
	$(patsubst src/files/setup/%.c,               $(B_DIR)/assets/files/U%Z,               $(shell find src/files/setup -name '*.c')) \
	$(patsubst $(A_DIR)/files/setup/%.bin,        $(B_DIR)/assets/files/U%Z,               $(shell find $(A_DIR)/files/setup -name '*.bin')) \
	$(patsubst $(A_DIR)/files/bgdata/%.seg,       $(B_DIR)/assets/files/bgdata/%.seg,      $(shell find $(A_DIR)/files/bgdata -name '*.seg')) \
	$(patsubst src/files/bgdata/%_tiles.s,        $(B_DIR)/assets/files/bgdata/%_tilesZ,   $(shell find src/files/bgdata -name 'bg_*_tiles.s')) \
	$(patsubst $(A_DIR)/files/bgdata/%_tiles.bin, $(B_DIR)/assets/files/bgdata/%_tilesZ,   $(shell find $(A_DIR)/files/bgdata -name 'bg_*_tiles.bin')) \
	$(B_DIR)/assets/files/ob/ob_mid.seg.o

LANG_JSON_FILES := $(shell find $(A_DIR)/lang -name '*.json')
PADS_JSON_FILES := $(shell find $(A_DIR)/pads -name '*.json')

LANG_O_FILES := $(patsubst $(A_DIR)/lang/%.json, $(B_DIR)/assets/files/L%.o, $(LANG_JSON_FILES))
PADS_O_FILES := $(patsubst $(A_DIR)/pads/%.json, $(B_DIR)/assets/files/bgdata/bg_%_padsZ.o, $(PADS_JSON_FILES))

O_FILES := \
	$(patsubst src/%.c, $(B_DIR)/%.o, $(C_FILES)) \
	$(patsubst src/%.s, $(B_DIR)/%.o, $(S_FILES)) \
	$(patsubst %, %.o, $(ASSET_FILES)) \
	$(LANG_O_FILES) \
	$(PADS_O_FILES) \
	$(B_DIR)/bootloader.o \
	$(B_DIR)/assets/animations.o \
	$(B_DIR)/assets/copyrightZ.o \
	$(B_DIR)/assets/files/list.o \
	$(B_DIR)/firingrange.o \
	$(B_DIR)/assets/fonts/bankgothic.o \
	$(B_DIR)/assets/fonts/handelgothiclg.o \
	$(B_DIR)/assets/fonts/handelgothicmd.o \
	$(B_DIR)/assets/fonts/handelgothicsm.o \
	$(B_DIR)/assets/fonts/handelgothicxs.o \
	$(B_DIR)/assets/fonts/numeric.o \
	$(B_DIR)/assets/fonts/ocralg.o \
	$(B_DIR)/assets/fonts/ocramd.o \
	$(B_DIR)/assets/fonts/tahoma.o \
	$(B_DIR)/assets/fonts/zurich.o \
	$(B_DIR)/getitle.o \
	$(B_DIR)/mpconfigs.o \
	$(B_DIR)/assets/mpstrings/mpstringsE.o \
	$(B_DIR)/assets/mpstrings/mpstringsF.o \
	$(B_DIR)/assets/mpstrings/mpstringsG.o \
	$(B_DIR)/assets/mpstrings/mpstringsI.o \
	$(B_DIR)/assets/mpstrings/mpstringsJ.o \
	$(B_DIR)/assets/mpstrings/mpstringsP.o \
	$(B_DIR)/assets/mpstrings/mpstringsS.o \
	$(B_DIR)/rsp/rspboot.text.o \
	$(B_DIR)/rsp/asp.data.o \
	$(B_DIR)/rsp/asp.text.o \
	$(B_DIR)/rsp/gsp.data.o \
	$(B_DIR)/rsp/gsp.text.o \
	$(B_DIR)/assets/seq.ctl.o \
	$(B_DIR)/assets/seq.tbl.o \
	$(B_DIR)/assets/sequences.o \
	$(B_DIR)/assets/sfx.ctl.o \
	$(B_DIR)/assets/sfx.tbl.o \
	$(B_DIR)/assets/textureslist.o \
	$(B_DIR)/assets/textures/config.o \
	$(B_DIR)/romheader.o

# ntsc-beta doesn't have this segment
ifneq ($(ROMID), ntsc-beta)
	O_FILES := $(O_FILES) $(B_DIR)/assets/accessingpakZ.o
endif

default: rom

################################################################################
# ROM Finalisation Stages

# Link all objects together with ld to make stage1.elf. In this stage, the game,
# lib and data segments are uncompressed and placed past the end of the ROM.
$(B_DIR)/stage1.elf: $(O_FILES) ld/pd.ld
	cpp -DROMID=$(ROMID) -DVERSION=$(VERSION) -P ld/pd.ld -o $(B_DIR)/pd.ld
	$(TOOLCHAIN)-ld --no-check-sections -T $(B_DIR)/pd.ld --print-map -o $@ > $(B_DIR)/pd.map

$(B_DIR)/stage1.bin: $(B_DIR)/stage1.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

# Stage2 takes stage1 and patches the piracy checksums.
$(B_DIR)/stage2.bin: $(B_DIR)/stage1.bin
	@cp $< $@.tmp
	ROMID=$(ROMID) PIRACYCHECKS=$(PIRACYCHECKS) tools/patchpiracysums $@.tmp $(B_DIR)/pd.map && mv $@.tmp $@

# Stage3 takes stage2, compresses the game/lib/data segments,
# inserts them and truncates the ROM to 32MB.
$(B_DIR)/stage3.bin: $(B_DIR)/stage2.bin $(B_DIR)/segments/gamezips.bin
	@cp $< $@.tmp
	tools/packrom $@.tmp && mv $@.tmp $@

$(B_DIR)/segments/gamezips.bin: $(B_DIR)/segments/game.bin
	ROMID=$(ROMID) tools/mkgamezips

# The final ROM image takes stage3 and calculates the ROM CRC.
$(B_DIR)/pd.z64: $(B_DIR)/stage3.bin
	@cp $< $@.tmp
	tools/patchromcrc $@.tmp --write && mv $@.tmp $@

################################################################################
# Testing Related
# ---------------------
# This works a little backwards, in that the ROM has to be built to at least
# stage 2, then extract-segment is used to slice out the segments.

CHECK_FILES := $(shell awk '{print $$2}' checksums.$(ROMID).md5)

test: $(CHECK_FILES)
	@md5sum --quiet -c checksums.$(ROMID).md5

$(B_DIR)/segments/%.bin: $(B_DIR)/stage2.bin
	@B_DIR=$(B_DIR) tools/extract-segment $*

################################################################################
# Raw data segments

$(B_DIR)/assets/fonts/%.o: $(A_DIR)/fonts/%.bin
	mkdir -p $(B_DIR)/assets/fonts
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/getitle.o: $(E_DIR)/getitle.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/seq.ctl.o: $(A_DIR)/seq.ctl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/seq.tbl.o: $(A_DIR)/seq.tbl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/sfx.ctl.o: $(A_DIR)/sfx.ctl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/sfx.tbl.o: $(A_DIR)/sfx.tbl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

################################################################################
# Asset Manager

ASSETMGR_O_FILES := \
	$(B_DIR)/assets/animations.o \
	$(LANG_O_FILES) \
	$(PADS_O_FILES) \
	$(B_DIR)/assets/sequences.o \
	$(B_DIR)/assets/textureslist.o \

# Anims
$(B_DIR)/assets/animations.o: $(A_DIR)/animations.json
	tools/assetmgr/mkanims

# Lang
$(B_DIR)/assets/files/L%.o: $(A_DIR)/lang/%.json
	tools/assetmgr/mklang $<

# Lang - but this is the zipped non-obj, for make test
$(B_DIR)/assets/files/L%: $(A_DIR)/lang/%.json
	tools/assetmgr/mklang $<

# Pads
$(B_DIR)/assets/files/bgdata/bg_%_padsZ.o: $(A_DIR)/pads/%.json
	tools/assetmgr/mkpads $<

# Pads - but this is the zipped non-obj, for make test
$(B_DIR)/assets/files/bgdata/bg_%_padsZ: $(A_DIR)/pads/%.json
	tools/assetmgr/mkpads $<

# Sequences
$(B_DIR)/assets/sequences.o: $(A_DIR)/sequences.json
	tools/assetmgr/mksequences

# Textures
$(B_DIR)/assets/textureslist.o: $(A_DIR)/textures.json
	tools/assetmgr/mktextures

################################################################################
# Files

# Audio
$(B_DIR)/assets/files/A%M: $(A_DIR)/files/audio/%.mp3
	@mkdir -p $(B_DIR)/assets/files
	cp $< $@

# BG segs
$(B_DIR)/assets/files/bgdata/bg_%.seg: $(A_DIR)/files/bgdata/bg_%.seg
	@mkdir -p $(B_DIR)/assets/files/bgdata
	cp $< $@

# BG tiles
# src/assets/files/bgdata/bg_foo_tiles.s
# -> B_DIR/assets/files/bgdata/bg_foo_tiles.o (done here)
# -> B_DIR/assets/files/bgdata/bg_foo_tiles.elf (done here)
# -> A_DIR/assets/files/bgdata/bg_foo_tiles.bin (done here)
# -> B_DIR/assets/files/bgdata/bg_foo_tilesZ (done here)
# Or create $(A_DIR)/files/bgdata/bg_foo_tiles.bin to skip the earlier steps
$(B_DIR)/assets/files/bgdata/bg_%_tiles.o: src/files/bgdata/bg_%_tiles.s
	$(TOOLCHAIN)-as --defsym VERSION=$(VERSION) -march=vr4300 -mabi=32 -I src/include -EB -o $@ $<

$(B_DIR)/assets/files/bgdata/bg_%_tiles.elf: $(B_DIR)/assets/files/bgdata/bg_%_tiles.o
	TOOLCHAIN=$(TOOLCHAIN) tools/mksimpleelf $< $@

$(A_DIR)/files/bgdata/bg_%_tiles.bin: $(B_DIR)/assets/files/bgdata/bg_%_tiles.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/assets/files/bgdata/bg_%_tilesZ: $(A_DIR)/files/bgdata/bg_%_tiles.bin
	tools/rarezip $< > $@

# Chrs
$(B_DIR)/assets/files/C%Z: $(A_DIR)/files/chrs/%.bin
	@mkdir -p $(B_DIR)/assets/files
	tools/rarezip $< > $@

# Guns
$(B_DIR)/assets/files/G%Z: $(A_DIR)/files/guns/%.bin
	@mkdir -p $(B_DIR)/assets/files
	tools/rarezip $< > $@

# OB seg
$(B_DIR)/assets/files/ob/ob_mid.seg.o: $(B_DIR)/assets/files/ob/ob_mid.seg
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/files/ob/ob_mid.seg:
	@mkdir -p $(B_DIR)/assets/files/ob
	> $@

# Props
$(B_DIR)/assets/files/P%Z: $(A_DIR)/files/props/%.bin
	tools/rarezip $< > $@

# Stage setups
# $(A_DIR)/files/setup/foo.c
# -> B_DIR/assets/files/setup/foo.o (done here)
# -> B_DIR/assets/files/setup/foo.elf (done here)
# -> A_DIR/assets/files/setup/foo.bin (done here)
# -> B_DIR/assets/files/UsetupfooZ (done here)
# -> B_DIR/assets/files/UsetupfooZ.o (done elsewhere)
# Or create $(A_DIR)/files/setup/foo.bin to skip the earlier steps
$(B_DIR)/assets/files/setup/%.o: src/files/setup/%.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/assets/files/setup/%.elf: $(B_DIR)/assets/files/setup/%.o
	TOOLCHAIN=$(TOOLCHAIN) tools/mksimpleelf $< $@

$(A_DIR)/files/setup/%.bin: $(B_DIR)/assets/files/setup/%.elf
	@mkdir -p $(dir $@)
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/assets/files/U%Z: $(A_DIR)/files/setup/%.bin
	tools/rarezip $< > $@

# General target to convert any finalised file into a raw object for ld
$(B_DIR)/assets/files/%.o: $(B_DIR)/assets/files/%
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/files/%.bin: $(B_DIR)/assets/files/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

################################################################################
# Miscellaneous

$(B_DIR)/bootloader.o: $(E_DIR)/bootloader.bin
	@mkdir -p $(dir $@)
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/romheader.o: src/romheader/romheader.s
	$(TOOLCHAIN)-as --defsym VERSION=$(VERSION) -march=vr4300 -mabi=32 -I src/include -EB -o $@ $<

$(B_DIR)/assets/accessingpakZ: $(A_DIR)/accessingpak.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/copyrightZ: $(A_DIR)/copyright.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/accessingpakZ.o: $(B_DIR)/assets/accessingpakZ
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/copyrightZ.o: $(B_DIR)/assets/copyrightZ
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/rsp/%.o: $(E_DIR)/rsp/%.bin
	@mkdir -p $(dir $@)
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/lib/ultra/libc/llcvt.o: src/lib/ultra/libc/llcvt.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< | $(IDOCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s
	tools/patchmips3 $@ || rm $@

$(B_DIR)/lib/ultra/libc/ll.o: src/lib/ultra/libc/ll.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@
	tools/patchmips3 $@ || rm $@

$(B_DIR)/lib/ultra/gu/align.o: src/lib/ultra/gu/align.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/ultra/gu/frustum.o: src/lib/ultra/gu/frustum.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/ultra/gu/ortho.o: src/lib/ultra/gu/ortho.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/ultra/gu/scale.o: src/lib/ultra/gu/scale.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/%.o: src/lib/%.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< | $(IDOCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/game/%.o: src/game/%.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< | $(IDOCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

# Files requiring qemu-irix to build rather than recomp due to using MAXFLOAT
$(B_DIR)/game/chr/chraction.o: src/game/chr/chraction.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< | $(QEMUCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/game/game_1657c0.o: src/game/game_1657c0.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< | $(QEMUCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py $(OPT_LVL) $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/%.o: src/%.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/%.o: src/%.s
	@mkdir -p $(dir $@)
	$(IDOAS) $(CFLAGS) $< -o $@

$(B_DIR)/assets/%.o: $(A_DIR)/%.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

extract:
	ROMID=$(ROMID) tools/extract

rom: $(B_DIR)/pd.z64

clean:
	rm -rf build/$(ROMID)

allclean:
	rm -rf build/*

codeclean:
	find $(B_DIR)/{game,inflate,lib} -name '*.o' -delete
