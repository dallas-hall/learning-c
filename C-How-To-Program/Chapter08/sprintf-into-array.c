#include <stdio.h>
#include <stdlib.h>

#define BUFFER 80

int main(void)
{
	char string[BUFFER];
	int i;
	double d;

	puts("# Storing Formatted Data Into An Array - sprintf");
	puts("## Get Values\nEnter an integer: ");
	scanf("%d", &i);
	puts("Enter a double: ");
	scanf("%lf", &d);

	puts("\n## Storing Formatted Data");
	sprintf(string, "Integer: %d\nDouble: %f", i, d);
	puts("The formatted data stored into the array was:");
	puts(string);
	return EXIT_SUCCESS;
}
