#include "commandLineInterface.h"
#include <iostream>

std::string CommandLineInterface::getInput() {
	std::string line;
	std::getline(std::cin, line);
	return line;
}

std::string CommandLineInterface::getNextWord(std::string &line) {
	if (line.find(" ") == std::string::npos) {
		std::string word = line.substr(0);
		line = "";
		return word;
	}
	int pos = line.find(" ");
	
	std::string word = line.substr(0, pos);
	line = line.substr(pos + 1);

	return word;
}