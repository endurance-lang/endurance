addi x5, x0, 10
add x8, x5, x0
addi x6, x0, 0
add x9, x6, x0
label_1:
addi x7, x0, 2
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
addi x31, x0, 0
add x18, x31, x0
label_5:
addi x5, x0, 2
# handle operation 304
slt x6, x18, x5
beq x0, x6, label_6
j label_7
label_8:
addi x7, x0, 1
# handle operation 294
add x28, x18, x7
add x18, x28, x0
j label_5
label_7:
addi x29, x0, 1
# handle operation 294
add x30, x8, x29
add x8, x30, x0
j label_8
label_6:
j label_4
label_2:
addi x31, x0, 8
sw x8, 0(x31)
addi x5, x0, 0
sw x9, 0(x5)
addi x6, x0, 4
sw x18, 0(x6)
