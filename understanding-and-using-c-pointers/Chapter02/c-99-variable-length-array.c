#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 8

int main(void)
{
	/*
	 * The c99 VLA means we can use a variable to initialise the array size.
	 * The size is still fixed. The allocation is done at runtime and the memory is inside the stackframe.
	 * The sizeof operator on this array will run at runtime too.
	 * Running these at runtime is slightly slower.
	 */ 
	char buffer[ARRAY_SIZE];

	puts("# C99 Variable Length Array");
	strcpy(buffer, "ABC123");

	for(int i = 0; i < ARRAY_SIZE; i++) {
		putchar(buffer[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}
