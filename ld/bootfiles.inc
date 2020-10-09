#define BOOTFILES(section) \
	build/ROMID/boot/boot.o (section); \
	build/ROMID/boot/reset.o (section); \
	build/ROMID/lib/ultra/os/maptlbrdb.o (section);
