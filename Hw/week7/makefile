CC = gcc
CFLAGS = -g -Wall
OBJECTS = dilema
all:$(OBJECTS)

dilema: dilema_matrixfpw.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./dilema<testcase1

	
clean:
	rm $(OBJECTS)
