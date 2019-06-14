#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double roundToInteger(double n);
double roundToTenths(double n);
double roundToHundreths(double n);
double roundToThousandths(double n);

int main(void)
{
	printf("%f rounded by integer is %.2f\n", 1.1, roundToInteger(1.1));
	printf("%f rounded by 10ths is %.2f\n", 1.1, roundToTenths(1.1));
	printf("%f rounded by 10ths is %.2f\n", 1.54, roundToTenths(1.55));
	printf("%f rounded by 100ths is %.3f\n", 1.544, roundToHundreths(1.54));
	printf("%f rounded by 100ths is %.3f\n", 1.545, roundToHundreths(1.55));
	printf("%f rounded by 1000ths is %.4f\n", 1.5444, roundToThousandths(1.544));
	printf("%f rounded by 1000ths is %.4f\n", 1.5445, roundToThousandths(1.545));
	return EXIT_SUCCESS;
}

/*
 * Floor can be used to round a value to the nearest integer.
 * To do this for integers, add .5 to it.
 * Decimal position rounding requires more work, you need to mutiple the number by the place you want to round,
 * then add .5, floor, and divide by the same number to return it to a decimal number.
 */ 
double roundToInteger(double n)
{
	return floor(n + .5); 
}

double roundToTenths(double n)
{
	return floor(n  * 10 + .5) / 10; 
}

double roundToHundreths(double n)
{
	return floor(n  * 100 + .5) / 100; 
}

double roundToThousandths(double n)
{
	return floor(n  * 1000 + .5) / 1000; 
}
