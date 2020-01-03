#ifndef CIRCLE_H
#define CIRCLE_H

#include "surface.h"
#include "point.h"

class Circle : public Surface {
	public:
		//Contructors
		Circle(int id, Point center, double radius = 1);

		//Getter
		Point getCenter() const { return center_m; }
		double getRadius() const { return radius_m; }

		//Setter
		void setCenter(double x, double y);
		void setCenter(Point center);
		void setRadius(double radius);

		virtual double getArea() const;

		std::string prettyString() const;

		//Destructor
		//~Circle();
		friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
		std::ostream& print(std::ostream& out) const;
	private:
		Point center_m;
		double radius_m;

		

};

#endif
