OBJFILES = $(patsubst %.c, %.o, src/lib/lex.l)
TARGET   = lex-xd

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.yy.c lex.l && \
	gcc lex.yy.c -o ../../build/a.out

test-first:
	./build/a.out < resources/first.end

test-second:
	./build/a.out < resources/second.end

test-third:
	./build/a.out < resources/third.end