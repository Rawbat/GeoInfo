/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#include "commandLineInterface.h"
#include <iostream>

//-----------------------------------------------------------------------------
const char* CommandLineInterface::GENERAL_HELP_MESSAGE = "Acceptable commands are:\n -new\n -delete\n -sort\n -select\n -print\n -read\n -store\n -exit\nAcceptable surface types are:\n -circle\n -sector\n -polygon\nFor detailed help type 'help <command name>'.";
const char* CommandLineInterface::NEW_HELP_MESSAGE = "new <surface type> <id> <rest arguments>\nThe new command adds a new surface of a given type. The user is able to choose all values including the id. If the surface is added the present selection is reset.";
const char* CommandLineInterface::DELETE_HELP_MESSAGE = "delete <id>\nDeletes the surface with the given id if it exists.";
const char* CommandLineInterface::SORT_HELP_MESSAGE = "sort <mode>\nSorts the selected surfaces either 'ascending or 'descending'.";
const char* CommandLineInterface::SELECT_HELP_MESSAGE = "select <surface type>\nSelects only surfaces of a given type. If 'all' or no surface type is given selects all surfaces.";
const char* CommandLineInterface::PRINT_HELP_MESSAGE = "print <mode>\nPrints an overview of all selected surfaces to the cmd if no mode is passed. The mode 'detailed' prints exact information of all and if an id is passed as mode only this surfaces is printed in detail.";
const char* CommandLineInterface::READ_HELP_MESSAGE = "read <file path>...\nAdds all surfaces found in the file at given path to the current loaded and selected surfaces. Possible to enter multiple file paths.";
const char* CommandLineInterface::STORE_HELP_MESSAGE = "store <file path> <mode>\nStores surfaces to passed file path. If no path is given stores them to 'shapes.txt'. If no mode or 'selected' is passed stores only the selected surfaces. If 'all' is passed stores all.";
const char* CommandLineInterface::EXIT_HELP_MESSAGE = "exit\nCloses the program.";

const char* CommandLineInterface::CIRCLE_HELP_MESSAGE = "The syntax to create a circle looks like this:\n circle <id> (<center_x>, <center_y>) <radius>\nBrackets and commas are optional.";
const char* CommandLineInterface::SECTOR_HELP_MESSAGE = "The syntax to create a sector looks like this:\n sector <id> (<center_x>, <center_y>) <radius> (<opening point_x>, <opening point_y>) <aperture>\nBrackets and commas are optional.";
const char* CommandLineInterface::POLYGON_HELP_MESSAGE = "The syntax to create a polygon looks like this:\n polygon <id> (<point1_x>, <point1_y>) (<point2_x>, <point2_y>) (<point3_x>, <point3_y>) ...\nAt least three points have to be passed. Brackets and commas are optional.";

//-----------------------------------------------------------------------------
std::string CommandLineInterface::getInput() {
	std::string line;
	std::getline(std::cin, line);
	return line;
}

//-----------------------------------------------------------------------------
std::string CommandLineInterface::getNextWord(std::string &line) {
   //If no mores spaces can be found take the whole string and return it as the word.
	if (line.find(" ") == std::string::npos) {
		std::string word = line.substr(0);
		line = "";

      //Check if a high comma is present
      if (word.find("'") != std::string::npos) {
        int high_comma_pos = word.find("'");
        //If the high comma is not at the start of the string its not valid
        if (high_comma_pos != 0) {
          throw std::invalid_argument("Unexpected: '");
        }
        //Erase the first high comma
        word.erase(high_comma_pos, 1);

        //Find the second high comma and erase it
        if (word.find("'") != std::string::npos) {
          high_comma_pos = word.find("'");
          word.erase(high_comma_pos);
        }
        //If there is no second high comma its not valid
        else {
          throw std::invalid_argument("Missing: '");
        }
      }
      
		return word;
	}

   //Helper indices
	int space_pos = line.find(" ");
	int word_start = 0;
	
	std::string word;
   //Check if a high comma is present before the next space
	if (line.find("'") != std::string::npos && line.find("'") < space_pos) {
     //If the high comma is not at the start of the string its not valid
		if (line.find("'") != 0) {
         throw std::invalid_argument("Unexpected: '");
		}
      //Set the indices according to the high commas to include everything between
		if (line.find("'", 1) != std::string::npos && line.find("'", 1) > space_pos) {
			word_start = line.find("'") + 1;
			space_pos = line.find("'", 1) - 1;
		}
      //If there is no second high comma its not valid
		else {
         throw std::invalid_argument("Missing: '");
		}
	}

	word = line.substr(word_start, space_pos);
	line = line.substr(space_pos + 1);

	return word;
}

//-----------------------------------------------------------------------------
void CommandLineInterface::toLower(std::string& input) {
	for (unsigned int c = 0; c < input.size(); c++)
	{
		if (input.at(c) >= 'A' && input.at(c) <= 'Z') {
			input.replace(c, 1, std::string(1, static_cast<char>(input.at(c) - ('A' - 'a'))));
		}
	}
}

//-----------------------------------------------------------------------------
void CommandLineInterface::standardizeInputString(std::string& input) {

	//Convert everything to lowercase
	toLower(input);

	unsigned int c = 0;
	while (c < input.size()) {
		//Remove additional spaces
		if (c < input.size() - 1 && input.at(c) == ' ' && input.at(c + 1) == ' ') {
			input.erase(c, 1);
		}
		else if (input.at(c) == '\t') {
			input.replace(c, 1, " ");
			if (c > 0) {
				c--;
			}
		}
		//Remove all commas
		else if (input.at(c) == ',') {
			input.replace(c, 1, " ");
			if (c > 0) {
				c--;
			}
		}
		//Remove all brackets
		else if (input.at(c) == '(' || input.at(c) == ')') {
			input.replace(c, 1, " ");
			if (c > 0) {
				c--;
			}
		}
		else {
			c++;
		}
	}
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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