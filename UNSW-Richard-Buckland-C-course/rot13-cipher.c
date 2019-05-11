// Library imports
#include <stdio.h>
#include <stdlib.h>

// Constants
#define SHIFT_NUMBER 13

// Function prototypes
char applyRot13(char c);

// Functions
int main(int argc, char *argv[])
{
  char c;

  printf("Enter a character to be ROT13 shifted.\n");
  scanf("%c", &c);
  printf("The character %c after ROT13 is %c\n.", c, applyRot13(c));
  return EXIT_SUCCESS;
}

// https://en.wikipedia.org/wiki/ROT13
char applyRot13(char c)
{
  // http://www.asciitable.com/
  char answer = '\0'; // Null control character.

  // Capitals are 65 - 90
  if (c >= 65 && c <= 77) {
    answer = c + SHIFT_NUMBER;
  }
  else if (c >= 78 && c <= 90) {
    answer = c - SHIFT_NUMBER;
  }
  // Lowercase are 97 to 122
  else if (c >= 97 && c <= 109) {
    answer = c + SHIFT_NUMBER;
  }
  else if (c >= 110 && c <= 122) {
    answer = c - SHIFT_NUMBER;
  }
  return answer;
}
