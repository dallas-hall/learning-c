#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        long x = -1L;
        unsigned int y = 1U;
        unsigned long int z = 1UL;

		printf("# Variables\n");
		printf("long x = %ld\n", x);
		printf("unsigned int y = %u\n", y);
		printf("unsigned long int z = %ld\n", z);

		printf("\n# Comparisons\n");
		printf("Is x < y ?\n");
        /* y is promoted to a signed long */
		if ( x < y) { 
                printf("-1L is smaller than 1U\n");
		}
        else {
                printf("-1L is larger than 1U\n");
		}
		printf("Because x = %ld and (signed long) y = %ld\n", x, (signed long) y);

		/* x is promoted to unsigned long */
		printf("\nIs x < z ?\n");
        if ( x < z) { 
                printf("-1L is smaller than 1UL\n");
		}
        else {
                printf("-1L is larger than 1UL\n");
		}
		printf("Because (unsigned long int) x = %ld and (unsigned long int) z = %ld\n", (unsigned long int) x, z);

        return EXIT_SUCCESS;
}
/* What gets printed? Hint: 1U is promoted to signed long
   i.e. 1L, and -1L is promoted to unsigned long, i.e. a large
   +ve integer */
