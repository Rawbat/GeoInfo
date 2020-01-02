#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>

class CommandHandler {
	public:
		CommandHandler();
		void handle(std::string command_line);
	private:
};
#endif
