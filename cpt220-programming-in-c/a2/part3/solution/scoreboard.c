/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/

#include "scoreboard.h"
#include "io.h"
#include "main.h"
/**
 * function that implements comparison between two scores - a score will be
 * earlier in the list if it is larger.
 **/
int score_cmp(const struct game_result* first, const struct game_result* second)
{
        return second->won_by - first->won_by;
}

/**
 * frees a game result and all its contents. Please note this function
 * cannot be used on a stack memory address
 **/
void free_result(struct game_result* theresult)
{
        /* left unimplemented as this is still something you need to do */
}

/**
 * tokenize a string that represents a score, allocate space for the score and
 * the contained strings, and copy the appropriate data in
 **/
struct game_result* result_from_string(const char resultstr[])
{
        /* duplicate the string so we don't modify the original string during
         * tokenization
         */
        char* copy = strdup(resultstr);
        /* begin tokenization */
        char* tok = strtok(copy, ",");
        /* allocate space for the game result */
        struct game_result* newresult = malloc(sizeof(struct game_result));
        /* start the tokenization counter at the first element */
        enum result_ind tokind = RI_WINNER;
        /* zero out the struct so that all pointers are NULL */
        memset(newresult, 0, sizeof(struct game_result));
        while (tok)
        {
                /* tokenize the string and copy the values into the allocated
                 * struct. Handle errors appropriately
                 */
                switch (tokind)
                {
                        case RI_WINNER:
                                newresult->winner = strdup(tok);
                                if (!newresult->winner)
                                {
                                        free_result(newresult);
                                        free(copy);
                                        return NULL;
                                }
                                break;
                        case RI_LOSER:
                                newresult->loser = strdup(tok);
                                if (!newresult->loser)
                                {
                                        free_result(newresult);
                                        free(copy);
                                        return NULL;
                                }
                                break;
                        case RI_WONBY:
                                if (!strtoint(&newresult->won_by, tok))
                                {
                                        free_result(newresult);
                                        free(copy);
                                        return NULL;
                                }
                                break;
                        default:
                                error_print("there are too many "
                                            "tokens in the string.\n");
                                free(copy);
                                free_result(newresult);
                                return NULL;
                }
                /* move to the next token */
                tok = strtok(NULL, ",");
                ++tokind;
                /* handle strings where there are too few tokens */
                if (!tok && tokind < RI_INVALID)
                {
                        error_print("too few tokens.\n");
                        free_result(newresult);
                        free(copy);
                        return NULL;
                }
        }
        /* clean up temporary allocations */
        free(copy);
        /* all good so return game result */
        return newresult;
}

/**
 * initialise the scores menu with the text and functions that perform the
 * required functionality.
 **/
void init_scores_menu(struct scores_menu_entry scores_menu[])
{
}

/**
 * manages user input via the scores menu
 **/
void scores_menu(struct game_system* thesystem)
{
}

/**
 * performs the display scores function for the scores menu
 **/
BOOLEAN print_scores(struct game_system* thesystem)
{
        return FALSE;
}

/**
 * adds a score to the system via user input. Please note that in a real
 * game score menu this makes no sense but it's here so you can show you
 * can do it.
 **/
BOOLEAN add_score(struct game_system* thesystem)
{
        return FALSE;
}

/**
 * handles the "delete node" submenu for the system. Again, this would not
 * be a likely part of such a program in the real world but we are getting
 * you do do this so you can show you know how.
 **/
BOOLEAN delete_score(struct game_system* thesystem)
{
        return FALSE;
}

/**
 * clears out the scoreboard to make it an empty list
 **/
BOOLEAN remove_all_scores(struct game_system* thesystem)
{
        return FALSE;
}

/**
 * save scores back to the same file it was loaded from
 **/
BOOLEAN resave_scores(struct game_system* thesystem)
{
        return FALSE;
}

/**
 * saves the data file to a new file. The datafile attribute of the game system
 * should now point to the path of the file the data has been saved to. This is
 * similar to "save as" functionality in a word processor.
 **/
BOOLEAN save_scores(struct game_system* thesystem)
{
        return FALSE;
}
