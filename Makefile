# User configurable

ROMID ?= ntsc-final
PIRACYCHECKS ?= 1

# In PD, some code is compiled with IDO 5.3 and some is IDO 7.1.
# The project requires the ido-static-recomp project, which deconstructs the IDO
# compiler and related binaries and recompiles them for your computer's
# architecture. These recompiled compilers and binaries are then used to compile
# the game's source.

# These are paths to the recompiled compilers
CC53 ?= build/recomp/5.3/cc
CC71 ?= build/recomp/7.1/cc

# By default we'll compile everything using 5.3,
# as this is what most of the project uses.
CC := $(CC53)

################################################################################

export ROMID

NTSC=0
PAL=0
JPN=0
ZIPMAGIC=0x0000

ifeq ($(ROMID),ntsc-beta)
	NTSC=1
	VERSION=0
	PIRACYCHECKS=0
endif
ifeq ($(ROMID),ntsc-1.0)
	NTSC=1
	VERSION=1
	ZIPMAGIC=0xffff
endif
ifeq ($(ROMID),ntsc-final)
	NTSC=1
	VERSION=2
	ZIPMAGIC=0xffff
endif
ifeq ($(ROMID),pal-beta)
	PAL=1
	VERSION=3
	ZIPMAGIC=0x0c00
endif
ifeq ($(ROMID),pal-final)
	PAL=1
	VERSION=4
	ZIPMAGIC=0xaf00
endif
ifeq ($(ROMID),jpn-final)
	JPN=1
	VERSION=5
	ZIPMAGIC=0x0002
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
	$(shell find src/lib/mp3 -name '*.c') \
	src/lib/lib_2fc60.c \
	src/lib/lib_317f0.c \
	src/lib/lib_39c80.c \
	src/lib/lib_3e3e0.c \
	src/lib/mp3.c \
	src/lib/speaker.c

O1_C_FILES := \
	src/lib/lib_04f60nb.c \
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
	src/lib/ultra/os/initialize2.c \
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
	src/lib/ultra/gu/scale.c \
	src/lib/ultra/libc/xprintf.c

IDO71_C_FILES := \
	$(shell find src/lib/ultra/audio -name '*.c') \
	$(shell find src/lib/naudio -name '*.c') \
	$(shell find src/lib/mp3 -name '*.c') \
	src/lib/lib_2fc60.c \
	src/lib/lib_39c80.c

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
	-Olimit 2000 \
	-G 0 \
	-Xcpluscomm \
	-w2 \
	-Wab,-w \
	-woff 581,649,819,820,821,838,852 \
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

# Files containing GLOBAL_ASM must be built with the asm_processor
GLOBALASM_C_FILES != grep -rl 'GLOBAL_ASM(' $(C_FILES)
GLOBALASM_O_FILES = $(patsubst src/%.c, $(B_DIR)/%.o, $(GLOBALASM_C_FILES))

$(GLOBALASM_O_FILES): CC := /usr/bin/env python3 tools/asm_processor/build.py $(CC) -- $(TOOLCHAIN)-as $(ASFLAGS) --

# Asset files are files which are included in the "files" segment of the ROM.
# This excludes animations, fonts, SFX, MIDI and textures.
# And because setup files are part of the files segment they are included here,
# despite them being written in C.
#
# Create names such as $(B_DIR)/assets/files/PfooZ.
# These names (with .o added) will be dependenices for ld.
ASSET_FILES := \
	$(patsubst $(A_DIR)/files/audio/%.mp3,  $(B_DIR)/assets/files/A%M,          $(shell find $(A_DIR) -path '*/files/audio/*.mp3')) \
	$(patsubst $(A_DIR)/files/chrs/%.bin,   $(B_DIR)/assets/files/C%Z,          $(shell find $(A_DIR) -path '*/files/chrs/*.bin')) \
	$(patsubst $(A_DIR)/files/guns/%.bin,   $(B_DIR)/assets/files/G%Z,          $(shell find $(A_DIR) -path '*/files/guns/*.bin')) \
	$(patsubst $(A_DIR)/files/props/%.bin,  $(B_DIR)/assets/files/P%Z,          $(shell find $(A_DIR) -path '*/files/props/*.bin')) \
	$(patsubst src/files/setup/%.c,         $(B_DIR)/assets/files/U%Z,          $(shell find src/files/setup -name '*.c')) \
	$(patsubst $(A_DIR)/files/bgdata/%.seg, $(B_DIR)/assets/files/bgdata/%.seg, $(shell find $(A_DIR) -path '*/files/bgdata/*.seg')) \
	$(B_DIR)/assets/files/ob/ob_mid.seg.o

LANG_JSON_FILES := $(shell find $(A_DIR) -path '*/lang/*.json')
PADS_JSON_FILES := $(shell find $(A_DIR) -path '*/pads/*.json')
TILES_JSON_FILES := $(shell find $(A_DIR) -path '*/tiles/*.json')

LANG_O_FILES := $(patsubst $(A_DIR)/lang/%.json, $(B_DIR)/assets/files/L%.o, $(LANG_JSON_FILES))
PADS_O_FILES := $(patsubst $(A_DIR)/pads/%.json, $(B_DIR)/assets/files/bgdata/bg_%_padsZ.o, $(PADS_JSON_FILES))
TILES_O_FILES := $(patsubst $(A_DIR)/tiles/%.json, $(B_DIR)/assets/files/bgdata/bg_%_tilesZ.o, $(TILES_JSON_FILES))

O_FILES := \
	$(patsubst src/%.c, $(B_DIR)/%.o, $(C_FILES)) \
	$(patsubst src/%.s, $(B_DIR)/%.o, $(S_FILES)) \
	$(patsubst %, %.o, $(ASSET_FILES)) \
	$(LANG_O_FILES) \
	$(PADS_O_FILES) \
	$(TILES_O_FILES) \
	$(B_DIR)/assets/animations.o \
	$(B_DIR)/assets/copyrightZ.o \
	$(B_DIR)/assets/files/list.o \
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
	$(B_DIR)/assets/mpstrings/mpstringsE.o \
	$(B_DIR)/assets/mpstrings/mpstringsF.o \
	$(B_DIR)/assets/mpstrings/mpstringsG.o \
	$(B_DIR)/assets/mpstrings/mpstringsI.o \
	$(B_DIR)/assets/mpstrings/mpstringsJ.o \
	$(B_DIR)/assets/mpstrings/mpstringsP.o \
	$(B_DIR)/assets/mpstrings/mpstringsS.o \
	$(B_DIR)/assets/seq.ctl.o \
	$(B_DIR)/assets/seq.tbl.o \
	$(B_DIR)/assets/sequences.o \
	$(B_DIR)/assets/sfx.ctl.o \
	$(B_DIR)/assets/sfx.tbl.o \
	$(B_DIR)/assets/textureslist.o \
	$(B_DIR)/bootloader.o \
	$(B_DIR)/firingrange.o \
	$(B_DIR)/garbage.o \
	$(B_DIR)/getitle.o \
	$(B_DIR)/mpconfigs.o \
	$(B_DIR)/romheader.o \
	$(B_DIR)/rsp/asp.data.o \
	$(B_DIR)/rsp/asp.text.o \
	$(B_DIR)/rsp/gsp.data.o \
	$(B_DIR)/rsp/gsp.text.o \
	$(B_DIR)/rsp/rspboot.text.o \
	$(B_DIR)/textureconfig.o

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

# Build the final ROM from stage1.bin using mkrom
# mkrom handles calculating the piracy checksums, zipping segments and
# calculating the ROM checksum.
$(B_DIR)/pd.z64: $(B_DIR)/stage1.bin tools/mkrom/mkrom
	tools/mkrom/mkrom $(B_DIR)/stage1.bin $(B_DIR)/pd.map $(PIRACYCHECKS) $(ZIPMAGIC) $@

tools/mkrom/mkrom:
	$(MAKE) -C tools/mkrom

################################################################################
# Recomp
# ---------------------
# The ido-static-recomp project is installed as a git submodule at tools/recomp.
# The IRIX binaries are taken from that project and they are recompiled to
# build/recomp/<version>/

RECOMP_FILES := \
	build/recomp/5.3/as1 \
	build/recomp/5.3/cc \
	build/recomp/5.3/cfe \
	build/recomp/5.3/err.english.cc \
	build/recomp/5.3/ugen \
	build/recomp/5.3/ujoin \
	build/recomp/5.3/uld \
	build/recomp/5.3/umerge \
	build/recomp/5.3/uopt \
	build/recomp/5.3/usplit \
	build/recomp/7.1/as1 \
	build/recomp/7.1/cc \
	build/recomp/7.1/cfe \
	build/recomp/7.1/err.english.cc \
	build/recomp/7.1/ugen \
	build/recomp/7.1/uopt

tools/recomp/recomp.cpp:
	@echo "Please install ido-static-recomp by running:"
	@echo
	@echo "    git submodule update --init --recursive"
	@echo
	@exit 1

build/recomp/recomp: tools/recomp/recomp.cpp
	@mkdir -p build/recomp/5.3
	@mkdir -p build/recomp/7.1
	g++ tools/recomp/recomp.cpp -o build/recomp/recomp -g -lcapstone

build/recomp/5.3/ugen:
	@mkdir -p build/recomp/5.3
	g++ tools/recomp/recomp.cpp -o build/recomp/recomp-ugen53 -g -lcapstone -Dugen53
	./build/recomp/recomp-ugen53 tools/recomp/ido/5.3/usr/lib/ugen > build/recomp/5.3/ugen.c
	gcc tools/recomp/libc_impl.c build/recomp/5.3/ugen.c -Itools/recomp -o build/recomp/5.3/ugen -O2 -fno-strict-aliasing -lm -no-pie -DIDO53

build/recomp/5.3/cc: build/recomp/recomp
	./build/recomp/recomp tools/recomp/ido/5.3/usr/bin/cc > build/recomp/5.3/cc.c
	gcc tools/recomp/libc_impl.c build/recomp/5.3/cc.c -Itools/recomp -o build/recomp/5.3/cc -O2 -fno-strict-aliasing -lm -no-pie -DIDO53

build/recomp/5.3/%: build/recomp/recomp
	./build/recomp/recomp tools/recomp/ido/5.3/usr/lib/$* > build/recomp/5.3/$*.c
	gcc tools/recomp/libc_impl.c build/recomp/5.3/$*.c -Itools/recomp -o build/recomp/5.3/$* -O2 -fno-strict-aliasing -lm -no-pie -DIDO53

build/recomp/7.1/cc: build/recomp/recomp
	./build/recomp/recomp tools/recomp/ido/7.1/usr/bin/cc > build/recomp/7.1/cc.c
	gcc tools/recomp/libc_impl.c build/recomp/7.1/cc.c -Itools/recomp -o build/recomp/7.1/cc -O2 -fno-strict-aliasing -lm -no-pie -DIDO71

build/recomp/7.1/%: build/recomp/recomp
	./build/recomp/recomp tools/recomp/ido/7.1/usr/lib/$* > build/recomp/7.1/$*.c
	gcc tools/recomp/libc_impl.c build/recomp/7.1/$*.c -Itools/recomp -o build/recomp/7.1/$* -O2 -fno-strict-aliasing -lm -no-pie -DIDO71

build/recomp/%/err.english.cc:
	@mkdir -p build/recomp/$?
	cp tools/err.english.cc build/recomp/$*

################################################################################
# Testing Related
# ---------------------
# This works a little backwards, in that the ROM has to be built to at least
# stage 2, then extract-segment is used to slice out the segments.

CHECK_FILES := $(shell awk '{print $$2}' checksums.$(ROMID).md5)

test: $(CHECK_FILES)
	@md5sum --quiet -c checksums.$(ROMID).md5

$(B_DIR)/segments/%.bin: $(B_DIR)/pd.z64
	@B_DIR=$(B_DIR) tools/extract-segment $*

################################################################################
# Raw data segments

$(B_DIR)/assets/fonts/%.o: $(A_DIR)/fonts/%.bin
	mkdir -p $(B_DIR)/assets/fonts
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/garbage.o: $(E_DIR)/garbage.bin
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
	$(TILES_O_FILES) \
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

# Tiles
$(B_DIR)/assets/files/bgdata/bg_%_tilesZ.o: $(A_DIR)/tiles/%.json
	tools/assetmgr/mktiles $<

# Tiles - but this is the zipped non-obj, for make test
$(B_DIR)/assets/files/bgdata/bg_%_tilesZ: $(A_DIR)/tiles/%.json
	tools/assetmgr/mktiles $<

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
# -> B_DIR/assets/files/setup/foo.bin (done here)
# -> B_DIR/assets/files/UsetupfooZ (done here)
# -> B_DIR/assets/files/UsetupfooZ.o (done elsewhere)
$(B_DIR)/assets/files/setup/%.o: src/files/setup/%.c $(ASSETMGR_O_FILES) $(RECOMP_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

$(B_DIR)/assets/files/setup/%.elf: $(B_DIR)/assets/files/setup/%.o
	TOOLCHAIN=$(TOOLCHAIN) tools/mksimpleelf $< $@

$(B_DIR)/files/setup/%.bin: $(B_DIR)/assets/files/setup/%.elf
	@mkdir -p $(dir $@)
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/assets/files/U%Z: $(B_DIR)/files/setup/%.bin
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

$(B_DIR)/rsp/%.text.bin $(B_DIR)/rsp/%.data.bin &: src/rsp/%.s
	@mkdir -p $(dir $@)
	armips -strequ CODE_FILE $(B_DIR)/rsp/$*.text.bin -strequ DATA_FILE $(B_DIR)/rsp/$*.data.bin $<

# For RSP ucodes which haven't been diassembled yet, copy from extracted
$(B_DIR)/rsp/%.bin: $(E_DIR)/rsp/%.bin
	@mkdir -p $(dir $@)
	cp $< $@

$(B_DIR)/rsp/%.o: $(B_DIR)/rsp/%.bin
	TOOLCHAIN=$(TOOLCHAIN) ROMID=$(ROMID) tools/mkrawobject $< $@

$(B_DIR)/lib/ultra/libc/llcvt.o: src/lib/ultra/libc/llcvt.c $(ASSETMGR_O_FILES) $(RECOMP_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<
	tools/patchmips3 $@ || rm $@

$(B_DIR)/lib/ultra/libc/ll.o: src/lib/ultra/libc/ll.c $(ASSETMGR_O_FILES) $(RECOMP_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
	tools/patchmips3 $@ || rm $@

$(B_DIR)/%.o: src/%.c $(ASSETMGR_O_FILES) $(RECOMP_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

$(B_DIR)/%.o: src/%.s
	@mkdir -p $(dir $@)
	cpp -P -Wno-trigraphs -I include -I include/PR -I src/include $(C_DEFINES) -D_LANGUAGE_ASSEMBLY -D_MIPSEB $< | $(AS) $(ASFLAGS) -o $@

$(B_DIR)/assets/%.o: $(A_DIR)/%.c $(RECOMP_FILES)
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
