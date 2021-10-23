CC = gcc
CFLAGS = -g -Wall
OBJECTS = luck area rat

all: $(OBJECTS)

luck: luck_binarysearch.c
	$(CC) $(CFLAGS) $^ -o $@

area: area_pretoin.c
	$(CC) $(CFLAGS) $^ -o $@

rat: binary_search_tree.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./luck

do2:
	./area<testcase2

do3:
	./rat<testcase3

clean:
	rm $(OBJECTS)
