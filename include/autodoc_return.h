//
// Created by andy on 1/10/23.
//
#include <string>
#include <autodoc_description.h>

#ifndef PYAUTODOC_AUTODOC_RETURN_H
#define PYAUTODOC_AUTODOC_RETURN_H

class AutoDocReturn {
public:
	AutoDocReturn ();

	AutoDocReturn (
			std::istream *is,
			std::string line
	);
	~AutoDocReturn();
	AutoDocDescription description();
	std::string type();
	void type(std::string type);

	std::string swigDocString ();

private:
	AutoDocDescription description_;
	std::string type_;
};

#endif //PYAUTODOC_AUTODOC_RETURN_H
