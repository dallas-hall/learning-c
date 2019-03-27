/*
 * Demo code written in lecture 4 week 1 comp191 
 * by: blindcant
 * date: 26-03-2019
 */

/*
 * Lines beginning with # are instructions to the compiler.
 * The compiler will find this library file and insert it into this point. Saves you typing out all of the code in that file.
 */
#include <stdio.h>

// This line will be explained in week 3
int main(int argc, char *argv[])
{
	// Use a variable to store the value
	int numberOfChickens = 0;

	/*
	 * printf means formatted printing
	 * Remember to put \n on every line to advance the newline
	 */
	printf("How many chickens do I have?\n");

	/*
	 * scanf means read in formatted input
	 * %d is a base10 number
	 * But C will silently convert types which may or may not give intended results. The Ariane 5 space rocket disaster was caused by this. https://en.wikipedia.org/wiki/Ariane_5 & https://blog.bugsnag.com/bug-day-ariane-5-disaster/
	 */ 
	scanf("%d", &numberOfChickens);
	printf("I have %d chickens\n", numberOfChickens);

	if (numberOfChickens == 0) {
		printf("DING!\n");
	} else {
		printf("DONG!\n");
	}
	return 0;
}
