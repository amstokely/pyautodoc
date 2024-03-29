%feature("docstring")
Atom
"\nDescription\n"
"--------------------\n"
"    A light weight class for storing individual atom information\n"
"    typically found in molecular topology files."
"\n"
;%feature("docstring")
Atom::Atom
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"Atom()\n"
"\nDescription\n"
"--------------------\n"
"    The default constructor. When an instance of Atom is\n"
"    instantiated using this constructor, you have to manually set\n"
"    all of the class attributes."
"\n"

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"Atom(index, name, element, residueName, residueId, mass)\n"
"\nParameters\n"
"--------------------\n"
"index: int\n"
"    The atom's index."
"\n"
"\n"
"name: str\n"
"    The atom's name."
"\n"
"\n"
"element: str\n"
"    The atom's element symbol."
"\n"
"\n"
"residueName: str\n"
"    The atom's residue name."
"\n"
"\n"
"residueId: str\n"
"    The atom's residue ID."
"\n"
"\n"
"mass: [np.float64, float, np.float32]\n"
"    The atom's atomic mass in amu."
"\n"
"\nExample\n"
"--------------------\n"
"    "
%feature("docstring")
Atom::index
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"index()->int\n"
"\nDescription\n"
"--------------------\n"
"    Return's the atom's index."
"\n"
"\nReturns\n"
"--------------------\n"
"    The atom's index."
"\n"
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the index attribute getter\n"
"    *"
"\n"
"\nExample\n"
"--------------------\n"
"    "

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"index(index)->None\n"
"\nDescription\n"
"--------------------\n"
"    Sets the atom's index."
"\n"
"\nParameters\n"
"--------------------\n"
"index: int\n"
"    The atom's index."
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the index attribute setter.\n"
"    *"
"\n"
"\nExample\n"
"--------------------\n"
"    "
%feature("docstring")
Atom::name
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"name()->str\n"
"\nDescription\n"
"--------------------\n"
"    Return's the atom's name."
"\n"
"\nReturns\n"
"--------------------\n"
"    The atom's name."
"\n"
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the name attribute getter.\n"
"    *"
"\n"
"\nExample\n"
"--------------------\n"
"    "

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"name(name)->None\n"
"\nDescription\n"
"--------------------\n"
"    Sets the atom's name."
"\n"
"\nParameters\n"
"--------------------\n"
"name: str\n"
"    The atom's name."
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the name attribute setter."
"\n"
"\nExample\n"
"--------------------\n"
"    "
%feature("docstring")
Atom::element
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"element()->str\n"
"\nDescription\n"
"--------------------\n"
"    Return's the atom's element symbol."
"\n"
"\nReturns\n"
"--------------------\n"
"    The atom's element symbol."
"\n"
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the element attribute getter."
"\n"
"\nExample\n"
"--------------------\n"
"    "

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"element(element)->None\n"
"\nDescription\n"
"--------------------\n"
"    Sets the atom's element symbol."
"\n"
"\nParameters\n"
"--------------------\n"
"element: str\n"
"    The atom's element symbol."
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the element attribute setter."
"\n"
"\nExample\n"
"--------------------\n"
"    "
%feature("docstring")
Atom::residueName
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"residueName()->str\n"
"\nDescription\n"
"--------------------\n"
"    Return's the atom's residue name."
"\n"
"\nReturns\n"
"--------------------\n"
"    The atom's residue name."
"\n"
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the residueName attribute getter."
"\n"
"\nExample\n"
"--------------------\n"
"    "

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"residueName(residueName)->None\n"
"\nDescription\n"
"--------------------\n"
"    Sets the atom's residue name."
"\n"
"\nParameters\n"
"--------------------\n"
"residueName: str\n"
"    The atom's residue name."
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the residueName attribute setter."
"\n"
"\nExample\n"
"--------------------\n"
"    "
%feature("docstring")
Atom::residueId
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"residueId()->int\n"
"\nDescription\n"
"--------------------\n"
"    Return's the atom's residue ID."
"\n"
"\nReturns\n"
"--------------------\n"
"    The atom's residue ID."
"\n"
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the residueId attribute getter."
"\n"
"\nExample\n"
"--------------------\n"
"    "

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"residueId(residueId)->None\n"
"\nDescription\n"
"--------------------\n"
"    Sets the atom's residue ID."
"\n"
"\nParameters\n"
"--------------------\n"
"residueId: int\n"
"    The atom's residue ID."
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the residueId attribute setter."
"\n"
"\nExample\n"
"--------------------\n"
"    "
%feature("docstring")
Atom::mass
"\n"
"********************\n"
"*    Version 1     *\n"
"********************\n"

"mass()->float\n"
"\nDescription\n"
"--------------------\n"
"    Return's the atom's mass."
"\n"
"\nReturns\n"
"--------------------\n"
"    The atom's mass."
"\n"
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the mass attribute getter."
"\n"
"\nExample\n"
"--------------------\n"
"    "

"\n"
"********************\n"
"*    Version 2     *\n"
"********************\n"

"mass(mass)->None\n"
"\nDescription\n"
"--------------------\n"
"    Sets the atom's mass."
"\n"
"\nParameters\n"
"--------------------\n"
"mass: [np.float64, float, np.float32]\n"
"    The atom's mass."
"\n"
"\nNote\n"
"--------------------\n"
"    This method is the mass attribute setter."
"\n"
"\nExample\n"
"--------------------\n"
"    "
;