#include "point.h"
#include "circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

Circle::Circle(int id, Point center, int radius) {
	center_m = center;
	radius_m = radius;
	id_m = id;
	setName("circle");
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

double Circle::getArea() const {
	double area = 0;
	area = std::pow(getRadius(), 2) * M_PI;
	return area;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
	out << circle.getName() << " " << circle.getId() << " " << "(" << circle.getCenter().getX() << ", " << circle.getCenter().getY() << ") " << circle.getRadius();
	return out;
}

std::ostream& Circle::print(std::ostream& out) const {
	return out << *this;
}
