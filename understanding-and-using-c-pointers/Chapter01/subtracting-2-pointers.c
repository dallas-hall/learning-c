#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * On my machine, an int is 4 bytes.
	 */ 
	int vector[] = {28, 41, 7};
	/*
	 * This will be the memory address of the first index
	 */ 
	int* iPtr = vector;
	int* i2Ptr = &vector[1];
	int* i3Ptr = &vector[2];

	puts("# Pointer Arithmetic - Using An Array Of Integers");
	/*
	 * Remember that the name of an array is the same as &name[0]
	 * %p needs a (void*) cast
	 */ 
	printf("The address of vector[0] is %p\n", (void*) vector);
	printf("The address of vector[1] is %p\n", (void*) &vector[1]);
	printf("The address of vector[2] is %p\n", (void*) &vector[2]);
	/*
	 * iPtr is the address that the pointer is pointing to.
	 * &iPtr is the address that the pointer is located at.
	 */ 
	printf("The address that iPtr is holding is %p\n", (void*) iPtr);
	printf("The address where &iPtr lives is %p\n", (void*) &iPtr);
	printf("The address that i2Ptr is holding is %p\n", (void*) i2Ptr);
	printf("The address where &i2Ptr lives is %p\n", (void*) &i2Ptr);
	printf("The address that i3Ptr is holding is %p\n", (void*) i3Ptr);
	printf("The address where &3iPtr lives is %p\n", (void*) &i3Ptr);

	printf("The value of vector[0] is %d\n", vector[0]);
	printf("The value of vector[1] is %d\n", vector[1]);
	printf("The value of vector[1] is %d\n", vector[2]);
	/*
	 * Need to dereference to see the value of the pointer
	 */
	printf("The value of *iPtr is %d\n", *iPtr);
	printf("The value of *i2Ptr is %d\n", *i2Ptr);
	printf("The value of *i3Ptr is %d\n", *i3Ptr);

	/*
	 * Pointer - pointer arithmetic.
	 *
	 * In arrays, when subtracting the addresses that pointers point to, this is
	 * essentially telling you the order of the 2 elements. The order is important,
	 * the higher element of the array should appear first. Otherwise you may go
	 * outside the bounds of the array.
	 *
	 *
	 * -n = You are probably outside the array bounds. Do not use this memory address.
	 * 0 = the same element
	 * n = This is how many elements apart they are.
	 *
	 * This works because when doing arithmetic on pointers, the pointer's data type
	 * size is added or subtracted against the memory address. So by comparing to like
	 * pointers in an array, we can work out based on the result of memory address
	 * arithmetic the ordering of array elemnts.
	 */ 
	puts("## Array Pointer - Array Pointer");
	puts("A negative number means appears before, 0 means the same element, and a positive number means appears after.");
	printf("How far apart is i3Ptr & i2Ptr? %ld\n", i3Ptr - i2Ptr);
	printf("How far apart is i3Ptr & iPtr? %ld\n", i3Ptr - iPtr);
	/*
	 * This puts us outside the array bounds
	 */ 
	printf("How far apart is iPtr & i2Ptr? %ld\n", iPtr - i2Ptr);

	return EXIT_SUCCESS;
}
