# User configurable

REGION=ntsc
RELEASE=final

################################################################################
# Not user configurable

ROMID := $(REGION)-$(RELEASE)
E_DIR := extracted/$(ROMID)
B_DIR := build/$(ROMID)
SETUP_FILES := $(wildcard src/setup/*.c)
SETUP_H_FILES := $(wildcard src/include/*.h)
B_BIN_FILES := $(patsubst src/setup/%.c, $(B_DIR)/files/U%, $(SETUP_FILES))
E_BIN_FILES := $(patsubst src/setup/%.c, $(E_DIR)/files/U%, $(SETUP_FILES))
B_BINZ_FILES := $(patsubst src/setup/%.c, $(B_DIR)/files/U%Z, $(SETUP_FILES))
E_BINZ_FILES := $(patsubst src/setup/%.c, $(E_DIR)/files/U%Z, $(SETUP_FILES))

QEMU_IRIX := tools/irix/qemu-irix
IRIX_ROOT := tools/irix/root

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
    TOOLCHAIN := mips-linux-gnu
else
    TOOLCHAIN := mips64-elf
endif

CFLAGS := -Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -woff 819,820,852,821 -signed -I . -I include -mips2

default: $(B_BIN_FILES) $(B_DIR)/Uglobals

################################################################################
# Extract related

extract:
	tools/extract $(ROMID)

################################################################################
# Test related

test: $(B_BIN_FILES)
	@diff -q --exclude='A*' --exclude='C*' --exclude='G*' --exclude='L*' --exclude='P*' --exclude='*Z' --exclude=bgdata --exclude=ob $(E_DIR)/files $(B_DIR)/files
	@cmp -b --ignore-initial=0x1be00 --bytes=0x4ff0 $(E_DIR)/Uglobals $(B_DIR)/Uglobals

testall:
	REGION=ntsc RELEASE=final make test
	REGION=ntsc RELEASE=1.0 make test
	REGION=ntsc RELEASE=beta make test
	REGION=pal RELEASE=final make test
	REGION=pal RELEASE=beta make test
	REGION=jap RELEASE=final make test

################################################################################
# Stage setup files

$(B_DIR)/files/%.o: src/setup/%.c $(SETUP_H_FILES)
	mkdir -p $(B_DIR)/files
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/files/%.elf: $(B_DIR)/files/%.o
	cp $< build/setup.tmp.o
	$(TOOLCHAIN)-ld -T setup.ld -o $@
	rm -f build/setup.tmp.o

$(B_DIR)/files/U%: $(B_DIR)/files/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/files/U%Z: $(B_DIR)/files/U%
	tools/rarezip $< > $@

################################################################################
# Globals file

$(B_DIR)/globals.o: src/globals.c $(SETUP_H_FILES)
	mkdir -p $(B_DIR)
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/globals.elf: $(B_DIR)/globals.o
	cp $< build/globals.tmp.o
	$(TOOLCHAIN)-ld -e 0x80059fe0 -T globals.ld -o $@
	rm -f build/globals.tmp.o

$(B_DIR)/Uglobals: $(B_DIR)/globals.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

################################################################################
# Miscellaneous

rom: $(B_BINZ_FILES)
	tools/inject pd.$(ROMID).z64

clean:
	rm -rf build/*

