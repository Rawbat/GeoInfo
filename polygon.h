#ifndef POLYGON_H
#define POLYGON_H

#include "surface.h"
#include "point.h"
#include "line.h"
#include <vector>

class Polygon {
	public:
		//Constructors
		Polygon(std::vector<Point> points);
		Polygon(std::vector<Line> edges);

		//Getter
		std::vector<Line> getEdges() const { return edges_m; }

		//Setter
		void setEdges(std::vector<Line> edges);

		//Destructor
		~Polygon();
	private:
		std::vector<Line> edges_m;
};

#endif
