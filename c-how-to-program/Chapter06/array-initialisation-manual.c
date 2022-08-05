#include <stdio.h>
#include <stdlib.h>

#define INT_ARRAY_LIMIT 10

int main(void)
{
	int intArray[INT_ARRAY_LIMIT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	/* This will automatically initialise all elements to 0 */
	int intArray2[INT_ARRAY_LIMIT] = {1};

	printf("# Manual Array Initialisation and Declaration.\n## Manually Declared\n");
	printf("%s%13s\n", "Element", "Value");
	// C99 and beyond allows variables to be delcared in the code.
	for (size_t i = 0; i < INT_ARRAY_LIMIT; i++) {
		printf("%7lu%13d\n", i, intArray[i]);
	}
		
	printf("\n## Manually Declared First Element & Automatically Assigned Remainder Elements\n%s%13s\n", "Element", "Value");
	for (size_t i = 0; i < INT_ARRAY_LIMIT; i++) {
		printf("%7lu%13d\n", i, intArray2[i]);
	}
	
	return EXIT_SUCCESS;
}
