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
 * Create an array filled with function pointers.
 * We are using 128 for ASCII chars.
 */ 
static intFptr fptrs[128] = {NULL};
/*
 * Same as above, but without a typedef
 */ 
// int (*fptrs[128](int, int) = {NULL};

int main(void)
{
	int a = 8;
	int b = 4;
	int result = 0;
	fptrs['+'] = add;
	fptrs['-'] = subtract;

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
	intFptr fptr = fptrs[(int) c];
	/*
	 * Execute the function.
	 */ 
	return fptr(a, b);
}
