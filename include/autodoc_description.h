//
// Created by andy on 1/10/23.
//

#ifndef PYAUTODOC_AUTODOC_DESCRIPTION_H
#define PYAUTODOC_AUTODOC_DESCRIPTION_H

#include <string>

class AutoDocDescription {
public:
	AutoDocDescription ();

	AutoDocDescription (
			std::istream *is,
			std::string line
	);
	~AutoDocDescription();
	std::string str();
	std::string swigDocString();

private:
	std::string str_;
};

#endif //PYAUTODOC_AUTODOC_DESCRIPTION_H
