#include <stdio.h>
// import the new int types libary
#include <inttypes.h>

// This method returns an int (return code) and takes no arguments
int main(void)
{
	int8_t lower, increment;
	int16_t f, c, upper;

	lower = 0;
	upper = 300;
	increment = 20;

	f = lower;
	printf("F\tC\n");
	while (f <= upper) {
		c = 5 * (f - 32) / 9;
		// print right justified
		printf("%3d %6d\n", f, c);
		f = f + increment;
	}

	return 0;
}
