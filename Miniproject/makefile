CC = gcc
CFLAGS = -g -Wall
OBJECTS = binaryexp pretoin syntax

all: $(OBJECTS)

binaryexp: Binary_exp.c
	$(CC) $(CFLAGS) $^ -o $@

pretoin: prefix_to_infix.c
	$(CC) $(CFLAGS) $^ -o $@

syntax: syntax.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./binaryexp<test

do2:
	./pretoin

do3:
	./syntax

clean:
	rm $(OBJECTS)