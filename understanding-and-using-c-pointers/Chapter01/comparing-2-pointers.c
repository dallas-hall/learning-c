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
	 * Normally comparing to pointers is useless. But when doing it with
	 * pointers in the same array, it can be used to determine the ordering
	 * of the array elements.
	 *
	 * The outcome of the comparison operators will be 0 or n, false or true.
	 */
	puts("## Comparing Array Element Pointers To Determine Order");
	printf("Does iPtr element == iPtr element? %d\n", iPtr == iPtr);
	printf("Does iPtr element == i2Ptr element? %d\n", iPtr == i2Ptr);
	printf("Is iPtr element < i2Ptr element? %d\n", iPtr < i2Ptr);
	printf("Is iPtr element > i2Ptr element? %d\n", iPtr > i2Ptr);
	printf("Is i2Ptr element < iPtr element? %d\n", i2Ptr < iPtr);
	printf("Is i2Ptr element > iPtr element? %d\n", i2Ptr > iPtr);

	return EXIT_SUCCESS;
}
