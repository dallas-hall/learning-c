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

	printf("%4s%21s%4s\n", "Year", "Amount on deposit", "Rate");
	for (int year = 1; year <= years; year++) {
		amount = principle * pow(1.0 + rate, year);
		printf("%4d%21.2f %.2lf\n", year, amount, rate);
	}

	// Update for an exercise
	amount = 0;
	for (int i = 4; i <= 10; i++) {
		if (i != 4) {
			rate = (double) i / 100;
		}
		printf("%4s%21s%5s\n", "Year", "Amount on deposit", "Rate");
		for (int year = 1; year <= years; year++) {
			if (1 == year) {
				amount += principle * (1.0 + rate);
			}
			else {
				amount *= (1.0 + rate);
			}
			printf("%4d%21.2f %-.2lf\n", year, amount, rate);
		}
		amount = 0;
	}
	return EXIT_SUCCESS;
}
