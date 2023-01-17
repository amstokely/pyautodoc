//
// Created by andy on 1/9/23.
//

#ifndef PYAUTODOC_AUTODOC_PARAMETER_H
#define PYAUTODOC_AUTODOC_PARAMETER_H
//
// Created by andy on 1/9/23.
//
#include <string>
#include "autodoc_description.h"

class AutoDocParameter {
public:
	AutoDocParameter (
			std::istream *is,
			std::string line
	);
	AutoDocParameter (
	);
	~AutoDocParameter();

	std::string name ();

	std::string type ();

	void type(const std::string &type);

	AutoDocDescription description();

	std::string swigDocString();

private:
	std::string name_;
	std::string type_;
	AutoDocDescription description_;
};



#endif //PYAUTODOC_AUTODOC_PARAMETER_H
