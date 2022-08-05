#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * A self referential structure, which is what stacks are
 */
struct treeNode {
	char data;
	struct treeNode *leftTreeNodePtr;
	struct treeNode *rightTreeNodePtr;
};

/*
 * Create some synonyms.
 * 1) For the struct treeNode
 * 2) For the pointer to the struct treeNode
 */
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertTreeNode(TreeNodePtr *treePtr, char c);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void printMenu(void);
void populateTree(TreeNodePtr *treePtr);

int main(void)
{
	int done = 0;
	char c;
	/*
	 * The binary search tree will start out empty.
	 * NULL is the end of the nodes.
	 */
	TreeNodePtr rootPtr = NULL;
	puts("# Binary Search Tree Example");

	/*
	 * Put some capital letters into the tree
	 * Pass the address of the pointer so we can directly manipulate it.
	 */
	populateTree(&rootPtr);

	do {
		printMenu();
		scanf("\n%c", &c);

		switch (c) {
			case '1':
				preOrder(rootPtr);
				break;
			case '2':
				inOrder(rootPtr);
				break;
			case '3':
				postOrder(rootPtr);
				break;
			case '4':
				done = 1;
				break;
			default:
				puts("Invalid input.");
				break;
		}
	}
	while (!done);

	puts("Program exiting.");
	return EXIT_SUCCESS;
}

void insertTreeNode(TreeNodePtr *treePtr, char c)
{
	if(*treePtr == NULL) {
		/*
		 * mallac tries to allocate memory with the specified bytes.
	 	 * sizeof will return the size of the data structure, platform dependent.
	 	 * If successful, malloc returns a void * to the allocated memory, otherwise returns NULL
	 	 */
		*treePtr = malloc(sizeof(TreeNode));

		if(*treePtr != NULL) {
			/*
			 * The root (first) node of the tree becomes the middle value.
		 	 */
			(*treePtr)->data = c;
			(*treePtr)->leftTreeNodePtr = NULL;
			(*treePtr)->rightTreeNodePtr = NULL;
		}
		else {
			fprintf(stderr, "%c couldn't be added to the binary search tree. No memory available.\n", c);
		}
	}
	else {
		/*
		 * Values smaller than the root node are added to the left hand side of the tree
		 */
		if(c < (*treePtr)-> data) {
			/*
			 * Recursively call insertTreeNode with the address of leftTreeNode pointer, so we can insert it there.
			 */ 
			insertTreeNode(&((*treePtr)->leftTreeNodePtr), c);
		}
		/*
		 * Values larger than the root node are added to the right hand side of the tree
		 */
		else if(c > (*treePtr)-> data) {
			/*
			 * Recursively call insertTreeNode with the address of rightTreeNode pointer, so we can insert it there.
			 */ 
	
			insertTreeNode(&((*treePtr)->rightTreeNodePtr), c);
		}
		else {
			puts("Duplicate values aren't inserted into the tree.");
		}
	}
}

/*
 * Print in ascending order.
 * 1) Left nodes and children first (lowest)
 * 2) Middle (root) node
 * 3) Right nodes and children last (highest)
 */ 
void inOrder(TreeNodePtr treePtr)
{
	if(treePtr != NULL) {
		inOrder(treePtr->leftTreeNodePtr);
		printf("%c ", treePtr->data);
		inOrder(treePtr->rightTreeNodePtr);
	}
}

/*
 * Print the value of each node as its visited.
 * 1) Root
 * 2) left child
 * 3) Right child
 * 4) Repeat 1 to 3 for all nodes.
 */ 
void preOrder(TreeNodePtr treePtr)
{
	if(treePtr != NULL) {
		printf("%c ", treePtr->data);
		preOrder(treePtr->leftTreeNodePtr);
		preOrder(treePtr->rightTreeNodePtr);
	}
}

/*
 * Print children node values first.
 * 1) All left node children then left nodes
 * 2) All right node children then right nodes
 * 3) Middle (root) value
 */ 
void postOrder(TreeNodePtr treePtr)
{
	if(treePtr != NULL) {
		preOrder(treePtr->leftTreeNodePtr);
		preOrder(treePtr->rightTreeNodePtr);
		printf("%c ", treePtr->data);
	}
}

void printMenu(void)
{
	puts("\n## Binary Search Tree Example Menu");
	puts("Choose from the following options:");
	puts("1) to pre-order traverse the binary search tree.");
	puts("2) to in-order traverse the binary search tree.");
	puts("3) to post-order traverse the binary search tree.");
	puts("4) to quit.");
	printf("Enter the number for yor choice: ");
}

void populateTree(TreeNodePtr *treePtr)
{
	int i;
	char c;

	puts("## Populating Binary Search Tree");

	for(i = 0; i < 10; i++) {
		c = 65 + rand() % 25;
		printf("%c\n", c);
		insertTreeNode(treePtr, c);
	}
}
