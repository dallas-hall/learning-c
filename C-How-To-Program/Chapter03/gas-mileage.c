#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float input, gallons, miles, totalGallons, totalMiles;
	totalGallons = 0;
	totalMiles = 0;

	while(1) {
		printf("Enter gallons used or -1 to end: ");
		scanf("%f", &input);
		if ((int) input == -1) {
			printf("Calculating total average.\n");
			break;
		}
		else {
			gallons = input;
			totalGallons += gallons;
			printf("Enter miles driven: ");
			scanf("%f", &miles);
			totalMiles += miles;

			printf("The average miles / gallon for this tank was: %f\n", (float) miles / gallons);
		}
	}

	printf("The overall average miles / gallon was: %f\n", (float) totalMiles / totalGallons);
	return EXIT_SUCCESS;
}
