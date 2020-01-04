#include "surface.h"

void Surface::setName(std::string name) {
	name_m = name;
}

std::ostream& operator<<(std::ostream& out, const Surface& surface) {
	return surface.print(out);
}


bool  Surface::operator==(const Surface& other) const { 
	if (this->getArea() == other.getArea() ) {
		return true;
	}
	return false;
}

bool  Surface::operator>(const Surface& other) const {
	if (this->getArea() > other.getArea()) {
		return true;
	}
	return false;
}

bool  Surface::operator<(const Surface& other) const {
	if (this->getArea() < other.getArea()) {
		return true;
	}
	return false;
}