#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Enter some text via stdin which is read in and printed to stdout.\n");
	printf("Press ctrl+D to send an EOF character.\n");	
	
	int32_t c;
	char line[256];

	for (int i = 0; i < 256; i++)
	{
		line[i] = 0;
	}

	/*
	Pur the getchar() call inside the while loop. This needs to be inside parentheses.
	!= has a higher precedence than =, so without the parentheses the relational test
	is done before the assignment statement. This would set the variable to being
	either 0 or 1, depending on if EOF was returned.
	*/
	int	i = 0;
	while(EOF != (c = getchar())) {
		line[i] = c;
		i++;
	}
	if (i > 15) {
		for (int j = 0; j < i; j++) {
			putchar(line[j]);
		}
	}
	else {
		printf("The line was less than 16 characters long so it wasn't printed.\n");
	}
	return 0;
}
