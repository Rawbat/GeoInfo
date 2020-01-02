#ifndef CIRCLE_H
#define CIRCLE_H

#include "surface.h"
#include "point.h"

class Circle : public Surface {
	public:
		//Contructors
		Circle(Point center, int radius = 1);

		//Getter
		Point getCenter() { return center_m; }
		int getRadius() { return radius_m; }

		//Setter
		void setCenter(int x, int y);
		void setCenter(Point center);
		void setRadius(int radius);

		//Destructor
		//~Circle();

	private:
		Point center_m;
		int radius_m;

		

};

#endif
