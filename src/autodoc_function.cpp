//
// Created by andy on 1/9/23.
//

#include <iostream>
#include "../include/autodoc_function.h"
#include "../include/utils.h"
#include <utility>
#include <algorithm>
#include <fstream>


AutoDocFunction::AutoDocFunction (
		std::istream *is,
		std::string className
) {
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
	if (substringInString(
			line,
			"@const"
	)) {
		this->const_ = 1;
	}
	this->className_ = std::move(className);
	this->signature_ = this->type_
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
							+ this->type_
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
					line
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
		if (line.find("@PythonExample")
		    != std::string::npos) {
			this->pythonExamples_.emplace_back(
					is,
					"python"
			);
		}
		if (line.find("@CppExample")
		    != std::string::npos) {
			this->cppExamples_.emplace_back(
					is,
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

void AutoDocFunction::generateSwigDocString () {
	this->swigDocString_ =
			"%feature(\"docstring\")\n";
	if (this->className_.empty()) {
		this->swigDocString_ += this->name_;
	} else {
		this->swigDocString_ += (
				this->className_
				+ "::"
				+ this->name_
		);
	}
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

std::vector<AutoDocNote> AutoDocFunction::notes () {
	return this->notes_;
}

AutoDocFunction::AutoDocFunction () = default;

AutoDocFunction::~AutoDocFunction () = default;
