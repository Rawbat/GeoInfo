/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef POINT_H
#define POINT_H

#include <iostream>

/// <summary>A class containing two double values representing the coordinates of the point.</summary>
class Point {
	public:
		//Constructors
		Point();
		Point(double x, double y);

      /// <summary>Returns the x coordinate of the point.</summary>
      /// <returns>The x coordinate.</returns>
		double getX() const { return x_m; }

      /// <summary>Returns the y coordinate of the point.</summary>
      /// <returns>The y coordinate.</returns>
		double getY() const { return y_m; }

      /// <summary>Takes a double and sets the x coordinate of the point.</summary>
      /// <param name="x">The new x coordinate.</param>  
		void setX(double x);

      /// <summary>Takes a double and sets the y coordinate of the point.</summary>
      /// <param name="y">The new y coordinate.</param> 
		void setY(double y);

      /// <summary>Calculates the euclidian distance between this and the passed point.</summary>
      /// <param name="point">The point the distance to is going to be calculated.</param> 
      /// <returns>The euclidian distance between the two points as a double.</returns>
      double getEuclidianDistance(Point point) const;

      /// <summary>The overloaded not equal comparison operator. Returns a boolean with the result.</summary>
      /// <param name="point">The point to be compared with.</param>  
      /// <returns>True if the passed point is not equal to this one. That means if either the x or y coordinate is different.</returns> 
      bool operator!=(const Point& point) const;

      /// <summary>The overloaded ostream operator. Returns an ostream containing information about the point.</summary>
      /// <param name="out">The ostream to be filled with the information.</param>  
      /// <param name="point">The point to fill the ostream.</param>
      /// <returns>The ostream containing the information.</returns> 
		friend std::ostream& operator<<(std::ostream& out, const Point& point);

	private:
      /// <summary>The x coordinate of the point.</summary>
		double x_m;

      /// <summary>The y coordinate of the point.</summary>
		double y_m;
};

#endif
