#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	struct customer {
		char lastName[ 15 ];
		char firstName[ 15 ];
		int customerNumber;
		struct {
			char phoneNumber[ 11 ];
			char address[ 50 ];
			char city[ 15 ];
			char state[ 3 ];
			char zipCode[ 6 ];
		} personal;
	} customerRecord, *customerPtr;

	customerPtr = &customerRecord;

	strcpy(customerRecord.firstName, "Jamie");
	strcpy(customerPtr->lastName, "Jones");
	customerRecord.customerNumber = 1;
	strcpy(customerRecord.personal.phoneNumber, "111-222-333");
	strcpy(customerPtr->personal.address, "1 Smith Street");
	strcpy(customerRecord.personal.city, "Popular City");
	strcpy(customerPtr->personal.state, "ABC");
	strcpy(customerRecord.personal.zipCode, "123456");

	printf("customerRecord.firstName is %s\n", customerRecord.firstName);
	printf("customerPtr->lastName is %s\n", customerPtr->lastName);
	printf("customerRecord.customerNumber is %d\n", customerRecord.customerNumber);
	printf("customerPtr->lastName is %s\n", customerPtr->lastName);
	printf("customerRecord.personal.phoneNumber is %s\n", customerRecord.personal.phoneNumber);
	printf("customerPtr->personal.address is %s\n", customerPtr->personal.address);
	printf("customerRecord.personal.city is %s\n", customerRecord.personal.city);
	printf("customerPtr->personal.state is %s\n", customerPtr->personal.state);
	printf("customerRecord.personal.zipCode is %s\n", customerRecord.personal.zipCode);

	return EXIT_SUCCESS;
}
