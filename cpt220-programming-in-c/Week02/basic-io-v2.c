/* Pre-processor directives */
#include <stdlib.h> /* EXIT_SUCCESS  & EXIT_FAILURE */
#include <stdio.h> /* printf & scanf */

/* Symbolic constants  - use these to avoid magic numbers */
#define ASSIGNMENT1_WORTH 20
#define ASSIGNMENT2_WORTH 30
#define EXAM_WORTH 50
#define ASSESSMENT_TOTAL_MARKS 100

/* Globally defined function called main, the entry point to the program */
int main(void)
{
	/* Declare variables */
	int assignment1, assignment2, exam, studentCount;
	float total;
	char grade;

	/* Initialise variables after declaration */
	assignment1 = 0;
	assignment2 = 0;
	exam = 0;
	studentCount = 0;
	total = 0.0;
	grade = '\0'; /* null control character */

	/* Initialise and declare variables at the same time - but ANIS C forbids this so we receive a warning */
	int assignment1Sum = 0;
	int assignment2Sum = 0;
	int examSum = 0;
	float totalSum = 0.0;

	/*Printing the table heading */
	printf("\n Line   Assignment Scores    Exam        Total\n"); /* \n is the new line character */
	printf("Number         1        2      Score       Score\n"); 
	printf("======    =================    ======      =====\n");

	/* Data input */
	 printf("Enter 3 integers, press enter after each integer or leave a space between all 3 on the same line.\nThese are the students score from assingment 1, 2, and the exam.\nType anything besides a number to quit: ");

	 /* %d means read in an integer and make sure 3 were entered */
	 /* &variableName means assign the data to that variable as & is the address operator */
	while (scanf("%d%d%d", &assignment1, &assignment2, &exam) == 3) {
		studentCount++;

		/* Calculate assessment marks using percentages from symbolic constants and not magic numbers */
		total = (float) assignment1 * ASSIGNMENT1_WORTH / ASSESSMENT_TOTAL_MARKS + 
			(float) assignment2 * ASSIGNMENT2_WORTH / ASSESSMENT_TOTAL_MARKS + 
			(float) exam * EXAM_WORTH / ASSESSMENT_TOTAL_MARKS;

		/* Assign grades base on total marks */
		if (total < 50.0) {
			grade = 'N';
		}
		else if (total < 60.0) {
			grade = 'P';
		}
		else if (total < 70.0) {
			grade = 'C';
		}
		else if (total < 80.0) {
			grade = 'D';
		}
		else {
			grade = 'H';
		}

		/* %3d means print out an integer with at least 3 spaces */
		/* %6.2f means print out a float with at least 6 spaces and 2 decimal places */
		/* %c means print out a char */
		printf("%d %3d %3d %3d %6.2f %c\n",
			studentCount,
			assignment1,
			assignment2,
			exam,
			total,
			grade);

		/* Update sums */
		assignment1Sum += assignment1;
		assignment2Sum += assignment2;
		examSum += exam;
		totalSum += total;
	}

   if ( studentCount == 0 ) 
      printf("\nNo input recieved from stdin.\n"); 
   else
   { 
      printf("         ================     =======     ======\n"); 
      printf("Averages:     %6.2f    %6.2f    %6.2f     %6.2f", 
      assignment1Sum / (float) studentCount, /*Using a float cast */
      assignment2Sum / (float) studentCount, 
      examSum / (float) studentCount, 
      totalSum / studentCount ); 
      printf("    Total no. of students = %d\n", studentCount);
   }

	/* Return the O/S` successful int number. */
	return EXIT_SUCCESS;
}

