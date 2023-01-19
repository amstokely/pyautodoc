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
	*
	*@PythonExample{
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.index(0)
	* newAtom.name('CA')
	* newAtom.element("C")
	* newAtom.residueName("GLU")
	* newAtom.residueId(1)
	* newAtom.mass(12.001)
	*
	* }<!--EXAMPLE END-->
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
	* @note This method is the index attribute getter
	*
	* } <!--EXAMPLE END-->
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
	* @PythonExample{
	*
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.index(0)
	*
	* index = newAtom.index()
	* print(index)
	*
	* '''
	* --> 0
	* '''
	* } <!--EXAMPLE END-->
	*/
	void index (int index);

	/*!
	* @function{name} @type{std::string}
	* @brief Return's the atom's name.
	* @return The atom's name.
	* @note This method is the name attribute getter.
	*/
	std::string name ();

	/*!
	* @function{name} @type{void}
	* @param name The atom's name.
	* @type{std::string}
	*
	* @brief Sets the atom's name.
	* @note This method is the name attribute setter.
	*
	* @PythonExample{
	*
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.name("CA)
	*
	* name = newAtom.name()
	* print(name)
	*
	* '''
	* --> CA
	* '''
	* } <!--EXAMPLE END-->
	*/
	void name (std::string name);

	/*!
	* @function{element} @type{std::string}
	* @brief Return's the atom's element symbol.
	* @return The atom's element symbol.
	* @note This method is the element attribute getter.
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
	*
	* @PythonExample{
	*
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.element("C")
	*
	* element = newAtom.element()
	* print(element)
	*
	* '''
	* --> C
	* '''
	*
	* } <!--EXAMPLE END-->
	*
	*/
	void element (std::string element);

	/*!
	* @function{residueName} @type{std::string}
	* @brief Return's the atom's residue name.
	* @return The atom's residue name.
	* @note This method is the residueName attribute getter.
	*/
	std::string residueName ();

	/*!
	* @function{residueName} @type{void}
	* @param residueName The atom's residue name.
	* @type{std::string}
	*
	* @brief Sets the atom's residue name.
	* @note This method is the residueName attribute setter.
	*
	* @PythonExample{
	*
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.residueName("GLU")
	*
	* residueName = newAtom.residueName()
	* print(residueName)
	*
	* '''
	* --> GLU
	* '''
	* } <!--EXAMPLE END-->
	*/
	void residueName (std::string residueName);

	/*!
	* @function{residueId} @type{int} @const
	* @brief Return's the atom's residue ID.
	* @return The atom's residue ID.
	* @note This method is the residueId attribute getter.
	*/
	int residueId () const;

	/*!
	* @function{residueId} @type{void}
	* @param residueId The atom's residue ID.
	* @type{int}
	*
	* @brief Sets the atom's residue ID.
	* @note This method is the residueId attribute setter.
	*
	* @PythonExample{
	*
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.residueId(1)
	*
	* residueId = newAtom.residueId()
	* print(residueId)
	*
	* '''
	* --> 1
	* '''
	* } <!--EXAMPLE END-->
	*/
	void residueId (int residueId);


	/*!
	* @function{mass} @type{double} @const
	* @brief Return's the atom's mass.
	* @return The atom's mass.
	* @note This method is the mass attribute getter.
	*/
	double mass () const;

	/*!
	* @function{mass} @type{void}
	* @param mass The atom's mass.
	* @type{double}
	*
	* @brief Sets the atom's mass.
	* @note This method is the mass attribute setter.
	*
	* @PythonExample{
	*
	* from atom import Atom
	*
	* newAtom = Atom()
	* newAtom.mass(12.001)
	*
	* mass = newAtom.mass()
	* print(mass)
	*
	* '''
	* --> 12.001
	* '''
	*
	* } <!--EXAMPLE END-->
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
