#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a, b, c, sum, product, smallest, largest;
	float average;

	printf("Enter 2 integers separated by space: ");
	scanf("%d %d", &a, &b);
	if (a > b) {
		printf("%d > %d.\n", a, b);
	}
	else if (a == b) {
		printf("%d = %d.\n", a, b);
	}
	else {
		printf("%d < %d.\n", a, b);
	}

	printf("Enter 1 more integer: ");
	scanf("%d", &c);
	sum = a + b + c;
	product = a * b * c;
	
	if (a > b && a > c) {
		largest = a;
	}
	else if (b > a && b > c) {
		largest = b;
	}
	else if (c > a && c > b) {
		largest = c;
	}
	/* Take the first as the "largest" */
	else
	{
		if (a == b && a > c) {
			largest = a;
		}
		else if (a == c && a > b) {
			largest = a;
		}
		/*else if (b == a && b > c) {
			largest = b;
		}*/
		else if (b == c && b > a) {
			largest = b;
		}
		/*else if (c == a && c > b) {
			largest = c;
		}
		else if (c == b && c > a) {
			largest = c;
		}*/
	}

	if (a < b && a < c) {
		smallest = a;
	}
	else if (b < a && b < c) {
		smallest = b;
	}
	else if (c < a && c < b) {
		smallest = c;
	}
	/* Take the first as the "smallest" */
	else {
		if (a == b && a < c) {
			smallest = a;
		}
		else if (a == c && a < b) {
			smallest = a;
		}
		/*else if (b == a && b < c) {
			smallest = b;
		}*/
		else if (b == c && b < a) {
			smallest = b;
		}
		/*else if (c == a && c < b) {
			smallest = c;
		}
		else if (c == b && c < a) {
			smallest = c;
		}*/
	
	}

	sum = a + b + c;
	product = a * b * c;
	average = (float) sum / 3;

	printf("The largest of %d, %d, and %d is %d.\n", a, b, c, largest);
	printf("The smallest of %d, %d, and %d is %d.\n", a, b, c, smallest);
	printf("The sum of %d + %d + %d is %d.\n", a, b, c, sum);
	printf("The product of %d * %d * %d is %d.\n", a, b, c, product);
	printf("The average of (%d + %d + %d) / 3 is %.2f.\n", a, b, c, average);

	return EXIT_SUCCESS;
}

