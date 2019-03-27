#include <stdio.h>
#include <inttypes.h>

#define LOWER 0
#define UPPER 300
#define INCREMENT 20

int main(void)
{
	int16_t f;

	for(f = LOWER; f <= UPPER; f = f + INCREMENT) {
		printf("%3d %6.1f\n", f, (5.0 / 9.0) * (f - 32));
	}

	return 0;
}
