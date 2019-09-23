#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(long n);
bool isMersennePrime(long n);
unsigned long getMersennePrimeValue(long n);
bool isPerfectNumber(long n);
unsigned long getPerfectNumber(long n);

int main(void)
{
    puts("# Perfect Number Calculation");
    for(int i = 0; i < 16; i++) {
        printf("Is %d prime? %s\n", i, isPrime(i) ? "true" : "false");
        printf("Is %d a Mersenne prime exponent? %s\n", i, isMersennePrime(i) ? "true" : "false");
        if(isMersennePrime(i)) {
            printf("The Mersenne prime value is %lu\n", getMersennePrimeValue(i));
			printf("Is %d a perfect number exponent? %s\n", i, isPerfectNumber(i) ? "true" : "false");
			if (isPerfectNumber(i)) {
				int sum = 0;
				for (int j = 1; j < i; j++) {
					sum += j;
					printf("%d + ", j);
				}
				printf("\b\b= %d\n", sum);
			}
        }
		puts("");
    }

    return EXIT_SUCCESS;
}

// https://www.mathsisfun.com/prime-composite-number.html
// https://www.mathsisfun.com/numbers/prime-numbers-advanced.html
// A Prime Number can be divided exactly only by 1 or itself. And it must be a whole number greater than 1.
bool isPrime(long n)
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
            unsigned long i;
            for (i = 3; (long) i < n - 1; i++) {
                if (n % (long) i == 0) {
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
bool isMersennePrime(long n)
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

unsigned long getMersennePrimeValue(long n)
{
    return pow(2, n) - 1;
}

// https://en.wikipedia.org/wiki/Perfect_number
// https://en.wikipedia.org/wiki/List_of_perfect_numbers
// https://en.wikipedia.org/wiki/Euclid%E2%80%93Euler_theorem
// A whole number that is equal to the sum of its positive factors (except the number itself). - https://www.mathsisfun.com/definitions/perfect-number.html
// 2 ^ (p - 1) * ((2 ^ p) - 1) when (2 ^ p) - 1 is a Mersenne Prime
bool isPerfectNumber(long n)
{
	if (isMersennePrime(pow(2, n) - 1)) {
		return true;	
	}
	else {
		return false;
	}
}

unsigned long getPerfectNumber(long n)
{
	return pow(2, n - 1) * (pow(2, n) - 1);
}
