#ifndef CIRCLE_SECTOR_H
#define CIRCLE_SECTOR_H

#include "surface.h"
#include "point.h"

class circleSector : public Surface {
	public:
		//Constructors
		circleSector(Point center, int radius, double aperture, Point opening_point);

		//Getter
		Point getCenter() { return center_m; }
		int getRadius() { return radius_m; }
		double getAperture() { return aperture_m; }
		Point getOpeningPoint() { return opening_point_m; }

		//Setter
		void setCenter();
		void setRadius();
		void setAperture();
		void setOpeningPoint();

		//Destructor
		//~circleSector();

	private:
		Point center_m;
		int radius_m;
		double aperture_m;
		Point opening_point_m;

};

#endif