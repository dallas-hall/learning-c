#include <stdio.h>
#include <stdlib.h>

int squareInt(int n);
double squareDouble(double n);

int main(void)
{
	/*
	 * Can use a type definition for common function pointer definitions.
	 * This is a typedfe named intFuncPtr that
	 * a) takes a function pointer a function that takes an int and returns an int.
	 */ 
	typedef int (*intFuncPtr)(int);

	/*
	 * Declare the function pointers
	 * fptr is a function pointer that takes an int and returns an int.
	 * We must provide a function's name that matches this signature. The functions name is a pointer itself.
	 */
	intFuncPtr fptr1;
	double (*fptr2)(double);

	int i = 2;
	double d = 3.14;

	puts("# Functoin Pointers");

	printf("The value is i is %d\n", i);
	/*
	 * Assign the address of the function to the function pointer
	 */ 
	fptr1 = squareInt;
	/*
	 * Call the function via the function pointer.
	 */ 
	i = fptr1(i);
	printf("After squareInt, the value is i is %d\n", i);
	
	printf("The value is d is %f\n", d);
	fptr2 = squareDouble;
	d = fptr2(d);
	printf("After squareInt, the value is i is %f\n", d);

	return EXIT_SUCCESS;
}

int squareInt(int n)
{
	return n * n;
}

double squareDouble(double n)
{
	return n * n;
}
