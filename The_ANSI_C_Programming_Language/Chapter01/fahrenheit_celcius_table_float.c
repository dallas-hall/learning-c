#include <stdio.h>

main()
{
	float f, c;
	int lower, upper, increment;

	lower = 0;
	upper = 300;
	increment = 20;

	f = lower;
	printf("F\tC\n");
	while (f <= upper) {
		//c = 5 * (f - 32) / 9; // Integer division
		c = (5.0 / 9.0) * (f - 32.0);
		//printf("%f\t%f\n", f, c); // not right justified
		printf("%3.0f %6.1f\n", f, c); // right justified
		f = f + increment;
	}
}
