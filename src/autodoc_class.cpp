//
// Created by andy on 1/10/23.
//

#include <fstream>
#include <iostream>
#include "../include/autodoc_class.h"
#include "../include/utils.h"

AutoDocClass::AutoDocClass (
		std::istream *is
) {
	std::string line;
	int         finishedProcessingDocString = 0;
	std::string delimiter                   = "};";
	while (!finishedProcessingDocString) {
		std::getline(
				*is,
				line
		);
		if (substringInString(line, "@class")){
			this->name_ = line.substr(
					line.find("@class")
					+ 6
			);
			removeLeadingWhiteSpace(this->name_);
			removeTrailingWhiteSpace(this->name_);
		}
		if (substringInString(line, delimiter)){
			finishedProcessingDocString = 1;
		}
		if (substringInString(line, "@brief")) {
			this->description_ = AutoDocDescription(
					is,
					line
			);
		}
		if (substringInString(
				line,
				"@PythonExample"
		)) {
			this->pythonExamples_.emplace_back(
					is,
					"python"
			);
		}
		if (substringInString(
				line,
				"@CppExample"
		)) {
			this->cppExamples_.emplace_back(
					is,
					"c++"
			);
		}
		if (substringInString(line, "@AutoDocIgnore")){
			processAutoDocIgnore(
					is,
					line,
					"function"
			);
		}
		if (docStringStart(line)) {
			std::string docStringType = getDocStringType(
					is,
					line
			);
			if (docStringType
			    == "function") {
				AutoDocFunction autoDocFunction(
						is,
						this->name_
				);
				this->methods_.push_back(autoDocFunction);
			}
		}
	}
}

std::vector<AutoDocFunction> AutoDocClass::methods () {
	return this->methods_;
}

AutoDocDescription AutoDocClass::description () {
	return this->description_;
}


std::string AutoDocClass::name () {
	return this->name_;
}

std::vector<AutoDocClass> AutoDocClass::classes () {
	return this->classes_;
}

std::string AutoDocClass::swigDocString () {
	return this->swigDocString_;
}

void AutoDocClass::generateSwigDocString () {
	this->swigDocString_ += (
			"%feature(\"docstring\")\n"
			+ this->name_
			+ '\n'
	);
	if (!this->description_.str().empty()) {
		this->swigDocString_ += "\"\\nDescription\\n\"\n";
		this->swigDocString_ += "\"--------------------\\n\"\n";
		this->swigDocString_ += this->description_.swigDocString();
		this->swigDocString_ += "\"\\n\"\n";
	}
	if (!this->pythonExamples_.empty()) {
		for (
			auto example: this->pythonExamples_
				) {
			this->swigDocString_ += "\"\\nExample\\n\"\n";
			this->swigDocString_ += "\"--------------------\\n\"\n";
			this->swigDocString_ += example.swigDocString();
		}
	}
	this->swigDocString_ += ";";
	for (
		auto method: this->methods_
			) {
		method.generateSwigDocString();
		this->swigDocString_ += method.swigDocString();
	}
}

void AutoDocClass::writeSwigDocString (
		const std::string &fname,
		int overwrite
) {
	this->swigDocString_.clear();
	this->generateSwigDocString();
	std::ofstream swigInterfaceFile;
	if (overwrite) {
		swigInterfaceFile.open(fname);
	} else {
		swigInterfaceFile.open(
				fname,
				std::ios_base::app
		);
	}
	swigInterfaceFile
			<< this->swigDocString_;
	swigInterfaceFile.close();

}

std::vector<AutoDocExample> AutoDocClass::pythonExamples () {
	return this->pythonExamples_;
}

std::vector<AutoDocExample> AutoDocClass::cppExamples () {
	return this->cppExamples_;
}

AutoDocClass::AutoDocClass () = default;


