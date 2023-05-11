OBJFILES = $(patsubst %.c, %.o, src/lib/lex.l)
TARGET   = lex-xd

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.yy.c lex.l && \
	gcc lex.yy.c -o ../../build/a.out

test:
	./build/a.out < resources/1.txt