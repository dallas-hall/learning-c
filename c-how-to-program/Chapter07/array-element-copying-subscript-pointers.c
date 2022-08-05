#include <stdlib.h>
#include <stdio.h>

/*
 * char * const stringPointer1 = A constant char pointer called string1Pointer with a non-constant char [] - this gets updated.
 * const char * const string2Pointer = A constant char pointer called string2Pointer with a constant char [] - this gets read from only.
 */ 
void copySubscript(char * const string1Pointer, const char * const string2Pointer);
/*
 * char *stringPointer1 = a non-constant char pointer with non-constant char [] - this gets updated.
 * const char *stringPointer2 = a non-constant char pointer to constant char [] - this gets read only.
 */ 
void copyPointer(char *stringPointer1, const char *stringPointer2);

int main(void)
{
	char s1[10];
	char *strPtr2 = "Hello";
	char s3[10];
	char s4[] = "Good bye";

	printf("# Showing Interchangability Of Arrays & Pointers\n");
	printf("## Pre-copying Values\n");
	printf("s1 is currently \"%s\"\n", s1);
	printf("strPtr2 is currently \"%s\"\n", strPtr2);
	printf("s3 is currently \"%s\"\n", s3);
	printf("s4 is currently \"%s\"\n", s4);
	
	printf("\n## Post-copying Values\n");
	/*
	 * Copy string2 into string1
	 * Both functions` first parameter is the string to be copied into.
	 * Both functions` second parameter is the constant string to read for copying.
	 */
	copySubscript(s1, strPtr2);
	copyPointer(s3, s4);
	printf("s1 is currently \"%s\"\n", s1);
	printf("strPtr2 is currently \"%s\"\n", strPtr2);
	printf("s3 is currently \"%s\"\n", s3);
	printf("s4 is currently \"%s\"\n", s4);
	
	return EXIT_SUCCESS;
}


void copySubscript(char * const string1Pointer, const char * const string2Pointer)
{
	int i;

	/*
	 * The first step is assigning the element at s1[i] the value of the element at s2[i].
	 * The left operand, s1[i], is then checked to see if its '\0'
	 * If no, keep copying, if yes, we are at the end of the string.
	 */ 
	for(i = 0; (string1Pointer[i] = string2Pointer[i]) != '\0'; i++) {
		/*
		 * Do nothing here, because everything is done above.
		 */ 
	}
}


void copyPointer(char *stringPointer1, const char *stringPointer2)
{
	/*
	 * Dont' need a counter variable because we are using pointer arithmetic.
	 * The first step is assigning the the element at *s1 the value of the element at *s2.
	 * The left operand, *s1, is then checked to see if its '\0'
	 * If no, keep copying, if yes, we are at the end of the string.
	 * The pointer arithmetic, *s1++ and *s2++, advances both pointers one element.
	 */ 
	
	for ( ; (*stringPointer1 = *stringPointer2) != '\0'; stringPointer1++, stringPointer2++) {
		/*
		 * Do nothing here, because everything is done above.
		 */ 
	}
}
