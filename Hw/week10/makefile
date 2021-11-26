CC = gcc
CFLAGS = -g -Wall
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
OBJECTS = break cat bonus

all: $(OBJECTS)
break: break_set.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

cat: point_dfs.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

bonus: bonus.c
	$(CC) $(CFLAGS) $^ -o $@

do1:
	./break

do2:
	./cat

do3:
	./bonus<testcase

clean:
	rm $(OBJECTS) 