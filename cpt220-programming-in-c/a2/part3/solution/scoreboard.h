/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "linkedlist.h"
#include "helpers.h"
#include <ctype.h>
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
/* forwards declaration of the game_system so we can have pointers
 * to it. We'll import main.h in scoreboard.h
 */
struct game_system;
/* the size of the scoreboard menu */
#define NUM_SCORES_MENU_ITEMS 6

/**
 * a scoreboard menu entry - the text for the scoreboard entry and the function
 * that implements that functionality.
 **/
struct scores_menu_entry
{
        char text[LINE_LEN + 1];
        BOOLEAN (*function)(struct game_system *);
};

/**
 * the components of a string read in that represents a score
 **/
enum result_ind
{
        RI_WINNER,
        RI_LOSER,
        RI_WONBY,
        RI_INVALID
};

void scores_menu(struct game_system *);
void init_scores_menu(struct scores_menu_entry[]);
BOOLEAN print_scores(struct game_system *);
BOOLEAN add_score(struct game_system *);
BOOLEAN delete_score(struct game_system *);
BOOLEAN remove_all_scores(struct game_system *);
BOOLEAN resave_scores(struct game_system *);
BOOLEAN save_scores(struct game_system *);
void free_result(struct game_result *);

int score_cmp(const struct game_result *, const struct game_result *);
struct game_result *result_from_string(const char[]);
#endif
