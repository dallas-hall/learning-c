#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This includes the implicit argv[0] argument of the program name.
 * So we are expecting to user arguments.
 */ 
#define MAX_ARGS 3

int closeFileAndExit(FILE *ptr);

int main(int argc, char *argv[])
{
	unsigned long chars = 0;
	unsigned long words = 0;
	unsigned long lines = 0;
	FILE *inputFilePointer = NULL;
	char c;
	char lastC;

	puts("# Basic wc Clone");
	if(argc > MAX_ARGS) {
		/*
		 * We need minus 1 here to cover the implicit argv[0] with the program's name.
		 */ 
		fprintf(stderr, "[ERROR] Too many arguments supplied. Expected %d and got %d.\n", MAX_ARGS - 1, argc - 1);
		return EXIT_FAILURE;
	}
	else if(argc == 1) {
		puts("## Counting stdin - Chars, Words, Lines");
		/*
		 * Remember () for precedence, as assignment is lower than comparison.
		 */ 
		while((c = getchar()) != EOF) {
			++chars;
			if(c == ' ') {
				++words;
			}
			/*
			 * Assumes all lines ending with a newline.
			 * If they don't we add an extra one after.
			 */ 
			else if(c == '\n') {
				++words;\
				++lines;
			}
			lastC = c;
		}
		
		if(lastC != '\n') {
			++words;
		}
		printf("%lu\t%lu\t%lu\n", chars, words, lines);
	}
	else if(argc == 3 && strcmp(argv[1], "-m") == 0)
	{
		puts("## Char Count");
		if ((inputFilePointer = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "[ERROR] The file %s couldn't be opened. Does it exist?\n", argv[2]);
			return EXIT_FAILURE;
		}
	
		do {
			c = fgetc(inputFilePointer);
			if(feof(inputFilePointer)) {
				break;
			}
			++chars;
			lastC = c;
		} while (1);

		printf("%lu\n", chars);
	}
	else if(argc == 3 && strcmp(argv[1], "-w") == 0)
	{
		puts("## Word Count");
		if ((inputFilePointer = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "[ERROR] The file %s couldn't be opened. Does it exist?\n", argv[2]);
			return EXIT_FAILURE;
		}
	
		do {
			c = fgetc(inputFilePointer);
			if(feof(inputFilePointer)) {
				break;
			}
			if (c == ' ' || c == '\n') {
				++words;
			}
			lastC = c;
		} while (1);

		if(lastC != '\n') {
			++words;
		}
		printf("%lu\n", words);
	}
	else if(argc == 3 && strcmp(argv[1], "-l") == 0)
	{
		puts("## Line Count");
		if ((inputFilePointer = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "[ERROR] The file %s couldn't be opened. Does it exist?\n", argv[2]);
			return EXIT_FAILURE;
		}
	
		do {
			c = fgetc(inputFilePointer);
			if(feof(inputFilePointer)) {
				break;
			}
			else  if(c == '\n') {
				++lines;
			}
		} while (1);

		printf("%lu\n", lines);
	}
	else if(argc == 2) {
		puts("## File Count - Char, Words, Lines");
		if ((inputFilePointer = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "[ERROR] The file %s couldn't be opened. Does it exist?\n", argv[2]);
			return EXIT_FAILURE;
		}
	
		do {
			c = fgetc(inputFilePointer);
			if(feof(inputFilePointer)) {
				break;
			}
			++chars;
			if(c == ' ') {
				++words;
			}
			else if(c == '\n') {
				++words;
				++lines;
			}
			lastC = c;
		} while (1);

		if(lastC != '\n') {
			++words;
		}
		printf("%lu\t%lu\t%lu\n", chars, words, lines);
		return closeFileAndExit(inputFilePointer);
	}
	else {
		fprintf(stderr, "[ERROR] Incorrect arguments. Use no arguments|-m file|-w file|-l file| file\n");
	}
	
	return closeFileAndExit(inputFilePointer);
}

int closeFileAndExit(FILE *ptr)
{
	if(ptr != NULL) {
		fclose(ptr);
	}
	return EXIT_SUCCESS;
}
