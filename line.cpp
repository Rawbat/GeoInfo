#include "line.h"
#include "point.h"

Line::Line() {
	points_m = std::make_pair(Point(), Point());

}

Line::Line(Point a, Point b) {
	points_m = std::make_pair(a, b);
}

Line::Line(std::pair<Point, Point> points) {
	points_m = points;
}


void Line::setPoints(std::pair<Point, Point> points) {
	points_m = points;
}

void Line::setPoints(Point a, Point b) {
	points_m = std::make_pair(a, b);
}

std::ostream& operator<<(std::ostream& out, const Line& line) {
	out << line.getPoints().first << "-" << line.getPoints().second;
	return out;
}


