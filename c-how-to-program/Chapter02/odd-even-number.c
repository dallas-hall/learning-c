#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);

	if(n % 2 == 0) {
		printf("The number %d is even.\n", n);
	}
	else {

		printf("The number %d is odd.\n", n);
	}

	return EXIT_SUCCESS;
}
