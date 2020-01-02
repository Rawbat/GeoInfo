#include "point.h"
#include "circle.h"


Circle::Circle(int id, Point center, int radius) {
	center_m = center;
	radius_m = radius;
	id_m = id;
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
	//TODO calculate and return area
	return area;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
	out << "(" << circle.getCenter().getX() << ", " << circle.getCenter().getY() << ") " << circle.getRadius();
	return out;
}