#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MATRIX_SIZE 4

void populate2dArray(size_t m, size_t n, int a[][n]);

void print2dArray(size_t m, size_t n, const int a[][n]);

void print1dArray(size_t m, const long int a[]);

// The 2d array is a square matrix, m  x m. Thus c will be m as well.
void setArrayProduct(size_t m, const int a[][m], const int b[][m], long int c[]);

int main(void)
{
	puts("# 2D Matrix Multiplication");

	int a1[MATRIX_SIZE][MATRIX_SIZE] = {0};
	int a2[MATRIX_SIZE][MATRIX_SIZE] = {0};
	long int a3[MATRIX_SIZE] = {0};

	populate2dArray(MATRIX_SIZE, MATRIX_SIZE, a1);
	populate2dArray(MATRIX_SIZE, MATRIX_SIZE, a2);

	print2dArray(MATRIX_SIZE, MATRIX_SIZE, a1);
	print2dArray(MATRIX_SIZE, MATRIX_SIZE, a2);
	
	setArrayProduct(MATRIX_SIZE,a1, a2, a3);
	print1dArray(MATRIX_SIZE, a3);

	return EXIT_SUCCESS;
}

void populate2dArray(size_t m, size_t n, int a[][n])
{
	/*
	 * Seed rand() so it doesn't roll consecutive numbers.
	 * Seed it with the number of seconds since the Unix Epoch.
	 */
	//srand((unsigned int) time(NULL));

	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < n; j++) {
			// Random number between 1 and 6, inclusive.
			a[i][j] = 1 + rand() % 6;
		}
	}
}

void print2dArray(size_t m, size_t n, const int a[][n])
{
	size_t finalLine = m - 1;
	printf("[\n");
	for (size_t i = 0; i < m; i++) {
		printf("\t[");
		for (size_t j = 0; j < n; j++) {
			printf("%d, ", a[i][j]);
		}

		if (i != finalLine) {
			printf("\b\b],\n");
		}
		else {
			printf("\b\b]\n");
		}
	}
	printf("]\n");
}

void print1dArray(size_t m, const long int a[])
{
	printf("%s", "[");
	for (size_t i = 0; i < m; i++) {
		printf("%ld, ", a[i]);
	}
	printf("%s", "\b\b]\n");
}

// The 2d array is a square matrix, m  x m. Thus c will be m as well.
void setArrayProduct(size_t m, const int a[][m], const int b[][m], long int c[])
{
	long int sum = 0;
	long int product = 0;
	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < m; j++) {
			printf("a[%lu][%lu] %d and b[%lu][%lu] %d\t", i, j, a[i][j], j, i,
				   b[j][i]);
			product = a[i][j] * b[j][i];
			sum += product;
		}
		printf("\nsum is %ld\n", sum);
		c[i] = sum;
		sum = 0;
	}
}
