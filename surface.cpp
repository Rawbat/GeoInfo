#include "surface.h"

void Surface::setName(std::string name) {
	name_m = name;
}

std::ostream& operator<<(std::ostream& out, const Surface& surface) {
	return surface.print(out);
}