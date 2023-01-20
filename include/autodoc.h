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

	/*!
	* @function{AutoDoc}
	* @brief Use this constructor if you want to preserve C++ types
	* in the python documentation.
	*
	* @param fname The C++ header file name that contains the C++
	* doxygen documentation
	* @type{const std::string&}
	*/
	explicit AutoDoc (
			const std::string &fname
	);

	/*!
	* @function{AutoDoc}
	* @brief Use this constructor if you want to replace C++ types
	* with the Python types defined in the cppPyTypes parameter.
	*
	* @param fname The C++ header file name that contains the C++
	* doxygen documentation
	* @type{const std::string&}
	*
	* @param cppPyTypes Map defining the C++/Python type
	* substitutions, where the keys are the C++ types, and the values
	* are the Python types. The same substitutions with be performed
	* for both parameters and functions. In python, cppPyTypes will be
	* a string/string dictionary.
	* @type{std::map<std::string, std::string>*}
	*/
	AutoDoc (
			const std::string &fname,
			std::map<
					std::string,
					std::string
			        > *cppPyTypes
	);

	/*!
	* @function{AutoDoc}
	* @brief Use this constructor if you want to replace the C++
	* types with Python types, but want to use different types for
	* the parameters and functions. This is useful when a wrapped
	* Python function can accept multiple "similar" types,
	* but can only
	* return one specific type.
	*
	* @param fname The C++ header file name that contains the C++
	* doxygen documentation
	* @type{const std::string&}
	*
	* @param parameterCppPyTypes Map defining the C++/Python type
	* substitutions used for parameters, where the keys are the C++
	* types, and the values
	* are the Python types. In python, parameterCppPyTypes will be
	* a string/string dictionary.
	* @type{std::map<std::string, std::string>*}
	*
	* @param functionCppPyTypes Map defining the C++/Python type
	* substitutions used for functions, where the keys are the C++
	* types, and the values
	* are the Python types. In python, functionCppPyTypes will be
	* a string/string dictionary.
	* @type{std::map<std::string, std::string>*}
	*
	*/
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
};

#endif //PYCDOC_PYDOC_H
