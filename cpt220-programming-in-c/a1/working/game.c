/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "game.h"

/*
 * The extern variable for this is inside shared.h
 * The controls debug message printing, 1 = on and 0 = off
 * https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files/1433387#1433387
 */
int DEBUGGING = 0;

/**
 * initialise the game structure passed in. For full details of the requirements
 * for this function, please see the assignment requirements.
 **/
BOOLEAN game_init(struct game *thegame)
{
	return FALSE;
}

/**
 * you'll manage the game loop here and provide notification when a player has
 * won the game. Please see the assignment specifications for the full detail
 * on what is required here.
 **/
void play_game(struct falsible_long seed)
{
	/**
	 * declare and allocate memory for the main game struct
	 **/
	struct game thegame;
	BOOLEAN quit = FALSE;
	char *heading = NULL;

	/**
	 * set the seed in the game struct - set to the current time if no
	 * seed was provided.
	 **/
	if (seed.success) {
		thegame.seed = seed.thelong;
	} else {
		thegame.seed = time(NULL);
	}

	/* print the heading */
	heading = "Welcome to CPT220 Backgammon";
	normal_print("%s\n", heading);
	PUTLINE('-', strlen(heading));
	normal_print("The seed number being used is: %d\n", seed);
	PUTLINE('-', strlen(heading));

	if (DEBUGGING) {
		normal_print("%s\n", "[DEBUG] game.c - Trying to create the board.");
	}
	board_init(thegame.game_board);

	if (DEBUGGING) {
		printBoard(thegame.game_board);
		printBoardReverse(thegame.game_board);
		normal_print("%s\n", "[DEBUG] game.c - Trying to create the players.");
	}

	/*
	 * Setting these to empty so I can use later to determine which player
	 * pointer was passed.
	 */
	thegame.players[0].name[0] = '\0';
	thegame.players[1].name[0] = '\0';

	/*
	 * Need to send the address here, so use &
	 */
	player_init(thegame.other_player, &thegame);
	player_init(thegame.current_player, &thegame);

	if (DEBUGGING) {
		normal_print("%s\n",
					 "[DEBUG] game.c - Trying to print created the players.");
		/*
		 * Need to use -> since its a pointer.
		 */
		printf("The first player - thegame.current_player->name is %s\n",
			   thegame.current_player->name);
		printf("The first player - thegame.players[0].name is  %s\n",
			   thegame.players[0].name);
		printf("The second player - thegame.other_player->name is %s\n",
			   thegame.other_player->name);
		printf("The second player - thegame.players[1].name is  %s\n",
			   thegame.players[1].name);
	}

	/*
	 * Determine the player order.
	 * Need to pass the address here with &
	 *
	 * I based this off of the material in chapter 5 of C How To Program 6e
	 * srand will make sure rand produces different number sequences.
	 * time() returns how many seconds since the Unix Epoch (1/1/1970).
	 * Was initially using NULL parameter, which for time means apply no
	 * formatting. But then I decided to use the supplied seed number.
	 * Needed the address operator to get the right data type,
	 */
	srand(time(&thegame.seed));
	if (DEBUGGING) {
		printCurrentPlayer(&thegame);
		printOtherPlayer(&thegame);
	}

	determine_player_order(&thegame);

	if (DEBUGGING) {
		printCurrentPlayer(&thegame);
		printOtherPlayer(&thegame);
	}

	/**
	 * if initialisation of the game failed, we should quit
	 **/
	if (!game_init(&thegame)) {
		return;
	}
	/* implement game loop logic here */
	while (!quit) {
	}
}

/*
 * TODO - Check this
 */

/**
 * swap the players by swapping the pointers. Please note this is an advanced
 * and optional requirement but should be straight forward if you have
 * understood pointers. This is an optional requirement as I don't expect
 * everyone will be able to do this.
 **/
void swap_players(struct player **first, struct player **second)
{
	/*
	 * Use * to dereference the pointer to a pointer.
	 */
	struct player *swap = *first;
	*first = *second;
	*second = *first;
}
