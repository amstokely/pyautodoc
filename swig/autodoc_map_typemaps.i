#include <iostream>
#include <map>
#include <string>


%typecheck(SWIG_TYPECHECK_POINTER)
(std::map<std::string, std::string> *cppPyTypes) {
	$1 = PyDict_Check($input) ? 1 : 0;
}

%typemap(in) (
		std::map<std::string, std::string> *cppPyTypes
){
	$1 = new std::map<std::string, std::string>;
	int i;
	if (!PyDict_Check($input)) {
		PyErr_SetString(PyExc_ValueError, "Expecting a dictionary");
		return NULL;
	}
	int len = PyDict_Size($input);
	PyObject *cppTypes = PyDict_Keys($input);
	char **tmpCppType = (char **) malloc((1)*sizeof(char *));
	char **tmpPyType = (char **) malloc((1)*sizeof(char *));
	for (i = 0; i < len; i++) {
		PyObject *cppType = PyList_GetItem(cppTypes,i);
		PyObject *pyType = PyDict_GetItem($input, cppType);
		PyObject * byteCppType = PyUnicode_AsEncodedString(
				cppType, "UTF-8", "strict"
				);
		PyObject * bytePyType = PyUnicode_AsEncodedString(
				pyType, "UTF-8", "strict"
		);
		if (byteCppType != NULL) {
			tmpCppType[0] =
					PyBytes_AS_STRING(byteCppType);
			tmpPyType[0] =
					PyBytes_AS_STRING(bytePyType);
			tmpCppType[0] = strdup(tmpCppType[0]);
			tmpPyType[0] = strdup(tmpPyType[0]);
			(*($1))[tmpCppType[0]] = tmpPyType[0];
		}
		Py_DECREF(byteCppType);
		Py_DECREF(bytePyType);
	}
	Py_DECREF(cppTypes);
	free(tmpCppType);
	free(tmpPyType);
}

%typemap(out) std::map<std::string, std::string> *cppPyTypes {
	Py_XDECREF($result);   /* Blow away any previous result */
	$result = PyDict_New();
	for (auto it : *$1) {
		auto cppType = PyUnicode_FromString(it.first.data());
		auto pyType = PyUnicode_FromString(it.second.data());
		PyDict_SetItem($result, cppType, pyType);
	}
}
%typemap(freearg)
	std::map<std::string, std::string> *cppPyTypes {
	delete $1;
}
