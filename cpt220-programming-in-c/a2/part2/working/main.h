/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "game.h"
#include "player.h"
#include "scoreboard.h"
#include "fileio.h"
#include <errno.h>
#include <stdlib.h>

/**
 * enum that specifies the number of arguments that should be passed into this
 * program - note that this is changed for assignment 2
 **/
enum
{
	MINARGS = 1,
	MAXARGS
};

/*
 * Updated for the input file path.
 */
#define FILE_PATH_ARG 1
#define SEED_ARG 2

/**
 * assignment 2 data structures
 **/
/**
 * number of main menu items
 **/
#define NUM_MAIN_MENU_ITEMS 4
/**
 * enum of all the main menu items
 **/
enum main_menu_choice
{
	MMC_PLAY,
	MMC_SCORES,
	MMC_ABORT,
	MMC_QUIT,
	MMC_INVALID
};

/* forwards declaration of the game_system so we can declare pointers to one
 * until we declare the game_system itself */
struct game_system;

/**
 * a main menu item - consists of menu text and a pointer to the function that
 * implements that functionality
 **/
struct main_menu_entry
{
	char text[LINE_LEN + 1];

	void (* function)(struct game_system*);
};

/**
 * the menu system for our application - there is the menu in main and the
 * menu for managing the scoreboard
 **/
struct menu_system
{
	struct main_menu_entry main_menu[NUM_MAIN_MENU_ITEMS];
	struct scores_menu_entry scores_menu[NUM_SCORES_MENU_ITEMS];
};

/**
 * the core data structure for the application. It contains the menus, the
 * result of a game, the file name of the data file that contains the scores
 * that we are currently manipulating and the seed for the game.
 **/
struct game_system
{
	/* the menus for our system */
	struct menu_system the_menus;
	/* the result of the last game played */
	struct game_result theresult;
	/* the scoreboard for the game */
	struct linkedlist scoreboard;
	/* the file name for the datafile containing the scores we
	 * are manipulating
	 */
	const char* datafile;
	/**
	 * the seed for the games we create if requested from the
	 * command line
	 **/
	struct falsible_long gameseed;
};

/**
 * the new functions required as part of the main module for assignment 2
 **/
BOOLEAN init_system(struct game_system*, const char[]);

void init_main_menu(struct main_menu_entry[]);

void quit_program(struct game_system*);

void abort_program(struct game_system*);

struct game_system* createGameSystem(void);

struct linkedlist* getLinkedList(void);

struct game_system* getGameSystem(void);

/*
 * Used to print the game system state for debugging.
 */
void printDebugGameSystem(struct game_system* theGameSystemPtr);

/**
 * end of assignment 2 data structures
 **/

/**
 * You may add your own datastructures or function declarations here if you
 * need to.
 **/