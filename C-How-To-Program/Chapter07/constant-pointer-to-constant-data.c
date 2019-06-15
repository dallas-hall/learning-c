#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 2;
	int b;
	/*
	 * Define a constant integer, so the data can never change.
	 * Define a constant pointer, so the pointer can only point to one memory address.
	 * Trying to change either is a compile time error.
	 */ 
	const int *const intPointer = &a;

	printf("# Constant Pointer To Constant Data\n## Display Address & Value");
	/*
	 * Need to cast to a void pointer as that is what %p expects.
	 * Direclty updating the variable is okay because it isn't defined as constant.
	 */ 
	printf("The value at address %p is %d\n", (void *) intPointer, a);
	a++;
	printf("The value at address %p after variable++ is %d\n", (void *) intPointer, a);
	
	printf("## Attempting To Update Constant Pointer & Constant Variable - compile time error\n");
	/*
	 * Assign a value to a new variable
	 * Attempt to update the constant pointer's constant data to the new variable's address.
	 * This is a compile time error.
	 */ 
	b = 2 * 2;
	intPointer = &b;
	/*
	 * Attempt to update the constant pointer's value directly.
	 * This is a compile time error.
	 */ 

	*intPointer = 4;

	return EXIT_SUCCESS;
}
