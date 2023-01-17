//
// Created by andy on 1/10/23.
//
#include "../include/autodoc_example.h"
#include "../include/utils.h"
#include <istream>
#include <utility>

AutoDocExample::AutoDocExample () = default;

AutoDocExample::AutoDocExample (
		std::istream *is,
		std::string language
) {
	this->language_ = std::move(language);
	std::string line;
	while (std::getline(
			*is,
			line
	)) {
		std::string lineCopy = line;
		removeLeadingWhiteSpace(lineCopy);
		removeTrailingWhiteSpace(lineCopy);
		if (line.find("} <!--END-->")
		    != std::string::npos) {
			this->str_ = this->str_.substr(
					0,
					this->str_.length()
					- 1
			);
			break;
		} else {
			cleanDocStringLine(line);
			this->str_ += (
					line
					+ '\n'
			);
		}
	}
}

std::string AutoDocExample::swigDocString () {
	std::string swigDocString_;
	swigDocString_ = indentSwigDocStringLine(this->str_);
	return swigDocString_;
}

AutoDocExample::~AutoDocExample () = default;

std::string AutoDocExample::str () {
	return this->str_;
}

std::string AutoDocExample::language () {
	return this->language_;
}
