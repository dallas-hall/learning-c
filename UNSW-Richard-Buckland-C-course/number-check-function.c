#include <stdio.h> // Has scanf and printf
#include <stdlib.h> // Has EXIT_SUCCESS
#include <stdbool.h> // Has boolean valuables

// Function prototypes
bool isNumberEven(int n);
bool isNumberPrime(int n);

int main(int argc, char *argv[])
{
  int inputNumber;
  bool answer;

  printf("Enter an integer.\n");
  scanf("%d", &inputNumber);
  answer = isNumberEven(inputNumber);
  // https://stackoverflow.com/a/17307307
  printf("Is the number %d even? %s.\n", inputNumber, answer ? "true" : "false");
  answer = isNumberPrime(inputNumber);
  printf("Is the number %d prime? %s.\n", inputNumber, answer ? "true" : "false");

  return EXIT_SUCCESS;
}

bool isNumberEven(int n)
{
  if (n % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

// https://www.mathsisfun.com/prime-composite-number.html
bool isNumberPrime(int n)
{
  if (n <= 1) {
    return false;
  } else if (isNumberEven(n) && n != 2) {
    return false;
  } else if (n == 2 || n == 3) {
    return true;
  } else {
    for (int i = 3; i < n - 2; i+=2) {
      if(n % i == 0) {
        return false;
      }
    }
    return true;
  }
}
