#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	printf("# math.h Functions\n## Square Root - sqrt()\n");
	printf("sqrt(%1.f) = %.1f\n", 900.0, sqrt(900.0));
	printf("sqrt(%1.f) = %.1f\n", 9.0, sqrt(9.0));

	printf("\n## Exponential Value - exp()\n");
	printf("exp(%1.f) = %.1f\n", 1.0, exp(1.0));
	printf("exp(%1.f) = %.1f\n", 2.0, exp(2.0));

	printf("\n## Natural Logarithm - log()\n");
	printf("log(%1.f) = %.1f\n", 2.718282, log(2.718282));
	printf("log(%1.f) = %.1f\n", 7.389056, log(7.389056));

	printf("\n## Common Logarithm - log10()\n");
	printf("log10(%1.f) = %.1f\n", 1.0, log10(1.0));
	printf("log10(%1.f) = %.1f\n", 10.0, log10(10.0));
	printf("log10(%1.f) = %.1f\n", 100.0, log10(100.0));

	printf("\n## Asbolute Number - fabs()\n");
	printf("fabs(%1.f) = %.1f\n", 13.5, fabs(13.5));
	printf("fabs(%1.f) = %.1f\n", 0.0, fabs(0.0));
	printf("fabs(%1.f) = %.1f\n", -13.5, fabs(13.5));

	printf("\n## Ceiling - ceil()\n");
	printf("ceil(%1.f) = %.1f\n", 9.2, ceil(9.2));
	printf("ceil(%1.f) = %.1f\n", -9.8, ceil(-9.8));

	printf("\n## Floor - floor()\n");
	printf("floor(%1.f) = %.1f\n", 9.2, floor(9.2));
	printf("floor(%1.f) = %.1f\n", -9.8, floor(-9.8));

	printf("\n## Power Of - pow()\n");
	printf("pow(%1.f, %1.f) = %.1f\n", 2.0, 7.0, pow(2.0, 7.0));
	printf("pow(%1.f, %1.f) = %.1f\n", 9.0, 0.5, pow(9.0, 0.5));

	printf("\n## Modulo - fmod()\n");
	printf("fmod(%1.f, %1.f) = %.1f\n", 13.675, 2.333, fmod(13.675, 2.333));

	printf("\n## Sine - sin()\n");
	printf("sin(%1.f) = %.1f\n", 0.0, sin(0.0));
	
	printf("\n## Cosine - cos()\n");
	printf("cos(%1.f) = %.1f\n", 0.0, cos(0.0));

	printf("\n## Tan - tan()\n");
	printf("tan(%1.f) = %.1f\n", 0.0, tan(0.0));
	
	return EXIT_SUCCESS;
}
