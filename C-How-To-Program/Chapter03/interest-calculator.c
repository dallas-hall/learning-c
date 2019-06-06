#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float principle, rate, days;
	while(1) {
		printf("Enter the loan principle or -1 to exit: ");
		scanf("%f", &principle);
		if((int) principle == -1) {
			break;
		}
		printf("Enter the interest rate: ");
		scanf("%f", &rate);
		printf("Enter the term of the loan in days: ");
		scanf("%f", &days);

		printf("The interest charge is: $%.2f\n", principle * rate * days / 365);
	}
	return EXIT_SUCCESS;
}
