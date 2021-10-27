CC = gcc
CFLAGS = -g -Wall
OBJECTS = construct knuckles test
all:$(OBJECTS)

construct: construct_tree.c
	$(CC) $(CFLAGS) $^ -o $@

knuckles: knuckle_string.c
	$(CC) $(CFLAGS) $^ -o $@

test: test.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./construct

do2:
	./knuckles

do3:
	./test
	
clean:
	rm $(OBJECTS)
