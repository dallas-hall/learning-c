#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER 80
#define EXTRA_CHARS 80

int debugging = 1;

void countAndPrintCharTypes(char s[])
{
  int total, lower, upper, alphaNumberic, whitespace, digits, punct, other, i;
  total = lower = upper = alphaNumberic = whitespace = digits = punct = other = 0;

  if(debugging) {
    printf("[DEBUG] countAndPrintCharTypes called with:\n%s\n", s);
  }

  for(i = 0; i < strlen(s); i++) {
    if(islower(s[i])) {
      ++lower;
      ++alphaNumberic;
      ++total;
    }
    else if(isupper(s[i])) {
      ++upper;
      ++alphaNumberic;
      ++total;
    }
    else if(isdigit(s[i])) {
      ++upper;
      ++alphaNumberic;
      ++total;
    }
    else if(isspace(s[i])) {
      ++whitespace;
      ++total;
    }
    else if(ispunct(s[i])) {
      ++punct;
      ++total;
    }
    else {
      ++other;
      ++total;
    }
  }

  printf("Lowercase: %d\n", lower);
  printf("Uppercase: %d\n", upper);
  printf("Digits: %d\n", digits);
  printf("Alpha-numeric: %d\n", alphaNumberic);
  printf("Whitespace: %d\n", whitespace);
  printf("Punctuation: %d\n", punct);
  printf("Other: %d\n", other);
  printf("Total input: %d\n", total);
  printf("String length: %lu\n", strlen(s));
}

int main(void)
{
  char input[BUFFER + EXTRA_CHARS];
  puts("Enter a string: ");
  fgets(input, BUFFER + EXTRA_CHARS, stdin);

  /* If last char isn't a newline then the input overflowed */
  if(input[strlen(input) - 1] != '\n') {
    printf("[ERROR] Buffer exceeded.\n");
    return EXIT_FAILURE;
  }

  if(debugging) {
    printf("[DEBUG] Input was:\n%s\n", input);
  }

  countAndPrintCharTypes(input);

  return EXIT_SUCCESS;
}
