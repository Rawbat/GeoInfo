#include "circleSector.h"
#define _USE_MATH_DEFINES
#include "math.h"

CircleSector::CircleSector(int id, Point center, double radius, Point opening_point, double aperture) {
	id_m = id;
	center_m = center;
	radius_m = radius;
	aperture_m = aperture;
	opening_point_m = opening_point;
	setName("SECTOR");
}

std::string CircleSector::prettyString() const {
	std::string return_string;

	return_string = "ID: " + std::to_string(getId()) + "";
	return_string += "\nType: " + getName();
	return_string += "\nArea: " + std::to_string(getArea());
	return_string += "\nCenter: (" + std::to_string(getCenter().getX()) + ", " + std::to_string(getCenter().getY()) + ")";
	return_string += "\nRadius: " + std::to_string(getRadius());
	return_string += "\nOpening Point: (" + std::to_string(getOpeningPoint().getX()) + ", " + std::to_string(getOpeningPoint().getY()) + ")";
	return_string += "\nRadius: " + std::to_string(getAperture());

	return return_string;
}

std::ostream& operator<<(std::ostream& out, const CircleSector& circleSector) {
	out << circleSector.getName() << " " << circleSector.getId() << " (" << circleSector.getCenter().getX() << ", " << circleSector.getCenter().getY() << ") "
		<< circleSector.getRadius() << " (" << circleSector.getOpeningPoint().getX() << ", " << circleSector.getOpeningPoint().getY() << ") " << circleSector.getAperture();
	return out;
}

std::ostream& CircleSector::print(std::ostream& out) const {
	return out << *this;
}

void CircleSector::setCenter(double x, double y) {
	center_m = Point(x, y);
}

void CircleSector::setCenter(Point center) {
	center_m = center;
}

void CircleSector::setRadius(double radius) {
	radius_m = radius;
}

void CircleSector::setAperture(double aperture) {
	aperture_m = aperture;
}

void CircleSector::setOpeningPoint(double x, double y) {
	opening_point_m = Point(x, y);
}
void CircleSector::setOpeningPoint(Point opening_point) {
	opening_point_m = opening_point;
}

double CircleSector::getArea() const {
	double area;
	area = (M_PI * aperture_m / 180) * std::pow(getRadius(), 2);
	return area;
}