#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	// https://stackoverflow.com/a/18688992
	char binary[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};

	printf("%8s\t%8s\t%8s\t%8s\n", "Binary", "Octal", "Decimal", "Hex");
	for (int i = 0; i < 256; i++) {
		int n = i;
		if (n / 128 == 1) {
			binary[0] = '1';
			n -= 128;
		}
		if (n / 64 == 1) {
			binary[1] = '1';
			n -= 64;
		}
		if (n / 32 == 1) {
			binary[2] = '1';
			n -= 32;
		}
		if (n / 16 == 1) {
			binary[3] = '1';
			n -= 16;
		}
		if (n / 8 == 1) {
			binary[4] = '1';
			n -= 8;
		}
		if (n / 4 == 1) {
			binary[5] = '1';
			n -= 4;
		}
		if (n / 2 == 1) {
			binary[6] = '1';
			n -= 2;
		}
		if (n / 1 == 1) {
			binary[7] = '1';
			n -= 1; 
		}
		
		printf("%8s%8o\t%8d\t%8x\n", binary, i, i, i); 
		// Reset the array. I am a fucking moron. Didn't do this and spent 30 minutes wondering why my binary was wrong lols.
		for (int j = 0; j < 8; j++) {
			binary[j] = '0';
		}
	}

	return EXIT_SUCCESS;
}
