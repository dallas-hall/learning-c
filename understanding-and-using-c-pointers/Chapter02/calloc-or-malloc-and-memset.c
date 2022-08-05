#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char* callocPtr;
	char* mallocPtr;

	puts("# calloc Vs Malloc");
	puts("## calloc - Allocates And Zereos Memory");

	/*
	 * + 1 needed for the null terminator.
	 * The result is the product of both arguments, so 1 x sizeof("calloc0")
	 */ 
	callocPtr = calloc(1, sizeof(strlen("calloc") + 1));
	if(!callocPtr) {
		perror("calloc");
	}
	printf("Before allocation, callocPtr is '%s'\n", callocPtr);
	strcpy(callocPtr, "calloc");
	printf("After allocation, callocPtr is '%s'\n", callocPtr);

	puts("## malloc - Allocates Memory And Does Nothing To It");
	
	mallocPtr = malloc(sizeof(strlen("malloc") + 1));
	if(!mallocPtr) {
		perror("malloc");
	}

	printf("I like to live dangerously. Before allocation, mallocPtr is '%s'\n", mallocPtr);
	
	memset(mallocPtr, 0, sizeof(strlen("malloc") + 1));
	printf("After memset, mallocPtr is '%s'\n", mallocPtr);
	
	strcpy(mallocPtr, "malloc");
	printf("After allocation, mallocPtr is '%s'\n", mallocPtr);

	return EXIT_SUCCESS;
}
