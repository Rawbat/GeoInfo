#ifndef SURFACE_H
#define SURFACE_H

class Surface {
	public:
		//Constructors
		//Surface();

		virtual double getArea() const = 0;
		int getId() const { return id_m; }
	protected:
		int id_m;
};

#endif
