addi x5, x0, 1
add x8, x5, x0
addi x6, x0, 0
add x9, x6, x0
label_1:
addi x7, x0, 3
# handle operation 304
slt x28, x9, x7
beq x0, x28, label_2
j label_3
label_4:
addi x29, x0, 1
# handle operation 294
add x30, x9, x29
add x9, x30, x0
j label_1
label_3:
addi x31, x0, 2
# handle operation 296
mul x5, x8, x31
add x8, x5, x0
j label_4
label_2:
addi x6, x0, 4
sw x8, 0(x6)
addi x7, x0, 0
sw x9, 0(x7)
nop