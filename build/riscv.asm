ADDi x5, x0, 0
ADD x8, x5, x0
ADDi x6, x0, 0
ADD x9, x6, x0
label_1:
ADDi x7, x0, 3
ADD x28, x8, x7
ADD x8, x28, x0
ADDi x29, x0, 1
ADD x30, x9, x29
ADD x9, x30, x0
ADDi x31, x0, 1
SUB x5, x9, x31
BEQ x0, x5, label_2
BEQ x0, x0, label_1
label_2:
ADDi x6, x0, 8
SW x8, 0(x6)
ADDi x7, x0, 12
SW x9, 0(x7)
