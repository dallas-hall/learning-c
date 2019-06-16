#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

/*
 * A constant integer pointer with a non-constant integer array.
 * A constant integer as a parameter.
 */ 
void printIntArray(const int *intPointer, const int size);
/*
 * A non-constant int [] as a parameter
 * A constant int as a parameter.
 *
 * (*compare)(parameters) tells the function to expect a function name pointer, and its parameters.
 * The parentheses indicate compare is a pointer. 
 * Can be written as type (*)(parameters) - ie no name
 */ 
void bubbleSort(int array[], const int size, int (*compare)(int a, int b));
/*
 * These function names are passed as pointers.
 *
 */ 
int ascending(int a, int b);
int descending(int a, int b);

int main(void)
{
	int a[SIZE];
	int i;

	printf("# Bubble Sorting With Functions As Pointers\n");

	srand(time(NULL));
	for(i = 0; i < SIZE; i++) {
		a[i] = 1 + (rand() % 10);
	}
	printIntArray(a, SIZE);

	/*
	 * Pass a pointer that points to a function name.
	 * This is the starting address in memory of the code in that function.
	 */ 
	bubbleSort(a, SIZE, ascending);
	printIntArray(a, SIZE);
	
	bubbleSort(a, SIZE, descending);
	printIntArray(a, SIZE);

	return EXIT_SUCCESS;
}

void bubbleSort(int array[], const int size, int (*compare)(int a, int b))
{
	int i, j;
	
	/*
	 * This means only bubbleSort can use this function.
	 */ 
	void swap(int *element1Pointer, int *element2Pointer);

	for(i = 0; i < SIZE; i++) {
		for(j = i + 1; j < SIZE; j++) {
			/*
			 * The function in the pointer is deferenced here.
			 * The * means to use the pointer with the function in it.
			 */ 
			if( (*compare)(array[i], array[j]) ) {
				swap( &array[i], &array[j] );
			}
		}
	}
	
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

int ascending(int a, int b)
{
	return b < a;
}

int descending(int a, int b)
{
	return b > a;
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

