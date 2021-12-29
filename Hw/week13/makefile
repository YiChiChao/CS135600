CXX = g++
CXXFLAGS = -g -Wall -std=c++14
OBJECTS = bonus people coffee choose

all: $(OBJECTS)

bonus: bonus3.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

people: people.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

coffee: coffee_greedy.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

choose: choose.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
do1:
	./bonus < testcase1
do2:
	./people < testcase2

do3:
	./coffee < testcase3
do4:
	./choose < testcase4