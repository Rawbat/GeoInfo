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

void CommandLineInterface::toLower(std::string& input) {
	for (unsigned int c = 0; c < input.size(); c++)
	{
		if (input.at(c) >= 'A' && input.at(c) <= 'Z') {
			input.replace(c, 1, std::string(1, static_cast<char>(input.at(c) - ('A' - 'a'))));
		}
	}
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
	else if (additional_arg.compare("sort") == 0) {
		std::cout << SORT_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("select") == 0) {
		std::cout << SELECT_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("print") == 0) {
		std::cout << PRINT_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("read") == 0) {
		std::cout << READ_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("store") == 0) {
		std::cout << STORE_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("exit") == 0) {
		std::cout << EXIT_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("circle") == 0) {
		std::cout << CIRCLE_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("sector") == 0) {
		std::cout << SECTOR_HELP_MESSAGE << std::endl;
	}
	else if (additional_arg.compare("polygon") == 0) {
		std::cout << POLYGON_HELP_MESSAGE << std::endl;
	}
	else {
		std::cout << "Unknown help option" << std::endl;
		std::cout << GENERAL_HELP_MESSAGE << std::endl;
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