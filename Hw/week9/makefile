CC = gcc
CFLAGS = -g -Wall
OBJECTS = rat thano

all: $(OBJECTS)

rat: rat2_tree.c
	$(CC) $(CFLAGS) $^ -o $@

thano: thano_bs.c
	$(CC) $(CFLAGS) $^ -o $@
do1:
	./rat

do2:
	./thano

clean:
	rm $(OBJECTS)