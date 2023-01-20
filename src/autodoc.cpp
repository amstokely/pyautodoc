//
// Created by andy on 1/9/23.
//
#include <fstream>
#include <iostream>
#include "../include/autodoc.h"
#include "../include/utils.h"

AutoDoc::AutoDoc () = default;

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

std::map<
		std::string,
		std::string
        > *AutoDoc::functionCppPyTypes () {
	return &(functionCppPyTypes_);
}

std::map<
		std::string,
		std::string
        > *AutoDoc::parameterCppPyTypes () {
	return &(parameterCppPyTypes_);
}

AutoDoc::AutoDoc (
		const std::string &fname,
		const std::string &exampleFilesDirectory,
		std::map<
				std::string,
				std::string
		        > *functionCppPyTypes,
		std::map<
				std::string,
				std::string
		        > *parameterCppPyTypes
) {
	this->exampleFilesDirectory_ = exampleFilesDirectory;
	for (
		auto      &it: *functionCppPyTypes
			) {
		this->functionCppPyTypes_[it.first] = it.second;
	}
	for (
		auto      &it: *parameterCppPyTypes
			) {
		this->parameterCppPyTypes_[it.first] = it.second;
	}
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
						line,
						this->exampleFilesDirectory_,
						this->functionCppPyTypes_,
						this->parameterCppPyTypes_
				);
				this->functions_.push_back(autoDocFunction);
			} else if (docStringType
			           == "class") {
				AutoDocClass autoDocClass(
						&is,
						this->exampleFilesDirectory_,
						this->functionCppPyTypes_,
						this->parameterCppPyTypes_
				);
				this->classes_.push_back(autoDocClass);
			}
		}
	}
}






