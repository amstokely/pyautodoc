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
* @brief The user interface class in PyAutoDoc that initiates the
* transfer of doxygen documentation from C++ to Python. A
* comprehensive PyAutoDoc tutorial can be found on the
* documentation main page.
*/
class AutoDoc {
public:
	AutoDoc ();

	AutoDoc (
			const std::string &fname,
			const std::string &doxygenExamplePath,
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

	/*!
	* @function{writeSwigDocString} @type{void}
	* @brief Writes a SWIG docstring feature directive interface file.
	*
	* @param fname The name of the output SWIG interface file. The
	* interface file has a ".i" extension and it's path must be in an
	* include directive in the primary SWIG interface file.
	* @type{const std::string&}
	*
	*/
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
	std::string exampleFilesDirectory_;
};

#endif //PYCDOC_PYDOC_H
