//
// Created by andy on 1/10/23.
//
#include "../include/autodoc_description.h"
#include "../include/utils.h"
#include <iostream>

AutoDocDescription::AutoDocDescription () = default;

AutoDocDescription::AutoDocDescription (
		std::istream *is,
		std::string line
) {
	cleanDocStringLine(line);
	removeLeadingWhiteSpace(line);
	this->str_ += line;
	unsigned int len = is->tellg();
	while (std::getline(
			*is,
			line
	)) {
		if (substringInString(
				line,
				"@"
		)) {
			is->seekg(
					len,
					std::ios_base::beg
			);
			removeLeadingWhiteSpace(this->str_);
			removeTrailingWhiteSpace(this->str_);
			break;
		} else if (substringInString(
				line,
				"*/"
		)) {
			is->seekg(
					len,
					std::ios_base::beg
			);
			removeLeadingWhiteSpace(this->str_);
			removeTrailingWhiteSpace(this->str_);
			break;
		} else {
			line = escapeQuotes(
					line
			);
			cleanDocStringLine(line);
			removeLeadingWhiteSpace(line);
			removeTrailingWhiteSpace(line);
			this->str_ += (
					'\n'
					+ line
			);
			len = is->tellg();
		}
	}
}

std::string AutoDocDescription::str () {
	return this->str_;
}

std::string AutoDocDescription::swigDocString () {
	std::string swigDocString_;
	swigDocString_ = indentSwigDocStringLine(this->str_);
	return swigDocString_;
}

AutoDocDescription::~AutoDocDescription () = default;
