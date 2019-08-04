#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* names[] = {"Miller", "Jones", "Anderson"};
	
	puts("# Compact Expression Example");

	/*
	 * Print the third letter of the second element
	 */ 
	printf("%c\n", *(*(names+1)+2));
	printf("%c\n", names[1][2]);
	
	return EXIT_SUCCESS;
}
