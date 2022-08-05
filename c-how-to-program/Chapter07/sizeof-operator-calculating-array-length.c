#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

int main(void)
{
	/*
	 * Pointer to a double is 8 bytes.
	 * Each element takes up 8 bytes.
	 * There are 10 elements.
	 * 10 * 8 = 80 bytes total element size.
	 */ 
	double doubleArray[SIZE];
	/*
	 * Pointer to an int is 4 bytes.
	 * Each element takes up 4 bytes.
	 * There are 3 elements, in each array.
	 * 3 * 3 * 4 = 36 bytes total elements size;
	 *
	 */ 
	int int2dArray[3][3];

	printf("# sizeof Operator Returns Byte Size Of Object\n");
	printf("## Array Of double[10]\n");
	printf("The total number of bytes the doubleArray uses is %ld\n", sizeof(doubleArray));
	printf("The total number of bytes the doubleArray's pointer uses is %ld\n", sizeof(&doubleArray));
	printf("The total number of bytes that doubleArray uses is %ld\n", sizeof(doubleArray[0]));
	printf("The total number of elements in the doubleArray is calculated using sizeof(doubleArray) / sizeof(doubleArray[0]) - this is %ld\n", sizeof(doubleArray) / sizeof(doubleArray[0]));

	printf("## 2d Array Of int[3][3]\n");
	printf("The total number of bytes the int2dArray uses is %ld\n", sizeof(int2dArray));
	printf("The total number of bytes the int2dArray's pointer uses is %ld\n", sizeof(&int2dArray));
	printf("The total number of bytes that int2dArray[] uses is %ld\n", sizeof(int2dArray[0]));
	printf("The total number of bytes that int2dArray[][] uses is %ld\n", sizeof(int2dArray[0][0]));
	printf("The total number of elements in the int2dArray[] is calculated using sizeof(int2dArray) / sizeof(int2dArray[0]) - this is %ld\n", sizeof(int2dArray) / sizeof(int2dArray[0]));
	printf("The total number of elements in the int2dArray[][] is calculated using sizeof(int2dArray) / sizeof(int2dArray[0][0]) - this is %ld\n", sizeof(int2dArray) / sizeof(int2dArray[0][0]));


	return EXIT_SUCCESS;
}
