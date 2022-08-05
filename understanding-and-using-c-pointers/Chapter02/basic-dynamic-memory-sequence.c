#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* iPtr;
	
	puts("# Basic Dynamic Memory Management");
	puts("## Allocating Memory\nUsing malloc and sizeof to allocate memory for a pointer.");

	/*
	 * malloc returns null if it can't allocate memory. Otherwise returns a void* to the memory. You can cast this if you like for clarity.
	 * sizeof will return the platform dependent size of the type given.
	 */  
	iPtr = malloc(sizeof(int));
	if(!iPtr) {
		perror("malloc");
	}
	/*
	 * Assign a value to the pointer
	 */ 
	*iPtr = 2;

	/*
	 * dereference to get the value
	 */
	printf("The value of iPtr is %d\n", *iPtr);
	printf("The address of iPtr is %p\n", (void*) &iPtr);
	printf("The address iPtr points to %p\n", (void*) iPtr);

	puts("## Deallocating Memory\nUsing free to give the memory back to the system.");
	/*
	 * Delete the memory since we no longer need it
	 */
	free(iPtr);

	return EXIT_SUCCESS;
}
