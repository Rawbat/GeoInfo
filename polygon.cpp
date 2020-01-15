/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#include "polygon.h"
#include "math.h"
#include <cmath>
#define _USE_MATH_DEFINES

#define LEFT 1
#define RIGHT -1
#define ON 0

//-----------------------------------------------------------------------------
Polygon::Polygon(int id, std::vector<Point> points) {
	if (points.size() <= 2) {
		throw std::invalid_argument("[Error] Too few points in polygon: " + std::to_string(points.size()) + "; 3 required");
	}

	for (unsigned int p = 0; p < points.size() - 1; p++) {
		edges_m.push_back(Line(points.at(p), points.at(p + 1)));
	}

	id_m = id;
	setName("POLYGON");

   //TODO check if polygon is closed

   if (doesSelfIntersect()) {
     std::cout << "Intersection" << std::endl;
     throw std::invalid_argument("Polygon with id: " + std::to_string(id) + " does self intersect. Only non self intersecting polygons are allowed.");
   }
}

//-----------------------------------------------------------------------------
bool Polygon::doesSelfIntersect() {
  for (int i = 0; i < edges_m.size(); i++) {
    Point p1 = edges_m.at(i).getPoints().first;
    Point p2 = edges_m.at(i).getPoints().second;

    for (int j = i + 1; j < edges_m.size(); j++) {
      Point q1 = edges_m.at(j).getPoints().first;
      Point q2 = edges_m.at(j).getPoints().second;

      int pos_q1 = relativePositionTo(p1, p2, q1);
      int pos_q2 = relativePositionTo(p1, p2, q2);

      if (pos_q1 == ON || pos_q2 == ON) {
        continue;
      }
      else if ((pos_q1 == RIGHT && pos_q2 == LEFT) || (pos_q1 == LEFT && pos_q2 == RIGHT)) {
        Point s = getIntersection(p1, p2, q1, q2);

        double distance_p1_s = getEuclidianDistance(p1, s);
        double distance_p1_p2 = getEuclidianDistance(p1, p2);

        //If true the intersection point of the linear equation lies on the line
        //That means there is an intersection
        if (distance_p1_s < distance_p1_p2) {
          return true;
        }
      }
    }
  }
  return false;
}

//-----------------------------------------------------------------------------
int Polygon::relativePositionTo(Point p1, Point p2, Point q) {
  //Calculate the determinant:
  // (p1_x  p2_x  q_x)
  // (p1_y  p2_y  q_y)
  // (1     1     1  )
  double det_q = p1.getX() * p2.getY() + p2.getX() * q.getY() + q.getX() * p1.getY()
    - p2.getY() * q.getX() - q.getY() * p1.getX() - p1.getY() * p2.getX();

  if (det_q < 0) {
    return RIGHT;
  }
  else if (det_q > 0) {
    return LEFT;
  }
  else {
    return ON;
  }
}

//-----------------------------------------------------------------------------
Point Polygon::getIntersection(Point p1, Point p2, Point q1, Point q2) {
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
double Polygon::getEuclidianDistance(Point p1, Point p2) {
  return std::sqrt(std::pow(p1.getX() - p2.getX(), 2) + std::pow(p1.getY() - p2.getY(), 2));
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
std::ostream& Polygon::print(std::ostream& out) const {
	return out << *this;
}

//-----------------------------------------------------------------------------
Polygon::~Polygon() {

}