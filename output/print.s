j main

printf: # receive a value to print on a1
li a0, 1
ecall
li a0, 11
li a1, '\n'
ecall
ret

scanf: # read a value and return in a1
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

programExit:
li a0, 10
ecall

main:
jal x1, scanf
jal x1, printf
j programExit