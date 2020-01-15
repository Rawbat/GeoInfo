#include <iostream>
#include "circle.h"

#include "application.h"

#include "point.h"
#include "line.h"

int main() {

 

  /*Point p1(-2, 0);
  Point p2(2, 4);
  Point q(-1, 3);
  Point r(2, 2);

  //> 0 => q is left
  //< 0 => q is right
  //= 0 => q is on
  double det_q = p1.getX() * p2.getY() + p2.getX() * q.getY() + q.getX() * p1.getY()
               - p2.getY() * q.getX() - q.getY() * p1.getX() - p1.getY() * p2.getX();

  double det_r = p1.getX() * p2.getY() + p2.getX() * r.getY() + r.getX() * p1.getY()
    - p2.getY() * r.getX() - r.getY() * p1.getX() - p1.getY() * p2.getX();

  if (det_q == 0 || det_r == 0) {
    std::cout << "point on line" << std::endl;
  }
  else if ((det_q < 0 && det_r > 0) || (det_q > 0 && det_r < 0)) {
    std::cout << "test1 successful" << std::endl;

    double a = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
    double b = p1.getY() - (a * p1.getX());
    double c = (q.getY() - r.getY()) / (q.getX() - r.getX());
    double d = q.getY() - (c * q.getX());

    double x = (d - b) / (a - c);

    std::cout << x << std::endl;

    Point s(x, a * x + b);
    
    double distance_p1_s = std::sqrt(std::pow(p1.getX() - s.getX(), 2) + std::pow(p1.getY() - s.getY(), 2));
    double distance_p1_p2 = std::sqrt(std::pow(p1.getX() - p2.getX(), 2) + std::pow(p1.getY() - p2.getY(), 2));
    if (distance_p1_s < distance_p1_p2) {
      std::cout << "test2 successful" << std::endl;
    }
    //std::cout << lambda << std::endl;
  }

  std::cout << det_q << std::endl;*/

  Circle test(1, Point(2, 2));

	Application application;
	application.run();

	return 0;
}