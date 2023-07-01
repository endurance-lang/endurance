ADDi x5, x0, 0
ADD x8, x5, x0
label_1:
ADDi x6, x0, 3
SUB x7, x8, x6
BEQ x0, x7, label_2
ADDi x28, x0, 1
ADD x29, x8, x28
ADD x8, x29, x0
BEQ x0, x0, label_1
label_2:
ADDi x30, x0, 0
SW x8, 0(x30)
