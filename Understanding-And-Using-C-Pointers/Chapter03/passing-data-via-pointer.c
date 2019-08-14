#include <stdio.h>
#include <stdlib.h>

void intValueSwap(int* a, int* b);

int main(void)
{
	int i = 2;
	int j = 4;

	puts("# Passing Pointers As Function Parameters");
	puts("## Current State");
	printf("The value of i is %d\n", i);
	printf("The address of i is %p\n", (void*) &i);
	printf("The value of j is %d\n", j);
	printf("The address of j is %p\n", (void*) &j);

	/*
	 * Pass in the address of i and j.
	 * They will be assigned to pointers and be manipulated.
	 */ 
	intValueSwap(&i, &j);

	puts("\n## Current State");
	printf("The value of i is %d\n", i);
	printf("The address of i is %p\n", (void*) &i);
	printf("The value of j is %d\n", j);
	printf("The address of j is %p\n", (void*) &j);

	return EXIT_SUCCESS;
}


void intValueSwap(int* a, int* b)
{
	int c;

	/*
	 * Assign the value of a through dereferencing to c
	 */ 
	c = *a;
	/*
	 * Swap the values.
	 * The * on the left means update the pointer's value.
	 * The * on the right is dereferncing the pointer's value.
	 */ 
	*a = *b;
	*b = c;
}
