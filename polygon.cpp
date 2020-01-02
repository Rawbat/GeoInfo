#include "polygon.h"

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
	//TODO calculate and return area
	return area;
}

std::ostream& operator<<(std::ostream& out, const Polygon& polygon) {
	out << polygon.getName() << " " << polygon.getId();
	return out;
}

std::ostream& Polygon::print(std::ostream& out) const {
	return out << this;
}

Polygon::~Polygon() {

}