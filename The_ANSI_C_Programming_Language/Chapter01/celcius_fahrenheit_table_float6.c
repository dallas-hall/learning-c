#include <stdio.h>
// import new int types
#include <inttypes.h>

/*
if it is a constant value, prefer const <type> name = value over #define

#define LOWER 0
#define UPPER 300
#define INCREMENT 20
*/
const int8_t LOWER = 0;
const int16_t UPPER = 300;
const int8_t INCREMENT = 20;


// this method returns an int (return code) and takes no arguments
int main(void)
{
	float c;

	printf("C\tF\n");
	for(c = LOWER; c <= UPPER; c = c + INCREMENT) {
		printf("%1.1f\t%3.1f\n", c, (c * 9.0 / 5.0) + 32); // right justified
	}

	return 0;
}

