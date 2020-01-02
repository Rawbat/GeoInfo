#ifndef COMMAND_LINE_INTERFACE
#define COMMAND_LINE_INTERFACE

#include <string>

class CommandLineInterface {
	public:
		std::string getInput();
		std::string getNextWord(std::string &line);
	private:
};

#endif
