#include <stdio.h>
#include <inttypes.h>

static double fahrenheit2celcius(double f)
{
	return (5.0 / 9.0) * (f - 32.0);
}

static double celcius2fahrenheit(double c)
{
	return ((c * 9.0 / 5.0) + 32); 
}

int main(void)
{
	double f, c;

	printf("F\tC\n");
	f = 0;
	for(int i = 0; i < 16; i++, f += 20) {
		c = fahrenheit2celcius(f); 
		printf("%1.1f\t%3.1f\n", f, c);
	}

	printf("C\tF\n");
	c = 0;
	for(int i = 0; i < 16; i++, c += 20) {
		f = celcius2fahrenheit(c); 
		printf("%1.1f\t%3.1f\n", c, f);
	}

	return 0;
}


