#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;

	printf("Enter an integer: ");
	scanf("%d", &n);
	int m = n;

	printf("\n# Pre-increment ++n\n");
	printf("You entered %d.\n", m);
	printf("Printing ++n is %d.\n", ++n);
	printf("Printing n after ++n is %d.\n", n);
	printf("Resetting n to %d.\n", m);
	n = m;

	printf("\n# Post-increment n++\n");
	printf("You entered %d.\n", m);
	printf("Printing n++ is %d.\n", n++);
	printf("Printing n after n++ is %d.\n", n);
	printf("Resetting n to %d.\n", m);
	n = m;

	printf("\n# Pre-decrement --n\n");
	printf("You entered %d.\n", m);
	printf("Printing --n is %d.\n", --n);
	printf("Printing n after --n is %d.\n", n);
	printf("Resetting n to %d.\n", m);
	n = m;

	printf("\n# Post-decrement n--\n");
	printf("You entered %d.\n", m);
	printf("Printing n-- is %d.\n", n--);
	printf("Printing n after n-- is %d.\n", n);

	return EXIT_SUCCESS;
}
