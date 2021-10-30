CC = gcc
CFLAGS = -g -Wall
OBJECTS = dilema treasure potopre chicken
all:$(OBJECTS)

dilema: dilema_matrixfpw.c
	$(CC) $(CFLAGS) $^ -o $@

treasure: treasure_prefixsum.c
	$(CC) $(CFLAGS) $^ -o $@

potopre: postorder_to_preorder.c
	$(CC) $(CFLAGS) $^ -o $@

chicken: chicken.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./dilema<testcase1

do2:
	./treasure<testcase2

do3:
	./potopre<testcase3

do4:
	./chicken<testcase4

	
clean:
	rm $(OBJECTS)
