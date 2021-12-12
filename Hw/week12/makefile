CC = gcc
CFLAGS = -g -Wall
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
OBJECTS = vector salary

all: $(OBJECTS)
vector: vector.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

salary: salary.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

do1:
	./vector

do2:
	./salary < testcase2

clean: rm $(OBJECTS)
