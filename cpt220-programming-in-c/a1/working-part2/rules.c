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
	if (1) {
		normal_print("%s\n", "[DEBUG] rules.c - Entering validate_moves.");
	}
	/*
	 * getMovePair validation checks.
	 * a) direction movement checked for the end piece
	 * b) cannot move an empty piece
	 * c) cannot move an opponent's piece
	 * d) cannot move to a place where an opponent has 2 or more pieces already
	 *
	 */




	return FALSE;
}

/**
 * apply the moves listed in themoves. These are offset pairs that were inserted
 * in the "changes" array in the validate_moves() function.
 **/
BOOLEAN apply_moves(const struct move_pair themoves[], int num_moves,
					struct player *curplayer)
{
	if (1) {
		normal_print("%s\n", "[DEBUG] rules.c - Entering apply_moves.");
	}

	return FALSE;
}

/**
 * determines whether the player has won the game. the player has won the game
 * when they have no tokens on the board and there are no tokens in their bar
 * list.
 **/
BOOLEAN has_won_game(const struct player *curplayer)
{
	int currentScore = curplayer->score;
	BOOLEAN emptyBarList = FALSE;
	BOOLEAN noTokensLeft = FALSE;

	if (1) {
		normal_print("%s\n", "[DEBUG] rules.c - Entering has_won_game.");
	}

	if (curplayer->bar_list.token_count == 0) {
		emptyBarList = TRUE;
	}

	/*
	 * TODO check for no more tokens.
	 */

	if (currentScore == 15 && emptyBarList && noTokensLeft) {
		return TRUE;
	}

	return FALSE;
}

/*
 * Gets the piece's
 */
struct move_pair getMovePair(int y, int moves, struct player *currentPlayer)
{
	struct piece_location startPieceLocation;
	struct piece_location endPieceLocation;
	/*
	 * P_WHITE or P_RED
	 */
	enum piece currentPlayerPiece = currentPlayer->token;
	enum piece otherPlayerPiece = currentPlayer->curgame->other_player->token;
	enum piece previousBoardPiece = P_INVALID;
	enum piece currentBoardPiece = P_INVALID;
	/*
	 * -99 catch all invalid
	 * -1 is into into the bar list
	 * else is x, y of the board
	 */
	int currentPieceX = -99;
	int currentPieceY = -99;
	struct move_pair currentMovePair;
	int boardHalfToCheck;
	int otherPlayerPieceCount;

	/*
	 * Remember this is [BOARD_HEIGHT 14][BOARD_WIDTH 12]
	 */
	int i, columnOffset;

	if (DEBUGGING_RULES) {
		normal_print("%s\n", "[DEBUG] rules.c - Entering has_won_game.");
		printBoard(currentPlayer->curgame->game_board);
	}

	/*
	 * The clockwise player as 13-24 on the bottom and 12-1 on top
	 * The anticlockwise player as 13-24 on the top and 12-1 on bottom
	 */
	if (currentPlayer->orientation == OR_CLOCKWISE) {
		if (y >= 1 && y <= 12) {
			startPieceLocation.direction = DIR_DOWN;
		}
		else if (y >= 13 && y <= 24) {
			startPieceLocation.direction = DIR_UP;
		}

	}
	else if (currentPlayer->orientation == OR_ANTICLOCKWISE) {
		if (y >= 13 && y <= 24) {
			startPieceLocation.direction = DIR_DOWN;
		}
		else if (y >= 1 && y <= 12) {
			startPieceLocation.direction = DIR_UP;
		}
	}

	/*
	 * Convert the initial y value into the correct array index.
	 */
	columnOffset = getColumnOffset(y);

	/* # FIRST PIECE
	 *
	 * Get the starting move position. If a value returns -99 then that is
	 * an invalid move because either:
	 * a) > 7 pieces exist on that column -99
	 * b) Trying to move an empty space -98
	 * c) Trying to move the opponents piece -97
	 * d) Too many other player pieces -96
	 * there already.
	 *
	 * This logic applies to players of both directions.
	 *
	 * For starting moves from the top, get the piece at the bottom if it
	 * exists. Otherwise error.
	 *
	 * For starting moves from the bottom, get the piece at the top if it
	 * exists. Otherwise error.
	 */
	if (startPieceLocation.direction == DIR_DOWN) {
		/*
		 * Check 8 places, 0 to 7
		 */
		boardHalfToCheck = BOARD_HEIGHT / 2;
		for (i = 0; i <= boardHalfToCheck; i++) {
			currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];

			/*
			 * If the first place checked is empty, invalid move.
			 * If the first place checked has an opponents token, invalid move.
			 */
			if (i == BOARD_HEIGHT - 1 && currentBoardPiece == P_EMPTY) {
				currentPieceX = -98;
				currentPieceY = -98;
				break;
			}
			else if (i == BOARD_HEIGHT - 1 && currentBoardPiece == otherPlayerPiece) {
				currentPieceX = -97;
				currentPieceY = -97;
				break;
			}
			else if (i != 0) {
				previousBoardPiece = currentPlayer->curgame->game_board[i -
																		1][columnOffset];
				if (currentBoardPiece == P_EMPTY &&
					previousBoardPiece == currentPlayerPiece) {
					/*
					 * If i == boardHalfToCheck then we've checked 8 places
					 * which is too many.
					 */
					if (i == boardHalfToCheck) {
						break;
					}

					/*
					 * Remember - 1 here since we are comparing previous values.
					 */
					currentPieceX = i - 1;
					currentPieceY = columnOffset;
					break;
				}
			}
		}
	}
	else if (startPieceLocation.direction == DIR_UP) {
		/*
		 * Check 8 places, 13 to 6
		 */
		boardHalfToCheck = (BOARD_HEIGHT / 2) - 1;
		for (i = BOARD_HEIGHT - 1; i >= boardHalfToCheck; i--) {
			currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];

			/*
			 * If the first place checked is empty, invalid move.
			 * If the first place checked has an opponents token, invalid move.
			 */
			if (i == BOARD_HEIGHT - 1 && currentBoardPiece == P_EMPTY) {
				currentPieceX = -98;
				currentPieceY = -98;
				break;
			}
			else if (i == BOARD_HEIGHT - 1 && currentBoardPiece == otherPlayerPiece) {
				currentPieceX = -97;
				currentPieceY = -97;
				break;
			}
			else if (i != BOARD_HEIGHT - 1) {
				previousBoardPiece = currentPlayer->curgame->game_board[i +
																		1][columnOffset];
				if (currentBoardPiece == P_EMPTY &&
					previousBoardPiece == currentPlayerPiece) {
					/*
					 * If i == boardHalfToCheck then we've checked 8 places
					 * which is too many.
					 */
					if (i == boardHalfToCheck) {
						break;
					}

					/*
					 * Remember + 1 here since we are comparing previous values
					 * that are higher in the array.
					 */
					currentPieceX = i + 1;
					currentPieceY = columnOffset;
					break;
				}
			}
		}
	}
	startPieceLocation.x = currentPieceX;
	startPieceLocation.y = currentPieceY;
	currentMovePair.start = startPieceLocation;

	if (1) {
		printf("currentMovePair.start.x is %d\n", currentMovePair.start.x);
		printf("currentMovePair.start.y is %d\n", currentMovePair.start.y);
		printf("currentMovePair.start.direction is %d\n",
			   currentMovePair.start.direction);
	}


	/* # SECOND PIECE
	 *
	 * Get the second move. Resetting original check values.
	 *
 	 * All valid movements are reducing the column the intended amount of moves.
 	 * We check for negative numbers previously to ensure this is correct.
 	 *
 	 * If columnOffset is negative, we are trying to move into the bar list.
	 */
	columnOffset = getColumnOffset(y - moves);
	/*
	 * The clockwise player as 13-24 on the bottom and 12-1 on top
	 * The anticlockwise player as 13-24 on the top and 12-1 on bottom
	 */
	boardHalfToCheck = y - moves;
	if (currentPlayer->orientation == OR_CLOCKWISE) {
		if (boardHalfToCheck >= 1 && boardHalfToCheck <= 12) {
			endPieceLocation.direction = DIR_DOWN;
		}
		else if (boardHalfToCheck >= 13 && boardHalfToCheck <= 24) {
			endPieceLocation.direction = DIR_UP;
		}

	}
	else if (currentPlayer->orientation == OR_ANTICLOCKWISE) {
		if (boardHalfToCheck >= 13 && boardHalfToCheck <= 24) {
			endPieceLocation.direction = DIR_DOWN;
		}
		else if (boardHalfToCheck >= 1 && boardHalfToCheck <= 12) {
			endPieceLocation.direction = DIR_UP;
		}
	}
	currentPieceX = -99;
	currentPieceY = -99;
	previousBoardPiece = P_INVALID;
	currentBoardPiece = P_INVALID;
	otherPlayerPieceCount = 0;

	if (endPieceLocation.direction == DIR_DOWN) {
		/*
		 * Check 8 places, 0 to 7
		 */
		boardHalfToCheck = BOARD_HEIGHT / 2;
		for (i = 0; i <= boardHalfToCheck; i++) {
			/*
			 * Trying to move into the bar list.
			 */
			if(columnOffset < 0) {
				currentPieceX = -1;
				currentPieceY = -1;
				break;
			}
			currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];

			/*
			 * If the other player has 2 or more pieces on the intended spot
			 * to move to then it is an invalid move.
			 */
			if (currentBoardPiece == otherPlayerPiece) {
				++otherPlayerPieceCount;
				if (otherPlayerPieceCount >= 2) {
					currentPieceX = -96;
					currentPieceY = -96;
					break;
				}
			}

			/*
			 * If the first place checked is empty, its good as this is valid
			 * move for the player.
			 */
			if (i == 0 && currentBoardPiece == P_EMPTY) {
				/*
				 * Don't need - 1 here since we want the empty space.
				 */
				currentPieceX = i;
				currentPieceY = columnOffset;
				break;
			}
			else if (i != 0) {
				previousBoardPiece = currentPlayer->curgame->game_board[i -
																		1][columnOffset];

				if (currentBoardPiece == P_EMPTY &&
						 previousBoardPiece == currentPlayerPiece) {
					/*
					 * If i == boardHalfToCheck then we've checked 8 places
					 * which is too many.
					 */
					if (i == boardHalfToCheck) {
						break;
					}

					currentPieceX = i;
					currentPieceY = columnOffset;
					break;
				}
			}
		}
	}
	else if (endPieceLocation.direction == DIR_UP) {
		/*
		 * Check 8 places, 13 to 6
		 */
		boardHalfToCheck = (BOARD_HEIGHT / 2) - 1;
		for (i = BOARD_HEIGHT - 1; i >= boardHalfToCheck; i--) {
			/*
 			 * Trying to move into the bar list.
 			 */
			if(columnOffset < 0) {
				currentPieceX = -1;
				currentPieceY = -1;
				break;
			}

			currentBoardPiece = currentPlayer->curgame->game_board[i][columnOffset];

			/*
			 * If the other player has 2 or more pieces on the intended spot
			 * to move to then it is an invalid move.
			 */
			if (currentBoardPiece == otherPlayerPiece) {
				++otherPlayerPieceCount;
				if (otherPlayerPieceCount >= 2) {
					currentPieceX = -96;
					currentPieceY = -96;
					break;
				}
			}

			/*
			 * If the first place checked is empty, its good as this is valid
			 * move for the player.
			 */
			if (i == BOARD_HEIGHT - 1 && currentBoardPiece == P_EMPTY) {
				/*
 				 * Don't need - 1 here since we want the empty space.
 				*/
				currentPieceX = i;
				currentPieceY = columnOffset;
				break;
			}
			else if (i != BOARD_HEIGHT - 1) {
				previousBoardPiece = currentPlayer->curgame->game_board[i +
																		1][columnOffset];


				if (currentBoardPiece == P_EMPTY &&
						 previousBoardPiece == currentPlayerPiece) {
					/*
					 * If i == boardHalfToCheck then we've checked 8 places
					 * which is too many.
					 */
					if (i == boardHalfToCheck) {
						break;
					}


					currentPieceX = i;
					currentPieceY = columnOffset;
					break;
				}
			}
		}
	}
	endPieceLocation.x = currentPieceX;
	endPieceLocation.y = currentPieceY;
	currentMovePair.end = endPieceLocation;

	if (1) {
		printf("currentMovePair.end.x is %d\n", currentMovePair.end.x);
		printf("currentMovePair.end.y is %d\n", currentMovePair.end.y);
		printf("currentMovePair.end.direction is %d\n",
			   currentMovePair.end.direction);
	}

	return currentMovePair;
}

/*
 * This gets the user inputted y axis and converts it into the appropriate array
 * index for both directions.
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