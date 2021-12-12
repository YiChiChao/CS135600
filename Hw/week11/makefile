CC = gcc
CFLAGS = -g -Wall
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
OBJECTS = test gordan  try big

all: $(OBJECTS)
test: test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

gordan: gordan_iosteam.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

big: bigdigit_class.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

try: try.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@



do1:
	./test

do2:
	./gordan
do3:
	./big < testcase3
do4:
	./try



clean:
	rm $(OBJECTS) 