#include <stdio.h>
#include <inttypes.h>

static const int32_t INPUT_LIMIT = 1000;

int get_line(char line[], int input_limit);
void copy_2_array(char to[], char from[]);

/* print the longest input line */
int main(void)
{

	int current_line_length;
	int current_max_length;
	char current_line[INPUT_LIMIT];
	char longest_line[INPUT_LIMIT];
	current_max_length = 0;

	printf("Type some lines, the longest_line line will be stored and displayed back at the end.\nPress control + d to exit.\n");
	while ((current_line_length = get_line(current_line, INPUT_LIMIT)) > 0) {
		if (current_line_length > current_max_length) {
		current_max_length = current_line_length;
		copy_2_array(longest_line, current_line);
		}
	}

	if (current_max_length > 0) /* there was a line */
		printf("The longest_line line was:\n%s", longest_line);

	return 0;
}

/* get_line: read a line into s, return current_line_lengthgth */
int get_line(char s[], int input_limit)
{
	int i;
	int32_t c;

	for (i = 0; i < input_limit - 1 && EOF != (c = getchar()) && '\n' != c; i++) {
		s[i] = c;
	}
	if ('\n' == c) {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

/* copy_2_array: copy 'from' into 'to'; assume to is big enough */
void copy_2_array(char to[], char from[])
{
	int i;
	i = 0;

	while ('\0' != (to[i] = from[i])) {
		i++;
	}
}
