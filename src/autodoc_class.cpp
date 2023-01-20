//
// Created by andy on 1/10/23.
//

#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include "../include/autodoc_class.h"
#include "../include/utils.h"

AutoDocClass::AutoDocClass (
		std::istream *is,
		const std::string& exampleFilesDirectory,
		std::map<
				std::string,
				std::string
		        > &functionCppPyTypes,
		std::map<
				std::string,
				std::string
		        > &parameterCppPyTypes
) {
	std::map<
			std::string,
			int
	        >                    methodsNameCount;
	std::vector<AutoDocFunction> tmpMethods;
	this->functionCppPyTypes_               =
			std::move(functionCppPyTypes);
	this->parameterCppPyTypes_              =
			std::move(parameterCppPyTypes);
	std::string line;
	int         finishedProcessingDocString = 0;
	std::string delimiter                   = "};";
	while (!finishedProcessingDocString) {
		std::getline(
				*is,
				line
		);
		if (substringInString(
				line,
				"@class"
		)) {
			this->name_ = line.substr(
					line.find("@class")
					+ 6
			);
			removeLeadingWhiteSpace(this->name_);
			removeTrailingWhiteSpace(this->name_);
		}
		if (substringInString(
				line,
				delimiter
		)) {
			finishedProcessingDocString = 1;
		}
		if (substringInString(
				line,
				"@brief"
		)) {
			this->description_ = AutoDocDescription(
					is,
					line
			);
		}
		if (substringInString(
				line,
				"@PythonExampleFile"
		)) {
			this->pythonExamples_.emplace_back(
					parseExampleFileName(
							line,
							exampleFilesDirectory
					),
					"python"
			);
		} else if (substringInString(
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
				"@CppExampleFile"
		)) {
			this->cppExamples_.emplace_back(
					parseExampleFileName(
							line,
							exampleFilesDirectory
					),
					"c++"
			);
		} else if (substringInString(
				line,
				"@CppExample"
		)) {
			this->cppExamples_.emplace_back(
					is,
					"c++"
			);
		}
		if (substringInString(
				line,
				"@AutoDocIgnore"
		)) {
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
						this->name_,
						exampleFilesDirectory,
						this->functionCppPyTypes_,
						this->parameterCppPyTypes_
				);
				tmpMethods.push_back(autoDocFunction);
			}
		}
	}
	for (
		auto    method: tmpMethods
			) {
		std::string methodName      = method.name();
		auto        methodNameCount = methodsNameCount.emplace(
				methodName,
				0
		);
		methodNameCount.first->second += 1;
	}
	std::partition_copy(
			tmpMethods.begin(),
			tmpMethods.end(),
			std::back_inserter(this->overloadedMethods_),
			std::back_inserter(this->methods_),
			[methodsNameCount] (
					AutoDocFunction method
			) {
				return methodsNameCount.at(method.name())
				       > 1;
			}
	);
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
	std::string previousMethodName;
	int         overloadedMethodVersion = 1;
	if (!this->overloadedMethods_.empty()) {
		for (
			auto method: this->overloadedMethods_
				) {
			if (method.name()
			    != previousMethodName) {
				overloadedMethodVersion = 1;
			}
			method.generateOverloadedSwigDocString(
					overloadedMethodVersion
			);
			this->swigDocString_ +=
					method.overloadedSwigDocString();
			previousMethodName = method.name();
			overloadedMethodVersion++;
		}
		this->swigDocString_ += ";";
	}
	for (
		auto    method: this->methods_
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

std::map<
		std::string,
		std::string
        > *AutoDocClass::functionCppPyTypes () {
	return &(functionCppPyTypes_);
}

std::map<
		std::string,
		std::string
        > *AutoDocClass::parameterCppPyTypes () {
	return &(parameterCppPyTypes_);
}

std::vector<AutoDocFunction> AutoDocClass::overloadedMethods () {
	return this->overloadedMethods_;
}

AutoDocClass::AutoDocClass () = default;


