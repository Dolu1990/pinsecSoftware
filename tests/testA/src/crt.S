  
.macro nopFill
  nop
  nop
  nop
  nop
  nop
  nop
  nop
.endm

.macro interTest
  nopFill
  nopFill
  nopFill
.endm

.macro none
.endm

.macro testA1 interInstr
  \interInstr
  la x1, 10
  \interInstr
  la x2, 20
  \interInstr
  addi x3, x1, 30
  \interInstr
  add x4, x3, x2
  \interInstr
.endm

.macro testA2 interInstr name
  \interInstr
  la x5, 1
  \interInstr
  j \name
  \interInstr
  la x6, 2
  \interInstr
\name:  
  la x7, 3
  \interInstr
.endm

  testA1 nopFill
  testA1 none
  interTest
  testA2 nopFill testA2WithNop
  testA2 none testA2WithoutNop