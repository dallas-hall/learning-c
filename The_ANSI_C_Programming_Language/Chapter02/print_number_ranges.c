#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

int main(void)
{
	char char_min, char_max;
	short short_min, short_max;
	int int_min, int_max;
	long long_min, long_max;
	unsigned char uchar_min, uchar_max;
	unsigned short ushort_min, ushort_max;
	unsigned int uint_min, uint_max;
	unsigned long ulong_min, ulong_max;
	
	// Signed - use 2s complement to store positive and negative numbers
	char_min = SCHAR_MIN;
	char_max = SCHAR_MAX;
	short_min = SHRT_MIN;
	short_max = SHRT_MAX;
	int_min = INT_MIN;
	int_max = INT_MAX;
	long_min = LONG_MIN;
	long_max = LONG_MAX;

	// Unsigned - start at 0 and can't overflow as they can only be positive numbers
	uchar_min = 0;
	uchar_max = UCHAR_MAX;
	ushort_min = 0;
	ushort_max = USHRT_MAX;
	uint_min = 0;
	uint_max = UINT_MAX;
	ulong_min = 0;
	ulong_max = ULONG_MAX;

	printf("The C99 SIGNED number ranges are:\n");
	// %d prints out a signed integer
	printf("char min:\t%d\t\nchar max:\t%d\n", char_min, char_max);
	printf("short min:\t%d\t\nshort max:\t%d\n", short_min, short_max);
	printf("int min:\t%d\t\nint max:\t%d\n", int_min, int_max);
	// %ld prints out a signed long
	printf("long min:\t%ld\t\nlong max:\t%ld\n\n", long_min, long_max);

	printf("The C99 UNSIGNED number ranges are:\n");
	// %u prints out an unsigned integer
	printf("char min:\t%u\t\nchar max:\t%u\n", uchar_min, uchar_max);
	printf("short min:\t%u\t\nshort max:\t%u\n", ushort_min, ushort_max);
	printf("int min:\t%u\t\nint max:\t%u\n", uint_min, uint_max);
	// %ld prints out an unsigned long
	printf("long min:\t%lu\t\nlong max:\t%lu\n", ulong_min, ulong_max);

	return 0;
}
