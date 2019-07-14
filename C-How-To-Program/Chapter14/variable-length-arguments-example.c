#include <stdio.h>
#include <stdlib.h>
/*
 * Has macros and defintions that allow variable lengthed arguments to be passed.
 * va_list - The type suitable for holding information needed by macros va_start, va_arg, and va_end.
 * va_start - A macro that is invoked before the variable legnth arguments list can be accessed.
 * va_arg - A macro that expands into an expression of the value and type of argument within the variable argument list.
 *          Each time you use this it iterates through the variable argument list.
 * va_end - A macro that allows the normal return from a function that has variable length arguments.
 */ 
#include <stdarg.h>

/*
 * The function prototype for a function that accepts 1 to m amount of int arguments.
 * The parameter i is how many arguments were passed.
 * The parameter ... means an arbitrary number of arguments can be passed.
 */ 
double average(int i, ...);

int main(void)
{
	double w = 37.5;
	double x = 22.5;
	double y = 1.7;
	double z = 10.2;

	puts("# Variable Length Arguments");
	puts("## Variable Values");
	printf("w = %f\n", w);
	printf("x = %f\n", x);
	printf("y = %f\n", y);
	printf("z = %f\n", z);

	puts("## Variable Length Function Calls");
	printf("The average of w and x is %.3f\n", average(2, w, x));
	printf("The average of w, x and y is %.3f\n", average(3, w, x, y));
	printf("The average of w, x, y and z is %.3f\n", average(4, w, x, y, z));

	return EXIT_SUCCESS;
}


double average(int i, ...)
{
	double total = 0;
	int j;

	/*
	 * Stores information needed by va_start and va_end
	 */ 
	va_list varArgList;

	/*
	 * Uses i to determine where the variable length argument list begins.
	 */ 
	va_start(varArgList, i);

	for(j = 0; j < i; j++) {
		/*
		 * Process each item in the variable length argument list.
		 * va_arg iterates the list for you.
		 */ 
		total += va_arg(varArgList, double);
	}

	/*
	 * Clean up the variable length argument list.
	 */ 
	va_end(varArgList);
	return total / i;
}
