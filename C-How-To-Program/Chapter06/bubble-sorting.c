#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void printArray(int a[], size_t size);
void bubbleSortAsc(int a[], size_t size);
void bubbleSortDesc(int a[], size_t size);

int main(void) {
    int a[SIZE];
    /* Seed rand with the seconds since Unix Epoch, NULL specifies no formatting of seconds */
    srand((unsigned int) time(NULL));

    for (size_t i = 0; i < SIZE; i++) {
        /* Random number between 0 and 99 ( % 100) and shift it 1 and 100 (+ 1) */
        a[i] = 1 + (rand() % 100);
    }

    printf("# Array Bubble Sorting - ascending & descending \n");
    printArray(a, SIZE);

    bubbleSortAsc(a, SIZE);
    printArray(a, SIZE);

    bubbleSortDesc(a, SIZE);
    printArray(a, SIZE);

    return EXIT_SUCCESS;
}

void printArray(int a[], size_t size) {
    printf("\n## Printing Array\n");
    for (size_t i = 0; i < size; i++) {
        if (i == 0) {
            printf("[%d, ", a[i]);
        } else if (i != size - 1) {
            printf("%d, ", a[i]);
        } else {
            printf("%d]\n", a[i]);
        }
    }
}

void bubbleSortAsc(int a[], size_t size) {
    int value;
    printf("\n## Bubble Sorting - ascending\n");

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            // Try to swap only if there are 2 elemnts to swap.
            if (j < size - 1) {
                size_t next = j + 1;
                // Only swap if necessary
                if (a[j] > a[next]) {
                    value = a[j];
                    a[j] = a[next];
                    a[next] = value;
                }
            }
        }
    }
    printf("Done.\n");
}

void bubbleSortDesc(int a[], size_t size) {
    int value;
    printf("\n## Bubble Sorting - descending\n");

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            // Try to swap only if there are 2 elemnts to swap.
            if (j < size - 1) {
                size_t next = j + 1;
                // Only swap if necessary
                if (a[j] < a[next]) {
                    value = a[j];
                    a[j] = a[next];
                    a[next] = value;
                }
            }
        }
    }
    printf("Done.\n");
}
