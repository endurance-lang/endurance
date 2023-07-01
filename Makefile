OBJFILES = $(patsubst %.c, %.o, src/lib/lex.l)
TARGET   = ../../build/lex-endurance

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.yy.c lex.l && \
	bison -d -v -o translate.tab.c translate.y && \
	gcc translate.tab.c lex.yy.c ../utils/print-source-code.c ../symbol-table/symbol.c ../symbol-table/symbolTable.c ../risc-v/*.c -o ../../build/a.out

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