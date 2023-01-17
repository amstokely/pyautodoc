//
// Created by andy on 1/9/23.
//
#include <fstream>
#include <iostream>
#include "../include/autodoc.h"
#include "../include/utils.h"

AutoDoc::AutoDoc () = default;

AutoDoc::AutoDoc (const std::string &fname) {
	std::ifstream is(
			fname,
			std::ifstream::binary
	);
	std::string   line;
	while (std::getline(
			is,
			line
	)) {
		if (docStringStart(line)) {
			std::string docStringType = getDocStringType(
					&is,
					line
			);
			if (docStringType
			    == "function") {
				AutoDocFunction autoDocFunction(
						&is,
						std::__cxx11::string());
				this->functions_.push_back(autoDocFunction);
			} else if (docStringType
			           == "class") {
				AutoDocClass autoDocClass(&is);
				this->classes_.push_back(autoDocClass);
			}
		}
	}
}

std::vector<AutoDocFunction> AutoDoc::functions () {
	return this->functions_;
}

std::vector<AutoDocClass> AutoDoc::classes () {
	return this->classes_;
}

void AutoDoc::writeSwigDocString (const std::string &fname) {
	for (
		auto function: this->functions_
			) {
		function.writeSwigDocString(
				fname,
				0
		);
	}
	for (
		auto class_: this->classes_
			) {
		class_.generateSwigDocString();
		class_.writeSwigDocString(
				fname,
				0
		);
	}
}



