#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define STUDENTS 10
#define ASSESSMENTS 3

// Using const so the arrays can never be updated as we don't want to update them.
int min(const int grades[][ASSESSMENTS], size_t students, size_t assessments);
int max(const int grades[][ASSESSMENTS], size_t students, size_t assessments);
long double avg(const int grades[][ASSESSMENTS], size_t students, size_t assessments);
void print2dArray(const int grades[][ASSESSMENTS], size_t students, size_t assessments);

int main(void) {
    int classResults[STUDENTS][ASSESSMENTS];

    puts("# 2D Array Manipulations");
    puts("Initialising classResults array.");

    srand((unsigned int) time(NULL));
    for (size_t i = 0; i < STUDENTS; i++) {
        for (size_t j = 0; j < ASSESSMENTS; j++) {
            // Random number between 0 and 100 inclusive
            classResults[i][j] = rand() % 101;
        }
    }

    print2dArray(classResults, STUDENTS, ASSESSMENTS);

    puts("## Minimum Score");
    printf("The mimimum score was %d\n", min(classResults, STUDENTS, ASSESSMENTS));

    puts("## Maximum Score");
    printf("The maximum score was %d\n", max(classResults, STUDENTS, ASSESSMENTS));

    puts("## Average Score");
    printf("The average score was %LF\n", avg(classResults, STUDENTS, ASSESSMENTS));

    return EXIT_SUCCESS;
}

int min(const int grades[][ASSESSMENTS], size_t students, size_t assessments) {
    // Set to the maximum number an int can hold so we can get numbers less than that if they exist.
    int min = INT_MAX;

    for (size_t i = 0; i < students; i++) {
        for (size_t j = 0; j < assessments; j++) {
            if (grades[i][j] < min) {
                min = grades[i][j];
            }
        }
    }

    return min;
}

int max(const int grades[][ASSESSMENTS], size_t students, size_t assessments) {
    // Set to the miniumum number an int can hold so we can get numbers greater than that if they exist.
    int max = INT_MIN;

    for (size_t i = 0; i < students; i++) {
        for (size_t j = 0; j < assessments; j++) {
            if (grades[i][j] > max) {
                max = grades[i][j];
            }
        }
    }

    return max;
}

long double avg(const int grades[][ASSESSMENTS], size_t students, size_t assessments) {
    size_t count = 0;
    unsigned long total = 0;

    for (size_t i = 0; i < students; i++) {
        for (size_t j = 0; j < assessments; j++) {
            total += (unsigned long) grades[i][j];
            ++count;
        }
    }

    return (long double) (total / (unsigned long) count);
}

void print2dArray(const int grades[][ASSESSMENTS], size_t students, size_t assessments) {
    for (size_t i = 0; i < students; i++) {
        printf("Student %lu results are [", i + 1);
        for (size_t j = 0; j < assessments; j++) {
            printf("%d, ", grades[i][j]);
        }
        printf("\b\b]\n");
    }
}
