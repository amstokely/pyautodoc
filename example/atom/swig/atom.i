%module atom
%include "std_string.i"
%include "std_vector.i"
%{
#include "atom.h"
%}
%template(dvector) std::vector<double>;
%include "atom_docs.i"

%include atom.h
