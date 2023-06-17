OBJFILES = $(patsubst %.c, %.o, src/lib/lex.l)
TARGET   = ../../build/lex-endurance

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.yy.c lex.l && \
	bison -d -o translate.tab.c translate.y && \
	gcc translate.tab.c lex.yy.c -o ../../build/a.out

test-first:
	./build/a.out < resources/first.end

test-second:
	./build/a.out < resources/second.end

test-third:
	./build/a.out < resources/third.end

test-fourth:
	./build/a.out < resources/fourth.end