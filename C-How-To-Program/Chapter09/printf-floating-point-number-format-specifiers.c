#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float nosign = 1234567.89;
	float positive = +1234567.89;
	float negative = -1234567.89;
	double nosign2 = 1234567.89;
	double positive2 = +1234567.89;
	double negative2 = -1234567.89;

	puts("# Floating Point Number Format Specifiers");
	puts("## Floats %%f");
	printf("%%f 1234567.89 is %f\n", nosign);
	printf("%%f +1234567.89 is %f\n", positive);
	printf("%%f -1234567.89 is %f\n", negative);
	
	puts("\n## Floats %%e and %%E");
	printf("%%e 1234567.89 is %e\n", nosign);
	printf("%%e +1234567.89 is %e\n", positive);
	printf("%%e -1234567.89 is %e\n", negative);
	printf("%%E 1234567.89 is %E\n", nosign);
	printf("%%E +1234567.89 is %E\n", positive);
	printf("%%E -1234567.89 is %E\n", negative);

	/*
	 * e of E is ued when the value's exponent is less than -4, or the exponent is greater than the default 6 width or specified width.
	 * Otherwise f is used.
	 */ 
	puts("\n## Floats %%g and %%G");
	printf("%%g 1234567.89 is %g\n", nosign);
	printf("%%g +1234567.89 is %g\n", positive);
	printf("%%g -1234567.89 is %g\n", negative);
	printf("%%G 1234567.89 is %G\n", nosign);
	printf("%%G +1234567.89 is %G\n", positive);
	printf("%%G -1234567.89 is %G\n", negative);

	puts("\n## Doubles %%f");
	printf("%%f 1234567.89 is %f\n", nosign2);
	printf("%%f +1234567.89 is %f\n", positive2);
	printf("%%f -1234567.89 is %f\n", negative2);
	
	puts("\n## Doubles %%e and %%E");
	printf("%%e 1234567.89 is %e\n", nosign2);
	printf("%%e +1234567.89 is %e\n", positive2);
	printf("%%e -1234567.89 is %e\n", negative2);
	printf("%%E 1234567.89 is %E\n", nosign2);
	printf("%%E +1234567.89 is %E\n", positive2);
	printf("%%E -1234567.89 is %E\n", negative2);

	puts("\n## Doubles %%g and %%G");
	printf("%%g 1234567.89 is %g\n", nosign2);
	printf("%%g +1234567.89 is %g\n", positive2);
	printf("%%g -1234567.89 is %g\n", negative2);
	printf("%%G 1234567.89 is %G\n", nosign2);
	printf("%%G +1234567.89 is %G\n", positive2);
	printf("%%G -1234567.89 is %G\n", negative2);


	return EXIT_SUCCESS;
}
