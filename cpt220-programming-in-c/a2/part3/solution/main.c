/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "main.h"

/**
 * function converts string data to a long and sets its BOOLEAN member to FALSE
 * if anything goes wrong.
 **/
struct falsible_long longfromstr(const char* str)
{
        /**
         * pointer to the next character after what we successfully parses with
         * strtol().
         **/
        char* end;
        /**
         * the result that we will return
         **/
        struct falsible_long result;
        /**
         * parse the string
         **/
        result.thelong = strtol(str, &end, DECIMAL);
        /**
         * ignore spaces at the end of the string
         **/
        while (isspace(*end))
        {
                ++end;
        }
        /**
         * if an invalid argument was passed into strtol or the number converted
         * is outside the range of a long, this operation failed so display
         * an error and exit.
         **/
        if (errno == EINVAL || errno == ERANGE)
        {
                result.success = FALSE;
                error_print("%s\n", strerror(errno));
                return result;
        }
        /**
         * if there was trailing data that was not numeric, display an error
         * message and return FALSE
         **/
        if (*end)
        {
                result.success = FALSE;
                error_print("the provided value is not numeric. \n");
                return result;
        }
        result.success = TRUE;
        return result;
}
/**
 * simple function to print out a node's data to the screen.
 **/
BOOLEAN simple_print(const struct game_result* result, FILE* out, void* arg)
{
        return fprintf(out, "%s\t%s\t%d\n", result->winner, result->loser,
                       result->won_by);
}
/**
 * main function that kickstatts the program
 **/
int main(int argc, char* argv[])
{
        struct game_system thesystem;
        /**
         * if no arguments were passed in, display an error and exit as we need
         * as a minimum one argument
         **/
        if (argc < MINARGS)
        {
                error_print("you need to pass in a file to load at "
                            "a minimum.\n");
                return EXIT_FAILURE;
        }
        /**
         * load up the system based on the filename passed in
         **/
        if (!init_system(&thesystem, argv[FILE_ARG]))
        {
                /* if this failed, we just exit as we couldn't load the data */
                return EXIT_FAILURE;
        }
        /**
         * a falsible number - set it to 0 as if no seed is passed it that's
         *what it should be.
         **/
        /* was no seed passed in? */
        if (argc == MAXARGS)
        {
                /* retrieve the seed from argv 1 */
                thesystem.gameseed = longfromstr(argv[SEED_ARG]);
                /* if we did not succeed in retrieving the seed,
                 * exit the program
                 */
                if (!thesystem.gameseed.success)
                {
                        return EXIT_FAILURE;
                }
                /* start the game, passing in the seed */
        }

        /* print out the linked list */

        linkedlist_print(&thesystem.scoreboard, stdout, NULL, simple_print);
        return EXIT_SUCCESS;
}

/**
 * function that performs the quit program action. It saves data to the
 * filename listed in game_system structure then frees all memory
 **/
void quit_program(struct game_system* thesystem)
{
}

/**
 * don't save back the data to the data file but free all memory before
 * exiting the program
 **/
void abort_program(struct game_system* thesystem)
{
}

/**
 * initialise menus and load data from disk. For part 2, you don't need to
 * initialise the menus, just load in the data.
 **/
BOOLEAN init_system(struct game_system* thesystem, const char fname[])
{
        memset(thesystem, 0, sizeof(struct game_system));
        if (!load_data(fname, &thesystem->scoreboard))
        {
                return FALSE;
        }
        thesystem->datafile = strdup(fname);
        if (!thesystem->datafile)
        {
                return FALSE;
        }
        return TRUE;
}

/**
 * initialise the menu manu array to hold the right strings and function
 * pointers
 **/
void init_main_menu(struct main_menu_entry mainmenu[])
{
}
