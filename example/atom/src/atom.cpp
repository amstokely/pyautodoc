
#include "../include/atom.h"

Atom::Atom () = default;

Atom::Atom (
		int index,
		const std::string &name,
		const std::string &element,
		const std::string &residueName,
		int residueId,
		const std::string &chainId,
		const std::string &segmentId,
		double temperatureFactor,
		double occupancy,
		int serial,
		double mass
) {
	this->_index = index;
	this->_name = name;
	this->_element = element;
	this->_residueName = residueName;
	this->_residueId = residueId;
	this->_chainId = chainId;
	this->_segmentId = segmentId;
	this->_temperatureFactor = temperatureFactor;
	this->_occupancy = occupancy;
	this->_serial = serial;
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

std::string Atom::chainId () {
	return _chainId;
}

std::string Atom::segmentId () {
	return _segmentId;
}

double Atom::temperatureFactor () const {
	return _temperatureFactor;
}

double Atom::occupancy () const {
	return _occupancy;
}

int Atom::serial () const {
	return _serial;
}

double Atom::mass() const {
	return this->_mass;
}
