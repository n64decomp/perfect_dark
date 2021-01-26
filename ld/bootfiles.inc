#define BOOTFILES(section) \
	build/ROMID/boot/entry.o (section); \
	build/ROMID/boot/segments.o (section); \
	build/ROMID/boot/init.o (section); \
	build/ROMID/boot/sched.o (section); \
	build/ROMID/boot/reset.o (section); \
	build/ROMID/lib/ultra/os/maptlbrdb.o (section);
