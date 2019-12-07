#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5

void populate1dArray(int a[], size_t length);
void print1dArray(int a[], size_t length);
// Inefficient but easy
void bubbleSortAsc(int a[], size_t size);
void bubbleSortDesc(int a[], size_t size);
void mergeSortTwoSets(const int a[], size_t length1, const int b[], size_t length2, int c[], size_t length3);
bool areTwoSortedSetsEqual(const int a[], size_t length1, const int b[], size_t length2);
int getUniqueElementCountOneSortedSet(const int a[], size_t length1);
int getUniqueElementCountTwoSortedSets(const int a[], size_t length1, const int b[], size_t length2);
/*
 * https://en.wikipedia.org/wiki/Set_theory
 * https://en.wikipedia.org/wiki/Union_(set_theory)
 */
void twoSortedSetUnion(const int a[], size_t length1, const int b[], size_t length2, int c[], size_t length3);
//https://en.wikipedia.org/wiki/Intersection_(set_theory)
int getCommonUniqueElementCountTwoOrderedSets(const int a[], size_t length1, const int b[], size_t length2);
void twoSortedSetIntersection(int a[], size_t length1, int b[], size_t length2, int c[], size_t length3);

int main(void) {
	puts("# Sets");
	puts("Creating arrays.");

//	int a1[] = {2, 4, 1, 3, 1};
//	int a2[] = {4, 1, 3, 1, 2};

	//srand((unsigned int) time(NULL));
	/*
	 * 1 has 7 unique elements shared across both sets. Set 1 has 4 unique elements and set 2 has 5 unique elements.
	 * 2 has 5 unique elements shared across both sets. Set 1 has 4 unique elements and set 2 has 4 unique elements.
	 * 4 has 7 unique elements shared across both sets. Set 1 has 3 unique elements and set 2 has 4 unique elements.
	 * 8 has 6 unique elements shared across both sets. Set 1 has 4 unique elements and set 2 has 5 unique elements.
	 * 16 has 6 unique elements shared across both sets. Set 1 has 4 unique elements and set 2 has 4 unique elements.
	 * 512 has 7 unique elements shared across both sets. Set 1 has 3 unique elements and set 2 has 5 unique elements.
	 */
	srand(8);

	int a1[SIZE];
	int a2[SIZE];

	populate1dArray(a1, SIZE);
	populate1dArray(a2, SIZE);

	print1dArray(a1, SIZE);
	print1dArray(a2, SIZE);

	puts("Sorting arrays.");
	bubbleSortAsc(a1, SIZE);
	bubbleSortAsc(a2, SIZE);

	print1dArray(a1, SIZE);
	print1dArray(a2, SIZE);

	puts("Merging and sorting arrays.");
	size_t mergedSortedSize = SIZE * 2;
	int mergedSorted[mergedSortedSize];
	mergeSortTwoSets(a1, SIZE, a2, SIZE, mergedSorted, mergedSortedSize);
	print1dArray(mergedSorted, mergedSortedSize);

	puts("Comparing arrays.");
	printf("Are the 2 sorted sets equal? %s\n", areTwoSortedSetsEqual(a1, SIZE, a2, SIZE) ? "true" : "false");
	printf("The amount of unique elements in a1 is %d.\n", getUniqueElementCountOneSortedSet(a1, SIZE));
	printf("The amount of unique elements in a2 is %d.\n", getUniqueElementCountOneSortedSet(a2, SIZE));


	puts("## Set union.");
	size_t uniqueElementCountBothSets = getUniqueElementCountTwoSortedSets(a1, SIZE, a2, SIZE);
	printf("The amount of unique elements in both arrays is %d.\n", (int) uniqueElementCountBothSets);
	int setUnion[uniqueElementCountBothSets];
	twoSortedSetUnion(a1, SIZE, a2, SIZE, setUnion, uniqueElementCountBothSets);
	print1dArray(setUnion, uniqueElementCountBothSets);

	puts("## Set intersection.");
	size_t commonElementsBothSets = getCommonUniqueElementCountTwoOrderedSets(a1, SIZE, a2, SIZE);
	printf("The amount of common elements between both arrays is %d.\n", (int) commonElementsBothSets);
	int setIntersection[commonElementsBothSets];
	twoSortedSetIntersection(a1, SIZE, a2, SIZE, setIntersection, commonElementsBothSets);
	print1dArray(setIntersection, commonElementsBothSets);

	return EXIT_SUCCESS;
}

void populate1dArray(int a[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		// Random number between 0 and 10. This doesn't check for duplicates
		a[i] = rand() % 11;
	}
}


void print1dArray(int a[], size_t length) {
	printf("[");
	for (size_t i = 0; i < length; i++) {
		printf("%d, ", a[i]);
	}
	printf("\b\b]\n");
}

void bubbleSortAsc(int a[], size_t size)
{
	int value;
	size_t position;

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
}

void bubbleSortDesc(int a[], size_t size)
{
	int value;
	size_t position;

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
}

void mergeSortTwoSets(const int a[], size_t length1, const int b[], size_t length2, int c[], size_t length3)
{
	// Insert array 1
	for (size_t i = 0; i < length1; i++) {
		c[i] = a[i];
	}

	// Insert array 2, start after array 1 finishes. Could merge sort here.
	size_t elementToUpdate = length1;
	for (size_t i = 0; i < length2; i++, elementToUpdate++) {
		c[elementToUpdate] = b[i];
	}

	// Sort merged array
	bubbleSortAsc(c, length3);
}

/*
 * Two sets are equal if they have precisely the same members, regardless of order.
 * This function expects ordered sets.
 */
bool areTwoSortedSetsEqual(const int a[], size_t length1, const int b[], size_t length2)
{
	// If the sets don't have the same amount of elements, they cannot be equal
	if (length1 != length2) {
		return false;
	}

	// The ordered sets of the same size should have elements matching in every position..
	for (size_t i = 0; i < length1; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

int getUniqueElementCountOneSortedSet(const int a[], size_t length1) {
	int count = length1;

	for (size_t i = 0; i < length1; i++) {
		// Check all the values inside of a[] against each other
		if (i < length1 - 1) {
			// This for loop works on unsorted sets.
//			for (size_t j = i + 1; j < length1; j++) {
//				if (a[i] == a[j]) {
//					--count;
//					break;
//				}
//			}
			// Only works if sorted.
			if (a[i] == a[i + 1]) {
				--count;
			}
		}
	}

	return count;
}


int getUniqueElementCountTwoSortedSets(const int a[], size_t length1, const int b[], size_t length2) {
	// Merge the sets
	size_t mergeSortedLength = length1 + length2;
	int mergedSorted[mergeSortedLength];
	mergeSortTwoSets(a, length1, b, length2, mergedSorted, mergeSortedLength);

	return getUniqueElementCountOneSortedSet(mergedSorted, mergeSortedLength);
}

// https://en.wikipedia.org/wiki/Set_(mathematics)#Unions
void twoSortedSetUnion(const int a[], size_t length1, const int b[], size_t length2, int c[], size_t length3) {
	// All unique elements in either set a, set b, or both set a and b
	// Merge the sets
	size_t mergeSortedLength = length1 + length2;
	int mergedSorted[mergeSortedLength];
	mergeSortTwoSets(a, length1, b, length2, mergedSorted, mergeSortedLength);

	// Insert unique elements from both sets
	size_t elementToUpdate = 0;
	for (size_t i = 0; i < mergeSortedLength; i++) {
		// Check all the values inside of a[] against each other
		if (i < mergeSortedLength - 1 && elementToUpdate < length3) {
			// Only works if sorted.
			if (mergedSorted[i] != mergedSorted[i + 1]) {
				c[elementToUpdate] = mergedSorted[i];
				++elementToUpdate;
			}
		}
			// Check the last value and add it if it hasn't been already
		else {
			if (c[elementToUpdate] != mergedSorted[i] && elementToUpdate < length3) {
				c[elementToUpdate] = mergedSorted[i];
			}
		}
	}
}

int getCommonUniqueElementCountTwoOrderedSets(const int a[], size_t length1, const int b[], size_t length2)
{
	size_t result = 0;

	// Get all the elements from set A that appear in set B
	for (size_t i = 0; i < length1; i++) {
		for (size_t j = 0; j < length2; j++) {
			// Check each element against each other
			if (i < length1 - 1) {
				if (a[i] == b[j] && a[i] != a[i + 1]) {
					++result;
					break;
				}
			}
				// Check the last value and add it if it hasn't been already
			else {
				if (a[i] == b[j] && a[i] != a[i - 1]) {
					++result;
				}
			}
		}
	}

	return result;
}

// https://en.wikipedia.org/wiki/Set_(mathematics)#Intersections
void twoSortedSetIntersection(int a[], size_t length1, int b[], size_t length2, int c[], size_t length3)
{
	size_t elementToUpdate = 0;

	// Get all elements that appear in both A and B
	for (size_t i = 0; i < length1; i++) {
		for (size_t j = 0; j < length2; j++) {
			// Check each element against each other
			if (i < length1 - 1 && elementToUpdate < length3) {
				if (a[i] == b[j] && a[i] != a[i + 1]) {
					c[elementToUpdate] = a[i];
					++elementToUpdate;
					break;
				}
			}
				// Check the last value and add it if it hasn't been already
			else {
				if (a[i] == b[j] && a[i] != a[i - 1] && elementToUpdate < length3) {
					c[elementToUpdate] = a[i];
				}
			}
		}
	}
}
