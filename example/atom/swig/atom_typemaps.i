#include <iostream>
#include <map>
#include <string>


%typecheck(SWIG_TYPECHECK_POINTER)
		(std::vector<int> *) {
	$1 = PyList_Check($input) ? 1 : 0;
}

%typemap(in) (
		std::vector<int> *
){
	$1 = new std::vector<int>;
	int i;
	if (!PyList_Check($input)) {
		PyErr_SetString(PyExc_ValueError, "Expecting a list");
		return NULL;
	}
	size_t len = PyList_Size($input);
	for (size_t i = 0; i < len; i++) {
		PyObject *val = PyList_GetItem($input, i);
		$1->push_back(PyLong_AsLong(val));
	}
}

%typemap(out) std::vector<int> * {
	Py_XDECREF($result);
	$result = PyList_New($1->size());
	for (size_t idx; idx < $1->size(); idx++) {
		PyObject *val = PyLong_FromLong($1->at(idx));
		PyList_SetItem($result, idx, val);
	}
}

%typemap(freearg)
	std::vector<int> * {
delete $1;
}
