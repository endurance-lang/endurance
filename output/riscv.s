addi x5, x0, 0
add x8, x5, x0
label_1:
label_3:
addi x6, x0, 1
# handle operation 294
add x7, x8, x6
add x8, x7, x0
addi x28, x0, 3
# handle operation 304
slt x29, x8, x28
beq x0, x29, label_2
j label_3
label_2:
addi x30, x0, 0
sw x8, 0(x30)
