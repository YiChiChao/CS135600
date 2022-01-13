CC = gcc
CFLAGS = -g -Wall
CXX = g++
CXXFLAGS = -g -Wall -std=c++11
OBJECTS = name triangle
all: $(OBJECTS)

name: name_new.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

triangle: test.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./name < testcase1
do2:
	./triangle < testcase3
clean:
	rm $(OBJECTS)