#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
	public:

		//Constructors
		Point();
		Point(int x, int y);

		//Getter
		int getX() const { return x_m; }
		int getY() const { return y_m; }

		//Setter
		void setX(int x);
		void setY(int y);

		//Overloaded Operators
		friend std::ostream& operator<<(std::ostream& out, const Point& point);

		//Destructor
		~Point();
	private:
		int x_m;
		int y_m;
};

#endif
