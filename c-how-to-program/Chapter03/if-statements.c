#include <stdio.h>

int main(void)
{
	int result = 0;
	int code = 0;
	int debugging = 1; // 0 to turn off

	printf("Enter the student's score:\n");
	scanf("%d", &result);

	if (debugging) {
		printf("Score is: %d\n", result);
	}

	printf("\n# If Selection Statements\n## if Statement\n");
	if (result >= 50) {
		printf("You passed.\n");
	}

	if (result < 50) {
		printf("You failed.\n");
	}

	printf("\n## if else Statement\n");
	if (result >= 50) {
		printf("You passed.\n");
	}
	else {
		printf("You failed.\n");
	}

	printf("\n## else if Statement\n");
	if (result >= 80) {
		printf("You passed and got a high distinction.\n");
		code = 4;
	}
	else if (result >= 70) {
		printf("You passed and got a distinction.\n");
		code = 3;
	}
	else if (result >= 60) {
		printf("You passed and got a credit.\n");
		code = 2;
	}
	else if (result >= 50) {
		printf("You passed.\n");
		code = 1;
	} else {
		printf("You failed.\n");
	}

	printf("\n## Tenary Conditional Operator Statement\n");
    printf("%s\n", result >= 50 ? "You passed.\n" : "You failed.\n");

	return 0;
}	
