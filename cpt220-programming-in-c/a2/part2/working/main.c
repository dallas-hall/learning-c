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
	struct linkedlist* linkedListPtr = NULL;

	/*
	 * Create and initialise the game system. Doing this here so it is alive
	 * for the duration of the running program.
	 */
	gameSystemPtr = createGameSystemPtr();
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
	 * Create and initialise the linked list
	 */
	linkedListPtr = createLinkedList();

	/*
	 * Same as linkedListPtr == NULL, I tend to switch between both.
	 */
	if (!linkedListPtr) {
		error_print("Couldn't create the linked list.\n");
		return EXIT_FAILURE;
	}
	/*
	 * Assign the value of the linked list pointer through dereferencing to the
	 * game system and update the linked list pointer to the address of the
	 * game system linked list. May not need this, not sure yet.
	 *
	 * I think Paul mentioned not needing to do this in my previous assignment
	 * but I didn't really understand why.
	 */
	gameSystemPtr->scoreboard = *linkedListPtr;
	linkedListPtr = &gameSystemPtr->scoreboard;

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
	 * We need to take the address of the list
	 */
	prettyPrintLinkedList(&gameSystemPtr->scoreboard);
	printCsvLinkedList(&gameSystemPtr->scoreboard, DELIMITER);

	/* start the game, passing in the seed */
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

	/*
	 * if valid load_data and assign filename to thesystem->datafile
	 * else exit with error
	 *
	 * Blank input already covered by arg check, because there is a mandatory
	 * argument required which is the filename. If it is blank, it will fail
	 * that mandatory argument check.
	 */
	if (strlen(fname) > PATH_MAX) {
		error_print("Input file path is too long, must be <= 4096 characters.\n");
		return FALSE;
	}

	/*
	 * We need the memory address of the linked list with &, so we can directly
	 * update that memory within the init_system function.
	 *
	 * This is simulated pass by reference.
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
struct game_system* createGameSystemPtr()
{
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