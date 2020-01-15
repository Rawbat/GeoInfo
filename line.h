#ifndef LINE_H
#define LINE_H

#include <utility>
#include "point.h"
#include <iostream>

class Line {
	public:
		//Constructors
		Line();
		Line(Point a, Point b);
		Line(std::pair<Point, Point> points);

		//Getter
		std::pair<Point, Point> getPoints() const { return  points_m; }
		
		//Setter
		void setPoints(std::pair<Point, Point> points);
		void setPoints(Point a, Point b); //overloaded

     // Point getIntersection(Point p1, Point p2, Point q1, Point q2);
      Point getIntersection(Line line) const;
      int getRelativePointPosition(Point q) const;

		friend std::ostream& operator<<(std::ostream& out, const Line& line);

		//Destructor
		//~Line();
	private:
		std::pair<Point, Point> points_m;
};


#endif