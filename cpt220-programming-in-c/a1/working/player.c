/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
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
BOOLEAN
player_init(struct player* aplayer, struct game* thegame)
{
        char input[MAXPROMPTLEN];
        BOOLEAN done = FALSE;
        /*aplayer -> name[0] = 0;*/

        if(DEBUGGING) {
                printf("%s\n", "[DEBUG] player.c - Entering player_init.");
        }
        do {
                done = getName(input, MAXPROMPTLEN, aplayer);
        } while (!done);


        return TRUE;
}

/**
 * implement the taking of a turn and turn validation in this function and
 * functions called from here. Please refer to the assignment specifications
 * for details on what you need to do here.
 **/
enum input_result
player_take_turn(struct player* current_player)
{
        return IR_FAILURE;
}

/*
  This function reads in input from stdnin
  I have taken the concepts from /home/el9/E70949/shared/prog_in_c/tutes/week03/getname.c and chapter 8 from C How to program textbook.
*/
BOOLEAN getName(char s[], int size, struct player* aplayer)
{
        int i;
        if(DEBUGGING) {
                printf("%s\n", "[DEBUG] player.c - Entering getName.");
        }
        normal_print("Enter your name (max 20 characters): ", s);
        /*
         * Need to account for the '\n' and '\0' that fgets adds.
         * If the last isn't '\n' then we know we didn't receive all the input.
         * We need to remove the '\n' as well.
         */
        if(fgets(s, MAXPROMPTLEN + FGETS_EXTRA_CHARS, stdin) == NULL) {
                return FALSE;
        }
        if (s[strlen(s) - 1] != '\n')
        {
                error_print("[ERROR] buffer overflow.\n");
                clear_buffer();
                return getName(s, size, aplayer);
        }

        if (strlen(s) > NAME_LEN + 1) {
                error_print("[ERROR] Input too long, less than 20 only.\n");
                return getName(s, size, aplayer);
        }

        if(DEBUGGING) {
                printf("[DEBUG] player.c - strlen(s) before removing \\n is %ld\n", strlen(s));
                printf("[DEBUG] player.c - s is %s\n", s);
        }
        s[strlen(s) - 1] = '\0';

        if(DEBUGGING) {
                printf("[DEBUG] player.c - strlen(s) after removing \\n is %ld\n", strlen(s));
                printf("[DEBUG] player.c - s is %s\n", s);

                printf("%s\n", "[DEBUG] player.c - Printing s with for loop.");
                for(i = 0; i < strlen(s); i++) {
                        printf("%c", s[i]);
                }
                printf("\n");
        }

        strcpy(aplayer -> name, s);

        /*if(DEBUGGING) {
                printf("%s\n", "[DEBUG] player.c - Printing aplayer -> name with for loop..");
                s[strlen(s) - 1] = 0;
                for (i = 0; i < strlen(s); i++) {
                        printf("%c", aplayer -> name[i]);
                }
        }*/

        return TRUE;
}
