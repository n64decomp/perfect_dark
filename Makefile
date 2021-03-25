# User configurable

ROMID ?= ntsc-final
PIRACYCHECKS ?= 1

QEMU_IRIX ?= tools/irix/qemu-irix
IRIX_ROOT ?= tools/irix/root

IDOCC ?= $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
IDOAS ?= $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/as

################################################################################

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

B_DIR := build/$(ROMID)

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
$(B_DIR)/lib/ultra/io/motor.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/pfschecker.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/pfsfreeblocks.o: LOOPUNROLL :=
$(B_DIR)/lib/ultra/io/pfsgetstatus.o: LOOPUNROLL :=

$(B_DIR)/lib/ultra/libc/ll.o: MIPSISET := -mips3 -o32
$(B_DIR)/lib/ultra/libc/llcvt.o: MIPSISET := -mips3 -32

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
	-G 0 \
	-Xcpluscomm \
	-woff 581,649,819,820,821,838,852 \
	-w2 \
	-I src/include \
	$(OPT_LVL) \
	$(MIPSISET)

C_FILES := $(shell find src/lib src/game src/inflate -name '*.c')
S_FILES := $(shell find src/lib src/game -name '*.s')

# Create names such as $(B_DIR)/assets/files/PfooZ
# These names (with .o added) will be dependenices for LD
ASSET_FILES := \
	$(patsubst src/assets/files/audio/%.mp3, $(B_DIR)/assets/files/A%M, $(shell find src/assets/files/audio -name '*.mp3')) \
	$(patsubst src/assets/files/chrs/%.bin, $(B_DIR)/assets/files/C%Z, $(shell find src/assets/files/chrs -name '*.bin')) \
	$(patsubst src/assets/files/guns/%.bin, $(B_DIR)/assets/files/G%Z, $(shell find src/assets/files/guns -name '*.bin')) \
	$(patsubst src/assets/files/props/%.bin, $(B_DIR)/assets/files/P%Z, $(shell find src/assets/files/props -name '*.bin')) \
	$(patsubst src/assets/files/setup/%.c, $(B_DIR)/assets/files/U%Z, $(shell find src/assets/files/setup -name '*.c')) \
	$(patsubst src/assets/files/bgdata/%.seg, $(B_DIR)/assets/files/bgdata/%.seg, $(shell find src/assets/files/bgdata -name '*.seg')) \
	$(patsubst src/assets/files/bgdata/%_pads.bin, $(B_DIR)/assets/files/bgdata/%_padsZ, $(shell find src/assets/files/bgdata -name 'bg_*_pads.bin')) \
	$(patsubst src/assets/files/bgdata/%_tiles.s, $(B_DIR)/assets/files/bgdata/%_tilesZ, $(shell find src/assets/files/bgdata -name 'bg_*_tiles.s')) \
	$(patsubst src/assets/files/bgdata/%_tiles.bin, $(B_DIR)/assets/files/bgdata/%_tilesZ, $(shell find src/assets/files/bgdata -name 'bg_*_tiles.bin')) \
	$(patsubst src/assets/files/lang/$(ROMID)/%.c, $(B_DIR)/assets/files/L%, $(shell find src/assets/files/lang/$(ROMID) -name '*[EJP].c')) \
	$(patsubst src/assets/files/lang/$(ROMID)/%.c, $(B_DIR)/assets/files/L%Z, $(shell find src/assets/files/lang/$(ROMID) -name '*_str_[fgis].c')) \
	$(B_DIR)/assets/files/ob/ob_mid.seg.o

ANIM_FILES := $(shell find src/assets/animations -name '*.bin')

O_FILES := \
	$(patsubst src/%.c, $(B_DIR)/%.o, $(C_FILES)) \
	$(patsubst src/%.s, $(B_DIR)/%.o, $(S_FILES)) \
	$(patsubst %, %.o, $(ASSET_FILES)) \
	$(patsubst src/%.bin, $(B_DIR)/%.o, $(ANIM_FILES)) \
	$(B_DIR)/assets/animations/list.o \
	$(B_DIR)/assets/bootloader/bootloader.o \
	$(B_DIR)/assets/copyrightZ.o \
	$(B_DIR)/assets/files/list.o \
	$(B_DIR)/assets/firingrange.o \
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
	$(B_DIR)/assets/getitle.o \
	$(B_DIR)/assets/mpconfigs.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsE.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsF.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsG.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsI.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsJ.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsP.o \
	$(B_DIR)/assets/mpstrings/$(ROMID)/mpstringsS.o \
	$(B_DIR)/assets/rsp/rspboot.text.o \
	$(B_DIR)/assets/rsp/asp.data.o \
	$(B_DIR)/assets/rsp/asp.text.o \
	$(B_DIR)/assets/rsp/gsp.data.o \
	$(B_DIR)/assets/rsp/gsp.text.o \
	$(B_DIR)/assets/seq.ctl.o \
	$(B_DIR)/assets/seq.tbl.o \
	$(B_DIR)/assets/sequences.o \
	$(B_DIR)/assets/sfx.ctl.o \
	$(B_DIR)/assets/sfx.tbl.o \
	$(B_DIR)/assets/texturesdata.o \
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

CHECK_FILES := \
	$(B_DIR)/segments/filenames.bin \
	$(B_DIR)/segments/firingrange.bin \
	$(B_DIR)/segments/game.bin \
	$(B_DIR)/segments/data.bin \
	$(B_DIR)/segments/lib.bin \
	$(B_DIR)/segments/inflate.bin \
	$(B_DIR)/segments/mpconfigs.bin \
	$(B_DIR)/segments/mpstringsE.bin \
	$(B_DIR)/segments/mpstringsJ.bin \
	$(B_DIR)/segments/mpstringsP.bin \
	$(B_DIR)/segments/mpstringsG.bin \
	$(B_DIR)/segments/mpstringsF.bin \
	$(B_DIR)/segments/mpstringsS.bin \
	$(B_DIR)/segments/mpstringsI.bin \
	$(B_DIR)/segments/textureconfig.bin

test: rom $(CHECK_FILES) $(ASSET_FILES)
	@md5sum --quiet -c checksums.$(ROMID).md5

$(B_DIR)/segments/%.bin: $(B_DIR)/stage2.bin
	@B_DIR=$(B_DIR) tools/extract-segment $*

################################################################################
# Raw data segments

$(B_DIR)/assets/fonts/%.o: src/assets/fonts/%.bin
	mkdir -p $(B_DIR)/assets/fonts
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/getitle.o: src/assets/getitle.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/seq.ctl.o: src/assets/seq.ctl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/seq.tbl.o: src/assets/seq.tbl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/sfx.ctl.o: src/assets/sfx.ctl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/sfx.tbl.o: src/assets/sfx.tbl
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/textures.o: src/assets/textures.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

################################################################################
# Files

# Audio
$(B_DIR)/assets/files/A%M: src/assets/files/audio/%.mp3
	@mkdir -p $(B_DIR)/assets/files
	cp $< $@

# BG segs
$(B_DIR)/assets/files/bgdata/bg_%.seg: src/assets/files/bgdata/bg_%.seg
	@mkdir -p $(B_DIR)/assets/files/bgdata
	cp $< $@

# BG pads
$(B_DIR)/assets/files/bgdata/bg_%_padsZ: src/assets/files/bgdata/bg_%_pads.bin
	@mkdir -p $(B_DIR)/assets/files/bgdata
	tools/rarezip $< > $@

# BG tiles
# src/assets/files/bgdata/bg_foo_tiles.s
# -> B_DIR/assets/files/bgdata/bg_foo_tiles.o (done by generic .o target)
# -> B_DIR/assets/files/bgdata/bg_foo_tiles.elf (done here)
# -> B_DIR/assets/files/bgdata/bg_foo_tiles (done here)
# -> B_DIR/assets/files/bgdata/bg_foo_tilesZ (done here)
# Or create src/assets/files/bgdata/bg_foo_tiles.bin and it'll get copied/zipped
$(B_DIR)/assets/files/bgdata/bg_%_tiles.o: src/assets/files/bgdata/bg_%_tiles.s
	$(TOOLCHAIN)-as --defsym VERSION=$(VERSION) -march=vr4300 -mabi=32 -I src/include -EB -o $@ $<

$(B_DIR)/assets/files/bgdata/bg_%_tiles.elf: $(B_DIR)/assets/files/bgdata/bg_%_tiles.o
	TOOLCHAIN=$(TOOLCHAIN) tools/mksimpleelf $< $@

$(B_DIR)/assets/files/bgdata/bg_%_tiles: $(B_DIR)/assets/files/bgdata/bg_%_tiles.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/assets/files/bgdata/bg_%_tilesZ: src/assets/files/bgdata/bg_%_tiles.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/bgdata/bg_%_tilesZ: $(B_DIR)/assets/files/bgdata/bg_%_tiles
	tools/rarezip $< > $@

# Chrs
$(B_DIR)/assets/files/C%Z: src/assets/files/chrs/%.bin
	@mkdir -p $(B_DIR)/assets/files
	tools/rarezip $< > $@

# Guns
$(B_DIR)/assets/files/G%Z: src/assets/files/guns/%.bin
	@mkdir -p $(B_DIR)/assets/files
	tools/rarezip $< > $@

# Lang
$(B_DIR)/assets/files/lang/%.elf: $(B_DIR)/assets/files/lang/$(ROMID)/%.o
	TOOLCHAIN=$(TOOLCHAIN) tools/mksimpleelf $< $@

$(B_DIR)/assets/files/lang/%.bin: $(B_DIR)/assets/files/lang/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/assets/files/L%E: $(B_DIR)/assets/files/lang/%E.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/L%J: $(B_DIR)/assets/files/lang/%J.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/L%P: $(B_DIR)/assets/files/lang/%P.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/L%_str_fZ: $(B_DIR)/assets/files/lang/%_str_f.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/L%_str_gZ: $(B_DIR)/assets/files/lang/%_str_g.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/L%_str_iZ: $(B_DIR)/assets/files/lang/%_str_i.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/L%_str_sZ: $(B_DIR)/assets/files/lang/%_str_s.bin
	tools/rarezip $< > $@

# OB seg
$(B_DIR)/assets/files/ob/ob_mid.seg.o: $(B_DIR)/assets/files/ob/ob_mid.seg
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/files/ob/ob_mid.seg:
	@mkdir -p $(B_DIR)/assets/files/ob
	> $@

# Props
$(B_DIR)/assets/files/P%Z: src/assets/files/props/%.bin
	tools/rarezip $< > $@

# Stage setups
# src/assets/files/setup/foo.c
# -> B_DIR/assets/files/setup/foo.o (done by generic .o target)
# -> B_DIR/assets/files/setup/foo.elf (done here)
# -> B_DIR/assets/files/Usetupfoo (done here)
# -> B_DIR/assets/files/UsetupfooZ (done here)
# Or create src/assets/files/setup/foo.bin and it'll get copied/zipped
$(B_DIR)/assets/files/setup/%.elf: $(B_DIR)/assets/files/setup/%.o
	TOOLCHAIN=$(TOOLCHAIN) tools/mksimpleelf $< $@

$(B_DIR)/assets/files/U%: $(B_DIR)/assets/files/setup/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/assets/files/U%Z: src/assets/files/setup/%.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/files/U%Z: $(B_DIR)/assets/files/U%
	tools/rarezip $< > $@

# General target to convert any finalised file into a raw object for ld
$(B_DIR)/assets/files/%.o: $(B_DIR)/assets/files/%
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/files/%.bin: $(B_DIR)/assets/files/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

################################################################################
# Miscellaneous

$(B_DIR)/assets/bootloader/bootloader.o: src/assets/bootloader/bootloader.bin
	@mkdir -p $(dir $@)
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/romheader.o: src/romheader/romheader.s
	$(TOOLCHAIN)-as --defsym VERSION=$(VERSION) -march=vr4300 -mabi=32 -I src/include -EB -o $@ $<

$(B_DIR)/assets/accessingpakZ: src/assets/accessingpak.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/copyrightZ: src/assets/copyright.bin
	tools/rarezip $< > $@

$(B_DIR)/assets/accessingpakZ.o: $(B_DIR)/assets/accessingpakZ
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/copyrightZ.o: $(B_DIR)/assets/copyrightZ
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/rsp/%.o: src/assets/rsp/%.bin
	@mkdir -p $(dir $@)
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/sequences.bin: src/assets/sequences/sequences.py
	tools/mksequences

$(B_DIR)/assets/sequences.o: $(B_DIR)/assets/sequences.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/texturesdata.bin: src/assets/textures/textures.py
	tools/mktextures

$(B_DIR)/assets/textureslist.bin: src/assets/textures/textures.py
	tools/mktextures

$(B_DIR)/assets/texturesdata.o: $(B_DIR)/assets/texturesdata.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/textureslist.o: $(B_DIR)/assets/textureslist.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/assets/animations/%.o: src/assets/animations/%.bin
	@mkdir -p $(dir $@)
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@ 0x1

$(B_DIR)/assets/animations/list.o: src/assets/animations/list.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/ultra/libc/llcvt.o: src/lib/ultra/libc/llcvt.c
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< | $(IDOCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s
	tools/patchmips3 $@ || rm $@

$(B_DIR)/lib/ultra/libc/ll.o: src/lib/ultra/libc/ll.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@
	tools/patchmips3 $@ || rm $@

# Files that use -O3 must be compiled without the ASM processor, otherwise it
# introduces a race condition when using make -j because they create a temporary
# include-stdin.u file during compilation.
$(B_DIR)/lib/ultra/gu/frustum.o: src/lib/ultra/gu/frustum.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/ultra/gu/ortho.o: src/lib/ultra/gu/ortho.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/ultra/gu/scale.o: src/lib/ultra/gu/scale.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/lib/%.o: src/lib/%.c
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< | $(IDOCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/game/%.o: src/game/%.c
	@mkdir -p $(dir $@)
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< | $(IDOCC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@
	/usr/bin/env python3 tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(IDOCC) -c $(CFLAGS) $< -o $@

$(B_DIR)/%.o: src/%.s
	@mkdir -p $(dir $@)
	$(IDOAS) $(CFLAGS) $< -o $@

extract:
	ROMID=$(ROMID) tools/extract

rom: $(B_DIR)/pd.z64

clean:
	rm -rf build/$(ROMID)

allclean:
	rm -rf build/*

assetsclean:
	find src/assets -name '*.bin' -delete
	find src/assets -name '*.ctl' -delete
	find src/assets -name '*.mp3' -delete
	find src/assets -name '*.seg' -delete
	find src/assets -name '*.seq' -delete
	find src/assets -name '*.tbl' -delete

codeclean:
	rm -f $(B_DIR)/segments/*.bin
	find $(B_DIR)/{game,inflate,lib} -name '*.o' -delete
