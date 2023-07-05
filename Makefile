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

test-lex-error:
	./build/endurance < resources/lex-error.end

test-syn-error:
	./build/endurance < resources/syn-error.end

test-sem-error:
	./build/endurance < resources/sem-error.end

run:
	./build/endurance < $(FILE)

graphviz-image:
	dot -Tpng ./output/tree.dot -o ./output/tree.png