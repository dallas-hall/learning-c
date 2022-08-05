#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;
	unsigned d, e, f;
	
	puts("# scanf Integer Format Specifiers");
	puts("Enter 3 signed integers: ");
	/*
	 * %d integer
	 * %i any integer, including octal and hex
	 * %u is unsigned
	 * %o is octal
	 * %x is hex
	 */ 
	scanf("%d%i%i", &a, &b, &c);
	puts("Enter 3 unsigned integers: ");
	scanf("%u%o%x", &d, &e, &f);
	printf("In base 10 you entered: %d %d %d %d %d %d\n", a, b, c, d, e, f);

	return EXIT_SUCCESS;
}
