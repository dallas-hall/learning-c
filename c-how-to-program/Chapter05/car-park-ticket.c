#include <stdlib.h>
#include <stdio.h>

#define MINIMUM_FEE 2.00
#define ADDITIONAL_FEE 0.50
#define MAXIMUM_24_HOUR_FEE 10.00

double getParkingFee(double totalHours);

int main(void)
{
	int i;
	double totalHours, totalFees;
	totalHours = 0.0;
	totalFees = 0.0;

	printf("# Car Parking Fees\n");
	printf("%-8s%8s%8s\n", "Car", "Hours", "Charge");
	for(i = 1; i <= 4; i++) {
		double hours;
		double fee;
		switch (i) {
			case 1: 
				hours = 1.5;
				fee = getParkingFee(hours);
				totalHours += hours;
				totalFees += fee;
				break;
			case 2:
				hours = 4.0;
				fee = getParkingFee(hours);
				totalHours += hours;
				totalFees += fee;
				break;
			case 3:
				hours = 24.0;
				fee = getParkingFee(hours);
				totalHours += hours;
				totalFees += fee;
				break;
			case 4:
				hours = 28.0;
				fee = getParkingFee(hours);
				totalHours += hours;
				totalFees += fee;
				break;
		
		}
		

		printf("%-8d%8.1f%8.2f\n", i, hours, fee);
	}
	printf("%-8s%8.1f%8.2f\n", "TOTAL", totalHours, totalFees);

	return EXIT_SUCCESS;
}

double getParkingFee(double totalHours)
{
	double fee = MINIMUM_FEE;
	int days, hours, minutes;

	if (totalHours > 24.0) {
		days = (int) totalHours / 24;
		hours = (int) totalHours % 24;
		fee = days * MAXIMUM_24_HOUR_FEE;
		if (hours < 3) {
			fee += MINIMUM_FEE;
		}
		else {
			fee += MINIMUM_FEE + (hours - 3) * ADDITIONAL_FEE;
		}
	}
	else if (totalHours == 24.0) {
		fee = MAXIMUM_24_HOUR_FEE;
	}
	else {
		if (totalHours > 3.0) {
			hours = (int) totalHours;
			fee += (hours - 3) * ADDITIONAL_FEE; 
			/* Subtract the whole number to get the remainder */
			minutes = (totalHours - (int) totalHours) * 100;
			if (minutes > 0) {
				fee += ADDITIONAL_FEE;
			}
			if (fee > MAXIMUM_24_HOUR_FEE) {
				fee = MAXIMUM_24_HOUR_FEE;
			}
		}
	}
		
	return fee;	
}
