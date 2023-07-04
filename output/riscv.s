addi x5, x0, 8
add x8, x5, x0
label_1:
addi x6, x0, 10
# handle operation 304
slt x7, x8, x6
beq x0, x7, label_2
j label_3
label_3:
addi x28, x0, 10
add x9, x28, x0
addi x29, x0, 1
# handle operation 294
add x30, x8, x29
add x8, x30, x0
j label_1
label_2:
addi x31, x0, 0
sw x8, 0(x31)
addi x5, x0, 4
sw x9, 0(x5)
