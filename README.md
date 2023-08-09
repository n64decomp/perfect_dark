# Perfect Dark port

This repository contains a work-in-progress port of the [Perfect Dark decompilation](https://github.com/n64decomp/perfect_dark) to modern platforms.

To run the port, you must already have a Perfect Dark ROM, specifically the ntsc-final/revision 1 version  
(md5 `e03b088b6ac9e0080440efed07c1e40f`).

## Status

Currently only 32-bit platforms are supported, namely x86 Windows and Linux.

The game is in a somewhat functional but probably unstable state.
There are major graphical issues, minor audio issues and possibly other issues.
Splitscreen modes currently do not work.

There are currently no "extra features" implemented, such as widescreen,
except for janky mouselook, arbitrary 4:3 resolution support and somewhat expanded heap size.

## Running

1. Create a directory named `data` next to `pd.exe`.
2. Put your Perfect Dark ROM named `pd.ntsc-final.z64` into it.
3. Run `pd.exe`.

## Building

1. Ensure you have SDL2, libGL and ZLib installed on your system.
2. Run `make -f Makefile.port` in the `perfect_dark` directory.
3. The resulting executable will be at `build/ntsc-final-port/pd.exe`.

If cross-compiling, specify the target platform on the `make` command line like so:  
```make -f Makefile.port TARGET_PLATFORM=i686-linux```

Currently only `i686-linux` and `i686-windows` are supported, using `i686-linux-gnu-gcc` and `i686-w64-mingw32-gcc` as compilers, respectively.

## Credits

* the original [decompilation project](https://github.com/n64decomp/perfect_dark) authors;
* doomhack for the only other publicly available [PD porting effort](https://github.com/doomhack/perfect_dark) I could find;
* [sm64-port](https://github.com/sm64-port/sm64-port) authors for the audio mixer and some other changes;
* [Ship of Harkinian team](https://github.com/Kenix3/libultraship/tree/main/src/graphic/Fast3D), Emill and MaikelChan for the libultraship version of fast3d that this port uses;
* lieff for [minimp3](https://github.com/lieff/minimp3);
* probably more I'm forgetting.
