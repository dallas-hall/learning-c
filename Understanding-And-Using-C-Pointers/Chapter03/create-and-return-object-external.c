#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

int* allocateArray(int*, int);

int main(void)
{
	int* array;

	puts("# Creating & Returning Objects - External Object Creation");
	puts("When creating an object externally outsidea function with malloc, the caller is still responsible for using free on the object.");

	array = (int*) malloc(sizeof(int) * (unsigned long) ARRAY_SIZE);

	if(!array) {
		return EXIT_FAILURE;
	}
	
	allocateArray(array, ARRAY_SIZE);

	for(int i = 0; i < ARRAY_SIZE; i++) {
		printf("i is %d and has the value %d\n", i, array[i]);
	}

	free(array);

	return EXIT_SUCCESS;
}

int* allocateArray(int* array, int size)
{
	for(int i = 0; i < size; i++) {
		array[i] = i * i;
	}

	return array;
}
