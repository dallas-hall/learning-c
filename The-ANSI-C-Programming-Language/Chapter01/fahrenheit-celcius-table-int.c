#include <stdio.h>

main()
{
	int f, c;
	int lower, upper, increment;

	lower = 0;
	upper = 300;
	increment = 20;

	f = lower;
	printf("F\tC\n");
	while (f <= upper) {
		c = 5 * (f - 32) / 9;
		//printf("%d\t%d\n", f, c); // not right justified
		printf("%3d %6d\n", f, c); // right justified
		f = f + increment;
	}
}
