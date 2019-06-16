#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

size_t getSizeOfPointer(float *pointer);

int main(void)
{
	float array[SIZE];

	printf("# sizeof Operator Returns Byte Size Of Object\n");
	printf("The number of bytes the array uses is %ld\n", sizeof(array));
	printf("The number of bytes the array's pointer uses is %ld\n", sizeof(&array));
	printf("The number of bytes returned by getSizeOfPointer is %ld\n", getSizeOfPointer(array));
	return EXIT_SUCCESS;
}

/*
 * Get the memory address of the object.
 */ 
size_t getSizeOfPointer(float *pointer)
{
	/*
	 * Return the size of the pointer in bytes.
	 */ 
	return sizeof(pointer);
}
