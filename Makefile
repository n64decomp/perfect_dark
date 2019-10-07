# User configurable

REGION=ntsc
RELEASE=final

################################################################################
# Not user configurable

ROMID := $(REGION)-$(RELEASE)
E_DIR := extracted/$(ROMID)
B_DIR := build/$(ROMID)

QEMU_IRIX := tools/irix/qemu-irix
IRIX_ROOT := tools/irix/root

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
    TOOLCHAIN := mips-linux-gnu
else
    TOOLCHAIN := mips64-elf
endif

ifeq ($(REGION),ntsc)
    VERSION_CFLAGS := -DNTSC=1 -DPAL=0 -DJAP=0
endif
ifeq ($(REGION),pal)
    VERSION_CFLAGS := -DNTSC=0 -DPAL=1 -DJAP=0
endif
ifeq ($(REGION),jap)
    VERSION_CFLAGS := -DNTSC=0 -DPAL=0 -DJAP=1
endif

ifeq ($(RELEASE),beta)
    RELEASE_CFLAGS := -DBETA=1 -DREL1_0 -DFINAL=0
endif
ifeq ($(RELEASE),1.0)
    RELEASE_CFLAGS := -DBETA=0 -DREL1_1 -DFINAL=0
endif
ifeq ($(RELEASE),final)
    RELEASE_CFLAGS := -DBETA=0 -DREL1_0 -DFINAL=1
endif

CFLAGS := $(VERSION_CFLAGS) $(RELEASE_CFLAGS) -Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -woff 819,820,852,821 -signed -I src/include -mips2

C_FILES := $(shell find src -name '*.c')
O_FILES := $(patsubst %.c, %.o, $(C_FILES))

default: all

################################################################################
# Extract related

extract:
	tools/extract $(ROMID)

################################################################################
# Stage setup files

SETUP_C_FILES := $(wildcard src/files/setup/*.c)
SETUP_BIN_FILES := $(patsubst src/files/setup/%.c, $(B_DIR)/files/setup/U%.bin, $(SETUP_C_FILES))
SETUP_BINZ_FILES := $(patsubst src/files/setup/%.c, $(B_DIR)/files/U%Z, $(SETUP_C_FILES))

$(B_DIR)/files/setup/%.elf: src/files/setup/%.o
	mkdir -p $(B_DIR)/files/setup
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

$(B_DIR)/files/setup/U%.bin: $(B_DIR)/files/setup/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/files/U%Z: $(B_DIR)/files/setup/U%.bin
	tools/rarezip $< > $@

stagesetup: $(SETUP_BIN_FILES)

################################################################################
# Lang files

LANG_C_FILES := $(wildcard src/files/lang/*.c)
LANG_BIN_FILES := $(patsubst src/files/lang/%.c, $(B_DIR)/files/lang/L%.bin, $(LANG_C_FILES))
LANG_BINZ_FILES := $(patsubst src/files/lang/%.c, $(B_DIR)/files/L%, $(LANG_C_FILES))

$(B_DIR)/files/lang/%.elf: src/files/lang/%.o
	mkdir -p $(B_DIR)/files/lang
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

$(B_DIR)/files/lang/L%.bin: $(B_DIR)/files/lang/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/files/L%E: $(B_DIR)/files/lang/L%E.bin
	tools/rarezip $< > $@

$(B_DIR)/files/L%J: $(B_DIR)/files/lang/L%J.bin
	tools/rarezip $< > $@

$(B_DIR)/files/L%P: $(B_DIR)/files/lang/L%P.bin
	tools/rarezip $< > $@

$(B_DIR)/files/L%Z: $(B_DIR)/files/lang/L%.bin
	tools/rarezip $< > $@

lang: $(LANG_BIN_FILES)

################################################################################
# Boot

$(B_DIR)/boot.elf: $(O_FILES)
	mkdir -p $(B_DIR)
	$(TOOLCHAIN)-ld -e 0x00003050 -T ld/boot.ld -o $@

$(B_DIR)/ucode/boot.bin: $(B_DIR)/boot.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=8272 count=1
	mv "$@.tmp" "$@"

boot: $(B_DIR)/ucode/boot.bin

################################################################################
# Library

$(B_DIR)/library.elf: $(O_FILES)
	mkdir -p $(B_DIR)
	$(TOOLCHAIN)-ld -e 0x00003050 -T ld/library.ld -o $@

$(B_DIR)/ucode/library.bin: $(B_DIR)/library.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=356240 count=1
	mv "$@.tmp" "$@"

library: $(B_DIR)/ucode/library.bin

################################################################################
# Game setup file

$(B_DIR)/setup.elf: $(O_FILES)
	mkdir -p $(B_DIR)
	$(TOOLCHAIN)-ld -e 0x80059fe0 -T ld/setup.ld -o $@

$(B_DIR)/ucode/setup.bin: $(B_DIR)/setup.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=200256 count=1
	mv "$@.tmp" "$@"

setup: $(B_DIR)/ucode/setup.bin

################################################################################
# Rarezip

$(B_DIR)/rarezip.elf: $(O_FILES)
	mkdir -p $(B_DIR)
	$(TOOLCHAIN)-ld -T ld/rarezip.ld -o $@

$(B_DIR)/ucode/rarezip.bin: $(B_DIR)/rarezip.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary

rarezip: $(B_DIR)/ucode/rarezip.bin

################################################################################
# Main game

$(B_DIR)/game.elf: $(O_FILES)
	mkdir -p $(B_DIR)
	$(TOOLCHAIN)-ld -T ld/game.ld -o $@

$(B_DIR)/ucode/game.bin: $(B_DIR)/game.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=1808864 count=1
	mv "$@.tmp" "$@"

game: $(B_DIR)/ucode/game.bin

################################################################################
# gVars

$(B_DIR)/gvars.elf: $(O_FILES)
	mkdir -p $(B_DIR)
	$(TOOLCHAIN)-ld -T ld/gvars.ld -o $@

$(B_DIR)/ucode/gvars.bin: $(B_DIR)/gvars.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary

gvars: $(B_DIR)/ucode/gvars.bin

################################################################################
# Test related

test: all
	@rm -f $(B_DIR)/*.elf
	@diff -q $(E_DIR)/files/lang/ $(B_DIR)/files/lang/
	@diff -q $(E_DIR)/files/setup/ $(B_DIR)/files/setup/
	@diff -q $(E_DIR)/ucode/boot.bin $(B_DIR)/ucode/boot.bin
	@diff -q $(E_DIR)/ucode/game.bin $(B_DIR)/ucode/game.bin
	@diff -q $(E_DIR)/ucode/library.bin $(B_DIR)/ucode/library.bin
	@diff -q $(E_DIR)/ucode/rarezip.bin $(B_DIR)/ucode/rarezip.bin
	@diff -q $(E_DIR)/ucode/setup.bin $(B_DIR)/ucode/setup.bin

################################################################################
# Miscellaneous

%.o: %.c
	python tools/asmpreproc/asm-processor.py -O2 $< | $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ -O2
	python tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

all: stagesetup lang boot library setup rarezip game gvars

rom: all
	tools/inject pd.$(ROMID).z64

clean:
	rm -rf build/*
	find src -name '*.o' -delete

