#include <stdio.h>
#include <inttypes.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy_2_array(char to[], char from[]);

/* print the longest input line */
int main(void)
{

	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;

	printf("Type some lines, the longest line will be stored and displayed back at the end.\nPress control + d to exit.\n");
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
		max = len;
		copy_2_array(longest, line);
		}
	}

	if (max > 0) /* there was a line */
		printf("%s", longest);

	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int limit)
{
	int i;
	int32_t c;

	for (i = 0; i < limit - 1 && EOF != (c = getchar()) && '\n' != c; i++) {
		s[i] = c;
	}
	if ('\n' == c) {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy_2_array(char to[], char from[])
{
	int i;
	i = 0;

	while ('\0' != (to[i] = from[i])) {
		i++;
	}
}
