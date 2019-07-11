#include <stdio.h>
#include <stdlib.h>

/*
 * argc stores how many arguments were passed.
 * *argv[] is an array of pointers for char arrays, which hold each supplied argument.
 */
int main(int argc, char *argv[])
{
	int i;

	puts("# Passing Command Lines Arguments To Main");
	puts("## First Argument - Program Name");
	printf("The first command line argument is always the program's name.\nargv[0] is %s\n", argv[0]);
	
	puts("\n## All Other Arguments");
	/*
	 * Start at 1 so we skip the program name.
	 */ 
	for(i = 1; i < argc; i++) {
		printf("argv[%d] is %s\n", i, argv[i]);
	}

	return EXIT_SUCCESS;
}
