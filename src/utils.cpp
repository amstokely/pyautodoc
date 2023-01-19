//
// Created by andy on 1/9/23.
//
#include <vector>
#include <iostream>
#include "../include/utils.h"


std::string escapeQuotes (
		std::string &str
) {
	std::string newStr;
	for (
		auto    c: str
			) {
		if (c
		    == '\"') {
			newStr += "\\\"";
		} else {
			newStr += c;
		}
	}
	return newStr;
}

std::string getDocStringType (
		std::istream *is,
		std::string line
) {
	int len = is->tellg();
	std::getline(
			*is,
			line
	);
	if (line.find("@class")
	    != std::string::npos) {
		is->seekg(
				len,
				std::ios_base::beg
		);
		return "class";
	}
	if (line.find("@function")
	    != std::string::npos) {
		is->seekg(
				len,
				std::ios_base::beg
		);
		return "function";
	}
	is->seekg(
			len,
			std::ios_base::beg
	);
	return "";
}

int docStringStart (const std::string &line) {
	if (line.find("/*!")
	    != std::string::npos) {
		return 1;
	}
	return 0;
}

int docStringEnd (const std::string &line) {
	if (line.find("*/")
	    != std::string::npos) {
		return 1;
	}
	return 0;
}

void cleanDocStringLine (std::string &line) {
	if (docStringEnd(line)) {
		return;
	}
	size_t                   pos;
	std::vector<std::string> substringsToErase = {
			std::string("*"),
			std::string("@param"),
			std::string("@brief"),
			std::string("@return"),
			std::string("@note")

	};
	for (
		auto                 &s: substringsToErase
			) {
		pos = line.find(s);
		if (pos
		    != std::string::npos) {
			line.erase(
					pos,
					s.length());
		}
	}
}

void removeLeadingWhiteSpace (std::string &str) {
	const char *t = " \t\n\r\f\v";
	str.erase(
			0,
			str.find_first_not_of(t));
}

void removeTrailingWhiteSpace (std::string &str) {
	const char *t = " \t\n\r\f\v";
	str.erase(
			str.find_last_not_of(t)
			+ 1
	);
}

void parseFunctionTypeAndName (
		const std::string &line,
		std::string &functionType,
		std::string &functionName
) {
	unsigned int pos, start, end;
	if (substringInString(
			line,
			"@type"
	)) {
		std::string typeDelimiter = "@type{";
		pos   = line.find(typeDelimiter);
		start = pos
		        + typeDelimiter.length();
		end   = line.find(
				'}',
				start
		);
		auto typeStringLength = end
		                        - start;
		functionType = line.substr(
				start,
				typeStringLength
		);
	}
	if (substringInString(
			line,
			"@function"
	)) {
		std::string nameDelimiter = "@function{";
		pos                       = line.find(nameDelimiter);
		start                     = pos
		                            + nameDelimiter.length();
		end                       = line.find(
				'}',
				start
		);
		auto nameStringLength = end
		                        - start;
		functionName = line.substr(
				start,
				nameStringLength
		);
	}
}

std::string parseType (
		std::string &line
) {
	if (substringInString(
			line,
			"@type"
	)
	    != std::string::npos) {
		std::string delimiter        = "@type{";
		auto        pos              = line.find(delimiter);
		auto        start            = pos
		                               + delimiter.length();
		auto        end              = line.find('}');
		auto        typeStringLength = end
		                               - start;
		auto        type             = line.substr(
				start,
				typeStringLength
		);
		std::string newLineBeginning = line.substr(
				0,
				pos
		);
		std::string newLineEnd       = line.substr(
				end
				+ 1
		);
		removeTrailingWhiteSpace(newLineBeginning);
		removeLeadingWhiteSpace(newLineBeginning);
		removeTrailingWhiteSpace(newLineEnd);
		removeLeadingWhiteSpace(newLineEnd);
		line = (
				newLineBeginning
				+ ' '
				+ newLineEnd
		);
		return type;
	} else {
		return std::string{};
	}
}

std::string indentSwigDocStringLine (
		const std::string &str
) {
	std::string indentedSwigDocStringLine = (
			"\"    "
	);
	for (
		auto    c: str
			) {
		if (c
		    == '\n') {
			indentedSwigDocStringLine += (
					"\\n\"\n\"    "
			);
		} else {
			indentedSwigDocStringLine += c;
		}
	}
	indentedSwigDocStringLine += "\"\n";
	return indentedSwigDocStringLine;
}

void processAutoDocIgnore (
		std::istream *is,
		std::string line,
		const std::string &ignoreType
) {
	if (ignoreType
	    == "function") {
		while (!docStringEnd(line)) {
			getline(
					*is,
					line
			);
		}
	}
}

int substringInString (
		const std::string &str,
		const std::string &substr
) {
	if (str.find(substr)
	    != std::string::npos) {
		return 1;
	} else {
		return 0;
	}
}