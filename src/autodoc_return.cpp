//
// Created by andy on 1/10/23.
//
#include "../include/autodoc_return.h"
#include "../include/utils.h"
#include <utility>

AutoDocReturn::AutoDocReturn () = default;

AutoDocReturn::AutoDocReturn (
		std::istream *is,
		std::string line
) {
	cleanDocStringLine(line);
	removeLeadingWhiteSpace(line);
	this->description_ = AutoDocDescription(
			is,
			line
	);
}

AutoDocDescription AutoDocReturn::description () {
	return this->description_;
}

std::string AutoDocReturn::type () {
	return this->type_;
}

void AutoDocReturn::type (std::string type) {
	this->type_ = std::move(type);
}

std::string AutoDocReturn::swigDocString () {
	std::string swigDocString_;
	swigDocString_ = indentSwigDocStringLine(
			this->description().str()
	);
	swigDocString_ += "\"\\n\"\n";
	return swigDocString_;
}

AutoDocReturn::~AutoDocReturn () = default;

