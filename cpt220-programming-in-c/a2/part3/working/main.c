/******************************************************************************
 * Student Name    :  Dallas Hall
 * RMIT Student ID :  s3461243
 * COURSE CODE     :  CPT220 / OLA00
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "main.h"

/*
 * Using this variable in every .c file to control debug print messages.
 * I did this in the first assignment and it worked pretty well.
 */
const int DEBUGGING_MAIN = 0;

/*
 * Using this so I can pass the game_result into scoreboard so I can update
 * the scoreboard. Couldn't think of anything other way to do it with my
 * current design
 */
/*struct game_system* gameSystemPtr;*/

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
	while (isspace(*end)) {
		++end;
	}
	/**
	 * if an invalid argument was passed into strtol or the number converted
	 * is outside the range of a long, this operation failed so display
	 * an error and exit.
	 **/
	if (errno == EINVAL || errno == ERANGE) {
		result.success = FALSE;
		error_print("%s\n", strerror(errno));
		return result;
	}
	/**
	 * if there was trailing data that was not numeric, display an error
	 * message and return FALSE
	 **/
	if (*end) {
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
	struct falsible_long seed = {0};
	struct game_system* gameSystemPtr = NULL;
	/*
	 * Removing this pointer as I lost marks
	 *
	 * struct linkedlist* linkedListPtr = NULL;
	 */

	/*
	 * We need +1 here because of the program name being passed in automatically
	 * as the first argument. Remembering that the first element is actually 0
	 * and not 1.
	 */
	if (argc != MINARGS + 1 && argc != MAXARGS + 1) {
		error_print(
				"Invalid arguments. Arguments must be either 1 file path, or 1 file path and 1 seed number.\n");
		return EXIT_FAILURE;
	}
	else {
		if (argc == MAXARGS + 1) {
			/* retrieve the seed from argv 1 */
			seed = longfromstr(argv[SEED_ARG]);
			/* if we did not succeed in retrieving the seed,
			 * exit the program
			 */
			if (!seed.success) {
				error_print("Couldn't get the game seed.\n");
				return EXIT_FAILURE;
			}
		}

		if (DEBUGGING_MAIN) {
			printDebug("The file path passed in was %s\n", argv[FILE_PATH_ARG]);
			printDebug("The seed passed in was %s\n", argv[SEED_ARG]);
		}
	}

	/*
	 * Create and initialise the game system. Doing this here so it is alive
	 * for the duration of the running program.
	 */
	gameSystemPtr = createGameSystem();
	if (!gameSystemPtr) {
		error_print("Couldn't create the game system with malloc.\n");
		return EXIT_FAILURE;
	}
	if (DEBUGGING_MAIN) {
		/*
		 * From my understanding, everything should either be 0, NULL or '\0'
		 * at this point.
		 */
		printDebugGameSystem(gameSystemPtr);
	}

	/*
	 * Testing delete list nodes and list on an empty list
	 */
	if (DEBUGGING_MAIN) {
		deleteLinkedListNodes(&gameSystemPtr->scoreboard);
	}

	/*
	 * Create and initialise the linked list.
	 *
	 * Dereference the created linked list and store it int the game_system.
	 * Grab the address of that and store it in a pointer.
	 *
	 * linkedListPtr = createLinkedList();
	 * gameSystemPtr->scoreboard = *linkedListPtr;
	 */
	gameSystemPtr->scoreboard = *createLinkedList();

	/*
	 * Same as linkedListPtr == NULL, I tend to switch between both.
	 */
	if (&gameSystemPtr->scoreboard == NULL) {
		error_print("Couldn't create the linked list.\n");
		return EXIT_FAILURE;
	}


	/*
	 * Delete the list because we have dereferenced it, without deleting it here
	 * we will have a memory leak.
	 *
	 * Future calls to deleteLinkedList won't actually work because the list
	 * inside gameSystemPtr->scoreboard  wasn't created with malloc, it was
	 * dereferenced into it. We still need to free the nodes of the list and
	 * other parts of gameSystemPtr. Which are handled elsewhere.
	 *
	 * deleteLinkedList(linkedListPtr);
	 *
	 * Reassign the data inside game_system->scoreboard to the pointer.
	 *
	 * linkedListPtr = &gameSystemPtr->scoreboard;
	 */

	if (DEBUGGING_MAIN) {
		/*
		 * These should be the same.
		 */
		printf("The address of gameSystemPtr->scoreboard is %p\n",
			   (void*) &gameSystemPtr->scoreboard);
		/*printf("The address of linkedListPtr is %p\n", (void*) linkedListPtr);*/
	}

	/*
	 * Testing delete list nodes on an empty list
	 */
	if (DEBUGGING_MAIN) {
		remove_all_scores(gameSystemPtr);

		if (!remove_all_scores(gameSystemPtr)) {
			fprintf(stderr, "%s",
					"[ERROR] The list was empty, couldn't delete any scores.\n");
		}
	}

	/*
	 * Initialise the game system. i.e. load some data boys!
	 */
	if (!init_system(gameSystemPtr, argv[FILE_PATH_ARG])) {
		error_print("Couldn't initialise the game system.\n");
		return EXIT_FAILURE;
	}
	else {
		gameSystemPtr->gameseed.success = seed.success;
		gameSystemPtr->gameseed.thelong = seed.thelong;

		if (DEBUGGING_MAIN) {
			printDebugGameSystem(gameSystemPtr);
		}
	}

	/*
	 * We need to take the address of the list as the function expects a
	 * pointer.
	 *
	 * 	prettyPrintLinkedList(&gameSystemPtr->scoreboard);
	 * 	printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);
	 */

	/*
	 * Testing find a node.
	 */
	if (DEBUGGING_MAIN) {
		findNode(&gameSystemPtr->scoreboard, NULL);
		findNode(NULL, gameSystemPtr->scoreboard.head->next);
		if (findNode(&gameSystemPtr->scoreboard,
					 gameSystemPtr->scoreboard.head->next)) {
			printf("Node found.\n");
		}
		else {
			printf("Node not found.\n");
		}
	}

	/*
	 * Testing delete list on a populated list
	 */
	if (DEBUGGING_MAIN) {
		deleteLinkedListNodes(&gameSystemPtr->scoreboard);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);
	}

	if (DEBUGGING_MAIN) {
		/*
		 * These should be the same.
		 */
		printf("The address of gameSystemPtr->scoreboard is %p\n",
			   (void*) &gameSystemPtr->scoreboard);
		/*printf("The address of linkedListPtr is %p\n", (void*) linkedListPtr);*/
	}

	if (DEBUGGING_MAIN) {
		deleteLinkedListNodes(&gameSystemPtr->scoreboard);

		updateScoreboardManually("Roger", "Jamie", "15", gameSystemPtr);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

		updateScoreboardManually("Roger", "Jamie", "7", gameSystemPtr);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

		updateScoreboardManually("Jamie", "Roger", "1", gameSystemPtr);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

		updateScoreboardManually("Jamie", "Roger", "5", gameSystemPtr);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

		/*
		 * Should fail as this will be NULL
		 */
		/*deleteNode(&gameSystemPtr->scoreboard,
				   gameSystemPtr->scoreboard.head->next->next->next->next);*/
		deleteNodeViaPosition(&gameSystemPtr->scoreboard, 5);
		deleteNodeViaPosition(&gameSystemPtr->scoreboard, -1);

		/*
		 * Delete the middle
		 */
		/*deleteNode(&gameSystemPtr->scoreboard,
				   gameSystemPtr->scoreboard.head->next);*/
		deleteNodeViaPosition(&gameSystemPtr->scoreboard, 2);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

		/*
		 * Delete the tail
		 */
		/*deleteNode(&gameSystemPtr->scoreboard,
				   gameSystemPtr->scoreboard.head->next->next);*/
		deleteNodeViaPosition(&gameSystemPtr->scoreboard, 3);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

		/*
		 * Delete the head
		 */
		/*deleteNode(&gameSystemPtr->scoreboard, gameSystemPtr->scoreboard.head);*/
		deleteNodeViaPosition(&gameSystemPtr->scoreboard, 1);
		printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);
	}

	print_scores(gameSystemPtr);

	/* start the game, passing in the seed */
	play_game(seed);

	/*
	 * Cleanup after the game has finished.
	 */
	quit_program(gameSystemPtr);

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
	BOOLEAN result;

	result = save_data(thesystem->datafile, &thesystem->scoreboard);

	if (!result) {
		EXIT_FAILURE;
	}

	/*
	 * We don't need to delete the list as it will be deleted by
	 * deleteGameSystem. But we need to delete the nodes before calling that.
	 */
	result = remove_all_scores(thesystem);
	if (!result) {
		EXIT_FAILURE;
	}

	deleteGameSystem(thesystem);
}

/**
 * don't save back the data to the data file but free all memory before
 * exiting the program
 **/
void abort_program(struct game_system* thesystem)
{
	BOOLEAN result;

	result = remove_all_scores(thesystem);

	if (!result) {
		EXIT_FAILURE;
	}

	deleteGameSystem(thesystem);
}

/**
 * initialise menus and load data from disk. For part 2, you don't need to
 * initialise the menus, just load in the data.
 **/
BOOLEAN init_system(struct game_system* thesystem, const char fname[])
{
	/*
	 * if valid load_data and assign filename to thesystem->datafile
	 * else exit with error
	 *
	 * Blank input already covered by arg check, because there is a mandatory
	 * argument required which is the filename. If it is blank, it will fail
	 * that mandatory argument check.
	 */
	if (strlen(fname) > PATH_MAX) {
		error_print(
				"Input file path is too long, must be <= 4096 characters.\n");
		return FALSE;
	}

	/*
	 * I thought we were using simulated pass by reference here. Which is
	 * using the memory address of the linked list with &, so we can directly
	 * update that memory within the init_system function.
	 *
	 * But I think a copy of game_system is being passed here. Every time I
	 * think I understand pointers I realise I don't. Not sure how I fix this.
	 * Or maybe I am wrong???
	 */
	if (!load_data(fname, &thesystem->scoreboard)) {
		error_print("Couldn't load the data because of the above error.\n");
		return FALSE;
	}

	/*
	 * I learnt the value of using strdup here. Otherwise my strcpy approach
	 * would return:
	 * main.c: In function ‘init_system’:
	 * main.c:233:18: warning: passing argument 1 of ‘strcpy’ discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
	 * 233 |  strcpy(thesystem->datafile, fname);
	 */
	thesystem->datafile = strdup(fname);

	return TRUE;
}

/**
 * initialise the menu manu array to hold the right strings and function
 * pointers
 **/
void init_main_menu(struct main_menu_entry mainmenu[])
{
}

/*
 * Create and initialise our game system pointer.
 * Return this new zeroed out game system back to main.
 * We then pass this to init_system.
 *
 * Paul tends to cast the void* returned by malloc.
 */
struct game_system* createGameSystem()
{
	/*
	 * Using the global variable instead.
	 */
	struct game_system* gameSystemPtr;

	/*
	 * malloc tries to allocate memory with the specified bytes.
	 * sizeof will return the size of the data structure, platform dependent.
	 * If successful, malloc returns a void * to the allocated memory, otherwise
	 * returns NULL
	 *
	 * We are using struct game_system because that is the object that will be
	 * stored in the pointer.
	 *
	 * Paul tends to cast the void* returned by malloc.
	 */
	gameSystemPtr = malloc(sizeof(struct game_system));

	/*
	 * The same as gameSystemPtr == NULL. I tend to switch between the two.
	 */
	if (!gameSystemPtr) {
		return NULL;
	}
	else {
		/*
		 * memset copies a byte value for n bytes into a specified object
		 * arg 1) the object to copy into
		 * arg 2) the byte to copy
		 * arg 3) how many bytes in the object to copy into
		 *
		 * We are using struct game_system because that is the object that will
		 * be stored in the pointer.
		 *
		 * This is called zeroing out the memory. I believe this means:
		 * int = 0
		 * ptr = NULL
		 * char = '\0'
		 *
		 * Not sure if this is even necessary at this point? Every time I
		 * inspected these variables there were already zeroed.
		 */
		memset(gameSystemPtr, '\0', sizeof(struct game_system));
		return gameSystemPtr;
	}
}

/*
 * I tried putting this in io.h / io.c but I was getting an error that I didn't
 * know how to resolve.
 *
 * I think this relates to the forward declaration mentioned in main.h for
 * the struct game_system but I am not entirely sure.
 */
void printDebugGameSystem(struct game_system* gameSystemPtr)
{
	int i;

	for (i = 0; i < 4; i++) {
		printDebug("gameSystemPtr->the_menus.main_menu[%d].text is '%s'\n",
				   i,
				   gameSystemPtr->the_menus.main_menu[i].text);
		printDebug("gameSystemPtr->the_menus.main_menu[%d].function is %d\n",
				   i,
				   gameSystemPtr->the_menus.main_menu[i].function);
	}

	for (i = 0; i < 6; i++) {
		printDebug("gameSystemPtr->the_menus.scores_menu[%d].text is '%s'\n",
				   i,
				   gameSystemPtr->the_menus.scores_menu[i].text);
		printDebug(
				"gameSystemPtr->the_menus.scores_menu[%d].function is %d\n",
				i,
				gameSystemPtr->the_menus.scores_menu[i].function);
	}

	printDebug("gameSystemPtr->scoreboard.head is '%s'\n",
			   gameSystemPtr->scoreboard.head);
	printDebug("gameSystemPtr->scoreboard.size is %d\n",
			   gameSystemPtr->scoreboard.size);

	printDebug("gameSystemPtr->datafile is '%s'\n",
			   gameSystemPtr->datafile);

	printDebug("gameSystemPtr->scoreboard.thelong is %ld\n",
			   gameSystemPtr->gameseed.thelong);
	printDebug("gameSystemPtr->scoreboard.success is '%s'\n",
			   gameSystemPtr->gameseed.success);
}

/*
 * Clean up when ending the game.
 *
 * Took me a while to figure this out but eventually https://stackoverflow.com/a/17267808
 * lead me to the correct implementation.
 *
 *
 */
void deleteGameSystem(struct game_system* gameSystemPtr)
{
	/*
	 * Need to cast to non-const pointer to silence the compiler warning -
	 * https://stackoverflow.com/a/2819594
	 */
	free((char*) gameSystemPtr->datafile);
	free(gameSystemPtr);
}