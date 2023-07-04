addi x5, x0, 10
addi x6, x0, 0
lw x8, 0(x6)
# handle operation 296
mul x7, x5, x8
addi x28, x0, 2
addi x29, x0, 1
# handle operation 294
add x30, x8, x29
# handle operation 297
div x31, x28, x30
# handle operation 294
add x5, x7, x31
add x8, x5, x0
add x9, x8, x0
addi x6, x0, 0
sw x8, 0(x6)
addi x7, x0, 4
sw x9, 0(x7)
