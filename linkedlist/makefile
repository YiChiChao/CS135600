CC = gcc
CFLAGS = -g -Wall
OBJECTS = cir dou

all:$(OBJECTS)

cir: circular_linkedlist.c
	$(CC) $(CFLAGS) $^ -o $@

dou: double_pointer.c
	$(CC) $(CFLAGS) $^ -o $@

do_cir:
	./cir

do_dou:
	./dou

clean:
	rm $(OBJECTS)
