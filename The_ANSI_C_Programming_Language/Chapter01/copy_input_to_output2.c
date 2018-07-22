#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("Press ctrl+D to send an EOF character.\n");	
	int16_t c;

	// put getchar inside the while loop, it must be inside brackets because
	// != has higher precedence than =, so without brackets it won't work.
	while((c = getchar() )!= EOF) {
		putchar(c);
	}
	return 0;
}
