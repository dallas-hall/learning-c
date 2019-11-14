#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

void populate1dArray(int a[], size_t length);
void print1dArray(int a[], size_t length);
int getUniqueElementCountOneSet(int a[], size_t length1);
int getUniqueElementCountTwoSets(int a[], size_t length1, int b[], size_t length2);
/*
 * https://en.wikipedia.org/wiki/Set_theory
 * https://en.wikipedia.org/wiki/Union_(set_theory)
 */
void setUnion(int a[], size_t length1, int b[], size_t length2, int c[], size_t length3);
//https://en.wikipedia.org/wiki/Intersection_(set_theory)
int getCommonElementCountTwoSets(int a[], size_t length1, int b[], size_t length2);
void setIntersection(int a[], size_t length1, int b[], size_t length2, int c[], size_t length3);

int main(void) {
    puts("# Union Of 2 Sets");
    puts("Creating arrays.");
    //srand((unsigned int) time(NULL));
    /*
     * 1 has 18 unique elements shared across both sets. Set 1 has 9 unique elements and set 2 has 10 unique elements.
     * 22 has 6 unique elements shared across both sets. Set 1 has 10 unique elements and set 2 has 9 unique elements.
     * 32 has 16 unique elements shared across both sets. Both sets have 10 unique elements invididually.
     */
    srand(1);

    int a1[SIZE];
    int a2[SIZE];

    populate1dArray(a1, SIZE);
    populate1dArray(a2, SIZE);

    print1dArray(a1, SIZE);
    print1dArray(a2, SIZE);

    int a3Size = getUniqueElementCountTwoSets(a1, SIZE, a2, SIZE);
    printf("The amount of unique elements in array1 is %d.\n", getUniqueElementCountOneSet(a1, SIZE));
    printf("The amount of unique elements in array2 is %d.\n", getUniqueElementCountOneSet(a2, SIZE));
    printf("The amount of unique elements between both arrays is %d.\n", a3Size);

    // Union
    int a3[a3Size];
    setUnion(a1, SIZE, a2, SIZE, a3, a3Size);
    print1dArray(a3, a3Size);

    // Intersection
    int a4Szie = a3Size;
    int a4[a4Szie];


    return EXIT_SUCCESS;
}

void populate1dArray(int a[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        // Random number between 0 and 100. This doesn't check for duplicates
        a[i] = rand() % 101;
    }
}


void print1dArray(int a[], size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%d, ", a[i]);
    }
    printf("\b\b]\n");
}

int getUniqueElementCountOneSet(int a[], size_t length1) {
    int count = length1;

    for (size_t i = 0; i < length1; i++) {
        // Check all the values inside of a[] against each other
        if (i < length1 - 1) {
            if (a[i] == a[i + 1]) {
                --count;
            }
        }
    }

    return count;
}

int getUniqueElementCountTwoSets(int a[], size_t length1, int b[], size_t length2) {
    int count = length1 + length2;

    for (size_t i = 0; i < length1; i++) {
        // Check all the values inside of a[] against each other
        if (i < length1 - 1) {
            if (a[i] == a[i + 1]) {
                --count;
            }
        }

        for (size_t j = 0; j < length2; j++) {
            // Check all the values inside of b[] against each other
            if (j < length1 - 1) {
                if (b[j] == b[j + 1]) {
                    --count;
                }
            }

            // Check all the values inside of a[] and b[] against each other
            if (a[i] == b[j]) {
                --count;
            }
        }
    }

    return count;
}

// https://en.wikipedia.org/wiki/Set_(mathematics)#Unions
void setUnion(int a[], size_t length1, int b[], size_t length2, int c[], size_t length3) {
    int elementsAdded = 0;

    // Add all the unique elements from array 1
    for (size_t i = 0; i < length1; i++) {
        // Always add the first element
        if (i == 0) {
            c[i] = a[i];
            ++elementsAdded;
        }
            // Check every other element to make sure it hasn't already been added
        else {
            bool found = false;
            // Loop through the union array and check if the current element already exists
            for (size_t j = 0; j < elementsAdded; j++) {
                //printf("c[%zu] is %d and a[%zu] is %d\n", j, c[j], i, a[i]);
                if (c[j] == a[i]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                c[elementsAdded] = a[i];
                ++elementsAdded;
            }
        }
    }

    // Add all the unique elements from array 2
    for (size_t i = 0; i < length2; i++) {
        bool found = false;
        // Loop through the union array and check if the current element already exists
        for (size_t j = 0; j < elementsAdded; j++) {
            //printf("c[%zu] is %d and a[%zu] is %d\n", j, c[j], i, a[i]);
            if (c[j] == b[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            c[elementsAdded] = b[i];
            ++elementsAdded;
        }
    }
}

int getCommonElementCountTwoSets(int a[], size_t length1, int b[], size_t length2)
{
    int result = 0;


    return result;
}

// https://en.wikipedia.org/wiki/Set_(mathematics)#Intersections
void setIntersection(int a[], size_t length1, int b[], size_t length2, int c[], size_t length3)
{

}
