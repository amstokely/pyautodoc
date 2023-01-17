//
// Created by andy on 1/9/23.
//

#ifndef PYAUTODOC_AUTODOC_PARAMETER_H
#define PYAUTODOC_AUTODOC_PARAMETER_H
//
// Created by andy on 1/9/23.
//
#include <string>
#include <map>
#include "autodoc_description.h"

class AutoDocParameter {
public:
	AutoDocParameter (
			std::istream *is,
			std::string line,
			std::map<
					std::string,
					std::string
			        > &cppPyTypes
	);
	AutoDocParameter (
	);
	~AutoDocParameter();

	std::string name ();

	std::string type ();

	void type(const std::string &type);

	AutoDocDescription description();

	std::string swigDocString();

	std::string pyType();

private:
	std::string name_;
	std::string type_;
	std::string pyType_;
	AutoDocDescription description_;
};



#endif //PYAUTODOC_AUTODOC_PARAMETER_H
