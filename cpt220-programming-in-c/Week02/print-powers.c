#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i, j, n, result;

	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("Printing powers of %d 14 times.\n", n);
	if (0 == n) {
		printf("0 to the power of anything is 0\n");
	}
	else {
		for(i = 0; i < 14; ++i) {
			/* n ^ 0 is always 1 */
			if (0 == i) {
				result = 1;
			}
			/* n ^ 1 is always n */
			else if (1 == i) {
				result = n;
			}
			else {
				result = n;
				
				for(j = 0; j < i - 1; ++j) {
					result *= n;
				}
			}

			printf("%d to the power of %d is: %d\n", n, i, result);
		}
	}

	return EXIT_SUCCESS;
}
