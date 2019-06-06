#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int weightKg, heightCm;
	float heightM, result;

	printf("Enter your weight in kilograms:");
	scanf("%d", &weightKg);

	printf("Enter your height in centimetres:");
	scanf("%d", &heightCm);

	heightM = (float) heightCm / 100; 
	result = (float) weightKg / (heightM * heightM);
	printf("Your BMI is: %.2f\n", result);
	
	if(result < 18.5) {
		printf("You are Underweight: < 18.5\n");
	}
	else if(result >= 18.5 && result <= 24.9) {
		printf("You are Normal: >= 18.5 & <= 24.9\n");
	}
	else if(result >= 25 && result <= 29.9) {
		printf("You are Overweight: >= 25 & <= 29.9\n");
	}
	else {
		printf("You are obese. > 30\n");
	}

	return EXIT_SUCCESS;
}
