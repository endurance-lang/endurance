.data
progaddr:   .word 0

.text
li a0, 9        # alloc
li a1, 4096     # 4096 bytes
ecall           
la t1, progaddr
sw a0, 0(t1)    # save in progaddr the program address space in heap



exit_program:
li a0, 10
ecall