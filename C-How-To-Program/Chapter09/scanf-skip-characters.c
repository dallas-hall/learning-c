#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int year, month, day;
	char delimiter;

	puts("# Skipping Any Character");
	puts("Enter a date (yyyy-mm-dd): ");
	/*
	 * %*c skips the character entered here.
	 */ 
	scanf("%d%c%d%*c%d", &year, &delimiter, &month, &day);
	printf("You entered %d%c%d%c%d\n", year, delimiter, month, delimiter, day);

	return EXIT_SUCCESS;
}
