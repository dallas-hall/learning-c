/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"
#include "helpers.h"

const char* color_strings[NUM_COLORS] = {"\x1b[31m", "\x1b[37m", "\x1b[0m"};
const struct move error_move = {EOF, EOF};

/**
 * function that does buffer clearing when there is a buffer overflow on
 * input - only call this function when there is an actual buffer overflow as
 * otherwise you will have additional problems
 **/
void clear_buffer(void)
{
	int ch;
	/* while there are still chars to read and we have not reached
	 * the newline char, keep reading */
	while (ch = getc(stdin), ch != EOF && ch != '\n');
	/* reset the error status on the stdin file pointer */
	clearerr(stdin);
}

/**
 * this function simply calls printf. It is implemented here so that if we
 * wish to change our output target (such as using a gui) we could change our
 * implementation here and it would not affect any other code in our project.
 **/
int normal_print(const char format[], ...)
{
	int char_count;
	va_list vlist;
	va_start(vlist, format);
	char_count = vprintf(format, vlist);
	va_end(vlist);
	return char_count;
}

/**
 * this function prints out error messages to the stderr file pointer. It is
 * standard practice to output all error messages to stderr rather than
 * stdout (where printf sends messages).
 **/
int error_print(const char format[], ...)
{
	int char_count = 0;
	va_list vlist;
	char_count += fprintf(stderr, "Error: ");
	va_start(vlist, format);
	char_count += vfprintf(stderr, format, vlist);

	return char_count;
}

/**
 * print the heading for the board
 **/
static void print_heading(void)
{
	char* heading = "Backgammon - Current board state";
	puts(heading);
	PUTLINE('-', strlen(heading));
}

/**
 * print the top row based on the orientation of the current player
 **/
static void print_top_row(enum orientation orient)
{
	int xcount;
	/* for clockwise, print the numbers 12 down to 1 */
	if (orient == OR_CLOCKWISE) {
		for (xcount = BOARD_WIDTH; xcount > 0; --xcount) {
			normal_print("| %-2d ", xcount);
		}
	}
	else {
		/* for anticlockwise, print the numbers 13 to 24 */
		for (xcount = BOARD_WIDTH + 1; xcount <= 2 * BOARD_WIDTH;
				++xcount) {
			normal_print("| %-2d ", xcount);
		}
	}
	putchar('\n');
	/* put a line of dashes under the row */
	PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print the bottom row of the table
 **/
static void print_bottom_row(enum orientation orient)
{
	int xcount;
	/* if the player's orientation is clockwise print 13 to 24 */
	if (orient == OR_CLOCKWISE) {
		for (xcount = BOARD_WIDTH + 1; xcount <= BOARD_WIDTH * 2;
				++xcount) {

			normal_print("| %-2d ", xcount);
		}
	}
	else {
		/* if the player's orientation is anticlockwise, print the
		 * numbers 12 down to 1
		 */
		for (xcount = BOARD_WIDTH; xcount > 0; --xcount) {

			normal_print("| %-2d ", xcount);
		}
	}
	putchar('\n');
	PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print a row of the board
 **/
static void print_row(int rownum, board theboard)
{
	int count;
	putchar('|');
	for (count = 0; count < BOARD_WIDTH; ++count) {
		/* for each cell, print the appropriate code for a blank, red or
		 * white token
		 */
		switch (theboard[rownum][count]) {
			case P_EMPTY:
				normal_print(" %2c |", EMPTY_TOKEN);
				break;
			case P_RED:
				normal_print(
						" %s%2c%s |", color_strings[COLOR_RED],
						RED_TOKEN, color_strings[COLOR_RESET]);
				break;
			case P_WHITE:
				normal_print(
						" %s%2c%s |", color_strings[COLOR_WHITE],
						WHITE_TOKEN, color_strings[COLOR_RESET]);
				break;
			default:
				error_print(
						"Oh noes, invalid value in the board!!\n");
				return;
		}
	}
	putchar('\n');
	PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print out the board according to the orientation of the current player
 **/
void board_print(board theboard, enum orientation orient)
{
	int row_count;
	print_heading();
	print_top_row(orient);

	for (row_count = 0; row_count < BOARD_HEIGHT; ++row_count) {
		print_row(row_count, theboard);
	}
	print_bottom_row(orient);
}

/**
 * read strings from the keyboard input
 **/
enum input_result read_string(const char prompt[], char input[], int size)
{
	size_t len;
	/* print out the prompt */
	normal_print("%s: ", prompt);
	/* read data from the keyboard - if ctrl-d is detected, then return
	 * the quit value
	 */
	if (fgets(input, size + EXTRA_CHARS, stdin) == NULL) {
		return IR_QUIT;
	}
	/* if the newline is at the start of the input, return the 'skip turn'
	 * value
	 */
	if (*input == '\n') {
		return IR_SKIP_TURN;
	}
	/* check that there has not been buffer overflow */
	len = strlen(input);
	if (input[len - 1] != '\n') {
		error_print("your input was too long.\n");
		clear_buffer();
		return IR_FAILURE;
	}
	/* replace the new line with a null terminator */
	input[len - 1] = 0;
	return IR_SUCCESS;
}

/**
 * read an int from the keyboard
 **/
enum input_result read_int(const char prompt[], int* input)
{
	long lresult;
	enum input_result iresult;
	char input_string[LINE_LEN + EXTRA_CHARS];
	char* end;

	/* read in a string with the read_string function */
	if (iresult = read_string(prompt, input_string, LINE_LEN),
			iresult != IR_SUCCESS) {
		return iresult;
	}
	/* convert that string to a long integer if we can */
	lresult = strtol(input_string, &end, DECIMAL);
	/* skip over any white space in the string */
	while (isspace(*end)) {
		++end;
	}
	/* if there's leftover input at this point then non-numeric data
	 * has been detected
	 */
	if (*end) {
		error_print(
				"The input entered was not numeric. Please try again.\n");
		return IR_FAILURE;
	}
	/* finally validate that the long integer that has been read is
	 * within the range of an int */
	if (lresult < INT_MIN || lresult > INT_MAX) {
		error_print(
				"The number entered was outside the range of an int.\n");
		return IR_FAILURE;
	}
	/* store the value back to the caller */
	*input = lresult;
	return IR_SUCCESS;
}

/**
 * read in a set of moves from the user in the format of
* col:moves;col:moves;col:moves as many times as needed.
*
* The moves should be tokenized and converted to integers and then stored in
* the themoves array and the number of moves that are entered should be
* stored in the num_moves pointer. No more moves should be read than the number
* specified in the max_moves variable
**/
enum input_result read_moves(struct move themoves[], int* num_moves,
							 int max_moves)
{
	char line[LINE_LEN + EXTRA_CHARS];
	enum input_result iresult;
	char** move_strings;
	int num_tokens;
	int move_count;
	/* the prompt should be displayed in folded format */
	const char* prompt =
			fold("Please enter moves in the format of 3:4;2:5 where 3 abd 2 "
				 "are column numbers and 4 and 5 are the number of spaces to "
				 "move a token at that location. If you want to take a token "
				 "from your bar list, enter the starting column as B");
	/* read in user input as a string */
	if (iresult = read_string(prompt, line, LINE_LEN),
			iresult == IR_FAILURE || iresult == IR_QUIT ||
			iresult == IR_SKIP_TURN) {
		free((char*) prompt);
		return iresult;
	}
	free((char*) prompt);
	/**
	 * malloc space for the token strings for each move
	 **/
	move_strings = malloc(sizeof(char*) * max_moves);
	/* tokenize the user input into move strings (tokenize on the ;
	 * character
	 */
	if (!get_move_strings(move_strings, &num_tokens, line)) {
		return IR_FAILURE;
	}

	/**
	 * convert each movestring into an actual move
	 **/
	for (move_count = 0; move_count < num_tokens; ++move_count) {
		struct move themove = strtomove(move_strings[move_count]);
		if (themove.index == error_move.index) {
			return IR_FAILURE;
		}
		themoves[move_count] = themove;
		free(move_strings[move_count]);
	}
	free(move_strings);
	/* store the number of successful moves performed */
	*num_moves = num_tokens;
	return IR_SUCCESS;
}


/*
 * Copied the normal_print function for my debug messages.
 *
 * I used this instead of typing the same thing over and over again.
 */
int printDebug(const char format[], ...)
{
	int char_count = 0;
	va_list vlist;
	char_count += fprintf(stderr, "[DEBUG] ");
	va_start(vlist, format);
	char_count += vfprintf(stderr, format, vlist);

	return char_count;
}

BOOLEAN validInputName(const char* name)
{
	int nameLength;
	int i;

	if (name == NULL) {
		error_print("Name token is missing.\n");
		return FALSE;
	}

	/*
	 * Must be <= 20
	 */
	nameLength = strlen(name);
	if (nameLength > 20) {
		error_print("Name is too long. Must be <= 20 but is %d.\n",
					nameLength);
		return FALSE;
	}

	/*
	 * Must not have any punctuation in it.
	 *
	 * Paul did mention on the forum that - is probably acceptable as people
	 * can have them in their names. So I will look for all punctuation except
	 * a -
	 *
	 * The spec also talked about no tabs, but I am taking the hard line
	 * approach of [^[:space:]]
	 */
	for (i = 0; i < nameLength; i++) {
		if (ispunct(name[i]) && name[i] != '-') {
			error_print(
					"Invalid character found in the name. Must not contain punctuation but found %c\n",
					name[i]);
			return FALSE;
		}
		if (isspace(name[i]) && name[i] != ' ') {
			error_print(
					"Invalid character found in the name. Must not contain white space characters but found '%c'\n",
					name[i]);
			return FALSE;
		}
	}

	return TRUE;
}

int validWinningMargin(char* winningMarginPtr)
{
	char* strtolRemainderPointer;
	long winningMargin;

	if (winningMarginPtr == NULL) {
		error_print(
				"Invalid input in the third token, token is missing.\n");
		return -1;
	}

	/*
	 * Extract out the number using strtol.
	 * strtol will
	 *
	 * 1) Try to extract numbers used the supplied number system, in this case
	 * decimal.
	 * 2) Store any non-digits in strtolRemainderPointer, specifically the
	 * pointer to the first non-digit character.
	 *
	 * If there was no numbers at all, strtolRemainderPointer has the original
	 * string and 0 is returned.
	 */
	winningMargin = strtol(winningMarginPtr, &strtolRemainderPointer, BASE_10);

	/*
	 * Invalid characters found in the score.
	 *
	 * This means that an integer wasn't passed in. Could be decimal point or
	 * other non-integer junk.
	 */
	if (strlen(strtolRemainderPointer) > 0) {
		error_print(
				"Invalid input in the third token, should be an integer number only.\n");
		return -1;
	}

	/*
	 * The won by margin must be greater than 0, otherwise it would be a tie.
	 * There are only 15 tokens on the board, so that is the max won by margin.
	 */
	if (winningMargin <= 0 || winningMargin > 15) {
		error_print(
				"Invalid input in the third token, should be between 1 and 15 but was %ld.\n",
				winningMargin);
		return -1;
	}

	return (int) winningMargin;
}