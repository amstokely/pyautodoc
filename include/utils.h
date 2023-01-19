//
// Created by andy on 1/9/23.
//

#ifndef PYAUTODOC_UTILS_H
#define PYAUTODOC_UTILS_H

#include <string>
#include <vector>

std::string escapeQuotes (
		std::string &str
);

int docStringStart (
		const std::string &line
);

int docStringEnd (
		const std::string &line
);

void cleanDocStringLine (
		std::string &line
);

void removeLeadingWhiteSpace (
		std::string &str
);

void removeTrailingWhiteSpace (
		std::string &str
);

void parseFunctionTypeAndName (
		const std::string &line,
		std::string &functionType,
		std::string &functionName
);

std::string getDocStringType (
		std::istream *is,
		std::string line
);

std::string parseType (
		std::string &line
);

std::string indentSwigDocStringLine (
		const std::string &str
);

void processAutoDocIgnore (
		std::istream *is,
		std::string line,
		const std::string &ignoreType
);

template<class T>
int isLastElementInVector (
		T &element,
		std::vector<T> &vec
) {
	if (&element
	    == &vec.back()) {
		return 1;
	} else {
		return 0;
	}
}

int substringInString (
		const std::string &str,
		const std::string &substr
);

#endif //PYAUTODOC_UTILS_H
