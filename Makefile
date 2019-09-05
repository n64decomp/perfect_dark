# User configurable

REGION=ntsc
RELEASE=final

################################################################################
# Not user configurable

ROMID := $(REGION)-$(RELEASE)
E_DIR := extracted/$(ROMID)
B_DIR := build/$(ROMID)
S_FILES := $(wildcard asm/setup/*.s)
S_INC_FILES := $(wildcard asm/include/*.inc)
B_BIN_FILES := $(patsubst asm/setup/%.s, $(B_DIR)/files/U%, $(S_FILES))
E_BIN_FILES := $(patsubst asm/setup/%.s, $(E_DIR)/files/U%, $(S_FILES))
B_BINZ_FILES := $(patsubst asm/setup/%.s, $(B_DIR)/files/U%Z, $(S_FILES))
E_BINZ_FILES := $(patsubst asm/setup/%.s, $(E_DIR)/files/U%Z, $(S_FILES))

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

$(B_DIR)/files/%.o: asm/setup/%.s $(S_INC_FILES)
	mkdir -p $(B_DIR)/files
	aarch64-linux-gnu-as -EB -o $@ $<

$(B_DIR)/files/%.elf: $(B_DIR)/files/%.o
	aarch64-linux-gnu-ld -EB -e 0 -Tdata=0 -o $@ $<

$(B_DIR)/files/U%: $(B_DIR)/files/%.elf
	aarch64-linux-gnu-objcopy -O binary $< $@

$(B_DIR)/files/U%Z: $(B_DIR)/files/U%
	tools/rarezip $< > $@

################################################################################
# Globals file

$(B_DIR)/Uglobals.o: asm/globals.s $(S_INC_FILES)
	aarch64-linux-gnu-as -EB -o $@ $<

$(B_DIR)/Uglobals.elf: $(B_DIR)/Uglobals.o
	aarch64-linux-gnu-ld -EB -e 0 -Tdata=0x80059fe0 -o $@ $<

$(B_DIR)/Uglobals: $(B_DIR)/Uglobals.elf
	aarch64-linux-gnu-objcopy -O binary $< $@

################################################################################
# Miscellaneous

rom: $(B_BINZ_FILES)
	tools/inject pd.$(ROMID).z64

clean:
	rm -rf build/*

