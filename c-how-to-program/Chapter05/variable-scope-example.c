#include <stdlib.h>
#include <stdio.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

/* Global variable */
int x = 1;

int main(void)
{
	/* Local variable to main */
	int x = 10;

	printf("# Variable Scope Examples\n");
	printf("## main()\nThe value of x from the outer scope of main is %d\n", x);

	if (1) {
		/* Local variable to the if statement */
		int x = 100;

		printf("The value of x from the inner if block scope of main is %d\n", x);
	}

	printf("The value of x from the outer scope of main is %d\n", x);
	
	useLocal();
	useStaticLocal();
	useGlobal();
	useLocal();
	useStaticLocal();
	useGlobal();

	return EXIT_SUCCESS;
}

void useLocal(void)
{
	int x = 2;
	printf("\n### useLocal()\nThe value of x from the block scope of useLocal() is %d\n", x);
	++x;
	printf("After incrementing, the value of x from the block scope of useLocal() is %d\n", x);
}

void useStaticLocal(void)
{
	static int x = 20;
	printf("\n### useStaticLocal()\nThe value of static x from the block scope of useStaticLocal() is %d\n", x);
	++x;
	printf("After incrementing, the value of static x from the block scope of useStaticLocal() is %d\n", x);
}

void useGlobal(void)
{
	printf("\n### useGlobal()\nThe value of global x from the file scope acceesed inside of useGlobal() is %d\n", x);
	++x;
	printf("After incrementing, the value of global x from the file scope acceesed inside of useGlobal() is %d\n", x);
}
