OBJFILES = $(patsubst %.c, %.o, src/lib/lex.l)
TARGET   = ../../build/lex-endurance

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.yy.c lex.l && \
	bison -d -v -o translate.tab.c translate.y && \
	gcc *.c ../utils/print-source-code.c ../symbol-table/*.c ../risc-v/*.c ../pseudo/*.c -o ../../build/endurance

test-first:
	./build/endurance < resources/first.end

test-second:
	./build/endurance < resources/second.end

test-third:
	./build/endurance < resources/third.end

test-input:
	./build/endurance < resources/input.end

test-error:
	./build/endurance < resources/error.end

run:
	./build/endurance < $(FILE)

test-graphviz:
	./build/endurance < resources/graphviz.end

graphviz-image:
	dot -Tpng ./output/tree.dot -o ./output/tree.png