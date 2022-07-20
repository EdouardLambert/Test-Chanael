#include <stdlib.h>
#include <stdio.h>
#include "header.h"

Point milieu(Point a, Point b) {
	Point mid;
	mid.x = (a.x + b.x) / 2;
	mid.y = (a.y + b.y) / 2;
	return mid;
}

int main() {

	Point a;
	a.x = 2;
	a.y = 8;
	Point b;
	b.x = 4;
	b.y = -3,5;
	printf("\nA(%f, %f)", a.x, a.y);
	printf("\nB(%f, %f)", b.x, b.y);
	Point mid = milieu(a, b);
	printf("\nCoords du milieu : (%f, %f)", mid.x, mid.y);

	return EXIT_SUCCESS;
}