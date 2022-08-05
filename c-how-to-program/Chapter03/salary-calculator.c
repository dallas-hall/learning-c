#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float hours, rate, wage;
	while(1) {
		printf("Enter total hours worked for the week the week or -1 to end: ");
		scanf("%f", &hours);
		if((int) hours == -1) {
			break;
		}
		printf("Enter hourly rate: ");
		scanf("%f", &rate);
		// Base hours is 40 @ rate, rest is rate * 1.5
		if(hours > 40) {
			wage = (hours - ((int) hours % 40)) * rate;
			wage += ((int) hours % 40) * (10 * 1.5);
		}
		else {
			wage = hours * 10;
		}
		printf("Weekly wage is: %.2f\n", wage);
	}
	return EXIT_SUCCESS;
}
