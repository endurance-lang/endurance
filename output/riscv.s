addi x5, x0, 10
add x8, x5, x0
li a0, 1
li a1, 42
ecall
addi x6, x0, 0
sw x8, 0(x6)
