#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// 31 and above takes a long time to calculate if a perfect number.
// 17 and above takes a long time to find all the divisors.
#define LIMIT 20

bool isPrime(long long int n);
bool isMersennePrime(long long int n);
long long int getMersennePrimeValue(long long int n);
bool isPerfectNumberExponent(long long int n);
long long int getPerfectNumberFromExponent(long long int n);
void printFactors(long long int n);

int main(void)
{
    puts("# Perfect Number Calculation");
    for(unsigned int i = 0; i < LIMIT; i++) {
        printf("Is %d prime? %s\n", i, isPrime(i) ? "true" : "false");
        printf("Is %d a Mersenne prime exponent? %s\n", i, isMersennePrime(i) ? "true" : "false");
        if(isMersennePrime(i)) {
            printf("The Mersenne prime value is %lld\n", getMersennePrimeValue(i));
			printf("Is %d a perfect number exponent? %s\n", i, isPerfectNumberExponent(i) ? "true" : "false");
			if (isPerfectNumberExponent(i)) {
				long long int result = getPerfectNumberFromExponent(i);
				printf("The perfect number of %d is %lld\n", i, result);
				printFactors(result);
			}
        }
		puts("");
    }

    return EXIT_SUCCESS;
}

// https://www.mathsisfun.com/prime-composite-number.html
// https://www.mathsisfun.com/numbers/prime-numbers-advanced.html
// A Prime Number can be divided exactly only by 1 or itself. And it must be a whole number greater than 1.
bool isPrime(long long int n)
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

// https://www.mathsisfun.com/numbers/prime-numbers-advanced.html
// Mersenne prime numbers of the form 2 ^ n - 1 where n must itself be prime.
// https://en.wikipedia.org/wiki/Mersenne_prime
// https://www.mersenne.org/primes/
bool isMersennePrime(long long int n)
{
    if(!isPrime(n)) {
        return false;
    }
    else {
        if(isPrime(pow(2, n) - 1)) {
            return true;
        }
        else {
            return false;
        }
    }
}

long long int getMersennePrimeValue(long long int n)
{
    return pow(2, n) - 1;
}

// https://en.wikipedia.org/wiki/Perfect_number
// https://en.wikipedia.org/wiki/List_of_perfect_numbers
// https://en.wikipedia.org/wiki/Euclid%E2%80%93Euler_theorem
// A whole number that is equal to the sum of its positive factors (except the number itself). - https://www.mathsisfun.com/definitions/perfect-number.html
// 2 ^ (p - 1) * ((2 ^ p) - 1) when (2 ^ p) - 1 is a Mersenne Prime
bool isPerfectNumberExponent(long long int n)
{
	// There are no known odd perfect numbers - https://en.wikipedia.org/wiki/Perfect_number#Even_perfect_numbers
	// https://stackoverflow.com/a/6567128
	if (isPrime(pow(2, n) - 1) && isPrime(n)) {
		return true;	
	}
	else {
		return false;
	}
}

long long int getPerfectNumberFromExponent(long long int n)
{
	return pow(2, n - 1) * (pow(2, n) - 1);
}

// https://www.geeksforgeeks.org/find-divisors-natural-number-set-1/
void printFactors(long long int n)
{
	// We don't want to include n as a perfect number is the sum between all factors 1 through to n, excluding n
	for (long long int i = 1; i < n; i++) {
		if(n % (long long int) i == 0) {
			printf("%lld + ", i);
		}
	}
	printf("\b\b\b = %lld\n", n);
}
