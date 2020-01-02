#ifndef POLYGON_H
#define POLYGON_H

#include "surface.h"
#include "point.h"
#include <vector>

class Polygon {
	public:
		//Constructors
		Polygon();
		Polygon(std::vector<Point> points_m);

		//Getter
		std::vector<Point> getPoints() { return points_m; }

		//Setter
		void setPoints(std::vector<Point> points);

		//Destructor
		~Polygon();
	private:
		std::vector<Point> points_m;
};

#endif
