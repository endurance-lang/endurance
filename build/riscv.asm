ADDi x5, x0, 0
ADD x8, x5, x0
ADDi x6, x0, 0
ADD x9, x6, x0
label_1:
ADDi x7, x0, 3
SUB x28, x9, x7
BEQ x0, x28, label_2
BEQ x0, x0, label_3
label_4:
ADDi x29, x0, 1
ADD x30, x9, x29
ADD x9, x30, x0
BEQ x0, x0, label_1
label_3:
ADDi x31, x0, 2
ADD x5, x8, x31
ADD x8, x5, x0
BEQ x0, x0, label_4
label_2:
ADDi x6, x0, 4
SW x8, 0(x6)
ADDi x7, x0, 0
SW x9, 0(x7)
