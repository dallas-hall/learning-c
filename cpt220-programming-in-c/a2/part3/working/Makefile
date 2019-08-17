# Compiler
CC=gcc

# Compile flags
CFLAGS=-Wall -ansi -pedantic

# Linking flags
# -lm is the math library
LFLAGS=-lm

# Target File
# The file(s) to compile to.
TARGETS=backgammon.out

# Source files
SOURCES=board.c game.c io.c main.c rules.c player.c bar_list.c helpers.c \
	scoreboard.c fileio.c linkedlist.c

# Header files
HEADERS=board.h game.h io.h main.h rules.h shared.h player.h bar_list.h \
	helpers.h scoreboard.h fileio.h linkedlist.h

# Object files
OBJECTS=board.o game.o io.o main.o rules.o player.o bar_list.o helpers.o \
	scoreboard.o fileio.o linkedlist.o

# all: is the first target in your Makefile. Typically points to your
# binary executable file
all:$(TARGETS)

# Linking
# Don't need flags here because they refer to code and linking.
# Note: the required tab below this line
# $^ refers to the name of the object(s)
# $@ refers to the name of the target(s)
$(TARGETS): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

# Compiling
# This is where the .o and .c check occurs to see if recompiling is needed
# The % is the wildcard here for all. We are getting all object, header, and source files.
# Note: the required tab below this lkine
# $^ refers to the name of the target(s)
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $^

# Debugging
debug:CFLAGS+=-g
debug:clean all

# Memory Address Sanitising
# Requires scl enable devtoolset-8 bash
sanitize:CFLAGS+=-fsanitize=address
sanitize:LFLAGS+=-fsanitize=address
sanitize:debug

# Clean Up From Previous Runs
# .PHONY means don't check anything
.PHONY:clean
clean:
	rm -f $(OBJECTS) $(TARGETS)

# Compression type
archiver=zip

#this target is provided to make it easier to zip up your program for submission
archive:
	$(archiver) ${USER} ${SOURCES} ${HEADERS} Makefile read.me

# Makefile usage
# Standard build = make clean all 
# Debugging build = make debug
# Address Sanitisation = make sanitize
# Creating Zip = make archive
