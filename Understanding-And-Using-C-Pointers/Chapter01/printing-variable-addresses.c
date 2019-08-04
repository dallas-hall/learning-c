#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 2;
	int* iPtr = &i;

	puts("# Printing Memory Addresses");
	puts("## Using %d and &");
	/*
	 * Not supported in C90.
	 * %ls is needed but C90 doesn't support this either.
	 */
	printf("Value of i is %d and the address of i is %d\n", i, &i); 
	/*
	 * We are not dereferencing here so we can see the address value of the pointer
	 * The value of iPtr will match the address of i.
	 */ 
	printf("Value of iPtr is %d and the address of iPtr is %d\n", iPtr, &iPtr); 

	puts("## Using %p and &");
	/*
	 * Need to cast to a void pointer to silence compiler warning
	 * The value of iPtr will match the address of i.
	 */ 
	printf("Value of i is %d and the address of i is %p\n", i, (void *) &i); 
	printf("Value of iPtr is %p and the address of iPtr is %p\n", iPtr, (void *) &iPtr); 

	puts("## Using %x and &");
	/*
	 * The value of iPtr will match the address of i.
	 */ 
	printf("Value of i is %d and the address of i is %x\n", i, &i); 
	printf("Value of iPtr is %x and the address of iPtr is %x\n", iPtr, &iPtr); 

	puts("## Using %o and &");
	/*
	 * The value of iPtr will match the address of i.
	 */ 
	printf("Value of i is %d and the address of i is %o\n", i, &i); 
	printf("Value of iPtr is %o and the address of iPtr is %o\n", iPtr, &iPtr); 


	return EXIT_SUCCESS;
}
