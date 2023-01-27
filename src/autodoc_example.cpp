//
// Created by andy on 1/10/23.
//
#include "../include/autodoc_example.h"
#include "../include/utils.h"
#include <istream>
#include <utility>
#include <fstream>
#include <iostream>
#include "boost/filesystem.hpp"

AutoDocExample::AutoDocExample () = default;

AutoDocExample::AutoDocExample (
		const std::string& fname,
		const std::string& language
) {
	this->language_ = language;
	std::ifstream is(
			fname,
			std::ifstream::binary
	);
	std::string   line;
	while(getline(is, line)) {
		line = escapeQuotes(
				line
		);
		cleanDocStringLine(line);
		this->str_ += (
				line
				+ '\n'
		);
	}
	is.close();
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
