#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *anInt = "8";
	char *aLongInt = "4294967296";
	char *aFloat = "1.23456789";
	char *aDouble = "1.23456789";

	double d;
	long l;
	unsigned long ul;
	char aDouble2[] = "1.23456789 & some extra crap.";
	char aLongInt2[] ="4294967296 & some extra crap."; 
	char anUnsignedLong[] = "4294967296 & some extra crap.";
	char *strPtr;

	printf("# String To Number Conversions\n");
	printf("# atoi - a to int\n");
	printf("The string \"%s\" as an int is %d\n", anInt, atoi(anInt));

	printf("\n# atol - a to long int\n");
	printf("The string \"%s\" as a long is %ld\n", aLongInt, atol(aLongInt));

	printf("\n# atof - a to long float (really a double)\n");
	printf("The string \"%s\" as a double is %f\n", aFloat, atof(aFloat));
	
	printf("\n# atof - a to long double\n");
	printf("The string \"%s\" as a double is %f\n", aDouble, atof(aDouble));
	
	printf("\n# strtod - string to double & remaining string\n");
	d = strtod(aDouble2, &strPtr);
	printf("The string \"%s\" as a double is %f\nWwith the string \"%s\" removed from it.\n", aDouble2, d, strPtr); 

	printf("\n# strtol - string to long & remaining string\n");
	/*
	 * Third argument is the radix (number system) to use.
	 * 8 = octal
	 * 0 / 10= decimal
	 * 16 = hex
	 *
	 */ 
	l = strtol(aLongInt2, &strPtr, 10);
	printf("The string \"%s\" as a long is %ld\nWith the string \"%s\" removed from it.\n", aLongInt2, l, strPtr); 

	printf("\n# strtoul - string to unsigned long & remaining string\n");
	/*
	 * Third argument is the radix (number system) to use.
	 * 8 = octal
	 * 0 / 10 = decimal
	 * 16 = hex
	 *
	 */ 
	ul = strtoul(anUnsignedLong, &strPtr, 0);
	printf("The string \"%s\" as an unsigned long is %lu\nWith the string \"%s\" removed from it.\n", anUnsignedLong, ul, strPtr); 
	
	return EXIT_SUCCESS;
}
