.rsp

// OSTask placed at end of DMEM (IMEM_START - sizeof(OSTask))
.definelabel OSTask_addr, 0xfc0

// OSTask data member offsets
OSTask_flags           equ 0x04
OSTask_ucode           equ 0x10
OSTask_ucode_size      equ 0x14
OSTask_ucode_data      equ 0x18
OSTask_ucode_data_size equ 0x1c

OS_TASK_DP_WAIT        equ 0x0002

// RDP Status read flags
DPC_STATUS_DMA_BUSY    equ 0x0100

.create CODE_FILE, 0x04001000

    j     rdpcheck
     addi  at, zero, OSTask_addr

ucodeload:
    lw    v0, OSTask_ucode(at)
    addi  v1, zero, 0x0f7f
    addi  a3, zero, 0x1080
    mtc0  a3, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN

ucodeloadloop:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, ucodeloadloop
     nop
    jal   checkyield
     nop
    jr    a3
     mtc0  zero, SP_SEMAPHORE

checkyield:
    mfc0  t0, SP_STATUS
    andi  t0, t0, 0x0080
    bne   t0, zero, Yield
     nop
    jr    ra

Yield:
     mtc0  zero, SP_SEMAPHORE
    ori   t0, zero, 0x5200
    mtc0  t0, SP_STATUS
    break
    nop

rdpcheck:
    lw    v0, OSTask_flags(at)
    andi  v0, v0, OS_TASK_DP_WAIT
    beq   v0, zero, rdpwait
     nop
    jal   checkyield
     nop
    mfc0  v0, DPC_STATUS
    andi  v0, v0, DPC_STATUS_DMA_BUSY
    bgtz  v0, checkyield
     nop

rdpwait:
    lw    v0, OSTask_ucode_data(at)
    lw    v1, OSTask_ucode_data_size(at)
    addi  v1, v1, -1

DMEMLoad:
    mfc0  s8, SP_DMA_FULL
    bne   s8, zero, DMEMLoad
     nop
    mtc0  zero, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN

dmaloop:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, dmaloop
     nop
    jal   checkyield
     nop
    j     ucodeload
     nop
    nop

.close // CODE_FILE
