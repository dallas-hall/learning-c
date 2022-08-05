#include <stdlib.h>
#include <stdio.h>

/*
 * Declare a stucture that has 2 members.
 * Both members have a char point, which is a pointer to a char of any size. If this is null terminated it is a string
 */ 
struct card {
	char *face;
	char *suit;
};

int main(void)
{
	/*
	 * Create a variable that can hold a struct of card data type.
	 */ 
	struct card aCard;
	/*
	 * Create a variable that can hold a pointer to a struct of card data type.
	 */ 
	struct card *aCardPointer;

	/*
	 * Add data to the struct of card members (fields).
	 */ 
	aCard.face = "Ace";
	aCard.suit = "Spades";

	/*
	 * Assign the memory address of aCard to the pointer
	 */
	aCardPointer = &aCard;

	/*
	 * Directly access the variable and the value of the member.
	 */ 
	puts("# Structure Example - Playing Card");
	puts("## Struct Member Access - Dot Operator (strucIdentifier.memberIdentifier)");
	printf("The value of aCard.face is %s\n", aCard.face);
	printf("The value of aCard.suit is %s\n", aCard.suit);

	/*
	 * Indirectly access the variable via the memory address the pointer is pointing to, and access the value of the member.
	 */ 
	puts("\n## Struct Member Access - Pointer Operator (structPointer->memberIdentifier)");
	printf("The value of aCardPointer->face is %s\n", aCardPointer->face);
	printf("The value of aCardPointer->suit is %s\n", aCardPointer->suit);

	/*
	 * Dereference (*) the pointer and directly access the value of its member.
	 * The () are needed because . has a higher precedence than &
	 */ 
	puts("\n## Struct Member Access - Pointer Operator (*structPointer).memberIdentifier");
	printf("The value of (*aCardPointer).face is %s\n", (*aCardPointer).face);
	printf("The value of (*aCardPointer).suit is %s\n", (*aCardPointer).suit);


	return EXIT_SUCCESS;
}
