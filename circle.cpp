#include "point.h"
#include "circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

Circle::Circle(int id, Point center, double radius) {
	center_m = center;
	radius_m = radius;
	id_m = id;
	setName("CIRCLE");
}


//Setter
void Circle::setCenter(double x, double y) {
	center_m = Point(x, y);
}

void Circle::setCenter(Point center) {
	center_m = center;
}

void Circle::setRadius(double radius) {
	radius_m = radius;
}

double Circle::getArea() const {
	double area = 0;
	area = std::pow(getRadius(), 2) * M_PI;
	return area;
}

std::string Circle::prettyString() const{
	std::string return_string;

	return_string = "ID: " + std::to_string(getId()) + "";
	return_string += "\nType: " + getName();
	return_string += "\nArea: " + std::to_string(getArea());
	return_string += "\nCenter: (" + std::to_string(getCenter().getX()) + ", " + std::to_string(getCenter().getY()) + ")";
	return_string += "\nRadius: " + std::to_string(getRadius());

	return return_string;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
	out << circle.getName() << " " << circle.getId() << " " << "(" << circle.getCenter().getX() << ", " << circle.getCenter().getY() << ") " << circle.getRadius();
	return out;
}

std::ostream& Circle::print(std::ostream& out) const {
	return out << *this;
}
