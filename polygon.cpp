/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#include "polygon.h"
#include "math.h"
#include <cmath>
#define _USE_MATH_DEFINES


//-----------------------------------------------------------------------------
Polygon::Polygon(int id, std::vector<Point> points) {
	if (points.size() <= 2) {
		throw std::invalid_argument("[Error] Too few points in polygon: " + std::to_string(points.size()) + "; 3 required");
	}

   for (int i = 0; i < points.size(); i++) {
     for (int j = i + 1; j < points.size(); j++) {
       if (points.at(i) == points.at(j)) {
         throw std::invalid_argument("[Error] Polygon with id: " + std::to_string(id) + " contains the same point twice which is not allowed.");
       }
     }
   }

	for (unsigned int p = 0; p < points.size() - 1; p++) {
		edges_m.push_back(Line(points.at(p), points.at(p + 1)));
	}
   edges_m.push_back(Line(points.at(points.size() - 1), points.at(0)));

	id_m = id;
	setName("POLYGON");

   if (doesSelfIntersect()) {
     throw std::invalid_argument("[Error] Polygon with id: " + std::to_string(id) + " does self intersect. Only non self intersecting polygons are allowed.");
   }
}

//-----------------------------------------------------------------------------
bool Polygon::doesSelfIntersect() const {
  for (int i = 0; i < edges_m.size(); i++) {
    Point p1 = edges_m.at(i).getPoints().first;
    Point p2 = edges_m.at(i).getPoints().second;

    for (int j = 0; j < edges_m.size(); j++) {
      if (i == j) {
        continue;
      }
      Point q1 = edges_m.at(j).getPoints().first;
      Point q2 = edges_m.at(j).getPoints().second;

      //Calculates if the points are left, right or on the line
      double pos_q1 = edges_m.at(i).getRelativePointPosition(q1);
      double pos_q2 = edges_m.at(i).getRelativePointPosition(q2);

      //True if q1 is on the line
      if (pos_q1 == 0) {
        if (checkAdditionalPointIntersectionCriteria(p1, p2, q1)) {
          return true;
        }
      }
      //True if q2 is on the line
      if (pos_q2 == 0) {
        if (checkAdditionalPointIntersectionCriteria(p1, p2, q2)) {
          return true;
        }
      }
      //True if the points are on opposite sides of the line
      else if ((pos_q1 < 0 && pos_q2 > 0) || (pos_q1 > 0 && pos_q2 < 0)) {
        Point s = edges_m.at(i).getIntersection(edges_m.at(j));

        double distance_p1_p2 = p1.getEuclidianDistance(p2);
        double distance_p1_s = p1.getEuclidianDistance(s);
        double distance_p2_s = p2.getEuclidianDistance(s);

        //True if s is actually between p1 and p2 on the line
        if (distance_p1_s < distance_p1_p2 && distance_p2_s < distance_p1_p2) {
          return true;
        }
      }
    }
  }
  return false;
}

//-----------------------------------------------------------------------------
bool Polygon::checkAdditionalPointIntersectionCriteria(Point p1, Point p2, Point q) const {
  if (q != p1 && q != p2) {
    double distance_p1_p2 = p1.getEuclidianDistance(p2);
    double distance_p1_q = p1.getEuclidianDistance(q);
    double distance_p2_q = p2.getEuclidianDistance(q);

    //True if q is actually between p1 and p2 on the line
    if (distance_p1_q < distance_p1_p2 && distance_p2_q < distance_p1_p2) {
      return true;
    }
  }
  return false;
}

//-----------------------------------------------------------------------------
double Polygon::getArea() const {
  double area = 0;
  double fine_addition;
  double x1, x2, y1, y2;
  for (unsigned i = 0; i < getEdges().size(); i++) {
    x1 = edges_m[i].getPoints().first.getX();
    x2 = edges_m[i].getPoints().second.getX();
    y1 = edges_m[i].getPoints().first.getY();
    y2 = edges_m[i].getPoints().second.getY();

    fine_addition = x1 * y2 - y1 * x2;
    area += fine_addition;
  }
  area = abs(area) / 2;
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

	return out;
}

//-----------------------------------------------------------------------------
std::ostream& Polygon::print(std::ostream& out) const {
	return out << *this;
}
