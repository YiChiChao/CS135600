CC = gcc
CFLAGS = -g -Wall
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
OBJECTS = vector salary cat lyrics bonus

all: $(OBJECTS)
vector: vector2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

salary: salary.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

cat: cat.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

lyrics: lyrics.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

bonus: bonus.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./vector < testcase1

do2:
	./salary < testcase2

do3:
	./cat < testcase3
do4:
	./lyrics < testcase4
do5:
	./bonus < testcase5

clean: 
	rm $(OBJECTS)
