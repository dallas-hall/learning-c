/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
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
 * main function that kickstatts the program
 **/
int main(int argc, char* argv[])
{
        struct falsible_long seed = { 0 };
        /* was no seed passed in? */
        if (argc == MAXARGS)
        {
                /* retrieve the seed from argv 1 */
                seed = longfromstr(argv[SEED_ARG]);
                /* if we did not succeed in retrieving the seed,
                 * exit the program
                 */
                if (!seed.success)
                {
                        return EXIT_FAILURE;
                }
                /* start the game, passing in the seed */
        }
        play_game(seed);

        /**
         * dead code bug required in order to avoid compiler warnings
         **/
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
        /* remove this return statement and replace it with the code to
         * initialise the system. Also, remove this comment */
        return FALSE;
}

/**
 * initialise the menu manu array to hold the right strings and function
 * pointers
 **/
void init_main_menu(struct main_menu_entry mainmenu[])
{
}
