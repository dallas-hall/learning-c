#include <stdio.h>
#include <inttypes.h>

// function prototypes
// Using the signed 64 integer int64_t so there is room for larger numbers.
int64_t power(int64_t base, size_t n);

int main(void)
{
	printf("Displaying the first 16 powers of 2.\n");
	// Using the unsigned integer size_t. This is an unassigned integer of at least 16 bits. All unsigned integers are handled as positive numbers.
	// Note: the overflow happens at 63 when using int64_t.
	for (size_t i = 0; i < 32; i++) {
		// %lu is an unsigned integer aka long
		// Using PRId64 to print out the int64_t
		printf("2 ** %lu\t%" PRId64 "\n", i, power(2,  i));
	}
	return 0;
}

int64_t power(int64_t base, size_t n)
{
	int64_t result = 1;
	for (size_t i = 1; i <= n; i++) {
		result = result * base;	
	}

	return result;
}
