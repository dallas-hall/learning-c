/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
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
        MINARGS = 2,
        MAXARGS
};

/**
 * argcount enum - new with a2 as there are multiple arguments
 **/
enum
{
        FILE_ARG = 1,
        SEED_ARG
};

#define NUM_SCORES_MENU_ITEMS 6
#define NUM_MAIN_MENU_ITEMS 4
/**
 * assignment 2 data structures
 **/

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
        void (*function)(struct game_system*);
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
/**
 * end of assignment 2 data structures
 **/

/**
 * You may add your own datastructures or function declarations here if you
 * need to.
 **/
