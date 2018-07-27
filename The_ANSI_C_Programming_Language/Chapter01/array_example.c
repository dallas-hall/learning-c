#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t currentChar, whitespace, other;
	whitespace = 0;
	other = 0;

	int8_t digit[10];
	for (int i = 0; i < 10; i++) {
		digit[i] = 0;
	}

	printf("Enter some text, press control+d to exit.\n");
	while (EOF != (currentChar = getchar())) {
		if (currentChar >= '0' && currentChar <= '9') {
			digit[currentChar - '0']++;
		}
		else if (' ' == currentChar || '\n' == currentChar || '\t' == currentChar) {
			whitespace++;
		}
		else {
			other++;
		}
	}
	
	printf("Digits:");
	for (int i = 0; i < 10; i++) {
		printf(" %d has %d\n", i, digit[i]);
	}
	printf("\nWhitespace: %d\nOther: %d", whitespace, other);
	
	return 0;
}
