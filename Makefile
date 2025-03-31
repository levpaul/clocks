CC = gcc
CFLAGS = -std=c99 -I.

.PHONY: clocks run

build:
	mkdir build

run: clocks
	./clocks

clocks: build
	$(CC) $(CFLAGS) *.c -o build/clocks

clean:
	rm clocks
