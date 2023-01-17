//
// Created by andy on 1/10/23.
//

#ifndef PYAUTODOC_AUTODOC_EXAMPLE_H
#define PYAUTODOC_AUTODOC_EXAMPLE_H

#include <string>

class AutoDocExample {
public:
	AutoDocExample ();

	explicit AutoDocExample (
			std::istream *is,
			std::string language
	);
	~AutoDocExample();
	std::string str();
	std::string language();
	std::string swigDocString();

private:
	std::string str_;
	std::string language_;

	std::string formatSwigDocString ();
};



#endif //PYAUTODOC_AUTODOC_EXAMPLE_H
