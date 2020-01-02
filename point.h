#ifndef POINT_H
#define POINT_H

class Point {
	public:

		//Constructors
		Point();
		Point(int x, int y);

		//Getter
		int getX() { return x_m; }
		int getY() { return y_m; }

		//Setter
		void setX(int x);
		void setY(int y);

		//Destructor
		~Point();
	private:
		int x_m;
		int y_m;
};

#endif
