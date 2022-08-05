SOURCES=board.c game.c io.c main.c rules.c player.c bar_list.c helpers.c \
	scoreboard.c fileio.c linkedlist.c
HEADERS=board.h game.h io.h main.h rules.h shared.h player.h bar_list.h \
	helpers.h scoreboard.h fileio.h linkedlist.h

archiver=zip

#this target is provided to make it easier to zip up your program for submission
archive:
	$(archiver) ${USER} ${SOURCES} ${HEADERS} Makefile read.me


