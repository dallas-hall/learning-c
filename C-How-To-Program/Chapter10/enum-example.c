#include <stdio.h>
#include <stdlib.h>


enum monthsStartingAtZero {
	JAN, FEB, MAR, APR,
	MAY, JUN, JUL, AUG,
	SEP, OCT, NOV, DEC
};

enum monthsStartingAtOne {
	JAN1 = 1, FEB1, MAR1, APR1,
	MAY1, JUN1, JUL1, AUG1,
	SEP1, OCT1, NOV1, DEC1
};

const char *monthNames[] = {
	"January", "Februrary", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};

int main(void)
{
	enum monthsStartingAtZero month;
	enum monthsStartingAtOne month1;

	puts("# enum Example Using Months");
	puts("## Starting At 0");
	for (month = JAN; month <= DEC; month++) {
		printf("%2d has the value %-8s\n", month, monthNames[month]);
	}

	puts("\n## Starting At 1");
	for (month1 = JAN1; month1 <= DEC1; month1++) {
		printf("%2d has the value %-8s\n", month1, monthNames[month1 - 1]);
	}

	return EXIT_SUCCESS;
}
