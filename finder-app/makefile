
CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)ld

writer: writer.o
	$(CC) -o writer writer.o

writer.o: writer.c
	$(CC) -c writer.c

clean:
	rm -f writer.o writer