#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int input;
	printf("Enter an integer with 5 places: ");
	scanf("%d", &input);

	// Use integer division and remainder division to get the required digits.
	printf("%d\t%d\t%d\t%d\t%d\n",
		input / 10000,
		input / 1000 % 10,
		input / 100 % 10,
		input / 10 % 10,
		input / 1 % 10
	); 

	return EXIT_SUCCESS;
}
