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
	char input[MAXPROMPTLEN];
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
		done = getName(input, MAXPROMPTLEN, aplayer, thegame);
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

/*
 * This function reads in input from stdnin
 * I have taken the concepts from /home/el9/E70949/shared/prog_in_c/tutes/week03/getname.c and chapter 8 from C How to program textbook.
 */
BOOLEAN
getName(char s[], int size, struct player *aplayer, struct game *thegame)
{
	int i;
	if (DEBUGGING_PLAYER) {
		printf("%s\n", "[DEBUG] player.c - Entering getName.");
	}

	if (strlen(thegame->players[0].name) == 0) {
		normal_print("Player 1, enter your name (max 20 characters): ", s);
	}
	else if (strlen(thegame->players[1].name) == 0) {
		normal_print("Player 2, enter your name (max 20 characters): ", s);
	}


	/*
	 * Need to account for the '\n' and '\0' that fgets adds.
	 * If the char last isn't '\n' then we know we didn't receive all the input.
	 * We need to remove the '\n' as well.
	 */

	if (fgets(s, MAXPROMPTLEN + FGETS_EXTRA_CHARS, stdin) == NULL) {
		return FALSE;
	}

	/*
	 * Remember that strlen doesn't include the \0 in its count
	 */

	if (s[strlen(s) - 1] != '\n') {
		error_print("Buffer overflow.\n");
		clear_buffer();
		return getName(s, size, aplayer, thegame);
	}

	if (strlen(s) > NAME_LEN + 1) {
		error_print("Input too long, less than 20 only.\n");
		return getName(s, size, aplayer, thegame);
	}

	if (strlen(s) < MIN_NAME_LEN) {
		error_print("Input too short, greater than 1 only.\n");
		return getName(s, size, aplayer, thegame);
	}

	if (DEBUGGING_PLAYER) {
		printf("[DEBUG] player.c - strlen(s) before removing \\n is %ld\n",
			   strlen(s));
		printf("[DEBUG] player.c - s is %s\n", s);
	}

	/*
	 * Replace \n with \0
	 */

	s[strlen(s) - 1] = '\0';

	if (DEBUGGING_PLAYER) {
		printf("[DEBUG] player.c - strlen(s) after removing \\n is %ld\n",
			   strlen(s));
		printf("[DEBUG] player.c - s is %s\n", s);

		printf("%s\n", "[DEBUG] player.c - Printing s with for loop.");
		for (i = 0; i < strlen(s); i++) {
			printf("%c", s[i]);
		}
		printf("\n");
	}

	/*
	 * Copy the input string into the player
	 */
	strcpy(aplayer->name, s);

	if (DEBUGGING_PLAYER) {
		printf("[DEBUG] player.c - aplayer -> name is %s\n", aplayer->name);
		printf("%s\n",
			   "[DEBUG] player.c - Printing aplayer -> name with for loop.");
		for (i = 0; i < strlen(s); i++) {
			printf("%c", aplayer->name[i]);
		}
		printf("\n");
	}

	return TRUE;
}

/*
 * The next 2 functions are used during debugging, so we can see which pointer
 * is currently inside of current_player or other_player.
 */
void printCurrentPlayer(struct game *thegame)
{
	printf("[DEBUG] player.c - printCurrentPlayer\n");
	printf("thegame->current_player.name is %s\n",
		   thegame->current_player->name);
	printf("thegame->current_player.score is %d\n",
		   thegame->current_player->score);
	printf("thegame->current_player.token is %d\n",
		   thegame->current_player->token);
	printf("thegame->current_player.orientation is %d\n",
		   thegame->current_player->orientation);
}

void printOtherPlayer(struct game *thegame)
{
	printf("[DEBUG] player.c - printOtherPlayer\n");
	printf("thegame->other_player.name is %s\n", thegame->other_player->name);
	printf("thegame->other_player.score is %d\n", thegame->other_player->score);
	printf("thegame->other_player.token is %d\n", thegame->other_player->token);
	printf("thegame->other_player.orientation is %d\n",
		   thegame->other_player->orientation);
}
