# VARIABLES
CC = gcc
CFLAGS = -g -lcriterion -Wall
LDLIBS = -lcrypto  		## -l represents a binary in ...(some folder in the FS) ...

HEADERS = $(wildcard src/*.h)
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=bin/%.o)

UNITTESTS = $(wildcard tests/unit/*.c)
TESTOBJS = $(filter-out bin/main.o, $(SRCS:src/%.c=bin/%.o))

# TARGET EXECUTABLES
MAIN_TARGET = csafe
DEBUG_TARGET = debug
TEST_TARGET = tests

# MAKE FUNCTIONS
## entry point for the make commmand
all: clean mkdir ${MAIN_TARGET} clear
	bin/csafe

Wall: clean mkdir ${MAIN_TARGET}

## build the debug executable
debug: clean mkdir $(TESTOBJS) clear
	$(CC) $(CFLAGS) $@.c -o bin/$@ $(TESTOBJS) $(LDLIBS)
	bin/$@

unittest: clean mkdir $(TESTOBJS) $(UNITTESTS) clear
	$(CC) $(CFLAGS) $(UNITTESTS) -o bin/$@ $(TESTOBJS) $(LDLIBS)
	bin/$@
	rmdir output

$(MAIN_TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o bin/$@ $(OBJS) $(LDLIBS)

bin/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

## remove .o files and the executable
## -rf to recursively remove files from directory
clean:
	rm -rf bin output

clear:
	clear

## make binary directory
## -p for removing chance of errors
mkdir:
	mkdir -p bin output

find:
	find ./output -type f -name "_*"

.PHONY: all clean

# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile