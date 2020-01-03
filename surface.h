#ifndef SURFACE_H
#define SURFACE_H

#include <string>

class Surface {
	public:
		//Constructors
		//Surface();

		virtual double getArea() const = 0;
		virtual std::string prettyString() const = 0;

		int getId() const { return id_m; }
		std::string getName() const { return name_m; }
		void setName(std::string name);

		friend std::ostream& operator<<(std::ostream& out, const Surface& surface);
		
	protected:
		int id_m;
		std::string name_m;

	private:
		virtual std::ostream& print(std::ostream& out) const = 0;
		
};

#endif
