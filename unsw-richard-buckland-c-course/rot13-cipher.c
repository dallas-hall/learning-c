// Library imports
#include <stdio.h>
#include <stdlib.h>

// Constants
#define SHIFT_NUMBER 13

// Function prototypes
char applyRot13(char c);
void printAllUppercaseRot13(void); // void is needed for a 0 paramater function
void printAllLowercaseRot13(void);

// Functions
int main(int argc, char *argv[])
{
  char c;

  printf("Enter a character to be ROT13 shifted.\n");
  scanf("%c", &c);
  printf("The character %c after ROT13 is %c.\n", c, applyRot13(c));

  printAllUppercaseRot13();
  printAllLowercaseRot13();
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

void printAllUppercaseRot13()
{
  printf("ROT13 applied to A-Z:\n");
  for (int i = 65; i <= 90; i++) {
    printf("%c", applyRot13((char) i));
  }
  printf("\n");
}

void printAllLowercaseRot13()
{
  printf("ROT13 applied to a-z:\n");
  for (int i = 97; i <= 122; i++) {
    printf("%c", applyRot13((char) i));
  }
  printf("\n");
}
