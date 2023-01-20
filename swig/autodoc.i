%module pyautodoc
%include "std_string.i"
%include "std_vector.i"
%{
#include "autodoc.h"
#include "autodoc_function.h"
#include "autodoc_class.h"
#include "autodoc_return.h"
#include "autodoc_parameter.h"
#include "autodoc_example.h"
#include "autodoc_description.h"
#include "utils.h"
%}
%template(AutoDocFunctionVector) std::vector<AutoDocFunction>;
%template(AutoDocParameterVector) std::vector<AutoDocParameter>;
%template(AutoDocClassVector) std::vector<AutoDocClass>;
%template(AutoDocExampleVector) std::vector<AutoDocExample>;
%template(svector) std::vector<std::string>;
%include "autodoc_python_special_methods.i"
%include "autodoc_map_typemaps.i"
%include "autodoc_documentation.i"

%include autodoc.h
%include autodoc_return.h
%include autodoc_function.h
%include autodoc_class.h
%include autodoc_example.h
%include autodoc_parameter.h
%include autodoc_description.h
%include utils.h
