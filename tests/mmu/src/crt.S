#define regnum_x0   0
#define regnum_x1   1
#define regnum_x2   2
#define regnum_x3   3
#define regnum_x4   4
#define regnum_x5   5
#define regnum_x6   6
#define regnum_x7   7
#define regnum_x8   8
#define regnum_x9   9
#define regnum_x10 10
#define regnum_x11 11
#define regnum_x12 12
#define regnum_x13 13
#define regnum_x14 14
#define regnum_x15 15
#define regnum_x16 16
#define regnum_x17 17
#define regnum_x18 18
#define regnum_x19 19
#define regnum_x20 20
#define regnum_x21 21
#define regnum_x22 22
#define regnum_x23 23
#define regnum_x24 24
#define regnum_x25 25
#define regnum_x26 26
#define regnum_x27 27
#define regnum_x28 28
#define regnum_x29 29
#define regnum_x30 30
#define regnum_x31 31

#define regnum_zero 0
#define regnum_ra   1
#define regnum_sp   2
#define regnum_gp   3
#define regnum_tp   4
#define regnum_t0   5
#define regnum_t1   6
#define regnum_t2   7
#define regnum_s0   8
#define regnum_s1   9
#define regnum_a0  10
#define regnum_a1  11
#define regnum_a2  12
#define regnum_a3  13
#define regnum_a4  14
#define regnum_a5  15
#define regnum_a6  16
#define regnum_a7  17
#define regnum_s2  18
#define regnum_s3  19
#define regnum_s4  20
#define regnum_s5  21
#define regnum_s6  22
#define regnum_s7  23
#define regnum_s8  24
#define regnum_s9  25
#define regnum_s10 26
#define regnum_s11 27
#define regnum_t3  28
#define regnum_t4  29
#define regnum_t5  30
#define regnum_t6  31

#define r_type_insn(_f7, _rs2, _rs1, _f3, _rd, _opc) \
.word (((_f7) << 25) | ((_rs2) << 20) | ((_rs1) << 15) | ((_f3) << 12) | ((_rd) << 7) | ((_opc) << 0))

#define mmuw0(_data) \
r_type_insn(0b0000000, 0, regnum_ ## _data, 0b111, 0, 0b0001111)

#define mmuw1(_data, _addr) \
r_type_insn(0b0000001, regnum_ ## _data, regnum_ ## _addr, 0b111, 0, 0b0001111)


  j _start
  nop
  nop
  nop
  nop
  nop
  nop
  nop

.global  trap_entry
trap_entry:
  csrr x28, mcause
  csrr x28, mbadaddr
  li x29, 0x000C4000
  li x30, 0xF0010000
  li x31, 0x4
  mmuw0(x29)
  mmuw1(x30, x31)
  mret
  
  
  .text
  .globl _start
_start:
  li x28, 1
  li x6, 31
mmuInitLoop:
  addi x6, x6, -1
  mmuw1(x0, x6)
  bnez x6, mmuInitLoop
  
  li x28, 2
  li x4, 0x000C0000
  li x5, 0xF0010000
  li x6, 0x0
  mmuw0(x4)
  mmuw1(x5, x6)

  li x4, 0x000C1000
  li x5, 0xF0010000
  li x6, 0x1
  mmuw0(x4)
  mmuw1(x5, x6)

  li x4, 0x000C2000
  li x5, 0xF0020000
  li x6, 0x2
  mmuw0(x4)
  mmuw1(x5, x6)

  li x4, 0x000C3000
  li x5, 0xF0020000
  li x6, 0x3
  mmuw0(x4)
  mmuw1(x5, x6)
  li x28, 3


  li x4 , 0x10000000
  li x5 , 0xC0000000
  li x6 , 0xC1000000
  li x7 , 0x20000000
  li x8 , 0xC2000000
  li x9 , 0xC3000000
  li x10, 0xC4000000
  li x12, 0x11111111
  li x13, 0x22222222
  li x14, 0x33333333
  sw x12, 0(x4)
  lw x28, 0(x4)
  lw x28, 0(x5)
  lw x28, 0(x6)
  sw x13, 256(x7)
  lw x28, 256(x7)
  lw x28, 256(x8)
  lw x28, 256(x9)
  li x28, 4

  lw x28, 0(x4)
  sw x14, 0(x6)
  lw x28, 0(x5)
  lw x28, 0(x4)

  li x28, 5


  lw x28, 0(x10)
  li x28, 6
  li x28, 7
  li x4, 0x000C6000
  li x5, 0xF0000000
  li x6, 0x1F
  mmuw0(x4)
  mmuw1(x5, x6)
  nop
  nop
  nop
  nop
  nop
  li x4, 0xC6000000
  jr x4
  
  
  nop
  nop
  nop
  nop
  nop
  
