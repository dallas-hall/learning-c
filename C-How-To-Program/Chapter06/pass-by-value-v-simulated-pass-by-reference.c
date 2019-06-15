#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void printArray(int a[], int size);
void passPointer(int a[], int size);
void passValue(int e);

int main(void)
{
	int a[] = {0, 1, 2, 3, 4, 5};
	int i;

	printf("# Pass By Value - value copy v pointer\n");
	/*
	 * a passes the pointer (memory address locatoin) of the first element of the array.
	 * Same as &a
	 * Same as &a[0]
	 * Remember to pass the size of the array to the function.
	 */ 
	printArray(a, SIZE);

	for(i = 0; i < SIZE; i++) {
		passValue(a[i]);
	}
	printArray(a, SIZE);

	/* Need to cast here because of compiler warning. */
	passPointer((int *) &a, SIZE);
	printArray(&a[0], SIZE);

	return EXIT_SUCCESS;
}

void printArray(int a[], int size)
{
	int i;

	printf("\n## Printing Array Element Values\n");
	for (i = 0; i < SIZE; i++) {
		printf("Element %d is %d\n", i, a[i]);
	}
}

void passPointer(int a[], int size)
{
	int i;

	printf("\n## Modifying Array Element Values - e * 2\n");
	for (i = 0; i < SIZE; i++) {
		a[i] *= 2;
	}
	printf("Done.\n");
}

void passValue(int e)
{
	printf("\n## Updating Pass By Value - copy of value passed * 2\n");
	printf("Before update, the copy of element's value is %d\n", e);
	e *= 2;
	printf("After update, the copy of element's value is %d\n", e);
}
