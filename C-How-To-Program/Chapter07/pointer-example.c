#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	/*
	 * The * here means to define a pointer.
	 */
	int* nPointer;
	int* mPointer;

	printf("# Intger Pointer Example\nEnter an integer: ");
	/*
	 * The & returns the memory address of its operand.
	 * scanf is taking an integer and storing it in the memory location of n.
	 * nPointer is taking the memory location of n and storing it.
	 */
	scanf("%d", &n);
	m = n * 2;
	nPointer = &n;
	mPointer = &m;

	printf("\n# Memory Address\n");
	/*
	 * %p is used to print the memory address in hex
	 * Need to cast with (void*) as this is happening implicitly. The compiler is warning without this.
	 */
	printf("The address of n is %p\nThe direct value of nPointer is %p\n", (void*) &n, (void*) nPointer);
	printf("The address of m is %p\nThe direct value of mPointer is %p\n", (void*) &m, (void*) mPointer);

	printf("\n# Memory Values\n");
	/* The star here returns the value that is being pointed to. This is called dereferrncing a pointer. */
	printf("The direct value of n is %d\nThe indirect (i.e. dereferenced) value of nPointer is %d\n", n, *nPointer);
	printf("The direct value of m is %d\nThe indirect (i.e. dereferenced)  value of mPointer is %d\n", m, *mPointer);

	printf("\nThis shows that * and & are complements of each other.\n");
	printf("&*nPointer = %p\n*&nPointer = %p\n&*mPointer = %p\n*&mPointer = %p\n",
		   (void*) &*nPointer, (void*) *&nPointer, (void*) &*nPointer, (void*) *&nPointer);

	return EXIT_SUCCESS;
}
