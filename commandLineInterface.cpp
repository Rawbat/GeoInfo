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

	int space_pos = line.find(" ");
	int word_start = 0;
	
	std::string word;
	if (line.find("'") != std::string::npos && line.find("'") < space_pos) {
		if (line.find("'") != 0) {
			std::cout << "Unexpected: " <<  "'" << std::endl;
			return "";
		}
		if (line.find("'", 1) != std::string::npos && line.find("'", 1) > space_pos) {
			word_start = line.find("'") + 1;
			space_pos = line.find("'", 1) - 1;
		}
		else {
			std::cout << "Missing: " << "'" << std::endl;
			return "";
		}
	}

	word = line.substr(word_start, space_pos);
	line = line.substr(space_pos + 1);

	return word;
}

void CommandLineInterface::handleHelpMessage(std::string input) {
	std::string additional_arg = getNextWord(input);
	if (additional_arg.compare("") == 0) {
		std::cout << GENERAL_HELP_MESSAGE << std::endl;
	}
	else if(additional_arg.compare("new") == 0) {
		std::cout << NEW_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("delete") == 0) {
		std::cout << DELETE_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("print") == 0) {
		std::cout << PRINT_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("exit") == 0) {
		std::cout << EXIT_HELP_MESSAGE << std::endl;
	}
}

void CommandLineInterface::printAdditionalArguments(std::string input) {
	std::string additional_arg = getNextWord(input);
	if (additional_arg.compare("") != 0) {
		std::cout << "[WARNING] Following arguments have not been used: ";

		while (additional_arg.compare("") != 0) {
			std::cout << "'" << additional_arg << "'" << " ";
			additional_arg = getNextWord(input);
		}

		std::cout << std::endl;
	}
}