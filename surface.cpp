/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#include "surface.h"

//-----------------------------------------------------------------------------
void Surface::setName(std::string name) {
	name_m = name;
}

//-----------------------------------------------------------------------------
bool Surface::operator==(const Surface& other) const { 
	if (getArea() == other.getArea() ) {
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
bool Surface::operator>(const Surface& other) const {
	if (getArea() > other.getArea()) {
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
bool Surface::operator<(const Surface& other) const {
	if (getArea() < other.getArea()) {
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const Surface& surface) {
  return surface.print(out);
}