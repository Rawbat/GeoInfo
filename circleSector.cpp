#include "circleSector.h"
#define _USE_MATH_DEFINES
#include "math.h"

CircleSector::CircleSector(int id, Point center, int radius, double aperture, Point opening_point) {
	id_m = id;
	center_m = center;
	radius_m = radius;
	aperture_m = aperture;
	opening_point_m = opening_point;
}

std::ostream& operator<<(std::ostream& out, const CircleSector& circleSector) {
	out << circleSector.getName() << " " << circleSector.getId();
	return out;
}

std::ostream& CircleSector::print(std::ostream& out) const {
	return out << *this;
}

void CircleSector::setCenter(int x, int y) {
	center_m = Point(x, y);
}

void CircleSector::setCenter(Point center) {
	center_m = center;
}

void CircleSector::setRadius(int radius) {
	radius_m = radius;
}

void CircleSector::setAperture(double aperture) {
	aperture_m = aperture;
}

void CircleSector::setOpeningPoint(int x, int y) {
	opening_point_m = Point(x, y);
}
void CircleSector::setOpeningPoint(Point opening_point) {
	opening_point_m = opening_point;
}

double const CircleSector::getArea() {
	double area;
	area = (M_PI * aperture_m / 180) * std::pow(getRadius(), 2);
	return area;
}