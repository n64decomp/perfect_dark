#include "os_tlb.h"
#include "asm_helper.h"
#include "macros.inc"
#include "versions.h"
#include "lib/vm.h"
.set noat
.set noreorder

.bss
.balign 4

/**
 * Quick figures (correct for ntsc-final):
 * 443 pages
 * Page size is 4096 (ie. 4KB each)
 * Virtual range is 0x7f000000 to 0x7f1bb000 (0x7f000000 + 443 * 4096)
 *
 * There are 268 physical slots, meaning 268 pages can be loaded at a time.
 * There are 30-ish entries in the TLB, so only 30-ish can be mapped at a time.
 * Physical slots are in physical memory at 0x80220000 to 0x8032c000.
 */

# Pointer to the physical slots where pages can be loaded (ie. 0x80220000).
# Size = 268 * 4096
glabel g_VmPhysicalSlots
.space 4

# Pointer to the virtual-to-physical (V2P) table.
# Each entry is 8 bytes and there is one entry for each virtual page.
# The first word is the physical address where the page is loaded, or 0 if not loaded.
# The second word is unused.
# An example physical address is 0x00220000.
# Size = 443 * 8
glabel g_VmVirtualToPhysicalTable
.space 4

# Set but never read
glabel g_VmInitialised
.space 1
.align 1

# The number of pages that can be loaded at any one time (268).
# Written but never read.
glabel g_VmNumSlots
.space 2

# Pointer to a buffer that's big enough to hold the biggest zip file.
glabel g_VmZipBuffer
.space 4

# Pointer to an array of ROM offsets where each zip can be found.
# Size = 443 * sizeof(void *)
glabel g_VmZipTable
.space 4

# Temporary stack space. Used when unzipping a page.
.align 3
glabel g_VmTempStack
.space 0x1000

# A scratch area that can be used by rzip_inflate.
glabel g_VmScratch
.space 0x1400

# Array where each bit represents a physical slot (268 bits).
# Bits are 1 if the slot is vacant.
glabel g_VmVacantBits
.space VM_VACANTBITS_LEN

# The number of pages that can be loaded at any one time (268).
# Written but never read.
# Duplicate of g_VmNumSlots.
glabel g_VmNumSlots2
.space 2

# Pointer to the first byte in the g_VmVacantBits array. Never changed once set.
glabel g_VmVacantFirstByte
.space 4

# Pointer to the last byte in the g_VmVacantBits array. Never changed once set.
glabel g_VmVacantLastByte
.space 4

# Unused.
glabel var8008d264
.space 2

# Masked with C0_COUNT to choose which page to replace.
# Initialised with the value 0x1ff then never changed.
glabel g_VmEvictMask
.space 2

# The physical address of the slots (0x00220000).
glabel g_VmSlotsPhysicalAddr
.space 4

.text

/**
 * Sets up TLB index 0 (0x70000000), then calls boot.
 */
glabel vm_boot
	li     $t0, OS_PM_4M
	mtc0   $t0, C0_PAGEMASK
	li     $t0, 0x70000000
	mtc0   $t0, C0_ENTRYHI
	li     $t0, 0x1f
	mtc0   $t0, C0_ENTRYLO0
	li     $t0, 0x1001f
	mtc0   $t0, C0_ENTRYLO1
	li     $t0, 0
	mtc0   $t0, C0_INX
 	nop
 	tlbwi
 	nop
 	nop
 	nop
	la     $t0, boot
	jr     $t0
 	nop

glabel vm_init_vars
	addiu  $sp, $sp, -8
	sw     $ra, 0x0($sp)

	mtc0   $zero, C0_CONTEXT

	li     $t0, 2
	mtc0   $t0, C0_WIRED

	li     $t1, 0x1ff
	lui    $at, %hi(g_VmEvictMask)
	sh     $t1, %lo(g_VmEvictMask)($at)

	li     $a0, VM_NUM_SLOTS
	lui    $at, %hi(g_VmNumSlots)
	sh     $a0, %lo(g_VmNumSlots)($at)

	lui    $at, %hi(g_VmNumSlots2)
	sh     $a0, %lo(g_VmNumSlots2)($at)

	sll    $a0, $a0, VM_PAGE_SIZE_SHIFT

	lw     $v0, g_VmPhysicalSlots
	la     $t1, _gameSegmentEnd    # unused
	la     $t2, _gameSegmentStart  # unused
	subu   $t1, $t1, $t2           # unused
	li     $t0, 0x0fffffff
	and    $v0, $v0, $t0
	lui    $at, %hi(g_VmSlotsPhysicalAddr)
	sw     $v0, %lo(g_VmSlotsPhysicalAddr)($at)

	la     $v0, g_VmVacantBits
	li     $a0, VM_VACANTBITS_LEN - 1
	lui    $at, %hi(g_VmVacantFirstByte)
	sw     $v0, %lo(g_VmVacantFirstByte)($at)

	addu   $v1, $v0, $a0
	lui    $at, %hi(g_VmVacantLastByte)
	sw     $v1, %lo(g_VmVacantLastByte)($at)

	lw     $ra, 0x0($sp)
	addiu  $sp, $sp, 8
	jr     $ra
 	nop

glabel vm_init_vacant
	# Fill array with 0xff (ie. all vacant)
	li     $t0, 0xff
	lw     $v0, g_VmVacantFirstByte
	lw     $v1, g_VmVacantLastByte
.fill_loop:
	sb     $t0, 0x0($v0)
	bne    $v0, $v1, .fill_loop
	addiu  $v0, $v0, 1

	# Set the last byte with a partial bitmask based on the number of page slots
	li     $a0, VM_NUM_SLOTS % 8
	beqz   $a0, .after_remainder
	addiu  $a0, $a0, -1
	li     $t0, 2
	sllv   $t0, $t0, $a0
	addiu  $t0, $t0, -1
	sb     $t0, 0x0($v1)
.after_remainder:
	jr     $ra
 	nop

/**
 * vm_handle_miss is called from the exception handler when a request is made to
 * access a virtual memory address that isn't currently mapped in the TLB.
 * vm_handle_miss must load the page from ROM if not already loaded, then map it
 * in the TLB.
 *
 * In NTSC Final, there are 443 virtual pages, 268 slots where these can be loaded,
 * and 30 of these can be mapped in the TLB at the same time.
 */
glabel vm_handle_miss
	# C0_CONTEXT must be the 512-byte chunk index that was requested?
	# Convert it to a virtual address
	mfc0   $t0, C0_CONTEXT
	sll    $s5, $t0, 9
	li     $t1, VM_VIRTUAL_ADDR
	sub    $t0, $s5, $t1
	srl    $t0, $t0, VM_PAGE_SIZE_SHIFT  # t0 = virtual page index

	# Multiply t0 by 8 to get the V2P table offset
	sll    $t0, $t0, 3
	lw     $t1, g_VmVirtualToPhysicalTable
	addu   $s0, $t0, $t1  # s0 = pointer to V2P entry

	# Check that the requested address is within the virtual range
	li     $s8, VM_VIRTUAL_ADDR
	slt    $at, $s5, $s8
	bnez   $at, .out_of_range
 	nop
	lw     $t1, g_VmRamEnd
	slt    $at, $s5, $t1
	beqz   $at, .out_of_range
 	nop

#if VERSION < VERSION_NTSC_1_0
	# Increment g_VmNumTlbMisses
	la     $t2, g_VmNumTlbMisses
	lw     $t6, 0($t2)
	addiu  $t6, $t6, 1
	sw     $t6, 0($t2)
#endif

	# If the page index is even then read the current slot's unk00.
	# If the page index is odd then read from the next slot's unk00.
	mfc0   $t9, C0_BADVADDR
	srl    $t9, $t9, VM_PAGE_SIZE_SHIFT
	andi   $t9, $t9, 1
	beqzl  $t9, .after_odd_even_check1
	lw     $s1, 0x0($s0)
	lw     $s1, 0x8($s0)
.after_odd_even_check1:
	bnezl  $s1, .map_tlb  # Page is already loaded, so just map it
	li     $t5, 1
	li     $t5, 0
	lw     $t1, g_VmVacantFirstByte
	lw     $t2, g_VmVacantLastByte

	# Find any bit that is set in the byte array
.find_byte_loop:
	lbu    $t0, 0x0($t1)
	beqz   $t0, .after_bit_loop
 	nop
	li     $t6, 0
	li     $t7, 1
.find_bit_loop:
	and    $t8, $t0, $t7
	bnez   $t8, .use_empty_slot
 	nop
	addiu  $t6, $t6, 1
	li     $at, 8
	bne    $t6, $at, .find_bit_loop
	sll    $t7, $t7, 1
.after_bit_loop:
	bne    $t1, $t2, .find_byte_loop
	addiu  $t1, $t1, 1

	# All slots are allocated
	j      .choose_page_to_replace
 	nop

.use_empty_slot:
	# t0 is the available byte's value
	# t1 is a pointer to the available byte
	# t6 is the bit index (0-7) of the available bit
	# t7 is the bit power (1, 2, 4.. 128) of the available bit
	xor    $t0, $t0, $t7
	sb     $t0, 0x0($t1)
	lw     $t2, g_VmVacantFirstByte
	lw     $s1, g_VmSlotsPhysicalAddr
	subu   $t1, $t1, $t2  # t1 = byte index
	sll    $t1, $t1, 3    # t1 now a V2P table byte offset
	addu   $t0, $t6, $t1  # t0 = offset to V2P table entry
	sll    $t0, $t0, VM_PAGE_SIZE_SHIFT  # t0 now the virtual page index of the empty slot
	addu   $s1, $s1, $t0

.load_page:
#if VERSION < VERSION_NTSC_1_0
	# Increment g_VmNumPageMisses
	la     $t2, g_VmNumPageMisses
	lw     $t0, 0($t2)
	addiu  $t0, $t0, 1
	sw     $t0, 0($t2)
#endif

	# Calculate the offset of the entry in the zip table.
	# The zip table is an array of ROM offsets where each zip can be found.
	mfc0   $t2, C0_BADVADDR
	li     $t0, 0x01000000 - VM_PAGE_SIZE
	and    $t2, $t2, $t0
	srl    $t2, $t2, 10
	lw     $t0, g_VmZipTable
	addu   $t0, $t0, $t2

	lw     $t2, 0x0($t0)  # t2 = zip ROM start address
	lw     $t0, 0x4($t0)  # t0 = zip ROM end address
	subu   $t0, $t0, $t2  # t0 = zip length (compressed)

	# Align the zip length to 0x10
	li     $t1, 0xfffffff0
	addiu  $t0, $t0, 15
	and    $t6, $t0, $t1

	# Wait for the PI to be available
	li     $t0, PHYS_TO_K1(PI_STATUS_REG)
.wait_for_pi_ready_loop:
	lw     $t1, 0x0($t0)
	andi   $t1, $t1, PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY
	bnez   $t1, .wait_for_pi_ready_loop
 	nop

	# Check if the PI has a pending interrupt - this will be used after the DMA
	lw     $s6, PHYS_TO_K1(MI_INTR_REG)
	andi   $s6, $s6, MI_INTR_PI

	# Set PI_DRAM_ADDR_REG to g_VmZipBuffer (where the zip will be loaded to)
	li     $t0, PHYS_TO_K1(PI_DRAM_ADDR_REG)
	lw     $t1, g_VmZipBuffer
	li     $t7, 0x0fffffff
	and    $t1, $t1, $t7
	sw     $t1, 0x0($t0)

	# Set PI_CART_ADDR_REG to the ROM address of the zip
	li     $t0, PHYS_TO_K1(PI_CART_ADDR_REG)
	lw     $t1, osRomBase
	or     $t1, $t1, $t2
	li     $t2, 0x1fffffff
	and    $t1, $t1, $t2
	sw     $t1, 0x0($t0)

	# Set PI_WR_LEN_REG to the aligned size of the zip
	li     $t0, PHYS_TO_K1(PI_WR_LEN_REG)
	addiu  $t6, $t6, -1
	sw     $t6, 0x0($t0)

	beqzl  $t9, .after_odd_even_check2
 	nop
	beqzl  $zero, .pointless_branch
	sw     $s1, 0x8($s0)
.after_odd_even_check2:
	sw     $s1, 0x0($s0)

.pointless_branch:
	li     $t0, PHYS_TO_K1(PI_STATUS_REG)
.wait_for_pi_dma_completed_loop:
	lw     $t1, 0x0($t0)
	andi   $t1, $t1, PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY
	bnez   $t1, .wait_for_pi_dma_completed_loop
 	nop

	# Invalidate cache in the zip buffer area
	lw     $t0, g_VmZipBuffer
	addiu  $t1, $t0, VM_PAGE_SIZE
.invalidate_dcache_loop:
	cache  0x15, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .invalidate_dcache_loop
	addiu  $t0, $t0, 16

	# If the PI didn't previously have a pending interrupt,
	# make sure the above work hasn't triggered one
	bnez   $s6, .after_clear_pi_interrupt
 	nop
	li     $t0, PI_CLR_INTR
	lui    $at, %hi(PHYS_TO_K1(PI_STATUS_REG))
	sw     $t0, %lo(PHYS_TO_K1(PI_STATUS_REG))($at)

.after_clear_pi_interrupt:
	# Set stack pointer to g_VmTempStack
	la     $a0, g_VmTempStack
	addiu  $a0, $a0, 0xff8
	sw     $sp, 0x0($a0)
	addiu  $sp, $a0, 0

	# Prepare arguments for rzip_inflate
	lw     $a0, g_VmZipBuffer
	addiu  $a0, $a0, 2  # Move past the 2-byte checksum
	li     $t0, K0BASE
	or     $a1, $s1, $t0
	la     $a2, g_VmScratch

	# Save registers to the stack
	addiu  $sp, $sp, -0x80
	sw     $ra, 0x0($sp)
	sw     $at, 0x4($sp)
	sw     $v0, 0x8($sp)
	sw     $v1, 0xc($sp)
	sw     $a0, 0x10($sp)
	sw     $a1, 0x14($sp)
	sw     $a2, 0x18($sp)
	sw     $a3, 0x1c($sp)
	sw     $t0, 0x20($sp)
	sw     $t1, 0x24($sp)
	sw     $t2, 0x28($sp)
	sw     $t3, 0x2c($sp)
	sw     $t4, 0x30($sp)
	sw     $t5, 0x34($sp)
	sw     $t6, 0x38($sp)
	sw     $t7, 0x3c($sp)
	sw     $s0, 0x40($sp)
	sw     $s1, 0x44($sp)
	sw     $s2, 0x48($sp)
	sw     $s3, 0x4c($sp)
	sw     $s4, 0x50($sp)
	sw     $s5, 0x54($sp)
	sw     $s6, 0x58($sp)
	sw     $s7, 0x5c($sp)
	sw     $t8, 0x60($sp)
	sw     $t9, 0x64($sp)
	sw     $gp, 0x70($sp)
	sw     $sp, 0x74($sp)
	sw     $s8, 0x78($sp)

	# Unzip the zip
	jal    rzip_inflate
 	nop

	# Reload registers from the stack
	lw     $ra, 0x0($sp)
	lw     $at, 0x4($sp)
	lw     $v0, 0x8($sp)
	lw     $v1, 0xc($sp)
	lw     $a0, 0x10($sp)
	lw     $a1, 0x14($sp)
	lw     $a2, 0x18($sp)
	lw     $a3, 0x1c($sp)
	lw     $t0, 0x20($sp)
	lw     $t1, 0x24($sp)
	lw     $t2, 0x28($sp)
	lw     $t3, 0x2c($sp)
	lw     $t4, 0x30($sp)
	lw     $t5, 0x34($sp)
	lw     $t6, 0x38($sp)
	lw     $t7, 0x3c($sp)
	lw     $s0, 0x40($sp)
	lw     $s1, 0x44($sp)
	lw     $s2, 0x48($sp)
	lw     $s3, 0x4c($sp)
	lw     $s4, 0x50($sp)
	lw     $s5, 0x54($sp)
	lw     $s6, 0x58($sp)
	lw     $s7, 0x5c($sp)
	lw     $t8, 0x60($sp)
	lw     $t9, 0x64($sp)
	lw     $gp, 0x70($sp)
	lw     $sp, 0x74($sp)
	lw     $s8, 0x78($sp)
	addiu  $sp, $sp, 0x80

	# Restore the stack pointer
	la     $a0, g_VmTempStack
	addiu  $a0, $a0, 0xff8
	lw     $sp, 0x0($a0)

	# Invalidate the cache
	li     $t0, K0BASE
	or     $t0, $s1, $t0
	addiu  $t1, $t0, VM_PAGE_SIZE - 0x10
.invalidate_dcache_loop2:
	cache  0x19, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .invalidate_dcache_loop2
	addiu  $t0, $t0, 0x10

.map_tlb:
	li     $t0, OS_PM_4K
	mtc0   $t0, C0_PAGEMASK
	mtc0   $s5, C0_ENTRYHI
 	nop
 	nop
 	nop
 	tlbp
 	nop
 	nop
	mfc0   $t1, C0_INX
	mtc0   $t0, C0_PAGEMASK
	mtc0   $s5, C0_ENTRYHI
	lw     $t0, 0x0($s0)
	srl    $t0, $t0, VM_PAGE_SIZE_SHIFT
	sll    $t0, $t0, 6
	bnezl  $t0, .set_entrylo0
	ori    $t0, $t0, 0x1e
.set_entrylo0:
	mtc0   $t0, C0_ENTRYLO0
	lw     $t0, 0x8($s0)
	srl    $t0, $t0, VM_PAGE_SIZE_SHIFT
	sll    $t0, $t0, 6
	bnezl  $t0, .set_entrylo1
	ori    $t0, $t0, 0x1e
.set_entrylo1:
	mtc0   $t0, C0_ENTRYLO1
	bltzl  $t1, .write_random_tlb_entry
 	nop
	b      .after_write_tlb
 	tlbwi  # Replace TLB entry at index C0_INX
.write_random_tlb_entry:
 	tlbwr  # Replace a random TLB entry
.after_write_tlb:
	bnez   $t5, .after_invalidate_cache
 	nop
	move   $t0, $s5
	bnezl  $t9, .after_odd_even_check3
	addiu  $t0, $t0, VM_PAGE_SIZE
.after_odd_even_check3:
	addiu  $t1, $t0, VM_PAGE_SIZE - 0x20
	andi   $t2, $t0, 0x1f
	subu   $t0, $t0, $t2
.invalidate_dcache_loop3:
	cache  0x10, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .invalidate_dcache_loop3
	addiu  $t0, $t0, 0x20

.after_invalidate_cache:
	jr     $ra
 	nop

.choose_page_to_replace:
	# This part of the function chooses a loaded-but-unmapped slot to be replaced.
	# The physical address of the page is stored to s1, then it jumps to load_page.
#if VERSION < VERSION_NTSC_1_0
	# Increment g_VmNumPageReplaces
	la     $t0, g_VmNumPageReplaces
	lw     $t1, 0($t0)
	addiu  $t1, $t1, 1
	sw     $t1, 0($t0)
#endif

.evict_loop:
	# Choose a slot to evict. This is done by taking C0_COUNT & 0x1ff.
	# If this is still bigger than the number of pages then the number of pages
	# is subtracted from the value.
	lw     $s4, g_VmVirtualToPhysicalTable
	lw     $gp, g_VmVirtualToPhysicalTableEnd
	mfc0   $t0, C0_COUNT
	lhu    $t1, g_VmEvictMask
	lw     $t2, g_VmNumPages
	and    $t0, $t0, $t1
	slt    $at, $t0, $t2
	beqzl  $at, .after_subtract
	subu   $t0, $t0, $t2

.after_subtract:
	# Convert it to a V2P table offset
	sll    $t1, $t0, 3
	addu   $t1, $t1, $s4

	# Move forward through the table until a loaded slot is found.
	# If the end is reached, wrap back to the start.
.slot_loop:
	lw     $s1, 0x0($t1)
	bnez   $s1, .check_tlb_entry
 	nop
	addiu  $t1, $t1, 8
	bne    $t1, $gp, .slot_loop
 	nop
	j      .slot_loop
	move   $t1, $s4

.check_tlb_entry:
	# Query the TLB to make sure this page isn't currently mapped.
	# If it is then it must have been used recently, so find another page to replace.
	subu   $t0, $t1, $s4  # t0 is now an offset in the V2P table
	srl    $t0, $t0, 3    # t0 is now an index in the V2P table
	sll    $t0, $t0, VM_PAGE_SIZE_SHIFT  # t0 is now the byte offset in the physical slots
	addu   $t0, $t0, $s8                 # t0 += 0x7f000000
	li     $t2, 0x100000000 - VM_PAGE_SIZE
	and    $t0, $t0, $t2                 # t0 is now aligned to a page
	mtc0   $t0, C0_ENTRYHI
	li     $t0, OS_PM_4K
	mtc0   $t0, C0_PAGEMASK
 	nop
 	nop
 	nop
	# tlbp sets C0_INX to to the index of the TLB entry which has the given ENTRYHI
 	tlbp
 	nop
 	nop
	mfc0   $t2, C0_INX
	mfc0   $t0, C0_ENTRYHI
	bltz   $t2, .not_mapped
 	nop
	j      .evict_loop
 	nop

.not_mapped:
	# The page is not mapped in the TLB, so it's okay to replace it.
	sw     $zero, 0x0($t1)
	j      .load_page
 	nop

.out_of_range:
	j      handle_fault
 	nop

glabel vm_unmap_range
	mfc0   $t0, C0_ENTRYHI
	li     $t2, K0BASE
	mtc0   $t2, C0_ENTRYHI
	mtc0   $zero, C0_ENTRYLO0
	mtc0   $zero, C0_ENTRYLO1
.unmap_loop:
	mtc0   $a1, C0_INX
 	nop
 	tlbwi
 	nop
 	nop
	bne    $a1, $a0, .unmap_loop
	addi   $a1, $a1, -1
	mtc0   $t0, C0_ENTRYHI
	jr     $ra
 	nop

#if VERSION < VERSION_NTSC_1_0
glabel vm_invalidate_first_8kb
	li     $t0, K0BASE
	addiu  $t1, $t0, 0x1ff0
.invalidate_dcache_loop4:
	cache  0x1, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .invalidate_dcache_loop4
	addiu  $t0, $t0, 0x10
	jr     $ra
 	nop
#endif
