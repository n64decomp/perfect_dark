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

CFLAGS := -Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -woff 819,820,852,821 -signed -I . -I include -mips2

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

setup: $(B_SETUP_BINZ_FILES)

$(B_DIR)/files/setup/%.o: src/setup/%.c $(SETUP_H_FILES)
	mkdir -p $(B_DIR)/files/setup
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/files/setup/%.elf: $(B_DIR)/files/setup/%.o
	cp $< build/setup.tmp.o
	$(TOOLCHAIN)-ld -T setup.ld -o $@
	rm -f build/setup.tmp.o

$(B_DIR)/files/setup/U%.bin: $(B_DIR)/files/setup/%.elf
	$(TOOLCHAIN)-objcopy $< $@ -O binary

$(B_DIR)/files/U%Z: $(B_DIR)/files/setup/U%.bin
	tools/rarezip $< > $@

################################################################################
# Lang files

LANG_C_EJP_FILES := $(wildcard src/lang/*E.c) $(wildcard src/lang/*J.c) $(wildcard src/lang/*P.c)
LANG_C_STR_FILES := $(wildcard src/lang/*_str.c)
B_LANG_BIN_FILES := $(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%.bin, $(LANG_C_EJP_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%_f.bin, $(LANG_C_STR_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%_g.bin, $(LANG_C_STR_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%_i.bin, $(LANG_C_STR_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/lang/L%_s.bin, $(LANG_C_STR_FILES))
B_LANG_BINZ_FILES := $(patsubst src/lang/%.c, $(B_DIR)/files/L%, $(LANG_C_EJP_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/L%_fZ, $(LANG_C_STR_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/L%_gZ, $(LANG_C_STR_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/L%_iZ, $(LANG_C_STR_FILES)) \
	$(patsubst src/lang/%.c, $(B_DIR)/files/L%_sZ, $(LANG_C_STR_FILES))
E_LANG_BIN_FILES := $(patsubst $(B_DIR), $(E_DIR), $(B_LANG_BIN_FILES))
E_LANG_BINZ_FILES := $(patsubst $(B_DIR), $(E_DIR), $(B_LANG_BINZ_FILES))

lang: $(B_LANG_BINZ_FILES)

$(B_DIR)/files/lang/%.o: src/lang/%.c
	mkdir -p $(B_DIR)/files/lang
	$(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc -c $(CFLAGS) -o $@ -O2 $<

$(B_DIR)/files/lang/%.elf: $(B_DIR)/files/lang/%.o
	cp $< build/setup.tmp.o
	$(TOOLCHAIN)-ld -T setup.ld -o $@
	rm -f build/setup.tmp.o

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
# Globals file

globals: $(B_DIR)/Uglobals

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
# Test related

test: $(B_SETUP_BINZ_FILES) $(B_LANG_BINZ_FILES)
	@rm -f $(B_DIR)/files/lang/*.{elf,o}
	@diff -rq --exclude='*.bin' \
		--exclude=chrs \
		--exclude=guns \
		--exclude=props \
		--exclude='A*' \
		--exclude='C*' \
		--exclude='G*' \
		--exclude='P*' \
		--exclude=bgdata \
		--exclude=ob \
		$(E_DIR)/files $(B_DIR)/files
	@cmp -b --ignore-initial=0x1be00 --bytes=0x4ff0 $(E_DIR)/Uglobals $(B_DIR)/Uglobals

testall:
	REGION=ntsc RELEASE=final make test
	REGION=ntsc RELEASE=1.0 make test
	REGION=ntsc RELEASE=beta make test
	REGION=pal RELEASE=final make test
	REGION=pal RELEASE=beta make test
	REGION=jap RELEASE=final make test

################################################################################
# Miscellaneous

all: setup lang globals

rom: $(B_SETUP_BINZ_FILES)
	tools/inject pd.$(ROMID).z64

clean:
	rm -rf build/*

