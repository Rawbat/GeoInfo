/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef SURFACE_H
#define SURFACE_H

#include <string>

/// <summary>The abstract class all surfaces are inhereting from.</summary>
class Surface {
	public:
      /// <summary>Calculates and returns the area of the surface. Must be implemented.</summary>
      /// <returns>A double containing the surface area.</returns> 
		virtual double getArea() const = 0;

      /// <summary>Returns the id of the surface.</summary>
      /// <returns>An integer containing the id.</returns> 
		int getId() const { return id_m; }

      /// <summary>Returns the name of the surface.</summary>
      /// <returns>A string containing the name.</returns> 
		std::string getName() const { return name_m; }

      /// <summary>Sets the name of the surface.</summary>
      /// <param name="name">A string containing the new name.</param> 
		void setName(std::string name);

      /// <summary>The overloaded equal comparison operator. Returns a boolean with the result.</summary>
      /// <param name="other">The surface to be compared with.</param>  
      /// <returns>True if the passed surface is equal to this one.</returns> 
		bool operator==(const Surface& other) const;

      /// <summary>The overloaded greater comparison operator. Returns a boolean with the result.</summary>
      /// <param name="other">The surface to be compared with.</param>  
      /// <returns>True if the passed surface is lesser to this one.</returns> 
		bool operator>(const Surface& other) const;

      /// <summary>The overloaded lesser comparison operator. Returns a boolean with the result.</summary>
      /// <param name="other">The surface to be compared with.</param>  
      /// <returns>True if the passed surface is greater to this one.</returns> 
		bool operator<(const Surface& other) const;

      /// <summary>Returns a string containing detailed and formatted information about the surface. Must be implemented.</summary>
      /// <returns>The string containing the information.</returns>
      virtual std::string prettyString() const = 0;

      /// <summary>The overloaded ostream operator. Returns an ostream containing information about the surface formatted for file storing.</summary>
      /// <param name="out">The ostream to be filled with the information.</param>  
      /// <param name="surface">The surface to fill the ostream.</param>
      /// <returns>The ostream containing the information.</returns> 
		friend std::ostream& operator<<(std::ostream& out, const Surface& surface);
		
	protected:
      /// <summary>The unique id of the surface.</summary>
		int id_m;

      /// <summary>The name of the surface. Depending on its type.</summary>
		std::string name_m;

	private:
      /// <summary>Helper function that calls the overloaded ostream function. Needed because of inheritance.</summary>
      /// <returns>The ostream returned by the overloaded ostream function. Must be implemented.</returns> 
		virtual std::ostream& print(std::ostream& out) const = 0;
		
};

#endif
