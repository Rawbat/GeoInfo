#include "circleSector.h"

std::ostream& operator<<(std::ostream& out, const CircleSector& circleSector) {
	out << circleSector.getName() << " " << circleSector.getId();
	return out;
}

std::ostream& CircleSector::print(std::ostream& out) const {
	return out << *this;
}