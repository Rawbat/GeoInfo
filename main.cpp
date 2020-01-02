#include <iostream>
#include "circle.h"
#include "point.h"
#include "line.h"

int main() {
	std::cout << "Hello World" << std::endl;

	Point point1(5, 3);
	std::cout << point1 << std::endl;
	Point point2(8, 6);
	std::cout << point2 << std::endl;

	Line line(point1, point2);
	std::cout << line << std::endl;

	Circle Kreis;
	Kreis = Circle(Point(2, 4), 1);

	int temp;
	std::cin >> temp;



	return 0;
}