#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * Integers
	 */ 
	char c;
	short s;
	int i;
	long l;
	/*
	 * Floating point numbers
	 */ 
	float f;
	double d;
	long double ld;
	/*
	 * Arrays & pointers
	 */ 
	int array[10];
	int *intArrayPointer = array;

	printf("# C Data Types Sizes With sizeof\n");
	printf("sizeof(aChar) is %ld bytes.\t\tsizeof(char) is %ld bytes.\n", sizeof(c), sizeof(char));
	printf("sizeof(aShort) is %ld bytes.\t\tsizeof(short) is %ld bytes.\n", sizeof(s), sizeof(short));
	printf("sizeof(anInt) is %ld bytes.\t\tsizeof(int) is %ld bytes.\n", sizeof(i), sizeof(int));
	printf("sizeof(aLong) is %ld bytes.\t\tsizeof(long) is %ld bytes.\n", sizeof(l), sizeof(long));
	printf("sizeof(aFloat) is %ld bytes.\t\tsizeof(float) is %ld bytes.\n", sizeof(f), sizeof(float));
	printf("sizeof(aDouble) is %ld bytes.\t\tsizeof(double) is %ld bytes.\n", sizeof(d), sizeof(double));
	printf("sizeof(aLongDouble) is %ld bytes.\tsizeof(long double) is %ld bytes.\n", sizeof(ld), sizeof(long double));
	printf("sizeof(anIntArray) with 10 elements is %ld bytes.\n", sizeof(array));
	printf("sizeof(anIntArrayPointer) is %ld bytes.\n", sizeof(intArrayPointer));

	return EXIT_SUCCESS;
}
