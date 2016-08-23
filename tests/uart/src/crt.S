.macro retirq
custom0 0,0,0,0
.endm

.macro readtIrq rd
custom0 \rd,0,0,1
.endm

.macro writetIrqMask rs
custom0 0,\rs,0,2
.endm

.macro readtIrqMask rd
custom0 \rd,0,0,3
.endm


.global  trap_entry
trap_entry:
  nop
  addi sp,sp,-128

  sw gp,   0*4(sp)
  sw x1,   1*4(sp)
  sw x2,   2*4(sp)
  sw x3,   3*4(sp)
  sw x4,   4*4(sp)
  sw x5,   5*4(sp)
  sw x6,   6*4(sp)
  sw x7,   7*4(sp)
  sw x8,   8*4(sp)
  sw x9,   9*4(sp)
  sw x10, 10*4(sp)
  sw x11, 11*4(sp)
  sw x12, 12*4(sp)
  sw x13, 13*4(sp)
  sw x14, 14*4(sp)
  sw x15, 15*4(sp)
  sw x16, 16*4(sp)
  sw x17, 17*4(sp)
  sw x18, 18*4(sp)
  sw x19, 19*4(sp)
  sw x20, 20*4(sp)
  sw x21, 21*4(sp)
  sw x22, 22*4(sp)
  sw x23, 23*4(sp)
  sw x24, 24*4(sp)
  sw x25, 25*4(sp)
  sw x26, 26*4(sp)
  sw x27, 27*4(sp)
  sw x28, 28*4(sp)
  sw x29, 29*4(sp)
  sw x30, 30*4(sp)
  sw x31, 31*4(sp)
  nop
  readtIrq a0
  jal ra, irqCpp
  nop
  nop
  nop

  lw x1,   1*4(sp)
  lw x3,   3*4(sp)
  lw x4,   4*4(sp)
  lw x5,   5*4(sp)
  lw x6,   6*4(sp)
  lw x7,   7*4(sp)
  lw x8,   8*4(sp)
  lw x9,   9*4(sp)
  lw x10, 10*4(sp)
  lw x11, 11*4(sp)
  lw x12, 12*4(sp)
  lw x13, 13*4(sp)
  lw x14, 14*4(sp)
  lw x15, 15*4(sp)
  lw x16, 16*4(sp)
  lw x17, 17*4(sp)
  lw x18, 18*4(sp)
  lw x19, 19*4(sp)
  lw x20, 20*4(sp)
  lw x21, 21*4(sp)
  lw x22, 22*4(sp)
  lw x23, 23*4(sp)
  lw x24, 24*4(sp)
  lw x25, 25*4(sp)
  lw x26, 26*4(sp)
  lw x27, 27*4(sp)
  lw x28, 28*4(sp)
  lw x29, 29*4(sp)
  lw x30, 30*4(sp)
  lw x31, 31*4(sp)
  addi sp,sp,128
  retirq
  nop
  .text

  .align 9 
  .globl _start
_start:


  li  x1, 0
  li  x2, 0
  li  x3, 0
  li  x4, 0
  li  x5, 0
  li  x6, 0
  li  x7, 0
  li  x8, 0
  li  x9, 0
  li  x10,0
  li  x11,0
  li  x12,0
  li  x13,0
  li  x14,0
  li  x15,0
  li  x16,0
  li  x17,0
  li  x18,0
  li  x19,0
  li  x20,0
  li  x21,0
  li  x22,0
  li  x23,0
  li  x24,0
  li  x25,0
  li  x26,0
  li  x27,0
  li  x28,0
  li  x29,0
  li  x30,0
  li  x31,0

  nop
  nop
  nop
  nop
  nop
  nop

  li  x10,0xFF
  writetIrqMask x10

  la sp, _stack_start

  jal ra, init_bss
  jal ra, main


infinitLoop:
  j infinitLoop


.section ".tdata.begin"
.globl _tdata_begin
_tdata_begin:

.section ".tdata.end"
.globl _tdata_end
_tdata_end:

.section ".tbss.end"
.globl _tbss_end
_tbss_end:
