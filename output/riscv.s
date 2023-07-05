j main

# receive a value to print on a1
printf:
li a0, 1
ecall
li a0, 11
li a1, '\n'
ecall
ret

# read a value and return in a1
scanf:
li t0, 0
li a0, 0x130 # activate terminal input
ecall
scanfPollInt:
addi a1, x0, 0 # reset a1
addi a0, x0, 0x131 # read input in a1
ecall
beqz a0, scanfReturn # if all input read, exit
li t1, 0x00000001
beq a0, t1, scanfPollInt # keep waiting for input
li t1, 10
mul t0, t0, t1
add t0, t0, a1
addi t0, t0, -48
j scanfPollInt
scanfReturn:
mv a1, t0
ret

# exit program
programExit:
li a0, 10
ecall

# main code here
main:
<<<<<<< HEAD
addi x5, x0, 8
add x8, x5, x0
label_1:
addi x6, x0, 10
# handle operation 304
slt x7, x8, x6
beq x0, x7, label_2
j label_3
label_3:
addi x28, x0, 1
# handle operation 294
add x29, x8, x28
add x8, x29, x0
j label_1
label_2:
addi x30, x0, 0
sw x8, 0(x30)
=======
addi x5, x0, 10
add x8, x5, x0
addi x6, x0, 0
sw x8, 0(x6)
>>>>>>> ac39d6660788dc8411e49a58a53b0dc41d16d31e
j programExit
