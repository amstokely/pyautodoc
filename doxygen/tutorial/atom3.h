#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>


/*!
* @class Atom
* @brief A light weight class for storing individual atom information
* typically found in molecular topology files.
*/
class Atom {
public:
	Atom ();

	/*!
* @function{Atom}
*
* @param index The atom's index.
* @type{int}
*
* @param name The atom's name.
* @type{const std::string&}
*
* @param element The atom's element symbol.
* @type{const std::string&}
*
* @param residueName The atom's residue name.
* @type{const std::string&}
*
* @param residueId The atom's residue ID.
* @type{const std::string&}
*
* @param mass The atom's atomic mass in amu.
* @type{double}
*
* @PythonExample{
* from atom import Atom
*
* newAtom = Atom(0, 'CA', 'C', 'GLU', 1, 12.001)
* } <!--EXAMPLE END-->
*/
	Atom (
			int index,
			const std::string &name,
			const std::string &element,
			const std::string &residueName,
			int residueId,
			double mass
	);

	/*!
	* @function{index} @type{int} @const
	* @brief Return's the atom's index.
	* @return The atom's index.
	*/
	int index () const;

	/*!
	* @function{name} @type{std::string}
	* @brief Return's the atom's name.
	* @return The atom's name.
	*/
	std::string name ();

	/*!
	* @function{element} @type{std::string}
	* @brief Return's the atom's element symbol.
	* @return The atom's element symbol.
	*/
	std::string element ();

	/*!
	* @function{residueName} @type{std::string}
	* @brief Return's the atom's residue name.
	* @return The atom's residue name.
	*/
	std::string residueName ();

	/*!
	* @function{residueId} @type{int} @const
	* @brief Return's the atom's residue ID.
	* @return The atom's residue ID.
	*/
	int residueId () const;

	/*!
	* @function{mass} @type{double} @const
	* @brief Return's the atom's mass.
	* @return The atom's mass.
	*/
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
