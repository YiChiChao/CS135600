CC = gcc
CFLAGS = -g -Wall
OBJECTS = dilema treasure potopre
all:$(OBJECTS)

dilema: dilema_matrixfpw.c
	$(CC) $(CFLAGS) $^ -o $@

treasure: treasure_prefixsum.c
	$(CC) $(CFLAGS) $^ -o $@

potopre: postorder_to_preorder.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./dilema<testcase1

do2:
	./treasure<testcase2

do3:
	./potopre<testcase3

	
clean:
	rm $(OBJECTS)
