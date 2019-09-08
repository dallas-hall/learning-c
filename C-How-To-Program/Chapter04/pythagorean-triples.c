#include <stdio.h>
#include <stdlib.h>

#define LIMIT 500

int main(void)
{
	puts("# Calculating Pythagorean Triples Up To 500");
	/*
	 * https://www.mathsisfun.com/right_angle_triangle.html
	 * https://www.mathsisfun.com/pythagoras.html
	 * https://www.mathsisfun.com/pythagorean_triples.html - a squared + b squared =  c squared
	 * https://www.mathsisfun.com/numbers/pythagorean-triples.html
	 */

	 unsigned int i, j, k, side1Squared, side2Squared, hyptonuseSquared;

	 for (i = 1; i < LIMIT; i++) {
		 side1Squared = i * i;
		 for (j = 1; j < LIMIT; j++) {
			 side2Squared = j * j;
			 for (k = 1; k < LIMIT; k++) {
				 hyptonuseSquared = k * k;
				 if(side1Squared + side2Squared == hyptonuseSquared) {
					 printf("[%u, %u, %u] is a Pythagorean Triple.\n", i, j, k);
				 }
			 }
		 }
	 }

	return EXIT_SUCCESS;
}
