
#include "../include/atom.h"

Atom::Atom () = default;

Atom::Atom (
		int index,
		const std::string &name,
		const std::string &element,
		const std::string &residueName,
		int residueId,
		double mass
) {
	this->_index = index;
	this->_name = name;
	this->_element = element;
	this->_residueName = residueName;
	this->_residueId = residueId;
	this->_mass = mass;
}

int Atom::index () const {
	return _index;
}

std::string Atom::name () {
	return _name;
}

std::string Atom::element () {
	return _element;
}

std::string Atom::residueName () {
	return _residueName;
}

int Atom::residueId () const {
	return _residueId;
}

double Atom::mass() const {
	return this->_mass;
}
