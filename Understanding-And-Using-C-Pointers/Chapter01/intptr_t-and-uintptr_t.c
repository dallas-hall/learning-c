#include <stdio.h>
#include <stdlib.h>
/*
 * Needed for intptr_t and uintptr_t
 */
#include <stdint.h>

int main(void)
{
	int i = 2;
	/*
	 * Both require C99
	 * Need a case here to get the correct number
	 */ 
	intptr_t* iPtr = (intptr_t*) &i;
	/*
	 * Without a cast this is illegal.
	 * Remember about the high-order bit and negative numbers.
	 * In integers it is a negative sign but in unsigned numbers it is a large power of 2.
	 */ 
	uintptr_t* uiPtr = (uintptr_t*) &i;

	puts("# Portable Pointer Types");
	puts("## intptr_t");
	printf("The value of i is %d\n", i);
	/*
	 * Need to cast to (void*) for %p to silence compiler warning. 
	 */
	printf("The address of i is %p\n", (void*) &i);
	/*
	 * The compiler suggests using %ld here but the number is interpretted wrong.
	 * A manual (int) works, gets the correct number and silences compiler warning.
	 */ 
	printf("After intptr_t* iPtr = &i; the value of iPtr is %d\n", (int) *iPtr);
	printf("After intptr_t* iPtr = &i; the address of iPtr is %p\n", (void*) &iPtr);

	puts("## uintptr_t");
	printf("After uintptr_t* iPtr = (uintptr_t*) &i; the value of iPtr is %d\n", (int) *uiPtr);
	printf("After uintptr_t* iPtr = (uintptr_t*) &i; the address of iPtr is %p\n", (void*) &uiPtr);

	return EXIT_SUCCESS;
}
