#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("Enter some numbers. These will be displayed in a histogram. Everything else will be ignored. Press ^D (control + d) to exit.\n");
	int currentChar;
	_Bool debugging = true;

	int histogramHeight = 10;
	int numbers[10];

	for (int i = 0; i < 10; i++) {
		numbers[i] = 0;
	}

	while((currentChar = getchar()) != EOF) {
		// Ignore ASCII code point 10 which is the enter key.
		if(debugging && currentChar != 10) {
			printf("currentChar ASCII code point is %d\n", currentChar);
			printf("currentChar decimal number is %d\n", currentChar - '0');
		}
		
		if(currentChar == '0' && numbers[0] < histogramHeight) {
			numbers[0]++;
		}
		if(currentChar == '1' && numbers[0] < histogramHeight) {
			numbers[1]++;
		}
		if(currentChar == '2' && numbers[0] < histogramHeight) {
			numbers[2]++;
		}
		if(currentChar == '3' && numbers[0] < histogramHeight) {
			numbers[3]++;
		}
		if(currentChar == '4' && numbers[0] < histogramHeight) {
			numbers[4]++;
		}
		if(currentChar == '5' && numbers[0] < histogramHeight) {
			numbers[5]++;
		}
		if(currentChar == '6' && numbers[0] < histogramHeight) {
			numbers[6]++;
		}
		if(currentChar == '7' && numbers[0] < histogramHeight) {
			numbers[7]++;
		}
		if(currentChar == '8' && numbers[0] < histogramHeight) {
			numbers[8]++;
		}
		if(currentChar == '9' && numbers[0] < histogramHeight) {
			numbers[9]++;
		}
	}

	printf("The histograms are limited to a height of %d characters.\n", histogramHeight);
	printf("Vertical Histogram\n");
	for (int i = 0; i < 10; i++) {
		printf("%d: ", i);
		for(int j = 0; j < numbers[i]; j++) {
			printf("=");
		}
		printf("\n");
	}

	printf("Horizontal Histogram\n");
	for (int i = histogramHeight; i > 0; i--) {
		for (int j = 0; j < 10; j++) {
			if(numbers[j] < i) {
				printf("   ");
			} else {
				printf(" * ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 10; i++) {
		printf(" %d ", i);
	}
	printf("\n");
	return 0;
}
