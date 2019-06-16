#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

/*
 * int * const array is the same as int array[]
 * These are constant pointers with non-constant data
 */ 
void bubbleSortAsc(int * const array, const int size);
void bubbleSortDesc(int array[], const int size);
void swap(int *element1Pointer, int *element2Pointer);
void printIntArray(const int *intPointer, const int size);

int main(void)
{
	int a[SIZE];
	int i;
	/*
	 * Seed rand() with seconds since Unix Epoch
	 */ 
	srand(time(NULL));

	printf("# Bubble Sorting Via Element Pass By Reference Simulation\n## Creating array.\n");
	for(i = 0; i < SIZE; i++) {
		/*
		 * Number between 0 and 9 (% 10)
		 * Make it between and at 10 (+ 1)
		 */
		a[i] = 1 + rand() % 10;
	}
	printf("Done.\n");
	/*
	 * The variable name of the array has a pointer with the memory address of the first element of the array.
	 * Same as &a and &a[0]
	 */ 
	printIntArray(a, SIZE);
	bubbleSortAsc(a, SIZE);
	printIntArray(a, SIZE);
	bubbleSortDesc(a, SIZE);
	printIntArray(a, SIZE);

	return EXIT_SUCCESS;
}

void bubbleSortAsc(int * const array, const int size)
{
	int i, j;

	/*
	 * Bubble sort goes through the array multiple times.
	 * Currently the same amount as there are items.
	 */ 
	printf("\n## Bubble Sorting Array Ascending\n");
	for(i = 0; i < size; i++) {
		/*
		 * Skip the current element at i.
		 */ 
		for(j = i + 1; j < size; j++) {
			/*
			 * Compare the values of array[i] and array[j]
			 * The & gets the memory address (pointer) of the array elements.
			 * Call swap() with these pointers when necessary.
			 */ 
			if(array[j] < array[i]) {
				swap(&array[j], &array[i]);
			}
		}
	}
	printf("Done.\n");
}

void bubbleSortDesc(int array[], const int size)
{
	int i, j;

	/*
	 * Bubble sort goes through the array multiple times.
	 * Currently the same amount as there are items.
	 */ 
	printf("\n## Bubble Sorting Array Descending\n");
	for(i = 0; i < size; i++) {
		/*
		 * Skip the current element at i.
		 */ 
		for(j = i + 1; j < size; j++) {
			/*
			 * Compare the values of array[i] and array[j]
			 * The & gets the memory address (pointer) of the array elements.
			 * Call swap() with these pointers when necessary.
			 */ 
			if(array[j] > array[i]) {
				swap(&array[j], &array[i]);
			}
		}
	}
	printf("Done.\n");
}

/*
 * This function uses simluated call by reference to swap 2 array elements.
 * The memory addresses of the 2 elements to be swapped are passed in as pointers.
 * These pointers are used to swap the elements, with the help of a temporary variable.
 */ 
void swap(int *element1Pointer, int *element2Pointer)
{
	int tmp = *element1Pointer;
	*element1Pointer = *element2Pointer;
	*element2Pointer = tmp;
}

void printIntArray(const int *intPointer, const int size)
{
	int i;

	printf("\n## Printing Integer Array\n");
	/*
	 * The counter variable is for printing control only.
	 * We are using pointer arithmetic for iterate.
	 * We are iterating from the first element of the array at the pointer.
	 * Iterating until the null control character is found, which is the end of the string.
	 * We are using point arithmetic to access each element. This is the same as i++
	 * Notice there is not * for the pointer arithmetic. This updates the pointers subscript (aka index)
	 * But there is a * when we are accessing the value inside current element being pointed at.
	 */
	for(i = 0; i <  size; i++) {
		if (i == 0) {
			printf("[%d, ", *intPointer);
		}
		else if (i == size - 1) {
			printf("%d]\n", *intPointer);
		}
		else {
			printf("%d, ", *intPointer);
		}
		++intPointer;
	}
}
