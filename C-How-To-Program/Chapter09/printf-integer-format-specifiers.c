#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	puts("# printf Integer Format Specifiers");
	puts("## Signed Integers");

	puts("### Short Integers");
	printf("%%hd 32000 is %hd\n", 32000);

	puts("\n### Integers");
	printf("%%d 255 is %d\n", 255);
	printf("%%i 255 is %i\n", 255);
	printf("%%d +255 is %d\n", +255);
	printf("%%d -255 is %d\n", -255);
	
	puts("\n### Long Integers");
	printf("%%ld 2000000000L is %ld\n", 2000000000L);

	puts("\n## Unsigned Integers");
	puts("### Short Integers");
	printf("%%hu 32000 is %hu\n", 32000);
	puts("\n### Integers");
	printf("%%u 255 is %u\n", 255);
	printf("%%u -255 is %u\n", -255);
	printf("%%u +255 is %u\n", +255);
	puts("\n### Long Integers");
	printf("%%lu 2000000000L is %lu\n", 2000000000L);

	puts("\n## Octal Intgers");
	printf("%%o 255 is %o\n", 255);

	puts("\n## Hexadecimal Intgers");
	printf("%%x 255 is %x\n", 255);
	printf("%%X 255 is %X\n", 255);

	return EXIT_SUCCESS;
}
