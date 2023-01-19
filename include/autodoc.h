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

/*!
* @class AutoDoc
*/
class AutoDoc {
public:
	AutoDoc ();

	/*!
	* @function{AutoDoc}
	* @param fname
	*/
	explicit AutoDoc (
			const std::string &fname
	);

	AutoDoc (
			const std::string &fname,
			std::map<
					std::string,
					std::string
			        > *cppPyTypes
	);
	AutoDoc (
			const std::string &fname,
			std::map<
					std::string,
					std::string
			        > *functionCppPyTypes,
			std::map<
					std::string,
					std::string
			        > *parameterCppPyTypes
	);

	std::map<
			std::string,
			std::string
	        > *functionCppPyTypes ();

	std::map<
			std::string,
			std::string
	        > *parameterCppPyTypes ();

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
	        >                    functionCppPyTypes_;
	std::map<
			std::string,
			std::string
	        >                    parameterCppPyTypes_;
};

#endif //PYCDOC_PYDOC_H
