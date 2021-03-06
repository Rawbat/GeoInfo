/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef POLYGON_H
#define POLYGON_H

#include "surface.h"
#include "point.h"
#include "line.h"
#include <vector>

/// <summary>A surface type defined by edges.</summary>
class Polygon : public Surface{
	public:
		//Constructors
		Polygon(int id, std::vector<Point> points);

      /// <summary>Returns the edges of the polygon as a vector.</summary>
      /// <returns>The vector containing the edges.</returns> 
		std::vector<Line> getEdges() const { return edges_m; }

      /// <summary>Calculates and returns the area of the polygon.</summary>
      /// <returns>A double containing the polygon area.</returns> 
		double getArea() const;

      /// <summary>Returns a string containing detailed and formatted information about the polygon.</summary>
      /// <returns>The string containing the information.</returns> 
		std::string prettyString() const;

      /// <summary>The overloaded ostream operator. Returns an ostream containing information about the polygon formatted for file storing.</summary>
      /// <param name="out">The ostream to be filled with the information.</param>  
      /// <param name="polygon">The polygon to fill the ostream.</param>
      /// <returns>The ostream containing the information.</returns> 
		friend std::ostream& operator<<(std::ostream& out, const Polygon& polygon);  
      
	private: 
     /// <summary>The edges defining the polygon.</summary>
	  std::vector<Line> edges_m;

     /// <summary>Checks if the polygon does self intersect and returns the result.</summary>
     /// <returns>A boolean value set to true if the polygon does self intersect.</returns> 
     bool doesSelfIntersect() const;

     /// <summary>Performs additional intersection tests on point q with line defined by p1 and p2.</summary>
     /// <param name="p1">First point of the line.</param>
     /// <param name="p2">Second point of the line.</param> 
     /// <param name="q">Point to perform intersection tests on.</param> 
     /// <returns>A boolean value set to true if an intersection occured.</returns> 
     bool checkAdditionalPointIntersectionCriteria(Point p1, Point p2, Point q) const;

     /// <summary>Helper function that calls the overloaded ostream function. Needed because of inheritance.</summary>
     /// <returns>The ostream returned by the overloaded ostream function.</returns> 
     std::ostream& print(std::ostream& out) const;
};

#endif
