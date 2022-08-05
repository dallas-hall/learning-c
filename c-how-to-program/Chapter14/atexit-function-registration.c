#include <stdlib.h>
#include <stdio.h>

void exitFunction1(void);
void exitFunction2(void);

int main(void)
{
	puts("# atexit Function Registration");
	puts("Any functions registered with atexit are invoked in reverse registration order when the exit function is called.");
	
	puts("\n## Registring atexit Functions");
	puts("Registring exitFunction1()");
	atexit(exitFunction1);
	puts("Registring exitFunction2()");
	atexit(exitFunction2);
	
	puts("\n## Invoking exit");
	puts("Invoking exit(EXIT_SUCCESS);");
	exit(EXIT_SUCCESS);
}

void exitFunction1(void)
{
	puts("\n### exitFunction1()\nHi, I am exitFunction1 and I was registered first.");

}

void exitFunction2(void)
{
	puts("\n### exitFunction2()\nHi, I am exitFunction2 and I was registered second.");

}

