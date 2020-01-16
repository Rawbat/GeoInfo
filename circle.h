/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "surface.h"
#include "point.h"

/// <summary>A surface type defined by a center point and radius.</summary>
class Circle : public Surface {
	public:
		//Contructors
		Circle(int id, Point center, double radius = 1);

      /// <summary>Returns the center of the circle.</summary>
      /// <returns>The center as a point.</returns>
		Point getCenter() const { return center_m; }

      /// <summary>Returns the radius of the circle.</summary>
      /// <returns>The radius as a double.</returns>
		double getRadius() const { return radius_m; }

      /// <summary>Calculates and returns the area of the circle.</summary>
      /// <returns>A double containing the circle area.</returns> 
      virtual double getArea() const;

      /// <summary>Takes an x and y coordinate and sets the center point of the circle.</summary>
      /// <param name="x">The x coordinate of the center.</param>  
      /// <param name="y">The y coordinate of the center.</param>
		void setCenter(double x, double y);

      /// <summary>Takes a point and sets the center point of the circle to it.</summary>
      /// <param name="center">The new center point</param>  
		void setCenter(Point center);

      /// <summary>Takes a double and sets the radius of the circle.</summary>
      /// <param name="center">The new circle radius.</param> 
		void setRadius(double radius);

      /// <summary>Returns a string containing detailed and formatted information about the circle.</summary>
      /// <returns>The string containing the information.</returns> 
		std::string prettyString() const;

      /// <summary>The overloaded ostream operator. Returns an ostream containing information about the circle formatted for file storing.</summary>
      /// <param name="out">The ostream to be filled with the information.</param>  
      /// <param name="circle">The circle to fill the ostream.</param>
      /// <returns>The ostream containing the information.</returns> 
		friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
      
	private:
      /// <summary>The center point of the circle.</summary>
		Point center_m;

      /// <summary>The radius of the circle.</summary>
		double radius_m;

      /// <summary>Helper function that calls the overloaded ostream function. Needed because of inheritance.</summary>
      /// <returns>The ostream returned by the overloaded ostream function.</returns> 
      std::ostream& print(std::ostream& out) const;
		

};

#endif
