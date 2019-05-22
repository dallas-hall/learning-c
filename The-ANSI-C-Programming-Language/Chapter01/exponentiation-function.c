#include <stdio.h>
#include <stdbool.h> // Has boolean valuables

int powerLoop(int base, int n);
int powerRecursion(int base, int n);
bool debugging = true;

int main(void)
{
	printf("Displaying the first 16 powers of 2 ^ i (loop).\n");
	for (int i = 0; i < 16; i++) {
		printf("2 ** %d\t%d\n", i, powerLoop(2, i));
	}

	printf("Displaying the first 16 powers of 2 ^ i (recursion).\n");
	for (int i = 0; i < 16; i++) {
		printf("2 ** %d\t%d\n", i, powerRecursion(2, i));
	}
	return 0;
}

int powerLoop(int base, int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result = result * base;	
	}

	return result;
}

int powerRecursion(int base, int n)
{
	int result = 0;
	int recursionResult = 0;

	// 0 ^ n is always 0
	if (base == 0) {
		return 0;
	}

	// base ^ 0 is always 1
	if (n == 0) {
		return 1;
	}
	// base ^ 1 is always base
	else if (n == 1) {
		return base;
	}
	// base ^ 2 is always base * base
	else if (n == 2) {
		return base * base;
	} else {
		/*
		 * When base is higher then 3, this will recurse through n - 1 until something is returned.
		 * The lowest number returned will always be base * base.
		 * The stack is unwound and each returned recursion result is used in next the multiplication.
		 * This happens until the stack is empty and no more reursion results exist, and the final answer is the expected power.
		 *
		 * Lets take base ^ 3 as an example.
		 *
		 * # main method
		 *
		 * base = 2
		 * n = 3
		 * answer = powerRecursion(2, 3)
		 *
		 * # powerRecursion(2, 3)
		 *
		 * result, recursionResult = 0
		 * base = 2
		 * n = 3
		 * n > 2 so powerRecursion(2, 3 - 1)
		 *
		 * # powerRecursion(2, 2)
		 * 
		 * result, recursionResult = 0
		 * base = 2
		 * n = 2
		 * n equals 2 so result = base * base
		 * result (2 * 2) = 4 
		 * The return of statements pops this off of the stack, back to the previous stack frame.
		 *
		 * # powerRecursion(2, 3)
		 *
		 * recursionResult = 4
		 * result = recursionResult * base
		 * result = 4 * 2
		 * result = 8
		 * The return of statements pops this off of the stack, back to the previous stack frame.
		 *
		 * # main method
		 *
		 * answer = 8
		 * Thus 2 ^ 3 = 8
		 */
		recursionResult = powerRecursion(base, n - 1);
		result = base * recursionResult;
		if (debugging) {
			printf("\n[DEBUG]\n");
			printf("base is %d\n", base);
			printf("n is %d\n", n);
			printf("recursionResult is %d\n", recursionResult);
			printf("result is %d\n", result);
		}
	
		return result;
	}
}
