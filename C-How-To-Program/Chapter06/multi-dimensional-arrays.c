#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_1ST_DIMENSION 3
#define SIZE_2ND_DIMENSION 3
#define SIZE_3RD_DIMENSION 3

int main(void)
{
	int i, j, k;
	int a[SIZE_1ST_DIMENSION][SIZE_2ND_DIMENSION];
	int b[SIZE_1ST_DIMENSION][SIZE_2ND_DIMENSION][SIZE_3RD_DIMENSION];

	printf("# Multi-dimensional Arrays - 2d array example\n");
	srand(time(NULL));

	for (i = 0; i < SIZE_1ST_DIMENSION; i++) {
		for (j = 0; j < SIZE_2ND_DIMENSION; j++) {
			a[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < SIZE_1ST_DIMENSION; i++) {
		for (j = 0; j < SIZE_2ND_DIMENSION; j++) {
			printf("a[%d][%d] is %d\t", i, j, a[i][j]);
		}
		printf("\n");
	}

	printf("\n# Multi-dimensional Arrays - 3d array example\n");
	for (i = 0; i < SIZE_1ST_DIMENSION; i++) {
		for (j = 0; j < SIZE_2ND_DIMENSION; j++) {
			for( k = 0; k < SIZE_3RD_DIMENSION; k++) {
				b[i][j][k] = rand() % 10;
			}
		}
	}

	for (i = 0; i < SIZE_1ST_DIMENSION; i++) {
		for (j = 0; j < SIZE_2ND_DIMENSION; j++) {
			for( k = 0; k < SIZE_3RD_DIMENSION; k++) {
				printf("b[%d][%d][%d] is %d\t", i, j, k, b[i][j][k]);
			}
		}
		printf("\n");
	}	

	return EXIT_SUCCESS;
}

