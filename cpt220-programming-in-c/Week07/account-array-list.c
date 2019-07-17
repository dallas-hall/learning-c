#include <stdlib.h>
#include <stdio.h>

#define NAME_LEN 40
#define ACCOUNT_NUM_LEN 10

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
/*struct accountsList* createAccount(void); */
BOOLEAN createAccountList(struct accountsList*);
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
 */ 
BOOLEAN destoryAccountList(struct accountsList*);

int main(void)
{

	return EXIT_SUCCESS;
}
