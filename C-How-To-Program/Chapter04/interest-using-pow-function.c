#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	double amount, principle, rate;
	int years;

	printf("Enter starting amount (i.e principle): ");
	scanf("%lf", &principle);
	printf("Enter interest rate (decimal representing a percentage): ");
	scanf("%lf", &rate);
	printf("Enter the amount of years to invest: ");
	scanf("%d", &years);

	printf("%4s%21s\n", "Year", "Amount on deposit");
	for (int year = 1; year <= years; year++) {
		amount = principle * pow(1.0 + rate, year);
		printf("%4d%21.2f\n", year, amount);
	}

	amount = 0;
	printf("%4s%21s\n", "Year", "Amount on deposit");
	for (int year = 1; year <= years; year++) {
		if (1 == year) {
			amount += principle * (1.0 + rate);
		}
		else {
			amount *= (1.0 + rate);
		}
		printf("%4d%21.2f\n", year, amount);
	}

	return EXIT_SUCCESS;
}
