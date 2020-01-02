#include "point.h"

Point::Point()
	: x_m(0), y_m(0) {

}

Point::Point(int x, int y)
	: x_m(x), y_m(y) {

}

void Point::setX(int x) {
	x_m = x;
}

void Point::setY(int y) {
	y_m = y;
}

Point::~Point() {

}


