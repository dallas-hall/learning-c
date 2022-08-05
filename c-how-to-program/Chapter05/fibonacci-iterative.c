#include <stdio.h>
#include <stdlib.h>

#define LIMIT 64

int main(void)
{
	unsigned long long a, b, c;
	int printCount;

	a = 0;
	b = 1;
	printCount = 0;

	puts("# Fibonacci - Iterative");
	for(unsigned int i = 0; i < LIMIT; i++) {
		// First 2 ifs will print the starting terms, 0 and 1
		if (i == 0) {
			printf("%llu, ", a);
			++printCount;
		}
		else if (i == 1) {
			printf("%llu, ", a + b);
			++printCount;
		}
		else {
			printf("%llu, ", a + b);
			c = a;
			a = b;
			b = b + c;
			++printCount;
		}

		if (printCount % 10 == 0) {
			puts("");
		}
	}
	printf("\b\b");
	puts("");

	return EXIT_SUCCESS;
}
