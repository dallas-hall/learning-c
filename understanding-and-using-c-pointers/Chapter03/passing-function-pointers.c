#include <stdio.h>
#include <stdlib.h>

/*
 * A typedef for a function pointer:
 * a) called intFptr
 * b) takes 2 ints
 * c) returns an in
 */ 
typedef int (*intFptr)(int, int);

int add(int a, int b);
int subtract(int a, int b);
int compute(intFptr fptr, int a, int b);

int main(void)
{
intFptr fptr1;
	intFptr fptr2;

	int a = 8;
	int b = 4;
	int result = 0;

	fptr1 = add;
	fptr2 = subtract;

	puts("# Passing Function Pointers");
	printf("The value is a is %d\n", a);
	printf("The value is b is %d\n", b);

	puts("\n## Passing add(a, b)");
	result = compute(fptr1, a, b);
	printf("The value is result is %d\n", result);

	puts("\n## Passing subtract(a, b)");
	result = compute(fptr2, a, b);
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

int compute(intFptr fptr, int a, int b)
{
	return fptr(a, b);
}
