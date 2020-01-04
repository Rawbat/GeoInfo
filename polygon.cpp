#include "polygon.h"
#include "math.h"
#include <cmath>
#define _USE_MATH_DEFINES

Polygon::Polygon(int id, std::vector<Point> points) {
	if (points.size() <= 2) {
		//Throw invalid number of points exception
	}
	Point *last_point = nullptr;

	for (unsigned int p = 0; p < points.size() - 1; p++) {
		edges_m.push_back(Line(points.at(p), points.at(p + 1)));
	}

	id_m = id;
	setName("POLYGON");

	//TODO check for intersections
}

Polygon::Polygon(int id, std::vector<Line> edges) {
	if (edges.size() <= 2) {
		//Throw invalid number of points exception
	}
	edges_m = edges;

	id_m = id;
	setName("POLYGON");

	//TODO check for intersections
}

double Polygon::getArea() const {
	double area = 0;
	double fine_addition;
	double x1, x2, y1, y2;
	for (unsigned i = 0; i < getEdges().size()-1; i++) { 
		x1 = edges_m[i].getPoints().first.getX();
		x2 = edges_m[i+1].getPoints().first.getX();
		y1 = edges_m[i].getPoints().first.getY();
		y2 = edges_m[i+1].getPoints().first.getY();

		fine_addition = x1 * y2 - y1 * x2;
		area += fine_addition;
	}
	//TODO fix this 
	area = abs(area)/2;
	return area;
}

std::string Polygon::prettyString() const {
	std::string return_string;

	return_string = "ID: " + std::to_string(getId()) + "";
	return_string += "\nType: " + getName();
	return_string += "\nArea: " + std::to_string(getArea());

	return_string += "\nPoints: ";

	//Print first point of all edges
	for (Line edge : edges_m) {
		return_string += " (" + std::to_string(edge.getPoints().first.getX()) + ", " + std::to_string(edge.getPoints().first.getY()) + ")";
	}
	//Print second point of last edge
	return_string += " (" + std::to_string(edges_m.at(edges_m.size() - 1).getPoints().second.getX()) + ", " + std::to_string(edges_m.at(edges_m.size() - 1).getPoints().second.getY()) + ")";

	return return_string;
}

std::ostream& operator<<(std::ostream& out, const Polygon& polygon) {
	out << polygon.getName() << " " << polygon.getId();
	
	std::vector<Line> edges = polygon.getEdges();
	//Print first point of all edges
	for (Line edge : edges) {
		out << " (" << edge.getPoints().first.getX() << ", " << edge.getPoints().first.getY() << ")";
	}
	//Print second point of last edge
	out << " (" << edges.at(edges.size() - 1).getPoints().second.getX() << ", " << edges.at(edges.size() - 1).getPoints().second.getY() << ")";
	return out;
}

std::ostream& Polygon::print(std::ostream& out) const {
	return out << *this;
}

Polygon::~Polygon() {

}