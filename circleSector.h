/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef CIRCLE_SECTOR_H
#define CIRCLE_SECTOR_H

#include "surface.h"
#include "point.h"

/// <summary>A surface type defined by a center point, radius, aperture and an opening point.</summary>
class CircleSector : public Surface {
	public:
		//Constructors
		CircleSector(int id, Point center, double radius = 1, Point opening_point, double aperture);

      /// <summary>Returns the center of the circle sector.</summary>
      /// <returns>The center as a point.</returns>
		Point getCenter() const { return center_m; }

      /// <summary>Returns the radius of the circle sector.</summary>
      /// <returns>The radius as a double.</returns>
		double getRadius() const { return radius_m; }

      /// <summary>Returns the aperture of the circle sector.</summary>
      /// <returns>The aperture as a double.</returns>
		double getAperture() const { return aperture_m; }

      /// <summary>Returns the opening point of the circle sector.</summary>
      /// <returns>The opening as a point.</returns>
		Point getOpeningPoint() const { return opening_point_m; }

      /// <summary>Calculates and returns the area of the circle sector.</summary>
      /// <returns>A double containing the circle sector area.</returns> 
		virtual double getArea() const;

      /// <summary>Takes an x and y coordinate and sets the center point of the circle sector.</summary>
      /// <param name="x">The x coordinate of the center.</param>  
      /// <param name="y">The y coordinate of the center.</param>
      void setCenter(double x, double y);

      /// <summary>Takes a point and sets the center point of the circle sector to it.</summary>
      /// <param name="center">The new center point.</param>  
		void setCenter(Point center);     

      /// <summary>Takes a double and sets the radius of the circle sector.</summary>
      /// <param name="center">The new circle sector radius.</param> 
		void setRadius(double radius);

      /// <summary>Takes a double and sets the aperture of the circle sector.</summary>
      /// <param name="aperture">The new circle sector aperture in degrees.</param> 
		void setAperture(double aperture);

      /// <summary>Takes a point and sets the opening point of the circle sector to it.</summary>
      /// <param name="opening_point">The new opening point.</param> 
		void setOpeningPoint(Point opening_point);

      /// <summary>Takes an x and y coordinate and sets the opening point of the circle sector.</summary>
      /// <param name="x">The x coordinate of the opening point.</param>  
      /// <param name="y">The y coordinate of the opening point.</param>
		void setOpeningPoint(double x, double y);

      /// <summary>Returns a string containing detailed and formatted information about the circle sector.</summary>
      /// <returns>The string containing the information.</returns> 
		std::string prettyString() const;

      /// <summary>The overloaded ostream operator. Returns an ostream containing information about the circle sector formatted for file storing.</summary>
      /// <param name="out">The ostream to be filled with the information.</param>  
      /// <param name="circleSector">The circle to fill the ostream.</param>
      /// <returns>The ostream containing the information.</returns> 
		friend std::ostream& operator<<(std::ostream& out, const CircleSector& circleSector);

	private:
      /// <summary>The center point of the circle sector.</summary>
		Point center_m;

      /// <summary>The radius of the circle sector.</summary>
		double radius_m;

      /// <summary>The aperture of the circle sector in degrees.</summary>
		double aperture_m;

      /// <summary>The opening point of the sector.</summary>
		Point opening_point_m;

      /// <summary>Helper function that calls the overloaded ostream function. Needed because of inheritance.</summary>
      /// <returns>The ostream returned by the overloaded ostream function.</returns> 
      std::ostream& print(std::ostream& out) const;
};

#endif