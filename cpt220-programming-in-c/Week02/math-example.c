#include  <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Need to include the linker option -lm at compile time for this to run.
 * gcc -Wall -pedantic -ansi -lm math-example.c -o math-example.out
 * 
 */
int main(void)
{
	float f;

	printf("Enter a float: ");
	if (scanf("%f", &f) == 1)
	{
		printf("f = %f\nsin(f) = %f\ncos(f) = %f\ntan(f) = %f\n", f, sin(f), cos(f), tan(f));
	}
	else {
		printf("Couldn't find a valid float. Exiting.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
