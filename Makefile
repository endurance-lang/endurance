OBJFILES = $(patsubst %.c, %.o, src/lib/lex.l)
TARGET   = ../../build/lex-endurance

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.yy.c lex.l && \
	bison -d -v -o translate.tab.c translate.y && \
	gcc *.c ../utils/print-source-code.c ../symbol-table/*.c ../risc-v/*.c ../pseudo/*.c -o ../../build/a.out

llvm:
	clang ./src/lib/translate.tab.c -emit-llvm -S -c -o ./build/endurance.ll
	llvm-as ./build/endurance.ll -o ./build/endurance.bc
	llc ./build/endurance.bc -o ./build/endurance.s
	clang ./build/endurance.s -o ./build/endurance.native
	
llvm-test:
	clang ./src/lib/translate.tab.c -emit-llvm -S -c -o ./build/endurance.ll
	clang -fPIE ./build/endurance.ll -o ./build/endurance.native


test-first:
	./build/a.out < resources/first.end

test-second:
	./build/a.out < resources/second.end

test-third:
	./build/a.out < resources/third.end

test-input:
	./build/a.out < resources/input.end

test-error:
	./build/a.out < resources/error.end

run:
	./build/a.out < $(FILE)