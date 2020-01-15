#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
	public:

		//Constructors
		Point();
		Point(double x, double y);

		//Getter
		double getX() const { return x_m; }
		double getY() const { return y_m; }

		//Setter
		void setX(double x);
		void setY(double y);

      double getEuclidianDistance(Point point) const;

		//Overloaded Operators
		friend std::ostream& operator<<(std::ostream& out, const Point& point);

		//Destructor
		~Point();
	private:
		double x_m;
		double y_m;
};

#endif
