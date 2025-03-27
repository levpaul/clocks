CC = gcc
CFLAGS = -std=c99 -I.

.PHONY: clocks

clocks:
	$(CC) $(CFLAGS) *.c -o clocks

clean:
	rm clocks
