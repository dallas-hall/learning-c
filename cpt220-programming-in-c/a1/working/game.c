/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "game.h"

/*
 * The extern variable for this is inside shared.h
 * The controls debug message printing, 1 = on and 0 = off
 */
int DEBUGGING = 1;

/**
 * initialise the game structure passed in. For full details of the requirements
 * for this function, please see the assignment requirements.
 **/
BOOLEAN
game_init(struct game* thegame)
{
        return FALSE;
}

/**
 * you'll manage the game loop here and provide notification when a player has
 * won the game. Please see the assignment specifications for the full detail
 * on what is required here.
 **/
void
play_game(struct falsible_long seed)
{
        /**
         * declare and allocate memory for the main game struct
         **/
        struct game thegame;
        BOOLEAN quit = FALSE;
        char* heading = NULL;

        /**
         * set the seed in the game struct - set to the current time if no
         * seed was provided.
         **/
        if (seed.success)
        {
                thegame.seed = seed.thelong;
        }
        else
        {
                thegame.seed = time(NULL);
        }
        /* print the heading */
        heading = "Welcome to CPT220 Backgammon";
        normal_print("%s\n", heading);
        PUTLINE('-', strlen(heading));
        normal_print("The seed number being used is: %d\n", seed);
        PUTLINE('-', strlen(heading));

        if(DEBUGGING)
        {
                normal_print("%s\n", "[DEBUG] Trying to create board.");
        }
        board_init(thegame.game_board);

        /**
         * if initialisation of the game failed, we should quit
         **/
        if (!game_init(&thegame))
        {
                return;
        }
        /* implement game loop logic here */
        while (!quit)
        {
        }
}

/**
 * swap the players by swapping the pointers. Please note this is an advanced
 * and optional requirement but should be straight forward if you have
 * understood pointers. This is an optional requirement as I don't expect
 * everyone will be able to do this.
 **/
void
swap_players(struct player** first, struct player** second)
{
}
