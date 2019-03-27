#include <stdio.h>
// import new int types
#include <inttypes.h>

// this method returns an int (return code) and takes no arguments
int main(void)
{
	float f, c;
	int16_t lower, upper, increment;

	lower = 0;
	upper = 300;
	increment = 20;

	c = lower;
	printf("C\tF\n");
	while (c <= upper) {
		f = (c * 9.0 / 5.0) + 32;  
		printf("%1.1f\t%3.1f\n", c, f); // right justified
		c = c + increment;
	}
	return 0;
}

