#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // https://stackoverflow.com/a/4767943

#define VALID_DEGREES 180
#define RIGHT_ANGLE 90
#define EQUILATERAL_DEGREES 60

int main(void)
{
	// https://www.mathsisfun.com/triangle.html
	int angle1, angle2, angle3;
	int side1, side2, side3;
	bool isTriangle, isEquilateral, isIsosceles, isScalene, isAcute, isRightAngle, isObtuse;

	isTriangle = false;
	isEquilateral = false;
	isIsosceles = false;
	isScalene = false;
	isAcute = false;
	isRightAngle = false;
	isObtuse = false;

	puts("# Triangles");
	printf("Enter 3 integers separated by space for the angles: ");
	scanf("%d %d %d", &angle1, &angle2, &angle3);
	printf("Enter 3 integers separated by space for the sides: ");
	scanf("%d %d %d", &side1, &side2, &side3);

	if((angle1 + angle2 + angle3) == VALID_DEGREES) {
		isTriangle = true;

		if((angle1 == EQUILATERAL_DEGREES && angle2 == EQUILATERAL_DEGREES && angle3 == EQUILATERAL_DEGREES) &&
			(side1 == side2 && side1 == side3 && side2 == side3)) {
			isEquilateral = true;
		}
		if ((angle1 == angle2 || angle1 == angle3 || angle2 == angle3) &&
			(side1 == side2 || side1 == side3 || side2 == side3)) {
			isIsosceles = true;
		}
		if ((angle1 != angle2 && angle1 != angle3 && angle2 != angle3) &&
			(side1 != side2 && side1 != side3 && side2 != side3)) {
			isScalene = true;
		}
		if (angle1 < RIGHT_ANGLE && angle2 < RIGHT_ANGLE && angle3 < RIGHT_ANGLE) {
			isAcute = true;
		}
		if (angle1 == RIGHT_ANGLE || angle2 == RIGHT_ANGLE || angle3 == RIGHT_ANGLE) {
			isRightAngle = true;
		}
		if (angle1 > RIGHT_ANGLE || angle2 > RIGHT_ANGLE || angle3 > RIGHT_ANGLE) {
			isObtuse = true;
		}
	}

	if(isTriangle) {
		printf("The angles %d, %d, and %d and the sides %d, %d, and %d can make a triangle.\n", angle1, angle2, angle3, side1, side2, side3);
		if(isEquilateral) {
			puts("This is an equilateral triangle.");
		}
		if (isIsosceles) {
			puts("This is an isosceles triangle.");
		}
		if (isScalene) {
			puts("This is an scalene triangle.");
		}
		if (isAcute) {
			puts("This is an acute triangle.");
		}
		if (isRightAngle) {
			puts("This is a right angle triangle.");
		}
		if (isObtuse) {
			puts("This is an obtuse triangle.");
		}
	}
	else {
		printf("The angles %d, %d, and %d and the sides %d, %d, and %d cannot make a triangle.\n", angle1, angle2, angle3, side1, side2, side3);
	}

	return EXIT_SUCCESS;
}
