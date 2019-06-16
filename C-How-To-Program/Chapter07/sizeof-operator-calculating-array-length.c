#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

int main(void)
{
	/*
	 * Pointer is 8 bytes.
	 * Each element takes up 8 bytes.
	 * 10 * 8 = 80 bytes total element size.
	 */ 
	double array[SIZE];

	printf("# sizeof Operator Returns Byte Size Of Object\n");
	printf("The number of bytes the array uses is %ld\n", sizeof(array));
	printf("The number of bytes the array's pointer uses is %ld\n", sizeof(&array));
	printf("The total number of elements in the array is calculated using sizeof(array) / sizeof(array[0]) - this is %ld\n", sizeof(array) / sizeof(&array));
	return EXIT_SUCCESS;
}
