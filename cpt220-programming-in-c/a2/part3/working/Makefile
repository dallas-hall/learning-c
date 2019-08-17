# Compiler to use
CC=gcc

# Compiler flags to use
CFLAGS=-Wall -ansi -pedantic

# Linking flags to use
# -lm is the math library
LFLAGS=-lm

# Executable binary file(s) to build
TARGETS=backgammon.out

# Source files to use
SOURCES=board.c game.c io.c main.c rules.c player.c bar_list.c helpers.c \
	scoreboard.c fileio.c linkedlist.c

# Header files to use
HEADERS=board.h game.h io.h main.h rules.h shared.h player.h bar_list.h \
	helpers.h scoreboard.h fileio.h linkedlist.h

# Object files to use
OBJECTS=board.o game.o io.o main.o rules.o player.o bar_list.o helpers.o \
	scoreboard.o fileio.o linkedlist.o

# all: is the first target in your Makefile. Typically points to your
# binary executable file
all:$(TARGETS)

# Linking the files
# The object files on the right are required to compile the program's assembly files.
# Timestamps are used here to work out which files to recompile.
# Note: the required tab below the first line.
# $^ refers to the name of the object file(s)
# $@ refers to the name of the target file(s)
$(TARGETS): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

# Compiling the file
# The % is the wildcard here for all. We are getting all object, header, and source files.
# All object files (%.o) require matching source (%.c) and header files $(HEADERS).
# Note: the required tab below the first line
# $< refers to the first argument in the %.o:%.c $(HEADERS) line.
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

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
	$(RM) -f $(OBJECTS) $(TARGETS)

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
