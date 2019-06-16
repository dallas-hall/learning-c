#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char header[] = "ID\tNAME\tDEPT\n";
	char body[] = "1\tJOHN\tSALES\n2\tJANE\tACCOUNTING\n3\tJACK\tBOSSMAN\n";
	
	int id1;

	puts("# Getting Formatted Data Into An Array - scanf");
	puts("## Printing Array As Is");
	printf("%s", header);
	printf("%s", body);
	
	puts("\n## Printing Formatted Array - extracted IDs");
	/*
	 * Remember to use the address operator here.
	 */ 
	sscanf(body, "%d", &id1);
	printf("The first ID found was %d\n", id1);

	return EXIT_SUCCESS;
}
