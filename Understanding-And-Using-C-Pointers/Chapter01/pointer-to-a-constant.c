#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 2;
	const int limit = 32;
	/*
	 * Integer pointer
	 */ 
	int* iPtr = &num;
	/*
	 * Constant integer pointer
	 * The pointer cannot be used to modify the value its referencing.
	 * We can update the address of the pointer though.
	 */ 
	const int* iPtrConst = &limit;

	puts("# Pointers To A Constant");
	puts("## Accessing Pointers");
	/*
	 * Cast to (void*) is needed to silence compiler warning.
	 */ 
	printf("The address of num is %p\n", (void*) &num);
	printf("The value of num is %d\n", num);
	printf("The address of iPtr is %p\n", (void*) &iPtr);
	printf("The address iPtr points to is %p\n", (void*) iPtr);
	printf("The value iPtr points to is %d\n", *iPtr);
	
	/*
	 * Adding const is needed to silence compiler warning.
	 */ 
	printf("The address of limit is %p\n", (const void*) &limit);
	printf("The value of limit is %d\n", limit);
	printf("The address of iPtrConst is %p\n", (void*) &iPtrConst);
	printf("The address iPtrConst points to is %p\n", (const void*)iPtrConst);
	printf("The value iPtrConst points to is %d\n", *iPtrConst);

	puts("\n## Updating const Pointer Address");
	puts("iPtrConst = iPtr;");
	/*
	 * Even though iPtr is not a const that is okay.
	 */ 
	iPtrConst = iPtr;
	printf("The address of iPtrConst is %p\n", (void*) &iPtrConst);
	printf("The address iPtrConst points to is %p\n", (const void*)iPtrConst);
	printf("The value iPtrConst points to is %d\n", *iPtrConst);

	puts("\n## Updating const Pointer Value Via Proxy");
	puts("num *= num;");
	num *= num;
	printf("The address of num is %p\n", (void*) &num);
	printf("The value of num is %d\n", num);
	printf("The address of iPtrConst is %p\n", (void*) &iPtrConst);
	printf("The address iPtrConst points to is %p\n", (const void*)iPtrConst);
	printf("The value iPtrConst points to is %d\n", *iPtrConst);

	return EXIT_SUCCESS;
}
