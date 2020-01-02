#ifndef CIRCLE_SECTOR_H
#define CIRCLE_SECTOR_H

#include "surface.h"
#include "point.h"

class CircleSector : public Surface {
	public:
		//Constructors
		CircleSector(int id, Point center, int radius, double aperture, Point opening_point);

		//Getter
		Point getCenter() const { return center_m; }
		int getRadius() const { return radius_m; }
		double getAperture() const { return aperture_m; }
		Point getOpeningPoint() const { return opening_point_m; }
		double const getArea();

		//Setter
		void setCenter(Point center);
		void setCenter(int x, int y);
		void setRadius(int radius);
		void setAperture(double aperture);
		void setOpeningPoint(Point opening_point);
		void setOpeningPoint(int x, int y);

		friend std::ostream& operator<<(std::ostream& out, const CircleSector& circleSector);
		std::ostream& print(std::ostream& out) const;

		//Destructor
		//~circleSector();

	private:
		Point center_m;
		int radius_m;
		double aperture_m;
		Point opening_point_m;

};

#endif