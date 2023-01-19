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
#include <map>
#include "autodoc_example.h"
#include "autodoc_note.h"

class AutoDocClass;

class AutoDocFunction {
public:
	AutoDocFunction ();

	AutoDocFunction (
			std::istream *is,
			std::string className,
			std::map<
					std::string,
					std::string
			        > &functionCppPyTypes,
			std::map<
					std::string,
					std::string
			        > &parameterCppPyTypes
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

	std::vector<AutoDocNote> notes ();

	std::string className ();

	std::string swigDocString ();

	std::string overloadedSwigDocString ();

	void generateSwigDocString ();

	void writeSwigDocString (
			const std::string &fname,
			int overwrite
	);

	std::string pyType ();

	std::map<
			std::string,
			std::string
	        > *functionCppPyTypes ();

	std::map<
			std::string,
			std::string
	        > *parameterCppPyTypes ();

	void generateOverloadedSwigDocString (int version);

	std::string swigDocStringPrefix ();


private:
	std::string                   name_;
	AutoDocDescription            description_;
	std::vector<AutoDocParameter> parameters_;
	std::string                   type_;
	std::string                   pyType_;
	std::string                   signature_;
	AutoDocReturn                 return_;
	std::vector<AutoDocExample>   pythonExamples_;
	std::vector<AutoDocExample>   cppExamples_;
	std::vector<AutoDocNote>      notes_;
	std::string                   className_;
	int                           const_ = 0;
	std::string                   swigDocString_;
	std::string                   overloadedSwigDocString_;
	std::string                   swigSignature_;
	std::map<
			std::string,
			std::string
	        >                     functionCppPyTypes_;
	std::map<
			std::string,
			std::string
	        >                     parameterCppPyTypes_;
};


#endif //PYAUTODOC_PYAUTODOC_FUNCTION_H
