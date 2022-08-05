/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "helpers.h"
#include "io.h"

/**
 * duplicates a string passed in by allocating memory for it and copying the
 * data. Please note that this function is implemented in C99 but I find it to
 * be a rather convenient function so I often implement it in my ansi C code.
 **/
char* strdup(const char* orig)
{
        /**
         * allocate sufficient memory for the string, including the nul
         * terminator
         **/
        char* new = malloc(strlen(orig) + 1);
        /**
         * check that the allocation succeeded and if it did not, print an
         * error message
         **/
        if (!new)
        {
                error_print(strerror(errno));
                return NULL;
        }
        /**
         * copy the data
         **/
        strcpy(new, orig);
        return new;
}

/**
 * tokenizes the string passed in into a series of move strings. That is,
 * splits up the entered string at the semicolons
 **/
BOOLEAN
get_move_strings(char* moves[], int* total_moves, const char input[])
{
        char* tok;
        int moves_count = 0;
        char* delims = ";";
        /**
         * make a copy of the string
         **/
        char* copy = strdup(input);
        if (!copy)
        {
                return FALSE;
        }
        /* grab the first move string */
        tok = strtok(copy, delims);
        while (tok)
        {
                /* tokenize at the semicolong, storing each string */
                moves[moves_count++] = strdup(tok);
                tok = strtok(NULL, delims);
        }
        /* store a count of each move string we process */
        *total_moves = moves_count;
        free(copy);
        return TRUE;
}

/**
 * this enum is only used in the following function and so it is declared here.
 * Ofen in C we only make objects visible to the code that actually needs it and
 * this is an example of this principle
 **/
/**
 * move index is the component of a move string we are processing:
 * - the index, or the starting position on the board for the move
 * - the value, or how many spots on the board the current move should move.
 **/
enum move_ind
{
        MI_INDEX,
        MI_VALUE,
        MI_INVALID
};

/**
 * takes a string that is meant to represent a move on the board and parses it
 * into a struct move which is in numerical form and thus easier for use to
 * manipulate
 **/
struct move strtomove(const char movestr[])
{
        struct move parsed_move;
        /* duplicate the string as strtok() modifies the string */
        char* copy = strdup(movestr);
        /* we will tokenize on the ":" or what is called the colon */
        const char* delims = ":";
        char* tok;
        /* count of how many tokens have been processed */
        enum move_ind tok_count = 0;

        /**
         * if we failed to make a copy of the string, we exit as there's no
         * point in going further.
         **/
        if (!copy)
        {
                return error_move;
        }
        /* start the string tokenization */
        tok = strtok(copy, delims);
        /* continue while there is another token to process */
        while (tok)
        {
                switch (tok_count)
                {
                        /* process the first value that is tokenized */
                        case MI_INDEX:
                                /* can start with a B or a number */
                                if (*tok == BARLIST_CHAR)
                                {
                                        parsed_move.index = BARLIST_CHAR;
                                }
                                /* otherwise, convert to int */
                                else if (!strtoint(&parsed_move.index, tok))
                                {
                                        return error_move;
                                }
                                break;
                        case MI_VALUE:
                                /* convert the offset to int */
                                if (!strtoint(&parsed_move.count, tok))
                                {
                                        free(copy);
                                        return error_move;
                                }
                                break;
                        default:
                                /* check that we only have two tokens in the
                                 * string to be tokenized
                                 */
                                error_print("too many colons in a move!");
                                free(copy);
                                return error_move;
                                break;
                }
                /* move to the next token */
                tok = strtok(NULL, delims);
                ++tok_count;
        }
        free(copy);
        return parsed_move;
}

/**
 * extracts an int from a string
 **/
BOOLEAN strtoint(int* result, const char input[])
{
        /**
         * a pointer to the next index after what was successfully parsed
         **/
        char* end;
        long lresult;
        /**
         * extract a long int from the string.
         **/
        lresult = strtol(input, &end, DECIMAL);
        /**
         * iterator over the string checking that there is only whitespace
         * after the number that as been converted.
         **/
        while (isspace(*end))
        {
                ++end;
        }
        /**
         * if we are not at the end of the string, there is some non-numeric
         * data
         **/
        if (*end)
        {
                error_print("%s is not numeric!\n", input);
                return FALSE;
        }
        /**
         * check that the long extracted
         **/
        if (lresult < INT_MIN || lresult > INT_MAX)
        {
                error_print("%ld is out of the range of an int!!\n", lresult);
                return FALSE;
        }
        /* the value is valid so we assign it back to the calling function's
         * memory
         */
        *result = lresult;
        return TRUE;
}

/**
 * function that folds a string passed in so that it can be printed with no
 * wraparound on an 80 column display
 **/
char* fold(const char origline[])
{
        /* get the length of the string so we know when we have finished
         * processing it
         */
        int len = strlen(origline);
        int numleft = strlen(origline);
        /**
         * duplicate the string so we leave the original the way it was
         **/
        char* copy = strdup(origline);
        char* current;
        /* check that our copy succeeded */
        if (!copy)
        {
                return NULL;
        }
        /* start iteration - set current to the start of our string and move
         * along by a single screen width
         */
        current = copy;
        current += LINE_LEN;
        numleft -= LINE_LEN;
        /**
         * continue this process until we have exhausted the string
         **/
        while (numleft > 0)
        {
                /* search for the last space character */
                while (!isspace(*current))
                {
                        --current;
                }
                /* replace it with a newline character */
                *current = '\n';
                /* jump to the next line */
                current += LINE_LEN;
                numleft = len - (current - copy);
        }
        return copy;
}
