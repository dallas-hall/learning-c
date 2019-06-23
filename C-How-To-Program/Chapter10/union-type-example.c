#include <stdio.h>
#include <stdlib.h>

/*
 * Union declartion.
 */ 
union numbers {
	char c;
	int i;
	long l;
	float f;
	double d;
};


int main(void)
{
	union numbers value;
	/*
	 * Use dot notation to access members
	 */ 
	value.c = 'a';
	puts("# Union Type Example");
	puts("\n## Assign Char Value - print all members");
	printf("The value of value.c as a %%c is %c\n", value.c);
	printf("The value of value.i as a %%d is %d\n", value.i);
	printf("The value of value.l as a %%ld is %ld\n", value.l);
	printf("The value of value.f as a %%f is %f\n", value.f);
	printf("The value of value.d as a %%f is %f\n", value.d);

	puts("\n## Assign Int Value - print all members");
	value.i = 97;
	printf("The value of value.c as a %%c is %c\n", value.c);
	printf("The value of value.i as a %%d is %d\n", value.i);
	printf("The value of value.l as a %%ld is %ld\n", value.l);
	printf("The value of value.f as a %%f is %f\n", value.f);
	printf("The value of value.d as a %%f is %f\n", value.d);

	puts("\n## Assign Long Value - print all members");
	value.l = 4294967296;
	printf("The value of value.c as a %%c is %c\n", value.c);
	printf("The value of value.i as a %%d is %d\n", value.i);
	printf("The value of value.l as a %%ld is %ld\n", value.l);
	printf("The value of value.f as a %%f is %f\n", value.f);
	printf("The value of value.d as a %%f is %f\n", value.d);

	puts("\n## Assign Float Value - print all members");
	value.f = 3.14;
	printf("The value of value.c as a %%c is %c\n", value.c);
	printf("The value of value.i as a %%d is %d\n", value.i);
	printf("The value of value.l as a %%ld is %ld\n", value.l);
	printf("The value of value.f as a %%f is %f\n", value.f);
	printf("The value of value.d as a %%f is %f\n", value.d);

	puts("\n## Assign Double Value - print all members");
	value.d = 3.14;
	printf("The value of value.c as a %%c is %c\n", value.c);
	printf("The value of value.i as a %%d is %d\n", value.i);
	printf("The value of value.l as a %%ld is %ld\n", value.l);
	printf("The value of value.f as a %%f is %f\n", value.f);
	printf("The value of value.d as a %%f is %f\n", value.d);



	return EXIT_SUCCESS;
}
