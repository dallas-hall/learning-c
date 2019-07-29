/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "scoreboard.h"
#include "io.h"
#include "main.h"

/**
 * initialise the scores menu with the text and functions that perform the
 * required functionality.
 **/
void init_scores_menu(struct scores_menu_entry scores_menu[])
{
}

/**
 * manages user input via the scores menu
 **/
void scores_menu(struct game_system* thesystem)
{
}

/**
 * performs the display scores function for the scores menu
 **/
BOOLEAN print_scores(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * adds a score to the system via user input. Please note that in a real
 * game score menu this makes no sense but it's here so you can show you
 * can do it.
 **/
BOOLEAN add_score(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * handles the "delete node" submenu for the system. Again, this would not
 * be a likely part of such a program in the real world but we are getting
 * you do do this so you can show you know how.
 **/
BOOLEAN delete_score(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * clears out the scoreboard to make it an empty list
 **/
BOOLEAN remove_all_scores(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * save scores back to the same file it was loaded from
 **/
BOOLEAN resave_scores(struct game_system* thesystem)
{
	return FALSE;
}

/**
 * saves the data file to a new file. The datafile attribute of the game system
 * should now point to the path of the file the data has been saved to. This is
 * similar to "save as" functionality in a word processor.
 **/
BOOLEAN save_scores(struct game_system* thesystem)
{
	return FALSE;
}
