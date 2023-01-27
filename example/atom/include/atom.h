#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>
#include <map>

/*!
* @class Atom
* @brief A light weight class for storing individual atom information
* typically found in molecular topology files.
*/
class Atom {
public:

	/*!
	* @function{Atom}
	*
	* @brief The default constructor. When an instance of Atom is
	* instantiated using this constructor, you have to manually set
	* all of the class attributes.
	*/
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
* @PythonExample{Atom_Atom.py}
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
	* @note This method is the index attribute getter
	*
	* @PythonExample{Atom_index.py}
	*
	*/
	int index () const;

	/*!
	* @function{index} @type{void}
	*
	* @param index The atom's index.
	* @type{int}
	*
	* @brief Sets the atom's index.
	* @note This method is the index attribute setter.
	*
	* @PythonExample{Atom_int_index.py}
	*/
	void index (int index);

	/*!
	* @function{name} @type{std::string}
	* @brief Return's the atom's name.
	* @return The atom's name.
	* @note This method is the name attribute getter.
	*
	* @PythonExample{Atom_name.py}
	*/
	std::string name ();

	/*!
	* @function{name} @type{void}
	* @param name The atom's name.
	* @type{std::string}
	*
	* @brief Sets the atom's name.
	* @note This method is the name attribute setter.
	* @PythonExample{Atom_str_name.py}
	*/
	void name (std::string name);

	/*!
	* @function{element} @type{std::string}
	* @brief Return's the atom's element symbol.
	* @return The atom's element symbol.
	* @note This method is the element attribute getter.
	* @PythonExample{Atom_element.py}
	*
	*/
	std::string element ();

	/*!
	* @function{element} @type{void}
	* @param element The atom's element symbol.
	* @type{std::string}
	*
	* @brief Sets the atom's element symbol.
	* @note This method is the element attribute setter.
	* @PythonExample{Atom_str_element.py}
	*/
	void element (std::string element);

	/*!
	* @function{residueName} @type{std::string}
	* @brief Return's the atom's residue name.
	* @return The atom's residue name.
	* @note This method is the residueName attribute getter.
	* @PythonExample{Atom_residueName.py}
	*/
	std::string residueName ();

	/*!
	* @function{residueName} @type{void}
	* @param residueName The atom's residue name.
	* @type{std::string}
	*
	* @brief Sets the atom's residue name.
	* @note This method is the residueName attribute setter.
	* @PythonExample{Atom_str_residueName.py}
	*/
	void residueName (std::string residueName);

	/*!
	* @function{residueId} @type{int} @const
	* @brief Return's the atom's residue ID.
	* @return The atom's residue ID.
	* @note This method is the residueId attribute getter.
	* @PythonExample{Atom_residueId.py}
	*/
	int residueId () const;

	/*!
	* @function{residueId} @type{void}
	* @param residueId The atom's residue ID.
	* @type{int}
	*
	* @brief Sets the atom's residue ID.
	* @note This method is the residueId attribute setter.
	* @PythonExample{Atom_int_residueId.py}
	*/
	void residueId (int residueId);


	/*!
	* @function{mass} @type{double} @const
	* @brief Return's the atom's mass.
	* @return The atom's mass.
	* @note This method is the mass attribute getter.
	* @PythonExample{Atom_mass.py}
	*/
	double mass () const;

	/*!
	* @function{mass} @type{void}
	* @param mass The atom's mass.
	* @type{double}
	*
	* @brief Sets the atom's mass.
	* @note This method is the mass attribute setter.
	* @PythonExample{Atom_double_mass.py}
	*/
	void mass (double mass);


private:
	int         _index;
	std::string _name;
	std::string _element;
	std::string _residueName;
	int         _residueId;
	double      _mass;
};

#endif //ATOM_H
