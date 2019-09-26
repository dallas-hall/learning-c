#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 32

bool isPrimeIterative(long long int n);
bool isPrimeRecursive(long long int n, long long int m);
bool isMersennePrime(long long int n);

int main(void)
{
    puts("# Prime Numbers");
    puts("## Iterative");

    for(unsigned int i = 0; i <= LIMIT; i++) {
        bool result = isPrimeIterative((long long int) i);
        printf("Is %u prime? %s.\n", i, result ? "True" : "False");
    }

    puts("## Recursive");

    for(unsigned int i = 0; i <= LIMIT; i++) {
        bool result = isPrimeRecursive((long long int) i, 3);
        printf("Is %u prime? %s.\n", i, result ? "True" : "False");
    }
    return EXIT_SUCCESS;
}

// https://www.mathsisfun.com/prime-composite-number.html
// https://www.mathsisfun.com/numbers/prime-numbers-advanced.html
// A Prime Number can be divided exactly only by 1 or itself. And it must be a whole number greater than 1.
bool isPrimeIterative(long long int n)
{
    // Numbers 2 and above can be prime.
    if(n > 1) {
        // 2 is the only even prime
        if (n % 2 == 0 && n != 2) {
            return false;
        }

        // Skip 3 as there is no odd number between 1 and 3 to test for divisibility.
        if(n == 2 || n == 3) {
            return true;
        }
            // Test all numbers between 3 and n - 1. If any can be evenly divided they are not prime.
        else {
            for (unsigned long i = 3; (long long int) i < n - 1; i++) {
                if (n % (long long int) i == 0) {
                    return false;
                }
            }
            return true;
        }
    }

    return false;
}

/*
 * n is the number to check to see if it is prime.
 * m is the divisor, start at 3 and check until n - 1.
 */
bool isPrimeRecursive(long long int n, long long int m)
{
    bool recursionResult = true;

    // Only numbers 2 and higher can be prime
    if (n <= 1) {
        recursionResult = false;
    }
    // 2 is the only even prime number
    else if (n % 2 == 0 && n != 2) {
        recursionResult = false;
    }
    else if(n == 2 || n == 3) {
        recursionResult = true;
    }
    else {
        // Check for m - 2 because we are only checking odd numbers.
        if (m != n - 2) {
            if (n % m == 0) {
                recursionResult = false;
            }
            else {
                recursionResult = isPrimeRecursive(n, m + 2);
            }
        }
    }
    return recursionResult;
}

// Mersenne prime numbers of the form 2 ^ n - 1 where n must itself be prime.
// https://en.wikipedia.org/wiki/Mersenne_prime
// https://www.mersenne.org/primes/
bool isMersennePrime(long long int n)
{
    if(!isPrimeIterative(n)) {
        return false;
    }
    else {
        if(isPrimeIterative(pow(2, n) - 1)) {
            return true;
        }
        else {
            return false;
        }
    }
}

