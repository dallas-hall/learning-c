#include <stdio.h>
// import new int types
#include <inttypes.h>

#define LOWER 0
#define UPPER 300
#define INCREMENT 20

// this method returns an int (return code) and takes no arguments
int main(void)
{
	float c;

	printf("C\tF\n");
	for(c = LOWER; c <= UPPER; c = c + INCREMENT) {
		printf("%1.1f\t%3.1f\n", c, (c * 9.0f / 5.0f) + 32); // right justified
	}

	return 0;
}

