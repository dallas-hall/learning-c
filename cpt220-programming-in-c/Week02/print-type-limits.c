#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	/* C primitive types - unqualified & signed */
	char c;
	int i;
	float f;
	double d;

	/* C primitive types - qualified & signed */
	short s;
	short int si;
	long l;
	long int li;
	long double ld;

	/* C primitive types - unqualified & unsigned */
	unsigned char uc;
	unsigned int ui;

	/* C primitive types - qualified & signed */
	unsigned short us;
	unsigned short int usi;
	unsigned long ul;
	unsigned long int uli;

	/* https://stackoverflow.com/questions/2053843/min-and-max-value-of-data-type-in-c */
	/* %ld prints out the number as a long integer, needed here to cover the byte size */
	printf("# Signed Primitive Types.\n");
	printf("The size of the signed & unqualified ANSI C primitive types on my system is:\n");
	printf("A char is %ld bits or %ld byte(s). The CHAR_MIN is %d and the CHAR_MAX is %d.\n", sizeof(c) * 8, sizeof(c), CHAR_MIN, CHAR_MAX);
	printf("An int is %ld bits or %ld byte(s). The INT_MIN is %d and the INT_MAX is %d.\n", sizeof(i) * 8, sizeof(i), INT_MIN, INT_MAX);
	printf("A float is %ld bits or %ld byte(s) The -FLT_MAX is %e and the FLT_MAX is %e.\n", sizeof(f) * 8, sizeof(f), -FLT_MAX, FLT_MAX);
	printf("A double is %ld bits or %ld byte(s). The -DBL_MAX is %e and the DLB_MAX is %e.\n", sizeof(d) * 8, sizeof(d), -DBL_MAX, DBL_MAX);

	printf("\n# Signed Qualified Primtive Types.\n");
	printf("The size of the signed & qualified ANSI C primitive types on my system is:\n");
	printf("A short is %ld bits or %ld byte(s). The SHRT_MIN is %d and the SHRT_MAX is %d.\n", sizeof(s) * 8, sizeof(s), SHRT_MIN, SHRT_MAX);
	printf("A short int is %ld bits or %ld byte(s). The SHRT_MIN is %d and the SHRT_MAX is %d.\n", sizeof(si) * 8, sizeof(si), SHRT_MIN, SHRT_MAX);
	printf("A long is %ld bits or %ld byte(s). The LONG_MIN is %ld and the LONG_MAX is %ld.\n", sizeof(l) * 8, sizeof(l), LONG_MIN, LONG_MAX);
	printf("A long int is %ld bits or %ld byte(s). The LONG_MIN is %ld and the LONG_MAX is %ld.\n", sizeof(li) * 8, sizeof(li), LONG_MIN, LONG_MAX);
	printf("A long double is %ld bits or %ld byte(s). The -LDBL_MAX is %Lf and the LDBL_MAX is %Lf.\n", sizeof(ld) * 8, sizeof(ld), -LDBL_MAX, LDBL_MAX);
	
	printf("\n# Unsigned Primitive Types.\n");
	printf("The size of the unsigned & unqualified ANSI C primitive types on my system is:\n");
	printf("An unsigned char is %ld bits or %ld byte(s). The minimum of unsigned number is always 0 and the UCHAR_MAX is %d.\n", sizeof(uc) * 8, sizeof(uc), UCHAR_MAX);
	printf("An unsigned int is %ld bits or %ld byte(s). The minimum of an unsigned number is always 0 and the UINT_MAX is %u.\n", sizeof(ui) * 8, sizeof(ui), UINT_MAX);
	
	printf("\n# Unsigned Qualified Primtive Types.\n");
	printf("The size of the unsigned & qualified ANSI C primitive types on my system is:\n");
	printf("An unsigned short is %ld bits or %ld byte(s). The minimum of an unsigned number is always 0 and the USHRT_MAX is %u.\n", sizeof(us) * 8, sizeof(us), USHRT_MAX);
	printf("An unsigned short int is %ld bits or %ld byte(s). The minimum of an unsigned number is always 0 and the USHRT_MAX is %u.\n", sizeof(usi) * 8, sizeof(usi), USHRT_MAX);
	printf("An unsigned long is %ld bits or %ld byte(s). The minimum of an unsigned number is always 0 and the ULONG_MAX is %ld.\n", sizeof(ul) * 8, sizeof(ul), ULONG_MAX);
	printf("An unsigned long int is %ld bits or %ld byte(s). The minimum of an unsigned number is always 0 and the ULONG_MAX is %ld.\n", sizeof(uli) * 8, sizeof(uli), ULONG_MAX);
	
	printf("\nThe minimums on a *nix system can be found at /usr/include/limits.h\nOn my system signing data types is default.\n");	
	
	return EXIT_SUCCESS;
}
