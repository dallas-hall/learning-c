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
	// Unsigned
	uint8_t uint8_t_min, uint8_t_max;
	uint16_t uint16_t_min, uint16_t_max;
	uint32_t uint32_t_min, uint32_t_max;
	uint64_t uint64_t_min, uint64_t_max;

	int8_t_min = INT8_MIN;
	int8_t_max = INT8_MAX;
	int16_t_min = INT16_MIN;
	int16_t_max = INT16_MAX;
	int32_t_min = INT32_MIN;
	int32_t_max = INT32_MAX;
	int64_t_min = INT64_MIN;
	int64_t_max = INT64_MAX;

	uint8_t_min = 0;
	uint8_t_max = UINT8_MAX;
	uint16_t_min = 0;
	uint16_t_max = UINT16_MAX;
	uint32_t_min = 0; 
	uint32_t_max = UINT32_MAX;
	uint64_t_min = 0;
	uint64_t_max = UINT64_MAX;

	// Fastest at least signed 8, 16, 32, & 64 bits
	int_fast8_t int_fast8_t_min, int_fast8_t_max;
	int_fast16_t int_fast16_t_min, int_fast16_t_max;
	int_fast32_t int_fast32_t_min, int_fast32_t_max;
	int_fast64_t int_fast64_t_min, int_fast64_t_max; 
	// Unsigned
	uint_fast8_t uint_fast8_t_min, uint_fast8_t_max;
	uint_fast16_t uint_fast16_t_min, uint_fast16_t_max;
	uint_fast32_t uint_fast32_t_min, uint_fast32_t_max;
	uint_fast64_t uint_fast64_t_min, uint_fast64_t_max; 

	int_fast8_t_min = INT_FAST8_MIN;
	int_fast8_t_max = INT_FAST8_MAX;
	int_fast16_t_min = INT_FAST16_MIN;
	int_fast16_t_max = INT_FAST16_MAX;
	int_fast32_t_min = INT_FAST32_MIN;
	int_fast32_t_max = INT_FAST32_MAX;
	int_fast64_t_min = INT_FAST64_MIN;
	int_fast64_t_max = INT_FAST64_MAX;

	uint_fast8_t_min = 0;
	uint_fast8_t_max = UINT_FAST8_MAX;
	uint_fast16_t_min = 0;
	uint_fast16_t_max = UINT_FAST16_MAX;
	uint_fast32_t_min = 0;
	uint_fast32_t_max = UINT_FAST32_MAX;
	uint_fast64_t_min = 0;
	uint_fast64_t_max = UINT_FAST64_MAX;
	
	// Smallest at least signed 8, 16, 32, & 64 bits
	int_least8_t int_least8_t_min, int_least8_t_max;
	int_least16_t int_least16_t_min, int_least16_t_max;
	int_least32_t int_least32_t_min, int_least32_t_max;
	int_least64_t int_least64_t_min, int_least64_t_max; 
	// Unsigned
	uint_least8_t uint_least8_t_min, uint_least8_t_max;
	uint_least16_t uint_least16_t_min, uint_least16_t_max;
	uint_least32_t uint_least32_t_min, uint_least32_t_max;
	uint_least64_t uint_least64_t_min, uint_least64_t_max; 

	printf("The C11 SIGNED number ranges are:\n");
	// PRId prints out a signed integer with the corresponding bit amount.  
	printf("int8_t min:\t%" PRId8 "\t\nint8_t max:\t%" PRId8 "\n", int8_t_min, int8_t_max);
	printf("int16_t min:\t%" PRId16 "\t\nint16_t max:\t%" PRId16 "\n", int16_t_min, int16_t_max);
	printf("int32_t min:\t%" PRId32 "\t\nint32_t max:\t%" PRId32 "\n", int32_t_min, int32_t_max);
	printf("int64_t min:\t%" PRId64 "\t\nint64_t max:\t%" PRId64 "\n\n", int64_t_min, int64_t_max);

	printf("The C11 UNSIGNED number ranges are:\n");
	// PRIu prints out an unsigned integer with the corresponding bit amount.  
	printf("uint8_t min:\t%" PRIu8 "\t\nuint8_t max:\t%" PRIu8 "\n", uint8_t_min, uint8_t_max);
	printf("uint16_t min:\t%" PRIu16 "\t\nuint16_t max:\t%" PRIu16 "\n", uint16_t_min, uint16_t_max);
	printf("uint32_t min:\t%" PRIu32 "\t\nuint32_t max:\t%" PRIu32 "\n", uint32_t_min, uint32_t_max);
	printf("uint64_t min:\t%" PRIu64 "\t\nuint64_t max:\t%" PRIu64 "\n\n", uint64_t_min, uint64_t_max);

	printf("The C11 SIGNED FAST number ranges are:\n");
	// PRIu prints out an unsigned integer with the corresponding bit amount.  
	printf("uint8_t min:\t%" PRIu8 "\t\nuint8_t max:\t%" PRIu8 "\n", uint8_t_min, uint8_t_max);
	printf("uint16_t min:\t%" PRIu16 "\t\nuint16_t max:\t%" PRIu16 "\n", uint16_t_min, uint16_t_max);
	printf("uint32_t min:\t%" PRIu32 "\t\nuint32_t max:\t%" PRIu32 "\n", uint32_t_min, uint32_t_max);
	printf("uint64_t min:\t%" PRIu64 "\t\nuint64_t max:\t%" PRIu64 "\n\n", uint64_t_min, uint64_t_max);


	return 0;
}
