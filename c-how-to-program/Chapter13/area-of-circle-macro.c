#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159
/*
 * This is a macro that accepts one argument.
 * It will then compute the expression inside the brackets with the argument.
 * Each value in the expression needs to be enclosed in brackets to ensure its evaluated properly.
 *
 * pi * r ^ 2
 */ 
#define CIRCLE_AREA(n) ((PI) * (n) * (n))

int main(void)
{
	double d, area;
	puts("# Macro With Arguments - Area Of A Circle");
	puts("Enter the radius of the circle:");
	scanf("%lf", &d);

	area = CIRCLE_AREA(d);
	printf("The area of a circle with the radius %f is %f\n", d, area);

	return EXIT_SUCCESS;
}
