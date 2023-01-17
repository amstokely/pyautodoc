//
// Created by andy on 1/9/23.
//
#include <iostream>
#include "../include/autodoc_parameter.h"
#include "../include/utils.h"
#include "autodoc_description.h"

AutoDocParameter::AutoDocParameter (
		std::istream *is,
		std::string line
) {
	cleanDocStringLine(line);
	removeLeadingWhiteSpace(line);
	this->name_ = line.substr(
			0,
			line.find(' '));
	removeTrailingWhiteSpace(this->name_);
	size_t pos = line.find(this->name_);
	this->description_ = AutoDocDescription(
			is,
			line.substr(
					pos
					+ this->name_.length())
	);
	unsigned int len = is->tellg();
	getline(
			*is,
			line
	);
	if (substringInString(
			line,
			"@type"
	)) {
		this->type_ = parseType(line);
		is->seekg(len);
	}
}

std::string AutoDocParameter::name () {
	return this->name_;
}

std::string AutoDocParameter::type () {
	return this->type_;
}

void AutoDocParameter::type (const std::string &type) {
	this->type_ = type;
}

AutoDocDescription AutoDocParameter::description () {
	return this->description_;
}

std::string AutoDocParameter::swigDocString () {
	std::string swigDocString_;
	swigDocString_ += (
			"\""
			+ this->name_
	);
	if (!this->type_.empty()) {
		swigDocString_ += (
				": "
				+ this->type_
		);
	}
	swigDocString_ += (
			"\\n\"\n"
	);
	if (!this->description_.str().empty()) {
		swigDocString_ +=
				this->description_.swigDocString();
		swigDocString_ += "\"\\n\"\n";
	}
	return swigDocString_;
}

AutoDocParameter::~AutoDocParameter () = default;

AutoDocParameter::AutoDocParameter () = default;
