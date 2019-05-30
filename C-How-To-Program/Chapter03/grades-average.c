#include <stdio.h>

int main(void)
{
	int counter = 0;
	int students = 0;
	int grade = 0;
	int total = 0;
	double average = 0;

	printf("Enter how many students to grade:\n");
	scanf("%d", &students);

	while (counter < students) {
		printf("Enter student # %d's grade:\n", counter + 1);
		scanf("%d", &grade);
		total = total + grade;
		counter += 1;
	}

	average = total / students;
	printf("The average grade was %.2f.\n", average);

	return 0;
}
