#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_STRING "String on the heap in stackFrame2()"  

void stackFrame1(void);
void stackFrame2(void);

int main(void)
{
	char* stackString1 = "String on the stack in main()";
	puts("# Stack & Heap Conceptual Example");
	puts("## New Stack Frame Created - main()");

	printf("%s\n", stackString1);
	printf("The address of stackString1 is %p\n", (void*) &stackString1);
	printf("The address stackString1 points to is %p\n", (void*) stackString1);
	stackFrame1();


	puts("Popping main() off the stack.\nProgram returning to O/S.");
	return EXIT_SUCCESS;
}

void stackFrame1(void)
{
	char* stackString2 = "String on the stack in stackFrame1()";

	puts("\n## New Stack Frame Created - stackFrame1()");
	printf("%s\n", stackString2);
	printf("The address of stackString2 is %p\n", (void*) &stackString2);
	printf("The address stackString2 points to is %p\n", (void*) stackString2);
	stackFrame2();
	puts("Popping stackFrame1() off the stack.\nFunction returning to caller.\n");
}

void stackFrame2(void)
{
	char* heapStringPtr;

	puts("\n## New Stack Frame Created - stackFrame2()");
	
	/*
	 * + 1 for the null terminator
	 */ 
	heapStringPtr = malloc(sizeof(char) * strlen(HEAP_STRING) + 1);
	if(!heapStringPtr) {
		perror("malloc");
	}

	strcpy(heapStringPtr, HEAP_STRING);

	printf("%s\n", heapStringPtr);
	printf("The address of heapStringPtr is %p\n", (void*) &heapStringPtr);
	printf("The address heapStringPtr points to is %p\n", (void*) heapStringPtr);

	/*
	 * Code blocks have their own stack frames created.
	 */ 
	{
		puts("\n## New Stack Frame Created - code block inside stackFrame2()");

		int i = 2;
		printf("The address of i is %p\n", (void*) &i);
		puts("Popping code block inside stackFrame2() off the stack.\n");
	}

	puts("Popping stackFrame2() off the stack.\nFunction returning to caller.\n");
}


