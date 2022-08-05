#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int grade, aCount, bCount, cCount, dCount, eCount, fCount;
	aCount = 0;
	bCount = 0;
	cCount = 0;
	dCount = 0;
	eCount = 0;
	fCount = 0;

	printf("Enter the grade letter for each student.\n");
	printf("Press ^D (control + d) to exit.\n");

	while ( EOF != (grade =  getchar()) ) {
		switch (grade) {
			case 'A':
			case 'a':
				++aCount;
				break;
			case 'B':
			case 'b':
				++bCount;
				break;
			case 'C':
			case 'c':
				++cCount;
				break;
			case 'D':
			case 'd':
				++dCount;
				break;
			case 'E':
			case 'e':
				++eCount;
				break;
			case 'F':
			case 'f':
				++fCount;
				break;
			case '\t':
			case ' ':
			case '\n':
				break;
			default:
				printf("Invalid input, try again.\n");
		}
	}

	printf("# Totals for each grade\n");
	printf("A:\t%d\n", aCount);
	printf("B:\t%d\n", bCount);
	printf("C:\t%d\n", cCount);
	printf("D:\t%d\n", dCount);
	printf("E:\t%d\n", eCount);
	printf("F:\t%d\n", fCount);

	return EXIT_SUCCESS;
}
