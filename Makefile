CC = gcc
CFLAGS = -std=c99

.PHONY: clocks

clocks:
	$(CC) $(CFLAGS) main.c -o clocks

clean:
	rm clocks
