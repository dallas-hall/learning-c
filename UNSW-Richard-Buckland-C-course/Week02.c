/*
 * Week 2 demo code.
 *
 * author: blindcant
 * date: 26-03-2019
 *
 */

// Tell the compiler to include this file at this point in the source code. This is a way to import libraries and their code.
#include <stdio.h>
// This means the copmiler rewrites the constant with the value
#define LENGTH 2
#define WIDTH 4

//The main function is called by the operating system. It should return at int to the O/S to tell it if the program was successful or not. 0 = successful.
int main(int argc, char *argv[])
{
	int input;
	int dollars;
	int integerDivision;

	// Print formatted data
	printf("How many dollars do you have?\n");
	
	// Read in the user input
	scanf("%d", &input);
	
	dollars = (input) / 2;
	// When integer division is performed on an odd number, the decimal is component is thrown away. This is essentially division with remainders and ignoring the remainder.
	integerDivision = input % 2;

	printf("Integer division: %d / 2 is $%d.\n", input, dollars);
	// Notice the double % to type a literal %
	printf("Integer modulo: %d %% 2 is $%d.\n", input, integerDivision);
	printf("The constant LENGTH is %d\nThe constant WIDTH is %d\n", LENGTH, WIDTH);
	int area = LENGTH * WIDTH;
	printf("The area of %d * %d is %d\n", LENGTH, WIDTH, area);
	return 0;
}
