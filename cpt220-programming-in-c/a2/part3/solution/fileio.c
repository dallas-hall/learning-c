/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "fileio.h"

/**
 * loads the data from the filename specified into the linked list.
 * If the linked list is not empty you should release any data it contains
 * first.
 **/
BOOLEAN load_data(const char fname[], struct linkedlist* scorelist)
{
        /* open the data file */
        FILE* reader = fopen(fname, "r");
        char line[MAXRESULTSTRING + EXTRA_CHARS];

        /* validate that we were able to open the file successfully */
        if (!reader)
        {
                /* if the file does not exist, that's ok - we just have an empty
                 * list for now - we'll save out any new data later */
                if (errno == ENOENT)
                {
                        return TRUE;
                }
                perror("fopen failed");
                return FALSE;
        }
        /**
         * if the linked list currently contains any nodes, free them
         **/
        if (scorelist->size)
        {
                linkedlist_free(scorelist, free_result);
        }
        /* initialise the list to be an empty list */
        linkedlist_init(scorelist);
        /**
         * read each line in from the file
         **/
        while (fgets(line, MAXRESULTSTRING + EXTRA_CHARS, reader))
        {
                struct game_result* newresult;
                /* validate that the whole string was read in */
                if (line[strlen(line) - 1] != '\n')
                {
                        fprintf(stderr,
                                "Error: lines longer than allowed occured in "
                                "the file.\n");
                        return FALSE;
                }
                /* remove the new line as it has served its purpose */
                line[strlen(line) - 1] = 0;
                /* get the game result from the string */
                newresult = result_from_string(line);
                if (!newresult)
                {
                        return FALSE;
                }
                /* add the new score to the linked list */
                if (!linkedlist_add(scorelist, newresult, score_cmp))
                {
                        fclose(reader);
                        return FALSE;
                }
        }
        /* don't forget to close the file */
        fclose(reader);
        return TRUE;
}

/**
 * saves the linked list to the filename spacified
 **/
BOOLEAN save_data(const char fname[], const struct linkedlist* thelist)
{
        return FALSE;
}
