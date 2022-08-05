#include <stdio.h>
#include <stdlib.h>

/*
 * Casting, sizeof and enums cannot be evaluated by the preprocessor.
 *
 * This works much like an if statement, must begin with #if and end with #endif.
 * #elif can also be used.
 *
 * #ifdef is a shortcut for #if defined(name)
 * #ifndef is a shortcut for #if !defined(name)
 *
 * These are frequently used to prevent header files from being included multiple times in the same source file.
 */ 
#if !defined(MY_CONSTAT)
	#define MY_CONSTANT "A constant string that was conditionally compiled."
#endif
#define DEBUG 1

int main(void)
{
	/*
	 * An easy way to comment out code from compiling is using 
	 *
	 * #if 
	 * 
	 * ...
	 *
	 * #endif
	 *
	 */ 


	puts("# Conditional Preprocessor Compilation");

	#ifdef DEBUG
		printf("[DEBUG] DEBUG macro is on.");
		printf("The value of MY_CONSTANT is\n%s\n", MY_CONSTANT);
	#endif

	#ifndef INFO
		printf("[INFO] INFO macro hasn't been defined.\n");
	#endif

	return EXIT_SUCCESS;
}
