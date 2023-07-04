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
jal x1, scanf
add x8, x11, x0
jal x1, scanf
addi x5, x0, 0
sw x8, 0(x5)
j programExit
