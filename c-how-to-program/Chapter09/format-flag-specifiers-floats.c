#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* s = "hello";
	int i = 95;
	int j = -95;
	float f = 123;
	double d = 123.456;

	/*
	 * - is left justified.
	 * Default is right justified.
	 */ 
	puts("# Format Flags");
	puts("## Justification");
	printf("%%-10s %s after \\t is\t'%-10s'\n", s, s);
	printf("%%10s %s after \\t is\t'%10s'\n", s, s);
	printf("%%-10d %d after \\t is\t'%-10d'\n", i, i);
	printf("%%10d %d after \\t is\t'%10d'\n", j, j);

	/*
	 * + adds a + or - sign
	 * ' ' adds a - sign only.
	 */ 
	puts("\n## Integer Signing");
	printf("%%+10d %d after \\t is\t'%+10d'\n", i, i);
	printf("%%10d %d after \\t is\t'%10d'\n", i, i);
	printf("%%+10d %d after \\t is\t'%+10d'\n", j, j);
	printf("%%10d %d after \\t is\t'%10d'\n", j, j);
	printf("%% 10d %d after \\t is\t'% 10d'\n", i, i);
	printf("%% 10d %d after \\t is\t'% 10d'\n", j, j);

	/*
	 * # adds leading 0s to Base 8 and Base 16 Numbers
	 */ 
	puts("\n## Octal / Hex Leading Zereos");
	printf("%%#10o %d after \\t is\t'%#10o'\n", i, i);
	printf("%%#10x %d after \\t is\t'%#10x'\n", i, i);
	printf("%%#10X %d after \\t is\t'%#10X'\n", i, i);

	/*
	 * # adds trailing 0s to non-existant decimals in floating point Base 10 numbers
	 */ 
	puts("\n## Fractional Forced Zereos");
	printf("%%10f %f after \\t is\t'%10f'\n", f, f);
	printf("%%#10f %f after \\t is\t'%#10f'\n", f, f);
	printf("%%#10e %e after \\t is\t'%#10e'\n", f, f);
	printf("%%#10E %E after \\t is\t'%#10E'\n", d, d);
	printf("%%#10g %g after \\t is\t\t'%#10g'\n", f, f);
	printf("%%#10g %G after \\t is\t'%#10G'\n", d, d);
	
	/*
	 * 0 adds leading 0s to Base 10 numbers
	 */ 
	puts("\n## Decimal Leading Zereos");
	printf("%%010s %d after \\t is\t'%010d'\n", i, i);
	printf("%%010s %d after \\t is\t'%010d'\n", j, j);

	return EXIT_SUCCESS;
}
