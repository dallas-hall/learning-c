#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * This array stores pointers to char arrays (ie strings)
	 */ 
	char* titles[] = {
		"Title 1",
		"Title 2",
		"Title 3",
		"Title 4"
	};
	/*
	 * The arrays store pointer to pointers
	 */ 
	char** bestBooks[2];
	char** englishBooks[3];
	int i;

	puts("# Pointer To Pointer");

	/*
	 * Assign the pointer to a char[] pointer
	 */ 
	bestBooks[0] = &titles[1];
	bestBooks[1] = &titles[3];

	englishBooks[0] = &titles[0];
	englishBooks[1] = &titles[1];
	englishBooks[2] = &titles[2];

	for(i = 0; i < 4; i++) {
		printf("Title %d is '%s'\n", (i + 1), titles[i]);
	}

	for(i = 0; i < 2; i++) {
		/*
		 * We need to dereference the point here to get the title from the pointer.
		 */ 
		printf("Best book title %d is '%s'\n", (i + 1), *bestBooks[i]);
	}

	for(i = 0; i < 3; i++) {
		printf("English book title %d is '%s'\n", (i + 1), *englishBooks[i]);
	}


	return EXIT_SUCCESS;
}
