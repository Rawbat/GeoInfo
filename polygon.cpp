#include "polygon.h"
#include "math.h"
#include <cmath>
#define _USE_MATH_DEFINES

Polygon::Polygon(int id, std::vector<Point> points) {
	if (points.size() <= 2) {
		//Throw invalid number of points exception
	}
	Point *last_point = nullptr;
	for (Point point : points) {
		if (last_point == nullptr) {
			last_point = &point;
		}
		else {
			edges_m.push_back(Line(*last_point, point));
		}
	}

	id_m = id;
	setName("polygon");

	//TODO check for intersections
}

Polygon::Polygon(int id, std::vector<Line> edges) {
	if (edges.size() <= 2) {
		//Throw invalid number of points exception
	}
	edges_m = edges;

	id_m = id;
	setName("polygon");

	//TODO check for intersections
}

double Polygon::getArea() const {
	double area = 0;
	double fine_addition;
	int x1, x2, y1, y2;
	for (int i = 0; i < getEdges().size()-1; i++) {
		x1 = edges_m[i].getPoints().first.getX();
		x2 = edges_m[i+1].getPoints().first.getX();
		y1 = edges_m[i].getPoints().first.getY();
		y2 = edges_m[i+1].getPoints().first.getY();

		fine_addition = std::abs(x1 * y2 - y1 * x2)/2;
		area += fine_addition;
	}
	return area;
}

std::ostream& operator<<(std::ostream& out, const Polygon& polygon) {
	out << polygon.getName() << " " << polygon.getId();
	return out;
}

std::ostream& Polygon::print(std::ostream& out) const {
	return out << *this;
}

Polygon::~Polygon() {

}