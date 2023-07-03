addi a0, x0, 0x130 # activate terminal input
ecall
jal pollInt

exit:
li a0, 11
li a1, '\n'
ecall
addi a0, x0, 10 # exit
ecall

pollInt:
addi a1, x0, 0 # reset a1
addi a0, x0, 0x131 # read input in a1
ecall
beq a0, x0, exit # if all input read, exit
addi t1, x0, 0x00000001
beq a0, t1, pollInt # keep waiting for input
addi a0, x0, 11 # If we have input we echo it in the console
ecall   # If we have input we echo it in the console
j pollInt