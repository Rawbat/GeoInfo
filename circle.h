#ifndef CIRCLE_H
#define CIRCLE_H

#include "surface.h"
#include "point.h"

class Circle : public Surface {
	public:
		//Contructors
		Circle(int id, Point center, int radius = 1);

		//Getter
		Point getCenter() const { return center_m; }
		int getRadius() const { return radius_m; }

		//Setter
		void setCenter(int x, int y);
		void setCenter(Point center);
		void setRadius(int radius);

		virtual double getArea() const;

		//Destructor
		//~Circle();
		friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
		std::ostream& print(std::ostream& out) const;
	private:
		Point center_m;
		int radius_m;

		

};

#endif
