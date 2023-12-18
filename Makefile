# VARIABLES
CXX = g++
CXXFLAGS = -std=c++11 	##
CPPFLAGS = -I./src/objs ## -I represents an include statement
CC = gcc
# CFLAGS = 

LDLIBS = -lcrypto 		## -l represents a binary in ...(some folder in the FS) ...
HEADERS = $(wildcard src/*.h)
SRCS = $(wildcard src/*.cpp)
TEST = $(wildcard tests/*.c)
OBJS = $(SRCS:src/%.c=bin/%.o)
### TESTS = $(wildcard test/*.c)

# TARGET EXECUTABLES
MAIN_TARGET = csafe
DEBUG_TARGET = debug
TEST_TARGET = tests

# MAKE FUNCTIONS
## entry point for the make commmand
all: clean bin ${MAIN_TARGET}
	bin/csafe

## build the debug executable
debug: clean bin $(OBJS) 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) debug.cpp -o bin/$@ $(LDLIBS)
	bin/debug

unittest: clean bin bin/File.o $(TEST)
	$(CC) tests/unit/*.c -o bin/$@ -lcriterion bin/*.o
	bin/unittest

bin/File.o: src/File.c
	gcc -c $< -o $@


$(MAIN_TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o bin/$@ $(OBJS) $(LDLIBS)

bin/%.o: src/%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

## remove .o files and the executable
## -rf to recursively remove files from directory
clean:
	rm -rf bin output/*

## make binary directory
## -p for removing chance of errors
bin:
	mkdir -p bin

find:
	find ./output -type f -name "_*"

.PHONY: all clean

# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile