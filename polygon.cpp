#include "polygon.h"

Polygon::Polygon(std::vector<Point> points) {
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
	//TODO check for intersections
}

Polygon::Polygon(std::vector<Line> edges) {
	if (edges.size() <= 2) {
		//Throw invalid number of points exception
	}
	edges_m = edges;

	//TODO check for intersections
}

Polygon::~Polygon() {

}