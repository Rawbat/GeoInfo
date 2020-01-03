#ifndef CIRCLE_SECTOR_H
#define CIRCLE_SECTOR_H

#include "surface.h"
#include "point.h"

class CircleSector : public Surface {
	public:
		//Constructors
		CircleSector(int id, Point center, double radius, Point opening_point, double aperture);

		//Getter
		Point getCenter() const { return center_m; }
		double getRadius() const { return radius_m; }
		double getAperture() const { return aperture_m; }
		Point getOpeningPoint() const { return opening_point_m; }
		virtual double getArea() const;


		//Setter
		void setCenter(Point center);
		void setCenter(double x, double y);
		void setRadius(double radius);
		void setAperture(double aperture);
		void setOpeningPoint(Point opening_point);
		void setOpeningPoint(double x, double y);

		std::string prettyString() const;
		friend std::ostream& operator<<(std::ostream& out, const CircleSector& circleSector);
		std::ostream& print(std::ostream& out) const;

		//Destructor
		//~circleSector();

	private:
		Point center_m;
		double radius_m;
		double aperture_m;
		Point opening_point_m;

};

#endif