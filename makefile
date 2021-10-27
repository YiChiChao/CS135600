CC = gcc
CFLAGS = -g -Wall
OBJECTS = matrix

all: $(OBJECTS)

matrix: practice_matrixmult.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./matrix


clean:
	rm $(OBJECTS)
