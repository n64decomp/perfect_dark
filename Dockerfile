FROM --platform=linux/amd64 ubuntu:20.04

# Ubuntu 20.04 is pinned deliberately, for binutils.
#
# 20.04 ships GNU binutils 2.34, which produces a ROM byte-identical to retail.
# 22.04 ships 2.38, which does not -- and fails in a way that looks like
# everything is broken when nothing is:
#
#   * 811 of 1553 `make test` checksums fail.
#   * The built ROM differs from retail in 42% of its bytes.
#   * Yet every compressed asset is byte-identical to the one in the retail ROM,
#     just at a different offset, and the decompiled code compiles exactly.
#
# The cause is that 2.38 lays the lib segment out 3600 (0xE10) bytes differently
# under `BEGIN_SEG(lib) SUBALIGN(0x10)` in ld/pd.ld. That changes link-time
# constants baked into lib and game as addiu immediates (18 bytes in total, each
# off by exactly 0xE10), which changes the compressed lib stream from ROM offset
# 0x8F7C onward, which shifts every asset after it, which regenerates the
# file-offset table in data.bin with 1951 drifted words.
#
# So: do not "modernise" this base image without re-running `make test`.
#
# linux/amd64 is also deliberate -- libc6-dev-i386 is i386 multilib.

# xxd is not in a default 20.04 install and is not named by the README, but
# tools/rarezip pipes through it. Without it the build dies partway through the
# assets with "xxd: command not found".
RUN echo ">> install distro packages ..." && \
    apt update && \
    DEBIAN_FRONTEND=noninteractive apt -y install \
        binutils-mips-linux-gnu build-essential gcc-mips-linux-gnu \
        libc6-dev-i386 libcapstone-dev make git python3 wget cmake \
        ca-certificates xxd

# armips has no Debian/Ubuntu package -- the README says to compile and install
# it. It is used by exactly one Makefile rule, assembling the RSP microcode.
RUN echo ">> build armips ..." && \
    git clone --recursive https://github.com/Kingcom/armips.git /tmp/armips && \
    cmake -S /tmp/armips -B /tmp/armips/build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build /tmp/armips/build -j"$(nproc)" && \
    install -m755 /tmp/armips/build/armips /usr/local/bin/armips && \
    rm -rf /tmp/armips

RUN useradd -ms /bin/bash dev
USER dev
WORKDIR /home/dev/pd

CMD ["/bin/bash"]
