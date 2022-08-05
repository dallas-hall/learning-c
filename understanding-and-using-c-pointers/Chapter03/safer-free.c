#include <stdio.h>
#include <stdlib.h>

/*
 * This macro calls the saferFree function and does the cast for us automatically.
 */ 
#define safeFree(p) saferFree((void**)&(p))

void saferFree(void** ptrPtr);

int main(void)
{
	/*
	 * Declare an integer pointer
	 */ 
	int* iPtr;

	puts("# Creating A Safer Free");
	puts("free doesn't check if the pointer is NULL and doesn't return NULL. We create our own free to do that.");

	/*
	 * Allocate some memory to our integer pointer
	 */ 
	iPtr = malloc(sizeof(int));

	if(!iPtr) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	*iPtr = 2;

	puts("## Before safeFree Macro");
	printf("iPtr value is %d\n", *iPtr);
	printf("iPtr address is %p\n", (void*) &iPtr);
	printf("iPtr points to %p\n", (void*) iPtr);

	puts("\n## After safeFree Macro");
	safeFree(iPtr);
	//printf("iPtr value is %d\n", *iPtr);
	printf("iPtr address is %p\n", (void*) &iPtr);
	printf("iPtr points to %p\n", (void*) iPtr);

	puts("\n## After safeFree Macro\nThis should be a use after free error, but safeFree handles it.");
	safeFree(iPtr);
	//printf("iPtr value is %d\n", *iPtr);
	printf("iPtr address is %p\n", (void*) &iPtr);
	printf("iPtr points to %p\n", (void*) iPtr);

	return EXIT_SUCCESS;
}


/*
 * Using a pointer to a pointer allows us to modiy the pointer that was passed.
 * Using void means we can use all types of pointers with this function.
 * But there will be a compiler warning without an explicit cast.
 * We can get around this by the macro above.
 */ 
void saferFree(void** ptrPtr)
{
	/*
	 * Check that the pointer to a pointer to void isn't NULL.
	 * Check that the pointer to void isn't NULL
	 */
	if(ptrPtr != NULL && *ptrPtr != NULL) {
		/*
		 * Derefernce the pointer to void and free it.
		 * Then set it to NULL
		 */ 
		free(*ptrPtr);
		*ptrPtr = NULL;
	}
}
