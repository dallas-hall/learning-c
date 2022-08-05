#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	/* String literal plus the '\0' is stored. */
	char array[] = "Hello World!";

	printf("# Array Name Is Memory Location Example - variable called array\n");
	/*
	 * Remeber to cast &array to (void *), otherwise compiler implicitly does this.
	 */ 

	printf("array\t\t = %p\n&array\t\t = %p\n&array[0]\t = %p\n", (void *) array, (void *) &array, (void *) &array[0]);

	return EXIT_SUCCESS;
}
