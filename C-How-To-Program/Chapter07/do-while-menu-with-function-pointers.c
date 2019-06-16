#include <stdio.h>
#include <stdlib.h>

#define MENU_SIZE 3

void function1(int n);
void function2(int n);
void function3(int n);

int main(void)
{
	/*
	 * Initialise an array of 3 pointers to functions.
	 * Each take an integer argument and return void.
	 */
	void (*functionPointers[MENU_SIZE])(int) = {function1, function2, function3};

	int choice;
	printf("# Text Menu Driven By Function Pointers\n");

	do {
		printf("\n## Menu Options\n");
		printf("1) Print a \"Hello World\"\n");
		printf("2) Print 2 ^ 0 to 2 ^ 8\n");
		printf("3) Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		if(choice == 1) {
			/*
			 * Choose the function the corresponds to the number entered.
			 * Remember - 1 for arrays starting at 0
			 * Pass the int parameter.
			 */ 
			(*functionPointers[choice - 1])(choice);
		}
		else if(choice == 2) {
			(*functionPointers[choice - 1])(choice);
		}
		else if(choice == 3) {
			(*functionPointers[choice - 1])(choice);
			break;
		}
	
	} while (1);

	return EXIT_SUCCESS;
}

void function1(int n)
{
	printf("\n### Menu Option %d\n", n);
	printf("Hello World\n");
	printf("Returning to menu.\n");
}

void function2(int n)
{
	int i, j, result;
	
	printf("\n### Menu Option %d\n", n);
	for(i = 0; i <=8; i++)
	{
		if(i == 0) {
			printf("2 ^ %d is %d\n", i, 1);
		} else if (i == 1) {
			printf("2 ^ %d is %d\n", i, 2);
		}
		else if (i == 2) {
			printf("2 ^ %d is %d\n", i, 2 * 2);
		}
		else {
			result = 2;
			/*
			 * Remember - 1 here for the correct answer.
			 */ 
			for(j = 0; j < i - 1; j++) {
				result *= 2;
			}
			printf("2 ^ %d is %d\n", i, result);
		}
	}
	printf("Returning to menu.\n");
}

void function3(int n)
{
	printf("\n### Menu Option %d\n", n);
	printf("Exiting the program.\n");
}
