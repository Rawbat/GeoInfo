#ifndef COMMAND_LINE_INTERFACE
#define COMMAND_LINE_INTERFACE

#include <string>

class CommandLineInterface {
	public:
		std::string getInput();
		std::string getNextWord(std::string &line);
		void printAdditionalArguments(std::string input);
		void handleHelpMessage(std::string input);

	private:
		const char* GENERAL_HELP_MESSAGE = "Acceptable commands are:\n -new\n -delete\n -print\n -exit\nFor detailed help type 'help COMMAND_NAME'.";
		const char* NEW_HELP_MESSAGE = "new SURFACE_NAME ID REST_ARGUMENTS\nThe new command adds a new surface of a given type. The user is able to choose all values including the id.";
		const char* DELETE_HELP_MESSAGE = "delete ID\nDeletes the surface with the given id if it exists.";
		const char* PRINT_HELP_MESSAGE = "print\nPrints all surfaces to the cmd.";
		const char* EXIT_HELP_MESSAGE = "exit\nCloses the program.";
};

#endif
