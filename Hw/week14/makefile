CXX = g++
CXXFLAGS = -g -Wall -std=c++14
OBJECTS = left perfect wall

all: $(OBJECTS)

left: LR.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

perfect: perfect.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

wall: wall.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


do1:
	./left < testcase1

do2:
	./perfect < testcase2

do3:
	./wall < testcase3
