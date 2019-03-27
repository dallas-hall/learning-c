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
	printf("char min:\t%d\n", char_min);
	printf("char max:\t%d\n", char_max);
	printf("short min:\t%d\n", short_min);
	printf("short max:\t%d\n", short_max);
	printf("int min:\t%d\n", int_min);
	printf("int max:\t%d\n", int_max);
	// %ld prints out a signed long
	printf("long min:\t%ld\n", long_min);
	printf("long max:\t%ld\n", long_max);

	printf("\nThe C99 UNSIGNED number ranges are:\n");
	// %u prints out an unsigned integer
	printf("uchar min:\t%u\n", uchar_min);
	printf("uchar max:\t%u\n", uchar_max);
	printf("ushort min:\t%u\n", ushort_min);
	printf("ushort max:\t%u\n", ushort_max);
	printf("uint min:\t%u\n", uint_min);
	printf("uint max:\t%u\n", uint_max);
	// %ld prints out an unsigned long
	printf("ulong min:\t%lu\n", ulong_min);
	printf("ulong max:\t%lu\n", ulong_max);

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

	int_least8_t_min = INT_LEAST8_MIN;
	int_least8_t_max = INT_LEAST8_MAX;
	int_least16_t_min = INT_LEAST16_MIN;
	int_least16_t_max = INT_LEAST16_MAX;
	int_least32_t_min = INT_LEAST32_MIN;
	int_least32_t_max = INT_LEAST32_MAX;
	int_least64_t_min = INT_LEAST64_MIN;
	int_least64_t_max = INT_LEAST64_MAX;

	uint_least8_t_min = 0;
	uint_least8_t_max = UINT_LEAST8_MAX;
	uint_least16_t_min = 0;
	uint_least16_t_max = UINT_LEAST16_MAX;
	uint_least32_t_min = 0;
	uint_least32_t_max = UINT_LEAST32_MAX;
	uint_least64_t_min = 0;
	uint_least64_t_max = UINT_LEAST64_MAX;
	

	printf("\nThe C11 SIGNED number ranges are:\n");
	// PRId prints out a signed integer with the corresponding bit amount.  
	printf("int8_t min:\t%" PRId8 "\n", int8_t_min);
	printf("int8_t max:\t%" PRId8 "\n", int8_t_max);
	printf("int16_t min:\t%" PRId16 "\n", int16_t_min);
	printf("int16_t max:\t%" PRId16 "\n", int16_t_max);
	printf("int32_t min:\t%" PRId32 "\n", int32_t_min);
	printf("int32_t max:\t%" PRId32 "\n", int32_t_max);
	printf("int64_t min:\t%" PRId64 "\n", int64_t_min);
	printf("int64_t max:\t%" PRId64 "\n", int64_t_max);

	printf("\nThe C11 UNSIGNED number ranges are:\n");
	// PRIu prints out an unsigned integer with the corresponding bit amount.  
	printf("uint8_t min:\t%" PRIu8 "\n", uint8_t_min);
	printf("uint8_t max:\t%" PRIu8 "\n", uint8_t_max);
	printf("uint16_t min:\t%" PRIu16 "\n", uint16_t_min);
	printf("uint16_t max:\t%" PRIu16 "\n", uint16_t_max);
	printf("uint32_t min:\t%" PRIu32 "\n", uint32_t_min);
	printf("uint32_t max:\t%" PRIu32 "\n", uint32_t_max);
	printf("uint64_t min:\t%" PRIu64 "\n", uint64_t_min);
	printf("uint64_t max:\t%" PRIu64 "\n", uint64_t_max);


	printf("\nThe C11 SIGNED FAST number ranges are:\n");
	// PRIu prints out a signed integer with the corresponding bit amount.  
	printf("int_fast8_t min:\t%" PRIdFAST8 "\n", int_fast8_t_min);
	printf("int_fast8_t maxn:\t%" PRIdFAST8 "\n", int_fast8_t_max);
	printf("int_fast16_t min:\t%" PRIdFAST16 "\n", int_fast16_t_min);
	printf("int_fast16_t maxn:\t%" PRIdFAST16 "\n", int_fast16_t_max);
	printf("int_fast32_t min:\t%" PRIdFAST32 "\n", int_fast32_t_min);
	printf("int_fast32_t maxn:\t%" PRIdFAST32 "\n", int_fast32_t_max);
	printf("int_fast64_t min:\t%" PRIdFAST64 "\n", int_fast64_t_min);
	printf("int_fast64_t maxn:\t%" PRIdFAST64 "\n", int_fast64_t_max);

	printf("\nThe C11 UNSIGNED FAST number ranges are:\n");
	// PRIu prints out an unsigned integer with the corresponding bit amount.  
	printf("uint_fast8_t min:\t%" PRIuFAST8 "\n", uint_fast8_t_min);
	printf("uint_fast8_t maxn:\t%" PRIuFAST8 "\n", uint_fast8_t_max);
	printf("uint_fast16_t min:\t%" PRIuFAST16 "\n", uint_fast16_t_min);
	printf("uint_fast16_t maxn:\t%" PRIuFAST16 "\n", uint_fast16_t_max);
	printf("uint_fast32_t min:\t%" PRIuFAST32 "\n", uint_fast32_t_min);
	printf("uint_fast32_t maxn:\t%" PRIuFAST32 "\n", uint_fast32_t_max);
	printf("uint_fast64_t min:\t%" PRIuFAST64 "\n", uint_fast64_t_min);
	printf("uint_fast64_t maxn:\t%" PRIuFAST64 "\n", uint_fast64_t_max);

	printf("\nThe C11 SIGNED LEAST number ranges are:\n");
	// PRIu prints out a signed integer with the corresponding bit amount.  
	printf("int_least8_t min:\t%" PRIdLEAST8 "\n", int_least8_t_min);
	printf("int_least8_t maxn:\t%" PRIdLEAST8 "\n", int_least8_t_max);
	printf("int_least16_t min:\t%" PRIdLEAST16 "\n", int_least16_t_min);
	printf("int_least16_t maxn:\t%" PRIdLEAST16 "\n", int_least16_t_max);
	printf("int_least32_t min:\t%" PRIdLEAST32 "\n", int_least32_t_min);
	printf("int_least32_t maxn:\t%" PRIdLEAST32 "\n", int_least32_t_max);
	printf("int_least64_t min:\t%" PRIdLEAST64 "\n", int_least64_t_min);
	printf("int_least64_t maxn:\t%" PRIdLEAST64 "\n", int_least64_t_max);

	printf("\nThe C11 UNSIGNED LEAST number ranges are:\n");
	// PRIu prints out an unsigned integer with the corresponding bit amount.  
	printf("uint_least8_t min:\t%" PRIuLEAST8 "\n", uint_least8_t_min);
	printf("uint_least8_t maxn:\t%" PRIuLEAST8 "\n", uint_least8_t_max);
	printf("uint_least16_t min:\t%" PRIuLEAST16 "\n", uint_least16_t_min);
	printf("uint_least16_t maxn:\t%" PRIuLEAST16 "\n", uint_least16_t_max);
	printf("uint_least32_t min:\t%" PRIuLEAST32 "\n", uint_least32_t_min);
	printf("uint_least32_t maxn:\t%" PRIuLEAST32 "\n", uint_least32_t_max);
	printf("uint_least64_t min:\t%" PRIuLEAST64 "\n", uint_least64_t_min);
	printf("uint_least64_t maxn:\t%" PRIuLEAST64 "\n", uint_least64_t_max);

	return 0;
}
