#include <stdio.h>

// void here means don't take any command line arguments
int main(void)
{
	float f, c;
	int lower, upper, increment;

	lower = 0;
	upper = 300;
	increment = 20;

	c = lower;
	printf("C\tF\n");
	while (c <= upper) {
		f = (c * 9.0f / 5.0f) + 32;  
		printf("%1.1f\t%3.1f\n", c, f); // right justified
		c = c + increment;
	}
}
