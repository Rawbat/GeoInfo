#ifndef CIRCLE_H
#define CIRCLE_H

#include "surface.h"
#include "point.h"

class Circle : public Surface {
	public:
		//Contructors
		Circle(Point center, int radius = 1);
	private:
		Point center_m;
		int radius_m;
};

#endif
