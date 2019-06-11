#include <stdio.h>

void printHexChar(int n);
char getHexChar(int n);

int main(void)
{
	for (int i = 0; i < 256; i++) {
		printHexChar(i);
		if ((i + 1) % 16 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

void printHexChar(int n)
{
	if (n >= 0 && n <= 15) {
		printf("0x0%c ", getHexChar(n));
	} else {
		int a = n / 16;
		int b = n % 16;
		printf("0x%c%c ", getHexChar(a), getHexChar(b));
	}
}

char getHexChar(int n)
{
	switch(n) {
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		default:
			return '\0';
	}
}
