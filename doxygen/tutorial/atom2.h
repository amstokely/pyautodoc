#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>


/*!
* @class Atom
* @brief Light weight class used to store individual atom information
* typically found in molecular topology files.
*/
class Atom {
public:

	Atom ();
	Atom (
			int index,
			const std::string &name,
			const std::string &element,
			const std::string &residueName,
			int residueId,
			double mass
	);
	int index () const;

	std::string name ();

	std::string element ();

	std::string residueName ();

	int residueId () const;

	double mass () const;


private:
	int         _index;
	std::string _name;
	std::string _element;
	std::string _residueName;
	int         _residueId;
	double      _mass;
};

#endif //ATOM_H
