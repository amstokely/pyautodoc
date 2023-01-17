#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>

/*!
* @class Atom
* @brief Atom class
*/
class Atom {
public:
	Atom ();
	/*!
	* @function{Atom}
	* @brief Atom class constructor
	* @note All Atom class method examples use the Atom object in the
	* constructor example.
	*
	* @param index The atom's index.
	* 	@type{int}
	*
	* @param name The atom's name.
	* 	@type{const std::string&}
	*
	* @param element The atom's element symbol.
	* 	@type{const std::string&}
	*
	* @param residueName The atom's residue name.
	* 	@type{const std::string&}
	*
	* @param residueId The atom's residue ID.
	* 	@type{const std::string&}
	*
	* @param chainId The atom's chain ID.
	* 	@type{const std::string&}
	*
	* @param segmentId The atom's segment ID.
	* 	@type{const std::string&}
	*
	* @param temperatureFactor The atom's temperature factor.
	* 	@type{double}
	*
	* @param occupancy The atom's occupancy
	* 	@type{double}
	*
	* @param serial The atom's serial number, which is always one
	* greater than the index.
	* 	@type{int}
	*
	* @param mass The atom's atomic mass in amu.
	* 	@type{double}
	*
	*
	* @PythonExample{
	* from atom import Atom
	*
	* index = 0
	* name = 'CA'
	* element = 'C'
	* residueName = 'GLU'
	* residueId = 1
	* chainId = 'A'
	* segmentId = ''
	* temperatureFactor = 0.0
	* occupancy = 2.0
	* serial = 1
	* mass = 12.001
	*
	* atom = Atom(
	* 	index,
	* 	name,
	* 	element,
	* 	residueName,
	* 	residueId,
	* 	chainId,
	* 	segmentId,
	* 	temperatureFactor,
	* 	occupancy,
	* 	serial,
	* 	mass,
	* )
	* } <!--END-->
	*/
	Atom (
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
	);

	/*!
	* @function{index} @type{int} @const
	* @brief Returns the atom's index.
	* @return The atom's
	* index.
	*/
	int index () const;

	std::string name ();

	std::string element ();

	std::string residueName ();

	int residueId () const;

	std::string chainId ();

	std::string segmentId ();

	double temperatureFactor () const;

	double occupancy () const;

	int serial () const;

	double mass () const;


private:
	int         _index;
	std::string _name;
	std::string _element;
	std::string _residueName;
	int         _residueId;
	std::string _chainId;
	std::string _segmentId;
	double      _temperatureFactor;
	double      _occupancy;
	int         _serial;
	std::string _tag;
	double      _mass;
};

#endif //ATOM_H
