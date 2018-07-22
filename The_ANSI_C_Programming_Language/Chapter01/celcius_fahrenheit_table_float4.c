#include <stdio.h>
// import new int types
#include <inttypes.h>

// this method returns an int (return code) and takes no arguments
int main(void)
{
	float c;

	printf("C\tF\n");
	for(c = 300; c >= 0; c = c - 20) {
		printf("%1.1f\t%3.1f\n", c, (c * 9.0 / 5.0) + 32); // right justified
	}

	return 0;
}

