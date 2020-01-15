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

      /// <summary>Helper function that calls the overloaded ostream function. Needed because of inheritance.</summary>
      /// <returns>The ostream returned by the overloaded ostream function.</returns> 
		std::ostream& print(std::ostream& out) const; 
      
		//Destructor
		~Polygon();
	private:
     /// <summary>Checks if the polygon does self intersect and returns the result.</summary>
     /// <returns>A boolean value set to true if the polygon does self intersect.</returns> 
     bool doesSelfIntersect() const;
     
     /// <summary>The edges defining the polygon.</summary>
	  std::vector<Line> edges_m;
};

#endif
