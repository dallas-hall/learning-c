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

const int DEBUGGING_RULES = 0;


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
	printf("ENTERED validate_moves\n");


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

/*
 * Gets the piece's
 */
struct move_pair getMovePair(int y, int moves, struct player *currentPlayer)
{
	struct piece_location pieceLocation;
	enum piece currentPlayerPiece = currentPlayer->token; /* P_WHITE or P_RED */
	enum piece currentBoardPiece, previousBoardPiece;
	/*
	 * -99 for invalid
	 * anything else negative is into into the bar list
	 * else is x, y of the board
	 */
	int currentPieceX = -99;
	int currentPieceY = -99;
	struct move_pair currentMovePair;

	/*
	 * Remember this is [HEIGHT][WIDTH]
	 */
	int i, columnOffset;

	if (DEBUGGING_RULES) {
		printBoard(currentPlayer->curgame->game_board);
	}

	/*
	 * The clockwise player as 13-24 on the bottom and 12-1 on top
	 */
	if (currentPlayer->orientation == OR_CLOCKWISE) {
		if (y >= 13 && y <= 24) {
			pieceLocation.direction = DIR_UP;
		}
		else if (y >= 1 && y <= 12) {
			pieceLocation.direction = DIR_DOWN;
		}

		/*
 		 * For starting moves, get the piece on top or bottom.
 		 */
		columnOffset = getColumnOffset(y);
		for (i = 0; i < BOARD_HEIGHT; i++) {

			currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];
			/*
			 * If the first place checked is empty, its bad.
			 */
			if (i == 0 && currentBoardPiece == P_EMPTY) {
				break;
			}
			else if (i != 0) {
				previousBoardPiece = currentPlayer->curgame->game_board[i -
																		1][columnOffset];
				if (currentBoardPiece == P_EMPTY &&
					previousBoardPiece == currentPlayerPiece) {
					/*
					 * Remember - 1 here since we are comparing previous values.
					 */
					currentPieceX = i - 1;
					currentPieceY = columnOffset;
					break;
				}
			}

			if (DEBUGGING_RULES) {
				printf("Current piece at [%d][%d] %d.\n", i, columnOffset,
					   currentBoardPiece);
			}
		}
		pieceLocation.x = currentPieceX;
		pieceLocation.y = currentPieceY;
		currentMovePair.start = pieceLocation;
	}
		/*
		 * The anticlockwise player as 13-24 on the top and 12-1 on bottom
		 */
	else if (currentPlayer->orientation == OR_ANTICLOCKWISE) {
		if (y >= 13 && y <= 24) {
			pieceLocation.direction = DIR_DOWN;
		}
		else if (y >= 1 && y <= 12) {
			pieceLocation.direction = DIR_UP;
		}

		/*
 		 * For starting moves, get the piece on top or bottom.
 		 */
		columnOffset = getColumnOffset(y);
		for (i = BOARD_HEIGHT; i >= 0; i--) {

			currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];
			/*
			 * If the first place checked is empty, its bad.
			 */
			if (i == 0 && currentBoardPiece == P_EMPTY) {
				break;
			}
			else if (i != 0) {
				previousBoardPiece = currentPlayer->curgame->game_board[i -
																		1][columnOffset];
				if (currentBoardPiece == currentPlayerPiece &&
					previousBoardPiece == P_EMPTY) {
					/*
					 * No need to - 1 here since we have flipped the check above.
					 * Because we are processing the array upside down.
					 */
					currentPieceX = i;
					currentPieceY = columnOffset;
					break;
				}
			}

			if (DEBUGGING_RULES) {
				printf("Current piece at [%d][%d] %d.\n", i, columnOffset,
					   currentBoardPiece);
			}
		}
		pieceLocation.x = currentPieceX;
		pieceLocation.y = currentPieceY;
		currentMovePair.start = pieceLocation;
	}

	if (1) {
		printf("currentMovePair.start.x is %d\n", currentMovePair.start.x);
		printf("currentMovePair.start.y is %d\n", currentMovePair.start.y);
		printf("currentMovePair.start.direction is %d\n",
			   currentMovePair.start.direction);
	}

	/*
	 * For finishing moves, get the final destination.
	 * We will validate this move later.
	 */
	currentPieceX = -99;
	currentPieceY = -99;

	columnOffset = y - moves;
	for (i = 0; i < BOARD_HEIGHT; i++) {
		/*
		 * Trying to move into the bar list.
		 * Setting both to the columnOffSet as we don't need to know what
		 * this value is.
		 */
		if (columnOffset < 0) {
			currentPieceX = columnOffset;
			currentPieceY = columnOffset;
			break;
		}

		currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];
		/*
		 * If the first place checked is empty, its good.
		 */
		if (i == 0 && currentBoardPiece == P_EMPTY) {
			currentPieceX = i;
			currentPieceY = columnOffset;
			break;
		}
		else if (i != 0) {
			previousBoardPiece = currentPlayer->curgame->game_board[i -
																	1][columnOffset];
			if (previousBoardPiece == currentPlayerPiece &&
				currentBoardPiece == P_EMPTY) {
				/*
				 * Remember - 1 here since we are comparing previous values.
				 */
				currentPieceX = i - 1;
				currentPieceY = columnOffset;
				break;
			}

		}

		if (DEBUGGING_RULES) {
			printf("Current piece at [%d][%d] %d.\n", i, columnOffset,
				   currentBoardPiece);
		}
	}


	/*
	 * For ending moves, get the correct x and y for the empty spot
	 */
	pieceLocation.x = currentPieceX;
	pieceLocation.y = currentPieceY;
	currentMovePair.end = pieceLocation;

	if (1) {
		printf("currentMovePair.end.x is %d\n", currentMovePair.end.x);
		printf("currentMovePair.end.y is %d\n", currentMovePair.end.y);
		printf("currentMovePair.end.direction is %d\n",
			   currentMovePair.end.direction);
	}

	return currentMovePair;
}

/*
 * Caller to check if this is -1 and handle appropriately.
 */

int getColumnOffset(int y)
{
	int columnOffset;

	switch (y) {
		case 1:
		case 24:
			columnOffset = 11;
			break;
		case 2:
		case 23:
			columnOffset = 10;
			break;
		case 3:
		case 22:
			columnOffset = 9;
			break;
		case 4:
		case 21:
			columnOffset = 8;
			break;
		case 5:
		case 20:
			columnOffset = 7;
			break;
		case 6:
		case 19:
			columnOffset = 6;
			break;
		case 7:
		case 18:
			columnOffset = 5;
			break;
		case 8:
		case 17:
			columnOffset = 4;
			break;
		case 9:
		case 16:
			columnOffset = 3;
			break;
		case 10:
		case 15:
			columnOffset = 2;
			break;
		case 11:
		case 14:
			columnOffset = 1;
			break;
		case 12:
		case 13:
			columnOffset = 0;
			break;
		default:
			columnOffset = -1;
			break;
	}

	return columnOffset;
}