CC = gcc
CFLAGS = -std=c99 -I.

.PHONY: clocks run

run: clocks
	./clocks

clocks:
	$(CC) $(CFLAGS) *.c -o clocks

clean:
	rm clocks
