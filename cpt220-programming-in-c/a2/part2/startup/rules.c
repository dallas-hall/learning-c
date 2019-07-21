/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "rules.h"
#include "game.h"
#include "player.h"

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

void determine_player_order(struct game* thegame)
{
        /* using char to represent to dice roll as it saves space rather than
         * int */
        char dice_rolls[NUM_PLAYERS][NUM_DICE] = { { 0 } };
        int player_count;
        int roll_count;
        char roll_totals[NUM_PLAYERS] = { 0 };

        /**
         * keep rolling dice for each player until player has a roll total
         * larger than the other
         **/
        while (roll_totals[FIRST] == roll_totals[SECOND])
        {
                for (player_count = 0; player_count < NUM_PLAYERS;
                     ++player_count)
                {
                        /* do two dice rolls */
                        char* cur_rolls = dice_rolls[player_count];
                        for (roll_count = 0; roll_count < NUM_DICE;
                             ++roll_count)
                        {
                                dice_rolls[player_count][roll_count] =
                                    DICE_ROLL();
                        }
                        /* add the values for the two dice rolls */
                        roll_totals[player_count] =
                            cur_rolls[FIRST] + cur_rolls[SECOND];
                        /* print out the dice rolls for the current player */
                        normal_print("%s rolls a %d and a %d\n",
                                     thegame->players[player_count].name,
                                     cur_rolls[FIRST], cur_rolls[SECOND]);
                }
        }
        /* decide who the first player will be - the one with the higher
         * dice roll
         */
        if (roll_totals[FIRST] > roll_totals[SECOND])
        {
                thegame->current_player = &thegame->players[FIRST];
                thegame->other_player = &thegame->players[SECOND];
        }
        else
        {
                thegame->current_player = &thegame->players[SECOND];
                thegame->other_player = &thegame->players[FIRST];
        }
        /* set the properties for the first and second player for starting
         * the game
         */
        thegame->current_player->token = P_WHITE;
        thegame->other_player->token = P_RED;

        thegame->current_player->orientation = OR_CLOCKWISE;
        thegame->other_player->orientation = OR_ANTICLOCKWISE;
        /* print out the details of each player so we can see they have been
         * set
         */
        normal_print(
            "%s is playing first and their token colour is %swhite%s.\n",
            thegame->current_player->name, color_strings[COLOR_WHITE],
            color_strings[COLOR_RESET]);
        normal_print(
            "%s is the other player and their token color is %sred%s.\n",
            thegame->other_player->name, color_strings[COLOR_RED],
            color_strings[COLOR_RESET]);
}

/**
 * static methods are only visible in the current module from this place forward
 **/

/**
 * gets the location of the piece on the board based on the board index passed
 * in. the board index should be the column number as printed out when the
 * board is printed.
 **/
static struct piece_location current_player_index(int index,
                                                  enum orientation orient)
{
        struct piece_location result;
        int curx;
        int cury;
        enum direction dir;
        /**
         * if the piece is in the lower half of the player board, ie heading
         * towards the home board
         **/
        if (index <= BOARD_WIDTH)
        {
                /* the column number will be the opposite of the index passed in
                 * as we count from highest to lowest but this is the opposite
                 * to array layout
                 */
                curx = BOARD_WIDTH - index;
                /* the y index is set to either the top or bottom of the
                 * board, depending on the direction of travel
                 */
                if (orient == OR_CLOCKWISE)
                {
                        /* top */
                        cury = 0;
                        dir = DIR_DOWN;
                }
                else
                {
                        /* bottom */
                        cury = BOARD_HEIGHT - 1;
                        dir = DIR_UP;
                }
        }
        else
        {
                /* indexes in the range of 13 to 24 for the current player */
                curx = index - BOARD_WIDTH - 1;
                if (orient == OR_CLOCKWISE)
                {
                        /* in the top half of the board */
                        cury = BOARD_HEIGHT - 1;
                        dir = DIR_UP;
                }
                else
                {
                        /* in the bottom half of the board */
                        cury = 0;
                        dir = DIR_DOWN;
                }
        }
        /* record the values we have set and return them */
        result.direction = dir;
        result.x = curx;
        result.y = cury;
        return result;
}

/**
 * adds an offset to a piece location for the final location of a move
 **/
static struct piece_location location_add(struct piece_location aloc,
                                          int move_size,
                                          enum orientation orient)
{
        int x = aloc.x;
        int y = aloc.y;
        enum direction dir = aloc.direction;
        struct piece_location newloc;
        /* a white token */
        if (orient == OR_CLOCKWISE)
        {
                /* are we at the bottom of the board? */
                if (dir == DIR_UP)
                {
                        /* subtranct the move from the x coordinate. If it goes
                         * below 0 then we switch to the top half of the board
                         */
                        x -= move_size;
                        if (x < 0)
                        {
                                x = abs(x) - 1;
                                y = 0;
                                dir = DIR_DOWN;
                        }
                }
                else
                {
                        /* top half of the board - we are on our way to the home
                         * board so just add. We'll check for array overflow
                         * later
                         */
                        x += move_size;
                }
        }
        else
        {
                /* for red tokens */
                /* are we at the bottom of the board ? if so, just add onto x
                 * as we are moving upward in array indexes */
                if (dir == DIR_UP)
                {
                        x += move_size;
                }
                else
                {
                        /* apply the move offset and handle flipping from the
                         * top
                         * of the board down to the bottom
                         */
                        x -= move_size;
                        if (x < 0)
                        {
                                x = abs(x) - 1;
                                y = 13;
                                dir = DIR_UP;
                        }
                }
        }
        /**
         * collate the results of the move and return them as they are the
         * data for a move
         **/
        newloc.x = x;
        newloc.y = y;
        newloc.direction = dir;
        return newloc;
}

/**
 * detect if all the tokens in play for a particular player are in their home
 * board. The home board is defined for a player to be those columns labelled
 * as 1-6 when the board is printed out.
 **/
static BOOLEAN all_in_home_board(const struct player* curplayer)
{
        int ycount, xcount;
        /**
         * if some tokens are currently on the bar then clearly not all tokens
         * are in the home board.
         **/
        if (curplayer->bar_list.token_count > 0)
        {
                return FALSE;
        }
        /**
         * iterate over all cells on the board
         **/
        for (ycount = 0; ycount < BOARD_HEIGHT; ++ycount)
        {
                for (xcount = 0; xcount < BOARD_WIDTH; ++xcount)
                {
                        /* does this cell contain one of the player's tokens? */
                        if (curplayer->curgame->game_board[ycount][xcount] ==
                            curplayer->token)
                        {
                                /* if we are examining a ce ll in the 'right
                                 * half' for the array, it is possible it is in
                                 * the home board depending on the player's
                                 * orientation
                                 */
                                if (xcount >= BOARD_WIDTH / 2)
                                {
                                        /* for a clockwise piece, we're in the
                                         * home board if we are on the top half
                                         * of the board
                                         */
                                        if (curplayer->orientation ==
                                            OR_CLOCKWISE)
                                        {
                                                if (ycount >= BOARD_HEIGHT / 2)
                                                {
                                                        return FALSE;
                                                }
                                        }

                                        /* for an anticlockwise piece, we're in
                                         * the home board if we are on the
                                         * bottom half of the board
                                         */
                                        else
                                        {
                                                if (ycount < BOARD_HEIGHT / 2)
                                                {
                                                        return FALSE;
                                                }
                                        }
                                }
                                else
                                {
                                        /* left half of the board */
                                        return FALSE;
                                }
                        }
                }
        }
        return TRUE;
}

/**
 * does this column contain the token specified?
 **/
static BOOLEAN column_contains(board theboard, const struct piece_location* loc,
                               enum piece token)
{
        return theboard[loc->y][loc->x] == token;
}

/**
 * how many tokens of the colour specified are in this column?
 **/
static int column_token_count(board aboard, const struct piece_location* loc,
                              enum piece token)
{
        int token_count = 0;
        int increment;
        int ycount;
        /* set the direction of the count - counting upwards means
         * decrementing by one on the y position for each token and counting
         * downwards means incrementing the y array position
         */
        if (loc->direction == DIR_UP)
        {
                increment = -1;
                ycount = BOARD_HEIGHT - 1;
        }
        else
        {
                increment = 1;
                ycount = 0;
        }
        /**
         * do the counting
         **/
        while (aboard[ycount][loc->x] == token)
        {
                ycount += increment;
                ++token_count;
        }
        return token_count;
}

/**
 * this next section of the module is for enabling my solution to matching moves
 * to dice rolls - a move should really be the sum of some subset of the dice
 * rolls. Ie: it could be the sum or all of them or any smaller group of
 * dice rolls.
 *
 * The algorithm is based on the concept of a falsible pair tuple. A pair tuple
 * is a pair of a value and the original index it was located at. So the pair
 * tuple can have values removed or reorganised and we know what the original
 * index was in the array.
 *
 * I then put the pair_tuple into a struct with a boolean so it can define that
 * whether the requested operation can succeed and if it has, we then look at
 * that pair_tuple.
 *
 * This section is a good example of how an array can be returned and passed by
 * value by wrapping it in a struct. Please note that this idea / concept that
 * a struct enforces value semantics on its contents is one that has been
 * borrowed by C# as well.
 **/

/**
 * add an element to our tuple
 **/

static void tuple_add(struct pair_tuple* tuple, struct int_pair val)
{
        /* insert the int pair into the next available slot and increment the
         * slot count
         */
        tuple->tuple_vals[tuple->tuple_count] = val;
        ++tuple->tuple_count;
}

/**
 * performs a sum over the pair_tuple
 **/
static int array_sum(const struct pair_tuple* thetuple)
{
        int count, result = 0;
        /**
         * iterate over the tuple's values
         **/
        for (count = 0; count < thetuple->tuple_count; ++count)
        {
                /* sum up the values */
                result += thetuple->tuple_vals[count].value;
        }
        return result;
}

/**
 * this is the core of my algorithm to match moves to dice rolls. for a given
 * target sum, we first check if the total sum for this tuple matches the
 * target sum and if it does, we set success to true and return the tuple.
 *
 * Otherwise we iterate over the values in the tuple, inserting all values
 * except the current value into a pair tuple. We then recursively perform this
 * operation to see whether any subset of the pairs in the tuple will give us
 * the desired target sum
 **/
static struct falsible_pair_tuple find_sum(struct falsible_pair_tuple* nums,
                                           int target_sum)
{
        struct falsible_pair_tuple sum_indexes;
        int count, except_count;
        /**
         * zero initialize
         **/
        memset(&sum_indexes, 0, sizeof(sum_indexes));
        /**
         * base case for recursion. If the tuple passed in is empty, our search
         * for the target sum has failed.
         **/
        if (nums->thepairs.tuple_count == 0)
        {
                sum_indexes.success = FALSE;
                return sum_indexes;
        }
        /**
         * if the sum of this tuple matches the desired sum, we have succeeded
         * so we set the success member for falsible_tuple to true and copy
         * the data across and return it.
         **/
        if (array_sum(&nums->thepairs) == target_sum)
        {
                memcpy(&sum_indexes, nums, sizeof(*nums));
                sum_indexes.success = TRUE;
                return sum_indexes;
        }
        for (except_count = 0; except_count < nums->thepairs.tuple_count;
             ++except_count)
        {
                /**
                 * iterate over the elements of the pairs tuple and insert all
                 * elements except the current element into the pair tuple.
                 **/
                memset(&sum_indexes, 0, sizeof sum_indexes);
                for (count = 0; count < nums->thepairs.tuple_count; ++count)
                {
                        if (count != except_count)
                        {
                                tuple_add(&sum_indexes.thepairs,
                                          nums->thepairs.tuple_vals[count]);
                        }
                }
                /**
                 * search for a subset of the current tuple that matches the
                 * required sum
                 **/
                sum_indexes = find_sum(&sum_indexes, target_sum);
                if (sum_indexes.success)
                {
                        return sum_indexes;
                }
        }
        return sum_indexes;
}

/**
 * test for valid moves. Have a look at the assignment specifications for
 * full details. If a move is valid, you will have to add the move offsets to
 * the changes array so they can be applied in apply_moves.
 **/
BOOLEAN validate_moves(const struct move selected_moves[], int num_moves,
                       const struct player* curplayer, const int dicerolls[],
                       struct move_pair changes[])
{
        int move_count;
        enum orientation orient = curplayer->orientation;
        enum piece player_token = curplayer->token;
        struct piece_location destination;
        BOOLEAN matched_rolls[MAX_ROLLS] = { 0 };
        int dice_values[MAX_ROLLS];
        int roll_count;
        int total_matched_rolls;
        int dice_count;

        /**
         * if the bar list is not empty, we must move from there first
         **/
        if (curplayer->bar_list.token_count > 0)
        {
                for (move_count = 0; move_count < num_moves; ++move_count)
                {
                        int mycount, theircount;
                        /* check for the barlist char as the start location */
                        if (selected_moves[move_count].index != BARLIST_CHAR)
                        {
                                return FALSE;
                        }
                        /* default to the y location being bottom for clockwise
                         * and top for counterclockwise as that's where it will
                         * be for a smaller move (less than 12)
                         */
                        if (orient == OR_CLOCKWISE)
                        {
                                destination.y = BOARD_HEIGHT - 1;
                                destination.direction = DIR_UP;
                        }
                        else
                        {
                                destination.y = 0;
                                destination.direction = DIR_DOWN;
                        }
                        /* x should default to the offset specified by the user
                         */
                        destination.x =
                            BOARD_WIDTH - selected_moves[move_count].count;
                        /* count the number of tokens at the target location
                         * for both friendly and enemy tokens */
                        mycount =
                            column_token_count(curplayer->curgame->game_board,
                                               &destination, curplayer->token);
                        theircount = column_token_count(
                            curplayer->curgame->game_board, &destination,
                            OTHER_TOKEN(curplayer->token));
                        /* the target column should contain either friendly
                         * tokens or be empty
                         */
                        if (!column_contains(curplayer->curgame->game_board,
                                             &destination, player_token) &&
                            !column_contains(curplayer->curgame->game_board,
                                             &destination, P_EMPTY) &&
                            theircount > 1)
                        {
                                return FALSE;
                        }
                        /**
                         * there should be space to insert this token in that
                         * column
                         **/
                        if (mycount > COLUMN_HEIGHT)
                        {
                                return FALSE;
                        }
                        /**
                         * all good so insert this move into the changes list
                         **/
                        changes[move_count].start.x = BARLIST_CHAR;
                        changes[move_count].end = destination;
                }
        }
        else
        {
                /**
                 * if the bar list is empty, iterate over the moves
                 **/
                for (move_count = 0; move_count < num_moves; ++move_count)
                {
                        /* get the location in the array for this piece */
                        struct piece_location start = current_player_index(
                            selected_moves[move_count].index, orient);
                        /* get the destination cell for this piece */
                        int curoffset = selected_moves[move_count].count;
                        destination = location_add(start, curoffset, orient);
                        /* check whethre this piece can be moved off the board
                         */
                        if (destination.x >= BOARD_WIDTH)
                        {
                                if (!all_in_home_board(curplayer))
                                {
                                        return FALSE;
                                }
                        }
                        else
                        {
                                /* the move needs to contain one of the player's
                                 * tokens in the starting column */
                                if (!column_contains(
                                         curplayer->curgame->game_board, &start,
                                         player_token))
                                {
                                        return FALSE;
                                }
                                /* if the target column contains an opponent
                                 * piece, it must be a maximum of one piece
                                 */
                                if (column_contains(
                                        curplayer->curgame->game_board,
                                        &destination,
                                        OTHER_TOKEN(player_token)))
                                {
                                        if (column_token_count(
                                                curplayer->curgame->game_board,
                                                &destination,
                                                OTHER_TOKEN(player_token)) > 1)
                                        {
                                                return FALSE;
                                        }
                                }
                        }
                        /* all good, store the changes */
                        changes[move_count].start = start;
                        changes[move_count].end = destination;
                }
        }
        /**
         * now we need to validate the dice rolls. The first part of that is
         * to check if both rolls were the same and if they were, we will
         * consider that there have been four rolls of the same number
         **/
        if (dicerolls[FIRST] == dicerolls[SECOND])
        {
                for (roll_count = 0; roll_count < MAX_ROLLS; ++roll_count)
                {
                        dice_values[roll_count] = dicerolls[FIRST];
                }
        }
        else
        {
                /* otherwise, just copy the dice_rolls across to dice_values as
                 * these will be the starting point for validating agains the
                 * moves
                 */
                memcpy(dice_values, dicerolls, sizeof(*dicerolls) * NUM_DICE);
                roll_count = NUM_DICE;
        }
        total_matched_rolls = 0;
        /* iterate over the moves and try to find matching dice rolls.
         * Each move must match a sum of 1 or more dice rolls
         */
        for (move_count = 0; move_count < num_moves; ++move_count)
        {
                struct falsible_pair_tuple results_tuple;
                struct pair_tuple* results = &results_tuple.thepairs;
                int match_count;
                struct falsible_pair_tuple rolls_tuple;
                struct pair_tuple* rolls_list = &rolls_tuple.thepairs;

                /* add all unmatched dice rolls to the group of potential dice
                 * rolls to match against
                 */
                memset(&rolls_tuple, 0, sizeof rolls_tuple);
                for (dice_count = 0; dice_count < roll_count; ++dice_count)
                {
                        if (!matched_rolls[dice_count])
                        {
                                rolls_list->tuple_vals[rolls_list->tuple_count]
                                    .value = dice_values[dice_count];
                                rolls_list->tuple_vals[rolls_list->tuple_count]
                                    .index = dice_count;
                                ++rolls_list->tuple_count;
                        }
                }
                /* search to see if this matches a subset of the currently
                 * unmatched dice
                 */
                results_tuple =
                    find_sum(&rolls_tuple, selected_moves[move_count].count);
                /* if it does not, an invalid move was entered */
                if (!results_tuple.success)
                {
                        return FALSE;
                }
                /* mark each matched roll as having been used */
                for (match_count = 0;
                     match_count < results_tuple.thepairs.tuple_count;
                     ++match_count)
                {
                        matched_rolls[results->tuple_vals[match_count].index] =
                            TRUE;

                        ++total_matched_rolls;
                }
        }
        return TRUE;
}

/**
 * adds the token type specified to the column specified.
 **/
static BOOLEAN column_add(board game_board, struct piece_location* target,
                          enum piece token, struct player* opponent)
{
        const int MIN_SAFE_TOKENS = 2;
        enum piece curtok;
        int tokcount;
        /* if the column contains more than one token from the oppoenent
         * player then the token cannot be placed */
        if (column_contains(game_board, target, opponent->token) &&
            column_token_count(game_board, target, opponent->token) >=
                MIN_SAFE_TOKENS)
        {
                return FALSE;
        }
        /* if the target location is empty already, just place the token */
        curtok = game_board[target->y][target->x];
        if (curtok == P_EMPTY)
        {
                game_board[target->y][target->x] = token;
        }
        else if (curtok == token)
        {
                /* if the token to be placed is of the same type as the bottom
                 * token in the current loction */
                if (target->direction == DIR_UP)
                {
                        /* check if there is space to place it */
                        for (tokcount = target->y;
                             tokcount > COLUMN_HEIGHT &&
                                 game_board[tokcount][target->x] == token;
                             --tokcount)
                                ;
                        if (tokcount == COLUMN_HEIGHT)
                        {
                                return FALSE;
                        }
                        /* if so, place it */
                        game_board[tokcount][target->x] = token;
                }
                else
                {
                        /* check if there is space to place the token */
                        for (tokcount = target->y;
                             tokcount < COLUMN_HEIGHT &&
                                 game_board[tokcount][target->x] == token;
                             ++tokcount)
                                ;
                        if (tokcount == COLUMN_HEIGHT)
                        {
                                return FALSE;
                        }
                        /* if so, place it */
                        game_board[tokcount][target->x] = token;
                }
        }
        else
        {
                /* landing on opponent piece - double check there is only one
                 * piece at this locatoin */
                assert(column_token_count(game_board, target,
                                          OTHER_TOKEN(token)) == 1);
                /* put the piece on the barlist */
                barlist_push(&opponent->bar_list,
                             game_board[target->y][target->x]);
                /* place our piece */
                game_board[target->y][target->x] = token;
        }
        return TRUE;
}

/**
 * remove a piece from its current column as part of moving the piece
 **/
static BOOLEAN column_remove(board game_board, struct piece_location* source,
                             enum piece token)
{
        int rowcount;
        /**
         * if a token of the target type is not actually at this location,
         * it is an invalid move
         **/
        if (game_board[source->y][source->x] != token)
        {
                return FALSE;
        }

        /* remove a piece from the top of the pile */
        if (source->direction == DIR_UP)
        {
                for (rowcount = source->y;
                     rowcount > COLUMN_HEIGHT &&
                         game_board[rowcount - 1][source->x] == token;
                     --rowcount)
                        ;
                if (rowcount == COLUMN_HEIGHT)
                {
                        return FALSE;
                }
                game_board[rowcount][source->x] = P_EMPTY;
        }
        else
        {
                for (rowcount = source->y;
                     rowcount < COLUMN_HEIGHT &&
                         game_board[rowcount + 1][source->x] == token;
                     ++rowcount)
                        ;
                if (rowcount == COLUMN_HEIGHT)
                {
                        return FALSE;
                }
                game_board[rowcount][source->x] = P_EMPTY;
        }

        return TRUE;
}

/**
 * apply the moves listed in themoves. These are offset pairs that were inserted
 * in the "changes" array in the validate_moves() function.
 **/

BOOLEAN
apply_moves(const struct move_pair themoves[], int num_moves,
            struct player* curplayer)
{
        struct player* other_player = curplayer->curgame->other_player;
        int move_count;
        /**
         * ierate over the list of move changes that have been requested
         **/
        for (move_count = 0; move_count < num_moves; ++move_count)
        {
                struct piece_location start = themoves[move_count].start;
                struct piece_location end = themoves[move_count].end;
                /* if this move is from the bar list , pop off the bar list and
                 * add it to the target column
                 */
                if (start.x == BARLIST_CHAR)
                {
                        enum piece popped_token;
                        assert(curplayer->bar_list.token_count > 0);
                        popped_token = barlist_pop(&curplayer->bar_list);
                        column_add(curplayer->curgame->game_board, &end,
                                   popped_token, other_player);
                }
                else
                {
                        /* if this piece is to be moved off the board, simply
                         * remove from the start column and increment the
                         * player's score by one
                         */
                        if (end.x >= BOARD_WIDTH)
                        {
                                column_remove(curplayer->curgame->game_board,
                                              &start, curplayer->token);
                                ++curplayer->score;
                        }
                        else
                        {
                                /* if we can't actually remove the requested
                                 * piece, there was an error in validating the
                                 * move, so return FALSE
                                 */
                                if (!column_remove(
                                         curplayer->curgame->game_board, &start,
                                         curplayer->token))
                                {
                                        return FALSE;
                                }
                                /* add the piece to the target column */
                                if (!column_add(curplayer->curgame->game_board,
                                                &end, curplayer->token,
                                                other_player))
                                {
                                        return FALSE;
                                }
                        }
                }
        }
        return TRUE;
}

/**
 * determines whether the player has won the game. the player has won the game
 * when they have no tokens on the board and there are no tokens in their bar
 * list.
 **/

BOOLEAN has_won_game(const struct player* curplayer)
{
        int xcount, ycount;

        /**
         * if there are pieces in the player's bar list, they have not won yet
         **/

        if (curplayer->bar_list.token_count != 0)
        {
                return FALSE;
        }

        /* if there are pieces on the board still, the player has not won the
         * game
         */
        for (ycount = 0; ycount < BOARD_HEIGHT; ++ycount)
        {
                for (xcount = 0; xcount < BOARD_WIDTH; ++xcount)
                {
                        if (curplayer->curgame->game_board[ycount][xcount] ==
                            curplayer->token)
                        {
                                return FALSE;
                        }
                }
        }
        return TRUE;
}
