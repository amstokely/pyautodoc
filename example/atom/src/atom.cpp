
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
	this->_index       = index;
	this->_name        = name;
	this->_element     = element;
	this->_residueName = residueName;
	this->_residueId   = residueId;
	this->_mass        = mass;
}

int Atom::index () const {
	return _index;
}

void Atom::index (int index) {
	this->_index = index;
}


std::string Atom::name () {
	return _name;
}

void Atom::name (std::string name) {
	this->_name = name;
}

std::string Atom::element () {
	return _element;
}

void Atom::element (std::string element) {
	this->_element = element;
}

std::string Atom::residueName () {
	return _residueName;
}

void Atom::residueName (std::string residueName) {
	this->_residueName = residueName;
}

int Atom::residueId () const {
	return _residueId;
}

void Atom::residueId (int residueId) {
	this->_residueId = residueId;
}

double Atom::mass () const {
	return this->_mass;
}

void Atom::mass (double mass) {
	this->_mass = mass;
}
