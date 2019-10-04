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

CFLAGS := $(VERSION_CFLAGS) $(RELEASE_CFLAGS) -Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -woff 819,820,852,821 -signed -I . -I include -mips2

default: all

################################################################################
# Extract related

extract:
	tools/extract $(ROMID)

################################################################################
# Stage setup files

SETUP_C_FILES := $(wildcard src/setup/*.c)
SETUP_H_FILES := $(wildcard src/include/*.h)
B_SETUP_BIN_FILES := $(patsubst src/setup/%.c, $(B_DIR)/files/setup/U%.bin, $(SETUP_C_FILES))
E_SETUP_BIN_FILES := $(patsubst src/setup/%.c, $(E_DIR)/files/setup/U%.bin, $(SETUP_C_FILES))
B_SETUP_BINZ_FILES := $(patsubst src/setup/%.c, $(B_DIR)/files/U%Z, $(SETUP_C_FILES))
E_SETUP_BINZ_FILES := $(patsubst src/setup/%.c, $(E_DIR)/files/U%Z, $(SETUP_C_FILES))

stagesetup: $(B_SETUP_BINZ_FILES)

$(B_DIR)/files/setup/%.o: src/setup/%.c $(SETUP_H_FILES)
	mkdir -p $(B_DIR)/files/setup
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/files/setup/%.elf: $(B_DIR)/files/setup/%.o
	cp $< build/zero.tmp.o
	$(TOOLCHAIN)-ld -T ld/zero.ld -o $@
	rm -f build/zero.tmp.o

$(B_DIR)/files/setup/U%.bin: $(B_DIR)/files/setup/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/files/U%Z: $(B_DIR)/files/setup/U%.bin
	tools/rarezip $< > $@

################################################################################
# Lang files

LANG_C_EJP_FILES := $(wildcard src/lang/*E.c) $(wildcard src/lang/*J.c) $(wildcard src/lang/*P.c)
LANG_C_STR_FILES := $(wildcard src/lang/*_str_*.c)
B_LANG_BIN_FILES := $(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%.bin, $(LANG_C_EJP_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%.bin, $(LANG_C_STR_FILES))
B_LANG_BINZ_FILES := $(patsubst src/lang/%.c, $(B_DIR)/files/L%, $(LANG_C_EJP_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/L%Z, $(LANG_C_STR_FILES))
E_LANG_BIN_FILES := $(patsubst $(B_DIR), $(E_DIR), $(B_LANG_BIN_FILES))
E_LANG_BINZ_FILES := $(patsubst $(B_DIR), $(E_DIR), $(B_LANG_BINZ_FILES))

lang: $(B_LANG_BINZ_FILES)

$(B_DIR)/files/lang/%.o: src/lang/%.c
	mkdir -p $(B_DIR)/files/lang
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/files/lang/%.elf: $(B_DIR)/files/lang/%.o
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

################################################################################
# Boot

boot: $(B_DIR)/ucode/boot.bin

$(B_DIR)/boot.o: src/boot.c
	mkdir -p $(B_DIR)
	python tools/asmpreproc/asm-processor.py -O2 $< | $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ -O2
	python tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/boot.elf: $(B_DIR)/boot.o $(B_DIR)/library.o
	$(TOOLCHAIN)-ld -e 0x00003050 -T ld/boot.ld -o $@

$(B_DIR)/ucode/boot.bin: $(B_DIR)/boot.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=8272 count=1
	mv "$@.tmp" "$@"

################################################################################
# Library

library: $(B_DIR)/ucode/library.bin

$(B_DIR)/library.o: src/library.c
	mkdir -p $(B_DIR)
	python tools/asmpreproc/asm-processor.py -O2 $< | $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ -O2
	python tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/library.elf: $(B_DIR)/library.o $(B_DIR)/setup.o
	$(TOOLCHAIN)-ld -e 0x00003050 -T ld/library.ld -o $@

$(B_DIR)/ucode/library.bin: $(B_DIR)/library.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=356240 count=1
	mv "$@.tmp" "$@"

################################################################################
# Game setup file

setup: $(B_DIR)/ucode/setup.bin

$(B_DIR)/setup.o: src/setup.c $(SETUP_H_FILES)
	mkdir -p $(B_DIR)
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/setup.elf: $(B_DIR)/setup.o
	$(TOOLCHAIN)-ld -e 0x80059fe0 -T ld/setup.ld -o $@

$(B_DIR)/ucode/setup.bin: $(B_DIR)/setup.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary

################################################################################
# Rarezip

$(B_DIR)/ucode/rarezip.o: src/rarezip/rarezip.c
	mkdir -p $(B_DIR)/ucode
	python tools/asmpreproc/asm-processor.py -O2 $< | $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ -O2
	python tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/ucode/rarezip.elf: $(B_DIR)/ucode/rarezip.o
	cp $< build/rarezip.tmp.o
	$(TOOLCHAIN)-ld -T ld/rarezip.ld -o $@
	rm -f build/rarezip.tmp.o

$(B_DIR)/ucode/rarezip.bin: $(B_DIR)/ucode/rarezip.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

################################################################################
# Main game

game: $(B_DIR)/ucode/game.bin

$(B_DIR)/game.o: src/game/game.c
	mkdir -p $(B_DIR)/ucode
	python tools/asmpreproc/asm-processor.py -O2 $< | $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ -O2
	python tools/asmpreproc/asm-processor.py -O2 $< --post-process $@ --assembler "$(TOOLCHAIN)-as -march=vr4300 -mabi=32" --asm-prelude tools/asmpreproc/prelude.s

$(B_DIR)/game.elf: $(B_DIR)/game.o $(B_DIR)/library.o $(B_DIR)/setup.o
	$(TOOLCHAIN)-ld -T ld/game.ld -o $@

$(B_DIR)/ucode/game.bin: $(B_DIR)/game.elf
	mkdir -p $(B_DIR)/ucode
	$(TOOLCHAIN)-objcopy $< $@ -O binary
	dd if="$@" of="$@.tmp" bs=1808864 count=1
	mv "$@.tmp" "$@"

################################################################################
# Test related

test: $(B_SETUP_BINZ_FILES) $(B_LANG_BINZ_FILES)
	@rm -f $(B_DIR)/files/lang/*.{elf,o}
	@diff -rq --exclude='*.bin' \
		--exclude=chrs \
		--exclude=guns \
		--exclude=lang \
		--exclude=props \
		--exclude=setup \
		--exclude='A*' \
		--exclude='C*' \
		--exclude='G*' \
		--exclude='P*' \
		--exclude=bgdata \
		--exclude=ob \
		$(E_DIR)/files $(B_DIR)/files
	@diff -q $(E_DIR)/ucode/setup.bin $(B_DIR)/ucode/setup.bin
	@diff -q $(E_DIR)/ucode/library.bin $(B_DIR)/ucode/library.bin
	@diff -q $(E_DIR)/ucode/game.bin $(B_DIR)/ucode/game.bin

testall:
	REGION=ntsc RELEASE=final make test
	REGION=ntsc RELEASE=1.0 make test
	REGION=ntsc RELEASE=beta make test
	REGION=pal RELEASE=final make test
	REGION=pal RELEASE=beta make test
	REGION=jap RELEASE=final make test

################################################################################
# Miscellaneous

all: library setup lang stagesetup

rom: $(B_SETUP_BINZ_FILES) $(B_DIR)/ucode/setup.bin
	tools/inject pd.$(ROMID).z64

clean:
	rm -rf build/*

