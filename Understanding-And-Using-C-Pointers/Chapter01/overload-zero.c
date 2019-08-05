#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * 0 here means the number 0
	 */ 
	int i = 0;
	/*
	 * 0 here means NULL because it is a pointer.
	 * NULL and 0 are interchangable in this context.
	 */ 
	int* iPtr = 0;

	puts("# Overloaded 0");
	printf("After int i = 0; The value of i is %d\n", i);
	printf("After int* iPtr = 0; The value of iPtr with %%d is %d\n", iPtr);
	printf("After int* iPtr = 0; The value of iPtr with %%s is %s\n", iPtr);

	return EXIT_SUCCESS;
}
