#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

int* allocateArray(int**, int);

int main(void)
{
	int* array;

	puts("# Creating & Returning Objects - Internal Object Creation & Pointer To A Pointer");
	puts("When creating an object inside a function with malloc, the caller is responsible for using free on the object.");
	puts("When passing a pointer to a pointer to aType, we need to pass in the address of the pointer to aType, and dereference the pointer to a pointer to aType inside the function to manipulate the pointer to aType");

	array = allocateArray(&array, ARRAY_SIZE);
	if(!array) {
		return EXIT_FAILURE;
	}
	
	/*
	 * We must use the address of the pointer to a pointer to aType.
	 * This is so it matches the aType** parameter type.
	 */ 

	for(int i = 0; i < ARRAY_SIZE; i++) {
		printf("i is %d and has the value %d\n", i, array[i]);
	}

	free(array);

	return EXIT_SUCCESS;
}

int* allocateArray(int** array, int size)
{
	/*
	 * Need to dereference from a pointer to a pointer to an int to just a pointer to an int
	 */ 
	*array = (int*) malloc(sizeof(int) * (unsigned long) ARRAY_SIZE);
	if(!array) {
		return NULL;
	}

	for(int i = 0; i < size; i++) {
		/*
		 * When updating a pointer to a pointer to aType, we must dereference it.
		 * This is so we are updating the pointer to Atype.
		 *
		 * Since we are working with a pointer to a pointer to int.
		 * To get the address of the pointer to an int, we must deference.
		 *
		 * (*array)
		 *
		 * To get the value from that pointer to an int, we must dereference again.
		 * *(*array)
		 *
		 * To iterate through all of the address inside array, we add i each time we go through the loop.
		 */ 
		*(*array + i) = i * i;
	}

	/*
	 * We must dereference again to return a pointer to Atype
	 */ 
	return *array;
}
