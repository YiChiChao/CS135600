CC = gcc
CFLAGS = -g -Wall
OBJECTS = rat thano min

all: $(OBJECTS)

rat: rat2_tree.c
	$(CC) $(CFLAGS) $^ -o $@

thano: thano_bs.c
	$(CC) $(CFLAGS) $^ -o $@

min: min_rectangle.c
	$(CC) $(CFLAGS) $^ -o $@
do1:
	./rat

do2:
	./thano

do3:
	./min
clean:
	rm $(OBJECTS)