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

	printf("\n# Selection Statements\n## if Statement\n");
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

	printf("## Switch Statement\n");
	switch(code) {
		case 4:
		printf("You passed and got a high distinction.\n");
		break;

		case 3:
		printf("You passed and got a distinction.\n");
		break;
	
		case 2:
		printf("You passed and got a credit.\n");
		break;
	
		case 1:
		printf("You passed.\n");
		break;
	
		case 0:
		printf("You failed.\n");
		break;
	
		default:
		printf("Invalid entry.\n");
	}

	return 0;
}	
