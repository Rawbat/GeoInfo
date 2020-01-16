/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef LINE_H
#define LINE_H

#include <utility>
#include "point.h"
#include <iostream>

/// <summary>A class containing a pair of points representing a line between them.</summary>
class Line {
	public:
		//Constructors
		Line();
		Line(Point a, Point b);
		Line(std::pair<Point, Point> points);

      /// <summary>Returns the end points of the line.</summary>
      /// <returns>The end points as a std::pair.</returns>
		std::pair<Point, Point> getPoints() const { return  points_m; }
		
      /// <summary>Takes two points and sets the line points.</summary>
      /// <param name="a">The new first point of the line.</param> 
      /// <param name="b">The new second point of the line.</param> 
      void setPoints(Point a, Point b);

      /// <summary>Takes a pair of points and sets the line points.</summary>
      /// <param name="points">The two points as a std::pair.</param> 
		void setPoints(std::pair<Point, Point> points);
      
      /// <summary>Calculates the intersection point of this and the passed line and returns it.</summary>
      /// <param name="line">The line to be intersected with.</param> 
      /// <returns>The intersection point of the two lines.</returns>
      Point getIntersection(Line line) const;

      /// <summary>Calculates the determinant of the two line points and the passed point to determin its relative position to the line.</summary>
      /// <param name="q">The point which relative position is to be determined.</param> 
      /// <returns>The result of the determinant calculation.</returns>
      double getRelativePointPosition(Point q) const;

      /// <summary>The overloaded ostream operator. Returns an ostream containing information about the line.</summary>
      /// <param name="out">The ostream to be filled with the information.</param>  
      /// <param name="line">The line to fill the ostream.</param>
      /// <returns>The ostream containing the information.</returns> 
		friend std::ostream& operator<<(std::ostream& out, const Line& line);

	private:
      /// <summary>A std::pair of points to define the line.</summary>
		std::pair<Point, Point> points_m;
};


#endif