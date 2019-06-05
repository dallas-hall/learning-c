#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, sum, product, difference, quotient, remainder;
	printf("Enter 2 digits separated by space: ");
	// No need for a \n as scanf provides this.
	scanf("%d %d", &a, &b);

	remainder = a % b;
	product = a * b;
	quotient = a / b;
	sum = a + b;
	difference = a - b;

	printf("Remainder of %d %% %d = %d.\n", a, b, remainder);
	printf("Product of %d * %d = %d.\n", a, b, product);
	printf("Quotient of %d / %d = %d.\n", a, b, quotient);
	printf("Sum of %d + %d = %d.\n", a, b, sum);
	printf("Difference of %d - %d = %d.\n", a, b, difference);

	return EXIT_SUCCESS;
}
