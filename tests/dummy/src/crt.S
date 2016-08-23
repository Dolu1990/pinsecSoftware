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


  lui	a5,0xf0000
  addi	a5,a5,8
  li	a4,255
  sw	a4,0(a5)

  lui	a5,0xf0000
  li	a4,1
  sw	a4,0(a5)




  la sp, _stack_start

  jal ra, init_sections
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
