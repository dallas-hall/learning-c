#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define NAME_LEN 40
#define ACCOUNT_NUM_LEN 10
/*
 * Powers of 2 is a good idea.
 */ 
#define STARTING_SIZE 16
#define SIZE_MULTIPLIER 2

typedef enum {
	FALSE,
	TRUE
} BOOLEAN;

struct money {
	int dollars;
	char cents;
};

struct account {
	char name[NAME_LEN + 1];
	char accountNumber[ACCOUNT_NUM_LEN + 1];
	struct money balance;
};
 
/*
 * Will preallocate accounts, and double the list once the amount is exhausted.
 */ 
struct accountsList {
	struct account *accounts;
	int numberOfAccountsAllocated;
	int numberOfAccountsUsed;
};

/*
 * The struct would return NULL if it failed.
 * Using the pointer as a parameter means the list has already been created.
 */ 
struct accountsList* createAccountsList(void); 
void initialiseAccountsList(struct accountsList*);
/*
 * Need to use pass the pointer so we can directly manipulate the list.
 * Without using a pointer, we pass a copy and we only update the copy. 
 *
 * Use a pointer to somewhere else on the stack, so we avoid making a copy.
 *
 * We aren't using parameter names here.
 */ 
BOOLEAN addAccount(struct accountsList*, struct account*);
/*
 * Using const as we don't need to update the account.
 */ 
BOOLEAN removeAccount(struct accountsList*, const char[]);
struct account* getAccount(struct accountsList*, const char[]);
/*
 * free turns void, which is nothing. This isn't a void pointer.
 *
 * Calling free twice will crash the program. There is no way to detect when memory allocation fails.
 */ 
BOOLEAN destoryAccountList(struct accountsList*);

int main(void)
{
	puts("# Bank Account - Dynamic Array List");

	return EXIT_SUCCESS;
}

struct accountsList* createAccountsList(void)
{
	/*
	 * Need to cast because of the void * pointer.
	 */ 
	struct accountsList* newList = (struct accountsList*) malloc(sizeof(struct accountsList));

	/*
	 * malloc failed.
	 */
	if(!newList) {
		return NULL;
	}

	initialiseAccountsList(newList);
	return newList;
}

void initialiseAccountsList(struct accountsList* theList)
{
	/*
	 * memset initialises every byte to whatever you want.
	 *
	 * Use sizeof with the struct accountsList so we get the exact size.
	 */
	memset(theList, 0, sizeof(struct accountsList));
}

BOOLEAN addAccount(struct accountsList* theList, struct account* newAccount)
{
	int desiredNumberOfAccounts;
	void* newList;

	if(theList->numberOfAccountsAllocated == 0) {
		theList->accounts = (struct account*) malloc(sizeof(struct account) * STARTING_SIZE);
		/*
		 * malloc failed.
		 */ 
		if(!theList->accounts) {
			return FALSE;
		}
		theList->numberOfAccountsAllocated = STARTING_SIZE;
	}
	
	if(theList->numberOfAccountsUsed == theList->numberOfAccountsAllocated) {
		/*
		 * The list is full.
		 */ 
		if(((long) theList->numberOfAccountsAllocated) * SIZE_MULTIPLIER > INT_MAX) {
			return FALSE;
		}
		desiredNumberOfAccounts = theList->numberOfAccountsAllocated * SIZE_MULTIPLIER;
		/*
		 * Use realloc to resize the memory.
		 *
		 * Returns a void * and it will return NULL if it fails.
		 * Without storing the old memory address, we would lose all the data.
		 *
		 * If realloc succeeds, all old pointers are invalid.
		 */ 
		newList = realloc(theList->accounts, desiredNumberOfAccounts);
		if(!newList) {
			return FALSE;
		}

		/*
		 * Update to the newly created pointer.
		 */ 
		theList->accounts = (struct account*) newList;
		theList->numberOfAccountsAllocated = desiredNumberOfAccounts;
	}
	
	/*
	 * Dereferences the newAccount pointer, which is making a copy of the the account that was pointed to by the pointer.
	 */ 
	theList->accounts[theList->numberOfAccountsUsed++] = *newAccount;
	

	return TRUE;
}

/*
BOOLEAN removeAccount(struct accountsList* theList, const char[] accountNumber)
{
	
}

struct account* getAccount(struct accountsList* theList, const char[] accountNumber)
{
	
}
*/

BOOLEAN destoryAccountList(struct accountsList* theList)
{
	/*
	 * Delete all accounts.
	 */ 
	free(theList->accounts);
	numberOfAccountsUsed = 0;
}

