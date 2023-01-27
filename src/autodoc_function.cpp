//
// Created by andy on 1/9/23.
//

#include <iostream>
#include "../include/autodoc_function.h"
#include "../include/utils.h"
#include <utility>
#include <fstream>


AutoDocFunction::AutoDocFunction (
		std::istream *is,
		std::string className,
		const std::string &doxygenExamplePath,
		std::map<
				std::string,
				std::string
		        > &functionCppPyTypes,
		std::map<
				std::string,
				std::string
		        > &parameterCppPyTypes
) {
	this->functionCppPyTypes_  = functionCppPyTypes;
	this->parameterCppPyTypes_ = parameterCppPyTypes;
	std::string line;
	std::getline(
			*is,
			line
	);
	parseFunctionTypeAndName(
			line,
			this->type_,
			this->name_
	);
	if (this->functionCppPyTypes_.count(this->type_)) {
		this->pyType_ = this->functionCppPyTypes_[this->type_];
	}
	if (substringInString(
			line,
			"@const"
	)) {
		this->const_ = 1;
	}
	this->className_           = std::move(className);
	this->signature_           = this->type_
	                             + ' ';
	int finishedProcessingDocstring = 0;
	while (!finishedProcessingDocstring) {
		std::getline(
				*is,
				line
		);
		if (docStringEnd(line)) {
			this->swigSignature_ += (
					name_
					+ '('
			);
			if (this->className_.empty()) {
				this->signature_ += (
						name_
						+ '('
				);
			} else {
				this->signature_ += (
						this->className_
						+ "::"
						+ this->name_
						+ '('
				);
				for (
					auto parameter: this->parameters_
						) {
					this->signature_ += (
							parameter.type()
							+ ' '
							+ parameter.name()
							+ ", "
					);
					this->swigSignature_ += (
							parameter.name()
							+ ", "
					);
				}
				this->signature_     = this->signature_.substr(
						0,
						this->signature_.find_last_of(',')
				);
				this->swigSignature_ = this->swigSignature_.substr(
						0,
						this->swigSignature_.find_last_of(',')
				);
				this->signature_ += ')';
				if (this->type_.empty()) {
					this->swigSignature_ += ')';
				} else {
					this->swigSignature_ += (
							")->"
							+ (
									(this->pyType_.empty())
									? this->type_ : this->pyType_
							)
					);
				}
				if (this->const_) {
					this->signature_ += " const";
				}
			}
			removeTrailingWhiteSpace(this->signature_);
			removeLeadingWhiteSpace(this->signature_);
			removeTrailingWhiteSpace(this->swigSignature_);
			removeLeadingWhiteSpace(this->swigSignature_);
			finishedProcessingDocstring = 1;
		}
		if (line.find("@param")
		    != std::string::npos) {
			this->parameters_.emplace_back(
					is,
					line,
					this->parameterCppPyTypes_
			);
		}
		if (line.find("@brief")
		    != std::string::npos) {
			this->description_ = AutoDocDescription(
					is,
					line
			);
		}
		if (line.find("@note")
		    != std::string::npos) {
			this->notes_.emplace_back(
					is,
					line

			);
		}
		if (line.find("@return")
		    != std::string::npos) {
			this->return_ = AutoDocReturn(
					is,
					line
			);
		}
		if (substringInString(
				line,
				"@PythonExample"
		)) {
			this->pythonExamples_.emplace_back(
					parseExampleFileName(
							line,
							doxygenExamplePath
					),
					"python"
			);
		}
		if (substringInString(
				line,
				"@CppExample"
		)) {
			this->cppExamples_.emplace_back(
					parseExampleFileName(
							line,
							doxygenExamplePath
					),
					"c++"
			);
		}
	}
}


std::string AutoDocFunction::name () {
	return this->name_;
}

AutoDocDescription AutoDocFunction::description () {
	return this->description_;
}

std::vector<AutoDocParameter> AutoDocFunction::parameters () {
	return this->parameters_;
}

std::string AutoDocFunction::type () {
	return this->type_;
}

AutoDocReturn AutoDocFunction::returnInfo () {
	return this->return_;
}

std::string AutoDocFunction::signature () {
	return this->signature_;
}

std::vector<AutoDocExample> AutoDocFunction::pythonExamples () {
	return this->pythonExamples_;
}

std::vector<AutoDocExample> AutoDocFunction::cppExamples () {
	return this->cppExamples_;
}

std::string AutoDocFunction::className () {
	return this->className_;
}

std::string AutoDocFunction::swigDocString () {
	return this->swigDocString_;
}

std::string AutoDocFunction::swigDocStringPrefix () {
	std::string swigDocStringPrefix_ =
			            "%feature(\"docstring\")\n";
	if (this->className_.empty()) {
		swigDocStringPrefix_ += this->name_;
	} else {
		swigDocStringPrefix_ += (
				this->className_
				+ "::"
				+ this->name_
		);
	}
	return swigDocStringPrefix_;
}

void AutoDocFunction::generateOverloadedSwigDocString (int version) {
	this->overloadedSwigDocString_.clear();
	if (version
	    == 1) {
		this->overloadedSwigDocString_ = this->swigDocStringPrefix();
	}
	this->overloadedSwigDocString_ += "\n\"\\n\"\n\"";
	std::string border =
			            "********************";
	this->overloadedSwigDocString_ += border;
	this->overloadedSwigDocString_ += "\\n\"\n";
	std::string versionString = "\"*    Version ";
	versionString += std::to_string(version);
	for (
			auto pos = versionString.length();
			pos
			< border.length();
			pos++
			) {
		versionString += ' ';
	}
	versionString += "*\\n\"\n";
	this->overloadedSwigDocString_ += versionString;
	this->overloadedSwigDocString_ +=
			"\"********************\\n\"\n";

	this->overloadedSwigDocString_ += (
			"\n\""
			+ this->swigSignature_
			+ "\\n\"\n"
	);
	if (!this->description_.str().empty()) {
		this->overloadedSwigDocString_ += "\"\\nDescription\\n\"\n";
		this->overloadedSwigDocString_ +=
				"\"--------------------\\n\"\n";
		this->overloadedSwigDocString_ +=
				this->description_.swigDocString();
		this->overloadedSwigDocString_ += "\"\\n\"\n";
	}
	if (!this->parameters_.empty()) {
		this->overloadedSwigDocString_ += "\"\\nParameters\\n\"\n";
		this->overloadedSwigDocString_ +=
				"\"--------------------\\n\"\n";
		for (
			auto &parameter: this->parameters_
				) {
			this->overloadedSwigDocString_ +=
					parameter.swigDocString();
			if (!isLastElementInVector<AutoDocParameter>(
					parameter,
					this->parameters_
			)) {
				this->overloadedSwigDocString_ += "\"\\n\"\n";
			}
		}
	}
	if (!this->return_.description().str().empty()) {
		this->overloadedSwigDocString_ += "\"\\nReturns\\n\"\n";
		this->overloadedSwigDocString_ +=
				"\"--------------------\\n\"\n";
		this->overloadedSwigDocString_ +=
				this->return_.swigDocString();
		this->overloadedSwigDocString_ += "\"\\n\"\n";
	}
	if (!this->notes_.empty()) {
		for (
			auto note: this->notes_
				) {
			this->overloadedSwigDocString_ += "\"\\nNote\\n\"\n";
			this->overloadedSwigDocString_ +=
					"\"--------------------\\n\"\n";
			this->overloadedSwigDocString_ += note.swigDocString();
			this->overloadedSwigDocString_ += "\"\\n\"\n";
		}
	}
	if (!this->pythonExamples_.empty()) {
		for (
			auto example: this->pythonExamples_
				) {
			this->overloadedSwigDocString_ += "\"\\nExample\\n\"\n";
			this->overloadedSwigDocString_ +=
					"\"--------------------\\n\"\n";
			this->overloadedSwigDocString_ +=
					example.swigDocString();
		}
	}
}

void AutoDocFunction::generateSwigDocString () {
	this->swigDocString_.clear();
	this->swigDocString_ = swigDocStringPrefix();
	this->swigDocString_ += (
			"\n\""
			+ this->swigSignature_
			+ "\\n\"\n"
	);
	if (!this->description_.str().empty()) {
		this->swigDocString_ += "\"\\nDescription\\n\"\n";
		this->swigDocString_ += "\"--------------------\\n\"\n";
		this->swigDocString_ += this->description_.swigDocString();
		this->swigDocString_ += "\"\\n\"\n";
	}
	if (!this->parameters_.empty()) {
		this->swigDocString_ += "\"\\nParameters\\n\"\n";
		this->swigDocString_ += "\"--------------------\\n\"\n";
		for (
			auto &parameter: this->parameters_
				) {
			this->swigDocString_ += parameter.swigDocString();
			if (!isLastElementInVector<AutoDocParameter>(
					parameter,
					this->parameters_
			)) {
				this->swigDocString_ += "\"\\n\"\n";
			}
		}
	}
	if (!this->return_.description().str().empty()) {
		this->swigDocString_ += "\"\\nReturns\\n\"\n";
		this->swigDocString_ += "\"--------------------\\n\"\n";
		this->swigDocString_ += this->return_.swigDocString();
		this->swigDocString_ += "\"\\n\"\n";
	}
	if (!this->notes_.empty()) {
		for (
			auto note: this->notes_
				) {
			this->swigDocString_ += "\"\\nNote\\n\"\n";
			this->swigDocString_ += "\"--------------------\\n\"\n";
			this->swigDocString_ += note.swigDocString();
			this->swigDocString_ += "\"\\n\"\n";
		}
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
}

void AutoDocFunction::writeSwigDocString (
		const std::string &fname,
		int overwrite
) {
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

std::vector<AutoDocNote> AutoDocFunction::notes () {
	return this->notes_;
}

std::string AutoDocFunction::pyType () {
	return this->pyType_;
}

std::map<
		std::string,
		std::string
        > *AutoDocFunction::functionCppPyTypes () {
	return &(functionCppPyTypes_);
}

std::map<
		std::string,
		std::string
        > *AutoDocFunction::parameterCppPyTypes () {
	return &(parameterCppPyTypes_);
}

std::string AutoDocFunction::overloadedSwigDocString () {
	return this->overloadedSwigDocString_;
}

AutoDocFunction::AutoDocFunction () = default;

AutoDocFunction::~AutoDocFunction () = default;
