#include <stdio.h>

main()
{
	float f, c;
	int lower, upper, increment;

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
}
