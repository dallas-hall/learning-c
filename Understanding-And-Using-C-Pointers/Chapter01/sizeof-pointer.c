#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* c;
	short s;
	int* i;
	long* l;
	float* f;
	double* d;
	unsigned int* ui;
	unsigned long* ul;
	void* voidPtr;

	puts("# sizeof(pointer)");
	/*
	 * ANSI C wants %ld
	 */ 
	printf("On this machine, sizeof(char*) is %ld bytes.\n", sizeof(c));
	printf("On this machine, sizeof(short*) is %ld bytes.\n", sizeof(s));
	printf("On this machine, sizeof(int*) is %ld bytes.\n", sizeof(i));
	printf("On this machine, sizeof(long*) is %ld bytes.\n", sizeof(l));
	printf("On this machine, sizeof(float*) is %ld bytes.\n", sizeof(f));
	printf("On this machine, sizeof(double*) is %ld bytes.\n", sizeof(d));
	printf("On this machine, sizeof(unsigned int*) is %ld bytes.\n", sizeof(ui));
	printf("On this machine, sizeof(unsigned long*) is %ld bytes.\n", sizeof(ul));
	printf("On this machine, sizeof(void*) is %ld bytes.\n", sizeof(voidPtr));

	return EXIT_SUCCESS;
}
