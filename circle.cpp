#include "point.h"
#include "circle.h"


Circle::Circle(Point center, int radius = 1) {
	center_m = center;
	radius_m = radius;
}


//Setter
void Circle::setCenter(int x, int y) {
	center_m = Point(x, y);
}

void Circle::setCenter(Point center) {
	center_m = center;
}

void Circle::setRadius(int radius) {
	radius_m = radius;
}

