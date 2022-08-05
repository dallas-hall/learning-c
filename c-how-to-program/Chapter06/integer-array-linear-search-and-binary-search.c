#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define SIZE 100

/*
 * Use const to let the caller know we are not modifying the array's contents.
 */
void printArray(const int a[], size_t size);
void bubbleSortAsc(int a[], size_t size);
void bubbleSortDesc(int a[], size_t size);

int main(void) {
    int a[SIZE];
    size_t position;
    int searchValue, searches, found, low, middle, high;

    /*
     * Seed rand with the seconds since Unix Epoch
     * NULL means no format necessary from time
     */
    srand((unsigned int) time(NULL));

    printf("# Integer Array Searching - linear search\nEnter an integer: ");
    scanf("%2d", &searchValue);
    printf("Initialising array with random values.\n");
    for (size_t i = 0; i < SIZE; i++) {
        /*
         * Generate a random number between 0 and 99 (% 100)
         * Shift the number range by 1, so its 1 and 100 (+ 1)
         */
        a[i] = 1 + rand() % 100;
    }
    printf("Done.\n");
    printArray(a, SIZE);

    printf("## Linear Searching - Unsorted\nSearching for %d.\n", searchValue);
    searches = found = 0;
    position = SIZE_MAX;
    for (size_t i = 0; i < SIZE; i++) {
        ++searches;
        if (searchValue == a[i]) {
            position = i;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("The search value %d was first found at position %zu after %d searches.\n", searchValue, position,
               searches);
    } else {
        printf("The search value %d was not found after %d searches.\n", searchValue, searches);
    }

    printf("## Linear Searching - Sorted\nSearching for %d.\n", searchValue);
    bubbleSortAsc(a, SIZE);
    printArray(a, SIZE);

    searches = found = 0;
    position = SIZE_MAX;
    for (size_t i = 0; i < SIZE; i++) {
        ++searches;
        if (searchValue == a[i]) {
            position = i;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("The search value %d was first found at position %zu after %d searches.\n", searchValue, position,
               searches);
    } else {
        printf("The search value %d was not found after %d searches.\n", searchValue, searches);
    }


    printf("\n## Binary Searching\nSearching for %d.\n", searchValue);
    searches = found = 0;
    printArray(a, SIZE);

    /*
     * Start with the entire array in scope.
     */
    low = 0;
    high = SIZE - 1;

    /*
     * Keep searching until the lower array position is higher than the upper array position.
     * This means we have searched everywhere.
     */
    while (low <= high) {
        ++searches;
        /*
         * Keep calculating the middle, so we can gradually reduce the search space.
         */
        middle = (low + high) / 2;

        /*
         * First check is always the middle.
         */
        if (a[middle] == searchValue) {
            found = 1;
            position = (size_t) middle;
            break;
        }
            /*
             * Search the lower half of the current scope.
             * Reduce the scope by updating high, making it below the current middle by 1.
             */
        else if (searchValue < a[middle]) {
            high = middle - 1;
        }
            /*
             * Search the upper half of the current scope.
             * Reduce the scope by updating low, making it above the current middle by 1.
             */
        else {
            low = middle + 1;
        }
    }

    if (found) {
        printf("The search value %d was first found at position %zu after %d searches.\n", searchValue, position,
               searches);
    } else {
        printf("The search value %d was not found after %d searches.\n", searchValue, searches);
    }

    return EXIT_SUCCESS;
}

void printArray(const int a[], size_t size) {
    int lines;

    lines = 0;
    printf("\n## Printing Array\n");
    for (size_t i = 0; i < size; i++) {
        ++lines;

        if (i == 0) {
            printf("[%d, ", a[i]);
        } else if (i != size - 1) {
            printf("%d, ", a[i]);
        } else {
            printf("%d]\n", a[i]);
        }

        if (lines % 10 == 0) {
            printf("\n");
        }
    }
}

void bubbleSortAsc(int a[], size_t size) {
    int value;
    size_t position;
    printf("\n## Bubble Sorting - ascending\n");

    for (size_t i = 0; i < size; i++) {
        /*
         * The current index is stored as the assumed smallest.
         * The subsequent search will see if that is true.
         */
        value = a[i];
        position = i;
        for (size_t j = i + 1; j < size; j++) {
            /*
             * Keep testing to see if any values are smaller.
             * Replace if they are.
             */
            if (a[j] < value) {
                value = a[j];
                position = j;
            }
        }
        /*
         * Check to see if we found a smaller value in a different position.
         * Swap them if we did.
         */
        if (value != a[i] && position != i) {
            a[position] = a[i];
            a[i] = value;
        }
    }
    printf("Done.\n");
}

void bubbleSortDesc(int a[], size_t size) {
    int value;
    size_t position;
    printf("\n## Bubble Sorting - descending\n");

    for (size_t i = 0; i < size; i++) {
        /*
         * The current index is stored as the assumed largest.
         * The subsequent search will see if that is true.
         */
        value = a[i];
        position = i;
        for (size_t j = i + 1; j < size; j++) {
            /*
             * Keep testing to see if any values are larger.
             * Replace if they are.
             */
            if (a[j] > value) {
                value = a[j];
                position = j;
            }
        }
        /*
         * Check to see if we found a larger value in a different position.
         * Swap them if we did.
         */
        if (value != a[i] && position != i) {
            a[position] = a[i];
            a[i] = value;
        }
    }
    printf("Done.\n");
}
