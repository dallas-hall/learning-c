#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate1dArray(int a[], size_t length);
void populate2dArray(size_t row, size_t col, int[row][col]);
void print1dArray(int a[], size_t length);
void print2dArray(size_t row, size_t col, int[row][col]);

int main(void) {
    puts("# c99's Variable Length Array (runtime size creation");
    puts("Creating arrays.");
    srand((unsigned int) time(NULL));

    // Random number between 0 and 5, shifting between 1 and 6
    size_t a1Length = 1 + rand() % 6;
    int a1[a1Length];
    populate1dArray(a1, a1Length);

    size_t a2Row = 1 + rand() % 6;
    size_t a2Col = 1 + rand() % 6;
    int a2[a2Row][a2Col];
    populate2dArray(a2Row, a2Col, a2);

    printf("Printing 1d c99 variable length array with function, it has a size of %zu.\n", a1Length);
    print1dArray(a1, a1Length);

    printf("Printing 2d c99 variable length array with function, it has a size of %zu by %zu.\n", a2Row, a2Col);
    print2dArray(a2Row, a2Col, a2);

    return EXIT_SUCCESS;
}

void populate1dArray(int a[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        // Random number between 0 and 100
        a[i] = rand() % 101;
    }
}

void populate2dArray(size_t row, size_t col, int a[row][col]) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            // Random number between 0 and 100
            a[i][j] = rand() % 101;
        }
    }
}

void print1dArray(int a[], size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%d, ", a[i]);
    }
    printf("\b\b]\n");
}

void print2dArray(size_t row, size_t col, int a[row][col]) {
    printf("[");
    for (size_t i = 0; i < row; i++) {
        printf("\n\t[");
        for (size_t j = 0; j < col; j++) {
            printf("%d, ", a[i][j]);
        }
        printf("\b\b],");
    }
    printf("\b\n]");
}