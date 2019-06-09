/* Pre-processor directives */
#include <stdlib.h> /* EXIT_SUCCESS  & EXIT_FAILURE */
#include <stdio.h> /* printf & scanf */

/* Globally defined function called main, the entry point to the program */
int main(void)
{
	/* Variables */
	int assignment1, assignment2, exam;
	float total;

	/* Data input */
	 printf("Enter 3 integers, press enter after each integer. These are the students score from assingment 1, 2, and the exam:\n");

	 /* %d means read in an integer and make sure 3 were entered */
	 /* &variableName means assign the data to that variable as & is the address operator */
	if (scanf("%d%d%d", &assignment1, &assignment2, &exam) != 3) {
		printf("Unable to find 3 integers from stdin.\n");

		/* Return the O/S` failure int number. */
		return EXIT_FAILURE;
	 }

	/* Calculate final mark */
	total =  (assignment1 * 0.2) + (assignment2 * 0.3) + (exam * 0.5);

	/* %3d means print out an integer with at least 3 spaces */
	printf("Assignment 1 score was: %3d\n", assignment1);
	printf("Assignment 2 score was: %3d\n", assignment2);
	printf("Exam score was: %3d\n", exam);
	/* %6.2f means print out a float with at least 6 spaces and 2 decimal places */
	printf("Total score was: %6.2f\n", total);

	/* Return the O/S` successful int number. */
	return EXIT_SUCCESS;
}

