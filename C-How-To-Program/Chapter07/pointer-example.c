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
	printf("%-35s%p\n", "The address of n via &n is ", (void*) &n);
	printf("%-35s%p\n", "The direct value of nPointer is ", (void*) nPointer);
	printf("%-35s%p\n", "The address of m via &m is ", (void*) &m);
	printf("%-35s%p\n", "The direct value of mPointer is ", (void*) mPointer);

	printf("\n# Memory Values\n");
	/* The star here returns the value that is being pointed to. This is called dereferrncing a pointer. */
	printf("%-48s%d\n", "The direct value of n is ", n);
	printf("%-48s%d\n", "The indirect value of nPointer via *nPointer is ", *nPointer);
	printf("%-48s%d\n", "TThe direct value of m is ", m);
	printf("%-48s%d\n", "The indirect value of mPointer via *mPointer is ", *mPointer);

	printf("\n# Pointer Memory Address\n");
	printf("&*nPointer = %p\n*&nPointer = %p\n&*mPointer = %p\n*&mPointer = %p\n",
		   (void*) &*nPointer, (void*) *&nPointer, (void*) &*nPointer, (void*) *&nPointer);
	printf("\nThis shows that * and & are complements of each other. I prefer &*var as left to right it means 'get the address of the pointer var'.\n");

	return EXIT_SUCCESS;
}
