#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	puts("# Escape Characters");
	printf("\\\' for a \' (single quote)\n");
	printf("\\\" for a \" (double quote)\n");
	printf("\\\\? for a \\? (quesiton mark)\n");
	printf("\\\\ for a \\ (backslash)\n");
	printf("\\\\v for a \\v (vertical tab)\n");
	printf("\\\\t for a \\t (horizontal tab)\n");
	printf("\\\\n for a \\n (newline)\n");
	printf("\\\\r for a \\r (carriage return)\n");
	
	return EXIT_SUCCESS;
}
