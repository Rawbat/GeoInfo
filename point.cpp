/*
Projekt: Fl�chenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#include "point.h"

//-----------------------------------------------------------------------------
Point::Point()
	: x_m(0), y_m(0) {

}

//-----------------------------------------------------------------------------
Point::Point(double x, double y)
	: x_m(x), y_m(y) {

}

//-----------------------------------------------------------------------------
void Point::setX(double x) {
	x_m = x;
}

//-----------------------------------------------------------------------------
void Point::setY(double y) {
	y_m = y;
}

//-----------------------------------------------------------------------------
double Point::getEuclidianDistance(const Point point) const {
  return std::sqrt(std::pow(getX() - point.getX(), 2) + std::pow(getY() - point.getY(), 2));
}

//-----------------------------------------------------------------------------
bool Point::operator!=(const Point& point) const {
  if (getX() != point.getX() || getY() != point.getY()) {
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << "(" << point.getX() << "|" << point.getY() << ")";
	return out;
}



