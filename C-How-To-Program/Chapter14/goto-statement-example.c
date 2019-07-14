#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int count = 1;

	puts("# goto Statement Example");

	/*
	 * Define our label for the goto statement
	 */ 
	start:

		if(count > 10) {
			/*
		 	* Jump forward to end.
		 	*/ 
			goto end;
		}

		printf("%d\t", count);
		++count;

	/*
	 * Jump back to start
	 */ 
	goto start;

	end:
		putchar('\n');

	return EXIT_SUCCESS;
}
