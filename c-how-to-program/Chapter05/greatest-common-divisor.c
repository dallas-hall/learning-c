#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// https://en.wikipedia.org/wiki/Euclidean_algorithm
int gcdEuclidSubtractionRecursion(int a, int b);
int gcdEuclidModuloRecursion(int a, int b);

int main(void)
{
	puts("# Greatest Common Divisor - Euclidean Subtraction");
	printf("The gcd(8, 12) is %d\n", gcdEuclidSubtractionRecursion(8, 12));
	printf("The gcd(54, 24) is %d\n", gcdEuclidSubtractionRecursion(54, 24));
	
	puts("# Greatest Common Divisor - Euclidean Modulo");
	printf("The gcd(8, 12) is %d\n", gcdEuclidModuloRecursion(8, 12));
	printf("The gcd(54, 24) is %d\n", gcdEuclidModuloRecursion(54, 24));

    return EXIT_SUCCESS;
}

int gcdEuclidSubtractionRecursion(int a, int b)
{
    /*
     * The Euclid subtraction algorithm works as follows.
     *
     * 1) Start with 2 numbers, a and b.
     * 2) Find the difference between a and b (large -  small)
     * 3) Repeat step 2 until a = b or both are 0. This is the GCD.
     *
     * Many subtraction steps are necessary so it can be improved with division remainder.
     */

    int recursionResult, c;

    if (a == b) {
        return a;
    }
    else if (a > b) {
        c = a - b;
        recursionResult = gcdEuclidSubtractionRecursion(b, c);
    }
    else {
        c = b - a;
        recursionResult = gcdEuclidSubtractionRecursion(a, c);
    }
    return recursionResult;
}

int gcdEuclidModuloRecursion(int a, int b)
{
	/*
	 * The Euclid division remainder algorithm
	 *
	 * 1) Start with 2 numbers, a and b.
	 * 2) Reduce the large number. a is now b and b is now a % b.
	 * 3) Repeat 2 until the remainder is 0.
	 */

	if (b == 0) {
		return a;
	}
	else {
		int t = a % b;
		int recursionResult = gcdEuclidModuloRecursion(b, t);
		return recursionResult;
	}
}	
