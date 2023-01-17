//
// Created by andy on 1/10/23.
//

#ifndef PYAUTODOC_AUTODOC_CLASS_H
#define PYAUTODOC_AUTODOC_CLASS_H

#include <istream>
#include <vector>
#include "../include/autodoc_function.h"

class AutoDocClass {
public:
	AutoDocClass ();

	explicit AutoDocClass (std::istream *is);

	std::vector<AutoDocFunction> methods ();

	AutoDocDescription description ();

	std::vector<AutoDocExample> pythonExamples ();

	std::vector<AutoDocExample> cppExamples ();

	std::string name ();

	std::vector<AutoDocClass> classes ();

	void generateSwigDocString ();

	void writeSwigDocString (
			const std::string &fname,
			int overwrite
	);

	std::string swigDocString ();

private:
	std::vector<AutoDocFunction> methods_;
	std::string                  swigDocString_;
	AutoDocDescription           description_;
	std::string                  name_;
	std::vector<AutoDocClass>    classes_;
	std::vector<AutoDocExample>  pythonExamples_;
	std::vector<AutoDocExample>  cppExamples_;
};

#endif //PYAUTODOC_AUTODOC_CLASS_H
