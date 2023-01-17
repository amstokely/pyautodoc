//
// Created by andy on 1/9/23.
//

#ifndef PYCDOC_PYDOC_H
#define PYCDOC_PYDOC_H

#include <string>
#include <vector>
#include <map>
#include "autodoc_function.h"
#include "autodoc_class.h"

class AutoDoc {
public:
	AutoDoc ();

	explicit AutoDoc (
			const std::string &fname,
			std::map<
					std::string,
					std::string
			        > *cppPyTypes
	);

	std::map<
			std::string,
			std::string
	        > *cppPyTypes();

	std::vector<AutoDocFunction> functions ();

	std::vector<AutoDocClass> classes ();

	void writeSwigDocString (
			const std::string &fname
	);

private:
	std::vector<AutoDocFunction> functions_;
	std::vector<AutoDocClass>    classes_;
	std::map<
			std::string,
			std::string
	        >                    cppPyTypes_;
};

#endif //PYCDOC_PYDOC_H
