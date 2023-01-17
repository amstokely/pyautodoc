//
// Created by andy on 1/9/23.
//

#ifndef PYAUTODOC_PYAUTODOC_FUNCTION_H
#define PYAUTODOC_PYAUTODOC_FUNCTION_H

#include <string>
#include "autodoc_parameter.h"
#include "autodoc_description.h"
#include "autodoc_return.h"
#include <vector>
#include "autodoc_example.h"

class AutoDocClass;

class AutoDocFunction {
public:
	AutoDocFunction ();

	explicit AutoDocFunction (
			std::istream *is,
			std::string className
	);

	~AutoDocFunction ();

	std::string name ();

	std::string type ();

	AutoDocDescription description ();

	std::vector<AutoDocParameter> parameters (
	);

	AutoDocReturn returnInfo ();

	std::string signature ();

	std::vector<AutoDocExample> pythonExamples ();

	std::vector<AutoDocExample> cppExamples ();

	std::string className ();

	std::string swigDocString ();

	void generateSwigDocString ();

	void writeSwigDocString (
			const std::string &fname,
			int overwrite
	);


private:
	std::string                   name_;
	AutoDocDescription            description_;
	std::vector<AutoDocParameter> parameters_;
	std::string                   type_;
	std::string                   signature_;
	AutoDocReturn                 return_;
	std::vector<AutoDocExample>   pythonExamples_;
	std::vector<AutoDocExample>   cppExamples_;
	std::string                   className_;
	int                           const_ = 0;
	std::string                   swigDocString_;
	std::string                   swigSignature_;
};


#endif //PYAUTODOC_PYAUTODOC_FUNCTION_H
