#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int miles, yards;
	float kilometres;
	double miles2, yards2, kilometres2; 

	miles = 385;
	yards = 26;
	/* 
	 * yards to miles is yards / 1760
	 * miles to km is miles * 1.609344
	 */
	kilometres = 1.609 * (miles + ((float) yards / 1760));

	miles2 = 385;
	yards2 = 26;
	kilometres2 = 1.609 * (miles2 + (yards2 / 1760));

	printf("%d miles, %d yards = %f kilometres\n", miles, yards, kilometres);
	// This is more accurate because of less rounding.
	printf("%.2f miles, %.2f yards = %f kilometres\n", miles2, yards2, kilometres2);

	return EXIT_SUCCESS;
}
