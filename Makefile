# VARIABLES
CXX = g++
CXXFLAGS = -std=c++11 	##
CPPFLAGS = -I./src/objs ## -I represents an include statement
LDLIBS = -lcrypto 		## -l represents a binary in ...
HEADERS = $(wildcard src/*.h)
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.c=bin/%.o)
### TESTS = $(wildcard test/*.c)

# TARGET EXECUTABLES
MAIN_TARGET = csafe
DEBUG_TARGET = debug

# MAKE FUNCTIONS
## entry point for the make commmand
all: clean bin ${MAIN_TARGET}
	bin/csafe

## build the debug executable
debug: clean bin $(OBJS) 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) debug.cpp -o bin/$@ $(LDLIBS)
	bin/debug

$(MAIN_TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o bin/$@ $(OBJS) $(LDLIBS)

## remove .o files and the executable
## -rf to recursively remove files from directory
clean:
	rm -rf bin 

## make binary directory
## -p for removing chance of errors
bin:
	mkdir -p bin

.PHONY: all clean

# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile