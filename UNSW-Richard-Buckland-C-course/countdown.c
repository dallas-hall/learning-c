#include <stdio.h> // Has printf and scanf in it
#include <stdlib.h> // Has EXIT_SUCCESS in it

// Constants
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOURS 60 
#define SECONDS_IN_MINUTES 60
#define MINUTES_IN_DAY (HOURS_IN_DAY * MINUTES_IN_HOURS)
#define SECONDS_IN_DAY (HOURS_IN_DAY * MINUTES_IN_HOURS * SECONDS_IN_MINUTES)

// Function prototyes
int daysToHours(int days);
int daysToMinutes(int days);
int daysToSeconds(int days);

// Functions
int main(int argc, char *argv[])
{
	int days, hours, minutes, seconds;
	
	printf("Enter the amount of days as an integer.\n");
	scanf("%d", &days);

	hours = daysToHours(days);
	minutes = daysToMinutes(days);
	seconds = daysToSeconds(days);
	
	printf("There are %d hours, %d minutes, and %d seconds in %d day(s).\n", hours, minutes, seconds, days);

	return EXIT_SUCCESS;
}

int daysToHours(int days)
{
	return (days * HOURS_IN_DAY);
}

int daysToMinutes(int days)
{
	return days * (MINUTES_IN_DAY);
}

int daysToSeconds(int days)
{
	return days * (SECONDS_IN_DAY);	
}
