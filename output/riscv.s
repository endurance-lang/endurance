addi x5, x0, 1
addi x6, x0, 2
# handle operation 304
slt x7, x5, x6
beq x0, x7, label_1
addi x28, x0, 10
add x8, x28, x0
addi x29, x0, 10
# handle operation 308
xor x30, x8, x29
seqz x30, x30
beq x0, x30, label_3
addi x31, x0, 30
add x9, x31, x0
beq x0, x0, label_4
label_3:
addi x5, x0, 40
add x18, x5, x0
label_4:
beq x0, x0, label_2
label_1:
addi x6, x0, 20
add x19, x6, x0
label_2:
addi x7, x0, 0
sw x8, 0(x7)
addi x28, x0, 4
sw x9, 0(x28)
addi x29, x0, 8
sw x18, 0(x29)
addi x30, x0, 12
sw x19, 0(x30)
