#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// https://en.wikipedia.org/wiki/Least_common_multiple
// https://www.mathsisfun.com/least-common-multiple.html
int lcm(int a, int b);
int lcm2(int a, int b);
int lcm3(int a, int b);

// https://en.wikipedia.org/wiki/Euclidean_algorithm
int gcdEuclidSubtractionRecursion(int a, int b);

int main(void)
{
    puts("# Least Common Multiple");
    puts("## Algorithm 1 - |a * b| / gcd(a, b)");
    printf("lcm(3, 5) is %d\n", lcm(3, 5)); // 15
    printf("lcm(21, 6) is %d\n", lcm(21, 6)); // 42

    puts("## Algorithm 2 - |a| / gcd(a, b) * |b|");
    printf("lcm2(3, 5) is %d\n", lcm2(3, 5));
    printf("lcm2(21, 6) is %d\n", lcm2(21, 6));

    puts("## Algorithm 3 - |b| / gcd(a, b) * |a|");
    printf("lcm3(3, 5) is %d\n", lcm3(3, 5));
    printf("lcm3(21, 6) is %d\n", lcm3(21, 6));

    return EXIT_SUCCESS;
}

// https://en.wikipedia.org/wiki/Least_common_multiple#Using_the_greatest_common_divisor
int lcm(int a, int b)
{
    int gcd = gcdEuclidSubtractionRecursion(a, b);
    int product = abs(a * b);
    return product / gcd;
}

int lcm2(int a, int b)
{
    int gcd = gcdEuclidSubtractionRecursion(a, b);
    return (abs(a) / gcd) * abs(b);
}

int lcm3(int a, int b)
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
