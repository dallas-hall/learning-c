#include <stdio.h>
// import the new int types library
#include <inttypes.h>

// void here means don't take any arguments
int main(void)
{
	float f, c;
	int16_t lower, upper, increment;

	lower = 0;
	upper = 300;
	increment = 20;

	f = lower;
	printf("F\tC\n");
	while (f <= upper) {
		//c = 5 * (f - 32) / 9; // Integer division
		c = (5.0f / 9.0f) * (f - 32.0f); // without f these are doubles
		//printf("%f\t%f\n", f, c); // not right justified
		printf("%3.0f %6.1f\n", f, c); // right justified
		f = f + increment;
	}
}
