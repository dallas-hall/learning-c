#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	char current_line[128];
	for (int i = 0; i < 128; i++) {
		current_line[i] = 0;
	}

	int32_t c;

	printf("Enter your line(s) of text. Only lines greater than 16 characters will be echoed back.\n");

	/*
	Pur the getchar() call inside the while loop. This needs to be inside parentheses.
	!= has a higher precedence than =, so without the parentheses the relational test
	is done before the assignment statement. This would set the variable to being
	either 0 or 1, depending on if EOF was returned.
	*/
	int16_t i = 0;
	while(EOF != (c = getchar())) {
		// Copy input before the enter key
		if ('\n' != c) {
			current_line[i] = c;
			i++;
		}
		// After enter key, terminate the string and check its length for printing
		else {
			current_line[i] = '\0';
			i++;

			if (i > 16) {
				for (int j = 0; j < i; j++) {
					putchar(current_line[j]);
				}
				printf("\n");
			}
			// Reset the array for the next line.
			for (int j = 0; j < i; j++) {
				current_line[j] = 0;
			}
		
			// Reset i for the next line
			i = 0;
		}
	}

	return 0;
}
