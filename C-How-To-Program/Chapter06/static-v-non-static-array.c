#include <stdlib.h>
#include <stdio.h>

#define SIZE 3

void staticArrayInit(void);
void automaticArrayInit(void);

int main(void)
{
	printf("# Static v Automatic Arrays\n");
	printf("## Static Array - first function call\n");
	staticArrayInit();
	printf("## Auto Array - first function call\n");
	automaticArrayInit();

	printf("## Static Array - second function call\n");
	staticArrayInit();
	printf("## Auto Array - second function call\n");
	automaticArrayInit();
	
	return EXIT_SUCCESS;
}

/*
 * The static array is initialised once, at compile time.
 * Its life is the life of the program.
 * Every time this function is called, the static array from compile time is used.
 * That means that updates survive between calls to this function.
 */ 
void staticArrayInit(void)
{
	/* All values are initially set to 0 in a static array when they are explicitly declared */
	static int staticArray[SIZE];
	int i;

	printf("### Static Array Printing\n");
	for(i = 0; i < SIZE; i++) {
		printf("Before updating, element %d is %d\n", i, staticArray[i]);
		/* Increment the array element */
		++staticArray[i];
		printf("After updating, element %d is %d\n", i, staticArray[i]);
	}
	printf("\n");
}

/*
 * This array is initialised every time the function is called.
 * The life is the life of the function.
 * Every time this function is called, a new array is created.
 * That means that updates don't survive between funciton calls.
 */
void automaticArrayInit(void)
{
	/* All remaining values are set to 0 when not all values have been explicitly declared */
	int autoArray[SIZE] = { 0 };
	int i;

	printf("### Auto Array Printing\n");
	for(i = 0; i < SIZE; i++) {
		printf("Before updating, element %d is %d\n", i, autoArray[i]);
		/* Increment the array element */
		++autoArray[i];
		printf("After updating, element %d is %d\n", i, autoArray[i]);
	}
	printf("\n");
}
