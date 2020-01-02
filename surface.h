#ifndef SURFACE_H
#define SURFACE_H

class Surface {
	public:
		//Constructors
		//Surface();

		virtual double getArea() const = 0;
	private:
		int id_m;
};

#endif
