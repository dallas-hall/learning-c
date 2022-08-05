#include <stdio.h>
#include <stdlib.h>

/*
 * Global and static pointer.
 * These are initialised to NULL when the program starts.
 */ 

int* globalStaticPtr;

int main(void)
{
	puts("# Global & Static Pointers");
	/*
	 * ANSI C doesn't support %ls 
	 */ 
	printf("The value fo the global and static pointer globalStaticPtr is %s\n", globalStaticPtr);

	return EXIT_SUCCESS;
}
