/*
Create 2 arrays that can hold 20 numbers, fill them with random numbers, sort them in ascending order, and compare each value.

* Create 2 arrays that can hold 20 integers
  * Create a function to create an array of int to the specified size
* Initialise each array with random numbers
  * Create a function that can return a random number when called
* Sort each array by ascending order
  * Create a function that can take an array pointer and sort the array.
* Compare each array indices.
  * Create a function that can take 2 array pointers, and compare then from start index to ending index.

 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define DEBUGGING 1

int debugging = 1;

void populateIntArray(int array[], int size, int seed);
int getRandomNumber(void);
void printIntArray(const int *intPointer, const int size);
void bubbleSortAsc(int * const array, const int size);
void bubbleSortDesc(int array[], const int size);
void swap(int *element1Pointer, int *element2Pointer);
void compareArrays(int a[], int b[], int c[], int size);
int getDifference(int a, int b);
void printArrayDifferences(int a[],int size);

int main(void)
{
  int a[SIZE] = {0};
  int b[SIZE] = {0};
  int c[SIZE] = {0};

  puts("# Create, populate with prn, sort, and compare int arrays.");
  populateIntArray(a, SIZE, 128);
  populateIntArray(b, SIZE, 256);

  if(DEBUGGING) {
    printIntArray(a, SIZE);
    printIntArray(b, SIZE);
  }

  bubbleSortAsc(a, SIZE);
  bubbleSortAsc(b, SIZE);

  if(DEBUGGING) {
    printIntArray(a, SIZE);
    printIntArray(b, SIZE);
  }

  compareArrays(a, b, c, SIZE);

  if(DEBUGGING) {
    printIntArray(c, SIZE);
  }

  printArrayDifferences(c, SIZE);

  return EXIT_SUCCESS;
}

void populateIntArray(int array[], int size, int seed)
{
  int i;

  srand(seed);
  for(i = 0; i < size; i++) {
    array[i] = getRandomNumber();
  }
}

int getRandomNumber()
{
  /* Between 0 and 99 */
  return rand() % 100;
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

void compareArrays(int a[], int b[], int c[], int size) {
  int i;

  for (i = 0; i < size; i++) {
    c[i] = getDifference(a[i], b[i]);
  }
}

int getDifference(int a, int b)
{
  if(a > b) {
    return a - b;
  }
  else if (b > a) {
    return b - a;
  }
  else if (a == b) {
    return 0;
  }
  return a;
}

void printArrayDifferences(int a[],int size) {
 int i;
 for(i = 0; i < size; i++) {
   printf("The differnce for index %d was %d\n", i, a[i]);
 }
}
