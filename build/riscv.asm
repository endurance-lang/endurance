ADDi x5, x0, 0
ADD x8, x5, x0
BEQ x0, x8, label_1
ADDi x6, x0, 1
ADD x7, x8, x6
ADD x9, x7, x0
BEQ x0, x0, label_2
label_1:
ADDi x28, x0, 10
ADD x9, x28, x0
label_2:
ADDi x29, x0, 0
SW x8, 0(x29)
ADDi x30, x0, 4
SW x9, 0(x30)
