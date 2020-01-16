/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#include "line.h"
#include "point.h"

//-----------------------------------------------------------------------------
Line::Line() {
	points_m = std::make_pair(Point(), Point());

}

//-----------------------------------------------------------------------------
Line::Line(Point a, Point b) {
	points_m = std::make_pair(a, b);
}

//-----------------------------------------------------------------------------
Line::Line(std::pair<Point, Point> points) {
	points_m = points;
}

//-----------------------------------------------------------------------------
void Line::setPoints(Point a, Point b) {
  points_m = std::make_pair(a, b);
}

//-----------------------------------------------------------------------------
void Line::setPoints(std::pair<Point, Point> points) {
	points_m = points;
}

//-----------------------------------------------------------------------------
Point Line::getIntersection(const Line line) const {
  Point p1 = getPoints().first;
  Point p2 = getPoints().second;

  Point q1 = line.getPoints().first;
  Point q2 = line.getPoints().second;

  //Create linear equation y = a * x + b
  double a = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
  double b = p1.getY() - (a * p1.getX());

  //Create linear equation y = c * x + d
  double c = (q1.getY() - q2.getY()) / (q1.getX() - q2.getX());
  double d = q1.getY() - (c * q1.getX());

  //Solve for intersect x coordinated
  double x = (d - b) / (a - c);

  //Return intersect point
  return Point(x, a * x + b);
}

//-----------------------------------------------------------------------------
double Line::getRelativePointPosition(const Point q) const {
  Point p1 = getPoints().first;
  Point p2 = getPoints().second;

  //Calculate the determinant:
  // (p1_x  p2_x  q_x)
  // (p1_y  p2_y  q_y)
  // (1     1     1  )
  double det_q = p1.getX() * p2.getY() + p2.getX() * q.getY() + q.getX() * p1.getY()
    - p2.getY() * q.getX() - q.getY() * p1.getX() - p1.getY() * p2.getX();

  return det_q;
}

//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const Line& line) {
	out << line.getPoints().first << "-" << line.getPoints().second;
	return out;
}


