ADDi x5, x0, 1
ADD x8, x5, x0
ADDi x6, x0, 0
ADD x9, x6, x0
BEQ x0, x8, label_1
BEQ x0, x9, label_3
ADDi x7, x0, 1
ADD x18, x7, x0
BEQ x0, x0, label_4
label_3:
ADDi x28, x0, 2
ADD x18, x28, x0
label_4:
BEQ x0, x0, label_2
label_1:
ADDi x29, x0, 3
ADD x18, x29, x0
label_2:
ADDi x30, x0, 4
ADD x18, x30, x0
ADDi x31, x0, 0
SW x8, 0(x31)
ADDi x5, x0, 4
SW x9, 0(x5)
ADDi x6, x0, 8
SW x18, 0(x6)
