#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * Normal integer, we can update this value if we like.
	 */ 
	int i = 2;
	/*
	 * Constant integer, we can never update this value. It is read only.
	 */ 
	const int iConst = 32;
	/*
	 * Non-constant integer pointer.
	 */ 
	int* iPtr = &i;
	/*
	 * Constant integer pointer.
	 *
	 * Can update the address of the constant pointer.
	 * We can't update this value unless we assign a non-constant type to it, and only through updating the type directly. Not through the pointer.
	 */ 
	const int* iPtrConst = &i;

	puts("# Pointers And Constants");
	puts("## Non-Constant Pointer To A Non-Constant Type");
	/*
	 * Cast to (void*) is needed to silence compiler warning.
	 */ 
	printf("The address of i is %p\n", (void*) &i);
	printf("The value of i is %d\n", i);
	printf("The address of iPtr is %p\n", (void*) &iPtr);
	printf("The address iPtr points to is %p\n", (void*) iPtr);
	printf("The value iPtr points to is %d\n", *iPtr);

	puts("\n## Constant Pointer To A Non-Constant Type");
	puts("iPtrConst = &i;");
	iPtrConst = &i;
	printf("The address of i is %p\n", (void*) &i);
	printf("The value of i is %d\n", i);
	printf("The address of iPtrConst is %p\n", (const void*) &iPtrConst);
	printf("The address iPtrConst points to is %p\n", (const void*) iPtrConst);
	printf("The value iPtrConst points to is %d\n", *iPtrConst);
	puts("Updating the non-constant type even though it has a constant pointer.\ni *= i;");
	i *= i;
	printf("The address of i is %p\n", (void*) &i);
	printf("The value of i is %d\n", i);
	printf("The address of iPtrConst is %p\n", (const void*) &iPtrConst);
	printf("The address iPtrConst points to is %p\n", (const void*) iPtrConst);
	printf("The value iPtrConst points to is %d\n", *iPtrConst);
	
	puts("\n## Constant Pointer To A Constant Type");
	puts("Updating the constant pointer's address.\niPtrConst = &iConst;");
	iPtrConst = &iConst;
	printf("The address of iConst is %p\n", (const void*) &iConst);
	printf("The value of iConst is %d\n", iConst);
	printf("The address of iPtrConst is %p\n", (const void*) &iPtrConst);
	printf("The address iPtrConst points to is %p\n", (const void*) iPtrConst);
	printf("The value iPtrConst points to is %d\n", *iPtrConst);

	return EXIT_SUCCESS;
}
