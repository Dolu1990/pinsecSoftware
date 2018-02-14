li x1, 10
li x2, 20
li x3, 30
ebreak
add x3,x1,x2
ebreak
addi x3, x3, 1
addi x3, x3, 10
addi x3, x3, 100
ebreak
li x29, 0x80000010
jalr x29,0(x1)
