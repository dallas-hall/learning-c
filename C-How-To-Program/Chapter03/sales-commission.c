#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float sales, wage;
	while(1) {
		printf("Enter total sales for the week or -1 to end: ");
		scanf("%f", &sales);
		if((int) sales == -1) {
			break;
		}
		// $200 base and 9% of total sales
		wage = sales * .09 + 200;
		printf("Monthly wage is: %.2f\n", wage);
	}
	return EXIT_SUCCESS;
}
