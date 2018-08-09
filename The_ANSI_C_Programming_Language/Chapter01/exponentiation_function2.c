#include <stdio.h>
#include <inttypes.h>

// function prototypes
int64_t power(int64_t base, size_t n);

int main(void)
{
	printf("Displaying the first 16 powers of 2.\n");
	for (int i = 0; i < 16; i++) {
		// Using PRId64 to print out the int64_t
		// The explicit size_t cast is to remove the implict cast warning, of int to size_t
		printf("2 ** %d\t%" PRId64 "\n", i, power(2, (size_t) i));
	}
	return 0;
}

// base is now using 64 bit int for larger numbers.
// n is now using size_t which is an unsigned integer of at least 16 bits. This stops a negative number from being passed. As all unsigned integers are handled as positive integers only.
int64_t power(int64_t base, size_t n)
{
	// Using 64 instead of 32 to hold moar numbers. 
	int64_t result = 1;
	// The explicit cast here is for the same reason as above.
	for (int i = 1; (size_t) i <= n; i++) {
		result = result * base;	
	}

	return result;
}
