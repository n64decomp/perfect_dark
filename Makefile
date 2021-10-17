# User configurable

ROMID ?= ntsc-final
PIRACYCHECKS ?= 1

# In PD, some code is compiled with IDO 5.3 and some is IDO 7.1.
# The project provides both versions of the IDO compiler so that the project can
# be compiled out of the box by running these compilers using qemu-irix.
# Recomp can be used for almost all files, but some must be compiled with qemu.

# These are the qemu-irix versions. These variables are constant.
CCQEMU53 = tools/irix/qemu-irix -silent -L tools/irix/root53 tools/irix/root53/usr/bin/cc
CCQEMU71 = tools/irix/qemu-irix -silent -L tools/irix/root71 tools/irix/root71/usr/bin/cc

# The user can use recomp by setting $CC53 and $CC71 in their environment.
# If not set, fall back to using the qemu-irix compilers.
CC53 ?= $(CCQEMU53)
CC71 ?= $(CCQEMU71)

# By default we'll compile everything using 5.3,
# as this is what most of the project uses.
CC := $(CC53)

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

DEFINES := VERSION=$(VERSION) NTSC=$(NTSC) PAL=$(PAL) JPN=$(JPN) PIRACYCHECKS=$(PIRACYCHECKS) _FINALROM=1

C_DEFINES := $(foreach d,$(DEFINES),-D$(d))
AS_DEFINES := $(foreach d,$(DEFINES),--defsym $(d)) --defsym _LANGUAGE_ASSEMBLY=1

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

AS := $(TOOLCHAIN)-as

LOOPUNROLL_C_FILES := \
	src/lib/ultra/gu/frustum.c \
	src/lib/ultra/gu/mtxutil.c \
	src/lib/ultra/gu/ortho.c \
	src/lib/ultra/io/conteepread.c \
	src/lib/ultra/io/conteepwrite.c \
	src/lib/ultra/io/contpfs.c \
	src/lib/ultra/io/contramread.c \
	src/lib/ultra/io/contramwrite.c \
	src/lib/ultra/io/gbpakgetstatus.c \
	src/lib/ultra/io/gbpakreadid.c \
	src/lib/ultra/io/motor.c \
	src/lib/ultra/io/pfschecker.c \
	src/lib/ultra/io/pfsfreeblocks.c \
	src/lib/ultra/io/pfsgetstatus.c \
	src/lib/ultra/io/pfsinitpak2.c

MIPS3_C_FILES := \
	src/lib/ultra/libc/ll.c \
	src/lib/ultra/libc/llcvt.c

G_C_FILES := \
	$(shell find src/lib/ultra/audio -name '*.c') \
	$(shell find src/lib/naudio -name '*.c') \
	src/lib/lib_2fba0.c \
	src/lib/lib_317f0.c \
	src/lib/lib_3a100.c \
	src/lib/lib_3e730.c \
	src/lib/mp3.c \
	src/lib/speaker.c

O1_C_FILES := \
	src/lib/ultra/io/ai.c \
	src/lib/ultra/io/aisetnextbuf.c \
	src/lib/ultra/io/conteeplongread.c \
	src/lib/ultra/io/contquery.c \
	src/lib/ultra/io/controller.c \
	src/lib/ultra/io/dpctr.c \
	src/lib/ultra/io/pigetcmdq.c \
	src/lib/ultra/io/pidma.c \
	src/lib/ultra/io/si.c \
	src/lib/ultra/io/sp.c \
	src/lib/ultra/io/spsetpc.c \
	src/lib/ultra/io/sptaskyielded.c \
	src/lib/ultra/io/vi.c \
	src/lib/ultra/io/viblack.c \
	src/lib/ultra/io/vigetcurrframebuf.c \
	src/lib/ultra/io/vigetnextframebuf.c \
	src/lib/ultra/io/visetevent.c \
	src/lib/ultra/io/visetmode.c \
	src/lib/ultra/io/visetxscale.c \
	src/lib/ultra/io/visetyscale.c \
	src/lib/ultra/io/viswapbuf.c \
	src/lib/ultra/libc/ll.c \
	src/lib/ultra/libc/llcvt.c \
	src/lib/ultra/os/atomic.c \
	src/lib/ultra/os/createmesgqueue.c \
	src/lib/ultra/os/destroythread.c \
	src/lib/ultra/os/gettime.c \
	src/lib/ultra/os/jammesg.c \
	src/lib/ultra/os/recvmesg.c \
	src/lib/ultra/os/resetglobalintmask.c \
	src/lib/ultra/os/sendmesg.c \
	src/lib/ultra/os/seteventmesg.c \
	src/lib/ultra/os/setglobalintmask.c \
	src/lib/ultra/os/setthreadpri.c \
	src/lib/ultra/os/settimer.c \
	src/lib/ultra/os/startthread.c \
	src/lib/ultra/os/stopthread.c \
	src/lib/ultra/os/stoptimer.c \
	src/lib/ultra/os/thread.c \
	src/lib/ultra/os/timerintr.c \
	src/lib/ultra/os/virtualtophysical.c \
	src/lib/ultra/os/yieldthread.c

ifeq ($(ROMID), ntsc-beta)
	O1_C_FILES := $(O1_C_FILES) src/lib/ultra/io/pfsisplug.c
endif

O3_C_FILES := \
	src/lib/ultra/gu/align.c \
	src/lib/ultra/gu/frustum.c \
	src/lib/ultra/gu/ortho.c \
	src/lib/ultra/gu/scale.c

IDO71_C_FILES := \
	$(shell find src/lib/naudio -name '*.c') \
	src/lib/lib_3a100.c

LOOPUNROLL_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(LOOPUNROLL_C_FILES))
MIPS3_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(MIPS3_C_FILES))
G_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(G_C_FILES))
O1_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(O1_C_FILES))
O3_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(O3_C_FILES))
IDO71_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(IDO71_C_FILES))

LOOPUNROLL := -Wo,-loopunroll,0
MIPSISET := -mips2 -32
OPT_LVL := -O2

$(LOOPUNROLL_O_FILES): LOOPUNROLL :=
$(MIPS3_O_FILES): MIPSISET := -mips3 -32
$(G_O_FILES): OPT_LVL := -g
$(O1_O_FILES): OPT_LVL := -O1
$(O3_O_FILES): OPT_LVL := -O3
$(IDO71_O_FILES): CC := $(CC71)

CFLAGS = $(C_DEFINES) \
	$(LOOPUNROLL) \
	-Wab,-r4300_mul \
	-non_shared \
	-Olimit 1000 \
	-G 0 \
	-Xcpluscomm \
	-woff 581,649,819,820,821,838,852 \
	-w2 \
	-I include \
	-I include/PR \
	-I src/include \
	-I src/generated/$(ROMID) \
	-I src/lib/ultra/audio \
	$(OPT_LVL) \
	$(MIPSISET)

ASFLAGS = -march=vr4300 -mabi=32 -Iinclude -Iinclude/PR -Isrc/include -Isrc/lib/ultra/audio $(AS_DEFINES)

C_FILES := $(shell find src/lib src/game src/inflate -name '*.c')
S_FILES := $(shell find src/lib src/game src/preamble -name '*.s')

# Files containing MAXFLOAT must be built with qemu, not recomp
# And luckily this only occurs in 5.3 code, so we can force CCQEMU53 here
MAXFLOAT_C_FILES != grep -rl 'MAXFLOAT' $(C_FILES)
MAXFLOAT_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(MAXFLOAT_C_FILES))

$(MAXFLOAT_O_FILES): CC := $(CCQEMU53)

# Files containing GLOBAL_ASM must be built with the asm_processor
GLOBALASM_C_FILES != grep -rl 'GLOBAL_ASM(' $(C_FILES)
GLOBALASM_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(GLOBALASM_C_FILES))

$(GLOBALASM_O_FILES): CC := /usr/bin/env python3 tools/asm_processor/build.py $(CC) -- $(TOOLCHAIN)-as $(ASFLAGS) --

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
	$(CC) -c $(CFLAGS) -o $@ $<

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
	$(CC) -c $(CFLAGS) -o $@ $<
	tools/patchmips3 $@ || rm $@

$(B_DIR)/lib/ultra/libc/ll.o: src/lib/ultra/libc/ll.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
	tools/patchmips3 $@ || rm $@

$(B_DIR)/%.o: src/%.c $(ASSETMGR_O_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

$(B_DIR)/%.o: src/%.s
	@mkdir -p $(dir $@)
	cpp -P -Wno-trigraphs -I include -I include/PR -I src/include $(C_DEFINES) -D_LANGUAGE_ASSEMBLY -D_MIPSEB $< | $(AS) $(ASFLAGS) -o $@

$(B_DIR)/assets/%.o: $(A_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

extract:
	ROMID=$(ROMID) tools/extract

rom: $(B_DIR)/pd.z64

clean:
	rm -rf build/$(ROMID)

allclean:
	rm -rf build/*

codeclean:
	find $(B_DIR)/{game,inflate,lib} -name '*.o' -delete
