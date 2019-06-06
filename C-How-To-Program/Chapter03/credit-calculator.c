#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int input, accountNumber;
	float balance, charges, credits, creditLimit;

	while(1) {
		printf("Enter account number or -1 to exit: ");
		scanf("%d", &input);
		if (input == -1) {
			break;
		}
		else {
			accountNumber = input;
			printf("Enter opening balance: ");
			scanf("%f", &balance);
			printf("Enter total charges: ");
			scanf("%f", &charges);
			printf("Enter total credits: ");
			scanf("%f", &credits);
			printf("Enter credit limit: ");
			scanf("%f", &creditLimit);
		
			balance = balance + charges - credits;
			if (balance > creditLimit) {
				printf("Account: %d\n", accountNumber);
				printf("Balance: %.2f\n", balance);
				printf("Credit limit: %.2f\n", creditLimit);
				printf("Credit limit exceeded.\n");
			}
			
		}
	}

	return EXIT_SUCCESS;
}
