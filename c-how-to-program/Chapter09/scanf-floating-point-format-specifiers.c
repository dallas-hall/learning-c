#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float a, b, c;
	
	puts("# scanf Floating Point Format Specifiers");
	puts("Enter 3 decimals: ");
	/*
	 * e, E, f, F, g, G can read any float, but with imprecision.
	 * %lf for long floats (doubles)
	 */ 
	scanf("%f%e%g", &a, &b, &c);
	printf("In base 10 you entered: %f %e %g\n", a, b, c);

	return EXIT_SUCCESS;
}
