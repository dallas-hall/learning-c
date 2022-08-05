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
	printf("Value of i is %d\n", i); 
	printf("The address of i is %d\n", (int*) &i); 
	/*
	 * We are not dereferencing here so we can see the address value of the pointer (ie what it points to)
	 * The value of iPtr will match the address of i.
	 */ 
	printf("Value of iPtr is %d\n", *iPtr); 
	printf("The address iPtr is pointing to is %d\n", (int*) iPtr); 
	printf("The address iPtr is located at is %d\n", (int*) &iPtr); 

	puts("\n## Using %p and &");
	/*
	 * Need to cast to a void pointer to silence compiler warning
	 * The value of iPtr will match the address of i.
	 */ 
	printf("Value of i is %d\n", i);
	printf("The address of i is %p\n", (void*) &i);
	
	printf("Value of iPtr is %d\n", *iPtr); 
	printf("The address iPtr is pointing to is %p\n", (void*) iPtr); 
	printf("The address iPtr is located at is %p\n", (void*) &iPtr); 

	puts("\n## Using %x and &");
	/*
	 * Lots of compiler warnings about implicit casts 
	 */ 
	printf("Value of iPtr is %d\n", *iPtr); 
	printf("The address iPtr is pointing to is %x\n", iPtr); 
	printf("The address iPtr is located at is %x\n", &iPtr); 

	puts("\n## Using %o and &");
	printf("Value of i is %d\n", i);
	printf("The address of i is %o\n", &i);
	
	printf("Value of iPtr is %d\n", *iPtr); 
	printf("The address iPtr is pointing to is %o\n", iPtr); 
	printf("The address iPtr is located at is %o\n", &iPtr); 


	return EXIT_SUCCESS;
}
