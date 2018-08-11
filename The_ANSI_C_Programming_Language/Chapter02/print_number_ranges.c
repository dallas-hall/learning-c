#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

int main(void)
{
	// @@@ C99 Standard @@@
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
	printf("long min:\t%lu\t\nlong max:\t%lu\n\n", ulong_min, ulong_max);

	// @@@ C11 Standard @@@
	// https://en.cppreference.com/w/c/types/integer
	// Exactly signed
	int8_t int8_t_min, int8_t_max;
	int16_t int16_t_min, int16_t_max;
	int32_t int32_t_min, int32_t_max;
	int64_t int64_t_min, int64_t_max;

	// Fastest at least signed 8, 16, 32, & 64 bits
	int_fast8_t int_fast8_t_min, int_fast8_t_max;
	int_fast16_t int_fast16_t_min, int_fast16_t_max;
	int_fast32_t int_fast32_t_min, int_fast32_t_max;
	int_fast64_t int_fast64_t_min, int_fast64_t_max; 

	// Smallest at least signed 8, 16, 32, & 64 bits
	int_least8_t int_least8_t_min, int_least8_t_max;
	int_least16_t int_least16_t_min, int_least16_t_max;
	int_least32_t int_least32_t_min, int_least32_t_max;
	int_least64_t int_least64_t_min, int_least64_t_max; 

	int8_t_min = INT8_MIN;
	int8_t_max = INT8_MAX;
	int16_t_min = INT16_MIN;
	int16_t_max = INT16_MAX;
	int32_t_min = INT32_MIN;
	int32_t_max = INT32_MAX;
	int64_t_min = INT64_MIN;
	int64_t_max = INT64_MAX;

	printf("The C11 SIGNED number ranges are:\n");
	// PRId prints out a signed integer with the corresponding bit amount.  
	printf("int8_t min:\t%" PRId8 "\t\nint8_t max:\t%" PRId8 "\n", int8_t_min, int8_t_max);

	printf("int16_t min:\t%" PRId16 "\t\nint16_t max:\t%" PRId16 "\n", int16_t_min, int16_t_max);
	printf("int32_t min:\t%" PRId32 "\t\nint32_t max:\t%" PRId32 "\n", int32_t_min, int32_t_max);
	printf("int64_t min:\t%" PRId64 "\t\nint64_t max:\t%" PRId64 "\n", int64_t_min, int64_t_max);


	return 0;
}
