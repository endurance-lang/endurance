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
ADDi x31, x0, 2
ADD x18, x31, x0
label_3:
BEQ x0, x18, label_4
BEQ x0, x0, label_5
label_6:
ADDi x5, x0, 1
SUB x6, x18, x5
ADD x18, x6, x0
BEQ x0, x0, label_3
label_5:
ADD x7, x8, x9
ADD x8, x7, x0
BEQ x0, x0, label_6
label_4:
ADDi x28, x0, 1
SUB x29, x9, x28
BEQ x0, x29, label_2
BEQ x0, x0, label_1
label_2:
ADDi x30, x0, 8
SW x8, 0(x30)
ADDi x31, x0, 12
SW x9, 0(x31)
ADDi x5, x0, 0
SW x18, 0(x5)
