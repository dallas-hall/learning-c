#include <stdio.h>
#include <stdlib.h>

/*
 * A typedef for a function pointer:
 * a) called intFptr
 * b) takes 2 ints
 * c) returns an int
 */ 
typedef int (*intFptr)(int, int);

int add(int, int);
int subtract(int, int);
int compute(char, int, int);
/*
 * Returns a function pointer based on the input char
 */ 
intFptr evaluate(char);

int main(void)
{
	int a = 8;
	int b = 4;
	int result = 0;

	puts("# Passing Function Pointers");
	printf("The value is a is %d\n", a);
	printf("The value is b is %d\n", b);

	puts("\n## Passing add(a, b)");
	result = compute('+', a, b);
	printf("The value is result is %d\n", result);

	puts("\n## Passing subtract(a, b)");
	result = compute('-', a, b);
	printf("The value is result is %d\n", result);

	return EXIT_SUCCESS;
}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int compute(char c, int a, int b)
{
	/*
	 * Get the function's address.
	 */ 
	intFptr fptr = evaluate(c);
	/*
	 * Execute the function.
	 */ 
	return fptr(a, b);
}

intFptr evaluate(char c)
{
	/*
	 * return the address of a function via its name
	 */ 
	switch(c) {
		case '+': return add;
		case '-': return subtract;
		default: return NULL;
	}
}
