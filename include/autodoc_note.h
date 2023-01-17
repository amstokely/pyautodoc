//
// Created by andy on 1/17/23.
//

#ifndef PYAUTODOC_AUTODOC_NOTE_H
#define PYAUTODOC_AUTODOC_NOTE_H
#include <string>

class AutoDocNote {
public:
	AutoDocNote ();

	AutoDocNote (
			std::istream *is,
			std::string line
	);
	~AutoDocNote();
	std::string str();
	std::string swigDocString();

private:
	std::string str_;
};

#endif //PYAUTODOC_AUTODOC_NOTE_H
