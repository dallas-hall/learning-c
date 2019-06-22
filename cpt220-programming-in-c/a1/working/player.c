/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "player.h"
#include "game.h"

const int DEBUGGING_PLAYER = 0;

/**
 * do the work to initialise a player here. Please refer to the assignment
 * specifications for what you need to do here.
 **/
BOOLEAN player_init(struct player *aplayer, struct game *thegame)
{

	BOOLEAN done = FALSE;
	/*
	Intialise the new player details
	Got the idea from https://www.tutorialspoint.com/cprogramming/c_structures.htm
	*/
	struct bar_list newBarList;
	struct player newPlayer;

	barlist_init(&newBarList);

	newPlayer.name[0] = '\0';
	newPlayer.score = 0;
	newPlayer.curgame = thegame;
	newPlayer.bar_list = newBarList;
	newPlayer.orientation = 0;
	aplayer = &newPlayer;

	if (DEBUGGING_PLAYER) {
		printf("[DEBUG] player.c - aplayer -> name before getName is %s\n",
			   aplayer->name);
		printf("[DEBUG] player.c - aplayer -> score before getName is %d\n",
			   aplayer->score);
		printf("[DEBUG] player.c - aplayer -> orientation before getName is %d\n",
			   aplayer->orientation);
	}

	do {
		done = getPlayerName(aplayer);
	} while (!done);

	/*
	Assign the newly created player to the players array in game.
	*/
	if (strlen(thegame->players[0].name) == 0) {
		if (DEBUGGING_PLAYER) {
			printf("[DEBUG] player.c - setting thegame -> players[0]\n");
		}
		thegame->players[0] = *aplayer;
		/*
		 * I had a huge bug here that took me hours to figure out.
		 * This bug is what made me use the IDE Clion, so I could visualise
		 * inside the debugger what was going on.
		 * I was using thegame->current_player = aplayer;
		 * I believe this was overwriting current_player with other_player.
		 * When I changed it to the code below it works as expected.
		 */
		thegame->current_player = &thegame->players[0];

	}
	else if (strlen(thegame->players[1].name) == 0) {
		if (DEBUGGING_PLAYER) {
			printf("[DEBUG] player.c - setting thegame -> players[1]\n");
		}
		thegame->players[1] = *aplayer;
		thegame->other_player = &thegame->players[1];
	}

	if (DEBUGGING_PLAYER) {
		printf("[DEBUG] player.c - aplayer -> name after getName is %s\n",
			   aplayer->name);
		printf("[DEBUG] player.c - aplayer -> score after getName is %d\n",
			   aplayer->score);
		printf("[DEBUG] player.c - aplayer -> orientation after getName is %d\n",
			   aplayer->orientation);

		printf("thegame -> current_player -> name is %s\n",
			   thegame->current_player->name);
		/*printf("thegame -> other_player -> name is %s\n", thegame -> other_player -> name);*/

		printf("thegame -> players[0].name is %s\n", thegame->players[0].name);
		printf("thegame -> players[1].name is %s\n", thegame->players[1].name);
	}
	return TRUE;
}

/**
 * implement the taking of a turn and turn validation in this function and
 * functions called from here. Please refer to the assignment specifications
 * for details on what you need to do here.
 **/
enum input_result player_take_turn(struct player *current_player)
{
	return IR_FAILURE;
}



