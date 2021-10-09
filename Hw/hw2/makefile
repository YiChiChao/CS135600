CC = gcc
CFLAGS = -g -Wall
OBJECTS = operation type tutor
all:$(OBJECTS)
type: typing.c
	$(CC) $(CFLAGS) $^ -o $@

operation: operation.c
	$(CC) $(CFLAGS) $^ -o $@

tutor: tutor.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./type 

do2:
	./operation

do3:
	./tutor

clean:
	rm $(OBJECTS)


