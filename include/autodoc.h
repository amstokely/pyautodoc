//
// Created by andy on 1/9/23.
//
/*
* set(DOXYGEN_ALIASES
        [[PythonExample{1}=<b>Python Example</b><br>\code{.py}\1\endcode]]
        [[CppExample{1}=<b>C++ Example</b><br>\code{.cpp}\1\endcode]]
        [[type{1}=<!-- \1 -->]]
        [[function{1}=<!-- \1 -->]]
        [[const=<!--  -->]]
        )
*/

#ifndef PYCDOC_PYDOC_H
#define PYCDOC_PYDOC_H

#include <string>
#include <vector>
#include "autodoc_function.h"
#include "autodoc_class.h"

class AutoDoc {
public:
	AutoDoc ();

	explicit AutoDoc (
			const std::string &fname
	);

	std::vector<AutoDocFunction> functions ();

	std::vector<AutoDocClass> classes ();

	void writeSwigDocString (
			const std::string &fname
	);

private:
	std::vector<AutoDocFunction> functions_;
	std::vector<AutoDocClass>    classes_;
};

#endif //PYCDOC_PYDOC_H
