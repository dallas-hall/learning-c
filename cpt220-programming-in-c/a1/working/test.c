void getEndPieceLocation(board gameBoard,

						 struct piece_location* endPieceLocation,

						 enum piece currentPlayerPiece,

						 enum piece otherPlayerPiece,

						 struct move_pair* currentMovePair,

						 int y, int moves, int boardHalfToCheck,

						 struct player* currentPlayer, BOOLEAN bPassed)
{

	/* # SECOND PIECE

	 *

 	 * Get the second move. Resetting original check values.

 	 *

  	 * All valid movements are reducing the column the intended amount of moves.

  	 * We check for negative numbers previously to ensure this is correct.

  	 *

  	 * If columnOffset is negative, we are trying to move into the bar list.

  	 *

  	 * This also has the logic for checking for a move onto an opponent's piece,

  	 * valid and invalid.

 	*/

	/*

 	 * P_WHITE or P_RED

 	 */

	enum piece previousBoardPiece = P_INVALID;

	enum piece currentBoardPiece = P_INVALID;


	/*

	 * -99 catch all invalid

	 * -1 is into into the bar list

	 * else is x, y of the board

	 */

	int currentPieceX = -99;

	int currentPieceY = -99;

	int columnOffset;

	int i;

	int otherPlayerPieceCount = 0;


	/*

	 * Trying to get out of the bar list. Add one from the moves amount

	 * as we are moving from the bar list and not starting on the board.

	 */

	if (bPassed) {

		columnOffset = getColumnOffset(y - moves + 1);

	}

	else {

		columnOffset = getColumnOffset(y - moves);

	}


	if (endPieceLocation->direction == DIR_DOWN) {

		/*

		 * Check 8 places, 0 to 7

		 */

		boardHalfToCheck = BOARD_HEIGHT / 2;

		for (i = 0; i <= boardHalfToCheck; i++) {

			/*

			 * Trying to move into the score board

			 */

			if (columnOffset < 0) {

				currentPieceX = -1;

				currentPieceY = -1;

				break;

			}


			currentBoardPiece = gameBoard[i][columnOffset];


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

			else if (i == BOARD_HEIGHT - 1 &&

					 currentBoardPiece == otherPlayerPieceCount) {

				previousBoardPiece = otherPlayerPieceCount;

			}

			else if (i != 0) {

				previousBoardPiece = gameBoard[i - 1][columnOffset];


				/*

 				 * If the second place checked is empty and the first place has

				 * an opponent's piece, its good as this is a valid move.

				 */

				if (i == BOARD_HEIGHT - 2 && currentBoardPiece == P_EMPTY &&

					previousBoardPiece == otherPlayerPiece) {

					/*

					  * Need - 1 here since we want to remove the player piece.

					 */

					currentPieceX = i - 1;

					currentPieceY = columnOffset;

					break;

				}

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

	else if (endPieceLocation->direction == DIR_UP) {

		/*

		 * Check 8 places, 13 to 6

		 */

		boardHalfToCheck = (BOARD_HEIGHT / 2) - 1;

		for (i = BOARD_HEIGHT - 1; i >= boardHalfToCheck; i--) {

			/*

 			 * Trying to move into the bar list.

 			 */

			if (columnOffset < 0) {

				currentPieceX = -1;

				currentPieceY = -1;

				break;

			}


			currentBoardPiece = gameBoard[i][columnOffset];


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

				previousBoardPiece = gameBoard[i + 1][columnOffset];


				/*

 				 * If the second place checked is empty and the first place has

				 * an opponent's piece, its good as this is a valid move.

				 */

				if (i == BOARD_HEIGHT - 2 && currentBoardPiece == P_EMPTY &&

					previousBoardPiece == otherPlayerPiece) {

					/*

					  * Need + 1 here since we want to remove the player piece.

					 */

					currentPieceX = i + 1;

					currentPieceY = columnOffset;

					break;

				}

				else if (currentBoardPiece == P_EMPTY &&

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


	endPieceLocation->x = currentPieceX;

	endPieceLocation->y = currentPieceY;

	currentMovePair->end = *endPieceLocation;


	if (DEBUGGING_RULES) {

		printf("currentMovePair->end.x is %d\n", currentMovePair->end.x);

		printf("currentMovePair->end.y is %d\n", currentMovePair->end.y);

		printf("currentMovePair->end.direction is %d\n",

			   currentMovePair->end.direction);

	}

}
