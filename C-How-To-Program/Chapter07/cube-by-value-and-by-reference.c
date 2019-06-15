#include <stdio.h>
#include <stdlib.h>

int cubeByValue(int n);
void cubeByReference(int *nPointer);

int main(void)
{
	int input, result;

	printf("# Cube Number - Pass By Value\nEnter an integer: ");
	scanf("%d", &input);
	printf("The original number (input) is %d\n", input);
	result = cubeByValue(input);
	printf("The original number (input) after cubeByValue is %d\n", input);
	printf("The new number (result) after cubeByValue is %d\n", result);

	printf("\n# Cube Number - Simulate Pass By Reference\nEnter an integer: ");
	scanf("%d", &input);
	printf("The original number (input) is %d\n", input);
	/*
	 * The & is needed here to pass the memory address of the variable.
	 * This simulates call by reference.
	 */ 
	cubeByReference(&input);
	printf("The original number (input) after cubeByReference is %d\n", input);


	return EXIT_SUCCESS;
}

/*
 * We need a return because we are manipulating the value.
 */ 
int cubeByValue(int n)
{
	return n * n * n;
}

/*
 * We don't need a return because we are directly manipulating the value.
 */ 
void cubeByReference(int *nPointer)
{
	*nPointer = *nPointer * *nPointer * *nPointer;
}
