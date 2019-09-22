#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// https://en.wikipedia.org/wiki/Least_common_multiple
// https://www.mathsisfun.com/least-common-multiple.html
int lcmSub(int a, int b);
int lcmSub2(int a, int b);
int lcmSub3(int a, int b);
int lcmMod(int a, int b);
int lcmMod2(int a, int b);
int lcmMod3(int a, int b);


// https://en.wikipedia.org/wiki/Euclidean_algorithm
int gcdEuclidSubtractionRecursion(int a, int b);
int gcdEuclidModuloRecursion(int a, int b);

int main(void)
{
    puts("# Least Common Multiple");
	puts("## Greatest Common Divisor - Euclidean Subtraction");
    puts("### Algorithm 1 - |a * b| / gcd(a, b)");
    printf("lcmSub(3, 5) is %d\n", lcmSub(3, 5)); // 15
    printf("lcmSub(21, 6) is %d\n", lcmSub(21, 6)); // 42

    puts("### Algorithm 2 - |a| / gcd(a, b) * |b|");
    printf("lcmSub2(3, 5) is %d\n", lcmSub2(3, 5));
    printf("lcmSub2(21, 6) is %d\n", lcmSub2(21, 6));

    puts("### Algorithm 3 - |b| / gcd(a, b) * |a|");
    printf("lcmSub3(3, 5) is %d\n", lcmSub3(3, 5));
    printf("lcmSub3(21, 6) is %d\n", lcmSub3(21, 6));

	puts("## Greatest Common Divisor - Euclidean Modulo");
    puts("### Algorithm 1 - |a * b| / gcd(a, b)");
    printf("lcmMod(3, 5) is %d\n", lcmMod(3, 5)); // 15
    printf("lcmMod(21, 6) is %d\n", lcmMod(21, 6)); // 42

    puts("### Algorithm 2 - |a| / gcd(a, b) * |b|");
    printf("lcmMod2(3, 5) is %d\n", lcmMod2(3, 5));
    printf("lcmMod2(21, 6) is %d\n", lcmMod2(21, 6));

    puts("### Algorithm 3 - |b| / gcd(a, b) * |a|");
    printf("lcmMod3(3, 5) is %d\n", lcmMod3(3, 5));
    printf("lcmMod3(21, 6) is %d\n", lcmMod3(21, 6));


    return EXIT_SUCCESS;
}

// https://en.wikipedia.org/wiki/Least_common_multiple#Using_the_greatest_common_divisor
int lcmSub(int a, int b)
{
    int gcd = gcdEuclidSubtractionRecursion(a, b);
    int product = abs(a * b);
    return product / gcd;
}

int lcmSub2(int a, int b)
{
    int gcd = gcdEuclidSubtractionRecursion(a, b);
    return (abs(a) / gcd) * abs(b);
}

int lcmSub3(int a, int b)
{
    int gcd = gcdEuclidSubtractionRecursion(a, b);
    return (abs(b) / gcd) * abs(a);
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

int lcmMod(int a, int b)
{
    int gcd = gcdEuclidModuloRecursion(a, b);
    int product = abs(a * b);
    return product / gcd;
}

int lcmMod2(int a, int b)
{
    int gcd = gcdEuclidModuloRecursion(a, b);
    return (abs(a) / gcd) * abs(b);
}

int lcmMod3(int a, int b)
{
    int gcd = gcdEuclidModuloRecursion(a, b);
    return (abs(b) / gcd) * abs(a);
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
