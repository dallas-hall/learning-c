#include <stdio.h>

// this method returns an int (return code) and takes no arguments
int main(void)
{
	float c;

	printf("C\tF\n");
	for(c = 0; c <= 300; c = c + 20) {
		printf("%1.1f\t%3.1f\n", c, (c * 9.0f / 5.0f) + 32); // right justified
	}

	return 0;
}

