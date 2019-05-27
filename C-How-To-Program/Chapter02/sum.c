#include <stdio.h>

int main(void)
{
	int integer1;
	int integer2;
	int sum;

	printf("Enter the first integer:\n");
	scanf("%d", &integer1);

	printf("Enter the second integer:\n");
	scanf("%d", &integer2);

	sum = integer1 + integer2;
	printf("The sum of %d and %d is %d.\n", integer1, integer2, sum);

	return 0;
}
