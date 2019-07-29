/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"
#include "io.h"
#include "shared.h"

#ifndef RULES_H
#define RULES_H
/**
 * forwards declarations that allow us to have pointers to the type specified
 * (game or player).
 **/
struct game;
struct player;
#define MAX_MOVES 4

/**
 * the direction a piece should be placed. So from bottom we build the pieces
 * upwards and from the top we add the pieces downwards.
 **/
enum direction
{
	DIR_UP,
	DIR_DOWN
};

/**
 * a piece location is a combination of the x and y values for a piece and the
 * direction that the pieces are built in a column. y is always 0 or 13 for
 * the top or bottom of the board - so if y is 0 then direction must be
 * DIR_DOWN and likewise when y is 13, direction must be DIR_UP. This may seem
 * complicated but I found this simpler to work with.
 **/
struct piece_location
{
	int x, y;
	enum direction direction;
};

/**
 * a move_pair represents the start and the end of a move - so the start column,
 * start y and direction for the opposite ends of a move
 **/
struct move_pair
{
	struct piece_location start;
	struct piece_location end;
};

/**
 * added for part 3 and the bonus marks
 **/
/* the max moves that can be made in a turn as there can only be 4 dice rolls */
#define MAX_MOVES 4
#define MAX_ROLLS 4
/* column height - the max tokens that can be stacked for a player */
#define COLUMN_HEIGHT 7
/* what is the token for the other player ? */
#define OTHER_TOKEN(token) (token) == P_RED ? P_WHITE : P_RED
/* the max size for the pair tuple array used to solve the move-dice matching
 * issue
 */
#define MAX_TUPLE_SIZE 10
/* int pair is used to associate the value at a particular index with that index
 * so that we can rearrange values but still know their original index */
struct int_pair
{
	int index;
	int value;
};

/**
 * the tuple type I am using. This has an advantage over a pure array as it can
 * be passed to and returned from a function by value so it simplifies recursion
 **/
struct pair_tuple
{
	struct int_pair tuple_vals[MAX_TUPLE_SIZE];
	int tuple_count;
};

/**
 * this enables me to handle the case where the operation fails without having
 * to handle another variable for return.
 **/
struct falsible_pair_tuple
{
	BOOLEAN success;
	struct pair_tuple thepairs;
};
/**
 * end of part 3 headers
 **/

/**
 * You may provide your own data type declarations here for this module
 **/

/**
 * end of the student's data type declarations
 **/

/**
 * functions that you will need to implement in rules.c
 **/
void determine_player_order(struct game*);

BOOLEAN validate_moves(const struct move[], int, const struct player*,
					   const int[], struct move_pair[]);

BOOLEAN apply_moves(const struct move_pair[], int, struct player*);

BOOLEAN has_won_game(const struct player*);

/**
 *You may add your own function prototypes here
 **/
#endif
