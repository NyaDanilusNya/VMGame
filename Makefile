CC = clang
LDFLAGS = -lSDL2 -lSDL2_image -lm -lpng -lz
CFLAGS = -Wall -Wextra -Wpedantic
OUT = bin/main
IN = src/main.c src/graphics.c src/game.c src/fonts.c

all: build run

build:
	$(CC) -o $(OUT) $(IN) $(CFLAGS) -O2 $(LDFLAGS)

debug:
	$(CC) -o $(OUT) $(IN) $(CFLAGS) -O0 -g $(LDFLAGS)

run:
	cd bin && ./main; cd ..

g:
	$(CC) -o $(OUT) $(IN) -Og -ggdb $(LDFLAGS)
	cd bin && gdb -q ./main; cd ..

v:
	$(CC) -o $(OUT) $(IN) -O0 -g $(LDFLAGS)
	cd bin && valgrind ./main; cd ..
