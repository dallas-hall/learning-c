#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8


int* allocateArray(int size);

int main(void)
{
	int* array;

	puts("# Creating & Returning Objects - Internal Object Creation");
	puts("When creating an object internally within a function with malloc, the caller becomes responsible for using free on the object.");

	array = allocateArray(ARRAY_SIZE);

	for(int i = 0; i < ARRAY_SIZE; i++) {
		printf("i is %d and has the value %d\n", i, array[i]);
	}

	free(array);

	return EXIT_SUCCESS;
}


int* allocateArray(int size)
{
	/*
	 * Use malloc to create the array.
	 * This means the caller is responsible for using free on this object.
	 *
	 * sizeof returns an unsigned long.
	 */ 
	int* array = (int*) malloc(sizeof(int) * (unsigned long) size);

	for(int i = 0; i < size; i++) {
		array[i] = i * i;
	}

	return array;
}
