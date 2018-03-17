CC = g++
CC_FLAGS = -Wall -ansi -pedantic -std=c++11 -03

EXECUTABLE = main
SOURCEDIR = src
BUILDDER = bin

SOURCE = $(wildcard(SOURCEDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(OBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) src/main.cpp -o bin/rshell

main: $(OBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) src/main.cpp -o $(BUILDDIR)/$(EXECTABLE)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXECTABLE) src/main/cpp
	rm -rf $(BUILDDIR)

