/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "rules.h"
#include "game.h"
#include "player.h"

#define MAX_ROLLS 4

/**
 * this function determines the player order and player tokens, and direction
 * of play for the game.
 *
 * start by rolling two dice for each player. the player with the higher sum
 * of dice rolls will go first. Make them the current player in the game struct
 * and set their token to X and their color to white, and their direction to
 * clockwise. Set the other player pointer to point to the other player. Set
 * their direction to anticlockwise, their token to O and their color to
 * red.
 **/
void determine_player_order(struct game *thegame)
{
	BOOLEAN done = FALSE;
	int playerOneTotal, playerTwoTotal;
	int die1, die2;
	char output[256];

	playerOneTotal = 0;
	playerTwoTotal = 0;

	do {
		die1 = rollDice();
		die2 = rollDice();
		playerOneTotal += die1 + die2;
		/*
		 * We need to thegame -> players because thegame has a pointer to the
		 * players array.
		 *
		 * And because its an array, we need to use players[subscript] to
		 * pick the right element.
		 *
		 * And then once we have the right element, use dot notation to access
		 * to correct field.
		 */
		normal_print("Player 1 named %s%s%s rolled %d and %d, totalling %d.\n",
					 fontEffectStrings[FONT_BOLD], thegame->players[0].name,
					 color_strings[COLOR_RESET],
					 die1, die2, playerOneTotal);

		die1 = rollDice();
		die2 = rollDice();
		playerTwoTotal += die1 + die2;
		normal_print("Player 2 named %s%s%s rolled %d and %d, totalling %d.\n",
					 fontEffectStrings[FONT_BOLD], thegame->players[1].name,
					 color_strings[COLOR_RESET], die1, die2, playerTwoTotal);

		if (playerOneTotal == playerTwoTotal) {
			/*
			 * Reset for the next roll
			 */
			normal_print("The result was a draw, re-rolling.\n");
			playerOneTotal = 0;
			playerTwoTotal = 0;
			continue;
		}
		else if (playerOneTotal > playerTwoTotal) {
			normal_print("Player 1 named %s%s%s wins the roll!\n",
						 fontEffectStrings[FONT_BOLD], thegame->players[0].name,
						 color_strings[COLOR_RESET]);
			thegame->players[0].token = P_WHITE;
			thegame->players[1].token = P_RED;

			thegame->players[0].orientation = OR_CLOCKWISE;
			thegame->players[1].orientation = OR_ANTICLOCKWISE;

			thegame->current_player = &thegame->players[0];
			thegame->other_player = &thegame->players[1];

			/*
			 * Worked out how to print the colours with the discussion here
			 * https://stackoverflow.com/a/3219471
			 *
			 * Got sprintf idea from Chapter 8, C How To Program 6e
			 *
			 * Sometimes this folds, sometimes it doesn't not sure why???
			 * It is the same logic as in io.c and that works fine every time.
			 *
			 * I BLAME YOU MR FOLD FUNCTION!
			 */

			sprintf(output,
					"Player 1 named %s%s%s will go first. They have the token %s%c%s and are moving %sCLOCKWISE%s around the board.\n",
					fontEffectStrings[FONT_BOLD], thegame->players[0].name,
					color_strings[COLOR_RESET], color_strings[COLOR_WHITE],
					WHITE_TOKEN,
					color_strings[COLOR_RESET], color_strings[COLOR_WHITE],
					color_strings[COLOR_RESET]);
			normal_print(fold(output));
			output[0] = '\0';

			sprintf(output,
					"Player 2 named %s%s%s will go second. They have the token %s%c%s and are moving %sANTICLOCKWISE%s around the board.\n",
					fontEffectStrings[FONT_BOLD], thegame->players[1].name,
					color_strings[COLOR_RESET], color_strings[COLOR_RED],
					RED_TOKEN,
					color_strings[COLOR_RESET], color_strings[COLOR_RED],
					color_strings[COLOR_RESET]);
			normal_print(fold(output));

			done = TRUE;
		}
		else {
			normal_print("Player 2 named %s%s%s wins the roll!\n",
						 fontEffectStrings[FONT_BOLD], thegame->players[1].name,
						 color_strings[COLOR_RESET]);
			thegame->players[0].token = P_RED;
			thegame->players[1].token = P_WHITE;

			thegame->players[0].orientation = OR_ANTICLOCKWISE;
			thegame->players[1].orientation = OR_CLOCKWISE;

			thegame->other_player = &thegame->players[0];
			thegame->current_player = &thegame->players[1];

			normal_print(
					"Player 2 named %s%s%s will go first. They have the token ",
					fontEffectStrings[FONT_BOLD], thegame->players[1].name,
					color_strings[COLOR_RESET]);
			normal_print("%s%c%s", color_strings[COLOR_WHITE], WHITE_TOKEN,
						 color_strings[COLOR_RESET]);
			normal_print(" and are moving %sCLOCKWISE%s around the board.\n",
						 color_strings[COLOR_WHITE],
						 color_strings[COLOR_RESET]);

			normal_print(
					"Player 1 named %s%s%s will go second They have the token ",
					fontEffectStrings[FONT_BOLD], thegame->players[0].name,
					color_strings[COLOR_RESET]);
			normal_print("%s%c%s", color_strings[COLOR_RED], RED_TOKEN,
						 color_strings[COLOR_RESET]);
			normal_print(
					" and are moving %sANTICLOCKWISE%s around the board.\n",
					color_strings[COLOR_RED], color_strings[COLOR_RESET]);

			done = TRUE;
		}

	} while (!done);
}

/**
 * test for valid moves. Have a look at the assignment specifications for
 * full details. If a move is valid, you will have to add the move offsets to
 * the changes array so they can be applied in apply_moves.
 **/
BOOLEAN validate_moves(const struct move selected_moves[], int num_moves,
					   const struct player *curplayer, const int dicerolls[],
					   struct move_pair changes[])
{
	return FALSE;
}

/**
 * apply the moves listed in themoves. These are offset pairs that were inserted
 * in the "changes" array in the validate_moves() function.
 **/
BOOLEAN apply_moves(const struct move_pair themoves[], int num_moves,
					struct player *curplayer)
{
	return FALSE;
}

/**
 * determines whether the player has won the game. the player has won the game
 * when they have no tokens on the board and there are no tokens in their bar
 * list.
 **/
BOOLEAN has_won_game(const struct player *curplayer)
{
	return FALSE;
}
