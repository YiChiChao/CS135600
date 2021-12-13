CC = gcc
CFLAGS = -g -Wall
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
OBJECTS = vector salary cat lyrics

all: $(OBJECTS)
vector: vector.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

salary: salary.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

cat: cat.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

lyrics: lyrics.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

do1:
	./vector

do2:
	./salary < testcase2

do3:
	./cat < testcase3
do4:
	./lyrics < testcase4

clean: 
	rm $(OBJECTS)
