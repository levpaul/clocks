CC = gcc
CFLAGS = -std=c99 -I. -Wall -Werror

.PHONY: clocks run clean

build:
	mkdir -p build

run: clocks
	./build/clocks

clocks: build
	$(CC) $(CFLAGS) *.c -o build/clocks

clean:
	rm -rf build
