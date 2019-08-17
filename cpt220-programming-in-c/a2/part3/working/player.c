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

/**
 * do the work to initialise a player here. Please refer to the assignment
 * specifications for what you need to do here.
 **/
BOOLEAN player_init(struct player* aplayer, struct game* thegame)
{
	enum input_result iresult;
	char name[NAME_LEN + EXTRA_CHARS];
	/**
	 * zero out the player struct
	 **/
	memset(aplayer, 0, sizeof(*aplayer));
	/* set the bar_list to empty */
	barlist_init(&aplayer->bar_list);
	/**
	 * read the player's name
	 **/
	 /*
	  * TODO validate the player name with new rules
	  */
	while (iresult = read_string("Please enter the name of the player",
								 name, NAME_LEN),
			iresult == IR_FAILURE);
	/**
	 * on ctrl-d or enter, return back to game_init()
	 **/
	if (iresult == IR_QUIT || iresult == IR_SKIP_TURN) {
		return FALSE;
	}
	/**
	 * copy in the name entered
	 **/
	strcpy(aplayer->name, name);
	/**
	 * set the game ponter for the player
	 **/
	aplayer->curgame = thegame;
	return TRUE;
}

/**
 * select the colorstrings for display based on the enum color value passed
 * in
 **/
static void select_color(enum color thecolor, const char** open_color,
						 const char** close_color, const char** color_word)
{
	static char* color_words[] = {"red", "white"};
	/* no colour but read or white should be requested */
	assert(thecolor == COLOR_RED || thecolor == COLOR_WHITE);
	/* retrieve the colour strings from the global variable */
	*open_color = color_strings[thecolor];
	*close_color = color_strings[COLOR_RESET];
	*color_word = color_words[thecolor];
}

/**
 * implement the taking of a turn and turn validation in this function and
 * functions called from here. Please refer to the assignment specifications
 * for details on what you need to do here.
 **/
enum input_result player_take_turn(struct player* current_player)
{
	const char* open_color, * close_color, * color_word;
	int dicerolls[NUM_DICE];
	int dice_count;
	struct move moves[MAX_MOVES];
	int move_count;
	enum input_result iresult;
	const char* direction_strings[] = {"clockwise", "anticlockwise"};
	char info[MAXPROMPTLEN + 1];
	char* info_folded;
	BOOLEAN move_success = FALSE;

	/**
	 * print out the game board based the variable passed in
	 **/
	board_print(current_player->curgame->game_board,
				current_player->orientation);
	/* print out the prompt for a turn */
	select_color(current_player->token == P_RED ? COLOR_RED : COLOR_WHITE,
				 &open_color, &close_color, &color_word);
	if (current_player->bar_list.token_count > 0) {
		sprintf(
				info,
				"It is %s's turn and their score is %d, and their colour "
				"is %s%s%s, their direction is %s and their bar list "
				"contains %d tokens. You will have to move these tokens "
				"before you can move any other tokens on the board.\n",
				current_player->name, current_player->score, open_color,
				color_word, close_color,
				direction_strings[current_player->orientation],
				current_player->bar_list.token_count);
	}
	else {
		sprintf(info, "It is %s's turn and their score is %d, and "
					  "their colour is %s%s%s, their direction is %s "
					  "and their bar list is empty.\n",
				current_player->name, current_player->score, open_color,
				color_word, close_color,
				direction_strings[current_player->orientation]);
	}
	/* fold the prompt for output */
	info_folded = fold(info);
	normal_print("%s\n", info_folded);
	free(info_folded);
	/* roll the dice */
	for (dice_count = 0; dice_count < NUM_DICE; ++dice_count) {
		dicerolls[dice_count] = DICE_ROLL();
	}
	normal_print("You have rolled a %d and a %d.\n", dicerolls[FIRST],
				 dicerolls[SECOND]);
	do {
		struct move_pair changes[MAX_MOVES];

		/* read the moves for the current player from the keyboard */

		while (iresult = read_moves(moves, &move_count, MAX_MOVES),
				iresult == IR_FAILURE) {
			error_print("Invalid input entered. Please try "
						"entering your "
						"move choices again.\n");
			normal_print("You have rolled a %d and a %d.\n",
						 dicerolls[FIRST], dicerolls[SECOND]);
		}
		/* if quit or skip turn have been read, return these back */
		if (iresult == IR_QUIT || iresult == IR_SKIP_TURN) {
			return iresult;
		}
		/* check that the moves entered by the player are valid */
		move_success = validate_moves(moves, move_count, current_player,
									  dicerolls, changes);
		if (!move_success) {
			error_print("invalid moves entered. Please try "
						"again.\n\n");
		}
		else {
			/* if so, apply the moves */
			if (!apply_moves(changes, move_count, current_player)) {
				error_print("invalid moves entered. Please try "
							"again.\n\n");
				move_success = FALSE;
			}
		}
		/* continue to reprompt until a valid move is entered */
	} while (!move_success);
	return IR_SUCCESS;
}
