#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int passes = 0;
	int failures = 0;
	int students = 0;
	int singleExamResult = 0;

	while (students < 10) {
		students += 1;
		printf("Enter student exam result (1=pass and 2=fail): ");
		scanf("%d", &singleExamResult);

		if (singleExamResult == 1) {
			passes += 1;
		} else {
			failures += 1;
		}
	}
	
	printf("The total amount of passes was: %d.\n", passes);
	printf("The total amount of failures was: %d.\n", failures);

	if (passes >= 8) {
		printf("Instructor bonus earned\n.");
	} else {
		printf("Instructor bonus not earned.\n");
	}

	return EXIT_SUCCESS;
}
