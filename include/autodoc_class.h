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

	explicit AutoDocClass (
			std::istream *is,
			const std::string& doxygenExamplePath,
			std::map<
					std::string,
					std::string
			        > &functionCppPyTypes,
			std::map<
					std::string,
					std::string
			        > &parameterCppPyTypes
	);

	std::vector<AutoDocFunction> methods ();

	std::vector<AutoDocFunction> overloadedMethods ();

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

	std::map<
			std::string,
			std::string
	        > *functionCppPyTypes ();

	std::map<
			std::string,
			std::string
	        > *parameterCppPyTypes ();

private:
	std::vector<AutoDocFunction> methods_;
	std::vector<AutoDocFunction> overloadedMethods_;
	std::string                  swigDocString_;
	AutoDocDescription           description_;
	std::string                  name_;
	std::vector<AutoDocClass>    classes_;
	std::vector<AutoDocExample>  pythonExamples_;
	std::vector<AutoDocExample>  cppExamples_;
	std::map<
			std::string,
			std::string
	        >                    functionCppPyTypes_;
	std::map<
			std::string,
			std::string
	        >                    parameterCppPyTypes_;

};

#endif //PYAUTODOC_AUTODOC_CLASS_H
