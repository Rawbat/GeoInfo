#ifndef POLYGON_H
#define POLYGON_H

#include "surface.h"
#include "point.h"
#include "line.h"
#include <vector>

class Polygon : public Surface{
	public:
		//Constructors
		Polygon(int id, std::vector<Point> points);
		Polygon(int id, std::vector<Line> edges);

		//Getter
		std::vector<Line> getEdges() const { return edges_m; }

		//Setter
		void setEdges(std::vector<Line> edges);

		virtual double getArea() const;

		//Destructor
		~Polygon();
	private:
		std::vector<Line> edges_m;
};

#endif
